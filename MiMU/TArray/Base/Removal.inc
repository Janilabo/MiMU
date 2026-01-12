{$IFDEF HELPERS}
function Delete(const index: Integer = 0): MArray; overload;
function Delete(const ID: TIntegerArray): MArray; overload;
function Drop(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
function Dump(const items: MArray; const index: Integer = 0): MArray; overload;
function Erase(const item: MType; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
function Erase(const item: MType; const all: Boolean): MArray; overload;
function Erase(const items: MArray; const index: Integer = 2147483647; const all: Boolean = True): MArray; overload;
function Erase(const items: MArray; const all: Boolean): MArray; overload;
function Pop: MType; overload;
function Pop(const null: MType): MType; overload;
function Pull: MArray; overload;
function Remove(const item: MType; const index: Integer = 0; const all: Boolean = True): MArray; overload;
function Remove(const item: MType; const all: Boolean): MArray; overload;
function Remove(const items: MArray; const index: Integer = 0; const all: Boolean = True): MArray; overload;
function Remove(const items: MArray; const all: Boolean): MArray; overload;
function Shift: MType; overload;
function Shift(const sCount: Integer): MArray; overload;
function Strip(const item: MType; const eraseDuplicates: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}