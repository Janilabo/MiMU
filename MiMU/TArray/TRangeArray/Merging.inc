{$IFDEF HELPERS}
function Coalesce: TRangeArray; overload;
function Collapse: TRangeArray; overload;
function Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
function Consolidated(const rAscending: Boolean = True): TRangeArray; overload;
function Defragment(const rAscending: Boolean = True): TRangeArray; overload;
function Fuse: TRangeArray; overload;
function Fused: TRangeArray; overload;
function Merge: TRangeArray; overload;
function Merged: TRangeArray; overload;
function Simplify: TRangeArray; overload;
function Squashed: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Coalesce>
  @action: Coalesce overlapping and adjacent ranges
  @note: Input normalized and sorted; adjacency = (start <= stop + 1)
[==============================================================================}
function TRangeArrayHelper.Coalesce: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, 0);
  R := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (R.stop + 1)) of
    True:
    if (S[i].stop > R.stop) then
      R.stop := S[i].stop;
    False:
    begin
      SetLength(Result, (Result.Length + 1));
      Result[High(Result)] := R;
      R := S[i];
    end;
  end;
  SetLength(Result, (Result.Length + 1));
  Result[High(Result)] := R;
end;

{==============================================================================]
  <Collapse>
  @action: Coalesce overlapping and adjacent ranges with preallocated result
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); uses index accumulator
[==============================================================================}
function TRangeArrayHelper.Collapse: TRangeArray; overload;
var
  S: TRangeArray;
  C: TRange;
  i, r: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, S.Length);
  r := 0;
  C := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (C.stop + 1)) of
    True:
    if (S[i].stop > C.stop) then
      C.stop := S[i].stop;
    False:
    begin
      Result[r.Increase] := C;
      C := S[i];
    end;
  end;
  Result[r.Increase] := C;
  SetLength(Result, r);
end;

{==============================================================================]
  <Consolidate>
  @action: Expands ranges into unique integer values using ordered insertion,
           then reconstructs contiguous ranges into a compact, non-overlapping array.
           Produces a new array ordered by rAscending.
  @note: Steps:
           1. Iterates all ranges and inserts each value via BinaryGrow (sorted, no duplicates).
           2. Tracks resulting element count (s).
           3. Rebuilds contiguous ranges from the ordered integer set.
         Time complexity: O(m log m) due to incremental ordered insertion,
         where m = total number of elements across all ranges.
         Avoids separate sort/compress pass (unlike Defragment).
         Produces normalized, non-overlapping ranges. Original array is not modified.
         Output direction controlled solely by rAscending.
[==============================================================================}
function TRangeArrayHelper.Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
var
  s, i, j, l, d: Integer;
  r: TIntegerArray;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  s := 0;
  SetLength(r, 0);
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s.Increase(r.BinaryGrow(j, rAscending));
  SetLength(Result, s);
  d := IfThen(rAscending, 1, -1);
  l := 0;
  Result[0].Create(r[0]);
  for i := 1 to (s - 1) do
    if (r[i] = (Result[l].stop + d)) then
      Result[l].stop := r[i]
    else
      Result[l.Increment].Create(r[i]);
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Consolidated>
  @action: Returns a compact version of the array where all overlapping or 
           adjacent segments are fused into single ranges.
  @note: - Uses a Geometric Sweep (O(n log n)).
         - Normalizes all input to ensure physical overlaps are detected.
         - Merges segments that touch (e.g., [1..5] and [6..10] become [1..10]).
         - If rAscending is False, the result is returned in Descending 
           order (e.g., [20..10, 5..1]).
[==============================================================================}
function TRangeArrayHelper.Consolidated(const rAscending: Boolean = True): TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  case Self.Length of
    0: Exit([]);
    1:
    if rAscending then
      Exit([Self[0].Normalize])
    else
      Exit([Self[0].Descended]);
  end;
  S := Self.Normalized;
  S.SortByStart(True);
  SetLength(Result, S.Length);
  l := 0;
  R := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (R.stop + 1)) of
    True:
    if (S[i].stop > R.stop) then
      R.stop := S[i].stop;
    False:
    begin
      Result[l.Increase] := R;
      R := S[i];
    end;
  end;
  Result[l.Increase] := R;
  SetLength(Result, l);
  if not rAscending then
    Result := Result.Descended.Reversed;
end;

{==============================================================================]
  <Defragment>
  @action: Expands all ranges into individual integer points, sorts and compresses them,
           then reconstructs contiguous ranges into a compact, non-overlapping array.
           Can produce ascending or descending ranges based on rAscending.
  @note: Steps:
           1. Computes total size of all ranges.
           2. Fills a temporary integer array with all values in all ranges.
           3. Sorts the integers (ascending or descending).
           4. Compresses duplicates.
           5. Rebuilds contiguous ranges into TRangeArray.
         Time complexity: O(n + m log m), where n = number of ranges, m = total elements.
         Produces fully normalized, non-overlapping ranges. Original array is not modified.
         Does not preserve original Ascending flags; controlled entirely by rAscending.
