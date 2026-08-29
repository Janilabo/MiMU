{$IFDEF TYPES}
generic TInterval<T> = record
  lower, upper: T;
  class operator =(const a, b: TInterval): Boolean; overload;
  class operator <>(const a, b: TInterval): Boolean; overload;
  constructor Create(const a, b: T);
  function Adjoins(const other: TInterval): Boolean; overload;
  function Clamp(const item: T): T; overload;
  function Contains(const item: T): Boolean; overload;
  function Contains(const other: TInterval): Boolean; overload;
  function Extend(const other: TInterval): TInterval; overload;
  function Extend(const item: T): TInterval; overload;
  function Intersect(const other: TInterval): TInterval; overload;
  function Overlaps(const other: TInterval): Boolean; overload;
  function Plural: Boolean; overload;
  function Precedes(const other: TInterval): Boolean; overload;
  function Singular: Boolean; overload;
  function Succeeds(const other: TInterval): Boolean; overload;
end;
{$ENDIF}

{$IFDEF FUNCTIONS}
generic function Interval<T>(const a, b: T): specialize TInterval<T>; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class operator TInterval.=(const a, b: TInterval): Boolean; overload;
begin
  Result := ((a.lower = b.lower) and (a.upper = b.upper));
end;

class operator TInterval.<>(const a, b: TInterval): Boolean; overload;
begin
  Result := not (a = b);
end;

{==============================================================================]
  <Create>
  @action: Constructs a TInterval from two values in either order, normalizing them so `lower` always holds the smaller and `upper` always holds the larger.
  @note: Enforces the interval invariant (lower <= upper) unconditionally — there is no way to construct an out-of-order TInterval, so no caller-side validation is needed downstream.
[==============================================================================}
constructor TInterval.Create(const a, b: T);
begin
  if (a <= b) then
  begin
    Self.lower := a;
    Self.upper := b;
  end else
  begin
    Self.lower := b;
    Self.upper := a;
  end;
end;

{==============================================================================]
  <Adjoins>
  @action: Checks whether this interval touches another at exactly one boundary point, with no interior overlap.
  @note: True when Self.upper = other.lower or Self.lower = other.upper. Distinct from Overlaps, which already counts boundary-touching as True — Adjoins isolates that specific edge case from genuine interior overlap.
[==============================================================================}
function TInterval.Adjoins(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.upper = other.lower) or (Self.lower = other.upper));
end;

{==============================================================================]
  <Clamp>
  @action: Constrains a item to fall within [lower, upper], leaving it unchanged if already inside.
  @note: Ordered-only tier — uses comparison alone, no arithmetic, so it works for any T including Char.
[==============================================================================}
function TInterval.Clamp(const item: T): T; overload;
begin
  if (item < Self.lower) then
    Result := Self.lower
  else if (item > Self.upper) then
    Result := Self.upper
  else
    Result := item;
end;

{==============================================================================]
  <Contains>
  @action: Checks whether a value lies within the interval, inclusive of both endpoints.
  @note: Bounds are inclusive on both ends (`>= lower` and `<= upper`); since `TInterval`'s invariant guarantees `lower <= upper`.
[==============================================================================}
function TInterval.Contains(const item: T): Boolean; overload;
begin
  Result := ((item >= Self.lower) and (item <= Self.upper));
end;

{==============================================================================]
  <Contains>
  @action: Checks if the current interval completely encompasses the specified 'other' interval.
  @note: Returns True only if 'other' starts on or after Self.lower AND ends on or before Self.upper.
[==============================================================================}
function TInterval.Contains(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.lower <= other.lower) and (Self.upper >= other.upper));
end;

{==============================================================================]
  <Extend>
  @action: Returns the smallest TInterval that fully encloses both this interval and another.
  @note: This is a bounding operation, not a set union — if the two intervals don't overlap,
         the result still spans the gap between them (e.g. [1,3] and [8,10] consolidate to [1,10],
		 not two separate pieces). Relies on TInterval's invariant holding for both operands.
