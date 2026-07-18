{$IFDEF METHODS}
function Ascendual: Boolean; overload;
function Ascenduet: Boolean; overload;
function Ascenduo: Boolean; overload;
function Ascouple: Boolean; overload;
function Bipolar: Boolean; overload;
function Coupled: Boolean; overload;
function Descendual: Boolean; overload;
function Descenduet: Boolean; overload;
function Descenduo: Boolean; overload;
function Descouple: Boolean; overload;
function Doublet: Boolean; overload;
function Dual: Boolean; overload;
function Duet: Boolean; overload;
function Duo: Boolean; overload;
function Exceeds(const maxElements: Integer): Boolean; overload;
function IsNarrow(const val: Integer): Boolean; overload;
function Insufficient(const minElements: Integer): Boolean; overload;
function IsNegligible(const threshold: Integer = 0): Boolean; overload;
function IsSignificant(const threshold: Integer = 0): Boolean; overload;
function IsSubstantial(const threshold: Integer): Boolean; overload;
function IsWide(const val: Integer): Boolean; overload;
function Natural: Boolean; overload;
function Negative: Boolean; overload;
function Nonascend(const val: Integer): Boolean; overload;
function Nondescend(const val: Integer): Boolean; overload;
function NonNegative: Boolean; overload;
function NonPositive: Boolean; overload;
function Positive: Boolean; overload;
function Terminal(const sValue: Integer = 0): Boolean; overload;
function Uniform(const val: Integer): Boolean; overload;
function Uniform: Boolean; overload;
function Zero: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascendual>
  @action: Determines whether the range is a minimal, ascending two-point step.
  @note:
    - Returns True strictly if the range is sorted in ascending order and contains exactly 2 elements.
    - Useful for detecting direct forward transitions or adjacent increments.
[==============================================================================}
function TRange.Ascendual: Boolean; overload;
begin
  Result := (Self.Ascending and (Self.size = 2));
end;

{==============================================================================]
  <Ascenduet>
  @action: Returns True if the range represents a single, positive consecutive step.
  @note: Ensures the stop boundary is greater than the start boundary via native
         comparison (= 1) while verifying a precise forward unitary gap size.
[==============================================================================}
function TRange.Ascenduet: Boolean; overload;
begin
  Result := ((Self.stop.Compare(Self.start) = 1) and ((Self.stop - Self.start) = 1));
end;

{==============================================================================]
  <Ascenduo>
  @action: Returns True if the range represents a single, positive consecutive step.
  @note: Validates that the start boundary sits exactly one unit below the 
         stop boundary (e.g., [4..5]).
[==============================================================================}
function TRange.Ascenduo: Boolean; overload;
begin
  Result := (Self.start = (Self.stop - 1));
end;

{==============================================================================]
  <Ascouple>
  @action: Returns True if the range represents a single, positive consecutive step.
  @note: Uses a zero-balanced arithmetic subtraction formula. Evaluates to True 
         only when the forward distance delta minus one equals exactly zero.
[==============================================================================}
function TRange.Ascouple: Boolean; overload;
begin
  Result := (((Self.stop - Self.start) - 1) = 0);
end;

{==============================================================================]
  <Bipolar>
  @action: Returns True if the range spans both negative and positive numbers.
  @note: The function is True when Self.start and Self.stop have opposite signs,
         i.e., one is negative and the other is positive. Zero endpoints are not included.
[==============================================================================}
function TRange.Bipolar: Boolean; overload;
begin
  Result := ((Self.start < 0) and (Self.stop > 0)) or ((Self.start > 0) and (Self.stop < 0));
end;

{==============================================================================]
  <Coupled>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Leverages the high-level Size property. Assuming Size calculates the 
         inclusive element count, a size of exactly 2 confirms that the range 
         contains only two adjacent structural points.
[==============================================================================}
function TRange.Coupled: Boolean; overload;
begin
  Result := (Self.Size = 2);
end;

{==============================================================================]
  <Descendual>
  @action: Determines whether the range is a minimal, descending two-point step.
  @note:
    - Returns True strictly if the range is sorted in descending order and contains exactly 2 elements.
    - Useful for detecting direct backward transitions or adjacent decrements.
[==============================================================================}
function TRange.Descendual: Boolean; overload;
begin
  Result := (Self.Descending and (Self.size = 2));
end;

{==============================================================================]
  <Descenduet>
  @action: Returns True if the range represents a single, negative consecutive step.
  @note: Ensures the start boundary is greater than the stop boundary via native
         comparison (= 1) while verifying a precise reverse unitary gap size.
[==============================================================================}
function TRange.Descenduet: Boolean; overload;
begin
  Result := ((Self.start.Compare(Self.stop) = 1) and ((Self.start - Self.stop) = 1));
end;

