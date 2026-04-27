{$IFDEF METHODS}
function Mirror(const mCenter: Integer = 0): TRange; overload;
function Reflect(const val: Integer): Integer; overload;
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
function TRange.Mirror(const mCenter: Integer = 0): TRange; overload;
begin
  Result.start := ((2 * mCenter) - Self.start);
  Result.stop := ((2 * mCenter) - Self.stop);
end;

{==============================================================================]
  <Reflect>
  @action: Returns the "mirrored" coordinate within the range boundaries.
  @note:
    - Direction Agnostic: Works for both 10..20 and 20..10.
    - Logic: (Start + Stop) - val.
    - Example: If Range is 10..20: Reflect(10) = 20.
               If Range is 20..10: Reflect(20) = 10.
[==============================================================================}
function TRange.Reflect(const val: Integer): Integer; overload;
begin
  Result := ((Self.start + Self.stop) - val);
end;
{$ENDIF}
