{$IFDEF METHODS}
function Area: Integer;
function Capacity: Integer;
function Count: Integer;
function Coverage: Integer; overload;
function Deficit: Integer; 
function Delta: Integer;
function Diameter: Integer; overload;
function Diff: Integer;
function Difference: Integer;
function Dist: Integer;
function Extent: Integer; overload;
function Length: Integer; overload;
function Magnitude: Integer;
function Population: Integer; overload;
function Rad: Integer; overload;
function Radiar: Integer; overload;
function Radius: Integer; overload;
function Reach: Integer; overload;
function Span: Integer;
function Size: Integer; overload; 
function Size(var minVal, maxVal: Integer): Integer; overload; 
function Sized: Integer; overload;
function Sum: Int64; 
function Summation: Int64;
function Total: Int64;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Area>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Area: Integer;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) + 1)
  else 
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <Count>
  @action: Returns count values in the given range.
  @note: None.
[==============================================================================}
function TRange.Count: Integer;
begin
  Result := ((Max(Self.start, Self.stop) - Min(Self.start, Self.stop)) + 1);
end;

{==============================================================================]
  <Coverage>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Coverage: Integer; overload;
begin
  case Self.start.Compare(Self.stop) of
    0: Result := 1;
	-1: Result := ((Self.stop - Self.start) + 1);
	1: Result := ((Self.start - Self.stop) + 1);
  end;
end;

{==============================================================================]
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
end;

{==============================================================================]
  <Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer; inline;
begin
  Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <Diameter>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Diameter: Integer; overload;
begin
  Result := ((Self.stop - Self.start) + 1);
  if (Self.stop < Self.start) then
    Result := (-Result + 2);
end;

{==============================================================================]
  <Diff>
  @action: Returns the absolute difference (magnitude) between start and stop,
           ignoring the direction of the range.
  @note: The result is always non-negative. Equivalent to Abs(stop - start).
         Does not include endpoints; useful when only the gap between values matters.
[==============================================================================}
function TRange.Diff: Integer;
begin
  Result := (Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Difference>
  @action: Returns the absolute difference between the start and stop values,
           ignoring the direction of the range.
  @note: Diff is always non-negative and exclusive of endpoints. Use this if
         you only care about the magnitude of the gap, not whether the range
         is ascending or descending.
[==============================================================================}
function TRange.Difference: Integer;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Dist>
  @action: Returns the distance between the start and stop values of the range.
           Uses a compact conditional expression to handle descending ranges.
  @note: Same as Distance but written using IfThen for brevity. Still exclusive
         of endpoints and sensitive to the Descending flag.
[==============================================================================}
function TRange.Dist: Integer;
begin
  Result := IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start));
end;

{==============================================================================]
  <Extent>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Extent: Integer; overload;
begin
  Result := Succ(Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Length: Integer; overload;
begin
  if (Self.start = Self.stop) then
    Result := 1
  else if (Self.stop < Self.start) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Magnitude>
  @action: Returns the magnitude (non-negative size) of the range, ignoring orientation.
  @note: Computed as the absolute value of Delta (Abs(Stop - Start)).
         Always ≥ 0, regardless of whether the range is ascending or descending.
[==============================================================================}
function TRange.Magnitude: Integer;
begin
  Result := Abs(Self.Delta);
end;

{==============================================================================]
  <Population>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Population: Integer; overload;
begin
  Result := ((Self.MinMax.stop - Self.MinMax.start) + 1);
end;

{==============================================================================]
  <Rad>
  @action: Returns the half-length (radius) of the range as an integer value.
  @note: Computed as Abs(Stop - Start) shr 1; equivalent to (|Stop - Start| div 2).
[==============================================================================}
function TRange.Rad: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) shr 1);
end;

{==============================================================================]
  <Radiar>
  @action: Returns half the absolute distance between Start and Stop, rounded to the nearest integer.
  @note: Computed as Round(Abs(Stop - Start) * 0.5). Useful when a midpoint-to-edge distance is needed
         and rounding is preferred over truncation. Order of Start and Stop does not matter.
[==============================================================================}
function TRange.Radiar: Integer; overload;
begin
  Result := Round(Abs(Self.stop - Self.start) * 0.5);
end;

{==============================================================================]
  <Radius>
  @action: Returns half the total span (distance) between Start and Stop.
  @note: Equivalent to (RangeLength / 2); independent of which value is greater.
[==============================================================================}
function TRange.Radius: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) div 2);
end;

{==============================================================================]
  <Reach>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Reach: Integer; overload;
begin
  Result := (Self.stop - Self.start);
  if (Result < 0) then
    Result := -Result;
  Result := (Result + 1);
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size(var minVal, maxVal: Integer): Integer; overload;
begin
  minVal := Min(Self.start, Self.stop);
  maxVal := Max(Self.start, Self.stop);
  Result := ((maxVal - minVal) + 1);
end;

{==============================================================================]
  <Sized>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Sized: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) + 1);
end;

{==============================================================================]
  <Span>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Span: Integer;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Sum>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Sum: Int64;
var
  a, b: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  Result := ((((b - a) + 1) * (a + b)) div 2);
end;

{==============================================================================]
  <Summation>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Summation: Int64;
var
  a, b, c, s, n: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  n := ((b - a) + 1);
  s := (a + b);
  c := (s div 2);
  Result := (n * c);
  if ((s and 1) = 1) then
    Result := (Result + (n div 2));
end;

{==============================================================================]
  <Total>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Total: Int64;
begin
  if Self.Descending then
    Result := (((Int64(Self.start) * (Self.start + 1)) div 2) - ((Int64(Self.stop - 1) * Self.stop) div 2))
  else
    Result := (((Int64(Self.stop) * (Self.stop + 1)) div 2) - ((Int64(Self.start - 1) * Self.start) div 2));
end;
{$ENDIF}