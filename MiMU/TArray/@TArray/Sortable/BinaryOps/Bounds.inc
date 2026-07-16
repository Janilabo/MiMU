{$IFDEF HELPERS}
function BinaryBoundaries(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundary(const threshold: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundLower(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBounds(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBracket(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryCeiled(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryDomain(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryFindLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFloored(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeft(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerB(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPredecessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRight(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryStart(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryStop(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySuccessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryThreshold(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUpperB(const target: MType; const oAscending: Boolean = True): Integer; overload;
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
  <BinaryLBound>
  @action: Performs a binary search to find the **first index** where
           the element satisfies the lower bound condition.
           For ascending arrays (`oAscending = True`):
             Returns the first index `i` where Self[i] >= target.
           For descending arrays (`oAscending = False`):
             Returns the first index `i` where Self[i] <= target.
           If no element satisfies the condition, returns -1.
  @param target the value to search for.
  @param oAscending indicates the sort order of the array.
           True  → ascending order
           False → descending order
  @note: The array must already be sorted according to `oAscending`.
         Time complexity is O(log n).
         This function uses a half-open interval binary search [start..stop).
[==============================================================================}
function MArrayHelper.BinaryLBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M, S: Integer;
begin
  R := 0;
  L := Self.Length;
  S := L;
  while (R < S) do
  begin
    M := ((R + S) shr 1);
    if ((Self[M] < target) = oAscending) then
      R := (M + 1)
    else
      S := M;
  end;
  if (R < L) then
    Result := R
  else
    Result := -1;
end;

{==============================================================================]
  <BinaryLeft>
  @action: Finds the index of the first element (leftmost position) in the
           array whose value lies within the specified range.
  @param: startItem   – First boundary value of the search range.
  @param: stopItem    – Second boundary value of the search range.
  @param: oAscending  – Sort order of the array:
                        True  = array is sorted ascending (default)
                        False = array is sorted descending.
  @return: The index of the leftmost element whose value is between
           startItem and stopItem (inclusive). Returns -1 if no such
           element exists.
  @note:
    - The array must be sorted according to oAscending.
    - The function automatically normalizes the range so that the lower
      and upper bounds are correctly determined even if the parameters
      are passed in reverse order.
    - Uses a binary search strategy and runs in O(log n) time.
    - The search continues toward the left side after a match to ensure
      the earliest valid index is found.
    - The array is not modified.
  @example:
    Self = [1,2,3,4,5,6,7]
    BinaryLeft(3,6) -> 2   // value = 3

    Self = [7,6,5,4,3,2,1]
    BinaryLeft(3,6, False) -> 1   // value = 6
[==============================================================================}
function MArrayHelper.BinaryLeft(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  L, H: MType;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  if (startItem <= stopItem) then
  begin
    L := startItem;
    H := stopItem;
  end else
  begin
    L := stopItem;
    H := startItem;
  end;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case oAscending of
      True:
      if Self[M] >= L then
      begin
        if (Self[M] <= H) then
          Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= H) then
      begin
        if (Self[M] >= L) then
          Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryLeftBound>
  @action: Returns the index of the left boundary for a target value using
           binary search.        
            - For ascending arrays, this is the first index where
              Self[i] >= target.
            - For descending arrays, this is the first index where 
	          Self[i] <= target.
           If no such element exists, -1 is returned.
  @note: The array must already be sorted according to the value of
         oAscending. The function runs in O(log n) time.
         When duplicates exist, the returned index points to the
         leftmost element satisfying the comparison condition.
[==============================================================================}
function MArrayHelper.BinaryLeftBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] >= target)) or ((not oAscending) and (Self[M] <= target))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
end;

{==============================================================================]
  <BinaryLeftBoundary>
  @action: Returns the index of the left boundary for a target value using
           binary search.        
            - For ascending arrays, this is the first index where
              Self[i] >= target.
            - For descending arrays, this is the first index where 
	          Self[i] <= target.
           If no such element exists, -1 is returned.
  @note: The array must already be sorted according to the value of
         oAscending. The function runs in O(log n) time.
         When duplicates exist, the returned index points to the
         leftmost element satisfying the comparison condition.
[==============================================================================}
function MArrayHelper.BinaryLeftBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] >= target) = oAscending) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
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
  <BinaryLowerB>
  @action: Performs a binary search using a `TRange` helper to find the
           **first index** where the element satisfies the lower bound condition.
           For ascending arrays (`oAscending = True`):
             Returns the first index `i` where Self[i] >= target.
           For descending arrays (`oAscending = False`):
             Returns the first index `i` where Self[i] <= target.
           If no element satisfies the condition, returns -1.
  @param target the value to search for.
  @param oAscending indicates the sort order of the array.
           True  → ascending order
           False → descending order
  @note: The array must already be sorted according to `oAscending`.
         Time complexity is O(log n).
         This function uses a half-open interval binary search managed via `TRange`.
[==============================================================================}
function MArrayHelper.BinaryLowerB(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, M: Integer;
  R: TRange;
begin
  L := Self.Length;
  R.Create(0, L);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] < target) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  if (R.start < L) then
    Result := R.start
  else
    Result := -1;
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
  <BinaryRight>
  @action: Finds the index of the last element (rightmost position) in the
           array whose value lies within the specified range.
  @param: startItem   – First boundary value of the search range.
  @param: stopItem    – Second boundary value of the search range.
  @param: oAscending  – Sort order of the array:
                        True  = array is sorted ascending (default)
                        False = array is sorted descending.
  @return: The index of the rightmost element whose value is between
           startItem and stopItem (inclusive). Returns -1 if no such
           element exists.
  @note:
    - The array must be sorted according to oAscending.
    - The range boundaries are normalized internally so reversed
      parameters are handled correctly.
    - Uses a binary search strategy and runs in O(log n) time.
    - The search continues toward the right side after a match to ensure
      the latest valid index is found.
    - The array is not modified.
[==============================================================================}
function MArrayHelper.BinaryRight(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  L, H: MType;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  if (startItem <= stopItem) then
  begin
    L := startItem;
    H := stopItem;
  end else
  begin
    L := stopItem;
    H := startItem;
  end;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case oAscending of
      True:
      if (Self[M] <= H) then
      begin
        if (Self[M] >= L) then
          Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
      False:
      if (Self[M] >= L) then
      begin
        if (Self[M] <= H) then
          Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryRightBound>
  @action: Returns the index of the right boundary for a target value using
           binary search.
            - For ascending arrays, this is the last index where
              Self[i] <= target.
            - For descending arrays, this is the last index where
              Self[i] >= target.
           If no such element exists, -1 is returned.
  @note: The array must already be sorted according to the value of
         oAscending. The function runs in O(log n) time.
         When duplicates exist, the returned index points to the
         rightmost element satisfying the comparison condition.
[==============================================================================}
function MArrayHelper.BinaryRightBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] <= target)) or ((not oAscending) and (Self[M] >= target))) then
    begin
      Result := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryRightBoundary>
  @action: Returns the index of the right boundary for a target value using
           binary search.
            - For ascending arrays, this is the last index where
              Self[i] <= target.
            - For descending arrays, this is the last index where
              Self[i] >= target.
           If no such element exists, -1 is returned.
  @note: The array must already be sorted according to the value of
         oAscending. The function runs in O(log n) time.
         When duplicates exist, the returned index points to the
         rightmost element satisfying the comparison condition.
[==============================================================================}
function MArrayHelper.BinaryRightBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] <= target) = oAscending) then
    begin
      Result := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
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
  <BinaryUBound>
  @action: Performs a binary search to find the **first index strictly greater than the target**.
           For ascending arrays (`oAscending = True`):
             Returns the first index `i` where Self[i] > target.
           For descending arrays (`oAscending = False`):
             Returns the first index `i` where Self[i] < target.
           If no element satisfies the condition, returns -1.
  @param target the value to search for.
  @param oAscending indicates the sort order of the array.
           True  → ascending order
           False → descending order
  @note: The array must already be sorted according to `oAscending`.
         Time complexity is O(log n).
         Uses a half-open interval binary search [start..stop) with integer indices.
[==============================================================================}
function MArrayHelper.BinaryUBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M, S: Integer;
begin
  R := 0;
  L := Self.Length;
  S := L;
  while (R < S) do
  begin
    M := ((R + S) shr 1);
    if ((Self[M] <= target) = oAscending) then
      R := (M + 1)
    else
      S := M;
  end;
  if (R < L) then
    Result := R
  else
    Result := -1;
end;

{==============================================================================]
  <BinaryUpperB>
  @action: Performs a binary search using a `TRange` helper to find the
           **first index strictly greater than the target**.
           For ascending arrays (`oAscending = True`):
             Returns the first index `i` where Self[i] > target.
           For descending arrays (`oAscending = False`):
             Returns the first index `i` where Self[i] < target.
           If no element satisfies the condition, returns -1.
  @param target the value to search for.
  @param oAscending indicates the sort order of the array.
           True  → ascending order
           False → descending order
  @note: The array must already be sorted according to `oAscending`.
         Time complexity is O(log n).
         Uses a half-open interval binary search [start..stop) managed via `TRange`.
[==============================================================================}
function MArrayHelper.BinaryUpperB(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, M: Integer;
  R: TRange;
begin
  L := Self.Length;
  R.Create(0, L);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] <= target) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  if (R.start < L) then
    Result := R.start
  else
    Result := -1;
end;
{$ENDIF}
