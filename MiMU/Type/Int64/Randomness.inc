{$IFDEF HELPERS}
function Rand: Int64;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Rand>
  @action: Random() with support for negative Range.
  @note: None
[==============================================================================}
function TInt64Helper.Rand: Int64;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;
{$ENDIF}