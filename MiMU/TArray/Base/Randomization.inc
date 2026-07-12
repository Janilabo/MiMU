{$IFDEF HELPERS}
function Any(const null: MType): MType; overload;
function Any: MType; overload;
function Derange: Boolean; overload;
function Deranged: MArray; overload;
function Disarray: MArray; overload;
function Disindex: TIntegerArray; overload;
function Disordered: MArray; overload;
function Disself: MArray; overload;
function Draft(const N: Integer = 1): MArray; overload;
function Favor(const weights: TDoubleArray): MType; overload;
function Favor(const weights: TIntegerArray): MType; overload;
function FisherYates: MArray; overload;
function Mix(const mixings: Integer = 1): Boolean; overload;
function Mixed(const mixings: Integer = 1): MArray; overload;
function Mixing: Integer; overload;
function Muddled: MArray; overload;
function Raffle(const rCount: Integer = 1): MArray; overload;
function Randex(const N: Integer = 1): TIntegerArray; overload;
function Randiced: TIntegerArray; overload;
function Randices: TIntegerArray; overload;
function Randicing: TIntegerArray; overload;
function Randomed: MArray; overload;
function Randomise: Integer; overload;
function Randomised: MArray; overload;
function Randomized: MArray; overload;
function Randomned: MArray; overload;
function Randsy: MArray; overload;
function Recomposed: MArray; overload;
function Scoop(const sCount: Integer = 1): MArray; overload;
function Scramble(const swaps: Integer = -1): MArray; overload;
function Shake(const shakes: Integer = 1): MArray; overload;
function Shuffle(const shuffles: Integer = 1): MArray; overload;
function Shuffled(const mixings: Integer = 1): MArray; overload;
function Shufflist: MArray; overload;
function Shuffly: MArray; overload;
function Some: MArray; overload;
function Some(const amount: Integer): MArray; overload;
function Sweepstake(const sCount: Integer = 1): MArray; overload;
function Unsettle: Integer; overload;
function Unsettled: MArray; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Conflate(const A, B: MArray): MArray; overload;
function Confound(const A, B: MArray): MArray; overload;
function Disarray(const A, B: MArray): MArray; overload;
function Interleaf(const A, B: MArray): MArray; overload;
function Interleave(const A, B: MArray): MArray; overload;
function Mingle(const A, B: MArray): MArray; overload;
function Redealt(const A, B: MArray): MArray; overload;
function Riffle(const A, B: MArray): MArray; overload;
function Roulette(const A, B: MArray): MArray; overload;
function Shuffle(const A, B: MArray): MArray; overload;
function Wash(const A, B: MArray): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Conflate>
  @action: Merges two arrays into a single array while shuffling the elements 
           on-the-fly using an online streaming randomization algorithm.
  @note: Implements an optimized variation of the reservoir sampling / inside-out 
         Fisher-Yates shuffle. It processes arrays A and B sequentially, placing 
         each new element into a random position `r` within the currently grown 
         pool, and moving displaced elements to the newly opened slot `n`.
[==============================================================================}
function Conflate(const A, B: MArray): MArray; overload;
var
  i, r, n: Integer;
begin
  SetLength(Result, (A.Length + B.Length));
  n := 0;
  for i := 0 to High(A) do
  begin
    r := Random(n + 1);
    if (r <> n) then
      Result[n] := Result[r];
    Result[r] := A[i];
    Inc(n);
  end;
  for i := 0 to High(B) do
  begin
    r := Random(n + 1);
    if (r <> n) then
      Result[n] := Result[r];
    Result[r] := B[i];
    Inc(n);
  end;
end;

{==============================================================================]
  <Confound>
  @action: Combines two arrays into a single, fully randomized array by pre-shuffling 
           both inputs and merging them using a reverse-order weighted lottery.
  @note: Unlike 'Disarray' which picks random indices on the fly, 'Confound' first 
         fully randomizes copies of arrays A and B. It then populates the final array 
         from the *last* index to the *first* index (using `r.Decrement`), pulling 
         sequentially from the pre-shuffled pools based on the remaining item ratios.
[==============================================================================}
function Confound(const A, B: MArray): MArray; overload;
var
  i, j, r, x, y: Integer;
  c, d: MArray;
begin
  c := A.Randomized;
  d := B.Randomized;
  x := c.Length;
  y := d.Length;
  r := Result.SetSize(x + y);
  i := 0;
  j := 0;
  while ((i < x) and (j < y)) do
    if (Random((x - i) + (y - j)) < (x - i)) then
      Result[r.Decrement] := c[i.Increase]
    else
      Result[r.Decrement] := d[j.Increase];
  while (i < x) do
    Result[r.Decrement] := c[i.Increase];
  while (j < y) do
    Result[r.Decrement] := d[j.Increase];
