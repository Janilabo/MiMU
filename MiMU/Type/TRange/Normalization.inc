{$IFDEF METHODS}
function Backwards: TRange; overload;
function Forwards: TRange; overload;
function Grab: TRange; overload;
function HighToLow: TRange; overload;
function HiLo: TRange; overload;
function LoHi: TRange; overload;
function LowToHigh: TRange; overload;
function MaxMin: TRange; overload;
function MinMax: TRange; overload;
function Norm: TRange; overload;
function Normal: TRange; overload;
function Normalization: TRange; overload;
function Normalize: TRange; overload;
function Normalized: TRange; overload;
function Normalizify: Boolean; overload;
function Normally: TRange; overload;
function Normed: TRange; overload;
function ToNormalized: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Backwards>
  @action: Ensures range is descending (start >= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.Backwards: TRange; overload;
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
function TRange.Forwards: TRange; overload;
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
function TRange.Grab: TRange; overload;
begin
  Result := IfThen(Self.Descending, Result.Create(Self.stop, Self.start), Self);
end;

{==============================================================================]
  <HighToLow>
  @action: Ensures range is descending (start >= stop)
  @note: Uses branch-free arithmetic to swap if needed
[==============================================================================}
function TRange.HighToLow: TRange; overload;
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
function TRange.HiLo: TRange; overload;
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
function TRange.LoHi: TRange; overload;
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
function TRange.LowToHigh: TRange; overload;
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
function TRange.Norm: TRange; overload;
begin
  Result := IfThen(Self.Descending, Self.Reversed, Self);
end;

{==============================================================================]
  <Normal>
  @action: XOR-swap based.
  @note: None.
[==============================================================================}
 function TRange.Normal: TRange; overload;
begin
  Result := Self;
  if Result.Ascending then
    Exit;
  Result.start := (Result.start xor Result.stop);
  Result.stop := (Result.start xor Result.stop);
  Result.start := (Result.start xor Result.stop);
end;

{==============================================================================]
  <Normalization>
  @action: Returns a new range with endpoints reordered so that `start <= stop`.
  @note:
    - If the range is already ascending (`start <= stop`), it is returned unchanged.
    - If the range is descending (`start > stop`), `start` and `stop` are swapped.
    - Uses bitwise operations for a branchless, efficient conditional swap.
    - Useful for operations that require a guaranteed ascending range, 
      such as calculating size, iteration, or partitioning.
[==============================================================================}
function TRange.Normalization: TRange; overload;
var
  m: Integer;
begin
  m := -Ord(Self.start > Self.stop);
  Result.start := (Self.start xor ((Self.start xor Self.stop) and m));
  Result.stop := (Self.stop xor ((Self.start xor Self.stop) and m));
end;

{==============================================================================]
  <Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange; overload;
begin
  Result.start := Self.Minimum;
  Result.stop := Self.Maximum;
end;

{==============================================================================]
  <Normalized>
  @action: Normalize to ascending range (start <= stop)
  @note: Swaps start/stop if descending; otherwise returns self
[==============================================================================}
function TRange.Normalized: TRange; overload;
begin
  if Self.Descending then
    Result := TRange.Construct(Self.stop, Self.start)
  else
    Result := Self;
end;

{==============================================================================]
  <Normalizify>
  @action: Checks if range is descending and normalizes it by swapping bounds.
  @note: Returns True if swap occurred; otherwise False.
[==============================================================================}
function TRange.Normalizify: Boolean; overload;
begin
  Result := Self.Descending;
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Normally>
  @action: Ord-based.
  @note: None.
[==============================================================================}
function TRange.Normally: TRange; overload;
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
function TRange.Normed: TRange; overload;
begin
  Result.Create(IfThen((Self.start < Self.stop), Self.start, Self.stop), IfThen((Self.start < Self.stop), Self.stop, Self.start));
end;

{==============================================================================]
  <ToNormalized>
  @action: Produces a normalized (canonical) representation of the range, ensuring
           consistent ordering and internal encoding regardless of the original
           start/stop configuration.
           The transformation reconstructs the range from its encoded form using
           Combined and Contra, yielding a stable [start, stop] pair.
  @note:
    - Normalization goal:
        * Enforces a canonical representation where:
            start ≤ stop
        * Eliminates ambiguity from reversed or non-canonical inputs.
    - Encoding details:
        * Combined and Contra represent a packed form of the range:
            - Combined encodes aggregate boundary information
            - Contra encodes directional / differential information
        * Reconstruction:
            start := Combined shr 1
            stop  := Abs(Contra) shr 1
        * Final Create call rehydrates the range using the derived
          canonical components.
    - Bit-level behavior:
        * Right shift (shr 1) implies values are stored with a scaling
          factor (e.g. doubled or tagged representation).
        * Abs ensures stop is always non-negative before normalization.
    - Complexity:
        * O(1), purely arithmetic and bitwise operations.
    - Characteristics:
        * Non-destructive; returns a new normalized instance.
        * Idempotent:
            ToNormalized(ToNormalized(R)) = ToNormalized(R)
    - Use cases:
        * Equality comparisons (e.g. Coequal with strictly = False)
        * Canonical storage or hashing
        * Preprocessing before range algebra operations
    - Assumptions:
        * Combined and Contra are internally consistent encodings.
        * Create correctly reconstructs a valid range from these values.
[==============================================================================}
function TRange.ToNormalized: TRange; overload;
begin
  Result.start := (Self.Combined shr 1);
  Result.stop := (Abs(Self.Contra) shr 1);
  Result.Create(Result.Contra, Result.Combined);
end;
{$ENDIF}
