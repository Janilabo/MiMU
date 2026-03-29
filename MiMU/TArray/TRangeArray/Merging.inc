{$IFDEF HELPERS}
function Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
function Defragment(const rAscending: Boolean = True): TRangeArray; overload;
function Fuse: TRangeArray; overload;
function Merge: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
