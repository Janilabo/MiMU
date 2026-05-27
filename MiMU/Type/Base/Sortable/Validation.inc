{$IFDEF FUNCTIONS}
function AllDistinct3(const A, B, C: MType): Boolean; overload;
function AllEqual3(const A, B, C: MType): Boolean; overload;
function AnyEqual3(const A, B, C: MType): Boolean; overload;
function Majority3(const A, B, C: MType): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function IsBetween(const A, B: MType): Boolean; overload;
function IsOutside(const A, B: MType): Boolean; overload;
function IsStrictlyBetween(const A, B: MType): Boolean; overload;
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
{$ENDIF}
