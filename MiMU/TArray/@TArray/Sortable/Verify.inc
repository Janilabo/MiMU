{$IFDEF HELPERS}
function Flaw(const oAscending: Boolean = True): Integer; overload;
function Fault(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flaw>
  @action: Returns the index of the last element where the array violates the
           expected sorted order.
  @note: Scans in reverse comparing each element with its successor. Equal
         adjacent values are allowed. Returns -1 when the array satisfies
         the specified ordering.
[==============================================================================}
function MArrayHelper.Flaw(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := (High(Self) - 1) downto 0 do
    if ((Self[Result] <> Self[Result + 1]) and ((Self[Result] < Self[Result + 1]) xor oAscending)) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Fault>
  @action: Returns the index of the first element where the array violates the
           expected sorted order.
  @note: Scans forward comparing each element with its successor. Equal
         adjacent values are allowed. Returns -1 when the array satisfies
         the specified ordering.
[==============================================================================}
function MArrayHelper.Fault(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := 0 to (High(Self) - 1) do
    if ((Self[Result] <> Self[Result + 1]) and ((Self[Result] < Self[Result + 1]) xor oAscending)) then
      Exit;
  Result := -1;
end;
{$ENDIF}
