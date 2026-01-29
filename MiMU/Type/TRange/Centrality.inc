{$IFDEF METHODS}
function AMean: Double;
function Amid: Integer;
function Average: Double;
function Bisect: Integer;
function Center: Integer;
function Centerpoint: Integer;
function Central: Integer;
function Centre: Integer; overload;
function Centroid: Integer; overload;
function Core: Integer; overload;
function Half: Integer; overload;
function Halfstep: Integer; overload;
function Halfway: Integer; overload;
function Halved: Integer; overload;
function Kernel: Integer;
function Mean: Double; overload;
function Median: Double;
function Medium: Double; overload;
function Medoid: Integer;
function Mid: Double;
function MidBit: Integer; overload;
function Middle: Integer;
function MiddleBit: Integer; overload;
function MiddleLeft: Integer; overload;
function MiddleRight: Integer; overload;
function MiddleStep: Integer; overload;
function MiddleVal: Integer; overload;
function MiddleValue: Double;
function Middleway: Integer;
function Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
function MidVal: Double;
function MidValue: Double;
function Nexus: Integer;
function Pivot: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <AMean>
 @action: Returns the arithmetic mean of the range bounds.
          The arithmetic mean is calculated as (Start + Stop) / 2 using floating-point
          arithmetic and represents the central value between the two bounds.
 @note:
   - No normalization is performed; Start and Stop are used as-is.
   - The result may be non-integer even when Start and Stop are integers.
   - For a singular range (Start = Stop), the result equals Start.
   - This method computes the arithmetic mean of the bounds, not the midpoint
     of discrete elements within the range.
[==============================================================================}
function TRange.AMean: Double;
begin
  Result := Math.Mean([Double(Self.start), Double(Self.stop)]);
end;

{==============================================================================]
 <Amid>
 @action: Returns the anchor point of the range.
          The anchor is defined as the upper midpoint of the range and is calculated
          as (Start + Stop + 1) div 2. This biases the result toward the upper bound
          when the range has an even number of elements.
  @note:
   - No normalization is performed; Start and Stop are used as-is.
   - For a singular range (Start = Stop), the anchor equals Start.
   - The result is always within the inclusive range Start .. Stop.
[==============================================================================}
function TRange.Amid: Integer;
begin
  Result := ((Self.start + Self.stop + 1) div 2);
end;

{==============================================================================]
 <Average>
 @action: Average value from TRange.
 @note: None
[==============================================================================}
function TRange.Average: Double;
var
  c: Int64;
begin
  c := Self.Size;
  Result := ((c * (Self.start + Self.stop) div 2) / c);
end;

{==============================================================================]
 <Bisect>
 @action: Returns the lower median index of the range using integer-only arithmetic.
 @note: The result is order-independent and always lies within the range bounds.
        For ranges with an even number of elements, the lower of the two central
        values is returned. Equivalent to: Min(start, stop) + ((Size - 1) div 2)
        This method avoids floating-point arithmetic and is safe for all integer
        ranges.
[==============================================================================}
function TRange.Bisect: Integer;
begin
  Result := (Min(Self.start, Self.stop) + ((Self.Size - 1) shr 1));
end;

{==============================================================================]
  <Center>
  @action: The value(s) at the center position(s) of given range.
  @note: None
[==============================================================================}
function TRange.Center: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
  <Centerpoint>
  @action: Returns the integer midpoint between Start and Stop using an overflow-safe
           calculation.
           The center point is computed using a bitwise formulation equivalent to:
           Start + (Stop − Start) div 2 - but without risk of integer overflow.
 @note
   - This method avoids overflow that may occur when summing large integers.
   - Integer division truncates toward zero, biasing the result toward Start.
   - No normalization is performed; Start and Stop are used as-is.
   - For a singular range (Start = Stop), the result equals Start.
   - The result lies between Start and Stop (inclusive) for both ascending and
     descending ranges.
[==============================================================================}
function TRange.Centerpoint: Integer;
begin
  Result := ((Self.start and Self.stop) + ((Self.start xor Self.stop) div 2));
end;

{==============================================================================]
 <Central>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Central: Integer;
begin
  Result := ((Self.start + self.stop) shr 1);
end;

{==============================================================================]
 <Centre>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Centre: Integer; overload;
begin
  Result := (Min(Self.start, Self.stop) + (Abs(Self.stop - Self.start) div 2));
end;

{==============================================================================]
 <Centroid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Centroid: Integer; overload;
begin
  Result := (((Self.start div 2) + (Self.stop div 2)) + (((Self.start mod 2) + (Self.stop mod 2)) div 2));
end;

{==============================================================================]
 <Core>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Core: Integer; overload;
begin
  Result := (Self.stop - Self.start);
  Result := (Result - (Result and 1));
  Result := (Self.start + (Result div 2));
end;

{==============================================================================]
  <Half>
  @action: Returns the arithmetic midpoint of the range using truncation toward zero.
  @note: Equivalent to Trunc((start + stop) / 2).
         For positive ranges this behaves like Floor; for negative ranges it behaves
         like Ceil. Use only when truncation semantics are explicitly desired.