[==============================================================================}
function TRangeArrayHelper.Defragment(const rAscending: Boolean = True): TRangeArray; overload;
var
  s, i, j, l, d: Integer;
  r: TIntegerArray;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Size);
  SetLength(r, s);
  l := 0;
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      r[l.Increase] := j;
  r.QuickSort(rAscending);
  r.Compress;
  SetLength(Result, r.Length);
  Result[0].Create(r[0]);
  d := IfThen(rAscending, 1, -1);
  l := 0;
  for i := 1 to High(r) do
    if (r[i] = (Result[l].stop + d)) then
      Result[l].stop := r[i]
    else
      Result[l.Increment].Create(r[i]);
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Fuse>
  @action: Combines overlapping or adjacent ranges into a single, non-overlapping array.
           Produces a new array; original array is not modified. Always normalizes
           ranges before merging.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`) via Self.Normalized.
           2. Sorts ranges by `start`.
           3. Iteratively merges overlapping or adjacent ranges (stop + 1).
           4. Writes merged ranges into Result, compacting array length.
         Time complexity: O(n log n) due to sorting; merge pass is O(n).
         Safe as long as all ranges have valid bounds. Does not preserve any Ascending flag.
[==============================================================================}
function TRangeArrayHelper.Fuse: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  S := Self.Normalized;
  S.SortByStart;
  SetLength(Result, S.Length);
  R := S[0];
  l := 0;
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      Result[l.Increase] := R;
      R := S[i];
    end else
      R.stop := Max(R.stop, S[i].stop);
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Fused>
  @action: Merge overlapping and adjacent ranges using supply-based append
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); result grows via Supply
[==============================================================================}
function TRangeArrayHelper.Fused: TRangeArray; overload;
var
  S: TRangeArray;
  R: Integer;
  i: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S.Copy);
  S.SortByStart;
  Result := [S[0]];
  R := 0;
  for i := 1 to High(S) do
    if not (S[i].start <= (Result[R].stop + 1)) then
      R := Result.Supply(S[i])
    else if (S[i].stop > Result[R].stop) then
      Result[R].stop := S[i].stop;
end;

{==============================================================================]
  <Merge>
  @action: Merges overlapping or adjacent ranges into a normalized, non-overlapping array.
           Produces a new array; does not modify the original. Preserves the original
           ascending/descending direction if all ranges share the same Ascending flag.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`) via Self.Normalized.
           2. Sorts ranges by `start`.
           3. Iteratively merges overlapping or adjacent ranges (stop + 1).
           4. Writes merged ranges into Result, compacting the array length.
           5. Reverses each merged range if original direction is descending.
         Time complexity: O(n log n) due to sort; merge pass is O(n).
         Safe as long as all ranges have valid bounds and share the same direction.
[==============================================================================}
function TRangeArrayHelper.Merge: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  a: Boolean;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  a := Self[0].Ascending;
  S := Self.Normalized;
  S.SortByStart;
  SetLength(Result, S.Length);
  l := 0;
  R := S[0];
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      if not a then
        R.Reverse;
      Result[l.Increase] := R;
      R := S[i];
    end else
      R.stop := Max(R.stop, S[i].stop);
  if not a then
    R.Reverse;
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Merged>
  @action: In-place merge of overlapping and adjacent ranges
  @note: Operates on normalized copy; adjacency = (start <= stop + 1); compacts via index overwrite
[==============================================================================}
function TRangeArrayHelper.Merged: TRangeArray; overload;
var
  i, r: Integer;
begin
  Result := Self.Normalized;
  if (Result.Length < 2) then
    Exit;
  r := 0;
  Result.SortByStart;
  for i := 1 to High(Result) do
    if (Result[i].start <= (Result[r].stop + 1)) then
      Result[r].stop := Max(Result[r].stop, Result[i].stop)
    else
      Result[r.Increment] := Result[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Simplify>
  @action: Normalizes, sorts, and merges overlapping or adjacent ranges into a
           minimal non-overlapping set.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`).
           2. Sorts ranges by `Minimum` (ascending).
           3. Sequentially merges overlapping or adjacent ranges (stop + 1).
           4. Compacts result to final length.
         Time complexity: O(n log n) due to sort; merge pass O(n).
         Produces normalized, non-overlapping ranges. Original array is not modified.
         Equivalent to Fuse after normalization; does not preserve direction.
[==============================================================================}
function TRangeArrayHelper.Simplify: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  S := Self.Normalized;
  S.SortByMinimum(True);
  SetLength(Result, S.Length);
  R := S[0];
  l := 0;
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      Result[l.Increase] := R;
      R := S[i];
    end else
	  R.stop := Max(R.stop, S[i].stop);
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Squashed>
  @action: Incrementally merge overlapping and adjacent ranges into result
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); grows result dynamically
[==============================================================================}
function TRangeArrayHelper.Squashed: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, h: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, 0);
  h := -1;
  for i := 0 to High(S) do
  begin
    R := S[i];
    if (h = -1) then
    begin
      SetLength(Result, (h.Increment + 1));
      Result[h] := R;
      Continue;
    end;
    if (R.Start > (Result[h].Stop + 1)) then
    begin
      SetLength(Result, (h.Increment + 1));
      Result[h] := R;
    end else if (R.Stop > Result[h].Stop) then
      Result[h].Stop := R.Stop;
  end;
end;
{$ENDIF}
