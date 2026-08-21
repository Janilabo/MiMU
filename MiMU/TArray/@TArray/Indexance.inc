{$IFDEF HELPERS}
function Disindex: TIntegerArray; overload;
function Randex(const N: Integer = 1): TIntegerArray; overload;
function Randiced: TIntegerArray; overload;
function Randices: TIntegerArray; overload;
function Randicing: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
