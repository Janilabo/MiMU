{==============================================================================]
  <TCharArrayHelper.Str>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Str: string; cdecl;
begin
  if Self.Empty then
    Exit('');
  SetString(Result, PChar(@Self[0]), Length(Self));
end;

{==============================================================================]
  <TCharArrayHelper.ToStr>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.ToStr: string; cdecl;
begin
  SetLength(Result, Length(Self));
  if Self.Exists then
    Move(Self[0], Result[1], (Length(Self) * SizeOf(Char)));
end;

{==============================================================================]
  <TCharArrayHelper.Join>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Join: string; overload; cdecl;
var
  i: Integer;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
  <TCharArrayHelper.Join(glue: string)>
  @action: Returns arr joined together as string.
  @note: Joins arr together with glue.
[==============================================================================}
function TCharArrayHelper.Join(const glue: string): string; overload; cdecl;
var
  i: Integer;
begin
  Result := '';
  if Self.Empty then
    Exit;
  for i := 0 to (High(Self) - 1) do
    Result := (Result + Self[i] + glue);
  Result := (Result + Self[High(Self)]);
end;

{==============================================================================]
  <TCharArrayHelper.Stringify>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Stringify: string; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i + 1] := Self[i];
end;

{==============================================================================]
  <TCharArrayHelper.Stringify(glue: string)>
  @action: Returns arr joined together as string.
  @note: Joins arr together with glue.
[==============================================================================}
function TCharArrayHelper.Stringify(const glue: string): string; overload; cdecl;
var
  a, i, j, l, g: Integer;
begin
  if Self.Empty then
    Exit('');
  a := Length(Self);
  g := Length(glue);
  SetLength(Result, (a + (g * (a - 1))));
  l := 1;
  for i := 0 to (a - 2) do
  begin
    Result[l.Increase] := Self[i];
    for j := 1 to g do
      Result[l.Increase] := glue[j];
  end;
  Result[l] := Self[a - 1];
end;
