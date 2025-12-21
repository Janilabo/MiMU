{$IFDEF HELPERS}
function Shuffle: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Shuffle>
  @action: Random() with support for negative Range (based on x value).
  @note: None
[==============================================================================}
function TIntegerHelper.Shuffle: Integer;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;
{$ENDIF}