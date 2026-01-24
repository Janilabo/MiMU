{$IFDEF METHODS}
function Aggregate(var items: TIntegerArray): Int64;
function Aggregated(var items: TIntegerArray): Int64;
function Area: Integer;
function Capacity: Integer;
function Cardinality: Integer;
function Count: Integer;
function Coverage: Integer; overload;
function Deficit: Integer;
function Delta: Integer;
function Diameter: Integer; overload;
function Diff: Integer;
function Difference: Integer;
function Dist: Integer;
function Extent: Integer; overload;
function Footprint: Integer;
function GetLength: Integer;
function GetSize: Integer;
function InclusiveSize: Integer;
function Len: Integer;
function Length: Integer; overload;
function Magnitude: Integer;
function Mass: Integer;
function Measure: Integer;
function Measured: Int64;
function Population: Integer; overload;
function Quantified: Int64;
function Quantify: Integer;
function Quantity: Integer;
function Rad: Integer; overload;
function Radiar: Integer; overload;
function Radius: Integer; overload;
function Reach: Integer; overload;
function Span: Integer;
function Sigma: Int64;
function Signed: Int64;
function Size: Integer; overload;
function Size(var minVal, maxVal: Integer): Integer; overload;
function Sized: Integer; overload;
function Spread: Integer;
function Stretch: Integer;
function Sum: Int64;
function Summa: Int64;
function Summation: Int64;
function Tally: Integer;
function Total: Int64;
function Volume: Integer;
function Width: Integer;
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
function TRange.Aggregate(var items: TIntegerArray): Int64;
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
function TRange.Aggregated(var items: TIntegerArray): Int64;
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
  <Area>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Area: Integer;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <Cardinality>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Cardinality: Integer;
  function C(const A, B: Integer): Integer;
  begin
    if (A > B) then
	  Exit(A - B);
    Result := (B - A);
  end;
begin
  if (Self.Start = Self.stop) then
    Result := 1
  else
    Result := (C(Self.start, Self.stop) + 1);
end;

{==============================================================================]
  <Count>
  @action: Returns count values in the given range.
  @note: None.
[==============================================================================}
function TRange.Count: Integer;
begin
  Result := ((Max(Self.start, Self.stop) - Min(Self.start, Self.stop)) + 1);
end;

{==============================================================================]
  <Coverage>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Coverage: Integer; overload;
begin
  case Self.start.Compare(Self.stop) of
    0: Result := 1;
	-1: Result := ((Self.stop - Self.start) + 1);
	1: Result := ((Self.start - Self.stop) + 1);
  end;
end;

{==============================================================================]
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
end;

{==============================================================================]
  <Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer;
begin
  Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <Diameter>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Diameter: Integer; overload;
begin
  Result := ((Self.stop - Self.start) + 1);
  if (Self.stop < Self.start) then
    Result := (-Result + 2);
end;

{==============================================================================]
  <Diff>
  @action: Returns the absolute difference (magnitude) between start and stop,
           ignoring the direction of the range.
  @note: The result is always non-negative. Equivalent to Abs(stop - start).
         Does not include endpoints; useful when only the gap between values matters.
[==============================================================================}
function TRange.Diff: Integer;
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
function TRange.Difference: Integer;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Dist>
  @action: Returns the distance between the start and stop values of the range.
           Uses a compact conditional expression to handle descending ranges.
  @note: Same as Distance but written using IfThen for brevity. Still exclusive
         of endpoints and sensitive to the Descending flag.
[==============================================================================}
function TRange.Dist: Integer;
begin
  Result := IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start));
end;

{==============================================================================]
  <Extent>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Extent: Integer; overload;
