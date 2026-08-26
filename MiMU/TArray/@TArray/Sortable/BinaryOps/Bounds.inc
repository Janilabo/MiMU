{$IFDEF HELPERS}
function BinaryBoundaries(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundary(const threshold: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundaryL(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundaryU(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundLower(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBounds(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryBoundUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBracket(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryCeil(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCeiled(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryDomain(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryFindFirst(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFloor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFloored(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeft(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftern(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftum(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerB(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerBound(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryLowerBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPredecessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRight(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightBoundary(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightern(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightmost(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryRightside(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightum(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchFirst(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinarySearchLast(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryStart(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryStop(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySuccessor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryThreshold(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUpperB(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUpperBound(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryUpperBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLeftpos(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLefty(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryPosLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRightpos(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRighty(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryPosRight(const item: MType; const oAscending: Boolean = True): Integer; overload;

function BinaryLower(const item: MTYpe; const oAscending: Boolean = True): Integer; overload;
function BinaryUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;

function BinaryBoundMax(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundMin(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryMaxBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryMinBound(const target: MType; const oAscending: Boolean = True): Integer; overload;

function BisectLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BisectRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
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
  <BinaryBoundaryL>
  @action: Finds the leftmost index at which item occurs in Self, or -1 if item is not present. Self must be sorted according to oAscending (ascending if True, descending if False).
  @note: Standard binary lower-bound search — records the pivot as a candidate match each time it equals item, then keeps narrowing toward the lower end. O(log n) regardless of how many duplicate occurrences of item exist.
[==============================================================================}
function MArrayHelper.BinaryBoundaryL(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s := Self.Locale;
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Result := m;
    if ((oAscending and (Self[m] >= item)) or ((not oAscending) and (Self[m] <= item))) then
      s.stop := (m - 1)
    else
      s.start := (m + 1);	
  end;
end;

{==============================================================================]
  <BinaryBoundaryU>
  @action: Finds the rightmost index at which item occurs in Self, or -1 if item is not present. Self must be sorted according to oAscending (ascending if True, descending if False).
  @note: Standard binary upper-bound search — records the pivot as a candidate match each time it equals item, then keeps narrowing toward the upper end. O(log n) regardless of how many duplicate occurrences of item exist.
[==============================================================================}
function MArrayHelper.BinaryBoundaryU(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s := Self.Locale;
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Result := m;
    if ((oAscending and (Self[m] <= item)) or ((not oAscending) and (Self[m] >= item))) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);	
  end;
end;

{==============================================================================]
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given item in the array.
  @note: Returns the index of the first element greater than or equal to the item for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function MArrayHelper.BinaryBoundLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
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
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given item in the array.
  @note: Returns the index of the first element strictly greater than the item for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function MArrayHelper.BinaryBoundRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] <= item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] >= item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
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
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `item`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `item`.
[==============================================================================}
function MArrayHelper.BinaryCeil(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > item) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
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
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `item`. If the item is not present,
           returns -1.
  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function MArrayHelper.BinaryFindFirst(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < item) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = item) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > item) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = item) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `item`. If the item is not present,
           returns -1.
  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function MArrayHelper.BinaryFindLast(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > item) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = item) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < item) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = item) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
  end;
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
  <BinaryFloor>
  @action: Returns the index of the greatest array element that is less than or
           equal to `item`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical floor. For descending
         order, the search logic is reversed but the returned index still
         represents the element whose value is the nearest lower-or-equal
         bound relative to `item`.
[==============================================================================}
function MArrayHelper.BinaryFloor(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > item) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < item) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
    end;
  end;
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
  <BinaryLBoundary>
  @action: Finds the leftmost index whose value equals item via a hybrid strategy: binary search lands on any matching pivot, then a linear backward scan confirms/extends the boundary,
           exiting the instant a non-matching neighbor is found.
  @note: Same result as BinaryLowerB (leftmost match, or -1), different mechanism and performance profile. Worst case O(n) when a long run of duplicates surrounds the landing pivot,
         since the backward scan is unbounded within [s.start, Result-1] — but short-circuits the whole search the moment a mismatch confirms the boundary,
         so it can beat pure binary search when duplicate runs are short.
[==============================================================================}
function MArrayHelper.BinaryLBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  r: Integer;
  s: TRange;
begin
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    Result := s.Pivot;
    if (Self[Result] = item) then
    for r := (Result - 1) downto s.start do
      if (Self[r] = item) then
        Result := r
      else
        Exit;
    if ((oAscending and (Self[Result] >= item)) or ((not oAscending) and (Self[Result] <= item))) then
      s.stop := (Result - 1)
    else
      s.start := (Result + 1);
  end;
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
  <BinaryLeftern>
  @action: Binary search over [0, High(Self)] for the leftmost index whose value equals item (sorted ascending or descending per oAscending).
  @note: Pure O(log n) binary search — narrows toward the front on every pivot that is >= item (ascending) or <= item (descending),
         so ties keep pushing the boundary left. Returns -1 if item is absent.
[==============================================================================}
function MArrayHelper.BinaryLeftern(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Result := m;
    if ((oAscending and (Self[m] >= item)) or ((not oAscending) and (Self[m] <= item))) then
      s.stop := (m - 1)
    else
      s.start := (m + 1);
  end;
end;

{==============================================================================]
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function MArrayHelper.BinaryLeftmost(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
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
  <BinaryLeftum>
  @action: Binary search over Self for the leftmost index whose value equals item, given sorted ascending or descending per oAscending.
  @note: Same result as BinaryLeftern (leftmost match, or -1) but hoists the direction check out of the loop via case oAscending of,
         running a specialized loop per direction instead of re-evaluating a combined boolean each iteration. O(log n).
[==============================================================================}
function MArrayHelper.BinaryLeftum(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  case oAscending of
    True:
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (Self[m] = item) then
        Result := m;
      if (Self[m] < item) then
        s.start := (m + 1)
      else
        s.stop := (m - 1);
    end;
    False:
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (Self[m] = item) then
        Result := m;
      if (Self[m] > item) then
        s.start := (m + 1)
      else
        s.stop := (m - 1);
    end;
  end;
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
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function MArrayHelper.BinaryLowerBound(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryLowerBoundary>
  @action: Finds the leftmost index at which item occurs in Self, or -1 if item is not present. Self must be sorted according to oAscending (ascending if True, descending if False).
  @note: Narrows via binary search; once a match is found at the pivot, linearly scans downward to confirm/extend the leftmost boundary,
         exiting as soon as a mismatch is hit or the current window's start is reached. Worst case (item spans most of the array) degrades to a single O(n) scan on top of the O(log n) narrowing,
		 but never re-scans across iterations.
[==============================================================================}
function MArrayHelper.BinaryLowerBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  r: Integer;
  s: TRange;
begin
  s := Self.Locale;
  while (s.start <= s.stop) do
  begin
    Result := s.Pivot;
	if (Self[Result] = item) then
	begin
	  for r := (Result - 1) downto s.start do
	    if (Self[r] = item) then
	      Result := r
        else
          Exit;
	  Exit(s.start);
	end;
    if ((oAscending and (Self[Result] >= item)) or ((not oAscending) and (Self[Result] <= item))) then
      s.stop := (Result - 1)
    else
      s.start := (Result + 1);	
  end;
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
  <BinaryRightern>
  @action: Binary search over [0, High(Self)] for the rightmost index whose value equals item (sorted ascending or descending per oAscending).
  @note: Mirror of BinaryLeftern, narrowing toward the back on ties. O(log n). Returns -1 if item is absent.
[==============================================================================}
function MArrayHelper.BinaryRightern(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Result := m;
    if ((oAscending and (Self[m] <= item)) or ((not oAscending) and (Self[m] >= item))) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function MArrayHelper.BinaryRightmost(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
      False:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
    end;
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
  <BinaryRightum>
  @action: Binary search over Self for the rightmost index whose value equals item, given sorted ascending or descending per oAscending.
  @note: Mirror of BinaryLeftum; same result as BinaryRightern, same specialized-loop-per-direction mechanism. O(log n).
[==============================================================================}
function MArrayHelper.BinaryRightum(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  case oAscending of
    True:
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (Self[m] = item) then
        Result := m;
      if (Self[m] > item) then
        s.stop := (m - 1)
      else
        s.start := (m + 1);
    end;
    False:
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (Self[m] = item) then
        Result := m;
      if (Self[m] < item) then
        s.stop := (m - 1)
      else
        s.start := (m + 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           item within a sorted array.
  @note: - The array must be sorted in ascending order.
         - If the item occurs multiple times, the index of its first occurrence is returned.
         - If the item is not found, returns -1.
[==============================================================================}
function MArrayHelper.BinarySearchFirst(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        R.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < item)) or ((not aAscending) and (Self[M] > item))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           item within a sorted array.
  @note: - The array must be sorted in ascending order.
         - If the item occurs multiple times, the index of its last occurrence is returned.
         - If the item is not found, returns -1.
[==============================================================================}
function MArrayHelper.BinarySearchLast(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        R.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < item)) or ((not aAscending) and (Self[M] > item))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
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
  <BinaryUBoundary>
  @action: Finds the rightmost index whose value equals item via the same hybrid strategy,
           scanning forward from the landing pivot instead of backward.
  @note: Same result as BinaryUpperB, same worst-case-O(n)/short-circuit trade-off as BinaryLBound, mirrored direction.
[==============================================================================}
function MArrayHelper.BinaryUBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  r: Integer;
  s: TRange;
begin
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    Result := s.Pivot;
    if (Self[Result] = item) then
    for r := (Result + 1) to s.stop do
      if (Self[r] = item) then
        Result := r
      else
        Exit;
    if ((oAscending and (Self[Result] <= item)) or ((not oAscending) and (Self[Result] >= item))) then
      s.start := (Result + 1)
    else
      s.stop := (Result - 1);
  end;
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

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function MArrayHelper.BinaryUpperBound(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] > x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] < x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryUpperBoundary>
  @action: Finds the rightmost index at which item occurs in Self, or -1 if item is not present. Self must be sorted according to oAscending (ascending if True, descending if False).
  @note: Narrows via binary search; once a match is found at the pivot, linearly scans upward to confirm/extend the rightmost boundary,
         exiting as soon as a mismatch is hit or the current window's stop is reached. Worst case (item spans most of the array) degrades to a single O(n) scan on top of the O(log n) narrowing,
		 but never re-scans across iterations.
[==============================================================================}
function MArrayHelper.BinaryUpperBoundary(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  r: Integer;
  s: TRange;
begin
  s := Self.Locale;
  while (s.start <= s.stop) do
  begin
    Result := s.Pivot;
	if (Self[Result] = item) then
	begin
	  for r := (Result + 1) to s.stop do
	    if (Self[r] = item) then
	      Result := r
	    else
	      Exit;
	  Exit(s.stop);
	end;
	if ((oAscending and (Self[Result] <= item)) or ((not oAscending) and (Self[Result] >= item))) then
	  s.start := (Result + 1)
	else
	  s.stop := (Result - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryLeftpos>
  @action: Finds the leftmost valid index at which item could appear in a
           sorted array — the first index where the element does not sort
           strictly before item (equivalent to std::lower_bound, expressed
           via Contest rather than direct comparison operators).
  @note:
    - Self must already be sorted according to oAscending.
    - If item is present with duplicates, returns the index of the first
      occurrence.
    - If item is not present, returns the index at which it would need to
      be inserted to preserve sort order.
    - Returns Self.Size if item would sort after every existing element.
[==============================================================================}
function MArrayHelper.BinaryLeftpos(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, Self.Size);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Contest(item, oAscending) < 0) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  Result := R.start;
end;

{==============================================================================]
  <BinaryLefty>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryLefty(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    case aAscending of
      True:
      if (Self[m] < x) then
        r.start := (m + 1)
      else
        r.stop := m;
      False:
      if (Self[m] > x) then
        r.start := (m + 1)
      else
        r.stop := m;
    end;
  end;
  if ((r.start < Self.Size) and (Self[r.start] = x)) then
    Result := r.start;
end;

{==============================================================================]
  <BinaryPosLeft>
  @action: Returns the index of the leftmost (first) occurrence of `item` in
           a sorted array, or -1 if `item` is not present.
  @note: - Requires the array to be sorted according to `oAscending`.
         - On each match, records the index and keeps searching left
           (R := M - 1) in case an earlier occurrence exists — same
           narrow-on-hit mechanism as BinaryAmount/BinaryQuantity/BinaryTally.
         - Unlike BisectLeft, returns -1 rather than an insertion point when
           `item` is absent — this is a "does it exist, and where" query,
           not an insertion-point query.
[==============================================================================}
function MArrayHelper.BinaryPosLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  Result := -1;
  L := 0;
  R := High(Self);
  while (L <= R) do
  begin
    M := ((L + R) shr 1);
    if (Self[M] = item) then
    begin
      Result := M;
      R := (M - 1);
    end else if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryRightpos>
  @action: Finds the rightmost valid index at which item currently occupies
           in a sorted array — the last index whose element does not sort
           strictly after item (equivalent to std::upper_bound minus one).
  @note:
    - Self must already be sorted according to oAscending.
    - If item is present with duplicates, returns the index of the last
      occurrence.
    - If item is not present, returns the index immediately before its
      would-be insertion point — this may be -1 if item sorts before
      every existing element.
    - Paired with BinaryLeftpos, (BinaryRightpos - BinaryLeftpos + 1)
      gives the count of occurrences of item in the array.
[==============================================================================}
function MArrayHelper.BinaryRightpos(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, Self.Size);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Contest(item, oAscending) <= 0) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  Result := (R.start - 1);
end;

{==============================================================================]
  <BinaryRighty>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryRighty(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    case aAscending of
      True:
      if (Self[m] <= x) then
        r.start := (m + 1)
      else
        r.stop := m;
      False:
      if (Self[m] >= x) then
        r.start := (m + 1)
      else
        r.stop := m;
    end;
  end;
  if ((r.start > 0) and (Self[r.start - 1] = x)) then
    Result := (r.start - 1);
end;

{==============================================================================]
  <BinaryPosRight>
  @action: Returns the index of the rightmost (last) occurrence of `item` in
           a sorted array, or -1 if `item` is not present.
  @note: - Requires the array to be sorted according to `oAscending`.
         - Mirror image of BinaryPosLeft: on each match, records the index
           and keeps searching right (L := M + 1) in case a later occurrence
           exists.
         - Together, BinaryPosLeft/BinaryPosRight are exactly what
           BinaryCounting wraps, and exactly what BinaryAmount/
           BinaryQuantity/BinaryTally reimplement inline as a single fused
           two-search body rather than delegating to these two.
[==============================================================================}
function MArrayHelper.BinaryPosRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  Result := -1;
  L := 0;
  R := High(Self);
  while (L <= R) do
  begin
    M := ((L + R) shr 1);
    if (Self[M] = item) then
    begin
      Result := M;
      L := (M + 1);
    end else if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryLower>
  @action: Finds the index of item's occurrence that borders the smaller-value side,
           regardless of whether Self is sorted ascending or descending —
           this is the leftmost occurrence in an ascending array, but the rightmost occurrence in a descending one.
@note: Delegates to BinaryLeftern/BinaryRightern based on oAscending,
       so it's O(log n), pure binary search underneath. Returns -1 if item is absent. Value-semantic,
       not index-semantic: unlike Leftern/Rightern,
       this always answers the same question ("which occurrence sits toward the low end of the value range?") independent of sort direction.
[==============================================================================}
function MArrayHelper.BinaryLower(const item: MTYpe; const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.BinaryLeftern(item, oAscending)
  else
    Result := Self.BinaryRightern(item, oAscending);
end;

{==============================================================================]
  <BinaryUpper>
  @action: Finds the index of item's occurrence that borders the larger-value side,
           regardless of sort direction — the rightmost occurrence in an ascending array, the leftmost occurrence in a descending one.
  @note: Mirror of BinaryLower; delegates to BinaryRightern/BinaryLeftern based on oAscending. O(log n). Returns -1 if item is absent.
[==============================================================================}
function MArrayHelper.BinaryUpper(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.BinaryRightern(item, oAscending)
  else
    Result := Self.BinaryLeftern(item, oAscending);
end;

{==============================================================================]
  <BinaryBoundMax>
  @action: Performs an upper-bound binary search to find the index of the last element in a sorted array that is less than or equal to `target` (ascending) or greater than or equal to `target` (descending). Returns -1 if no element satisfies the bound condition.
  @note: Operates strictly in pure O(log N) logarithmic time without performing linear scans. The unused local variable `r` can be safely cleaned up in future maintenance.
[==============================================================================}
function MArrayHelper.BinaryBoundMax(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  m, r: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if ((oAscending and (Self[m] <= target)) or ((not oAscending) and (Self[m] >= target))) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
    if ((oAscending and (Self[m] <= target)) or ((not oAscending) and (Self[m] >= target))) then
      Result := m;
  end;
end;

{==============================================================================]
  <BinaryBoundMin>
  @action: Performs a lower-bound binary search to find the index of the first element in a sorted array that is greater than or equal to `target` (ascending) or less than or equal to `target` (descending). Returns -1 if no element satisfies the bound condition.
  @note: Operates strictly in pure O(log N) logarithmic time without performing linear scans. The unused local variable `r` can be safely safely cleaned up in future maintenance.
[==============================================================================}
function MArrayHelper.BinaryBoundMin(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  m, r: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if ((oAscending and (Self[m] >= target)) or ((not oAscending) and (Self[m] <= target))) then
      s.stop := (m - 1)
    else
      s.start := (m + 1);
    if ((oAscending and (Self[m] >= target)) or ((not oAscending) and (Self[m] <= target))) then
      Result := m;
  end;
end;

{==============================================================================]
  <BinaryMaxBound>
  @action: Finds the index of the last occurrence of `target` in a sorted array using binary search with a linear forward scan for duplicates.
           If `target` is not present, returns the index of the largest element strictly less than `target` (ascending) or strictly greater than `target` (descending).
           Returns -1 if no element satisfies the criteria.
  @note: Uses a hybrid approach combining logarithmic binary search stepping with a linear forward scan upon reaching exact matches.
         Supports both ascending and descending arrays via `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryMaxBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = target) then
    begin
      Result := m;
      while ((Result < s.stop) and (Self[Result + 1] = target)) do
        Inc(Result);
      Exit;
    end;
    if ((oAscending and (Self[m] < target)) or ((not oAscending) and (Self[m] > target))) then
    begin
      Result := m;
      s.start := (m + 1);
    end else
      s.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinaryMinBound>
  @action: Finds the index of the first occurrence of `target` in a sorted array using binary search with a linear backward scan for duplicates.
           If `target` is not present, returns the index of the smallest element strictly greater than `target` (ascending) or strictly less than `target` (descending).
           Returns -1 if no element satisfies the criteria.
  @note: Uses a hybrid approach combining logarithmic binary search stepping with a linear backward scan upon reaching exact matches.
         Supports both ascending and descending arrays via `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryMinBound(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = target) then
    begin
      Result := m;
      while ((Result > s.start) and (Self[Result - 1] = target)) do
        Dec(Result);
      Exit;
    end;
    if ((oAscending and (Self[m] > target)) or ((not oAscending) and (Self[m] < target))) then
    begin
      Result := m;
      s.stop := (m - 1);
    end else
      s.start := (m + 1);
  end;
end;

{==============================================================================]
  <BisectLeft>
  @action: Returns the leftmost insertion point for `item` in a sorted array —
           the index of the first element not less than `item` (ascending)
           or not greater than `item` (descending). Matches Python's
           bisect_left semantics: if `item` is present, returns the index of
           its first occurrence; if absent, returns where it would need to be
           inserted to keep the array sorted.
  @note: - Requires the array to be sorted according to `oAscending`.
         - Unlike most Binary* functions in this family, never returns -1 —
           the result is always a valid insertion index in [0, Length].
         - Internally performs an initial binary search for any match, then
           (if found) a second binary search restricted to [0, p] to find the
           true left edge. If absent, degrades to a single binary search plus
           a clamp.
         - Result - BisectLeft difference against BisectRight gives an
           occurrence count directly, with no -1 handling required.
[==============================================================================}
function MArrayHelper.BisectLeft(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, h, m, p, s: Integer;
begin
  s := Self.Length;
  l := 0;
  h := (s - 1);
  p := -1;
  while (l <= h) do
  begin
    m := (l + (h - l) shr 1);
    if (Self[m] = item) then
    begin
      p := m;
      Break;
    end else if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  case (p = -1) of
    False:
    begin
      l := 0;
      h := p;
      while (l < h) do
      begin
        m := (l + (h - l) shr 1);
        if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
          l := (m + 1)
        else
          h := m;
      end;
      Result := l;
    end;
    True:
    if l < 0 then
      Result := 0
    else if (l > s) then
      Result := s
    else
      Result := l;
  end;
end;

{==============================================================================]
  <BisectRight>
  @action: Returns the rightmost insertion point for `item` in a sorted array —
           the index one past the last element equal to `item`. Matches
           Python's bisect_right semantics: if `item` is present, returns the
           index just after its last occurrence; if absent, returns the same
           insertion point as BisectLeft would.
  @note: - Requires the array to be sorted according to `oAscending`.
         - Never returns -1; result is always in [0, Length].
         - Internally performs an initial binary search for any match, then
           (if found) a second binary search restricted to [p, Length] using
           <=/>= (rather than BisectLeft's strict </>)  to find the true
           right edge.
         - BisectRight(item) - BisectLeft(item) gives the occurrence count of
           item with no separate counting function needed.
[==============================================================================}
function MArrayHelper.BisectRight(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, h, m, p, s: Integer;
begin
  s := Self.Length;
  l := 0;
  h := (s - 1);
  p := -1;
  while (l <= h) do
  begin
    m := (l + (h - l) shr 1);
    if (Self[m] = item) then
    begin
      p := m;
      Break;
    end else if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  case (p = -1) of
    False:
    begin
      l := p;
      h := s;
      while (l < h) do
      begin
        m := (l + (h - l) shr 1);
        if ((oAscending and (Self[m] <= item)) or ((not oAscending) and (Self[m] >= item))) then
          l := (m + 1)
        else
          h := m;
      end;
      Result := l;
    end;
    True:
    if (l < 0) then
      Result := 0
    else if (l > s) then
      Result := s
    else
      Result := l;
  end;
end;
{$ENDIF}