[==============================================================================}
function TInterval.Extend(const other: TInterval): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower <= other.lower) then
    l := Self.lower
  else
    l := other.lower;
  if (Self.upper >= other.upper) then
    u := Self.upper
  else
    u := other.upper;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Extend>
  @action: Returns a new TInterval, grown just enough to include a item or another interval that may fall outside the current bounds.
  @note: If the argument is already fully within [lower, upper], the result is identical to the original.
         Only ever widens, never shrinks — ordered-only tier, works for any T.
[==============================================================================}
function TInterval.Extend(const item: T): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower <= item) then
    l := Self.lower
  else
    l := item;
  if (Self.upper >= item) then
    u := Self.upper
  else
    u := item;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Intersect>
  @action: Returns the interval representing the overlapping region between this interval and another.
  @note: Only meaningful when Overlaps(other) is True — callers should check Overlaps first. If the intervals do not overlap, the result violates TInterval's invariant (lower > upper) and should not be used.
[==============================================================================}
function TInterval.Intersect(const other: TInterval): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower >= other.lower) then
    l := Self.lower
  else
    l := other.lower;
  if (Self.upper <= other.upper) then
    u := Self.upper
  else
    u := other.upper;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Overlaps>
  @action: Checks whether this interval shares any values with another interval.
  @note: Standard closed-interval overlap test: two intervals overlap iff each one's lower bound is not past the other's upper bound.
         Relies on TInterval's invariant (lower <= upper) holding for both operands.
[==============================================================================}
function TInterval.Overlaps(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.lower <= other.upper) and (other.lower <= Self.upper));
end;

{==============================================================================]
  <Plural>
  @action: Checks whether the interval spans more than a single point (lower differs from upper).
  @note: The logical complement of Singular — every valid TInterval is either Singular (a single point) or Plural (a proper span), never both.
[==============================================================================}
function TInterval.Plural: Boolean; overload;
begin
  Result := (Self.lower < Self.upper);
end;

{==============================================================================]
  <Precedes>
  @action: Checks whether this interval lies entirely before another, with no overlap.
  @note: Strict — if the intervals merely touch at a boundary (Self.upper = other.lower), this returns False, since that boundary point is shared. Complements Overlaps: for any two intervals, exactly one of Overlaps, Precedes, or other.Precedes(Self) holds.
[==============================================================================}
function TInterval.Precedes(const other: TInterval): Boolean; overload;
begin
  Result := (Self.upper < other.lower);
end;

{==============================================================================]
  <Singular>
  @action: Checks whether the interval collapses to a single point (lower equals upper).
  @note: A valid, non-empty edge case under the invariant — Create(5, 5) is legal and produces a degenerate interval.
[==============================================================================}
function TInterval.Singular: Boolean; overload;
begin
  Result := (Self.lower = Self.upper);
end;

{==============================================================================]
  <Succeeds>
  @action: Checks whether this interval lies entirely after another, with no overlap.
  @note: Strict — if the intervals merely touch at a boundary (Self.lower = other.upper), this returns False, since that boundary point is shared. Mirror of Precedes: Self.Succeeds(other) is equivalent to other.Precedes(Self).
[==============================================================================}
function TInterval.Succeeds(const other: TInterval): Boolean; overload;
begin
  Result := (Self.lower > other.upper);
end;

{==============================================================================]
  <Interval>
  @action: Constructs a TInterval<T> from two values in either order, without requiring the caller to write out the full `specialize TInterval<T>.Create(...)` syntax.
  @note: A thin convenience wrapper — normalization (lower <= upper) is entirely handled by TInterval.Create itself.
         T is inferred from the argument types at the call site in most cases, so callers can typically write Interval(1, 10) rather than specialize Interval<Integer>(1, 10).
		 Requires T to support <=, same ordered-only constraint as TInterval itself.
[==============================================================================}
generic function Interval<T>(const a, b: T): specialize TInterval<T>; overload;
begin
  Result := specialize TInterval<T>.Create(a, b);
end;
{$ENDIF}