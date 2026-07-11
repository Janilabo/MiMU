{$IFDEF METHODS}
function CountEven: Integer; overload;
function CountOdd: Integer; overload;
function Even: Boolean; overload;
function EvenAmount: Integer; overload;
function Evenc: Integer; overload;
function EvenCount: Integer; overload;
function Evened: TIntegerArray; overload;
function Evens: Integer; overload;
function Evensie: TIntegerArray; overload;
function EvenSummed: Boolean; overload;
function Evenx: Integer; overload;
function Evenz: TIntegerArray; overload;
function GetEven: TIntegerArray; overload;
function GetOdd: TIntegerArray; overload;
function Odd: Boolean; overload;
function OddAmount: Integer; overload;
function Oddc: Integer; overload;
function OddCount: Integer; overload;
function Odded: TIntegerArray; overload;
function Odds: Integer; overload;
function Oddsie: TIntegerArray; overload;
function OddSummed: Boolean; overload;
function Oddx: Integer; overload;
function Oddz: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <EvenTally>
  @action: Calculates the count of even/odd integers in the range via direct iteration.
  @note: O(n) reference implementation. Useful as a correctness oracle for the
         O(1) formulas elsewhere in this family. Handles ascending, descending,
         and singular ranges via explicit direction-aware loop bounds.
[==============================================================================}
function TRange.CountEven: Integer; overload;
var
  i, d: Integer;
begin
  if Self.Singular then
    Exit(Integer(Self.start.Even));
  Result := 0;
  d := Self.Direction;
  i := Self.start;
  while (((d > 0) and (i <= Self.stop)) or ((d < 0) and (i >= Self.stop))) do
    if i.Increase(d).Even then
      Inc(Result);
end;

{==============================================================================]
  <EvenTally>
  @action: Calculates the count of even/odd integers in the range via direct iteration.
  @note: O(n) reference implementation. Useful as a correctness oracle for the
         O(1) formulas elsewhere in this family. Handles ascending, descending,
         and singular ranges via explicit direction-aware loop bounds.
[==============================================================================}
function TRange.CountOdd: Integer; overload;
var
  i, d: Integer;
begin
  if Self.Singular then
    Exit(Integer(Self.start.Odd));
  Result := 0;
  d := Self.Direction;
  i := Self.start;
  while (((d > 0) and (i <= Self.stop)) or ((d < 0) and (i >= Self.stop))) do
    if i.Increase(d).Odd then
      Inc(Result);
end;

{==============================================================================]
  <Even>
  @action: Returns True when the size of the range is an even integer.
  @note: Delegates to Self.Size.Even; no side effects.
[==============================================================================}
function TRange.Even: Boolean; overload;
begin
  Result := Self.Size.Even;
end;

{==============================================================================]
  <EvenAmount>
  @action: Calculates the total count of even integers contained within the range.
  @note: Uses an optimized, loop-free approach. For odd-sized ranges, it relies on
         the mathematical principle that the boundary elements share the same 
         parity, adjusting the base division via a bitwise logical 'and'.
[==============================================================================}
function TRange.EvenAmount: Integer; overload;
begin
  Result := ((Self.Size div 2) + Integer(Self.start.Even and Self.stop.Even));
end;

{==============================================================================]
  <Evenc>
  @action: Calculates the total count of even integers contained within the range.
  @note: Uses a highly optimized, loop-free mathematical formula. If the total 
         size of the range is odd, the remainder element is counted as even 
         only if the range begins on an even number.
[==============================================================================}
function TRange.Evenc: Integer; overload;
begin
  Result := ((Self.Size div 2) + Integer(Self.Size.Odd and Self.start.Even));
end;

{==============================================================================]
  <EvenCount>
  @action: Returns the number of even integers within the range (including both start and stop).
  @note: Works for ascending, descending, and single-element ranges. Handles negative numbers correctly.
[==============================================================================}
function TRange.EvenCount: Integer; overload;
var
  f, l: Integer;
begin
  Result := Self.Direction;
  if (Result = 0) then
    Exit(IfThen(Self.start.Even, 1, 0));
  f := IfThen(Self.start.Even, Self.start, (Self.start + Result));
  l := IfThen(Self.stop.Even, Self.stop, (Self.stop - Result));
  if not (((Result > 0) and (f > l)) or ((Result < 0) and (f < l))) then
    Result := Abs((l - f) div 2) + 1;
end;

{==============================================================================]
  <Evened>
  @action: Produces an array containing all even integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest even boundary starting
         from `start`, then values progress by ±2 depending on whether the
         range is ascending or descending.
[==============================================================================}
function TRange.Evened: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Evens);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Odd then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <Evens>
  @action: Computes the total number of even integers contained within the range.
  @note: The computation is O(1) and works for both ascending and descending
         ranges. The result is inclusive of both endpoints.
[==============================================================================}
function TRange.Evens: Integer; overload;
var
  r: TRange;
begin
  r := Self.Normalize;
  if r.start.Odd then
    Inc(r.start);
  if r.stop.Odd then
    Dec(r.stop);
  if (r.start > r.stop) then
    Result := 0
  else
    Result := (((r.stop - r.start) div 2) + 1);
end;

{==============================================================================]
  <Evensie>
  @action: Filters the range, returning a new array containing only the even integers.
  @note: Reuses the internal array allocation before resizing it to match the count of even numbers found.
[==============================================================================}
function TRange.Evensie: TIntegerArray; overload;
var
  i, r: Integer;
