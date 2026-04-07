{$IFDEF HELPERS}
function Coalesce: TRangeArray; overload;
function Collapse: TRangeArray; overload;
function Condense(const oAscending: Boolean = True): TRangeArray; overload;
function Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
function Consolidated(const rAscending: Boolean = True): TRangeArray; overload;
function Defragment(const rAscending: Boolean = True): TRangeArray; overload;
function Fuse: TRangeArray; overload;
function Fused: TRangeArray; overload;
function Meld(const rSort: Boolean = True): TRangeArray; overload;
function Melted(const oAscending: Boolean = True): TRangeArray; overload;
function Merge: TRangeArray; overload;
function Merged: TRangeArray; overload;
function Mergified(const threshold: Integer = -1): TRangeArray; overload;
function Mergify(const threshold: Integer = -1): Integer; overload;
function Simplify: TRangeArray; overload;
function Squashed: TRangeArray; overload;
function Stream(const oAscending: Boolean = True): TRangeArray; overload;
function Streamed(const oAscending: Boolean = True): TRangeArray; overload;
function Streamline: TRangeArray; overload;
function Unite(const mAdjacent: Boolean = True): TRangeArray; overload;
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
  <Condense>
  @action: Merges overlapping and adjacent ranges in a TRangeArray into the minimal set
           of disjoint contiguous ranges. Returns the result in ascending or descending order.
  @note:
    - Normalizes all ranges internally before merging.
    - Adjacent ranges (stop + 1 = start) are merged automatically.
    - Efficient linear merge after sorting.
    - If oAscending = False, the resulting ranges are reversed.
    - Result contains the minimal number of ranges covering all integers from the input.
[==============================================================================}
function TRangeArrayHelper.Condense(const oAscending: Boolean = True): TRangeArray; overload;
var
  s: TRangeArray;
  r: TRange;
  i, l: Integer;
begin
  if (Self.Length = 0) then
    Exit([]);
  s := Self.Normalized;
  s.Sort(True);
  SetLength(Result, s.Length);
  l := 0;
  r := s[0];
  for i := 1 to High(s) do
    if (s[I].start > (r.stop + 1)) then
    begin
      Result[l.Increase] := r;
      r := s[I];
    end else if (s[I].stop > r.stop) then
      r.stop := s[I].stop;
  Result[l.Increase] := r;
  SetLength(Result, l);
  if not oAscending then
  for i := 0 to ((l div 2) - 1) do
  begin
    r := Result[i];
    Result[i] := Result[l - 1 - i];
    Result[l - 1 - i] := r;
  end;
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
  <Meld>
  @action: Merges overlapping ranges in a TRangeArray into the smallest set of disjoint ranges.
           Produces a union of all overlapping intervals. Optional sorting ensures
           ranges are processed in ascending start order.
  @note:
    - Only strictly overlapping ranges are merged; adjacent ranges are preserved as separate.
    - Sorting (`rSort`) is optional; if False, assumes input is pre-sorted.
    - Normalizes all ranges internally to ensure start ≤ stop.
    - Returns a copy of the input if fewer than 2 ranges exist.
    - Result preserves order of merged ranges.
