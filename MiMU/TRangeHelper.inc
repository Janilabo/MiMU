{==============================================================================]
  <TRangeHelper.Neutral>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRangeHelper.Neutral: Boolean; cdecl;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Ascending>
  @action: Returns true if range start is lower than stop
  @note: None.
[==============================================================================}
function TRangeHelper.Ascending: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Descending>
  @action: Returns true if range start is higher than stop
  @note: None.
[==============================================================================}
function TRangeHelper.Descending: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
function TRangeHelper.Create(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
begin
  Self.start := start;
  Self.stop := stop;
  Result := Self;
end;

{==============================================================================]
  <TRangeHelper.Build>
  @action: Create a TRange with start and stop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRangeHelper.Build(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
begin
  Self.start := Min(start, stop);
  Self.stop := Max(stop, start);
  Result := Self;
end;

{==============================================================================]
  <TRangeHelper.Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRangeHelper.Grab: TRange; cdecl;
begin
  if (Self.start > Self.stop) then
    Result.Create(Self.stop, Self.start)
  else
    Result := Self;
end;

{==============================================================================]
  <TRangeHelper.Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Size: Integer; cdecl;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <TRangeHelper.Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Length: Integer; cdecl;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <TRangeHelper.Lowest>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Lowest: Integer; cdecl;
begin
  Result := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Minimum: Integer; cdecl;
begin
  if (Self.stop > Self.start) then
    Result := Self.start
  else
    Result := Self.stop;
end;

{==============================================================================]
  <TRangeHelper.Highest>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Highest: Integer; cdecl;
begin
  Result := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <TRangeHelper.Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Maximum: Integer; cdecl;
begin
  if (Self.start < Self.stop) then
    Result := Self.stop
  else
    Result := Self.start;
end;

{==============================================================================]
  <TRangeHelper.Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Digits: TIntegerArray; cdecl;
var
  i, s: Integer;
begin
  s := Sign(Self.stop - Self.start);
  SetLength(Result, (Abs(Self.stop - Self.start) + 1));
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <TRangeHelper.Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Ints: TIntegerArray; cdecl;
var
  i, l: Integer;
begin
  l := (Abs(Self.stop - Self.start) + 1);
  SetLength(Result, l);
  case (Self.start > Self.stop) of
    True:
    for i := 0 to High(Result) do
      Result[(l - i) - 1] := (i + Self.stop);
    False:
    for i := 0 to High(Result) do
      Result[i] := (i + Self.start);
  end;
end;

{==============================================================================]
  <TRangeHelper.Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.Values: TIntegerArray; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  SetLength(Result, Self.Size);
  case Self.Ascending of
    False:
    for i := Self.start downto Self.stop do
      Result[r.Increase] := i;
    True:
    for i := Self.start to Self.stop do
      Result[r.Increase] := i;
  end;
end;

{==============================================================================]
  <TRangeHelper.TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRangeHelper.TIA: TIntegerArray; cdecl;
var
  i, l, d: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (Self.start <> Self.stop) then
  begin
    d := Sign(Self.stop - Self.start);
    for i := 0 to ((l - 1) div 2) do
    begin
      Result[i] := (Self.start + (i * d));
      Result[(l - 1) - i] := (Self.stop - (i * d));
    end;
  end else
    Result[0] := Self.start;
end;

{==============================================================================]
  <TRangeHelper.Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRangeHelper.Normalize: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRangeHelper.Overlapping(const b: TRange): Boolean; cdecl;
begin
  Result := (Min(Self.start, Self.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(Self.start, Self.stop));
end;

{==============================================================================]
  <TRangeHelper.Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRangeHelper.Overlap(const b: TRange): Boolean; cdecl;
begin
  Result := not (Min(Self.start, Self.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(Self.start, Self.stop));
end;

{==============================================================================]
  <TRangeHelper.Intersection>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRangeHelper.Intersection(const b: TRange; const null: TRange): TRange; cdecl;
var
  s, t: TRange;
  x, y: Integer;
begin
  s := Self.Normalize;
  t := b.Normalize;
  x := Max(s.start, t.start);
  y := Min(s.stop, t.stop);
  if (x <= y) then
    Result.Create(x, y)
  else
    Result := null;
end;

{==============================================================================]
  <TRangeHelper.Intersect>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRangeHelper.Intersect(const b: TRange; var intersection: TRange): Boolean; cdecl;
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
    intersection.Create(x, y);
end;

{==============================================================================]
  <TRangeHelper.Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRangeHelper.Union(const b: TRange): TRange; cdecl;
begin
  Result.start := Min(Min(Self.start, Self.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(Self.start, Self.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <TRangeHelper.Shift>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRangeHelper.Shift(const delta: Integer): TRange; cdecl;
begin
  Result.Create((Self.start + delta), (Self.stop + delta));
end;

{==============================================================================]
  <TRangeHelper.Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRangeHelper.Contains(const x: Integer): Boolean; overload; cdecl;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <TRangeHelper.Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRangeHelper.Contains(const x: TRange): Boolean; overload; cdecl;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRangeHelper.Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRangeHelper.Reversed: TRange; cdecl;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;

{==============================================================================]
  <TRangeHelper.Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRangeHelper.Reverse: Boolean; cdecl;
begin
  Result := (Self.start <> Self.stop);
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <TRangeHelper.Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRangeHelper.Equals(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) = Min(b.start, b.stop)) and (Max(Self.start, Self.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRangeHelper.Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRangeHelper.Differs(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) <> Min(b.start, b.stop)) or (Max(Self.start, Self.stop) <> Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRangeHelper.Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRangeHelper.Equal(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <TRangeHelper.Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRangeHelper.Differ(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <TRangeHelper.Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRangeHelper.Clamp(const zone: TRange): TRange; cdecl;
var
  z: TRange;
begin
  Result := Self.Normalize;
  z := zone.Normalize;
  if (Result.start < z.start) then
    Result.start := z.start
  else
    if (Result.start > z.stop) then
      Result.start := z.stop;
  if (Result.stop > z.stop) then
    Result.stop := z.stop
  else
    if (Result.stop < z.start) then
      Result.stop := z.start;
  if (Self.start > Self.stop) then
    Result.Reverse;
end;

{==============================================================================]
  <TRangeHelper.ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRangeHelper.ClampMax(const maximum: Integer): TRange; cdecl;
begin
  if (Self.start > maximum) then
    Result.start := maximum
  else
    Result.start := Self.start;
  if (Self.stop > maximum) then
    Result.stop := maximum
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRangeHelper.ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRangeHelper.ClampMin(const minimum: Integer): TRange; cdecl;
begin
  if (Self.start < minimum) then
    Result.start := minimum
  else
    Result.start := Self.start;
  if (Self.stop < minimum) then
    Result.stop := minimum
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRangeHelper.Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRangeHelper.Restrict(const zone: TRange): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.Clamp(zone);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRangeHelper.RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRangeHelper.RestrictMin(const minimum: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMin(minimum);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRangeHelper.RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRangeHelper.RestrictMax(const maximum: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMax(maximum);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRangeHelper.Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRangeHelper.Clip(const zone: TRange): TRange; cdecl;
begin
  Result.start := Max(zone.start, Min(Self.start, zone.stop));
  Result.stop := Min(zone.stop, Max(Self.stop, zone.start));
end;

{==============================================================================]
  <TRangeHelper.ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRangeHelper.ClipMin(const minimum: Integer): TRange; cdecl;
begin
  Result.start := Max(Self.start, minimum);
  Result.stop := Max(Self.stop, minimum);
end;

{==============================================================================]
  <TRangeHelper.ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRangeHelper.ClipMax(const maximum: Integer): TRange; cdecl;
begin
  Result.start := Min(Self.start, maximum);
  Result.stop := Min(Self.stop, maximum);
end;

{==============================================================================]
  <TRangeHelper.Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Distribute(const parts: Integer): TRangeArray; cdecl;
var
  i, s, e, a, b, p: Integer;
  r: TRange;
begin
  if (parts > 0) then
  begin
    r := Self.Normalize;
    s := r.Size;
    p := Min(s, parts);
    e := (s mod p);
    a := r.start;
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      b := (a + ((s div p) - 1));
      if (i < e) then
        Inc(b);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRangeHelper.Partition>
  @action: Partitions range to TRangeArray by size of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Partition(const size: Integer): TRangeArray; cdecl;
var
  a, b, l: Integer;
  r: TRange;
begin
  l := 0;
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, r.Size);
    a := r.start;
    while (a <= r.stop) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[l.Increase].Create(b, a)
      else
        Result[l.Increase].Create(a, b);
      a := (b + 1);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TRangeHelper.Divide>
  @action: Partitions range to TRangeArray by size of parts
  @note: Alternative for TRange_Partition.
[==============================================================================}
function TRangeHelper.Divide(const size: Integer): TRangeArray; cdecl;
var
  a, b, i: Integer;
  r: TRange;
begin
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, (((r.Size + size) - 1) div size));
    a := r.start;
    for i := 0 to High(Result) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRangeHelper.Touch>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRangeHelper.Touch(const b: TRange): Boolean; cdecl;
begin
  Result := (((Max(Self.start, Self.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRangeHelper.Touches>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRangeHelper.Touches(const b: TRange): Boolean; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <TRangeHelper.Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRangeHelper.Distance(const b: TRange): Integer; cdecl;
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
  <TRangeHelper.DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRangeHelper.DistHausdorff(const b: TRange): Integer; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
end;

{==============================================================================]
 <TRange_Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRangeHelper.Digit(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;


{==============================================================================]
 <TRangeHelper.Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRangeHelper.Value(const x: Integer): Boolean; cdecl; inline;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <TRangeHelper.Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRangeHelper.Middle: Double; cdecl;
var
  s: Integer;
begin
  s := (Self.Highest + Self.Lowest);
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
 <TRangeHelper.Center>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRangeHelper.Center: Integer; cdecl;
begin
  Result := ((Self.Highest + Self.Lowest) div 2);
end;

{==============================================================================]
 <TRange_Str>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRangeHelper.Str: string; cdecl;
begin
  Result := ('[' + IntToStr(Self.start) + '..' + IntToStr(Self.stop) + ']');
end;
