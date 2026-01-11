{$IFDEF HELPERS}
function Bound(const minimum, maximum: Double): Double;
function BoundMax(const limit: Double): Double;
function BoundMin(const limit: Double): Double;
function Clamp(const minimum, maximum: Double): Double;
function ClampMax(const limit: Double): Double;
function ClampMin(const limit: Double): Double;
function Constraint(const minimum, maximum: Double): Boolean;
function ConstraintMax(const limit: Double): Boolean;
function ConstraintMin(const limit: Double): Boolean;
function Limit(const minimum, maximum: Double): Double;
function LimitMax(const limit: Double): Double;
function LimitMin(const limit: Double): Double;
function Restrict(const minimum, maximum: Double): Double;
function RestrictMax(const limit: Double): Double;
function RestrictMin(const limit: Double): Double;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BoundMax>
  @action: Returns Double bounded by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.BoundMax(const limit: Double): Double;
begin
  Result := (((Self + limit) - Abs(Self - limit)) / 2);
end;

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
  <Clamp>
  @action: Returns Double clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Clamp(const minimum, maximum: Double): Double;
begin
  if (Self < minimum) then
    Result := minimum
  else
    if(Self > maximum) then
      Result := maximum
    else
      Result := Self;
end;

{==============================================================================]
  <ClampMax>
  @action: Returns Double clamped by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMax(const limit: Double): Double;
begin
  if (Self > limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <ClampMin>
  @action: Returns Double clamped by minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ClampMin(const limit: Double): Double;
begin
  if (Self < limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <Constraint>
  @action: Returns true if Double is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.Constraint(const minimum, maximum: Double): Boolean;
begin
  Result := (Self.ConstraintMin(minimum) or Self.ConstraintMax(maximum));
end;

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Double is constrainted with maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMax(const limit: Double): Boolean;
begin
  Result := (Self > limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Double is constrainted with minimum limit
  @note: None
[==============================================================================}
function TDoubleHelper.ConstraintMin(const limit: Double): Boolean;
begin
  Result := (Self < limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <Limit>
  @action: Returns Double with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TDoubleHelper.Limit(const minimum, maximum: Double): Double;
begin
  Result := EnsureRange(Self, minimum, maximum);
end;

{==============================================================================]
  <LimitMax>
  @action: Returns Double with maximum limit
  @note: Min() call.
[==============================================================================}
function TDoubleHelper.LimitMax(const limit: Double): Double;
begin
  Result := Min(Self, limit);
end;

{==============================================================================]
  <LimitMin>
  @action: Returns Double with minimum limit
  @note: Max() call.
[==============================================================================}
function TDoubleHelper.LimitMin(const limit: Double): Double;
begin
  Result := Max(Self, limit);
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
  <RestrictMax>
  @action: Returns Double bounded by maximum limit
  @note: None
[==============================================================================}
function TDoubleHelper.RestrictMax(const limit: Double): Double;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) / 2);
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
{$ENDIF}