end;

{==============================================================================]
  <Disarray>
  @action: Merges and completely shuffles (randomizes) two custom arrays into a single array.
  @note: Combines arrays A and B while preserving their original contents from mutation. 
         It uses an internal index-mapping array and a weighted random selection process 
         (similar to a Fisher-Yates shuffle variation) to ensure an unbiased, random 
         distribution of elements in the resulting combined array.
[==============================================================================}
function Disarray(const A, B: MArray): MArray; overload;
var
  i, j, r, x, y, z: Integer;
  C, D: TIntegerArray;
begin
  x := A.Length;
  if (x = 0) then
    Exit(B.Randomized);
  y := B.Length;
  if (y = 0) then
    Exit(A.Randomized);
  SetLength(Result, (x + y));
  C := A.Indexes;
  D := B.Indexes;
  i := 0;
  j := 0;
  r := 0;
  while ((x > 0) and (y > 0)) do
  case (Random(x + y) < x) of
    True:
    begin
      z := Random(x);
      Result[r.Increase] := A[C[z]];
      Swap(C[z], C[x.Decrement]);
    end;
    False:
    begin
      z := Random(y);
      Result[r.Increase] := B[D[z]];
      Swap(D[z], D[y.Decrement]);
    end;
  end;
  while (x > 0) do
    Result[r.Increase] := A[C[x.Decrement]];
  while (y > 0) do
    Result[r.Increase] := B[D[y.Decrement]];
end;

{==============================================================================]
  <Interleaf>
  @action: Randomly interleaves two arrays into one, preserving each array's
           internal element order.
  @note: Back-fill variant — fills Result from the tail forward using
         RandomB, decrementing x, y, and r as A and B are consumed from
         their ends.
[==============================================================================}
function Interleaf(const A, B: MArray): MArray; overload;
var
  r, x, y: Integer;
begin
  x := A.Length;
  y := B.Length;
  r := Result.SetSize(x + y);
  while ((x > 0) and (y > 0)) do
    if RandomB then
      Result[r.Decrement] := A[x.Decrement]
    else
      Result[r.Decrement] := B[y.Decrement];
  while (x > 0) do
    Result[r.Decrement] := A[x.Decrement];
  while (y > 0) do
    Result[r.Decrement] := B[y.Decrement];
end;

{==============================================================================]
  <Interleave>
  @action: Randomly interleaves two arrays into one, preserving each array's
           internal element order.
  @note: Pre-computes a placement mask so every possible interleaving is
         equally likely (fixes the tail-bias present in the coin-flip
         variants); randomness is front-loaded, the copy pass is pure
         mechanical placement.
[==============================================================================}
function Interleave(const A, B: MArray): MArray; overload;
var
  x, y, i, r: Integer;
  m: TBooleanArray;
begin
  x := A.Length;
  y := B.Length;
  SetLength(Result, (x + y));
  m.Create((x + y), False);
  i := 0;
  while (i < x) do
  begin
    r := Random(x + y);
    if m[r] then
      Continue;
    m[r] := True;
    Inc(i);
  end;
  for i := High(m) downto 0 do
    if m[i] then
      Result[i] := A[x.Decrement]
    else
      Result[i] := B[y.Decrement];
end;

{==============================================================================]
  <Mingle>
  @action: Merges two arrays into a temporary generic list and extracts elements 
           at random positions to build a shuffled combined array.
  @note: This implementation utilizes a Free Pascal / Delphi generic `TList` to 
         safely pool all elements from arrays A and B. It then iteratively draws 
         and deletes items from random positions in the list until it is empty, 
         guaranteeing a uniform shuffle while ensuring proper memory cleanup via 
         a `try...finally` block.
[==============================================================================}
function Mingle(const A, B: MArray): MArray; overload;
var
  L: specialize TList<MType>;
  i, r: Integer;
begin
  L := specialize TList<MType>.Create;
  try
    for i := 0 to High(A) do
      L.Add(A[i]);
    for i := 0 to High(B) do
      L.Add(B[i]);
    SetLength(Result, L.Count);
    i := 0;
    while (L.Count > 0) do
    begin
      r := Random(L.Count);
      Result[i.Increase] := L[r];
      L.Delete(r);
    end;
  finally
    L.Free;
  end;
end;

