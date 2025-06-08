{==============================================================================]
 <Integer_Even>
 @action: Returns true if Integer value x is an even number.
 @note: None
[==============================================================================}
function Integer_Even(const x: Integer): Boolean; cdecl; inline;
begin
  Result := ((x mod 2) = 0);
end;

{==============================================================================]
 <Integer_Odd>
 @action: Returns true if Integer value x is an odd number.
 @note: None
[==============================================================================}
function Integer_Odd(const x: Integer): Boolean; cdecl; inline;
begin
  Result := ((x mod 2) <> 0);
end;

{==============================================================================]
 <Integer_Inc>
 @action: Increases the x value by N.
 @note: Returns the increased x!
[==============================================================================}
function Integer_Inc(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Result := x;
  Inc(x, N);
end;

{==============================================================================]
 <Integer_Dec>
 @action: Decreases the x value by N.
 @note: Returns the increased x!
[==============================================================================}
function Integer_Dec(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Result := x;
  Dec(x, N);
end;

{==============================================================================]
 <Integer_Increase>
 @action: Increases the Integer value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function Integer_Increase(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Result := x;
  x := (x + N);
end;

{==============================================================================]
  <Integer_Decrease>
 @action: Decreases the Integer value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function Integer_Decrease(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Result := x;
  x := (x - N);
end;

{==============================================================================]
 <Integer_Increment>
 @action: Increases the Integer value x by N.
 @note: Returns the increased x!
[==============================================================================}
function Integer_Increment(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  x := (x + N);
  Result := x;
end;

{==============================================================================]
  <Integer_Decrement>
 @action: Decreases the Integer value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function Integer_Decrement(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  x := (x - N);
  Result := x;
end;

{==============================================================================]
 <Integer_Increment>
 @action: Increases the Integer value x by N.
 @note: Returns the increased x!
[==============================================================================}
function Integer_Incr(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Inc(x, N);
  Result := x;
end;

{==============================================================================]
  <Integer_Decrement>
 @action: Decreases the Integer value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function Integer_Decr(var x: Integer; const N: Integer = 1): Integer; cdecl;
begin
  Dec(x, N);
  Result := x;
end;

{==============================================================================]
 <Integer_DigitCount>
 @action: Returns count of digits Integer x value contains.
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647! 
[==============================================================================}
function Integer_DigitCount(const x: Integer): Integer; cdecl;
var
  a, n, m: Int64;
begin
  a := Abs(x);
  Result := 0;
  m := 10;
  repeat
    n := (a mod m);
    Result := (Result + 1);
    m := (m * 10);
  until ((Result = 10) or (n = a));
end;

{==============================================================================]
 <Integer_Digitz>
 @action: Converts Integer value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647! 
[==============================================================================}
function Integer_Digitz(const x: Integer): TIntegerArray; cdecl;
var
  a, n, m: Int64;
  i, r: Integer;
begin
  a := Abs(x);
  r := 0;
  SetLength(Result, 10);
  m := 10;
  repeat
    n := (a mod m);
    Result[r] := (n div (m div 10));
    r := (r + 1);
    m := (m * 10);
  until ((r = 10) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[((r - i) - 1)]);
end;

{==============================================================================]
 <Integer_Digits>
 @action: Converts Integer value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647! 
[==============================================================================}
function Integer_Digits(const x: Integer): TIntegerArray; cdecl;
var
  s: string;
  l, i: Integer;
begin
  s := IntToStr(Abs(x));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[(i + 1)]);
end;

{==============================================================================]
 <Integer_NegA>
 @action: Returns the negative number of x. 
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function Integer_NegA(const x: Integer): Integer; cdecl; inline;
begin
  Result := (Abs(x) * -1);
end;

{==============================================================================]
 <Integer_Neg>
 @action: Returns the negative number of x. 
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function Integer_Neg(const x: Integer): Integer; cdecl; inline;
begin
  if (x > -1) then
    Result := (x * -1)
  else
    Result := x;
end;

{==============================================================================]
 <Integer_Negative>
 @action: Returns True if Integer value x is lower than 0 (negative), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function Integer_Negative(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (x < 0);
end;

{==============================================================================]
 <Integer_Negative>
 @action: Returns True if Integer value x is higher than 0 (positive), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function Integer_Positive(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (x > 0);
end;

{==============================================================================]
 <Integer_Negative>
 @action: Returns True if Integer value x is 0 (neutral), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function Integer_Neutral(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (x = 0);
end;

{==============================================================================]
 <Integer_Compare>
 @action: Compares x with target T.
          Results: 0=EQUAL, 1=x>T, -1=x<T
 @note: None
[==============================================================================}
function Integer_Compare(const x, T: Integer): Integer; cdecl; inline;
begin
  if (x = T) then
    Exit(0);
  if (x > T) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <Integer_Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function Integer_Distance(const x, T: Integer): Integer; cdecl; inline;
begin
  Result := Abs(T - x);
end;

{==============================================================================]
 <Integer_Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function Integer_Difference(const x, T: Integer): Integer; cdecl; inline;
begin
  Result := (T - x);
end;

{==============================================================================]
 <Integer_Opposite>
 @action: Returns the opposite number of x. 
          -9999 to 9999 OR 9999 to -9999 (- <=> +) 
 @note: None
[==============================================================================}
function Integer_Opposite(const x: Integer): Integer; cdecl; inline;
begin
  Result := (x * -1);
end;

{==============================================================================]
 <Integer_Sign>
 @action: Indicates whether x value is positive, negative or zero.
          x < 0 = -1            x = 0 = 0             x > 0 = 1
 @note: None
[==============================================================================}
function Integer_Sign(const x: Integer): Integer; cdecl; inline;
begin
  if (x = 0) then
    Exit(0);
  if (x > 0) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <Integer_Random>
 @action: Random() with support for negative Range.
 @note: None
[==============================================================================}
function Integer_Random(const range: Integer): Integer; cdecl;
begin
  Result := Random(Abs(range));
  if (range < 0) then
    Result := (Result * -1);
end;

{==============================================================================]
 <Integer_Oversize>
 @action: Returns true if x is higher than limit.
 @note: None
[==============================================================================}
function Integer_Oversize(const x, limit: Integer): Boolean; cdecl; inline;
begin
  Result := (x > limit);
end;

{==============================================================================]
 <Integer_Undersize>
 @action: Returns true if x is lower than limit.
 @note: None
[==============================================================================}
function Integer_Undersize(const x, limit: Integer): Boolean; cdecl; inline;
begin
  Result := (x < limit);
end;