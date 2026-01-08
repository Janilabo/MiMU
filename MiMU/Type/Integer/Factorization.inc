{$IFDEF HELPERS}
function DivisibleBy(const value: Integer): Boolean; cdecl;
function Divisors: TIntegerArray; cdecl;
function Factors: TIntegerArray; cdecl;
function MultipleOf(const value: Integer): Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DivisibleBy>
  @action: Returns True if the current integer (`Self`) is evenly divisible by
           `value`. The function checks whether dividing `Self` by `value`
           yields an integer with no remainder. Uses an arithmetic identity
           (`Self = (Self div value) * value`) instead of the modulus operator.
  @note:
    - Returns True for `value = 1` or `value = -1` (all integers are divisible
      by ±1).
    - Returns False for `value = 0` to avoid division-by-zero.
    - Works correctly for positive and negative integers.
    - Uses a remainder-free equality test rather than `mod`.
[==============================================================================}
function TIntegerHelper.DivisibleBy(const value: Integer): Boolean; cdecl;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self - (Self div value) * value) = 0)));
end;

{==============================================================================]
  <Divisors>
  @action: Returns an array of all positive divisors of Self, including Self itself.
  @note:
    - If Self = 0, returns an empty array.
    - The divisors are calculated by iterating from 1 to Abs(Self) and checking modulo.
    - The resulting array contains only positive numbers and is in ascending order.
    - May be less efficient for large numbers compared to a square-root optimized method.
[==============================================================================}
function TIntegerHelper.Divisors: TIntegerArray; cdecl;
var
  a, i, r: Integer;
begin
  r := 0;
  if (Self <> 0) then
  begin
    a := Abs(Self);
    SetLength(Result, ((a div 2) + 1));
    for i := 1 to a do
      if ((Self mod i) = 0) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Factors>
  @action: Returns an array of all positive factors of Self (equivalent to divisors),
           optimized using the square root method.
  @note:
    - If Self = 0, returns an empty array.
    - Iterates from 1 to Trunc(Sqrt(Abs(Self))) to find factor pairs.
    - Adds both i and Abs(Self) div i when i divides Self.
    - Resulting array is sorted in ascending order using QuickSort.
    - More efficient than naive Divisors method for large numbers.
[==============================================================================}
function TIntegerHelper.Factors: TIntegerArray; cdecl;
var
  i, r, a: Integer;
begin
  a := Abs(Self);
  if (a = 0) then
    Exit([]);
  SetLength(Result, ((a div 2) + 1));
  r := 0;
  for i := 1 to Trunc(Sqrt(a)) do
  begin
    if not ((a mod i) = 0) then
      Continue;
    Result[r.Increase] := i;
    if (i <> (a div i)) then
      Result[r.Increase] := (a div i);
  end;
  SetLength(Result, r);
  Result.QuickSort;
end;

{==============================================================================]
  <MultipleOf>
  @action: Returns True if the current integer (`Self`) is a multiple of
           `value`. The function tests whether the remainder of `Self mod value`
           is zero.
  @note:
    - Returns True for `value = 1` or `value = -1` (all integers are multiples
      of ±1).
    - Returns False for `value = 0`, since no integer is a multiple of zero.
    - Works correctly with signed operands.
    - Uses the standard modulus operator for remainder testing.
[==============================================================================}
function TIntegerHelper.MultipleOf(const value: Integer): Boolean; cdecl;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self mod value) = 0)));
end;
{$ENDIF}