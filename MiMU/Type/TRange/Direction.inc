{$IFDEF METHODS}
function Direction: Integer;
function Orientation: Integer;
function Signum: Integer;
function Slope: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Direction>
  @action: Returns the orientation of the range.
  @note: 1  => descending (stop > start)
        -1  => ascending  (start > stop)
         0  => degenerate (start = stop)
[==============================================================================}
function TRange.Direction: Integer;
begin
  Result := Sign(Self.Delta);
end;

{==============================================================================]
  <Orientation>
  @action: Returns +1 if the range is ascending or degenerate (Stop >= Start),
           and -1 if the range is descending (Stop < Start).
  @note: Useful for determining iteration direction or orientation of the range.
[==============================================================================}
function TRange.Orientation: Integer;
begin
  Result := IfThen((Self.Stop < Self.Start), -1, 1);
end;

{==============================================================================]
  <Signum>
  @action: Returns the directional sign of the range. 
           +1 if the range is ascending (stop > start), 
           -1 if descending (stop < start), 
           0 if start = stop.
  @note: Useful for determining the trend or direction of the range without
         caring about the magnitude. Does not include endpoints count.
[==============================================================================}
function TRange.Signum: Integer;
begin
  if (Self.start = Self.stop) then
    Result := 0
  else
    Result := ((Self.stop - Self.start) div Abs(Self.start - Self.stop));
end;

{==============================================================================]
  <Slope>
  @action: Returns the slope (direction) of the range.
           +1 if the range is ascending (stop > start),
           -1 if descending (stop < start),
           0 if start = stop.
  @note: Useful for determining the trend of the range without considering magnitude.
         Equivalent to Signum in behavior; purely indicates direction.
[==============================================================================}
function TRange.Slope: Integer;
begin
  if (Self.start = Self.stop) then
    Result := 0
  else
    if (Self.stop > Self.start) then
      Result := 1
    else
      Result := -1;
end;
{$ENDIF}