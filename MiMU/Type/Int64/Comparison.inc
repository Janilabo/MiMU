{$IFDEF HELPERS}
function Compare(const target: Int64): Integer; inline;
function Precede(const target: Int64; const aAscending: Boolean): Boolean; overload; 
function Sign(const target: Int64 = 0): Integer; inline;
function Over(const target: Int64): Boolean; inline;
function Under(const target: Int64): Boolean; inline;
function Oversize(const limit: Int64): Boolean; inline;
function Undersize(const limit: Int64): Boolean; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TInt64Helper.Compare(const target: Int64): Integer; inline; {$DEFINE Skeleton_Compare}{$I ../Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TInt64Helper.Precede(const target: Int64; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I ../Skeletons.inc}{$UNDEF Skeleton_Precede}

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
function TInt64Helper.Sign(const target: Int64 = 0): Integer; inline; {$DEFINE Skeleton_Sign}{$I ../Skeletons.inc}{$UNDEF Skeleton_Sign}

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