begin
  Result := Succ(Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Footprint>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Explicitly branches on the sign of (stop - start) to derive the
         absolute distance, then adds one for inclusivity. This is the
         most direct and readable formulation.
[==============================================================================}
function TRange.Footprint: Integer;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  if (d >= 0) then
    Result := (d + 1)
  else
    Result := (-d + 1);
end;

{==============================================================================]
  <GetLength>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.GetLength: Integer;
var
  d: Integer;
begin
  if (Self.start = Self.stop) then
    Exit(1);
  if (Self.start <= Self.stop) then
    d := (Self.stop - Self.start)
  else
    d := (Self.start - Self.stop);
  Result := (((d xor (d shr 31)) - (d shr 31)) + 1);
end;

{==============================================================================]
  <GetSize>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.GetSize: Integer;
var
  c: Integer;
begin
  if (Self.start < Self.stop) then
    c := -1
  else if (Self.start > Self.stop) then
    c := 1
  else
    c := 0;
  case c of
     0: Result := 1;
     -1: Result := ((Self.stop - Self.start) + 1);
     1: Result := ((Self.start - Self.stop) + 1);
  end;
end;

{==============================================================================]
  <InclusiveSize>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.InclusiveSize: Integer;
  function D(const a, b: Integer): Integer;
  begin
    Result := ((Max(a, b) - Min(a, b)) + 1);
  end;
begin
  Result := D(Self.start, Self.stop);
end;


{==============================================================================]
  <Len>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Len: Integer;
begin
  Result := (((Self.stop - Self.start) * IfThen((Self.start <= Self.stop), 1, -1)) + 1);
end;

{==============================================================================]
  <Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Length: Integer; overload;
begin
  if (Self.start = Self.stop) then
    Result := 1
  else if (Self.stop < Self.start) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Magnitude>
  @action: Returns the magnitude (non-negative size) of the range, ignoring orientation.
  @note: Computed as the absolute value of Delta (Abs(Stop - Start)).
         Always ≥ 0, regardless of whether the range is ascending or descending.
[==============================================================================}
function TRange.Magnitude: Integer;
begin
  Result := Abs(Self.Delta);
end;

{==============================================================================]
  <Mass>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Uses Ord(...) as numeric selectors to choose the correct
         directional delta without branching. Produces the absolute
         difference plus one in a compact arithmetic form.
[==============================================================================}
function TRange.Mass: Integer;
begin
  Result := (1 + ((Ord(Self.stop > Self.start) * (Self.stop - Self.start)) + (Ord(Self.start > Self.stop) * (Self.start - Self.stop))));
end;

{==============================================================================]
  <Measure>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Normalizes direction by dividing the delta by its sign, ensuring
         a positive magnitude before adding one. Uses integer arithmetic
         and Sign to avoid conditional branching.
[==============================================================================}
function TRange.Measure: Integer;
begin
  Result := (Abs((Self.stop - Self.start) div Sign(Self.stop - Self.start + 1)) + 1);
end;

{==============================================================================]
  <Measured>
  @action: Returns the inclusive length of the range defined by Start and Stop.
  @note: The result is always non-negative and includes both endpoints.
         For example, Start = 5 and Stop = 5 yields 1.
         Uses Int64 arithmetic to avoid overflow on wide ranges.
[==============================================================================}
function TRange.Measured: Int64;
begin
  Result := (Abs(Int64(Self.stop) - Int64(Self.start)) + 1);
end;

{==============================================================================]
  <Population>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Population: Integer; overload;
begin
  Result := ((Self.MinMax.stop - Self.MinMax.start) + 1);
end;

{==============================================================================]
  <Quantified>
  @action: Returns the inclusive size of the range as a 64-bit integer.
           Works correctly for both ascending and descending ranges.
  @note: Computes the absolute difference between Stop and Start using
         branchless arithmetic to avoid conditional statements.
         The result is always non-negative and includes both endpoints.
         Uses Int64 arithmetic to safely handle very large ranges.
[==============================================================================}
function TRange.Quantified: Int64;
var
  d, m: Int64;
begin
  d := (Int64(Self.stop) - Int64(Self.start));
  if (d < 0) then
    d := -d;
  m := (d shr 63);
  Result := (((d xor m) - m) + 1);
end;  

{==============================================================================]
  <Quantify>
  @action: Returns the inclusive size of the range defined by Start and Stop.
  @note: This is an Integer-optimized variant that computes the absolute
         difference using bitwise arithmetic instead of Abs().
         The result is always non-negative and includes both endpoints.
         Assumes Start and Stop fit within 32-bit signed integer range.
[==============================================================================}
function TRange.Quantify: Integer;
var
  d, m: Integer;
begin
  d := (Self.stop - Self.start);
  if (d < 0) then
    d := -d;
  m := (d shr 31);
  Result := (((d xor m) - m) + 1);
end;

{==============================================================================]
  <Quantity>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Quantity: Integer;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := ((d * Sign(d)) + 1);
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
  <Reach>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Reach: Integer; overload;
begin
  Result := (Self.stop - Self.start);
  if (Result < 0) then
    Result := -Result;
  Result := (Result + 1);
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
function TRange.Sigma: Int64;
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
function TRange.Signed: Int64;
begin
  Result := (Int64(Self.stop) - Int64(Self.start));
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size(var minVal, maxVal: Integer): Integer; overload;
begin
  minVal := Min(Self.start, Self.stop);
  maxVal := Max(Self.start, Self.stop);
  Result := ((maxVal - minVal) + 1);
end;

{==============================================================================]
  <Sized>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Sized: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) + 1);