{==============================================================================]
  <Redealt>
  @action: Randomly interleaves two arrays into one, preserving each array's
           internal element order.
  @note: Recursively picks the head of A or B and conses it onto the
         riffle of the remainders; mirrors the recursive mechanism used
         in the Recursed shuffle variant. Costly (repeated slicing) but
         mechanically distinct.
[==============================================================================}
function Redealt(const A, B: MArray): MArray; overload;
begin
  if (A.Length = 0) then
    Exit(B.Clone);
  if (B.Length = 0) then
    Exit(A.Clone);
  if RandomB then
    Result := ([A[0]] + Redealt(System.Copy(A, 1, (A.Length - 1)), B))
  else
    Result := ([B[0]] + Redealt(A, System.Copy(B, 1, (B.Length - 1))));
end; 

{==============================================================================]
  <Riffle>
  @action: Randomly interleaves two arrays into one, preserving each array's
           internal element order.
  @note: Front-fill variant — fills Result from the head forward using
         RandomB, incrementing i, j, and r as A and B are consumed from
         their starts.
[==============================================================================}
function Riffle(const A, B: MArray): MArray; overload;
var
  i, j, r, x, y: Integer;
begin
  x := A.Length;
  y := B.Length;
  SetLength(Result, (x + y));
  i := 0;
  j := 0;
  r := 0;
  while ((i < x) and (j < y)) do
    if RandomB then
      Result[r.Increase] := A[i.Increase]
    else
      Result[r.Increase] := B[j.Increase];
  while (i < x) do
    Result[r.Increase] := A[i.Increase];
  while (j < y) do
    Result[r.Increase] := B[j.Increase];
end;

{==============================================================================]
  <Roulette>
  @action: Merges two arrays and shuffles their combined elements using a randomized 
           quicksort key-sorting mechanism.
  @note: This function leverages a unique randomization strategy. It generates a 
         matching-sized array of pseudo-random floating-point numbers via 'Randomal' 
         to act as sorting weights. It then uses 'QuickSorted' to order the combined 
         elements based on these random keys, resulting in a shuffled final array.
[==============================================================================}
function Roulette(const A, B: MArray): MArray; overload;
begin
  Result := A.Combine(B).QuickSorted(Randomal(A.Length + B.Length));
end;

{==============================================================================]
  <Shuffle>
  @action: Randomly interleaves two arrays into one, preserving each array's
           internal element order.
  @note: Weights the per-step draw by each side's remaining length rather
         than a fair coin, matching the Gilbert-Shannon-Reeds model of a
         physical riffle shuffle (the array with more elements left is
         proportionally more likely to be drawn from next).
[==============================================================================}
function Shuffle(const A, B: MArray): MArray; overload;
var
  i, j, r, x, y: Integer;
begin
  x := A.Length;
  y := B.Length;
  SetLength(Result, (x + y));
  i := 0;
  j := 0;
  r := 0;
  while ((i < x) and (j < y)) do
    if (Random(x - i + y - j) < (x - i)) then
      Result[r.Increase] := A[i.Increase]
    else
      Result[r.Increase] := B[j.Increase];
  while (i < x) do
    Result[r.Increase] := A[i.Increase];
  while (j < y) do
    Result[r.Increase] := B[j.Increase];
end;

{==============================================================================]
  <Wash>
  @action: Concatenates two arrays into one and completely shuffles the combined result.
  @note: This is a highly streamlined, expressive implementation. It sequentially 
         appends array B to the end of array A, and then invokes the native 
         `.Randomized` method on the entire combined pool to achieve uniform distribution.
[==============================================================================}
function Wash(const A, B: MArray): MArray; overload;
begin
  Result := A.Append(B).Randomized;
end;

{==============================================================================]
  <Any>
  @action: Returns random array item from Self.
  @note: Returns null with empty arrays.
[==============================================================================}
function MArrayHelper.Any(const null: MType): MType; overload;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[Random(Self.Size)];
end;

{==============================================================================]
  <Any>
  @action: Returns random array item from Self.
  @note: Make sure array has at least 1 item! This one is unsafe and returns error else.
[==============================================================================}
function MArrayHelper.Any: MType; overload;
begin
  Result := Self[Low(Self) + Random(Self.Size)];
end;

{==============================================================================]
  <Derange>
  @action: Shuffles Self in-place using Sattolo's algorithm, guaranteeing a
           single N-cycle permutation (no element can remain in, or return to,
           its original index).
  @note: Differs from Fisher-Yates by drawing each swap index from [0, i-1]
         instead of [0, i], excluding the current position. This trades
         uniform-permutation coverage for a guaranteed derangement w.r.t.
         cyclic structure — every element is guaranteed to move. Time
         complexity O(n), no extra allocation.
