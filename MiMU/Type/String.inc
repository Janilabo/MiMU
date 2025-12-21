{$DEFINE string}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I ./Core.inc}
  {$I ./String/String.inc}
  function After(const s: string; const index: Integer = 1): string; overload;
  function After(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Ahead(const s: string; const index: Integer = 2147483647): string; overload;
  function Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Before(const s: string; const index: Integer = 1): string; overload;
  function Before(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Behind(const s: string; const index: Integer = 2147483647): string; overload;
  function Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Blank: Boolean;
  function Between(const s1, s2: string; const index: Integer = 1): string;
  function Chop: TCharArray; overload;
  function Chop(const delimiter: Char): TStringArray; overload;
  function Split: TCharArray; overload;
  function Split(const delimiter: Char): TStringArray; overload;
  function Chunk(const a, b: Integer): string;
  function Center(const size: Integer; const fill: Char = #32): string;
  function Duplicate(const x: Integer = 2): string;
  function Duplicated(const x: Integer; const glue: string): string;
  function Empty: Boolean;
  function EndWith(const s: string; const index: Integer = 2147483647): Boolean;
  function Exch(const aIndex, bIndex: Integer): Boolean;
  function Exchange(const aIndex, bIndex: Integer): Boolean;
  function Exists: Boolean;
  function Explode: TCharArray; overload;
  function Explode(const d: string; const limit: Integer = -1): TStringArray; overload;
  function Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload;
  function Tokenized(const d: Char = #32): TStringArray; overload;
  function Delimited(const d: Char = #32): TStringArray; overload;
  function Flip: string;
  function FromLeft(const count: Integer; const index: Integer = 1): string;
  function FromRight(const count: Integer; const index: Integer = 2147483647): string;
  function Get(const index: Integer; const count: Integer): string; inline;
  function Pick(const index: Integer; const count: Integer = 2147483647): string;
  function Reverse: Boolean;
  function Reversed: string;
  function Slice(const a, b: Integer): string;
  function StartWith(const s: string; const index: Integer = 1): Boolean;
  function Stuff(const s: string; const iFrom, iCount: Integer): string;
  function TrimLeft(const t: Char = #32): string;
  function TrimRight(const t: Char = #32): string;
  function Trim(const t: Char = #32): string;
  function Void: Boolean;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./String/String.inc}
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
  <Void>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Void: Boolean;
begin
  Result := (Self = '');
end;

{==============================================================================]
  <Empty>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Empty: Boolean;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
  <Blank>
  @action: Returns true if string is empty or consists of whitespaces only.
  @note: None.
[==============================================================================}
function TStringHelper.Blank: Boolean;
var
  i: Integer;
begin
  for i := 1 to Length(Self) do
    if not CharInSet(Self[i], [' ', #9, #10, #13]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Exists>
  @action: Returns true if string is not empty.
  @note: Length(str) > 0.
[==============================================================================}
function TStringHelper.Exists: Boolean;
begin
  Result := (Length(Self) > 0);
end;

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
  <Chop>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Chop: TCharArray; overload;
var
  p: PChar;
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  p := PChar(Self);
  for i := 0 to (l - 1) do
  begin
    Result[i] := p^;
    Inc(p);
  end;
end;

{==============================================================================]
  <Chop>
  @action: Splits the string into substrings using the specified delimiter character.
           Each occurrence of the delimiter divides the string, producing an array
           of substrings. The delimiter itself is not included in the output.
  @note: - Consecutive delimiters produce empty substrings.
         - Leading or trailing delimiters result in empty strings at the start or end.
         - Uses Self.Count(d) to determine the number of delimiters; ensure this helper exists.
[==============================================================================}
function TStringHelper.Chop(const delimiter: Char): TStringArray; overload;
var
  s, i, l: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  SetLength(Result, (Self.Count(delimiter) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = delimiter) then
    begin
      Result[l.Increase] := Copy(Self, s, (i - s));
      s := (i + 1);
    end;
  Result[l] := Copy(Self, s, ((Length(Self) - s) + 1));
end;

{==============================================================================]
  <Split>
  @action: Converts the string into an array of characters (TCharArray),
           where each element of the array is a single character from the string.
  @note: - The resulting array length is equal to the length of the string.
         - Characters are placed in the same order as in the original string.
[==============================================================================}
function TStringHelper.Split: TCharArray; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l + 1];
end;

{==============================================================================]
  <Split>
  @action: Splits the string into substrings using the specified delimiter character.
           Each occurrence of the delimiter separates the string, and the substrings
           are returned as a TStringArray.
  @note:   - If the string is empty, returns an empty array.
           - Consecutive delimiters produce empty strings in the result array.
           - The delimiter itself is not included in the resulting substrings.
[==============================================================================}
function TStringHelper.Split(const delimiter: Char): TStringArray; overload;
var
  p, r: Integer;
  s: string;
begin
  if (Length(Self) = 0) then
    Exit([]);
  r := 0;
  s := Copy(Self, 1, Length(Self));
  p := s.Pos(delimiter);
  while (p > 0) do
  begin
    SetLength(Result, (r + 1));
    Result[r.Increase] := Copy(s, 1, (p - 1));
    s := Copy(s, (p + 1), High(Integer));
    p := s.Pos(delimiter);
  end;
  SetLength(Result, (r + 1));
  Result[r] := s;
end;

{==============================================================================]
  <Tokenized>
  @action: Splits the current string into an array of substrings using the
           specified delimiter character d. Returns all segments between
           occurrences of d.
  @note:   Consecutive delimiters produce empty substrings. The order of
           elements in the resulting array corresponds to their order in
           the original string. Preallocates the result array based on the
           count of delimiter occurrences for efficiency.
[==============================================================================}
function TStringHelper.Tokenized(const d: Char = #32): TStringArray; overload;
var
  s, i, l: Integer;
begin
  SetLength(Result, (Self.Count(d) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = d) then
    begin
      Result[l.Increase] := Copy(Self, s, (i - s));
      s := (i + 1);
    end;
  Result[l] := Copy(Self, s, ((Length(Self) - s) + 1));
end;

{==============================================================================]
  <Delimited>
  @action: Splits the current string into an array of substrings using the
           specified delimiter character `d`. Returns all segments between
           occurrences of `d`, preserving their order.
  @note: Consecutive delimiters produce empty substrings. Uses `Copy` and
         `Delete` to extract segments iteratively. Returns an empty array
         if the original string is empty. Slightly less efficient than
         preallocated approaches for very long strings due to repeated
         memory shifting by `Delete`.
[==============================================================================}
function TStringHelper.Delimited(const d: Char = #32): TStringArray; overload;
var
  t: string;
  p, c: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  t := Copy(Self, 1, Length(Self));
  c := 0;
  SetLength(Result, (t.Count(d) + 1));
  p := t.Pos(d);
  while (p > 0) do
  begin
    Result[c.Increase] := Copy(t, 1, (p - 1));
    Delete(t, 1, p);
    p := t.Pos(d);
  end;
  Result[c] := t;
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
  <Explode>
  @action: Simply "explodes" string to TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Explode: TCharArray; overload;
var
  p: PChar;
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  p := PChar(Self);
  for i := 0 to (l - 1) do
  begin
    Result[i] := p^;
    Inc(p);
  end;
end;

{==============================================================================]
  <Explode>
  @action: Explodes str with delimiter (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function TStringHelper.Explode(const d: string; const limit: Integer = -1): TStringArray; overload;
var
  a, b, l, p, r, s, t: Integer;
  m: Boolean;
begin
  SetLength(Result, 1);
  l := Length(Self);
  s := Length(d);
  if ((l > 0) and (s > 0)) then
  begin
    a := 1;
    p := 1;
    r := 0;
    if (limit = -1) then
      t := l
    else
      t := limit;
    while (((r + 1) < t) and ((a + s - 1) <= l)) do
    begin
      m := True;
      for b := 1 to s do
      begin
        if (Self[(a + b) - 1] <> d[b]) then
        begin
          m := False;
          Break;
        end;
      end;
      if m then
      begin
        Result[r.Increase] := Copy(Self, p, (a - p));
        p := (a + s);
        a := (p - 1);
        SetLength(Result, (r + 1));
      end;
      Inc(a);
    end;
    Result[r] := Copy(Self, p, ((l - p) + 1));
  end else
    Result[0] := '';
end;

{==============================================================================]
  <Explode>
  @action: Explodes str with delimiters (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function TStringHelper.Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload;
var
  i, j, p, l, f, c: Integer;
  s, x: string;
  r: Boolean;
begin
  case ((Self = '') or (Length(d) = 0)) of
    False:
    begin
      SetLength(Result, 0);
      p := 1;
      c := 0;
      r := False;
      while not r do
      begin
        f := 0;
        l := 0;
        for i := 0 to High(d) do
        begin
          x := d[i];
          if (x = '') then
            Continue;
          j := Self.Find(x, p);
          if (j > 0) and ((f = 0) or (j < f)) then
          begin
            f := j;
            l := Length(x);
          end;
        end;
        if ((f > 0) and ((limit = -1) or (c < (limit - 1)))) then
        begin
          s := Copy(Self, p, (f - p));
          SetLength(Result, (c + 1));
          Result[c.Increase] := s;
          p := (f + l);
        end else
        begin
          SetLength(Result, (c + 1));
          Result[c] := Copy(Self, p, ((Length(Self) - p) + 1));
          r := True;
        end;
      end;
    end;
    True:
    begin
      SetLength(Result, 1);
      Result[0] := Self;
    end;
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
function TStringHelper.Get(const index: Integer; const count: Integer): string; inline;
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
{$ENDIF}

{$UNDEF string}
