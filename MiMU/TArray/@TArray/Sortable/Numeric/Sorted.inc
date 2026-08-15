{$IFDEF HELPERS}
function Sorting(const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sorting>
  @action: Determines whether the array is sorted in ascending or descending order.
  @note:
    - Equal adjacent values are allowed.
    - Sorting direction is controlled by oAscending (True = ascending, False = descending).
    - Uses sign comparison of element differences for order detection.
    - Terminates early when a violation is found.
[==============================================================================}
function MArrayHelper.Sorting(const oAscending: Boolean = True): Boolean; overload;
var
  i, o: Integer;
begin
  o := Ord(not oAscending);
  for i := 0 to (High(Self) - 1) do
    if ((Self[i] <> Self[i + 1]) and (Ord((Self[i + 1] - Self[i]) < 0) <> o)) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
