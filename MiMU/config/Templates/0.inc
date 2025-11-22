{==============================================================================]
  <field(arr: TArray): TIntegerArray>
  @action: Returns X values from TPointArray arr.
  @note: None.
[==============================================================================}
function XFIELD(const arr: XARRAY): XRETURN; overload;
{$IFDEF IMPLEMENT}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].XFIELD;
end;
{$ENDIF}
