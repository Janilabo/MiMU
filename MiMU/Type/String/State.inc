{$IFDEF HELPERS}
function Blank: Boolean; overload;
function Empty: Boolean; overload;
function Emptyish: Boolean; overload;
function Exists: Boolean; overload;
function Void: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blank>
  @action: Returns true if string is empty or consists of whitespaces only.
  @note: None.
[==============================================================================}
function TStringHelper.Blank: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to Length(Self) do
    if not CharInSet(Self[i], [' ', #9, #10, #13]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Empty>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Empty: Boolean; overload;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
  <Emptyish>
  @action: Determines whether a string is empty or consists solely of whitespace 
           characters.
  @note: Strips leading and trailing spaces, tabs, and control characters via 
         Trim before checking. Returns True for '', '   ', or line breaks, 
         making it highly resilient for user input validation.
[==============================================================================}
function TStringHelper.Emptyish: Boolean; overload;
begin
  Result := (SysUtils.Trim(Self) = '');
end;

{==============================================================================]
  <Exists>
  @action: Returns true if string is not empty.
  @note: Length(str) > 0.
[==============================================================================}
function TStringHelper.Exists: Boolean; overload;
begin
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <Void>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Void: Boolean; overload;
begin
  Result := (Self = '');
end;
{$ENDIF}
