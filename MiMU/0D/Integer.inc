{$DEFINE TVar := Integer}
{$DEFINE TArr := TIntegerArray}
{$DEFINE T2DArr := T2DIntegerArray}
{$DEFINE THelper := TIntegerHelper}
{$DEFINE Sortable}

{$IFDEF TYPES}
TIntegerArray = array of Integer;
T2DIntegerArray = array of TIntegerArray;
{$ENDIF}

{$IFDEF HELPERS}
TIntegerHelper = type helper for Integer
  {$I Core.inc}
  function ClampMin(const limit: Integer): Integer;
  function ClampMax(const limit: Integer): Integer;
  function Clamp(const minimum, maximum: Integer): Integer; overload;
  function Clamp(const range: TRange): Integer; overload;
  function BoundMin(const limit: Integer): Integer;
  function BoundMax(const limit: Integer): Integer;
  function Bound(const minimum, maximum: Integer): Integer;
  function RestrictMin(const limit: Integer): Integer;
  function RestrictMax(const limit: Integer): Integer;
  function Restrict(const minimum, maximum: Integer): Integer;
  function LimitMin(const limit: Integer): Integer;
  function LimitMax(const limit: Integer): Integer;
  function Limit(const minimum, maximum: Integer): Integer;
  function ConstraintMin(const limit: Integer): Boolean;
  function ConstraintMax(const limit: Integer): Boolean;
  function Constraint(const minimum, maximum: Integer): Boolean; overload;
  function Constraint(const range: TRange): Boolean; overload;
  function Parity: Byte; inline;
  function Even: Boolean; inline;
  function IsEven: Boolean; inline;
  function Odd: Boolean; inline;
  function IsOdd: Boolean; inline;
  function Increase(const N: Integer = 1): Integer; overload;
  function Increase(const B: Boolean): Integer; overload;
  function Decrease(const N: Integer = 1): Integer; overload;
  function Decrease(const B: Boolean): Integer; overload;
  function Increment(const N: Integer = 1): Integer; overload;
  function Increment(const B: Boolean): Integer; overload;
  function Decrement(const N: Integer = 1): Integer; overload;
  function Decrement(const B: Boolean): Integer; overload;
  function DigitCount: Integer;
  function Digitz: TIntegerArray;
  function Digits: TIntegerArray;
  function NegA: Integer; inline;
  function Neg: Integer; inline;
  function Negative: Boolean; inline;
  function Positive: Boolean; inline;
  function Neutral: Boolean; inline;
  function Compare(const target: Integer): Integer; inline;
  function Precede(const target: Integer; const aAscending: Boolean): Boolean; overload;
  function Ascending(const target: Integer): Boolean; inline;
  function Descending(const target: Integer): Boolean; inline;
  function Distance(const T: Integer): Integer; inline;
  function Difference(const T: Integer): Integer; inline;
  function Opposite: Integer; inline;
  function Sign(const target: Integer = 0): Integer; inline;
  function Shuffle: Integer;
  function Over(const target: Integer): Boolean; inline;
  function Under(const target: Integer): Boolean; inline;
  function Oversize(const limit: Integer): Boolean; inline;
  function Undersize(const limit: Integer): Boolean; inline;
  function BitMax: Integer;
  function Unbitify: TBooleanArray; overload;
  function Unbitify(const bCount: Integer): TBooleanArray; overload;
  function Adjust(const cValue: Integer; const limits: TRange): Boolean;
  function AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
  function AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
  function Adjusted(const cValue: Integer; const limits: TRange): Integer;
  function AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
  function AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
  function Update(const cValue: Integer; const limits: TRange): Boolean;
  function UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
  function UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
  function Updated(const cValue: Integer; const limits: TRange): Integer;
  function UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
  function UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
  function Divisors: TIntegerArray;
  function Factors: TIntegerArray;
  function DivisibleBy(const value: Integer): Boolean;
  function MultipleOf(const value: Integer): Boolean;
end;
{$ENDIF}

{$IFDEF METHODS}
function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;

function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;

