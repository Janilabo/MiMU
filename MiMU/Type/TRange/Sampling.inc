{$IFDEF METHODS}
function Any: Integer; overload;
function Arbitrary: Integer; overload;
function Lottery(const lCount: Integer = 1): TIntegerArray; overload;
function Mixed(const mixings: Integer = 1): TIntegerArray; overload;
function Raffle(const N: Integer = 1): TIntegerArray; overload;
function Rand: Integer; overload;
function Randomize: TIntegerArray; overload;
function Randomly: Integer; overload;
function Randoms(const rSize: Integer = 1): TIntegerArray; overload;
function Roll(const rCount: Integer = 1): TIntegerArray; overload;
function Sample(const sSize: Integer): TIntegerArray; overload;
function Samples(const rCount: Integer = 1): TIntegerArray; overload;
function Shake(const shakes: Integer = 1): TIntegerArray; overload;
function Shuffle(const shuffles: Integer = 1): TIntegerArray; overload;
function Some: TIntegerArray; overload;
function Some(const amount: Integer): TIntegerArray; overload;
function Subsample(const sSize: Integer = 1): TIntegerArray; overload;
function Subsampled(const sSize: Integer = 1): TIntegerArray; overload;
function Zigzag(const zAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Any>
  @action: Returns random TRange item.
  @note: None.
[==============================================================================}
function TRange.Any: Integer; overload;
begin
  Result := ((Self.start + Random(Self.Size)) * IfThen(Self.Ascending, 1, -1));
end;

{==============================================================================]
  <Arbitrary>
  @action: Returns a single integer selected uniformly at random from the range.
  @note: • Selection is inclusive of both bounds (start and stop).
         • For ascending ranges:
           Result = start + Random((stop - start) + 1)
         • For descending ranges:
           Result = stop + Random((start - stop) + 1)
         • Random(N) yields a value in [0, N), ensuring uniform distribution
           across all integers in the range.
         • Does not allocate memory or modify the range.
[==============================================================================}
function TRange.Arbitrary: Integer; overload;
begin
  if Self.Ascending then
    Result := (Self.start + Random((Self.stop - Self.start) + 1))
  else
    Result := (Self.stop + Random((Self.start - Self.stop) + 1));
end;

{==============================================================================]
  <Lottery>
  @action: Selects a unique set of random integers within the range. 
  @note: Ensures no duplicates. If lCount exceeds the range's total size, 
         the result is capped at the range's capacity to prevent infinite loops.
[==============================================================================}
function TRange.Lottery(const lCount: Integer = 1): TIntegerArray; overload;
var
  m, c, i, j, r, s: Integer;
  u: Boolean;
begin
  if (lCount < 1) then
    Exit([]);
  s := Self.Size;
  c := Min(s, lCount);
  SetLength(Result, c);
  m := Self.Minimum;
  for i := 0 to (c - 1) do
  begin
    repeat
      r := (m + Random(s));
      u := False;
      for j := 0 to (i - 1) do
        if (Result[j] = r) then
        begin
          u := True;
          Break;
        end;
    until not u;
    Result[i] := r;
  end;
end;

{==============================================================================]
  <Mixed>
  @action: Returns TRange randomly mixed as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Mixed(const mixings: Integer = 1): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to mixings do
    for i := High(Result) downto 0 do
      Swap(Result[Random(Result.Size)], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Raffle>
  @action: Selects N distinct random elements from the range without replacement.
  @param N: The number of elements to select (default = 1).
  @returns: TIntegerArray containing up to N unique elements from the range.
  @note:
    - If N < 1, an empty array is returned.
    - If N >= Count, all range elements are returned in order.
    - For small N (less than one-tenth of Count), elements are selected
      individually using a boolean mask to ensure uniqueness.
    - For larger N, the range is converted to an array and partially shuffled
      using the Fisher–Yates algorithm to select the first N elements.
    - Preserves the range direction via Wind when computing element values.
    - The resulting array contains unique elements, randomly distributed,
      with no duplicates.
    - Original range is not modified.
[==============================================================================}
function TRange.Raffle(const N: Integer = 1): TIntegerArray; overload;
var
  a, c, i, m, v, w: Integer;
  u: TBooleanArray;
begin
  if (N < 1) then
    Exit([]);
  c := Self.Count;
  m := Min(N, c);
  SetLength(Result, m);
  if (m = c) then
    Exit(Self.ToArray);
  case (m < (c div 10)) of
    True:
    begin
      w := Self.Wind;
      SetLength(u, c);
      for i := 0 to (m - 1) do
      begin
        repeat
          v := Random(c);
        until not u[v];
        u[v] := True;
        Result[i] := (Self.start + (v * w));
      end;
    end;
    False:
    begin
      Result := Self.ToArray;
      for i := 0 to (m - 1) do
        Swap(Result[i], Result[(i + Random(c - i))]);
      SetLength(Result, m);
    end;
  end;
end; 

{==============================================================================]
  <Rand>
  @action: Returns a pseudo-random value within the numeric bounds of the range.
  @returns: A random integer between Min(Start, Stop) and
            Min(Start, Stop) + Size - 1.
  @note:
    - The lower bound is Min(Start, Stop).
    - The value is computed as:
        Min(Start, Stop) + Random(Size)
    - Assumes Size > 0.
    - The distribution is uniform over the produced interval.
    - This implementation does not explicitly account for Wind;
      it generates values within the numeric bounds rather than
      iterating according to range direction.
    - Correctness depends on Size matching the numeric span
      of the range.
[==============================================================================}
function TRange.Rand: Integer; overload;
begin
  Result := (Self.Minimum + Random(Self.Size));
end;

{==============================================================================]
  <Randomize>
  @action: Returns a randomly permuted array of the range values.
  @returns: TIntegerArray containing all elements of the range
            in randomized order.
  @note:
    - The result array length equals Size.
    - Elements are populated using At(i), preserving the
      logical order of the range prior to shuffling.
    - The array is shuffled in-place using the Fisher–Yates
      (Knuth) algorithm.
    - The permutation is uniformly distributed assuming
      Random(n) is uniform.
    - The original range remains unchanged.
    - Time complexity: O(n).
    - Space complexity: O(n).
[==============================================================================}
function TRange.Randomize: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := Self.At(i);
  for i := High(Result) downto 1 do
    Swap(Result[Random(i + 1)], Result[i]);
end;

{==============================================================================]
  <Randomly>
  @action: Returns a pseudo-random value from within the range.
  @returns: A randomly selected element of the range.
  @note:
    - If the range is ascending:
        Result := Start + Random(Count)
    - If the range is descending:
        Result := Start - Random(Count)
    - The distribution is uniform over Count possible values.
    - Assumes Count > 0.
    - The generated value follows the range direction (respects
      Ascending / descending orientation).
    - The result is guaranteed to lie within the range bounds.
[==============================================================================}
function TRange.Randomly: Integer; overload;
begin
  if Self.Ascending then
    Result := (Self.start + Random(Self.Count))
  else
    Result := (Self.start - Random(Self.Count));
end;

{==============================================================================]
  <Randoms>
  @action: Generates random values within the range.
  @note: 
    - Returns an array of rSize uniformly distributed random integers.
    - Values are sampled from the inclusive interval [Minimum, Maximum].
    - If rSize < 1, an empty array is returned.
[==============================================================================}
function TRange.Randoms(const rSize: Integer = 1): TIntegerArray; overload;
var
  i, m, s: Integer;
begin
  SetLength(Result, Max(0, rSize));
  if (rSize < 1) then
    Exit;
  m := Self.Minimum;
  s := ((Self.Maximum - m) + 1);
  for i := 0 to (rSize - 1) do
    Result[i] := (m + Random(s));
end;

{==============================================================================]
  <Roll>
  @action: Returns up to rCount unique integers randomly selected from the
           range without replacement.
  @note: • Computes c = Min(Size, rCount) as the number of values to return.
         • Implements a partial Fisher–Yates shuffle over index space [0..Size-1].
         • For each i ∈ [0, c-1]:
           - Selects a random index p ∈ [i, Size-1].
           - Resolves index indirection via a sparse map (dictionary).
           - Emits value: Minimum + resolved index.
           - Records the swap (p ↔ i) in the map.
         • The dictionary m lazily tracks virtual swaps, avoiding full array allocation.
         • Guarantees:
           - No duplicates (sampling without replacement).
           - Uniform distribution over all combinations of size c.
         • Does not modify the range.
         • Result order corresponds to selection order (not sorted).
[==============================================================================}
function TRange.Roll(const rCount: Integer = 1): TIntegerArray; overload;
var
  m: specialize TDictionary<Integer, Integer>;
  c, i, j, s, p: Integer;
  function GV(idx: Integer): Integer;
  begin
    if not m.TryGetValue(idx, Result) then
      Result := idx;
  end;
begin
  s := Self.Size;
  c := Min(rCount, s);
  SetLength(Result, c);
  if (c <= 0) then
    Exit;
  m := specialize TDictionary<Integer, Integer>.Create;
  try
    for i := 0 to (c - 1) do
    begin
      p := (i + Random(s - i));
      Result[i] := (Self.Minimum + GV(p));
      m.AddOrSetValue(p, GV(i));
    end;
  finally
    m.Free;
  end;
end;

{==============================================================================]
  <Sample>
  @action: Return evenly spaced integer samples across the range.
  @note: Always includes both start and stop values of the range (if sSize > 1).
         Uses rounding to map floating step positions to integers.
         If sSize = 1, returns only the start value.
[==============================================================================}
function TRange.Sample(const sSize: Integer): TIntegerArray; overload;
var
  i: Integer;
  s: Double;
begin
  if (sSize < 1) then
    Exit([]);
  SetLength(Result, sSize);
  s := (Self.Delta / (sSize - 1));
  for i := 0 to (sSize - 1) do
    Result[i] := Round(Self.start + (i * s));
end;

{==============================================================================]
  <Samples>
  @action: Generates random sample values within the range.
  @note: 
    - Returns an array of rCount uniformly distributed random integers.
    - Values are sampled from the inclusive interval [Minimum, Maximum].
    - If rCount < 1, an empty array is returned.
[==============================================================================}
function TRange.Samples(const rCount: Integer = 1): TIntegerArray; overload;
var
  i, l, h: Integer;
begin
  if (rCount < 1) then
    Exit([]);
  SetLength(Result, rCount);
  l := Self.Minimum;
  h := Self.Maximum;
  for i := 0 to (rCount - 1) do
    Result[i] := (l + Random((h - l) + 1));
end;

{==============================================================================]
  <Shake>
  @action: Returns TRange randomly shaked as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shake(const shakes: Integer = 1): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shakes do
    for i := Random(Result.Size) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shuffle>
  @action: Returns TRange randomly shuffled as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shuffle(const shuffles: Integer = 1): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shuffles do
    for i := High(Result) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some: TIntegerArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Size + 1), 1))
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some(const amount: Integer): TIntegerArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <Subsample>
  @action: Returns a contiguous random subrange (slice) of integers from Self.
           The slice length is defined by sSize and is clamped to the range size.
           The starting offset is chosen uniformly at random.
  @note: • This is NOT a statistical/random subset; elements are contiguous.
         • Time complexity: O(c), where c = Min(Size, sSize).
         • Space complexity: O(c) for the result buffer.
         • If sSize <= 0, returns an empty array.
         • If sSize >= Size, the full range is returned (still via copy).
         • Direction is preserved:
           - Ascending  → increasing sequence (step = +1)
           - Descending → decreasing sequence (step = -1)
         • Random() is expected to be uniform in [0, N), thus the start index
           r ∈ [0, Size - c] is uniformly distributed.
