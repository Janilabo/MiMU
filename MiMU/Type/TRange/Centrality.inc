{$IFDEF TYPES}
function Pivot: Integer; 
function Mean: Double; overload;
function Medium: Double; overload;
function MiddleRight: Integer; overload;
function MiddleLeft: Integer; overload;
function Middle: Integer;
function MiddleValue: Double;
function MiddleVal: Integer; overload;
function MiddleStep: Integer; overload;
function MiddleBit: Integer; overload;
function MidBit: Integer; overload;
function Mid: Double; 
function MidValue: Double; 
function MidVal: Double; 
function Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
function Average: Double; 
function Center: Integer; 
function Central: Integer; inline;
function Centre: Integer; overload;
function Centroid: Integer; overload;
function Core: Integer; overload;
function Half: Integer; overload; 
function Halfway: Integer; overload; 
function Halved: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
 <Medium>
 @action: Returns the arithmetic mean of the range bounds as a floating-point value.
 @note: This represents a mathematical midpoint only. The result may be fractional.
[==============================================================================}
function TRange.Medium: Double; overload;
begin
  Result := ((Self.start + Self.stop) * 0.5);
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
 <Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Middle: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
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
 <Mid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Mid: Double;
begin
  Result := ((Self.start + Self.stop) / 2.0);
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
 <Center>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Center: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
 <Central>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Central: Integer; inline;
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
  Result := ((Min(Self.start, Self.stop)) + (Abs(Self.start - Self.stop) div 2));
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
  @action: Returns half the length of the range as an integer, calculated as the
           absolute difference between Stop and Start divided by two.
  @note:   Direction-agnostic; works for both ascending and descending ranges.
           Useful for offset calculations, contraction, or expansion operations.
[==============================================================================}
function TRange.Half: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) div 2);
end;

{==============================================================================]
  <Halfway>
  @action: Returns half the distance between Start and Stop, explicitly handling
           ascending and descending ranges.
  @note:   Functionally identical to Half; uses conditional logic instead of Abs().
           Can be used interchangeably where explicit branch logic is preferred.
[==============================================================================}
function TRange.Halfway: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) div 2)
  else
    Result := ((Self.stop - Self.start) div 2);
end;

{==============================================================================]
  <Halved>
  @action: Returns half the distance between Start and Stop, explicitly handling
           ascending and descending ranges.
  @note:   EnsureRange-based.
[==============================================================================}
function TRange.Halved: Integer; overload;
begin
  Result := EnsureRange((Abs(Self.stop - Self.start) div 2), 0, High(Integer));
end;
{$ENDIF}