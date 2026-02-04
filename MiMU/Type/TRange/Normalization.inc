{$IFDEF METHODS}
function Backwards: TRange;
function Forwards: TRange;
function Grab: TRange;
function HighToLow: TRange;
function HiLo: TRange;
function LoHi: TRange;
function LowToHigh: TRange;
function MaxMin: TRange; overload;
function MinMax: TRange; overload;
function Norm: TRange;
function Normal: TRange;
function Normalize: TRange;
function Normalized: TRange;
function Normally: TRange;
function Normed: TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Backwards>
  @action: Ensures range is descending (start >= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.Backwards: TRange;
var
  m: Integer;
begin
  m := Max(Self.start, Self.stop);
  Result.start := m;
  Result.stop := (Self.start + (Self.stop - m));
end;

{==============================================================================]
  <Forwards>
  @action: Ensures range is ascending (start <= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.Forwards: TRange;
var
  m: Integer;
begin
  m := Max(Self.start, Self.stop);
  Result.start := (Self.start + (Self.stop - m));
  Result.stop := m;
end;

{==============================================================================]
  <Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange.Grab: TRange;
begin
  Result := IfThen(Self.Descending, Result.Create(Self.stop, Self.start), Self);
end;

{==============================================================================]
  <HighToLow>
  @action: Ensures range is descending (start >= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.HighToLow: TRange;
var
  a, s: Integer;
begin
  a := Abs(Self.Contra);
  s := Self.Combined;
  Result.stop := ((s - a) div 2);
  Result.start := ((s + a) div 2);
end;

{==============================================================================]
  <HiLo>
  @action: Ensures range is descending (start >= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.HiLo: TRange;
var
  c, d: Integer;
begin
  d := Self.Delta;
  c := -(Ord(d > 0));
  Result.start := (Self.start + (d and c));
  Result.stop := (Self.stop - (d and c));
end;

{==============================================================================]
  <LoHi>
  @action: Ensures range is ascending (start <= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.LoHi: TRange;
var
  c, d: Integer;
begin
  d := Self.Contra;
  c := -(Ord(d > 0));
  Result.start := (Self.start - (d and c));
  Result.stop := (Self.stop + (d and c));
end;

{==============================================================================]
  <LowToHigh>
  @action: Ensures range is ascending (start <= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.LowToHigh: TRange;
var
  a, s: Integer;
begin
  a := Abs(Self.start - Self.stop);
  s := Self.Combined;
  Result.start := ((s - a) div 2);
  Result.stop := ((s + a) div 2);
end;

{==============================================================================]
  <MaxMin>
  @action: Returns a normalized descending version of the range, ensuring start >= stop.
  @note: If the current range is already descending, the function returns Self unchanged.
[==============================================================================}
function TRange.MaxMin: TRange; overload;
begin
  if Self.Descending then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <MinMax>
  @action: Returns a normalized ascending version of the range, ensuring start <= stop.
  @note: If the current range is already ascending, the function returns Self unchanged.
[==============================================================================}
function TRange.MinMax: TRange; overload;
begin
  if Self.Ascending then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Norm>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Norm: TRange;
begin
  Result := IfThen(Self.Descending, Self.Reversed, Self);
end;

{==============================================================================]
  <Normal>
  @action: XOR-swap based.
  @note: None.
[==============================================================================}
 function TRange.Normal: TRange;
begin
  Result := Self;
  if Result.Ascending then
    Exit;
  Result.start := (Result.start xor Result.stop);
  Result.stop := (Result.start xor Result.stop);
  Result.start := (Result.start xor Result.stop);
end;

{==============================================================================]
  <Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange;
begin
  Result.start := Self.Minimum;
  Result.stop := Self.Maximum;
end;

{==============================================================================]
  <Normalized>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalized: TRange;
begin
  Result.start := (Self.Combined shr 1);
  Result.stop := (Abs(Self.Contra) shr 1);
  Result.Create(Result.Contra, Result.Combined);
end;

{==============================================================================]
  <Normally>
  @action: Ord-based.
  @note: None.
[==============================================================================}
function TRange.Normally: TRange;
var
  a: TIntegerArray;
begin
  a := [Self.start, Self.stop];
  Result.Create(a[Ord(Self.Descending)], a[Ord(Self.Ascending)]);
end;

{==============================================================================]
  <Normed>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normed: TRange;
begin
  Result.Create(IfThen((Self.start < Self.stop), Self.start, Self.stop), IfThen((Self.start < Self.stop), Self.stop, Self.start));
end;
{$ENDIF}