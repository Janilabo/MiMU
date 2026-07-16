{$IFDEF HELPERS}
function BinaryCardinality(const itemMin, itemMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCounter(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryEncounter(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFrequency(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrence(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrences(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrency(const item: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BinaryEncounter>
  @action: Counts how many elements in the array fall within the specified
           value range using binary search boundaries.
  @param: startItem   – First boundary value of the range.
  @param: stopItem    – Second boundary value of the range.
  @param: oAscending  – Sort order of the array:
                        True  = array is sorted ascending (default)
                        False = array is sorted descending.
  @return: The number of elements whose values lie between startItem and
           stopItem (inclusive).
  @note:
    - The array must already be sorted according to oAscending.
    - The function internally determines the correct range direction even if
      startItem and stopItem are provided in reverse order.
    - If no elements fall within the range, the result is 0.
[==============================================================================}
function MArrayHelper.BinaryEncounter(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
var
  b: Boolean;
begin
  b := (startItem <= stopItem);
  case (b.Binary + oAscending.Binary) of
    '11': Result := (Self.BinaryBoundUpper(stopItem, True) - Self.BinaryBoundLower(startItem, True));
    '10': Result := (Self.BinaryBoundUpper(startItem, False) - Self.BinaryBoundLower(stopItem, False));
    '01': Result := (Self.BinaryBoundUpper(startItem, True) - Self.BinaryBoundLower(stopItem, True));
    '00': Result := (Self.BinaryBoundUpper(stopItem, False) - Self.BinaryBoundLower(startItem, False));
  end;
  if (Result < 0) then
    Result := 0;
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
{$ENDIF}
