{$IFDEF METHODS}
function Any: Integer; overload;
function Arbitrary: Integer; overload;
function Disordered: TIntegerArray; overload;
function Jumbled: TIntegerArray; overload;
function Lottery(const lCount: Integer = 1): TIntegerArray; overload;
function Lucky: Integer; overload;
function Mixed(const mixings: Integer = 1): TIntegerArray; overload;
function Quantized(const sStep: Integer = 1): TIntegerArray; overload;
function Raffle(const N: Integer = 1): TIntegerArray; overload;
function Rand: Integer; overload;
function Randed: TIntegerArray; overload;
function Randomal: Integer; overload;
function Randomer: Integer; overload;
function RandomEx(const forbidden: Integer): Integer; overload;
function RandomEx(const forbidden: TIntegerArray): Integer; overload;
function Randomize: TIntegerArray; overload;
function Randomized: TIntegerArray; overload;
function Randomly: Integer; overload;
function Randoms(const rSize: Integer = 1): TIntegerArray; overload;
function Randomval: Integer; overload;
function Randstart: Integer; overload;
function Randstop: Integer; overload;
function Roll(const rCount: Integer = 1): TIntegerArray; overload;
function Sample(const sSize: Integer = 1): TIntegerArray; overload;
function Sampled(const totalElements: Integer = 1): TIntegerArray; overload;
function Samples(const rCount: Integer = 1): TIntegerArray; overload;
function Scrambled: TIntegerArray; overload;
function Shake(const shakes: Integer = 1): TIntegerArray; overload;
function Shuffle(const shuffles: Integer = 1): TIntegerArray; overload;
function Shuffled(const sCount: Integer): TIntegerArray; overload;
function Shuffled: TIntegerArray; overload;
function Some: TIntegerArray; overload;
function Some(const amount: Integer): TIntegerArray; overload;
function Startr: Integer; overload;
function Startra: Integer; overload;
function Stopr: Integer; overload;
function Stopra: Integer; overload;
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
  <Disordered>
  @action: Generates a randomized array containing all integer values defined within the TRange.
  @note: Materializes the entire range into a standard sequential array first via `.ToArray`,
         then applies a classic Durstenfeld-Fisher-Yates shuffle backwards in-place using `Swap`.
[==============================================================================}
function TRange.Disordered: TIntegerArray; overload;
var
  i: Integer;
begin
  Result := Self.ToArray;
  i := Result.Length;
  while (i.Decrement > 0) do
    Swap(Result[Random(i)], Result[i]);
end;

{==============================================================================]
  <Jumbled>
  @action: Generates a randomized array containing all unique integer values within the TRange bounds.
  @note: Populates the result by converting the range to a temporary sequential array,
         then repeatedly selects an item at a random index, copies it over,
		 and destructively removes it from the pool using `Delete`.
[==============================================================================}
function TRange.Jumbled: TIntegerArray; overload;
var
  s: TIntegerArray;
  i, r: Integer;
begin
  s := Self.ToArray;
  SetLength(Result, s.Length);
  for i := 0 to High(Result) do
  begin
    r := Random(s.Length);
    Result[i] := s[r];
    s.Delete(r);
  end;
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
  <Lucky>
  @action: Returns a random element within the range bounds
  @note: Uses Random(Size); direction adjusted by Ascending flag
[==============================================================================}
function TRange.Lucky: Integer; overload;
begin
  Result := (Self.start + (Random(Self.Size) * IfThen(Self.Ascending, 1, -1)));
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
  <Quantized>
  @action: Returns a step-sampled (quantized) sequence over the range using a fixed
           step size. The values are generated starting from `start` and advanced
           by `sStep` in the direction of the range.
  @note:
    - sStep <= 0 returns an empty array.
    - Sampling is direction-aware (uses Self.Direction).
    - The number of elements is computed from range span and step size.
    - Values are generated sequentially without exceeding the computed count.
[==============================================================================}
function TRange.Quantized(const sStep: Integer = 1): TIntegerArray; overload;
var
  i, v, d, c: Integer;
