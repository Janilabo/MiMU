{$IFDEF HELPERS}
function IsBinared: Boolean; overload;
function IsBinarial: Boolean; overload;
function IsBinaric: Boolean; overload;
function IsBinaried: Boolean; overload;
function IsBinarily: Boolean; overload;
function IsBinarsy: Boolean; overload;
function IsBinary: Boolean; overload;
function IsBinaural: Boolean; overload;
function IsNumber: Boolean; overload;
function IsNumeric: Boolean; overload;
function IsNumerical: Boolean; overload;
function Number: Boolean; overload;
function Numberic: Boolean; overload;
function Numberous: Boolean; overload;
function Numbery: Boolean; overload;
function Numberyous: Boolean; overload;
function Numerable: Boolean; overload;
function Numeric: Boolean; overload;
function Numerical: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsBinared>
  @action: Checks whether a non-empty string consists solely of binary characters ('0' and '1').
  @note: Utilizes an inner recursive helper function (R) to perform a short-circuiting,
         left-to-right linear scan of each character in the string.
[==============================================================================}
function TStringHelper.IsBinared: Boolean; overload;
  function R(const s: string; i: Integer): Boolean;
  begin
    if (i > Length(s)) then
      Exit(True);
    Result := ((s[i] in BINARY_CHARS) and R(s, (i + 1)));
  end;
begin
  Result := ((Length(Self) > 0) and R(Self, 1));
end;

{==============================================================================]
  <IsBinarial>
  @action: Returns True if the string contains only the characters '0' and
           '1', and is non-empty; False otherwise.
  @note: Each character is tested by XOR against 48 ('0'); valid results
         are 0 or 1, anything else exceeds 1. Length is cached in `l`;
         the empty check is deferred to the return expression rather than
         an early guard, allowing the loop to serve as the sole
         character-level gate.
[==============================================================================}
function TStringHelper.IsBinarial: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to Length(Self) do
    if ((Ord(Self[i]) xor 48) > 1) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <IsBinaric>
  @action: Checks whether a non-empty string contains exclusively binary characters.
  @note: Implements a clean, idiomatic iterative approach using a standard `for..in` loop to scan characters,
         relying on an external constant set (`BINARY_CHARS`) for character validation.
[==============================================================================}
function TStringHelper.IsBinaric: Boolean; overload;
var
  c: Char;
begin
  for c in Self do
    if not (c in BINARY_CHARS) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <IsBinaried>
  @action: Checks if the string contains only binary characters ('0' and '1') 
           using a null-terminated pointer loop.
  @note: Returns True if the string is non-empty and consists strictly of 
         '0' and '1' characters; returns False otherwise. Safe against 
         string-indexing settings since it uses PChar traversal.
[==============================================================================}
function TStringHelper.IsBinaried: Boolean; overload;
var
  P: PChar;
