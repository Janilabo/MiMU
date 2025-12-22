{$IFDEF HELPERS}
function Compare(const target: Double): Integer; inline;
function Sign(const target: Double = 0): Integer; inline;
function Precede(const target: Double; const aAscending: Boolean): Boolean; overload;
function Ascending(const target: Double): Boolean; inline;
function Descending(const target: Double): Boolean; inline;
function Over(const target: Double): Boolean; inline;
function Under(const target: Double): Boolean; inline;
function Oversize(const limit: Double): Boolean;
function Undersize(const limit: Double): Boolean;
{$ENDIF}

{$IFDEF METHODS}
function Comparison(const A, B: Double): Integer; overload; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TDoubleHelper.Compare(const target: Double): Integer; inline; {$DEFINE Skeleton_Compare}{$I ../Skeletons.inc}{$UNDEF Skeleton_Compare}

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
function TDoubleHelper.Sign(const target: Double = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I ../Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TDoubleHelper.Precede(const target: Double; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I ../Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TDoubleHelper.Ascending(const target: Double): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I ../Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TDoubleHelper.Descending(const target: Double): Boolean; inline; {$DEFINE Skeleton_Descending}{$I ../Skeletons.inc}{$UNDEF Skeleton_Descending}

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

function Comparison(const A, B: Double): Integer; overload; {$DEFINE Skeleton_Comparison}{$I ../Skeletons.inc}{$UNDEF Skeleton_Comparison}
{$ENDIF}