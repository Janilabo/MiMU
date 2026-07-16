{$IFDEF HELPERS}
function IsDigit: Boolean; overload;
function IsLetter: Boolean; overload;
function IsLower: Boolean; overload;
function IsLowercase: Boolean; overload;
function IsNumber: Boolean; overload;
function IsNumeric: Boolean; overload;
function IsUpper: Boolean; overload;
function IsUppercase: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsDigit>
  @action: Checks if the character is a valid numeric digit (0-9).
  @note: Fast set-based check; avoids complex character unit overloads.
[==============================================================================}
function TCharHelper.IsDigit: Boolean; overload;
begin
  Result := (Self in ['0'..'9']);
end;

{==============================================================================]
  <IsLetter>
  @action: Returns true if Char is part of lowercased or uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLetter: Boolean; overload;
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
function TCharHelper.IsLower: Boolean; overload;
begin
  Result := InRange(Ord(Self), 97, 122);
end;

{==============================================================================]
  <IsLowercase>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLowercase: Boolean; overload;
begin
  Result := ((Self >= 'a') and (Self <= 'z'));
end;

{==============================================================================]
  <IsNumber>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumber: Boolean; overload;
begin
  Result := ((Self >= '0') and (Self <= '9'));
end;

{==============================================================================]
  <IsNumeric>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumeric: Boolean; overload;
begin
  Result := InRange(Ord(Self), 48, 57);
end;

{==============================================================================]
  <IsUpper>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUpper: Boolean; overload;
begin
  Result := InRange(Ord(Self), 65, 90);
end;

{==============================================================================]
  <IsUppercase>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUppercase: Boolean; overload;
begin
  Result := ((Self >= 'A') and (Self <= 'Z'));
end;
{$ENDIF}