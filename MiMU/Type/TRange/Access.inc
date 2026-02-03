{$IFDEF METHODS}
function Access(const index: Integer = 0): Integer; overload;
function AsValue(const index: Integer = 0): Integer; overload;
function At(const index: Integer = 0): Integer; overload;
function AtIndex(const index: Integer = 0): Integer; overload;
function AtPos(const index: Integer = 0): Integer; overload;
function AtPosition(const index: Integer = 0): Integer; overload;
function Elem(const index: Integer = 0): Integer; overload;
function Element(const index: Integer = 0): Integer; overload;
function Entry(const index: Integer = 0): Integer; overload;
function Fetch(const index: Integer = 0): Integer; overload;
function Get(const index: Integer = 0): Integer; overload;
function GetValue(const index: Integer = 0): Integer; overload;
function Lookup(const index: Integer = 0): Integer; overload;
function Map(const index: Integer = 0): Integer; overload;
function Member(const index: Integer = 0): Integer; overload;
function Nth(const index: Integer = 0): Integer; overload;
function Term(const index: Integer = 0): Integer; overload;
function ToValue(const index: Integer = 0): Integer; overload;
function ValueAt(const index: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Access>
  @action: Returns the value at the specified zero-based index relative to the range start,
           resolving direction via a Boolean-indexed lookup table.
  @note: Index defaults to 0, which returns Start.
         Direction is determined from Descending and converted to an ordinal (0 or 1) to index the constant array `d`,
	 where 0 maps to +1 (ascending) and 1 maps to -1 (descending).
	 This implementation avoids conditional branching. No bounds checking is performed;
	 the caller must ensure the index is within the logical range limits.
[==============================================================================}
function TRange.Access(const index: Integer = 0): Integer;
const
  d: array[0..1] of Integer = (1, -1);
begin
  Result := (Self.start + (index * d[Ord(Self.Descending)]));
end;

{==============================================================================]
  <AsValue>
  @action: Returns the value at the specified zero-based index relative to the range start
           using a branchless direction multiplier derived from Descending.
  @note: Index defaults to 0, which returns Start. Direction is computed as ((Ord(Descending) * -2) + 1),
         producing +1 when not descending and -1 when descending.
	 Functionally equivalent to other index-based accessors but avoids conditional branching.
	 No bounds checking is performed; the caller is responsible for ensuring the index is within the valid range extent.
[==============================================================================}
function TRange.AsValue(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * ((Ord(Self.Descending) * -2) + 1)));
end;

{==============================================================================]
  <At>
  @action: Returns the value at the given zero-based offset from Start,
           moving forward for ascending ranges and backward for descending ranges.
  @note: No bounds checking is performed.
         Index values outside the range extent will extrapolate beyond Stop.
         Equivalent to direct offset addressing.
[==============================================================================}
function TRange.At(const index: Integer = 0): Integer; overload;
begin
  if Self.Ascending then
    Result := (Self.start + index)
  else
    Result := (Self.start - index);
end;

{==============================================================================]
  <AtIndex>
  @action: Returns the value at the specified zero-based index relative to the range start,
           adjusting for ascending or descending direction.
  @note: Index defaults to 0, which returns Start. Direction is determined by Ascending,
         and translated into a +1 or -1 step using IfThen.
         No bounds checking is performed;
	 the caller is responsible for ensuring the index lies within the valid range extent.
[==============================================================================}
function TRange.AtIndex(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * (IfThen(Self.Ascending, 1, -1))));
end;

{==============================================================================]
  <AtPos>
  @action: Computes the value at the specified zero-based index relative to the range start
           using a branchless direction multiplier derived from Descending.
  @note: Index defaults to 0, returning Start. Direction is computed as
         (1 - (2 * Ord(Descending))), yielding +1 for ascending and -1 for descending.
	 This avoids conditional branching. No validation of index bounds is performed.
[==============================================================================}
function TRange.AtPos(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * (1 - (2 * Ord(Self.Descending)))));
end;

{==============================================================================]
  <AtPosition>
  @action: Returns the value at the specified zero-based index relative to the range start
           using a bit-shift–based branchless direction calculation.
  @note: Index defaults to 0, returning Start. Direction is computed as
         (1 - (Ord(Descending) shl 1)), producing +1 when not descending and -1 when descending.
         Functionally equivalent to AtPos but uses a shift instead of multiplication.
	 No bounds enforcement is performed.
[==============================================================================}
function TRange.AtPosition(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * (1 - (Ord(Self.Descending) shl 1))));
end;

{==============================================================================]
  <Elem>
  @action: Returns the value at the given zero-based offset from Start,
           using the sign of the range direction.
  @note: Direction is determined by (Stop - Start).
         No bounds checking is performed.
[==============================================================================}
function TRange.Elem(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (Sign(Self.stop - Self.start) * index));
end;

{==============================================================================]
  <Element>
  @action: Returns the element at the given index, wrapping the index
           within the range size.
  @note: Index is taken modulo Size, allowing cyclic access.
         Negative indices are supported.
         Direction is respected (ascending or descending).
[==============================================================================}
function TRange.Element(const index: Integer = 0): Integer; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  i := (index mod s);
  if (i < 0) then
    i := (i + s);
  if Self.Descending then
    Result := (Self.start - i)
  else
    Result := (Self.start + i);
end;

{==============================================================================]
  <Entry>
  @action: Returns the value at the given offset from Start using
           bitwise arithmetic to account for direction.
  @note: Uses XOR and ordinal direction for branch-free computation.
         No bounds checking is performed.
[==============================================================================}
function TRange.Entry(const index: Integer = 0): Integer; overload;
var
  m: Integer;