{==============================================================================]
  <Descenduo>
  @action: Returns True if the range represents a single, negative consecutive step.
  @note: Validates that the start boundary sits exactly one unit above the 
         stop boundary (e.g., [5..4]).
[==============================================================================}
function TRange.Descenduo: Boolean; overload;
begin
  Result := (Self.start = (Self.stop + 1));
end;

{==============================================================================]
  <Descouple>
  @action: Returns True if the range represents a single, negative consecutive step.
  @note: Uses a zero-balanced arithmetic addition formula. Evaluates to True 
         only when the backward distance delta plus one equals exactly zero.
[==============================================================================}
function TRange.Descouple: Boolean; overload;
begin
  Result := (((Self.stop - Self.start) + 1) = 0);
end;

{==============================================================================]
  <Doublet>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Leverages a tight, short-circuited array pattern lookup. InRange safely
         bounds-checks the Delta value before indexing into a static boolean 
         map, ensuring branchless performance for valid inputs.
[==============================================================================}
function TRange.Doublet: Boolean; overload;
const
  r: array[0..2] of Boolean = (True, False, True);
begin
  Result := (InRange(Self.Delta, -1, 1) and r[Self.Delta + 1]);
end;

{==============================================================================]
  <Dual>
  @action: Determines whether the range represents exactly two adjacent, consecutive values.
  @note: 
    - Returns True if the stop boundary is exactly one unit greater or one unit less than the start boundary.
    - Represents a tight two-element pairing (a step of exactly 1 in either direction).
[==============================================================================}
function TRange.Dual: Boolean; overload;
begin
  Result := (((Self.start + 1) = Self.stop) or ((Self.start - 1) = Self.stop));
end;

{==============================================================================]
  <Duet>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Implements a high-performance, branchless bitwise strategy. By squaring 
         the distance delta, signs are eliminated, mapping both 1 and -1 to a 
         perfect bitwise match (xor 1 = 0). Safe for negative values.
[==============================================================================}
function TRange.Duet: Boolean; overload;
begin
  Result := (((Self.stop - Self.start) * (Self.stop - Self.start)) xor 1) = 0;
end;

{==============================================================================]
  <Duo>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Evaluates both Ascenduo and Descenduo, returning True if the absolute 
         distance between start and stop is exactly one unit.
[==============================================================================}
function TRange.Duo: Boolean; overload;
begin
  Result := (Self.Ascenduo or Self.Descenduo);
end;

{==============================================================================]
  <Exceeds>
  @action: Returns true if TRange contains more than maxElements.
  @note: TRange Exceeds maximum elements.
[==============================================================================}
function TRange.Exceeds(const maxElements: Integer): Boolean; overload;
begin
  Result := (Self.Size > maxElements);
end;

{==============================================================================]
  <Insufficient>
  @action: Returns true if TRange contains less than minElements.
  @note: TRange is behind minimum elements.
[==============================================================================}
function TRange.Insufficient(const minElements: Integer): Boolean; overload;
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
function TRange.Negative: Boolean; overload;
begin
  Result := ((Self.start < 0) and (Self.stop < 0));
end;

{==============================================================================]
  <Nonascend>
  @action: Evaluates if the range can accept a new value without ascending.
  @note: Returns True if the specified value is less than or equal to the start
         boundary, keeping any progression non-ascending.
[==============================================================================}
function TRange.Nonascend(const val: Integer): Boolean; overload;
begin
  Result := not (Self.start < val);
end;

{==============================================================================]
  <Nondescend>
  @action: Evaluates if the range can accept a new value without descending.
  @note: Returns True if the specified value is greater than or equal to the start
         boundary, keeping any progression non-descending.
[==============================================================================}
function TRange.Nondescend(const val: Integer): Boolean; overload;
begin
  Result := not (Self.start > val);
end;

{==============================================================================]
  <NonNegative>
  @action: Returns True if both endpoints of the range are zero or positive.
  @note: Both Self.start and Self.stop must be greater than or equal to 0.
[==============================================================================}
function TRange.NonNegative: Boolean; overload;
begin
  Result := ((Self.start > -1) and (Self.stop > -1));
end;

{==============================================================================]
  <NonPositive>
  @action: Returns True if both endpoints of the range are zero or negative.
  @note: Both Self.start and Self.stop must be less than or equal to 0.
[==============================================================================}
function TRange.NonPositive: Boolean; overload;
begin
  Result := ((Self.start < 1) and (Self.stop < 1));
end;

{==============================================================================]
  <Positive>
  @action: Returns True if both endpoints of the range are strictly positive.
  @note: Both Self.start and Self.stop must be greater than 0.
[==============================================================================}
function TRange.Positive: Boolean; overload;
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
function TRange.Terminal(const sValue: Integer = 0): Boolean; overload;
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
function TRange.Zero: Boolean; overload;
begin
  Result := ((Self.start = 0) and (Self.stop = 0));
end;
{$ENDIF}
