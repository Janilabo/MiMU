{$IFDEF METHODS}
function Access(const index: Integer = 0): Integer; overload;
function Access(const ID: TIntegerArray): TIntegerArray; overload;
function AsValue(const index: Integer = 0): Integer; overload;
function At(const index: Integer = 0): Integer; overload;
function AtIndex(const index: Integer = 0): Integer; overload;
function Ascender(const mIndex: Integer = 0): Integer; overload;
function AtPos(const index: Integer = 0): Integer; overload;
function AtPosition(const index: Integer = 0): Integer; overload;
function Derive(const index: Integer = 0): Integer; overload;
function Descender(const mIndex: Integer = 0): Integer; overload;
function Elem(const index: Integer = 0): Integer; overload;
function Element(const index: Integer = 0): Integer; overload;
function Entry(const index: Integer = 0): Integer; overload;
function Evaluate(const index: Integer = 0): Integer; overload;
function Fetch(const index: Integer = 0): Integer; overload;
function Get(const index: Integer = 0): Integer; overload;
function GetValue(const index: Integer = 0): Integer; overload;
function Lookup(const index: Integer = 0): Integer; overload;
function Map(const index: Integer = 0): Integer; overload;
function Member(const index: Integer = 0): Integer; overload;
function Node(const index: Integer = 0): Integer; overload;
function Nth(const index: Integer = 0): Integer; overload;
function NthVal(const index: Integer = 0): Integer; overload;
function NValue(const index: Integer = 0): Integer; overload;
function Query(const index: Integer = 0): Integer; overload;
function Read(const index: Integer = 0): Integer; overload;
function Resolve(const index: Integer = 0): Integer; overload;
function Retrieve(const index: Integer = 0): Integer; overload;
function Term(const index: Integer = 0): Integer; overload;
function ToValue(const index: Integer = 0): Integer; overload;
function ToValues(const ID: TIntegerArray): TIntegerArray; overload;
function ValueAt(const index: Integer = 0): Integer; overload;
function Yield(const index: Integer = 0): Integer; overload;
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
function TRange.Access(const index: Integer = 0): Integer; overload;
const
  d: array[0..1] of Integer = (1, -1);
begin
  Result := (Self.start + (index * d[Ord(Self.Descending)]));
end;

{==============================================================================]
  <Access>
  @action: Maps a set of indices to their corresponding values in the range.
  @note: Converts each element in ID (assumed zero-based indices) into a value
         using start + (index * step), where step is +1 for ascending ranges
         and -1 for descending ranges. Returns an array of the same length as
         ID. If ID is empty, returns an empty array. Does not perform bounds
         checking; out-of-range indices will yield extrapolated values.
[==============================================================================}
function TRange.Access(const ID: TIntegerArray): TIntegerArray; overload;
const
  d: array[0..1] of Integer = (1, -1);
var
  i, o: Integer;
begin
  if ID.Empty then
    Exit([]);
  SetLength(Result, ID.Length);
  o := Ord(Self.Descending);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (ID[i] * d[o]));
end;

{==============================================================================]
  <Ascender>
  @action: Returns a specific value by stepping upward from the range's floor.
  @note: mIndex is an offset added to Minimum. Defaults to 0 (the Minimum itself).
[==============================================================================}
function TRange.Ascender(const mIndex: Integer = 0): Integer; overload;
begin
  Result := (Self.Minimum + mIndex);
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
  <Derive>
  @action: Computes the value at a given index using direct directional arithmetic.
  @note: Derives the element as start ± index depending on Direction:
         +1 or 0 → start + index; -1 → start - index. Treats a zero direction
         (degenerate range) as ascending. This is a branch-based alternative
         to Query with explicit handling of Direction states. Does not perform
         bounds checking; indices outside [0, Size-1] yield extrapolated values.
