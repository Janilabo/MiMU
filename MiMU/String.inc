{==============================================================================]
  <String_Chars>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function String_Chars(const str: string): TCharArray; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(str));
  for i := 0 to High(Result) do
    Result[i] := str[(i + 1)];
end;

{==============================================================================]
  <String_At>
  @action: Checks if string s is at index position in str.
  @note: UNSAFE: Minimal checking for efficiency!
[==============================================================================}
function String_At(const str, s: string; const index: Integer = 1): Boolean; cdecl; inline;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := 1 to l do
    if (str[(((index) + i) - 1)] <> s[i]) then
      Exit(False);
  Result := (l > 0);
end;

{==============================================================================]
  <String_Get>
  @action: Fast method for getting substring from string index position by size.
  @note: UNSAFE! Minimal checks for efficiency.
[==============================================================================}
function String_Get(const str: string; const index: Integer; const count: Integer): string; cdecl; inline;
var
  i: Integer;
begin
  SetLength(Result, count);
  for i := 1 to count do
    Result[i] := str[((index + i) - 1)];
end;

{==============================================================================]
  <String_Pick>
  @action: Method for getting substring from string index position by count.
  @note: Contains some failsafes, alternative for String_Get.
[==============================================================================}
function String_Pick(const str: string; const index: Integer; const count: Integer = 2147483647): string; cdecl;
var
  s, i, p: Integer;
begin
  i := Max(index, 1);
  s := Min(((Length(str) - i) + 1), count);
  SetLength(Result, s);
  for p := 1 to s do
    Result[p] := str[((i + p) - 1)];
end;

{==============================================================================]
  <String_PosL>
  @action: Returns first position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function String_PosL(const str, s: string; const index: Integer = 1): Integer; cdecl;
var
  l: Integer;
begin
  l := Length(s);
  for Result := Max(1, index) to ((Length(str) - l) + 1) do
    if (Copy(str, Result, l) = s) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <String_PosR>
  @action: Returns last position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function String_PosR(const str, s: string; const index: Integer = 2147483647): Integer; cdecl;
var
  l: Integer;
begin
  l := Length(s);
  for Result := Min(index, ((Length(str) - l) + 1)) downto 1 do
    if (Copy(str, Result, l) = s) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <String_Pos>
  @action: Returns last position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function String_Pos(const str, s: string; const index: Integer = 1): Integer; cdecl;
var
  a, b: Integer;
