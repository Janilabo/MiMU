{$IFDEF FUNCTIONS}
function AllDistinct3(const A, B, C: MType): Boolean; overload;
function AllEqual3(const A, B, C: MType): Boolean; overload;
function AnyEqual3(const A, B, C: MType): Boolean; overload;
function Majority3(const A, B, C: MType): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Amid(const A, B: MType): Boolean; overload;
function Betwixt(const A, B: MType): Boolean; overload;
function Held(const A, B: MType): Boolean; overload;
function IsAbove(const target: MType): Boolean; overload;
function IsAtLeast(const target: MType): Boolean; overload;
function IsAtMost(const target: MType): Boolean; overload;
function IsBelow(const target: MType): Boolean; overload;
function IsBetween(const A, B: MType): Boolean; overload;
function IsIn(const A, B: MType): Boolean; overload;
function IsInside(const A, B: MType; const strictly: Boolean = False): Boolean; overload;
function IsOutside(const A, B: MType): Boolean; overload;
function IsStrictlyBetween(const A, B: MType): Boolean; overload;
function IsStrictlyIn(const A, B: MType): Boolean; overload;
function Above(const target: MType): Boolean; overload;
function Below(const limit: MType): Boolean; overload;
function Over(const target: MType): Boolean; overload;
function Under(const limit: MType): Boolean; overload;
function Unmoored(const A, B: MType): Boolean; overload;
function Between(const aMin, aMax: MType): Boolean; overload;
function Betweenish(const aMin, aMax: MType): Boolean; overload;
function BoundedBy(const aMin, aMax: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllDistinct3>
  @action: Checks if all three values are completely unique.
  @note: Returns True only if no two values are equal to each other. This is the strict logical inverse of AnyEqual3.
[==============================================================================}
function AllDistinct3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A <> B) and (B <> C) and (A <> C));
end;

{==============================================================================]
  <AllEqual3>
  @action: Checks if all three values (A, B, and C) are equal to each other.
  @note: Returns True only if A, B, and C hold the exact same value; otherwise returns False.
[==============================================================================}
function AllEqual3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A = B) and (B = C));
end;

{==============================================================================]
  <Amid>
  @action: Determines whether the current value falls inside the closed numerical 
           range bounded by A and B, inclusive.
  @note: Automatically handles unordered inputs (works perfectly whether A <= B 
         or A > B) by checking both orientation scenarios. This creates a safe, 
         bidirectional containment check.
[==============================================================================}
function MTypeHelper.Amid(const A, B: MType): Boolean; overload;
begin
  if (A <= B) then
    Result := ((A <= Self) and (Self <= B))
  else
    Result := ((B <= Self) and (Self <= A));
end;

{==============================================================================]
  <AnyEqual3>
  @action: Checks if there is any duplication among the three values.
  @note: Returns True if at least two of the values are equal (A=B, B=C, or A=C). Returns False only if all three are unique.
[==============================================================================}
function AnyEqual3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A = B) or (B = C) or (A = C));
end;

{==============================================================================]
  <Betwixt>
  @action: Returns True if Self lies between A and B, inclusive, regardless of which is smaller.
  @note: Order-independent — works whether A < B or A > B. Equivalent to A <= Self <= B or B <= Self <= A.
[==============================================================================}
function MTypeHelper.Betwixt(const A, B: MType): Boolean; overload;
begin
  Result := not (((Self > A) and (Self > B)) or ((Self < A) and (Self < B)));
end;

{==============================================================================]
  <Held>
  @action: Determines whether the current value is contained within the inclusive 
           range defined by endpoints A and B.
  @note: Normalizes the boundaries automatically by swapping them if A > B. 
         This ensures a reliable, orientation-independent range check without 
         requiring conditional branching on the final comparison.
[==============================================================================}
function MTypeHelper.Held(const A, B: MType): Boolean; overload;
var
  C, D: MType;
begin
  C := A;
  D := B;
  if (C > D) then
    Swap(C, D);
  Result := ((Self >= C) and (Self <= D));
end;

{==============================================================================]
  <Majority3>
  @action: Determines if a majority (at least 2 out of 3) of the values are equal.
  @note: Implements a 3-input majority gate logic. Because there are only 3 inputs, any matching pair constitutes a strict majority.
[==============================================================================}
function Majority3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A = B) or (B = C) or (A = C));
end;

{==============================================================================]
  <IsAbove>
  @action: Determines whether the item is strictly greater 
           than the specified target value.
  @note: This is an exclusive comparison (returns False if Self equals target).
[==============================================================================}
function MTypeHelper.IsAbove(const target: MType): Boolean; overload;
begin
  Result := (Self > target);
end;

{==============================================================================]
  <IsAtLeast>
  @action: Checks if the current value is greater than or equal to the target value.
  @note: Returns True if Self is greater than or equal to target.
[==============================================================================}
function MTypeHelper.IsAtLeast(const target: MType): Boolean; overload;
begin
  Result := (Self >= target);
end;

{==============================================================================]
  <IsAtMost>
  @action: Checks if the current value is less than or equal to the target value.
  @note: Returns True if Self is less than or equal to target.
[==============================================================================}
function MTypeHelper.IsAtMost(const target: MType): Boolean; overload;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <IsBelow>
  @action: Determines whether the current item is strictly less 
           than the specified target value.
  @note: This is an exclusive comparison (returns False if Self equals target).
[==============================================================================}
function MTypeHelper.IsBelow(const target: MType): Boolean; overload;
begin
  Result := (Self < target);
end;

