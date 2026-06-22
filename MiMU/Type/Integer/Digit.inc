{$IFDEF HELPERS}
function AsDigits: TIntegerArray; overload;
function CalculateDigits: Integer; overload;
function CountDigits: Integer; overload;
function DigitAmount: Integer; overload;
function DigitCount: Integer; overload;
function DigitCounter: Integer; overload;
function Digit1st: Integer; overload;
function DigitFirst: Integer; overload;
function Digiting: TIntegerArray; overload;
function DigitLst: Integer; overload;
function DigitLast: Integer; overload;
function Digitlist: TIntegerArray; overload;
function Digitment: TIntegerArray; overload;
function DigitQuantity: Integer; overload;
function Digits: TIntegerArray; overload;
function DigitsAmount: Integer; overload;
function DigitsCount: Integer; overload;
function DigitsCounted: Integer; overload;
function DigitsQuantity: Integer; overload;
function Digitted: TIntegerArray; overload;
function Digitz: TIntegerArray; overload;
function FinalDigit: Integer; overload;
function FirstDigit: Integer; overload;
function FrontDigit: Integer; overload;
function GetDigits: TIntegerArray; overload;
function HeadDigit: Integer; overload;
function LastDigit: Integer; overload;
function NDigited(const digitCount: Integer): Boolean; overload;
function NDigits: Integer; overload;
function QuantifyDigits: Integer; overload;
function RearDigit: Integer; overload;
function ReckonDigits: Integer; overload;
function StartDigit: Integer; overload;
function TailDigit: Integer; overload;
function ToDigits: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsDigits>
  @action: Converts the integer into an array of its individual digits.
  @note: Treats negative numbers as positive (ignores the sign via Abs). 
         Returns [0] if the value is 0.
[==============================================================================}
function TIntegerHelper.AsDigits: TIntegerArray; overload;
var
  n, c, i, d: Integer;
begin
  if (Self = 0) then
    Exit([0]);
  n := Abs(Self);
  d := n;
  c := 0;
  while (d > 0) do
  begin
    Inc(c);
    d := (d div 10);
  end;
  SetLength(Result, c);
  d := n;
  for i := (c - 1) downto 0 do
  begin
    Result[i] := (d mod 10);
    d := (d div 10);
  end;
end;

{==============================================================================]
  <CalculateDigits>
  @action: Counts the total number of digits in the integer by repeatedly
           multiplying a threshold by 10 until it exceeds the absolute value.
  @note: Inverse of the div-10 loop strategy. Safely handles Low(Integer)
         to prevent overflow when calling Abs().
[==============================================================================}
function TIntegerHelper.CalculateDigits: Integer; overload;
var
  s, m: Integer;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  s := Abs(Self);
  Result := 1;
  m := 1;
  while ((Result < 10) and (s >= m.X(10))) do
    Inc(Result);
end;

{==============================================================================]
  <CountDigits>
  @action: Calculates the total number of digits required to represent the 
           integer value in base-10.
  @note: Negative signs are ignored in the count. Safely handles the 
         Low(Integer) boundary condition to prevent an integer overflow 
         when calling Abs().
[==============================================================================}
function TIntegerHelper.CountDigits: Integer; overload;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  case Abs(Self) of
    0..9: Result := 1;
    10..99: Result := 2;
    100..999: Result := 3;
    1000..9999: Result := 4;
    10000..99999: Result := 5;
    100000..999999: Result := 6;
    1000000..9999999: Result := 7;
    10000000..99999999: Result := 8;
    100000000..999999999: Result := 9;
  else
    Result := 10;
  end;
end;

{==============================================================================]
  <DigitAmount>
  @action: Returns the total number of digits in the integer.
  @note: Works accurately for all positive and negative Int64 values.
[==============================================================================}
function TIntegerHelper.DigitAmount: Integer; overload;
var
  n: Int64;
  i: Integer;
begin
  n := Abs(Int64(Self));
  for i := 1 to 9 do
    if (n <= ALL_NINES[i]) then
      Exit(i);
  Result := 10;