[==============================================================================}
function MArrayHelper.Derange: Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Length > 1);
  if Result then
  for i := High(Self) downto 1 do
    Self.Exch(i, Random(i));
end;

{==============================================================================]
  <Deranged>
  @action: Returns a copy of Self shuffled via Sattolo's algorithm, guaranteeing
           a single N-cycle permutation.
  @note: Non-mutating counterpart to Derange. Original array is left untouched.
         Useful whenever you need a shuffle with the "everybody moves" property
         that plain FisherYates does not guarantee (Fisher-Yates can, with
         nonzero probability, leave an element fixed in place).
[==============================================================================}
function MArrayHelper.Deranged: MArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := High(Result) downto 1 do
    Result.Exch(i, Random(i));
end;

{==============================================================================]
  <Disarray>
  @action: Shuffles (randomizes) the elements of the array.
  @note: Implements an in-place Fisher-Yates shuffle variant using an index array to populate the result without modifying the original array.
[==============================================================================}
function MArrayHelper.Disarray: MArray; overload;
var
  i, r, l: Integer;
  s: TIntegerArray;
begin
  l := Result.SetSize(Self.Length);
  if (l = 0) then
    Exit;
  s := Self.Indexes;
  i := 0;
  while (l.Decrement > -1) do
  begin
    r := Random(l + 1);
    Result[i.Increase] := Self[s[r]];
    s[r] := s[l];
  end;
end;

{==============================================================================]
  <Disindex>
  @action: Generates a shuffled (randomized) array of the original array's indices.
  @note: Implements a classic, in-place Fisher-Yates shuffle algorithm directly on an index array.
[==============================================================================}
function MArrayHelper.Disindex: TIntegerArray; overload;
var
  s: Integer;
begin
  s := Self.Length;
  Result := Self.Indexes;
  while (s.Decrement > 0) do
    Swap(Result[Random(s + 1)], Result[s]);
end;

{==============================================================================]
  <Disordered>
  @action: Returns array with randomized order (disorder)
  @note: [1,2,3] => [1,3,2] | [2,1,3] | [2,3,1] | [3,2,1] ...
[==============================================================================}
function MArrayHelper.Disordered: MArray; overload;
var
  m: TBooleanArray;
  i, r, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(Result, l);
  m.Create(l, False);
  for i := 0 to (l - 1) do
  begin
    repeat
      r := Random(l);
    until (not m[r]);
    Result[i] := Self[r];
    m[r] := True;
  end;
end;

{==============================================================================]
  <Disself>
  @action: Creates a new array containing a shuffled (randomized) copy of the original array's elements.
  @note: Implements the Inside-Out Fisher-Yates algorithm, building the shuffled result forward in O(n) time without needing temporary index tracking arrays.
[==============================================================================}
function MArrayHelper.Disself: MArray; overload;
var
  i, r, l: Integer;
begin
  l := Result.SetSize(Self.Length);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  for i := 1 to (l - 1) do
  begin
    r := Random(i + 1);
    if (r <> i) then
      Result[i] := Result[r];
    Result[r] := Self[i];
  end;
end;

{==============================================================================]
  <Draft>
  @action: Returns an array of N unique elements randomly sampled from Self, without replacement (uniform reservoir sampling).
  @note: If N >= Self.Length, returns a randomized copy of the full array. Returns an empty array if N <= 0.
[==============================================================================}
function MArrayHelper.Draft(const N: Integer = 1): MArray; overload;
var
  i, r: Integer;
begin
  if (N <= 0) then
    Exit([]);
  if (N >= Self.Length) then
    Exit(Self.Randomized);
  SetLength(Result, N);
  for i := 0 to (N - 1) do
    Result[i] := Self[i];
  for i := N to High(Self) do
  begin
    r := Random(i + 1);
    if (r < N) then
      Result[r] := Self[i];
  end;
end; 

{==============================================================================]
  <Favor>
  @action: Returns a single random element from Self where the probability of 
           selecting each element is proportional to its matching floating-point weight.
  @note: Uses a Fitness-Proportionate (Roulette Wheel) Selection algorithm. 
         The `weights` array must have the exact same length as Self. Returns 
         the default value of MType if either array is empty or lengths mismatch.
[==============================================================================}
function MArrayHelper.Favor(const weights: TDoubleArray): MType; overload;
var
  h, i: Integer;
  w, s, r: Double;
begin
  h := High(weights);
  if ((h = -1) or (High(Self) <> h)) then
    Exit(Default(MType));
  w := 0;
  for i := 0 to h do
    w := (w + weights[i]);
  r := (Random * w);
  s := 0;
  for i := 0 to h do
  begin
    s := (s + weights[i]);
    if (r <= s) then
      Exit(Self[i]);
  end;
  Result := Self[h];
