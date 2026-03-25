{$IFDEF METHODS}
function PickStart: Integer; overload;
function PickStop: Integer; overload;
function PopStart: Integer; overload;
function PopStop: Integer; overload;
function PullStart: Integer; overload;
function PullStop: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <PickStart>
  @action: Returns the current start value, then advances the start boundary by
           one step if the range is not singular.
  @note: • Mutates the range by updating start after returning the current value.
         • If the range is singular (start = stop), start remains unchanged.
         • For ascending ranges:  start := start + 1 after returning current start.
         • For descending ranges: start := start - 1 after returning current start.
[==============================================================================}
function TRange.PickStart: Integer; overload;
begin
  if Self.Singular then
    Result := Self.start
  else if Self.Ascending then
    Result := Self.start.Increase
  else
    Result := Self.start.Decrease;
end;

{==============================================================================]
  <PickStop>
  @action: Returns the current stop value, then retreats the stop boundary by
           one step if the range is not singular.
  @note: • Mutates the range by updating stop after returning the current value.
         • If the range is singular (start = stop), stop remains unchanged.
         • For ascending ranges:  stop := stop - 1 after returning current stop.
         • For descending ranges: stop := stop + 1 after returning current stop.
[==============================================================================}
function TRange.PickStop: Integer; overload;
begin
  if Self.Singular then
    Result := Self.stop
  else if Self.Ascending then
    Result := Self.stop.Decrease
  else
    Result := Self.stop.Increase;
end;

{==============================================================================]
  <PopStart>
  @action: Returns the current start value, then unconditionally advances the
           start boundary by one step.
  @note: • Mutates the range by updating start after returning the current value.
         • No singular check; start is always increased (ascending) or decreased (descending).
         • May collapse or invert the range if over-applied.
[==============================================================================}
function TRange.PopStart: Integer; overload;
begin
  if Self.Ascending then
    Result := Self.start.Increase
  else
    Result := Self.start.Decrease;
end;

{==============================================================================]
  <PopStop>
  @action: Returns the current stop value, then unconditionally retreats the
           stop boundary by one step.
  @note: • Mutates the range by updating stop after returning the current value.
         • No singular check; stop is always decreased (ascending) or increased (descending).
         • May collapse or invert the range if over-applied.
[==============================================================================}
function TRange.PopStop: Integer; overload;
begin
  if Self.Ascending then
    Result := Self.stop.Decrease
  else
    Result := Self.stop.Increase;
end;

{==============================================================================]
  <PullStart>
  @action: Returns the current start value, then advances the start boundary by
           one step if the range is not singular.
  @note: • Mutates the range after returning current start.
         • If singular, start remains unchanged.
         • For ascending ranges:  start := start + 1 after returning current start.
         • For descending ranges: start := start - 1 after returning current start.
         • Equivalent to PickStart with explicit case handling.
[==============================================================================}
function TRange.PullStart: Integer; overload;
begin
  if Self.Singular then
    Exit(Self.start);
  case Self.Ascending of
    True: Result := Self.start.Increase;
    False: Result := Self.start.Decrease;
  end;
end;

{==============================================================================]
  <PullStop>
  @action: Returns the current stop value, then retreats the stop boundary by
           one step if the range is not singular.
  @note: • Mutates the range after returning current stop.
         • If singular, stop remains unchanged.
         • For ascending ranges:  stop := stop - 1 after returning current stop.
         • For descending ranges: stop := stop + 1 after returning current stop.
         • Equivalent to PickStop with explicit case handling.
[==============================================================================}
function TRange.PullStop: Integer; overload;
begin
  if Self.Singular then
    Exit(Self.stop);
  case Self.Ascending of
    True: Result := Self.stop.Decrease;
    False: Result := Self.stop.Increase;
  end;
end;
{$ENDIF}