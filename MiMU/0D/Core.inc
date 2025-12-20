{$IFDEF TYPES}
TCmp = specialize TCompare<TVar>;
TArr = array of TVar;
T2DArr = array of TArr;
{$ENDIF}

{$IFDEF HELPERS}
THelper = type helper for TVar
  function TArray(const aSize: Integer = 1): TArr; overload;
  function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
  function AppearsIn(const target: TArr): Integer; overload;
  function CountIn(const target: TArr): Integer; overload;
  function Scan(const target: TArr): TIntegerArray; overload;
  function PositionsIn(const target: TArr): TIntegerArray; overload;
  function LocationsIn(const target: TArr): TIntegerArray; overload;
  function Positions(const target: TArr): TIntegerArray; overload;
  function Locations(const target: TArr): TIntegerArray; overload;
{$ENDIF}

{$IFDEF METHODS}
function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline;
function Swap(var A, B: TVar): Boolean; overload; inline;
{$IFDEF Sortable}
function Swop(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function THelper.TArray(const aSize: Integer = 1): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;

{==============================================================================]
 <T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function THelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
var
  i, j: Integer;
begin
  SetLength(Result, size1D);
  for i := 0 to High(Result) do
  begin
    SetLength(Result[i], size2D);
    for j := 0 to High(Result[i]) do
      Result[i][j] := Self;
  end;
end;

{==============================================================================]
  <AppearsIn>
  @action: Counts the number of occurrences of Self within the given array target, using
           manual loop unrolling to reduce loop overhead.
  @note: Processes four elements per iteration to minimize loop-control and branching
         overhead, which may improve performance for large arrays.
         Any remaining elements (fewer than four) are processed by a final cleanup loop.
         If target is empty, the function exits immediately and returns 0.
         Correct operation assumes TRange.Create(0, High(target)) initializes inclusive
         start and stop bounds.
         This implementation is more complex than CountIn and is primarily intended for
         performance-critical scenarios where profiling justifies its use.
[==============================================================================}
function THelper.AppearsIn(const target: TArr): Integer; overload;
var
  R: TRange;
begin
  Result := 0;
  if target.Empty then
    Exit;
  R.Create(0, High(target));
  while ((R.stop - R.start) > 3) do
  begin
    Inc(Result, (Ord(target[R.start] = Self) + Ord(target[R.start + 1] = Self) + Ord(target[R.start + 2] = Self) + Ord(target[R.start + 3] = Self)));
    Inc(R.start, 4);
  end;
  while (R.start <= R.stop) do
    Inc(Result, Ord(target[R.start.Increase] = Self));
end;

{==============================================================================]
  <CountIn>
  @action: Counts the number of occurrences of Self within the given array target using a
           straightforward linear scan.
  @note: Iterates over every element in the array and increments the result for each
         match found.
         This implementation is simple, clear, and easy to maintain.
         For most array sizes, compiler optimizations make this approach sufficiently
         efficient; it should be preferred unless profiling indicates a need for the
         optimized AppearsIn implementation.
[==============================================================================}
function THelper.CountIn(const target: TArr): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(target) do
    Inc(Result, Ord(target[i] = Self));
end;

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
function THelper.Scan(const target: TArr): TIntegerArray; overload;
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
function THelper.PositionsIn(const target: TArr): TIntegerArray; overload;
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
function THelper.LocationsIn(const target: TArr): TIntegerArray; overload;
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
function THelper.Positions(const target: TArr): TIntegerArray; overload;
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
function THelper.Locations(const target: TArr): TIntegerArray; overload;
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

function Swap(var A, B: TVar): Boolean; overload; inline; var C: TVar; {$DEFINE Skeleton_Swap}{$I Skeletons.inc}{$UNDEF Skeleton_Swap}

function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline; {$DEFINE Skeleton_IfThen}{$I Skeletons.inc}{$UNDEF Skeleton_IfThen}

{$IFDEF Sortable}
function Swop(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TVar>(A, B, oAscending); end;
function Swop(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TVar>(A, B, C, oAscending); end;

function Sort(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TVar>(A, B, oAscending); end;
function Sort(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TVar>(A, B, C, oAscending); end;
{$ENDIF}
{$ENDIF}