end;

{==============================================================================]
  <Favor>
  @action: Returns a single random element from Self where the probability of 
           selecting each element is proportional to its matching integer weight.
  @note: Accumulates weights using a 64-bit integer to prevent overflow during 
         summation. The `weights` array must match Self's length exactly. Returns 
         the default value of MType if either array is empty or lengths mismatch.
[==============================================================================}
function MArrayHelper.Favor(const weights: TIntegerArray): MType; overload;
var
  h, i: Integer;
  w, s: Int64;
  r: Double;
begin
  h := High(weights);
  if ((h = -1) or (High(Self) <> h)) then
    Exit(Default(MType));
  w := 0;
  for i := 0 to h do
    w := (w + weights[i]);
  r := (Random * w);
  s := 0;
  for i := 0 to h do
  begin
    s := (s + weights[i]);
    if (r <= s) then
      Exit(Self[i]);
  end;
  Result := Self[h];
end;

{==============================================================================]
  <FisherYates>
  @action: Produces a uniformly random permutation (shuffle) of the array elements 
           by performing the standard Fisher‑Yates (Knuth) in‑place algorithm on 
           a copy of the source array. Each of the n! possible orderings is 
           equally likely, assuming a fair random generator.
  @note: Time complexity O(n), space complexity O(n) due to the internal copy 
         (the original array remains unchanged). The algorithm iterates from 
         the last index down to 1, swapping each position with a randomly 
         chosen earlier or equal index (0..i). This is the recommended 
         method for true random shuffling, in contrast to the biased 
         cross‑half mixing of Randsy. For cryptographic robustness, use 
         a secure random generator; otherwise, the built‑in Random() 
         suffices for general purposes.
[==============================================================================}
function MArrayHelper.FisherYates: MArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := High(Result) downto 1 do
    Result.Exch(i, Random(i + 1));
end;

{==============================================================================]
  <Mix>
  @action: Ramdomizes array with custom mixings.
  @note: None.
[==============================================================================}
function MArrayHelper.Mix(const mixings: Integer = 1): Boolean; overload;
var
  l, i, m: Integer;
begin
  Result := ((mixings > 0) and Self.Populated);
  if not Result then
    Exit;
  l := Self.Length;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Exchange(Random(l), Random(l));
end;

{==============================================================================]
  <Mixed>
  @action: Returns ramdomized array by mixing.
  @note: None.
[==============================================================================}
function MArrayHelper.Mixed(const mixings: Integer = 1): MArray; overload;
var
  l, i, m: Integer;
begin
  l := Self.Length;
  Result := Self.Copy;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
  <Mixing>
  @action: Randomizes the sequence of the array completely in-place using the 
           standard Fisher-Yates algorithm, returning the final array length.
  @note: Mutating variant of FisherYates. Unlike its counterparts, it operates 
         directly on Self with zero extra allocations, providing optimal performance 
         O(N) for in-place data modifications. Returns 0 if the array is empty.
[==============================================================================}
function MArrayHelper.Mixing: Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := (Result - 1) downto 1 do
    Self.Exch(i, Random(i + 1));
end;

{==============================================================================]
  <Muddled>
  @action: Shuffles the array by generating randomized index maps for the left 
           and right halves, then performing deterministic parallel cross-swaps.
  @note: Breaks the array indices into two separate tracking pools (excluding 
         the midpoint), shuffles those pools independently via .Mix, and then 
         swaps elements between the halves at those mixed positions. Finishes 
         by swapping the midpoint globally. Linear time complexity O(n).
[==============================================================================}
function MArrayHelper.Muddled: MArray; overload;
var
  s, m, i: Integer;
  l, r: TIntegerArray;
begin
  s := Self.Length;
  Result := Self.Copy;
  if (s < 2) then
    Exit;
  m := (s div 2);
  SetLength(l, m);
  for i := 0 to High(l) do
    l[i] := i;
  SetLength(r, (s - m - 1));
  for i := 0 to High(r) do
    r[i] := (m + 1 + i);
  l.Mix;
  r.Mix;
  for i := 0 to (Min(l.Length, r.Length) - 1) do
    Result.Exch(l[i], r[i]);
  Result.Exch(m, Random(s));
end;

{==============================================================================]
  <Raffle>
  @action: Returns a new array containing a specified number of randomly selected, 
           unique elements from the source array (a random sample without replacement).
  @note: Uses a partial Fisher-Yates shuffle algorithm for O(k) efficiency, ensuring 
         unbiased randomness. Original array remains unmodified.
