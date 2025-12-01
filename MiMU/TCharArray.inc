{$DEFINE Char}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  HArr = type helper for TArr {$I config\1D.inc}
    function Str: string;
    function ToStr: string;
    function Join: string; overload;
    function Join(const glue: string): string; overload;
    function Stringify: string; overload;
    function Stringify(const glue: string): string; overload;
    function Ordinals: TIntegerArray;
    function Unduped: TCharArray;
    function TSA: TStringArray;
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\1D.inc}

{==============================================================================]
  <Str>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Str: string;
begin
  if Self.Empty then
    Exit('');
  SetString(Result, PChar(@Self[0]), Length(Self));
end;

{==============================================================================]
  <ToStr>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.ToStr: string;
begin
  SetLength(Result, Length(Self));
  if Self.Exists then
    Move(Self[0], Result[1], (Length(Self) * SizeOf(Char)));
end;

{==============================================================================]
  <Join>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Join: string; overload;
var
  i: Integer;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
  <Join>
  @action: Returns arr joined together as string.
  @note: Joins arr together with glue.
[==============================================================================}
function TCharArrayHelper.Join(const glue: string): string; overload;
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
  <Stringify>
  @action: Returns arr joined together as string.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Stringify: string; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i + 1] := Self[i];
end;

{==============================================================================]
  <Stringify>
  @action: Returns arr joined together as string.
  @note: Joins arr together with glue.
[==============================================================================}
function TCharArrayHelper.Stringify(const glue: string): string; overload;
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

{==============================================================================]
  <Ordinals>
  @action: Returns Ord() of every array items as TIntegerArray.
  @note: None.
[==============================================================================}
function TCharArrayHelper.Ordinals: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Ord(Self[i]);
end;

{==============================================================================]
  <Unduped>
  @action: Returns TCharArray with unique chars. 
  @note: Works with ASCII.
[==============================================================================}
function TCharArrayHelper.Unduped: TCharArray;
var
  s: set of Char;
  i, l: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Self.Clone);
  s := [];
  l := 0;
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
  begin
    if (Self[i] in s) then
      Continue;
    Include(s, Self[i]);
    Result[l.Increase] := Self[i];
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TSA>
  @action: Returns TCharArray as TStringArray. 
  @note: None.
[==============================================================================}
function TCharArrayHelper.TSA: TStringArray;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
end;
{$ENDIF}

{$UNDEF Char}