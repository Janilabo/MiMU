{$IFDEF METHODS}
function Commonality(const target: TRange): Integer; overload;
function Commonality(const target: Integer): Integer; overload;
function Displacement(const val: Integer): Integer; overload;
function Dist(const target: TRange): Integer; overload;
function Dist: Integer; overload;
function DistAt(const target: TRange): Integer; overload;
function Distance(const b: TRange): Integer; overload;
function Distance: Integer; overload;
function Distance2(const target: TRange): Integer; overload;
function DistanceAt(const target: TRange): Integer; overload;
function DistanceEx(const target: TRange): Integer; overload;
function DistanceFor(const target: TRange): Integer; overload;
function DistanceOf(const target: TRange): Integer; overload;
function DistanceTo(const other: TRange): Integer; overload;
function DistanceWith(const target: TRange): Integer; overload;
function DistHausdorff(const b: TRange): Integer; overload;
function Gap(const other: TRange): Integer; overload;
function Gapping(const target: TRange): Integer; overload;
function GapTo(const other: TRange): Integer; overload;
function GetDistance(const target: TRange): Integer; overload;
function Intersecta(const target: TRange): Integer; overload;
function Intersecta(const target: Integer): Integer; overload;
function Margin(const val: Integer): Integer; overload;
function Proximity(const val: Integer): Integer; overload;
function Relationality(const target: TRange): Integer; overload;
function Relationality(const target: Integer): Integer; overload;
function Score(const target: TRange): Integer; overload;
function Score(const target: Integer): Integer; overload;
function Scored(const target: TRange): Integer; overload;
function Scored(const target: Integer): Integer; overload;
function Separation(const other: TRange): Integer; overload;
function Separaty(const r: TRange): Integer; overload;
function Space(const target: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Commonality>
  @action: Quantifies the intersection or gap between two ranges.
  @return:
    - Positive: Number of integers shared (Overlap).
    - Zero: Ranges are adjacent/touching.
    - Negative: Number of integers in the gap (Separation).
[==============================================================================}
function TRange.Commonality(const target: TRange): Integer; overload;
var
  a, b, c, d: Integer;
begin
  a := Self.Minimum;
  b := Self.Maximum;
  c := target.Minimum;
  d := target.Maximum;
  if (b < c) then
    Result := -((c - b) - 1)
  else if (d < a) then
    Result := -((a - d) - 1)
  else
    Result := ((Min(b, d) - Max(a, c)) + 1);
end;

function TRange.Commonality(const target: Integer): Integer; overload;
var
  a, b: Integer;
begin
  a := Self.Minimum;
  b := Self.Maximum;
  if (target < a) then
    Result := -((a - target) - 1)
  else if (target > b) then
    Result := -((target - b) - 1)
  else
    Result := 1;
end;

{==============================================================================]
  <Displacement>
  @action: Calculates the signed distance from a value to the nearest boundary
           of the range. Sign indicates direction relative to the range.
  @note: 0: val is inside [start..stop]
         <0: val is left of range  (distance from start)
         >0: val is right of range (distance from stop)
[==============================================================================}
function TRange.Displacement(const val: Integer): Integer; overload;
var
  n: TRange;
begin
  n := Self.Normalize;
  if ((val >= n.start) and (val <= n.stop)) then
    Result := 0
  else if (val < n.start) then
    Result := (val - n.start)
  else
    Result := (val - n.stop);
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
  else if (r2.stop < r1.start) then
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
  <Distance2>
  @action: Computes the minimum distance between two ranges.
  @note:
    - Both ranges are normalized before comparison (start <= stop).
    - Returns 0 if the ranges overlap or touch.
    - Otherwise returns the gap between the closest endpoints.
    - Result is always non-negative.
    - Works symmetrically regardless of input order.
    Cases:
      * Overlapping or adjacent:
          [a..b] vs [c..d] where a <= d and c <= b  -> 0
      * Self before target:
          b < c  ->  c - b
      * Self after target:
          a > d  ->  a - d
[==============================================================================}
function TRange.Distance2(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if ((s.start <= t.stop) and (t.start <= s.stop)) then
    Result := 0
  else if (s.stop < t.start) then
    Result := (t.start - s.stop)
  else
    Result := (s.start - t.stop);
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
  if ((s.stop >= t.start) and (t.stop >= s.start)) then
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
  <Gapping>
  @action: Quantifies the empty space (the void) between two ranges.
  @note: 
    - If separated: Returns the positive count of integers in the gap.
    - If touching or overlapping: Returns 0 (there is no gap).
[==============================================================================}
function TRange.Gapping(const target: TRange): Integer; overload;
var
  s: Integer;
begin
  s := Self.Intersecta(target);
  if (s < 0) then
    Result := Abs(s)
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
  <Intersecta>
  @action: Measures the linear depth of intersection or the void of separation.
  @note: 
    Returns a signed integer where:
    - Positive: The shared integer count (The overlap).
    - Zero: The ranges are adjacent (The touch point).
    - Negative: The number of integers between ranges (The gap).
[==============================================================================}
function TRange.Intersecta(const target: TRange): Integer; overload;
var
  g, o: Integer;
begin
  g := Max((target.Minimum - Self.Maximum), (Self.Minimum - target.Maximum));
  o := ((Min(Self.Maximum, target.Maximum) - Max(Self.Minimum, target.Minimum)) + 1);
  if (g > 0) then
    Result := -(g - 1)
  else
    Result := o;
end;

{==============================================================================]
  <Intersecta>
  @action: Projects a point onto the range to determine its inclusive depth.
  @note: Treats the target integer as a singular range [target..target].
[==============================================================================}
function TRange.Intersecta(const target: Integer): Integer; overload;
begin
  Result := Self.Intersecta(TRange.Construct(target, target));
end;

{==============================================================================]
  <Margin>
  @action: Calculates the strict gap between a value and the nearest boundary
           of the range (excludes adjacency). Distinguishes inside, adjacent,
           and outside positions.
  @note: -1: val is inside [start..stop]
         0: val is exactly adjacent (start-1 or stop+1)
         >0: number of integers strictly between val and nearest boundary
[==============================================================================}
function TRange.Margin(const val: Integer): Integer; overload;
var
  n: TRange;
begin
  n := Self.Normalize;
  if ((val >= n.start) and (val <= n.stop)) then
    Result := -1
  else if (val = (n.start - 1)) or (val = (n.stop + 1)) then
    Result := 0
  else if (val < n.start) then
    Result := ((n.start - val) - 1)
  else
    Result := ((val - n.stop) - 1);
end;

{==============================================================================]
  <Proximity>
  @action: Calculates the absolute distance from a value to the nearest boundary
           of the range. Treats inside as zero and adjacency as distance one.
  @note: 0: val is inside [start..stop]
         1: val is adjacent (start-1 or stop+1)
         >1: absolute distance to nearest boundary
[==============================================================================}
function TRange.Proximity(const val: Integer): Integer; overload;
var
  n: TRange;
begin
  n := Self.Normalize;
  if ((val >= n.start) and (val <= n.stop)) then
    Result := 0
  else if (val = (n.start - 1)) or (val = (n.stop + 1)) then
    Result := 1
  else if (val < n.start) then
    Result := (n.start - val)
  else
    Result := (val - n.stop);
end;

{==============================================================================]
  <Relationality>
  @action: Quantifies the spatial bond between two ranges.
  @return:
    - Negative: Overlap count (Interference).
    - Zero: Adjacency (The "Touching" point).
    - Positive: Gap size (Separation).
[==============================================================================}
function TRange.Relationality(const target: TRange): Integer; overload;
begin
  Result := -Self.Commonality(target);
end;

function TRange.Relationality(const target: Integer): Integer; overload;
begin
  Result := -Self.Commonality(target);
end;

{==============================================================================]
  <Score>
  @action: Returns a signed integer representing the connection quality.
  @return: 
    - Positive: Overlap count (higher is deeper).
    - Zero: Touching (adjacent).
    - Negative: Gap size (separation distance).
[==============================================================================}
function TRange.Score(const target: TRange): Integer; overload;
var
  a, b, c, d: Integer;
begin
  a := Self.Minimum;
  b := Self.Maximum;
  c := target.Minimum;
  d := target.Maximum;
  Result := Max((c - b), (a - d));
  if (Result <= 0) then
    Result := ((Min(b, d) - Max(a, c)) + 1)
  else
    Result := -(Result - 1);
end;

{==============================================================================]
  <Score> (Range vs Point)
  @action: Ranks the proximity of a single point to this range.
  @note:
    - 1: The point is inside the range.
    - 0: The point is adjacent to the range (distance of 1).
    - Negative: The gap between the point and the range.
[==============================================================================}
function TRange.Score(const target: Integer): Integer; overload;
begin
  Result := Max(0, Max((Self.Minimum - target), (target - Self.Maximum)));
  if (Result = 0) then
    Result := 1
  else
    Result := (-Result + 1);
end;

{==============================================================================]
  <Scored>
  @action: Distills the spatial relationship into a single qualitative value.
  @note: 
    - Positive: The number of shared integers (Depth of connection).
    - Zero: Perfectly adjacent/touching (The point of contact).
    - Negative: The number of missing integers (The distance to bridge).
[==============================================================================}
function TRange.Scored(const target: TRange): Integer; overload;
begin
  if Self.Intersects(target) then
    Result := Self.Sharedness(target)
  else if Self.Adjacency(target) then
    Result := 0
  else
    Result := -Self.Gapping(target);
end;

{==============================================================================]
  <Scored>
  @action: Ranks how deeply a point is integrated into (or separated from) the range.
  @note: None.
[==============================================================================}
function TRange.Scored(const target: Integer): Integer; overload;
begin
  Result := Self.Scored(TRange.Construct(target, target));
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
function TRange.Separation(const other: TRange): Integer; overload;
begin
  if (Self.Maximum < other.Minimum) then
    Result := ((other.Minimum - Self.Maximum) - 1)
  else if (other.Maximum < Self.Minimum) then
    Result := ((Self.Minimum - other.Maximum) - 1)
  else
    Result := -((Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum)) + 1);
end;

{==============================================================================]
  <Separaty>
  @action: Computes signed separation between two ranges.
  @note: Returns the number of elements between Self and r:
         > 0 → gap size
         = 0 → contiguous (touching)
         < 0 → overlap size (negative; magnitude = overlap length)
         Works with any ordering via normalized bounds.
[==============================================================================}
function TRange.Separaty(const r: TRange): Integer; overload;
begin
  Result := (Max(Self.Minimum, r.Minimum) - Min(Self.Maximum, r.Maximum) - 1);
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
{$ENDIF}
