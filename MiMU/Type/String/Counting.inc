{$IFDEF HELPERS}
function Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
function AmountOf(const item: Char): Integer; overload; cdecl;
function Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
function CountedIn(const target: string; const overlap: Boolean = True): Integer; overload; cdecl;
function CountIn(const target: string): Integer; overload; cdecl;
function CountOf(const item: Char): Integer; overload; cdecl;
function CountTokens(const items: TStringArray): Integer; overload; cdecl;
function Occurrences(const item: Char): Integer; overload; cdecl;
function Occurs(const item: Char): Integer; overload; cdecl;
function TokensCount(const items: TStringArray): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Amount>
  @action: Simply returns the amount of s in str.
  @note: Contains support for overlapping (overlap)
[==============================================================================}
function TStringHelper.Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(Self, 1, index);
  o := overlap.Select(1, Length(s));
  p := (1 - o);
  repeat
    p := c.Find(s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <AmountOf>
  @action: Returns how many times the specified character appears in the string.
  @note: Equivalent to CountOf but expressed with repeat/until iteration.
[==============================================================================}
function TStringHelper.AmountOf(const item: Char): Integer; overload; cdecl;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  if (P < E) then
  repeat
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  until (P = E);
end;

{==============================================================================]
  <Count>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Overlapping occurrences are considered.
  @note: The search is case-sensitive. If the length of Self is greater than
         the length of the target, the result is zero. This implementation
         uses a naive O(n*m) substring search algorithm, where n = Length(target)
         and m = Length(Self), so it may be inefficient for long strings.
[==============================================================================}
function TStringHelper.Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(Self, index, ((Length(Self) - index) + 1));
  o := overlap.Select(1, Length(s));
  p := (1 - o);
  repeat
    p := c.Find(s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <CountedIn>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Supports optional counting of
           overlapping occurrences.
  @note - The search is case-sensitive.
        - If `overlap` is True, overlapping occurrences are counted.
        - If `overlap` is False, occurrences are counted without overlaps
          (i.e., the search skips ahead by the length of the substring after
          each match).
        - Uses a naive O(n*m) substring search algorithm (n = Length(target),
          m = Length(Self)); may be inefficient for long strings.
        - If Self is empty or longer than target, the result is 0.
[==============================================================================}
function TStringHelper.CountedIn(const target: string; const overlap: Boolean = True): Integer; overload; cdecl;
var
  i, j, l, s, o: Integer;
begin
  Result := 0;
  l := Length(Self);
  if not InRange(l, 1, Length(target)) then
    Exit;
  s := ((Length(target) - l) + 1);
  i := 0;
  o := overlap.Select(0, (l - 1));
  while (i.Increase < s) do
    for j := 1 to l do
    case (Self[j] <> target[(i + j) - 1]) of
      False:
      if ((j = l) and (Self[j] = target[(i + j) - 1])) then
      begin
        Inc(Result);
        Inc(i, o);
      end;
      True: Break;
    end;
end;

{==============================================================================]
  <CountIn>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Overlapping occurrences are considered.
  @note: The search is case-sensitive. If the length of Self is greater than
         the length of the target, the result is zero. This implementation
         uses a naive O(n*m) substring search algorithm, where n = Length(target)
         and m = Length(Self), so it may be inefficient for long strings.
[==============================================================================}
function TStringHelper.CountIn(const target: string): Integer; overload; cdecl;
var
  i, j, l: Integer;
begin
  Result := 0;
  l := Length(Self);
  if InRange(l, 1, Length(target)) then
  for i := 1 to ((Length(target) - l) + 1) do
    for j := 1 to l do
      if (Self[j] <> target[(i + j) - 1]) then
        Break
      else if ((j = l) and (Self[j] = target[(i + j) - 1])) then
        Inc(Result);
end;

{==============================================================================]
  <CountOf>
  @action: Returns the number of occurrences of the specified character.
  @note: Performs a straightforward linear scan. Suitable for general use.
[==============================================================================}
function TStringHelper.CountOf(const item: Char): Integer; overload; cdecl;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  while (P < E) do
  begin
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <CountTokens>
  @action: Counts the number of non-overlapping occurrences of the specified token
           strings in the string. Scans left-to-right, matching the first token that
           fits at each position.
  @note:
    - Tokens are tested in the order provided; first match wins.
    - Overlapping tokens must be ordered from longest to shortest to avoid
      double-counting (e.g., #13#10 before #13 and #10).
    - Returns 0 if the string is empty or no tokens match.
[==============================================================================}
function TStringHelper.CountTokens(const items: TStringArray): Integer; overload; cdecl;
label
  ContinueScan;
var
  i, l, j, s: Integer;
begin
  Result := 0;
  s := Length(Self);
  i := 1;
  while (i <= s) do
  begin
    for j := 0 to High(items) do
    begin
      l := Length(items[j]);
      if (((l > 0) and (i + l - 1 <= s)) and CompareMem(@Self[i], @items[j][1], (l * SizeOf(Char)))) then
      begin
        Inc(Result);
        Inc(i, l);
        goto ContinueScan;
      end;
    end;
    Inc(i);
    ContinueScan:
  end;
end;

{==============================================================================]
  <Occurrences>
  @action: Returns the number of occurrences of the specified character.
  @note: Optimized approach using loop unrolling for improved performance.
[==============================================================================}
function TStringHelper.Occurrences(const item: Char): Integer; overload; cdecl;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  while ((PtrUInt(E) - PtrUInt(P)) >= 4) do
  begin
    Result := (Result + (Ord(P[0] = item)) + Ord(P[1] = item) + Ord(P[2] = item) + Ord(P[3] = item));
    Inc(P, 4);
  end;
  while (P < E) do
  begin
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <Occurs>
  @action: Counts occurrences of the specified character using indexed access.
  @note: Uses 1-based string indexing; clear and simple but slightly slower.
[==============================================================================}
function TStringHelper.Occurs(const item: Char): Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = item) then
      Inc(Result);
end;

{==============================================================================]
  <TokensCount>
  @action: Counts the number of non-overlapping occurrences of the specified token
           strings within the string. This version is provided for cases where a
           noun-first style is preferred over the verb-first form CountTokens.
  @note:
    - Tokens are tested in the order provided; the first matching token is
      counted at each position.
    - Overlapping tokens must be ordered from longest to shortest to prevent
      double-counting (e.g., #13#10 before #13 and #10).
    - The function performs a single left-to-right scan and advances the
      position by the full length of the matched token.
    - Returns 0 if the string is empty or no tokens are matched.
    - Matches are non-overlapping; once a token is matched, shorter tokens
      starting at the same position are ignored.
[==============================================================================}
function TStringHelper.TokensCount(const items: TStringArray): Integer; overload; cdecl;
var
  i, j, l, s: Integer;
  m: Boolean;
begin
  Result := 0;
  s := Length(Self);
  i := 1;
  while (i <= s) do
  begin
    m := False;
    for j := 0 to High(items) do
    begin
      l := Length(items[j]);
      if (((l > 0) and (i + l - 1 <= s)) and CompareMem(@Self[i], @items[j][1], (l * SizeOf(Char)))) then
      begin
        Inc(Result);
        Inc(i, l);
        m := True;
        Break;
      end;
    end;
    if not m then
      Inc(i);
  end;
end;
{$ENDIF}