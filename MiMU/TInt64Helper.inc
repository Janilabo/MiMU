{==============================================================================]
 <TInt64Helper.Even>
 @action: Returns true if Int64 value x is an even number.
 @note: None
[==============================================================================}
function TInt64Helper.Even: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
 <TInt64Helper.Odd>
 @action: Returns true if Int64 value x is an odd number.
 @note: None
[==============================================================================}
function TInt64Helper.Odd: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
 <TInt64Helper.Increase>
 @action: Increases the Int64 value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function TInt64Helper.Increase(const N: Int64 = 1): Int64; cdecl;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <TInt64Helper.Decrease>
 @action: Decreases the Int64 value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const N: Int64 = 1): Int64; cdecl;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
 <TInt64Helper.Increment>
 @action: Increases the Int64 value x by N.
 @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const N: Int64 = 1): Int64; cdecl;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <TInt64Helper.Decrement>
 @action: Decreases the Int64 value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const N: Int64 = 1): Int64; cdecl;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
 <TInt64Helper.DigitCount>
 @action: Returns count of digits Int64 x value contains.
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.DigitCount: Integer; cdecl;
var
  a, n, m: Int64;
begin
  a := Abs(Self);
  Result := 0;
  m := 10;
  repeat
    n := (a mod m);
    Result := (Result + 1);
    m := (m * 10);
  until ((Result = 19) or (n = a));
end;

{==============================================================================]
 <TInt64Helper.Digitz>
 @action: Converts Int64 value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.Digitz: TIntegerArray; cdecl;
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
    r := (r + 1);
    m := (m * 10);
  until ((r = 19) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[((r - i) - 1)]);
end; 

{==============================================================================]
 <TInt64Helper.Digits>
 @action: Converts Int64 value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.Digits: TIntegerArray; cdecl;
var
  s: string;
  l, i: Integer;
begin
  s := IntToStr(Abs(Self));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[(i + 1)]);
end;

{==============================================================================]
 <TInt64Helper.Compare>
 @action: Compares x with target T.
          Results: 0=EQUAL, 1=x>T, -1=x<T
 @note: None
[==============================================================================}
function TInt64Helper.Compare(const T: Int64): Integer; cdecl; inline;
begin
  if (Self = T) then
    Exit(0);
  if (Self > T) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <TInt64Helper.Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function TInt64Helper.Distance(const T: Int64): Int64; cdecl; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
 <TInt64Helper.Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function TInt64Helper.Difference(const T: Int64): Int64; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
 <TInt64Helper.Opposite>
 @action: Returns the opposite number of x. 
          -9999 to 9999 OR 9999 to -9999 (- <=> +) 
 @note: None
[==============================================================================}
function TInt64Helper.Opposite: Int64; cdecl; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
 <TInt64Helper.Sign>
 @action: Indicates whether x value is positive, negative or zero.
          x < 0 = -1            x = 0 = 0             x > 0 = 1
 @note: None
[==============================================================================}
function TInt64Helper.Sign: Integer; cdecl; inline;
begin
  if (Self = 0) then
    Exit(0);
  if (Self > 0) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <TInt64Helper.Shuffle>
 @action: Random() with support for negative Range.
 @note: None
[==============================================================================}
function TInt64Helper.Shuffle: Int64; cdecl;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;

{==============================================================================]
 <TInt64Helper.Oversize>
 @action: Returns true if x is higher than limit.
 @note: None
[==============================================================================}
function TInt64Helper.Oversize(const limit: Int64): Boolean; cdecl; inline;
begin
  Result := (Self > limit);
end;

{==============================================================================]
 <TInt64Helper.Undersize>
 @action: Returns true if x is lower than limit.
 @note: None
[==============================================================================}
function TInt64Helper.Undersize(const limit: Int64): Boolean; cdecl; inline;
begin
  Result := (Self < limit);
end;