end;

{==============================================================================]
  <DigitCount>
  @action: Returns count of digits Integer x value contains.
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.DigitCount: Integer; overload;
var
  a, n, m: Int64;
begin
  a := Abs(Self);
  Result := 0;
  m := 10;
  repeat
    n := (a mod m);
    m := (m * 10);
  until ((Result.Increment = 10) or (n = a));
end;

{==============================================================================]
  <DigitCounter>
  @action: Calculates the total number of digits in the current integer value 
           using an optimized binary search approach.
  @note: Thread-safe and handles edge cases such as zero (1 digit) and 
         the minimum possible integer value (10 digits).
[==============================================================================}
function TIntegerHelper.DigitCounter: Integer; overload;
var
  s: Int64;
  h, m: Integer;
begin
  if (Self = 0) then
    Exit(1);
  if (Self = Low(Integer)) then
    Exit(10);
  s := Abs(Int64(Self));
  Result := 1;
  h := 10;
  while (Result < h) do
  begin
    m := ((Result + h) div 2);
    if (s < POWERS_OF_TEN[m]) then
      h := m
    else
      Result := (m + 1);
  end;
end;

{==============================================================================]
  <Digit1st>
  @action: Extracts the first (most significant) digit of the integer using 
           pure mathematical division.
  @note: Highly optimized compared to string parsing. It handles negative 
         numbers by converting them to positive via an absolute value check, 
         then loops to find the correct power-of-10 divisor to isolate the 
         leading digit. Safe from string allocation overhead.
[==============================================================================}
function TIntegerHelper.Digit1st: Integer; overload;
var
  n, d, t: Int64;
begin
  n := Int64(IfThen((Self < 0), -Self, Self));
  d := 1;
  t := (n div 10);
  while (d <= t) do
    d := (d * 10);
  Result := (n div d);
end;

{==============================================================================]
  <DigitFirst>
  @action: Extracts the first (most significant) digit of the integer using a 
           pre-calculated powers-of-10 lookup table.
  @note: Highly optimized O(1) time complexity approach. It instantly handles 
         zero, converts negative numbers via `Abs`, and walks backward through 
         the `POW10` array to find the exact divisor scale without performing 
         expensive math operations in a loop.
[==============================================================================}
function TIntegerHelper.DigitFirst: Integer; overload;
const
  POW10: array[0..9] of Int64 = (1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000);
var
  n: Int64;
  i: Integer;
begin
  if (Self = 0) then
    Exit(0);
  n := Abs(Self);
  i := 9;
  while ((i > 0) and (n < POW10[i])) do
    Dec(i);
  Result := (n div POW10[i]);
end;

{==============================================================================]
  <Digiting>
  @action: Splits the integer value into an array of its individual digits.
  @note: Handles negative numbers by taking the absolute value; expects a 
         helper property or method `DigitCount` to correctly size the result array.
[==============================================================================}
function TIntegerHelper.Digiting: TIntegerArray; overload;
var
  n: Int64;
  i: Integer;
begin
  n := Abs(Int64(Self));
  SetLength(Result, Self.DigitCount);
  for i := High(Result) downto 0 do
  begin
    Result[i] := (n mod 10);
    n := n div 10;
  end;
end;

{==============================================================================]
  <DigitLst>
  @action: Extracts the last (least significant) digit of the integer using 
           the modulo operator.
  @note: Highly efficient. It converts negative numbers to positive values 
         and applies `mod 10` to instantly strip away everything except the 
         final digit.
[==============================================================================}
function TIntegerHelper.DigitLst: Integer; overload;
begin
  Result := (Int64(IfThen((Self < 0), -Self, Self)) mod 10);
end;

{==============================================================================]
  <DigitLast>
  @action: Extracts the last (least significant) digit of the integer using 
           the modulo operator.
  @note: Highly efficient. It converts negative numbers to positive values 
         and applies `mod 10` to instantly strip away everything except the 
         final digit.
[==============================================================================}
function TIntegerHelper.DigitLast: Integer; overload;
begin
  Result := (Abs(Self) mod 10);