begin
  if (sStep <= 0) then
    Exit([]);
  d := Self.Direction;
  v := Self.start;
  if Self.Ascending then
    c := (((Self.stop - Self.start) div sStep) + 1)
  else
    c := (((Self.start - Self.stop) div sStep) + 1);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    Result[i] := v.Increase(sStep * d);
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
  <Randed>
  @action: Generates a randomized array containing all integer values from the TRange.
  @note: Converts the range to an array first, then optimizes the traditional Fisher-Yates shuffle
         by accessing elements directly via a raw pointer (`PInteger`) to bypass high-level array safety overhead during swapping.
[==============================================================================}
function TRange.Randed: TIntegerArray; overload;
var
  i, r, s: Integer;
  p: PInteger;
begin
  Result := Self.ToArray;
  p := PInteger(Result);
  for i := High(Result) downto 1 do
  begin
    r := Random(i + 1);
    s := p[i];
    p[i] := p[r];
    p[r] := s;
  end;
end;

{==============================================================================]
  <Randomal>
  @action: Returns a pseudo-random integer within the range boundaries using 
           explicit Minimum and Maximum properties.
  @note: The result is inclusive of both Minimum and Maximum. Uses the Math 
         unit's RandomRange function, adjusting the upper bound by +1 to counteract 
         its exclusive nature.
[==============================================================================}
function TRange.Randomal: Integer; overload;
begin
  Result := RandomRange(Self.Minimum, (Self.Maximum + 1));
end;

{==============================================================================]
  <Randomer>
  @action: Returns a pseudo-random integer within the range by subtracting a 
           random offset from the Maximum boundary.
  @note: Generates a value by counting downward from Self.Maximum using the 
         range's Size property. The result spans from (Self.Maximum - Self.Size + 1) 
         up to Self.Maximum.
[==============================================================================}
function TRange.Randomer: Integer; overload;
begin
  Result := (Self.Maximum - Random(Self.Size));
end;

{==============================================================================]
  <RandomEx>
  @action: Returns a random value within the range, excluding a specific number.
  @note: 
    - If the range is Singular (Size=1), the Start value is returned regardless.
    - Uses a rejection-sampling loop; ensure the forbidden value is actually 
      within the range to avoid infinite loops in very small sets.
[==============================================================================}
function TRange.RandomEx(const forbidden: Integer): Integer; overload;
var
  s, d: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit(Self.start);
  d := Self.Direction;
  repeat
    Result := (Self.start + (Random(s) * d));
  until (Result <> forbidden);
end;

{==============================================================================]
  <RandomEx>
  @action: Selects a random value from the range that does not exist in the 
           provided exclusion list.
  @note: 
    - Optimization: Uses a sorted, unique-filtered version of the forbidden 
      array to enable O(log N) Binary Search lookups.
    - Safety: Performs a logical equivalence check between the range and the 
      filtered exclusion set to prevent infinite loops (deadlock).
    - If no valid values are available, the range's Start value is returned.
[==============================================================================}
function TRange.RandomEx(const forbidden: TIntegerArray): Integer; overload;
var
  s, d: Integer;
  f: TIntegerArray;
begin
  if forbidden.Empty then
    Exit(Self.Randomly);
  s := Self.Size;
  if (s = 1) then
    Exit(Self.start);
  f := forbidden.Cleaned;
  if ((s = f.Length) and Self.Equivalent(TRange.Construct(f[0], f[High(f)]))) then
    Exit(Self.start);
  d := Self.Direction;
  repeat
    Result := (Self.start + (Random(s) * d));
  until not f.BinaryContains(Result);
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
  <Randomized>
  @action: Returns a randomly shuffled permutation of all elements in the range.
  @note:
    - Produces a full permutation of Self.All using an in-place Fisher–Yates shuffle.
    - Iterates from 0 to High(Result), swapping each element with a random index in [0..i].
    - Ensures each element has an equal probability of appearing in any position.
    - Does not modify the original range.
    - Uses global Random generator; for non-deterministic results, ensure Randomize is called externally.
