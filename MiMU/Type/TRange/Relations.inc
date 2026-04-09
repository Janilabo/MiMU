{$IFDEF METHODS}
function Abuts(const other: TRange): Boolean; overload;
function Adjacent(const other: TRange): Boolean; overload;
function Coequal(const target: TRange; const strictly: Boolean = False): Boolean; overload;
function Differ(const b: TRange): Boolean; overload;
function Differs(const b: TRange): Boolean; overload;
function Equal(const b: TRange): Boolean; overload;
function Equals(const b: TRange): Boolean; overload;
function Equivalent(const b: TRange): Boolean; overload;
function IsAdjacent(const other: TRange): Boolean; overload;
function IsConnected(const target: TRange): Boolean; overload;
function IsEquivalent(const target: TRange): Boolean; overload;
function IsMergeable(const other: TRange): Boolean; overload;
function Loose(const target: TRange): Boolean; overload;
function Meet(const other: TRange; out mRange: TRange): Boolean; overload;
function Mergeable(const other: TRange): Boolean; overload;
function Neighbor(const b: TRange): Boolean; overload;
function Neighbour(const b: TRange): Boolean; overload;
function Overlap(const b: TRange): Boolean; overload;
function Overlapping(const b: TRange): Boolean; overload;
function Overlaps(const other: TRange): Boolean; overload;
function RelationshipTo(const target: TRange): Byte; overload;
function RelationTo(const target: TRange): Byte; overload;
function Separated(const other: TRange): Boolean; overload;
function Touch(const b: TRange): Boolean; overload;
function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Abuts>
  @action: Determines whether two ranges are directly adjacent (touching but not overlapping).
  @note: Returns True if the end of one normalized range is exactly one unit before the start of the other;
         ranges do not share any elements.
[==============================================================================}
function TRange.Abuts(const other: TRange): Boolean; overload;
var
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  Result := ((s.stop = (o.start - 1)) or (o.stop = (s.start - 1)));
end;

{==============================================================================]
  <Adjacent>
  @action: Returns True if Other begins exactly where Self ends, or vice versa.
  @note: Treats ranges as adjacent regardless of direction.
[==============================================================================}
function TRange.Adjacent(const other: TRange): Boolean; overload;
begin
  Result := ((Abs(Self.stop - other.start) = 1) or (Abs(other.stop - Self.start) = 1));
end; 

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
    - strictly = False:
        * Compares normalized ranges:
            s := Self.Normalized
            t := target.Normalized
            Result = (s.start = t.start) AND (s.stop = t.stop)
        * Ensures equivalence even if:
            - bounds are reversed (start > stop)
            - internal representation differs but logical interval matches
    - Normalization guarantees:
        * start ≤ stop
        * consistent canonical form for comparison
    - Complexity:
        * Strict:     O(1)
        * Non-strict: O(1), assuming Normalized is O(1)
    - Use cases:
        * strictly = True:
            When structural identity matters (exact stored values).
        * strictly = False:
            When logical interval equivalence is required.
    - Notes:
        * Non-strict mode is safer for external inputs or mixed range sources.
        * Strict mode avoids overhead when invariants are already enforced.
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
  <Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean; overload;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Differs(const b: TRange): Boolean; overload;
begin
  Result := ((Min(Self.start, Self.stop) <> Min(b.start, b.stop)) or (Max(Self.start, Self.stop) <> Max(b.start, b.stop)));
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
  <Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Equals(const b: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum = b.Minimum) and (Self.Maximum = b.Maximum));
end;

{==============================================================================]
  <Equivalent>
  @action: Determines whether two ranges represent the same interval,
           regardless of boundary ordering.
  @return: True: both ranges have identical bounds (direct or reversed)
           False: ranges differ in at least one boundary
  @note: Order-insensitive comparison; [a..b] is equivalent to [b..a].
         Does not require prior normalization.
[==============================================================================}
function TRange.Equivalent(const b: TRange): Boolean; overload;
begin
  Result := (((Self.start = b.start) and (Self.stop = b.stop)) or ((Self.start = b.stop) and (Self.stop = b.start)));
end;

{==============================================================================]
  <IsAdjacent>
  @action: Determines whether this range is directly adjacent to another range.
  @note: Returns True if the ranges do not overlap but touch at exactly one
         boundary, such that Self.Maximum + 1 = other.Minimum or
         other.Maximum + 1 = Self.Minimum. Adjacent ranges have no shared
         values and a gap size of zero.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.IsAdjacent(const other: TRange): Boolean; overload;
begin
  Result := (((Self.Maximum + 1) = other.Minimum) or ((other.Maximum + 1) = Self.Minimum));
end;

