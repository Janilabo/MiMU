{$IFDEF METHODS}
function Randrift(const aMin, aMax: Integer): TRange; overload;
function Randrift(const aStart, aStop: TRange): TRange; overload;
function Randrift(const N: Integer): TRange; overload;
class function Randomly(const N: Integer): TRange; overload; static;
class function Randomly(const aMin, aMax: Integer): TRange; overload; static;
class function Randomly(const R: TRange): TRange; overload; static;
class function Randomly(const aStart, aStop: TRange): TRange; overload; static;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Randrift>
  @action: Shifts the current range's boundaries by applying a random, independent 
           offset to both 'start' and 'stop' within the closed interval [aMin, aMax].
  @note: 
    - The generated range may change its size and orientation relative to the original.
    - Assumes aMax is greater than or equal to aMin; if aMax < aMin, a run-time division 
      by zero or invalid argument error may occur in the Random calculation.
[==============================================================================}
function TRange.Randrift(const aMin, aMax: Integer): TRange; overload;
begin
  Result.start := (Self.start + aMin + Random((aMax - aMin) + 1));
  Result.stop := (Self.stop + aMin + Random((aMax - aMin) + 1));
end;

{==============================================================================]
  <Randrift>
  @action: Shifts the current range's boundaries by applying independent random 
           offsets. 'start' is offset by a random value within the 'aStart' range, 
           and 'stop' is offset by a random value within the 'aStop' range.
  @note: 
    - Offsets are calculated relative to the Minimum bound of each constraint range 
      using a half-open interval [Minimum, Minimum + Size - 1].
    - Highly useful for applying asymmetrical random "jitter" or noise to the start 
      and end of a range independently.
[==============================================================================}
function TRange.Randrift(const aStart, aStop: TRange): TRange; overload;
begin
  Result.start := (Self.start + aStart.Minimum + Random(aStart.Size));
  Result.stop := (Self.stop + aStop.Minimum + Random(aStop.Size));
end;

{==============================================================================]
  <Randrift>
  @action: Shifts the current range's boundaries by applying a random, independent 
           positive offset to both 'start' and 'stop' within the range [0, N-1].
  @note: 
    - Sibling overload that degenerates to Randrift(0, N - 1).
    - Requires N to be greater than 0; passing N <= 0 will result in a runtime 
      invalid random argument exception.
[==============================================================================}
function TRange.Randrift(const N: Integer): TRange; overload;
begin
  Result := Self.Randrift(0, (N - 1));
end;

{==============================================================================]
  <Randomly>
  @action: Generates a TRange with both endpoints independently drawn from [0, N).
  @note: start and stop are not ordered relative to each other — start may exceed
         stop. N follows Random()'s convention: the upper bound is exclusive.
[==============================================================================}
class function TRange.Randomly(const N: Integer): TRange; overload;
begin
  Result.start := Random(N);
  Result.stop := Random(N);
end;

{==============================================================================]
  <Randomly>
  @action: Generates a TRange with both endpoints independently drawn from
           [aMin, aMax], inclusive on both ends.
  @note: start and stop are not ordered relative to each other — start may exceed
         stop. aMin may exceed aMax; RandomRange normalizes this internally.
         Unlike the single-argument overload, both bounds here are inclusive.
[==============================================================================}
class function TRange.Randomly(const aMin, aMax: Integer): TRange; overload;
begin
  Result.start := RandomRange(aMin, (aMax + 1));
  Result.stop := RandomRange(aMin, (aMax + 1));
end;

{==============================================================================]
  <Randomly>
  @action: Generates a TRange with both endpoints independently drawn from within
           the bounds of an existing TRange R, inclusive on both ends.
  @note: Works regardless of whether R is ascending or descending — the correct
         low/high bound is selected via R.Ascending before drawing. start and stop
         of the result are not ordered relative to each other.
[==============================================================================}
class function TRange.Randomly(const R: TRange): TRange; overload;
begin
  if R.Asceal then
    Result.Create(RandomRange(R.start, (R.stop + 1)), RandomRange(R.start, (R.stop + 1)))
  else
    Result.Create(RandomRange(R.stop, (R.start + 1)), RandomRange(R.stop, (R.start + 1)));
end;

{==============================================================================]
  <Randomly>
  @action: Generates a TRange whose start is drawn independently from within
           aStart's span and whose stop is drawn independently from within
           aStop's span.
  @note: 
    - start and stop are not ordered relative to each other; either may
      exceed the other, even if aStart and aStop themselves don't overlap.
    - Each source range's Minimum/Maximum is used rather than raw start/stop,
      so a reversed aStart or aStop (start > stop) is handled safely.
    - Unlike the single-range overload, the two endpoints are drawn from two
      independent pools rather than one shared [aMin, aMax] pool.
[==============================================================================}
class function TRange.Randomly(const aStart, aStop: TRange): TRange; overload;
begin
  Result.start := RandomRange(aStart.Minimum, (aStart.Maximum + 1));
  Result.stop := RandomRange(aStop.Minimum, (aStop.Maximum + 1));
end;
{$ENDIF}