begin
  P := PChar(Self);
  while (P^ <> #0) do
    if ((P^ <> '0') and (P^ <> '1')) then
      Exit(False)
    else
      Inc(P);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <IsBinarily>
  @action: Returns True if the string is non-empty and contains only the
           characters '0' and '1'; False otherwise.
  @note: Casts the string's first character address to PByte, walking raw
         memory and testing each byte directly against 48 and 49 (the ASCII
         ordinals of '0' and '1'), avoiding Ord() calls entirely. The index
         variable i drives iteration count while P advances independently
         as the read head
[==============================================================================}
function TStringHelper.IsBinarily: Boolean; overload;
var
  P: PByte;
  i, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  P := PByte(@Self[1]);
  for i := 1 to l do
    if ((P^ = 48) or (P^ = 49)) then
      Inc(P)
    else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsBinarsy>
  @action: Checks if the string contains only binary characters ('0' and '1') 
           by evaluating the characters in reverse order using a custom integer helper.
  @note: Returns True if the string is non-empty and consists strictly of 
         '0' and '1' characters; returns False otherwise. Uses pseudo-methods 
         on the loop variable (requires specific custom helpers to compile).
[==============================================================================}
function TStringHelper.IsBinarsy: Boolean; overload;
var
  l: Integer;
begin
  Result := (l.Assign(Length(Self)) > 0);
  while ((l > 0) and Result) do
    Result := (Self[l.Decrease] in BINARY_CHARS);
end;

{==============================================================================]
  <IsBinary>
  @action: Checks if the string contains only binary characters ('0' and '1').
  @note: Returns True if the string is non-empty and consists strictly of 
         '0' and '1' characters; returns False otherwise.
[==============================================================================}
function TStringHelper.IsBinary: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to Length(Self) do
    if not (Self[i] in BINARY_CHARS) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <IsBinaural>
  @action: Checks whether the string consists entirely of binary digits ('0' and '1').
  @note: Uses a two-pointer approach (via TRange) moving simultaneously from both ends of the string inward to validate the characters.
         Note that despite the acoustic terminology ("Binaural"), functionally this performs a binary character validation.
[==============================================================================}
function TStringHelper.IsBinaural: Boolean; overload;
var
  s: TRange;
begin
  s.Create(0, (Length(Self) + 1));
  Result := (s.stop > 1);
  while (Result and (s.start.Increment <= s.stop.Decrement)) do
    Result := ((Self[s.start] in BINARY_CHARS) and (Self[s.stop] in BINARY_CHARS));
end;

{==============================================================================]
  <IsNumber>
  @action: Checks if the string represents a valid integer, optionally preceded by a '+' or '-' sign.
  @note: Only validates whole numbers (integers); it will return False for floating-point numbers (e.g., contains '.'), thousands separators, or empty strings.
[==============================================================================}
function TStringHelper.IsNumber: Boolean; overload;
var
  p: PChar;
  l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  p := PChar(Self);
  if (p^ in SIGN_CHARS) then
  begin
    Inc(p);
    Dec(l);
  end;
  if (l = 0) then
    Exit(False);
  while (l > 0) do
    if (p^ in DIGIT_CHARS) then
    begin
      Inc(p);
      Dec(l);
    end else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsNumeric>
  @action: Validates whether the string contains exclusively numeric digits.
  @note: High-performance pointer scan that returns False instantly upon 
         encountering the first non-digit character.
		 NO SUPPORT for -/+ sign.
[==============================================================================}
function TStringHelper.IsNumeric: Boolean; overload;
var
  P: PChar;
begin
  Result := (Self <> '');
  if not Result then
    Exit;
  P := PChar(Self);
  while (P^ <> #0) do
    if (P^ in DIGIT_CHARS) then
      Inc(P)
	else
	  Exit(False);
end;

{==============================================================================]
  <Number>
  @action: Returns True if the string represents a signed integer; False
           otherwise. Accepts an optional leading sign ('+'/'-') followed by
           one or more digit characters ('0'..'9'). Empty strings and bare
           sign characters return False.
  @note: Uses a two-pointer pincer scan: a left index advances from the
         first digit and a right index retreats from the tail, meeting at
         the centre. Each iteration validates one character from each end,
         halving the number of loop passes relative to a single-direction
         scan. An odd-length digit run leaves one unvisited middle character
         which is checked as a post-loop guard.
[==============================================================================}
function TStringHelper.Number: Boolean; overload;
var
  l, r, o, s: Integer;
begin
  s := Length(Self);
  if (s = 0) then
    Exit(False);
  o := Integer(Self[1] in SIGN_CHARS);
  if ((s - o) = 0) then
    Exit(False);
  l := o;
  r := (s + 1);
  while (l.Increment < r.Decrement) do
    if ((Cardinal(Ord(Self[l]) - 48) > 9) or (Cardinal(Ord(Self[r]) - 48) > 9)) then
      Exit(False);
  Result := ((l > r) or (Cardinal(Ord(Self[l]) - 48) <= 9));
end;

{==============================================================================]
  <Numberic>
  @action: Returns True if the string is non-empty and represents a valid
           signed or unsigned whole integer; False otherwise.
  @note: Uses a for..in enumerator over the string characters, delegating
         digit membership to DIGIT_CHARS and sign membership to SIGN_CHARS.
         A boolean flag gates the first character via a case..of dispatch,
         permitting either a digit or an optional leading sign; all subsequent
         characters must be digits. A bare sign with no following digits
         returns False.
[==============================================================================}
function TStringHelper.Numberic: Boolean; overload;
var
  l: Integer;
  c: Char;
  f: Boolean;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  f := True;
  for c in Self do
  case f of
    True:
    begin
      f := False;
      if not ((c in DIGIT_CHARS) or (c in SIGN_CHARS)) then
        Exit(False);
    end;
	False:
    if not (c in DIGIT_CHARS) then
      Exit(False);
  end;
  Result := not ((l = 1) and (Self[1] in SIGN_CHARS));
end;

{==============================================================================]
  <Numberous>
  @action: Returns True if the string is non-empty and represents a valid
           signed or unsigned whole integer; False otherwise.
  @note: Uses a PChar null-terminator walk, advancing the pointer through
         the string without index arithmetic or a cached length. An optional
         leading sign is consumed by a single pointer increment before the
         main digit scan; a bare sign with no following digits is rejected
         by the second null-terminator guard.
[==============================================================================}
function TStringHelper.Numberous: Boolean; overload;
var
  p: PChar;
begin
  p := PChar(Self);
  if (p^ = #0) then
    Exit(False);
  if (p^ in SIGN_CHARS) then
    Inc(p);
  if (p^ = #0) then
    Exit(False);
  while (p^ <> #0) do
    if (p^ in DIGIT_CHARS) then
	  Inc(p)
	else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Numbery>
  @action: Checks if the current string represents a valid, whole integer number (including optional leading positive '+' or negative '-' signs).
  @note: Highly optimized, low-level pointer arithmetic implementation.
         It performs a two-pointer scan (from both ends inward) and assumes standard ASCII/UTF-8 character encoding for digits ('0'..'9').
[==============================================================================}
function TStringHelper.Numbery: Boolean; overload;
var
  L, R: PByte;
  o, s: Integer;
begin
  s := Length(Self);
  if (s = 0) then
    Exit(False);
  o := Integer(Self[1] in SIGN_CHARS);
  if ((s - o) = 0) then
    Exit(False);
  L := (PByte(PChar(Self)) + o);
  R := (PByte(PChar(Self)) + (s - 1));
  while (L < R) do
    if not ((Cardinal(L^ - 48) > 9) or (Cardinal(R^ - 48) > 9)) then
    begin
      Inc(L);
      Dec(R);
    end else
      Exit(False);
  Result := not ((L = R) and (Cardinal(L^ - 48) > 9));
end;

{==============================================================================]
  <Numberyous>
  @action: Validates if the string is a well-formed whole integer (allowing an optional leading '+' or '-' sign).
  @note: A mid-point convergence loop implementation using standard 1-based string indexing.
         It minimizes loop iterations by checking characters symmetrically from both ends simultaneously using an identical ASCII ordinal offset trick.
[==============================================================================}
function TStringHelper.Numberyous: Boolean; overload;
var
  i, s, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  s := Integer(Self[1] in SIGN_CHARS);
  if ((l - s) = 0) then
    Exit(False);
  for i := (1 + s) to ((1 + s + l) div 2) do
    if ((Cardinal(Ord(Self[i]) - 48) > 9) or  (Cardinal(Ord(Self[(l - i) + 1]) - 48) > 9)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsNumerical>
  @action: Validates whether the string represents a valid signed or unsigned 
           whole integer number.
  @note: Highly optimized index-shifting design. Uses an analytical offset 
         to cleanly bypass an optional leading sign, backed by a structural length 
         boundary gate to reject isolated operational symbols.
[==============================================================================}
function TStringHelper.IsNumerical: Boolean; overload;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  s := IfThen((Self[1] in SIGN_CHARS), 1, 0);
  for i := (1 + s) to l do
    if not (Self[i] in [#48..#57]) then
      Exit(False);
  Result := ((l > 1) or (s = 0));
end;

{==============================================================================]
  <Numerable>
  @action: Validates if the string represents a valid whole integer. Returns True if the string consists entirely of digits (0-9), optionally preceded by a single '+' or '-' sign.
  @note: 
  - Returns False for empty strings or strings containing only a sign character.
  - Leverages Pascal sets (SIGN_SET and DIGIT_SET) for efficient character validation.
  - Safely skips the first character index if a sign is detected by typecasting the boolean membership check to an Integer (0 or 1).
  - Uses 1-based string indexing.
[==============================================================================}
function TStringHelper.Numerable: Boolean; overload;
var
  i, s, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  s := Integer(Self[1] in SIGN_CHARS);
  if ((s = 1) and (l = 1)) then
    Exit(False);
  for i := (1 + s) to l do
    if not (Self[i] in DIGIT_CHARS) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Numeric>
  @action: Validates if the string represents a strictly whole integer. Returns True if the string is composed entirely of numeric digits (0-9), optionally starting with a single '+' or '-' sign.
  @note: 
  - Returns False for empty strings or strings that only contain a sign character.
  - Converts the boolean sign check into an integer offset (0 or 1) to dynamically adjust the starting index of the loop.
  - Utilizes a fast Cardinal pointer/ASCII offset trick `Cardinal(Ord(Self[i]) - 48) > 9` to determine if a character is outside the '0'..'9' ASCII range (ASCII 48-57) in a single comparison.
  - Uses 1-based string indexing.
[==============================================================================}
function TStringHelper.Numeric: Boolean; overload;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  s := Integer(Self[1] in SIGN_CHARS);
  if ((l - s) = 0) then
    Exit(False);
  for i := (1 + s) to l do
    if (Cardinal(Ord(Self[i]) - 48) > 9) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Numerical>
  @action: Validates if the string represents a strictly whole integer. Returns True if the string contains only digits (0-9),
           optionally starting with a single '+' or '-' sign.
  @note: 
  - Returns False for empty strings or solitary signs.
  - Returns False for floating-point values (e.g., '12.34') or whitespace.
  - Uses 1-based string indexing.
[==============================================================================}
function TStringHelper.Numerical: Boolean; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  i := IfThen((Self[1] in SIGN_CHARS), 2, 1);
  if (i > l) then
    Exit(False);
  while ((i <= l) and (Self[i] in DIGIT_CHARS)) do
    Inc(i);
  Result := (i > l);
end;
{$ENDIF}
