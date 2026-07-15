{$IFDEF METHODS}
function Ascendable: Boolean; overload;
function Ascendable(const val: Integer): Boolean; overload;
function Ascendal: Boolean; overload;
function Ascending: Boolean; overload;
function Asceal: Boolean; overload;
function Ascency: Boolean; overload;
function Ascends: Boolean; overload;
function Ascing: Boolean; overload;
function Decreasing: Boolean; overload;
function Decremental: Boolean; overload;
function Desceal: Boolean; overload;
function Descendable: Boolean; overload;
function Descendable(const val: Integer): Boolean; overload;
function Descency: Boolean; overload;
function Descendal: Boolean; overload;
function Descending: Boolean; overload;
function Descends: Boolean; overload;
function Descing: Boolean; overload;
function Dropping: Boolean; overload;
function Drops: Boolean; overload;
function Growing: Boolean; overload;
function Grows: Boolean; overload;
function Increasing: Boolean; overload;
function Incremental: Boolean; overload;
function IsAscending: Boolean; overload;
function IsDescending: Boolean; overload;
function Nonascending: Boolean; overload;
function Nondescending: Boolean; overload;
function Shrinking: Boolean; overload;
function Shrinks: Boolean; overload;
function Startbent: Boolean; overload;
function StartHigher: Boolean; overload;
function StartLower: Boolean; overload;
function Startmax: Boolean; overload;
function Startmin: Boolean; overload;
function Startminded: Boolean; overload;
function Startsided: Boolean; overload;
function Startwise: Boolean; overload;
function Stopbent: Boolean; overload;
function StopHigher: Boolean; overload;
function StopLower: Boolean; overload;
function Stopmax: Boolean; overload;
function Stopmin: Boolean; overload;
function Stopminded: Boolean; overload;
function Stopsided: Boolean; overload;
function Stopwise: Boolean; overload;
function Rises: Boolean; overload;
function Rising: Boolean; overload;
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
  Result := (Self.start <= Self.stop);
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
  <Ascency>
  @action: Determines if the range is strictly ascending using a sign-of-difference check.
  @note: Returns True if (stop - start) is positive. Only applicable to numeric range types.
[==============================================================================}
function TRange.Ascency: Boolean; overload;
begin
  Result := (Sign(Self.stop - Self.start) > 0);
end;

{==============================================================================]
  <Ascendal>
  @action: Determines if the range is strictly ascending (increasing).
  @note: Returns True only if the start boundary is strictly less than the stop boundary.
[==============================================================================}
function TRange.Ascendal: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) < 0);
end;

{==============================================================================]
  <Ascending>
  @action: Determines if the range is strictly ascending.
  @note: Returns True if the start value is strictly less than the stop value.
[==============================================================================}
function TRange.Ascending: Boolean; overload;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Determines if the range is strictly ascending by negating a greater-than-or-equal-to comparison.
  @note: Returns True if the start value is strictly less than the stop value. Logically equivalent to "not (start >= stop)".
[==============================================================================}
function TRange.Ascends: Boolean; overload;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Ascing>
  @action: Returns True if the range is oriented forward.
  @note: Strict inequality (Stop > Start).
         Returns False if the range is stationary (Start = Stop).
[==============================================================================}
function TRange.Ascing: Boolean; overload;
begin
  Result := (Self.stop > Self.start);
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
  Result := (Self.start >= Self.stop);
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
  <Descency>
  @action: Determines if the range is strictly descending using a sign-of-difference check.
  @note: Returns True if (start - stop) is positive. Only applicable to numeric range types.
[==============================================================================}
function TRange.Descency: Boolean; overload;
begin
  Result := (Sign(Self.start - Self.stop) > 0);
end;

{==============================================================================]
  <Descendal>
  @action: Determines if the range is strictly descending (decreasing).
  @note: Returns True only if the start boundary is strictly greater than the stop boundary.
[==============================================================================}
function TRange.Descendal: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) > 0);
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the range is ordered in strictly descending order,
           i.e. the start value is greater than the stop value.
  @note: A range with equal start and stop values is not considered descending.
         This function is logically equivalent to not Ascending.
[==============================================================================}
function TRange.Descending: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Descends>
  @action: Returns True if the range descends, meaning the start value is greater
           than the stop value.
  @note: This function is semantically equivalent to Descending and exists to
         support verb-style readability in conditional expressions.
[==============================================================================}
function TRange.Descends: Boolean; overload;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Descing>
  @action: Returns True if the range is oriented backward.
  @note: Strict inequality (Start > Stop).
         Returns False if the range is stationary (Start = Stop).
