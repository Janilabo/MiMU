{$IFDEF HELPERS}
function BinaryIdentify(const aIndex: Integer; const iItems: MArray; const iAscending: Boolean = True): Integer; overload;
function BinaryMode: MType; overload;
function BinaryNeighbors(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryPercented(const item: MType; const oAscending: Boolean = True): Double; overload;
function BinaryPercentile(const item: MType; const oAscending: Boolean = True): Double; overload;
function BinaryPopular(const oAscending: Boolean = True): MType; overload;
function BinaryRanking(const item: MType; const oAscending: Boolean = True): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryIdentify>
  @action: Performs a binary search to find the position of the element at aIndex
           within a sorted array (items). Returns the zero-based index of the matching element.
  @note:
    • The array (items) must be sorted in ascending or descending order,
      as specified by iAscending.
    • Returns -1 if:
      - aIndex is out of bounds, or
      - the value is not found in items.
    • This method is optimized for large arrays, providing O(log n) search
      complexity compared to a linear scan.
[==============================================================================}
function MArrayHelper.BinaryIdentify(const aIndex: Integer; const iItems: MArray; const iAscending: Boolean = True): Integer; overload;
begin
  if ((aIndex  > -1) and (aIndex < Self.Length)) then
    Result := iItems.BinarySearchBy(Self[aIndex], iAscending)
  else
    Result := -1;
end;

{==============================================================================]
  <BinaryMode>
  @action: Returns the mode (most frequent value) of a sorted array.
  @note:
    • O(n)
    • Requires sorted array
    • Scans once, counting consecutive identical values
    • Returns first element if array is empty
    • In case of ties, returns the first value with maximum frequency
[==============================================================================}
function MArrayHelper.BinaryMode: MType; overload;
var
  i, c, m: Integer;
  s: MType;
begin
  if Self.Empty then
    Exit;
  Result := Self[0];
  m := 1;
  c := 1;
  s := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] <> s) then
    begin
      if (c > m) then
      begin
        m := c;
        Result := s;
      end;
      s := Self[i];
      c := 1;
    end else
      Inc(c);
  if (c > m) then
    Result := s;
end;

{==============================================================================]
  <BinaryNeighbors>
  @action: Finds the closest lower and upper neighbors around a target
           value in a sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           TRange.start -> index of the largest element ≤ item (predecessor)
           TRange.stop  -> index of the smallest element ≥ item (successor)
           If no predecessor exists, start = -1
           If no successor exists, stop = -1
         Example:
           Ascending array: [1,3,5,7] item = 4 BinaryNeighbors(item) -> start=1 (3), stop=2 (5)
[==============================================================================}
function MArrayHelper.BinaryNeighbors(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  l, x: Integer;
begin
  l := Self.Length;
  Result.Create(-1, -1);
  if (l = 0) then
    Exit;
  x := Self.BinaryThreshold(item, oAscending);
  if (x > 0) then
    Result.start := (x - 1);
  if (x < l) then
    Result.stop := x;
end;

{==============================================================================]
  <BinaryPercented>
  @action: Returns the percentile rank position of a specified item within a
           sorted array using binary search.
  @note: The result represents the relative position of the item in the array
         on a scale from 0..100 where the first element corresponds to 0%
         and the last element corresponds to 100%. If the item is not found,
         the insertion index returned by BinarySearchBy is used. The array
         must be sorted according to oAscending.
[==============================================================================}
function MArrayHelper.BinaryPercented(const item: MType; const oAscending: Boolean = True): Double; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0.0);
  if (l = 1) then
    Exit(100.0);
  p := Self.BinarySearchBy(item, oAscending);
  if (p < 0) then
    p := not p;
  if (p > (l - 1)) then
    p := (l - 1);
  Result := ((p / (l - 1)) * 100.0);
end;

{==============================================================================]
  <BinaryPercentile>
  @action: Returns the percentile position of a value within a sorted array using
           binary search.
           Behavior:
            • O(log n) search complexity
            • Returns value in range [0..1]
            • If the item exists → percentile of its index
            • If not → percentile of its insertion position
            • Works with ascending or descending arrays
  @note: Percentile definition: P = index / (N - 1)
[==============================================================================}
function MArrayHelper.BinaryPercentile(const item: MType; const oAscending: Boolean = True): Double; overload;
var
  M, H: Integer;
  R: TRange;
begin
  H := High(Self);
  if (H <= 0) then
    Exit(0.0);
  R.Create(0, H);
  while (R.start <= R.Stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M / H);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item)))  then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := (R.start / H);
end;

{==============================================================================]
  <BinaryPopular>
  @action: Returns the most frequent value (mode) in a sorted array using
           binary search to determine the size of duplicate ranges.
  @note: The array must be sorted in ascending or descending order depending
         on oAscending. If multiple values share the same maximum frequency,
         the first encountered value is returned.
		 Returns nothing if array is empty!
[==============================================================================}
function MArrayHelper.BinaryPopular(const oAscending: Boolean = True): MType; overload;
var
  i, c, r, l, s: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit;
  r := 0;
  Result := Self[0];
  i := 0;
  while (i < l) do
  begin
    s := Self.BinaryStop(Self[i], oAscending);
    if (s < i) then
      s := i;
    c := ((s - i) + 1);
    if (c > r) then
    begin
      r := c;
      Result := Self[i];
    end;
    i := (s + 1);
  end;
end;

{==============================================================================]
  <BinaryRanking>
  @action: Returns the percentile rank position of a specified item within a
           sorted array using binary search.
  @note: The returned value represents the relative position of the item in
         the array as a percentage in the range [0..100). If the item is not
         present, the insertion index returned by BinarySearchBy is used to
         estimate where the item would be placed. The array must be sorted in
         ascending or descending order depending on oAscending.
[==============================================================================}
function MArrayHelper.BinaryRanking(const item: MType; const oAscending: Boolean = True): Double; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0.0);
  p := Self.BinarySearchBy(item, oAscending);
  if (p < 0) then
    p := not p;
  Result := ((p / l) * 100);
end;
{$ENDIF}
