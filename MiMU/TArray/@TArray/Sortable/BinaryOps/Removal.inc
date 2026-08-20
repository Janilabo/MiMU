{$IFDEF HELPERS}
function BinaryDelete(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryDeletion(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryEat(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryRemoval(const item: MType; const all: Boolean = True; const oAscending: Boolean = True): Integer; overload;
function BinaryRemove(const item: MType; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
function BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function BinaryTake(const item: MType; const oAscending: Boolean = True): Boolean; overload;
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
  <BinaryEat>
  @action: Removes item from Self via binary search, preserving sorted order.
           Works with ascending or descending order based on oAscending.
  @note: Returns True if item was found and removed, False if not present.
[==============================================================================}
function MArrayHelper.BinaryEat(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  m, i: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if (oAscending = (Self[m] < item)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((r.start <= High(Self)) and (Self[r.start] = item));
  if not Result then
    Exit;
  for i := r.start to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Length - 1));
end;

{==============================================================================]
  <BinaryExclude>
  @action: Removes item from Self via binary search, preserving sorted order.
           Works with ascending or descending order based on oAscending.
  @note: Returns True if item was found and removed, False if not present.
[==============================================================================}
function MArrayHelper.BinaryExclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  m: Integer;
  r: TRange;
begin
  r := TRange.Construct(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m] = item) then
    begin
      System.Delete(Self, m, 1);
      Exit(True);
    end;
    if ((oAscending and (Self[m] < item)) or (not oAscending and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := False;
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
  <BinaryRemoveAll>
  @action: Removes all elements from Self that also appear in the items array,
           modifying Self in place using a binary-style merge scan.
  @param: items      – Sorted array containing values to remove from Self.
  @param: oAscending  – Sort order of both arrays:
                        True  = arrays are sorted ascending (default)
                        False = arrays are sorted descending
  @return: The number of elements removed from Self.
  @note:
    - Both Self and items must already be sorted according to oAscending.
      If the ordering differs, the result is undefined.
    - Performs an in-place removal using a two-pointer linear scan.
      Time complexity: O(L + T), where L = Length(Self) and T = Length(target).
    - The array capacity is reused during compaction, then truncated to the
      new length at the end.
    - If no elements are removed, Self remains unchanged and the function
      returns 0.
    - Duplicate values in Self that match items values will all be removed.
[==============================================================================}
function MArrayHelper.BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  i, j, l, t: Integer;
begin
  t := items.Length;
  if (t = 0) then
    Exit(0);
  l := Self.Length;
  i := 0;
  j := 0;
  Result := 0;
  while (i < l) do
    if ((j < t) and (Self[i] = items[j])) then
      Inc(i)
    else if ((j < t) and ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j])))) then
      Inc(j)
    else
      Self[Result.Increase] := Self[i.Increase];
  if (l = Result) then
    Exit(0);
  SetLength(Self, Result);
  Result := (l - Result);
end;

{==============================================================================]
  <BinaryTake>
  @action: Removes item from Self via binary search, preserving sorted order.
           Works with ascending or descending order based on oAscending.
  @note: Returns True if item was found and removed, False if not present.
[==============================================================================}
function MArrayHelper.BinaryTake(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  l, h, m, i: Integer;
begin
  l := 0;
  h := High(Self);
  while (l <= h) do
  begin
    m := (l + ((h - l) div 2));
    if (Self[m] = item) then
    begin
      for i := m to (High(Self) - 1) do
        Self[i] := Self[i + 1];
      SetLength(Self, (Self.Length - 1));
      Exit(True);
    end;
    if ((oAscending and (Self[m] < item)) or (not oAscending and (Self[m] > item))) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  Result := False;
end;
{$ENDIF}
