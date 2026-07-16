{$IFDEF HELPERS}
function BinaryContain(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExist(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHave(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryItem(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryMajority(out oItem: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryMajority(const oAscending: Boolean = True): Boolean; overload;
function BinaryMembership(const item: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}