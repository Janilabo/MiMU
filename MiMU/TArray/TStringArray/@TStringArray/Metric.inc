{$IFDEF HELPERS}
function Tally: Int64;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Tally>
  @action: Returns total length of TStringArray strings combined together.
  @note: None.
[==============================================================================}
function TStringArrayHelper.Tally: Int64;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result.Increase(System.Length(Self[i]));
end;
{$ENDIF}
