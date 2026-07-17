{$IFDEF METHODS}
function Coequal(const target: TRange; const strictly: Boolean = False): Boolean; overload;

function Equal(const b: TRange): Boolean; overload;
function Equaled(const b: TRange): Boolean; overload;
function Equaling(const b: TRange): Boolean; overload;
function Equality(const b: TRange): Boolean; overload;
function Equals(const b: TRange): Boolean; overload;
function Equalsy(const b: TRange): Boolean; overload;
function Equaly(const b: TRange): Boolean; overload;
function Equalz(const b: TRange): Boolean; overload;
function Equant(const b: TRange): Boolean; overload;

function Match(const b: TRange): Boolean; overload;
function Matchal(const b: TRange): Boolean; overload;
function Matched(const b: TRange): Boolean; overload;
function Matches(const b: TRange): Boolean; overload;
function Matchet(const b: TRange): Boolean; overload;
function Matching(const target: TRange): Boolean; overload;
function Matchly(const b: TRange): Boolean; overload;
function Matchy(const b: TRange): Boolean; overload;

function Diffent(const b: TRange): Boolean; overload;
function Differ(const b: TRange): Boolean; overload;
function Differal(const b: TRange): Boolean; overload;
function Differed(const b: TRange): Boolean; overload;
function Differing(const b: TRange): Boolean; overload;
function Differs(const b: TRange): Boolean; overload;
function Differy(const b: TRange): Boolean; overload;
function Differz(const b: TRange): Boolean; overload;

function Mismatch(const b: TRange): Boolean; overload;
function Mismatcha(const b: TRange): Boolean; overload;
function Mismatchal(const b: TRange): Boolean; overload;
function Mismatched(const b: TRange): Boolean; overload;
function Mismatchet(const b: TRange): Boolean; overload;
function Mismatching(const b: TRange): Boolean; overload;
function Mismatchy(const b: TRange): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Coequal>
  @action: Determines whether two ranges are equal under either strict or
           normalized comparison semantics.
           Supports dual-mode equality:
             * Strict equality: direct field comparison (start/stop).
             * Non-strict equality: compares normalized bounds to account for
               differing internal representations.
  @note:
    - strictly = True:
        * Performs exact, field-level comparison:
            (Self.start = target.start) AND
            (Self.stop  = target.stop)
        * No normalization is applied.
        * Fastest path (O(1)).
		* Strict mode avoids overhead when invariants are already enforced.
    - strictly = False:
        * Compares normalized ranges:
            s := Self.Normalized
            t := target.Normalized
            Result = (s.start = t.start) AND (s.stop = t.stop)
        * Ensures equivalence even if:
            - bounds are reversed (start > stop)
            - internal representation differs but logical interval matches
        * Non-strict mode is safer for external inputs or mixed range sources.
[==============================================================================}
function TRange.Coequal(const target: TRange; const strictly: Boolean = False): Boolean; overload;
var
  s, t: TRange;
begin
  if strictly then
    Exit((Self.start = target.start) and (Self.stop = target.stop));
  s := Self.Normalized;
  t := target.Normalized;
  Result := ((s.start = t.start) and (s.stop = t.stop));
end;

{==============================================================================]
  <Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Equal(const b: TRange): Boolean; overload;
begin
  Result := ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <Equaled>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Equaled(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start xor b.start) or (Self.stop xor b.stop)) = 0);
end;

{==============================================================================]
  <Equaling>
  @action: Determines structural equality between two ranges using a zero-sum mismatch evaluation.
  @note: 
    - Converts inequality checks (<>) into binary integers (1 for a mismatch, 0 for a match).
    - Sums the mismatch scores; a combined total of exactly 0 confirms both start and stop boundaries are identical.
    - Eliminates conditional branching, processing both boundary checks mathematically.
[==============================================================================}
function TRange.Equaling(const b: TRange): Boolean; overload;
begin
  Result := ((Ord(Self.start <> b.start) + Ord(Self.stop <> b.stop)) = 0);
end;

