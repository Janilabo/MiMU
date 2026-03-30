{$IFDEF METHODS}
function Encapsulate(const val: Integer): TRange; overload;
function Encapsulate(const other: TRange): TRange; overload;
function Enclose(const val: Integer): TRange; overload;
function Enclose(const other: TRange): TRange; overload;
function Intersect(const b: TRange): TRange; overload;
function Intersect(const b: TRange; var iZone: TRange): Boolean; overload;
function Intersection(const target: TRange): TRange; overload;
function Join(const val: Integer): TRange; overload;
function Join(const other: TRange): TRange; overload;
function Joinage(const val: Integer): TRange; overload;
function Joinage(const other: TRange): TRange; overload;
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
  if Self.Ascending then
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
  if Self.Ascending then
    Result := TRange.Construct(Min(Min(other.start, other.stop), Min(Self.start, Self.stop)), Max(Max(other.start, other.stop), Max(Self.start, Self.stop)))
  else
    Result := TRange.Construct(Max(Max(other.start, other.stop), Max(Self.start, Self.stop)), Min(Min(other.start, other.stop), Min(Self.start, Self.stop)));
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
