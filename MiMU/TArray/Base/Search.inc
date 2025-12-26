{$IFDEF HELPERS}
function Find(const ID: TRange; const item: MType): Integer; overload;
function Find(const ID: TIntegerArray; const item: MType): Integer; overload;
function Find(const ID: TRange; const items: MArray): Integer; overload;
function Find(const ID: TIntegerArray; const items: MArray): Integer; overload;
function First: Integer; overload;
function First(const item: MType): Integer; overload;
function First(const items: MArray): Integer; overload;
function Last: Integer; overload;
function Last(const item: MType): Integer; overload;
function Last(const items: MArray): Integer; overload;
function Loc(const item: MType; const index: Integer = 2147483647): Integer; overload;
function Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload;
function Location(const item: MType; const index: Integer = 2147483647): Integer; overload;
function Location(const items: MArray; const index: Integer = 2147483647): Integer; overload;
function Pos(const item: MType; const index: Integer = 0): Integer; overload;
function Pos(const items: MArray; const index: Integer = 0): Integer; overload;
function Position(const item: MType; const index: Integer = 0): Integer; overload;
function Position(const items: MArray; const index: Integer = 0): Integer; overload;
function SubarrayLocation(const pattern: MArray): Integer; overload;
function SubarrayPosition(const pattern: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Find>
  @action: Scans array for item by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TRange; const item: MType): Integer; overload;
begin
  if Self.Populated then
  case ID.Ascending of
    True:
    for Result := ID.start to ID.stop do
      if (Self[Result] = item) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if (Self[Result] = item) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for item by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TIntegerArray; const item: MType): Integer; overload;
var
  i: Integer;
begin
  if Self.Populated then
  for i := 0 to High(ID) do
    if (Self[ID[i]] = item) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for items by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TRange; const items: MArray): Integer; overload;
begin
  if (Self.Populated and items.Populated) then
  case ID.Ascending of
    True:
    for Result := ID.start to ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for items by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TIntegerArray; const items: MArray): Integer; overload;
var
  i: Integer;
begin
  if (Self.Populated and items.Populated) then
  for i := 0 to High(ID) do
    if items.Contains(Self[ID[i]]) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
  <First>
  @action: Returns the first index of arr.
  @note: With empty array result will be -1!
[==============================================================================}
function MArrayHelper.First: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, 0);
end;

{==============================================================================]
  <First>
  @action: Returns the first index that matches item in arr.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.First(const item: MType): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <First>
  @action: Returns the first arr index that matches any of the items.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.First(const items: MArray): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Last>
  @action: Returns the last index of arr.
  @note: With empty array result will be -1!
[==============================================================================}
function MArrayHelper.Last: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, (Self.Size - 1));
end;

{==============================================================================]
  <Last>
  @action: Returns the last index that matches item in arr.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.Last(const item: MType): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Last>
  @action: Returns the last arr index that matches any of the items.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.Last(const items: MArray): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Loc>
  @action: Returns last index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Loc(const item: MType; const index: Integer = 2147483647): Integer; overload;
begin
  for Result := Min(High(Self), index) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Loc>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if items.Populated then
  for Result := Min(High(Self), index) downto 0 do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Location(const item: MType; const index: Integer = 2147483647): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  Result := Min(l, (index + 1));
  while (Result.Decrement > -1) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Location(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    l := Self.Length;
    Result := Min(l, (index + 1));
    while (Result.Decrement > -1) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Pos>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Pos(const item: MType; const index: Integer = 0): Integer; overload;
begin
  for Result := Max(0, index) to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Pos>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Pos(const items: MArray; const index: Integer = 0): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(Self) do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
  <Position>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Position(const item: MType; const index: Integer = 0): Integer; overload;
var
  l: Integer;
begin
  Result := Max(-1, (index - 1));
  l := Self.Length;
  while (Result.Increment < l) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Position>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Position(const items: MArray; const index: Integer = 0): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    Result := Max(-1, (index - 1));
    l := Self.Length;
    while (Result.Increment < l) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <SubarrayLocation>
  @action: Returns subarray position in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function MArrayHelper.SubarrayLocation(const pattern: MArray): Integer; overload;
var
  i, j, l, s, p: Integer;
begin
  l := Self.Length;
  p := pattern.Size;
  if ((p > 0) and (p <= l)) then
  for i := (l - p) downto 0 do
  begin
    s := 0;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
        Break
      else
        s := (s + 1);
    if (s = p) then
      Exit(i);
  end;
  Result := -1;
end;

{==============================================================================]
  <SubarrayPosition>
  @action: Returns subarray position in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => 1	
[==============================================================================}
function MArrayHelper.SubarrayPosition(const pattern: MArray): Integer; overload;
var
  i, j, l, p: Integer;
  f: Boolean;
begin
  l := Self.Length;
  p := pattern.Size;
  if ((p > 0) and (p <= l)) then
  for i := 0 to (l - p) do
  begin
    f := True;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(i);
  end;
  Result := -1;
end;
{$ENDIF}