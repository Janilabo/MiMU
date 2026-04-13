{$IFDEF METHODS}
function ConsumeStart: Integer; overload;
function ConsumeStop: Integer; overload;
function PickStart: Integer; overload;
function PickStop: Integer; overload;
function PopStart: Integer; overload;
function PopStop: Integer; overload;
function PullStart: Integer; overload;
function PullStop: Integer; overload;
function SStart: Integer; overload;
function SStop: Integer; overload;
function StartAtStop: TIntegerArray; overload;
function StartStep: Integer; overload;
function Startward: Integer; overload;
function Startwarded: TIntegerArray; overload;
function StepStart: Integer; overload;
function StepStop: Integer; overload;
function StopAtStart: TIntegerArray; overload;
function StopStep: Integer; overload;
function Stopward: Integer; overload;
function Stopwarded: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ConsumeStart>
  @action: Advances the start boundary in the current direction and returns it.
  @note: Consumes one element from the beginning of the range (direction-aware).
[==============================================================================}
function TRange.ConsumeStart: Integer; overload;
begin
  Result := Self.start.Increase(Self.Direction);
end;

{==============================================================================]
  <ConsumeStop>
  @action: Moves the stop boundary opposite to the current direction and returns it.
  @note: Consumes one element from the end of the range (symmetric to ConsumeStart).
[==============================================================================}
function TRange.ConsumeStop: Integer; overload;
begin
  Result := Self.stop.Decrease(Self.Direction);
end;

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

{==============================================================================]
  <SStart>
  @action: Steps `start` one unit toward `stop` and returns the new value.
  @note: If `start` = `stop` (singular range), returns `start` unchanged.
[==============================================================================}
function TRange.SStart: Integer; overload;
begin
  case Self.start.Compare(Self.stop) of
    0: Result := Self.start;
	-1: Result := Self.start.Increase;
	1: Result := Self.start.Decrease;
  end;
end;

{==============================================================================]
  <SStop>
  @action: Steps `stop` one unit toward `start` and returns the new value.
  @note: If `start` = `stop` (singular range), returns `stop` unchanged.
[==============================================================================}
function TRange.SStop: Integer; overload;
begin
  case Self.stop.Compare(Self.start) of
    0: Result := Self.stop;
	-1: Result := Self.stop.Increase;
	1: Result := Self.stop.Decrease;
  end;
end;

{==============================================================================]
  <StartAtStop>
  @action: Materializes the range by consuming `start` toward `stop`
           one step at a time, returning values in natural order.
  @note: DESTRUCTIVE — mutates Self directly. Final element Self.stop
         is written after the loop to avoid an extra SStart call.
[==============================================================================}
function TRange.StartAtStop: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  i := 0;
  while (Self.start <> Self.stop) do
    Result[i.Increase] := Self.SStart;
  Result[i] := Self.stop;
end;

{==============================================================================]
  <StartStep>
  @action: Advances `start` by one step in the current direction and returns
           the updated value.
  @note: Step size and sign are determined by `Self.Direction`. This method
         mutates the range by incrementing `start` toward `stop`.
[==============================================================================}
function TRange.StartStep: Integer; overload;
begin
  Self.start := (Self.start + Self.Direction);
  Result := Self.start;
end;

{==============================================================================]
  <Startward>
  @action: Steps `stop` one unit toward `start` and returns the new value.
  @note: If `start` = `stop` (singular range), returns `stop` unchanged.
[==============================================================================}
function TRange.Startward: Integer; overload;
begin
  if not Self.Singular then
    Dec(Self.stop, Self.Direction);
  Result := Self.stop;
end;

{==============================================================================]
  <Startwarded>
  @action: Generates an integer sequence starting from `stop`, progressing
           backward toward `start` using the range direction, and returns it
           as an array. After generation, updates `stop` to match `start`.
  @note: Direction is determined by `Self.Direction`. The sequence length is
         defined by `Self.Size`. This method mutates the range by collapsing
         `stop` onto `start`, effectively consuming the backward span.
[==============================================================================}
function TRange.Startwarded: TIntegerArray; overload;
var
  i, d: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  d := Self.Direction;
  for i := 0 to High(Result) do
  begin
    p^ := (Self.stop - (i * d));
    Inc(p);
  end;
  Self.stop := Self.start;
end;

{==============================================================================]
  <StepStart>
  @action: Steps the start boundary in the current direction and returns it.
  @note: Moves the start without implying consumption semantics (simple traversal step).
[==============================================================================}
function TRange.StepStart: Integer; overload;
begin
  Result := Self.start.Increment(Self.Direction);
end;

{==============================================================================]
  <StepStop>
  @action: Steps the stop boundary opposite to the current direction and returns it.
  @note: Moves the stop without implying consumption semantics (symmetric traversal step).
[==============================================================================}
function TRange.StepStop: Integer; overload;
begin
  Result := Self.stop.Decrement(Self.Direction);
end;

{==============================================================================]
  <StopAtStart>
  @action: Materializes the range by consuming `stop` toward `start`
           one step at a time, returning values in natural order.
  @note: DESTRUCTIVE — mutates Self directly. Final element Self.start
         is written after the loop to avoid an extra SStop call.
[==============================================================================}
function TRange.StopAtStart: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  i := 0;
  while (Self.stop <> Self.start) do
    Result[i.Increase] := Self.SStop;
  Result[i] := Self.start;
end;

{==============================================================================]
  <StopStep>
  @action: Retreats `stop` by one step in the current direction and returns
           the updated value.
  @note: Step size and sign are determined by `Self.Direction`. This method
         mutates the range by decrementing `stop` toward `start`.
[==============================================================================}
function TRange.StopStep: Integer; overload;
begin
  Self.stop := (Self.stop - Self.Direction);
  Result := Self.stop;
end;

{==============================================================================]
  <Stopward>
  @action: Steps `start` one unit toward `stop` and returns the new value.
  @note: If `start` = `stop` (singular range), returns `start` unchanged.
[==============================================================================}
function TRange.Stopward: Integer; overload;
begin
  if not Self.Singular then
    Inc(Self.start, Self.Direction);
  Result := Self.start;
end;

{==============================================================================]
  <Stopwarded>
  @action: Generates an integer sequence starting from `start`, progressing
           toward `stop` using the range direction, and returns it as an array.
           After generation, updates `start` to match `stop`.
  @note: Direction is determined by `Self.Direction`. The sequence length is
         defined by `Self.Size`. This method mutates the range by collapsing
         `start` onto `stop`, effectively consuming the forward span.
[==============================================================================}
function TRange.Stopwarded: TIntegerArray; overload;
var
  i, d: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  d := Self.Direction;
  for i := 0 to High(Result) do
  begin
    p^ := (Self.start + (i * d));
    Inc(p);
  end;
  Self.start := Self.stop;
end;
{$ENDIF}