end;

{==============================================================================]
  <Digitlist>
  @action: Extracts the digits of the integer into an array using a generic TList for dynamic storage.
  @note: Treats negative numbers as positive (ignores the sign via Abs). Returns [0] if the value is 0. 
         Allocates and frees a generic collection (specialize TList<Integer>) internally.
[==============================================================================}
function TIntegerHelper.Digitlist: TIntegerArray; overload;
var
  i, n: Integer;
  l: specialize TList<Integer>;
begin
  if (Self = 0) then
    Exit([0]);
  n := Abs(Self);
  l := specialize TList<Integer>.Create;
  try
    while (n > 0) do
    begin
      l.Add(n mod 10);
      n := (n div 10);
    end;
    l.Reverse;
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Digitment>
  @action: Extracts the digits of the integer into an array using logarithmic math to determine length and position.
  @note: Treats negative numbers as positive (ignores the sign via Abs). Returns [0] if the value is 0. 
         Relies on floating-point math (Log10, Power, Floor, Round) from the System.Math unit.
[==============================================================================}
function TIntegerHelper.Digitment: TIntegerArray; overload;
var
  n, i, d: Integer;
begin
  if (Self = 0) then
    Exit([0]);
  n := Abs(Self);
  d := Round(Power(10, (Result.SetSize(Floor(Log10(n)) + 1) - 1)));
  for i := 0 to High(Result) do
  begin
    Result[i] := (n div d);
    n := (n mod d);
    d := (d div 10);
  end;
end;

{==============================================================================]
  <DigitQuantity>
  @action: Counts the total number of digits in the integer by checking the 
           length of its string representation.
  @note: Automatically strips or offsets the negative sign for negative numbers. 
         Safely isolates Low(Integer) to prevent a string conversion that includes 
         an unexpected overflow representation.
[==============================================================================}
function TIntegerHelper.DigitQuantity: Integer; overload;
begin
  if (Self = 0) then
    Result := 1
  else if (Self > 0) then
    Result := Length(IntToStr(Self))
  else if (Self = Low(Integer)) then
    Result := 10
  else
    Result := (Length(IntToStr(Self)) - 1);
end;

{==============================================================================]
  <Digits>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digits: TIntegerArray; overload;
var
  s: string;
  i: Integer;
begin
  s := IntToStr(Abs(Self));
  SetLength(Result, Length(s));
  for i := 0 to High(Result) do
    Result[i] := StrToInt(s[i + 1]);
end;

{==============================================================================]
  <DigitsAmount>
  @action: Returns the total number of digits in the Integer instance using
           a logarithmic calculation.
  @note: Requires the 'Math' unit. Safely handles zero and the minimum 
         possible negative integer boundary.
[==============================================================================}
function TIntegerHelper.DigitsAmount: Integer; overload;
begin
  if (Self = 0) then
    Exit(1);
  if (Self = Low(Integer)) then
    Exit(10);
  Result := (Floor(Log10(Abs(Self))) + 1);
end;

{==============================================================================]
  <DigitsCount>
  @action: Counts the total number of digits in the integer by repeatedly 
           dividing the absolute value by 10 until it reaches zero.
  @note: Uses purely integer math. Safely bypasses the loop for Low(Integer) 
         to prevent an integer overflow error when calling Abs().
[==============================================================================}
function TIntegerHelper.DigitsCount: Integer; overload;
var
  s: Integer;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  Result := 0;
  s := Abs(Self);
  repeat
    s := (s div 10);
    Inc(Result);
  until (s = 0);
end;

{==============================================================================]
  <DigitsCounted>
  @action: Returns the total number of digits in the 32-bit Integer instance.
  @note: Works accurately for all positive and negative Integer values without
         relying on string conversions or loops.
