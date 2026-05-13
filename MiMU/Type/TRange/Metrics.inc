{$IFDEF METHODS}
function Combined: Int64; overload;
function Contra: Integer; overload;
function Deficit: Integer; overload;
function Delta: Integer; overload;
function Diff: Integer; overload;
function Difference: Integer; overload;
function Magnitude: Integer; overload;
function Prod: Int64; overload;
function Product: Int64; overload;
function Quotient(const defaultValue: Integer = 0): Integer; overload;
function Rad: Integer; overload;
function Radiar: Integer; overload;
function Radius: Integer; overload;
function Ratio(const defaultValue: Double = 0.0): Double; overload;
function Signed: Int64; overload;
function Span: Integer; overload;
function Spanitude: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Combined>
  @action: Returns the sum of the range boundaries (start + stop).
  @note: This function does not calculate a minimum, maximum, or midpoint;
         it simply adds start and stop and may overflow if values are large.
[==============================================================================}
function TRange.Combined: Int64; overload;
begin
  Result := (Int64(Self.start) + Self.stop);
end;

{==============================================================================]
  <Contra>
  @action: Returns the negative delta of the range (start - stop). 
           Equivalent to -Delta; reflects the range in the opposite direction.
  @note: The sign indicates the inverse orientation from start to stop.
[==============================================================================}
function TRange.Contra: Integer; overload;
begin
  Result := (Self.start - Self.stop);
end;

{==============================================================================]
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer; overload;
begin
  Result := (Self.Minimum - Self.Maximum);
end;

{==============================================================================]
  <Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer; overload;
begin
  Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <Diff>
  @action: Returns the absolute difference (magnitude) between start and stop,
           ignoring the direction of the range.
  @note: The result is always non-negative. Equivalent to Abs(stop - start).
         Does not include endpoints; useful when only the gap between values matters.
[==============================================================================}
function TRange.Diff: Integer; overload;
begin
  Result := (Self.Maximum - Self.Minimum);
end;

{==============================================================================]
  <Difference>
  @action: Returns the absolute difference between the start and stop values,
           ignoring the direction of the range.
  @note: Diff is always non-negative and exclusive of endpoints. Use this if
         you only care about the magnitude of the gap, not whether the range
         is ascending or descending.
[==============================================================================}
function TRange.Difference: Integer; overload;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Magnitude>
  @action: Returns the magnitude (non-negative size) of the range, ignoring orientation.
  @note: Computed as the absolute value of Delta (Abs(Stop - Start)).
         Always ≥ 0, regardless of whether the range is ascending or descending.
[==============================================================================}
function TRange.Magnitude: Integer; overload;
begin
  Result := Abs(Self.Delta);
end;

{==============================================================================]
  <Prod>
  @action: Returns the product of all integers in the range (Π)
  @note: Can overflow very quickly! Use with caution on large ranges.
         Returns 1 for empty ranges. Returns 0 if range contains 0.
  @examples:
    TRange.Create(1, 5).Product  → 120 (1×2×3×4×5)
    TRange.Create(3, 6).Product  → 360 (3×4×5×6)
    TRange.Create(1, 0).Product  → 1 (empty range)
[==============================================================================}
function TRange.Prod: Int64; overload;
var
  i: Integer;
begin
  Result := 1;
  for i := Self.Minimum to Self.Maximum do
    Result := (Result * i);
end;

{==============================================================================]
  <Product>
  @action: Returns the product of all integer values contained in the range.
  @note: The range is treated as inclusive and is evaluated from the smaller
         endpoint to the larger, regardless of direction. If the range spans
         zero, the result is immediately zero. The product is accumulated
         using Int64 and no overflow detection is performed.
[==============================================================================}
function TRange.Product: Int64; overload;
var
  i, l, h: Integer;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  if ((l <= 0) and (h >= 0)) then
    Exit(0);
  Result := 1;
  for i := l to h do
    Result := (Result * i);
end;

{==============================================================================]
  <Quotient>
  @action: Returns the integer quotient of the range start divided by the stop.
  @note: The result is calculated using integer division (start div stop),
         truncating toward zero. If stop is zero, the specified defaultValue
         is returned to avoid division-by-zero. No validation or normalization
         of the range endpoints is performed.
[==============================================================================}
function TRange.Quotient(const defaultValue: Integer = 0): Integer; overload;
begin
  if (Self.stop = 0) then
    Result := defaultValue
  else
    Result := (Self.start div Self.stop);
end;

{==============================================================================]
  <Rad>
  @action: Returns the half-length (radius) of the range as an integer value.
  @note: Computed as Abs(Stop - Start) shr 1; equivalent to (|Stop - Start| div 2).
[==============================================================================}
function TRange.Rad: Integer; overload;
begin
  Result := (Self.Difference shr 1);
end;

{==============================================================================]
  <Radiar>
  @action: Returns half the absolute distance between Start and Stop, rounded to the nearest integer.
  @note: Computed as Round(Abs(Stop - Start) * 0.5). Useful when a midpoint-to-edge distance is needed
         and rounding is preferred over truncation. Order of Start and Stop does not matter.
[==============================================================================}
function TRange.Radiar: Integer; overload;
begin
  Result := Round(Self.Difference * 0.5);
end;

{==============================================================================]
  <Radius>
  @action: Returns half the total span (distance) between Start and Stop.
  @note: Equivalent to (RangeLength / 2); independent of which value is greater.
[==============================================================================}
function TRange.Radius: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) div 2);
end;

{==============================================================================]
  <Ratio>
  @action: Returns the ratio of the range start value to the stop value.
  @note: The result is calculated as start / stop using floating-point
         division. If stop is zero, the specified defaultValue is returned
         instead to avoid division-by-zero. The method does not enforce any
         ordering between start and stop and performs no range validation.
[==============================================================================}
function TRange.Ratio(const defaultValue: Double = 0.0): Double; overload;
begin
  if (Self.stop = 0) then
    Result := defaultValue
  else
    Result := (Self.start / Self.stop);
end;

{==============================================================================]
  <Signed>
  @action: Returns the signed difference between Stop and Start as a 64-bit integer.
  @note: The result can be negative if Start > Stop.
         Does not include both endpoints; this is the exclusive difference.
         Uses Int64 arithmetic to safely handle large integer ranges without overflow.
[==============================================================================}
function TRange.Signed: Int64; overload;
begin
  Result := (Int64(Self.stop) - Int64(Self.start));
end;

{==============================================================================]
  <Span>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Span: Integer; overload;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Spanitude>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Spanitude: Integer; overload;
begin
  Result := IfThen(Self.Ascending, (Self.stop - Self.start), (Self.start - Self.stop));
end;
{$ENDIF}