[==============================================================================}
function TRange.Derive(const index: Integer = 0): Integer; overload;
begin
  case Self.Direction of
    1, 0: Result := (Self.start + index);
    -1: Result := (Self.start - index);
  end;
end;

{==============================================================================]
  <Descender>
  @action: Returns a specific value by stepping downward from the range's ceiling.
  @note: mIndex is an offset subtracted from Maximum. Defaults to 0 (the Maximum).
[==============================================================================}
function TRange.Descender(const mIndex: Integer = 0): Integer; overload;
begin
  Result := (Self.Maximum - mIndex);
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
  Result := (Self.start + (Self.Direction * index));
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
  <Evaluate>
  @action: Retrieves the value at a specified position via enumeration.
  @note: Iterates the range using its enumerator until the given index is
         reached, returning the last yielded value. If the index exceeds
         the range bounds, the result remains the last valid element reached.
         This approach is less efficient than direct index-based methods
         (e.g., Query/Read) due to iterative traversal.
[==============================================================================}
function TRange.Evaluate(const index: Integer = 0): Integer; overload;
var
  e: TRangeEnumerator;
  i: Integer;
begin
  Result := Self.start;
  e := GetEnumerator;
  for i := 0 to index do
    if e.MoveNext then
      Result := e.Current;
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
  <Node>
  @action: Retrieves the value at a specified index via iterative stepping.
  @note: Starts from Self.start and advances step-by-step using Succ
         (ascending) or Pred (descending) until the given index is reached.
         Equivalent in result to Query, but implemented with explicit looping.
         Does not perform bounds checking; large indices may result in
         extrapolated values beyond the original range.
[==============================================================================}
function TRange.Node(const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := Self.start;
  case Self.Ascending of
    True:
    for i := 1 to index do
      Result := Succ(Result);
    False:
    for i := 1 to index do
      Result := Pred(Result);
  end;
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
  <NthVal>
  @action: Returns the value at the specified zero-based index within the range.
  @param index: Zero-based position of the desired element (default = 0).
  @returns: The value at the specified index, or Low(Integer) if the
            index is out of bounds.
  @note:
    - If index < 0 or index >= Count, Low(Integer) is returned.
    - If index = 0, Start is returned directly.
    - For index > 0, the range is materialized via ToArray and the
      value is retrieved from the resulting array.
    - Indexing respects the range direction (ascending/descending),
      as determined by the underlying representation.
    - This method may incur additional allocation cost for
      index > 0 due to array construction.
[==============================================================================}
function TRange.NthVal(const index: Integer = 0): Integer; overload;
var
  arr: TIntegerArray;
begin
  if (index < 0) or (Index >= Self.Count) then
    Exit(Low(Integer));
  if (index = 0) then 
    Exit(Self.start);
  arr := Self.ToArray;
  Result := arr[Index];
end;

{==============================================================================]
  <NValue>
  @action: Returns the element at a specified zero-based index in the range,
           supporting negative indices to count from the end.
  @param index: Zero-based index of the desired element.  
                 - Positive values count from Start (0 = first element).  
                 - Negative values count backward from the last element (-1 = last element).
                 Default = 0.
  @returns: The integer value at the specified index in the range.
  @note:
    - The value is computed using: Start + (index * Wind) for non-negative indices,  
      or Start + ((Count + index) * Wind) for negative indices.
    - Preserves range direction (ascending/descending) via Wind.
    - Supports easy access to the first, last, or any element by index.
    - Does **not** perform bounds checking; using an out-of-range index may
      produce a value outside the range.
[==============================================================================}
function TRange.NValue(const index: Integer = 0): Integer; overload;
begin
  if (index < 0) then
    Result := (Self.start + ((Self.Count + index) * Self.Wind))
  else
    Result := (Self.start + (index * Self.Wind));
end;

{==============================================================================]
  <Query>
  @action: Retrieves the value at a specified index within the range.
  @note: Computes the value using a zero-based index with directional step:
         value = start + (index * sign(stop - start)). The Sign function
         determines whether the range is ascending, descending, or constant.
         Does not perform bounds checking; indices outside [0, Size-1] will
         yield extrapolated values.
[==============================================================================}
function TRange.Query(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * Sign(Self.stop - Self.start)));
end;

