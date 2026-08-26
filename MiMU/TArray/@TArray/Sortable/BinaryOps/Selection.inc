{$IFDEF HELPERS}
function BinaryClampMax(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMin(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryExcept(const target: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryExtract(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryFilter(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryItems(const item: MType; const aAscending: Boolean = True): MArray; overload;
function BinarySlice(const itemMin, itemMax: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryWithout(const target: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryExtractByMin(const limit: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryExtractByMax(const limit: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryFilterByMin(const limit: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryFilterByMax(const limit: MType; const oAscending: Boolean = True): MArray; overload;

function BinaryExtractify(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryExtractifyMax(const target: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryExtractifyMin(const target: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryFilterify(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryFilterifyMax(const target: MType; const oAscending: Boolean = True): MArray; overload;
function BinaryFilterifyMin(const target: MType; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BinaryExtract>
  @action: Returns a new array containing every element of Self that also
           appears in items (set intersection), preserving Self's original
           order.
  @note:
    - Both Self and items must be sorted according to aAscending.
    - Uses an early-exit optimization: once an element of Self exceeds
      (ascending) or falls below (descending) the range of items, no
      further elements of Self can match, and the scan stops.
    - Time complexity: O(S) worst case with early exit, using
      BinaryContains (O(log T)) per candidate element.
[==============================================================================}
function MArrayHelper.BinaryExtract(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  v: MArray;
  h, i, r: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  v := items.QuickSorted;
  h := High(v);
  r := 0;
  case aAscending of
    True:
    for i := 0 to Result.Alloc(Self.Size) do
      if (Self[i] > v[h]) then
        Break
      else if ((Self[i] >= v[0]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
    False:
    for i := 0 to Result.Alloc(Self.Size) do
      if (Self[i] < v[0]) then
        Break
      else if ((Self[i] <= v[h]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns a new array containing every element of Self that does
           NOT appear in items (set difference / complement of BinaryExtract),
           preserving Self's original order.
  @note:
    - items must be sorted according to aAscending. Self does not need
      to be sorted — every element of Self is checked individually via
      BinaryContains, since no early-exit shortcut is possible when
      producing a complement (unlike BinaryExtract's intersection case).
    - If items is empty, a copy of Self is returned unchanged.
    - If Self is empty, an empty array is returned.
    - Time complexity: O(S log T), where S = Length(Self), T = Length(items).
[==============================================================================}
function MArrayHelper.BinaryFilter(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  i, r: Integer;
begin
  if Self.Empty then
    Exit([]);
  if items.Empty then
    Exit(Self.Copy);
  r := 0;
  for i := 0 to Result.Alloc(Self.Size) do
    if not items.BinaryContains(Self[i], aAscending) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryItems>
  @action: Returns all items in the array that match a given item using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the item of aAscending. If the item does not occur in the array,
         an empty array is returned.
[==============================================================================}
function MArrayHelper.BinaryItems(const item: MType; const aAscending: Boolean = True): MArray; overload;
var
  i: Integer;
  r: TRange;
begin
  r := Self.BinaryRange(item, aAscending);
  if r.Employs(-1) then
    Exit([]);
  for i := 0 to Result.Alloc(r.Size) do
    Result[i] := Self[r.start + i];
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

{==============================================================================]
  <BinaryExtractByMin>
  @action: Returns a new array containing every element of Self that is equal
           to or greater than limit, using a binary boundary search.
  @note: Self must be sorted according to oAscending. This is the non-mutating
         complement of BinaryClampMin — it returns exactly the elements that
         BinaryClampMin would retain, without modifying Self.
         Returns an empty array if no elements meet the limit.
[==============================================================================}
function MArrayHelper.BinaryExtractByMin(const limit: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if oAscending then
    r.Create(Self.BinaryBoundLower(limit, oAscending), (l - 1))
  else
    r.Create(0, (Self.BinaryBoundUpper(limit, oAscending) - 1));
  if ((r.start >= l) or (r.stop < 0) or (r.start > r.stop)) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := r.start to r.stop do
    Result[i - r.start] := Self[i];
end;

{==============================================================================]
  <BinaryExtractByMax>
  @action: Returns a new array containing every element of Self that is equal
           to or less than limit, using a binary boundary search.
  @note: Self must be sorted according to oAscending. This is the non-mutating
         complement of BinaryClampMax — it returns exactly the elements that
         BinaryClampMax would retain, without modifying Self.
         Returns an empty array if no elements meet the limit.
[==============================================================================}
function MArrayHelper.BinaryExtractByMax(const limit: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if oAscending then
    r.Create(0, (Self.BinaryBoundUpper(limit, oAscending) - 1))
  else
    r.Create(Self.BinaryBoundLower(limit, oAscending), (l - 1));
  if ((r.start >= l) or (r.stop < 0) or (r.start > r.stop)) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := r.start to r.stop do
    Result[i - r.start] := Self[i];
end;

{==============================================================================]
  <BinaryFilterByMin>
  @action: Returns a new array containing every element of Self that is less
           than limit, using a binary boundary search.
  @note: Self must be sorted according to oAscending. This is the complement
         of BinaryExtractByMin — together they partition Self at limit without
         mutating it. Also equivalent to the elements BinaryClampMin would discard.
         Returns an empty array if no elements fall below the limit.
[==============================================================================}
function MArrayHelper.BinaryFilterByMin(const limit: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if oAscending then
    r.Create(0, (Self.BinaryBoundLower(limit, oAscending) - 1))
  else
      r.Create(Self.BinaryBoundUpper(limit, oAscending), (l - 1));
  if ((r.start >= l) or (r.stop < 0) or (r.start > r.stop)) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := r.start to r.stop do
    Result[i - r.start] := Self[i];
end;

{==============================================================================]
  <BinaryFilterByMax>
  @action: Returns a new array containing every element of Self that is greater
           than limit, using a binary boundary search.
  @note: Self must be sorted according to oAscending. This is the complement
         of BinaryExtractByMax — together they partition Self at limit without
         mutating it. Also equivalent to the elements BinaryClampMax would discard.
         Returns an empty array if no elements exceed the limit.
[==============================================================================}
function MArrayHelper.BinaryFilterByMax(const limit: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if oAscending then
    r.Create(Self.BinaryBoundUpper(limit, oAscending), (l - 1))
  else
    r.Create(0, (Self.BinaryBoundLower(limit, oAscending) - 1));
  if ((r.start >= l) or (r.stop < 0) or (r.start > r.stop)) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := r.start to r.stop do
    Result[i - r.start] := Self[i];
end;

{==============================================================================]
  <BinaryExtractify>
  @action: Uses binary search to extract all elements falling within the inclusive range [`aMin`, `aMax`] from a sorted array into a new array.
  @note: Achieves O(log N) boundary lookup time using `BinaryMinBound` and `BinaryMaxBound` to locate the contiguous target slice before copying it to `Result`.
         Supports both ascending and descending sorted arrays via `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryExtractify(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
var
  i: Integer;
  r: TRange;
begin
  if oAscending then
  begin
    r.start := Self.BinaryMinBound(aMin, oAscending);
    if (r.start = -1) then
      Exit([]);
    r.stop := Self.BinaryMaxBound(aMax, oAscending);
  end else
  begin
    r.start := Self.BinaryMinBound(aMax, oAscending);
    if (r.start = -1) then
      Exit([]);
    r.stop := Self.BinaryMaxBound(aMin, oAscending);
  end;
  for i := 0 to Result.Alloc(r.Size) do
    Result[i] := Self[i + r.start];
end;

{==============================================================================]
  <BinaryExtractifyMax>
  @action: Uses binary search to extract all elements less than or equal to `target` (ascending) or greater than or equal to `target` (descending) from a sorted array into a new array.
  @note: Leverages binary search bounds to locate the threshold pivot in O(log N) time, extracting the prefix slice for ascending arrays or the suffix slice for descending arrays.
[==============================================================================}
function MArrayHelper.BinaryExtractifyMax(const target: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, p: Integer;
begin
  SetLength(Result, 0);
  if oAscending then
  begin
    p := Self.BinaryMaxBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(p + 1) do
      Result[i] := Self[i];
  end else
  begin
    p := Self.BinaryMinBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(Self.Length - p) do
      Result[i] := Self[p + i];
  end;
end;

{==============================================================================]
  <BinaryExtractifyMin>
  @action: Uses binary search to extract all elements greater than or equal to `target` (ascending) or less than or equal to `target` (descending) from a sorted array into a new array.
  @note: Leverages binary search bounds to locate the threshold pivot in O(log N) time, extracting the suffix slice for ascending arrays or the prefix slice for descending arrays.
[==============================================================================}
function MArrayHelper.BinaryExtractifyMin(const target: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, p: Integer;
begin
  SetLength(Result, 0);
  if oAscending then
  begin
    p := Self.BinaryMinBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(Self.Length - p) do
      Result[i] := Self[p + i];
  end else
  begin
    p := Self.BinaryMaxBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(p + 1) do
      Result[i] := Self[i];
  end;
end;

{==============================================================================]
  <BinaryFilterify>
  @action: Uses binary search to identify elements falling within [`aMin`, `aMax`] in a sorted array, returning a new array with those elements excluded.
  @note: Leverages binary search bounds to locate the target sub-range in O(log N) time and copies the remaining outer segments.
         Returns a full clone of `Self` if no elements fall within the range.
[==============================================================================}
function MArrayHelper.BinaryFilterify(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
var
  r: TRange;
  l, i, s: Integer;
begin
  if oAscending then
    r.Create(Self.BinaryMinBound(aMin, oAscending), Self.BinaryMaxBound(aMax, oAscending))
  else
    r.Create(Self.BinaryMinBound(aMax, oAscending), Self.BinaryMaxBound(aMin, oAscending));
  if ((r.start = -1) or (r.stop = -1) or (r.start > r.stop)) then
    Exit(Self.Clone);
  s := Result.SetSize(Self.Length - r.Size);
  for i := High(Self) downto (r.stop + 1) do
    Result[s.Decrement] := Self[i];
  for i := (r.start - 1) downto 0 do
    Result[s.Decrement] := Self[i];
end;

{==============================================================================]
  <BinaryFilterifyMax>
  @action: Uses binary search to filter out elements up to `target`, returning a new array with elements strictly greater than `target` (ascending) or strictly less than `target` (descending).
  @note: Uses binary search to locate the cutoff index in O(log N) time, returning the remaining slice. Returns an empty array if no boundary element satisfies the condition.
[==============================================================================}
function MArrayHelper.BinaryFilterifyMax(const target: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, p: Integer;
begin
  SetLength(Result, 0);
  if oAscending then
  begin
    p := Self.BinaryMinBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(p) do
      Result[i] := Self[i];
  end else
  begin
    p := Self.BinaryMaxBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(Self.Length - (p + 1)) do
      Result[i] := Self[p + i + 1];
  end;
end;

{==============================================================================]
  <BinaryFilterifyMin>
  @action: Uses binary search to filter out elements down to `target`, returning a new array with elements strictly less than `target` (ascending) or strictly greater than `target` (descending).
  @note: Uses binary search to locate the cutoff index in O(log N) time, returning the remaining slice. Returns an empty array if no boundary element satisfies the condition.
[==============================================================================}
function MArrayHelper.BinaryFilterifyMin(const target: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, p: Integer;
begin
  SetLength(Result, 0);
  if oAscending then
  begin
    p := Self.BinaryMaxBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(Self.Length - (p + 1)) do
      Result[i] := Self[p + i + 1];
  end else
  begin
    p := Self.BinaryMaxBound(target, oAscending);
    if (p > -1) then
    for i := 0 to Result.Alloc(p + 1) do
      Result[i] := Self[i];
  end;
end;
{$ENDIF}
