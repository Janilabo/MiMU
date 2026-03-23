{$IFDEF METHODS}
function Bipolar: Boolean;
function Exceeds(const maxElements: Integer): Boolean;
function IsNarrow(const val: Integer): Boolean; overload;
function Insufficient(const minElements: Integer): Boolean;
function IsNegligible(const threshold: Integer = 0): Boolean; overload;
function IsSignificant(const threshold: Integer = 0): Boolean; overload;
function IsSubstantial(const threshold: Integer): Boolean; overload;
function IsWide(const val: Integer): Boolean; overload;
function Natural: Boolean; overload;
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
  <IsNarrow>
  @action: Returns True if the range's size is strictly less than the threshold.
  @note: Use this to detect "thin" or "sub-limit" spans where Size < val.
[==============================================================================}
function TRange.IsNarrow(const val: Integer): Boolean; overload;
begin
  Result := (Self.Size < val);
end;

{==============================================================================]
  <IsNegligible>
  @action: Returns True if the range is so small it can be ignored.
  @note: Usually used for "Zero-checks" or "Noise-filtering."
[==============================================================================}
function TRange.IsNegligible(const threshold: Integer = 0): Boolean; overload;
begin
  Result := (Self.Size <= threshold);
end;

{==============================================================================]
  <IsSignificant>
  @action: Returns True if the range is large enough to be meaningful.
  @note: This is the logical inverse of IsNegligible.
[==============================================================================}
function TRange.IsSignificant(const threshold: Integer = 0): Boolean; overload;
begin
  Result := (Self.Size > threshold);
end;

{==============================================================================]
  <IsSubstantial>
  @action: Returns True if the range exceeds a large, specific scale.
  @note: A formal synonym for IsLarge; implies a "major" span.
[==============================================================================}
function TRange.IsSubstantial(const threshold: Integer): Boolean; overload;
begin
  Result := (Self.Size >= threshold);
end;

{==============================================================================]
  <IsWide>
  @action: Returns True if the range's size is greater than or equal to the threshold.
  @note: Use this to detect "broad" or "at-limit" spans where Size >= val.
[==============================================================================}
function TRange.IsWide(const val: Integer): Boolean; overload;
begin
  Result := (Self.Size >= val);
end;

{==============================================================================]
  <Natural>
  @action: Determines whether the range lies entirely within the natural numbers.
  @note  :
    - Returns True if both `start` and `stop` are greater than or equal to 0.
    - Returns False if either endpoint is negative.
    - Does not consider ordering; only checks the sign of the endpoints.
    - Useful for validating ranges intended to represent non-negative domains.
[==============================================================================}
function TRange.Natural: Boolean; overload;
begin
  Result := ((Self.start >= 0) and (Self.stop >= 0));
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