[==============================================================================}
function TRange.Subsample(const sSize: Integer = 1): TIntegerArray; overload;
var
  m, r, i, s, c: Integer;
begin
  s := Self.Size;
  c := Min(s, sSize);
  if (c < 1) then
    Exit([]);
  r := Random((s - c) + 1);
  SetLength(Result, c);
  m := IfThen(Self.Ascending, (Self.start + r), (Self.start - r));
  case Self.Ascending of
    True:
    for i := 0 to (c - 1) do
      Result[i] := (m + i);
    False:
    for i := 0 to (c - 1) do
      Result[i] := (m - i);
  end;
end;

{==============================================================================]
  <Subsampled>
  @action: Generates a contiguous slice of integers from the range starting at
           a randomly selected offset, with length defined by sSize (clamped
           to the range size).
  @note: • Computes c = Min(Size, sSize) as the slice length.
         • Selects a random offset r ∈ [0, Size - c].
         • Derives the starting value m from the offset and range direction:
           - Ascending  → m = start + r
           - Descending → m = start - r
         • Uses a directional step d (±1) to construct the sequence.
         • Fills Result as: Result[i] = m + (i * d), i ∈ [0, c-1].
         • Output is always a contiguous, in-order segment of the range.
         • Returns [] when c < 1.
[==============================================================================}
function TRange.Subsampled(const sSize: Integer = 1): TIntegerArray; overload;
var
  m, r, i, s, c, d: Integer;
