{$IFDEF HELPERS}
function Exch(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(var b: MArray): Integer; overload;
function Exchange(const swaps: TConnectionArray): MArray; overload;
function Exchanges(const target: MArray): TConnectionArray; overload;
function Movement(const moves: TConnectionArray): MArray; overload;
function Movements(const target: MArray): TConnectionArray; overload;
function Reposition(const oldIndex, newIndex: Integer): Boolean; overload;
function Swapped(var target: MArray): Integer; overload;
function Trade(var b: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Exch>
  @action: Fast version of Exchange().
  @note: Unsafe, no checking.
[==============================================================================}
function MArrayHelper.Exch(const aIndex, bIndex: Integer): Boolean; overload;
var
  c: MType;
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;

{==============================================================================]
  <Exchange>
  @action: Swap items aIndex and bIndex in array arr.
  @note: Returns true with success.
[==============================================================================}
function MArrayHelper.Exchange(const aIndex, bIndex: Integer): Boolean; overload;
var
  c: MType;
  h: Integer;
begin
  h := High(Self);
  Result := ((h > 0) and (aIndex <> bIndex) and InRange(aIndex, 0, h) and InRange(bIndex, 0, h) and (Self[aIndex] <> Self[bIndex]));
  if Result then
  begin
    c := Self[aIndex];
    Self[aIndex] := Self[bIndex];
    Self[bIndex] := c;
  end;
end;

{==============================================================================]
  <Exchange> 
  @action: Swaps array arr and array b.
  @note: arr will be b and b will be arr.
[==============================================================================}
function MArrayHelper.Exchange(var b: MArray): Integer; overload;
var
  a: MArray;
begin
  Result := (Self.Size + b.Size);
  if (Result = 0) then
    Exit;
  a := Self.Dupe;
  Self := b.Dupe;
  b := a.Dupe;
  SetLength(a, 0);
end;

{==============================================================================]
  <Exchange>
  @action: Applies a sequence of swaps (from <arr.Exchanges>) to the current
           array (Self), producing a new array reflecting all swaps performed.
  @note: - Each swap exchanges two indices (id1,id2).
         - The input swap list must be compatible with the array length.
         - Commonly used to replay sorting animations or verify transformations.
[==============================================================================}
function MArrayHelper.Exchange(const swaps: TConnectionArray): MArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(swaps) do
    Swap(Result[swaps[i].id1], Result[swaps[i].id2]);
end;

{==============================================================================]
  <Exchanges>
  @action: Generates a sequence of adjacent swaps (id1,id2) required to
           transform the current array (Self) into the target array.
           Each swap exchanges two neighboring elements.
  @note: - Returns an array of TConnection records (id1,id2 swapped).
         - The swaps are replayable with <arr.Exchange>.
         - Ideal for sorting visualizations or swap-based replay systems.
         - All swaps are adjacent, producing stable step-by-step transitions.
[==============================================================================}
function MArrayHelper.Exchanges(const target: MArray): TConnectionArray; overload;
var
  i, j: Integer;
  s: MArray;
begin
  s := Self.Copy;
  SetLength(Result, 0);
  for i := 0 to High(target) do
  begin
    for j := i to High(s) do
      if (s[j] = target[i]) then
        Break;
    while (j > i) do
    begin
      SetLength(Result, (System.Length(Result) + 1));
      Result[High(Result)].Create((j - 1), j);
      s[j] := s[j - 1];
      s[j.Decrement] := target[i];
    end;
  end;
end;

{==============================================================================]
  <Movement>
  @action: Applies a sequence of movements (from <arr.Movements>) to the
           current array (Self), returning the resulting array.
  @note: - Each movement shifts elements between indices, not just swapping.
         - Movements preserve the array’s relative ordering behavior.
         - The input move set is assumed valid for the given array.
[==============================================================================}
function MArrayHelper.Movement(const moves: TConnectionArray): MArray; overload;
var
  t: MType;
  i, j, c: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(moves) do
  begin
    c := moves[i].id1.Compare(moves[i].id2);
    if (c = 0) then
      Continue;
    t := Result[moves[i].id1];
    case c of
      -1:
      for j := moves[i].id1 to (moves[i].id2 - 1) do
        Result[j] := Result[j + 1];
      1:
      for j := moves[i].id1 downto (moves[i].id2 + 1) do
        Result[j] := Result[j - 1];
    end;
    Result[moves[i].id2] := t;
  end;
end;

{==============================================================================]
  <Movements>
  @action: Generates a list of element movements required to transform the
           current array (Self) into the target array. Each movement represents
           relocating an element from one index to another, shifting intervening
           elements accordingly (like insertion).
  @note: - Returns an array of TConnection records (id1 = from, id2 = to).
         - The operations are positional (preserve relative order of others).
         - Can be reversed/applied using <arr.Movement>.
         - Useful for visualizing "element movement" sorting.
[==============================================================================}
function MArrayHelper.Movements(const target: MArray): TConnectionArray; overload;
var
  t: MType;
  i, j, k: Integer;
  s: MArray;
begin
  s := Self.Copy;
  SetLength(Result, 0);
  for i := 0 to High(target) do
  begin
    for j := i to High(s) do
      if (s[j] = target[i]) then
        Break;
    if (j <> i) then
    begin
      SetLength(Result, (System.Length(Result) + 1));
      Result[High(Result)].Create(j, i);
      t := s[j];
      case (j > i) of
        True:
        for k := j downto (i + 1) do
          s[k] := s[k - 1];
        False:
        for k := j to (i - 1) do
          s[k] := s[k + 1];
      end;
      s[i] := t;
    end;
  end;
end;

{==============================================================================]
  <Reposition>
  @action: Moves item from oldIndex to newIndex in array arr.
  @note: Returns true with success.
[==============================================================================}
function MArrayHelper.Reposition(const oldIndex, newIndex: Integer): Boolean; overload;
var
  s: MType;
  h, i: Integer;
begin
  h := High(Self);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    s := Self[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        Self[i] := Self[i - 1];
      False:
      for i := oldIndex to (newIndex - 1) do
        Self[i] := Self[i + 1];
    end;
    Self[newIndex] := s;
  end;
end;

{==============================================================================]
  <Swapped>
  @action: Swaps the contents of this array with the given target array.
  @note: The swap is O(1) because dynamic arrays are reference-counted.
         Returns Length(Self) + Length(target) after the swap.
[==============================================================================}
function MArrayHelper.Swapped(var target: MArray): Integer; overload;
var
  t: MArray;
begin
  t := Self;
  Self := target;
  target := t;
  Result := (Self.Size + target.Size);
end;

{==============================================================================]
  <Trade> 
  @action: Swaps array arr and array b.
  @note: arr will be b and b will be arr.
[==============================================================================}
function MArrayHelper.Trade(var b: MArray): Integer; overload;
var
  a: MArray;
begin
  Result := (Self.Size + b.Size);
  if (Result > 0) then
  begin
    a := Self.Copy;
    Self := b.Copy;
    b := a.Copy;
    SetLength(a, 0);
  end;
end;
{$ENDIF}