{$IFDEF HELPERS}
function Center(const size: Integer; const fill: Char = #32): string;
function Duplicate(const x: Integer = 2): string;
function Duplicated(const x: Integer; const glue: string): string;
function EndWith(const s: string; const index: Integer = 2147483647): Boolean;
function Exch(const aIndex, bIndex: Integer): Boolean;
function Exchange(const aIndex, bIndex: Integer): Boolean;
function Flip: string;
function Reverse: Boolean;
function Reversed: string;
function StartWith(const s: string; const index: Integer = 1): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Center>
  @action: Returns str centered with fill characters where size is the length of the Result.
  @note: Supports custom filling character by fill!
[==============================================================================}
function TStringHelper.Center(const size: Integer; const fill: Char = #32): string;
var
  l, p: Integer;
begin
  l := Length(Self);
  if (l >= size) then
    Result := Self
  else
    if (l > 0) then
    begin
      p := (((size - l) div 2) + 1);
      Result := (StringOfChar(fill, (p - 1)) + Self + StringOfChar(fill, ((size - (p + l)) + 1)));
    end else
      Result := StringOfChar(fill, size);
end;

{==============================================================================]
  <Duplicate>
  @action: Returns str * x (duplicated) times. Example: ('ha', 3) => 'hahaha'
  @note: None
[==============================================================================}
function TStringHelper.Duplicate(const x: Integer = 2): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to x do
    Result := (Result + Self);
end;

{==============================================================================]
  <Duplicated>
  @action: Returns str * x times. Example: ('ha', 3, ' ') => 'ha ha ha'
           Places glue between the str positions to result.
  @note: Supports custom glue addition between duplicated str's.
[==============================================================================}
function TStringHelper.Duplicated(const x: Integer; const glue: string): string;
var
  i: Integer;
begin
  Result := '';
  if (x > 0) then
    if (x > 1) then
    begin
      for i := 1 to (x - 1) do
        Result := (Result + Self + glue);
      Result := (Result + Self);
    end else
      Result := Self;
end;

{==============================================================================]
  <EndWith>
  @action: Returns true if s was found in str and it was set as the ending of the str.
  @note: Supports offset.
[==============================================================================}
function TStringHelper.EndWith(const s: string; const index: Integer = 2147483647): Boolean;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  Result := (p > 0);
  if Result then
    Self := Copy(Self, 1, ((p + Length(s)) - 1));
end;

{==============================================================================]
  <Exch(aIndex, bIndex: Integer): Boolean>
  @action: Fast version of Exchange().
  @note: Unsafe, no checking.
[==============================================================================}
function TStringHelper.Exch(const aIndex, bIndex: Integer): Boolean;
var
  c: Char;
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;

{==============================================================================]
  <Exchange(aIndex, bIndex: Integer): Boolean>
  @action: Swap items aIndex and bIndex in string.
  @note: Returns true with success.
[==============================================================================}
function TStringHelper.Exchange(const aIndex, bIndex: Integer): Boolean;
var
  l: Integer;
  c: Char;
begin
  l := Length(Self);
  Result := ((l > 1) and (aIndex <> bIndex) and InRange(aIndex, 1, l) and InRange(bIndex, 1, l) and (Self[aIndex] <> Self[bIndex]));
  if Result then
  begin
    c := Self[aIndex];
    Self[aIndex] := Self[bIndex];
    Self[bIndex] := c;
  end;
end;

{==============================================================================]
  <Flip>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Flip: string;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := l downto 1 do
    Result[i] := Self[(l - i) + 1];
end;

{==============================================================================]
  <Reverse>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Reverse: Boolean;
var
  i, l: Integer;
  c: Char;
begin
  l := Length(Self);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
  begin
    c := Self[i + 1];
    Self[i + 1] := Self[l - i];
    Self[l - i] := c;
  end;
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Reversed: string;
var
  i, l, m: Integer;
begin
  l := Length(Self);
  if (l > 1) then
  begin
    SetLength(Result, l);
    m := Floor(l / 2);
    for i := 1 to m do
    begin
      Result[i] := Self[(l - i) + 1];
      Result[(l - i) + 1] := Self[i];
    end;
    if not ((l mod 2) = 0) then
      Result[m + 1] := Self[m + 1];
  end else
    Result := Self;
end;

{==============================================================================]
  <StartWith>
  @action: Returns true if s was found in str and it was set as the beginning of the str.
  @note: None
[==============================================================================}
function TStringHelper.StartWith(const s: string; const index: Integer = 1): Boolean;
var
  p: Integer;
begin
  p := Self.Find(s, index);
  Result := (p > 0);
  if Result then
    Self := Copy(Self, p, (Length(Self) - (p - 1)));
end;
{$ENDIF}