[==============================================================================}
function TRange.Randomized: TIntegerArray; overload;
var
  i: Integer;
begin
  Result := Self.All;
  for i := 0 to High(Result) do
    Result.Exch(Random(i + 1), i);
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
  <Randomval>
  @action: Returns a pseudo-random integer within the current TRange bounds,
           inclusive of the start and stop values.
  @note: Automatically handles both ascending (e.g., 1 to 10) and descending
         (e.g., 10 to 1) ranges by adjusting the boundaries passed to RandomRange.
[==============================================================================}
function TRange.Randomval: Integer; overload;
begin
  if Self.Descending then
    Exit(RandomRange(Self.stop, (Self.start + 1)));
  Result := RandomRange(Self.start, (Self.stop + 1))
end;

{==============================================================================]
  <Randstart>
  @action: Randomly walks the range from `start` toward `stop`, returning the
           first index where `RandomB` succeeds; falls back to `stop` if no
           hit occurs. Direction follows `Self.Ascending`.
  @note: Biased toward `start` — an early success is more likely than a
         late one. Overloaded; see other `Randstart` variant(s) for
         related behavior.
[==============================================================================}
function TRange.Randstart: Integer; overload;
begin
  case Self.Ascending of
    True:
    for Result := Self.start to Self.stop do
      if RandomB then
        Exit;
    False:
    for Result := Self.start downto Self.stop do
      if RandomB then
        Exit;
  end;
  Result := Self.stop;
end;

{==============================================================================]
  <Randstop>
  @action: Randomly walks the range from `stop` toward `start`, returning the
           first index where `RandomB` succeeds; falls back to `start` if no
           hit occurs. Direction follows `Self.Ascending`.
  @note:   Biased toward `stop` — an early success is more likely than a
           late one. Mirror counterpart to `Randstart`.
[==============================================================================}
function TRange.Randstop: Integer; overload;
begin
  case Self.Ascending of
    True:
    for Result := Self.stop downto Self.start do
      if RandomB then
        Exit;
    False:
    for Result := Self.stop to Self.start do
      if RandomB then
        Exit;
  end;
  Result := Self.start;
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
function TRange.Sample(const sSize: Integer = 1): TIntegerArray; overload;
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
  <Sampled>
  @action: Produces a uniformly sampled subset of values across the range.
  @note: Returns a fixed-size array of totalElements values evenly distributed
         from Self.start to Self.stop (inclusive). If totalElements <= 0,
         returns an empty array; if totalElements = 1, returns [Self.start];
         if totalElements exceeds or equals Size, returns the full range (All).
         Otherwise computes a linear interpolation step and rounds each value,
         effectively performing uniform downsampling of the range.
[==============================================================================}
function TRange.Sampled(const totalElements: Integer = 1): TIntegerArray; overload;
var
  i: Integer;
  s: Double;
begin
  if (totalElements <= 0) then
    Exit([]);
  if (totalElements = 1) then
    Exit([Self.start]);
  if (totalElements >= Self.Size) then
    Exit(Self.All);  
  SetLength(Result, totalElements);
  s := ((Self.stop - Self.start) / (totalElements - 1));
  for i := 0 to (totalElements - 1) do
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
  <Scrambled>
  @action: Generates a randomized array containing every integer within the TRange boundaries.
  @note: Automatically handles singular ranges, and utilizes an inline Fisher-Yates shuffle variant
         to simultaneously generate and shuffle values in a single pass based on range direction (Ascending vs Descending).
[==============================================================================}
function TRange.Scrambled: TIntegerArray; overload;
var
  i, r: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  case Self.Ascending of
    True:
    for i := 0 to High(Result) do
    begin
      r := Random(i + 1);
      if (r <> i) then
        Result[i] := Result[r];
      Result[r] := (Self.start + i);
    end;
    False:
    for i := 0 to High(Result) do
    begin
      r := Random(i + 1);
      if (r <> i) then
        Result[i] := Result[r];
      Result[r] := (Self.stop + i);
    end;
  end;
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
  <Shuffled>
  @action: Generates a randomized selection of unique values from the range.
  @return: A TIntegerArray containing [sCount] unique random items.
  @note: 
    - Implements a Partial Fisher-Yates shuffle directly on the result array.
    - If sCount is 1 (default), returns a single random item in an array.
    - If sCount >= Size, returns the entire range in a randomized order.
    - Truncates the result to sCount after the necessary swaps are performed.
