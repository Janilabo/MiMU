{$IFDEF HELPERS}
function Shuffle: Int64; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Shuffle>
  @action: Random() with support for negative Range.
  @note: None
[==============================================================================}
function TInt64Helper.Shuffle: Int64; cdecl;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;
{$ENDIF}