{$IFDEF HELPERS}
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
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ClampMin>
  @action: Returns Integer clamped by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMin(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ClampMin}

{==============================================================================]
  <ClampMax>
  @action: Returns Integer clamped by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMax(const limit: Integer): Integer; {$DEFINE Skeleton_ClampMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ClampMax}

{==============================================================================]
  <Clamp>
  @action: Returns Integer clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const minimum, maximum: Integer): Integer; overload; {$DEFINE Skeleton_Clamp}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Clamp}

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
function TIntegerHelper.LimitMin(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_LimitMin}

{==============================================================================]
  <LimitMax>
  @action: Returns Integer with maximum limit
  @note: Min() call.
[==============================================================================}
function TIntegerHelper.LimitMax(const limit: Integer): Integer; {$DEFINE Skeleton_LimitMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_LimitMax}

{==============================================================================]
  <Limit>
  @action: Returns Integer with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TIntegerHelper.Limit(const minimum, maximum: Integer): Integer; {$DEFINE Skeleton_Limit}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Limit}

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Integer is constrainted with minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMin(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMin}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ConstraintMin}

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Integer is constrainted with maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMax(const limit: Integer): Boolean; {$DEFINE Skeleton_ConstraintMax}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_ConstraintMax}

{==============================================================================]
  <Constraint>
  @action: Returns true if Integer is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const minimum, maximum: Integer): Boolean; overload; {$DEFINE Skeleton_Constraint}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Constraint}

{==============================================================================]
  <Contstraint>
  @action: Returns true if Integer is constrainted with range
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
end;
{$ENDIF}