{$IFDEF METHODS}
class function Randomly(const N: Integer): TRange; overload; static;
class function Randomly(const aMin, aMax: Integer): TRange; overload; static;
class function Randomly(const R: TRange): TRange; overload; static;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
