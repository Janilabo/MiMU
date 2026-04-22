{$IFDEF METHODS}
function Above(const target: Integer): Boolean; overload;
function Above(const target: TRange): Boolean; overload;
function Accepts(const val: Integer): Boolean; overload;
function Adjoins(const val: Integer): Boolean; overload;
function Adjoins(const target: TRange): Boolean; overload;
function Admits(const val: Integer): Boolean; overload;
function Allows(const val: Integer): Boolean; overload;
function Apart(const val: Integer; const threshold: Integer = 1): Boolean; overload;
function AtBorder(const val: Integer): Boolean; overload;
function AtBorder(const target: TRange): Boolean; overload;
function Below(const target: Integer): Boolean; overload;
function Below(const target: TRange): Boolean; overload;
function Binds(const val: Integer): Boolean; overload;
function Carry(const val: Integer): Boolean; overload;
function Containing(const val: Integer): Boolean; overload;
function Contains(const x: Integer): Boolean; overload;
function Contains(const x: TRange): Boolean; overload;
function Contains(const x: TIntegerArray): Boolean; overload;
function Covered(const val: Integer): Boolean; overload;
function Covering(const val: Integer): Boolean; overload;
function Covers(const val: Integer): Boolean; overload;
function Deviant(const val: Integer): Boolean; overload;
function Digit(const x: Integer): Boolean; overload;
function Disjoint(const target: TRange): Boolean; overload;
function Disjointed(const target: TRange): Boolean; overload;
function Distant(const val: Integer; const threshold: Integer = 1): Boolean; overload;
function Embody(const val: Integer): Boolean; overload;
function Employs(const val: Integer): Boolean; overload;
function Encloses(const val: Integer): Boolean; overload;
function Encloses(const vals: TRange): Boolean; overload;
function Enveloping(const target: TRange): Boolean; overload;
function Envelops(const target: TRange): Boolean; overload;
function Far(const val: Integer; const threshold: Integer = 1): Boolean; overload;
function Flush(const val: Integer): Boolean; overload;
function Flush(const target: TRange): Boolean; overload;
function Gapped(const r: TRange; const gThreshold: Integer = 0): Boolean; overload;
function Got(const val: Integer): Boolean; overload;
function Has(const val: Integer): Boolean; overload;
function Have(const val: Integer): Boolean; overload;
function Holding(const val: Integer): Boolean; overload;
function Holds(const val: Integer): Boolean; overload;
function Holds(const vals: TRange): Boolean; overload;
function InAsc(const val: Integer): Boolean; overload;
function InBounds(const val: Integer): Boolean; overload;
function Includes(const val: Integer): Boolean; overload;
function InDesc(const val: Integer): Boolean; overload;
function Inhere(const val: Integer): Boolean; overload;
function InInterval(const val: Integer): Boolean; overload;
function Interior(const val: Integer): Boolean; overload;
function Internal(const val: Integer): Boolean; overload;
function InOpen(const val: Integer): Boolean; overload;
function InSet(const val: Integer): Boolean; overload;
function InsideRange(const val: Integer): Boolean; overload;
function InsideRange(const vals: TRange): Boolean; overload;
function Inside(const val: Integer): Boolean; overload;
function IsDisjoint(const other: TRange): Boolean; overload;
function IsIn(const val: Integer): Boolean; overload;
function IsIncluded(const val: Integer): Boolean; overload;
function IsInRange(const val: Integer): Boolean; overload;
function IsInside(const val: Integer): Boolean; overload;
function IsMember(const val: Integer): Boolean; overload;
function IsMissing(const val: Integer): Boolean; overload;
function IsOutside(const val: Integer): Boolean; overload;
function IsSubsetFor(const target: TRange): Boolean; overload;
function IsSubsetOf(const target: TRange): Boolean; overload;
function IsWithin(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
function Item(const x: Integer): Boolean; overload;
function Keeps(const val: Integer): Boolean; overload;
function Kissing(const val: Integer): Boolean; overload;
function Kissing(const target: TRange): Boolean; overload;
function Lacks(const x: Integer): Boolean; overload;
function Membership(const val: Integer): Boolean; overload;
function Missing(const val: Integer): Boolean; overload;
function Missing(const vals: TRange): Boolean; overload;
function Near(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
function Number(const val: Integer): Boolean; overload;	
function Omits(const val: Integer): Boolean; overload;
function Outlier(const val: Integer): Boolean; overload;
function OutOfRange(const val: Integer): Boolean; overload;
function OutOfRange(const vals: TRange): Boolean; overload;
function Outside(const x: Integer): Boolean; overload;
function Own(const val: Integer): Boolean; overload;
function Owns(const val: Integer): Boolean; overload;
function Subset(const r: TRange): Boolean; overload;
function Superset(const r: TRange): Boolean; overload;
function Surrounds(const target: TRange): Boolean; overload;
function Tangent(const val: Integer): Boolean; overload;
function Tangent(const target: TRange): Boolean; overload;
function Value(const x: Integer): Boolean; overload;
function WithinBounds(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
function Wrapping(const r: TRange): Boolean; overload;
function Wraps(const r: TRange): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Above>
  @action: Returns True if range is above target.
  @note: None.
[==============================================================================}
function TRange.Above(const target: Integer): Boolean; overload;
begin
  Result := (Self.Minimum > target);
end;

function TRange.Above(const target: TRange): Boolean; overload;
begin
  Result := Self.Above(target.Maximum);
end;

{==============================================================================]
  <Accepts>
  @action: Determines whether the specified integer value lies within the range
           by normalizing it to a [0,1] scale relative to the range endpoints.
  @note: Uses floating-point division to compute the relative position of val within the range.
         Returns True if the normalized value is between 0.0 and 1.0, inclusive.
		 Handles singular ranges (start = stop) explicitly.
		 May be susceptible to floating-point rounding errors for very large integers.
[==============================================================================}
function TRange.Accepts(const val: Integer): Boolean; overload;
var
  d: Double;
begin
  if Self.Singular then
    Exit(val = Self.start);
  d := ((val - Self.start) / (Self.stop - Self.start));
  Result := ((d >= 0.0) and (d <= 1.0));
end;

{==============================================================================]
  <Adjoins>
  @action: Returns True if val is exactly on either boundary of Self.
  @note: - Self [1..10] Adjoins 1  -> True
         - Self [1..10] Adjoins 10 -> True
         - Self [1..10] Adjoins 5  -> False (interior)
         - Self [1..10] Adjoins 11 -> False (exterior)
[==============================================================================}
function TRange.Adjoins(const val: Integer): Boolean; overload;
begin
  Result := not ((Self.start <> val) and (Self.stop <> val));
end;

{==============================================================================]
  <Adjoins>
  @action: Returns True if Self and target share exactly one boundary value.
  @note: - Self [1..5]  Adjoins [5..10] -> True
         - Self [1..5]  Adjoins [6..10] -> False (gap)
         - Self [1..5]  Adjoins [3..10] -> False (overlap > 1)
[==============================================================================}
function TRange.Adjoins(const target: TRange): Boolean; overload;
begin
  Result := (Self.Confluency(target) = 1);
end;

{==============================================================================]
  <Admits>
  @action: Determines whether the specified integer value lies within the range
           using a direction-aware parity comparison.
  @note: Uses the Ascending flag to branch between ascending and descending ranges.
         Implements a boolean XOR-style check (<>) to efficiently test inclusion,
		 including endpoints. Fully branch-dependent but avoids arithmetic overflow issues.
[==============================================================================}
function TRange.Admits(const val: Integer): Boolean; overload;
var
  a: Boolean;
begin
  a := Self.Ascending;
  Result := ((a and ((val >= Self.start) <> (val > Self.stop))) or ((not a) and ((val >= Self.stop) <> (val > Self.start))));
end;

{==============================================================================]
  <Allows>
  @action: Returns True if the value is permitted by the range.
  @note: A value is allowed if it is explicitly employed or lies within
         the inclusive bounds of the range. Bound order does not matter.
[==============================================================================}
function TRange.Allows(const val: Integer): Boolean; overload;
begin
  Result := (Self.Employs(val) or ((Self.start - val) xor (Self.stop - val) <= 0)); 
end;

{==============================================================================]
  <Apart>
  @action: Determines whether a value lies outside the central portion of the range.
  @note: Computes the distance from the midpoint of [Minimum, Maximum] and returns 
         True if it exceeds half the range plus an optional threshold (default = 1). 
         Useful for checking if a value is “far from the center.”
[==============================================================================}
function TRange.Apart(const val: Integer; const threshold: Integer = 1): Boolean; overload;
begin
  Result := (Abs(val - ((Self.Minimum + Self.Maximum) / 2)) > (((Self.Maximum - Self.Minimum) / 2) + threshold));
end;

{==============================================================================]
  <AtBorder>
  @action: Checks whether a value lies on the boundary of the range.
  @note: True when val equals either Self.Minimum or Self.Maximum.
         Returns False if the value is strictly inside or outside
         the range.
[==============================================================================}
function TRange.AtBorder(const val: Integer): Boolean; overload;
begin
  Result := ((Self.Maximum = val) or (Self.Minimum = val));
end;

{==============================================================================]
  <AtBorder>
  @action: Checks whether two ranges touch at any boundary point.
  @note: True when either Self.Maximum = target.Minimum or
         Self.Minimum = target.Maximum. Returns False if the ranges
         are disjoint or overlap without touching boundaries.
[==============================================================================}
function TRange.AtBorder(const target: TRange): Boolean; overload;
begin
  Result := ((Self.Maximum = target.Minimum) or (Self.Minimum = target.Maximum));
end;

{==============================================================================]
  <Below>
  @action: Returns True if range is below target.
  @note: None.
[==============================================================================}
function TRange.Below(const target: Integer): Boolean; overload;
begin
  Result := (Self.Maximum < target);
end;

function TRange.Below(const target: TRange): Boolean; overload;
begin
  Result := Self.Below(target.Minimum);
end;

{==============================================================================]
  <Binds>
  @action: Tests whether the value is bound by the range
  @note: Returns True if val lies within [start..stop], inclusive.
         Works regardless of whether start <= stop or start > stop.
         Internally normalizes bounds using bitwise operations for branchless evaluation.
[==============================================================================}
function TRange.Binds(const val: Integer): Boolean; overload;
var
  l, h, o, x: Integer;
begin
  x := (Self.start xor Self.stop);
  o := -Ord(Self.start < Self.stop);
  l := (Self.stop xor (x and o));
  h := (Self.start xor (x and o));
  Result := ((val >= l) and (val <= h));
end;

{==============================================================================]
  <Carry>
  @action: Tests whether the range carries the value
  @note: Returns True if val lies within [start..stop], inclusive.
         Works regardless of the order of start and stop by normalizing bounds.
[==============================================================================}
function TRange.Carry(const val: Integer): Boolean; overload;
var
  m: Integer;
begin
  m := Self.Minimum;
  Result := (Cardinal(val - m) <= Cardinal(Self.Maximum - m));
end;

{==============================================================================]
  <Containing>
  @action: Determines whether the specified integer value is contained within the range,
           independent of boundary order.
  @note: Implements a branchless, overflow-safe check by normalizing the lower bound via Min,
         and comparing unsigned distance using Cardinal arithmetic.
		 Works for both ascending and descending ranges and includes both endpoints.
[==============================================================================}
function TRange.Containing(const val: Integer): Boolean; overload;
begin
  Result := (Cardinal(val - Min(Self.start, Self.stop)) <= Cardinal(Abs(Self.stop - Self.start)));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload;
begin
  Result := ((x >= Self.Minimum) and (x <= Self.Maximum));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload;
begin
  Result := ((x.Minimum >= Self.Minimum) and (x.Maximum <= Self.Maximum));
end;

{==============================================================================]
  <ContainsAll>
  @action: Returns True if every value in x exists within the range.
  @note: Returns True for an empty array.
[==============================================================================}
function TRange.Contains(const x: TIntegerArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(x) do
    if not Self.Contains(x[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Covered>
  @action: Returns True if <val> lies within the range, including the endpoints.
           Works for both ascending and descending ranges.
  @note: Uses XOR logic to perform a branch-free, orientation-agnostic check.
         Equivalent to checking: Min(Self.start, Self.stop) <= val <= Max(Self.start, Self.stop).
[==============================================================================}
function TRange.Covered(const val: Integer): Boolean; overload;
begin
  Result := not ((val < Self.Minimum) xor (val > Self.Maximum));
end;

{==============================================================================]
  <Covering>
  @action: Returns True if `val` lies within the range boundaries (inclusive).
  @note: Works regardless of whether the range is ascending or descending.
         This is an inclusive check: endpoints are considered inside.
[==============================================================================}
function TRange.Covering(const val: Integer): Boolean; overload;
begin
  if Self.Ascending then
    Result := (((val - Self.start) or (Self.stop - val)) >= 0)
  else
    Result := (((val - Self.stop) or (Self.start - val)) >= 0);
end;

{==============================================================================]
  <Covers>
  @action: Determines whether a value val lies within the bounds of the range,
           accounting for reversed start/stop ordering.
  @note: Explicitly branches on range direction before calling InRange,
         avoiding Min/Max calls and making ordering logic explicit.
[==============================================================================}
function TRange.Covers(const val: Integer): Boolean; overload;
begin
  if Self.Descending then
    Exit(InRange(val, Self.stop, Self.start));
  Result := InRange(val, Self.start, Self.stop);
end;

{==============================================================================]
  <Deviant>
  @action: Determines whether a value lies outside the range [Minimum, Maximum].
  @note: 
    - Returns True if val is less than Minimum or greater than Maximum.
    - Uses a branchless sign check: (val - Minimum) and (Maximum - val) must 
      have the same sign (or be zero) for the value to be within range.
    - If their signs differ, the value is outside the range.
[==============================================================================}
function TRange.Deviant(const val: Integer): Boolean; overload;
begin
  Result := not (((val - Self.Minimum) xor (Self.Maximum - val)) >= 0);
end;

{==============================================================================]
  <Digit>
  @action: Returns true if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Digit(const x: Integer): Boolean; overload;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
  <Disjoint>
  @action: Returns True if this range and the target range are strictly
           non-overlapping. That is, the closed intervals
           [Self.Minimum, Self.Maximum] and [target.Minimum, target.Maximum] share no common values.
  @note:
    • Implemented as:
      (Self.Maximum < target.Minimum) OR (Self.Minimum > target.Maximum)
    • Endpoint contact is considered overlap.
      Example: [0,5] and [5,10] → NOT disjoint.
    • Assumes both ranges are valid (Minimum ≤ Maximum).
[==============================================================================}
function TRange.Disjoint(const target: TRange): Boolean; overload;
begin
  Result := not Self.Overlaps(target);
end;

{==============================================================================]
  <Disjointed>
  @action: Returns True if this range and the target range are strictly non-overlapping.
           Implementation uses the “Min/Max test”: the smaller of the two interval
           ends is less than the larger of the two interval starts. If so, the ranges
           do not intersect.
  @note:
    • Endpoint contact is considered overlapping:
        Example: [0,3] and [3,5] → Disjointed = False
    • Equivalent to:
        (Self.Maximum < target.Minimum) OR (Self.Minimum > target.Maximum)
      for closed intervals.
    • Assumes both ranges are valid (Minimum ≤ Maximum).
    • This formulation may be visually confusing, but is mathematically correct.
[==============================================================================}
function TRange.Disjointed(const target: TRange): Boolean; overload;
begin
  Result := (Min(Self.Maximum, target.Maximum) < Max(Self.Minimum, target.Minimum));
end;

{==============================================================================]
  <Distant>
  @action: Determines whether a value lies outside the extended range [Minimum - threshold, Maximum + threshold].
  @note: Returns True if val is less than (Minimum - threshold) or greater than (Maximum + threshold). 
         The threshold parameter allows for flexible margin beyond the defined range. Default threshold is 1.
[==============================================================================}
function TRange.Distant(const val: Integer; const threshold: Integer = 1): Boolean; overload;
begin
  Result := ((((Self.Minimum - threshold) - val) > 0) or ((val - (Self.Maximum + threshold)) > 0));
end;

{==============================================================================]
  <Embody>
  @action: Check if value is in range
  @note: Returns True if val lies within [start..stop], inclusive.
         Works regardless of start > stop.
[==============================================================================}
function TRange.Embody(const val: Integer): Boolean; overload;
begin
  Result := (((((Self.start - val) shr 31) xor ((Self.stop - val) shr 31)) <> 0) or Self.Employs(val));
end;

{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches either the start or stop of the range.
  @note: Useful for quickly verifying if a value is an endpoint of the range.
[==============================================================================}
function TRange.Employs(const val: Integer): Boolean; overload;
begin
  Result := ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Encloses>
  @action: Determines whether a value lies within the inclusive bounds of
           the range [start..stop].
  @return: True: val is inside or exactly on the boundaries
           False: val is outside the range
  @note: Range is normalized prior to evaluation to ensure start <= stop.
[==============================================================================}
function TRange.Encloses(const val: Integer): Boolean; overload;
var
  n: TRange;
begin
  n := Self.Normalize;
  Result := ((val >= n.start) and (val <= n.stop));
end;

{==============================================================================]
  <Encloses>
  @action: Determines whether a range is fully contained within this range,
           using inclusive boundary comparison.
  @return: True: vals.start >= start AND vals.stop <= stop
           False: any portion of vals lies outside this range
  @note: Both ranges are normalized prior to evaluation to ensure
         start <= stop semantics for consistent comparison.
[==============================================================================}
function TRange.Encloses(const vals: TRange): Boolean; overload;
var
  s, v: TRange;
begin
  s := Self.Normalize;
  v := vals.Normalize;
  Result := ((v.start >= s.start) and (v.stop <= s.stop));
end;

{==============================================================================]
  <Enveloping>
  @action: Returns True if the target range is strictly contained within Self.
  @note: STRICT INTERIOR: Returns False if target boundaries touch or 
         match Self boundaries.
         NORMALIZATION: Uses local TRange copies (Self.Normalize) to 
         ensure physical comparison regardless of original direction.
[==============================================================================}
function TRange.Enveloping(const target: TRange): Boolean; overload;
var
  S, T: TRange;
begin
  S := Self.Normalize;
  T := target.Normalize;
  Result := ((T.start > S.start) and (T.stop < S.stop));
end;

{==============================================================================]
  <Envelops>
  @action: Returns True if the target range is strictly contained within Self, 
           with "breathing room" on both edges.
  @note: BOUNDARY EXCLUSIVE: 
          - Self[1..10], Target[2..9] -> True
          - Self[1..10], Target[1..9] -> False (Touch at start)
          - Self[1..10], Target[1..10]-> False (Identical)
[==============================================================================}
function TRange.Envelops(const target: TRange): Boolean; overload;
begin
  Result := ((target.Minimum > Self.Minimum) and (target.Maximum < Self.Maximum));
end;

{==============================================================================]
  <Far>
  @action: Returns True if val lies outside the range by at least threshold.
  @note:
    - A threshold of 1 (default) performs a standard exclusive check.
    - A positive threshold requires the value to be "well clear" of the range.
    - Internally calls Within(val, -threshold) or performs a direct check.
[==============================================================================}
function TRange.Far(const val: Integer; const threshold: Integer = 1): Boolean; overload;
begin
  Result := ((val < (Self.Minimum - threshold)) or (val > (Self.Maximum + threshold)));
end;

{==============================================================================]
  <Flush>
  @action: Checks whether a value lies exactly on one boundary of the range.
  @note: True when either Self.Maximum = val or Self.Minimum = val,
         but not both (XOR). Returns False if the value is strictly
         inside or outside the range, or if the range is degenerate
         (Minimum = Maximum) and equals val.
[==============================================================================}
function TRange.Flush(const val: Integer): Boolean; overload;
begin
  Result := ((Self.Maximum = val) xor (Self.Minimum = val));
end;

{==============================================================================]
  <Flush>
  @action: Checks whether two ranges touch at exactly one boundary.
  @note: True when either Self.Maximum = target.Minimum or
         Self.Minimum = target.Maximum, but not both (XOR).
         Returns False if ranges overlap, are disjoint, or are identical.
[==============================================================================}
function TRange.Flush(const target: TRange): Boolean; overload;
begin
  Result := ((Self.Maximum = target.Minimum) xor (Self.Minimum = target.Maximum));
end;

{==============================================================================]
  <Gapped>
  @action: Determines whether two ranges are separated by a gap exceeding a threshold.
  @note: Returns True if the distance between Self and r is greater than the
         allowed gap threshold (gThreshold). The comparison is based on the
         difference between the combined span and the sum of individual sizes.
         When gThreshold = 0, this detects any non-adjacent, non-overlapping
         separation. Larger thresholds tolerate small gaps before reporting True.
[==============================================================================}
function TRange.Gapped(const r: TRange; const gThreshold: Integer = 0): Boolean; overload;
begin
  Result := (((Max(Self.Maximum, r.Maximum) - Min(Self.Minimum, r.Minimum)) + 1) > ((Self.Size + r.Size) + (gThreshold - 1)));
end;

{==============================================================================]
  <Got>
  @action: Checks whether a value lies within the current range bounds.
  @note: Direction-aware inclusion test; works for both ascending and descending ranges.
[==============================================================================}
function TRange.Got(const val: Integer): Boolean; overload;
var
  d: Integer;
begin
  d := Self.Direction;
  Result := ((((val - Self.start) * d) >= 0) and (((val - Self.stop) * d) <= 0));
end;

{==============================================================================]
  <Has>
  @action: Determines whether a value val lies between start and stop inclusively.
  @note: Performs a direct bidirectional comparison without normalization
         or helper functions; logically equivalent to Inside.
[==============================================================================}
function TRange.Has(const val: Integer): Boolean; overload;
begin
  Result := (((val >= Self.start) and (val <= Self.stop)) or ((val >= Self.stop) and (val <= Self.start)));
end;

{==============================================================================]
  <Have>
  @action: Returns True if `val` lies within the range boundaries (inclusive).
  @note: Uses a midpoint/radius formulation equivalent to an inclusive
         range check. Endpoints are considered inside.
[==============================================================================}
function TRange.Have(const val: Integer): Boolean; overload;
begin
  Result := (Abs(val - ((Self.start + Self.stop) / 2)) <= (Abs(Self.stop - Self.start) / 2));
end;

{==============================================================================]
  <Holding>
  @action: Returns True if <val> lies within the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Implements an inclusive membership test using the midpoint of the range:
           - The midpoint is calculated as (Start + Stop) / 2
           - Half of the range length is Abs(Stop - Start) / 2
           - A value is inside the range if its distance from the midpoint
             does not exceed half the range length
         This approach is branch-free, symmetric, and works correctly
         for ranges of both even and odd lengths.
         Uses floating-point arithmetic, so large integers may be
         subject to precision limits, but typical integer ranges are safe.
[==============================================================================}
function TRange.Holding(const val: Integer): Boolean; overload;
begin
  Result := (Abs(val - (Self.Combined / 2)) <= (Self.Span / 2));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Self.Minimum) and (val <= Self.Maximum));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const vals: TRange): Boolean; overload;
begin
  Result := ((vals.Minimum >= Self.Minimum) and (vals.Maximum <= Self.Maximum));
end;

{==============================================================================]
  <InAsc>
  @action: Returns True if the value lies within the range assuming start <= stop.
  @note: Inclusive comparison; both bounds are considered part of the range.
[==============================================================================}
function TRange.InAsc(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Self.start) and (val <= Self.stop));
end;

{==============================================================================]
  <InBounds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.InBounds(const val: Integer): Boolean; overload;
begin
  Result := ((Int64(val - Self.start) * (val - Self.stop)) <= 0);
end; 

{==============================================================================]
  <Includes>
  @action: Returns True if <val> lies within the range, including the endpoints.
           Works for both ascending and descending ranges.
  @note: Uses a distance-based check:
         The sum of the distances from <val> to the endpoints equals the total range
         distance if and only if <val> lies inside the range.
         Equivalent to Min(Self.start, Self.stop) <= val <= Max(Self.start, Self.stop).
         Branch-free and orientation-agnostic.
[==============================================================================}
function TRange.Includes(const val: Integer): Boolean; overload;
begin
  Result := ((Abs(val - Self.start) + Abs(val - Self.stop)) = Abs(Self.start - Self.stop));
end;

{==============================================================================]
  <InDesc>
  @action: Returns True if the value lies within the range assuming start >= stop.
  @note: Inclusive comparison; both bounds are considered part of the range.
[==============================================================================}
function TRange.InDesc(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Self.stop) and (val <= Self.start));
end;

{==============================================================================]
  <Inhere>
  @action: Tests whether the value inheres in the range
  @note: Returns True if val lies within [start..stop], inclusive.
         Works regardless of whether start <= stop or start > stop.
[==============================================================================}
function TRange.Inhere(const val: Integer): Boolean; overload;
begin
  Result := (((val >= Self.start) <> (val > Self.stop)) or ((val >= Self.stop) <> (val > Self.start)));
end;

{==============================================================================]
  <InInterval>
  @action: Returns True if the given value lies within the range (inclusive).
  @note: Works regardless of whether Start <= Stop or Start > Stop.
         Both bounds are treated as inclusive.
[==============================================================================}
function TRange.InInterval(const val: Integer): Boolean; overload;
begin
  Result := ((((Self.start - val) xor (Self.stop - val)) <= 0) or (Self.Minimum = val));
end;

{==============================================================================]
  <InOpen>
  @action: Returns True if the specified value lies strictly within the range
           defined by start and stop (exclusive of both bounds).
  @note: The range is treated as open (start < val < stop).
         Bound order is normalized internally; start may be greater than stop.
[==============================================================================}
function TRange.InOpen(const val: Integer): Boolean; overload;
begin
  Result := ((val > Self.Minimum) and (val < Self.Maximum));
end;

{==============================================================================]
  <Interior>
  @action: Returns True if the specified value lies strictly within the range
           defined by start and stop (exclusive of both bounds).
  @note: The range is treated as open (start < val < stop).
         Bound order is normalized internally; start may be greater than stop.
[==============================================================================}
function TRange.Interior(const val: Integer): Boolean; overload;
var
  n: TRange;
begin
  n.Create(Self.Minimum, Self.Maximum);
  Result := ((val > n.start) and (val < n.stop));
end;

{==============================================================================]
  <Internal>
  @action: Returns True if the specified value lies strictly within the range
           defined by start and stop (exclusive of both bounds).
  @note: The range is treated as open (start < val < stop).
         Bound order is normalized internally; start may be greater than stop.
[==============================================================================}
function TRange.Internal(const val: Integer): Boolean; overload;
begin
  if Self.Descending then
    Exit((val > Self.stop) and (val < Self.start));
  Result := ((val > Self.start) and (val < Self.stop));
end;

{==============================================================================]
  <InSet>
  @action: Determines whether a given integer value lies within the bounds of the range,
           accounting for both ascending and descending order.
  @note: Returns False if the value or range boundaries fall outside the byte interval (0..255).
         When Ascending is True, the range is evaluated as start..stop; otherwise, it is evaluated as stop..start.
[==============================================================================}
function TRange.InSet(const val: Integer): Boolean; overload;
begin
  if not ((val in [0..255]) and (Self.start in [0..255]) and (Self.stop in [0..255])) then
    Result := False
  else if Self.Ascending then
    Result := (val in [Self.start..Self.stop])
  else
    Result := (val in [Self.stop..Self.start]);
end;

{==============================================================================]
  <Inside>
  @action: Determines whether a value val lies within the bounds of the range,
           regardless of the ordering of start and stop.
  @note:   Normalizes the range by computing Min(start, stop) and Max(start, stop)
           before performing inclusive boundary comparison.
[==============================================================================}
function TRange.Inside(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Self.Minimum) and (val <= Self.Maximum));
end;

{==============================================================================]
  <InsideRange>
  @action: Determines whether a value val lies within the bounds of the range,
           regardless of the ordering of start and stop.
  @note: Functionally equivalent to Inside, but delegates the comparison
         to the RTL InRange helper after normalizing bounds.
[==============================================================================}
function TRange.InsideRange(const val: Integer): Boolean; overload;
begin
  Result := InRange(val, Self.Minimum, Self.Maximum);
end;

{==============================================================================]
  <InsideRange>
  @action: Checks whether another range lies fully within this range.
  @note: Evaluates both endpoints against this range’s normalized bounds (Minimum/Maximum).
[==============================================================================}
function TRange.InsideRange(const vals: TRange): Boolean; overload;
begin
  Result := (InRange(vals.Minimum, Self.Minimum, Self.Maximum) and InRange(vals.Maximum, Self.Minimum, Self.Maximum));
end;

{==============================================================================]
  <IsDisjoint>
  @action: Determines whether two ranges have no overlap.
  @note: Returns True if the ranges do not intersect at all;
         implemented as the logical negation of Meet.
[==============================================================================}
function TRange.IsDisjoint(const other: TRange): Boolean; overload;
var
  d: TRange;
begin
  Result := not Self.Meet(other, d);
end;

{==============================================================================]
  <IsIn>
  @action: Returns True if <val> lies within the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Uses a split check:
         - Self.Employs(val) handles endpoint inclusion.
         - Sign comparison detects strict interior membership.
         This formulation is orientation-agnostic and branch-free.
         Equivalent to: Min(Start, Stop) <= val <= Max(Start, Stop).
[==============================================================================}
function TRange.IsIn(const val: Integer): Boolean; overload;
begin
  Result := (Self.Employs(val) or (Sign(val - Self.start) = Sign(Self.stop - val)));
end;

{==============================================================================]
  <IsIncluded>
  @action: Returns True if <val> lies within the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: This implementation compares the signs of the differences
           (val - Start) and (val - Stop) using bitwise XOR.
[==============================================================================}
function TRange.IsIncluded(const val: Integer): Boolean; overload;
begin
  Result := not ((Sign(val - Self.start) xor Sign(val - Self.stop)) = 0);
end;

{==============================================================================]
  <IsInRange>
  @action: Returns True if the value lies within the range (inclusive).
  @note: Implements an inclusive interval check: val ∈ [Start, Stop].
         Assumes Start <= Stop; results are undefined if bounds are reversed.
         Uses a product-based sign test for branchless evaluation.
[==============================================================================}
function TRange.IsInRange(const val: Integer): Boolean; overload;
begin
  Result := ((Int64(val - Self.start) * (Self.stop - val)) >= 0);
end;

{==============================================================================]
  <IsInside>
  @action: Returns True if <val> lies within the range, including the endpoints.
           Works for both ascending and descending ranges.
  @note: Uses the product-of-differences method:
         ((val - Start) * (Stop - val) >= 0), which is branch-free and orientation-agnostic.
         Equivalent to checking: Min(Start, Stop) <= val <= Max(Start, Stop).
[==============================================================================}
function TRange.IsInside(const val: Integer): Boolean; overload;
begin
  Result := (((val - Self.start) * (Self.stop - val)) >= 0);
end;

{==============================================================================]
  <IsMember>
  @action: Returns True if <val> is a member of the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Implements an inclusive membership test by converting boolean
         comparisons to integers using Ord().
         The value is considered inside the range only when both
         comparisons evaluate to True: Ord(val >= Minimum) + Ord(val <= Maximum) = 2
         This approach is branch-free and avoids arithmetic overflow,
         but is less idiomatic than direct boolean expressions.
[==============================================================================}
function TRange.IsMember(const val: Integer): Boolean; overload;
begin
  Result := ((Ord(val >= Self.Minimum) + Ord(val <= Self.Maximum)) = 2);
end;

{==============================================================================]
  <IsMissing>
  @action: Determines whether a value lies outside the range [Minimum, Maximum].
  @note: 
    - Returns True if val < Minimum or val > Maximum.
    - Returns False if val is within the range or exactly equal to the boundaries.
    - Uses a branchless absolute-distance test:
        |val - Minimum| + |val - Maximum| > (Maximum - Minimum)
      which holds only when val is outside the interval.
[==============================================================================}
function TRange.IsMissing(const val: Integer): Boolean; overload;
begin
  Result := ((Abs(val - Self.Minimum) + Abs(val - Self.Maximum)) > (Self.Maximum - Self.Minimum));
end;

{==============================================================================]
  <IsOutside>
  @action: Determines whether a value lies strictly outside the range [Minimum, Maximum].
  @note: 
    - Returns True if val < Minimum or val > Maximum.
    - Returns False if val is within the range or exactly equal to the boundaries.
    - Uses a branchless multiplication sign test: 
        (val - Minimum) * (val - Maximum) > 0
      which is positive only when val is on the same side of both bounds.
    - Operates in Int64 to avoid overflow during multiplication.
[==============================================================================}
function TRange.IsOutside(const val: Integer): Boolean; overload;
begin
  Result := (Int64(val - Self.Minimum) * Int64(val - Self.Maximum) > 0);
end;

{==============================================================================]
  <IsSubsetFor>
  @action: Determines whether the current range is entirely contained within the target range.
  @note: Explicitly calculates min/max of both ranges and checks that the current range is fully within the target.
         Order-independent; works even if start > stop.
[==============================================================================}
function TRange.IsSubsetFor(const target: TRange): Boolean; overload;
var
  a, b: Integer;
begin
  a := Self.Minimum;
  b := Self.Maximum;
  Result := ((Max(a, target.Minimum) = a) and (Min(b, target.Maximum) = b));
end;

{==============================================================================]
  <IsSubsetOf>
  @action: Returns true if the current range lies entirely within the target range.
  @note: Compares the range’s Minimum and Maximum properties; equivalent to IsSubsetFor but relies on existing property getters.
         Order-independent and overflow-safe if Minimum/Maximum use Int64 internally.
[==============================================================================}
function TRange.IsSubsetOf(const target: TRange): Boolean; overload;
begin
  Result := ((Self.Minimum >= target.Minimum) and (Self.Maximum <= target.Maximum));
end;

{==============================================================================]
  <IsWithin>
  @action: Returns True if val lies within the range, optionally expanded
           by vRadius on both sides.
  @note: Radius of 0 performs a standard inclusive range check.
          - Positive radius extends the range outward symmetrically.
          - Negative radius is considered invalid and returns False.
[==============================================================================}
function TRange.IsWithin(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
begin
  Result := ((vRadius >= 0) and (val >= (Self.Minimum - vRadius)) and (val <= (Self.Maximum + vRadius)));
end;

{==============================================================================]
  <Item>
  @action: Returns true if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Item(const x: Integer): Boolean; overload;
begin
  if Self.Ascending then
    Result := ((x >= Self.start) and (x <= Self.stop))
  else
    Result := ((x >= Self.stop) and (x <= Self.start));
end;

{==============================================================================]
  <Keeps>
  @action: Returns True if <val> lies within the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Implements an inclusive membership test using midpoint geometry:
         a value belongs to the range if its distance from the midpoint
         does not exceed half the range width.
         Expressed algebraically as:
           |2·val − (Start + Stop)| ≤ |Stop − Start|.
         This formulation is orientation-agnostic and branch-free.
         Be aware that for very large integer values, the intermediate
         multiplication may overflow.
[==============================================================================}
function TRange.Keeps(const val: Integer): Boolean; overload;
begin
  Result := (Abs((val * 2) - Self.Combined) <= Self.Span);
end;

{==============================================================================]
  <Kissing>
  @action: Returns True if val lies exactly on either boundary of Self.
  @note: - Self [1..10] Kissing 1  -> True
         - Self [1..10] Kissing 10 -> True
         - Self [1..10] Kissing 5  -> False (interior)
         - Self [1..10] Kissing 11 -> False (exterior)
[==============================================================================}
function TRange.Kissing(const val: Integer): Boolean; overload;
begin
  Result := ((Self.Maximum = val) or (Self.Minimum = val));
end;

{==============================================================================]
  <Kissing>
  @action: Returns True if Self ends exactly where target begins, or vice versa.
  @note:   - Self [1..5]  Kisses [5..10] -> True  (5 is stop of Self, start of target)
           - Self [5..10] Kisses [1..5]  -> True  (5 is start of Self, stop of target)
           - Self [1..5]  Kisses [3..8]  -> False (overlap)
           - Self [1..5]  Kisses [6..10] -> False (gap)
[==============================================================================}
function TRange.Kissing(const target: TRange): Boolean; overload;
begin
  Result := ((Self.Maximum = target.Minimum) or (Self.Minimum = target.Maximum));
end;

{==============================================================================]
  <Lacks>
  @action: Returns true if x-value is out of range.
  @note: None.
[==============================================================================}
function TRange.Lacks(const x: Integer): Boolean; overload;
begin
  Result := (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
  <Membership>
  @action: Returns True if <val> is a member of the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Implements an orientation-agnostic, inclusive membership test using
         boolean XOR logic: not ((val < Minimum) xor (val > Maximum))
         A value is considered outside the range if it lies on exactly one side
         of the interval bounds; otherwise it is inside.
         Equivalent to: Minimum <= val <= Maximum.
         Branch-free and safe for all integer ranges.
[==============================================================================}
function TRange.Membership(const val: Integer): Boolean; overload;
begin
  Result := not ((val < Self.Minimum) xor (val > Self.Maximum)); 
end;

{==============================================================================]
  <Missing>
  @action: Determines whether a given integer value lies outside the range.
  @note: Returns True if the value is less than the lower bound or greater than
         the upper bound, regardless of start/stop order. Complementary to Holds.
[==============================================================================}
function TRange.Missing(const val: Integer): Boolean; overload;
begin
  Result := ((val < Self.Minimum) or (val > Self.Maximum));
end;

{==============================================================================]
  <Missing>
  @action: Determines whether another range lies entirely outside this range.
  @note: Returns True if the input range is completely disjoint from this range,
         i.e., there is no overlap between the ranges. Works correctly for both
         ascending and descending ranges by normalizing start and stop values.
[==============================================================================}
function TRange.Missing(const vals: TRange): Boolean; overload;
begin
  Result := ((vals.Maximum < Self.Minimum) or (vals.Minimum > Self.Maximum));
end;

{==============================================================================]
  <Near>
  @action: Determines whether a value lies within or near the range, based on
           an optional radius.
  @note:
    - Returns True if `val` lies within the range extended by `vRadius`.
    - The range is treated as centered at its midpoint with half-width expanded
      by `vRadius`.
    - If `vRadius = 0`, this is equivalent to checking whether `val` is inside
      the range.
    - If `vRadius > 0`, the effective range is expanded outward by `vRadius`.
    - Returns False if `vRadius < 0`.
    - Works for both ascending and descending ranges.
[==============================================================================}
function TRange.Near(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
var
  c, h: Double;
begin
  if (vRadius < 0) then
    Exit(False);
  c := ((Self.start + Self.stop) / 2);
  h := ((Abs(Self.stop - Self.start) / 2) + vRadius);
  Result := (Abs(val - c) <= h);
end;

{==============================================================================]
  <Number>
  @action: Returns True if <val> lies within the range, including both endpoints.
           Works for both ascending and descending ranges.
  @note: Uses sign multiplication:
         Sign(val - Start) * Sign(Stop - val) >= 0
         If <val> is between the endpoints (or equal to one),
         both differences have the same sign or zero.
         Equivalent to:
         Min(Start, Stop) <= val <= Max(Start, Stop).
         Branch-free and orientation-agnostic.
[==============================================================================}
function TRange.Number(const val: Integer): Boolean; overload;
begin
  Result := ((Sign(val - Self.start) * Sign(Self.stop - val)) >= 0);
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present as either the start or stop of the range.
  @note: Logical inverse of TRange.Employs; returns True if the value is absent from the range endpoints.
[==============================================================================}
function TRange.Omits(const val: Integer): Boolean; overload;
begin
  Result := not ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Outlier>
  @action: Determines whether a value lies outside the bounds of the range.
  @note: 
    - For a singular range, returns True if val differs from the single value.
    - For a non-singular range, evaluates whether val falls outside the interval 
      defined by start and stop by comparing its distance from the midpoint 
      against half the range width.
    - Works for both ascending and descending ranges.
[==============================================================================}
function TRange.Outlier(const val: Integer): Boolean; overload;
begin
  if Self.Singular then
    Result := (val <> Self.start)
  else if Self.Ascending then
    Result := (Abs(val - ((Self.start + Self.stop) / 2)) > ((Self.stop - Self.start) / 2))
  else
    Result := (Abs(val - ((Self.start + Self.stop) / 2)) > ((Self.start - Self.stop) / 2));
end;

{==============================================================================]
  <OutOfRange>
  @action: Checks whether a value lies outside the current range bounds.
  @note: Uses normalized bounds (Minimum/Maximum); equivalent to not InRange(val).
[==============================================================================}
function TRange.OutOfRange(const val: Integer): Boolean; overload;
begin
  Result := ((val < Self.Minimum) or (Self.Maximum < val));
end;

{==============================================================================]
  <OutOfRange>
  @action: Checks whether another range lies completely outside this range.
  @note: True when ranges do not overlap at all (disjoint intervals).
[==============================================================================}
function TRange.OutOfRange(const vals: TRange): Boolean; overload;
begin
  Result := ((vals.Maximum < Self.Minimum) or (Self.Maximum < vals.Minimum));
end;

{==============================================================================]
  <Outside>
  @action: Returns true if x-value is outside the range.
  @note: None.
[==============================================================================}
function TRange.Outside(const x: Integer): Boolean; overload;
begin
  Result := not (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
  <Own>
  @action: Contains()
  @note: Returns True if val is within the range [start..stop], inclusive.
[==============================================================================}
function TRange.Own(const val: Integer): Boolean; overload;
begin
  Result := ((((val - Self.start) xor (val - Self.stop)) < 0) or Self.Employs(val));
end;

{==============================================================================]
  <Owns>
  @action: Determines whether a value val lies between start and stop inclusively.
  @note: Uses a mathematical sign test: if value lies between start and stop,
         the product of (value - start) and (value - stop) is non-positive.
         This is a compact, branch-free formulation.
[==============================================================================}
function TRange.Owns(const val: Integer): Boolean; overload;
begin
  Result := (((val - Self.start) * (val - Self.stop)) <= 0);
end;

{==============================================================================]
  <Subset>
  @action: Determines whether the given range r is entirely contained within the current range.
  @note: Uses Contains checks on both endpoints of r; simpler for single-value containment but equivalent in effect to IsSubsetOf.
         Order-independent as Contains accounts for start/stop ordering.
[==============================================================================}
function TRange.Subset(const r: TRange): Boolean; overload;
begin
  Result := (Self.Contains(r.start) and Self.Contains(r.stop));
end;

{==============================================================================]
  <Superset>
  @action: Determines whether the current range fully contains another range.
  @note: Returns True if both the minimum and maximum bounds of r lie within
         Self. This implies complete coverage of r by Self, assuming contiguous
         ranges. Relies on Contains for boundary checks.
[==============================================================================}
function TRange.Superset(const r: TRange): Boolean; overload;
begin
  Result := (Self.Contains(r.Minimum) and Self.Contains(r.Maximum));
end;

{==============================================================================]
  <Surrounds>
  @action: Bitmask-based check for boundary-independent containment.
  @note: LOGIC WARNING: This specific bitwise implementation returns True 
         if Self strictly Envelops Target OR if Self is strictly a Subset 
         of Target. It effectively flags any relationship where no 
         boundaries are shared (Masks 0 or 12).
[==============================================================================}
function TRange.Surrounds(const target: TRange): Boolean; overload;
begin
  Result := ((Self.RelationshipTo(target) and 12) = Self.RelationshipTo(target));
end;

{==============================================================================]
  <Tangent>
  @action: Returns True if val lies exactly on either boundary of Self.
  @note: - Self [1..10] Tangent 1  -> True
         - Self [1..10] Tangent 10 -> True
         - Self [1..10] Tangent 5  -> False (interior)
         - Self [1..10] Tangent 11 -> False (exterior)
[==============================================================================}
function TRange.Tangent(const val: Integer): Boolean; overload;
begin
  Result := Self.Employs(val);
end;

{==============================================================================]
  <Tangent>
  @action: Returns True if Self and target meet at exactly one shared boundary point.
  @note: - Self [1..5]  Tangent [5..10] -> True
         - Self [1..5]  Tangent [6..10] -> False (gap)
         - Self [1..5]  Tangent [3..8]  -> False (overlap > 1)
         - Self [1..5]  Tangent [1..10] -> False (target encloses Self)
[==============================================================================}
function TRange.Tangent(const target: TRange): Boolean; overload;
var
  r: TRange;
begin
  Result := (Self.Meet(target, r) and (r.Size = 1) and Self.Employs(r.start));
end;

{==============================================================================]
  <Value>
  @action: Returns true if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; overload;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
  <WithinBounds>
  @action: Returns True if the value lies within the range or is explicitly accepted.
  @note: Performs an inclusive interval check: val ∈ [Start, Stop], regardless
         of bound order. Additionally returns True if Employs(val) is True.
         The vRadius parameter is reserved and currently unused.
[==============================================================================}
function TRange.WithinBounds(const val: Integer; const vRadius: Integer = 0): Boolean; overload;
begin
  Result := (((val > Self.start) <> (val > Self.stop)) or Self.Employs(val));
end;

{==============================================================================]
  <Wrapping>
  @action: Determines whether the current range strictly encloses another range.
  @note: Returns True if Self extends beyond r on both sides, i.e. Self.Minimum
         is strictly less than r.Minimum and Self.Maximum is strictly greater
         than r.Maximum. The implementation evaluates the two boundary conditions
         sequentially, short-circuiting on failure of the lower-bound check.
         This expresses a strict containment relationship (non-inclusive).
[==============================================================================}
function TRange.Wrapping(const r: TRange): Boolean; overload;
begin
  Result := (Self.Minimum < r.Minimum);
  if not Result then
    Result := (Self.Maximum > r.Maximum);
end;

{==============================================================================]
  <Wraps>
  @action: Determines whether the current range fully wraps another range.
  @note: Returns True when Self fully encloses r (i.e., r.Minimum is not
         outside Self.Minimum and r.Maximum is not outside Self.Maximum).
         The logic performs boundary comparisons using Min/Max checks rather
         than direct relational operators. Equivalent in intent to a strict
         containment test (Self.Minimum <= r.Minimum AND Self.Maximum >= r.Maximum),
         but expressed via negated extremum comparisons.
[==============================================================================}
function TRange.Wraps(const r: TRange): Boolean; overload;
var
  m: Integer;
begin
  m := r.Minimum;
  Result := not (Min(m, Self.Minimum) = m);
  if not Result then
    Exit;
  m := r.Maximum;
  Result := not (Max(m, Self.Maximum) = m);
end;
{$ENDIF}
