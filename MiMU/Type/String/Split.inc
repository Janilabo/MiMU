{$IFDEF HELPERS}
function Chop: TCharArray; overload; cdecl;
function Chop(const delimiter: Char): TStringArray; overload; cdecl;
function Delimited(const d: Char = #32): TStringArray; overload; cdecl;
function Explode: TCharArray; overload; cdecl;
function Explode(const d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
function Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
function Split: TCharArray; overload; cdecl;
function Split(const delimiter: Char): TStringArray; overload; cdecl;
function Tokenized(const d: Char = #32): TStringArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Chop>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Chop: TCharArray; overload; cdecl;
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
function TStringHelper.Chop(const delimiter: Char): TStringArray; overload; cdecl;
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
function TStringHelper.Delimited(const d: Char = #32): TStringArray; overload; cdecl;
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
  <Explode>
  @action: Simply "explodes" string to TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Explode: TCharArray; overload; cdecl;
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
function TStringHelper.Explode(const d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
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
function TStringHelper.Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
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
  <Split>
  @action: Converts the string into an array of characters (TCharArray),
           where each element of the array is a single character from the string.
  @note: - The resulting array length is equal to the length of the string.
         - Characters are placed in the same order as in the original string.
[==============================================================================}
function TStringHelper.Split: TCharArray; overload; cdecl;
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
function TStringHelper.Split(const delimiter: Char): TStringArray; overload; cdecl;
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
function TStringHelper.Tokenized(const d: Char = #32): TStringArray; overload; cdecl;
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
{$ENDIF}