{$IFDEF HELPERS}
function Center(const size: Integer; const fill: Char = #32): string; overload;
function Duplicate(const x: Integer = 2): string; overload;
function Duplicated(const x: Integer; const glue: string): string; overload;
function EndWith(const s: string; const index: Integer = 2147483647): Boolean; overload;
function Exch(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(const aIndex, bIndex: Integer): Boolean; overload;
function Flip: string; overload;
function LeftOf(const aDelimiter: string): string; overload;
function Reverse: Boolean; overload;
function Reversed: string; overload;
function RightOf(const aDelimiter: string): string; overload;
function StartWith(const s: string; const index: Integer = 1): Boolean; overload;
function Wrapped(const aChar: Char = #32): string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Center>
  @action: Returns str centered with fill characters where size is the length of the Result.
  @note: Supports custom filling character by fill!
[==============================================================================}
function TStringHelper.Center(const size: Integer; const fill: Char = #32): string; overload;
var
  l, p: Integer;
begin
  l := Length(Self);
  if (l >= size) then
    Result := Self
  else if (l > 0) then
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
function TStringHelper.Duplicate(const x: Integer = 2): string; overload;
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
function TStringHelper.Duplicated(const x: Integer; const glue: string): string; overload;
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
function TStringHelper.EndWith(const s: string; const index: Integer = 2147483647): Boolean; overload;
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
function TStringHelper.Exch(const aIndex, bIndex: Integer): Boolean; overload;
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
function TStringHelper.Exchange(const aIndex, bIndex: Integer): Boolean; overload;
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
function TStringHelper.Flip: string; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := l downto 1 do
    Result[i] := Self[(l - i) + 1];
end;

{==============================================================================]
  <LeftOf>
  @action: Returns the substring leading up to the first occurrence of a
           specified delimiter string.
  @note: If the delimiter is not found, it safely returns the entire original
         string.
[==============================================================================}
function TStringHelper.LeftOf(const aDelimiter: string): string; overload;
var
  P: Integer;
begin
  P := System.Pos(aDelimiter, Self);
  if (P = 0) then
    Exit(Self);
  Result := System.Copy(Self, 1, (P - 1));
end;

{==============================================================================]
  <Reverse>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Reverse: Boolean; overload;
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
function TStringHelper.Reversed: string; overload;
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
  <RightOf>
  @action: Returns the substring following the first occurrence of a
           specified delimiter string.
  @note: If the delimiter is not found, it returns an empty string ('').
[==============================================================================}
function TStringHelper.RightOf(const aDelimiter: string): string; overload;
var
  P: Integer;
begin
  P := System.Pos(aDelimiter, Self);
  if (P = 0) then
    Exit('');
  Result := System.Copy(Self, (P + System.Length(aDelimiter)), System.Length(Self));
end;

{==============================================================================]
  <StartWith>
  @action: Returns true if s was found in str and it was set as the beginning of the str.
  @note: None
[==============================================================================}
function TStringHelper.StartWith(const s: string; const index: Integer = 1): Boolean; overload;
var
  p: Integer;
begin
  p := Self.Find(s, index);
  Result := (p > 0);
  if Result then
    Self := Copy(Self, p, (Length(Self) - (p - 1)));
end;

{==============================================================================]
  <Wrapped>
  @action: Wraps the string inside a specified leading and trailing character.
  @note: Highly useful for wrapping values in quotes, brackets, or delimiters 
         without writing clunky string concatenation formulas. Returns a new 
         modified copy of the string.
[==============================================================================}
function TStringHelper.Wrapped(const aChar: Char = #32): string; overload;
begin
  Result := (aChar + Self + aChar);
end;
{$ENDIF}
