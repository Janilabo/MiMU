{$IFDEF HELPERS}
function BinaryEat(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function BinaryTake(const item: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
