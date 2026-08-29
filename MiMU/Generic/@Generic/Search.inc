{$IFDEF FUNCTIONS}
generic function Position<T>(const arr: array of T; const item: T): Integer; overload;
generic function Location<T>(const arr: array of T; const item: T): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Position>
  @action: Finds the first index of an item in an array.
  @note: Returns the index if found, -1 if the item does not exist. Searches Low to High.
[==============================================================================}
generic function Position<T>(const arr: array of T; const item: T): Integer; overload;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Finds the last index of an item in an array.
  @note: Returns the index if found, -1 if the item does not exist. Searches High to Low.
[==============================================================================}
generic function Location<T>(const arr: array of T; const item: T): Integer; overload;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;
{$ENDIF}