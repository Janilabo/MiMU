{$IFDEF HELPERS}
function Falseness: Integer; overload;
function Occupancy(const val: Boolean = True): Double; overload;
function Matching(const tState: Boolean): Integer; overload;
function Score(const iTrue: Integer = 1; const iFalse: Integer = 0): Integer; overload;
function Trueness: Integer; overload;
function Unmatching(const tState: Boolean): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Falseness>
  @action: Returns count of False values arr has got.
  @note: [False, False, True, True, False] => 3
[==============================================================================}
function TBooleanArrayHelper.Falseness: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if not Self[i] then
      Inc(Result);
end;

{==============================================================================]
  <Matching>
  @action: Counts how many elements in the boolean array match the specified target state.
  @note: Implemented using a branchless approach, casting the boolean comparison directly to an integer via Ord() to accumulate the count.
[==============================================================================}
function TBooleanArrayHelper.Matching(const tState: Boolean): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Ord(Self[i] = tState));
end;

{==============================================================================]
  <Occupancy>
  @action: Returns the occupancy of the array: fraction of elements that are True.
           1.0 = all val, 0.0 = no vals
[==============================================================================}
function TBooleanArrayHelper.Occupancy(const val: Boolean = True): Double; overload;
var
  i, c: Integer;
begin
  if Self.Empty then
    Exit(0.0);
  c := 0;
  for i := 0 to High(Self) do
    if (Self[i] = val) then
      Inc(c);
  Result := (c / Self.Size);
end;

{==============================================================================]
  <Score>
  @action: Compiles a weighted mathematical total across the array by mapping boolean states to custom integer point values.
  @note: Highly flexible algorithm for game scoring, multi-rule evaluation, or custom metric tallies.
[==============================================================================}
function TBooleanArrayHelper.Score(const iTrue: Integer = 1; const iFalse: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if Self[i] then
      Result := (Result + iTrue)
    else
      Result := (Result + iFalse);
end;

{==============================================================================]
  <Trueness>
  @action: Returns count of True values arr has got.
  @note: [False, False, True, True, False] => 2
[==============================================================================}
function TBooleanArrayHelper.Trueness: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if Self[i] then
      Inc(Result);
end;

{==============================================================================]
  <Unmatching>
  @action: Counts how many elements in the boolean array do not match the specified target state.
  @note: Reuses the Matching function by passing the inverted (not) tState, ensuring clean code reuse without duplicating the loop.
[==============================================================================}
function TBooleanArrayHelper.Unmatching(const tState: Boolean): Integer; overload;
begin
  Result := Self.Matching(not tState);
end;
{$ENDIF}
