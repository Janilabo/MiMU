{$IFDEF HELPERS}
function Bound(const minimum, maximum: Integer): Integer; cdecl;
function BoundMax(const limit: Integer): Integer; cdecl;
function BoundMin(const limit: Integer): Integer; cdecl;
function Clamp(const minimum, maximum: Integer): Integer; overload; cdecl;
function Clamp(const range: TRange): Integer; overload; cdecl;
function ClampMax(const limit: Integer): Integer; cdecl;
function ClampMin(const limit: Integer): Integer; cdecl;
function Constraint(const minimum, maximum: Integer): Boolean; overload; cdecl;
function Constraint(const range: TRange): Boolean; overload; cdecl;
function ConstraintMax(const limit: Integer): Boolean; cdecl;
function ConstraintMin(const limit: Integer): Boolean; cdecl;
function Limit(const minimum, maximum: Integer): Integer; cdecl;
function LimitMax(const limit: Integer): Integer; cdecl;
function LimitMin(const limit: Integer): Integer; cdecl;
function Restrict(const minimum, maximum: Integer): Integer; cdecl;
function RestrictMax(const limit: Integer): Integer; cdecl;
function RestrictMin(const limit: Integer): Integer; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bound>
  @action: Returns Integer bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TIntegerHelper.Bound(const minimum, maximum: Integer): Integer; cdecl;
begin
  Result := (((Self + minimum) + Abs(Self - minimum)) div 2);
  Result := (((Result + maximum) - Abs(Result - maximum)) div 2);
end;

{==============================================================================]
  <BoundMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.BoundMax(const limit: Integer): Integer; cdecl;
begin
  Result := (((Self + limit) - Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <BoundMin>
  @action: Returns Integer bounded by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.BoundMin(const limit: Integer): Integer; cdecl;
begin
  Result := (((Self + limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <Clamp>
  @action: Returns Integer clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const minimum, maximum: Integer): Integer; cdecl; overload;
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
  <Clamp>
  @action: Returns Integer clamped by minimum and maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Clamp(const range: TRange): Integer; overload; cdecl;
begin
  Result := Self.ClampMin(range.Minimum);
  if (Self = Result) then
    Result := Self.ClampMax(range.Maximum);
end;

{==============================================================================]
  <ClampMax>
  @action: Returns Integer clamped by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMax(const limit: Integer): Integer; cdecl;
begin
  if (Self > limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <ClampMin>
  @action: Returns Integer clamped by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ClampMin(const limit: Integer): Integer; cdecl;
begin
  if (Self < limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <Constraint>
  @action: Returns true if Integer is constrainted with minimum or maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const minimum, maximum: Integer): Boolean; overload; cdecl;
begin
  Result := (Self.ConstraintMin(minimum) or Self.ConstraintMax(maximum));
end;

{==============================================================================]
  <Contstraint>
  @action: Returns true if Integer is constrainted with range
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload; cdecl;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
end;

{==============================================================================]
  <ConstraintMax>
  @action: Returns true if Integer is constrainted with maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMax(const limit: Integer): Boolean; cdecl;
begin
  Result := (Self > limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <ConstraintMin>
  @action: Returns true if Integer is constrainted with minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.ConstraintMin(const limit: Integer): Boolean; cdecl;
begin
  Result := (Self < limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <Limit>
  @action: Returns Integer with minimum and maximum limits
  @note: EnsureRange() call.
[==============================================================================}
function TIntegerHelper.Limit(const minimum, maximum: Integer): Integer; cdecl;
begin
  Result := EnsureRange(Self, minimum, maximum);
end;

{==============================================================================]
  <LimitMax>
  @action: Returns Integer with maximum limit
  @note: Min() call.
[==============================================================================}
function TIntegerHelper.LimitMax(const limit: Integer): Integer; cdecl;
begin
  Result := Min(Self, limit);
end;

{==============================================================================]
  <LimitMin>
  @action: Returns Integer with minimum limit
  @note: Max() call.
[==============================================================================}
function TIntegerHelper.LimitMin(const limit: Integer): Integer; cdecl;
begin
  Result := Max(Self, limit);
end;

{==============================================================================]
  <Restrict>
  @action: Returns Integer bounded by minimum and maximum limits
  @note: None
[==============================================================================}
function TIntegerHelper.Restrict(const minimum, maximum: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - minimum) - Abs(Self - minimum)) div 2);
  Result := (Result - ((Result - maximum) + Abs(Result - maximum)) div 2);
end;

{==============================================================================]
  <RestrictMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.RestrictMax(const limit: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) div 2);
end;

{==============================================================================]
  <RestrictMin>
  @action: Returns Integer bounded by minimum limit
  @note: None
[==============================================================================}
function TIntegerHelper.RestrictMin(const limit: Integer): Integer; cdecl;
begin
  Result := (Self - ((Self - limit) - Abs(Self - limit)) div 2);
end;
{$ENDIF}