{==============================================================================]
  <Equality>
  @action: Assesses structural equality via absolute distance summation.
  @note: 
    - Calculates the absolute mathematical delta of both individual boundaries.
    - A combined delta sum of zero guarantees absolute coordinate parity.
[==============================================================================}
function TRange.Equality(const b: TRange): Boolean; overload;
begin
  Result := ((Abs(Self.start - b.start) + Abs(Self.stop - b.stop)) = 0);
end;

{==============================================================================]
  <Equals>
  @action: Evaluates whether two ranges are structurally and directionally identical.
  @note: 
    - Computes zero-differential equality for both start and stop boundaries.
    - Unlike value-containment comparisons, this requires matching orientations
	  (e.g., an ascending range will not equal its inverted descending counterpart).
[==============================================================================}
function TRange.Equals(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start - b.start) = 0) and ((Self.stop - b.stop) = 0));
end;

{==============================================================================]
  <Equalsy>
  @action: Compares the current range (Self) with another range (b) to determine if they are identical.
  @note: Uses direct, nested conditional checks to evaluate equality. 
         Compared to the mathematical trick in `Equalz`, this approach is much more readable, performant,
		 and avoids any risk of numerical overflow since it bypasses arithmetic operations entirely.
		 It utilizes an early exit (`Exit(True)`) if a match is found, defaulting to `False` otherwise.
[==============================================================================}
function TRange.Equalsy(const b: TRange): Boolean; overload;
begin
  if (Self.start = b.start) then
    if (Self.stop = b.stop) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Equaly>
  @action: Performs a branchless logical evaluation to determine if two ranges share identical structures.
  @note: 
    - Converts individual boundary equality evaluations into ordinal integer states (0 or 1).
    - Multiplies the states to eliminate conditional branch mispredictions at the hardware level.
    - Requires matching start and stop trajectories; inverted matching ranges will return False.
[==============================================================================}
function TRange.Equaly(const b: TRange): Boolean; overload;
begin
  Result := Boolean(Ord(Self.start = b.start) * Ord(Self.stop = b.stop));
end;

{==============================================================================]
  <Equalz>
  @action: Compares the current range (Self) with another range (b) to determine if they are identical.
  @note: Uses the sum of squares of the differences:
         $$(Self.start - b.start)^2 + (Self.stop - b.stop)^2 = 0$$
         Since the square of a real number is always non-negative,
		 this sum can only equal zero if both individual differences are zero (i.e., $Self.start = b.start$ and $Self.stop = b.stop$). 
         Note that while mathematically clever, a standard logical comparison `(Self.start = b.start) and (Self.stop = b.stop)`
		 is typically more readable and faster to execute.
[==============================================================================}
function TRange.Equalz(const b: TRange): Boolean; overload;
begin
  Result := (Sqr(Self.start - b.start) + Sqr(Self.stop - b.stop) = 0);
end;

{==============================================================================]
  <Equant>
  @action: Determines structural equality using a nested, short-circuiting logical evaluation.
  @note: 
    - First evaluates the start boundaries; if they differ, it exits immediately with False.
    - Only compares the stop boundaries if the start boundaries are confirmed to be identical.
    - Highly efficient for datasets where ranges are statistically likely to start at different coordinates.
[==============================================================================}
function TRange.Equant(const b: TRange): Boolean; overload;
begin
  if (Self.start = b.start) then
    Result := (Self.stop = b.stop)
  else
    Result := False;
end;

{==============================================================================]
  <Match>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Match(const b: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum = b.Minimum) and (Self.Maximum = b.Maximum));
end;

{==============================================================================]
  <Matchal>
  @action: Checks for an exact boundary match using subtraction.
  @note: If TRange uses floating-point types, this is prone to precision rounding 
         errors (epsilon comparison is preferred). For integer types, watch out 
         for potential arithmetic overflow under strict compiler checks.
[==============================================================================}
function TRange.Matchal(const b: TRange): Boolean; overload;
begin
  Result := (((Self.Minimum - b.Minimum) = 0) and ((Self.Maximum - b.Maximum) = 0));