function Comparison(const A, B: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Core.inc}

{==============================================================================]
  <ClampMin>
  @action: Returns Integer clamped by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMin(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMin}{$I Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
  <ClampMax>
  @action: Returns Integer clamped by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMax(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMax}{$I Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
  <Clamp>
  @action: Returns Integer clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const minimum, maximum: Integer): Integer; overload; {$DEFINE Skeleton_Clamp}{$I Skeletons.inc}{$UNDEF Skeleton_Clamp}

{==============================================================================]
  <Clamp>
  @action: Returns Integer clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const range: TRange): Integer; overload;
begin
  Result := Self.ClampMin(range.Minimum);
  if (Self = Result) then
    Result := Self.ClampMax(range.Maximum);
end;

{==============================================================================]
  <BoundMin>
  @action: Returns Integer bounded by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.BoundMin(const limit: Integer): Integer;
begin
  Result := (((Self + limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <BoundMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.BoundMax(const limit: Integer): Integer;
begin
  Result := (((Self + limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <Bound>
  @action: Returns Integer bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TIntegerHelper.Bound(const minimum, maximum: Integer): Integer;
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) div 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) div 2);
end;

{==============================================================================]
  <RestrictMin>
  @action: Returns Integer bounded by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.RestrictMin(const limit: Integer): Integer;
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <RestrictMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.RestrictMax(const limit: Integer): Integer;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <Restrict>
  @action: Returns Integer bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TIntegerHelper.Restrict(const minimum, maximum: Integer): Integer;
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) div 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) div 2);
end;

{==============================================================================]
  <LimitMin>
  @action: Returns Integer with minimum limit
  @note: Max() call.
