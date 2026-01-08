{$IFDEF HELPERS}
function IsLetter: Boolean; cdecl;
function IsLower: Boolean; cdecl;
function IsLowercase: Boolean; cdecl;
function IsNumber: Boolean; cdecl;
function IsNumeric: Boolean; cdecl;
function IsUpper: Boolean; cdecl;
function IsUppercase: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsLetter>
  @action: Returns true if Char is part of lowercased or uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLetter: Boolean; cdecl;
var
  o: Integer;
begin
  o := Ord(Self);
  Result := (InRange(o, 65, 90) or InRange(o, 97, 122));
end;

{==============================================================================]
  <IsLower>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLower: Boolean; cdecl;
begin
  Result := InRange(Ord(Self), 97, 122);
end;

{==============================================================================]
  <IsLowercase>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLowercase: Boolean; cdecl;
begin
  Result := ((Self >= 'a') and (Self <= 'z'));
end;

{==============================================================================]
  <IsNumber>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumber: Boolean; cdecl;
begin
  Result := ((Self >= '0') and (Self <= '9'));
end;

{==============================================================================]
  <IsNumeric>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumeric: Boolean; cdecl;
begin
  Result := InRange(Ord(Self), 48, 57);
end;

{==============================================================================]
  <IsUpper>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUpper: Boolean; cdecl;
begin
  Result := InRange(Ord(Self), 65, 90);
end;

{==============================================================================]
  <IsUppercase>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUppercase: Boolean; cdecl;
begin
  Result := ((Self >= 'A') and (Self <= 'Z'));
end;
{$ENDIF}