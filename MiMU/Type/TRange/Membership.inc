{$IFDEF METHODS}
function Above(const target: Integer): Boolean; overload;
function Above(const target: TRange): Boolean; overload;
function Below(const target: Integer): Boolean; overload;
function Below(const target: TRange): Boolean; overload;
function Contains(const x: Integer): Boolean; overload;
function Contains(const x: TRange): Boolean; overload;
function Covered(const val: Integer): Boolean; overload;
function Covers(const val: Integer): Boolean; overload;
function Digit(const x: Integer): Boolean; overload;
function Employs(const val: Integer): Boolean; overload;
function Got(const val: Integer): Boolean; overload;
function Has(const val: Integer): Boolean; overload;
function Holding(const val: Integer): Boolean; overload;
function Holds(const val: Integer): Boolean; overload;
function Holds(const vals: TRange): Boolean; overload;
function Includes(const val: Integer): Boolean; overload;
function Interior(const val: Integer): Boolean; overload;
function Internal(const val: Integer): Boolean; overload;
function InOpen(const val: Integer): Boolean; overload;
function Inside(const val: Integer): Boolean; overload;
function IsIn(const val: Integer): Boolean; overload;
function IsIncluded(const val: Integer): Boolean; overload;
function IsInside(const val: Integer): Boolean; overload;
function IsMember(const val: Integer): Boolean; overload;
function IsSubsetFor(const target: TRange): Boolean; overload;
function IsSubsetOf(const target: TRange): Boolean; overload;
function Item(const x: Integer): Boolean; overload;
function Keeps(const val: Integer): Boolean; overload;
function Lacks(const x: Integer): Boolean; overload;
function Membership(const val: Integer): Boolean; overload;
function Missing(const val: Integer): Boolean; overload;
function Missing(const vals: TRange): Boolean; overload;
function Number(const val: Integer): Boolean; overload;	
function Omits(const val: Integer): Boolean; overload;
function Outside(const x: Integer): Boolean; overload;
function Owns(const val: Integer): Boolean; overload;
function Subset(const r: TRange): Boolean; overload;
function Value(const x: Integer): Boolean; overload;
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
  <Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
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
  <Covers>
  @action: Determines whether a value val lies within the bounds of the range,
           accounting for reversed start/stop ordering.
  @note: Explicitly branches on range direction before calling InRange,
         avoiding Min/Max calls and making ordering logic explicit.
[==============================================================================}
function TRange.Covers(const val: Integer): Boolean; overload;
begin
  if (Self.start > Self.stop) then
    Exit(InRange(val, Self.stop, Self.start));
  Result := InRange(val, Self.start, Self.stop);
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
  <Employs>
  @action: Checks if the given integer value matches either the start or stop of the range.
  @note: Useful for quickly verifying if a value is an endpoint of the range.
[==============================================================================}
function TRange.Employs(const val: Integer): Boolean; overload;
begin
  Result := ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Got>
  @action: Determines whether a value val lies within the bounds of the range,
           regardless of the ordering of start and stop.
  @note:   Functionally equivalent to Inside, but delegates the comparison
           to the RTL InRange helper after normalizing bounds.
[==============================================================================}
function TRange.Got(const val: Integer): Boolean; overload;
begin
  Result := InRange(val, Min(Self.start, Self.stop), Max(Self.start, Self.stop));
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
  Result := (Abs(val - ((Self.start + Self.stop) / 2)) <= (Abs(Self.stop - Self.start) / 2));
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
  Result := ((val >= Min(Self.start, Self.stop)) and (val <= Max(Self.start, Self.stop)));
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
  Result := (Min(vals.start, vals.stop) >= Min(Self.start, Self.stop)) and (Max(vals.start, vals.stop) <= Max(Self.start, Self.stop));
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
  <InOpen>
  @action: Returns True if the specified value lies strictly within the range
           defined by start and stop (exclusive of both bounds).
  @note: The range is treated as open (start < val < stop).
         Bound order is normalized internally; start may be greater than stop.
[==============================================================================}
function TRange.InOpen(const val: Integer): Boolean; overload;
begin
  Result := ((val > Min(Self.start, Self.stop)) and (val < Max(Self.start, Self.stop)));
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
  n.Create(Min(Self.start, Self.stop), Max(Self.start, Self.stop));
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
  if (Self.start > Self.stop) then
    Exit((val > Self.stop) and (val < Self.start));
  Result := ((val > Self.start) and (val < Self.stop));
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
  Result := ((val >= Min(Self.start, Self.stop)) and (val <= Max(Self.start, Self.stop)));
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
  <IsSubsetFor>
  @action: Determines whether the current range is entirely contained within the target range.
  @note: Explicitly calculates min/max of both ranges and checks that the current range is fully within the target.
         Order-independent; works even if start > stop.
[==============================================================================}
function TRange.IsSubsetFor(const target: TRange): Boolean; overload;
var
  a, b, c, d: Integer;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  c := Min(target.start, target.stop);
  d := Max(target.start, target.stop);
  Result := ((Max(a, c) = a) and (Min(b, d) = b));
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
  <Item>
  @action: Returns true if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Item(const x: Integer): Boolean; overload;
begin
  if (Self.start <= Self.stop) then
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
  Result := (Abs((val * 2) - (Self.start + Self.stop)) <= Abs(Self.stop - Self.start));
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
  Result := ((val < Min(Self.start, Self.stop)) or (val > Max(Self.start, Self.stop)));
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
  Result := ((Max(vals.start, vals.stop) < Min(Self.start, Self.stop)) or (Min(vals.start, vals.stop) > Max(Self.start, Self.stop)));
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
  <Outside>
  @action: Returns true if x-value is outside the range.
  @note: None.
[==============================================================================}
function TRange.Outside(const x: Integer): Boolean; overload;
begin
  Result := not (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
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
  <Value>
  @action: Returns true if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; overload;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;
{$ENDIF}
