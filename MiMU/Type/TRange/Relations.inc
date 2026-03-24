{$IFDEF METHODS}
function Differ(const b: TRange): Boolean; overload;
function Differs(const b: TRange): Boolean; overload;
function Equal(const b: TRange): Boolean; overload;
function Equals(const b: TRange): Boolean; overload;
function Equivalent(const b: TRange): Boolean; overload;
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
function Touch(const b: TRange): Boolean; overload;
function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; overload;
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
