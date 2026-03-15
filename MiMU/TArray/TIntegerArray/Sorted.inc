{$IFDEF HELPERS}
function Orderliness(const oAscending: Boolean = True): Boolean; overload;
function Sorting(const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Orderliness>
  @action: Determines whether the integer array is ordered in ascending or descending order.
  @note:
    - Adjacent equal values are allowed.
    - Sorting direction is controlled by oAscending (True = ascending, False = descending).
    - Uses pointer-based iteration for efficiency.
    - Stops at the first detected ordering violation.
    - Arrays with fewer than two elements are considered ordered.
[==============================================================================}
function TIntegerArrayHelper.Orderliness(const oAscending: Boolean = True): Boolean; overload;
var
  H: Integer;
  P, E: PInteger;
begin
  H := High(Self);
  if (H < 1) then
    Exit(True);
  P := @Self[0];
  E := @Self[H];
  while (P < E) do
    if ((P^ <> (P + 1)^) and ((P^ < (P + 1)^) xor oAscending)) then
      Exit(False)
	else
      Inc(P);
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
function TIntegerArrayHelper.Sorting(const oAscending: Boolean = True): Boolean; overload;
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