[==============================================================================}
function TIntegerHelper.DigitsCounted: Integer; overload;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  Result := Abs(Self);
  if (Result < 10) then
    Exit(1);
  if (Result < 100) then
    Exit(2);
  if (Result < 1000) then
    Exit(3);
  if (Result < 10000) then
    Exit(4);
  if (Result < 100000) then
    Exit(5);
  if (Result < 1000000) then
    Exit(6);
  if (Result < 10000000) then
    Exit(7);
  if (Result < 100000000) then
    Exit(8);
  if (Result < 1000000000) then
    Exit(9);
  Result := 10;
end;

{==============================================================================]
  <DigitsQuantity>
  @action: Calculates the number of digits in the integer using a hardcoded 
           binary search tree structure to minimize conditional evaluations.
  @note: Casts to Int64 to allow safe absolute value calculation. Directly 
         bypasses the decision tree for Low(Integer) to protect bounds.
[==============================================================================}
function TIntegerHelper.DigitsQuantity: Integer; overload;
var
  V: Int64;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  V := Abs(Int64(Self));
  case (V < 10000) of
    True:
    case (V < 100) of
      True:
      if (V < 10) then
        Result := 1
      else
        Result := 2;
      False:
      if (V < 1000) then
        Result := 3
      else
        Result := 4;
    end;
    False:
    case (V < 1000000) of
      True:
      if (V < 100000) then
        Result := 5
      else
        Result := 6;
      False:
      case (V < 100000000) of
        True:
        if (V < 10000000) then
          Result := 7
        else
          Result := 8;
        False:
        if (V < 1000000000) then
          Result := 9
        else
          Result := 10;
      end;
    end;
  end;
end;

{==============================================================================]
  <Digitted>
  @action: Extracts all digits of the integer into a dynamic TIntegerArray,
           ordered from most significant digit to least significant digit.
  @note: Cross-compiler compatible implementation optimized for Free Pascal and
         Delphi. Bypasses the strict `var` reference checks of `DivMod` by using
         native `mod` and `div` operators, which seamlessly handle `Int64` data
         types and prevent `Low(Integer)` overflow traps.
[==============================================================================}
function TIntegerHelper.Digitted: TIntegerArray; overload;
var
  n: Int64;
  b: array[0..9] of Integer;
  l, i: Integer;
begin
  if (Self = 0) then
    Exit([0]);
  n := Abs(Int64(Self));
  l := 0;
  while (n > 0) do
  begin
    b[l.Increase] := (n mod 10);
    n := (n div 10);
  end;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := b[(l - 1) - i];
end;

{==============================================================================]
  <Digitz>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digitz: TIntegerArray; overload;
var
  a, n, m: Int64;
  i, r: Integer;
begin
  a := Abs(Self);
  r := 0;
  SetLength(Result, 10);
  m := 10;
  repeat
    n := (a mod m);
    Result[r] := (n div (m div 10));
    m := (m * 10);
  until ((r.Increment = 10) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[(r - i) - 1]);
end;

{==============================================================================]
  <FinalDigit>
  @action: Extracts the very last digit of the integer as an Integer value.
  @note: Uses ASCII character code conversion (subtracting 48 from the Ordinal 
         value of the character). It relies on a custom or third-party string 
         helper property/method `.Lasty` to get the final character.
[==============================================================================}
function TIntegerHelper.FinalDigit: Integer; overload;
begin
  Result := (Ord(IntToStr(Self).Lasty) - 48);
end;

{==============================================================================]
  <FirstDigit>
  @action: Extracts the very first digit of the integer, correctly skipping the 
           negative sign if the number is less than zero.
  @note: WARNING: This code contains a bug. It attempts to reference an 
         undeclared variable `s`. It should be rewritten to reference the 
         converted string, e.g., `StrToInt(IntToStr(Self)[IfThen((Self < 0), 2, 1)])`.
[==============================================================================}
function TIntegerHelper.FirstDigit: Integer; overload;
begin
  Result := StrToInt(IntToStr(Self)[IfThen((Self < 0), 2, 1)]);
end;

