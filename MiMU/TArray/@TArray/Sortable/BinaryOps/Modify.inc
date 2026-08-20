{$IFDEF HELPERS}
function BinaryReplace(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryReplaceAll(const oItem, nItem: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryUpdate(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryReplace>
  @action: Replaces a specific item in a sorted array with a new one.
  @note: Uses binary search to locate and delete the old item,
         then reinserts the new one while maintaining sorted order.
         Returns True if the old item was found and replaced, otherwise False.
         Complexity: O(log n + n)
[==============================================================================}
function MArrayHelper.BinaryReplace(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := Self.BinaryDelete(oItem, aAscending);
  if (Result and (oItem <> nItem)) then
    Self.BinaryInsert(nItem, aAscending);
end;

{==============================================================================]
  <BinaryReplaceAll>
  @action: Replaces all occurrences of a specified item (oItem) with another
           item (nItem) in the array, preserving binary order if necessary.
  @note: Returns the number of replacements performed. If any substitution
         breaks sorted order, the array is re-sorted automatically using
         BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function MArrayHelper.BinaryReplaceAll(const oItem, nItem: MType; const aAscending: Boolean = True): Integer; overload;
var
  i, p: Integer;
  r: Boolean;
begin
  Result := 0;
  p := Self.BinaryLefty(oItem);
  if (p = -1) then
    Exit;
  r := False;
  for i := p to High(Self) do
    if (Self[i] = oItem) then
    begin
      Self[i] := nItem;
      Inc(Result);
      if ((not r) and (not Self.IsSorted(i, aAscending))) then
        r := True;
    end else
	  Break;
  if r then
    Self.BinaryInsertionSort(aAscending);
end;

{==============================================================================]
  <BinaryUpdate>
  @action: Updates the first occurrence of an element in the sorted array.
  @note: Searches for oItem using binary search. If found, replaces it with nItem.
         Returns True if updated, False if the item was not found.
         After replacement, sorting may be violated if nItem changes order.
[==============================================================================}
function MArrayHelper.BinaryUpdate(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
var
  p: Integer;
begin
  Result := False;
  p := Self.BinaryIndex(oItem, aAscending);
  Result := (p > -1);
  if Result then
    Self[p] := nItem;
end;
{$ENDIF}
