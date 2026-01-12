{$IFDEF HELPERS}
function IsLetter: Boolean;
function IsLower: Boolean;
function IsLowercase: Boolean;
function IsNumber: Boolean;
function IsNumeric: Boolean;
function IsUpper: Boolean;
function IsUppercase: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsLetter>
  @action: Returns true if Char is part of lowercased or uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLetter: Boolean;
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
function TCharHelper.IsLower: Boolean;
begin
  Result := InRange(Ord(Self), 97, 122);
end;

{==============================================================================]
  <IsLowercase>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLowercase: Boolean;
begin
  Result := ((Self >= 'a') and (Self <= 'z'));
end;

{==============================================================================]
  <IsNumber>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumber: Boolean;
begin
  Result := ((Self >= '0') and (Self <= '9'));
end;

{==============================================================================]
  <IsNumeric>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumeric: Boolean;
begin
  Result := InRange(Ord(Self), 48, 57);
end;

{==============================================================================]
  <IsUpper>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUpper: Boolean;
begin
  Result := InRange(Ord(Self), 65, 90);
end;

{==============================================================================]
  <IsUppercase>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUppercase: Boolean;
begin
  Result := ((Self >= 'A') and (Self <= 'Z'));
end;
{$ENDIF}