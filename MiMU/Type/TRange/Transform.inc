{$IFDEF METHODS}
function Mirror(const mCenter: Integer = 0): TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Mirror>
  @action: Mirrors the range around a center point (mCenter) on the number line.
  @param mCenter: The center value to mirror around. Defaults to 0.
  @returns: A new TRange with mirrored endpoints and reversed direction.
  @note: Mirrors using formula: mirrored = 2*center - value
         Example: TRange(2, 4).Mirror(10) = TRange(18, 16)
[==============================================================================}
function TRange.Mirror(const mCenter: Integer = 0): TRange;
begin
  Result.start := ((2 * mCenter) - Self.start);
  Result.stop := ((2 * mCenter) - Self.stop);
end;
{$ENDIF}