end;

{==============================================================================]
  <Matched>
  @action: Compares the current range with another to check for an exact boundary match.
  @note: Uses bitwise XOR check. Ensure TRange bounds are integer-based; 
         floating-point types may bypass precision/epsilon tolerances.
[==============================================================================}
function TRange.Matched(const b: TRange): Boolean; overload;
begin
  Result := (((Self.Minimum xor b.Minimum) = 0) and ((Self.Maximum xor b.Maximum) = 0));
end;

{==============================================================================]
  <Matches>
  @action: Determines whether two ranges represent the same interval,
           regardless of boundary ordering.
  @return: True: both ranges have identical bounds (direct or reversed)
           False: ranges differ in at least one boundary
  @note: Order-insensitive comparison; [a..b] is equivalent to [b..a].
         Does not require prior normalization.
[==============================================================================}
function TRange.Matches(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start = b.start) and (Self.stop = b.stop)) or ((Self.start = b.stop) and (Self.stop = b.start)));
end;

{==============================================================================]
  <Matchet>
  @action: Determines direction-insensitive structural equality using a nested,
           short-circuiting logical evaluation on normalized bounds.
  @note: 
    - First evaluates the Minimum boundaries; if they differ, exits immediately with False.
    - Only compares the Maximum boundaries if the Minimum boundaries are confirmed identical.
    - Direction-insensitive complement of Equant: 0..3 and 3..0 ARE treated as a match,
      since normalized bounds (Minimum/Maximum) are used rather than raw start/stop.
    - Short-circuit sibling of Match; logical complement of Mismatchet.
[==============================================================================}
function TRange.Matchet(const b: TRange): Boolean; overload;
begin
  if (Self.Minimum = b.Minimum) then
    Result := (Self.Maximum = b.Maximum)
  else
    Result := False;
end;

{==============================================================================]
  <Matching>
  @action: Returns True if both ranges occupy the exact same physical span 
           on the number line.        
  @note: This is a spatial check, not a structural one. For example, 
         [1..10] and [10..1] are considered equivalent because they 
         cover the same ground.
         Relies on RelationshipTo(target) returning 3 (Binary 0011), 
         indicating that both the Minimum and Maximum boundaries match.
[==============================================================================}
function TRange.Matching(const target: TRange): Boolean; overload;
begin
  Result := (Self.RelationshipTo(target) = 3);
end;

{==============================================================================]
  <Matchly>
  @action: Asserts a match by summing the boolean inequalities of the boundaries
           converted to integers, ensuring the total inequality sum is zero.
  @note: Bypasses standard compiler short-circuit evaluation, forcing both 
         minimum and maximum boundaries to be checked every time.
[==============================================================================}
function TRange.Matchly(const b: TRange): Boolean; overload;
begin
  Result := ((Ord(Self.Minimum <> b.Minimum) + Ord(Self.Maximum <> b.Maximum)) = 0);
end;

{==============================================================================]
  <Matchy>
  @action: Determines whether two ranges occupy the same normalized interval.
  @note: Two ranges are Matchy if their normalized forms coincide, even when
         raw start/stop orientation differs. Normalize-based sibling to Match
         (which compares Minimum/Maximum directly) — same result, different route.
[==============================================================================}
function TRange.Matchy(const b: TRange): Boolean; overload;
var
  s, t: TRange;
begin
  s := Self.Normalized;
  t := b.Normalized;
  Result := ((s.start = t.start) and (s.stop = t.stop));
end;

{==============================================================================]
  <Diffent>
  @action: Determines structural inequality using a nested, short-circuiting logical evaluation.
  @note: 
    - First evaluates the start boundaries; if they differ, exits immediately with True.
    - Only compares the stop boundaries if the start boundaries are confirmed identical.
    - Short-circuit complement to Equant; efficient when ranges are statistically
      likely to differ at the start boundary.
[==============================================================================}
function TRange.Diffent(const b: TRange): Boolean; overload;
begin
  if (Self.start <> b.start) then
    Result := True
  else
    Result := (Self.stop <> b.stop);
