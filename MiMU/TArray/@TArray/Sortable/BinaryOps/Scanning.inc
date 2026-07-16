{$IFDEF HELPERS}
function BinaryCluster(const start: Integer; const allowed: MArray; const aAscending: Boolean = True): TRange; overload;
function BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryIndices(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInterval(const item: MType; const oAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCluster>
  @action: Starting at <start>, expands left and right to determine the maximal
           contiguous range of elements whose values are contained in <allowed>.
           Membership is verified using binary search on <allowed>.
  @note:
    - <start> must be a valid index within the array.
    - The element at <start> must exist in <allowed>.
    - <allowed> must be sorted according to <aAscending>.
    - Returns (-1, -1) if:
        * <start> is invalid,
        * <allowed> is empty, or
        * Self[<start>] is not contained in <allowed>.
    - Time complexity: O(k log m), where:
        k = size of the resulting cluster,
        m = length of <allowed>.
[==============================================================================}
function MArrayHelper.BinaryCluster(const start: Integer; const allowed: MArray; const aAscending: Boolean = True): TRange; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if not ((start > -1) and (start < l) and (allowed.Length > 0) and (allowed.BinarySearchBy(Self[start], aAscending) > -1)) then
    Exit(TRange.Construct(-1, -1));
  Result := TRange.Construct(start, start);
  while ((Result.start > -1) and (allowed.BinarySearchBy(Self[Result.start - 1], aAscending) > -1)) do
    Dec(Result.start);
  l := Self.Length;
  while ((Result.stop < l) and (allowed.BinarySearchBy(Self[Result.stop + 1], aAscending) > -1)) do
    Inc(Result.stop);
end;

{==============================================================================]
  <BinaryHits>
  @action: Performs a binary search for each value in the supplied array
           `items` against the current integer array and returns the indices
           of all values that are found.
  @note:   The current array (`Self`) must be sorted according to the
           `oAscending` flag prior to calling this method. The result contains
           only successful hit indices, in the same order as the `items`
           parameter. Items not found are silently ignored.
[==============================================================================}
function MArrayHelper.BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, p, k: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  SetLength(Result, items.Length);
  k := 0;
  for i := 0 to High(items) do
  begin
    p := Self.BinarySearchBy(items[i], oAscending);
    if (p >= 0) then
      Result[k.Increase] := p;
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <BinaryHitsOf>
  @action: Performs a binary search for each element in the supplied array `items`
           against the current array (`Self`) and returns the indices of all elements
           that are found.
           For every value in `items`, `BinarySearch` is invoked on `Self`. If the value
           exists, the index returned by `BinarySearch` is collected into the result
           array. The result therefore represents the hit positions within `Self`,
           not within `items`.
  @note:
    - `Self` must be sorted according to the order specified by `oAscending`
      for `BinarySearch` to operate correctly.
    - If either `Self` or `items` is empty, the function returns an empty array.
    - If the same value appears multiple times in `items`, its hit index in
      `Self` may appear multiple times in the result.
    - The function performs two passes over `items`: one to count hits and one
      to populate the result array.
[==============================================================================}
function MArrayHelper.BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, p, r: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  r := 0;
  for i := 0 to High(items) do
    if (Self.BinarySearchBy(items[i], oAscending) >= 0) then
      Inc(r);
  SetLength(Result, r);
  r := 0;
  for i := 0 to High(items) do
  begin
    p := Self.BinarySearchBy(items[i], oAscending);
    if (p >= 0) then
      Result[r.Increase] := p;
  end;
end;

{==============================================================================]
  <BinaryIndices>
  @action: Performs batch membership position lookup between the current array and
           a sorted query array. Returns the list of indices in the current array
           where elements exist in the provided `items` collection.
  @note:
    - The query array `items` is internally sorted before searching.
    - Binary search is used for membership testing.
    - Duplicate matches may result in multiple indices being returned.
    - The function excludes non-existent matches (no -1 values are returned).
    - Time complexity is approximately O(n log m), where:
        n = length of Self
        m = length of items
    - If `items` is empty, the function returns an empty array.
    - The search ordering follows `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryIndices(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, p, c: Integer;
  t: MArray;
begin
  if items.Empty then
    Exit([]);
  SetLength(Result, Self.Length);
  c := 0;
  t := items.QuickSorted(oAscending);
  for i := 0 to High(Result) do
    if (t.BinarySearchBy(Self[i], oAscending) > -1) then
      Result[c.Increase] := i;
  SetLength(Result, c);
end;

{==============================================================================]
  <BinaryInterval>
  @action: Performs a binary search for <item> in a sorted array and returns the
           contiguous interval (range) of all elements equal to <item>.
  @note:
    - The array must be sorted in ascending or descending order as specified
      by <oAscending>.
    - If <item> is not found, the returned range has Start = -1.
    - Time complexity: O(log n + k), where k is the number of equal elements.
[==============================================================================}
function MArrayHelper.BinaryInterval(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  l: Integer;
begin
  Result.Create(Self.BinarySearchBy(item, oAscending));
  if (Result.start = -1) then
    Exit;
  while ((Result.start > -1) and (Self[Result.start - 1] = item)) do
    Dec(Result.start);
  l := Self.Length;
  while ((Result.stop < l) and (Self[Result.stop + 1] = item)) do
    Inc(Result.stop);
end;
{$ENDIF}