[==============================================================================}
function TRange.Shuffled(const sCount: Integer): TIntegerArray; overload;
var
  i, c, l: Integer;
begin
  if (sCount < 1) then
    Exit([]);
  Result := Self.Items;
  l := Result.Length;
  c := Min(sCount, l);
  for i := 0 to (c - 1) do
    Swap(Result[i], Result[i + Random(l - i)]);
  SetLength(Result, c);
end;

{==============================================================================]
  <Shuffled>
  @action: Full TRange shuffled.
  @note: None.
[==============================================================================}
function TRange.Shuffled: TIntegerArray; overload;
begin
  Result := Self.Shuffled(Self.Size);
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
  <Startr>
  @action: Generates a pseudo-random integer that is heavily weighted (skewed) 
           towards the start boundary of the range using a geometric distribution.
  @note: Uses a logarithmic transformation of a uniform random float to create 
         an exponential decay distribution. The resulting offset is capped at 
         (Size - 1) to prevent out-of-bounds values, and is applied relative to 
         the direction of the range (added if ascending, subtracted if descending).
[==============================================================================}
function TRange.Startr: Integer; overload;
var
  s: Integer;
begin
  s := Self.Size;
  Result := Trunc(Ln(Random) / Ln(0.5));
  if (Result >= s) then
    Result := (s - 1);
  if Self.Ascending then
    Result := (Self.start + Result)
  else
    Result := (Self.start - Result);
end;

{==============================================================================]
  <Startra>
  @action: Materializes the range into an array via `ToArray`, then randomly
           walks it front-to-back, returning the first element where
           `RandomB` succeeds; falls back to the first element (`s[0]`) if no
           hit occurs.
  @note: Array-based counterpart to `Randstart` — same start-biased search,
         but operates over a materialized `TIntegerArray` rather than
         iterating `start`/`stop` directly. Overloaded.
[==============================================================================}
function TRange.Startra: Integer; overload;
var
  r: Integer;
  s: TIntegerArray;
begin
  s := Self.ToArray;
  for r := 0 to High(s) do
    if RandomB then
      Exit(s[r]);
  Result := s[0];
end;

{==============================================================================]
  <Stopr>
  @action: Generates a pseudo-random integer that is heavily weighted (skewed) 
           towards the stop boundary of the range using a geometric distribution.
  @note: Uses a logarithmic transformation of a uniform random float to create 
         an exponential decay distribution. The resulting offset is capped at 
         (Size - 1) to prevent out-of-bounds values, and is applied moving backward 
         from the stop boundary (subtracted if ascending, added if descending).
[==============================================================================}
function TRange.Stopr: Integer; overload;
var
  s: Integer;
begin
  s := Self.Size;
  Result := Trunc(Ln(Random) / Ln(0.5));
  if (Result >= s) then
    Result := (s - 1);
  if Self.Ascending then
    Result := (Self.stop - Result)
  else
    Result := (Self.stop + Result);
end;

{==============================================================================]
  <Stopra>
  @action: Materializes the range into an array via `ToArray`, then randomly
           walks it back-to-front, returning the first element where
           `RandomB` succeeds; falls back to the last element (`s[High(s)]`)
           if no hit occurs.
  @note: Array-based counterpart to `Randstop` — same stop-biased search,
         but operates over a materialized `TIntegerArray` rather than
         iterating `start`/`stop` directly. Overloaded.
[==============================================================================}
function TRange.Stopra: Integer; overload;
var
  r: Integer;
  s: TIntegerArray;
begin
  s := Self.ToArray;
  for r := High(s) downto 0 do
    if RandomB then
      Exit(s[r]);
  Result := s[High(s)];
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
  if Self.Singular then
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