[==============================================================================}
function TIntegerHelper.LimitMin(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMin}{$I Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
  <LimitMax>
  @action: Returns Integer with maximum limit
  @note: Min() call.
[==============================================================================}
function TIntegerHelper.LimitMax(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMax}{$I Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
  <Limit>
  @action: Returns Integer with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TIntegerHelper.Limit(const minimum, maximum: Integer): Integer; {$DEFINE Skeleton_Limit}{$I Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Integer is constrainted with minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMin(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMin}{$I Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Integer is constrainted with maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMax(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMax}{$I Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
  <Constraint>
  @action: Returns true if Integer is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const minimum, maximum: Integer): Boolean; overload; {$DEFINE Skeleton_Constraint}{$I Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
  <Contstraint>
  @action: Returns true if Integer is constrainted with range
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
end;

{==============================================================================]
  <Parity>
  @action: Returns the Integer Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; inline;
begin
  Result := (Self mod 2);
end;

{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <IsEven>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsEven: Boolean; inline;
begin
  Result := ((Self and 1) = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <IsOdd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsOdd: Boolean; inline;
begin
  Result := ((Self and 1) = 1);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TIntegerHelper.Increase(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Increase}{$I Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by 1 when B is true.
  @note: Returns x before increasing!
[==============================================================================}
function TIntegerHelper.Increase(const B: Boolean): Integer; overload; {$DEFINE Skeleton_IncreaseB}{$I Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TIntegerHelper.Decrease(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Decrease}{$I Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by 1 if B is true.
  @note: Returns x before decreasing!
[==============================================================================}
function TIntegerHelper.Decrease(const B: Boolean): Integer; overload; {$DEFINE Skeleton_DecreaseB}{$I Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Increment}{$I Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const B: Boolean): Integer; overload; {$DEFINE Skeleton_IncrementB}{$I Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Decrement}{$I Skeletons.inc}{$UNDEF Skeleton_Decrement} 

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const B: Boolean): Integer; overload; {$DEFINE Skeleton_DecrementB}{$I Skeletons.inc}{$UNDEF Skeleton_DecrementB} 

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
  <NegA>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Neg>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer; inline;
begin
  if (Self > -1) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
  <Negative>
  @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Integer value x is 0 (neutral), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TIntegerHelper.Compare(const target: Integer): Integer; inline; {$DEFINE Skeleton_Compare}{$I Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TIntegerHelper.Precede(const target: Integer; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TIntegerHelper.Ascending(const target: Integer): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TIntegerHelper.Descending(const target: Integer): Boolean; inline; {$DEFINE Skeleton_Descending}{$I Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer; inline;
begin
  Result := (Self * -1);
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
function TIntegerHelper.Sign(const target: Integer = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Shuffle>
  @action: Random() with support for negative Range (based on x value).
  @note: None
[==============================================================================}
function TIntegerHelper.Shuffle: Integer;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;

{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TIntegerHelper.Over(const target: Integer): Boolean; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TIntegerHelper.Oversize(const limit: Integer): Boolean; inline;
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TIntegerHelper.Under(const target: Integer): Boolean; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TIntegerHelper.Undersize(const limit: Integer): Boolean; inline;
begin
  Result := (Self < limit);
end;

{==============================================================================]
  <BitMax>
  @action: Returns maximum bit index
  @note: Returns -1 with negatives.
[==============================================================================}
function TIntegerHelper.BitMax: Integer;
var
  i: Integer;
begin
  if (Self < 0) then
    Exit(-1);
  if (Self > 0) then
  for i := 31 downto 0 do
    if ((Self shr i) <> 0) then
      Exit(i);
  Result := 0;
end;

{==============================================================================]
  <Unbitify>
  @action: Returns array of Booleans by bits.
  @note: None.
[==============================================================================}
function TIntegerHelper.Unbitify: TBooleanArray; overload;
var
  c, i, s: Integer;
begin
  if (Self < 0) then
    Exit([]);
  s := Self;
  c := (s.BitMax + 1);
  SetLength(Result, c);
  for i := (c - 1) downto 0 do
  begin
    Result[i] := ((s and 1) <> 0);
    s := (s shr 1);
  end;
end;

{==============================================================================]
  <Unbitify>
  @action: Returns array of Booleans by bits.
  @note: None.
[==============================================================================}
function TIntegerHelper.Unbitify(const bCount: Integer): TBooleanArray; overload;
var
  i, s: Integer;
begin
  if ((Self < 0) or (bCount < 1)) then
    Exit([]);
  s := Self;
  SetLength(Result, bCount);
  for i := (bCount - 1) downto 0 do
  begin
    Result[i] := ((s and 1) <> 0);
    s := (s shr 1);
  end;
end;

{==============================================================================]
  <Adjust>
  @action: Attempts to adjust the current value by cValue if the resulting value
           stays within the specified limits range.
  @note: Returns True if the value was adjusted, False if it would go out of range.
[==============================================================================}
function TIntegerHelper.Adjust(const cValue: Integer; const limits: TRange): Boolean;
begin
  Result := limits.Contains(Self + cValue);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <AdjustMin>
  @action: Attempts to increase or decrease the integer by cValue, but prevents
           it from going below limit.
  @note: Returns True if the value stayed above or equal to limit.
[==============================================================================}
function TIntegerHelper.AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
begin
  Result := ((Self + cValue) >= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <AdjustMax>
  @action: Attempts to adjust by cValue but prevents exceeding the upper limit.
  @note: Returns True if the new value remains <= limit.
[==============================================================================}
function TIntegerHelper.AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
begin
  Result := ((Self + cValue) <= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Adjusted>
  @action: Returns a potentially adjusted copy of the integer, adding cValue
           only if it stays within limits.
  @note: Non-mutating version of Adjust.
[==============================================================================}
function TIntegerHelper.Adjusted(const cValue: Integer; const limits: TRange): Integer;
begin
  Result := Self;
  if limits.Contains(Self + cValue) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMin>
  @action: Returns Self + cValue if above limit; otherwise returns Self.
  @note: Non-mutating version of AdjustMin.
[==============================================================================}
function TIntegerHelper.AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
begin
  Result := Self;
  if ((Self + cValue) >= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMax>
  @action: Returns Self + cValue if below limit; otherwise returns Self.
  @note:   Non-mutating version of AdjustMax.
[==============================================================================}
function TIntegerHelper.AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
begin
  Result := Self;
  if ((Self + cValue) <= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <Update>
  @action: Adjusts the integer by cValue and clamps it within the specified limits.
  @note: Returns True if the result was within the range and assigned without clamping.
[==============================================================================}
function TIntegerHelper.Update(const cValue: Integer; const limits: TRange): Boolean;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Self := r.start
  else
    if (n > r.stop) then
      Self := r.stop
    else
      Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <UpdateMin>
  @action: Adjusts the integer by cValue, ensuring it does not fall below limit.
  @note: Returns True if the result was above or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <UpdateMax>
  @action: Adjusts the integer by cValue, ensuring it does not exceed limit.
  @note: Returns True if the result was below or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <Updated>
  @action: Returns a new value equal to Self + cValue, clamped within the specified limits.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.Updated(const cValue: Integer; const limits: TRange): Integer;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Result := r.start
  else
    if (n > r.stop) then
      Result := r.stop
    else
      Result := n;
end;

{==============================================================================]
  <UpdatedMin>
  @action: Returns Self + cValue, ensuring the result is not below limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <UpdatedMax>
  @action: Returns Self + cValue, ensuring the result is not above limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <Divisors>
  @action: Returns an array of all positive divisors of Self, including Self itself.
  @note:
    - If Self = 0, returns an empty array.
    - The divisors are calculated by iterating from 1 to Abs(Self) and checking modulo.
    - The resulting array contains only positive numbers and is in ascending order.
    - May be less efficient for large numbers compared to a square-root optimized method.
[==============================================================================}
function TIntegerHelper.Divisors: TIntegerArray;
var
  a, i, r: Integer;
begin
  r := 0;
  if (Self <> 0) then
  begin
    a := Abs(Self);
    SetLength(Result, ((a div 2) + 1));
    for i := 1 to a do
      if ((Self mod i) = 0) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Factors>
  @action: Returns an array of all positive factors of Self (equivalent to divisors),
           optimized using the square root method.
  @note:
    - If Self = 0, returns an empty array.
    - Iterates from 1 to Trunc(Sqrt(Abs(Self))) to find factor pairs.
    - Adds both i and Abs(Self) div i when i divides Self.
    - Resulting array is sorted in ascending order using QuickSort.
    - More efficient than naive Divisors method for large numbers.
[==============================================================================}
function TIntegerHelper.Factors: TIntegerArray;
var
  i, r, a: Integer;
begin
  a := Abs(Self);
  if (a = 0) then
    Exit([]);
  SetLength(Result, ((a div 2) + 1));
  r := 0;
  for i := 1 to Trunc(Sqrt(a)) do
  begin
    if not ((a mod i) = 0) then
      Continue;
    Result[r.Increase] := i;
    if (i <> (a div i)) then
      Result[r.Increase] := (a div i);
  end;
  SetLength(Result, r);
  Result.QuickSort;
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
function TIntegerHelper.DivisibleBy(const value: Integer): Boolean;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self - (Self div value) * value) = 0)));
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
function TIntegerHelper.MultipleOf(const value: Integer): Boolean;
begin
  Result := (((value = 1) or (value = -1)) or ((value <> 0) and ((Self mod value) = 0)));
end;

function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (oAscending and (A > B)) or ((not oAscending) and (A < B));
  if Result then
  begin
    A := (A xor B);
    B := (A xor B);
    A := (A xor B);
  end;
end;

function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(XORSort(A, B, oAscending)) + Integer(XORSort(A, C, oAscending)) + Integer(XORSort(B, C, oAscending))) > 0);
end;

function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
  begin
    A := (A + B);
    B := (A - B);
    A := (A - B);
  end;
end;

function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(iSort(A, B, oAscending)) + Integer(iSort(A, C, oAscending)) + Integer(iSort(B, C, oAscending))) > 0);
end;

function Comparison(const A, B: Integer): Integer; overload; {$DEFINE Skeleton_Comparison}{$I Skeletons.inc}{$UNDEF Skeleton_Comparison}
{$ENDIF}