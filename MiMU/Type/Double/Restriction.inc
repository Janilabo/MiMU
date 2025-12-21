{$IFDEF HELPERS}
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
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ClampMin>
  @action: Returns Double clamped by minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMin(const limit: Double): Double; {$DEFINE Skeleton_ClampMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
  <ClampMax>
  @action: Returns Double clamped by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMax(const limit: Double): Double; {$DEFINE Skeleton_ClampMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
  <Clamp>
  @action: Returns Double clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Clamp(const minimum, maximum: Double): Double; {$DEFINE Skeleton_Clamp}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Clamp}

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
function TDoubleHelper.LimitMin(const limit: Double): Double; {$DEFINE Skeleton_LimitMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
  <LimitMax>
  @action: Returns Double with maximum limit
  @note: Min() call.
[==============================================================================}
function TDoubleHelper.LimitMax(const limit: Double): Double; {$DEFINE Skeleton_LimitMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
  <Limit>
  @action: Returns Double with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TDoubleHelper.Limit(const minimum, maximum: Double): Double; {$DEFINE Skeleton_Limit}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Double is constrainted with minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMin(const limit: Double): Boolean; {$DEFINE Skeleton_ConstraintMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Double is constrainted with maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMax(const limit: Double): Boolean; {$DEFINE Skeleton_ConstraintMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
  <Constraint>
  @action: Returns true if Double is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Constraint(const minimum, maximum: Double): Boolean; {$DEFINE Skeleton_Constraint}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Constraint}
{$ENDIF}