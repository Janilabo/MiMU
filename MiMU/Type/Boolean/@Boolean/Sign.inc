{$IFDEF HELPERS}
function Sign: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sign>
  @action: Converts Self to a signed unit value.
  @note: Returns 1 if Self is True, -1 if Self is False. There is no zero case.
[==============================================================================}
function TBooleanHelper.Sign: Integer; overload;
begin
  if Self then
    Result := 1
  else
    Result := -1;
end;
{$ENDIF}