end;

{==============================================================================]
  <Span>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Span: Integer;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Spread>
  @action: Returns the inclusive size of the range defined by Start and Stop.
  @note: Uses arithmetic manipulation to derive the absolute difference
         without calling Abs() or using conditional branches.
         The result is always non-negative and includes both endpoints.
         Operates entirely on 32-bit Integer arithmetic.
[==============================================================================}
function TRange.Spread: Integer;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := (d + (d shr 31) * (-d shl 1) + 1);
end;

{==============================================================================]
  <Stretch>
  @action: Returns the inclusive size of the range defined by Start and Stop.
  @note: Computes the range length by explicitly selecting the positive
         difference using boolean-to-integer conversion via Bitify().
         Avoids branching while remaining semantically explicit.
         The result is always non-negative and includes both endpoints.
[==============================================================================}
function TRange.Stretch: Integer;
begin
  Result := ((((Self.start - Self.stop) * Bitify(Self.start >= Self.stop)) + ((Self.stop - Self.start) * Bitify(Self.stop > Self.start))) + 1);
end;

{==============================================================================]
  <Sum>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Sum: Int64;
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
function TRange.Summa: Int64;
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
function TRange.Summation: Int64;
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
  <Tally>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Converts a comparison result to an integer selector, then applies
         directional arithmetic based on range ordering. Semantically
         equivalent to Mass, with explicit Boolean state.
[==============================================================================}
function TRange.Tally: Integer;
var
  a: Boolean;
begin
  a := (Self.stop >= Self.start);
  Result := (1 + (Integer(a) * (Self.stop - Self.start)) + (Integer(not a) * (Self.start - Self.stop)));
end; 

{==============================================================================]
  <Total>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Total: Int64;
begin
  if Self.Descending then
    Result := (((Int64(Self.start) * (Self.start + 1)) div 2) - ((Int64(Self.stop - 1) * Self.stop) div 2))
  else
    Result := (((Int64(Self.stop) * (Self.stop + 1)) div 2) - ((Int64(Self.start - 1) * Self.start) div 2));
end;

{==============================================================================]
  <Volume>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Calculates the absolute distance between start and stop using
         a squared–square-root round-trip, then adds one to account for
         inclusive bounds. Functionally equivalent to Abs(stop - start) + 1,
         but expressed via arithmetic normalization.
[==============================================================================}
function TRange.Volume: Integer;
begin
  Result := (Round(Sqrt(Sqr(Self.stop - Self.start))) + 1);
end;

{==============================================================================]
  <Width>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Width: Integer;
var
  s: Int64;
begin
  if (Self.start = Self.stop) then
    Exit(1);
  s := (Int64(Self.stop) - Int64(Self.start));
  if (s < 0) then
    s := -s;
  Result := (Integer(s) + 1);
end;
{$ENDIF}
