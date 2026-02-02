{$IFDEF METHODS}
function Flip: TRange; overload;
function Flipped: TRange; overload;
function Invert: Boolean; overload;
function Inverted: TRange; overload;
function Reverse: Boolean; overload;
function Reversed: TRange; overload;
function Reversify: TRange; overload;
function Rotate32: TRange; overload;
function Toggle: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flip>
  @action: Returns a new range with start and stop exchanged, using an XOR-swap
    sequence instead of a temporary variable.
  @note:
    - Functionally equivalent to swapping Self.start and Self.stop.
    - Relies on bitwise XOR; valid only for integral types.
    - Assumes start and stop are distinct storage locations.
    - Offers no semantic advantage over a simple swap and may reduce clarity.
[==============================================================================}
function TRange.Flip: TRange; overload;
begin
  Result.start := (Self.start xor Self.stop);
  Result.stop := (Result.start xor Self.stop);
  Result.start := (Result.start xor Result.stop);
end;

{==============================================================================]
  <Flipped>
  @action: Returns a new range with start and stop values exchanged, using
           sum–difference arithmetic instead of a temporary variable.
  @note:
    - Functionally equivalent to swapping Self.start and Self.stop.
    - Uses addition and subtraction; may overflow for large integral values.
    - Less explicit and less safe than a direct constructor-based swap.
    - No validation is performed (e.g., start <= stop).
[==============================================================================}
function TRange.Flipped: TRange; overload;
begin
  Result.start := (Self.start + Self.stop);
  Result.stop := (Result.start - Self.stop);
  Result.start := (Result.start - Result.stop)
end;

{==============================================================================]
  <Invert>
  @action: Negates both endpoints of the range in place.
  @note: This is a mutating operation. The range is reflected through the
         origin (0), mapping [start, stop] → [-start, -stop].
         The function returns True if the original range was non-zero
         (i.e. either endpoint was non-zero), and False otherwise.
         Direction and magnitude are preserved, but sign is inverted.
[==============================================================================}
function TRange.Invert: Boolean; overload;
begin
  Result := ((Self.start <> 0) or (Self.stop <> 0));
  Self.start := -Self.start;
  Self.stop := -Self.stop;
end;

{==============================================================================]
  <Inverted>
  @action: Returns a copy of the range with both endpoints negated.
  @note: This is a non-mutating operation. The resulting range is the
         reflection of the original through the origin (0), mapping
         [start, stop] → [-start, -stop].
         Direction and magnitude are preserved.
[==============================================================================}
function TRange.Inverted: TRange; overload;
begin
  Result.start := -Self.start;
  Result.stop := -Self.stop;
end;

{==============================================================================]
  <Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean; overload;
begin
  Result := Self.Plural;
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange.Reversed: TRange; overload;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;

{==============================================================================]
  <Reversify>
  @action: Returns a new range whose bounds are reversed (start and stop swapped),
    preserving the same midpoint as the original range.
  @note:
    - Functionally equivalent to exchanging Self.start and Self.stop.
    - Assumes that start and stop are symmetric endpoints of the range.
    - No validation is performed (e.g., start <= stop).
    - Uses Int64 arithmetic; extreme values may overflow when summed.
[==============================================================================}
function TRange.Reversify: TRange; overload;
var
  s: Int64;
begin
  s := (Self.start + Self.stop);
  Result.start := (s - Self.start);
  Result.stop := (s - Self.stop);
end;

{==============================================================================]
  <Rotate32>
  @action: Rotates the 64-bit value left by 32 bits.
  @note: Equivalent to swapping the high and low 32-bit words.
[==============================================================================}
function TRange.Rotate32: TRange; overload;
var
  c: Int64;
begin
  c := Int64(Self);
  Int64(Result) := ((c shl 32) or (c shr 32));
end;

{==============================================================================]
  <Toggle>
  @action: Returns a new range with its start and stop values exchanged.
  @note:
    - Purely swaps the range bounds.
    - No arithmetic or bitwise operations involved.
    - Clearer and safer than XOR- or sum-based swap implementations.
    - No validation is performed (e.g., start <= stop).
[==============================================================================}
function TRange.Toggle: TRange; overload;
begin
  Result := TRange.Construct(Self.stop, Self.start);
end;
{$ENDIF}