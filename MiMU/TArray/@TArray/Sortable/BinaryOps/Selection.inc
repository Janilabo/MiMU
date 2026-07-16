{$IFDEF HELPERS}
function BinaryClampMax(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMin(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryExcept(const target: MArray; const oAscending: Boolean = True): MArray; overload;
function BinarySlice(const itemMin, itemMax: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryWithout(const target: MArray; const oAscending: Boolean = True): MArray; overload;
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
{$ENDIF}
