{$IFDEF METHODS}
function Differ(const b: TRange): Boolean; overload;
function Differs(const b: TRange): Boolean; overload;
function Dist(const target: TRange): Integer; overload;
function Dist: Integer; overload;
function DistAt(const target: TRange): Integer; overload;
function Distance(const b: TRange): Integer; overload;
function Distance: Integer; overload;
function DistanceAt(const target: TRange): Integer; overload;
function DistanceEx(const target: TRange): Integer; overload;
function DistanceFor(const target: TRange): Integer; overload;
function DistanceOf(const target: TRange): Integer; overload;
function DistanceTo(const other: TRange): Integer; overload;
function DistanceWith(const target: TRange): Integer; overload;
function DistHausdorff(const b: TRange): Integer; overload;
function Equal(const b: TRange): Boolean; overload;
function Equals(const b: TRange): Boolean; overload;
function Gap(const other: TRange): Integer; overload;
function GapTo(const other: TRange): Integer; overload;
function GetDistance(const target: TRange): Integer; overload;
function Intersect(const b: TRange): TRange; overload;
function Intersect(const b: TRange; var iZone: TRange): Boolean; overload;
function IsAdjacent(const other: TRange): Boolean; overload;
function IsMergeable(const other: TRange): Boolean; overload;
function Loose(const target: TRange): Boolean; overload;
function Mergeable(const other: TRange): Boolean; overload;
function Neighbor(const b: TRange): Boolean; overload;
function Neighbour(const b: TRange): Boolean; overload;
function Overlap(const b: TRange): Boolean; overload;
function Overlapping(const b: TRange): Boolean; overload;
function Overlaps(const other: TRange): Boolean; overload;
function Separated(const other: TRange): Boolean; overload;
function Separation(other: TRange): Integer; overload;
function Shared(const other: TRange): Integer; overload;
function Space(const target: TRange): Integer; overload;
function Touch(const b: TRange): Boolean; overload;
function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
function Union(const b: TRange): TRange; overload;
function Union(const val: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Dist>
  @action: Returns the non-negative discrete distance between this range and a
           target range.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Uses Minimum/Maximum accessors; start/stop order does not matter.
[==============================================================================}
function TRange.Dist(const target: TRange): Integer; overload;
begin
  Result := Max(0, (Max(Self.Minimum, target.Minimum) - Min(Self.Maximum, target.Maximum)));
end;

{==============================================================================]
  <Dist>
  @action: Returns the distance between the start and stop values of the range.
           Uses a compact conditional expression to handle descending ranges.
  @note: Same as Distance but written using IfThen for brevity. Still exclusive
         of endpoints and sensitive to the Descending flag.
[==============================================================================}
function TRange.Dist: Integer; overload;
begin
  Result := IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start));
end;

{==============================================================================]
  <DistAt>
  @action: Returns the non-negative discrete distance between this range and a
           target range using a center-based arithmetic computation.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized; start/stop order does not matter.
         Fully branchless and symmetric.
