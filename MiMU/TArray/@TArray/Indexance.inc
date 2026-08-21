{$IFDEF HELPERS}
function Defixed: TIntegerArray; overload;
function Disid: TIntegerArray; overload;
function Disindex: TIntegerArray; overload;
function Disindiced: TIntegerArray; overload;
function Randex(const N: Integer = 1): TIntegerArray; overload;
function Randexed: TIntegerArray; overload;
function Randiced: TIntegerArray; overload;
function Randices: TIntegerArray; overload;
function Randicing: TIntegerArray; overload;
function Refixed: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Defixed>
  @action: Returns a randomly generated derangement of Self's indices (0..High(Self)) — a permutation in which no index appears at its own original position.
  @note: Starts from the identity permutation and repeatedly resolves fixed points by swapping each one with a randomly chosen index, rescanning until none remain.
         No derangement exists for a single-element array (n = 1), so that case returns the identity [0] unavoidably.
         Not a uniform-random derangement — the resolution order and rescan-from-start approach bias the resulting distribution;
         use Deranged (Sattolo's algorithm) instead if uniform-among-derangements matters. Less efficient than Deranged due to full rescans after each fix.
[==============================================================================}
function MArrayHelper.Defixed: TIntegerArray; overload;
var
  l, i: Integer;
  f: Boolean;
begin
  Result := Self.Indexes;
  l := Result.Length;
  if (l > 1) then
  repeat
    f := False;
    for i := 0 to (l - 1) do
      if (Result[i] = i) then
      begin
        Result.Switch(i, Random(l));
        f := True;
        Break;
      end;
  until not f;
end;

{==============================================================================]
  <Disid>
  @action: Returns a randomly shuffled array of Self's indices (0..High(Self)),
           guaranteed to be a derangement — no index ever appears at its own original position.
  @note: Implements Sattolo's algorithm (a one-character variant of Fisher-Yates: swaps against 0..s-1 instead of 0..s).
         This is NOT a uniform-random shuffle — the identity permutation and all permutations with any fixed point are excluded by construction,
		 biasing the result toward full-cycle derangements. Do not use as a drop-in replacement for Disindiced/Randiced where uniformity matters.
[==============================================================================}
function MArrayHelper.Disid: TIntegerArray; overload;
var
  s: Integer;
begin
  s := Self.Length;
  Result := Self.Indexes;
  while (s.Decrement > 0) do
    Swap(Result[Random(s)], Result[s]);
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
  <Disindiced>
  @action: Returns a randomly shuffled array of Self's indices (0..High(Self)), each index appearing exactly once.
  @note: Standard in-place Fisher-Yates shuffle applied to a working copy of Self.Indexes;
         Self itself is never mutated.
[==============================================================================}
function MArrayHelper.Disindiced: TIntegerArray; overload;
var
  r: Integer;
begin
  Result := Self.Indexes;
  for r := High(Self) downto 1 do
    Result.Exch(Random(r + 1), r);
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
  <Randexed>
  @action: Returns a randomly shuffled array of Self's indices (0..High(Self)), each index appearing exactly once.
  @note: Uses rejection sampling: repeatedly generates a random candidate index and retries on collision (tracked via a used-flags array) until an unused one is found.
         Unlike Disindiced's swap-based Fisher-Yates (strict O(n)), this degrades toward the classic coupon-collector bound as the array fills — expected O(n log n) comparisons,
		 with a longer tail for large arrays. Prefer Disindiced unless this specific mechanism is needed.
[==============================================================================}
function MArrayHelper.Randexed: TIntegerArray; overload;
var
  s, i, r: Integer;
  u: TBooleanArray;
begin
  s := Result.SetSize(Self.Length);
  if (s = 0) then
    Exit;
  u.Create(s, False);
  for i := 0 to High(Result) do
  begin
    repeat
      r := Random(s);
    until not u[r];
    u[r] := True;
    Result[i] := r;
  end;
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
  <Refixed>
  @action: Returns a randomly generated derangement of Self's indices (0..High(Self)) — a permutation in which no index appears at its own original position.
  @note: Repeatedly generates a complete Fisher-Yates shuffle and checks whether it happens to have zero fixed points, retrying with a fresh full shuffle if any are found.
         No derangement exists for a single-element array (n = 1), so that case returns the identity [0] unavoidably. Expected number of shuffle attempts converges to e (~2.718) for n >= ~5,
		 per derangement probability theory. Distinct from Defixed (which repairs individual fixed points in place rather than discarding and reshuffling the whole array) and Deranged (Sattolo's algorithm,
		 a single deterministic O(n) pass with no retries).
[==============================================================================}
function MArrayHelper.Refixed: TIntegerArray; overload;
var
  h, i: Integer;
  o: Boolean;
begin
  Result := Self.Indexes;
  h := High(Result);
  if (h > 0) then
  repeat
    for i := h downto 1 do
      Result.Switch(i, Random(i + 1));
    o := True;
    for i := 0 to h do
      if (Result[i] = i) then
      begin
        o := False;
        Break;
      end;
  until o;
end;
{$ENDIF}
