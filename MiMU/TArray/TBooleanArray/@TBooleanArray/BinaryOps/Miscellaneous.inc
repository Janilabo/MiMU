{$IFDEF HELPERS}
function BinaryPivot(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <BinaryPivot>
  @action: Returns the starting index of the second partition in the sorted array.
           - Ascending [F, F, T, T]: Returns index of the FIRST True.
           - Descending [T, T, F, F]: Returns index of the FIRST False.
  @note: Returns Self.Length if the array contains only one uniform value type.
[==============================================================================}
function TBooleanArrayHelper.BinaryPivot(const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.Binary1st(True, True)
  else
    Result := Self.Binary1st(False, False);
  if (Result = -1) then
    Result := Self.Length;
end;
{$ENDIF}
