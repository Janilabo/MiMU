{$IFDEF HELPERS}
function Rand: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Rand>
  @action: Randomizes Self and then returns it.
  @note: None
[==============================================================================}
function TBooleanHelper.Rand: Boolean;
begin
  Self := (Random(2) = 0);
  Result := Self;
end;
{$ENDIF}