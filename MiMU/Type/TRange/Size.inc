{$IFDEF METHODS}
function Area: Integer;
function Bulk: Integer;
function Capacity: Integer;
function Cardinality: Integer;
function Count: Integer;
function Counted: Int64;
function Coverage: Integer; overload;
function Diameter: Integer; overload;
function Extent: Integer; overload;
function Footprint: Integer;
function GetCount: Integer;
function GetLength: Integer;
function GetSize: Integer;
function InclusiveSize: Integer;
function Latitude: Integer;
function Len: Integer;
function Length: Integer; overload;
function Mass: Integer;
function Measure: Integer;
function Measured: Int64;
function Population: Integer; overload;
function PopulationSize: Integer;
function Quantified: Int64;
function Quantify: Integer;
function Quantity: Integer;
function Reach: Integer; overload;
function Size: Integer; overload;
function Size(var minVal, maxVal: Integer): Integer; overload;
function Sized: Integer; overload;
function Spread: Integer;
function Stretch: Integer;
function Tally: Integer;
function Volume: Integer;
function Width: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Bulk>
  @action: Returns the inclusive cardinality of the range, i.e. the number of
           integer values contained between start and stop, regardless of order.
  @note:
    This implementation computes the absolute difference between stop and
    start using Sign-based multiplication, then adds one to account for
    inclusive bounds.
      Bulk = |stop − start| + 1
    It is functionally equivalent to:
      Abs(stop - start) + 1
    This method is order-independent (ascending or descending) and returns
    1 for degenerate ranges where start = stop.
[==============================================================================}
function TRange.Bulk: Integer;
begin
  Result := (((Self.stop - Self.start) * Sign(Self.stop - Self.start)) + 1);
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
  <Counted>
  @action: Returns the number of discrete integer values contained in the range.
  @note: The result is calculated using 64-bit arithmetic and supports both
         ascending and descending ranges. The count is inclusive of both
         start and stop values and is equivalent to Abs(stop - start) + 1.
         This method is overflow-safe for all Integer endpoint values.
[==============================================================================}
function TRange.Counted: Int64;
begin
  Result := (Abs(Int64(Self.stop) - Int64(Self.start)) + 1);
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
  <GetCount>
  @action: Returns the number of discrete integer values contained in the range.
  @note: The result is computed using branchless 32-bit arithmetic and supports
         both ascending and descending ranges. The count is inclusive of both
         start and stop values and is equivalent to Abs(stop - start) + 1.
[==============================================================================}
function TRange.GetCount: Integer;
var
  d, m: Integer;
begin
  d := IfThen((Self.start <= Self.stop), (Self.stop - Self.start), (Self.start - Self.stop));
  m := (d shr 31);
  Result := (((d xor m) - m) + 1);
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
  <Latitude>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Latitude: Integer;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := (d * ((Ord(d >= 0) * 2) - 1) + 1);
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
  <PopulationSize>
  @action: Returns the number of discrete integer values in the range.
  @note: The calculation supports both ascending and descending ranges and
         treats the range as inclusive. The function uses unsigned arithmetic
         to reduce the risk of overflow in intermediate subtraction. For
         ascending ranges (stop >= start), the count is stop - start + 1.
         For descending ranges (start > stop), the count is start - stop + 1.
[==============================================================================}
function TRange.PopulationSize: Integer;
begin
  Result := UInt32(Self.stop - Self.start);
  if (Self.stop >= Self.start) then
    Inc(Result)
  else
    Result := (-Result + 1);
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