{==============================================================================]
  <IsConnected>
  @action: Determines if Self and the target range share any physical points, 
           including shared boundaries (touching).
           
  @note:   POLARITY AGNOSTIC: 
           Evaluates physical boundaries (Min/Max). Returns True if there is 
           an overlap, containment, or if the ranges are adjacent (e.g., [1..5] 
           and [5..10] are connected at point 5).
           
           LOGIC: 
           Returns True if (Self.Min <= Target.Max) AND (Target.Min <= Self.Max).
           If False, the ranges are "Disjoint" (separated by a gap).
[==============================================================================}
function TRange.IsConnected(const target: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum <= target.Maximum) and (target.Minimum <= Self.Maximum));
end;

{==============================================================================]
  <IsEquivalent>
  @action: Returns True if both ranges occupy the exact same physical span 
           on the number line.        
  @note: This is a spatial check, not a structural one. For example, 
         [1..10] and [10..1] are considered equivalent because they 
         cover the same ground.
         Relies on RelationshipTo(target) returning 3 (Binary 0011), 
         indicating that both the Minimum and Maximum boundaries match.
[==============================================================================}
function TRange.IsEquivalent(const target: TRange): Boolean; overload;
begin
  Result := (Self.RelationshipTo(target) = 3);
end;

{==============================================================================]
  <IsMergeable>
  @action: Determines whether this range can be merged with another range.
  @note: Returns True if the ranges overlap or are directly adjacent.
         Mergeable ranges can be combined into a single contiguous range
         without introducing gaps.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.IsMergeable(const other: TRange): Boolean; overload;
begin
  Result := (Self.Overlaps(other) or Self.IsAdjacent(other));
end;

{==============================================================================]
  <Loose>
  @action: Returns True if this range and the target range are strictly separated,
           i.e., there is a positive gap between them. Equivalent to saying the
           ranges are disjoint with no touching endpoints.
  @note:
    • Uses the Gap method: Result = Self.Gap(target) > 0
[==============================================================================}
function TRange.Loose(const target: TRange): Boolean; overload;
begin
  Result := (Self.Gap(target) > 0);
end;

{==============================================================================]
  <Meet>
  @action: Computes whether two ranges overlap and, if so, returns their intersection.
  @note: Returns True when the normalized ranges share at least one common value (l <= h).
         The resulting range represents the inclusive intersection [max(start), min(stop)].
[==============================================================================}
function TRange.Meet(const other: TRange; out mRange: TRange): Boolean; overload;
var
  s, o: TRange;
  h, l: Integer;
begin
  s := Self.Normalize;
  o := other.Normalize;
  l := Max(s.start, o.start);
  h := Min(s.stop, o.stop);
  Result := (l <= h);
  if Result then
    mRange := TRange.Construct(l, h);
end;

{==============================================================================]
  <Mergeable>
  @action: Determines whether this range is mergeable with another range.
  @note: Returns True if the ranges overlap or are directly adjacent.
         The evaluation is inclusive of a one-unit boundary, meaning that
         ranges with no gap between them can be combined into a single
         contiguous range. This condition is equivalent to testing whether
         the union of the two ranges would form a continuous interval.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Mergeable(const other: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum <= (other.Maximum + 1)) and ((Self.Maximum + 1) >= other.Minimum));
end;

{==============================================================================]
  <Neighbor>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbor(const b: TRange): Boolean; overload;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <Neighbour>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbour(const b: TRange): Boolean; overload;
