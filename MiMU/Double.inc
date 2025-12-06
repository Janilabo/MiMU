{$DEFINE Double}{$DEFINE THelper := TDoubleHelper}{$I config\Defines.inc}

{$IFDEF TYPES}
TDoubleArray = array of Double;
T2DDoubleArray = array of TDoubleArray;
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I config\0D.inc}
  function ClampMin(const limit: Double): Double;
  function ClampMax(const limit: Double): Double;
  function Clamp(const minimum, maximum: Double): Double;
  function BoundMin(const limit: Double): Double;
  function BoundMax(const limit: Double): Double;
  function Bound(const minimum, maximum: Double): Double;
  function RestrictMin(const limit: Double): Double;
  function RestrictMax(const limit: Double): Double;
  function Restrict(const minimum, maximum: Double): Double;
  function LimitMin(const limit: Double): Double;
  function LimitMax(const limit: Double): Double;
  function Limit(const minimum, maximum: Double): Double;
  function ConstraintMin(const limit: Double): Boolean;
  function ConstraintMax(const limit: Double): Boolean;
  function Constraint(const minimum, maximum: Double): Boolean;
  function Increase(const N: Double = 1): Double; overload;
  function Increase(const B: Boolean): Double; overload;
  function Decrease(const N: Double = 1): Double; overload;
  function Decrease(const B: Boolean): Double; overload;
  function Increment(const N: Double = 1): Double; overload;
  function Increment(const B: Boolean): Double; overload;
  function Decrement(const N: Double = 1): Double; overload;
  function Decrement(const B: Boolean): Double; overload;
  function Digits: TIntegerArray;
  function NegA: Double; inline;
  function Neg: Double; inline;
  function Negative: Boolean; inline;
  function Positive: Boolean; inline;
  function Neutral: Boolean; inline;
  function MinDecimal: Double;
  function MaxDecimal: Double;
  function Accuracy(const a: Integer): Double;
  function Compare(const target: Double): Integer; inline;
  function Sign(const target: Double = 0): Integer; inline;
  function Precede(const target: Double; const aAscending: Boolean): Boolean; overload;
  function Ascending(const target: Double): Boolean; inline;
  function Descending(const target: Double): Boolean; inline;
  function Distance(const T: Double): Double; inline;
  function Difference(const T: Double): Double; inline;
  function Opposite: Double; inline;
  function FixDegrees: Double;
  function Degrees: Double;
  function FixRadians: Double;
  function Radians(const compass: Boolean = False): Double;
  function Percent(const position: Double): Double; inline;
  function Percentage(const percent: Double): Double; inline;
  function Over(const target: Double): Boolean; inline;
  function Under(const target: Double): Boolean; inline;
  function Oversize(const limit: Double): Boolean;
  function Undersize(const limit: Double): Boolean;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\0D.inc}

{==============================================================================]
  <ClampMin>
  @action: Returns Double clamped by minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMin(const limit: Double): Double; {$DEFINE Skeleton_ClampMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
  <ClampMax>
  @action: Returns Double clamped by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMax(const limit: Double): Double; {$DEFINE Skeleton_ClampMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
  <Clamp>
  @action: Returns Double clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Clamp(const minimum, maximum: Double): Double; {$DEFINE Skeleton_Clamp}{$I config\Skeletons.inc}{$UNDEF Skeleton_Clamp}

{==============================================================================]
  <BoundMin>
  @action: Returns Double bounded by minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.BoundMin(const limit: Double): Double; 
begin
  Result := (((Self + limit) + Abs(Self - limit)) / 2);
end;

{==============================================================================]
  <BoundMax>
  @action: Returns Double bounded by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.BoundMax(const limit: Double): Double; 
begin
  Result := (((Self + limit) - Abs(Self - limit)) / 2);
end;

{==============================================================================]
  <Bound>
  @action: Returns Double bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TDoubleHelper.Bound(const minimum, maximum: Double): Double; 
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) / 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) / 2);
end;

{==============================================================================]
  <RestrictMin>
  @action: Returns Double bounded by minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.RestrictMin(const limit: Double): Double; 
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) / 2);
end;

{==============================================================================]
  <RestrictMax>
  @action: Returns Double bounded by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.RestrictMax(const limit: Double): Double; 
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) / 2);
end;

{==============================================================================]
  <Restrict>
  @action: Returns Double bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TDoubleHelper.Restrict(const minimum, maximum: Double): Double; 
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) / 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) / 2);
end;

{==============================================================================]
  <LimitMin>
  @action: Returns Double with minimum limit
  @note: Max() call.
