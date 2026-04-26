{$IFDEF METHODS}
function Anchor(const aLength: Integer = 1): TRange; overload;
function AnchorStart(const aLength: Integer = 1): TRange; overload;
function AnchorStop(const aLength: Integer = 1): TRange; overload;
function Bounce(const val: Integer): Integer; overload;
function Clamp(const zone: TRange): TRange; overload;
function ClampMin(const minValue: Integer): TRange; overload;
function ClampMax(const maxValue: Integer): TRange; overload;
function Clip(const zone: TRange): TRange; overload;
function ClipMax(const maxValue: Integer): TRange; overload;
function ClipMin(const minValue: Integer): TRange; overload;
function Confine(const val: Integer): Integer; overload;
function Ensure(const zone: TRange): Boolean; overload;
function Ensured(const zone: TRange): TRange; overload;
function Limit(const val: Integer): Integer; overload;
function MaxLimit(const val: Integer): Integer; overload;
function MinLimit(const val: Integer): Integer; overload;
function Pin(const val: Integer): Integer; overload;
function Pinned(const val: Integer): Integer; overload;
function Pinned(const vals: TRange): TRange; overload;
function PinMax(const val: Integer): Integer; overload;
function PinMin(const val: Integer): Integer; overload;
function Restrict(const zone: TRange): Boolean; overload;
function RestrictMax(const maxValue: Integer): Boolean; overload;
function RestrictMin(const minValue: Integer): Boolean; overload;
function Snap(const val: Integer): Integer; overload;
function Snap(const vals: TRange): TRange; overload;
function Wrap(const val: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Anchor>
  @action: Returns a range of the given length anchored to the natural end of
           the range, based on its direction.
  @note: This is a non-mutating operation. For ascending ranges, anchoring is
         performed at the start endpoint; for descending ranges, anchoring is
         performed at the stop endpoint.
         Length is inclusive: aLength = 1 produces a single-point range.
         The direction of the original range is preserved.
[==============================================================================}
function TRange.Anchor(const aLength: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result := Self.AnchorStart(aLength)
  else
    Result := Self.AnchorStop(aLength);
end;

{==============================================================================]
  <AnchorStart>
  @action: Returns a range of the given length anchored at the start endpoint.
  @note: This is a non-mutating operation. The resulting range begins at
         Self.start and extends in the direction of the original range.
         Length is inclusive: aLength = 1 produces a single-point range.
         If aLength < 2, the range collapses to [start .. start].
         The direction (ascending or descending) of the original range
         is preserved.
[==============================================================================}
function TRange.AnchorStart(const aLength: Integer = 1): TRange; overload;
begin
  if (aLength < 2) then
    Exit(TRange.Construct(Self.start, Self.start));
  if Self.Ascending then
    Result.Create(Self.start, (Self.start + (aLength - 1)))
  else
    Result.Create(Self.start, (Self.start - (aLength - 1)));
end;

{==============================================================================]
  <AnchorStop>
  @action: Returns a range of the given length anchored at the stop endpoint.
  @note: This is a non-mutating operation. The resulting range ends at
         Self.stop and extends backward relative to the direction of the
         original range.
         Length is inclusive: aLength = 1 produces a single-point range.
         If aLength < 2, the range collapses to [stop .. stop].
         The direction (ascending or descending) of the original range
         is preserved.
[==============================================================================}
function TRange.AnchorStop(const aLength: Integer = 1): TRange; overload;
begin
  if (aLength < 2) then
    Exit(TRange.Construct(Self.stop, Self.stop));
  if Self.Ascending then
    Result.Create((Self.stop - (aLength - 1)), Self.stop)
  else
    Result.Create((Self.stop + (aLength - 1)), Self.stop);
end;

{==============================================================================]
  <Bounce>
  @action: Constraints a value within the range by "bouncing" it off the
           boundaries instead of wrapping or clamping.
  @return: A value that oscillates between start and stop.
  @example: For Range(10, 13), inputs 10, 11, 12, 13, 14, 15...
            become 10, 11, 12, 13, 12, 11...
[==============================================================================}
function TRange.Bounce(const val: Integer): Integer; overload;
var
  m, w, d, r: Integer;
begin
  m := Min(Self.start, Self.stop);
  w := Abs(Self.stop - Self.start);
  if (w = 0) then
    Exit(m);
  d := (w * 2);
  r := ((val - m) mod d);
  if (r < 0) then
    r := (r + d);
  if (r > w) then
    Result := (m + (d - r))
  else
    Result := (m + r);
end;

{==============================================================================]
  <Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRange.Clamp(const zone: TRange): TRange; overload;
var
  z: TRange;
begin
  Result := Self.Normalize;
  z := zone.Normalize;
  if (Result.start < z.start) then
    Result.start := z.start
  else if (Result.start > z.stop) then
    Result.start := z.stop;
  if (Result.stop > z.stop) then
    Result.stop := z.stop
  else if (Result.stop < z.start) then
    Result.stop := z.start;
  if (Self.start > Self.stop) then
    Result.Reverse;
end;

{==============================================================================]
  <ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRange.ClampMax(const maxValue: Integer): TRange; overload;
begin
  if (Self.start > maxValue) then
    Result.start := maxValue
  else
    Result.start := Self.start;
  if (Self.stop > maxValue) then
    Result.stop := maxValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRange.ClampMin(const minValue: Integer): TRange; overload;
begin
  if (Self.start < minValue) then
    Result.start := minValue
  else
    Result.start := Self.start;
  if (Self.stop < minValue) then
    Result.stop := minValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRange.Clip(const zone: TRange): TRange; overload;
begin
  Result.start := Max(zone.start, Min(Self.start, zone.stop));
  Result.stop := Min(zone.stop, Max(Self.stop, zone.start));
end;

{==============================================================================]
  <ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRange.ClipMax(const maxValue: Integer): TRange; overload;
begin
  Result.start := Min(Self.start, maxValue);
  Result.stop := Min(Self.stop, maxValue);
end;

{==============================================================================]
  <ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRange.ClipMin(const minValue: Integer): TRange; overload;
begin
  Result.start := Max(Self.start, minValue);
  Result.stop := Max(Self.stop, minValue);
end;

{==============================================================================]
  <Confine>
  @action: Returns the value clamped within the range [Minimum, Maximum].
  @note: If val is less than Minimum, Minimum is returned; 
         if val is greater than Maximum, Maximum is returned. 
         Otherwise, val is returned unchanged. Implements a branchless clamp.
[==============================================================================}
function TRange.Confine(const val: Integer): Integer; overload;
var
  l, h: Integer;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  Result := ((l + h + Abs(val - l) - Abs(val - h)) div 2);
end;

{==============================================================================]
  <Ensure>
  @action: Clamps the current TRange (Self) to fit within zone.
  @note: Preserves the direction (start > stop) of Self.
         Returns True if Self was modified; False otherwise.
         Zone is normalized internally, so reversed zones are handled.
[==============================================================================}
function TRange.Ensure(const zone: TRange): Boolean; overload;
var
  s: TRange;
begin
  s := Self;
  Self := zone.Normalize;
  Self.Create(Max(Self.start, Min(s.start, Self.stop)), Min(Self.stop,  Max(s.stop,  Self.start)));
  Result := (Self <> s);
end;

{==============================================================================]
  <Ensured>
  @action: Returns a new TRange with start and stop clamped to fit within zone.
  @note: Preserves the direction (start > stop) of the original range.
         Zone is normalized internally, so reversed zones are handled.
[==============================================================================}
function TRange.Ensured(const zone: TRange): TRange; overload;
begin
  Result := zone.Normalize;
  Result.Create(Max(Result.start, Min(Self.start, Result.stop)), Min(Result.stop,  Max(Self.stop,  Result.start)));
end;

{==============================================================================]
  <Limit>
  @action: Restricts a value to lie within the range defined by Start and Stop.
  @note: Equivalent to clamping value to the inclusive range [Min(start, stop), Max(start, stop)].
         Returns Min(start, stop) if val is below the range.
         Returns Max(start, stop) if val is above the range.
         Otherwise returns value itself.
[==============================================================================}
function TRange.Limit(const val: Integer): Integer; overload;
var
  r: TRange;
begin
  r.Create(Min(Self.Start, Self.Stop), Max(Self.start, Self.stop));
  if (val < r.start) then
    Result := r.start
  else if (val > r.stop) then
    Result := r.stop
  else
    Result := val;
end;

{==============================================================================]
  <MaxLimit>
  @action: Ensures a value is not greater than the range maximum.
  @note: Returns Min(val, Max(start, stop)).
         Values below the range minimum are allowed.
         Useful when you only want to enforce an upper bound.
[==============================================================================}
function TRange.MaxLimit(const val: Integer): Integer; overload;
begin
  Result := Min(val, Max(Self.start, Self.stop));
end;

{==============================================================================]
  <MinLimit>
  @action: Ensures a value is not less than the range minimum.
  @note: Returns Max(val, Min(start, stop)).
         Values above the range maximum are allowed.
         Useful when you only want to enforce a lower bound.
[==============================================================================}
function TRange.MinLimit(const val: Integer): Integer; overload;
begin
  Result := Max(val, Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Pin>
  @action: Pins a value to the range boundaries (Clamp).
  @note: If the value is within the range, it is returned unchanged.
         Otherwise, the nearest boundary (Min or Max) is returned.
[==============================================================================}
function TRange.Pin(const val: Integer): Integer; overload;
begin
  Result := Max(Self.Minimum, Min(Self.Maximum, val));
end;

{==============================================================================]
  <Pinned>
  @action: Returns the value constrained within the range [Minimum, Maximum].
  @note: If val is less than Minimum, Minimum is returned; 
         if val is greater than Maximum, Maximum is returned; 
         otherwise, val is returned unchanged. Uses standard conditional branching.
[==============================================================================}
function TRange.Pinned(const val: Integer): Integer; overload;
begin
  if (val < Self.Minimum) then
    Result := Self.Minimum
  else if (val > Self.Maximum) then
    Result := Self.Maximum
  else
    Result := val;
end;

{==============================================================================]
  <Pinned>
  @action: Forces an external range to stay within the bounds of this range.
  @note: Clamps both Start and Stop to [Minimum..Maximum]. If the input 
         range exceeds these bounds, it is truncated or "pinned" to the edges.
[==============================================================================}
function TRange.Pinned(const vals: TRange): TRange; overload;
var
  l, h: Integer;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  if (vals.start < l) then
    Result.start := l
  else if (vals.start > h) then
    Result.start := h
  else
    Result.start := vals.start;
  if (vals.stop > h) then
    Result.stop := h
  else if (vals.stop < l) then
    Result.stop := l
  else
    Result.stop := vals.stop;
end;

{==============================================================================]
  <PinMax>
  @action: Ensures the value is not higher than the range's Maximum.
  @note: Ignores the lower bound (Minimum).
[==============================================================================}
function TRange.PinMax(const val: Integer): Integer; overload;
begin
  Result := Min(Self.Maximum, val);
end;

{==============================================================================]
  <PinMin>
  @action: Ensures the value is not lower than the range's Minimum.
  @note: Ignores the upper bound (Maximum).
[==============================================================================}
function TRange.PinMin(const val: Integer): Integer; overload;
begin
  Result := Max(Self.Minimum, val);
end;

{==============================================================================]
  <Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.Restrict(const zone: TRange): Boolean; overload;
var
  e: TRange;
begin
  e := Self.Clamp(zone);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMax(const maxValue: Integer): Boolean; overload;
var
  e: TRange;
begin
  e := Self.ClampMax(maxValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMin(const minValue: Integer): Boolean; overload;
var
  e: TRange;
begin
  e := Self.ClampMin(minValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <Snap>
  @action: Forces a value to reside within the range boundaries.
  @note: If the value is outside the [Minimum..Maximum] bounds, it "snaps"
         to the closest boundary. This is functionally equivalent to a Clamp.
[==============================================================================}
function TRange.Snap(const val: Integer): Integer; overload;
var
  m: Integer;
begin
  m := Self.Minimum;
  if (val < m) then
    Exit(m);
  m := Self.Maximum;
  if (val > m) then
    Exit(m);
  Result := val;
end;

{==============================================================================]
  <Snap>
  @action: Constrains an external range to the boundaries of the current range.
  @note: Snaps both the Start and Stop points of the input range. Useful for
         ensuring a "Selection Range" stays within a "Buffer Range."
[==============================================================================}
function TRange.Snap(const vals: TRange): TRange; overload;
begin
  Result.start := Self.Snap(vals.start);
  Result.stop := Self.Snap(vals.stop);
end; 

{==============================================================================]
  <Wrap>
  @action: Wraps a value into the bounds of the range using modular arithmetic.
  @note: 
    - Maps val into the interval [Minimum, Maximum) of the range.
    - Handles values outside the range by wrapping around cyclically.
    - Negative values are correctly wrapped into the range.
    - If the range has zero width, Minimum is returned.
[==============================================================================}
function TRange.Wrap(const val: Integer): Integer; overload;
var
  m, w, r: Integer;
begin
  m := Self.Minimum;
  w := Abs(Self.stop - Self.start);
  if (w = 0) then
    Exit(m);
  r := ((val - m) mod w);
  if (r < 0) then
    r := (r + w);
  Result := (m + r);
end;
{$ENDIF}
