{$IFDEF HELPERS}
function After(const s: string; const index: Integer = 1): string; overload;
function After(const index: Integer; const count: Integer = 2147483647): string; overload;
function Ahead(const s: string; const index: Integer = 2147483647): string; overload;
function Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
function Before(const s: string; const index: Integer = 1): string; overload;
function Before(const index: Integer; const count: Integer = 2147483647): string; overload;
function Behind(const s: string; const index: Integer = 2147483647): string; overload;
function Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
function Between(const s1, s2: string; const index: Integer = 1): string;
function Chunk(const a, b: Integer): string;
function FromLeft(const count: Integer; const index: Integer = 1): string;
function FromRight(const count: Integer; const index: Integer = 2147483647): string;
function Get(const index: Integer; const count: Integer): string;
function Pick(const index: Integer; const count: Integer = 2147483647): string;
function Slice(const a, b: Integer): string;
function Stuff(const s: string; const iFrom, iCount: Integer): string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <After>
  @action: Returns string that is found after s in str.
  @note: None
[==============================================================================}
function TStringHelper.After(const s: string; const index: Integer = 1): string; overload;
var
  p: Integer;
begin
  p := Self.Pos(s, index);
  if (p > 0) then
    Result := Copy(Self, (p + Length(s)), Length(Self))
  else
    Result := '';
end;

{==============================================================================]
  <After>
  @action: Returns string that is found after index in str.
  @note: None
[==============================================================================}
function TStringHelper.After(const index: Integer; const count: Integer = 2147483647): string; overload;
begin
  if ((index >= 0) and (index < Length(Self)) and (count > 0)) then
    Result := Copy(Self, (index + 1), count)
  else
    Result := '';
end;

{==============================================================================]
  <Ahead>
  @action: Returns string that is ahead the s in str.
  @note: None
[==============================================================================}
function TStringHelper.Ahead(const s: string; const index: Integer = 2147483647): string; overload;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  if (p > 0) then
    Result := Copy(Self, 1, (p - 1))
  else
    Result := '';
end;

{==============================================================================]
  <Ahead>
  @action: Returns string that is ahead the index in str.
  @note: None
[==============================================================================}
function TStringHelper.Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
var
  c: Integer;
begin
  if ((index > 1) and (count > 0)) then
  begin
    c := Min(count, (index - 1));
    Result := Copy(Self, (index - c), c);
  end else
    Result := '';
end;

{==============================================================================]
  <Before>
  @action: Returns string that is found before s in str.
  @note: None
[==============================================================================}
function TStringHelper.Before(const s: string; const index: Integer = 1): string; overload;
var
  p: Integer;
begin
  p := Self.Pos(s, index);
  if (p > 0) then
    Result := Copy(Self, 1, (p - 1))
  else
    Result := '';
end;

{==============================================================================]
  <Before>
  @action: Returns string that is found before index in str.
  @note: None
[==============================================================================}
function TStringHelper.Before(const index: Integer; const count: Integer = 2147483647): string; overload;
var
  c: Integer;
begin
  if ((index > 1) and (count > 0)) then
  begin
    c := Min(count, (index - 1));
    Result := Copy(Self, (index - c), c);
  end else
    Result := '';
end;

{==============================================================================]
  <Behind>
  @action: Returns string (with count) that is behind the s in str.
  @note: None
[==============================================================================}
function TStringHelper.Behind(const s: string; const index: Integer = 2147483647): string; overload;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  if (p > 0) then
    Result := Copy(Self, (p + Length(s)), Length(Self))
  else
    Result := '';
end;

{==============================================================================]
  <Behind>
  @action: Returns string (with count) that is behind the index in str.
  @note: None
[==============================================================================}
function TStringHelper.Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
begin
  if (index >= 0) and (index < Length(Self)) and (count > 0) then
    Result := Copy(Self, (index + 1), count)
  else
    Result := '';
end;

{==============================================================================]
  <Between>
  @action: Returns the string between s1 and s2 in str.
  @note: Supports offset (index).
