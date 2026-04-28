{$IFDEF METHODS}
function Antipode: TRange; overload;
function Flip: TRange; overload;
function Flipped: TRange; overload;
function Invert: Boolean; overload;
function Inverted: TRange; overload;
function Reconstruct: TRange; overload;
function Reverse: Boolean; overload;
function Reversed: TRange; overload;
function Reversely: TRange; overload;
function Reversified: TRange; overload;
function Reversify: TRange; overload;
function Reversion: TRange; overload;
function Revert: TRange; overload;
function Reverted: TRange; overload;
function Rotate32: TRange; overload;
function Toggle: TRange; overload;
function Turnaround: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Antipode>
  @action: Returns a TRange where the start and stop boundaries are 
           diametrically swapped.
  @note: 
    - Implementation: Employs an 'absolute' memory overlay, mapping the 
      TRange record to a two-element integer array for a zero-cost swap.
    - Efficiency: Extremely stable and high-performance; compiles to 
      direct CPU move instructions without temporary variable overhead.
    - Semantic: Represents the "Polar Opposite" orientation of the range, 
      effectively inverting its direction while preserving its magnitude.
[==============================================================================}
function TRange.Antipode: TRange; overload;
var
  s: array[0..1] of Integer absolute Self;
  r: array[0..1] of Integer absolute Result;
begin
  r[0] := s[1];
  r[1] := s[0];
end;

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
  <Reconstruct>
  @action: Generates a new TRange with swapped boundaries, effectively 
           inverting the direction of the original.
  @note: 
    - Logic: Re-passes the existing 'stop' and 'start' through the primary 
      'Construct' logic, ensuring all internal validation or normalization 
      is applied to the new orientation.
    - Semantic: Unlike 'Antipode' (which implies a raw memory swap), 
      'Reconstruct' implies a formal re-declaration of the range's identity.
    - Result: A TRange where the destination becomes the origin.
[==============================================================================}
function TRange.Reconstruct: TRange; overload;
begin
  Result := TRange.Construct(Self.stop, Self.start);
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
  <Reversely>
  @action: Swaps the start and stop boundaries of the range using bitwise 
           packing and shifting.
  @note: 
    - Logic: Packs the two 32-bit integers into a single 64-bit register (Int64), 
      performs a 32-bit swap via bit-shifting, and unpacks the results.
    - Style: An "Atomic-style" swap that treats the range boundaries as a 
      single contiguous memory block.
    - Result: If the range was (0..10), it becomes (10..0).
[==============================================================================}
function TRange.Reversely: TRange; overload;
var
  q: Int64;
begin
  q := (Int64(UInt32(Self.start)) shl 32) or UInt32(Self.stop);
  q := ((q shr 32) or (q shl 32));
  Result.start := Integer(q shr 32);
  Result.stop := Integer(q and $FFFFFFFF);
end;

{==============================================================================]
  <Reversified>
  @action: Re-anchors the range boundaries by calculating the stop point 
           relative to the original distance.
  @note: 
    - Logic: Effectively performs a boundary flip [Result.Stop = Self.Start] 
      but does so via an algebraic expansion (Self.stop - (Self.stop - Self.start)).
    - Contrast: While 'Reversely' is mechanical/bitwise, 'Reversified' is 
      arithmetic. 
    - Result: Mathematically identical to a swap, ensuring the range's 
      absolute distance remains constant while the direction is inverted.
[==============================================================================}
function TRange.Reversified: TRange; overload;
begin
  Result.start := Self.stop;
  Result.stop := (Self.stop - (Self.stop - Self.start));
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
  <Reversion>
  @action: Returns a new TRange object representing the **reverse of the current range**.
           The new range starts at the original Stop and ends at the original Start,
           preserving the step direction.
  @note: For ascending ranges, the returned range counts down from Stop to Start.
         For descending ranges, the returned range counts up from Stop to Start.
         The size of the range remains the same as the original.
[==============================================================================}
function TRange.Reversion: TRange; overload;
begin
  Result := Range((Self.start + ((Self.Size - 1) * IfThen(Self.Ascending, 1, -1))), Self.start);
end;

{==============================================================================]
  <Revert>
  @action: Returns a new TRange object representing the **reversed range**,
           calculated from the original Start and Size. The new range starts
           at the original Stop and ends at the original Start, preserving
           the original step direction.
  @note: This differs from Reversion in that it explicitly computes the
         Start and Stop values using the Size and Ascending flag, rather
         than using the Range helper. For ascending ranges, the returned
         range counts down; for descending ranges, it counts up.
[==============================================================================}
function TRange.Revert: TRange; overload;
var
  s: Integer;
  a: Boolean;
begin
  s := (Self.Size - 1);
  a := Self.Ascending;
  Result.start := (Self.start + (s * IfThen(a, 1, -1)));
  Result.stop := IfThen(a, (Result.start - s), (Result.start + s));
end;

{==============================================================================]
  <Masked>
  @action: Returns a new range with the order of endpoints reversed.
  @note:
    - If the original range is ascending (`start < stop`), the result is descending.
    - If the original range is descending (`start > stop`), the result is ascending.
    - The size of the range remains the same; only the order of `start` and `stop` is inverted.
    - Useful when you need a range in the opposite order without modifying the original.
[==============================================================================}
function TRange.Reverted: TRange; overload;
var
  d, m: Integer;
begin
  d := (Self.start - Self.stop);
  m := (d shr 31);
  Result.start := (Self.stop + (d and m));
  Result.stop := (Self.start - (d and m));
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
  @action: Inverts the range boundaries by applying the calculated span 
           differentially to both the start and stop points.
  @note: 
    - Logic: Determines the absolute distance (s), then shifts the origin 
      forward and the destination backward by that amount. 
    - Character: Unlike 'Antipode' (which is a memory swap), 'Toggle' is a 
      "Relational" inversion. It treats the boundaries as points in motion 
      rather than static data fields.
    - Result: Effectively swaps start and stop, but does so through algebraic 
      displacement rather than direct assignment.
[==============================================================================}
function TRange.Toggle: TRange; overload;
var
  s: Integer;
begin
  if Self.Ascending then
  begin
    s := (Self.stop - Self.start);
    Result.start := (Self.start + s);
    Result.stop := (Self.stop - s);
  end else
  begin
    s := (Self.start - Self.stop);
    Result.start := (Self.start - s);
    Result.stop := (Self.stop + s);
  end;
end;

{==============================================================================]
  <Turnaround>
  @action: Returns a new TRange representing the same interval
           with its direction reversed.
  @note: - The new Start becomes the original terminal value
           (computed via Span).
         - The new Stop becomes the original Start.
         - Assumes unit step (±1).
         - Works correctly for negative Start values.
[==============================================================================}
function TRange.Turnaround: TRange; overload;
begin
  if Self.Ascending then
    Result.start := (Self.start + Self.Span)
  else
    Result.start := (Self.start - Self.Span);
  Result.stop := Self.start;
end;
{$ENDIF}
