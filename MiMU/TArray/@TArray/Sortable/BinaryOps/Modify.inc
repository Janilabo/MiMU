{$IFDEF HELPERS}
function BinaryDelete(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryDeletion(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryRemoval(const item: MType; const all: Boolean = True; const oAscending: Boolean = True): Integer; overload;
function BinaryRemove(const item: MType; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
function BinaryReplace(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryReplaceAll(const oItem, nItem: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryUpdate(const oItem, nItem: MType; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryDelete>
  @action: Removes the first occurrence of a specific item from a sorted array.
  @note: Uses binary search to locate the target efficiently.
         Returns True if the item was found and deleted, otherwise False.
         Works for ascending or descending arrays.
[==============================================================================}
function MArrayHelper.BinaryDelete(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  p, l, i: Integer;
begin
  p := Self.BinaryIndex(item, aAscending);
  Result := (p > -1);
  if not Result then
    Exit;
  l := Self.Length;
  for i := p to (l - 2) do
    Self[i] := Self[i + 1];
  SetLength(Self, (l - 1));
end;

{==============================================================================]
  <BinaryDeletion>
  @action: Removes the first occurrence of item from Self, located via binary
           search, and returns True if an element was removed.
  @note: Array must be sorted according to oAscending, consistent with
         BinarySearcha's comparison convention (element's .Contest() method).
         Returns False and leaves Self unmodified if item is not found.
         Shifts all elements after the found index left by one position —
         O(n) worst case due to the shift, despite O(log n) lookup.
[==============================================================================}
function MArrayHelper.BinaryDeletion(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  i, p: Integer;
begin
  p := Self.BinarySearcha(item, oAscending);
  Result := (p > -1);
  if not Result then
    Exit;
  for i := p to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Size - 1));
end;

{==============================================================================]
  <BinaryRemoval>
  @action: Removes occurrences of item from Self, located via binary search.
           If all is True, removes every occurrence in one pass; if False,
           removes only the first occurrence found. Returns the number of
           elements removed.
  @note: Array must be sorted according to oAscending, consistent with the
         comparison convention used by BinaryRange/BinaryDeletion. Returns 0
         if item is not found or Self is empty. Self is left unmodified when
         no elements are removed.
[==============================================================================}
function MArrayHelper.BinaryRemoval(const item: MType; const all: Boolean = True; const oAscending: Boolean = True): Integer; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  case all of
    True:
    begin
      r := Self.BinaryRange(item, oAscending);
      if r.Employs(-1) then
        Exit(0);
      Result := r.Size;
      for i := r.start to ((l - Result) - 1) do
        Self[i] := Self[i + Result];
      SetLength(Self, (l - Result));
    end;
	False: Result := IfThen(Self.BinaryDelete(item, oAscending), 1, 0);
  end;
end;

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified item from a sorted array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function MArrayHelper.BinaryRemove(const item: MType; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
var
  l, p, i, j: Integer;
  s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinarySearch(item, aAscending);
  if (p > -1) then
  case all of
    True:
    begin
      s.start := p;
      while ((s.start > 0) and (Self[s.start - 1] = item)) do
        Dec(s.start);
      s.stop := p;
      while ((s.stop < High(Self)) and (Self[s.stop + 1] = item)) do
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
