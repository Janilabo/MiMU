{$IFDEF METHODS}
function Aggregate(var aItems: TIntegerArray): Int64; overload;
function Aggregated(var aItems: TIntegerArray): Int64; overload;
function Compute: Int64; overload;
function Computed: Int64; overload;
function Resultant: Int64; overload;
function Sigma: Int64; overload;
function Sum: Int64; overload;
function Sum2: Int64; overload;
function SumAll: Int64; overload;
function Sumified: Int64; overload;
function Sumify: Int64; overload;
function Summa: Int64; overload;
function Summarize: Int64; overload;
function Summarized: Int64; overload;
function Summary: Int64; overload;
function Summation: Int64; overload;
function Summative: Int64; overload;
function Summed: Int64; overload;
function Summing: Int64; overload;
function Total: Int64; overload;
function Totaled: Int64; overload;
function Totally: Int64; overload;
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
function TRange.Aggregate(var aItems: TIntegerArray): Int64; overload;
var
  l, r, s: Integer;
begin
  l := Self.Size;
  SetLength(aItems, l);
  aItems[0] := Self.start;
  Result := Self.start;
  if Self.Singular then
    Exit;
  s := IfThen(Self.Ascending, 1, -1);
  r := 1;
  repeat
    aItems[r] := (aItems[r - 1] + s);
    Result := (Result + aItems[r]);
  until (r.Increment >= l);
end;

{==============================================================================]
  <Aggregated>
  @action: Fills a TIntegerArray with all values in the range and returns their sum.
  @note: Supports both ascending and descending ranges. The sum is computed
         incrementally while filling the array. The array length is automatically
         set to the range size. Uses Int64 for the sum to reduce overflow risk.
[==============================================================================}
function TRange.Aggregated(var aItems: TIntegerArray): Int64; overload;
var
  i, l, r, s: Integer;
begin
  l := Self.Size;
  SetLength(aItems, l);
  Result := 0;
  s := IfThen(Self.Ascending, 1, -1);
  r := 0;
  i := Self.Start;
  while (r < l) do
  begin
    aItems[r.Increase] := i;
    Result := (Result + i.Increase(s));
  end;
end;

{==============================================================================]
  <Compute>
  @action: Calculates the sum of the range using a recursive binary split 
           (Divide and Conquer) algorithm.
  @note: While mathematically sound, this method has O(n) time complexity and 
         O(log n) stack depth. It is significantly less efficient than 
         "Summarized" but serves as a functional example of recursive 
         decomposition.
[==============================================================================}
function TRange.Compute: Int64; overload;
  function C(const L, H: Integer): Int64;
  var
    m: Integer;
  begin
    if (L = H) then
      Exit(L);
    m := (L + ((H - L) div 2));
    Result := (C(L, m) + C((m + 1), H));
  end;
begin
  Result := C(Self.Minimum, Self.Maximum);
end;

{==============================================================================]
  <Computed>
  @action: Calculates the sum of the range using a double-ended recursive 
           "pincer" algorithm that shrinks the boundaries toward the center.
  @note: Reduces recursion depth by 50% compared to linear recursion (O(n/2)).
         It explicitly handles the center element for odd-sized ranges via 
         the (L = H) base case.
[==============================================================================}
function TRange.Computed: Int64; overload;
  function C(const L, H: Integer): Int64;
  begin
    if (L > H) then
      Exit(0);
    if (L = H) then
      Exit(L);
    Result := (Int64(L) + H + C((L + 1), (H - 1)));
  end;
begin
  Result := C(Self.Minimum, Self.Maximum);
end;

{==============================================================================]
  <Resultant>
  @action: Computes the sum of the range using an arithmetic series formula
           based on the minimum and maximum bounds.
  @note: The range is treated as inclusive [Minimum..Maximum].
[==============================================================================}
function TRange.Resultant: Int64; overload;
var
  l, h, n, s: Int64;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  n := ((h - l) + 1);
  s := (l + h);
  if ((n and 1) = 0) then
    Result := ((n div 2) * s)
  else
    Result := (n * (s div 2));
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
  Result := ((Int64(Self.Size) * Self.Combined) div 2);
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
  a := Self.Minimum;
  b := Self.Maximum;
  Result := ((((b - a) + 1) * (a + b)) div 2);
end;

{==============================================================================]
  <Sum2>
  @action: Calculates the total sum of a stepped arithmetic progression.
  @note: Uses the advanced series formula [n/2 * (2a + (n-1)d)] to account for 
         Direction (step). Operates in O(1) constant time.
[==============================================================================}
function TRange.Sum2: Int64; overload;
var
  s: Int64;
