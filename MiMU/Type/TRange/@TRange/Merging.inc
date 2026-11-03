{$IFDEF METHODS}
function Encapsulate(const val: Integer): TRange; overload;
function Encapsulate(const other: TRange): TRange; overload;
function Enclose(const val: Integer): TRange; overload;
function Enclose(const other: TRange): TRange; overload;
function Hull(const target: TRange): TRange; overload;
function Intersect(const b: TRange): TRange; overload;
function Intersect(const b: TRange; var iZone: TRange): Boolean; overload;
function Intersection(const target: TRange): TRange; overload;
function IntersectionStart(const target: TRange): Integer; overload;
function IntersectionStop(const target: TRange): Integer; overload;
function Intersectry(const target: TRange; out aIntersection: TRange): Boolean; overload;
function Join(const val: Integer): TRange; overload;
function Join(const other: TRange): TRange; overload;
function Joinage(const val: Integer): TRange; overload;
function Joinage(const other: TRange): TRange; overload;
function Overlay(const target: TRange): TRange; overload;
function Superimposed(const target: TRange; out aIntersection: TRange): Boolean; overload;
function Union(const b: TRange): TRange; overload;
function Union(const val: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Encapsulate>
  @action: Expands the range to include the specified value.
  @note: Returns a new range whose bounds are adjusted so that val lies within it;
         the start becomes Min(Minimum, val) and the stop becomes Max(Maximum, val).
[==============================================================================}
function TRange.Encapsulate(const val: Integer): TRange; overload;
begin
  Result.start := Min(Self.Minimum, val);
  Result.stop := Max(Self.Maximum, val);
end;

{==============================================================================]
  <Encapsulate>
  @action: Expands the range to include another range.
  @note: Returns the minimal bounding range that contains both ranges;
         uses Minimum/Maximum to ensure correctness regardless of endpoint ordering.
[==============================================================================}
function TRange.Encapsulate(const other: TRange): TRange; overload;
begin
  Result.start := Min(Self.Minimum, other.Minimum);
  Result.stop := Max(Self.Maximum, other.Maximum);
end;

{==============================================================================]
  <Enclose>
  @action: Expands the range to include the specified value.
  @note: Result is the minimal enclosing range of Self and val.
         Preserves the original direction of Self (ascending/descending).
[==============================================================================}
function TRange.Enclose(const val: Integer): TRange; overload;
var
  l, h, m, d: Integer;
begin
  l := Min(val, Min(Self.start, Self.stop));
  h := Max(val, Max(Self.start, Self.stop));
  m := IfThen((Self.start <= Self.stop), 0, -1);
  d := (l xor h);
  Result.start := (l xor (m and d));
  Result.stop := (h xor (m and d));
end;

{==============================================================================]
  <Enclose>
  @action: Expands the range to include another range.
  @note: Result is the minimal enclosing range of Self and other.
         Input ranges are normalized before evaluation.
         Preserves the original direction of Self.
[==============================================================================}
function TRange.Enclose(const other: TRange): TRange; overload;
var
  l, h, m, d: Integer;
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  l := Min(s.start, o.start);
  h := Max(s.stop, o.stop);
  m := IfThen((Self.start <= Self.stop), 0, -1);
  d := (l xor h);
  Result.start := (l xor (m and d));
  Result.stop := (h xor (m and d));
end;

{==============================================================================]
  <Hull>
  @action: Computes the minimal enclosing range of two ranges.
  @note: Returns the convex hull (bounding interval) that fully contains both
         Self and target. The resulting range spans from the minimum of both
         lower bounds to the maximum of both upper bounds. This operation
         merges two ranges into a single continuous covering interval without
         regard to gaps or overlap.
[==============================================================================}
function TRange.Hull(const target: TRange): TRange; overload;
begin
  Result := TRange.Construct(Min(Self.Minimum, target.Minimum), Max(Self.Maximum, target.Maximum));
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
  <Intersection>
  @action: Returns the common overlapping area between two ranges.
  @note: If IsConnected is False, returns TRange.Null.
[==============================================================================}
function TRange.Intersection(const target: TRange): TRange; overload;
begin
  if not Self.IsConnected(target) then 
    Exit(TRange.Null);
  Result.Create(Max(Self.Minimum, target.Minimum), Min(Self.Maximum, target.Maximum));
end;

{==============================================================================]
  <IntersectionStart>
  @action: Calculates and returns the starting boundary of the intersection between the current range and the target range.
  @note: If the ranges do not intersect, the returned value will be greater than IntersectionStop, resulting in an inverted/invalid range.
[==============================================================================}
function TRange.IntersectionStart(const target: TRange): Integer; overload;
begin
  Result := Max(Min(Self.start, Self.stop), Min(target.start, target.stop));
end;

{==============================================================================]
  <IntersectionStop>
  @action: Calculates and returns the ending boundary of the intersection between the current range and the target range.
  @note: If the ranges do not intersect, the returned value will be less than IntersectionStart, resulting in an inverted/invalid range.
[==============================================================================}
function TRange.IntersectionStop(const target: TRange): Integer; overload;
begin
  Result := Min(Max(Self.start, Self.stop), Max(target.start, target.stop));
end;

{==============================================================================]
  <Intersectry>
  @action: Attempts to compute the intersection between the current range and the target range,
           returning the result via the out parameter. Returns True if a valid intersection exists, or False otherwise.
  @note: If the ranges do not intersect, the function returns False and sets aIntersection to TRange.Null.
[==============================================================================}
function TRange.Intersectry(const target: TRange; out aIntersection: TRange): Boolean; overload;
begin
  aIntersection.start := Self.IntersectionStart(target);
  aIntersection.stop := Self.IntersectionStop(target);
  Result := (aIntersection.start <= aIntersection.stop);
  if not Result then
    aIntersection := TRange.Null;
end;

{==============================================================================]
  <Join>
  @action: Expands the range to encompass a specific value.
  @return: A new TRange spanning from the lowest to highest point between 
           'val' and 'Self'.
  @note: Preserves the original orientation (Ascending/Descending) of 'Self'.
[==============================================================================}
function TRange.Join(const val: Integer): TRange; overload;
begin
  Result.Create(Min(val, Self.Minimum), Max(val, Self.Maximum));
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Join>
  @action: Calculates the Union of two ranges.
  @return: A new TRange that covers the total extent of both input ranges.
  @note: 
    - Normalizes both inputs internally to find the absolute min/max.
    - Preserves the original orientation (Ascending/Descending) of 'Self'.
[==============================================================================}
function TRange.Join(const other: TRange): TRange; overload;
var
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  Result.Create(Min(s.start, o.start), Max(s.stop, o.stop));
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Joinage>
  @action: Calculates the Union of two ranges.
  @return: A new TRange that covers the total extent of both input ranges.
  @note: 
    - Normalizes both inputs internally to find the absolute min/max.
    - Preserves the original orientation (Ascending/Descending) of 'Self'.
[==============================================================================}
function TRange.Joinage(const val: Integer): TRange; overload;
begin
  if Self.Asceal then
    Result := TRange.Construct(Min(val, Min(Self.start, Self.stop)), Max(val, Max(Self.start, Self.stop)))
  else
    Result := TRange.Construct(Max(val, Max(Self.start, Self.stop)), Min(val, Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <Joinage>
  @action: Calculates the Union of two ranges.
  @return: A new TRange that covers the total extent of both input ranges.
  @note: 
    - Normalizes both inputs internally to find the absolute min/max.
    - Preserves the original orientation (Ascending/Descending) of 'Self'.
[==============================================================================}
function TRange.Joinage(const other: TRange): TRange; overload;
begin
  if Self.Asceal then
    Result := TRange.Construct(Min(Min(other.start, other.stop), Min(Self.start, Self.stop)), Max(Max(other.start, other.stop), Max(Self.start, Self.stop)))
  else
    Result := TRange.Construct(Max(Max(other.start, other.stop), Max(Self.start, Self.stop)), Min(Min(other.start, other.stop), Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <Overlay>
  @action: Returns the physical segment where this range and the target coincide.
  @note: 
    - Returns the intersection as a new TRange.
    - If there is no overlap (Aparted or Abuts), returns TRange.Null.
[==============================================================================}
function TRange.Overlay(const target: TRange): TRange; overload;
begin
  if (Self.Intersecta(target) <= 0) then
    Result := TRange.Null
  else
    Result := TRange.Construct(Max(Self.Minimum, target.Minimum), Min(Self.Maximum, target.Maximum));
end;

{==============================================================================]
  <Superimposed>
  @action: Determines whether the range overlaps with a target range,
           returning the overlapping intersection adjusted to match the directional orientation of the calling range.
  @note: Automatically normalizes both ranges to compute the intersection safely,
         regardless of whether they are ascending or descending.
         Returns True and populates 'aIntersection' if an overlap exists; otherwise, returns False.
[==============================================================================}
function TRange.Superimposed(const target: TRange; out aIntersection: TRange): Boolean; overload;
var
  s, t, r: TRange;
begin
  s := Self.Normalized;
  t := target.Normalized;
  r.start := Max(s.start, t.start);
  r.stop := Min(s.stop, t.stop);
  Result := (r.start <= r.stop);
  if Result then
    if (Self.start <= Self.stop) then
      aIntersection := r
    else
      aIntersection := r.Reversed;
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
	else if (val < Self.stop) then
	  Result.stop := val;
    False:
	if (val < Self.start) then
	  Result.start := val
	else if (val > Self.stop) then
	  Result.stop := val;
  end;
end;
{$ENDIF}
