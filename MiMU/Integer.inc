{$DEFINE Integer}{$I config\Defines.inc}

{==============================================================================]
 <TIntegerHelper.ClampMin>
 @action: Returns Integer clamped by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ClampMin(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
 <TIntegerHelper.ClampMax>
 @action: Returns Integer clamped by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ClampMax(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
 <TIntegerHelper.Clamp>
 @action: Returns Integer clamped by minimum and maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const minimum, maximum: Integer): Integer; overload; {$DEFINE Skeleton_Clamp}{$I config\Skeletons.inc}{$UNDEF Skeleton_Clamp}

{==============================================================================]
 <TIntegerHelper.Clamp>
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
 <TIntegerHelper.BoundMin>
 @action: Returns Integer bounded by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.BoundMin(const limit: Integer): Integer;
begin
  Result := (((Self + limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.BoundMax>
 @action: Returns Integer bounded by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.BoundMax(const limit: Integer): Integer;
begin
  Result := (((Self + limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.Bound>
 @action: Returns Integer bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TIntegerHelper.Bound(const minimum, maximum: Integer): Integer;
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) div 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.RestrictMin>
 @action: Returns Integer bounded by minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.RestrictMin(const limit: Integer): Integer;
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.RestrictMax>
 @action: Returns Integer bounded by maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.RestrictMax(const limit: Integer): Integer;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.Restrict>
 @action: Returns Integer bounded by minimum and maximum limits
 @note: None
[==============================================================================}
function TIntegerHelper.Restrict(const minimum, maximum: Integer): Integer;
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) div 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) div 2);
end;

{==============================================================================]
 <TIntegerHelper.LimitMin>
 @action: Returns Integer with minimum limit
 @note: Max() call.
[==============================================================================}
function TIntegerHelper.LimitMin(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
 <TIntegerHelper.LimitMax>
 @action: Returns Integer with maximum limit
 @note: Min() call.
[==============================================================================}
function TIntegerHelper.LimitMax(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
 <TIntegerHelper.Limit>
 @action: Returns Integer with minimum and maximum limits
 @note: EnsureRange() call.
[==============================================================================}
function TIntegerHelper.Limit(const minimum, maximum: Integer): Integer; {$DEFINE Skeleton_Limit}{$I config\Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
 <TIntegerHelper.ConstraintMin>
 @action: Returns true if Integer is constrainted with minimum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMin(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMin}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
 <TIntegerHelper.ConstraintMax>
 @action: Returns true if Integer is constrainted with maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMax(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMax}{$I config\Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
 <TIntegerHelper.Constraint>
 @action: Returns true if Integer is constrainted with minimum or maximum limit
 @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const minimum, maximum: Integer): Boolean; overload; {$DEFINE Skeleton_Constraint}{$I config\Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
 <TIntegerHelper.Contstraint>
 @action: Returns true if Integer is constrainted with range
 @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
end;

{==============================================================================]
 <TIntegerHelper.Parity>
 @action: Returns the Integer Parity Bit as Byte.
 @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; inline;
begin
  Result := (Self mod 2);
end;

{==============================================================================]
 <TIntegerHelper.Even>
 @action: Returns true if Integer value x is an even number.
 @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; inline;
begin
  Result := ((Self mod 2) = 0);
end;

function TIntegerHelper.IsEven: Boolean; inline;
begin
  Result := ((Self and 1) = 0);
end;

{==============================================================================]
 <TIntegerHelper.Odd>
 @action: Returns true if Integer value x is an odd number.
 @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
 <TIntegerHelper.Odd>
 @action: Returns true if Integer value x is an odd number.
 @note: None
[==============================================================================}
function TIntegerHelper.IsOdd: Boolean; inline;
begin
  Result := ((Self and 1) = 1);
end;

{==============================================================================]
 <TIntegerHelper.Increase>
 @action: Increases the Integer value x by N.
 @note: Returns x before increasing it with N!
[==============================================================================}
function TIntegerHelper.Increase(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Increase}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
 <TIntegerHelper.Increase>
 @action: Increases the Integer value x by 1 when B is true.
 @note: Returns x before increasing!
[==============================================================================}
function TIntegerHelper.Increase(const B: Boolean): Integer; overload; {$DEFINE Skeleton_IncreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <TIntegerHelper.Decrease>
 @action: Decreases the Integer value x by N.
 @note: Returns x before decreasing it with N!
[==============================================================================}
function TIntegerHelper.Decrease(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Decrease}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <TIntegerHelper.Decrease>
 @action: Decreases the Integer value x by 1 if B is true.
 @note: Returns x before decreasing!
[==============================================================================}
function TIntegerHelper.Decrease(const B: Boolean): Integer; overload; {$DEFINE Skeleton_DecreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
 <TIntegerHelper.Increment>
 @action: Increases the Integer value x by N.
 @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Increment}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
 <TIntegerHelper.Increment>
 @action: Increases the Integer value x by 1 if B is true.
 @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const B: Boolean): Integer; overload; {$DEFINE Skeleton_IncrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <TIntegerHelper.Decrement>
 @action: Decreases the Integer value x by N.
 @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const N: Integer = 1): Integer; overload; {$DEFINE Skeleton_Decrement}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrement} 

{==============================================================================]
  <TIntegerHelper.Decrement>
 @action: Decreases the Integer value x by 1 if B is true.
 @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const B: Boolean): Integer; overload; {$DEFINE Skeleton_DecrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecrementB} 

{==============================================================================]
 <TIntegerHelper.DigitCount>
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
 <TIntegerHelper.Digitz>
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
 <TIntegerHelper.Digits>
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
 <TIntegerHelper.NegA>
 @action: Returns the negative number of x.
          -9999 to -9999 OR 9999 to -9999 (+/- => -)
 @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
 <TIntegerHelper.Neg>
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
 <TIntegerHelper.Negative>
 @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
 <TIntegerHelper.Positive>
 @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
 <TIntegerHelper.Neutral>
 @action: Returns True if Integer value x is 0 (neutral), otherwise False.
 @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
 <TIntegerHelper.Compare>
 @action: Compares x with target target.
          Results: 0=EQUAL, 1=x>target, -1=x<target
 @note: None
[==============================================================================}
function TIntegerHelper.Compare(const target: Integer): Integer; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
 <TIntegerHelper.Precede>
 @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
 @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TIntegerHelper.Precede(const target: Integer; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I config\Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
 <TIntegerHelper.Ascending>
 @action  Returns True if the helper’s value is less than or equal to         
          the given target value. Useful as a comparison predicate when        
          sorting or merging arrays in ascending order.
 @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TIntegerHelper.Ascending(const target: Integer): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
 <TIntegerHelper.Descending>
 @action: Returns True if the helper’s value is greater than or equal to
          the given target value. Use as a comparison predicate when
          sorting or merging arrays in descending order.
 @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TIntegerHelper.Descending(const target: Integer): Boolean; inline; {$DEFINE Skeleton_Descending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
 <TIntegerHelper.Distance>
 @action: Returns the distance between x and T.
 @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
 <TIntegerHelper.Difference>
 @action: Returns the difference from x to T.
 @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
 <TIntegerHelper.Opposite>
 @action: Returns the opposite number of x.
          -9999 to 9999 OR 9999 to -9999 (- <=> +)
 @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
 <TIntegerHelper.Sign>
 @action: Compares the current double (Self) with a target double and returns
          a directional sign indicating whether the target is greater, equal,
          or smaller than Self.
 @note:   Returns:
            1  if Self < target (target is larger → ascending)
            0  if Self = target (no change)
           -1  if Self > target (target is smaller → descending)
          Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TIntegerHelper.Sign(const target: Integer = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I config\Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
 <TIntegerHelper.Shuffle>
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
 <TIntegerHelper.Over>
 @action: Returns true if x is higher than target.
 @note: None
[==============================================================================}
function TIntegerHelper.Over(const target: Integer): Boolean; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
 <TIntegerHelper.Oversize>
 @action: Returns true if x is higher than limit.
 @note: None
[==============================================================================}
function TIntegerHelper.Oversize(const limit: Integer): Boolean; inline;
begin
  Result := (Self > limit);
end;

{==============================================================================]
 <TIntegerHelper.Under>
 @action: Returns true if x is lower than target.
 @note: None
[==============================================================================}
function TIntegerHelper.Under(const target: Integer): Boolean; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
 <TIntegerHelper.Undersize>
 @action: Returns true if x is lower than limit.
 @note: None
[==============================================================================}
function TIntegerHelper.Undersize(const limit: Integer): Boolean; inline;
begin
  Result := (Self < limit);
end;

{==============================================================================]
 <TIntegerHelper.BitMax>
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
 <TIntegerHelper.Unbitify>
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
 <TIntegerHelper.Unbitify>
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
 <Integer.Adjust>
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
 <Integer.AdjustMin>
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
 <Integer.AdjustMax>
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
 <Integer.Adjusted>
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
 <Integer.AdjustedMin>
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
 <Integer.AdjustedMax>
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
 <Integer.Update>
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
 <Integer.UpdateMin>
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
 <Integer.UpdateMax>
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
 <Integer.Updated>
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
  if (n < limits.start) then
    Result := limits.start
  else
    if (n > limits.stop) then
      Result := limits.stop
    else
      Result := n;
end;

{==============================================================================]
 <Integer.UpdatedMin>
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
 <Integer.UpdatedMax>
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

{$UNDEF Integer}