begin
  s := Self.Size;
  Result := (s * (2 * Int64(Self.start) + (s - 1) * Self.Direction) div 2);
end;

{==============================================================================]
  <SumAll>
  @action: Returns the sum of the range starting at `start` and progressing
           towards `stop` using a step of ±1 depending on direction.
  @note: If the range is singular, the result is `start`.
         The `stop` value is not included in the summation.
         Iteration is performed via `Increase(d)` where
         d = +1 (ascending) or -1 (descending).
[==============================================================================}
function TRange.SumAll: Int64; overload;
var
  s, d: Integer;
begin
  Result := Self.start;
  if Self.Singular then
    Exit;
  s := Self.start;
  d := IfThen(Self.Ascending, 1, -1);
  while (s.Increase(d) <> Self.stop) do
    Inc(Result, s);
end;

{==============================================================================]
  <Sumified>
  @action: Computes the arithmetic sum of all integer values within the range
           defined by Self.Minimum (f) and Self.Maximum (l), inclusive.
           Uses a constant-time formula derived from the arithmetic series:
           sum = n * (f + l) / 2
           To avoid intermediate overflow and preserve integer arithmetic,
           the implementation splits the computation into: (n div 2) * (f + l)
           and conditionally adds the middle element when n is odd.
  @note:
    - n is the total number of elements in the range:
        n = (l - f) + 1
    - When n is even:
        Result = (n / 2) * (f + l)
    - When n is odd:
        The midpoint term (f + n div 2) is added explicitly to compensate
        for integer division truncation.
    - Assumes f <= l; behavior is undefined if the range is inverted.
    - Entire computation is O(1), no iteration is performed.
    - Uses Int64; ensure (f + l) and intermediate products do not overflow.
[==============================================================================}
function TRange.Sumified: Int64; overload;
var
  n, f, l: Int64;
begin
  f := Self.Minimum;
  l := Self.Maximum;
  n := ((l - f) + 1);
  Result := ((n div 2) * (f + l));
  if n.Odd then
    Result := (Result + (f + (n div 2)));
end;

{==============================================================================]
  <Sumify>
  @action: Computes the sum of the range using an arithmetic series formula
           based on the minimum and maximum bounds.
  @note: The range is treated as inclusive [Minimum..Maximum].
         Uses n = (h - l + 1) and s = (l + h) to avoid iteration.
         Applies parity optimization to reduce overflow risk:
         - If n is even: (n div 2) * (l + h)
         - If n is odd:  n * ((l + h) div 2)
         Direction (ascending/descending) has no effect on the result.
