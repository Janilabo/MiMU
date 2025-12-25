{$IFDEF HELPERS}
function Scan(const target: MArray): TIntegerArray; overload;
function PositionsIn(const target: MArray): TIntegerArray; overload;
function LocationsIn(const target: MArray): TIntegerArray; overload;
function Positions(const target: MArray): TIntegerArray; overload;
function Locations(const target: MArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Scan>
  @action: Scans the given array target and returns the zero-based indexes at which
           elements are equal to Self.
  @note: Performs a single-pass linear scan and collects matching indexes.
         The result array grows dynamically using geometric expansion to minimize
         reallocations.
         Indexes are returned in ascending order.
         If target is empty or no matches are found, an empty array is returned.
         This implementation favors reduced passes over the array and is well suited
         for cases where the number of matches is unknown.
[==============================================================================}
function MTypeHelper.Scan(const target: MArray): TIntegerArray; overload;
var
  i, r, c: Integer;
begin
  SetLength(Result, 0);
  if target.Empty then
    Exit;
  r := 0;
  c := 8;
  SetLength(Result, c);
  for i := 0 to High(target) do
    if (target[i] = Self) then
    begin
      if (r = c) then
        SetLength(Result, c.Increase(c * 2));
      Result[r.Increase] := i;
    end;
  SetLength(Result, r);
end;

{==============================================================================]
  <PositionsIn>
  @action: Returns the zero-based positions at which elements in target are equal to Self.
  @note: Allocates the result array using AppearsIn to determine the exact number of matches.
         Iterates over target from the end toward the beginning, filling the result array
         from the end, which produces indexes in ascending order.
         If no matches are found, an empty array is returned.
         This implementation minimizes memory allocations while preserving deterministic
         ordering.
[==============================================================================}
function MTypeHelper.PositionsIn(const target: MArray): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.AppearsIn(target));
  l := Result.Length;
  if (l > 0) then
  for i := High(target) downto 0 do
    if (Self = target[i]) then
      Result[l.Decrement] := i;
end;

{==============================================================================]
  <LocationsIn>
  @action: Returns the zero-based locations at which elements in target are equal to Self.
  @note: Allocates the result array using AppearsIn to determine the exact number of matches.
         Iterates over target from beginning to end while filling the result array from the end,
         producing indexes in descending order.
         If no matches are found, an empty array is returned.
         This implementation is functionally equivalent to PositionsIn but returns the
         indexes in reversed order.
[==============================================================================}
function MTypeHelper.LocationsIn(const target: MArray): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.AppearsIn(target));
  l := Result.Length;
  if (l > 0) then
  for i := 0 to High(target) do
    if (Self = target[i]) then
      Result[l.Decrement] := i;
end;

{==============================================================================]
  <Positions>
  @action: Returns the zero-based positions at which elements in target are equal to Self.
  @note: Allocates the result array using CountIn to determine the exact number of matches.
         Iterates over target from the end toward the beginning and fills the result
         array from the end, producing indexes in ascending order.
         If no matches are found, an empty array is returned.
         This implementation guarantees a single allocation and predictable memory
         usage.
[==============================================================================}
function MTypeHelper.Positions(const target: MArray): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.CountIn(target));
  l := Result.Length;
  if (l > 0) then
  for i := High(target) downto 0 do
    if (target[i] = Self) then
      Result[l.Decrement] := i;
end;

{==============================================================================]
  <Locations>
  @action: Returns the zero-based locations at which elements in target are equal to Self.
  @note: Allocates the result array using CountIn to determine the exact number of matches.
         Iterates over target from beginning to end while filling the result array from
         the end, resulting in indexes ordered in descending order.
         If no matches are found, an empty array is returned.
         This method is functionally equivalent to Positions but differs in the
         ordering of the returned indexes.
[==============================================================================}
function MTypeHelper.Locations(const target: MArray): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.CountIn(target));
  l := Result.Length;
  if (l > 0) then
  for i := 0 to High(target) do
    if (target[i] = Self) then
      Result[l.Decrement] := i;
end;
{$ENDIF}