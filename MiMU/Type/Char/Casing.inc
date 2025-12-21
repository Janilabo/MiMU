{$IFDEF HELPERS}
function Swapcase: Char;
function Upper: Char;
function Lower: Char;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Swapcase>
  @action: Swaps casing of Char, if it is part of letters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Swapcase: Char; 
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
function TCharHelper.Upper: Char; 
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 97, 122) then
    Result := Char(o - 32)
  else
    Result := Self;
end;

{==============================================================================]
  <Lower>
  @action: Lowers char casing if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Lower: Char; 
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 65, 90) then
    Result := Char(o + 32)
  else
    Result := Self;
end;
{$ENDIF}