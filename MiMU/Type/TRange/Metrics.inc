{$IFDEF TYPES}
function Count: Integer; 
function Area: Integer; 
function Span: Integer;
function Sized: Integer; overload;	
function Size: Integer; overload; 
function Size(var minVal, maxVal: Integer): Integer; overload; 
function Length: Integer; overload;
function Capacity: Integer;
function Extent: Integer; overload;
function Reach: Integer; overload;
function Coverage: Integer; overload;
function Diameter: Integer; overload;
function Population: Integer; overload;	
function Delta: Integer;
function Dist: Integer;
function Difference: Integer;
function Diff: Integer;
function Magnitude: Integer; 
function Deficit: Integer;
{$ENDIF}

{$IFDEF HELPERS}

{$ENDIF}

{$IFDEF METHODS}

{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
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
  <Extent>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Extent: Integer; overload;
begin
  Result := Succ(Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Reach>
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
  <Population>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Population: Integer; overload;
begin
  Result := ((Self.MinMax.stop - Self.MinMax.start) + 1);
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
  <Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer; inline;
begin
  Result := (Self.stop - Self.start);
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
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
end;
{$ENDIF}