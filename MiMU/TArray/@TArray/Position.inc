{$IFDEF HELPERS}
function At(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
function At(const aItem: MType; const aIndex: Integer = 0): Boolean; overload;
function AtPos(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
function AtPos(const aItem: MType; const aIndex: Integer = 0): Boolean; overload;
function Identify(const aIndex: Integer; const iItems: MArray): Integer; overload;
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
  <At>
  @action: Determines whether the element at a specified index equals the given item.
           Unlike AtPosition, this method performs **no bounds checking** for maximum efficiency.
  @note:
    • Unsafe: calling with an out-of-bounds index may cause an access violation.
    • Default aIndex = 0 allows checking the first element without extra parameters.
    • Use only when you are certain the index is valid.
[==============================================================================}
function MArrayHelper.At(const aItem: MType; const aIndex: Integer = 0): Boolean; overload;
begin
  Result := (Self[aIndex] = aItem);
end;

{==============================================================================]
  <AtPos>
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
function MArrayHelper.AtPos(const sArray: MArray; const aIndex: Integer = 0): Boolean; overload;
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

{==============================================================================]
  <AtPos>
  @action: Checks whether the element at a specified index matches the given item.
  @note:
    • Returns True if:
        - aIndex is within bounds (0..Length-1), and
        - Self[aIndex] equals aItem.
    • Returns False if:
        - aIndex is out of bounds, or
        - the value does not match.
    • Default aIndex = 0 allows checking the first element conveniently.
[==============================================================================}
function MArrayHelper.AtPos(const aItem: MType; const aIndex: Integer = 0): Boolean; overload;
begin
  Result := ((aIndex > -1) and (aIndex < Self.Length) and (Self[aIndex] = aItem));
end;

{==============================================================================]
  <Identify>
  @action: Determines the position of the item at aIndex within the specified array.
  @note: Returns the zero-based index of the first matching element in iItems.
         Returns -1 if:
          • aIndex is out of bounds, or
          • no matching value is found.
[==============================================================================}
function MArrayHelper.Identify(const aIndex: Integer; const iItems: MArray): Integer; overload;
begin
  if ((aIndex  > -1) and (aIndex < Self.Length)) then
  for Result := 0 to High(iItems) do
    if (Self[aIndex] = iItems[Result]) then
      Exit;
  Result := -1;
end;
{$ENDIF}