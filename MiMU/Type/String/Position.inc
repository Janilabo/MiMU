{$IFDEF HELPERS}
function At(const s: string; const index: Integer = 1): Boolean; cdecl; inline;
function At2(const s: string; const index: Integer = 1): Boolean; cdecl;
function AtIndex(const s: string; const index: Integer = 1): Boolean; cdecl;
function AtP(const s: string; const index: Integer = 1): Boolean; cdecl;
function AtPos(const s: string; const index: Integer = 1): Boolean; cdecl;
function AtPosEx(const s: string; const index: Integer = 1): Boolean; cdecl;
function AtPosition(const s: string; const index: Integer = 1): Boolean; cdecl;
function IsAt(const s: string; const index: Integer = 1): Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <At>
  @action: Checks if string s is at index position in str.
  @note: UNSAFE: Minimal checking for efficiency!
[==============================================================================}
function TStringHelper.At(const s: string; const index: Integer = 1): Boolean; cdecl; inline;
var
  i: Integer;
begin
  for i := 1 to Length(s) do
    if (Self[((index) + i) - 1] <> s[i]) then
      Exit(False);
  Result := (Length(s) > 0);
end;

{==============================================================================]
  <At2>
  @action: Compares the substring s with the characters of the current string
           starting at the specified 1-based index using a decrementing-length
           loop and raw pointer iteration.
  @note: Performs no validation of the receiver’s bounds; the caller must
         guarantee that index and Length(s) reference valid memory within
         Self. Uses minimal loop overhead and a countdown-based termination
         condition, making this an efficient but unsafe low-level routine.
[==============================================================================}
function TStringHelper.At2(const s: string; const index: Integer = 1): Boolean; cdecl;
var
  a, b: PChar;
  l: Integer;
begin
  l := Length(s);
  if (l = 0) then
    Exit(False);
  a := (PChar(Self) + (index - 1));
  b := PChar(s);
  repeat
    if (a^ <> b^) then
      Exit(False);
    Inc(a);
    Inc(b);
  until (l.Decrement = 0);
  Result := True;
end;

{==============================================================================]
  <AtIndex>
  @action: Determines whether the substring s matches the content of the
           current string beginning at the specified 1-based index by performing
           a direct character-by-character comparison.
  @note: Avoids temporary string allocation and uses an early check on the
         first character for efficiency. Performs full boundary validation and
         is suitable for performance-sensitive contexts where readability and
         safety must both be preserved.
[==============================================================================}
function TStringHelper.AtIndex(const s: string; const index: Integer = 1): Boolean; cdecl;
var
  i, l: Integer;
begin
  l := Length(s);
  if ((l = 0) or (index < 1) or (((index + l) - 1) > Length(Self)) or (Self[index] <> s[1])) then
    Exit(False);
  for i := 2 to l do
    if (Self[(index + i) - 1] <> s[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <AtP>
  @action: Evaluates whether the substring s matches the characters of the
           current string beginning at the specified 1-based index by performing
           a raw pointer-based sequential comparison.
  @note: Performs no boundary validation on Self; caller must ensure that
         index and Length(s) reference valid memory within the string.
         Uses direct pointer arithmetic and is optimized for maximum speed
         with minimal overhead, but is inherently unsafe if misused.
[==============================================================================}
function TStringHelper.AtP(const s: string; const index: Integer = 1): Boolean; cdecl;
var
  a, b, c: PChar;
  l: Integer;
begin
  l := Length(s);
  if (l = 0) then
    Exit(False);
  a := (PChar(Self) + (index - 1));
  b := PChar(s);
  c := (b + l);
  while (b < c) do
  begin
    if (a^ <> b^) then
      Exit(False);
    Inc(a);
    Inc(b);
  end;
  Result := True;
end;

{==============================================================================]
  <AtPos>
  @action: Determines whether the substring s matches the content of the
           current string starting at the specified 1-based index.
  @note: Performs full bounds checking and uses Copy for comparison, which
         is safe but allocates a temporary substring.
[==============================================================================}
function TStringHelper.AtPos(const s: string; const index: Integer = 1): Boolean; cdecl;
begin
  Result := ((index > 0) and (Length(s) > 0) and (((index + Length(s)) - 1) <= Length(Self)) and (Copy(Self, index, Length(s)) = s));
end;

{==============================================================================]
  <AtPosEx>
  @action: Determines whether the substring s matches the content of the
           current string starting at the specified 1-based index.
  @note: Based on PosEx
[==============================================================================}
function TStringHelper.AtPosEx(const s: string; const index: Integer = 1): Boolean; cdecl;
begin
  Result := ((Length(s) > 0) and (index > 0) and (PosEx(s, Self, index) = index));
end;

{==============================================================================]
  <AtPosition>
  @action: Checks whether the substring s is present at the specified 1-based
           index in the current string using a direct memory comparison.
  @note: Validates bounds but avoids temporary allocations by using
         CompareMem, providing a faster, low-overhead comparison.
[==============================================================================}
function TStringHelper.AtPosition(const s: string; const index: Integer = 1): Boolean; cdecl;
var
  l: Integer;
begin
  l := Length(s);
  if ((l = 0) or (index < 1) or (((index + l) - 1) > Length(Self))) then
    Exit(False);
  Result := CompareMem(@Self[index], @s[1], (l * SizeOf(Char)));
end;

{==============================================================================]
  <IsAt>
  @action: Evaluates whether the substring s matches the characters of the
           current string beginning at the specified 1-based index by performing
           a raw memory comparison via CompareMem.
  @note: Performs no boundary checks on Self or index; the caller must ensure
         that the referenced range is valid. Provides extremely low overhead
         and represents the fastest practical implementation when safety is
         managed externally.
[==============================================================================}
function TStringHelper.IsAt(const s: string; const index: Integer = 1): Boolean; cdecl;
begin
  Result := CompareMem((PChar(Self) + (index - 1)), PChar(s), (Length(s) * SizeOf(Char)));
end;
{$ENDIF}