{$IFDEF HELPERS}
function AppearsIn(const target: MArray): Integer; overload;
function CountIn(const target: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
function MTypeHelper.AppearsIn(const target: MArray): Integer; overload;
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
function MTypeHelper.CountIn(const target: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(target) do
    Inc(Result, Ord(target[i] = Self));
end;
{$ENDIF}