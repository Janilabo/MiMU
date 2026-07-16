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
function Matches(const b: TRange): Boolean; overload;
function Matching(const target: TRange): Boolean; overload;

function Differ(const b: TRange): Boolean; overload;
function Differing(const b: TRange): Boolean; overload;
function Mismatch(const b: TRange): Boolean; overload;
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
  <Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean; overload;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
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
{$ENDIF}
