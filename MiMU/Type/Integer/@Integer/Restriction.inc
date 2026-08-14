{$IFDEF HELPERS}
function Bound(const minimum, maximum: Integer): Integer;
function BoundMax(const limit: Integer): Integer;
function BoundMin(const limit: Integer): Integer;
function Clamp(const range: TRange): Integer; overload;
function Constraint(const range: TRange): Boolean; overload;
function Restrict(const minimum, maximum: Integer): Integer;
function RestrictMax(const limit: Integer): Integer;
function RestrictMin(const limit: Integer): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BoundMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.BoundMax(const limit: Integer): Integer;
begin
  Result := (((Self + limit) - Abs(Self - limit)) div 2);
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
  <Contstraint>
  @action: Returns true if Integer is constrainted with range
  @note: None
[==============================================================================}
function TIntegerHelper.Constraint(const range: TRange): Boolean; overload;
begin
  Result := (Self.ConstraintMin(range.Minimum) or Self.ConstraintMax(range.Maximum));
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
  <RestrictMax>
  @action: Returns Integer bounded by maximum limit
  @note: None
[==============================================================================}
function TIntegerHelper.RestrictMax(const limit: Integer): Integer;
begin
  Result := (Self - ((Self - limit) + Abs(Self - limit)) div 2);
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
{$ENDIF}