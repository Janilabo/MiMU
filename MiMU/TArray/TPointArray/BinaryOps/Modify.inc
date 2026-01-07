{$IFDEF HELPERS}
function BinaryDelete(const item: TPoint): Boolean; overload;
function BinaryMerge(const items: TPointArray): TPointArray; overload;
function BinaryRemove(const item: TPoint; const all: Boolean = True): Integer; overload;
function BinaryReplace(const oItem, nItem: TPoint): Boolean; overload;
function BinaryReplaceAll(const oItem, nItem: TPoint): Integer; overload;
function BinarySinglified(const item: TPoint): TPointArray; overload;
function BinarySinglify(const item: TPoint): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryDelete>
  @action: Removes the specified TPoint from the array using binary search.
           If found, the element is deleted and the array is resized.
  @note: - The array must be sorted according to the same ordering rule
           used by TPointArray.BinarySearch.
         - All elements after the deleted item are shifted left by one.
         - Returns True if the point was found and removed, False otherwise.
[==============================================================================}
function TPointArrayHelper.BinaryDelete(const item: TPoint): Boolean; overload;
var
  i, p: Integer;
begin
  p := Self.BinarySearch(item);
  Result := (p > -1);
  if not Result then
    Exit;
  for i := p to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Size - 1));
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges the current sorted TPointArray with another sorted TPointArray,
           producing a new sorted array.
  @note: - Both arrays must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - The resulting array preserves sort order.
         - Duplicate points are preserved.
[==============================================================================}
function TPointArrayHelper.BinaryMerge(const items: TPointArray): TPointArray; overload;
var
  i, j, k: Integer;
  s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  SetLength(Result, (s + o));
  if (Result.Size < 1) then
    Exit;
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
  begin
    if (Self[i].Compare(items[j]) <= 0) then
      Result[k] := Self[i.Increase]
    else
      Result[k] := items[j.Increase];
    Inc(k);
  end;
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified TPoint from the array
           using binary search. If 'all' is True, every matching element is
           deleted; otherwise, only the first found instance is removed.
  @note: - The array must be sorted using the same ordering as
           TPointArray.BinarySearch and TPointArray.BinaryRange.
         - When 'all' is True, deletion shifts the remaining elements left.
         - Returns the number of elements removed (0 if none found).
[==============================================================================}
function TPointArrayHelper.BinaryRemove(const item: TPoint; const all: Boolean = True): Integer; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  case all of
    False: Result := IfThen(Self.BinaryDelete(item), 1, 0);
    True:
    begin
      r := Self.BinaryRange(item);
      if r.Employs(-1) then
        Exit(0);
      Result := r.Size;
      for i := r.start to ((l - Result) - 1) do
        Self[i] := Self[i + Result];
      SetLength(Self, (l - Result));
    end;
  end;
end;

{==============================================================================]
  <BinaryReplace>
  @action: BinaryReplace for TPointArray
  @note: Only Ascending order.
[==============================================================================}
function TPointArrayHelper.BinaryReplace(const oItem, nItem: TPoint): Boolean; overload;
begin
  Result := Self.BinaryDelete(oItem);
  if (Result and (oItem <> nItem)) then
    Self.BinaryInsert(nItem);
end;

{==============================================================================]
  <BinaryReplaceAll>
  @action: BinaryReplaceAll for TPointArray
  @note: Only Ascending order.
[==============================================================================}
function TPointArrayHelper.BinaryReplaceAll(const oItem, nItem: TPoint): Integer; overload;
var
  i, p: Integer;
  r: Boolean;
begin
  Result := 0;
  p := Self.BinaryPosL(oItem);
  if (p = -1) then
    Exit;
  r := False;
  for i := p to High(Self) do
    if (Self[i] = oItem) then
    begin
      Self[i] := nItem;
      Inc(Result);
      if ((not r) and (not Self.IsSorted(i))) then
        r := True;
    end else
      Break;
  if r then
    Self.BinaryInsertionSort;
end;

{==============================================================================]
  <BinarySinglified>
  @action: Returns a copy of the array with all occurrences of a specified point
           removed, preserving the original order.
  @note: - The array must be sorted ascending by X then Y, consistent with TPoint.Compare.
         - Uses BinaryPosL to locate the first occurrence efficiently.
[==============================================================================}
function TPointArrayHelper.BinarySinglified(const item: TPoint): TPointArray; overload;
var
  i, l, p: Integer;
begin
  p := Self.BinaryPosL(item);
  if (p = -1) then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  l := 0;
  for i := 0 to High(Self) do
    if ((i = p) or (Self[i] <> item)) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <BinarySinglify>
  @action: Removes all occurrences of a specified point from the sorted TPointArray
           in place, preserving ascending lexicographic order by X, then Y.
  @note: - The array must be sorted ascending by X, then Y, consistent with TPoint.Compare.
         - Uses BinaryPosL to locate the first occurrence efficiently.
         - Shifts subsequent elements left to fill removed entries.
         - Returns the number of points removed.
		 - KEEPS ONLY ONE!
[==============================================================================}
function TPointArrayHelper.BinarySinglify(const item: TPoint): Integer; overload;
var
  i, l, s, p: Integer;
begin
  p := Self.BinaryPosL(item);
  if (p = -1) then
    Exit(0);
  s := Self.Size;
  l := p;
  for i := (p + 1) to (s - 1) do
    if (Self[i] <> item)then
      Self[l.Increment] := Self[i];
  Result := (s - (l + 1));
  if (Result > 0) then
    SetLength(Self, (l + 1));
end;
{$ENDIF}
