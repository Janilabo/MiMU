{$IFDEF HELPERS}
function Toggle: Boolean;
function Opposite: Boolean;
function Switch: Boolean;
function Flip: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Toggle>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Toggle: Boolean; 
begin
  Result := not Self;
end;

{==============================================================================]
  <Opposite>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Opposite: Boolean; 
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
function TBooleanHelper.Switch: Boolean; 
begin
  if Self then
    Self := False
  else
    Self := True;
  Result := Self;
end;

{==============================================================================]
  <Flip>
  @action: Reverses Self.
  @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Flip: Boolean; 
begin
  Self := not Self;
  Result := Self;
end;
{$ENDIF}