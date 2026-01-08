{$IFDEF HELPERS}
function Flip: Boolean; cdecl;
function Opposite: Boolean; cdecl;
function Switch: Boolean; cdecl;
function Toggle: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flip>
  @action: Reverses Self.
  @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Flip: Boolean; cdecl;
begin
  Self := not Self;
  Result := Self;
end;

{==============================================================================]
  <Opposite>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Opposite: Boolean; cdecl;
begin
  if Self then
    Result := False
  else
    Result := True;
end;

{==============================================================================]
  <Switch>
  @action: Reverses Self.
  @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Switch: Boolean; cdecl;
begin
  if Self then
    Self := False
  else
    Self := True;
  Result := Self;
end;

{==============================================================================]
  <Toggle>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Toggle: Boolean; cdecl;
begin
  Result := not Self;
end;
{$ENDIF}