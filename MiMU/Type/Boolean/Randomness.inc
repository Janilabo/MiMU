{$IFDEF HELPERS}
function Shuffle: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Shuffle>
  @action: Randomizes Self and then returns it.
  @note: None
[==============================================================================}
function TBooleanHelper.Shuffle: Boolean;
begin
  Self := (Random(2) = 0);
  Result := Self;
end;
{$ENDIF}