{$IFDEF HELPERS}
function BuiltWith(const blocks: TCharArray): Boolean;
function BuiltWithout(const forbidden: TCharArray): Boolean;
function Consists(const allowed: TCharArray): Boolean;
function Contains(const s: string; const index: Integer = 1): Boolean;
function ContainsAtLeast(const item: string; const limit: Integer): Boolean; overload;
function ContainsAtMost(const item: string; const limit: Integer): Boolean; overload;
function ContainsBetween(const item: string; const limit: TRange): Boolean; overload;
function EndsWith(const s: string): Boolean;
function FreeOf(const forbidden: TCharArray): Boolean;
function Includes(const s: string; const index: Integer = 2147483647): Boolean;
function MadeOf(const allowed: TCharArray): Boolean;
function Pure(const allowed: TCharArray): Boolean;
function StartsWith(const s: string): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BuiltWith>
  @action: Returns true is string is built with blocks.
  @note: This function requires blocks array to be unique (no duplicates allowed for it).
[==============================================================================}
function TStringHelper.BuiltWith(const blocks: TCharArray): Boolean;
var
  i, p: Integer;
  u: TBooleanArray;
begin
  if (Self.Empty or blocks.Empty) then
    Exit(False);
  SetLength(u, Length(blocks));
  for i := 1 to Length(Self) do
  begin
    p := blocks.Pos(Self[i]);
    if (p = -1) then
      Exit(False);
    u[p] := True;
  end;
  for i := 0 to High(blocks) do
    if not u[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <BuiltWithout> 
  @action: Checks if array arr does not have any forbidden items.
  @note: None.
[==============================================================================}
function TStringHelper.BuiltWithout(const forbidden: TCharArray): Boolean;
var
  i, j: Integer;
begin
  if forbidden.Exists then
  for i := 1 to Length(Self) do
    for j := 0 to High(forbidden) do
      if (Self[i] = forbidden[j]) then
        Exit(False);
  Result := True;
end;

{==============================================================================]
  <Consists>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.Consists(const allowed: TCharArray): Boolean;
var
  i: Integer;
  m: TBooleanArray;
begin
  if (allowed.Empty or Self.Empty) then
    Exit(False);
  m.Create(256, False);
  for i := 0 to High(allowed) do
    m[Ord(allowed[i])] := True;
  for i := 1 to Length(Self) do
    if not m[Ord(Self[i])] then
      Exit(False);
  Result := True;
end; 

{==============================================================================]
  <Contains>
  @action: Returns true if s can be found in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Contains(const s: string; const index: Integer = 1): Boolean;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Max(1, index) to ((Length(Self) - l) + 1) do
    if (Copy(Self, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <ContainsAtLeast>
  @action: Determines whether the string contains at least limit occurrences of item.
  @note:
    - Returns False if item is empty or limit < 1.
    - Stops scanning early once the limit is reached.
    - Performs an early-exit optimization if remaining characters cannot reach the limit.
    - Uses 1-based indexing.
[==============================================================================}
function TStringHelper.ContainsAtLeast(const item: string; const limit: Integer): Boolean; overload;
var
  i, c, r, l, s: Integer;
begin
  l := Length(item);
  if ((l = 0) or (limit < 1)) then
    Exit(False);
  c := 0;
  i := 1;
  s := Length(Self);
  while (i <= s) do
  begin
    i := Self.Pos(item, i);
    if (i = 0) then
      Break;
    Inc(c);
    if (c >= limit) then
      Exit(True);
    r := (s - ((i + l) - 1));
    if ((r + c) < limit) then
      Exit(False);
    Inc(i, l);
  end;
  Result := False;
end;

{==============================================================================]
  <ContainsAtMost>
  @action: Determines whether the string contains at most limit occurrences of item.
  @note:
    - Returns False if item is empty or limit < 0.
    - Stops scanning early once the limit is exceeded.
    - Performs an early-exit optimization if remaining characters cannot exceed the limit.
    - Uses 1-based indexing.
[==============================================================================}
function TStringHelper.ContainsAtMost(const item: string; const limit: Integer): Boolean; overload;
var
  i, c, r, l, s: Integer;
begin
  l := Length(item);
  if ((l = 0) or (limit < 0)) then
    Exit(False);
  c := 0;
  i := 1;
  s := Length(Self);
  while (i <= s) do
  begin
    i := Self.Pos(item, i);
    if (i = 0) then
      Break;
    Inc(c);
    if (c > limit) then
      Exit(False);
    r := (s - ((i + l) - 1));
    if ((r + c) <= limit) then
      Exit(True);
    Inc(i, l);
  end;
  Result := True;
end;

{==============================================================================]
  <ContainsBetween>
  @action: Determines whether the string contains a number of item occurrences
           within the inclusive range specified by limit (normalized).
  @note:
    - Returns False if item is empty.
    - Stops scanning early if occurrences exceed the maximum or cannot reach the minimum.
    - Uses 1-based indexing.
    - limit.Normalize ensures that limit.start <= limit.stop.
[==============================================================================}
function TStringHelper.ContainsBetween(const item: string; const limit: TRange): Boolean; overload;
var
  i, c, r, l, s: Integer;
  n: TRange;
begin
  l := Length(item);
  if (l = 0) then
    Exit(False);
  n := limit.Normalize;
  c := 0;
  i := 1;
  s := Length(Self);
  while (i <= s) do
  begin
    i := Self.Pos(item, i);
    if (i = 0) then
      Break;
    Inc(c);
    if (c > n.stop) then
      Exit(False);
    r := (s - ((i + l) - 1));
    if ((c + (r div l)) < n.start) then
      Exit(False);
    Inc(i, l);
  end;
  Result := InRange(c, n.start, n.stop);
end;

{==============================================================================]
  <EndsWith>
  @action: Returns True if str ends with s.
  @note: None
[==============================================================================}
function TStringHelper.EndsWith(const s: string): Boolean;
var
  l, t: Integer;
begin
  l := Length(s);
  t := Length(Self);
  Result := ((l > 0) and (t >= l) and Self.At(s, ((t - l) + 1)));
end;

{==============================================================================]
  <FreeOf>
  @action: Returns true if str is built without forbidden characters.
  @note: None.
[==============================================================================}
function TStringHelper.FreeOf(const forbidden: TCharArray): Boolean;
var
  i: Integer;
begin
  if forbidden.Exists then
  for i := Length(Self) downto 1 do
    if forbidden.Contains(Self[i]) then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <Includes>
  @action: Returns true if s can be found in str.
  @note: Starts backwards search from index position.!
[==============================================================================}
function TStringHelper.Includes(const s: string; const index: Integer = 2147483647): Boolean;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Min(index, ((Length(Self) - l) + 1)) downto 1 do
    if (Copy(Self, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <MadeOf>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.MadeOf(const allowed: TCharArray): Boolean;
var
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
  for i := 1 to Length(Self) do
    if not allowed.Contains(Self[i]) then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <Pure>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.Pure(const allowed: TCharArray): Boolean;
begin
  Result := Self.Chars.Ordinals.Pure(allowed.Ordinals);
end;

{==============================================================================]
  <StartsWith>
  @action: Returns True if str starts with s.
  @note: None
[==============================================================================}
function TStringHelper.StartsWith(const s: string): Boolean;
begin
  Result := ((s <> '') and (Length(Self) >= Length(s)) and Self.At(s));
end;
{$ENDIF}