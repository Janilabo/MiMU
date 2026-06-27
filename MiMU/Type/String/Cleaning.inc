{$IFDEF HELPERS}
function Cleaned: string; overload;
function Despace: string; overload;
function Despaced: string; overload;
function Despacement: string; overload;
function Sanitize: string; overload;
function Trim(const t: Char = #32): string;
function TrimLeft(const t: Char = #32): string;
function TrimRight(const t: Char = #32): string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cleaned>
  @action: Removes control characters (ASCII 0 to 31) from the string,
           except for carriage returns (#13) and line feeds (#10), after trimming leading and trailing whitespace.
  @note: Modifies the string from right to left using a downward loop.
[==============================================================================}
function TStringHelper.Cleaned: string; overload;
var
  i: Integer;
begin
  Result := SysUtils.Trim(Self);
  for i := Length(Result) downto 1 do
    if not ((Result[i] = #13) or (Result[i] = #10) or not (Result[i] in [#0..#31])) then
      System.Delete(Result, i, 1);
end;

{==============================================================================]
  <Despace>
  @action: Normalizes internal spacing by collapsing all consecutive whitespace
           characters down to a single space.
  @note: Ideal for smoothing out erratic spacing in sentences or parsed data tokens.
[==============================================================================}
function TStringHelper.Despace: string; overload;
var
  i, l, r: Integer;
  s: Boolean;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  r := 0;
  s := False;
  for i := 1 to l do
    if not (Self[i] = #32) then
    begin
      Result[r.Increment] := Self[i];
      s := False;
    end else if not s then
    begin
      Result[r.Increment] := #32;
      s := True;
    end;
  if (r < l) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Despaced>
  @action: Normalizes internal spacing by collapsing all consecutive whitespace 
           characters down to a single space.
  @note: Uses a highly optimized look-ahead evaluation rule that eliminates 
         the need for state-tracking boolean flags, safely concluding bounds 
         within a single conditional pass.
[==============================================================================}
function TStringHelper.Despaced: string; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  r := 0;
  for i := 1 to (l - 1) do
    if not ((Self[i] = #32) and (Self[i + 1] = #32)) then
      Result[r.Increment] := Self[i];
  if ((Self[l] <> #32) or (Result[r] <> #32)) then
    Result[r.Increment] := Self[l];
  if (r < l) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Despacement>
  @action: Normalizes internal spacing by collapsing all consecutive whitespace 
           characters down to a single space.
  @note: Highly optimized sentinel look-ahead implementation. By casting to a 
         0-based PChar pointer, it safely utilizes the invisible #0 null-terminator 
         to evaluate 'P[i + 1]' on the final character without risking an access violation.
[==============================================================================}
function TStringHelper.Despacement: string; overload;
var
  i, l, r: Integer;
  P: PChar;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  P := PChar(Self);
  r := 0;
  for i := 0 to (l - 1) do
    if not ((P[i] = #32) and (P[i + 1] = #32)) then
      Result[r.Increment] := P[i];
  if (r < l) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Sanitize>
  @action: Creates a new string filtering out specific control characters (ASCII 0 to 31), while explicitly preserving carriage returns (#13) and line feeds (#10).
  @note: Highly efficient performance compared to Cleaned. It pre-allocates memory and builds the string left-to-right using a custom `.Increment` helper on the index pointer,
         avoiding the overhead of repetitive string deletion. Does not perform an initial `Trim`.
[==============================================================================}
function TStringHelper.Sanitize: string; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  r := 0;
  for i := 1 to l do
    if ((Self[i] = #13) or (Self[i] = #10) or not (Self[i] in [#0..#31])) then
      Result[r.Increment] := Self[i];
  if (r < l) then
    SetLength(Result, r);
end;

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