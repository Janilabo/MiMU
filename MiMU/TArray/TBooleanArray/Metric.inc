{$IFDEF HELPERS}
function Trueness: Integer; overload;  
function Falseness: Integer; overload;
function Occupancy(const val: Boolean = True): Double; overload;
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
{$ENDIF}
