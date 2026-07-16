{$IFDEF HELPERS}
function Ceiling: Integer; overload;
function Flooring: Integer; overload;
function MaxStart: Integer; overload;
function MaximumValue: Integer; overload;
function MaxStop: Integer; overload;
function MaxValue: Integer; overload;
function MinimumValue: Integer; overload;
function MinStart: Integer; overload;
function MinStop: Integer; overload;
function MinValue: Integer; overload;
function StartMax: Integer; overload;
function StartMin: Integer; overload;
function StopMax: Integer; overload;
function StopMin: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ceiling>
  @action: Scans for the absolute highest coordinate value in the set.
  @note: Uses pointer arithmetic for maximum performance. This identifies the
         true "top" of the data, regardless of range orientation or field.
[==============================================================================}
function TRangeArrayHelper.Ceiling: Integer; overload;
var
  P: PRange;
  i: Integer;
begin
  Result := Low(Integer);
  if Self.Empty then
    Exit;
  P := @Self[0];
  for i := 0 to High(Self) do
  begin
    if (P^.start > Result) then
      Result := P^.start;
    if (P^.stop > Result) then
      Result := P^.stop;
    Inc(P);
  end;
end;

{==============================================================================]
  <Flooring>
  @action: Scans for the absolute lowest coordinate value in the set.
  @note: Uses pointer arithmetic to find the "true bottom" coordinate.
         Essential for datasets containing inverted (descending) ranges.
[==============================================================================}
function TRangeArrayHelper.Flooring: Integer; overload;
var
  P: PRange;
  i: Integer;
begin
  Result := High(Integer);
  if Self.Empty then
    Exit;
  P := @Self[0];
  for i := 0 to High(Self) do
  begin
    if (P^.start < Result) then
      Result := P^.start;
    if (P^.stop < Result) then
      Result := P^.stop;
    Inc(P);
  end;
end;

{==============================================================================]
  <MaximumValue>
  @action: Recursively finds the absolute highest coordinate in the array.
  @note: Identifies the "peak" coordinate by comparing all start/stop fields
         through a recursive winner-take-all tree.
[==============================================================================}
function TRangeArrayHelper.MaximumValue: Integer; overload;
  function Return(const aLow, aHigh: Integer): Integer;
  var
    M: Integer;
    L, R: Integer;
  begin
    if (aLow = aHigh) then
      Exit(Max(Self[aLow].start, Self[aLow].stop));
    M := ((aLow + aHigh) div 2);
    L := Return(aLow, M);
    R := Return((M + 1), aHigh);
    Result := Max(L, R);
  end;
begin
  if Self.Empty then
    Exit(Low(Integer));
  Result := Return(0, High(Self));
end;

{==============================================================================]
  <MaxStart>
  @action: Returns the highest numerical value found across all 'start' fields.
  @note: Independent of range direction; purely scans the 'start' member.
[==============================================================================}
function TRangeArrayHelper.MaxStart: Integer; overload;
var
  i: Integer;
begin
  Result := Low(Integer);
  for i := 0 to High(Self) do
    Result := Max(Result, Self[i].start);
end;

{==============================================================================]
  <MaxStop>
  @action: Returns the highest numerical value found across all 'stop' fields.
  @note: Tracks the maximum value specifically within the 'stop' column.
[==============================================================================}
function TRangeArrayHelper.MaxStop: Integer; overload;
var
  i: Integer;
begin
  Result := Low(Integer);
  for i := 0 to High(Self) do
    Result := Max(Result, Self[i].stop);
end;

{==============================================================================]
  <MaxValue>
  @action: Scans the entire array for the absolute highest coordinate value.
  @note: Inspects both 'start' and 'stop' fields. This is the definitive 
         "Right-most" or "Top" point of the data set.
[==============================================================================}
function TRangeArrayHelper.MaxValue: Integer; overload;
var
  i: Integer;
begin
  Result := Low(Integer);
  for i := 0 to High(Self) do
    Result := Max(Result, Self[i].Maximum);