[==============================================================================}
function TRange.Descing: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Dropping>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Dropping: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Drops>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Drops: Boolean; overload;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Growing>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Growing: Boolean; overload;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Grows>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Grows: Boolean; overload;
begin
  Result := not (Self.start >= Self.stop);
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
  <IsAscending>
  @action: Determines if the range is strictly ascending by checking if the start value is less than the stop value.
  @note: Returns True if (start - stop) is less than zero. Requires a numeric type that supports subtraction.
[==============================================================================}
function TRange.IsAscending: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) < 0);
end;

{==============================================================================]
  <IsDescending>
  @action: Determines whether the range is in descending order.
  @note: Returns True if Start is greater than Stop.
         Useful for iteration or conditional logic that depends on direction.
[==============================================================================}
function TRange.IsDescending: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) > 0);
end;

{==============================================================================]
  <Nonascending>
  @action: Evaluates if the range is currently oriented in a non-ascending direction.
  @note: Returns True if start is greater than or equal to stop, ensuring that
         no upward progression exists between the boundaries.
[==============================================================================}
function TRange.Nonascending: Boolean; overload;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Nondescending>
  @action: Evaluates if the range is currently oriented in a non-descending direction.
  @note: Returns True if start is less than or equal to stop, ensuring that
         no downward progression exists between the boundaries.
[==============================================================================}
function TRange.Nondescending: Boolean; overload;
begin
  Result := not (Self.start > Self.stop);
end; 

{==============================================================================]
  <Shrinking>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinking: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Shrinks>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinks: Boolean; overload;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Startbent>
  @action: Returns True if the range is bent toward `start`,
           progressing from a greater to a lesser value (Direction <= 0).
  @note: Returns True for singular ranges (Direction = 0).
[==============================================================================}
function TRange.Startbent: Boolean; overload;
begin
  Result := (Self.Direction <= 0);
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
  Result := (Max(Self.start, Self.stop) = Self.start);
end;

{==============================================================================]
  <Startmin>
  @action: Returns True if `start` holds the minimum value (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Startmin: Boolean; overload;
begin
  Result := (Min(Self.start, Self.stop) = Self.start);
end;

{==============================================================================]
  <Startminded>
  @action: Determines whether the range is currently aligned with its start boundary.
  @note: Returns True when the Minimum value equals the Start value, indicating
         that the range is positioned at or biased toward the start endpoint.
[==============================================================================}
function TRange.Startminded: Boolean; overload;
begin
  Result := (Self.Minimum = Self.start);
end;

{==============================================================================]
  <Startsided>
  @action: Returns True if `start` sits on the lesser side (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Startsided: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) < 1);
end;

{==============================================================================]
  <Startwise>
  @action: Returns True if the range progresses from a greater to a lesser value (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Startwise: Boolean; overload;
begin
  Result := not (Self.stop > Self.start);
end;

{==============================================================================]
  <Stopbent>
  @action: Returns True if the range is bent toward `stop`,
           progressing from a lesser to a greater value (Direction >= 0).
  @note: Returns True for singular ranges (Direction = 0).
[==============================================================================}
function TRange.Stopbent: Boolean; overload;
begin
  Result := (Self.Direction >= 0);
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
  Result := (Max(Self.start, Self.stop) = Self.stop);
end;

{==============================================================================]
  <Stopmin>
  @action: Returns True if `stop` holds the minimum value (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Stopmin: Boolean; overload;
begin
  Result := (Min(Self.start, Self.stop) = Self.stop);
end;

{==============================================================================]
  <Stopminded>
  @action: Determines whether the range is currently aligned with its stop boundary.
  @note: Returns True when the Minimum value equals the Stop value, indicating
         that the range is positioned at or biased toward the stop endpoint.
[==============================================================================}
function TRange.Stopminded: Boolean; overload;
begin
  Result := (Self.Minimum = Self.stop);
end;

{==============================================================================]
  <Stopsided>
  @action: Returns True if `stop` sits on the lesser side (stop <= start).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Stopsided: Boolean; overload;
begin
  Result := (Self.stop.Compare(Self.start) < 1);
end;

{==============================================================================]
  <Stopwise>
  @action: Returns True if the range progresses from a lesser to a greater value (start <= stop).
  @note: Returns True for singular ranges (start = stop).
[==============================================================================}
function TRange.Stopwise: Boolean; overload;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Rises>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rises: Boolean; overload;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Rising>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rising: Boolean; overload;
begin
  Result := (Self.start < Self.stop);
end;
{$ENDIF}
