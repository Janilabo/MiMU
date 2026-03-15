{$IFDEF HELPERS}
function BinaryBreach(const oAscending: Boolean = True): Integer; overload;
function BinaryBreaks(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBreach>
  @action: Returns the index of the first element where the array violates the
           expected sorted order.
  @note: Uses a direction multiplier (+1 for ascending, −1 for descending)
         to perform a branch-free comparison between adjacent elements while
         scanning forward. Returns -1 when the array satisfies the specified
         ordering.
[==============================================================================}
function TIntegerArrayHelper.BinaryBreach(const oAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := (1 - (2 * Ord(not oAscending)));
  for Result := 0 to (High(Self) - 1) do
    if (((Self[Result] - Self[Result + 1]) * d) > 0) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <BinaryBreaks>
  @action: Returns the index of the last element where the array violates the
           expected sorted order.
  @note: Scans the array in reverse order using a direction multiplier
         (+1 for ascending, −1 for descending) to detect ordering violations
         without branching inside the loop. Returns -1 when the array
         respects the specified ordering.
[==============================================================================}
function TIntegerArrayHelper.BinaryBreaks(const oAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := ((Ord(oAscending) * 2) - 1);
  for Result := (High(Self) - 1) downto 0 do
    if (((Self[Result] - Self[Result + 1]) * d) > 0) then
      Exit;
  Result := -1;
end;
{$ENDIF}