begin
  Result := (((Max(Self.start, Self.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlap(const b: TRange): Boolean; overload;
begin
  Result := not ((Min(Self.start, Self.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlapping(const b: TRange): Boolean; overload;
begin
  Result := ((Min(Self.start, Self.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Overlaps>
  @action: Determines whether this range overlaps with another range.
  @note: Overlap is evaluated inclusively. If the ranges share at least one
         value, including boundary values, the result is True. For example,
         ranges where Self.Maximum = other.Minimum are considered overlapping.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Overlaps(const other: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum <= other.Maximum) and (Self.Maximum >= other.Minimum));
end;

{==============================================================================]
  <RelationshipTo>
  @action: Generates a 4-bit topological bitmask representing the spatial
           alignment of the 'Self' range relative to a 'Target' range.
  @return: A Byte (0-14) where each bit signifies a specific boundary condition.
  @note:   INTERNAL NORMALIZATION:
           Both ranges are normalized (Start <= Stop) before comparison.
           The result reflects physical coverage, not drawing direction.

           BIT DEFINITIONS:
           - Bit 0 (1): [MATCH]  Self.Start == Target.Start
           - Bit 1 (2): [MATCH]  Self.Stop  == Target.Stop
           - Bit 2 (4): [LOWER]  Self.Start <  Target.Start (Starts earlier)
           - Bit 3 (8): [HIGHER] Self.Stop  >  Target.Stop  (Ends later)

           VALID LOGICAL STATES:
           - [0]  SUBSET:     Self is strictly inside Target.
           - [1]  FLUSH-ST:   Starts together; Self is a prefix of Target.
           - [2]  FLUSH-SP:   Stops together; Self is a suffix of Target.
           - [3]  IDENTICAL:  Exact same footprint (Bits 1+2).
           - [4]  LEFT-LEAN:  Self starts earlier and ends earlier/inside.
           - [8]  RIGHT-LEAN: Self starts later/inside and ends later.
           - [12] ENVELOPING: Self strictly contains Target (Bits 4+8).
           - [13] ENVELOP-ST: Starts together; Self is longer than Target.
           - [14] ENVELOP-SP: Stops together; Self starts earlier than Target.

           IMPOSSIBLE STATES (Exclusive Logic):
           Certain bit combinations are physically excluded because a point
           cannot be simultaneously "Equal" and "Less Than" another point.
           - [5, 7, 15]: Invalid. Bit 0 (Equal) and Bit 2 (Less) are exclusive.
           - [10, 11, 15]: Invalid. Bit 1 (Equal) and Bit 3 (Greater) are exclusive.
           - [9]: Invalid. Requires Start > Target.Start AND Stop > Target.Stop
                  while maintaining Start < Target.Start logic.
[==============================================================================}
function TRange.RelationshipTo(const target: TRange): Byte; overload;
var
  S, T: TRange;
begin
  Result := 0;
  S := Self.Normalize;
  T := target.Normalize;
  if (S.start = T.start) then
    Result := (Result or 1);
  if (S.stop = T.stop) then
    Result := (Result or 2);
  if (S.start < T.start) then
    Result := (Result or 4);
  if (S.stop > T.stop) then
    Result := (Result or 8);
end;

{==============================================================================]
  <RelationTo>
  @action: Compares the physical boundaries of Self against a target range,
           returning a 4-bit topological bitmask (0..14).
  @note:   POLARITY AGNOSTIC:
           Uses .Minimum and .Maximum to evaluate physical occupancy.
           The result is identical regardless of range direction (Asc/Desc).

           BIT DEFINITIONS:
           - Bit 0 (1): [Snap-Start] Low boundaries are equal.
           - Bit 1 (2): [Snap-Stop]  High boundaries are equal.
           - Bit 2 (4): [Precedent]  Self starts before Target.
           - Bit 3 (8): [Subsequent] Self ends after Target.

           VALID STATES & IMPOSSIBILITIES:
           - Result 3:  Identical physical footprint.
           - Result 12: Enveloping (Self strictly contains Target).
           - Result 0:  Subset (Self is strictly inside Target).
           - States [5, 6, 7, 9, 10, 11, 15] are mathematically impossible
             due to boundary exclusivity and internal normalization.
[==============================================================================}
function TRange.RelationTo(const target: TRange): Byte; overload;
begin
  Result := 0;
  if (Self.Minimum = target.Minimum) then
    Result := (Result or 1);
  if (Self.Maximum = target.Maximum) then
    Result := (Result or 2);
  if (Self.Minimum < target.Minimum) then
    Result := (Result or 4);
  if (Self.Maximum > target.Maximum) then
    Result := (Result or 8);
end;

{==============================================================================]
  <Separated>
  @action: Determines whether this range is strictly separated from another range.
  @note: Returns True if there is at least one discrete value between the two
         ranges. Overlapping or directly adjacent ranges are not considered
         separated. In other words, this method evaluates whether the gap
         between the ranges is greater than zero.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Separated(const other: TRange): Boolean; overload;
begin
  Result := ((Self.Maximum < (other.Minimum - 1)) or (other.Maximum < (Self.Minimum - 1)));
end; 

{==============================================================================]
  <Touch>
  @action: Returns true if range touches b.
  @note: Touch = only single value is shared between the ranges.
[==============================================================================}
function TRange.Touch(const b: TRange): Boolean; overload;
var
  l, h, r: TRange;
begin
  l := Self.Normalize;
  h := b.Normalize;
  r.Create(Max(l.start, h.start), Min(l.stop, h.stop));
  Result := r.Singular;
end;

{==============================================================================]
  <Touches>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
var
  x, y: TRange;
  i, s: Integer;
begin
  x := Self.Normalize;
  y := b.Normalize;
  s := 0;
  for i := x.start to x.stop do
    if ((i >= y.start) and (i <= y.stop)) then
      if (s.Increment > maxTouch) then
        Exit(False);
  Result := (s >= minTouch);
end;

{==============================================================================]
  <Touching>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
var
  x, y: TRange;
  s, i: Integer;
begin
  x := Self.Normalize;
  y := b.Normalize;
  s := 0;
  for i := x.start to x.stop do
    if ((i >= y.start) and (i <= y.stop)) then
      if (s.Increment > maxTouch) then
        Exit(False);
  Result := (s >= minTouch);
end;
{$ENDIF}
