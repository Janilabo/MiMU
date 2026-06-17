{$IFDEF HELPERS}
function DigitCount: Integer; overload;
function Digits: TIntegerArray; overload;
function Digitz: TIntegerArray; overload;
function FinalDigit: Integer; overload;
function FirstDigit: Integer; overload;
function LastDigit: Integer; overload;
function StartDigit: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DigitCount>
  @action: Returns count of digits Integer x value contains.
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.DigitCount: Integer;
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
  <Digits>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digits: TIntegerArray;
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
  <Digitz>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digitz: TIntegerArray;
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
{$ENDIF}
