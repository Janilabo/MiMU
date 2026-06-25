{$IFDEF HELPERS}
function CountDigits: Integer; overload;
function DigitAmount: Integer; overload;
function DigitCount: Integer; overload;
function DigitCounter: Integer; overload;
function DigitQuantity: Integer; overload;
function Digits: TIntegerArray; overload;
function DigitsAmount: Integer; overload;
function DigitsCount: Integer; overload;
function DigitsCounted: Integer; overload;
function DigitsQuantity: Integer; overload;
function Digitz: TIntegerArray; overload;
function QuantifyDigits: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CountDigits>
  @action: Counts and returns the total number of digits in a 64-bit signed integer (Int64).
  @note: Correctly handles negative numbers by using their absolute value, and includes a 
         hardcoded boundary check for Low(Int64) to prevent integer overflow errors.
[==============================================================================}
function TInt64Helper.CountDigits: Integer; overload;
begin
  if (Self = Low(Int64)) then
    Exit(19);
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
    1000000000..9999999999: Result := 10;
    10000000000..99999999999: Result := 11;
    100000000000..999999999999: Result := 12;
    1000000000000..9999999999999: Result := 13;
    10000000000000..99999999999999: Result := 14;
    100000000000000..999999999999999: Result := 15;
    1000000000000000..9999999999999999: Result := 16;
    10000000000000000..99999999999999999: Result := 17;
    100000000000000000..999999999999999999: Result := 18;
  else
    Result := 19;
  end;
end;

{==============================================================================]
  <DigitAmount>
  @action: Calculates and returns the number of digits in a 64-bit signed integer (Int64).
  @note: Uses a loop to compare the absolute value of the integer against an array of 
         upper-bound thresholds (ALL_NINES). Safely handles Low(Int64) explicitly 
         to prevent integer overflow on negation.
[==============================================================================}
function TInt64Helper.DigitAmount: Integer; overload;
var
  n: Int64;
  i: Integer;
begin
  if (Self = Low(Int64)) then
    Exit(19);
  n := Abs(Self);
  for i := 1 to 18 do
    if (n <= NINES_TABLE[i]) then
      Exit(i);
  Result := 19;
end;

{==============================================================================]
  <DigitCount>
  @action: Returns count of digits Int64 x value contains.
  @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807!
[==============================================================================}
function TInt64Helper.DigitCount: Integer; overload;
var
  a, n, m: Int64;
begin
  a := Abs(Self);
  Result := 0;
  m := 10;
  repeat
    n := (a mod m);
    m := (m * 10);
  until ((Result.Increment = 19) or (n = a));
end;

{==============================================================================]
  <DigitCounter>
  @action: Determines the total number of digits in a 64-bit signed integer (Int64) 
           using a binary search algorithm.
  @note: Leverages a precalculated array of powers of ten (POWERS_OF_TEN) to find 
         the digit count in O(log N) time. Explicitly handles 0 and Low(Int64) 
         as edge cases to prevent logic or overflow issues.
[==============================================================================}
function TInt64Helper.DigitCounter: Integer; overload;
var
  s: Int64;
  h, m: Integer;
begin
  if (Self = 0) then
    Exit(1);
  if (Self = Low(Int64)) then
    Exit(19);
  s := Abs(Self);
  Result := 1;
  h := 19;
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
  <DigitQuantity>
  @action: Calculates the number of digits in a 64-bit signed integer (Int64) by 
           converting the value into a string and checking its length.
  @note: Accounts for the negative sign character ('-') in negative integers by 
         subtracting 1 from the string length, and explicitly handles 0.
[==============================================================================}
function TInt64Helper.DigitQuantity: Integer; overload;
begin
  if (Self = 0) then
    Result := 1
  else if (Self > 0) then
    Result := Length(IntToStr(Self))
  else
    Result := (Length(IntToStr(Self)) - 1);
end;

{==============================================================================]
  <Digits>
  @action: Converts Int64 value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -9223372036854775808 - 9223372036854775807!
[==============================================================================}
function TInt64Helper.Digits: TIntegerArray; overload;
var
  s: string;
  l, i: Integer;
begin
  s := IntToStr(Abs(Self));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[i + 1]);
end;

{==============================================================================]
  <DigitsAmount>
  @action: Calculates the number of digits in a 64-bit signed integer (Int64) 
           using a logarithmic mathematical formula.
  @note: Uses the base-10 logarithm of the absolute value, rounded down via Floor 
         and incremented by 1. Requires explicit checks for 0 (logarithm undefined) 
         and Low(Int64) (avoids absolute value overflow).
[==============================================================================}
function TInt64Helper.DigitsAmount: Integer; overload;
begin
  if (Self = 0) then
    Exit(1);
  if (Self = Low(Int64)) then
    Exit(19);
  Result := (Floor(Log10(Abs(Self))) + 1);
end;