[==============================================================================}
function TRange.DistAt(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  Result := Max(0, (Abs((s.start + s.stop) - (t.start + t.stop)) div 2) - (((s.stop - s.start) + (t.stop - t.start)) div 2));
end;

{==============================================================================]
  <Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRange.Distance(const b: TRange): Integer; overload;
var
  r1, r2: TRange;
begin
  r1 := Self.Normalize;
  r2 := b.Normalize;
  if (r1.stop < r2.start) then
    Result := (r2.start - r1.stop)
  else
    if (r2.stop < r1.start) then
      Result := (r1.start - r2.stop)
    else
      Result := 0;
end;

{==============================================================================]
  <Distance>
  @action: Returns the distance between the start and stop values of the range.
           Accounts for the direction of the range (descending or ascending).
  @note: Distance is exclusive of endpoints. Use this if you want the signed
         difference based on the range direction (negative if descending?).
[==============================================================================}
function TRange.Distance: Integer; overload;
begin
  if Self.Descending then
    Result := (Self.start - Self.stop)
  else
    Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <DistanceAt>
  @action: Returns the non-negative distance between this range and a target range.
           Overlapping = 0
		   Touching (adjacent) = 1
		   Otherwise +1 (returns the integer gap between the ranges)
  @note: Ranges are internally normalized, so start/stop order does not matter.
[==============================================================================}
function TRange.DistanceAt(const target: TRange): Integer; overload;
var
  a, g: Integer;
  s, t: TRange;
begin
  a := Abs(Self.start - Self.stop);
  s.Create(((Self.start + Self.stop - a) div 2), ((Self.start + Self.stop + a) div 2));
  a := Abs(target.start - target.stop);
  t.Create(((target.start + target.stop - a) div 2), ((target.start + target.stop + a) div 2));
  g := (Max(s.start, t.start) - Min(s.stop, t.stop));
  Result := ((g + Abs(g)) div 2);
end;

{==============================================================================]
  <DistanceEx>
  @action: Returns the non-negative discrete distance between this range and a
           target range using explicit overlap and ordering checks.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized before comparison; start/stop order
         does not matter.
[==============================================================================}
function TRange.DistanceEx(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if (s.stop >= t.start) then
    if (t.stop >= s.start) then
      Exit(0);
  if (s.stop < t.start) then
    Result := (t.start - s.stop)
  else
    Result := (s.start - t.stop);
end;

{==============================================================================]
  <DistanceFor>
  @action: Returns the non-negative discrete distance between this range and a
           target range.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized before comparison; start/stop order
         does not matter.
[==============================================================================}
function TRange.DistanceFor(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  Result := Max(0, Max(s.start, t.start) - Min(s.stop, t.stop));
end;

{==============================================================================]
  <DistanceOf>
  @action: Returns the non-negative discrete distance between this range and a
           target range using a branchless boolean-masked computation.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized before computation; start/stop order
         does not matter.
[==============================================================================}
function TRange.DistanceOf(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  Result := (((t.start - s.stop) * Ord(s.stop < t.start)) + ((s.start - t.stop) * Ord(t.stop < s.start)));
end;

{==============================================================================]
  <DistanceTo>
  @action: Returns the minimum discrete distance between this range and another
          range.
  @note: The distance is defined as the number of integer steps required to
         move from one range to the other. If the ranges overlap, the result
         is 0. If the ranges are adjacent, the result is 1. For non-overlapping
         ranges, the result is equal to GapTo(other) + 1.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.DistanceTo(const other: TRange): Integer; overload;
begin
  Result := Max(0, (Self.GapTo(other) + 1));
end;

{==============================================================================]
  <DistanceWith>
  @action: Returns the non-negative discrete distance between this range and a
           target range.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized before comparison; start/stop order
         does not matter.
[==============================================================================}
function TRange.DistanceWith(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if (s.stop < t.start) then
    Result := (t.start - s.stop)
  else if (t.stop < s.start) then
    Result := (s.start - t.stop)
  else
    Result := 0;
end;

{==============================================================================]
  <DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRange.DistHausdorff(const b: TRange): Integer; overload;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
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
  Result := ((Min(Self.start, Self.stop) = Min(b.start, b.stop)) and (Max(Self.start, Self.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <Gap>
  @action: Returns the number of discrete values strictly between this range and
          another range.
  @note: If the ranges do not overlap and are not adjacent, the result is the
         exclusive gap size between them. If the ranges overlap or are directly
         adjacent, the result is 0. This method does not distinguish overlap
         from adjacency and always returns a non-negative value.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Gap(const other: TRange): Integer; overload;
begin
  if (Self.Maximum < other.Minimum) then
    Result := ((other.Minimum - Self.Maximum) - 1)
  else if (other.Maximum < Self.Minimum) then
    Result := ((Self.Minimum - other.Maximum) - 1)
  else
    Result := 0;
end;

{==============================================================================]
  <GapTo>
  @action: Returns the number of discrete values between this range and another
          non-overlapping range.
  @note: If the ranges overlap, the function returns -1. If the ranges do not
         overlap, the result represents the exclusive gap between them, i.e.
         the count of integer values that lie strictly between
         Self.Maximum and other.Minimum, or between other.Maximum and
         Self.Minimum, depending on their relative ordering.
         Adjacent ranges (where Self.Maximum + 1 = other.Minimum, or vice
         versa) yield a gap of 0. This method assumes both ranges are valid
         (Minimum <= Maximum).
[==============================================================================}
function TRange.GapTo(const other: TRange): Integer; overload;
begin
  if Self.Overlaps(other) then
    Exit(-1)
  else if (Self.Maximum < other.Minimum) then
    Result := ((other.Minimum - Self.Maximum) - 1)
  else
    Result := ((Self.Minimum - other.Maximum) - 1);
end;

{==============================================================================]
  <GetDistance>
  @action: Returns the non-negative discrete distance between this range and a
           target range using a branchless signed-gap computation.
           Overlapping or endpoint-touching ranges return 0.
           Adjacent ranges return 1.
           Otherwise returns the integer gap between the ranges.
  @note: Both ranges are normalized before computation; start/stop order
         does not matter.
         Uses arithmetic clamping: (g + Abs(g)) div 2.
[==============================================================================}
function TRange.GetDistance(const target: TRange): Integer; overload;
var
  s, t: TRange;
  g: Integer;
begin
  s := Self.Normalize;
  t := target.Normalize;
  g := (Max(s.start, t.start) - Min(s.stop, t.stop));
  Result := ((g + Abs(g)) div 2);
end;

{==============================================================================]
  <Intersect>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRange.Intersect(const b: TRange): TRange; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := b.Normalize;
  Result.start := Max(s.start, t.start);
  Result.stop := Min(s.stop, t.stop);
end;

{==============================================================================]
  <Intersect>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRange.Intersect(const b: TRange; var iZone: TRange): Boolean; overload;
var
  s, t: TRange;
  x, y: Integer;
begin
  s := Self.Normalize;
  t := b.Normalize;
  x := Max(s.start, t.start);
  y := Min(s.stop, t.stop);
  Result := (x <= y);
  if Result then
    iZone.Create(x, y);
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
  <Separation>
  @action: Returns the signed separation between this range and another range.
  @note: For non-overlapping ranges, the result is a positive value equal to
         the number of discrete values strictly between the two ranges.
         For overlapping ranges, the result is negative and represents the
         inclusive size of the overlap (i.e. the negated shared value count).
         Adjacent ranges yield a separation of 0.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Separation(other: TRange): Integer; overload;
begin
  if (Self.Maximum < other.Minimum) then
    Result := ((other.Minimum - Self.Maximum) - 1)
  else if (other.Maximum < Self.Minimum) then
    Result := ((Self.Minimum - other.Maximum) - 1)
  else
    Result := -((Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum)) + 1);
end;

{==============================================================================]
  <Shared>
  @action: Returns the number of discrete values shared by this range and another
          range.
  @note: If the ranges overlap, the result is the inclusive size of their
         intersection, calculated as
         Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum) + 1.
         If the ranges do not overlap, the result is 0.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Shared(const other: TRange): Integer; overload;
begin
  if Self.Overlaps(other) then
    Result := ((Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum)) + 1)
  else
    Result := 0;
end;

{==============================================================================]
  <Space>
  @action: Returns the signed distance between this range and the target range.
    - Positive if the target range lies entirely after this range.  
    - Negative if the target range lies entirely before this range.  
    - Zero if the ranges overlap.
  @note:
    • Uses normalized ranges (Self.Normalize and target.Normalize) so that
      start ≤ stop is guaranteed.  
    • Computation:
        - If Self stops before target starts: Result = target.start - Self.stop
        - If Self starts after target stops: Result = target.stop - Self.start
        - Otherwise (overlap): Result = 0
    • Useful for determining relative position, separation, or collision clearance.
    • Returns negative, zero, or positive values depending on relative ordering.
[==============================================================================}
function TRange.Space(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if (s.stop < t.start) then
    Result := (t.start - s.stop)
  else if (s.start > t.stop) then
    Result := (t.stop - s.start)
  else
    Result := 0;
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

{==============================================================================]
  <Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRange.Union(const b: TRange): TRange; overload;
begin
  Result.start := Min(Min(Self.start, Self.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(Self.start, Self.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <Union>
  @action: Returns union of range and val.
  @note: None.
[==============================================================================}
function TRange.Union(const val: Integer): TRange; overload;
begin
  Result := Self;
  case Self.Descending of
    True:
	if (val > Self.start) then
	  Result.start := val
	else
	  if (val < Self.stop) then
	    Result.stop := val;
    False:
	if (val < Self.start) then
	  Result.start := val
	else
	  if (val > Self.stop) then
	    Result.stop := val;
  end;
end;
{$ENDIF}
