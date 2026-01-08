{$IFDEF METHODS}
function Ascending: Boolean; cdecl;
function Ascends: Boolean; cdecl;
function Atomic: Boolean; cdecl;
function Composite: Boolean; cdecl;
function Descending: Boolean; cdecl;
function Descends: Boolean; cdecl;
function Decreasing: Boolean; cdecl;
function Dropping: Boolean; cdecl;
function Drops: Boolean; cdecl;
function Growing: Boolean; cdecl;
function Grows: Boolean; cdecl;
function Increasing: Boolean; cdecl;
function Plural: Boolean; cdecl;
function Shrinking: Boolean; cdecl;
function Shrinks: Boolean; cdecl;
function Singular: Boolean; cdecl;
function Rises: Boolean; cdecl;
function Rising: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascending: Boolean; cdecl;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascends: Boolean; cdecl;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean; cdecl;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean; cdecl;
begin
  Result := not (Self.start = Self.stop);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean; cdecl;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Descending>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descending: Boolean; cdecl;
begin
  Result := (Self.start >= Self.stop);
end;

{==============================================================================]
  <Descends>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descends: Boolean; cdecl;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Dropping>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Dropping: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Drops>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Drops: Boolean; cdecl;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Growing>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Growing: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Grows>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Grows: Boolean; cdecl;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Non-strict.
[==============================================================================}
function TRange.Increasing: Boolean; cdecl;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean; cdecl;
begin
  Result := (Self.start <> Self.stop);
end;

{==============================================================================]
  <Shrinking>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinking: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Shrinks>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinks: Boolean; cdecl;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean; cdecl;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <Rises>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rises: Boolean; cdecl;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Rising>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rising: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;
{$ENDIF}