[==============================================================================}
function TRange.Sumify: Int64; overload;
var
  n, s: Int64;
  l, h: Integer;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  n := ((h - l) + 1);
  s := (l + h);
  if ((n and 1) = 0) then
    Result := ((n shr 1) * s)
  else
    Result := (n * (s shr 1));
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
  <Summarize>
  @action: Calculates the arithmetic sum of all values within the range.
  @return: Sum of all elements from Self.start to Self.stop (inclusive)
  @note: • Uses the arithmetic series formula: Sum = n * (first + last) / 2
         • Handles both ascending and descending ranges correctly
         • Self.Combined = Self.start + Self.stop (cached or calculated)
         • Returns Int64 to prevent overflow for large ranges
         • Examples:
             - Range(1, 10).Summarize = 55
             - Range(10, 1).Summarize = 55  (same result, order doesn't matter)
             - Range(0, 100).Summarize = 5050
         • O(1) time complexity - no iteration required
         • Edge Cases:
             - Empty range: Size = 0 → Result = 0
             - Single element: Size = 1 → Result = start = stop
         • Equivalent to: Sum := (Size * (start + stop)) div 2
[==============================================================================}
function TRange.Summarize: Int64; overload;
begin
  Result := ((Self.Size * Self.Combined) div 2);
end;

{==============================================================================]
  <Summarized>
  @action: Calculates the sum of all integer values within the TRange using 
           an optimized O(1) arithmetic series formula.
  @note: Uses Int64 casting to prevent overflow during addition and handles 
         even/odd parity of the range size to maintain precision before division.
[==============================================================================}
function TRange.Summarized: Int64; overload;
var
  s: Int64;
begin
  if Self.Singular then
    Exit(Self.start);
  s := Self.Size;
  if ((s mod 2) = 0) then
    Result := ((s div 2) * (Int64(Self.start) + Self.stop))
  else
    Result := (s * ((Int64(Self.start) + Self.stop) div 2));
end;

{==============================================================================]
  <Summary>
  @action: Iteratively computes the sum of all values between Minimum and
           Maximum using a linear loop.
  @note: The range is treated as inclusive [Minimum..Maximum].
         Performs a simple accumulation via Inc over each integer value.
         Less efficient than formula-based approaches (e.g. Sumify),
         but straightforward and safe for small ranges.
[==============================================================================}
function TRange.Summary: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := Self.Minimum to Self.Maximum do
    Inc(Result, i);
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
  a := Self.Minimum;
  b := Self.Maximum;
  n := ((b - a) + 1);
  s := (a + b);
  c := (s div 2);
  Result := (n * c);
  if ((s and 1) = 1) then
    Result := (Result + (n div 2));
end;

{==============================================================================]
  <Summative>
  @action: Computes the sum of the range by iteratively advancing from `start`
           towards `stop` using `Increment(d)` and accumulating each step.
  @note: The initial value `start` is included in the result.
         Iteration continues until `s = stop`, with the loop adding each
         incremented value returned by `Increment(d)`.
         The `stop` value is included if `Increment(d)` reaches it.
         Direction is controlled by d = +1 (ascending) or -1 (descending).
         Behavior depends on `Increment(d)` semantics (in-place vs return).
[==============================================================================}
function TRange.Summative: Int64; overload;
var
  s, d: Integer;
begin
  d := IfThen(Self.Ascending, 1, -1);
  s := Self.start;
  Result := Self.start;
  while (s <> Self.stop) do
    Inc(Result, s.Increment(d));
end;

{==============================================================================]
  <Summed>
  @action: Computes the sum of the range using a floating-point arithmetic
           series formula and rounds the result to Int64.
  @note: The range is treated as inclusive [Minimum..Maximum].
         Uses ((h - l + 1) * ((l + h) / 2.0)) for calculation.
         Relies on floating-point division and Round, which may introduce
         minor precision considerations for very large values.
         Direction (ascending/descending) has no effect on the result.
[==============================================================================}
function TRange.Summed: Int64; overload;
var
  l, h: Int64;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  Result := Round(((h - l) + 1) * ((l + h) / 2.0));
end;

{==============================================================================]
  <Summing>
  @action: Computes the arithmetic sum of all Int64 values within the inclusive
           range [Minimum, Maximum] using a symmetric two-pointer accumulation.         
           The algorithm iteratively pairs the lower and upper bounds, adding
           their sum while converging toward the midpoint:
             (a + b), (a+1 + b-1), ...
           If the range has odd cardinality, the midpoint value is added once.
           This avoids full linear traversal while remaining branch-light and
           free of multiplication/division operations.
  @note: Time complexity is O(n/2), effectively linear but with half the
         iterations of a naive loop.
         Behavior is undefined if Minimum > Maximum unless externally guarded.
         Relies on side-effect semantics of Increase/Decrease:
           - a.Increase returns current value of a, then increments a
           - b.Decrease returns current value of b, then decrements b
         This method reduces (but does not eliminate) overflow risk compared
         to direct summation; overflow may still occur for large ranges.
         For constant-time evaluation, prefer the closed-form variant
         (see Resultant).
[==============================================================================}
function TRange.Summing: Int64; overload;
var
  a, b: Int64;
begin
  Result := 0;
  a := Self.Minimum;
  b := Self.Maximum;
  while (a < b) do
    Inc(Result, (a.Increase + b.Decrease));
  if (a = b) then
    Inc(Result, a);
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

{==============================================================================]
  <Totaled>
  @action: Calculates the sum of all values in the range by iterating from 
           start to stop.
  @note: This is an O(n) operation. Unlike "Summarized", this method 
         manually increments through each element, making it useful for 
         ranges where custom stepping or state-heavy iteration is required.
[==============================================================================}
function TRange.Totaled: Int64; overload;
var
  r, d: Integer;
begin
  if Self.Singular then
    Exit(Self.start);
  Result := 0;
  d := Self.Direction;
  r := Self.start;
  while (r <> Self.stop) do
    Result := (Result + r.Increase(d));
  Result := (Result + Self.stop);
end;

{==============================================================================]
  <Totally>
  @action: Aggregates the sum of the range by calculating the absolute value 
           of each element based on its index and adding it to the start value.
  @note: Uses a for-loop based on Size. This approach ensures the loop runs 
         a deterministic number of times, avoiding potential infinite loops 
         associated with "while (r <> stop)" in non-contiguous ranges.
[==============================================================================}
function TRange.Totally: Int64; overload;
var
  i, d: Integer;
begin
  Result := Self.start;
  d := Self.Direction;
  for i := 1 to (Self.Size - 1) do
    Result.Increase(Self.start + (i * d));
end;
{$ENDIF}
