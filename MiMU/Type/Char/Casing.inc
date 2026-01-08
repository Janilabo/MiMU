{$IFDEF HELPERS}
function Lower: Char; cdecl;
function Swapcase: Char; cdecl;
function Upper: Char; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Lower>
  @action: Lowers char casing if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Lower: Char; cdecl;
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 65, 90) then
    Result := Char(o + 32)
  else
    Result := Self;
end;

{==============================================================================]
  <Swapcase>
  @action: Swaps casing of Char, if it is part of letters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Swapcase: Char; cdecl;
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 65, 90) then
    Result := Char(o + 32)
  else
    if InRange(o, 97, 122) then
      Result := Char(o - 32)
    else
      Result := Self;
end;

{==============================================================================]
  <Upper>
  @action: Uppers char casing if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Upper: Char; cdecl;
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 97, 122) then
    Result := Char(o - 32)
  else
    Result := Self;
end;
{$ENDIF}