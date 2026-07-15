{$IFDEF METHODS}
function Asceal: Boolean; overload;
function Ascendable: Boolean; overload;
function Ascendable(const val: Integer): Boolean; overload;
function Ascual: Boolean; overload;
function Ascular: Boolean; overload;

function Desceal: Boolean; overload;
function Descendable: Boolean; overload;
function Descendable(const val: Integer): Boolean; overload;
function Descual: Boolean; overload;
function Descular: Boolean; overload;

function Decreasing: Boolean; overload;
function Decremental: Boolean; overload;
function Increasing: Boolean; overload;
function Incremental: Boolean; overload;

function StartHigher: Boolean; overload;
function StartLower: Boolean; overload;
function Startmax: Boolean; overload;
function Startmaximal: Boolean; overload;
function Startmin: Boolean; overload;
function Startminimal: Boolean; overload;

function StopHigher: Boolean; overload;
function StopLower: Boolean; overload;
function Stopmax: Boolean; overload;
function Stopmaximal: Boolean; overload;
function Stopmin: Boolean; overload;
function Stopminimal: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Asceal>
  @action: Determines if the range is configured in ascending (increasing) order.
  @note: Returns True if the start boundary is less than or equal to the stop boundary.
[==============================================================================}
function TRange.Asceal: Boolean; overload;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <Ascendable>
  @action: Checks if the range is currently oriented in an ascending direction.
  @note: Returns True if start is less than or equal to stop, indicating a 
         valid upward or flat progression.
[==============================================================================}
function TRange.Ascendable: Boolean; overload;
begin
  Result := (Self.Singular or (Self.start < Self.stop));
end;

{==============================================================================]
  <Ascendable>
  @action: Evaluates if the range can maintain or form an ascending sequence with the value.
  @note: Returns True if the specified value is greater than or equal to the start 
         boundary, meaning progression from start to val climbs upward or remains flat.
[==============================================================================}
function TRange.Ascendable(const val: Integer): Boolean; overload;
begin
  Result := (Self.start <= val);
end;

{==============================================================================]
  <Ascual>
  @action: Returns True if the range is bent toward `stop`,
           progressing from a lesser to a greater value (Direction >= 0).
  @note: Returns True for singular ranges (Direction = 0).
[==============================================================================}
function TRange.Ascual: Boolean; overload;
begin
  Result := (Self.Direction >= 0);
end;

{==============================================================================]
  <Ascular>
  @action: Returns True if `start` sits on the lesser side (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Ascular: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) < 1);
end;

{==============================================================================]
  <Desceal>
  @action: Determines if the range is configured in descending (decreasing) order.
  @note: Returns True if the start boundary is greater than or equal to the stop boundary.
[==============================================================================}
function TRange.Desceal: Boolean; overload;
begin
  Result := (Self.start >= Self.stop);
end;

{==============================================================================]
  <Descendable>
  @action: Checks if the range is currently oriented in a descending direction.
  @note: Returns True if start is greater than or equal to stop, indicating a 
         valid downward or flat progression.
[==============================================================================}
function TRange.Descendable: Boolean; overload;
begin
  Result := (Self.Singular or (Self.start > Self.stop));
end;

{==============================================================================]
  <Descendable>
  @action: Evaluates if the range can maintain or form a descending sequence with the value.
  @note: Returns True if the specified value is less than or equal to the start 
         boundary, meaning progression from start to val drops downward or remains flat.
[==============================================================================}
function TRange.Descendable(const val: Integer): Boolean; overload;
begin
  Result := (Self.start >= val);
end;

{==============================================================================]
  <Descual>
  @action: Returns True if the range is bent toward `start`,
           progressing from a greater to a lesser value (Direction <= 0).
  @note: Returns True for singular ranges (Direction = 0).
[==============================================================================}
function TRange.Descual: Boolean; overload;
begin
  Result := (Self.Direction <= 0);
end;

