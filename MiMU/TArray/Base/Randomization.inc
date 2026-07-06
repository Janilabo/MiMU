{$IFDEF HELPERS}
function Any(const null: MType): MType; overload;
function Any: MType; overload;
function Disordered: MArray; overload;
function FisherYates: MArray; overload;
function Mix(const mixings: Integer = 1): Boolean; overload;
function Mixed(const mixings: Integer = 1): MArray; overload;
function Muddled: MArray; overload;
function Randomed: MArray; overload;
function Randomized: MArray; overload;
function Randsy: MArray; overload;
function Scramble(const swaps: Integer = -1): MArray; overload;
function Shake(const shakes: Integer = 1): MArray; overload;
function Shuffle(const shuffles: Integer = 1): MArray; overload;
function Shuffled(const mixings: Integer = 1): MArray; overload;
function Shufflist: MArray; overload;
function Some: MArray; overload;
function Some(const amount: Integer): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