[==============================================================================}
function TRange.Half: Integer; overload;
begin
  Result := Trunc((Self.start + Self.stop) / 2);
end;

{==============================================================================]
  <Halfstep>
  @action: Returns the arithmetic midpoint of the range, rounded down.
  @note: Equivalent to Floor((start + stop) / 2).
         Always rounds toward negative infinity. This is the lower of the two central
         values when the midpoint lies between integers.
[==============================================================================}
function TRange.Halfstep: Integer; overload;
begin
  Result := Floor((Self.start + Self.stop) / 2);
end;

{==============================================================================]
  <Halfway>
  @action: Returns the arithmetic midpoint of the range using banker's rounding.
  @note: Equivalent to Round((start + stop) / 2).
         Uses the RTL rounding mode (round-to-nearest, ties to even).
         May round up or down depending on parity when the fractional part is exactly 0.5.
[==============================================================================}
function TRange.Halfway: Integer; overload;
begin
  Result := Round((Self.start + Self.stop) / 2);
end;

{==============================================================================]
  <Halved>
  @action: Returns the arithmetic midpoint of the range, rounded up.
  @note: Equivalent to Ceil((start + stop) / 2).
         Always rounds toward positive infinity. This is the upper of the two central
         values when the midpoint lies between integers.
[==============================================================================}
function TRange.Halved: Integer; overload;
begin
  Result := Ceil((Self.start + Self.stop) / 2);
end;

{==============================================================================]
  <Kernel>
  @action: Returns the midpoint of the range, biased toward the start value.
  @note: The result is computed using integer-only arithmetic and preserves the
         direction of the range. For ranges where start < stop, the midpoint is
         rounded down; for ranges where start > stop, the midpoint is rounded up.
         This makes the result stable with respect to the start endpoint and suitable
         for iterative bisection algorithms that advance from start toward stop.
         Equivalent to: start + Sign(stop - start) * (Abs(stop - start) div 2)
[==============================================================================}
function TRange.Kernel: Integer;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := (Self.start + (Sign(d) * (Abs(d) div 2)));
end;

{==============================================================================]
 <Mean>
 @action: Returns the arithmetic mean (midpoint) of the range's Start and Stop values as a Double.
 @note: Uses floating-point division to avoid integer truncation and to handle large integer values safely.
[==============================================================================}
function TRange.Mean: Double; overload;
begin
  Result := ((Self.start / 2.0) + (Self.stop / 2.0));
end;

{==============================================================================]
 <Median>
 @action: Returns the discrete median of the range as a floating-point value.
 @note: This is a non-mutating operation. The median is calculated over the
        set of integers represented by the range, including both endpoints.
        - For odd-sized ranges, it returns the middle element.
        - For even-sized ranges, it returns the average of the two central
          elements.
        The function respects the direction of the range (ascending or
        descending) and produces the same numeric result regardless of
        order.
[==============================================================================}
function TRange.Median: Double;
var
  M, D, S: Integer;
begin
  D := IfThen(Self.Descending, -1, 1);
  S := Self.Size;
  M := (S div 2);
  if S.Odd then
    Result := (Self.start + D * M)
  else
    Result := (((Self.start + D * (M - 1)) + (Self.start + D * M)) / 2.0);
end;

{==============================================================================]
 <Medium>
 @action: Returns the arithmetic mean of the range bounds as a floating-point value.
 @note: This represents a mathematical midpoint only. The result may be fractional.
[==============================================================================}
function TRange.Medium: Double; overload;
begin
  Result := ((Self.start + Self.stop) * 0.5);
end;

{==============================================================================]
  <Medoid>
  @action: Returns the direction-aware integer center of the range.
           The medoid is computed as the start value offset by half the absolute
           range length, using integer division. The offset is added for ascending
           ranges and subtracted for descending ranges.
  @note
    - The result is always reachable from Start by moving halfway toward Stop
      using integer steps.
    - Integer division truncates toward zero, biasing the result toward Start
      for ranges of odd length.
    - For a singular range (Start = Stop), the result equals Start.
[==============================================================================}
function TRange.Medoid: Integer;
begin
  if Self.Descending then
    Result := (Self.start - (Abs(Self.start - Self.stop) div 2))
  else
    Result := (Self.start + (Abs(Self.start - Self.stop) div 2));
end;

{==============================================================================]
 <Mid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Mid: Double;
begin
  Result := ((Self.start + Self.stop) / 2.0);
end;

{==============================================================================]
 <MidBit>
 @action: Returns the integer midpoint of the range using a bitwise shift (shr 1) for division by 2.
 @note: Safe for both ascending and descending ranges. This is a floor-biased midpoint,
        equivalent to MiddleLeft, but implemented with a bit shift for efficiency.
[==============================================================================}
function TRange.MidBit: Integer; overload;
begin
  if (Self.start <= Self.stop) then
    Exit(Self.start + ((Self.stop - Self.start) shr 1));
  Result := TRange.Construct(Self.stop, Self.start).MidBit;
end;

{==============================================================================]
 <Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Middle: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
 <MiddleBit>
 @action: Returns the integer midpoint of the range using a bitwise shift for division by 2.
 @note: Safe for ascending and descending ranges. Equivalent to a floor-biased midpoint
        but uses low-level arithmetic for efficiency.