{==============================================================================]
  <Descular>
  @action: Returns True if `stop` sits on the lesser side (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Descular: Boolean; overload;
begin
  Result := (Self.stop.Compare(Self.start) < 1);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) > -1);
end;

{==============================================================================]
  <Decremental>
  @action: Returns True if the range progresses from a greater to a lesser value (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Decremental: Boolean; overload;
begin
  Result := (Self.stop <= Self.start);
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Non-strict.
[==============================================================================}
function TRange.Increasing: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) < 1);
end;

{==============================================================================]
  <Incremental>
  @action: Returns True if the range progresses from a lesser to a greater value (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Incremental: Boolean; overload;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <StartHigher>
  @action: Returns True if `start` is strictly greater than `stop`.
  @note: Returns False for singular ranges (start = stop).
[==============================================================================}
function TRange.StartHigher: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <StartLower>
  @action: Returns True if `start` is strictly less than `stop`.
  @note: Returns False for singular ranges (start = stop).
[==============================================================================}
function TRange.StartLower: Boolean; overload;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Startmax>
  @action: Returns True if `start` holds the maximum value (start >= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Startmax: Boolean; overload;
begin
  Result := (Self.Maximum = Self.start);
end;

{==============================================================================]
  <Startmaximal>
  @action: Determines if the range's start boundary is free to be the maximum value.
  @note: Returns True if the Maximum does not equal the stop boundary,
         implying that the start boundary holds the Maximum value (or the range is descending).
[==============================================================================}
function TRange.Startmaximal: Boolean; overload;
begin
  Result := not (Self.Maximum = Self.stop);
end;

{==============================================================================]
  <Startmin>
  @action: Returns True if `start` holds the minimum value (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Startmin: Boolean; overload;
begin
  Result := (Self.Minimum = Self.start);
end;

{==============================================================================]
  <Startminimal>
  @action: Determines if the range's start boundary is free to be the minimum value.
  @note: Returns True if the Minimum does not equal the stop boundary,
         implying that the start boundary holds the Minimum value (or the range is ascending).
[==============================================================================}
function TRange.Startminimal: Boolean; overload;
begin
  Result := not (Self.Minimum = Self.stop);
end;

{==============================================================================]
  <StopHigher>
  @action: Returns True if `stop` is strictly greater than `start`.
  @note: Returns False for singular ranges (start = stop).
[==============================================================================}
function TRange.StopHigher: Boolean; overload;
begin
  Result := (Self.stop > Self.start);
end;

{==============================================================================]
  <StopLower>
  @action: Returns True if `stop` is strictly less than `start`.
  @note: Returns False for singular ranges (start = stop).
[==============================================================================}
function TRange.StopLower: Boolean; overload;
begin
  Result := (Self.stop < Self.start);
end;

{==============================================================================]
  <Stopmax>
  @action: Returns True if `stop` holds the maximum value (stop >= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Stopmax: Boolean; overload;
begin
  Result := (Self.Maximum = Self.stop);
end;

{==============================================================================]
  <Stopmaximal>
  @action: Determines if the range's stop boundary is free to be the maximum value.
  @note: Returns True if the Maximum does not equal the start boundary,
         implying that the stop boundary holds the Maximum value (or the range is ascending).
[==============================================================================}
function TRange.Stopmaximal: Boolean; overload;
begin
  Result := not (Self.Maximum = Self.start);
end;

{==============================================================================]
  <Stopmin>
  @action: Returns True if `stop` holds the minimum value (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Stopmin: Boolean; overload;
begin
  Result := (Self.Minimum = Self.stop);
end;

{==============================================================================]
  <Stopminimal>
  @action: Determines if the range's stop boundary is free to be the minimum value.
  @note: Returns True if the Minimum does not equal the start boundary,
         implying that the stop boundary holds the Minimum value (or the range is descending).
[==============================================================================}
function TRange.Stopminimal: Boolean; overload;
begin
  Result := not (Self.Minimum = Self.start);
end;
{$ENDIF}
