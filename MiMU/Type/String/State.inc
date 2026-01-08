{$IFDEF HELPERS}
function Blank: Boolean; cdecl;
function Empty: Boolean; cdecl;
function Exists: Boolean; cdecl;
function Void: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blank>
  @action: Returns true if string is empty or consists of whitespaces only.
  @note: None.
[==============================================================================}
function TStringHelper.Blank: Boolean; cdecl;
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
function TStringHelper.Empty: Boolean; cdecl;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
  <Exists>
  @action: Returns true if string is not empty.
  @note: Length(str) > 0.
[==============================================================================}
function TStringHelper.Exists: Boolean; cdecl;
begin
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <Void>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Void: Boolean; cdecl;
begin
  Result := (Self = '');
end;
{$ENDIF}