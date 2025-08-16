{==============================================================================]
 <TIntegerHelper.ClampMin>
 @action: Returns Integer clamped by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ClampMin(const limit: Integer): Integer; cdecl; {$DEFINE Skeleton_ClampMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
 <TIntegerHelper.ClampMax>
 @action: Returns Integer clamped by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ClampMax(const limit: Integer): Integer; cdecl; {$DEFINE Skeleton_ClampMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
 <TIntegerHelper.Clamp>
 @action: Returns Integer clamped by minimum and maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const minimum, maximum: Integer): Integer; overload; cdecl; {$DEFINE Skeleton_Clamp}{$I config\Skeletons.inc}{$UNDEF Skeleton_Clamp}

{==============================================================================]
 <TIntegerHelper.Clamp>
 @action: Returns Integer clamped by minimum and maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const range: TRange): Integer; overload; cdecl;
begin
  Result := Self.ClampMin(range.Minimum);
  if (Self = Result) then
    Result := Self.ClampMax(range.Maximum);
end;

{==============================================================================]
 <TIntegerHelper.BoundMin>
 @action: Returns Integer bounded by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.BoundMin(const limit: Integer): Integer; cdecl;
begin
  Result := (((Self + limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.BoundMax>
 @action: Returns Integer bounded by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.BoundMax(const limit: Integer): Integer; cdecl;
begin
  Result := (((Self + limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.Bound>
 @action: Returns Integer bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TIntegerHelper.Bound(const minimum, maximum: Integer): Integer; cdecl;
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) div 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.RestrictMin>
 @action: Returns Integer bounded by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.RestrictMin(const limit: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.RestrictMax>
 @action: Returns Integer bounded by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.RestrictMax(const limit: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.Restrict>
 @action: Returns Integer bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TIntegerHelper.Restrict(const minimum, maximum: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) div 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.LimitMin>
 @action: Returns Integer with minimum limit
 @note: Max() call.
[==============================================================================}
function TIntegerHelper.LimitMin(const limit: Integer): Integer; cdecl; {$DEFINE Skeleton_LimitMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
 <TIntegerHelper.LimitMax>
 @action: Returns Integer with maximum limit
 @note: Min() call.
[==============================================================================}
function TIntegerHelper.LimitMax(const limit: Integer): Integer; cdecl; {$DEFINE Skeleton_LimitMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
 <TIntegerHelper.Limit>
 @action: Returns Integer with minimum and maximum limits
 @note: EnsureRange() call.
[==============================================================================}
function TIntegerHelper.Limit(const minimum, maximum: Integer): Integer; cdecl; {$DEFINE Skeleton_Limit}{$I config\Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
 <TIntegerHelper.ConstraintMin>
 @action: Returns true if Integer is constrainted with minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMin(const limit: Integer): Boolean; cdecl; {$DEFINE Skeleton_ConstraintMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
 <TIntegerHelper.ConstraintMax>
 @action: Returns true if Integer is constrainted with maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMax(const limit: Integer): Boolean; cdecl; {$DEFINE Skeleton_ConstraintMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
 <TIntegerHelper.Constraint>
 @action: Returns true if Integer is constrainted with minimum or maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const minimum, maximum: Integer): Boolean; overload; cdecl; {$DEFINE Skeleton_Constraint}{$I config\Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
 <TIntegerHelper.Contstraint>
 @action: Returns true if Integer is constrainted with range
 @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload; cdecl;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
end;

{==============================================================================]
 <TIntegerHelper.Even>
 @action: Returns true if Integer value x is an even number.
 @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
 <TIntegerHelper.Odd>
 @action: Returns true if Integer value x is an odd number.
 @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
 <TIntegerHelper.Increase>
 @action: Increases the Integer value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function TIntegerHelper.Increase(const N: Integer = 1): Integer; cdecl; {$DEFINE Skeleton_Increase}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <TIntegerHelper.Decrease>
 @action: Decreases the Integer value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function TIntegerHelper.Decrease(const N: Integer = 1): Integer; cdecl; {$DEFINE Skeleton_Decrease}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
 <TIntegerHelper.Increment>
 @action: Increases the Integer value x by N.
 @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const N: Integer = 1): Integer; cdecl; {$DEFINE Skeleton_Increment}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <TIntegerHelper.Decrement>
 @action: Decreases the Integer value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const N: Integer = 1): Integer; cdecl; {$DEFINE Skeleton_Decrement}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrement} 

{==============================================================================]
 <TIntegerHelper.DigitCount>
 @action: Returns count of digits Integer x value contains.
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.DigitCount: Integer; cdecl;
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
 <TIntegerHelper.Digitz>
 @action: Converts Integer value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digitz: TIntegerArray; cdecl;
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
 <TIntegerHelper.Digits>
 @action: Converts Integer value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored.
        Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digits: TIntegerArray; cdecl;
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
 <TIntegerHelper.NegA>
 @action: Returns the negative number of x.
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; cdecl; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
 <TIntegerHelper.Neg>
 @action: Returns the negative number of x.
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer; cdecl; inline;
begin
  if (Self > -1) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
 <TIntegerHelper.Negative>
 @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean; cdecl; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
 <TIntegerHelper.Positive>
 @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; cdecl; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
 <TIntegerHelper.Neutral>
 @action: Returns True if Integer value x is 0 (neutral), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; cdecl; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
 <TIntegerHelper.Compare>
 @action: Compares x with target target.
          Results: 0=EQUAL, 1=x>target, -1=x<target
 @note: None
[==============================================================================}
function TIntegerHelper.Compare(const target: Integer): Integer; cdecl; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
 <TIntegerHelper.Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; cdecl; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
 <TIntegerHelper.Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
 <TIntegerHelper.Opposite>
 @action: Returns the opposite number of x.
          -9999 to 9999 OR 9999 to -9999 (- <=> +)
 @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer; cdecl; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
 <TIntegerHelper.Sign>
 @action: Indicates whether x value is positive, negative or zero.
          x < 0 = -1            x = 0 = 0             x > 0 = 1
 @note: None
[==============================================================================}
function TIntegerHelper.Sign: Integer; cdecl; inline;
begin
  if (Self = 0) then
    Exit(0);
  if (Self > 0) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <TIntegerHelper.Shuffle>
 @action: Random() with support for negative Range (based on x value).
 @note: None
[==============================================================================}
function TIntegerHelper.Shuffle: Integer; cdecl;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;

{==============================================================================]
 <TIntegerHelper.Over>
 @action: Returns true if x is higher than target.
 @note: None
[==============================================================================}
function TIntegerHelper.Over(const target: Integer): Boolean; cdecl; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
 <TIntegerHelper.Oversize>
 @action: Returns true if x is higher than limit.
 @note: None
[==============================================================================}
function TIntegerHelper.Oversize(const limit: Integer): Boolean; cdecl; inline;
begin
  Result := (Self > limit);
end;

{==============================================================================]
 <TIntegerHelper.Under>
 @action: Returns true if x is lower than target.
 @note: None
[==============================================================================}
function TIntegerHelper.Under(const target: Integer): Boolean; cdecl; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
 <TIntegerHelper.Undersize>
 @action: Returns true if x is lower than limit.
 @note: None
[==============================================================================}
function TIntegerHelper.Undersize(const limit: Integer): Boolean; cdecl; inline;
begin
  Result := (Self < limit);
end;
