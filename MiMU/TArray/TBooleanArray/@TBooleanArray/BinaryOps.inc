{$IFDEF HELPERS}
function BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <BinarySearch>
  @action: Searches for item in a sorted TBooleanArray.
  @note: Returns an index where item occurs, or -1 if item is not found.
[==============================================================================}
function TBooleanArrayHelper.BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  L := 0;
  R := High(Self);
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    if (Self[M] = item) then
      Exit(M);
    if (item = oAscending) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
  Result := -1;
end;
{$ENDIF}