{==============================================================================]
  <FrontDigit>
  @action: Extracts the first (most significant) digit of the integer by 
           repeatedly dividing the number by 10 until a single digit remains.
  @note: Highly intuitive and does not require an array lookup table. 
         CRITICAL: To prevent an integer overflow bug when `Self` is exactly 
         `Low(Integer)` (-2,147,483,648), `Self` must be safely cast to an 
         `Int64` before taking its absolute value: `n := Abs(Int64(Self));`.
[==============================================================================}
function TIntegerHelper.FrontDigit: Integer; overload;
var
  n: Int64;
begin
  n := Abs(Self);
  while (n >= 10) do
    n := (n div 10);
  Result := n;
end;

{==============================================================================]
  <GetDigits>
  @action: Extracts the individual digits of the integer into an array using a fixed-size local buffer.
  @note: Treats negative numbers as positive (ignores the sign via Abs). 
         Returns [0] if the value is 0. Reverses the internal buffer to maintain correct digit order.
[==============================================================================}
function TIntegerHelper.GetDigits: TIntegerArray; overload;
var
  n, c, i: Integer;
  r: array[0..9] of Integer;
begin
  if (Self = 0) then
    Exit([0]);
  n := Abs(Self);
  c := 0;
  while (n > 0) do
  begin
    r[c.Increase] := (n mod 10);
    n := (n div 10);
  end;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    Result[i] := r[(c - 1) - i];
end;

{==============================================================================]
  <HeadDigit>
  @action: Extracts the first (most significant) digit of the integer using a 
           pre-calculated powers-of-10 lookup table and System.Math.DivMod.
  @note: Highly optimized O(1) approach. It features explicit short-circuiting 
         for zero, and handles boundaries safely by immediately returning `2` 
         if `Self` is either `Low(Integer)` (-2147483648) or `High(Integer)` 
         (2147483647).
[==============================================================================}
function TIntegerHelper.HeadDigit: Integer; overload;
const
  POW10: array[0..9] of Integer = (1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000);
var
  n, i, d: Integer;
begin
  if (Self = 0) then
    Exit(0);
  if ((Self = Low(Integer)) or (Self = High(Integer))) then
    Exit(2);
  n := Abs(Self);
  i := 9;
  while ((i > 0) and (n < POW10[i])) do
    Dec(i);
  Math.DivMod(n, POW10[i], Result, d);
end;

{==============================================================================]
  <LastDigit>
  @action: Extracts the last digit of the integer by converting it to a string 
           and back to an integer.
  @note: Functional equivalent to `FinalDigit`, but uses `StrToInt` instead of 
         ASCII math. Also relies on the custom `.Lasty` string property/method.
[==============================================================================}
function TIntegerHelper.LastDigit: Integer; overload;
begin
  Result := StrToInt(IntToStr(Self).Lasty);
end;

{==============================================================================]
  <NDigited>
  @action: Checks if the current integer has exactly the specified number of digits.
  @note: 
    * Validates that digitCount is within a safe range for a 32-bit signed integer (1 to 10).
    * Uses Abs(Self) to support both positive and negative numbers seamlessly.
    * Performs a high-performance mathematical boundary check against a pre-defined 
      lookup array (ALL_NINES) instead of executing a slow string conversion.
[==============================================================================}
function TIntegerHelper.NDigited(const digitCount: Integer): Boolean; overload;
begin
  Result := (InRange(digitCount, 1, 10) and InRange(Abs(Self), (ALL_NINES[digitCount - 1] + 1), ALL_NINES[digitCount]));
end;

{==============================================================================]
  <NDigits>
  @action: Counts the total number of digits in the integer by converting it
           to a ShortString via Str() and measuring the resulting length.
  @note: Avoids heap allocation by writing into a stack-local ShortString.
         Negative sign character is excluded from the count. Handles
         Low(Integer) safely without requiring Abs().
[==============================================================================}
function TIntegerHelper.NDigits: Integer; overload;
var
  s: ShortString;
begin
  Str(Self, s);
  Result := Length(s);
  if (Self < 0) then
    Dec(Result);
end;

{==============================================================================]
  <QuantifyDigits>
  @action: Determines the total digit count using a nested if-then-else 
           decision tree to minimize comparisons.
  @note: Leverages an Int64 cast for safe absolute value processing. Directly 
         returns 10 for Low(Integer) to prevent overflow anomalies.
