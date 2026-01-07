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
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascending: Boolean;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
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
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Descending>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descending: Boolean;
begin
  Result := (Self.start >= Self.stop);
end;

{==============================================================================]
  <Descends>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descends: Boolean;
begin
  Result := not (Self.start < Self.stop);
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
  Result := not (Self.start > Self.stop);
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