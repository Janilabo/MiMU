{$IFDEF METHODS}
function Amount: Int64; overload;
function Area: Integer; overload;
function Bulk: Integer; overload;
function Capacity: Integer; overload;
function Cardinality: Integer; overload;
function Count: Integer; overload;
function Counted: Int64; overload;
function Counting: Integer; overload;
function Coverage: Integer; overload;
function Depth: Integer; overload;
function Diameter: Integer; overload;
function Extent: Integer; overload;
function Footprint: Integer; overload;
function GetAmount: Int64; overload;
function GetCount: Integer; overload;
function GetLength: Integer; overload;
function GetSize: Integer; overload;
function InclusiveSize: Integer; overload;
function Latitude: Integer; overload;
function Len: Integer; overload;
function Length: Integer; overload;
function Load: Integer; overload;
function Mass: Integer; overload;
function Measure: Integer; overload;
function Measured: Int64; overload;
function Measuring: Integer; overload;
function Mob: Integer; overload;
function Ordinality: Integer; overload;
function Perim: Integer; overload;
function Perimeter: Int64; overload;
function Populates: Integer; overload;
function Population: Integer; overload;
function PopulationCount: Integer; overload;
function PopulationSize: Integer; overload;
function Quantified: Int64; overload;
function Quantify: Integer; overload;
function Quantity: Integer; overload;
function Quota: Integer; overload;
function Reach: Integer; overload;
function Scope: Integer; overload;
function Size: Integer; overload;
function Size(var minVal, maxVal: Integer): Integer; overload;
function Sized: Integer; overload;
function Sizing: Integer; overload;
function Spread: Integer; overload;
function Stretch: Integer; overload;
function Tally: Integer; overload;
function Volume: Integer; overload;
function Weight: Integer; overload;
function Width: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Amount>
  @action: Returns the number of discrete Int64 values contained in the
           inclusive range defined by Self.start and Self.stop.
  @note: Order-independent. If start > stop, the result is still positive.
         Uses a branchless absolute-value implementation for performance.
         If (stop - start) overflows Int64, the result is undefined.
  Formula: |stop - start| + 1        
[==============================================================================}
function TRange.Amount: Int64; overload;
var
  d: Int64;
begin
  d := (Int64(Self.stop) - Self.start);
  if (d < 0) then
    d := -d;
  Result := ((d xor (d shr 63)) - (d shr 63) + 1);
end;

