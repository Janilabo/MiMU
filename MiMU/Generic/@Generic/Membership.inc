{$IFDEF FUNCTIONS}
generic function Contains<T>(const arr: array of T; const item: T): Boolean; overload;
generic function Includes<T>(const arr: array of T; const item: T): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contains>
  @action: Checks if a given item exists in an array.
  @note: Returns True if the item is found, False otherwise. Searches from Low(arr) to High(arr).
[==============================================================================}
generic function Contains<T>(const arr: array of T; const item: T): Boolean; overload;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Includes>
  @action: Checks if a given item exists in an array.
  @note: Returns True if the item is found, False otherwise. Searches from High(arr) down to Low(arr).
[==============================================================================}
generic function Includes<T>(const arr: array of T; const item: T): Boolean; overload;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;
{$ENDIF}
