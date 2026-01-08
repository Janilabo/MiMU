{$IFDEF HELPERS}
function Shuffle: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Shuffle>
  @action: Randomizes Self and then returns it.
  @note: None
[==============================================================================}
function TBooleanHelper.Shuffle: Boolean; cdecl; 
begin
  Self := (Random(2) = 0);
  Result := Self;
end;
{$ENDIF}