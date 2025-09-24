{==============================================================================]
 <TDoubleHelper.ClampMin>
 @action: Returns Double clamped by minimum limit
 @note: None
[==============================================================================}
function TDoubleHelper.ClampMin(const limit: Double): Double; cdecl; {$DEFINE Skeleton_ClampMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
 <TDoubleHelper.ClampMax>
 @action: Returns Double clamped by maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.ClampMax(const limit: Double): Double; cdecl; {$DEFINE Skeleton_ClampMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
 <TDoubleHelper.Clamp>
 @action: Returns Double clamped by minimum and maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.Clamp(const minimum, maximum: Double): Double; cdecl; {$DEFINE Skeleton_Clamp}{$I config\Skeletons.inc}{$UNDEF Skeleton_Clamp}

{==============================================================================]
 <TDoubleHelper.BoundMin>
 @action: Returns Double bounded by minimum limit
 @note: None
[==============================================================================}
function TDoubleHelper.BoundMin(const limit: Double): Double; cdecl;
begin
  Result := (((Self + limit) + Abs(Self - limit)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.BoundMax>
 @action: Returns Double bounded by maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.BoundMax(const limit: Double): Double; cdecl;
begin
  Result := (((Self + limit) - Abs(Self - limit)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.Bound>
 @action: Returns Double bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TDoubleHelper.Bound(const minimum, maximum: Double): Double; cdecl;
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) / 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.RestrictMin>
 @action: Returns Double bounded by minimum limit
 @note: None
[==============================================================================}
function TDoubleHelper.RestrictMin(const limit: Double): Double; cdecl;
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.RestrictMax>
 @action: Returns Double bounded by maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.RestrictMax(const limit: Double): Double; cdecl;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.Restrict>
 @action: Returns Double bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TDoubleHelper.Restrict(const minimum, maximum: Double): Double; cdecl;
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) / 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) / 2);
end;

{==============================================================================]
 <TDoubleHelper.LimitMin>
 @action: Returns Double with minimum limit
 @note: Max() call.
[==============================================================================}
function TDoubleHelper.LimitMin(const limit: Double): Double; cdecl; {$DEFINE Skeleton_LimitMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
 <TDoubleHelper.LimitMax>
 @action: Returns Double with maximum limit
 @note: Min() call.
[==============================================================================}
function TDoubleHelper.LimitMax(const limit: Double): Double; cdecl; {$DEFINE Skeleton_LimitMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
 <TDoubleHelper.Limit>
 @action: Returns Double with minimum and maximum limits
 @note: EnsureRange() call.
[==============================================================================}
function TDoubleHelper.Limit(const minimum, maximum: Double): Double; cdecl; {$DEFINE Skeleton_Limit}{$I config\Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
 <TDoubleHelper.ConstraintMin>
 @action: Returns true if Double is constrainted with minimum limit
 @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMin(const limit: Double): Boolean; cdecl; {$DEFINE Skeleton_ConstraintMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
 <TDoubleHelper.ConstraintMax>
 @action: Returns true if Double is constrainted with maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMax(const limit: Double): Boolean; cdecl; {$DEFINE Skeleton_ConstraintMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
 <TDoubleHelper.Constraint>
 @action: Returns true if Double is constrainted with minimum or maximum limit
 @note: None
[==============================================================================}
function TDoubleHelper.Constraint(const minimum, maximum: Double): Boolean; cdecl; {$DEFINE Skeleton_Constraint}{$I config\Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
 <TDoubleHelper.Increase>
 @action: Increases the Double value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function TDoubleHelper.Increase(const N: Double = 1): Double; cdecl; {$DEFINE Skeleton_Increase}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <TDoubleHelper.Decrease>
 @action: Decreases the Double value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function TDoubleHelper.Decrease(const N: Double = 1): Double; cdecl; {$DEFINE Skeleton_Decrease}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
 <TDoubleHelper.Increment>
 @action: Increases the Double value x by N.
 @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const N: Double = 1): Double; cdecl; {$DEFINE Skeleton_Increment}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <TDoubleHelper.Decrement>
 @action: Decreases the Double value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const N: Double = 1): Double; cdecl; {$DEFINE Skeleton_Decrement}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrement}

{==============================================================================]
 <TDoubleHelper.Digits>
 @action: Converts Double value (x) to digits of it.
          Example: 1234 => 1,2,3,4, -999 => 9,9,9
 @note: If x is negative value, the negative sign is ignored. 
[==============================================================================}
function TDoubleHelper.Digits: TIntegerArray; cdecl;
var
  s: string;
  l, i: Integer;
begin
  s := FloatToStr(Abs(Self));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[i + 1]);
end;

{==============================================================================]
 <TDoubleHelper.NegA>
 @action: Returns the negative number of x. 
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function TDoubleHelper.NegA: Double; cdecl; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
 <TDoubleHelper.Neg>
 @action: Returns the negative number of i. 
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function TDoubleHelper.Neg: Double; cdecl; inline;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end; 

{==============================================================================]
 <TDoubleHelper.Negative>
 @action: Returns True if Double value x is lower than 0 (negative), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Negative: Boolean; cdecl; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
 <TDoubleHelper.Positive>
 @action: Returns True if Double value x is higher than 0 (positive), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Positive: Boolean; cdecl; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
 <TDoubleHelper.Neutral>
 @action: Returns True if Double value x is 0 (neutral), otherwise False. 
 @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Neutral: Boolean; cdecl; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
 <TDoubleHelper.MinDecimal>
 @action: Returns the minimum decimal value.
          0.12345 => 0.00001
 @note: None
[==============================================================================}
function TDoubleHelper.MinDecimal: Double; cdecl;
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else
    if (d < 0) then
      Result := StrToFloat('-0,' + StringOfChar('0', (Length(FloatToStr(d)) - 4)) + '1')
    else
      Result := StrToFloat('0,' + StringOfChar('0', (Length(FloatToStr(d)) - 3)) + '1');
end;

{==============================================================================]
 <TDoubleHelper.MaxDecimal>
 @action: Returns the maximum decimal value.
          0.12345 => 0.99999
 @note: None
[==============================================================================}
function TDoubleHelper.MaxDecimal: Double; cdecl;
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else
    if (d < 0) then
      Result := StrToFloat('-0,' + StringOfChar('9', (Length(FloatToStr(d)) - 3)))
    else
      Result := StrToFloat('0,' + StringOfChar('9', (Length(FloatToStr(d)) - 2)));
end;

{==============================================================================]
 <TDoubleHelper.Acc>
 @action: Returns x with decimal accuracy of a. Examples below with '123.456789'.
          a=0    a=1     a=2       a=3       a=4         a=5
          123   123.4   123.45   123.456   123.4567   123.45678
 @note: None
[==============================================================================}
function TDoubleHelper.Accuracy(const a: Integer): Double; cdecl;
var
  d: Double;
  z: Boolean;
begin
  if (a < 1) then
    Exit(Self);
  Result := Int(Real(Self));
  d := Frac(Self);
  z := (d < 0.1);
  if z then
    d := (d + 0.1);
  Result := (Result + StrToFloatDef((',' + Copy(FloatToStr(d), 3, a)), 0));
  if z then
    Result := (Result - 0.1);
end;

{==============================================================================]
 <TDoubleHelper.Compare>
 @action: Compares x with target target.
          Results: 0=EQUAL, 1=x>target, -1=x<target
 @note: None
[==============================================================================}
function TDoubleHelper.Compare(const target: Double): Integer; cdecl; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
 <TDoubleHelper.Precede>
 @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
 @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TDoubleHelper.Precede(const target: Double; const aAscending: Boolean): Boolean; overload; cdecl; {$DEFINE Skeleton_Precede}{$I config\Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
 <Double_Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function TDoubleHelper.Distance(const T: Double): Double; cdecl; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
 <TDoubleHelper.Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function TDoubleHelper.Difference(const T: Double): Double; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
 <TDoubleHelper.Opposite>
 @action: Returns the opposite number of x. 
          -9999 to 9999 OR 9999 to -9999 (- <=> +) 
 @note: None
[==============================================================================}
function TDoubleHelper.Opposite: Double; cdecl; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
 <Double_Sign>
 @action: Indicates whether x value is positive, negative or zero.
          x < 0 = -1            x = 0 = 0             x > 0 = 1
 @note: None
[==============================================================================}
function TDoubleHelper.Sign: Integer; cdecl; inline;
begin
  if (Self = 0) then
    Exit(0);
  if (Self > 0) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
 <TDoubleHelper.FixDegrees>
 @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
 @note: None
[==============================================================================}
function TDoubleHelper.FixDegrees: Double; cdecl;
var
  t: Integer;
begin
  t := -1;
  if (Self > -1) then
    t := Abs(t);
  Result := Abs(Self);
  Result := ((Floor(Result) mod 360 + Frac(Result)) * t);
  if (Result < 0) then
    Result := (Result + 360.0);
end;

{==============================================================================]
 <TDoubleHelper.Degrees>
 @action: Converts Radians to Degrees.
 @note: None
[==============================================================================} 
function TDoubleHelper.Degrees: Double; cdecl;
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := r.FixDegrees;
end;

{==============================================================================]
 <TDoubleHelper.FixRadians>
 @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
 @note: None
[==============================================================================}
function TDoubleHelper.FixRadians: Double; cdecl;
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := (r.FixDegrees * (Pi / 180.0));
end;

{==============================================================================]
 <TDoubleHelper.Radians>
 @action: Converts Degrees or Compass (degrees) to Radians.
 @note: Supports compass.
[==============================================================================}
function TDoubleHelper.Radians(const compass: Boolean = False): Double; cdecl;
var
  d: Double;
begin
  if not compass then
    d := (Self * (Pi / 180.0))
  else
    d := ((Self - 90.0) * (Pi / 180.0));
  Result := d.FixRadians;
end;

{==============================================================================]
 <TDoubleHelper.Percent>
 @action: Returns percent (%) from x by position.
 @note: Value-to-Percent conversion!
[==============================================================================}
function TDoubleHelper.Percent(const position: Double): Double; cdecl; inline;
begin
  if (position <> 0) then
    Result := ((position / Self) * 100.0)
  else
    Result := 0.0;
end;

{==============================================================================]
 <TDoubleHelper.Percentage>
 @action: Returns value from x by percent.
 @note: Percent-to-Value conversion!
[==============================================================================}
function TDoubleHelper.Percentage(const percent: Double): Double; cdecl; inline;
begin
  if (percent <> 0) then
    Result := ((percent / 100.0) * Self)
  else
    Result := 0.0;
end;

{==============================================================================]
 <TDoubleHelper.Over>
 @action: Returns true if x is higher than target.
 @note: None
[==============================================================================}
function TDoubleHelper.Over(const target: Double): Boolean; cdecl; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
 <TDoubleHelper.Oversize>
 @action: Returns true if x is higher than limit.
 @note: None
[==============================================================================}
function TDoubleHelper.Oversize(const limit: Double): Boolean; cdecl;
begin
  Result := (Self > limit);
end;

{==============================================================================]
 <TDoubleHelper.Under>
 @action: Returns true if x is lower than target.
 @note: None
[==============================================================================}
function TDoubleHelper.Under(const target: Double): Boolean; cdecl; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
 <Double_Undersize>
 @action: Returns true if x is lower than limit.
 @note: None
[==============================================================================}
function TDoubleHelper.Undersize(const limit: Double): Boolean; cdecl;
begin
  Result := (Self < limit);
end;
