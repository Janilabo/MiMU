{$IFDEF HELPERS}
function IsBinarial: Boolean; overload;
function IsBinary(const emptyTrue: Boolean = True): Boolean; overload;
function IsNumber: Boolean; overload;
function IsNumeric: Boolean; overload;
function IsNumerical: Boolean; overload;
function Number: Boolean; overload;
function Numbery: Boolean; overload;
function Numberyous: Boolean; overload;
function Numerable: Boolean; overload;
function Numeric: Boolean; overload;
function Numerical: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  i, l: Integer;
begin
  l := Length(Self);
  for i := 1 to l do
    if ((Ord(Self[i]) xor 48) > 1) then
      Exit(False);
  Result := (l > 0);
end;

{==============================================================================]
  <IsBinary>
  @action: Returns true if str contains only 0's and 1's
  @note: If str is empty and emptyTrue is True, then this function returns True with empty strings.
[==============================================================================}
function TStringHelper.IsBinary(const emptyTrue: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  if (Self = '') then
    Exit(emptyTrue);
  for i := 1 to Length(Self) do
    if not (Self[i] in ['0', '1']) then
      Exit(False);
  Result := True;
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
  if ((p^ = '-') or (p^ = '+')) then
  begin
    Inc(p);
    Dec(l);
  end;
  if (l = 0) then
    Exit(False);
  while (l > 0) do
    if not ((p^ < '0') or (p^ > '9')) then
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
    if (P^ in ['0'..'9']) then
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
  o := Integer((Self[1] = '-') or (Self[1] = '+'));
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
  o := Integer((Self[1] = '-') or (Self[1] = '+'));
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
  s := Integer((Self[1] = '-') or (Self[1] = '+'));
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
  s := IfThen(((Self[1] = '-') or (Self[1] = '+')), 1, 0);
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
const
  DIGIT_SET: set of Char = ['0'..'9'];
  SIGN_SET: set of Char = ['-', '+'];
var
  i, s, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(False);
  s := Integer(Self[1] in SIGN_SET);
  if ((s = 1) and (l = 1)) then
    Exit(False);
  for i := (1 + s) to l do
    if not (Self[i] in DIGIT_SET) then
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
  s := Integer((Self[1] = '-') or (Self[1] = '+'));
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
  i := IfThen(((Self[1] = '-') or (Self[1] = '+')), 2, 1);
  if (i > l) then
    Exit(False);
  while ((i <= l) and (Self[i] >= '0') and (Self[i] <= '9')) do
    Inc(i);
  Result := (i > l);
end;
{$ENDIF}