[==============================================================================}
function TDoubleHelper.LimitMin(const limit: Double): Double; {$DEFINE Skeleton_LimitMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
  <LimitMax>
  @action: Returns Double with maximum limit
  @note: Min() call.
[==============================================================================}
function TDoubleHelper.LimitMax(const limit: Double): Double; {$DEFINE Skeleton_LimitMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
  <Limit>
  @action: Returns Double with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TDoubleHelper.Limit(const minimum, maximum: Double): Double; {$DEFINE Skeleton_Limit}{$I config\Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Double is constrainted with minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMin(const limit: Double): Boolean; {$DEFINE Skeleton_ConstraintMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Double is constrainted with maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMax(const limit: Double): Boolean; {$DEFINE Skeleton_ConstraintMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
  <Constraint>
  @action: Returns true if Double is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Constraint(const minimum, maximum: Double): Boolean; {$DEFINE Skeleton_Constraint}{$I config\Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
  <Increase>
  @action: Increases the Double value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TDoubleHelper.Increase(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Increase}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <Increase>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TDoubleHelper.Increase(const B: Boolean): Double; overload; {$DEFINE Skeleton_IncreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TDoubleHelper.Decrease(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Decrease}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns x before decreasing it!
[==============================================================================}
function TDoubleHelper.Decrease(const B: Boolean): Double; overload; {$DEFINE Skeleton_DecreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Increment}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const B: Boolean): Double; overload; {$DEFINE Skeleton_IncrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Decrement}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrement}

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const B: Boolean): Double; overload; {$DEFINE Skeleton_DecrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecrementB}

{==============================================================================]
  <Digits>
  @action: Converts Double value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored. 
[==============================================================================}
function TDoubleHelper.Digits: TIntegerArray; 
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
  <NegA>
  @action: Returns the negative number of x. 
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.NegA: Double; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Neg>
  @action: Returns the negative number of i. 
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.Neg: Double; inline;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end; 

{==============================================================================]
  <Negative>
  @action: Returns True if Double value x is lower than 0 (negative), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Negative: Boolean; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Double value x is higher than 0 (positive), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Positive: Boolean; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Double value x is 0 (neutral), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Neutral: Boolean; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Sign>
  @action: Compares the current double (Self) with a target double and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TDoubleHelper.Sign(const target: Double = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I config\Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <MinDecimal>
  @action: Returns the minimum decimal value.
           0.12345 => 0.00001
  @note: None
[==============================================================================}
function TDoubleHelper.MinDecimal: Double; 
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
  <MaxDecimal>
  @action: Returns the maximum decimal value.
           0.12345 => 0.99999
  @note: None
[==============================================================================}
function TDoubleHelper.MaxDecimal: Double; 
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
  <Acc>
  @action: Returns x with decimal accuracy of a. Examples below with '123.456789'.
           a=0    a=1     a=2       a=3       a=4         a=5
           123   123.4   123.45   123.456   123.4567   123.45678
  @note: None
[==============================================================================}
function TDoubleHelper.Accuracy(const a: Integer): Double; 
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
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TDoubleHelper.Compare(const target: Double): Integer; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TDoubleHelper.Precede(const target: Double; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I config\Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TDoubleHelper.Ascending(const target: Double): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TDoubleHelper.Descending(const target: Double): Boolean; inline; {$DEFINE Skeleton_Descending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TDoubleHelper.Distance(const T: Double): Double; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TDoubleHelper.Difference(const T: Double): Double; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x. 
           -9999 to 9999 OR 9999 to -9999 (- <=> +) 
  @note: None
[==============================================================================}
function TDoubleHelper.Opposite: Double; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
  <FixDegrees>
  @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
  @note: None
[==============================================================================}
function TDoubleHelper.FixDegrees: Double; 
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
  <Degrees>
  @action: Converts Radians to Degrees.
  @note: None
[==============================================================================} 
function TDoubleHelper.Degrees: Double; 
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := r.FixDegrees;
end;

{==============================================================================]
  <FixRadians>
  @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
  @note: None
[==============================================================================}
function TDoubleHelper.FixRadians: Double; 
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := (r.FixDegrees * (Pi / 180.0));
end;

{==============================================================================]
  <Radians>
  @action: Converts Degrees or Compass (degrees) to Radians.
  @note: Supports compass.
[==============================================================================}
function TDoubleHelper.Radians(const compass: Boolean = False): Double; 
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
  <Percent>
  @action: Returns percent (%) from x by position.
  @note: Value-to-Percent conversion!
[==============================================================================}
function TDoubleHelper.Percent(const position: Double): Double; inline;
begin
  if (position <> 0) then
    Result := ((position / Self) * 100.0)
  else
    Result := 0.0;
end;

{==============================================================================]
  <Percentage>
  @action: Returns value from x by percent.
  @note: Percent-to-Value conversion!
[==============================================================================}
function TDoubleHelper.Percentage(const percent: Double): Double; inline;
begin
  if (percent <> 0) then
    Result := ((percent / 100.0) * Self)
  else
    Result := 0.0;
end;

{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TDoubleHelper.Over(const target: Double): Boolean; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TDoubleHelper.Oversize(const limit: Double): Boolean; 
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TDoubleHelper.Under(const target: Double): Boolean; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TDoubleHelper.Undersize(const limit: Double): Boolean; 
begin
  Result := (Self < limit);
end;
{$ENDIF}

{$UNDEF Double}