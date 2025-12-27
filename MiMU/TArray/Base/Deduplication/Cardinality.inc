{$IFDEF HELPERS}
function Distinct: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distinct>
  @action: Returns the number of unique elements in array 
  @note: None.
[==============================================================================}
function MArrayHelper.Distinct: Integer; overload;
var
  i, j: Integer;
  u: Boolean;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
  begin
    u := True;
    for j := 0 to (i - 1) do
      if (Self[i] = Self[j]) then
      begin
        u := False;
        Break;
      end;
    if u then
      Inc(Result);
  end;
end;
{$ENDIF}