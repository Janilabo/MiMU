{$IFDEF HELPERS}
function Divability(const value: Integer): Boolean; overload;
function Divable(const value: Integer): Boolean; overload;
function Divisibility(const value: Integer): Boolean; overload;
function DivisibleBy(const value: Integer): Boolean; overload;
function IsPowerOf2: Boolean; overload;
function IsPowerOfTwo: Boolean; overload;
function IsPowOf2: Boolean; overload;
function IsPowOfTwo: Boolean; overload;
function MultipleOf(const value: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Divability>
  @action: Returns True if the integer is evenly divisible by the specified value, supporting both positive and negative integers.
  @note: Uses `Abs()` on both operands to normalize negative inputs before applying the modulo operation.
         Returns False if the divisor is 0 to prevent a division-by-zero crash.
[==============================================================================}
function TIntegerHelper.Divability(const value: Integer): Boolean; overload;
begin
  Result := ((value <> 0) and ((Abs(Self) mod Abs(value)) = 0));
end;

{==============================================================================]
  <Divable>
  @action: Returns True if the integer is evenly divisible by the specified value without a remainder.
  @note: Highly optimized. If the divisor is a positive power of 2,
         it bypasses heavy CPU division entirely by using the fast bitwise shortcut `(Self and (value - 1)) = 0`.
[==============================================================================}
function TIntegerHelper.Divable(const value: Integer): Boolean; overload;
begin
  if (value = 0) then
    Result := False
  else if (value > 0) and ((value and (value - 1)) = 0) then
    Result := ((Self and (value - 1)) = 0)
  else
    Result := ((Self mod value) = 0);
end;

{==============================================================================]
  <Divisibility>
  @action: Returns True if the integer is evenly divisible by the specified value, supporting both positive and negative integers.
  @note: Safely handles non-zero inputs by casting both `Self` and `value` to `Int64` prior to evaluation.
         This casting eliminates potential integer overflow or boundary anomalies during the modulo operation.
[==============================================================================}
function TIntegerHelper.Divisibility(const value: Integer): Boolean; overload;
begin
  Result := ((value <> 0) and ((Int64(Self) mod Int64(value)) = 0));
end;

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
function TIntegerHelper.DivisibleBy(const value: Integer): Boolean; overload;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self - (Self div value) * value) = 0)));
end;

{==============================================================================]
  <IsPowerOf2>
  @action: Returns True if the integer is a positive power of 2 (e.g., 1, 2, 4, 8, 16...), and False otherwise.
  @note: Uses an efficient bitwise trick `(Self and (Self - 1)) = 0` which executes in O(1) time without loops or floating-point math.
[==============================================================================}
function TIntegerHelper.IsPowerOf2: Boolean; overload;
begin
  Result := ((Self > 0) and ((Self and (Self - 1)) = 0));
end;

{==============================================================================]
  <IsPowerOfTwo>
  @action: Returns True if the integer is a positive power of 2 (e.g., 1, 2, 4, 8...), and False otherwise.
  @note: Uses logarithmic math corrected by `Round()` to fix floating-point precision drops (like Log2(8) evaluating to 2.9999...). 
         While functionally correct, it is slower than pure bitwise AND variations.
[==============================================================================}
function TIntegerHelper.IsPowerOfTwo: Boolean; overload;
begin
  Result := ((Self > 0) and ((1 shl Round(Log2(Self))) = Self));
end;

{==============================================================================]
  <IsPowOf2>
  @action: Returns True if the integer matches a precomputed value in the POWERS_OF_TWO array, indicating it is a positive power of 2.
  @note: Operates via a deterministic linear search loop (up to 31 iterations). While safe from floating-point bugs, it is less efficient than O(1) bitwise operations.
[==============================================================================}
function TIntegerHelper.IsPowOf2: Boolean; overload;
var
  i: Integer;
begin
  if (Self > 0) then
  for i := 0 to 30 do
    if (Self = POWERS_OF_TWO[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <IsPowOfTwo>
  @action: Returns True if Self is a power of 2.
  @note: Uses `(Self and -Self) = Self`. For 8 (1000), -8 (111...11000)
         ANDed together gives 8. For 6 (110), it gives 2 (not equal).
[==============================================================================}
function TIntegerHelper.IsPowOfTwo: Boolean; overload;
begin
  Result := ((Self > 0) and ((Self and -Self) = Self));
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
function TIntegerHelper.MultipleOf(const value: Integer): Boolean; overload;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self mod value) = 0)));
end;
{$ENDIF}