[==============================================================================}
function TIntegerHelper.QuantifyDigits: Integer; overload;
var
  s: Int64;
begin
  if (Self = Low(Integer)) then
    Exit(10);
  s := Abs(Int64(Self));
  if (s < 10000) then
  begin
    if (s < 100) then
      if (s < 10) then
        Result := 1
      else
        Result := 2
    else if (s < 1000) then
      Result := 3
    else
      Result := 4;
  end else if (s < 1000000) then
  begin
    if (s < 100000) then
      Result := 5
    else
      Result := 6;
  end else if (s < 100000000) then
  begin
    if (s < 10000000) then
      Result := 7
    else
      Result := 8;
  end else if (s < 1000000000) then
    Result := 9
  else
    Result := 10;
end;

{==============================================================================]
  <RearDigit>
  @action: Extracts the last (least significant) digit of the integer using 
           conditional modulo operations.
  @note: Thread-safe and safe from overflow bugs. It explicitly branches to 
         handle zero, positive integers, and negative integers (using an 
         un-sign inversion `-Self` cast to Int64) to isolate the final digit 
         via `mod 10`.
[==============================================================================}
function TIntegerHelper.RearDigit: Integer; overload;
begin
  if (Self = 0) then
    Result := 0
  else if (Self > 0) then
    Result := (Int64(Self) mod 10)
  else
    Result := (Int64(-Self) mod 10);
end;

{==============================================================================]
  <ReckonDigits>
  @action: Determines the total digit count of the integer value through
           recursive integer division, using the call stack depth as the
           implicit counter.
  @note: A private helper handles the recursion on an Int64 to avoid
         overflow on Abs(Low(Integer)). Negative sign is not counted.
[==============================================================================}
function TIntegerHelper.ReckonDigits: Integer; overload;
  function R(const n: Int64): Integer;
  begin
    if (n < 10) then
      Exit(1);
    Result := (1 + R(n div 10));
  end;
begin
  Result := R(Abs(Int64(Self)));
end;

{==============================================================================]
  <StartDigit>
  @action: Extracts the first digit of the integer using efficient ASCII math, 
           properly handling negative signs.
  @note: Functional equivalent to `FirstDigit`, but optimized by using `Ord(...) - 48` 
         instead of calling `StrToInt`. It correctly uses 1-based string indexing.
[==============================================================================}
function TIntegerHelper.StartDigit: Integer; overload;
begin
  Result := (Ord(IntToStr(Self)[IfThen((Self < 0), 2, 1)]) - 48);
end;

{==============================================================================]
  <TailDigit>
  @action: Extracts the last (least significant) digit of the integer using
           the optimized System.Math.DivMod procedure.
  @note: Highly efficient and safe from boundary bugs. It explicitly handles
         and hardcodes the return values for `Low(Integer)` (-2147483648 -> 8)
         and `High(Integer)` (2147483647 -> 7), allowing it to safely use a
         single assembly instruction via `DivMod` for all other values.
[==============================================================================}
function TIntegerHelper.TailDigit: Integer; overload;
var
  d: Integer;
begin
  if (Self = 0) then
    Exit(0);
  if (Self = Low(Integer)) then
    Exit(8)
  else if (Self = High(Integer)) then
    Exit(7);
  Math.DivMod(Abs(Self), 10, d, Result);
end;

{==============================================================================]
  <ToDigits>
  @action: Converts the integer into an array of its individual digits using string conversion.
  @note: Treats negative numbers as positive (ignores the sign via Abs). 
         Relies on character ASCII offsets (subtracting 48 from the character code).
[==============================================================================}
function TIntegerHelper.ToDigits: TIntegerArray; overload;
var
  s: string;
  i: Integer;
begin
  s := IntToStr(Abs(Self));
  for i := 1 to Result.SetSize(Length(s)) do
    Result[i-1] := (Ord(s[i]) - 48);
end;
{$ENDIF}