[==============================================================================}
function TRange.MiddleBit: Integer; overload;
begin
  if (Self.start <= Self.stop) then
    Result := (Self.start + ((Self.stop - Self.start) shr 1))
  else
    Result := (Self.start - ((Self.start - Self.stop) shr 1));
end;

{==============================================================================]
 <MiddleLeft>
 @action: Returns the integer midpoint of the range, biased toward the lower index.
 @note: Uses floor division. This is the classic binary search midpoint and is safe
        for single-element, ascending, and descending ranges.
[==============================================================================}
function TRange.MiddleLeft: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self.stop + (Self.start - Self.stop) div 2);
  Result := (Self.start + (Self.stop - Self.start) div 2);
end;

{==============================================================================]
 <MiddleRight>
 @action: Returns the integer midpoint of the range, biased toward the higher index.
 @note: Uses ceiling division. Suitable for binary search variants that advance the
        lower bound and require guaranteed progress on even-length ranges. Supports
        both ascending and descending ranges.
[==============================================================================}
function TRange.MiddleRight: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self.stop + ((Self.start - Self.stop) + 1) div 2);
  Result := (Self.start + ((Self.stop - Self.start) + 1) div 2);
end;

{==============================================================================]
 <MiddleStep>
 @action: Returns the integer midpoint of the range, calculated by stepping halfway
          from start to stop. Works for both ascending and descending ranges.
 @note: Neutral midpoint, unbiased toward lower or higher indices.
[==============================================================================}
function TRange.MiddleStep: Integer; overload;
begin
  if (Self.stop > Self.start) then
    Result := (Self.start + (Abs(Self.stop - Self.start) div 2))
  else
    Result := (Self.start - (Abs(Self.stop - Self.start) div 2));
end;

{==============================================================================]
 <MiddleValue>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MiddleValue: Double;
begin
  if (Self.start <= Self.stop) then
    Result := (Self.start + ((Self.stop - Self.start) / 2))
  else
    Result := (Self.stop + ((Self.start - Self.stop) / 2));
end;

{==============================================================================]
 <MiddleVal>
 @action: Middle value alternative
 @note: None
[==============================================================================}
function TRange.MiddleVal: Integer; overload;
begin
  Result := ((Int64(Self.start) + Int64(Self.stop)) div 2);
end;

{==============================================================================]
 <Middleway>
 @action: Returns the rounded midpoint of the range.
          The midpoint is calculated as: Start + ((Stop − Start) * 0.5)
          and rounded to the nearest integer using standard rounding rules.
  @note:
   - No normalization is performed; Start and Stop are used as-is.
   - Rounding may bias the result upward or downward depending on the fractional
     component and the active rounding mode.
   - For a singular range (Start = Stop), the result equals Start.
[==============================================================================}
function TRange.Middleway: Integer;
begin
  Result := Round(Self.start + ((Self.stop - Self.start) * 0.5));
end;

{==============================================================================]
 <Midpoint>
  @action: Computes the weighted midpoint (center) of the range using given weights.
  @note: Returns a Double. Weighted midpoint formula: ((Start * wStart) + (Stop * wStop)) / (wStart + wStop).
         Useful when one bound of the range has more importance than the other.
[==============================================================================}
function TRange.Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
begin
  Result := (((Self.start * wStart) + (Self.stop * wStop)) / (wStart + wStop));
end;

{==============================================================================]
 <MidVal>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MidVal: Double;
var
  s: Integer;
begin
  s := (Self.Highest + Self.Lowest);
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
  <MidValue>
  @action: The value(s) at the center position(s) of given range.
  @note: None
[==============================================================================}
function TRange.MidValue: Double;
var
  s: Integer;
begin
  s := (Self.start + Self.stop);
  Result := (s div 2);
  if ((s mod 2) <> 0) then
    Result := (Result + 0.5);
end;

{==============================================================================]
  <Nexus>
  @action: Returns the arithmetic midpoint of the range using overflow-safe integer
           arithmetic.
  @note: Computes the midpoint of start and stop without risk of signed integer
         overflow. The calculation is order-independent and equivalent to
         Floor((start + stop) / 2)
         for all integer values within the Integer domain.
         The implementation uses a bitwise averaging algorithm with an offset to
         preserve correct signed behavior.
         This method should be preferred when start and stop may approach the
         integer limits.
[==============================================================================}
function TRange.Nexus: Integer;
var
  o: Integer;
  l, h: Int64;
begin
  o := High(Integer);
  l := (Int64(Self.start) + o);
  h := (Int64(Self.stop) + o);
  Result := Integer(((l and h) + (l xor h) shr 1) - o);
end;

{==============================================================================]
  <Pivot>
  @action: The value(s) at the center position(s) of given range.
  @note: None
[==============================================================================}
function TRange.Pivot: Integer;
begin
  if Self.Ascending then
    Result := (Self.start + ((Self.stop - Self.start) div 2))
  else
    Result := (Self.stop + ((Self.start - Self.stop) div 2));
end; 
{$ENDIF}
