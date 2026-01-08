{$IFDEF HELPERS}
function Find(const ID: TRange; const item: MType): Integer; overload; cdecl;
function Find(const ID: TIntegerArray; const item: MType): Integer; overload; cdecl;
function Find(const ID: TRange; const items: MArray): Integer; overload; cdecl;
function Find(const ID: TIntegerArray; const items: MArray): Integer; overload; cdecl;
function First: Integer; overload; cdecl;
function First(const item: MType): Integer; overload; cdecl;
function First(const items: MArray): Integer; overload; cdecl;
function Last: Integer; overload; cdecl;
function Last(const item: MType): Integer; overload; cdecl;
function Last(const items: MArray): Integer; overload; cdecl;
function Loc(const item: MType; const index: Integer = 2147483647): Integer; overload; cdecl;
function Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function Location(const item: MType; const index: Integer = 2147483647): Integer; overload; cdecl;
function Location(const items: MArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function Pos(const item: MType; const index: Integer = 0): Integer; overload; cdecl;
function Pos(const items: MArray; const index: Integer = 0): Integer; overload; cdecl;
function Position(const item: MType; const index: Integer = 0): Integer; overload; cdecl;
function Position(const items: MArray; const index: Integer = 0): Integer; overload; cdecl;
function Range(const subArray: MArray; const index: Integer = 0): TRange; overload; cdecl;
function Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload; cdecl;
function Span: TRange; overload; cdecl;
function Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload; cdecl;
function Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload; cdecl;
function SubarrayLocation(const pattern: MArray): Integer; overload; cdecl;
function SubarrayPosition(const pattern: MArray): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Find>
  @action: Scans array for item by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TRange; const item: MType): Integer; overload; cdecl;
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
function MArrayHelper.Find(const ID: TIntegerArray; const item: MType): Integer; overload; cdecl;
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
function MArrayHelper.Find(const ID: TRange; const items: MArray): Integer; overload; cdecl;
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
function MArrayHelper.Find(const ID: TIntegerArray; const items: MArray): Integer; overload; cdecl;
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
function MArrayHelper.First: Integer; overload; cdecl;
begin
  Result := IfThen(Self.Empty, -1, 0);
end;

{==============================================================================]
  <First>
  @action: Returns the first index that matches item in arr.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.First(const item: MType): Integer; overload; cdecl;
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
function MArrayHelper.First(const items: MArray): Integer; overload; cdecl;
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
function MArrayHelper.Last: Integer; overload; cdecl;
begin
  Result := IfThen(Self.Empty, -1, (Self.Size - 1));
end;

{==============================================================================]
  <Last>
  @action: Returns the last index that matches item in arr.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.Last(const item: MType): Integer; overload; cdecl;
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
function MArrayHelper.Last(const items: MArray): Integer; overload; cdecl;
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
function MArrayHelper.Loc(const item: MType; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function MArrayHelper.Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function MArrayHelper.Location(const item: MType; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function MArrayHelper.Location(const items: MArray; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function MArrayHelper.Pos(const item: MType; const index: Integer = 0): Integer; overload; cdecl;
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
function MArrayHelper.Pos(const items: MArray; const index: Integer = 0): Integer; overload; cdecl;
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
function MArrayHelper.Position(const item: MType; const index: Integer = 0): Integer; overload; cdecl;
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
function MArrayHelper.Position(const items: MArray; const index: Integer = 0): Integer; overload; cdecl;
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
  <Range>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Range(const subArray: MArray; const index: Integer = 0): TRange; overload; cdecl;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Ranges>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload; cdecl;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  l := 0;
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
  end;
end;

{==============================================================================]
  <Span>
  @action: -
  @note: -
[==============================================================================}
function MArrayHelper.Span: TRange; overload; cdecl;
begin
  Result.stop := High(Self);
  Result.start := IfThen((Result.stop = -1), -1, 0);
end;

{==============================================================================]
  <Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload; cdecl;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Spans>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload; cdecl;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  l := 0;
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
  end;
end;

{==============================================================================]
  <SubarrayLocation>
  @action: Returns subarray position in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function MArrayHelper.SubarrayLocation(const pattern: MArray): Integer; overload; cdecl;
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
function MArrayHelper.SubarrayPosition(const pattern: MArray): Integer; overload; cdecl;
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