[==============================================================================}
function MArrayHelper.Raffle(const rCount: Integer = 1): MArray; overload;
var
  i, l: Integer;
begin
  if (rCount <= 0) then
    Exit([]);
  if (rCount >= Self.Length) then
    Exit(Self.Randomized);
  Result := Self.Copy;
  l := Result.Length;
  for i := 0 to (rCount - 1) do
    Result.Exch(i, (i + Random(l - i)));
  SetLength(Result, rCount);
end;

{==============================================================================]
  <Randex>
  @action: Selects `N` unique, random indices from the array, returning them in a randomized order.
  @note: Uses a partial Fisher-Yates shuffle algorithm for optimal performance ($O(N)$ time complexity).
         If `N` meets or exceeds the array's length, it safely returns all indices scrambled.
[==============================================================================}
function MArrayHelper.Randex(const N: Integer = 1): TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (N >= l) then
    Exit(Self.Randices);
  Result := Self.Indexes;
  for i := 0 to (N - 1) do
    Swap(Result[i], Result[i + Random(l - i)]);
  SetLength(Result, N);
end;

{==============================================================================]
  <Randiced>
  @action: Returns a randomly ordered array of all valid indices (0..High(Self)).
  @note: Equivalent to Self.Indexes.FisherYates.
[==============================================================================}
function MArrayHelper.Randiced: TIntegerArray; overload;
begin
  Result := Self.Indexes.FisherYates;
end;

{==============================================================================]
  <Randices>
  @action: Returns a randomly ordered array of all valid indices (0..High(Self)).
  @note: Useful for parallel iteration or non-destructive random access.
[==============================================================================}
function MArrayHelper.Randices: TIntegerArray; overload;
begin
  Result := Self.Indexes.Mixed;
end;

{==============================================================================]
  <Randicing>
  @action: Generates a completely shuffled array of all available indices from the source array.
  @note: Uses a random-key weights approach by pairing sequential indices with random floating-point values
         and sorting them via a weighted QuickSort. Time complexity is $O(L \log L)$, where $L$ is the array length.
[==============================================================================}
function MArrayHelper.Randicing: TIntegerArray; overload;
var
  i: Integer;
  k: TDoubleArray;
begin
  for i := 0 to (Result.SetSize(k.SetSize(Self.Length)) - 1) do
  begin
    Result[i] := i;
    k[i] := Random;
  end;
  Result.QuickSortWeighted(k);
end;

{==============================================================================]
  <Randomed>
  @action: Returns a new array with the elements shuffled into a random order.
  @note: Uses a random-weight quicksort approach to achieve the shuffle. 
         Does not mutate the original array.
[==============================================================================}
function MArrayHelper.Randomed: MArray; overload;
var
  i, l: Integer;
  w: TDoubleArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(w, l);
  for i := 0 to (l - 1) do
    w[i] := Random;
  Result := Self.QuickSorted(w);
end;

{==============================================================================]
  <Randomise>
  @action: Shuffles the elements of the array randomly in-place.
  @return: The total number of elements (Length) in the array.
  @note: Implements an efficient, unbiased Fisher-Yates shuffle. Relies on 
         the internal .Exch() helper and a custom .Decrement iterator.
[==============================================================================}
function MArrayHelper.Randomise: Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  Result := l;
  while (l.Decrement > -1) do
    Self.Exch(Random(l + 1), l);
end;

{==============================================================================]
  <Randomised>
  @action: Returns a completely shuffled copy of the current array instance.
  @note: Implements a classic, in-place Fisher-Yates (Knuth) shuffle algorithm 
         using a temporary index-tracking array (`s`). By shuffling indices 
         rather than the data objects themselves, it ensures an unbiased, 
         unbound random distribution with $O(N)$ efficiency.
[==============================================================================}
function MArrayHelper.Randomised: MArray; overload;
var
  s: TIntegerArray;
  l, r: Integer;
begin
  l := Result.SetSize(Self.Length);
  if (l = 0) then
    Exit;
  s := Self.Indexes;
  while (l.Decrement > 0) do
  begin
    r := Random(l + 1);
    Result[l] := Self[s[r]];
    s[r] := s[l];
  end;
  Result[0] := Self[s[0]];
end;

{==============================================================================]
  <Randomized>
  @action: Returns randomized copy of array
  @note: None.
[==============================================================================}
function MArrayHelper.Randomized: MArray; overload;
var
  s, l, r: Integer;
  i: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(Result, l);
  i := Self.Indexes;
  for s := 0 to High(Self) do
  begin
    r := Random(l);
    Result[i[r]] := Self[s];
    i[r] := i[l.Decrement];
  end;