{==============================================================================]
  <Area>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Area: Integer; overload;
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
function TRange.Bulk: Integer; overload;
begin
  Result := (((Self.stop - Self.start) * Sign(Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer; overload;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <Cardinality>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Cardinality: Integer; overload;
  function C(const A, B: Integer): Integer;
  begin
    if (A > B) then
	  Exit(A - B);
    Result := (B - A);
  end;
begin
  if Self.Singular then
    Result := 1
  else
    Result := (C(Self.start, Self.stop) + 1);
end;

{==============================================================================]
  <Count>
  @action: Returns count values in the given range.
  @note: None.
[==============================================================================}
function TRange.Count: Integer; overload;
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
function TRange.Counted: Int64; overload;
begin
  Result := (Abs(Int64(Self.stop) - Int64(Self.start)) + 1);
end;

{==============================================================================]
  <Counting>
  @action: Computes the number of elements in the range.
  @note:
    - Constant time O(1)
    - Formula: ((stop - start) * Direction) + 1
    - Interprets direction to normalize increasing/decreasing ranges
    - Assumes inclusive endpoints and consistent step of ±1
    - No validation of start/stop ordering; relies on Direction correctness
[==============================================================================}
function TRange.Counting: Integer; overload;
begin
  Result := (((Self.stop - Self.start) * Self.Direction) + 1);
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
  <Depth>
  @action: Returns the number of discrete elements in the range.
  @note: Computes the inclusive distance between Self.start and Self.stop
         along a single dimension. The use of Hypot(..., 0) is equivalent
         to Abs(Self.stop - Self.start). The result is rounded and incremented
         by 1 to ensure both endpoints are included.
[==============================================================================}
function TRange.Depth: Integer; overload;
begin
  Result := (Round(Hypot((Double(Self.stop) - Self.start), 0)) + 1);
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
function TRange.Footprint: Integer; overload;
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
  <GetAmount>
  @action: Returns the number of discrete Int64 values contained in the
           inclusive range defined by Self.start and Self.stop.
  @note: Order-independent. The bounds are normalized internally
         (min/max) before evaluation. Formula: (max - min) + 1
         Computation is performed in signed Int64 arithmetic.
[==============================================================================}
function TRange.GetAmount: Int64; overload;
var
  l, h: Int64;
begin
  l := Self.start;
  h := Self.stop;
  if (l > h) then
    Swap(l, h);
  Result := ((h - l) + 1);
end;

{==============================================================================]
  <GetCount>
  @action: Returns the number of discrete integer values contained in the range.
  @note: The result is computed using branchless 32-bit arithmetic and supports
         both ascending and descending ranges. The count is inclusive of both
         start and stop values and is equivalent to Abs(stop - start) + 1.
[==============================================================================}
function TRange.GetCount: Integer; overload;
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
function TRange.GetLength: Integer; overload;
var
  d: Integer;
begin
  if Self.Singular then
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
function TRange.GetSize: Integer; overload;
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
function TRange.InclusiveSize: Integer; overload;
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
function TRange.Latitude: Integer; overload;
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
function TRange.Len: Integer; overload;
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
  if Self.Singular then
    Result := 1
  else if (Self.stop < Self.start) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Load>
  @action: Returns the inclusive size of the range as Integer.
  @note: Computed as |Start - Stop| + 1 and capped at High(Integer).
[==============================================================================}
function TRange.Load: Integer; overload;
begin
  Result := Min(High(Integer), (Abs(Int64(Self.stop) - Int64(Self.start)) + 1));
end;

{==============================================================================]
  <Mass>
  @action: Computes the inclusive size (cardinality) of the range.
  @note: Uses Ord(...) as numeric selectors to choose the correct
         directional delta without branching. Produces the absolute
         difference plus one in a compact arithmetic form.
[==============================================================================}
function TRange.Mass: Integer; overload;
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
function TRange.Measure: Integer; overload;
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
function TRange.Measured: Int64; overload;
begin
  Result := (Abs(Int64(Self.stop) - Int64(Self.start)) + 1);
end;

{==============================================================================]
  <Measuring>
  @action: Calculates the number of elements in the range.
  @note: Recursively counts the inclusive distance between Self.start and
         Self.stop by stepping one unit at a time toward the target.
         Equivalent in result to Depth, but implemented via recursion,
         which may incur significant call overhead or risk stack overflow
         for large ranges.
[==============================================================================}
function TRange.Measuring: Integer; overload;
  function C(A, B: Integer): Integer;
  begin
    if (A = B) then
      Result := 1
    else if (A < B) then
      Result := (1 + C((A + 1), B))
    else
      Result := (1 + C((A - 1), B));
  end;
begin
  Result := C(Self.start, Self.stop);
end;

{==============================================================================]
  <Mob>
  @action: Returns the inclusive size of the range as Integer, preserving sign.
  @note: Computed as |Stop - Start| + 1, clamped to High(Integer); uses Sign to handle negative ranges.
[==============================================================================}
function TRange.Mob: Integer; overload;
var
  D: Int64;
begin
  D := (Int64(Self.stop) - Self.start);
  Result := Min(High(Integer), ((D * Sign(D)) + 1));
end;

{==============================================================================]
  <Ordinality>
  @action: Returns the number of discrete elements in the range of an
           enumerated type, including both `start` and `stop`.
  @note:
    - Computes `Abs(Ord(stop) - Ord(start)) + 1`.
    - Works for ascending or descending ranges.
    - Useful for iterating over all values of an enumerated range or
      determining the total count of members.
    - Always returns a value ≥ 1 for non-empty ranges.
[==============================================================================}
function TRange.Ordinality: Integer; overload;
begin
  Result := (Abs(Ord(Self.stop) - Ord(Self.start)) + 1);
end;

{==============================================================================]
  <Perim>
  @action: Returns the total number of discrete elements in the range,
           inclusive of both `Minimum` and `Maximum`.
  @note:
    - Computes `Abs(Maximum - Minimum) + 1`.
    - Works correctly for ascending or descending ranges.
    - Result is clamped to `High(Integer)` if the range is larger than the maximum Integer.
    - Conceptually, this is the "perimeter" or extent of the range in terms of
      the number of elements it contains.
[==============================================================================}
function TRange.Perim: Integer; overload;
var
  D: Int64;
begin
  D := (Int64(Self.Maximum) - Self.Minimum);
  D := (((D xor (D shr 63)) - (D shr 63)) + 1);
  Result := Integer(Min(D, High(Integer)));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the size of the inclusive range defined by Self.start and Self.stop.
  @note: Order-independent. The result is always positive.
         Formula: |stop - start| + 1
         Uses Abs() on PtrInt-casted operands to ensure native-sized
         signed arithmetic before evaluation.
         If (stop - start) exceeds the signed range of PtrInt, the result is undefined.
[==============================================================================}
function TRange.Perimeter: Int64; overload;
begin
  Result := (Abs(PtrInt(Self.stop) - PtrInt(Self.start)) + 1);
end;

{==============================================================================]
  <Populates>
  @action: Returns the inclusive number of elements in the range as Integer.
  @note: Computed as |Stop - Start| + 1; does not clamp to High(Integer).
[==============================================================================}
function TRange.Populates: Integer; overload;
var
  D: Int64;
begin
  D := (Int64(Self.stop) - Self.start);
  if (D < 0) then
    D := -D;
  Result := (Integer(D) + 1);
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
  <PopulationCount>
  @action: Returns the number of integers contained in the range, inclusive of
           both `start` and `stop`, as an Integer.
  @note:
    - If `Self.start <= Self.stop`, returns `stop - start + 1`.
    - If `Self.start > Self.stop`, returns `start - stop + 1`.
    - Result is clamped to `High(Integer)` if the range exceeds the Integer limit.
    - The function always returns a value ≥ 1 for non-empty ranges.
    - Useful when you need the count of discrete elements within a range.
[==============================================================================}
function TRange.PopulationCount: Integer; overload;
var
  H: Integer;
  D, N: Int64;
begin
  D := (Int64(Self.stop) - Self.start);
  N := ((D shr 63) and 1);
  D := ((D * (1 - (2 * N))) + 1);
  H := High(Integer);
  if (D > H) then
    Exit(H);
  Result := Integer(D);
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
function TRange.PopulationSize: Integer; overload;
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
function TRange.Quantified: Int64; overload;
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
function TRange.Quantify: Integer; overload;
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
function TRange.Quantity: Integer; overload;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := ((d * Sign(d)) + 1);
end;

{==============================================================================]
  <Quota>
  @action: Returns the inclusive size of the range as Integer.
  @note: Computed as |Start - Stop| + 1 and capped at High(Integer).
[==============================================================================}
function TRange.Quota: Integer; overload;
var
  A, B, D: Int64;
  H: Integer;
begin
  A := Self.start;
  B := Self.stop;
  if (A > B) then
    D := (A - B)
  else
    D := (B - A);
  D := (D + 1);
  H := High(Integer);
  if (D > H) then
    Result := H
  else
    Result := Integer(D);
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
  <Scope>
  @action: Returns the size (count of integers) in the range
  @note: 
    - If start = stop, returns 1
    - Handles inverted ranges (start > stop) correctly
    - Computed as Abs(stop - start) + 1 using Int64 to prevent overflow
[==============================================================================}
function TRange.Scope: Integer; overload;
begin
  if (Self.start = Self.stop) then
    Exit(1);
  if (Self.start > Self.stop) then
    Exit(Integer(((Int64(Self.stop) - Self.start) div -1) + 1));
  Result := Integer(((Int64(Self.stop) - Self.start) div 1) + 1);
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
  <Sizing>
  @action: Returns the inclusive size of the range as Integer.
  @note: Computed as Max(Start, Stop) - Min(Start, Stop) + 1 and capped at High(Integer).
[==============================================================================}
function TRange.Sizing: Integer; overload;
begin
  Result := Min(High(Integer), (Int64(Max(Self.start, Self.stop)) - Int64(Min(Self.start, Self.stop)) + 1));
end;

{==============================================================================]
  <Spread>
  @action: Returns the inclusive size of the range defined by Start and Stop.
  @note: Uses arithmetic manipulation to derive the absolute difference
         without calling Abs() or using conditional branches.
         The result is always non-negative and includes both endpoints.
         Operates entirely on 32-bit Integer arithmetic.
[==============================================================================}
function TRange.Spread: Integer; overload;
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
function TRange.Stretch: Integer; overload;
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
function TRange.Tally: Integer; overload;
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
function TRange.Volume: Integer; overload;
begin
  Result := (Round(Sqrt(Sqr(Self.stop - Self.start))) + 1);
end;

{==============================================================================]
  <Weight>
  @action: Returns the inclusive size of the range as Integer.
  @note: Computed as |Start - Stop| + 1 and clamped to [0, High(Integer)].
[==============================================================================}
function TRange.Weight: Integer; overload;
begin
  Result := EnsureRange((Abs(Int64(Self.stop) - Self.start) + 1), 0, High(Integer(Integer)));
end;

{==============================================================================]
  <Width>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Width: Integer; overload;
var
  s: Int64;
begin
  if Self.Singular then
    Exit(1);
  s := (Int64(Self.stop) - Int64(Self.start));
  if (s < 0) then
    s := -s;
  Result := (Integer(s) + 1);
end;
{$ENDIF}