begin
  m := -Ord(Self.Descending);
  Result := (Self.start + ((index xor m) - m));
end;

{==============================================================================]
  <Fetch>
  @action: Returns the value at the given offset from Start,
           explicitly branching on range direction.
  @note: Uses explicit control flow rather than expressions.
         No bounds checking is performed.
[==============================================================================}
function TRange.Fetch(const index: Integer = 0): Integer; overload;
label 
  forward, backward;
begin
  if Self.Ascending then
    goto forward
  else
    goto backward;   
  forward:
  Result := (Self.start + index);
  Exit;
  backward:
  Result := (Self.start - index);
end;

{==============================================================================]
  <Get>
  @action: Returns the value at the given offset from Start using
           a conditional multiplier based on direction.
  @note: Uses IfThen() for direction selection.
         No bounds checking is performed.
[==============================================================================}
function TRange.Get(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (IfThen(Self.Descending, -1, 1) * index));
end;

{==============================================================================]
  <GetValue>
  @action: Returns the value at the specified zero-based index relative to the range start,
           deriving the step direction from the Descending flag using ordinal Boolean arithmetic.
  @note: Index defaults to 0, which returns Start. The direction multiplier is computed without branching: 
         when Descending = False, the expression evaluates to +1; 
         when Descending = True, it evaluates to -1. 
         This implementation avoids conditional statements but may be less immediately readable than a simple if-based approach. 
         No bounds checking is performed; the caller must ensure the index lies within the valid range extent.
[==============================================================================}
function TRange.GetValue(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * (Ord(not Self.Descending) - Ord(Self.Descending))));
end;

{==============================================================================]
  <Lookup>
  @action: Returns the value at the specified zero-based index relative to the range start,
           using a precomputed direction lookup based on Ascending.
  @note: Index defaults to 0, which returns Start. Direction is resolved via a Boolean-indexed constant array `d`,
         where False maps to -1 and True maps to +1, eliminating conditional branching.
	 This assumes Ascending accurately reflects the range direction. No bounds validation is performed;
	 the caller is responsible for ensuring the index lies within the valid range extent.
[==============================================================================}
function TRange.Lookup(const index: Integer = 0): Integer; overload;
const
  d: array[Boolean] of Integer = (-1, 1);
begin
  Result := (Self.start + (index * d[Self.Ascending]));
end;

{==============================================================================]
  <Map>
  @action: Translates a zero-based index into its corresponding value within the range,
           applying direction derived from the Descending flag.
  @note: Index defaults to 0, which returns Start.
         The direction multiplier is computed branchlessly as (-(Ord(Descending) shl 1) + 1),
	 yielding +1 when Descending = False and -1 when Descending = True.
	 Equivalent to other index-to-value implementations but expressed using shift-based Boolean arithmetic.
	 No bounds validation is performed; the caller must ensure the index is within the logical range limits.
[==============================================================================}
function TRange.Map(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * (-(Ord(Self.Descending) shl 1) + 1)));
end;

{==============================================================================]
  <Member>
  @action: Returns the value at the given offset from Start using
           conditional selection on range direction.
  @note: Expressed using IfThen() with explicit branch semantics.
         No bounds checking is performed.
[==============================================================================}
function TRange.Member(const index: Integer = 0): Integer; overload;
begin
  Result := IfThen(Self.Ascending, (Self.start + index), (Self.start - index));
end;

{==============================================================================]
  <Nth>
  @action: Returns the N-th value from Start, respecting range direction,
           using ordinal arithmetic.
  @note: Direction is encoded via Ord(not Descending).
         No bounds checking is performed.
[==============================================================================}
function TRange.Nth(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + ((Ord(not Self.Descending) * 2) - 1) * index);
end;

{==============================================================================]
  <Term>
  @action: Returns the value at the specified zero-based index within the range,
           calculating direction dynamically from the difference between Stop and Start.
  @note: Index defaults to 0, which returns Start. Direction is computed using ordinal comparison:
         +1 if Stop > Start, -1 if Stop < Start, and 0 if Start = Stop (degenerate range).
	 This approach allows the range to determine its direction automatically without relying on an Ascending/Descending flag.
	 No bounds checking is performed; the caller must ensure the index is within the logical range extent.
[==============================================================================}
function TRange.Term(const index: Integer = 0): Integer; overload;
var
  d: Integer;
begin
  d := (Self.stop - Self.start);
  Result := (Self.start + (index * (Ord(d > 0) - Ord(d < 0))));
end;

{==============================================================================]
  <ToValue>
  @action: Returns the value at the specified zero-based index relative to the range start,
           determining direction dynamically from the sign of (Stop - Start).
  @note: Index defaults to 0, which returns Start. Direction is computed using Sign(Stop - Start),
          yielding +1 for ascending ranges, -1 for descending ranges, and 0 when Start equals Stop.
	  In the degenerate case where Start = Stop, the result will always equal Start regardless of Index.
	  No bounds checking is performed; the caller must ensure the index is within the logical range length.
[==============================================================================}
function TRange.ToValue(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * Sign(Self.stop - Self.start)));
end;

{==============================================================================]
  <ValueAt>
  @action: Returns the value at a specified index from the start of the range, accounting for ascending or descending order.
  @note: Index defaults to 0. The method assumes the caller ensures the index stays within valid range bounds. Works for both ascending and descending ranges.
[==============================================================================}
function TRange.ValueAt(const index: Integer = 0): Integer; overload;
begin
  case Self.Descending of
    False: Result := (start + index);
    True: Result := (start - index);
  end;
end;
{$ENDIF}