end;

{==============================================================================]
  <Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean; overload;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <Differal>
  @action: Returns True if there is any difference between the start or stop 
           boundaries of the two ranges.
  @note: Uses subtraction-to-zero equivalence. Ensure TRange implements 
         'start' and 'stop' fields (unlike the Min/Max used in other matchers), 
         and watch for floating-point rounding errors or integer overflows.
[==============================================================================}
function TRange.Differal(const b: TRange): Boolean; overload;
begin
  Result := not (((Self.start - b.start) = 0) and ((Self.stop - b.stop) = 0));
end;

{==============================================================================]
  <Differed>
  @action: Checks if a mismatches b, using bitwise XOR to detect boundary divergence.
  @note: 
    - XOR-based complement to Equaled: 0..3 and 3..0 will NOT be treated as a match,
      since this compares raw start/stop directly rather than normalized bounds.
    - (Self.start xor b.start) is nonzero iff the values differ; same for stop.
    - Combines both checks with OR so that a divergence in either boundary is sufficient.
    - Overflow-safe regardless of sign or magnitude, unlike subtraction- or
      square-based equivalents (Differs, Differz).
[==============================================================================}
function TRange.Differed(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start xor b.start) <> 0) or ((Self.stop xor b.stop) <> 0));
end;

{==============================================================================]
  <Differing>
  @action: Compares the current range (Self) with another range (b) to determine if they are different.
  @note: Evaluates to `True` if either the start point, the stop point, or both points do not match. 
         This is implemented by logically negating (`not`) a direct equality check of both boundary properties.
		 It is highly readable, efficient, and is the logical inverse of `Equalsy`.
[==============================================================================}
function TRange.Differing(const b: TRange): Boolean; overload;
begin
  Result := not ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <Differs>
  @action: Evaluates whether two ranges are structurally or directionally different.
  @note: 
    - Computes non-zero-differential inequality for either the start or stop boundary.
    - Subtraction-based complement to Equals; requires matching orientations,
      so an ascending range is Differs from its inverted descending counterpart.
    - As with Equals, uses arithmetic subtraction rather than a direct <> comparison;
      functionally safe for <>0 checks but avoid reusing this pattern where the
      magnitude of the difference matters, since it can overflow silently.
[==============================================================================}
function TRange.Differs(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start - b.start) <> 0) or ((Self.stop - b.stop) <> 0));
end;

{==============================================================================]
  <Differy>
  @action: Determines structural inequality between two ranges using a zero-sum mismatch evaluation.
  @note: 
    - Converts inequality checks (<>) into binary integers (1 for a mismatch, 0 for a match).
    - Sums the mismatch scores; any combined total greater than 0 confirms at least one boundary differs.
    - Branchless complement to Equaling.
[==============================================================================}
function TRange.Differy(const b: TRange): Boolean; overload;
begin
  Result := ((Ord(Self.start <> b.start) + Ord(Self.stop <> b.stop)) > 0);
end;

{==============================================================================]
  <Differz>
  @action: Compares the current range (Self) with another range (b) to determine if they differ.
  @note: Uses the sum of squares of the differences:
         $$(Self.start - b.start)^2 + (Self.stop - b.stop)^2 \neq 0$$
         Since squares are non-negative, any nonzero sum guarantees at least one boundary
         differs. Mathematically cute complement to Equalz; a plain <> comparison is faster.
[==============================================================================}
function TRange.Differz(const b: TRange): Boolean; overload;
begin
  Result := ((Sqr(Self.start - b.start) + Sqr(Self.stop - b.stop)) <> 0);
end;

{==============================================================================]
  <Mismatch>
  @action: Compares the absolute boundaries of the current range (Self) with range (b) to see if they differ.
  @note: Uses normalized bounds (Minimum/Maximum) instead of raw start/stop properties. 
         This makes the check direction-insensitive; for example, a range of 0..3 and 3..0 
         will yield matching Minimums (0) and Maximums (3), resulting in False (no mismatch).
