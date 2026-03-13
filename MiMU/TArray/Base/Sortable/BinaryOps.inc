{$IFDEF HELPERS}
function BinaryBoundaries(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundary(const threshold: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundLower(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBounds(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBracket(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryCardinality(const itemMin, itemMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCeiled(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMax(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMin(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCluster(const start: Integer; const allowed: MArray; const aAscending: Boolean = True): TRange; overload;
function BinaryContain(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryConverge(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCounter(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryDomain(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryEncase(const item: MType): Boolean; overload;
function BinaryExcept(const target: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryExist(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindID(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindIndex(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFloored(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFrequency(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGallopingSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHasVariance: Boolean; overload;
function BinaryHave(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryIdentify(const aIndex: Integer; const iItems: MArray; const iAscending: Boolean = True): Integer; overload;
function BinaryIndices(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryInterval(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryIsConstant: Boolean; overload;
function BinaryIsUnique: Boolean; overload;
function BinaryItem(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryLeftside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryMajority(out oItem: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryMajority(const oAscending: Boolean = True): Boolean; overload;
function BinaryMembership(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryMetaSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryMode: MType; overload;
function BinaryNeighbors(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryOccurrence(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrences(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrency(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPercented(const item: MType; const oAscending: Boolean = True): Double; overload;
function BinaryPercentile(const item: MType; const oAscending: Boolean = True): Double; overload;
function BinaryPopular(const oAscending: Boolean = True): MType; overload;
function BinaryPredecessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryProbe(const item: MType; const oAscending: Boolean = True; const probeRadius: Integer = 5): Integer; overload;
function BinaryProbe(const item: MType; const probeRadius: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryProxy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRanking(const item: MType; const oAscending: Boolean = True): Double; overload;
function BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function BinaryRightside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySlice(const itemMin, itemMax: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySpot(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryStart(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryStop(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySuccessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryThreshold(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUniformSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryWithout(const target: MArray; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundaries>
  @action: Searches the sorted array for the contiguous occurrence block of the
           specified item and returns its index interval boundaries.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs a boundary pre-check using WithinBounds().
         If the item is found, the function expands the match position to the
         full occurrence domain by scanning left and right while adjacent
         elements are equal to the item.
         Returns TRange(start = -1, stop = -1) if the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryBoundaries(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  H, M: Integer;
  R: TRange;
begin
  Result.Create(-1, -1);
  H := High(Self);
  if ((H = -1) or (not Self.WithinBounds(item, oAscending))) then
    Exit;
  R.Create(0, H);
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result.start := M;
      Result.stop := M;
      while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
        Dec(Result.start);
      while ((Result.stop < H) and (Self[Result.stop + 1] = item)) do
        Inc(Result.stop);
      Exit;
    end;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinaryBoundary>
  @action: Finds the index of the first element that meets or exceeds a threshold
           in a sorted array, respecting ascending or descending order.
           Conceptually, this is the “boundary” where values transition relative
           to the threshold.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the first element ≥ threshold (ascending)
           - Index of the first element ≤ threshold (descending)
           - If no such element exists, returns Length(Self)
         Internally uses BinaryBoundLower / BinaryBoundUpper helpers.
[==============================================================================}
function MArrayHelper.BinaryBoundary(const threshold: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.BinaryBoundLower(threshold, oAscending)
  else
    Result := Self.BinaryBoundUpper(threshold, oAscending);
end;

{==============================================================================]
  <BinaryBoundLower>
  @action: Performs a binary search to determine the lower boundary insertion
           position for the specified item in the sorted array.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Returns the first index where:
           - array[index] >= item (ascending order)
           - array[index] <= item (descending order)
         If the item is greater than all elements (or smaller in descending
         order), returns Length(Self).
[==============================================================================}
function MArrayHelper.BinaryBoundLower(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Length;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if not ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  until False;
end;

{==============================================================================]
  <BinaryBounds>
  @action: Returns the inclusive lower and upper bounds of <item> within the
           sorted array using binary search.
  @note:
    - The array must be sorted according to <oAscending>.
    - Returns (-1, -1) if <item> is not present.
    - Time complexity: O(log n).
[==============================================================================}
function MArrayHelper.BinaryBounds(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  M, L: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(TRange.Construct(-1, -1));
  R.Create(0, (L - 1));
  Result.start := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result.start := M;
      R.stop := (M - 1);
    end else if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result.stop := Result.start;
  if (Result.start = -1) then
    Exit;
  R.Create(Result.start, (L - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result.stop := M;
      R.start := (M + 1);
    end else if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryBoundUpper>
  @action: Performs a binary search to determine the upper boundary insertion
           position for the specified item in the sorted array.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Returns the first index where:
           - array[index] > item (ascending order)
           - array[index] < item (descending order)
         If no such position exists, returns Length(Self).
[==============================================================================}
function MArrayHelper.BinaryBoundUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Length;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if not ((oAscending and (Self[M] <= item)) or ((not oAscending) and (Self[M] >= item))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  until False;
end;

{==============================================================================]
  <BinaryBracket>
  @action: Returns indices of the nearest elements surrounding item.
  @note: Always returns valid indices within the array.
         start -> index of predecessor
         stop  -> index of successor
         If item is outside array bounds, both indices clamp to
         the nearest edge element.
[==============================================================================}
function MArrayHelper.BinaryBracket(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  M, L: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(TRange.Construct(-1, -1));
  R.Create(0, (L - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(TRange.Construct(M, M));
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  if (R.stop < 0) then
    Result.Create(0, 0)
  else if (R.start >= L) then
    Result.Create((L - 1), (L - 1))
  else
    Result.Create(R.stop, R.start);
end;

{==============================================================================]
  <BinaryCardinality>
  @action: Counts the number of elements within a specified value interval
           `[itemMin..itemMax]` in a sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Number of elements whose values fall within the interval
           - 0 if no elements lie in the range or the array is empty
         Duplicate values are counted individually.
         Internally uses BinaryBoundLower / BinaryBoundUpper.
[==============================================================================}
function MArrayHelper.BinaryCardinality(const itemMin, itemMax: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, h: MType;
begin
  if (Self.Length = 0) then
    Exit(0);
  if (itemMin <= itemMax) then
  begin
    l := itemMin;
    h := itemMax;
  end else
  begin
    l := itemMax;
    h := itemMin;
  end;
  if oAscending then
    Result := (Self.BinaryBoundUpper(h, oAscending) - Self.BinaryBoundLower(l, oAscending))
  else
    Result := (Self.BinaryBoundUpper(l, oAscending) - Self.BinaryBoundLower(h, oAscending));
  if (Result < 0) then
    Result := 0;
end;

{==============================================================================]
  <BinaryCeiled>
  @action: Finds the index of the smallest element whose value is greater than
           or equal to the specified item in a sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the element equal to `item` if it exists
           - Otherwise the index of the nearest element whose value is not
             less than `item` (ceiling)
           - If `item` is smaller than all elements, returns 0
           - If `item` is greater than all elements, returns High(Self)
           - Returns -1 if the array is empty
         The result is always clamped to a valid array index.
[==============================================================================}
function MArrayHelper.BinaryCeiled(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  H, M: Integer;
  R: TRange;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  if (R.start > H) then
    Exit(H);
  if (R.stop < 0) then
    Exit(0);
  Result := R.start;
end;

{==============================================================================]
  <BinaryClampMax>
  @action: Removes elements greater than aMax from a sorted array using a binary boundary scan.
          The scan searches the upper valid boundary depending on whether the array is sorted in ascending or descending order,
		  then compacts the array in place and truncates it.
  @note: The function assumes the array is already sorted according to oAscending.
         It returns the number of elements removed (original length minus the clamped length).
		 If no elements exceed the upper bound, the array is unchanged and the function returns 0.
[==============================================================================}
function MArrayHelper.BinaryClampMax(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
var
  c, i, l: Integer;
  r: TRange;
begin
  Result := 0;
  l := Self.Length;
  if ((l = 0) or ((oAscending and (Self[l - 1] < aMax)) or ((not oAscending) and (Self[0] < aMax)))) then
    Exit;
  r.Create(0, (l - 1));
  case oAscending of
    True:
    begin
      while (r.stop > -1) do
        if (Self[r.stop] > aMax) then
          Dec(r.stop)
        else
          Break;
      if (r.stop = -1) then
        Exit(0);
    end;
    False:
    begin
      while (r.start < l) do
        if  (Self[r.start] > aMax) then
          Inc(r.start)
        else
          Break;
      if (r.start = l) then
        Exit(0);
      Result := (l - r.start);
    end;
  end;
  c := r.Size;
  Result := (l - c);
  if (Result > 0) then
  begin
    for i := r.start to r.stop do
      Self[i - r.start] := Self[i];
    SetLength(Self, c);
  end;
end;

{==============================================================================]
  <BinaryClampMin>
  @action: Removes elements less than aMin from a sorted array using a binary boundary scan.
           The scan locates the lower valid boundary according to sort direction,
		   then shifts remaining elements forward and truncates the array.
  @note: The array must maintain the sorting invariant defined by oAscending.
         The function returns the count of removed elements. If no elements violate the lower bound,
		 the array remains unchanged and the function returns 0.
[==============================================================================}
function MArrayHelper.BinaryClampMin(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
var
  c, i, l: Integer;
  r: TRange;
begin
  Result := 0;
  l := Self.Length;
  if ((l = 0) or ((oAscending and (Self[0] > aMin)) or ((not oAscending) and (Self[l - 1] > aMin)))) then
    Exit;
  r.Create(0, (l - 1));
  case oAscending of
    True:
    begin
      while (r.start < l) do
        if (Self[r.start] < aMin) then
          Inc(r.start)
        else
          Break;
      if (r.start = l) then
        Exit(0);
    end;
    False:
    begin
      while (r.stop > -1) do
        if  (Self[r.stop] < aMin) then
          Dec(r.stop)
        else
          Break;
      if (r.stop = -1) then
        Exit(0);
    end;
  end;
  c := r.Size;
  Result := (l - c);
  if (Result > 0) then
  begin
    for i := r.start to r.stop do
      Self[i - r.start] := Self[i];
    SetLength(Self, c);
  end;
end;

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
  p, l: Integer;
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
  <BinaryContain>
  @action: Determines whether the specified item exists in the sorted array
           using a binary search over a narrowing range window.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs boundary pre-check via WithinBounds().
         Utilizes TRange abstraction for search window management.
         Time complexity: O(log n).
         Space complexity: O(1).
         Returns False if the array is empty or the item is not found.
[==============================================================================}
function MArrayHelper.BinaryContain(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  if (Self.Empty or (not Self.WithinBounds(item, oAscending))) then
    Exit(False);
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit(False);
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True);
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinaryConverge>
  @action: Performs binary search convergence and returns the candidate index
           reached by the search path.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function searches for the specified item and returns:
           - The index of the item if found.
           - Otherwise the terminal convergence candidate index of the binary
             search path.
         Returns:
           0..Length(Self)-1 -> array index candidate
           -1                -> array is empty
         This function does not guarantee that the item exists in the array.
         It represents the final convergence position of the binary search
         traversal.
[==============================================================================}
function MArrayHelper.BinaryConverge(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    Result := M;
    if (Self[M] = item) then
      Break;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryCounter>
  @action: Counts the number of occurrences of the specified item in the
           sorted array using binary search assisted boundary expansion.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function first locates the first occurrence of the item using
         BinaryFindID, then expands linearly to the left and right boundaries
         of the matching block to determine the total number of occurrences.
         Returns:
           0  -> item does not exist in the array
           >0 -> number of occurrences of the item
         Internal Steps:
           1. Binary search to locate a candidate position.
           2. Expand search window while adjacent elements match the item.
[==============================================================================}
function MArrayHelper.BinaryCounter(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  H, i, L, R: Integer;
begin
  i := Self.BinaryFindID(item, oAscending);
  if (i = -1) then
    Exit(0);
  L := i;
  R := i;
  H := High(Self);
  while ((L > 0) and (Self[L - 1] = item)) do
    Dec(L);
  while ((R < H) and (Self[R + 1] = item)) do
    Inc(R);
  Result := ((R - L) + 1);
end; 

{==============================================================================]
  <BinaryDomain>
  @action: Returns the contiguous index range where the specified item exists
           within the sorted array using binary search bounds.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function combines BinaryStart() and BinaryStop() to construct
         the domain interval [start, stop] where item occurs.
         Returns TRange with start = -1 and stop = -1 if the item is not found.
[==============================================================================}
function MArrayHelper.BinaryDomain(const item: MType; const oAscending: Boolean = True): TRange; overload;
begin
  Result.start := Self.BinaryStart(item, oAscending);
  if (Result.start = -1) then
    Result.stop := -1
  else
    Result.stop := Self.BinaryStop(item, oAscending);
end;

{==============================================================================]
  <BinaryEncase>
  @action: Determines whether the specified item falls within the range of values
           in a sorted array. The function returns True if the item is greater
           than or equal to the smallest element and less than or equal to the
           largest element, regardless of whether the array is ascending or
           descending.
  @note: Works for arrays of any length, including empty arrays.
         - Returns False for empty arrays.
         - Correctly handles both ascending and descending order arrays.
         - Only checks the array’s first and last elements; does not search
           for exact membership.
[==============================================================================}
function MArrayHelper.BinaryEncase(const item: MType): Boolean; overload;
var
  b, t: MType;
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(False);
  if (Self[0] < Self[h]) then
  begin
    b := Self[0];
    t := Self[h];
  end else
  begin
    b := Self[h];
    t := Self[0];
  end;
  Result := ((item >= b) and (item <= t));
end;

{==============================================================================]
  <BinaryExcept>
  @action: Returns the set difference of two arrays (elements in Self that are NOT in target),
           supporting both ascending and descending sorted arrays.
  @param: target      – A sorted array to compare against Self.
  @param: oAscending  – Boolean flag indicating the sort order of both arrays:
                        True = ascending (default), False = descending.
  @return: A new MArray containing elements from Self that do not appear in target.
  @note:
    - Both Self and target must be sorted in the order specified by oAscending; otherwise, the result may be incorrect.
    - Efficient linear scan: O(L + T), where L = Length(Self), T = Length(target).
    - Does not modify the original arrays; returns a new array.
    - If Self is empty, returns an empty array.
    - If target is empty, returns a copy of Self.
  @example:
    // Ascending arrays
    Self = [1,2,3,4,5], target = [2,4], oAscending = True -> Result = [1,3,5]
    // Descending arrays
    Self = [5,4,3,2,1], target = [4,2], oAscending = False -> Result = [5,3,1]
    // Empty target
    Self = [1,3,5], target = [], oAscending = True -> Result = [1,3,5]
[==============================================================================}
function MArrayHelper.BinaryExcept(const target: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i, j, k, l, t: Integer;
begin
  t := target.Length;
  if (t = 0) then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  i := 0;
  j := 0;
  k := 0;
  case oAscending of
    True:
    while (i < l) do
      if ((j >= t) or (Self[i] < target[j])) then
        Result[k.Increase] := Self[i.Increase]
      else if (Self[i] > target[j]) then
        Inc(j)
      else
        Inc(i);
	False:
	while (i < l) do
      if ((j >= t) or (Self[i] > target[j])) then
        Result[k.Increase] := Self[i.Increase]
      else if (Self[i] < target[j]) then
        Inc(j)
      else
        Inc(i);
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <BinaryExist>
  @action: Determines whether the specified item in the sorted array
           using a branch-reduced binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Uses a reduced branching condition:
           (Self[M] < item) = oAscending
         to decide which half of the search range to continue with.
[==============================================================================}
function MArrayHelper.BinaryExist(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True);
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := False;
end;

{==============================================================================]
  <BinaryExpSearch>
  @action: Performs an exponential (galloping) search to locate the specified
           item in a sorted TIntegerArray. Returns the index of the item if
           found; otherwise returns -1. Combines exponential range expansion
           with standard binary search within the identified range.
  @note: The array must be pre-sorted according to 'oAscending'. Efficient
         for large arrays or targets near the beginning. Supports ascending
         (default) and descending arrays. Time complexity is O(log n).
[==============================================================================}
function MArrayHelper.BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  B, L: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(-1);
  B := 1;
  while ((B < L) and ((oAscending and (Self[B] < item)) or ((not oAscending) and (Self[B] > item)))) do
    B := (B * 2);
  R.Create((B div 2), Min(B, (L - 1)));
  while (R.start <= R.stop) do
  begin
    Result := R.Pivot;
    if (Self[Result] = item) then
      Exit;
    if ((oAscending and (Self[Result] < item)) or ((not oAscending) and (Self[Result] > item))) then
      R.start := (Result + 1)
    else
      R.stop := (Result - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryFindID>
  @action: Locates the specified item in the sorted array using binary search
           and returns its array index position.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns the 0-based index position of the first
         occurrence of the item in the array.
         Returns:
           0..Length(Self)-1 -> array index of the item
           -1                -> item does not exist in the array
         Internally uses BinaryBoundLower to determine the candidate
         position and verifies equality before returning the index.
[==============================================================================}
function MArrayHelper.BinaryFindID(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryBoundLower(item, oAscending);
  if not ((Result < Self.Length) and (Self[Result] = item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryFindIndex>
  @action: Locates the specified item in the sorted array using binary search
           and returns its array index position.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns the 0-based index position of the first
         occurrence of the item in the array.
         Returns:
           0..Length(Self)-1 -> array index of the item
           -1                -> item does not exist in the array
         Internally uses BinaryBoundLower to determine the candidate
         position and verifies equality before returning the index.
[==============================================================================}
function MArrayHelper.BinaryFindIndex(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryBoundLower(item, oAscending);
  if ((Result = Self.Length) or (Self[Result] <> item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryFindLeft>
  @action: Locates the first occurrence of a specified value in a sorted array
           using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the first element equal to `item`
           - -1 if the value does not exist in the array
         Internally uses BinaryBoundLower to locate the candidate index
         and verifies equality.
[==============================================================================}
function MArrayHelper.BinaryFindLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryBoundLower(item, oAscending);
  if not ((Result > -1) and (Result < Self.Length) and (Self[Result] = item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryFindRight>
  @action: Locates the last occurrence of a specified value in a sorted array
           using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the last element equal to `item`
           - -1 if the value does not exist in the array
         Internally uses BinaryBoundUpper to locate the first element greater
         than `item`, then steps one position back to obtain the last match.
[==============================================================================}
function MArrayHelper.BinaryFindRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Self.BinaryBoundUpper(item, oAscending) - 1);
  if not ((Result > -1) and (Result < Self.Length) and (Self[Result] = item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryFloored>
  @action: Finds the index of the largest element whose value is less than or
           equal to the specified item in a sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the element equal to `item` if it exists
           - Otherwise the index of the nearest element whose value does not
             exceed `item` (floor)
           - If `item` is smaller than all elements, returns 0
           - If `item` is greater than all elements, returns High(Self)
           - Returns -1 if the array is empty
         The result is always clamped to a valid array index.
[==============================================================================}
function MArrayHelper.BinaryFloored(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  H, M: Integer;
  R: TRange;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  if (R.start > H) then
    Exit(H);
  if (R.stop < 0) then
    Exit(0);
  Result := R.stop;
end;

{==============================================================================]
  <BinaryFrequency>
  @action: Returns the number of occurrences of a specified item in a sorted array
           using binary search to locate the first and last matching indices.
  @note: The array must be sorted in either ascending or descending order
         depending on the value of oAscending. Returns 0 if the item is not found.
         Internally uses BinaryStart and BinaryStop to determine the range of
         matching elements.
[==============================================================================}
function MArrayHelper.BinaryFrequency(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  s: Integer;
begin
  s := Self.BinaryStart(item, oAscending);
  if (s = -1) then
    Exit(0);
  Result := ((Self.BinaryStop(item, oAscending) - s) + 1);
end;

{==============================================================================]
  <BinaryGallopingSearch>
  @action: Performs an exponential (galloping) range expansion to locate a bounded
           interval that may contain the specified item, followed by a binary search
           refinement within that interval.
           Returns the zero-based index of the matching element if found;
           otherwise returns -1.
  @note:
    - The array must be globally sorted in either ascending or descending
      order, as specified by oAscending.
    - Time complexity is O(log k), where k is the index distance to the target.
    - Particularly efficient when the sought element is located near the
      beginning of the array.
    - If duplicate values exist, any matching index may be returned.
[==============================================================================}
function MArrayHelper.BinaryGallopingSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  B, H, M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  H := High(Self);
  B := 1;
  case oAscending of
    True:
    begin
      while ((B <= H) and (Self[B] < item)) do
        B := (B shl 1);
      R.Create((B shr 1), Min(B, H));
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = item) then
          Exit(M);
        if (Self[M] < item) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
    end;
    False:
    begin
      while ((B <= H) and (Self[B] > item)) do
        B := (B shl 1);
      R.Create((B shr 1), Min(B, H));
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = item) then
          Exit(M);
        if (Self[M] > item) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryGot>
  @action: Performs a binary search on the array to determine
           whether a specified value exists and returns its index if found.
  @note: Assumes the array is pre-sorted in either ascending or descending
         order, depending on the oAscending flag. Uses TRange utilities
         for interval reduction; returns -1 when the item is not present.
[==============================================================================}
function MArrayHelper.BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    if (Self[index] = item) then
      Exit(True);
    if ((oAscending and (Self[index] < item)) or ((not oAscending) and (Self[index] > item))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end;

{==============================================================================]
  <BinaryHas>
  @action: Checks whether the specified item exists in the sorted integer array.
           Returns True if the item is found, otherwise False. If found, the
           index of the item is returned via the 'out' parameter.
  @note: The array must be pre-sorted according to the order specified by
         'oAscending'. Supports both ascending and descending arrays. Uses
          a standard binary search algorithm to efficiently locate the item.
[==============================================================================}
function MArrayHelper.BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
  C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := Self[index].Compare(item);
	if (C = 0) then
	  Exit(True);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  Result := False;
  index := -1;
end;

{==============================================================================]
  <BinaryHasVariance>
  @action: Returns True if the sorted array contains more than one distinct value.
  @note:
    • O(1)
    • Requires sorted array
    • Compares first and last elements only
    • False if array has zero or one element
[==============================================================================}
function MArrayHelper.BinaryHasVariance: Boolean; overload;
var
  H: Integer;
begin
  H := High(Self);
  Result := ((H > 0) and (Self[0] <> Self[H]));
end;

{==============================================================================]
  <BinaryHave>
  @action: Determines whether the specified item exists in the sorted array
           using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns True if the item exists in the array, otherwise False.
         Internally uses BinaryBoundLower to locate the first candidate
         position and verifies equality.
[==============================================================================}
function MArrayHelper.BinaryHave(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  i := Self.BinaryBoundLower(item, oAscending);
  Result := ((i < Self.Length) and (Self[i] = item));
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
  <BinaryInsertingSort>
  @action: Sorts the array in place using a binary-insertion approach.
           Each element is inserted into its correct position in the partially
           sorted portion of the array by performing a binary search to find
           the insertion point.
  @note:
    • Sorting is done in place, overwriting the original array.  
    • The optional parameter aAscending specifies sort order:
        - True  → ascending
        - False → descending  
    • Equality is determined using the Compare method of MType.  
    • Time complexity: O(n log n) for binary search + O(n²) for shifting,
      overall O(n²) in the worst case.  
    • Space complexity: O(n) due to the temporary copy used during sorting.  
    • Returns the length of the array.
[==============================================================================}
function MArrayHelper.BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
var
  a, i, m, c: Integer;
  s: MArray;
  r: TRange;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  SetLength(Self, 1);
  a := IfThen(aAscending, 1, -1);
  for i := 1 to (Result - 1) do
  begin
    r.Create(0, High(Self));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
	  c := s[i].Compare(Self[m]);
      if (c = 0) then
      begin
        r.start := m;
        Break;
      end;
      if (c = a) then
        r.start := (m + 1)
      else
	    r.stop := (m - 1);
    end;
    Insert(s[i], Self, r.start);
  end;
end;

{==============================================================================]
  <BinaryInsertingSorted>
  @action: Returns a new array containing all elements of the original array,
           sorted using binary-insertion. The original array is not modified.
  @note:
    • The returned array preserves the sorted order: ascending or descending,
      based on aAscending.  
    • Each element is inserted into the result array using binary search
      to find its correct position.  
    • Equality is determined using the Compare method of MType.  
    • Time complexity: O(n log n) for binary search + O(n²) for shifting,
      overall O(n²) worst case.  
    • Space complexity: O(n) due to building the new array.  
    • If the array contains fewer than two elements, a copy is returned unchanged.
[==============================================================================}
function MArrayHelper.BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
var
  l, a, i, m, c: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  Result := [Self[0]];
  a := IfThen(aAscending, 1, -1);
  for i := 1 to (l - 1) do
  begin
    r.Create(0, High(Result));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
	  c := Self[i].Compare(Result[m]);
      if (c = 0) then
      begin
        r.start := m;
        Break;
      end;
      if (c = a) then
        r.start := (m + 1)
      else
	    r.stop := (m - 1);
    end;
    Insert(Self[i], Result, r.start);
  end;
end;

{==============================================================================]
  <BinaryInsertion>
  @action: Inserts an item into a sorted array while preserving order.
  @note: Array must already be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns index where the element was inserted.
[==============================================================================}
function MArrayHelper.BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
procedure I(var arr: MArray; const index: Integer; const value: MType);
var
  a, N: Integer;
begin
  N := System.Length(arr);
  SetLength(arr, (N + 1));
  for a := N downto (index + 1) do
    arr[a] := arr[a - 1];
  arr[index] := value;
end;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := R.start;
  I(Self, Result, item);
end;

{==============================================================================]
  <BinaryInsertionSort>
  @action: Sorts the array in ascending or descending order using binary
           insertion sort, which combines binary search and insertion.
  @note: This algorithm runs in O(n²) time in the worst case but uses binary
         search to minimize comparisons. It performs well on small or
         partially sorted datasets. Returns the number of elements sorted.
[==============================================================================}
function MArrayHelper.BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
  function BP(const value: MType; const hIndex: Integer): Integer;
  var
    L, R, M: Integer;
  begin
    L := 0;
    R := hIndex;
    while (L <= R) do
    begin
      M := ((L + R) div 2);
      if ((aAscending and (Self[M] > value)) or ((not aAscending) and (Self[M] < value))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    Result := L;
  end;
var
  k: MType;
  i, j, p: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  for i := 1 to (Result - 1) do
  begin
    k := Self[i];
    p := BP(k, (i - 1));
    j := (i + 1);
    while (j.Decrement > p) do
      Self[j] := Self[j - 1];
    Self[p] := k;
  end;
end;

{==============================================================================]
  <BinaryInsertionSorted>
  @action: Returns a new array sorted using the Binary Insertion Sort algorithm.
           The insertion position for each element is determined via binary search
           within the already sorted left partition.
  @note:
    - Stable sorting algorithm.
    - In-place with respect to the returned copy (original array is unchanged).
    - Comparison complexity: O(n log n).
    - Data movement complexity: O(n²) due to element shifting.
    - Performs efficiently on small or nearly sorted datasets.
[==============================================================================}
function MArrayHelper.BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
var
  s, i, j, m, p: Integer;
  k: MType;
  r: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Result := Self.Copy;
  for i := 1 to (s - 1) do
  begin
    k := Result[i];
    p := 0;
    r.Create(0, (i - 1));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if ((aAscending and (k < Result[m])) or ((not aAscending) and (k > Result[m]))) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    p := r.start;
    j := i;
    while (j.Decrement >= p) do
      Result[j + 1] := Result[j];
    Result[p] := k;
  end;
end;

{==============================================================================]
  <BinaryInsertPosition>
  @action: Returns the insertion position where the specified item should be
           inserted to maintain sorted array order.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns:
           0 .. Length(Self)
           Position where item should be inserted.
         If the item already exists, the insertion position will be the
         first occurrence boundary.
[==============================================================================}
function MArrayHelper.BinaryInsertPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Length;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if not ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
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

{==============================================================================]
  <BinaryIsConstant>
  @action: Returns True if all elements in the sorted array are equal.
  @note:
    • O(1)
    • Requires sorted array
    • Compares first and last elements
    • False if array is empty
[==============================================================================}
function MArrayHelper.BinaryIsConstant: Boolean; overload;
var
  H: Integer;
begin
  H := High(Self);
  Result := ((H > -1) and (Self[0] = Self[H]));
end;

{==============================================================================]
  <BinaryIsUnique>
  @action: Returns True if the sorted array contains no duplicate values.
  @note:
    • O(n)
    • Requires sorted array
    • Adjacent elements are compared
    • False if array is empty
[==============================================================================}
function MArrayHelper.BinaryIsUnique: Boolean; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  for i := 0 to (h - 1) do
    if (Self[i] = Self[i + 1]) then
      Exit(False);
  Result := (h > -1);
end;

{==============================================================================]
  <BinaryItem>
  @action: Determines whether the specified item exists in the sorted array
           using binary search with a narrowing range abstraction.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Utilizes the TRange helper to maintain the search window.
         Returns False if the array is empty or the item is not found.
[==============================================================================}
function MArrayHelper.BinaryItem(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit(False);
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True);
    if ((oAscending and (item < Self[M])) or ((not oAscending) and (item > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  until False;
end;

{==============================================================================]
  <BinaryLeftside>
  @action: Searches the sorted array using binary search and returns the
           first index position where the specified item is found.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs binary search over a narrowing range window.
         Continues searching the left side of the match block to locate the
         earliest occurrence of the item.
         Returns -1 if the array is empty or the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryLeftside(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result := M;
      R.stop := (M - 1);
      Continue;
    end;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinaryMajority>
  @action: Determines whether the sorted array contains a majority element
           (an element occurring more than half of the array length) using
           binary search to measure the frequency of the middle value.
  @note: In a sorted array, any majority element must occupy the median
         position. The function therefore checks the value at index N div 2
         and counts its occurrences using BinaryStart and BinaryStop.
         If the count exceeds N div 2, the element is returned in oItem.
         Time complexity: O(log n). The array must be sorted according to
         oAscending.
[==============================================================================}
function MArrayHelper.BinaryMajority(out oItem: MType; const oAscending: Boolean = True): Boolean; overload;
var
  L, M: Integer;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(False);
  M := (L div 2);
  Result := ((Self.BinaryStop(Self[M]) - Self.BinaryStart(Self[M]) + 1) > M);
  if Result then
    oItem := Self[M];
end;

{==============================================================================]
  <BinaryMajority>
  @action: Returns True if the sorted array contains a majority element
           (an element occurring more than half the array length).
  @note: The majority candidate must appear at index N div 2 in a sorted
         array. The function verifies this by counting occurrences of the
         median value using BinaryStart and BinaryStop. Returns True when
         the count exceeds N div 2. Time complexity: O(log n).
         The array must be sorted according to oAscending.
[==============================================================================}
function MArrayHelper.BinaryMajority(const oAscending: Boolean = True): Boolean; overload;
var
  L, M: Integer;
begin
  L := Self.Length;
  case L of
    0: Exit(False);
	1: Exit(True);
  end;
  M := (L div 2);
  Result := ((Self.BinaryStop(Self[M]) - Self.BinaryStart(Self[M]) + 1) > M);
end;

{==============================================================================]
  <BinaryMembership>
  @action: Performs a binary search to determine whether the specified item
           exists within the helper array.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs a boundary pre-check via WithinBounds().
         Time complexity: O(log n).
         Returns False if the array is empty.
[==============================================================================}
function MArrayHelper.BinaryMembership(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  if (Self.Empty or (not Self.WithinBounds(item, oAscending))) then
    Exit(False);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True)
    else if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := False;
end;

{==============================================================================]
  <BinaryMetaSearch>
  @action: Performs a binary-like search on a sorted array to find the index of a given item.
  @note:
    • O(log n)
    • Requires sorted array (ascending or descending)
    • Returns index of item if found
    • Returns -1 if item is not in the array
    • Uses a binary meta-step approach instead of classic binary search
[==============================================================================}
function MArrayHelper.BinaryMetaSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, p, i, s: Integer;
begin
  l := Self.Length;
  i := (1 shl Trunc(Log2(l)));
  p := 0;
  while (i > 0) do
  begin
    s := (p or i);
    if ((s < l) and ((oAscending and (Self[s] <= item)) or ((not oAscending) and (Self[s] >= item)))) then
      p := s;
    i := (i shr 1);
  end;
  if ((p < l) and (Self[p] = item)) then
    Result := p
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
  <BinaryOccurrence>
  @action: Returns the number of occurrences of the specified item in the
           sorted array using binary boundary search primitives.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Computed as: Occurrence = BinaryBoundUpper(item) - BinaryBoundLower(item)
         If the item does not exist in the array, returns 0.
[==============================================================================}
function MArrayHelper.BinaryOccurrence(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Self.BinaryBoundUpper(item, oAscending) - Self.BinaryBoundLower(item, oAscending));
end;

{==============================================================================]
  <BinaryOccurrences>
  @action: Returns the number of occurrences of the specified item in the
           sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function determines the first and last occurrence of the item
         and computes the amount of matching elements.
         Returns:
           0  -> item does not exist
           >0 -> number of occurrences
[==============================================================================}
function MArrayHelper.BinaryOccurrences(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryStart(item, oAscending);
  if (Result > -1) then
    Result := (Self.BinaryStop(item, oAscending) - Result);
  Inc(Result);
end;

{==============================================================================]
  <BinaryOccurrency>
  @action: Returns the number of occurrences of the specified item in the
           sorted array using binary boundary search primitives.
  @note:   Requires the array to be sorted.
           oAscending = True  -> ascending order assumed.
           oAscending = False -> descending order assumed.
           Computed as: Occurrence = BinaryBoundUpper(item) - BinaryBoundLower(item)
           If the item does not exist in the array, returns 0.
           Time complexity: O(log n).
[==============================================================================}
function MArrayHelper.BinaryOccurrency(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, U: Integer;
begin
  L := Self.BinaryBoundLower(item, oAscending);
  U := Self.BinaryBoundUpper(item, oAscending);
  if (L >= U) then
    Exit(0);
  Result := (U - L);
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
  <BinaryPredecessor>
  @action: Returns the index of the largest element strictly less than item.
  @note: Requires sorted array.
         oAscending = True  -> ascending order
         oAscending = False -> descending order
         Returns:
           index of predecessor
           -1 if no predecessor exists
[==============================================================================}
function MArrayHelper.BinaryPredecessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
    begin
      Result := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryProbe>
  @action: Performs a hybrid divide-and-conquer search for `item` within the
           current array. At each binary pivot, the function first checks the
           pivot element and then linearly probes a symmetric neighborhood
           around the pivot defined by `probeRadius`. If no match is found
           within the probe window, the binary reduction continues.
           Returns the index of a matching element if found; otherwise returns -1.
  @note:
    - The array must be sorted according to `oAscending`.
    - The probe window at each iteration is:
        [M - probeRadius .. M + probeRadius]
      clamped to the current search bounds.
    - Effective window width is (2 * probeRadius + 1).
    - If duplicates exist, any matching index may be returned.
    - Worst-case time complexity remains O(log n), but each iteration
      incurs up to O(probeRadius) additional comparisons.
    - If probeRadius is 0, behavior degenerates to standard binary search.
    - No internal validation of sortedness is performed.
    - If the array is empty, returns -1.
[==============================================================================}
function MArrayHelper.BinaryProbe(const item: MType; const oAscending: Boolean = True; const probeRadius: Integer = 5): Integer; overload;
var
  M, I: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    for I := Max(R.start, (M - probeRadius)) to Min(R.stop, (M + probeRadius)) do
      if (Self[I] = item) then
        Exit(I);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := -1;
end;

function MArrayHelper.BinaryProbe(const item: MType; const probeRadius: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryProbe(item, oAscending, probeRadius);
end;

{==============================================================================]
  <BinaryProxy>
  @action: Performs a binary search for a value in a sorted array and returns
           the index of the last pivot inspected during the search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the matching element if `item` exists
           - Otherwise the index of the last pivot examined during the
             binary search (a position near where the item would appear)
           - -1 if the array is empty
         This method provides a fast approximate location that can be used
         as a starting point for nearby searches or adjustments.
[==============================================================================}
function MArrayHelper.BinaryProxy(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  Result := 0;
  while (R.start <= R.stop) do
  begin
    Result := R.Pivot;
    if (Self[Result] = item) then
      Exit;
    if ((oAscending and (Self[Result] < item)) or ((not oAscending) and (Self[Result] > item))) then
      R.start := (Result + 1)
    else
      R.stop := (Result - 1);
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

{==============================================================================]
  <BinaryRemoveAll>
  @action: Removes all elements from Self that also appear in the items array,
           modifying Self in place using a binary-style merge scan.
  @param: items      – Sorted array containing values to remove from Self.
  @param: oAscending  – Sort order of both arrays:
                        True  = arrays are sorted ascending (default)
                        False = arrays are sorted descending
  @return: The number of elements removed from Self.
  @note:
    - Both Self and items must already be sorted according to oAscending.
      If the ordering differs, the result is undefined.
    - Performs an in-place removal using a two-pointer linear scan.
      Time complexity: O(L + T), where L = Length(Self) and T = Length(target).
    - The array capacity is reused during compaction, then truncated to the
      new length at the end.
    - If no elements are removed, Self remains unchanged and the function
      returns 0.
    - Duplicate values in Self that match items values will all be removed.
[==============================================================================}
function MArrayHelper.BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  i, j, l, t, r: Integer;
begin
  t := items.Length;
  if (t = 0) then
    Exit(0);
  l := Self.Length;
  i := 0;
  j := 0;
  Result := 0;
  while (i < l) do
    if ((j < t) and (Self[i] = items[j])) then
      Inc(i)
    else if ((j < t) and ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j])))) then
      Inc(j)
    else
      Self[Result.Increase] := Self[i.Increase];
  if (l = Result) then
    Exit(0);
  SetLength(Self, Result);
  Result := (l - Result);
end;

{==============================================================================]
  <BinaryRightside>
  @action: Searches the sorted array using binary search and returns the
           last index position where the specified item is found.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oDescending = False -> descending order assumed.
         Performs binary search over a narrowing range window.
         Continues searching the right side of the match block to locate the
         latest occurrence of the item.
         Returns -1 if the array is empty or the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryRightside(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result := M;
      R.start := (M + 1);
      Continue;
    end;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinarySearchBy>
  @action: Performs a binary search over the array using a
           comparator-based comparison. Returns the index of the specified
           item if found, or -1 if the item is not present. Supports arrays
           sorted in ascending or descending order.
  @note: The input array must be pre-sorted according to the order specified
         by the oAscending parameter. This function uses a standard binary
         search algorithm: repeatedly divides the search interval in half
         until the target item is found or the interval is empty.
         Comparisons are performed using Integer_Compare, allowing for
         consistent ordering and potential extension to other comparison logic.
[==============================================================================}
function MArrayHelper.BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  R: TRange;
  M, C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := Self[M].Compare(item);
    if (C = 0) then
      Exit(M);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySlice>
  @action: Finds the contiguous index range of elements within a specified
           value interval `[itemMin..itemMax]` in a sorted array.
           The function automatically handles cases where `itemMin > itemMax`
           and can return ranges for both ascending and descending arrays.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns a TRange where:
           - start -> index of the first element ≥ min(itemMin,itemMax) (ascending)
                      or ≤ max(itemMin,itemMax) (descending)
           - stop  -> index of the last element ≤ max(itemMin,itemMax) (ascending)
                      or ≥ min(itemMin,itemMax) (descending)
         If no elements exist in the range, returns `TRange(-1, -1)`.
         Automatically handles:
           - empty arrays
           - reversed min/max ranges (will flip result if itemMin > itemMax)
           - duplicates
[==============================================================================}
function MArrayHelper.BinarySlice(const itemMin, itemMax: MType; const oAscending: Boolean = True): TRange; overload;
var
  s: Integer;
  nMin, nMax: MType;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(TRange.Construct(-1, -1));
  nMin := IfThen((itemMin > itemMax), itemMax, itemMin);
  nMax := IfThen((itemMin > itemMax), itemMin, itemMax);
  if oAscending then
    Result.Create(Self.BinaryBoundLower(nMin, oAscending), (Self.BinaryBoundUpper(nMax, oAscending) - 1))
  else
    Result.Create(Self.BinaryBoundLower(nMax, oAscending), (Self.BinaryBoundUpper(nMin, oAscending) - 1));
  if ((Result.start >= s) or (Result.stop < 0) or (Result.start > Result.stop)) then
    Exit(TRange.Construct(-1, -1));
  if (itemMin > itemMax) then
    Result.Reverse;
end;

{==============================================================================]
  <BinarySpot>
  @action: Performs a high-speed binary search to locate the index of a item 
           value or identify its ideal insertion point within a sorted array.        
  @note: 
    - The array MUST be pre-sorted according to the [oAscending] parameter.
    - If Found: Returns the 0-based index [0..High].
    - If Not Found: Returns the bitwise NOT of the start index (not R.start), 
      representing the position where the item should be inserted to 
      preserve order.
    - Complexity: O(log n).
[==============================================================================}
function MArrayHelper.BinarySpot(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M)
    else if (oAscending = (Self[M] < item)) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := not R.start;
end;

{==============================================================================]
  <BinaryStart>
  @action: Searches the sorted array using binary search and returns the
           first index position where the specified item is found.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs a boundary pre-check via WithinBounds().
         Uses a narrowing search window implemented through TRange.
         Returns -1 if the array is empty or the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryStart(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if (Self.Empty or (not Self.WithinBounds(item, oAscending))) then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result := M;
      R.stop := (M - 1);
      Continue;
    end;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinaryStop>
  @action: Searches the sorted array using binary search and returns the
           last index position where the specified item is found.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Performs a boundary pre-check via WithinBounds().
         Uses a narrowing search window implemented through TRange.
         Returns -1 if the array is empty or the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryStop(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if (Self.Empty or (not Self.WithinBounds(item, oAscending))) then
    Exit;
  R.Create(0, High(Self));
  repeat
    if (R.start > R.stop) then
      Exit;
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result := M;
      R.start := (M + 1);
    end else if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until False;
end;

{==============================================================================]
  <BinarySuccessor>
  @action: Returns the index of the smallest element strictly greater than item.
  @note: Requires sorted array.
         oAscending = True  -> ascending order
         oAscending = False -> descending order
         Returns:
           index of successor
           -1 if no successor exists
[==============================================================================}
function MArrayHelper.BinarySuccessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] > item)) or ((not oAscending) and (Self[M] < item))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts the item x into the array at the correct position to maintain
           sorted order. Supports both ascending and descending order.
  @note:
    • The array must already be sorted according to aAscending.  
    • If aAscending = True, ascending order is assumed;  
      if aAscending = False, descending order is assumed.  
    • The value is not inserted if it already exists in the array.  
    • Returns True if the value was inserted, False if it already exists.  
    • Search complexity: O(log n).  
    • Insertion (element shift) complexity: O(n).  
    • Overall complexity: O(n).  
    • The array is resized when insertion occurs.
[==============================================================================}
function MArrayHelper.BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
	if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> item));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := item;
end;

{==============================================================================]
  <BinaryThreshold>
  @action: Returns the first index where elements become greater than or
           equal to the specified item.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Conceptually partitions the array:
           Self[i] < item   (or > item for descending)
           Self[i] >= item  (or <= item for descending)
         Returns:
           0..Length(Self)-1 -> first partition index
           Length(Self)      -> no element satisfies the condition
           -1                -> array is empty
         Time complexity: O(log n).
[==============================================================================}
function MArrayHelper.BinaryThreshold(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] >= item)) or ((not oAscending) and (Self[M] <= item))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  Result := R.start;
end;

{==============================================================================]
  <BinaryUniformSearch>
  @action: Performs a stepwise power-of-two probing search on a sorted array using
           precomputed uniform binary stepping. The algorithm first determines the
           largest exponential step size not exceeding the search interval and then
           repeatedly halves the step size while moving the probe index.
           Returns the index of the matching element if found; otherwise returns -1.
  @note:
    - The array must be monotonically sorted according to oAscending.
    - This algorithm is a variant of meta-binary (uniform binary) search.
    - Pivot movement is performed using fixed exponential step offsets rather
      than dynamic midpoint division.
    - Division operations are eliminated inside the main probing loop.
    - Time complexity is O(log n).
    - If duplicate values exist, any matching index may be returned.
    - If Self is empty, the function returns -1.
[==============================================================================}
function MArrayHelper.BinaryUniformSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  S, M, K: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  S := 1;
  while (S <= (R.stop - R.start)) do
    S := (S shl 1);
  S := (S shr 1);
  while (S > 0) do
  begin
    K := (R.start + S);
    if ((K <= R.stop) and ((oAscending and (Self[K] <= item)) or ((not oAscending) and (Self[K] >= item)))) then
      R.start := K;
    S := (S shr 1);
  end;
  if ((R.start <= R.stop) and (Self[R.start] = item)) then
    Exit(R.start);
  Result := -1;
end;

{==============================================================================]
  <BinaryWithout>
  @action: Returns the set difference of two sorted arrays, producing all
           elements in Self that are not present in target.
  @param: target      – Sorted array whose values should be removed from Self.
  @param: oAscending  – Sort order of both arrays:
                        True  = arrays are sorted ascending (default)
                        False = arrays are sorted descending
  @return: A new MArray containing elements from Self that do not occur in target.
  @note:
    - Both Self and target must already be sorted in the order specified by
      oAscending; otherwise the result is undefined.
    - Uses a two-pointer linear scan and runs in O(L + T) time
      (L = Length(Self), T = Length(target)).
    - If target is empty, a copy of Self is returned immediately.
    - If Self is empty, an empty array is returned.
    - The original arrays are not modified.
    - Functionally equivalent to a binary-style "set subtraction":
        Result = Self − target
  @example:
    // Ascending
    Self = [1,2,3,4,5], target = [2,4]
    Result -> [1,3,5]

    // Descending
    Self = [5,4,3,2,1], target = [4,2], oAscending = False
    Result -> [5,3,1]

    // Empty target
    Self = [1,3,5], target = []
    Result -> [1,3,5]
[==============================================================================}
function MArrayHelper.BinaryWithout(const target: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i, j, k, l, t: Integer;
begin
  t := target.Length;
  if (t = 0) then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  i := 0;
  j := 0;
  k := 0;
  while (i < l) do
    if ((j >= t) or ((oAscending and (Self[i] < target[j])) or ((not oAscending) and (Self[i] > target[j])))) then
      Result[k.Increase] := Self[i.Increase]
    else if ((oAscending and (Self[i] > target[j])) or ((not oAscending) and (Self[i] < target[j]))) then
      Inc(j)
    else
      Inc(i);
  SetLength(Result, k);
end;
{$ENDIF}