begin
  Result := Self.ToArray;
  r := 0;
  for i := 0 to High(Result) do
    if Result[i].Even then
      Result[r.Increase] := Result[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <EvenSummed>
  @action: Returns True when Start and Stop sum to an even value.
  @note: Useful for parity-based branching or alternating patterns.
[==============================================================================}
function TRange.EvenSummed: Boolean; overload;
begin
  Result := (((Self.start + Self.stop) mod 2) = 0);
end;

{==============================================================================]
  <Evenx>
  @action: Calculates the total count of even integers contained within the range.
  @note: Floor-division derivation via Fiv, using the range's direction-agnostic
         Maximum/Minimum.
[==============================================================================}
function TRange.Evenx: Integer; overload;
begin
  Result := (Fiv(Self.Maximum, 2) - Fiv((Self.Minimum - 1), 2));
end;

{==============================================================================]
  <TRange.Evenz>
  @action: Returns an array of all even integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is odd.
[==============================================================================}
function TRange.Evenz: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.EvenCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Odd then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
end;

{==============================================================================]
  <GetEven>
  @action: Produces an array containing all even integers within the range,
           ordered according to the range direction.
  @note: Aligns the starting value to the nearest even boundary, then fills
         the result by direct index arithmetic rather than iterative
         accumulation. Allocation and loop bound are combined via SetSize's
         return value.
[==============================================================================}
function TRange.GetEven: TIntegerArray; overload;
var
  d, i, s: Integer;
begin
  d := Self.Direction;
  s := IfThen(Self.start.Even, Self.start, (Self.start + d));
  for i := 0 to (Result.SetSize(Self.Evenc) - 1) do
    Result[i] := (s + (i * d) * 2);
end;

{==============================================================================]
  <GetOdd>
  @action: Produces an array containing all odd integers within the range,
           ordered according to the range direction.
  @note: Aligns the starting value to the nearest odd boundary, then fills
         the result by direct index arithmetic rather than iterative
         accumulation. Allocation and loop bound are combined via SetSize's
         return value.
[==============================================================================}
function TRange.GetOdd: TIntegerArray; overload;
var
  d, i, s: Integer;
begin
  d := Self.Direction;
  s := IfThen(Self.start.Odd, Self.start, (Self.start + d));
  for i := 0 to (Result.SetSize(Self.Oddc) - 1) do
    Result[i] := (s + (i * d) * 2);
end;

{==============================================================================]
  <Odd>
  @action: Returns True when the size of the range is an odd integer.
  @note: Delegates to Self.Size.Odd; no side effects.
[==============================================================================}
function TRange.Odd: Boolean; overload;
begin
  Result := Self.Size.Odd;
end;

{==============================================================================]
  <OddAmount>
  @action: Calculates the total count of odd integers contained within the range.
  @note: Employs the same O(1) mathematical alignment optimization as EvenAmount.
         Directly evaluates boundary parities to handle remainder distribution 
         without requiring loops or branching on range size parity.
[==============================================================================}
function TRange.OddAmount: Integer; overload;
begin
  Result := ((Self.Size div 2) + Integer(Self.start.Odd and Self.stop.Odd));
end;

{==============================================================================]
  <Oddc>
  @action: Calculates the total count of odd integers contained within the range.
  @note: Implements the complement approach by subtracting the even integer 
         count from the total range size, ensuring perfect logical symmetry 
         with zero redundant evaluations.
[==============================================================================}
function TRange.Oddc: Integer; overload;
begin
  Result := (Self.Size - Self.EvenAmount);
end;

{==============================================================================]
  <OddCount>
  @action: Returns the number of odd integers within the range (including both start and stop).
  @note: Calculated as the total range size minus the number of even numbers. Works for ascending, descending, and negative ranges.
[==============================================================================}
function TRange.OddCount: Integer; overload;
begin
  Result := (Self.Size - Self.EvenCount);
end;

{==============================================================================]
  <Odded>
  @action: Produces an array containing all odd integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest odd boundary starting
         from `start`, then values progress by ±2 depending on the direction
         of the range.
[==============================================================================}
function TRange.Odded: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Odds);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Even then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <Odds>
  @action: Computes the total number of odd integers contained within the range.
  @note: Determined as (RangeSize - Evens), ensuring correctness regardless
         of range direction or endpoint parity.
[==============================================================================}
function TRange.Odds: Integer; overload;
begin
  Result := (Self.Size - Self.Evens);
end;

{==============================================================================]
  <Oddsie>
  @action: Filters the range, returning a new array containing only the odd integers.
  @note: Reuses the internal array allocation before resizing it to match the count of odd numbers found.
[==============================================================================}
function TRange.Oddsie: TIntegerArray; overload;
var
  i, r: Integer;
begin
  Result := Self.ToArray;
  r := 0;
  for i := 0 to High(Result) do
    if Result[i].Odd then
      Result[r.Increase] := Result[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <OddSummed>
  @action: Returns True if the sum of Start and Stop is not even.
  @note: Checks parity of (Start + Stop).
[==============================================================================}
function TRange.OddSummed: Boolean; overload;
begin
  Result := not (((Self.start + Self.stop) mod 2) = 0);
end;

{==============================================================================]
  <Oddx>
  @action: Calculates the total count of odd integers contained within the range.
  @note: Floor-division derivation via Fiv, using the range's direction-agnostic
         Maximum/Minimum.
[==============================================================================}
function TRange.Oddx: Integer; overload;
begin
  Result := (Fiv((Self.Maximum + 1), 2) - Fiv(Self.Minimum, 2));
end;

{==============================================================================]
  <TRange.Oddz>
  @action: Returns an array of all odd integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is even.
[==============================================================================}
function TRange.Oddz: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.OddCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Even then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
end;
{$ENDIF}
