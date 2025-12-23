{$IFDEF METHODS}
function Normed: TRange; 
function Norm: TRange; 
function Normal: TRange;
function Normally: TRange; 
function Normalize: TRange; 
function Normalized: TRange; 
function MinMax: TRange; overload;
function MaxMin: TRange; overload;
function Grab: TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Normed>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normed: TRange;
begin
  Result.Create(IfThen((Self.start < Self.stop), Self.start, Self.stop), IfThen((Self.start < Self.stop), Self.stop, Self.start));
end;

{==============================================================================]
  <Norm>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Norm: TRange;
begin
  Result := IfThen((Self.start > Self.stop), Self.Reversed, Self);
end;

{==============================================================================]
  <Normal>
  @action: XOR-swap based.
  @note: None.
[==============================================================================}
 function TRange.Normal: TRange;
begin
  Result := Self;
  if (Result.start <= Result.stop) then
    Exit;
  Result.start := (Result.start xor Result.stop);
  Result.stop := (Result.start xor Result.stop);
  Result.start := (Result.start xor Result.stop);
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
  Result.Create(a[Ord(Self.start > Self.stop)], a[Ord(Self.start <= Self.stop)]);
end;

{==============================================================================]
  <Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <Normalized>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalized: TRange;
begin
  Result.start := ((Self.start + Self.stop) shr 1);
  Result.stop := (Abs(Self.start - Self.stop) shr 1);
  Result.Create((Result.start - Result.stop), (Result.start + Result.stop));
end;

{==============================================================================]
  <MinMax>
  @action: Returns a normalized ascending version of the range, ensuring start <= stop.
  @note: If the current range is already ascending, the function returns Self unchanged.
[==============================================================================}
function TRange.MinMax: TRange; overload;
begin
  if (Self.start < Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <MaxMin>
  @action: Returns a normalized descending version of the range, ensuring start >= stop.
  @note: If the current range is already descending, the function returns Self unchanged.
[==============================================================================}
function TRange.MaxMin: TRange; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
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
{$ENDIF}