{$IFDEF FUNCTIONS}
generic function GetArrayBounds<T>(const arr: array of T; out L, H: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <GetArrayBounds>
  @action: Returns the bounds and element count of the specified dynamic array.
  @note: Supports dynamic arrays passed via open array parameter.
         Returns 0 if the array is empty.
         L = Low(arr), H = High(arr).
         Complexity: O(1). No element traversal performed.
[==============================================================================}
generic function GetArrayBounds<T>(const arr: array of T; out L, H: Integer): Integer; overload;
begin
  L := Low(arr);
  H := High(arr);
  if (H < L) then
    Exit(0);
  Result := ((H - L) + 1);
end;
{$ENDIF}