begin
  s := Self.Size;
  c := Min(s, sSize);
  if (c < 1) then
    Exit([]);
  r := Random((s - c) + 1);
  SetLength(Result, c);
  m := IfThen(Self.Ascending, (Self.start + r), (Self.start - r));
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to (c - 1) do
    Result[i] := (m + (i * d));
end;

{==============================================================================]
  <Zigzag>
  @action: Returns the integer values of the range in an alternating “zig-zag” order,
           taking elements from the start and end of the range alternately.
           For example, for a range 1..5, the result is [1,5,2,4,3].
  @note:   Works for ascending and descending ranges.
           If the range contains a single value, returns an array with that single value.
           Internally uses two arrays (ascending and reversed) to construct the pattern.
[==============================================================================}
function TRange.Zigzag(const zAscending: Boolean = True): TIntegerArray; overload;
var
  a, d: TIntegerArray;
  l, i, j, r, z: Integer;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  a := Self.ToArray;
  d := a.Reversed;
  l := a.Length;
  SetLength(Result, l);
  i := 0;
  j := 0;
  r := -1;
  z := IfThen(zAscending, 0, 1);
  while ((i + j) < l) do
    if ((r.Increment mod 2) = z) then
      Result[r] := a[i.Increase]
    else
      Result[r] := d[j.Increase];
end;
{$ENDIF}
