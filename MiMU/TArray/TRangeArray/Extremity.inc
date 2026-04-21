{$IFDEF HELPERS}
function MaxStart: Integer; overload;
function MaxStop: Integer; overload;
function MaxValue: Integer; overload;
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