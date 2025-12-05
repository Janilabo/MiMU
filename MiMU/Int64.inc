{$DEFINE Int64}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  TInt64Helper = type helper for Int64 
    function Prime: Boolean; 
    function IsPrime: Boolean; 
    function Parity: Byte; inline;
    function Even: Boolean; inline;
    function Odd: Boolean; inline;
    function Increase(const N: Int64 = 1): Int64; overload;
    function Increase(const B: Boolean): Int64; overload;
    function Decrease(const N: Int64 = 1): Int64; overload;
    function Decrease(const B: Boolean): Int64; overload;	
    function Increment(const N: Int64 = 1): Int64; overload;
    function Increment(const B: Boolean): Int64; overload;
    function Decrement(const N: Int64 = 1): Int64; overload;
    function Decrement(const B: Boolean): Int64; overload;
    function DigitCount: Integer; 
    function Digitz: TIntegerArray; 
    function Digits: TIntegerArray; 
    function Compare(const target: Int64): Integer; inline;
    function Precede(const target: Int64; const aAscending: Boolean): Boolean; overload; 
    function Distance(const T: Int64): Int64; inline;
    function Difference(const T: Int64): Int64; inline;
    function Opposite: Int64; inline;
    function Sign(const target: Int64 = 0): Integer; inline;
    function Shuffle: Int64; 
    function Over(const target: Int64): Boolean; inline;
    function Under(const target: Int64): Boolean; inline;
    function Oversize(const limit: Int64): Boolean; inline;
    function Undersize(const limit: Int64): Boolean; inline;
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Prime>
  @action: Returns true if N is prime.
  @note: None.
[==============================================================================}
function TInt64Helper.Prime: Boolean;
var
  i: Int64;
begin
  if ((Self = 2) or (Self = 3)) then
    Exit(True);
  if ((Self < 2) or ((Self mod 2) = 0) or ((Self mod 3) = 0)) then
    Exit(False);
  i := 5;
  repeat
    if (((Self mod i) = 0) or ((Self mod (i + 2)) = 0)) then
      Exit(False);
    i := (i + 6);
  until ((i * i) > Self);
  Result := True;
end;

{==============================================================================]
  <IsPrime>
  @action: Returns true if N is prime.
  @note: None.
[==============================================================================}
function TInt64Helper.IsPrime: Boolean;
var
  p: array of Int64;
  i: Integer;
  j: Int64;
begin
  if (Self < 2) then
    Exit(False);
  p := [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31];
  for i := 0 to High(p) do
    if (Self = p[i]) then
      Exit(True)
    else
      if ((Self mod p[i]) = 0) then
        Exit(False);
  j := 30;
  repeat
    if (((Self mod j) = 0) or ((Self mod (j + 2)) = 0)) then
      Exit(False);
    Inc(j, 6);
  until ((j * j) > Self);
  Result := True;
end;

{==============================================================================]
  <Parity>
  @action: Returns the Int64 Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TInt64Helper.Parity: Byte; inline;
begin
  Result := (Self mod 2);
end;

{==============================================================================]
  <Even>
  @action: Returns true if Int64 value x is an even number.
  @note: None
[==============================================================================}
function TInt64Helper.Even: Boolean; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Int64 value x is an odd number.
  @note: None
[==============================================================================}
function TInt64Helper.Odd: Boolean; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TInt64Helper.Increase(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Increase}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TInt64Helper.Increase(const B: Boolean): Int64; overload; {$DEFINE Skeleton_IncreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Decrease}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const B: Boolean): Int64; overload; {$DEFINE Skeleton_DecreaseB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Increment}{$I config\Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const B: Boolean): Int64; overload; {$DEFINE Skeleton_IncrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Decrement}{$I config\Skeletons.inc}{$UNDEF Skeleton_Decrement}

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const B: Boolean): Int64; overload; {$DEFINE Skeleton_DecrementB}{$I config\Skeletons.inc}{$UNDEF Skeleton_DecrementB}

{==============================================================================]
  <DigitCount>
  @action: Returns count of digits Int64 x value contains.
  @note: If x is negative value, the negative sign is ignored.
        Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.DigitCount: Integer;
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
  <Digitz>
  @action: Converts Int64 value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.Digitz: TIntegerArray;
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
  <Digits>
  @action: Converts Int64 value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -9223372036854775808 - 9223372036854775807! 
[==============================================================================}
function TInt64Helper.Digits: TIntegerArray;
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
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TInt64Helper.Compare(const target: Int64): Integer; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TInt64Helper.Precede(const target: Int64; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I config\Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TInt64Helper.Distance(const T: Int64): Int64; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TInt64Helper.Difference(const T: Int64): Int64; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x. 
           -9999 to 9999 OR 9999 to -9999 (- <=> +) 
  @note: None
[==============================================================================}
function TInt64Helper.Opposite: Int64; inline;
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
function TInt64Helper.Sign(const target: Int64 = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I config\Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Shuffle>
  @action: Random() with support for negative Range.
  @note: None
[==============================================================================}
function TInt64Helper.Shuffle: Int64;
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
function TInt64Helper.Over(const target: Int64): Boolean; inline;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TInt64Helper.Oversize(const limit: Int64): Boolean; inline;
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TInt64Helper.Under(const target: Int64): Boolean; inline;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TInt64Helper.Undersize(const limit: Int64): Boolean; inline;
begin
  Result := (Self < limit);
end;
{$ENDIF}

{$UNDEF Int64}