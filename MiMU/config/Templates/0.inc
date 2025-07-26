{==============================================================================]
  <field(arr: TArray): TIntegerArray>
  @action: Returns X values from TPointArray arr.
  @note: None.
[==============================================================================}
function XFUNC(const arr: XARRAY): XRETURN; overload; cdecl;
{$IFNDEF IMPLEMENT}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].XFIELD;
end;
{$ENDIF}
