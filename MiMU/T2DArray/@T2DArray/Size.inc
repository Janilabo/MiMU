{$IFDEF HELPERS}
function SetSize(const sSize: Integer = 1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SetSize>
  @action: Resizes the 2D dynamic array to the specified number of elements.
  @note: If sSize is 0 or negative, the array is cleared. Existing data is 
         preserved if the array is expanded. Uses Math unit for Max().
		 By default sets size as 1!
[==============================================================================}
function M2DArrayHelper.SetSize(const sSize: Integer = 1): Integer; overload;
begin
  SetLength(Self, Max(0, sSize));
  Result := Self.Length;
end;
{$ENDIF}
