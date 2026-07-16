{$IFDEF METHODS}
function Average: TPoint; overload;
function Center: TPoint; overload;
function Central: TPoint; overload;
function Centre: TPoint; overload;
function Centroid: TPoint; overload;
function Core: TPoint; overload;
function Mean: TPoint; overload;
function Medium: TPoint; overload;
function Mid: TPoint; overload;
function Middle: TPoint; overload;
function MiddlePoint: TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Average>
  @action: Returns the midpoint of the box using a zero-based (Blanco) frame.
  @note: The box is first translated so that its top-left corner lies at (0,0)
         via the `Blanco` method. The midpoint is then computed as half the
         width and height of this normalized box, and translated back to the
         box’s original coordinate space. Results use integer division, so
         fractional centers are truncated toward zero.
[==============================================================================}
function TBox.Average: TPoint; overload;
var
  B: TBox;
begin
  B := Self.Blanco;
  Result := Point((Self.X1 + (B.X2 div 2)), (Self.Y1 + (B.Y2 div 2)));
end;

{==============================================================================]
  <Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBox.Center: TPoint; overload;
begin
  Result.X := Round(Self.X1 + ((Self.Width - 1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Height - 1) div 2));
end;

{==============================================================================]
  <Central>
  @action: Returns the center point of the box after normalizing its bounds.
  @note: The box coordinates are internally ordered using Min/Max before
         computing the midpoint. This makes the result independent of
         coordinate direction. Integer division is used; results are
         truncated toward zero.
[==============================================================================}
function TBox.Central: TPoint; overload;
begin
  Result.X := ((Min(Self.X1, Self.X2) + Max(Self.X1, Self.X2)) div 2);
  Result.Y := ((Min(Self.Y1, Self.Y2) + Max(Self.Y1, Self.Y2)) div 2);
end;

{==============================================================================]
  <Centre>
  @action: Returns the arithmetic midpoint of the box corners using widened
           integer arithmetic.
  @note: The midpoint is computed as (X1 + X2) div 2 using Int64 to prevent
         overflow. Integer division truncates toward zero. The result is
         symmetric but may be biased for even extents.
[==============================================================================}
function TBox.Centre: TPoint; overload;
begin
  Result := Point(((Int64(Self.X1) + Self.X2) div 2), ((Int64(Self.Y1) + Self.Y2) div 2));
end;

{==============================================================================]
  <Centroid>
  @action: Returns the geometric centroid of the box.
  @note: The centroid is computed using floating-point arithmetic and rounded
         to the nearest integer. This yields the least biased integer
         approximation of the true geometric center.
[==============================================================================}
function TBox.Centroid: TPoint; overload;
begin
  Result := Point(Round((Self.X1 + Self.X2) * 0.5), Round((Self.Y1 + Self.Y2) * 0.5));
end;

{==============================================================================]
  <Core>
  @action: Returns exact center using floating point with banker's rounding
  @note: Uses Round() which implements banker's rounding (ties to nearest even).
[==============================================================================}
function TBox.Core: TPoint; overload;
begin
  Result := Point(Round((Self.X1 + Self.X2) / 2), Round((Self.Y1 + Self.Y2) / 2));
end;

{==============================================================================]
  <Mean>
  @action: Returns the arithmetic mean of the box corner coordinates.
  @note: The mean is computed using integer division and truncates toward
         zero. This function does not normalize bounds and performs no
         rounding correction.
[==============================================================================}
function TBox.Mean: TPoint; overload;
begin
  Result := Point(((Self.X1 + Self.X2) div 2), ((Self.Y1 + Self.Y2) div 2));
end;

{==============================================================================]
  <Medium>
  @action: Returns the rounded midpoint of the box corner coordinates.
  @note: This function performs integer midpoint rounding upward for odd
         coordinate sums, producing a bias toward higher indices. No floating
         point arithmetic is used.
[==============================================================================}
function TBox.Medium: TPoint; overload;
begin
  Result.X := ((Self.X1 + Self.X2 + Ord(((Self.X1 + Self.X2) mod 2) <> 0)) div 2);
  Result.Y := ((Self.Y1 + Self.Y2 + Ord(((Self.Y1 + Self.Y2) mod 2) <> 0)) div 2);
end;

{==============================================================================]
  <Mid>
  @action: Returns the midpoint based on the box width and height.
  @note: The midpoint is computed from the top-left corner using half the
         width and height. Bit-shift division is used and assumes non-negative
         extents. The result lies within the box.
[==============================================================================}
function TBox.Mid: TPoint; overload;
begin
  Result := Point((Self.X1 + (Self.Width shr 1)), (Self.Y1 + (Self.Height shr 1)));
end;

{==============================================================================]
  <Middle>
  @action: Returns the discrete middle cell of the box.
  @note: The middle is computed using integer division of the box extents and
         is biased toward the top-left for even sizes. The result always lies
         within the box.
[==============================================================================}
function TBox.Middle: TPoint; overload;
begin
  Result := Point((Self.X1 + ((Self.X2 - Self.X1) div 2)), (Self.Y1 + ((Self.Y2 - Self.Y1) div 2)));
end;

{==============================================================================]
  <MiddlePoint>
  @action: Returns the discrete midpoint of the box using bit-shift division.
  @note: Equivalent to Middle but uses bit-shift arithmetic. This assumes
         non-negative extents and produces identical results to division-based
         midpoint calculations.
[==============================================================================}
function TBox.MiddlePoint: TPoint; overload;
begin
  Result := Point((Self.X1 + ((Self.X2 - Self.X1) shr 1)), (Self.Y1 + ((Self.Y2 - Self.Y1) shr 1)));
end;
{$ENDIF}
