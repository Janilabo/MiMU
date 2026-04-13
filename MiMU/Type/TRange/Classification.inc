{$IFDEF METHODS}
function Ascending: Boolean; overload;
function Ascends: Boolean; overload;
function Atomic: Boolean; overload;
function Composite: Boolean; overload;
function Decreasing: Boolean; overload;
function Decremental: Boolean; overload;
function Descending: Boolean; overload;
function Descends: Boolean; overload;
function Dropping: Boolean; overload;
function Drops: Boolean; overload;
function Growing: Boolean; overload;
function Grows: Boolean; overload;
function Increasing: Boolean; overload;
function Incremental: Boolean; overload;
function IsAscending: Boolean; overload;
function IsDescending: Boolean; overload;
function IsPlural: Boolean; overload;
function IsSingle: Boolean; overload;
function IsSingular: Boolean; overload;
function Multiple: Boolean; overload;
function Plural: Boolean; overload;
function Shrinking: Boolean; overload;
function Shrinks: Boolean; overload;
function Singleton: Boolean; overload;
function Singular: Boolean; overload;
function Startbent: Boolean; overload;
function Startminded: Boolean; overload;
function Startwise: Boolean; overload;
function Stopbent: Boolean; overload;
function Stopminded: Boolean; overload;
function Stopwise: Boolean; overload;
function Rises: Boolean; overload;
function Rising: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Returns True if the range is ordered in ascending or neutral order,
           i.e. the start value is less than or equal to the stop value.
  @note: A range with equal start and stop values is considered ascending.
         This function is logically equivalent to not Descending.
[==============================================================================}
function TRange.Ascending: Boolean; overload;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Returns True if the range does not descend, meaning the start value
           is less than or equal to the stop value.
  @note: This function is semantically equivalent to Ascending and is provided
         for readability in contexts where verb-style predicates are preferred.
[==============================================================================}
function TRange.Ascends: Boolean; overload;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean; overload;
begin
  Result := not (Self.start = Self.stop);
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
  @action: Determines whether the range is in ascending order.
  @note: Returns True if Start is less than or equal to Stop.
         Useful for iteration or conditional logic that depends on direction.
[==============================================================================}
function TRange.IsAscending: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) <= 0);
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
  <IsPlural>
  @action: Checks if the range contains more than one element.
  @note: Returns True if Start does not equal Stop.
[==============================================================================}
function TRange.IsPlural: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) <> 0);
end;

{==============================================================================]
  <IsSingle>
  @action: Determines whether the range represents a single point.
  @note: 
    - Returns True if start and stop are equal.
    - Uses a branchless equality check via XOR:
        (start xor stop) = 0
      which holds only when both values are identical.
[==============================================================================}
function TRange.IsSingle: Boolean; overload;
begin
  Result := ((Self.start xor Self.stop) = 0);
end;

{==============================================================================]
  <IsSingular>
  @action: Checks if the range contains exactly one element.
  @note: Returns True if Start equals Stop.
         Can be used to optimize operations on singleton ranges or avoid unnecessary iteration.
[==============================================================================}
function TRange.IsSingular: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Multiple>
  @action: Determines whether the range contains more than one value.
  @note: 
    - Returns True if Size > 1.
    - Represents the logical complement of Singleton.
    - Assumes Size reflects the number of discrete values within the range.
[==============================================================================}
function TRange.Multiple: Boolean; overload;
begin
  Result := (Self.Size > 1);
end;

{==============================================================================]
  <Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean; overload;
begin
  Result := (Self.start <> Self.stop);
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
  <Singleton>
  @action: Determines whether the range contains exactly one value.
  @note: 
    - Returns True if the range size is equal to 1.
    - Assumes Size is defined as the count of discrete values within [start, stop].
    - For continuous ranges, prefer equality check (start = stop) instead.
[==============================================================================}
function TRange.Singleton: Boolean; overload;
begin
  Result := (Self.Size = 1);
end;

{==============================================================================]
  <Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean; overload;
begin
  Result := (Self.start = Self.stop);
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
