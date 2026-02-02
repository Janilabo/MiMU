{$IFDEF METHODS}
function Aggregate(var items: TIntegerArray): Int64; overload;
function Aggregated(var items: TIntegerArray): Int64; overload;
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
function Span: Integer; overload;
function Sigma: Int64; overload;
function Signed: Int64; overload;
function Sum: Int64; overload;
function Summa: Int64; overload;
function Summation: Int64; overload;
function Total: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Aggregate>
  @action: Fills a TIntegerArray with all integer values from this range and
          returns their sum.
  @note: The array is automatically sized to the range length. Supports both
         ascending and descending ranges. The sum is computed incrementally
         while filling the array. Uses Int64 for the result to reduce overflow
         risk. Assumes the range is inclusive and valid (Minimum <= Maximum
         or descending).
[==============================================================================}
function TRange.Aggregate(var items: TIntegerArray): Int64; overload;
var
  l, r, s: Integer;
begin
  l := Self.Size;
  SetLength(items, l);
  items[0] := Self.start;
  Result := Self.start;
  if (Self.start = Self.stop) then
    Exit;
  s := IfThen((Self.start < Self.stop), 1, -1);
  r := 1;
  repeat
    items[r] := (Items[r - 1] + s);
    Result := (Result + items[r]);
  until (r.Increment >= l);
end;

{==============================================================================]
  <Aggregated>
  @action: Fills a TIntegerArray with all values in the range and returns their sum.
  @note: Supports both ascending and descending ranges. The sum is computed
          incrementally while filling the array. The array length is automatically
          set to the range size. Uses Int64 for the sum to reduce overflow risk.
[==============================================================================}
function TRange.Aggregated(var items: TIntegerArray): Int64; overload;
var
  i, l, r, s: Integer;
begin
  l := Self.Size;
  SetLength(items, l);
  Result := 0;
  s := IfThen((Self.Start <= Self.Stop), 1, -1);
  r := 0;
  i := Self.Start;
  while (r < l) do
  begin
    items[r.Increase] := i;
    Result := (Result + i.Increase(s));
  end;
end; 

{==============================================================================]
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer; overload;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
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
  Result := (Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
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
  for i := Min(Self.start, Self.stop) to Max(Self.start, Self.stop) do
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
  l := Min(Self.start, Self.stop);
  h := Max(Self.start, Self.stop);
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
  if Self.stop = 0 then
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
  Result := (Abs(Self.stop - Self.start) shr 1);
end;

{==============================================================================]
  <Radiar>
  @action: Returns half the absolute distance between Start and Stop, rounded to the nearest integer.
  @note: Computed as Round(Abs(Stop - Start) * 0.5). Useful when a midpoint-to-edge distance is needed
         and rounding is preferred over truncation. Order of Start and Stop does not matter.
[==============================================================================}
function TRange.Radiar: Integer; overload;
begin
  Result := Round(Abs(Self.stop - Self.start) * 0.5);
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
  <Sigma>
  @action: Returns the sum of all integer values contained in this range.
  @note: The sum is calculated using the arithmetic series formula:
         Size * (start + stop) / 2. Both start and stop are promoted to
         Int64 to reduce the risk of 32-bit overflow. The division by 2 is
         performed after the multiplication, so extremely large ranges may
         still overflow Int64. This method assumes the range is valid
         (Minimum <= Maximum) and represents an inclusive set of integers.
[==============================================================================}
function TRange.Sigma: Int64; overload;
begin
  Result := ((Int64(Self.Size) * (Int64(Self.start) + Self.stop)) div 2);
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
  <Sum>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Sum: Int64; overload;
var
  a, b: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  Result := ((((b - a) + 1) * (a + b)) div 2);
end;

{==============================================================================]
  <Summa>
  @action: Returns the sum of all integer values contained in this range.
  @note: The sum is computed using the arithmetic series formula:
         Size * (start + stop) / 2. To reduce the risk of 32-bit overflow,
         start, stop, and Size are promoted to Int64. Division is done after
         multiplication when the range size is odd, and before multiplication
         when the size is even, to minimize intermediate value magnitude.
         Extremely large ranges may still overflow Int64. This method assumes
         the range is valid (Minimum <= Maximum) and inclusive.
[==============================================================================}
function TRange.Summa: Int64; overload;
var
  A, B, C: Int64;
begin
  A := Self.start;
  B := Self.stop;
  C := Self.Size;
  if ((C and 1) = 0) then
    Result := ((C div 2) * (A + B))
  else
    Result := (C * ((A + B) div 2));
end;

{==============================================================================]
  <Summation>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Summation: Int64; overload;
var
  a, b, c, s, n: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  n := ((b - a) + 1);
  s := (a + b);
  c := (s div 2);
  Result := (n * c);
  if ((s and 1) = 1) then
    Result := (Result + (n div 2));
end;

{==============================================================================]
  <Total>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Total: Int64; overload;
begin
  if Self.Descending then
    Result := (((Int64(Self.start) * (Self.start + 1)) div 2) - ((Int64(Self.stop - 1) * Self.stop) div 2))
  else
    Result := (((Int64(Self.stop) * (Self.stop + 1)) div 2) - ((Int64(Self.start - 1) * Self.start) div 2));
end;
{$ENDIF}
