{$IFDEF HELPERS}
function At(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
function AtPosition(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <At>
  @action: Returns True if sArray matches Self starting at the specified index.
  @param sArray: The sub-array to compare against Self.
  @param index: The starting position in Self for comparison (default = 0).
  @return: True if all elements of sArray match sequentially at index; otherwise False.
  @note: UNSAFE. Performs no bounds checking to keep efficiency!
         Caller must ensure that (index >= 0) and (index + sArray.Length <= Self.Length).
         Returns False if sArray is empty.
[==============================================================================}
function MArrayHelper.At(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
var
  i, l: Integer;
begin
  l := sArray.Length;
  for i := 0 to (l - 1) do
    if (Self[aIndex + i] <> sArray[i]) then
      Exit(False);
  Result := (l > 0);
end;

{==============================================================================]
  <AtPosition>
  @action: Returns True if sArray matches Self starting at the specified index.
  @param sArray: The sub-array to compare against Self.
  @param index: The starting position in Self for comparison (default = 0).
  @return: True if all elements of sArray match sequentially at index; otherwise False.
  @note: Safe implementation. Checks that:
         - Self is non-empty
         - sArray is non-empty
         - index is non-negative
         - There is enough room in Self for the comparison
         Prevents out-of-range access.
[==============================================================================}
function MArrayHelper.AtPosition(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
var
  i, l: Integer;
begin
  l := sArray.Length;
  if ((l = 0) or (aIndex < 0) or ((aIndex + l) > Self.Length)) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[aIndex + i] <> sArray[i]) then
      Exit(False);
  Result := True;
end;
{$ENDIF}