end;

{==============================================================================]
  <MinimumValue>
  @action: Recursively finds the absolute lowest coordinate in the array.
  @note: Uses a binary-split reduction (Divide & Conquer). This is the 
         "bedrock" value of the collection, regardless of range orientation.
[==============================================================================}
function TRangeArrayHelper.MinimumValue: Integer; overload;
  function Return(const aLow, aHigh: Integer): Integer;
  var
    M: Integer;
    L, R: Integer;
  begin
    if (aLow = aHigh) then
      Exit(Min(Self[aLow].start, Self[aLow].stop));
    M := ((aLow + aHigh) div 2);
    L := Return(aLow, M);
    R := Return((M + 1), aHigh);
    Result := Min(L, R);
  end;
begin
  if Self.Empty then
    Exit(High(Integer));
  Result := Return(0, High(Self));
end;

{==============================================================================]
  <MinStart>
  @action: Returns the lowest numerical value found across all 'start' fields.
  @note: Tracks the minimum value specifically within the 'start' column.
[==============================================================================}
function TRangeArrayHelper.MinStart: Integer; overload;
var
  i: Integer;
begin
  Result := High(Integer);
  for i := 0 to High(Self) do
    Result := Min(Result, Self[i].start);
end;

{==============================================================================]
  <MinStop>
  @action: Returns the lowest numerical value found across all 'stop' fields.
  @note: Useful for identifying the floor of the 'stop' values in the array.
[==============================================================================}
function TRangeArrayHelper.MinStop: Integer; overload;
var
  i: Integer;
begin
  Result := High(Integer);
  for i := 0 to High(Self) do
    Result := Min(Result, Self[i].stop);
end;

{==============================================================================]
  <MinValue>
  @action: Scans the entire array for the absolute lowest coordinate value.
  @note: Inspects both 'start' and 'stop' fields. This is the definitive 
         "Left-most" or "Bottom" point of the data set.
[==============================================================================}
function TRangeArrayHelper.MinValue: Integer; overload;
var
  i: Integer;
begin
  Result := High(Integer);
  for i := 0 to High(Self) do
    Result := Min(Result, Self[i].Minimum);
end;

{==============================================================================]
  <StartMax>
  @action: Returns the highest numerical value found in the 'start' fields.
  @note: Useful for finding the upper bound of start coordinates, regardless 
         of whether the ranges are ascending or descending.
[==============================================================================}
function TRangeArrayHelper.StartMax: Integer; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Low(Integer));
  Result := Self[0].start;
  for i := 1 to High(Self) do
    if (Self[i].start > Result) then
      Result := Self[i].start;
end;

{==============================================================================]
  <StartMin>
  @action: Returns the lowest numerical value found in the 'start' fields.
  @note: Tracks the minimum coordinate specifically within the 'start' column.
[==============================================================================}
function TRangeArrayHelper.StartMin: Integer; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(High(Integer));
  Result := Self[0].start;
  for i := 1 to High(Self) do
    if (Self[i].start < Result) then
      Result := Self[i].start;
end;

{==============================================================================]
  <StopMax>
  @action: Returns the highest numerical value found in the 'stop' fields.
  @note: Tracks the maximum coordinate specifically within the 'stop' column.
[==============================================================================}
function TRangeArrayHelper.StopMax: Integer; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Low(Integer));
  Result := Self[0].stop;
  for i := 1 to High(Self) do
    if (Self[i].stop > Result) then
      Result := Self[i].stop;
end;

{==============================================================================]
  <StopMin>
  @action: Returns the lowest numerical value found in the 'stop' fields.
  @note: Useful for finding the lower bound of stop coordinates in the array.
[==============================================================================}
function TRangeArrayHelper.StopMin: Integer; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(High(Integer));
  Result := Self[0].stop;
  for i := 1 to High(Self) do
    if (Self[i].stop < Result) then
      Result := Self[i].stop;
end;
{$ENDIF}