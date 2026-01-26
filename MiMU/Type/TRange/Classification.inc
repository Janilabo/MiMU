{$IFDEF METHODS}
function Ascending: Boolean;
function Ascends: Boolean;
function Atomic: Boolean;
function Composite: Boolean;
function Descending: Boolean;
function Descends: Boolean;
function Decreasing: Boolean;
function Dropping: Boolean;
function Drops: Boolean;
function Growing: Boolean;
function Grows: Boolean;
function Increasing: Boolean;
function IsAscending: Boolean;
function IsDescending: Boolean;
function IsPlural: Boolean;
function IsSingular: Boolean;
function Plural: Boolean;
function Shrinking: Boolean;
function Shrinks: Boolean;
function Singular: Boolean;
function Rises: Boolean;
function Rising: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Returns True if the range is ordered in ascending or neutral order,
           i.e. the start value is less than or equal to the stop value.
  @note: A range with equal start and stop values is considered ascending.
         This function is logically equivalent to not Descending.
[==============================================================================}
function TRange.Ascending: Boolean;
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
function TRange.Ascends: Boolean;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean;
begin
  Result := not (Self.start = Self.stop);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean;
begin
  Result := ((Self.start - Self.stop) > -1);
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the range is ordered in strictly descending order,
           i.e. the start value is greater than the stop value.
  @note: A range with equal start and stop values is not considered descending.
         This function is logically equivalent to not Ascending.
[==============================================================================}
function TRange.Descending: Boolean;
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
function TRange.Descends: Boolean;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Dropping>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Dropping: Boolean;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Drops>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Drops: Boolean;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Growing>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Growing: Boolean;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Grows>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Grows: Boolean;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Non-strict.
[==============================================================================}
function TRange.Increasing: Boolean;
begin
  Result := ((Self.start - Self.stop) < 1);
end;

{==============================================================================]
  <IsAscending>
  @action: Determines whether the range is in ascending order.
  @note: Returns True if Start is less than or equal to Stop.
         Useful for iteration or conditional logic that depends on direction.
[==============================================================================}
function TRange.IsAscending: Boolean;
begin
  Result := ((Self.start - Self.stop) <= 0);
end;

{==============================================================================]
  <IsDescending>
  @action: Determines whether the range is in descending order.
  @note: Returns True if Start is greater than Stop.
         Useful for iteration or conditional logic that depends on direction.
[==============================================================================}
function TRange.IsDescending: Boolean;
begin
  Result := ((Self.start - Self.stop) > 0);
end;

{==============================================================================]
  <IsPlural>
  @action: Checks if the range contains more than one element.
  @note: Returns True if Start does not equal Stop.
[==============================================================================}
function TRange.IsPlural: Boolean;
begin
  Result := ((Self.start - Self.stop) <> 0);
end;

{==============================================================================]
  <IsSingular>
  @action: Checks if the range contains exactly one element.
  @note: Returns True if Start equals Stop.
         Can be used to optimize operations on singleton ranges or avoid unnecessary iteration.
[==============================================================================}
function TRange.IsSingular: Boolean;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean;
begin
  Result := (Self.start <> Self.stop);
end;

{==============================================================================]
  <Shrinking>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinking: Boolean;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Shrinks>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinks: Boolean;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <Rises>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rises: Boolean;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Rising>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rising: Boolean;
begin
  Result := (Self.start < Self.stop);
end;
{$ENDIF}