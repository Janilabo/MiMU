{$IFDEF HELPERS}
function OrderIs(const oAscending: Boolean = True): Boolean; overload;
function Sorting(const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <OrderIs>
  @action: Validates whether the array elements are ordered according to the 
           specified direction flag.
  @note: Uses a branchless direction multiplier (1 for ascending, -1 for 
         descending) to perform a single-pass order check. Requires integer/
         numeric types where element subtraction will not overflow.
[==============================================================================}
function MArrayHelper.OrderIs(const oAscending: Boolean = True): Boolean; overload;
var
  i, d: Integer;
begin
  d := ((Ord(oAscending) * 2) - 1);
  for i := 0 to (Self.Length - 2) do
    if (((Self[i + 1] - Self[i]) * d) < 0) then
      Exit(False);
  Result := True;
end;

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
