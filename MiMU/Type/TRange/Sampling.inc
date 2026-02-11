{$IFDEF METHODS}
function Any: Integer; overload;
function Mixed(const mixings: Integer = 1): TIntegerArray; overload;
function Raffle(const N: Integer = 1): TIntegerArray; overload;
function Rand: Integer; overload;
function Randomize: TIntegerArray; overload;
function Randomly: Integer; overload;
function Sample(const sSize: Integer): TIntegerArray; overload;
function Shake(const shakes: Integer = 1): TIntegerArray; overload;
function Shuffle(const shuffles: Integer = 1): TIntegerArray; overload;
function Some: TIntegerArray; overload;
function Some(const amount: Integer): TIntegerArray; overload;
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