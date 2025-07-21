{==============================================================================]
  <TRange.Neutral>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Neutral: Boolean; cdecl;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <TRange.Ascend>
  @action: Returns asscending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Ascend: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <TRange.Descend>
  @action: Returns descending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Descend: TRange; cdecl;
begin
  Result.start := Max(Self.stop, Self.start);
  Result.stop := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Ascending>
  @action: Returns true if range start is lower than stop
  @note: None.
[==============================================================================}
function TRange.Ascending: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Descending>
  @action: Returns true if range start is higher than stop
  @note: None.
[==============================================================================}
function TRange.Descending: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Different logic compared to TRange.Ascending!
[==============================================================================}
function TRange.Increasing: Boolean; cdecl;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean; cdecl;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
constructor TRange.Create(const rStart, rStop: Integer); overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
end;

{==============================================================================]
  <TRange.Create>
  @action: Create a TRange with value
  @note: None.
[==============================================================================}
constructor TRange.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <TRange.Construct>
  @action: Constructs TRange with rStart and rStop.
  @note: None.
[==============================================================================}
class function TRange.Construct(const rStart, rStop: Integer): TRange; overload; cdecl;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <TRange.Build>
  @action: Create a TRange with rStart and rStop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange.Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; cdecl;
begin
  Self.start := Min(rStart, rStop);
  Self.stop := Max(rStop, rStart);
  Result := (Abs(rStop - rStart) + 1);
end;

{==============================================================================]
  <TRange.Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange.Grab: TRange; cdecl;
begin
  if (Self.start > Self.stop) then
    Result.Create(Self.stop, Self.start)
  else
    Result := Self;
end;

{==============================================================================]
  <TRange.Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size: Integer; cdecl;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <TRange.Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Length: Integer; cdecl;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <TRange.Lowest>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Lowest: Integer; cdecl;
begin
  Result := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Minimum: Integer; cdecl;
begin
  if (Self.stop > Self.start) then
    Result := Self.start
  else
    Result := Self.stop;
end;

{==============================================================================]
  <TRange.Highest>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Highest: Integer; cdecl;
begin
  Result := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <TRange.Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Maximum: Integer; cdecl;
begin
  if (Self.start < Self.stop) then
    Result := Self.stop
  else
    Result := Self.start;
end;

{==============================================================================]
  <TRange.Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Digits: TIntegerArray; cdecl;
var
  i, s: Integer;
begin
  s := Sign(Self.stop - Self.start);
  SetLength(Result, (Abs(Self.stop - Self.start) + 1));
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <TRange.Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Ints: TIntegerArray; cdecl;
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
  <TRange.Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Values: TIntegerArray; cdecl;
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
  <TRange.TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.TIA: TIntegerArray; cdecl;
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
  <TRange.Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlapping(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlap(const b: TRange): Boolean; cdecl;
begin
  Result := not ((Min(Self.start, Self.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Intersect>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRange.Intersect(const b: TRange): TRange; overload; cdecl;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := b.Normalize;
  Result.start := Max(s.start, t.start);
  Result.stop := Min(s.stop, t.stop);
end;

{==============================================================================]
  <TRange.Intersect>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRange.Intersect(const b: TRange; var iZone: TRange): Boolean; overload; cdecl;
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
  <TRange.Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRange.Union(const b: TRange): TRange; cdecl;
begin
  Result.start := Min(Min(Self.start, Self.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(Self.start, Self.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <TRange.Shift>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange.Shift(const delta: Integer): TRange; cdecl;
begin
  Result.Create((Self.start + delta), (Self.stop + delta));
end;

{==============================================================================]
  <TRange.Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload; cdecl;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <TRange.Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload; cdecl;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange.Reversed: TRange; cdecl;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;

{==============================================================================]
  <TRange.Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean; cdecl;
begin
  Result := (Self.start <> Self.stop);
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Equals(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) = Min(b.start, b.stop)) and (Max(Self.start, Self.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange.Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Differs(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) <> Min(b.start, b.stop)) or (Max(Self.start, Self.stop) <> Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange.Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Equal(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <TRange.Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <TRange.Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRange.Clamp(const zone: TRange): TRange; cdecl;
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
  <TRange.ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRange.ClampMax(const maxValue: Integer): TRange; cdecl;
begin
  if (Self.start > maxValue) then
    Result.start := maxValue
  else
    Result.start := Self.start;
  if (Self.stop > maxValue) then
    Result.stop := maxValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRange.ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRange.ClampMin(const minValue: Integer): TRange; cdecl;
begin
  if (Self.start < minValue) then
    Result.start := minValue
  else
    Result.start := Self.start;
  if (Self.stop < minValue) then
    Result.stop := minValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRange.Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.Restrict(const zone: TRange): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.Clamp(zone);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMin(const minValue: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMin(minValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMax(const maxValue: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMax(maxValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRange.Clip(const zone: TRange): TRange; cdecl;
begin
  Result.start := Max(zone.start, Min(Self.start, zone.stop));
  Result.stop := Min(zone.stop, Max(Self.stop, zone.start));
end;

{==============================================================================]
  <TRange.ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRange.ClipMin(const minValue: Integer): TRange; cdecl;
begin
  Result.start := Max(Self.start, minValue);
  Result.stop := Max(Self.stop, minValue);
end;

{==============================================================================]
  <TRange.ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRange.ClipMax(const maxValue: Integer): TRange; cdecl;
begin
  Result.start := Min(Self.start, maxValue);
  Result.stop := Min(Self.stop, maxValue);
end;

{==============================================================================]
  <TRangeHelper.Create>
  @action: TRange 0..0.
  @note: None.
[==============================================================================}
function TRangeHelper.Create: TRange; cdecl;
begin
  Self.start := 0;
  Self.stop := 0;
  Result := Self;
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
  <TRange.Touch>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Touch(const b: TRange): Boolean; cdecl;
begin
  Result := (((Max(Self.start, Self.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Touches>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Touches(const b: TRange): Boolean; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <TRange.Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRange.Distance(const b: TRange): Integer; cdecl;
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
  <TRange.DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRange.DistHausdorff(const b: TRange): Integer; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
end;

{==============================================================================]
 <TRange.Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Digit(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;


{==============================================================================]
 <TRange.Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; cdecl; inline;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <TRange.Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Middle: Double; cdecl;
var
  s: Integer;
begin
  s := (Self.Highest + Self.Lowest);
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
 <TRange.Center>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Center: Integer; cdecl;
begin
  Result := ((Self.Highest + Self.Lowest) div 2);
end;

{==============================================================================]
 <TRange.Str>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRange.Str: string; cdecl;
begin
  Result := ('[' + IntToStr(Self.start) + '..' + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
  <_TRange.Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TRange.Create(const rStart, rStop: Integer): TRange; overload; cdecl;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <_TRange.Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TRange.Create(const value: Integer = 0): TRange; overload; cdecl;
begin
  Result := _TRange.Create(value, value);
end;
