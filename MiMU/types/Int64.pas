{==============================================================================]
 <Int64_Even>
 @action: Returns true if Int64 value x is an even number.
 @note: None
[==============================================================================}
function Int64_Even(const x: Int64): Boolean; cdecl; inline;
begin
  Result := ((x mod 2) = 0);
end;

{==============================================================================]
 <Int64_Odd>
 @action: Returns true if Int64 value x is an odd number.
 @note: None
[==============================================================================}
function Int64_Odd(const x: Int64): Boolean; cdecl; inline;
begin
  Result := ((x mod 2) <> 0);
end;

{==============================================================================]
 <Int64_Inc>
 @action: Increases the Int64 value x by N.
 @note: Returns the increased x!
[==============================================================================}
function Int64_Inc(var x: Int64; const N: Int64 = 1): Int64; cdecl; inline;
begin
  x := (x + N);
  Result := x;
end;

{==============================================================================]
 <Int64_Dec>
 @action: Decreases the Int64 value x by N.
 @note:  Returns the increased x!
[==============================================================================}
function Int64_Dec(var x: Int64; const N: Int64 = 1): Int64; cdecl;
begin
  Result := x;
  x := (x - N);
end;

{==============================================================================]
 <Int64_Increase>
 @action: Increases the Int64 value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function Int64_Increase(var x: Int64; const N: Int64 = 1): Int64; cdecl; inline;
begin
  Result := x;
  x := (x + N);
end;

{==============================================================================]
  <Int64_Decrease>
 @action: Decreases the Int64 value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function Int64_Decrease(var x: Int64; const N: Int64 = 1): Int64; cdecl;
begin
  Result := x;
  x := (x - N);
end;

{==============================================================================]
 <Int64_DigitCount>
 @action: Returns count of digits Int64 x value contains.
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function Int64_DigitCount(const x: Int64): Int32; cdecl;
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
  until ((Result = 19) or (n = a));
end;

{==============================================================================]
 <Int64_Digitz>
 @action: Converts Int64 value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function Int64_Digitz(const x: Int64): TIntegerArray; cdecl;
var
  a, n, m: Int64;
  i, r: Int32;
begin
  a := Abs(x);
  r := 0;
  SetLength(Result, 19);
  m := 10;
  repeat
    n := (a mod m);
    Result[r] := (n div (m div 10));
    r := (r + 1);
    m := (m * 10);
  until ((r = 19) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[((r - i) - 1)]);
end; 

{==============================================================================]
 <Int64_Digits>
 @action: Converts Int64 value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function Int64_Digits(const x: Int64): TIntegerArray; cdecl;
var
  s: string;
  l, i: Int32;
begin
  s := IntToStr(Abs(x));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[(i + 1)]);
end;

{==============================================================================]
 <Int64_Compare>
 @action: Compares x with target T.
          Results: 0=EQUAL, 1=x>T, -1=x<T
 @note: None
[==============================================================================}
function Int64_Compare(const x, T: Int64): Int32; cdecl; inline;
begin
  if (x = T) then
    Exit(0);
  if (x > T) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <Int64_Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function Int64_Distance(const x, T: Int64): Int64; cdecl; inline;
begin
  Result := Abs(T - x);
end;

{==============================================================================]
 <Int64_Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function Int64_Difference(const x, T: Int64): Int64; cdecl; inline;
begin
  Result := (T - x);
end;

{==============================================================================]
 <Int64_Opposite>
 @action: Returns the opposite number of x. 
          -9999 to 9999 OR 9999 to -9999 (- <=> +) 
 @note: None
[==============================================================================}
function Int64_Opposite(const x: Int64): Int64; cdecl; inline;
begin
  Result := (x * -1);
end;

{==============================================================================]
 <Int64_Sign>
 @action: Indicates whether x value is positive, negative or zero.
          x < 0 = -1            x = 0 = 0             x > 0 = 1
 @note: None
[==============================================================================}
function Int64_Sign(const x: Int64): Int32; cdecl; inline;
begin
  if (x = 0) then
    Exit(0);
  if (x > 0) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <Int64_Random>
 @action: Random() with support for negative Range.
 @note: None
[==============================================================================}
function Int64_Random(const range: Int64): Int64; cdecl;
begin
  Result := Random(Abs(range));
  if (range < 0) then
    Result := (Result * -1);
end;