{==============================================================================]
  <Read>
  @action: Retrieves the value at a specified index with bounds enforcement.
  @note: Clamps the provided index to the valid range [0, Size-1] using
         EnsureRange, then computes the corresponding value via
         start + (index * Direction). Unlike Query, this method guarantees
         the result always falls within the range domain.
[==============================================================================}
function TRange.Read(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (EnsureRange(index, 0, (Self.Size - 1)) * Self.Direction));
end;

{==============================================================================]
  <Resolve>
  @action: Retrieves a value from the range using circular (wrapped) indexing.
  @note: Maps the given index into the valid range domain via modulo Size,
         supporting negative and out-of-bounds indices by wrapping them into
         [0, Size-1]. The resolved position is then converted to a value using
         start + (i * Direction). This provides cyclic access over the range.
[==============================================================================}
function TRange.Resolve(const index: Integer = 0): Integer; overload;
var
  s, i: Integer;
begin
  s := Self.Size;
  i := (index mod s);
  if (i < 0) then
    Inc(i, s);
  Result := (Self.start + (i * Self.Direction));
end;

{==============================================================================]
  <Retrieve>
  @action: Retrieves the value at a specified index using recursive traversal.
  @note: Computes the result by recursively stepping from Self.start toward
         the target index, applying Succ (ascending) or Pred (descending)
         per level. For index <= 0, returns Self.start. This method is
         functionally equivalent to Query but significantly less efficient
         due to recursion and potential stack growth for large indices.
[==============================================================================}
function TRange.Retrieve(const index: Integer = 0): Integer; overload;
begin
  if (index <= 0) then
    Result := Self.start
  else if Self.Ascending then
    Result := Succ(Self.Retrieve(index - 1))
  else
    Result := Pred(Self.Retrieve(index - 1));
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
  d := Self.Delta;
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
  Result := (Self.start + (index * Self.Direction));
end;

{==============================================================================]
  <ToValues>
  @action: Maps index positions to their corresponding range values.
  @note: Transforms a zero-based index array (ID) into actual values within
         the range using the relation: value = start + (index * Direction).
         The Direction ensures correct handling of ascending or descending
         ranges. The length of the result matches the input ID array.
         Assumes indices are within [0, Size-1]; out-of-range values will
         produce extrapolated results.
[==============================================================================}
function TRange.ToValues(const ID: TIntegerArray): TIntegerArray; overload;
var
  i, d: Integer;
begin
  d := Self.Direction;
  SetLength(Result, ID.Length);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (ID[i] * d));
end;

{==============================================================================]
  <ValueAt>
  @action: Returns the value at a specified index from the start of the range, accounting for ascending or descending order.
  @note: Index defaults to 0. The method assumes the caller ensures the index stays within valid range bounds. Works for both ascending and descending ranges.
[==============================================================================}
function TRange.ValueAt(const index: Integer = 0): Integer; overload;
begin
  case Self.Descending of
    False: Result := (Self.start + index);
    True: Result := (Self.start - index);
  end;
end;

{==============================================================================]
  <Yield>
  @action: Computes the value at a specified index using branchless direction encoding.
  @note: Derives the element as start + (index * step), where step is computed
         as (Ascending * 2) - 1, yielding +1 for ascending and -1 for descending.
         This avoids conditional branching by encoding direction arithmetically.
         Functionally equivalent to Query/Derive. Does not perform bounds
         checking; indices outside [0, Size-1] yield extrapolated values.
[==============================================================================}
function TRange.Yield(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (index * ((Integer(Self.Ascending) * 2) - 1)));
end;
{$ENDIF}
