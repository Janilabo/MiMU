{$IFDEF OPERATORS}
operator +(const a, b: TRange): TRange;
operator -(const a, b: TRange): TRange;
operator =(const a, b: TRange): Boolean;
operator <>(const a, b: TRange): Boolean;

operator in(const I: Integer; const R: TRange): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <+>
  @action: Computes the union of two integer ranges. The result spans from the
           smallest start value of either input range to the largest stop value.
  @note:   Both ranges are internally normalized to ascending order before the
           union is calculated. Descending ranges are fully supported.
[==============================================================================}
operator +(const a, b: TRange): TRange;
var
  x, y: TRange;
begin
  x := a.Normalize;
  y := b.Normalize;
  Result.Create(Min(x.start, y.start), Max(x.stop,  y.stop));
end;

{==============================================================================]
  <->
  @action: Computes the intersection of two integer ranges. If the ranges
           overlap, the result contains the overlapping interval. If they do
           not overlap, the function returns an empty range marker.
  @note:   Both ranges are normalized internally to ascending order before the
           intersection is computed. A non-overlapping result is represented
           by start = stop = Low(Integer).
[==============================================================================}
operator -(const a, b: TRange): TRange;
var
  x, y: TRange;
begin
  x := a.Normalize;
  y := b.Normalize;
  if ((x.stop < y.start) or (y.stop < x.start)) then
    Exit(TRange.Null);
  Result.start := Max(x.start, y.start);
  Result.stop := Min(x.stop, y.stop);
end;

{==============================================================================]
  <=>
  @action: Compares two ranges for exact equality. Returns True when both start and stop
           values are identical in both ranges.
  @note: The comparison is structural; ordering is not normalized. A range (3, 7) is not
         considered equal to a reversed range (7, 3).
[==============================================================================}
operator =(const a, b: TRange): Boolean;
begin
  Result := ((a.start = b.start) and (a.stop = b.stop));
end;

{==============================================================================]
  <<>>
  @action: Compares two ranges for inequality. Returns True when either start or stop
           differs between the two ranges.
  @note: This is the logical negation of the equality operator. Like '=', the test is
         sensitive to value order and does not perform normalization.
[==============================================================================}
operator <>(const a, b: TRange): Boolean;
begin
  Result := not ((a.start = b.start) and (a.stop = b.stop));
end;

{==============================================================================]
  <in>
  @action: Evaluates whether the given integer I lies within the bounds of the
           specified range R. Returns True when I is contained inside R according
           to the range's containment rules.
  @note: The containment test follows TRange.Contains, including its handling of
         ascending or descending ranges. No normalization is performed unless
         Contains does so internally.
[==============================================================================}
operator in(const I: Integer; const R: TRange): Boolean;
begin
  Result := R.Contains(I);
end;
{$ENDIF}