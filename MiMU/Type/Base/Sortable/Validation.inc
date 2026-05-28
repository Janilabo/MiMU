{$IFDEF FUNCTIONS}
function AllDistinct3(const A, B, C: MType): Boolean; overload;
function AllEqual3(const A, B, C: MType): Boolean; overload;
function AnyEqual3(const A, B, C: MType): Boolean; overload;
function Majority3(const A, B, C: MType): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Among(const A, B: MType): Boolean; overload;
function Amongst(const A, B: MType): Boolean; overload;
function IsAbove(const target: MType): Boolean; overload;
function IsBelow(const target: MType): Boolean; overload;
function IsBetween(const A, B: MType): Boolean; overload;
function IsIn(const A, B: MType): Boolean; overload;
function IsInside(const A, B: MType; const strictly: Boolean = False): Boolean; overload;
function IsOutside(const A, B: MType): Boolean; overload;
function IsStrictlyBetween(const A, B: MType): Boolean; overload;
function IsStrictlyIn(const A, B: MType): Boolean; overload;
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
  <Among>
  @action: Determines whether the current value falls inside the closed numerical 
           range bounded by A and B, inclusive.
  @note: Automatically handles unordered inputs (works perfectly whether A <= B 
         or A > B) by checking both orientation scenarios. This creates a safe, 
         bidirectional containment check.
[==============================================================================}
function MTypeHelper.Among(const A, B: MType): Boolean; overload;
begin
  if (A <= B) then
    Result := ((A <= Self) and (Self <= B))
  else
    Result := ((B <= Self) and (Self <= A));
end;

{==============================================================================]
  <Amongst>
  @action: Determines whether the current value is contained within the inclusive 
           range defined by endpoints A and B.
  @note: Normalizes the boundaries automatically by swapping them if A > B. 
         This ensures a reliable, orientation-independent range check without 
         requiring conditional branching on the final comparison.
[==============================================================================}
function MTypeHelper.Amongst(const A, B: MType): Boolean; overload;
var
  X, Y: MType;
begin
  X := A;
  Y := B;
  if (X > Y) then
    Swap(X, Y);
  Result := ((Self >= X) and (Self <= Y));
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
{$ENDIF}