end;

{==============================================================================]
  <Randomned>
  @action: Returns a new array containing Self's elements in uniformly
           random order, leaving Self unmodified.
  @note: Pre-generates the full pool of random values in a single pass
         before any swapping occurs (rather than calling Random inline
         per swap), then performs a standard Fisher-Yates shuffle via
         Exch, consuming the pre-generated pool with mod (i + 1). Minor,
         practically negligible modulo bias versus a division-based
         unbiased range reduction.
[==============================================================================}
function MArrayHelper.Randomned: MArray; overload;
var
  i: Integer;
  r: TIntegerArray;
begin
  Result := Self.Cloned;
  if (Result.Length < 2) then
    Exit;
  SetLength(r, Result.Length);
  for i := 0 to High(r) do
    r[i] := Random(High(Integer));
  for i := High(Result) downto 1 do
    Result.Exch(i, (r[i] mod (i + 1)));
end;

{==============================================================================]
  <Randsy>
  @action: Shuffles the array by partitioning it into left and right halves 
           and cross-swapping elements over the midpoint boundary with a slight 
           random overlap into the boundary zones.
  @note: Elements in the left half swap into the right range (potentially bleeding 
         into the midpoint/left edge), elements in the right half swap into the 
         left range (potentially bleeding into the midpoint/right edge), and the 
         center pivot element swaps globally. Linear time complexity O(n).
[==============================================================================}
function MArrayHelper.Randsy: MArray; overload;
var
  i, s, m: Integer;
  l, r: TRange;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(Self.Copy);
  if (s < 5) then
    Exit(Self.Randomized);
  m := (s div 2);
  l.Create(0, (m - 1));
  r.Create((m + 1), (s - 1));
  Result := Self.Copy;
  for i := 0 to (s - 1) do
  case i.Compare(m) of
    0: Result.Exch(i, Random(s));
    -1: Result.Exch(i, (r.Rand - Random(2)));
    1: Result.Exch(i, (l.Rand + Random(2)));
  end;
end;

{==============================================================================]
  <Recomposed>
  @action: Recursively splits the array and weaves the halves back together.
  @note: Uses a divide-and-conquer strategy. It clones arrays of length < 2,
         otherwise splits the array down the middle, recursively recomposes 
         both halves, and interleaves them using the Riffle method.
[==============================================================================}
function MArrayHelper.Recomposed: MArray; overload;
var
  M, S: Integer;
  L, R: MArray;
begin
  S := Self.Length;
  if (S < 2) then
    Exit(Self.Clone);
  M := (S div 2);
  L := System.Copy(Self, 0, M).Recomposed;
  R := System.Copy(Self, M, (S - M)).Recomposed;
  Result := Riffle(L, R);
end;

{==============================================================================]
  <Scoop>
  @action: Returns a new array containing a specified number of randomly selected 
           elements from the source array, allowing for duplicate selections.
  @note: Implements random sampling with replacement, identical in behavior to 
         Sweepstake but optimized using inline dynamic array resizing via 
         Result.SetSize(). Safely handles edge cases by forcing a size of 0 if 
         the source array is empty or if sCount is less than 1.
[==============================================================================}
function MArrayHelper.Scoop(const sCount: Integer = 1): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  for i := 0 to (Result.SetSize(Integer(l > 0) * (Max(0, sCount))) - 1) do
    Result[i] := Self[Random(l)];
end;

{==============================================================================]
  <Scramble>
  @action: Returns scrambled array, that is randomized with offset and swapping.
  @note: Supports custom swaps.
[==============================================================================}
function MArrayHelper.Scramble(const swaps: Integer = -1): MArray; overload;
var
  o, i, l, s: Integer;
begin
  l := Self.Length;
  o := Random(l);
  s := IfThen((swaps < 0), l, swaps);
  Result := Self.Copy(o, (l - o)) + Self.Copy(0, o);
  for i := 1 to s do
    Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
  <Shake>
  @action: Returns array as randomized with shaking it.
  @note: None.
[==============================================================================}
function MArrayHelper.Shake(const shakes: Integer = 1): MArray; overload;
var
  i, s: Integer;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
  for s := 1 to shakes do
    for i := 0 to Random(Self.Size) do
      Swap(Result[i], Result[Random(Self.Size)]);
end;

{==============================================================================]
  <Shuffle>
  @action: Returns array as randomized with shuffling it.
  @note: None.
