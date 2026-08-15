{$IFDEF HELPERS}
function BinaryRemoval(const items: TIntegerArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryRemoval>
  @action: Creates a new array by removing all elements from Self that also
           appear in the specified items array, using a binary-style
           two-pointer scan optimized with block copying.
  @param: items       – Sorted array containing values that should be removed.
  @param: oAscending  – Sort order of both arrays:
                        True  = arrays are sorted ascending (default)
                        False = arrays are sorted descending
  @return: A new TIntegerArray containing elements from Self that are not
           present in items.
  @note:
    - Both Self and items must already be sorted according to oAscending.
      If the order is incorrect, the result may be invalid.
    - Runs in linear time O(L + T), where L = Length(Self) and T = Length(items).
    - Uses block copying (Move) to efficiently transfer contiguous ranges of
      retained elements instead of copying them one-by-one.
    - Does not modify Self; the filtered result is returned as a new array.
    - If items is empty, a copy of Self is returned.
    - If Self is empty, an empty array is returned.
    - All occurrences in Self that match values in items are removed.
[==============================================================================}
function TIntegerArrayHelper.BinaryRemoval(const items: TIntegerArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k, s, l, t, z: Integer;
begin
  t := items.Length;
  if (t = 0) then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  i := 0;
  j := 0;
  k := 0;
  z := SizeOf(Integer);
  while (i < l) do
  begin
    s := i;
    while (i < l) do
    begin
      if (j >= t) then
        Break;
      if ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j]))) then
      begin
        Inc(j);
        Continue;
      end;
      if (Self[i] = items[j]) then
        Break;
      Inc(i);
    end;
    if (i > s) then
    begin
      Move(Self[s], Result[k], ((i - s) * z));
      Inc(k, (i - s));
    end;
    if ((i < l) and (j < t) and (Self[i] = items[j])) then
      Inc(i);
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Asceal do
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
{$ENDIF}
