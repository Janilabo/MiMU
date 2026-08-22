{$IFDEF HELPERS}
function BinaryAmount(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryAmountage(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryAmountOf(const x: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCardinality(const itemMin, itemMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCount(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryCountage(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCounted(const x: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCounter(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCountFor(const x: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCounting(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryCountOf(const x: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryEncounter(const startItem, stopItem: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFrequency(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryHigherCount(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerCount(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrence(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrences(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryOccurrency(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryQuantity(const x: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRecur(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryTally(const x: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAmount>
  @action: Returns count of x
  @note: Alternative for BinaryCount
[==============================================================================}
function MArrayHelper.BinaryAmount(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

{==============================================================================]
  <BinaryAmountage>
  @action: Returns the number of elements in the array equal to item, by
           locating the full matching range via BinaryRangeOf and measuring
           its size.
  @note: Assumes the array is sorted according to oAscending. Returns 0 if
         item is not present. Time complexity is O(log n), matching the
         complexity of BinaryRangeOf.
[==============================================================================}
function MArrayHelper.BinaryAmountage(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  r := Self.BinaryRangeOf(item, oAscending);
  if (r.start = -1) then
    Exit(0);
  Result := r.Size;
end;

{==============================================================================]
  <BinaryAmountOf>
  @action: Returns the number of occurrences of the specified value using
           binary search bound operations.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Internally uses BinaryLowerBound() and BinaryUpperBound().
         Time complexity: O(log n).
         Returns 0 if the value is outside bounds or not present.
[==============================================================================}
function MArrayHelper.BinaryAmountOf(const x: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if not Self.WithinBounds(x, oAscending) then
    Exit(0);
  Result := Self.BinaryUpperBound(x, oAscending);
  if (Result = -1) then
    Exit(0);
  Result := (Result - Self.BinaryLowerBound(x, oAscending));
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
  <BinaryCount>
  @action: Binary Count function for arrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function MArrayHelper.BinaryCount(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  r := Self.BinaryLocate(item, aAscending);
  Result := IfThen((r.start > -1), r.Size, 0);
end;

{==============================================================================]
  <BinaryCountage>
  @action: Returns the number of elements in the array equal to item, using
           binary search to locate any occurrence and linear expansion to
           count the full contiguous run.
  @note: Assumes the array is sorted according to oAscending. Returns 0 if
         item is not present. Time complexity is O(log n) to locate a match,
         degrading toward O(n) when the equal-value run is large.
[==============================================================================}
function MArrayHelper.BinaryCountage(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, i: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Vie(item, oAscending) of
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
      0:
      begin
        i := M;
        while ((i >= 0) and (Self[i] = item)) do
        begin
          Inc(Result);
          Dec(i);
        end;
        i := (M + 1);
        while ((i <= High(Self)) and (Self[i] = item)) do
        begin
          Inc(Result);
          Inc(i);
        end;
        Exit;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryCounted>
  @action: Counts the number of occurrences of a specific item value within
           the sorted array.
           Uses a binary search to locate one matching element, then expands
           linearly to the left and right to count all contiguous equal values.
  @note: - The array must be sorted according to `oAscending`.
         - Returns 0 if the array is empty or the value is not present.
         - Best-case time complexity is O(log n); worst-case is O(log n + k),
           where k is the number of equal values.
         - Equality comparison is order-independent; `oAscending` is used only
           for binary search navigation.
[==============================================================================}
function MArrayHelper.BinaryCounted(const x: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Duel(x, oAscending) of
      0:
      begin
        Result := 1;
        I := (M - 1);
        while ((I >= 0) and (Self[I.Decrease] = x)) do
          Inc(Result);
        I := (M + 1);
        while ((I <= H) and (Self[I.Increase] = x)) do
          Inc(Result);
        Exit;
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
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
  <BinaryCountFor>
  @action: Counts the number of occurrences of a specific item values
           in a sorted array. Performs a single binary search to locate
           any occurrence of the value, then uses **exponential ("gallop")**
           expansion left and right to efficiently count all contiguous duplicates.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or if the value is not present.
         - Time complexity is O(log n + log k), where k is the number of occurrences.
         - Works correctly for ascending or descending arrays.
         - Use this function instead of a linear count when duplicates may form
           large contiguous blocks.
[==============================================================================}
function MArrayHelper.BinaryCountFor(const x: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H, S: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
      Break;
    case oAscending of
      True:
      if (Self[M] < x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
      False:
      if (Self[M] > x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (Self[M] <> x) then
    Exit(0);
  Result := 1;
  S := 1;
  I := (M - 1);
  while (((I - S) >= 0) and (Self[I - S] = x)) do
    S := (S * 2);
  for I := Max(((I - S) + 1), 0) to (M - 1) do
    if (Self[I] = x) then
      Inc(Result);
  S := 1;
  I := (M + 1);
  while (((I + S) <= H) and (Self[I + S] = x)) do
    S := (S * 2);
  for I := (M + 1) to Min(((I + S) - 1), H) do
    if (Self[I] = x) then
      Inc(Result);
end;

{==============================================================================]
  <BinaryCounting>
  @action: Returns the number of occurrences of `item` in a sorted array, found via binary boundary search rather than a linear scan.
  @note: Self must already be sorted according to `oAscending`; an unsorted or mis-ordered array yields undefined results.
         If `item` is absent, `BinaryPosLeft` returns -1, the length calculation is skipped,
		 and the trailing `Inc` lands the result on 0 — so the "not found" case falls out naturally rather than needing an explicit branch.
[==============================================================================}
function MArrayHelper.BinaryCounting(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryPosLeft(item, oAscending);
  if (Result > -1) then
    Result := (Self.BinaryPosRight(item, oAscending) - Result);
  Inc(Result);
end;

{==============================================================================]
  <BinaryCountOf>
  @action: Counts the number of occurrences of a specific integer value
           in a sorted array. Uses a single binary search to locate any
           occurrence of the value, then expands left and right to
           count contiguous occurrences.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value is not present.
         - Time complexity is O(log n + k), where k is the number of occurrences.
         - Works correctly for ascending or descending arrays.
         - This overload counts a single integer value.
[==============================================================================}
function MArrayHelper.BinaryCountOf(const x: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
    begin
      Result := 1;
      I := (M - 1);
      while ((I >= 0) and (Self[I.Decrease] = x)) do
        Inc(Result);
      I := (M + 1);
      while ((I <= H) and (Self[I.Increase] = x)) do
        Inc(Result);
      Exit;
    end;
    if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
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
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `item`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function MArrayHelper.BinaryHigherCount(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundRight(item, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(0, l)
  else
    Result := oAscending.Select((l - p), p);
end;

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `item`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function MArrayHelper.BinaryLowerCount(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundLeft(item, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(l, 0)
  else
    Result := oAscending.Select(p, (l - p));
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
  <BinaryQuantity>
  @action: Returns the number of occurrences of a specific integer value within
           the sorted array.
           Performs a binary search to locate the first and last positions of
           the target value and computes the count as (last - first + 1).
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value does not exist.
         - Time complexity is O(log n) for the search.
         - The `oAscending` parameter must match the array’s actual sort order.
[==============================================================================}
function MArrayHelper.BinaryQuantity(const x: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L, H: Integer;
  R: TRange;
begin
  H := High(Self);
  if (H = -1) then
    Exit(0);
  R.Create(0, H);
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Duel(x, oAscending) of
      0:
      begin
        F := M;
        R.stop := (M - 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, H);
  L := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Duel(x, oAscending) of
      0:
      begin
        L := M;
        R.start := (M + 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  Result := ((L - F) + 1);
end;

{==============================================================================]
  <BinaryRecur>
  @action: Counts the total number of duplicate/matching items matching item in a sorted array using recursive binary search.
  @note: This implementation will stack overflow or trigger an infinite loop if duplicate values are adjacent.
[==============================================================================}
function MArrayHelper.BinaryRecur(const item: MType; const oAscending: Boolean = True): Integer; overload;
  function R(lo, hi: Integer): Integer;
  var
    m: Integer;
  begin
    if (lo > hi) then
      Exit(0);
    m := (lo + (hi - lo) div 2);
    if (Self[m] = item) then
      Result := (1 + R(lo, (m - 1)) + R((m + 1), hi))
    else if (Self[m].Contest(item, oAscending) < 0) then
      Result := R((m + 1), hi)
    else
      Result := R(lo, (m - 1));
  end;
begin
  Result := R(0, High(Self));
end;

{==============================================================================]
  <BinaryTally>
  @action: Counts the number of occurrences of a specific value in a sorted array
           using two binary searches to find the first and last occurrence.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value is not found.
         - Time complexity is O(log n) - performs two binary searches.
         - More efficient than linear expansion for many duplicates.
[==============================================================================}
function MArrayHelper.BinaryTally(const x: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(0);
  R.Create(0, High(Self));
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = x) of
      True:
      begin
        F := M;
        R.stop := (M - 1);
      end;
      False:
      if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, High(Self));
  L := F;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = x) of
      True:
      begin
        L := M;
        R.start := (M + 1);
      end;
      False:
      if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  Result := ((L - F) + 1);
end;
{$ENDIF}
