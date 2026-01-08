{$IFDEF METHODS}
function Grab: TRange; cdecl;
function MaxMin: TRange; overload; cdecl;
function MinMax: TRange; overload; cdecl;
function Norm: TRange; cdecl;
function Normal: TRange; cdecl;
function Normalize: TRange; cdecl;
function Normalized: TRange; cdecl;
function Normally: TRange; cdecl;
function Normed: TRange; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange.Grab: TRange; cdecl;
begin
  Result := IfThen(Self.Descending, Result.Create(Self.stop, Self.start), Self);
end;

{==============================================================================]
  <MaxMin>
  @action: Returns a normalized descending version of the range, ensuring start >= stop.
  @note: If the current range is already descending, the function returns Self unchanged.
[==============================================================================}
function TRange.MaxMin: TRange; overload; cdecl;
begin
  if (Self.start > Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <MinMax>
  @action: Returns a normalized ascending version of the range, ensuring start <= stop.
  @note: If the current range is already ascending, the function returns Self unchanged.
[==============================================================================}
function TRange.MinMax: TRange; overload; cdecl;
begin
  if (Self.start < Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Norm>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Norm: TRange; cdecl;
begin
  Result := IfThen((Self.start > Self.stop), Self.Reversed, Self);
end;

{==============================================================================]
  <Normal>
  @action: XOR-swap based.
  @note: None.
[==============================================================================}
 function TRange.Normal: TRange; cdecl;
begin
  Result := Self;
  if (Result.start <= Result.stop) then
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
function TRange.Normalize: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <Normalized>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalized: TRange; cdecl;
begin
  Result.start := ((Self.start + Self.stop) shr 1);
  Result.stop := (Abs(Self.start - Self.stop) shr 1);
  Result.Create((Result.start - Result.stop), (Result.start + Result.stop));
end;

{==============================================================================]
  <Normally>
  @action: Ord-based.
  @note: None.
[==============================================================================}
function TRange.Normally: TRange; cdecl;
var
  a: TIntegerArray;
begin
  a := [Self.start, Self.stop];
  Result.Create(a[Ord(Self.start > Self.stop)], a[Ord(Self.start <= Self.stop)]);
end;

{==============================================================================]
  <Normed>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normed: TRange; cdecl;
begin
  Result.Create(IfThen((Self.start < Self.stop), Self.start, Self.stop), IfThen((Self.start < Self.stop), Self.stop, Self.start));
end;
{$ENDIF}