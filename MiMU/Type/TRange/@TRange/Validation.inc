{$IFDEF METHODS}
function Ascendual: Boolean; overload;
function Ascenduet: Boolean; overload;
function Ascenduo: Boolean; overload;
function Ascouple: Boolean; overload;
function Bipolar: Boolean; overload;
function Couple: Boolean; overload;
function Coupled: Boolean; overload;
function Coupley: Boolean; overload;
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
function Nullbound: Boolean; overload;
function Axial: Boolean; overload;
function Anchoral: Boolean; overload;
function Anchored: Boolean; overload;
function Anchorly: Boolean; overload;
function Midzero: Boolean; overload;
function Midzeroing: Boolean; overload;
function Positive: Boolean; overload;
function Terminal(const sValue: Integer = 0): Boolean; overload;
function Uniform(const val: Integer): Boolean; overload;
function Uniform: Boolean; overload;
function Zero: Boolean; overload;
function Balanced: Boolean; overload;
function Balancy: Boolean; overload;
function Unbalanced: Boolean; overload;
function Unbalancy: Boolean; overload;
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
  <Couple>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Uses ordinal Succ/Pred stepping rather than arithmetic subtraction,
         routing the check through the compiler's ordinal-type successor and
         predecessor machinery instead of a raw '-' operator.
[==============================================================================}
function TRange.Couple: Boolean; overload;
begin
  Result := ((System.Succ(Self.start) = Self.stop) or (System.Pred(Self.start) = Self.stop));
end;

{==============================================================================]
  <Coupled>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Minimal absolute-value form — collapses direction via Abs(Delta)
         and compares directly against unity, with no intermediate branching
         or lookup structure.
[==============================================================================}
function TRange.Coupled: Boolean; overload;
begin
  Result := (Abs(Self.Delta) = 1);
end;

{==============================================================================]
  <Coupley>
  @action: Returns True if the range spans exactly one consecutive step in either direction.
  @note: Leverages the high-level Size property. Assuming Size calculates the 
         inclusive element count, a size of exactly 2 confirms that the range 
         contains only two adjacent structural points.
[==============================================================================}
function TRange.Coupley: Boolean; overload;
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
  <Nullbound>
  @action: Returns True if the range's midpoint is exactly zero.
  @note:
    - A range is zero-centered when start and stop are additive inverses of
      one another, i.e. (start + stop) = 0 (e.g., [-2..2], [2..-2], [-1..1],
      [1..-1]).
    - Also holds for the degenerate single-point range [0..0], since its
      only value is trivially its own midpoint.
[==============================================================================}
function TRange.Nullbound: Boolean; overload;
begin
  Result := ((Self.start + Self.stop) = 0);
end;

{==============================================================================]
  <Axial>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Tests via direct negation comparison rather than addition-to-zero —
         confirms stop is the exact arithmetic negative of start.
[==============================================================================}
function TRange.Axial: Boolean; overload;
begin
  Result := (Self.stop = -Self.start);
end;

{==============================================================================]
  <Anchoral>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Uses squared-sum equality — since (start + stop)^2 = 0 only when
         the sum itself is zero, this frames the check as a quadratic
         identity rather than a linear addition or negation comparison.
[==============================================================================}
function TRange.Anchoral: Boolean; overload;
begin
  Result := (Sqr(Self.start + Self.stop) = 0);
end;

{==============================================================================]
  <Anchored>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Tests via multiplication sign inversion — start multiplied by -1
         must equal stop, framing the check as a scalar reflection rather
         than an additive or subtractive identity.
[==============================================================================}
function TRange.Anchored: Boolean; overload;
begin
  Result := ((Self.start * -1) = Self.stop);
end;

{==============================================================================]
  <Anchorly>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Routes through the ordinal Compare method rather than an operator —
         confirms start and the negation of stop compare as exactly equal.
[==============================================================================}
function TRange.Anchorly: Boolean; overload;
begin
  Result := (Self.start.Compare(-Self.stop) = 0);
end;

{==============================================================================]
  <Midzero>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Evaluates zero-midpoint symmetry via a linear differential identity. 
         By checking if the spatial difference matches twice the starting boundary, 
         the formula algebraically reduces to (start + stop = 0) without requiring 
         multiplication operations to cross zero.
[==============================================================================}
function TRange.Midzero: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) = (2 * Self.start));
end;

{==============================================================================]
  <Midzeroing>
  @action: Returns True if the range's midpoint is exactly zero.
  @note: Floating-point average check — divides the summed boundaries by
         2.0 and compares against 0.0, routing the test through real-number
         division rather than integer arithmetic.
[==============================================================================}
function TRange.Midzeroing: Boolean; overload;
begin
  Result := (((Self.start + Self.stop) / 2.0) = 0.0);
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

{==============================================================================]
  <Balanced>
  @action: Returns True if the range has an exact, integer-valued midpoint.
  @note:
    - A range is balanced when start and stop share the same parity, meaning
      (start + stop) is evenly divisible by 2 with no fractional remainder.
    - Uses Abs on the summed boundaries to avoid relying on negative-operand
      'mod' semantics, guaranteeing consistent behavior across all sign
      combinations of start and stop.
[==============================================================================}
function TRange.Balanced: Boolean; overload;
begin
  Result := ((Abs(Self.start + Self.stop) mod 2) = 0);
end;

{==============================================================================]
  <Balancy>
  @action: Returns True if the range has an exact, integer-valued midpoint.
  @note: A range is balanced when start and stop share the same parity, meaning
         their sum is an even number. Uses a branchless bitwise AND mask on the 
         lowest bit, completely bypassing division to guarantee high performance 
         and perfect stability across all sign combinations.
[==============================================================================}
function TRange.Balancy: Boolean; overload;
begin
  Result := (((Self.start + Self.stop) and 1) = 0);
end;

{==============================================================================]
  <Unbalanced>
  @action: Returns True if the range has no exact, integer-valued midpoint.
  @note:
    - Tests parity directly rather than delegating to Balanced — evaluates
      whether (start + stop) is odd via Abs-guarded 'mod', avoiding any
      dependency on Boolean negation or a separate function call.
[==============================================================================}
function TRange.Unbalanced: Boolean; overload;
begin
  Result := ((Abs(Self.start + Self.stop) mod 2) = 1);
end;

{==============================================================================]
  <Unbalancy>
  @action: Returns True if the range has no exact, integer-valued midpoint.
  @note: Tests parity directly via bitwise mask rather than delegating or using
         negation. Evaluates whether the lowest binary bit of the summed 
         boundaries is set, confirming the sum is odd.
[==============================================================================}
function TRange.Unbalancy: Boolean; overload;
begin
  Result := (((Self.start + Self.stop) and 1) = 1);
end;
{$ENDIF}
