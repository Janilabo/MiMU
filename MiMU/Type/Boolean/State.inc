{$IFDEF HELPERS}
function Disable: Boolean; cdecl;
function Enable: Boolean; cdecl;
function SetFalse: Integer; cdecl;
function SetTrue: Integer; cdecl;
function SwitchOff(const state: Boolean): Boolean; cdecl;
function SwitchOn(const state: Boolean): Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Disable>
  @action: Sets Self to False (disabled).
  @note: Returns True if Self was previously True.
[==============================================================================}
function TBooleanHelper.Disable: Boolean; cdecl;
begin
  Result := (Self = True);
  Self := False;
end;

{==============================================================================]
  <Enable>
  @action: Sets Self to True (enabled).
  @note: Returns True if Self was previously False.
[==============================================================================}
function TBooleanHelper.Enable: Boolean; cdecl;
begin
  Result := (Self <> True);
  Self := True;
end;

{==============================================================================]
  <SetFalse>
  @action: Sets Self as False and returns 0.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetFalse: Integer; cdecl;
begin
  Self := False;
  Result := 0;
end;

{==============================================================================]
  <SetTrue>
  @action: Sets Self as True and returns 1.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetTrue: Integer; cdecl;
begin
  Self := True;
  Result := 1;
end;

{==============================================================================]
  <SwitchOff>
  @action: Inverts Self only if it equals the given state.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOff(const state: Boolean): Boolean; cdecl;
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
function TBooleanHelper.SwitchOn(const state: Boolean): Boolean; cdecl;
begin
  Result := (Self <> state);
  if Result then
    Self := state;
end;
{$ENDIF}