[==============================================================================}
function MArrayHelper.Shuffle(const shuffles: Integer = 1): MArray; overload;
var
  i, s: Integer;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
  for s := 1 to shuffles do
    for i := 0 to High(Result) do
      Swap(Result[i], Result[Random(Self.Size)]);
end;

{==============================================================================]
  <Shuffled>
  @action: Returns a new multi-dimensional array (MArray) containing the elements of the current array randomized into a shuffled sequence.
  @note: Handles edge cases for empty or single-element arrays instantly,
         and uses an external index permutation system (`Indexes.Mix`) to safely map old elements to new positions.
[==============================================================================}
function MArrayHelper.Shuffled(const mixings: Integer = 1): MArray; overload;
var
  r, l: Integer;
  i: TIntegerArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit(Self.Cloned);
  else
    SetLength(Result, l);
  end;
  i := Self.Indexes;
  i.Mix(mixings);
  for r := 0 to (l - 1) do
    Result[r] := Self[i[r]];
end;

{==============================================================================]
  <Shufflist>
  @action: Returns a new array with all elements randomly shuffled.
  @note: Leverages Delphi's native TList<T>.Shuffle method for an efficient, 
         built-in Fisher-Yates implementation. Does not mutate the original array.
[==============================================================================}
function MArrayHelper.Shufflist: MArray; overload;
var
  l: specialize TList<MType>;
  i: Integer;
begin
  l := specialize TList<MType>.Create;
  try
    for i := 0 to High(Self) do
      l.Add(Self[i]);
    for i := (l.Count - 1) downto 1 do
      l.Exchange(i, Random(i + 1));
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Shuffly>
  @action: Shuffles the array instance in-place on a duplicated copy, returning a 
           randomized version of the original array.
  @note: Implements the text-book Fisher-Yates (Knuth) shuffle algorithm. It clones 
         the current array and iterates backward from the highest index down to 1, 
         swapping the element at the current position with an element at a randomly 
         selected lower or equal index.
[==============================================================================}
function MArrayHelper.Shuffly: MArray; overload;
var
  i: Integer;
begin
  Result := Self.Clone;
  for i := High(Result) downto 1 do
    Swap(Result[i], Result[Random(i + 1)]);
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function MArrayHelper.Some: MArray; overload;
begin
  Result := Self.Shuffle.Copy(0, Max(Random(Self.Size + 1), 1));
end;

{==============================================================================]
  <Some>
  @action: Returns amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function MArrayHelper.Some(const amount: Integer): MArray; overload;
begin
  Result := Self.Shuffle.Copy(0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <Sweepstake>
  @action: Returns a new array containing a specified number of randomly selected 
           elements from the source array, allowing the same element to be chosen multiple times.
  @note: Implements random sampling with replacement (independent draws). This 
         differs from Raffle, as duplicate selections can occur. If sCount is 
         greater than the source array's length, the resulting array will safely 
         be populated entirely with repeating random elements.
[==============================================================================}
function MArrayHelper.Sweepstake(const sCount: Integer = 1): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if ((l = 0) or (sCount < 1)) then
    Exit([]);
  SetLength(Result, sCount);
  for i := 0 to (sCount - 1) do
    Result[i] := Self[Random(l)];
end;

{==============================================================================]
  <Unsettle>
  @action: Randomly permutes Self in place via Sattolo's algorithm (no
           element retains its original index), then performs one
           additional unconstrained random swap. Returns the array's
           new length.
  @note: The final swap can select the same index twice (no-op) or any
         two arbitrary positions, so — unlike Derange — the strict
         no-fixed-point guarantee is not preserved after this call.
[==============================================================================}
function MArrayHelper.Unsettle: Integer; overload;
var
  i, r: Integer;
begin
  Result := Self.Length;
  for i := (Result - 1) downto 1 do
    Self.Exch(i, Random(i));
  if (Result > 1) then
    Self.Exch(Random(Result), Random(Result));
end;

{==============================================================================]
  <Unsettled>
  @action: Returns a new array containing Self's elements permuted via
           Sattolo's algorithm (no element retains its original index),
           followed by one additional unconstrained random swap. Self is
           left unmodified.
  @note: Non-mutating twin of Unsettle. The final swap can select the
         same index twice (no-op) or any two arbitrary positions, so —
         unlike Deranged — the strict no-fixed-point guarantee is not
         preserved in the returned array.
[==============================================================================}
function MArrayHelper.Unsettled: MArray; overload;
var
  i: Integer;
begin
  Result := Self.Clone;
  for i := High(Result) downto 1 do
    Result.Exch(i, Random(i));
  if (Result.Length > 1) then
    Result.Exch(Random(Result.Length), Random(Result.Length));
end;
{$ENDIF}