{==============================================================================]
  <DigitsCount>
  @action: Counts the number of digits in a 64-bit signed integer (Int64) by 
           repeatedly dividing the value by 10.
  @note: Uses a loop-based truncation technique (division by 10) on the absolute 
         value until it reaches 0. Bypasses Low(Int64) explicitly to prevent an 
         integer overflow on negation.
[==============================================================================}
function TInt64Helper.DigitsCount: Integer; overload;
var
  s: Int64;
begin
  if (Self = Low(Int64)) then
    Exit(19);
  Result := 0;
  s := Abs(Self);
  repeat
    s := (s div 10);
    Inc(Result);
  until (s = 0);
end;

{==============================================================================]
  <DigitsCounted>
  @action: Calculates the total number of digits in a 64-bit signed integer (Int64) 
           using sequential less-than comparisons against powers of ten.
  @note: Leverages a series of unrolled linear conditional checks for optimal branch 
         prediction in low-digit scenarios. Safely traps Low(Int64) up front 
         to prevent negation overflow.
[==============================================================================}
function TInt64Helper.DigitsCounted: Integer; overload;
begin
  if (Self = Low(Int64)) then
    Exit(19);
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
  if (Result < 10000000000) then
    Exit(10);
  if (Result < 100000000000) then
    Exit(11);
  if (Result < 1000000000000) then
    Exit(12);
  if (Result < 10000000000000) then
    Exit(13);
  if (Result < 100000000000000) then
    Exit(14);
  if (Result < 1000000000000000) then
    Exit(15);
  if (Result < 10000000000000000) then
    Exit(16);
  if (Result < 100000000000000000) then
    Exit(17);
  if (Result < 1000000000000000000) then
    Exit(18);
  Result := 19;
end;

{==============================================================================]
  <DigitsQuantity>
  @action: Counts the total number of digits in a 64-bit signed integer (Int64) 
           using a nested, hardcoded binary search tree structure.
  @note: Uses nested boolean case statements to split the search space efficiently, 
         minimizing the number of comparisons required for any given value. Bypasses 
         Low(Int64) up front to avoid negation overflow.
[==============================================================================}
function TInt64Helper.DigitsQuantity: Integer; overload;
var
  V: Int64;
begin
  if (Self = Low(Int64)) then
    Exit(19);
  V := Abs(Self);
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
        case (V < 10000000000) of
          True:
          if (V < 1000000000) then
		        Result := 9
          else
		        Result := 10;
          False:
          case (V < 1000000000000) of
            True:
            if (V < 100000000000) then
			        Result := 11
            else
			        Result := 12;
            False:
            case (V < 100000000000000) of
              True:
              if (V < 10000000000000) then
			          Result := 13
              else
			          Result := 14;
              False:
              case (V < 10000000000000000) of
                True:
                if (V < 1000000000000000) then
				          Result := 15
                else
				          Result := 16;
                False:
                if (V < 100000000000000000) then
                  Result := 17
                else if (V < 1000000000000000000) then
                  Result := 18
                else
                  Result := 19;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <Digitz>
  @action: Converts Int64 value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -9223372036854775808 - 9223372036854775807!
[==============================================================================}
function TInt64Helper.Digitz: TIntegerArray; overload;
var
  a, n, m: Int64;
  i, r: Integer;
begin
  a := Abs(Self);
  r := 0;
  SetLength(Result, 19);
  m := 10;
  repeat
    n := (a mod m);
    Result[r] := (n div (m div 10));
    m := (m * 10);
  until ((r.Increment = 19) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[(r - i) - 1]);
end;

{==============================================================================]
  <QuantifyDigits>
  @action: Calculates the total number of digits in a 64-bit signed integer (Int64) 
           using an unrolled binary search tree based on if-then-else statements.
  @note: Implements a flat, nested conditional logic branch structure to split the 
         search domain efficiently. Safely handles Low(Int64) at the entry point 
         to eliminate absolute value overflow risks.
[==============================================================================}
function TInt64Helper.QuantifyDigits: Integer; overload;
var
  s: Int64;
begin
  if (Self = Low(Int64)) then
    Exit(19);
  s := Abs(Self);
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
  end else if (s < 10000000000) then
  begin
    if (s < 1000000000) then
      Result := 9
    else
      Result := 10;
  end else if (s < 1000000000000) then
  begin
    if (s < 100000000000) then
      Result := 11
    else
      Result := 12;
  end else if (s < 100000000000000) then
  begin
    if (s < 10000000000000) then
      Result := 13
    else
      Result := 14;
  end else if (s < 10000000000000000) then
  begin
    if (s < 1000000000000000) then
      Result := 15
    else
      Result := 16;
  end else if (s < 1000000000000000000) then
  begin
    if (s < 100000000000000000) then
      Result := 17
    else
      Result := 18;
  end else
    Result := 19;
end;
{$ENDIF}
