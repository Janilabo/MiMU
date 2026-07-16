{$IFDEF HELPERS}
function BinaryError(const oAscending: Boolean = True): Integer; overload;
function BinaryFail(const oAscending: Boolean = True): Integer; overload;
function BinaryFailure(const oAscending: Boolean = True): Integer; overload;
function BinaryViolation(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryError>
  @action: Returns the index of the first element where the array violates the
           expected sorted order.
  @note: Scans the array forward and detects ordering violations using a
         boolean XOR expression. Supports ascending and descending checks.
         Returns -1 if the array respects the specified ordering.
[==============================================================================}
function MArrayHelper.BinaryError(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := 0 to (High(Self) - 1) do
    if ((Ord(Self[Result] > Self[Result + 1]) xor Ord(oAscending) = 0) and (Self[Result] <> Self[Result + 1])) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <BinaryFail>
  @action: Returns the index of the first element where the array ordering
           fails relative to the specified sort direction.
  @note: Uses a simplified XOR comparison to detect violations while ignoring
         equal neighboring elements. Returns -1 when the array satisfies the
         expected ordering.
[==============================================================================}
function MArrayHelper.BinaryFail(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := 0 to (High(Self) - 1) do
    if ((not (Self[Result] = Self[Result + 1])) and ((Self[Result] < Self[Result + 1]) xor oAscending)) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <BinaryFailure>
  @action: Returns the index of the last element where the array violates the
           expected sorted order.
  @note: Scans the array in reverse order to locate the rightmost ordering
         violation. Returns -1 when the array satisfies the specified sort
         direction.
[==============================================================================}
function MArrayHelper.BinaryFailure(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := (High(Self) - 1) downto 0 do
    if ((oAscending and (Self[Result] > Self[Result + 1])) or ((not oAscending) and (Self[Result] < Self[Result + 1]))) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <BinaryViolation>
  @action: Returns the index of the first element that breaks the expected
           sorted ordering.
  @note: Performs a direct comparison between adjacent elements according
         to the specified sort direction. Returns -1 when no violation is
         found.
[==============================================================================}
function MArrayHelper.BinaryViolation(const oAscending: Boolean = True): Integer; overload;
begin
  for Result := 0 to (High(Self) - 1) do
    if ((oAscending and (Self[Result] > Self[Result + 1])) or ((not oAscending) and (Self[Result] < Self[Result + 1]))) then
      Exit;
  Result := -1;
end;
{$ENDIF}