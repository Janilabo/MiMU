{$IFDEF HELPERS}
function Find(const s: string; const index: Integer = 1): Integer;
function Loc(const s: string; const index: Integer = 2147483647): Integer;
function Location(const s: string; const index: Integer = 2147483647): Integer;
function Pos(const s: string; const index: Integer = 1): Integer;
function Position(const s: string; const index: Integer = 1): Integer;
function Search(const s: string; const index: Integer = 1): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Find>
  @action: Returns first position of s string in str.
  @note: Alternative for Pos().
[==============================================================================}
function TStringHelper.Find(const s: string; const index: Integer = 1): Integer;
var
  i, j, a, b: Integer;
begin
  Result := 0;
  a := Length(Self);
  b := Length(s);
  if ((a = 0) or (b = 0) or (b > a) or (index < 1) or (index > ((a - b) + 1))) then
    Exit;
  for i := index to (a - b + 1) do
    for j := 1 to b do
      if (Self[(i + j) - 1] <> s[j]) then
        Break
      else
        if (j = b) then
          Exit(i);
end;

{==============================================================================]
  <Loc>
  @action: Returns last position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Loc(const s: string; const index: Integer = 2147483647): Integer;
begin
  for Result := Min(index, ((Length(Self) - Length(s)) + 1)) downto 1 do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Location>
  @action: Returns last position of s string in str.
  @note: Starts search from index position. -1 means str length!
[==============================================================================}
function TStringHelper.Location(const s: string; const index: Integer = 2147483647): Integer;
var
  a, b, o: Integer;
begin
  a := Length(Self);
  b := Length(s);
  if (index = -1) then
    o := ((a - b) + 1)
  else
    o := Max(1, index);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := o downto 1 do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Pos>
  @action: Returns first position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Pos(const s: string; const index: Integer = 1): Integer;
begin
  for Result := Max(1, index) to ((Length(Self) - Length(s)) + 1) do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Position>
  @action: Returns s position from str. Starts scanning from start.
           If s doesn't exist in str, Result will be set as 0.
  @note: Supports custom index as scan start.
[==============================================================================}
function TStringHelper.Position(const s: string; const index: Integer = 1): Integer;
var
  a, b, i: Integer;
begin
  if (index < 2) then
    Exit(Self.Pos(s));
  a := Length(Self);
  b := Length(s);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := index to ((a - b) + 1) do
  begin
    i := 1;
    while ((i <= b) and (Self[(Result + i) - 1] = s[i])) do
      i := (i + 1);
    if (i > b) then
      Exit;
  end;
  Result := 0;
end;

{==============================================================================]
  <Search>
  @action: Returns first position of s string in str.
  @note: Alternative for Pos().
[==============================================================================}
function TStringHelper.Search(const s: string; const index: Integer = 1): Integer;
var
  i, j, a, b: Integer;
begin
  Result := 0;
  a := Length(Self);
  b := Length(s);
  if ((a = 0) or (b = 0) or (b > a) or (index < 1) or (index > ((a - b) + 1))) then
    Exit;
  i := index;
  while (i <= ((a - b) + 1)) do
  begin
    j := 1;
    while ((j <= b) and (Self[(i + j) - 1] = s[j])) do
      Inc(j);
    if (j > b) then
      Exit(i);
    Inc(i);
  end;
end;
{$ENDIF}