[==============================================================================}
function TRangeArrayHelper.Meld(const rSort: Boolean = True): TRangeArray; overload;
var
  n: TRangeArray;
  i, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  n := Self.Normalized;
  if rSort then
    n.SortByStart;
  SetLength(Result, l);
  r := 0;
  Result[0] := n[0];
  for i := 1 to (l - 1) do
    if Result[r].Overlap(n[i]) then
      Result[r].stop := Max(Result[r].stop, n[i].stop)
    else
      Result[r.Increment] := n[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Melted>
  @action: Flattens all ranges into individual integers, sorts them, removes duplicates,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - The parameter oAscending controls the final order of the reconstructed ranges.
    - Duplicate integers across overlapping ranges are removed automatically.
    - Useful for creating a fully “coalesced” representation of a set of ranges.
    - Internally expands ranges to integers, sorts, and merges—so large ranges may temporarily consume more memory.
    - The result contains disjoint ranges covering the same integers as the input.
[==============================================================================}
function TRangeArrayHelper.Melted(const oAscending: Boolean = True): TRangeArray; overload;
var
  n: TRangeArray;
  s: TIntegerArray;
  i, j, r, l: Integer;
begin
  l := 0;
  n := Self.Normalized;
  for i := 0 to High(n) do
    Inc(l, ((n[i].stop - n[i].start) + 1));
  SetLength(s, l);
  l := 0;
  for i := 0 to High(n) do
    for j := n[i].start to n[i].stop do
      s[l.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, s.Length);
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if (s[i] = s[i - 1]) then
      Continue
    else if (s[i] = (Result[r].stop + j)) then
      Result[R].stop := s[i]
    else
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
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
  <Mergified>
  @action: Returns a new array of merged ranges from the original array.
           Overlapping or nearby ranges (within optional 'threshold') are combined
           into minimal contiguous ranges.
  @note:
    - Non-destructive: does not modify the original array.
    - Threshold defaults to -1 (only strictly overlapping ranges are merged).
    - Useful for creating a canonical, merged representation of ranges.
[==============================================================================}
function TRangeArrayHelper.Mergified(const threshold: Integer = -1): TRangeArray; overload;
var
  s: TRangeArray;
  h, j, i, l: Integer;
  c, r: TRange;
begin
  s := Self.Normalized;
  h := High(s);
  if (h < 1) then
    Exit;
  for i := 0 to (h - 1) do
    for j := (i + 1) to h do
      if (s[i].start > s[j].start) then
        Swap(s[i], s[j]);
  SetLength(Result, (h + 1));
  l := 0;
  c := s[0];
  for i := 1 to h do
  begin
    r := s[i];
    if (r.start > (c.stop + threshold + 1)) then
    begin
      Result[l.Increase] := c;
      c := r;
    end else if (r.stop > c.stop) then
      c.stop := r.stop;
  end;
  Result[l] := c;
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Mergify>
  @action: Merges overlapping or nearby ranges into contiguous ranges.
           Ranges within the optional 'threshold' distance are combined.
  @note:
    - Operates in-place and updates the array.
    - Returns the number of merged ranges.
    - Threshold defaults to -1 (only strictly overlapping ranges are merged).
    - Useful for cleaning up scattered, overlapping, or adjacent ranges.
[==============================================================================}
function TRangeArrayHelper.Mergify(const threshold: Integer = -1): Integer; overload;
var
  h, i, w: Integer;
begin
  h := High(Self);
  Result := 0;
  if (h < 1) then
    Exit;
  Self.Normalizify;
  Self.SortByStart;
  for i := 1 to h do
    if (Self[i].start > (Self[Result].stop + threshold + 1)) then
      Self[Result.Increment] := Self[i]
    else if (Self[i].stop > Self[Result].stop) then
      Self[Result].stop := Self[i].stop;
  SetLength(Self, Result.Increment);
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

{==============================================================================]
  <Stream>
  @action: Flattens all ranges into individual integers, removes duplicates, sorts them,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - Produces a fully canonical, minimal set of disjoint ranges.
    - Duplicates and overlapping integers are automatically removed.
    - The parameter oAscending controls the ordering of the output.
    - Internally flattens ranges to integers, so large ranges may consume more memory temporarily.
[==============================================================================}
function TRangeArrayHelper.Stream(const oAscending: Boolean = True): TRangeArray; overload;
var
  i, j, r, l: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(s, Self.Sized);
  r := 0;
  for i := 0 to (l - 1) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s[r.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, l);
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if ((Result[r].stop + j) = s[i]) then
      Result[r].stop := s[i]
    else if (s[i] <> s[i - 1]) then
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Streamed>
  @action: Flattens all ranges to individual integers, sorts and deduplicates them,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - The parameter oAscending controls the ordering of the output ranges.
    - Duplicates and overlapping ranges are removed automatically.
    - Produces a canonical, minimal set of disjoint ranges covering all integers.
    - May consume more memory temporarily for large ranges, due to flattening.
    - Result is fully normalized and ordered.
[==============================================================================}
function TRangeArrayHelper.Streamed(const oAscending: Boolean = True): TRangeArray; overload;
var
  i, j, r, l: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(s, Self.Sized);
  r := 0;
  for i := 0 to (l - 1) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s[r.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, l);
  s.Compress;
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if ((Result[r].stop + j) = s[i]) then
      Result[r].stop := s[i]
    else
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Streamline>
  @action: Produces a canonical union of all ranges in the array. 
           Handles reversed, overlapping, or disordered ranges, 
           and outputs the minimal set of disjoint, contiguous ranges.
  @note:
    - Internally uses a bitmap to track all integers in all ranges.
    - All duplicates, overlaps, and reversed ranges are automatically handled.
    - Result covers every integer present in any input range exactly once.
    - This is effectively a “streamed union” operation.
[==============================================================================}
function TRangeArrayHelper.Streamline: TRangeArray; overload;
var
  a, h, i, p, s, o: Integer;
  n: TRangeArray;
  r: TRange;
  b: TBooleanArray;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(n, (h + 1));
  r := Self[0].Normalized;
  for i := 0 to h do
  begin
    if (Self[i].start <= Self[i].stop) then
      n[i] := Self[i]
    else
      n[i] := Self[i].Reversed;
    if (n[i].start < r.start) then
      r.start := n[i].start;
    if (n[i].stop > r.stop) then
      r.stop := n[i].stop;
  end;
  o := -r.start;
  SetLength(b, (r.stop + o + 2));
  for i := 0 to High(n) do
    for p := n[i].start to n[i].stop do
      b[p + o] := True;
  SetLength(Result, 0);
  p := 0;
  a := High(b);
  while (p <= a) do
    if b[p] then
    begin
      s := p;
      while ((p <= a) and b[p]) do
        Inc(p);
      Result.Supply(TRange.Construct((s - o), (p - 1 - o)));
    end else
      Inc(p);
end;

{==============================================================================]
  <Unite>
  @action: Merges overlapping or adjacent ranges in a TRangeArray into the smallest
           set of disjoint ranges. Produces a canonical union of all ranges.
  @note:
    - If mAdjacent is True, ranges that are immediately contiguous (stop + 1 >= start)
      are merged as well.
    - If mAdjacent is False, only strictly overlapping ranges are merged.
    - Input ranges are normalized and sorted internally before merging.
    - Returns an empty array if the input array has fewer than two ranges.
    - Result preserves ascending order by start value.
[==============================================================================}
function TRangeArrayHelper.Unite(const mAdjacent: Boolean = True): TRangeArray; overload;
var
  i, l, r: Integer;
  m: Boolean;
begin
  Result := Self.Normalized;
  l := Result.Length;
  if (l < 2) then
    Exit;
  Result.SortByStart;
  r := 0;
  for i := 1 to (l - 1) do
  begin
    if mAdjacent then
      m := (Result[i].start <= (Result[r].stop + 1))
    else
      m := Result[r].Overlap(Result[i]);
    if m then
      Result[r].stop := Max(Result[r].stop, Result[i].stop)
    else
      Result[r.Increment] := Result[i];
  end;
  SetLength(Result, (r + 1));
end;
{$ENDIF}