[==============================================================================}
function TStringHelper.Between(const s1, s2: string; const index: Integer = 1): string;
var
  b, e, l: Integer;
begin
  b := Self.Find(s1, index);
  if (b = 0) then
    Exit('');
  l := Length(s1);
  e := Self.Find(s2, (b + l));
  if (e = 0) then
    Exit('');
  Result := Self.Get((b + l), (e - (b + l)));
end;

{==============================================================================]
  <Chunk>
  @action: Returns chunk of string between a and b.
  @note: Supports reversed chunk, when a is higher than b.
[==============================================================================}
function TStringHelper.Chunk(const a, b: Integer): string;
var
  i, l, x, y: Integer;
begin
  l := Length(Self);
  x := a;
  y := b;
  if (x < 0) then
    x := 0;
  if (x > (l + 1)) then
    x := (l + 1);
  if (y < 0) then
    y := 0;
  if (y > (l + 1)) then
    y := (l + 1);
  if (x < y) then
    Result := Copy(Self, (x + 1), ((y - x) - 1))
  else
    if (x <> y) then
    begin
      SetLength(Result, ((x - y) - 1));
      for i := (x - 1) downto (y + 1) do
        Result[x - i] := Self[i];
    end else
      Result := '';
end;

{==============================================================================]
  <FromLeft>
  @action: Returns string from left with count of characters.
  @note: None
[==============================================================================}
function TStringHelper.FromLeft(const count: Integer; const index: Integer = 1): string;
begin
  Result := Copy(Self, index, count);
end;

{==============================================================================]
  <FromRight>
  @action: Returns string from right with count of characters.
  @note: None
[==============================================================================}
function TStringHelper.FromRight(const count: Integer; const index: Integer = 2147483647): string;
begin
  Result := Copy(Self, ((Min(Length(Self), index) - count) + 1), count);
end;

{==============================================================================]
  <Get>
  @action: Fast method for getting substring from string index position by size.
  @note: UNSAFE! Minimal checks for efficiency.
[==============================================================================}
function TStringHelper.Get(const index: Integer; const count: Integer): string;
var
  i: Integer;
begin
  SetLength(Result, count);
  for i := 1 to count do
    Result[i] := Self[(index + i) - 1];
end;

{==============================================================================]
  <Pick>
  @action: Method for getting substring from string index position by count.
  @note: Contains some failsafes, alternative for String_Get.
[==============================================================================}
function TStringHelper.Pick(const index: Integer; const count: Integer = 2147483647): string;
var
  s, i, p: Integer;
begin
  i := Max(index, 1);
  s := Min(((Length(Self) - i) + 1), count);
  SetLength(Result, s);
  for p := 1 to s do
    Result[p] := Self[(i + p) - 1];
end;

{==============================================================================]
  <Slice>
  @action: Returns slice of string with a and b.
  @note: Supports reversed slice, when a is higher than b.
[==============================================================================}
function TStringHelper.Slice(const a, b: Integer): string;
var
  i, l, x, y: Integer;
begin
  l := Length(Self);
  if (l > 0) then
  begin
    x := a;
    y := b;
    if (x < 1) then
      x := 1;
    if (x > l) then
      x := l;
    if (y < 1) then
      y := 1;
    if (y > l) then
      y := l;
    if (x < y) then
      Result := Copy(Self, x, ((y - x) + 1))
    else
      if (x <> y) then
      begin
        SetLength(Result, ((x - y) + 1));
        for i := x downto y do
          Result[(x - i) + 1] := Self[i];
      end else
        Result := Copy(Self, x, 1);
  end else
    Result := '';
end;

{==============================================================================]
  <Stuff>
  @action: Returns str stuffed with s. Starting from iFrom and ending to iFrom + iCount.
  @note: Places s to iFrom position and replaces iCount amount of next characters in str with s.
[==============================================================================}
function TStringHelper.Stuff(const s: string; const iFrom, iCount: Integer): string;
begin
  Result := Copy(Self, 1, Length(Self));
  Delete(Result, iFrom, iCount);
  Insert(s, Result, iFrom);
end;
{$ENDIF}