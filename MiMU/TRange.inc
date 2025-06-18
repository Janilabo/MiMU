{==============================================================================]
  <TRange_Neutral>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange_Neutral(const range: TRange): Boolean; cdecl;
begin
  Result := (range.start = range.stop);
end;

{==============================================================================]
  <TRange_Ascending>
  @action: Returns true if range start is lower than stop
  @note: None.
[==============================================================================}
function TRange_Ascending(const range: TRange): Boolean; cdecl;
begin
  Result := (range.start < range.stop);
end;

{==============================================================================]
  <TRange_Descending>
  @action: Returns true if range start is higher than stop
  @note: None.
[==============================================================================}
function TRange_Descending(const range: TRange): Boolean; cdecl;
begin
  Result := (range.start > range.stop);
end;

{==============================================================================]
  <TRange_Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
function TRange_Create(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
begin
  Result.start := start;
  Result.stop := stop;
end;

{==============================================================================]
  <TRange_Build>
  @action: Create a TRange with start and stop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange_Build(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
begin
  Result.start := Min(start, stop);
  Result.stop := Max(stop, start);
end;

{==============================================================================]
  <TRange_Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange_Grab(const range: TRange): TRange; cdecl;
begin
  if (range.start > range.stop) then
    Result := TRange_Create(range.stop, range.start)
  else
    Result := range;
end;

{==============================================================================]
  <TRange_Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange_Size(const range: TRange): Integer; cdecl;
begin
  Result := (Abs(range.stop - range.start) + 1);
end;

{==============================================================================]
  <TRange_Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange_Length(const range: TRange): Integer; cdecl;
begin
  if (range.start > range.stop) then
    Result := ((range.start - range.stop) + 1)
  else
    Result := ((range.stop - range.start) + 1);
end;

{==============================================================================]
  <TRange_Min>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange_Min(const range: TRange): Integer; cdecl;
begin
  Result := Min(range.start, range.stop);
end;

{==============================================================================]
  <TRange_Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange_Minimum(const range: TRange): Integer; cdecl;
begin
  if (range.stop > range.start) then
    Result := range.start
  else
    Result := range.stop;
end;

{==============================================================================]
  <TRange_Max>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange_Max(const range: TRange): Integer; cdecl;
begin
  Result := Max(range.stop, range.start);
end;

{==============================================================================]
  <TRange_Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange_Maximum(const range: TRange): Integer; cdecl;
begin
  if (range.start < range.stop) then
    Result := range.stop
  else
    Result := range.start;
end;

{==============================================================================]
  <TRange_Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange_Digits(const range: TRange): TIntegerArray; cdecl;
var
  i, s: Integer;
begin
  s := Sign(range.stop - range.start);
  SetLength(Result, (Abs(range.stop - range.start) + 1));
  for i := 0 to High(Result) do
    Result[i] := (range.start + (i * s));
end;

{==============================================================================]
  <TRange_Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange_Ints(const range: TRange): TIntegerArray; cdecl;
var
  i, l: Integer;
begin
  l := (Abs(range.stop - range.start) + 1);
  SetLength(Result, l);
  case (range.start > range.stop) of
    True:
    for i := 0 to High(Result) do
      Result[((l - i) - 1)] := (i + range.stop);
    False:
    for i := 0 to High(Result) do
      Result[i] := (i + range.start);
  end;
end;

function TRange_Values(const range: TRange): TIntegerArray; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  SetLength(Result, TRange_Size(range));
  case TRange_Ascending(range) of
    False:
    for i := range.start downto range.stop do
      Result[r.Increase] := i;
    True:
    for i := range.start to range.stop do
      Result[r.Increase] := i;
  end;
end;

{==============================================================================]
  <TRange_TIntegerArray>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange_TIntegerArray(const range: TRange): TIntegerArray; cdecl;
var
  i, l, d: Integer;
begin
  l := TRange_Length(range);
  SetLength(Result, l);
  if (range.start <> range.stop) then
  begin
    d := Sign(range.stop - range.start);
    for i := 0 to ((l - 1) div 2) do
    begin
      Result[i] := (range.start + (i * d));
      Result[((l - 1) - i)] := (range.stop - (i * d));
    end;
  end else
    Result[0] := range.start;
end;

{==============================================================================]
  <TRange_Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange_Normalize(const range: TRange): TRange; cdecl;
begin
  Result.start := Min(range.start, range.stop);
  Result.stop := Max(range.start, range.stop);
end;

{==============================================================================]
  <TRange_Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange_Overlapping(const a, b: TRange): Boolean; cdecl;
begin
  Result := (Min(a.start, a.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(a.start, a.stop));
end;

{==============================================================================]
  <TRange_Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange_Overlap(const a, b: TRange): Boolean; cdecl;
begin
  Result := not (Min(a.start, a.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(a.start, a.stop));
end;

{==============================================================================]
  <TRange_Intersection>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRange_Intersection(const a, b: TRange; const null: TRange): TRange; cdecl;
var
  s, t: TRange;
  x, y: Integer;
begin
  s := TRange_Normalize(a);
  t := TRange_Normalize(b);
  x := Max(s.start, t.start);
  y := Min(s.stop, t.stop);
  if (x <= y) then
    Result := TRange_Create(x, y)
  else
    Result := null;
end;

{==============================================================================]
  <TRange_Intersection>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRange_Intersect(const a, b: TRange; var intersection: TRange): Boolean; cdecl;
var
  s, t: TRange;
  x, y: Integer;
begin
  s := TRange_Normalize(a);
  t := TRange_Normalize(b);
  x := Max(s.start, t.start);
  y := Min(s.stop, t.stop);
  Result := (x <= y);
  if Result then
    intersection := TRange_Create(x, y);
end;

{==============================================================================]
  <TRange_Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRange_Union(const a, b: TRange): TRange; cdecl;
begin
  Result.start := Min(Min(a.start, a.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(a.start, a.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <TRange_Shift>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange_Shift(const range: TRange; const delta: Integer): TRange; cdecl;
begin
  Result := TRange_Create((range.start + delta), (range.stop + delta));
end;

{==============================================================================]
  <TRange_Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange_Contains(const range: TRange; const x: Integer): Boolean; overload; cdecl;
begin
  Result := ((x >= Min(range.start, range.stop)) and (x <= Max(range.stop, range.start)));
end;

{==============================================================================]
  <TRange_Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange_Contains(const range, x: TRange): Boolean; overload; cdecl;
begin
  Result := ((Min(x.start, x.stop) >= Min(range.start, range.stop)) and (Max(x.start, x.stop) <= Max(range.start, range.stop)));
end;

{==============================================================================]
  <TRange_Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange_Reversed(const range: TRange): TRange; cdecl;
begin
  Result.start := range.stop;
  Result.stop := range.start;
end;

{==============================================================================]
  <TRange_Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange_Reverse(var range: TRange): Boolean; cdecl;
var
  s: Integer;
begin
  Result := (range.start <> range.stop);
  if not Result then
    Exit;
  s := range.start;
  range.start := range.stop;
  range.stop := s;
end;

{==============================================================================]
  <TRange_Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange_Equals(const a, b: TRange): Boolean; cdecl;
begin
  Result := ((Min(a.start, a.stop) = Min(b.start, b.stop)) and (Max(a.start, a.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange_Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange_Differs(const a, b: TRange): Boolean; cdecl;
begin
  Result := ((Min(a.start, a.stop) <> Min(b.start, b.stop)) or (Max(a.start, a.stop) <> Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange_Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange_Equal(const a, b: TRange): Boolean; cdecl;
begin
  Result := ((a.start = b.start) and (a.stop = b.stop));
end;

{==============================================================================]
  <TRange_Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange_Differ(const a, b: TRange): Boolean; cdecl;
begin
  Result := ((a.start <> b.start) or (a.stop <> b.stop));
end;

{==============================================================================]
  <TRange_Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRange_Clamp(const range, zone: TRange): TRange; cdecl;
var
  z: TRange;
begin
  Result := TRange_Normalize(range);
  z := TRange_Normalize(zone);
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
  if (range.start > range.stop) then
    TRange_Reverse(Result);
end;

{==============================================================================]
  <TRange_ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRange_ClampMax(const range: TRange; const maximum: Integer): TRange; cdecl;
begin
  if (range.start > maximum) then
    Result.start := maximum
  else
    Result.start := range.start;
  if (range.stop > maximum) then
    Result.stop := maximum
  else
    Result.stop := range.stop;
end;

{==============================================================================]
  <TRange_ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRange_ClampMin(const range: TRange; const minimum: Integer): TRange; cdecl;
begin
  if (range.start < minimum) then
    Result.start := minimum
  else
    Result.start := range.start;
  if (range.stop < minimum) then
    Result.stop := minimum
  else
    Result.stop := range.stop;
end;

{==============================================================================]
  <TRange_Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange_Restrict(var range: TRange; const zone: TRange): Boolean; cdecl;
var
  e: TRange;
begin
  e := TRange_Clamp(range, zone);
  Result := not TRange_Equals(e, range);
  if Result then
    range := e;
end;

{==============================================================================]
  <TRange_RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange_RestrictMin(var range: TRange; const minimum: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := TRange_ClampMin(range, minimum);
  Result := not TRange_Equals(e, range);
  if Result then
    range := e;
end;

{==============================================================================]
  <TRange_RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange_RestrictMax(var range: TRange; const maximum: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := TRange_ClampMax(range, maximum);
  Result := not TRange_Equals(e, range);
  if Result then
    range := e;
end;

{==============================================================================]
  <TRange_Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRange_Clip(const range, zone: TRange): TRange;
begin
  Result.start := Max(zone.start, Min(range.start, zone.stop));
  Result.stop := Min(zone.stop, Max(range.stop, zone.start));
end;

{==============================================================================]
  <TRange_ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRange_ClipMin(const range: TRange; minimum: Integer): TRange;
begin
  Result.start := Max(range.start, minimum);
  Result.stop := Max(range.stop, minimum);
end;

{==============================================================================]
  <TRange_ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRange_ClipMax(const range: TRange; maximum: Integer): TRange;
begin
  Result.start := Min(range.start, maximum);
  Result.stop := Min(range.stop, maximum);
end;

{==============================================================================]
  <TRange_Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRange_Distribute(const range: TRange; const parts: Integer): TRangeArray; cdecl;
var
  i, s, e, a, b, p: Integer;
  r: TRange;
begin
  if (parts > 0) then
  begin
    r := TRange_Normalize(range);
    s := TRange_Size(r);
    p := Min(s, parts);
    e := (s mod p);
    a := r.start;
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      b := (a + ((s div p) - 1));
      if (i < e) then
        Inc(b);
      if (range.start > range.stop) then
        Result[i] := TRange_Create(b, a)
      else
        Result[i] := TRange_Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRange_Partition>
  @action: Partitions range to TRangeArray by size of parts
  @note: None.
[==============================================================================}
function TRange_Partition(const range: TRange; const size: Integer): TRangeArray; cdecl;
var
  a, b, l: Integer;
  r: TRange;
begin
  l := 0;
  if (size > 0) then
  begin
    r := TRange_Normalize(range);
    SetLength(Result, TRange_Size(r));
    a := r.start;
    while (a <= r.stop) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (range.start > range.stop) then
        Result[l.Increase] := TRange_Create(b, a)
      else
        Result[l.Increase] := TRange_Create(a, b);
      a := (b + 1);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TRange_Divide>
  @action: Partitions range to TRangeArray by size of parts
  @note: Alternative for TRange_Partition.
[==============================================================================}
function TRange_Divide(const range: TRange; const size: Integer): TRangeArray; cdecl;
var
  a, b, i: Integer;
  r: TRange;
begin
  if (size > 0) then
  begin
    r := TRange_Normalize(range);
    SetLength(Result, (((TRange_Size(r) + size) - 1) div size));
    a := r.start;
    for i := 0 to High(Result) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (range.start > range.stop) then
        Result[i] := TRange_Create(b, a)
      else
        Result[i] := TRange_Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRange_Touch>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange_Touch(const a, b: TRange): Boolean; cdecl;
begin
  Result := (((Max(a.start, a.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(a.start, a.stop)));
end;

{==============================================================================]
  <TRange_Touches>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange_Touches(const a, b: TRange): Boolean; cdecl;
var
  i, j: TRange;
begin
  i := TRange_Normalize(a);
  j := TRange_Normalize(b);
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <TRange_Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRange_Distance(const a, b: TRange): Integer; cdecl;
var
  r1, r2: TRange;
begin
  r1 := TRange_Normalize(a);
  r2 := TRange_Normalize(b);
  if (r1.stop < r2.start) then
    Result := (r2.start - r1.stop)
  else
    if (r2.stop < r1.start) then
      Result := (r1.start - r2.stop)
    else
      Result := 0;
end;

{==============================================================================]
  <TRange_DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRange_DistHausdorff(const a, b: TRange): Integer; cdecl;
var
  i, j: TRange;
begin
  i := TRange_Normalize(a);
  j := TRange_Normalize(b);
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
end;

{==============================================================================]
 <TRange_Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange_Digit(const range: TRange; const x: Integer): Boolean; cdecl; inline;
begin
  Result := (((x >= range.start) and (x <= range.stop)) or ((x >= range.stop) and (x <= range.start)));
end;


{==============================================================================]
 <TRange_Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange_Value(const range: TRange; const x: Integer): Boolean; cdecl; inline;
begin
  Result := not (((x < range.start) and (x < range.stop)) or ((x > range.stop) and (x > range.start)));
end;

{==============================================================================]
 <TRange_Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange_Middle(const range: TRange): Double; cdecl;
var
  s: Integer;
begin
  s := (TRange_Max(range) + TRange_Min(range));
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
 <TRange_Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange_Center(const range: TRange): Integer; cdecl;
begin
  Result := ((TRange_Max(range) + TRange_Min(range)) div 2);
end;

{==============================================================================]
 <TRange_String>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRange_String(const range: TRange): string; cdecl;
begin
  Result := ('[' + IntToStr(range.start) + '..' + IntToStr(range.stop) + ']');
end;