[==============================================================================}
function TRange.Mismatch(const b: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum <> b.Minimum) or (Self.Maximum <> b.Maximum));
end;

{==============================================================================]
  <Mismatcha>
  @action: Determines whether two ranges represent different intervals,
           regardless of boundary ordering.
  @return: True: ranges differ in bounds under both direct and reversed comparison
           False: ranges share identical bounds in either orientation
  @note: Order-insensitive complement to Matches; [a..b] and [b..a] are NOT
         mismatching with each other. Uses raw start/stop rather than Minimum/Maximum.
[==============================================================================}
function TRange.Mismatcha(const b: TRange): Boolean; overload;
begin
  Result := not (((Self.start = b.start) and (Self.stop = b.stop)) or ((Self.start = b.stop) and (Self.stop = b.start)));
end;

{==============================================================================]
  <Mismatchal>
  @action: Nautical register — determines whether Self and b are off-course
           from one another, direction-insensitively.
  @note: Uses arithmetic subtraction on normalized bounds rather than a direct
         <> comparison; functionally safe for <>0 checks. 0..3 and 3..0 are
         considered on-course (not Askew) since Minimum/Maximum align.
[==============================================================================}
function TRange.Mismatchal(const b: TRange): Boolean; overload;
begin
  Result := (((Self.Minimum - b.Minimum) <> 0) or ((Self.Maximum - b.Maximum) <> 0));
end;

{==============================================================================]
  <Mismatched>
  @action: Compares the absolute boundaries of Self and b using bitwise XOR to
           detect divergence, direction-insensitively.
  @note: Uses normalized bounds (Minimum/Maximum). (Self.Minimum xor b.Minimum)
         is nonzero iff the values differ; combined with OR across both boundaries.
         0..3 and 3..0 yield matching Minimums/Maximums, so no mismatch is reported.
[==============================================================================}
function TRange.Mismatched(const b: TRange): Boolean; overload;
begin
  Result := (((Self.Minimum xor b.Minimum) <> 0) or ((Self.Maximum xor b.Maximum) <> 0));
end;

{==============================================================================]
  <Mismatchet>
  @action: Determines direction-insensitive structural inequality using a nested,
           short-circuiting logical evaluation on normalized bounds.
  @note: 
    - First evaluates the Minimum boundaries; if they diverge, exits immediately with True.
    - Only compares the Maximum boundaries if the Minimum boundaries are confirmed identical.
    - Direction-insensitive complement of Diffent: 0..3 and 3..0 are NOT considered a
      mismatch, since normalized bounds (Minimum/Maximum) are used rather than raw start/stop.
    - Short-circuit sibling of Mismatch; logical complement of Matchet.
[==============================================================================}
function TRange.Mismatchet(const b: TRange): Boolean; overload;
begin
  if (Self.Minimum <> b.Minimum) then
    Result := True
  else
    Result := (Self.Maximum <> b.Maximum);
end;

{==============================================================================]
  <Mismatching>
  @action: Returns True if the two ranges do NOT occupy the exact same physical
           span on the number line.
  @note: Logical complement of Matching. Relies on RelationshipTo(target)
         returning any value other than 3 (Binary 0011), indicating that at
         least one of the Minimum/Maximum boundaries fails to align.
[==============================================================================}
function TRange.Mismatching(const b: TRange): Boolean; overload;
begin
  Result := (Self.RelationshipTo(b) <> 3);
end;

{==============================================================================]
  <Mismatchy>
  @action: Direction-insensitive structural mismatch via zero-sum evaluation.
  @note: Converts inequality checks on Minimum/Maximum into ordinal integers
         (1 for mismatch, 0 for match); any sum greater than 0 confirms divergence.
         Branchless sibling of Mismatch.
[==============================================================================}
function TRange.Mismatchy(const b: TRange): Boolean; overload;
begin
  Result := ((Ord(Self.Minimum <> b.Minimum) + Ord(Self.Maximum <> b.Maximum)) > 0);
end;
{$ENDIF}
