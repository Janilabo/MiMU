{$IFDEF HELPERS}
function Trim(const t: Char = #32): string;
function TrimLeft(const t: Char = #32): string;
function TrimRight(const t: Char = #32): string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Trim>
  @action: Returns str with left-side and right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.Trim(const t: Char = #32): string;
var
  i, l, x, y: Integer;
begin
  Result := '';
  l := Length(Self);
  if (l > 0) then;
  begin
    y := 0;
    for i := l downto 1 do
      if (Self[i] = t) then
        Inc(y)
      else
        Break;
    if (y = l) then
      Exit;
    x := 0;
    for i := 1 to l do
      if (Self[i] = t) then
        Inc(x)
      else
        Break;
    if (l <= (x + y)) then
      Exit;
    SetLength(Result, (l - (x + y)));
    for i := x to ((l - y) - 1) do
      Result[(i - x) + 1] := Self[i + 1];
  end;
end;

{==============================================================================]
  <TrimLeft>
  @action: Returns str with left-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.TrimLeft(const t: Char = #32): string;
var
  i, l: Integer;
begin
  l := Length(Self);
  for i := 1 to l do
    if (Self[i] <> t) then
      Exit(Copy(Self, i, ((l + 1) - i)));
  Result := '';
end;

{==============================================================================]
  <TrimRight>
  @action: Returns str with right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.TrimRight(const t: Char = #32): string;
var
  i, l: Integer;
begin
  l := Length(Self);
  for i := l downto 1 do
    if (Self[i] <> t) then
      Exit(Copy(Self, 1, i));
  Result := '';
end;
{$ENDIF}