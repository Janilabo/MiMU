{$IFDEF HELPERS}
function Cut(const cIndex: Integer; const nItem: MType): MType; overload;
function Cut(const cIndex: Integer = 0): MType; overload;
function Del(const dIndex: Integer = 0): Integer; overload;
function Delete(const index: Integer = 0): MArray; overload;
function Delete(const ID: TIntegerArray): MArray; overload;
function Deload(var target: MArray; const clearing: Boolean = True): Integer; overload;
function Discard(const ID: TIntegerArray): MArray; overload;
function Drop(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
function Dump(const items: MArray; const index: Integer = 0): MArray; overload;
function Eject(const eIndex: Integer): Integer; overload;
function Erase(const item: MType; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
function Erase(const item: MType; const all: Boolean): MArray; overload;
function Erase(const items: MArray; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
function Erase(const items: MArray; const all: Boolean): MArray; overload;
function Evict(const item: MType): Boolean; overload;
function Pop: MType; overload;
function Pop(const null: MType): MType; overload;
function Pull: MArray; overload;
function Pull(const pIndex: Integer): MType; overload;
function Purge(const item: MType): Integer; overload;
function Remove(const item: MType; const index: Integer = 0; const all: Boolean = True): MArray; overload;
function Remove(const item: MType; const all: Boolean): MArray; overload;
function Remove(const items: MArray; const index: Integer = 0; const all: Boolean = True): MArray; overload;
function Remove(const items: MArray; const all: Boolean): MArray; overload;
function RemoveIndex(const rIndex: Integer = 0): Boolean; overload;
function Shift: MType; overload;
function Shift(const sCount: Integer): MArray; overload;
function Strip(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
function Zap(const zIndex: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cut>
  @action: Removes the element at cIndex and returns it.
  @returns: The extracted element. If cIndex is out of bounds, returns nItem.
  @note: Uses Move for high-speed memory shifting. Effectively a "Pop" 
         operation with a safe fallback value.
[==============================================================================}
function MArrayHelper.Cut(const cIndex: Integer; const nItem: MType): MType; overload;
var
  h: Integer;
begin
  h := (Self.Length - 1);
  if ((cIndex < 0) or (cIndex > h)) then
    Exit(nItem);
  Result := Self[cIndex];
  if (cIndex < h) then
    Move(Self[cIndex + 1], Self[cIndex], ((h - cIndex) * SizeOf(MType)));
  SetLength(Self, h);
end;

{==============================================================================]
  <Cut>
  @action: Removes the element at cIndex and returns that element's value.
  @returns: The value of the removed element.
  @note: Default index is 0. If cIndex is out of bounds, an exception is raised
         (standard surgical behavior) or a default value is returned.
[==============================================================================}
function MArrayHelper.Cut(const cIndex: Integer = 0): MType; overload;
var
  n: MType;
begin
  Result := Self.Cut(cIndex, n);
end;

{==============================================================================]
  <Del>
  @action: Unsafely removes the element at dIndex by shifting elements left.
  @returns: The new Length of the array.
  @note: Default index is 0. This is a "raw" operation: it does not validate 
         if dIndex is within current bounds. Calling on an empty array 
         safely returns 0.
[==============================================================================}
function MArrayHelper.Del(const dIndex: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := High(Self);
  if (Result < 0) then
    Exit(0);
  for i := dIndex to (Result - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Delete>
  @action: Deletes array item from arr by index.
  @note: Returns true with success (index existed in arr).
[==============================================================================}
function MArrayHelper.Delete(const index: Integer = 0): MArray; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  if not ((index <= h) and (index > -1)) then
    Exit(Self.Copy);
  SetLength(Result, h);
  for i := 0 to (index - 1) do
    Result[i] := Self[i];
  for i := index to (h - 1) do
    Result[i] := Self[i + 1];
end;

{==============================================================================]
  <Delete>
  @action: Deletes array items from arr by indexes (ID).
  @note: Returns amount of items that were deleted succesfully by ID's.
[==============================================================================}
function MArrayHelper.Delete(const ID: TIntegerArray): MArray; overload;
var
  i, l, r: Integer;
begin
  if ID.Empty then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
    if not ID.Contains(i) then
      Result[i - r] := Self[i]
    else
      r := (r + 1);
  SetLength(Result, (l - r));
end;

{==============================================================================]
  <Deload>
  @action: Transfers all elements from the current array into the `target` array,
           resizing `target` if necessary. If `clearing` is True, the current
           array is emptied after the transfer; otherwise, it is left unchanged.
  @note: The function returns the number of elements transferred. The order
         of elements is preserved. The original array may be cleared depending
         on the `clearing` parameter, while `target` contains a copy of all
         the elements from the source array.
[==============================================================================}
function MArrayHelper.Deload(var target: MArray; const clearing: Boolean = True): Integer; overload;
var
  i, j, l: Integer;
begin
  Result := Self.Length;
  if (Result <> target.Length) then
    SetLength(target, Result);
  for i := 0 to High(Self) do
    target[i] := Self[i];
  if (clearing and (Result > 0)) then
    SetLength(Self, 0);
end;

{==============================================================================]
  <Discard>
  @action: Returns a new MArray with the elements at the specified indices removed.
  @note:
    - Non-mutating: the source array (Self) remains unchanged.
    - Indices outside the valid range [0..Length-1] are ignored.
    - Duplicate indices are tolerated.
    - If IDs is empty, a copy of Self is returned.
    - If Self is empty, an empty array is returned.
    - Order of remaining elements is preserved.
[==============================================================================}
function MArrayHelper.Discard(const ID: TIntegerArray): MArray; overload;
var
  i, l, m: Integer;
  s: TRange;
  r: TIntegerArray;
begin
  if ID.Empty then
    Exit(Self.Copy);
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  r := Self.IDs;
  s.Create(0, (l - 1));
  m := 0;
  for i := 0 to High(ID) do
    if s.Contains(ID[i]) then
      r[ID[i]] := -1
    else
      m := (m + 1);
  SetLength(Result, (l - m));
  l := 0;
  for i := 0 to s.stop do
    if (r[i] <> -1) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <Drop>
  @action: Removes item(s) from arr and returns it.
  @note: 	
[==============================================================================}
function MArrayHelper.Drop(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Positions(item)
  else
    p := [Self.Pos(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
  <Dump>
  @action: Deletes items from array, keeps others. Returns array length (after action).
  @note: Supports custom start index!
[==============================================================================}
function MArrayHelper.Dump(const items: MArray; const index: Integer = 0): MArray; overload;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  d := 0;
  m := Max(0, index);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
  <Eject>
  @action: Removes the element at eIndex and returns the new Length of the array.
  @returns: The updated element count. If the index is invalid, returns the 
            original length (no change).
  @note: This shifts subsequent elements and shrinks the memory block.
[==============================================================================}
function MArrayHelper.Eject(const eIndex: Integer): Integer; overload;
var
  i: Integer;
begin
  Result := High(Self);
  if ((eIndex > Result) or (eIndex < 0)) then
    Exit(Result + 1);
  for i := eIndex to (Result - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Erase>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function MArrayHelper.Erase(const item: MType; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
var
  j, i, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  if not (Self.Empty or (index < 0)) then
  begin
    l := Self.Length;
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      if (Self[i] = item) then
      begin
        r[i] := True;
        Inc(d);
        f := True;
      end;
      if (f and (not all)) then
        Break;
    end;
    j := 0;
	SetLength(Result, (l - d));
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
  <Erase>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed.
[==============================================================================}
function MArrayHelper.Erase(const item: MType; const all: Boolean): MArray; overload;
begin
  Result := Self.Erase(item, 2147483647, all);
end;

{==============================================================================]
  <Erase>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function MArrayHelper.Erase(const items: MArray; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
var
  h, i, j, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  if (Self.Populated and items.Populated and (index >= 0)) then
  begin
    h := High(items);
    l := Self.Length;
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      for j := 0 to h do
        if (Self[i] = items[j]) then
        begin
          r[i] := True;
          Inc(d);
          f := True;
          Break;
        end;
      if (f and (not all)) then
        Break;
    end;
	j := 0;
	SetLength(Result, (l - d));
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
  <Erase>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed.
[==============================================================================}
function MArrayHelper.Erase(const items: MArray; const all: Boolean): MArray; overload;
begin
  Result := Self.Erase(items, 2147483647, all);
end;

{==============================================================================]
  <Evict>
  @action: Removes the first occurrence of <item> from the array using an
           unordered removal strategy (swap-with-last compaction).
  @note:
    - Does not validate array bounds or internal state.
    - Order of elements is not preserved after eviction.
    - The caller is responsible for ensuring array integrity before calling.
    - Returns True if the item was found and removed, otherwise False.
    - Time complexity is approximately O(n) due to search operation.
    - This is a single-occurrence eviction.
[==============================================================================}
function MArrayHelper.Evict(const item: MType): Boolean; overload;
var
  h, p: Integer;
begin
  p := Self.Pos(item);
  Result := (p > -1);
  if not Result then
    Exit;
  h := High(Self);
  Self[p] := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Pop>
  @action: Returns and removes item from highest array index from arr.
  @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
function MArrayHelper.Pop: MType; overload;
var
  h: Integer;
begin
  if Self.Empty then
    Exit;
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Pop>
  @action: Returns and removes item from highest array index from arr.
  @note: Returns null if array contains no items.
[==============================================================================}
function MArrayHelper.Pop(const null: MType): MType; overload;
var
  h: Integer;
begin
  if Self.Empty then
    Exit(null);
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Pull>
  @action: Returns the contents of the array and leaves it empty.
  @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function MArrayHelper.Pull: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  SetLength(Self, 0);
end;

{==============================================================================]
  <Pull>
  @action: Extracts the element at the specified index, shifts the remaining 
           elements to close the gap, and returns the extracted value.
  @note: This is an O(N) operation. If the index is out of bounds, the function 
         returns the default value for the type.
[==============================================================================}
function MArrayHelper.Pull(const pIndex: Integer): MType; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((pIndex > h) or (pIndex < 0)) then
    Exit;
  Result := Self[pIndex];
  for i := pIndex to (h - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, h);
end;

{==============================================================================]
  <Purge>
  @action: Removes all occurrences of <item> from the array by overwriting matched
           elements with the current tail element and shrinking the array length.
  @note:
    - Order of elements is not preserved after purging.
    - Removes all matching occurrences of <item>.
    - The caller is responsible for ensuring array and range invariants.
    - Returns the number of elements removed.
    - Time complexity is approximately O(n), since the operation performs
      repeated bounded linear searches during purging.
    - This is a multi-occurrence purge operation.
[==============================================================================}
function MArrayHelper.Purge(const item: MType): Integer; overload;
var
  l: Integer;
  s: TRange;
begin
  Result := 0;
  l := Self.Length;
  if (l > 0) then
  begin
    s.Create(0, (l - 1));
    repeat
      s.start := Self.IndexOf(item, s);
      if (s.start = -1) then
        Break;
      Result := (Result + 1);
      Self[s.start] := Self[s.stop];
    until (s.start > s.stop.Decrement);
    if (Result > 0) then
      SetLength(Self, (l - Result));
  end;
end;

{==============================================================================]
  <Remove>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function MArrayHelper.Remove(const item: MType; const index: Integer = 0; const all: Boolean = True): MArray; overload;
var
  l, i, r, m: Integer;
  s: Boolean;
begin
  l := Self.Length;
  if ((l = 0) or (index >= l)) then
    Exit(Self.Copy);
  m := Max(0, index);
  s := False;
  r := 0;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if (s or (Self[i] <> item)) then
      Result[r.Increase + m] := Self[i]
    else
      s := not all;
  SetLength(Result, (r + m));
end;

{==============================================================================]
  <Remove>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed.
[==============================================================================}
function MArrayHelper.Remove(const item: MType; const all: Boolean): MArray; overload;
begin
  Result := Self.Remove(item, 0, all);
end;

{==============================================================================]
  <Remove>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function MArrayHelper.Remove(const items: MArray; const index: Integer = 0; const all: Boolean = True): MArray; overload;
var
  a, b, l, i, r, m: Integer;
  d, s: Boolean;
begin
  l := Self.Length;
  b := High(items);
  if ((l = 0) or (index >= l) or (b = -1)) then
    Exit(Self.Copy);
  m := Max(0, index);
  r := 0;
  s := False;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (Self[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
      Result[r.Increase + m] := Self[i]
    else
      d := not s;
  end;
  SetLength(Result, (r + m));
end;

{==============================================================================]
  <Remove>
  @action: Deletes item(s) from array arr. Only 1 if all is set as False.
  @note: Returns amount of items that were removed.
[==============================================================================}
function MArrayHelper.Remove(const items: MArray; const all: Boolean): MArray; overload;
begin
  Result := Self.Remove(items, 0, all);
end;

{==============================================================================]
  <RemoveIndex>
  @action: Validates the rIndex and, if valid, removes that element.
  @returns: True if the element was successfully removed; False if the index 
            was out of bounds.
  @note: Default index is 0. This method utilizes high-speed memory block 
         shifting (Move) and reduces the array length by 1.
[==============================================================================}
function MArrayHelper.RemoveIndex(const rIndex: Integer = 0): Boolean; overload;
var
  r: Integer;
begin
  r := High(Self);
  Result := not ((rIndex < 0) or (rIndex > r));
  if not Result then
    Exit;
  if (rIndex < r) then
    Move(Self[rIndex + 1], Self[rIndex], ((r - rIndex) * SizeOf(MType)));
  SetLength(Self, r);
end;

{==============================================================================]
  <Shift>
  @action: Shortens the array with first element.
  @note: Returns the removed arr[0].
[==============================================================================}
function MArrayHelper.Shift: MType; overload;
var
  i, h: Integer;
begin
  h := (Self.Size - 1);
  if (h < 0) then
    Exit;
  Result := Self[0];
  for i := 0 to (h - 1) do
    Self[i] := Self[i + h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Shift>
  @action: Shortens the array with first SCOUNT element(s).
  @note: Returns the removed arr[x]s.
[==============================================================================}
function MArrayHelper.Shift(const sCount: Integer): MArray; overload;
var
  i, l, s: Integer;
begin
  l := Self.Length;
  s := Max(0, Min(sCount, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  for i := s to High(Self) do
    Self[i - s] := Self[i];
  SetLength(Self, (Self.Size - s));
end;

{==============================================================================]
  <Strip>
  @action: Removes item(s) from arr and returns it.
  @note: 	
[==============================================================================}
function MArrayHelper.Strip(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Locations(item)
  else
    p := [Self.Loc(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
  <Zap>
  @action: Unsafely removes the element at zIndex and returns the new Length.
  @note: Default index is 0. This is a high-performance, raw memory operation.
         Warning: No bounds checking is performed. If zIndex is invalid, 
         this will result in memory corruption or an Access Violation.
[==============================================================================}
function MArrayHelper.Zap(const zIndex: Integer = 0): Integer; overload;
begin
  Result := (Self.Length - 1);
  if (zIndex < Result) then
    Move(Self[zIndex + 1], Self[zIndex], ((Result - zIndex) * SizeOf(MType)));
  SetLength(Self, Result);
end;
{$ENDIF}
