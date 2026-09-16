{$IFDEF HELPERS}
function Activate: Boolean; overload;
function Deactivate: Boolean; overload;
function Disable: Boolean; overload;
function Enable: Boolean; overload;
function SetFalse: Integer; overload;
function SetTrue: Integer; overload;
function SwitchOff(const state: Boolean): Boolean; overload;
function SwitchOn(const state: Boolean): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Activate>
  @action: Sets Self to True.
  @note: Returns True if Self was previously False.
[==============================================================================}
function TBooleanHelper.Activate: Boolean; overload;
begin
  Result := not Self;
  Self := True;
end;

{==============================================================================]
  <Deactivate>
  @action: Sets Self to False.
  @note: Returns True if Self was previously True.
[==============================================================================}
function TBooleanHelper.Deactivate: Boolean; overload;
begin
  Result := Self;
  Self := False;
end;

{==============================================================================]
  <Disable>
  @action: Sets Self to False (disabled).
  @note: Returns True if Self was previously True.
[==============================================================================}
function TBooleanHelper.Disable: Boolean; overload;
begin
  Result := (Self = True);
  Self := False;
end;

{==============================================================================]
  <Enable>
  @action: Sets Self to True (enabled).
  @note: Returns True if Self was previously False.
[==============================================================================}
function TBooleanHelper.Enable: Boolean; overload;
begin
  Result := (Self <> True);
  Self := True;
end;

{==============================================================================]
  <SetFalse>
  @action: Sets Self as False and returns 0.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetFalse: Integer; overload;
begin
  Self := False;
  Result := 0;
end;

{==============================================================================]
  <SetTrue>
  @action: Sets Self as True and returns 1.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetTrue: Integer; overload;
begin
  Self := True;
  Result := 1;
end;

{==============================================================================]
  <SwitchOff>
  @action: Inverts Self only if it equals the given state.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOff(const state: Boolean): Boolean; overload;
begin
  Result := (Self = state);
  if Result then
    Self := not state;
end;

{==============================================================================]
  <SwitchOn>
  @action: Sets Self to the given state if different.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOn(const state: Boolean): Boolean; overload;
begin
  Result := (Self <> state);
  if Result then
    Self := state;
end;
{$ENDIF}