begin
  a := Length(str);
  b := Length(s);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := Max(1, index) to ((a - b) + 1) do
    if String_At(str, s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <String_PosLast>
  @action: Returns last position of s string in str.
  @note: Starts search from index position. -1 means str length!
[==============================================================================}
function String_PosLast(const str, s: string; const index: Integer = 2147483647): Integer; cdecl;
var
  a, b, o: Integer;
begin
  a := Length(str);
  b := Length(s);
  if (index = -1) then
    o := ((a - b) + 1)
  else
    o := Max(1, index);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := o downto 1 do
    if String_At(str, s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <String_Position>
  @action: Returns s position from str. Starts scanning from start.
           If s doesn't exist in str, Result will be set as 0.
  @note: Supports custom index as scan start.
[==============================================================================}
function String_Position(const str, s: string; const index: Integer = 1): Integer; cdecl;
var
  a, b, i: Integer;
begin
  if (index < 2) then
    Exit(Pos(s, str));
  a := Length(str);
  b := Length(s);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := index to ((a - b) + 1) do
  begin
    i := 1;
    while ((i <= b) and (str[((Result + i) - 1)] = s[i])) do
      i := (i + 1);
    if (i > b) then
      Exit;
  end;
  Result := 0;
end;

{==============================================================================]
  <String_Contains>
  @action: Returns true if s can be found in str.
  @note: Starts search from index position.!
[==============================================================================}
function String_Contains(const str, s: string; const index: Integer = 1): Boolean; cdecl;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Max(1, index) to ((Length(str) - l) + 1) do
    if (Copy(str, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <String_Includes>
  @action: Returns true if s can be found in str.
  @note: Starts backwards search from index position.!
[==============================================================================}
function String_Includes(const str, s: string; const index: Integer = 2147483647): Boolean; cdecl;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Min(index, ((Length(str) - l) + 1)) downto 1 do
    if (Copy(str, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <String_Between>
 @action: Returns the string between s1 and s2 in str.
 @note: Supports offset (index).
[==============================================================================}
function String_Between(const str, s1, s2: string; const index: Integer = 1): string; cdecl;
var
  b, e, l: Integer;
begin
  b := String_Pos(str, s1, index);
  if (b = 0) then
    Exit('');
  l := Length(s1);
  e := String_Pos(str, s2, (b + l));
  if (e = 0) then
    Exit('');
  Result := String_Get(str, (b + l), (e - (b + l)));
end;

{==============================================================================]
  <String_Count>
  @action: Simply returns the count of s in str.
  @note: Contains support for overlapping (overlap)
[==============================================================================}
function String_Count(const str, s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(str, index, ((Length(str) - index) + 1));
  o := Boolean_X(overlap, 1, Length(s));
  p := (1 - o);
  repeat
    p := String_Pos(c, s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <String_Amount>
  @action: Simply returns the amount of s in str.
  @note: Contains support for overlapping (overlap)
[==============================================================================}
function String_Amount(const str, s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(str, 1, index);
  o := Boolean_X(overlap, 1, Length(s));
  p := (1 - o);
  repeat
    p := String_Pos(c, s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <String_FromLeft>
  @action: Returns string from left with count of characters.
  @note: None
[==============================================================================}
function String_FromLeft(const str: string; const count: Integer; const index: Integer = 1): string; cdecl;
begin
  Result := Copy(str, index, count);
end;

{==============================================================================]
  <String_FromRight>
  @action: Returns string from right with count of characters.
  @note: None
[==============================================================================}
function String_FromRight(const str: string; const count: Integer; const index: Integer = 2147483647): string; cdecl;
begin
  Result := Copy(str, ((Min(Length(str), index) - count) + 1), count);
end;

{==============================================================================]
  <String_Explode>
  @action: Explodes str with delimiter (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function String_Explode(const str, d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
var
  a, b, l, p, r, s, t: Integer;
  m: Boolean;
begin
  SetLength(Result, 1);
  l := Length(str);
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
        if (str[((a + b) - 1)] <> d[b]) then
        begin
          m := False;
          Break;
        end;
      end;
      if m then
      begin
        Result[Integer_Inc(r)] := Copy(str, p, (a - p));
        p := (a + s);
        a := (p - 1);
        SetLength(Result, (r + 1));
      end;
      Inc(a);
    end;
    Result[r] := Copy(str, p, ((l - p) + 1));
  end else
    Result[0] := '';
end;

{==============================================================================]
  <String_Explode>
  @action: Explodes str with delimiters (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function String_Explode(const str: string; const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
var
  i, j, p, l, f, c: Integer;
  s, x: string;
  r: Boolean;
begin
  case ((str = '') or (Length(d) = 0)) of
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
          j := String_Pos(str, x, p);
          if (j > 0) and ((f = 0) or (j < f)) then
          begin
            f := j;
            l := Length(x);
          end;
        end;
        if ((f > 0) and ((limit = -1) or (c < (limit - 1)))) then
        begin
          s := Copy(str, p, (f - p));
          SetLength(Result, (c + 1));
          Result[Integer_Inc(c)] := s;
          p := (f + l);
        end else
        begin
          SetLength(Result, (c + 1));
          Result[c] := Copy(str, p, ((Length(str) - p) + 1));
          r := True;
        end;
      end;
    end;
    True:
    begin
      SetLength(Result, 1);
      Result[0] := str;
    end;
  end;
end;

{==============================================================================]
  <String_Slice>
  @action: Returns slice of string with a and b.
  @note: Supports reversed slice, when a is higher than b.
[==============================================================================}
function String_Slice(const str: string; const a, b: Integer): string; cdecl;
var
  i, l, x, y: Integer;
begin
  l := Length(str);
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
      Result := Copy(str, x, ((y - x) + 1))
    else
      if (x <> y) then
      begin
        SetLength(Result, ((x - y) + 1));
        for i := x downto y do
          Result[((x - i) + 1)] := str[i];
      end else
        Result := Copy(str, x, 1);
  end else
    Result := '';
end;

{==============================================================================]
  <String_Chunk>
  @action: Returns chunk of string between a and b.
  @note: Supports reversed chunk, when a is higher than b.
[==============================================================================}
function String_Chunk(const str: string; const a, b: Integer): string; cdecl;
var
  i, l, x, y: Integer;
begin
  l := Length(str);
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
    Result := Copy(str, (x + 1), ((y - x) - 1))
  else
    if (x <> y) then
    begin
      SetLength(Result, ((x - y) - 1));
      for i := (x - 1) downto (y + 1) do
        Result[(x - i)] := str[i];
    end else
      Result := '';
end;

{==============================================================================]
  <String_Reverse>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function String_Reverse(var str: string): Boolean; cdecl;
var
  i, l: Integer;
  c: Char;
begin
  l := Length(str);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
  begin
    c := str[(i + 1)];
    str[(i + 1)] := str[(l - i)];
    str[(l - i)] := c;
  end;
end;

{==============================================================================]
  <String_Flip>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function String_Flip(const str: string): string; cdecl;
var
  i, l: Integer;
begin
  l := Length(str);
  SetLength(Result, l);
  for i := l downto 1 do
    Result[i] := str[((l - i) + 1)];
end;

{==============================================================================]
  <String_Reversed>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function String_Reversed(const str: string): string; cdecl;
var
  i, l, m: Integer;
begin
  l := Length(str);
  if (l > 1) then
  begin
    SetLength(Result, l);
    m := Floor(l / 2);
    for i := 1 to m do
    begin
      Result[i] := str[((l - i) + 1)];
      Result[((l - i) + 1)] := str[i];
    end;
    if not ((l mod 2) = 0) then
      Result[(m + 1)] := str[(m + 1)];
  end else
    Result := str;
end;

{==============================================================================]
  <String_StartsWith>
  @action: Returns True if str starts with s.
  @note: None
[==============================================================================}
function String_StartsWith(const str, s: string): Boolean; cdecl;
begin
  Result := ((s <> '') and (Length(str) >= Length(s)) and String_At(str, s));
end;

{==============================================================================]
  <String_EndsWith>
  @action: Returns True if str ends with s.
  @note: None
[==============================================================================}
function String_EndsWith(const str, s: string): Boolean; cdecl;
var
  l, t: Integer;
begin
  l := Length(s);
  t := Length(str);
  Result := ((l > 0) and (t >= l) and String_At(str, s, ((t - l) + 1)));
end;

{==============================================================================]
  <String_Begin>
  @action: Returns true if s was found in str and it was set as the beginning of the str.
  @note: None
[==============================================================================}
function String_Begin(var str: string; const s: string; const index: Integer = 1): Boolean; cdecl;
var
  p: Integer;
begin
  p := String_Pos(str, s, index);
  Result := (p > 0);
  if Result then
    str := Copy(str, p, (Length(str) - (p - 1)));
end;

{==============================================================================]
  <String_End>
  @action: Returns true if s was found in str and it was set as the ending of the str.
  @note: Supports offset.
[==============================================================================}
function String_End(var str: string; const s: string; const index: Integer = 2147483647): Boolean; cdecl;
var
  p: Integer;
begin
  p := String_PosLast(str, s, index);
  Result := (p > 0);
  if Result then
    str := Copy(str, 1, ((p + Length(s)) - 1));
end;

{==============================================================================]
  <String_Behind>
  @action: Returns string (with count) that is behind the index in str.
  @note: None
[==============================================================================}
function String_Behind(const str: string; const index, count: Integer): string; cdecl;
var
  l, r, c: Integer;
begin
  l := Length(str);
  if ((l > 0) and (index > 1) and (count > 0)) then
  begin
    c := count;
    if ((index - c) < 1) then
      c := ((index - c) + (c - 1));
    if (index > (l + 1)) then
    begin
      r := ((index - l) - 1);
      c := (c - r);
    end;
    Result := Copy(str, ((index - c) - r), c);
  end else
    Result := '';
end;

{==============================================================================]
  <String_Ahead>
  @action: Returns string (with count) that is behind the index in str.
  @note: None
[==============================================================================}
function String_Ahead(const str: string; const index, count: Integer): string; cdecl;
var
  l, c, i: Integer;
begin
  l := Length(str);
  if ((l > 0) and (index <= l) and (count > 0)) then
  begin
    c := count;
	i := index;
    if (i < 1) then
    begin
      c := (c - Abs(i - 1));
      i := 1;
    end;
    if ((c > 0) and ((i + c) > l)) then
      c := (c - (((i + c) - l) - 1));
    Result := Copy(str, i, c);
  end else
    Result := '';
end;

{==============================================================================]
  <String_After>
  @action: Returns string that is found after s in str.
  @note: None
[==============================================================================}
function String_After(const str, s: string; const index: Integer = 1): string; cdecl;
var
  p, b, a: Integer;
begin
  b := Length(s);
  a := Length(str);
  if ((b < a) and (index < a)) then
  begin
    p := String_Pos(str, s, index);
    if (p > 0) then
      Result := Copy(str, (p + b), ((1 + a) - (p + b)))
    else
      Result := '';
  end else
    Result := '';
end;

{==============================================================================]
  <String_Before>
  @action: Returns string that is found before s in str.
  @note: None
[==============================================================================}
function String_Before(const str, s: string; const index: Integer = 1): string; cdecl;
var
  p, l: Integer;
begin
  l := Length(str);
  if ((Length(s) < l)) then
  begin
    p := String_Pos(str, s, Min(l, index));
    if (p > 1) then
      Result := Copy(str, 1, (p - 1))
    else
      Result := '';
  end else
    Result := '';
end;

{==============================================================================]
  <String_AfterLast>
  @action: Returns string that is found after last s in str.
  @note: Supports index.
[==============================================================================}
function String_AfterLast(const str, s: string; const index: Integer = 2147483647): string; cdecl;
var
  p: Integer;
begin
  p := String_PosLast(str, s, index);
  if (p > 0) then
    Result := Copy(str, (p + 1), (Length(str) - p))
  else
    Result := '';
end;

{==============================================================================]
  <String_BeforeLast>
  @action: Returns string that is found before last s in str.
  @note: None
[==============================================================================}
function String_BeforeLast(const str, s: string; const index: Integer = 2147483647): string; cdecl;
var
  p: Integer;
begin
  p := String_PosLast(str, s, index);
  if (p > 0) then
    Result := Copy(str, 1, (p - Length(s)))
  else
    Result := '';
end;

{==============================================================================]
  <String_Center>
  @action: Returns str centered with fill characters where size is the length of the Result.
  @note: Supports custom filling character by fill!
[==============================================================================}
function String_Center(const str: string; const size: Integer; const fill: Char = #32): string; cdecl;
var
  l, p: Integer;
begin
  l := Length(str);
  if (l >= size) then
    Result := str
  else
    if (l > 0) then
    begin
      p := (((size - l) div 2) + 1);
      Result := (StringOfChar(fill, (p - 1)) + str + StringOfChar(fill, ((size - (p + l)) + 1)));
    end else
      Result := StringOfChar(fill, size);
end;

{==============================================================================]
  <String_Stuff>
  @action: Returns str stuffed with s. Starting from iFrom and ending to iFrom + iCount.
  @note: Places s to iFrom position and replaces iCount amount of next characters in str with s.
[==============================================================================}
function String_Stuff(const str, s: string; const iFrom, iCount: Integer): string; cdecl;
begin
  Result := Copy(str, 1, Length(str));
  Delete(Result, iFrom, iCount);
  Insert(s, Result, iFrom);
end;

{==============================================================================]
  <String_Duplicate>
  @action: Returns str * x (duplicated) times. Example: ('ha', 3) => 'hahaha'
  @note: None
[==============================================================================}
function String_Duplicate(const str: string; const x: Integer = 2): string; cdecl;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to x do
    Result := (Result + str);
end;

{==============================================================================]
  <String_Duplicated>
  @action: Returns str * x times. Example: ('ha', 3, ' ') => 'ha ha ha'
           Places glue between the str positions to result.
  @note: Supports custom glue addition between duplicated str's.
[==============================================================================}
function String_Duplicated(const str: string; const x: Integer; const glue: string): string; cdecl;
var
  i: Integer;
begin
  Result := '';
  if (x > 0) then
    if (x > 1) then
    begin
      for i := 1 to (x - 1) do
        Result := (Result + str + glue);
      Result := (Result + str);
    end else
      Result := str;
end;

{==============================================================================]
  <String_Compare>
  @action: Compares str with T.
  @note: Results: 0=EQUAL, 1=str>T, -1=str<T
[==============================================================================}
function String_Compare(const str, T: string): Integer; cdecl; inline;
begin
  if (str = T) then
    Exit(0);
  if (str > T) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <String_Quotatation>
  @action: Returns the quoted version of str.
  @note: None
[==============================================================================}
function String_Quotatation(const str: string): string; cdecl;
begin
  Result := ('''' + StringReplace(str, '''', '''''', [rfReplaceAll]) + '''');
end;

{==============================================================================]
  <String_PregQuote>
  @action: Returns string with all characters escaped that are part of the regular expression syntax.
  @note: Based on the character set...
[==============================================================================}
function String_PregQuote(const str: string; const regex: string = '.\+*?[^]$(){}=!<>|:-'): string; cdecl;
var
  l, i: Integer;
begin
  Result := str;
  l := Length(str);
  if (l > 0) then
  for i := l downto 1 do
    if (Pos(str[i], regex) > 0) then
      Insert('\', Result, i);
end;

{==============================================================================]
  <String_TrimLeft>
  @action: Returns str with left-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function String_TrimLeft(const str: string; const t: Char = #32): string; cdecl;
var
  i, l: Integer;
begin
  l := Length(str);
  for i := 1 to l do
    if (str[i] <> t) then
      Exit(Copy(str, i, ((l + 1) - i)));
  Result := '';
end;

{==============================================================================]
  <String_TrimRight>
  @action: Returns str with right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function String_TrimRight(const str: string; const t: Char = #32): string; cdecl;
var
  i, l: Integer;
begin
  l := Length(str);
  for i := l downto 1 do
    if (str[i] <> t) then
      Exit(Copy(str, 1, i));
  Result := '';
end;

{==============================================================================]
  <String_Trim>
  @action: Returns str with left-side and right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function String_Trim(const str: string; const t: Char = #32): string; cdecl;
var
  i, l, x, y: Integer;
begin
  Result := '';
  l := Length(str);
  if (l > 0) then;
  begin
    y := 0;
    for i := l downto 1 do
      if (str[i] = t) then
        Inc(y)
      else
        Break;
    if (y = l) then
      Exit;
    x := 0;
    for i := 1 to l do
      if (str[i] = t) then
        Inc(x)
      else
        Break;
    if (l <= (x + y)) then
      Exit;
    SetLength(Result, (l - (x + y)));
    for i := x to ((l - y) - 1) do
      Result[((i - x) + 1)] := str[(i + 1)];
  end;
end;

{==============================================================================]
  <String_TRange>
  @action: Returns indexes of string as TRange.
  @note: With empty string this function returns as 0..0!
[==============================================================================}
function String_TRange(const str: string): TRange; cdecl;
begin
  Result := TRange_Build(Min(1, Length(str)), Length(str));
end;

{==============================================================================]
  <String_IDs>
  @action: Returns indexes of string as TIntegerArray.
  @note: With empty string this function returns as []!
[==============================================================================}
function String_IDs(const str: string): TIntegerArray; overload; cdecl;
begin
  if (Length(str) > 0) then
    Result := TRange_TIntegerArray(String_TRange(str))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <String_IDs>
  @action: Returns indexes of string as TCharArray.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function String_IDs(const str: string; const IDs: TIntegerArray): TCharArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := str[IDs[i]];
end;

{==============================================================================]
  <String_IDs>
  @action: Returns indexes of string as TCharArray. Replaces character of str from IDs with item.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function String_IDs(const str: string; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
var
  i: Integer;
begin
  Result := String_Chars(str);
  for i := 0 to High(IDs) do
    Result[(IDs[i] - 1)] := item;
end;

{==============================================================================]
  <String_IDs>
  @action: Returns indexes of string as TCharArray. Replaces character of str from IDs with item.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function String_IDs(const str: string; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  i, l: Integer;
begin
  Result := String_Chars(str);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[(IDs[i] - 1)] := items[(i mod l)];	
end;  