{==============================================================================]
  <IsBetween>
  @action: Determines whether the instance value falls within an inclusive range defined by two boundaries.
  @note: The range is direction-agnostic; it automatically handles cases where the first boundary (A) is greater than the second boundary (B).
[==============================================================================}
function MTypeHelper.IsBetween(const A, B: MType): Boolean; overload;
begin
  if (B > A) then
    Result := ((Self >= A) and (Self <= B))
  else
    Result := ((Self >= B) and (Self <= A));
end;

{==============================================================================]
  <IsIn>
  @action: Checks if the current value is within the specified range (inclusive).
  @note: Automatically handles cases where A > B by using Min and Max.
[==============================================================================}
function MTypeHelper.IsIn(const A, B: MType): Boolean; overload;
begin
  Result := ((Self >= Min(A, B)) and (Self <= Max(A, B)));
end;

{==============================================================================]
  <IsInside>
  @action: Determines whether the current value falls within the range defined 
           by bounds A and B. 
           If 'strictly' is False, the range is inclusive of the boundaries. 
           If 'strictly' is True, the range is exclusive.
  @note: Automatically handles unordered bounds using Min() and Max().
[==============================================================================}
function MTypeHelper.IsInside(const A, B: MType; const strictly: Boolean = False): Boolean; overload;
begin
  if not strictly then
    Result := ((Ord(Self >= Min(A, B)) and Ord(Self <= Max(A, B))) = 1)
  else
    Result := ((Ord(Self > Min(A, B)) and Ord(Self < Max(A, B))) = 1);
end;

{==============================================================================]
  <IsOutside>
  @action: Determines whether the instance value falls completely outside an exclusive range defined by two boundaries.
  @note: The range is direction-agnostic; it automatically handles cases where the first boundary (A) is greater than the second boundary (B).
[==============================================================================}
function MTypeHelper.IsOutside(const A, B: MType): Boolean; overload;
begin
  if (B > A) then
    Result := ((Self < A) or (Self > B))
  else
    Result := ((Self < B) or (Self > A));
end;

{==============================================================================]
  <IsStrictlyBetween>
  @action: Determines whether the instance value falls strictly within an inclusive range defined by two boundaries.
  @note: The range is direction-agnostic; it automatically handles cases where the first boundary (A) is greater than the second boundary (B).
[==============================================================================}
function MTypeHelper.IsStrictlyBetween(const A, B: MType): Boolean; overload;
begin
  if (B > A) then
    Result := ((Self > A) and (Self < B))
  else
    Result := ((Self > B) and (Self < A));
end;

{==============================================================================]
  <IsStrictlyIn>
  @action: Checks if the current value is strictly between the specified range (exclusive).
  @note: Automatically handles cases where A > B by using Min and Max.
[==============================================================================}
function MTypeHelper.IsStrictlyIn(const A, B: MType): Boolean; overload;
begin
  Result := ((Self > Min(A, B)) and (Self < Max(A, B)));
end;

{==============================================================================]
  <Above>
  @action: Returns True if Self is higher than target.
  @note: Direct comparison form.
[==============================================================================}
function MTypeHelper.Above(const target: MType): Boolean; overload;
begin
  Result := (Self > target);
end;

{==============================================================================]
  <Below>
  @action: Returns True if Self is lower than limit.
  @note: Direct comparison form.
[==============================================================================}
function MTypeHelper.Below(const limit: MType): Boolean; overload;
begin
  Result := (Self < limit);
end;

{==============================================================================]
  <Over>
  @action: Returns True if Self is higher than target.
  @note: Expressed via De Morgan negation of <=.
[==============================================================================}
function MTypeHelper.Over(const target: MType): Boolean; overload;
begin
  Result := not (Self <= target);
end;

{==============================================================================]
  <Under>
  @action: Returns True if Self is lower than limit.
  @note: Expressed via De Morgan negation of >=.
[==============================================================================}
function MTypeHelper.Under(const limit: MType): Boolean; overload;
begin
  Result := not (Self >= limit);
end;

{==============================================================================]
  <Unmoored>
  @action: Returns True if Self lies strictly outside the range bounded by A and B (exclusive), regardless of which is smaller.
  @note: Order-independent — Strict > / < only, so Self exactly equal to A or B returns False.
[==============================================================================}
function MTypeHelper.Unmoored(const A, B: MType): Boolean; overload;
begin
  Result := (((Self > A) and (Self > B)) or ((Self < A) and (Self < B)));
end;

{==============================================================================]
  <Between>
  @action: Determines whether the value falls inclusively between a min and max.
  @note: Fluent replacement for standard Delphi InRange function.
[==============================================================================}
function MTypeHelper.Between(const aMin, aMax: MType): Boolean; overload;
begin
  Result := not ((Self < aMin) or (Self > aMax));
end;

{==============================================================================]
  <Betweenish>
  @action: Determines whether the value falls inclusively between a min and max.
  @note: Fluent replacement for standard Delphi InRange function.
[==============================================================================}
function MTypeHelper.Betweenish(const aMin, aMax: MType): Boolean; overload;
begin
  Result := ((Self >= aMin) and (Self <= aMax));
end;

{==============================================================================]
  <BoundedBy>
  @action: Determines whether the integer falls inclusively between a specified 
           minimum and maximum value.
  @note: Uses TIntegerHelper's internal Compare method to perform a safe 
         bounds check. Returns True if the value is equal to or greater than 
         aMin, and equal to or less than aMax.
[==============================================================================}
function MTypeHelper.BoundedBy(const aMin, aMax: MType): Boolean; overload;
begin
  Result := ((Self.Compare(aMin) >= 0) and (Self.Compare(aMax) <= 0));
end;
{$ENDIF}
