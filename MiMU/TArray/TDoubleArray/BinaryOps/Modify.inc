{$IFDEF HELPERS}
function BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload;
function BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
function BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
function BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean;
function BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryDelete>
  @action: Removes the first occurrence of a specific value from a sorted array.
  @note: Uses binary search to locate the target efficiently.
         Returns True if the value was found and deleted, otherwise False.
         Works for ascending or descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload;
var
  p, l, i: Integer;
begin
  p := Self.BinaryIndex(x, aAscending);
  Result := (p <> -1);
  if not Result then
    Exit;
  l := Self.Length;
  for i := p to (l - 2) do
    Self[i] := Self[i + 1];
  SetLength(Self, (l - 1));
end;

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted double array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
var
  l, p, i, j: Integer;
  s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinarySearch(val, aAscending);
  if (p > -1) then
  case all of
    True:
    begin
      s.start := p;
      while ((s.start > 0) and (Self[s.start - 1] = val)) do
        Dec(s.start);
      s.stop := p;
      while ((s.stop < High(Self)) and (Self[s.stop + 1] = val)) do
        Inc(s.stop);
      j := s.start;
      for i := (s.stop + 1) to High(Self) do
        Self[j.Increase] := Self[i];
      SetLength(Self, j);
    end;
    False:
    begin
      for i := p to (High(Self) - 1) do
        Self[i] := Self[i + 1];
      SetLength(Self, (High(Self)));
    end;
  end;
  Result := (l - Self.Size);
end;

{==============================================================================]
  <BinaryReplace>
  @action: Replaces a specific value in a sorted array with a new one.
  @note:   Uses binary search to locate and delete the old value,
           then reinserts the new one while maintaining sorted order.
           Returns True if the old value was found and replaced, otherwise False.
           Complexity: O(log n + n)
[==============================================================================}
function TDoubleArrayHelper.BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := Self.BinaryDelete(oValue, aAscending);
  if (Result and (oValue <> nValue)) then
    Self.BinaryInsert(nValue, aAscending);
end;

{==============================================================================]
  <BinaryReplaceAll>
  @action: Replaces all occurrences of a specified value (oValue) with another
           value (nValue) in the array, preserving binary order if necessary.
  @note: Returns the number of replacements performed. If any substitution
         breaks sorted order, the array is re-sorted automatically using
         BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload;
var
  i, p: Integer;
  r: Boolean;
begin
  Result := 0;
  p := Self.BinaryPosL(oValue);
  if (p = -1) then
    Exit;
  r := False;
  for i := p to High(Self) do
    if (Self[i] = oValue) then
    begin
      Self[i] := nValue;
      Inc(Result);
      if ((not r) and (not Self.IsSorted(i, aAscending))) then
        r := True;
    end else
	  Break;
  if r then
    Self.BinaryInsertionSort(aAscending);
end;

{==============================================================================]
  <BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TDoubleArrayHelper.BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size > r.start) and (Self[r.start] = x));
  if not Result then
    Exit;
  for i := r.start to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Size - 1));
end;

{==============================================================================]
  <BinaryUpdate>
  @action: Updates the first occurrence of an element in the sorted array.
  @note: Searches for old_value using binary search. If found, replaces it with new_value.
         Returns True if updated, False if the value was not found.
         After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
var
  p: Integer;
begin
  Result := False;
  p := Self.BinaryIndex(oValue, aAscending);
  Result := (p <> -1);
  if Result then
    Self[p] := nValue;
end;
{$ENDIF}
