{$IFDEF METHODS}
function Bipolar: Boolean;
function Exceeds(const maxElements: Integer): Boolean;
function Insufficient(const minElements: Integer): Boolean;
function Negative: Boolean;
function NonNegative: Boolean;
function NonPositive: Boolean;
function Positive: Boolean;
function Terminal(const sValue: Integer = 0): Boolean;
function Uniform(const val: Integer): Boolean; overload;
function Uniform: Boolean; overload;
function Zero: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bipolar>
  @action: Returns True if the range spans both negative and positive numbers.
  @note: The function is True when Self.start and Self.stop have opposite signs,
         i.e., one is negative and the other is positive. Zero endpoints are not included.
[==============================================================================}
function TRange.Bipolar: Boolean;
begin
  Result := ((Self.start < 0) and (Self.stop > 0)) or ((Self.start > 0) and (Self.stop < 0));
end;

{==============================================================================]
  <Exceeds>
  @action: Returns true if TRange contains more than maxElements.
  @note: TRange Exceeds maximum elements.
[==============================================================================}
function TRange.Exceeds(const maxElements: Integer): Boolean;
begin
  Result := (Self.Size > maxElements);
end;

{==============================================================================]
  <Insufficient>
  @action: Returns true if TRange contains less than minElements.
  @note: TRange is behind minimum elements.
[==============================================================================}
function TRange.Insufficient(const minElements: Integer): Boolean;
begin
  Result := (Self.Size < minElements);
end;

{==============================================================================]
  <Negative>
  @action: Returns True if both endpoints of the range are strictly negative.
  @note: Both Self.start and Self.stop must be less than 0.
[==============================================================================}
function TRange.Negative: Boolean;
begin
  Result := ((Self.start < 0) and (Self.stop < 0));
end;

{==============================================================================]
  <NonNegative>
  @action: Returns True if both endpoints of the range are zero or positive.
  @note: Both Self.start and Self.stop must be greater than or equal to 0.
[==============================================================================}
function TRange.NonNegative: Boolean;
begin
  Result := ((Self.start > -1) and (Self.stop > -1));
end;

{==============================================================================]
  <NonPositive>
  @action: Returns True if both endpoints of the range are zero or negative.
  @note: Both Self.start and Self.stop must be less than or equal to 0.
[==============================================================================}
function TRange.NonPositive: Boolean;
begin
  Result := ((Self.start < 1) and (Self.stop < 1));
end;

{==============================================================================]
  <Positive>
  @action: Returns True if both endpoints of the range are strictly positive.
  @note: Both Self.start and Self.stop must be greater than 0.
[==============================================================================}
function TRange.Positive: Boolean;
begin
  Result := ((Self.start > 0) and (Self.stop > 0));
end;

{==============================================================================]
  <Terminal>
  @action: Returns True if exactly one endpoint of the range equals sValue and
           the other endpoint is strictly greater than sValue.
  @note: The function works for ascending or descending ranges. The default
         value of sValue is 0. Can be used to check for 0, 1, or any other
         integer at an endpoint.
[==============================================================================}
function TRange.Terminal(const sValue: Integer = 0): Boolean;
begin
  Result := (((Self.start = sValue) and (Self.stop > sValue)) or ((Self.stop = sValue) and (Self.start > sValue)));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether both endpoints of the range equal the specified value.
  @note: Returns True only if (Start = Stop = val).
[==============================================================================}
function TRange.Uniform(const val: Integer): Boolean; overload;
begin
  Result := ((Self.start = val) and (Self.stop = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether the range’s start and stop positions are equal.
  @note: Returns True if (Start = Stop).
[==============================================================================}
function TRange.Uniform: Boolean; overload;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <Zero>
  @action: Returns True if both endpoints of the range are exactly zero.
  @note: Self.start = 0 and Self.stop = 0.
[==============================================================================}
function TRange.Zero: Boolean;
begin
  Result := ((Self.start = 0) and (Self.stop = 0));
end;
{$ENDIF}