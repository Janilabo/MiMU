{$IFDEF HELPERS}
function Condense: MArray; overload;
function Monotonize(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Condense>
  @action: Returns a new array with consecutive duplicate elements removed.
  @note: Unsorted arrays will retain non-adjacent duplicate values.
[==============================================================================}
function MArrayHelper.Condense: MArray; overload;
var
  r, i: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if ((Self[i] - Result[r]) <> 0) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Monotonize>
  @action: Returns a new array containing a strictly monotonic (increasing or decreasing) sequence.
  @note: Scans left-to-right and drops any element that does not strictly exceed (True) or stay below (False) the previously retained element.
[==============================================================================}
function MArrayHelper.Monotonize(const oAscending: Boolean = True): MArray; overload;
var
  r, i: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  Result[0] := Self[0];
  case oAscending of
    True:
    for i := 1 to High(Self) do
      if ((Self[i] - Result[r]) > 0) then
        Result[r.Increment] := Self[i];
    False:
    for i := 1 to High(Self) do
      if ((Self[i] - Result[r]) < 0) then
        Result[r.Increment] := Self[i];
  end;
  SetLength(Result, (r + 1));
end;
{$ENDIF}
