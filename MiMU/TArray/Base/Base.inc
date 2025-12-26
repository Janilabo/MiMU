{$IFDEF HELPERS}
{$I Base.pph}

function Any(const null: MType): MType; overload;
function Any: MType; overload;  
function Blend(const items: MArray; const index: Integer = 2147483647): MArray; overload;
function Clear: Boolean; overload;
function Clone(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Clone(const ID: TIntegerArray): MArray; overload;
function Cloned: MArray; overload;
function Combine(const b: MArray): MArray; overload;
function Compact: Integer; overload;
function Compacted: MArray; overload;
function Compacted(const threshold: Integer): MArray; overload;
function Compress: Integer; overload;
function Compressed: MArray; overload;
function Compressed(const threshold: Integer): MArray; overload;
function Copied: MArray; overload;
function Copy(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Count(const item: MType): Integer; overload;
function Count(const items: MArray): Integer; overload;
function Deduplicated: MArray; overload;
function Disordered: MArray; overload;
function Distinct: Integer; overload;
function Diversified: MArray; overload;
function DiversifiedEx(const dAscending: Boolean = True): MArray; overload;
function Domain: TRange; overload;
function Dupe: MArray; overload;
function Duplicate(const xTimes: Integer = 1): MArray; overload;
function Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): MArray; overload;
function Exch(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(var b: MArray): Integer; overload;
function Exchange(const swaps: TConnectionArray): MArray; overload;
function Exchanges(const target: MArray): TConnectionArray; overload;
function Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Free: Integer; overload;
function FromLeft(const count: Integer; const index: Integer = 2147483647): MArray; overload;
function FromRight(const count: Integer; const index: Integer = 0): MArray; overload;
function Get: MArray; overload;
function Get(const ID: TIntegerArray): MArray; overload;
function Get(const ID: TRange): MArray; overload;
function IntersectionCounted(const items: MArray): Integer; overload;
function Kill: Integer; overload;
function LeastCommon: MType; overload;
function LeastFrequent: MType; overload;
function Length: Integer; overload;
function Mix(const mixings: Integer = 1): Boolean; overload;
function Mixed(const mixings: Integer = 1): MArray; overload;
function MostCommon: MType; overload;
function MostFrequent: MType; overload;
function Movement(const moves: TConnectionArray): MArray; overload;
function Movements(const target: MArray): TConnectionArray; overload;
function Next(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Overlay(const items: MArray; const index: Integer; const init: MType): MArray; overload;
function Overlay(const items: MArray; const index: Integer = 0): MArray; overload;
function Patch(const index: Integer; const items: MArray): Integer; overload;
function Pick(const items: MArray; const index: Integer = 0): MArray; overload;
function Pop: MType; overload;
function Pop(const null: MType): MType; overload;
function Populate(const items: MArray; const times: Integer = 1): Boolean; overload;
function Populate(const item: MType; const times: Integer = 1): Boolean; overload;
function Previous(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Prune: Integer; overload;
function Pruned: MArray; overload;
function Pruned(const threshold: Integer): MArray; overload;
function Pull: MArray; overload;
function Purified(const dAscending: Boolean = True): MArray; overload;
function Purify(const dAscending: Boolean = True): Integer; overload;
function Randomized: MArray; overload;
function Range(const subArray: MArray; const index: Integer = 0): TRange; overload;
function Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload;
function Recreate(const arrSize: Integer): Boolean; overload;
function Reposition(const oldIndex, newIndex: Integer): Boolean; overload;
function Reset: Integer; overload;
function Resize(const aChange: Integer): Integer; overload;
function Resize(const aChange: Integer; const null: MType): Integer; overload;
function Sample(const sSize: Integer): MArray; overload;
function Scramble(const swaps: Integer = -1): MArray; overload;
function Shake(const shakes: Integer = 1): MArray; overload;
function Shift: MType; overload;
function Shift(const sCount: Integer): MArray; overload;
function Shuffle(const shuffles: Integer = 1): MArray; overload;
function Singlify(const item: MType): Integer; overload;
function Singlified(const item: MType): MArray; overload;
function Singularize(const item: MType): Integer; overload;
function Singularized(const item: MType): MArray; overload;
function Soloize(const item: MType): Integer; overload;
function Soloized(const item: MType): MArray; overload;
function Size: Integer; overload;
function Size(const aSize: Integer): MArray; overload;
function Size(const aSize: Integer; const null: MType): MArray; overload;
function Slice(const r: TRange): MArray; overload;
function Slice(const r: TRangeArray): MArray; overload;
function Some: MArray; overload;
function Some(const amount: Integer): MArray; overload;
function Span: TRange; overload;
function Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload;
function Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload;
function Swapped(var target: MArray): Integer; overload;
function SwapMerged(var target: MArray): MArray; overload;
function SwappedMerge(var target: MArray): MArray; overload;
function Trade(var b: MArray): Integer; overload;
function Uncluttered: MArray; overload;
function Uniformity: Double; overload;
function Unified(const dAscending: Boolean = True): MArray; overload;
function Unify(const dAscending: Boolean = True): Integer; overload;
function Unduplicated: MArray; overload;
function Uniqued: MArray; overload;
function Uniques: TIntegerArray; overload;
function Unshift(const item: MType): MArray; overload;
function Unshift(const items: MArray): MArray; overload;
function Waste: Integer; overload;
function Zigzag(const zAscending: Boolean = True): MArray; overload;
{$IFDEF Sortable}
function Sortable: Boolean; overload;
function Sorted(const aAscending: Boolean = True): Boolean; overload;
function IsSorted(const aAscending: Boolean = True): Boolean; overload;
function IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload;
function IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload;
function IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload;
function InOrder(const aAscending: Boolean = True): Boolean; overload;
function Orderly: Boolean; overload;
function Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
function Order: Integer; overload;
function Orientation: Integer; overload;
function Descend: MArray; overload;
function Ascend: MArray; overload;
function Descending: Boolean; overload;
function Ascending: Boolean; overload;
function Decreasing: Boolean; overload;
function Increasing: Boolean; overload;
function Downward: Boolean; overload;
function Upward: Boolean; overload;
function Lowest: MType; overload;
function Highest: MType; overload;
function Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function Mode: MType; overload;
function Center: MType; overload;
function MergeSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
function MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
function QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSorted(const aAscending: Boolean = True): MArray; overload;
function QuickSort(const aAscending: Boolean = True): Integer; overload;
function QuickSort3W(const aAscending: Boolean = True): Integer; overload;
function QSort(const aAscending: Boolean = True): Integer; overload;  
function PartitionSort(const aAscending: Boolean = True): Integer; overload;
function CoctailSort(const aAscending: Boolean = True): Integer; overload;
function CoctailSort2(const aAscending: Boolean = True): Integer; overload;
function GnomeSort(const aAscending: Boolean = True): Integer; overload;
function GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
function PancakeSort(const aAscending: Boolean = True): Integer; overload;
function BubbleSort(const aAscending: Boolean = True): Integer; overload;
function BubbleSort2(const aAscending: Boolean = True): Integer; overload;
function BubbleSortOptimized(const aAscending: Boolean = True): Integer; overload;
function CombSort(const aAscending: Boolean = True): Integer; overload;
function HeapSort(const aAscending: Boolean = True): Integer; overload;
function InsertionSort(const aAscending: Boolean = True): Integer; overload;
function SelectionSort(const aAscending: Boolean = True): Integer; overload;
function SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
function SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
function ShellSort(const aAscending: Boolean = True): Integer; overload;
function MergeSort(const aAscending: Boolean = True): Integer; overload;
function MergeSortBU(const aAscending: Boolean = True): Integer; overload;
function HybridSort(const aAscending: Boolean = True): Integer; overload;
function Uniq(const sSorted: Boolean = False): MArray; overload;
function Downtrending: Boolean; overload;
function Uptrending: Boolean; overload;
function Notrending: Boolean; overload;
function Trend: Integer; overload;
function Trending: Boolean; overload;
function Rising: Boolean; overload;
function Falling: Boolean; overload;
function Direction: Integer; overload;
function TrendFalling: Boolean; overload;
function TrendRising: Boolean; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function Sortedness: Boolean; overload;
function SortednessEx(const stride: Integer = 16): Boolean; overload;
function Monotonic: Boolean; overload;
function Monotone: Boolean; overload;
function IsMonotone: Boolean; overload;
function Monotonious: Boolean; overload;
function Unidirectional: Boolean; overload;
function Trendy: Boolean; overload;
function OnOrder: Boolean; overload;
function Peaks: TIntegerArray; overload;
function Valleys: TIntegerArray; overload;
function Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function IntersectionCount(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
function CountOf(const items: MArray; const iAscending: Boolean = True): Integer; overload;
function Counted(const items: MArray; const iSorted: Boolean = False): Integer; overload;
function MinItem: MType; overload;
function MinItem(const null: MType): MType; overload;
function MaxItem: MType; overload;
function MaxItem(const null: MType): MType; overload;
function Minimum(var index: Integer): MType; overload;
function Minimum: MType; overload;
function Maximum(var index: Integer): MType; overload;
function Maximum: MType; overload;
function Minim(var index: Integer): MType; overload;
function Minim: MType; overload;
function Maxim(var index: Integer): MType; overload;
function Maxim: MType; overload;
function WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF CLASSES}
{$IFDEF T1D}
class function Create(const item: MType; const aSize: Integer = 1): MArray; overload;
{$ENDIF}

{$IF DEFINED(TBS) AND DEFINED(Sortable)}
class function Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Base.pph}

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
  <Blend> 
  @action: Blends items with array, cleverly.
  @note: None.
[==============================================================================}
function MArrayHelper.Blend(const items: MArray; const index: Integer = 2147483647): MArray; overload;
var
  s, l, p, r, i: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(items.Copy);
  l := items.Size;
  if (l = 0) then
    Exit(Self.Copy);
  case (index > 0) of
    True:
    begin
      p := index;
      if (p > s) then
        p := s;
      r := (p + l);
      SetLength(Result, r);
      for i := 0 to (p - 1) do
        Result[i] := Self[i];
      for i := 0 to (l - 1) do
        Result[p + i] := items[i];
    end;
	False:
    begin
      p := ((s + index) - 1);
      if (p < 0) then
        p := 0;
      r := (l + (s - p));
      SetLength(Result, r);
      for i := 0 to (l - 1) do
        Result[i] := items[i];
      for i := p to (s - 1) do
        Result[l + (i - p)] := Self[i];
    end;
  end;
end;

{==============================================================================]
  <Clear>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function MArrayHelper.Clear: Boolean; overload;
begin
  Result := (Self.Length > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Clone>
  @action: Returns copy of an array arr.
  @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function MArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  i, s, c: Integer;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Self.Size - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[i - s] := Self[i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Clone>
  @action: Outputs array of items from arr by indexes (ID).
  @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[==============================================================================}
function MArrayHelper.Clone(const ID: TIntegerArray): MArray; overload;
var
  i, h, l, r: Integer;
begin
  r := 0;
  if (ID.Populated and Self.Populated) then
  begin
    h := High(Self);
    l := ID.Size;
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((ID[i] <= h) and (ID[i] > -1)) then
        Result[r.Increase] := Self[ID[i]];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Cloned>
  @action: Simply returns a clone of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Cloned: MArray; overload;
var
  r: TRange;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Self.Size);
  r.Create(-1, Result.Size);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.start];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.stop];
  end;
end;

{==============================================================================]
  <Compact>
  @action: Removes adjacent duplicates.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Compact: Integer; overload;
var
  i: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Size);
  Result := 1;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Compacted>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Compacted: MArray; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit([]);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Result.Supply(Self[i]);
end;

{==============================================================================]
  <Compacted>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Compacted(const threshold: Integer): MArray; overload;
var
  i, j: Integer;
  k: Boolean;
  r: Integer;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  r := 0;
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    k := True;
    for j := Max(0, (r - threshold)) to (r - 1) do
      if (Result[j] = Self[i]) then
      begin
        k := False;
        Break;
      end;
    if k then
    begin
      if (Result.Size <= r) then
        SetLength(Result, (r + 1));
      Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Combine>
  @action: Combines arrays arr and b together as single array.
  @note: This is an alternative method. :)
[==============================================================================}
function MArrayHelper.Combine(const b: MArray): MArray; overload;
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Self.Size);
end;

{==============================================================================]
  <Compressed>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Compressed: MArray; overload;
var
  r, i, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l > 1) then
  begin
    r := 0;
    for i := 1 to (l - 1) do
      if not (Self[i] = Result[r]) then
        Result[r.Increment] := Self[i];
    SetLength(Result, (r + 1));
  end;
end;

{==============================================================================]
  <Compressed>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Compressed(const threshold: Integer): MArray; overload;
var
  w, r, i: Integer;
  d: Boolean;
begin
  Result := Self.Copy;
  if (Self.Empty or (threshold < 1)) then
    Exit;
  w := 0;
  for r := 0 to High(Result) do
  begin
    d := False;
    for i := Max(0, (w - threshold)) to (w - 1) do
      if (Result[i] = Result[r]) then
      begin
        d := True;
        Break;
      end;
    if not d then
      Result[w.Increase] := Result[r];
  end;
  SetLength(Result, w);
end;

{==============================================================================]
  <Compress>
  @action: Removes all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Compress: Integer; overload;
var
  i: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Size);
  Result := 1;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Copy>
  @action: Returns copy of an array arr.
  @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function MArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if (index < l) then
  begin
    i := Max(index, 0);
    c := count;
    if ((i + c) > l) then
      c := (l - i);
    SetLength(Result, c);
    for l := 0 to (c - 1) do
      Result[l] := Self[l + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Copied>
  @action: Simply returns a copy of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Copied: MArray; overload;
var
  h, i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[i];
    Result[(l - i) - 1] := Self[(l - i) - 1];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;

{==============================================================================]
  <Count>
  @action: Counts how many times the specified item appears in the array.
  @note:
    - Returns 0 if the array is empty or the item is not found.
    - Uses zero-based indexing (0..High(Self)).
    - Single-pass, no extra memory allocation.
[==============================================================================}
function MArrayHelper.Count(const item: MType): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if (Self[i] = item) then
      Inc(Result);
end;

{==============================================================================]
  <Count>
  @action: Counts how many elements of the array appear in the given set of items.
  @note:
    - Returns 0 if either the array or the items array is empty.
    - Each match increments the count once; duplicates in items are considered normally.
    - Uses zero-based indexing (0..High(Self)).
    - Single-pass over Self, but each element performs a search over items (O(n*m)).
[==============================================================================}
function MArrayHelper.Count(const items: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  if (items.Length > 0) then
  for i := 0 to High(Self) do
    if items.Contains(Self[i]) then
      Inc(Result);
end;

{==============================================================================]
  <Deduplicated>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Deduplicated: MArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit();
  l := 0;
  for i := 0 to High(Self) do
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <Distinct>
  @action: Returns the number of unique elements in array 
  @note: None.
[==============================================================================}
function MArrayHelper.Distinct: Integer; overload;
var
  i, j: Integer;
  u: Boolean;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
  begin
    u := True;
    for j := 0 to (i - 1) do
      if (Self[i] = Self[j]) then
      begin
        u := False;
        Break;
      end;
    if u then
      Inc(Result);
  end;
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
  <Diversified>
  @action: Alternative for Unique methods
  @note: None.
[==============================================================================}
function MArrayHelper.Diversified: MArray; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
  k: MType;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    for i := 0 to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True);
    SetLength(Result, d.Count);
    i := 0;
    for k in d.Keys do
      Result[i.Increase] := k;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <DiversifiedEx>
  @action: Alternative for Unique methods
  @note: None.
[==============================================================================}
function MArrayHelper.DiversifiedEx(const dAscending: Boolean = True): MArray; overload;
var
  l: specialize TList<MType>;
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
begin
  l := specialize TList<MType>.Create;
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
  <Domain>
  @action: Returns the valid index range of the array.
  @note: 
    - If the array is empty, start and stop are set to -1.
    - Otherwise, start = 0 and stop = Length(Self) - 1.
[==============================================================================}
function MArrayHelper.Domain: TRange; overload;
begin
  Result.stop := (Self.Size - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
  <Dupe>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Dupe: MArray; overload;
var
  i, l, j: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if ((l mod 2) <> 0) then
  begin
    j := (l div 2);
    Result[j] := Self[j];
  end;
  if (l > 1) then
  for i := 0 to ((l div 2) - 1) do
  begin
    j := ((l - i) - 1);
    Result[i] := Self[i];
    Result[j] := Self[j];
  end;
end;

{==============================================================================]
  <Duplicate>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Duplicate(const xTimes: Integer = 1): MArray; overload;
var
  m, i, j, l: Integer;
begin
  l := Self.Length;
  m := Max(0, xTimes);
  SetLength(Result, (m * l));
  if (l > 0) then
  for i := 0 to (m - 1) do
    for j := 0 to (l - 1) do
      Result[(i * l) + j] := Self[j];
end;

{==============================================================================]
  <Elements>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): MArray; overload;
var
  h, i, j, l, c, s: Integer;
  r: TIntegerArray;
begin
  if (Self.Empty or returnIDs.Empty) then
    Exit([]);
  if returnSort then
    r := returnIDs.QuickSorted
  else
    r := returnIDs.Copy;
  h := High(r);
  s := High(Self);
  SetLength(Result, Self.Size);
  l := 0;
  c := 0;
  for i := 0 to s do
  case ((c > h) or (r[c] > s)) of
    False:
    for j := c to h do
      if not (r[j] = i) then
      begin
        c := (j + IfThen((r[j] < 0), 1, 0));
        Break;
      end else
        Result[l.Increase] := Self[i];
    True: Break;
  end;
  SetLength(Result, l);
end;

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
  <Fill>
  @action: Fills whole arr with item.
  @note: Returns the filled array.
[==============================================================================}
function MArrayHelper.Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  h, i, s, t: Integer;
begin
  s := Max(0, index);
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Fill>
  @action: Fills whole arr with items.
  @note: None
[==============================================================================}
function MArrayHelper.Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  h, i, s, t, l: Integer;
begin
  h := High(Self);
  l := items.Length;
  case l of
    0: Exit(Self.Copy);
    1: Exit(Self.Fill(items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[(index + i) mod (l - 1)];
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Fit>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function MArrayHelper.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function MArrayHelper.Fit(const aSize: Integer): Integer; overload;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to fit within the specified range.
  @note: 
    - Returns the final array length. 
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function MArrayHelper.Fit(const aBounds: TRange): Integer; overload;
var
  l: Integer;
  b: TRange;
begin
  l := Self.Length;
  b := aBounds.Normalize.ClampMin(0);
  if (l < b.start) then
    Result := b.start
  else
    if (l > b.stop) then
      Result := b.stop
    else
      Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <Free>
  @action: Result := Length(Self) + SetLength(Self, 0) combo. 
  @note: None.
[==============================================================================}
function MArrayHelper.Free: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <FromLeft>
  @action: Returns count of array items from left-side by index.
  @note: None
[==============================================================================}
function MArrayHelper.FromLeft(const count: Integer; const index: Integer = 2147483647): MArray; overload;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Min(High(Self), index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m - count), (m - 1)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <FromRight>
  @action: Returns count of array items from right-side by index.
  @note: None
[==============================================================================}
function MArrayHelper.FromRight(const count: Integer; const index: Integer = 0): MArray; overload;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Max(0, index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m + 1), (m + count)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Get>
  @action: Copy of an array arr.
  @note: Just an alternative.
[==============================================================================}
function MArrayHelper.Get: MArray; overload;
var
  a: MType;
  i: Integer;
begin
  SetLength(Result, Self.Size);
  i := 0;
  for a in Self do
    Result[i.Increase] := a;
 end;

{==============================================================================]
  <Get>
  @action: Outputs array of items from arr by indexes (IDs).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Get(const ID: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, ID.Size);
  for i := 0 to High(ID) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
  <Get>
  @action: Outputs array of items from arr by indexes (IDs).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Get(const ID: TRange): MArray; overload;
var
  i, a: Integer;
begin
  SetLength(Result, ID.Size);
  a := 0;
  case ID.Ascending of
    True:
    for i := ID.start to ID.stop do
      Result[a.Increase] := Self[i];
	False:
    for i := ID.start downto ID.stop do
      Result[a.Increase] := Self[i];
  end;
end;

{==============================================================================]
  <IntersectionCounted>
  @action: Counts the number of distinct elements in Self that also exist in Items.
           Each element is counted at most once, regardless of duplicates in either array.
  @note:
    - Does not require the arrays to be sorted.
    - Uses a hash-based dictionary to track membership; time complexity is roughly O(N + M), 
      where N = Length(Self), M = Length(Items).
    - Works for any type supported by MType that can be used as a dictionary key
      (must support hashing and equality comparison).
    - Each matched element is removed from the dictionary to ensure distinct counting.
    - Returns 0 if either array is empty.
[==============================================================================}
function MArrayHelper.IntersectionCounted(const items: MArray): Integer; overload;
var
  S: specialize TDictionary<MType, Byte>;
  i: Integer;
begin
  Result := 0;
  if (items.Empty or Self.Empty) then
    Exit;
  S := specialize TDictionary<MType, Byte>.Create;
  try
    for i := 0 to High(items) do
      S.TryAdd(items[i], 0);
    for i := 0 to High(Self) do
      if S.ContainsKey(Self[i]) then
      begin
        Inc(Result);
        S.Remove(Self[i]);
      end;
  finally
    S.Free;
  end;
end;

{==============================================================================]
  <Kill>
  @action: Combination of Length(arr) + SetLength(arr, 0).
  @note: Returns the length of the arr!
[==============================================================================}
function MArrayHelper.Kill: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <LeastCommon>
  @action: Returns the least common array item.
  @note: None
[==============================================================================}
function MArrayHelper.LeastCommon: MType; overload;
var
  d: specialize TDictionary<MType, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(MType));
  Result := Self[0];
  m := MaxInt;
  d := specialize TDictionary<MType, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] < m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <LeastFrequent> 
  @action: Returns the least frequent arr item.
  @note: None.
[==============================================================================}
function MArrayHelper.LeastFrequent: MType; overload;
var
  i, j, c, m: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit;
  m := 2147483647;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (Self[j] = Self[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := Self[i];
    end;
  end;
end;

{==============================================================================]
  <Len>
  @action: Simply Result := System.Length(arr);
  @note: None.
[==============================================================================}
function MArrayHelper.Length: Integer; overload;
begin
  Result := System.Length(Self);
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
  <MostCommon>
  @action: Returns the most common array item.
  @note: None
[==============================================================================}
function MArrayHelper.MostCommon: MType; overload;
var
  d: specialize TDictionary<MType, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(MType));
  Result := Self[0];
  m := 0;
  d := specialize TDictionary<MType, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] > m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <MostFrequent> 
  @action: Returns the most frequent arr item.
  @note: None.
[==============================================================================}
function MArrayHelper.MostFrequent: MType; overload;
var
  i, j, c, m: Integer;
begin
  if Self.Empty then
    Exit;
  m := 0;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := Self[i];
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
  <Next>
  @action: Returns next items from array by index and count.
  @note: None.	
[==============================================================================}
function MArrayHelper.Next(const index: Integer; const count: Integer = 2147483647): MArray; overload;
var
  m, i: Integer;
begin
  if ((index >= 0) and (index < (Self.Size - 1)) and (count > 0)) then
  begin
    m := Min((Self.Size - (index + 1)), count);
    SetLength(Result, m);
    for i := 0 to (m - 1) do
      Result[i] := Self[(index + 1) + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Overlay>
  @action: Overlays items to array index.
  @note: Returns the array with overlay action.		
[==============================================================================}
function MArrayHelper.Overlay(const items: MArray; const index: Integer; const init: MType): MArray; overload;
var
  s, l, r, i, a, j: Integer;
begin
  l := items.Length;
  if (l = 0) then
    Exit(Self.Copy);
  s := Self.Size;
  r := IfThen((index < 0), Max((Abs(index) + s), l), Max(s, (index + l)));
  SetLength(Result, r);
  for i := 0 to (r - 1) do
    if not ((index <= 0) and (i < l)) then
    begin
      j := (i - index);
      if not ((index >= 0) and (j >= 0) and (j < l)) then
      begin
        a := IfThen((index < 0), (i - Abs(index)), i);
        if ((a >= 0) and (a < s)) then
          Result[i] := Self[a]
        else
          Result[i] := init;
      end else
        Result[i] := items[j];
    end else
      Result[i] := items[i];
end;

function MArrayHelper.Overlay(const items: MArray; const index: Integer = 0): MArray; overload;
begin
  Result := Self.Overlay(items, index, Default(MType));
end;

{==============================================================================]
  <Patch>
  @action: Simply puts items to array index.
  @note: Uses SetLength incase index + items goes over the current length.
         If index is below 0 it will automatically set max length.
[==============================================================================}
function MArrayHelper.Patch(const index: Integer; const items: MArray): Integer; overload;
var
  j, i: Integer;
begin
  if items.Empty then
    Exit(index);
  i := IfThen((index < 0), Self.Size, index);
  Result := (i + items.Size);
  if (Result > Self.Size) then
    SetLength(Self, Result);
  for j := 0 to High(items) do
    Self[i + j] := items[j];
end;

{==============================================================================]
  <Pick>
  @action: Alternative method for arr.Keep
  @note: None.
[==============================================================================}
function MArrayHelper.Pick(const items: MArray; const index: Integer = 0): MArray; overload;
var
  i, m, l: Integer;
begin
  l := Self.Length;
  m := Max(0, index);
  case (items.Populated and (m < l)) of
    True:
    begin
      SetLength(Result, m);
      for i := 0 to (m - 1) do
        Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
        begin
          SetLength(Result, (Result.Size + 1));
          Result[High(Result)] := Self[i];
        end;
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
  <Pop>
  @action: Returns and removes item from highest array index from arr.
  @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
function MArrayHelper.Pop: MType; overload;
var
  h: Integer;
begin
  if Self.Empty then
    Exit;
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Pop>
  @action: Returns and removes item from highest array index from arr.
  @note: Returns null if array contains no items.
[==============================================================================}
function MArrayHelper.Pop(const null: MType): MType; overload;
var
  h: Integer;
begin
  if Self.Empty then
    Exit(null);
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Populate>
  @action: Populates array with items, x-times.
  @note: Returns true if items is not empty and times is more than 0.
[==============================================================================}
function MArrayHelper.Populate(const items: MArray; const times: Integer = 1): Boolean; overload;
var
  i, j, l: Integer;
begin
  l := items.Length;
  SetLength(Self, (l * times));
  Result := (Self.Size > 0);
  if Result then
  for i := 0 to (l - 1) do
    for j := 0 to (times - 1) do
      Self[i + (j * l)] := items[i];
end;

{==============================================================================]
  <Populate>
  @action: Populates array with item, x-times.
  @note: Returns true if times is more than 0.
[==============================================================================}
function MArrayHelper.Populate(const item: MType; const times: Integer = 1): Boolean; overload;
var
  i: Integer;
begin;
  SetLength(Self, times);
  Result := (Self.Size > 0);
  if Result then
  for i := 0 to (times - 1) do
    Self[i] := item;
end;

{==============================================================================]
  <Previous>
  @action: Returns previous array items from index by count.
  @note: None.
[==============================================================================}
function MArrayHelper.Previous(const index: Integer; const count: Integer = 2147483647): MArray; overload;
var
  m, l, i: Integer;
begin
  if ((index > 0) and (index < Self.Size) and (count > 0)) then
  begin
    m := Max(0, (index - count));
    l := (((index - 1) - m) + 1);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      Result[i] := Self[m + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Pruned>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Pruned: MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l = 1) then
    Exit;
  r := 0;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[i - 1]) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Pruned>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Pruned(const threshold: Integer): MArray; overload;
var
  w: MArray;
  e: MType;
  h, t, c, i, j: Integer;
  d: Boolean;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  SetLength(Result, 0);
  SetLength(w, threshold);
  h := 0;
  t := 0;
  c := 0;
  for i := 0 to High(Self) do
  begin
    e := Self[i];
    d := False;
    for j := 0 to (c - 1) do
      if (w[(h + j) mod threshold] = e) then
      begin
        d := True;
        Break;
      end;
    if not d then
    begin
      SetLength(Result, (Result.Size + 1));
      Result[High(Result)] := e;
      w[t] := e;
      t := ((t + 1) mod threshold);
      if (c < threshold) then
        Inc(c)
      else
        h := ((h + 1) mod threshold);
    end;
  end;
end;

{==============================================================================]
  <Prune>
  @action: Removes all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Prune: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[Result]) then
      Self[Result.Increment] := Self[i];
  if not Self.Empty then
    SetLength(Self, Result.Increment);
end; 

{==============================================================================]
  <Pull>
  @action: Returns the contents of the array and leaves it empty.
  @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function MArrayHelper.Pull: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  SetLength(Self, 0);
end;

{==============================================================================]
  <Purified>
  @action: Returns array with unique items
  @note: None.
[==============================================================================}
function MArrayHelper.Purified(const dAscending: Boolean = True): MArray; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  l: specialize TList<MType>;
  i: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  l := specialize TList<MType>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
  <Purify>
  @action: Removes duplicates
  @note: None
[==============================================================================}
function MArrayHelper.Purify(const dAscending: Boolean = True): Integer; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  c: MArray;
  i: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  Result := 0;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
	  Self[Result.Increase] := Self[i];
        end;
      False:
      begin
        c := Self.Copy;
        for i := High(c) downto 0 do
          if not d.ContainsKey(c[i]) then
          begin
            d.Add(c[i], True);
	    Self[Result.Increase] := c[i];
          end;
      end;
    end;
  finally
    d.Free;
  end;
  SetLength(Self, Result);
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
  <Range>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Range(const subArray: MArray; const index: Integer = 0): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Ranges>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  l := 0;
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
  end;
end;

{==============================================================================]
  <Recreate>
  @action: Clear the array and reallocate to arrSize (negative = previous length).
  @note: Returns True if array was non-empty and arrSize <> 0.
[==============================================================================}
function MArrayHelper.Recreate(const arrSize: Integer): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Length;
  Result := ((l > 0) or (arrSize <> 0));
  SetLength(Self, 0);
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
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
  <Reset>
  @action: Resets all elements of the array to default values while preserving its structure.
  @note: Returns the number of elements that were reset.
[==============================================================================}
function MArrayHelper.Reset: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
  SetLength(Self, Result);
end; 

{==============================================================================]
  <Resize>
  @action: Updates's arr length with aChange.
  @note: aChange > 0 => Result will give how many elements were added
         aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
         aChange = 0 => Returns 0.
[==============================================================================}
function MArrayHelper.Resize(const aChange: Integer): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Self, (l + aChange));
  Result := (Self.Size - l);
end;

{==============================================================================]
  <Resize>
  @action: Updates's arr length with aChange.
  @note: aChange > 0 => Result will give how many elements were added
         aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
         aChange = 0 => Returns 0.
         Supports null for filling created indexes.
[==============================================================================}
function MArrayHelper.Resize(const aChange: Integer; const null: MType): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Self, aChange);
  Result := (Self.Size - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;

{==============================================================================]
  <Sample>
  @action: Returns sample from array by sSize.
  @note: None.
[==============================================================================}
function MArrayHelper.Sample(const sSize: Integer): MArray; overload;
var
  i: Integer;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  r := Self.Domain.Sample(sSize);
  SetLength(Result, r.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[r[i]];
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
  <Shift>
  @action: Shortens the array with first element.
  @note: Returns the removed arr[0].
[==============================================================================}
function MArrayHelper.Shift: MType; overload;
var
  i, h: Integer;
begin
  h := (Self.Size - 1);
  if (h < 0) then
    Exit;
  Result := Self[0];
  for i := 0 to (h - 1) do
    Self[i] := Self[i + h];
  SetLength(Self, h);
end;

{==============================================================================]
  <Shift>
  @action: Shortens the array with first SCOUNT element(s).
  @note: Returns the removed arr[x]s.
[==============================================================================}
function MArrayHelper.Shift(const sCount: Integer): MArray; overload;
var
  i, l, s: Integer;
begin
  l := Self.Length;
  s := Max(0, Min(sCount, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  for i := s to High(Self) do
    Self[i - s] := Self[i];
  SetLength(Self, (Self.Size - s));
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
  <Singlify>
  @action: Removes duplicate occurrences of a specific item, keeping only the first.
  @note: Useful for ensuring a item appears exactly once in the array.
[==============================================================================}
function MArrayHelper.Singlify(const item: MType): Integer; overload;
var
  i, l: Integer;
  f: Boolean;
begin
  Result := Self.Size;
  l := 0;
  f := False;
  for i := 0 to (Result - 1) do
    if ((not f) or (Self[i] <> item)) then
    begin
      Self[l.Increase] := Self[i];
      if (Self[i] = item) then
        f := True;
    end;
  if (Result.Decrement(l) > 0) then
    SetLength(Self, l);
end;

{==============================================================================]
  <Singlified>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function MArrayHelper.Singlified(const item: MType): MArray; overload;
var
  i, l: Integer;
  f: Boolean;
begin
  SetLength(Result, Self.Size);
  l := 0;
  f := False;
  for i := 0 to High(Self) do
    if ((not f) or (Self[i] <> item)) then
    begin
      Result[l.Increase] := Self[i];
      if (Self[i] = item) then
        f := True;
    end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Singularize>
  @action: Removes duplicate items in the array, keeping only the first occurrence of each unique value.
  @note: The operation modifies the current array in-place. The order of the first appearances
         is preserved. Returns the number of items removed.
[==============================================================================}
function MArrayHelper.Singularize(const item: MType): Integer; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i, l: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    l := 0;
    for i := 0 to High(Self) do
      if ((Self[i] <> item) or (not d.ContainsKey(item))) then
      begin
	    if (Self[i] = item) then
          d.Add(item, True);
        Self[l.Increase] := Self[i];
      end;
    Result := (Self.Size - l);
    if (Result > 0) then
      SetLength(Self, l);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Singularized>
  @action: Returns a new array containing only the first occurrence of each unique item.
  @note: The original array remains unchanged. The resulting array preserves
         the order of the first appearances.
[==============================================================================}
function MArrayHelper.Singularized(const item: MType): MArray; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i, c: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    SetLength(Result, Self.Size);
    c := 0;
    for i := 0 to High(Self) do
      if ((Self[i] <> item) or (not d.ContainsKey(item))) then
      begin
        if (Self[i] = item) then
          d.Add(item, True);
        Result[c.Increase] := Self[i];
      end;
    SetLength(Result, c);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Size> 
  @action: Returns array length.
  @note: Simply Result := Length(arr);
[==============================================================================}
function MArrayHelper.Size: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Size>
  @action: Set's arr length to aSize.
  @note: None.
[==============================================================================}
function MArrayHelper.Size(const aSize: Integer): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Size>
  @action: Set's arr length to size.
  @note: Uses null for created indexes.
[==============================================================================}
function MArrayHelper.Size(const aSize: Integer; const null: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
  for i := l to (aSize - 1) do
    Result[i] := null;
end;

{==============================================================================]
  <Slice>
  @action: Returns array slice with TRange r.
  @note: Make sure you use correct indexes and there is enough buffer in array!
         No safety checks for this function. 
[==============================================================================}
function MArrayHelper.Slice(const r: TRange): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, r.Size);
  case r.Ascending of
    True:
    for i := r.start to r.stop do
      Result[i - r.start] := Self[i];
    False:
    for i := r.start downto r.stop do
      Result[i - r.start] := Self[i];
  end;
end;

{==============================================================================]
  <Slice>
  @action: Returns array slice with multiple TRanges by r.
  @note: Make sure you use correct indexes and there is enough buffer in array!
         No safety checks for this function. 
[==============================================================================}
function MArrayHelper.Slice(const r: TRangeArray): MArray; overload;
var
  i, j, l: Integer;
begin
  if r.Empty then
    Exit([]);
  l := 0;
  for i := 0 to High(r) do
    l := (l + r[i].Size);
  SetLength(Result, l);
  for i := High(r) downto 0 do
  case r[i].Ascending of
    True:
    for j := r[i].stop downto r[i].start do
      Result[l.Decrement] := Self[j];
    False:
    for j := r[i].stop to r[i].start do
      Result[l.Decrement] := Self[j];
  end;
end;

{==============================================================================]
  <Soloize>
  @action: Removes all occurrences of a specific item from the array.
  @note: Returns the number of items removed. If none found, the array is unchanged.
[==============================================================================}
function MArrayHelper.Soloize(const item: MType): Integer; overload;
var
  i, l: Integer;
begin
  l := 0;
  Result := 0;
  for i := 0 to High(Self) do
    if ((Self[i] = item) and (Result.Increase > 0)) then
      Continue
    else
      Self[l.Increase] := Self[i];
  if (Result > 0) then
    SetLength(Self, l);
end;

{==============================================================================]
  <Soloized>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function MArrayHelper.Soloized(const item: MType): MArray; overload;
var
  i, l, s: Integer;
begin
  SetLength(Result, Self.Size);
  s := 0;
  l := 0;
  for i := 0 to High(Self) do
    if ((Self[i] = item) and (s.Increase > 0)) then
      Continue
    else
      Result[l.Increase] := Self[i];
  if (s > 0) then
    SetLength(Result, l);
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
  <Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Span: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := IfThen((Result.stop = -1), -1, 0);
end;

{==============================================================================]
  <Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Spans>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  l := 0;
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
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
  <SwapMerged>
  @action: Swaps the contents of Self and target arrays manually using an
           auxiliary array, and returns a new array containing all elements
           from both arrays combined in the **original order** (before swap).
  @note: The swap is performed by copying elements from Self and target
         into a temporary array in reverse order, then assigning them back.
         This method works but is less efficient (O(n)) because every element
         is copied. Use this if the merged array should reflect the **pre-swap
         ordering**.
[==============================================================================}
function MArrayHelper.SwapMerged(var target: MArray): MArray; overload;
var
  r, t, s, i: Integer;
begin
  s := Self.Size;
  t := target.Size;
  r := (s + t);
  SetLength(Result, r);
  if (r = 0) then
    Exit;
  for i := High(target) downto 0 do
    Result[r.Decrement] := target[i];
  for i := High(Self) downto 0 do
    Result[r.Decrement] := Self[i];
  SetLength(Self, t);
  SetLength(target, s);
  for i := 0 to (t - 1) do
    Self[i] := Result[s + i];
  for i := 0 to (s - 1) do
    target[i] := Result[i];
end;

{==============================================================================]
  <SwappedMerge>
  @action: Swaps the contents of Self and target arrays using the reference
           swap method (Self.Swapped), and returns a new array containing all
           elements from both arrays combined in the **post-swap order**.
  @note: This implementation is more efficient (O(1) for the swap) because
         it swaps references rather than copying elements individually.
         The merged array is then constructed by iterating over Self and
         target. This is preferred for large dynamic arrays, and the
         resulting array reflects the swapped positions of Self and target.
[==============================================================================}
function MArrayHelper.SwappedMerge(var target: MArray): MArray; overload;
var
  t, s, i: Integer;
begin
  s := Self.Size;
  t := target.Size;
  SetLength(Result, (s + t));
  if ((s + t) = 0) then
    Exit;
  Self.Swapped(target);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(target) do
    Result[t + i] := target[i];
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

{==============================================================================]
  <Uncluttered>
  @action: Removes all duplicates from arr.
  @note: Returns the number of items that were removed.
[==============================================================================}
function MArrayHelper.Uncluttered: MArray; overload;
type
  TDict = specialize TDictionary<MType, Boolean>;
var
  d: TDict;
  r, i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  d := TDict.Create;
  try
    SetLength(Result, l);
    r := 0;
    for i := 0 to (l - 1) do
      if not d.ContainsKey(Self[i]) then
      begin
        d.Add(Self[i], True);
        Result[r.Increase] := Self[i];
      end;
    if ((l - r) > 0) then
      SetLength(Result, r);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Uniformity>
  @action: Returns 1.0 if all elements equal, 0.0 if all different,
           or something in between based on unique-value ratio. 
  @note: None.
 [==============================================================================}
function MArrayHelper.Uniformity: Double; overload;
begin
  if not Self.Empty then
    Result := (1.0 / Self.Distinct)
  else
    Result := 0.0;
end;

{==============================================================================]
  <Unified>
  @action: Uniques array
  @note: None.
 [==============================================================================}
function MArrayHelper.Unified(const dAscending: Boolean = True): MArray; overload;
var
  d: specialize TDictionary<MType, Byte>;
  i, n: Integer;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  try
    SetLength(Result, Self.Size);
    n := 0;
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
    end;
    SetLength(Result, n);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Unify>
  @action: Uniques array
  @note: None.
 [==============================================================================}
function MArrayHelper.Unify(const dAscending: Boolean = True): Integer; overload;
var
  s: MArray;
  d: specialize TDictionary<MType, Byte>;
  l, i: Integer;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  Result := 0;
  try
    l := Self.Length;
    case dAscending of
      False:
      begin
        s := Self.Copy;
        for i := (l - 1) downto 0 do
          if not d.ContainsKey(Self[i]) then
          begin
            d.Add(Self[i], 0);
            Self[Result.Increase] := s[i];
          end;
      end;
      True:
      for i := 0 to (l - 1) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Self[Result.Increase] := Self[i];
        end;
    end;
    SetLength(Self, Result);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Unduplicated>
  @action: Removes all duplicates from arr.
  @note: Returns the number of items that were removed.
[==============================================================================}
function MArrayHelper.Unduplicated: MArray; overload;
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  Result := Self.Copy;
  l := Result.Length;
  if (l < 2) then
    Exit;
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (Result[i] = Result[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    Result[a.Increment] := Result[i];
  end;
  if ((l - (a + 1)) > 0) then
    SetLength(Result, (a + 1));
end;

{==============================================================================]
  <Uniqued>
  @action: Removes all duplicates from arr.
  @note: Returns the unique version of arr.
[==============================================================================}
function MArrayHelper.Uniqued: MArray; overload;
var
  i, j, l, c: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (Self[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
        Result[c.Increase] := Self[i];
    end;
    SetLength(Result, c);
  end;
end;

{==============================================================================]
  <Uniques>
  @action: Returns the indexes of unique array (arr) items.
  @note: None.
[==============================================================================}
function MArrayHelper.Uniques: TIntegerArray; overload;
var
  h, r, x, y: Integer;
  m: Boolean;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (Self[x] = Self[y]));
        if m then
          Break;
      end;
      if not m then
        Result[r.Increase] := x;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

{==============================================================================]
  <Unshift>
  @action: Grows arr with item.
  @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function MArrayHelper.Unshift(const item: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l + 1));
  for i := l downto 1 do
    Result[i] := Self[i - 1];
  Result[0] := item;
end;

{==============================================================================]
  <Unshift>
  @action: Grows arr with items. Returns the index of last added item.
  @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function MArrayHelper.Unshift(const items: MArray): MArray; overload;
var
  l, i, r: Integer;
begin
  if items.Empty then
    Exit(Self.Copy);
  l := items.Length;
  r := (Self.Size + l);
  SetLength(Result, r);
  for i := (r - 1) downto l do
    Result[i] := Self[i - l];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
  <Void>
  @action: Returns true if array is void (empty)
  @note: Alternative for Empty.
[==============================================================================}
function MArrayHelper.Void: Boolean; overload;
begin
  Result := (Low(Self) > High(Self));
end;

{==============================================================================]
  <Waste>
  @action: Returns total count of Duplicates in array, which is considered as "Waste"
  @note: None.
[==============================================================================}
function MArrayHelper.Waste: Integer; overload;
type
  TDict = specialize TDictionary<MType, Integer>;
var
  d: TDict;
  i: Integer;
  v: MType;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  d := TDict.Create;
  try
    for v in Self do
      if d.ContainsKey(v) then
        d[v] := (d[v] + 1)
      else
        d.Add(v, 1);
    for i in d.Values do
      if (i > 1) then
        Result := (Result + (i - 1));
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Zigzag>
  @action: Creates a new array whose elements are taken alternately from the
           start and end of the source array, producing an outside-in “zigzag” order.
  @note: For odd-length arrays, the middle element appears last.
[==============================================================================}
function MArrayHelper.Zigzag(const zAscending: Boolean = True): MArray; overload;
var
  l, r: Integer;
  s: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  r := 0;
  s.Create(0, (l - 1));
  case zAscending of
    True:
    repeat
      Result[r.Increase] := Self[s.start];
      Result[r.Increase] := Self[s.stop];
    until (s.start.Increment >= s.stop.Decrement);
    False:
    repeat
      Result[r.Increase] := Self[s.stop];
      Result[r.Increase] := Self[s.start];
    until (s.start.Increment >= s.stop.Decrement);
  end;
  if (s.start = s.stop) then
    Result[r] := Self[s.stop];
end;

{$IFDEF Sortable}
{==============================================================================]
  <Sortable>
  @action: Checks whether the array contains at least two different elements.
           Returns True if sorting would change the array order.
  @note: Arrays with all equal elements, a single element, or empty arrays
         return False.
[==============================================================================}
function MArrayHelper.Sortable: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Sorted>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function MArrayHelper.Sorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to (High(Self) - 1) do
    if (aAscending and (Self[i] > Self[i + 1])) or ((not aAscending) and (Self[i] < Self[i + 1])) then
      Exit(False);
  Result := (not Self.Empty);
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the entire array is sorted in ascending or descending order.
  @note:   Returns True if all elements are in the correct order according to aAscending.
[==============================================================================}
function MArrayHelper.IsSorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the elements between iStart and iStop are in correct
           ascending or descending order.
  @note: The range [iStart..iStop] is automatically normalized and clamped to
         valid array bounds. Returns True if all elements within the range
         follow the specified order.
[==============================================================================}
function MArrayHelper.IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  i, s, e, h: Integer;
begin
  h := High(Self);
  if (h <= 0) then
    Exit(True);
  s := Max(0, Min(iStart, iStop));
  e := Min(Max(iStart, iStop), h);
  if (s >= e) then
    Exit(True);
  for i := (s + 1) to e do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsSorted>
  @action: Determines whether the array elements within the specified range
           (given as TRange) are ordered in ascending or descending order.
  @note: Internally calls the (iStart, iStop) overload. The range is
         automatically normalized and clamped to valid array bounds.
         Returns True if all elements within the range follow the specified order.
[==============================================================================}
function MArrayHelper.IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := Self.IsSorted(indexes.start, indexes.stop, aAscending);
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the element at the specified index is correctly
           positioned relative to its immediate neighbors according to
           ascending or descending order.
  @note: Returns True if the element at the given index maintains proper
         order with adjacent elements. Boundary or single-element arrays are
         considered sorted. Returns False for out-of-range indices.
[==============================================================================}
function MArrayHelper.IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (index < 0) or (index > h) then
    Exit(False);
  if (h = 0) then
    Exit(True);
  if ((index < h) and (aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  if ((index > 0) and (aAscending and (Self[index] < Self[index - 1])) or ((not aAscending) and (Self[index] > Self[index - 1]))) then
    Exit(False);
  Result := True;
end; 

{==============================================================================]
  <InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function MArrayHelper.InOrder(const aAscending: Boolean = True): Boolean; overload;
var
  i, l: Integer;
begin
  i := -1;
  l := Self.Length;
  Result := (l > 0);
  if (l > 1) then
  case aAscending of
    True:
    while (i.Increment < l.Decrement) do
      if ((Self[i] > Self[i + 1]) or (Self[l - 1] > Self[l])) then
        Exit(False);
    False:
    while (i.Increment < l.Decrement) do
      if ((Self[i] < Self[i + 1]) or (Self[l - 1] < Self[l])) then
        Exit(False);
  end;
end;

{==============================================================================]
  <Orderly>
  @action: Returns true if array arr is in ascending AND/OR descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Orderly: Boolean; overload;
var
  i: Integer;
  a, d: Boolean;
begin
  a := True;
  d := True;
  for i := 0 to (High(Self) - 1) do
  begin
    if (Self[i] > Self[i + 1]) then
      a := False;
    if (Self[i] < Self[i + 1]) then
      d := False;
    if not (a or d) then
      Break;
  end;
  Result := (a or d);
end;

{==============================================================================]
  <Ordered>
  @action: Returns true if array arr is in ascending AND/OR descending order by aAscending.
  @note: Recursive alternative.
[==============================================================================}
function MArrayHelper.Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
begin
  if (index >= High(Self)) then
    Exit(True);
  if ((aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  Result := Self.Ordered(aAscending, (index + 1));
end;

{==============================================================================]
  <Order>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 1 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function MArrayHelper.Order: Integer; overload;
var
  i, l: Integer;
  a, d: Boolean;
begin
  l := Self.Length;
  case l of
    0: Exit(0);
    1: Exit(1);
  end;
  a := True;
  d := True;
  for i := 1 to (l - 1) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else
      if (Self[i] > Self[i - 1]) then
        d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else
    if d then
      Result := -1
    else
      Result := 0;
end;

{==============================================================================]
  <Orientation>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 0 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function MArrayHelper.Orientation: Integer; overload;
var
  i: Integer;
  a, d: Boolean;
begin
  if not Self.Multi then
    Exit(0);
  a := True;
  d := True;
  for i := 1 to High(Self) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else
      if (Self[i] > Self[i - 1]) then
        d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else
    if d then
      Result := -1
    else
      Result := 0;
end;

{==============================================================================]
  <Ascend>
  @action: Returns array arr sorted to asscending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Ascend: MArray; overload;
procedure QS(var arr: MArray; const valLow, valHigh: Integer);
var
  p: MType;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] < p) do
      Inc(r.start);
    while (arr[r.stop] > p) do
      Dec(r.stop);
    if r.Ascending then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Descend>
  @action: Returns array arr sorted to descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Descend: MArray; overload;
procedure QS(var arr: MArray; const valLow, valHigh: Integer);
var
  p: MType;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] > p) do
      Inc(r.start);
    while (arr[r.stop] < p) do
      Dec(r.stop);
    if r.Ascending then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Descending>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function MArrayHelper.Descending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] < Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Ascending>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function MArrayHelper.Ascending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] > Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = True | [1,0] = True |
[==============================================================================}
function MArrayHelper.Decreasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = True | [1,0] = False |
[==============================================================================}
function MArrayHelper.Increasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] < Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Downward>
  @action: Returns true if array arr is in descending order.
  @note: Returns true with empty []array! Unlike Descending, Decreasing.
[==============================================================================}
function MArrayHelper.Downward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] < Self[h + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Upward>
  @action: Returns true if array arr is in ascending order.
  @note: Returns true with empty [] array! Unlike Ascending, Increasing.
[==============================================================================}
function MArrayHelper.Upward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] > Self[h + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Lowest>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function MArrayHelper.Lowest: MType; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <Highest>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function MArrayHelper.Highest: MType; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with aAscending as False.
[==============================================================================}
function MArrayHelper.Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
  end;
end;

function MArrayHelper.Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Mini(aAscending, start);
end;

{==============================================================================]
  <Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with aAscending as False.
[==============================================================================}
function MArrayHelper.Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
  end;
end;

function MArrayHelper.Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Maxi(aAscending, start);
end;

{==============================================================================]
  <Mode>
  @action: The value that occurs most frequently in arr.
  @note: None
[==============================================================================}
function MArrayHelper.Mode: MType; overload;
var
  a: MArray;
  c: TIntegerArray;
  h, i, j, l: Integer;
begin
  h := High(Self);
  if (h > -1) then
  case (h = 0) of
    False:
    begin
      SetLength(c, 0);
      SetLength(a, 0);
      for i := 0 to High(Self) do
      begin
        l := -1;
        for j := 0 to High(a) do
          if (Self[i] = a[j]) then
          begin
            l := j;
            Break;
          end;
        if (l = -1) then
        begin
          a := a.Append(Self[i]);
          c := c.Append(1);
        end else
          Inc(c[l]);
      end;
      Result := a[c.Maxi];
    end;
    True: Result := Self[0];
  end;
end;

{==============================================================================]
  <Center>
  @action: The value at the center position of a sorted or unsorted arr.
  @note: None
[==============================================================================}
function MArrayHelper.Center: MType; overload;
begin
  if (Self.Size > 0) then
    Result := Self[Self.Size div 2];
end;

{==============================================================================]
  <MergeSortIndexed>
  @action: Sorts the current integer array (Self) using merge sort while
           tracking the original indices of each element.
  @note: - Returns an array of indices representing the order of elements in the sorted array.
         - The original array (Self) is modified in-place.
         - Sorting is stable (preserves order of equal elements).
         - Useful for retrieving both sorted data and their original positions.
[==============================================================================}
function MArrayHelper.MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure MSI(var arr: MArray; var indexes: TIntegerArray; const L, R: Integer);
  var
    s: MArray;
    p: TIntegerArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSI(arr, indexes, L, m);
    MSI(arr, indexes, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(p, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (arr[i] <= arr[j])) or ((not aAscending) and (arr[i] >= arr[j]))) of
        True:
        begin
          s[k] := arr[i];
          p[k] := indexes[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          p[k] := indexes[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      p[k] := indexes[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      p[k] := indexes[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      indexes[L + k] := p[k];
    end;
  end;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := i;
  if (Self.Size > 1) then
    MSI(Self, Result, 0, High(Result));
end;

{==============================================================================]
  <MergeSortPair>
  @action: Performs an in-place merge sort on the current array (Self),
           reordering both Self and its associated partner array so that the
           elements of partner remain paired with their corresponding elements
           in Self. Sorting is based on the values in Self.
  @note: - Self and partner must have the same length.
         - Sorting is stable: equal values in Self preserve their original order.
         - Returns Length(Self).
         - Set aAscending = False for descending order.
[==============================================================================}
function MArrayHelper.MergeSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSP(var arr, prt: MArray; const L, R: Integer);
  var
    s, p: MArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSP(arr, prt, L, m);
    MSP(arr, prt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(p, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (arr[i] <= arr[j])) or ((not aAscending) and (arr[i] >= arr[j]))) of
        True:
        begin
          s[k] := arr[i];
          p[k] := prt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          p[k] := prt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      p[k] := prt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      p[k] := prt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      prt[L + k] := p[k];
    end;
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    MSP(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSortPair>
  @action: Sorts the array in-place while simultaneously reordering a partner array 
           to maintain element correspondence. Supports ascending or descending order.
  @note: Useful when you have a key array and a related value array that must stay paired.
         The method returns the length of the array.
[==============================================================================}
function MArrayHelper.QuickSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS2(var A, B: MArray; const L, R: Integer);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := A[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (A[i] < p) do
          Inc(i);
        while (A[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (A[i] > p) do
          Inc(i);
        while (A[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS2(A, B, L, j);
    if (i < R) then
      QS2(A, B, i, R);
  end;
begin
  Result := Self.Size;
  if (Result > 0) then
    QS2(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <PartitionSort>
  @action: Sorts the array (Self) in ascending or descending order using a
           stable partition-based recursive sorting algorithm.
  @note:   - Returns Length(Self)
           - The algorithm is conceptually similar to QuickSort but uses
             stable partitioning (no in-place swaps).
           - Equal elements preserve their original order (stable).
           - Uses auxiliary arrays, trading memory for stability.
           - Also known as "Stable QuickSort".
[==============================================================================}
function MArrayHelper.PartitionSort(const aAscending: Boolean = True): Integer; overload;
  procedure PS(var A: MArray; const L, R: Integer);
  var
    p: MType;
    i, t: Integer;
    s, e, b: MArray;
  begin
    if (L >= R) then
      Exit;
    p := A[(L + R) div 2];
    SetLength(s, 0);
    SetLength(e, 0);
    SetLength(b, 0);
    for i := L to R do
    case A[i].Compare(p) of
      -1:
      if aAscending then
        s.Supply(A[i])
      else
        b.Supply(A[i]);
      1:
      if aAscending then
        b.Supply(A[i])
      else
        s.Supply(A[i]);
      0: e.Supply(A[i]);
    end;
    if (s.Size > 1) then
      PS(s, 0, High(s));
    if (b.Size > 1) then
      PS(b, 0, High(b));
    t := L;
    for i := 0 to High(s) do
      A[t.Increase] := s[i];
    for i := 0 to High(e) do
      A[t.Increase] := e[i];
    for i := 0 to High(b) do
      A[t.Increase] := b[i];
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    PS(Self, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSortSwapped>
  @action: Sorts the array in ascending or descending order and records all swaps performed.
  @note: Returns a dynamic array of TConnection records, each representing the indices of elements swapped during the sort.
         Useful for visualizations or undoing the sort.
[==============================================================================}
function MArrayHelper.QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
  procedure QuickSortRec(const L, R: Integer; var swaps: TConnectionArray);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (System.Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (System.Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, swaps);
    if (i < R) then
      QuickSortRec(i, R, swaps);
  end;
begin
  SetLength(Result, 0);
  if (Self.Size > 1) then
    QuickSortRec(0, High(Self), Result);
end;

{==============================================================================]
  <QuickSortIndexed>
  @action: Sorts the array while tracking the original indices.
  @note: Returns an array of indices representing the order of elements in the sorted array.
         The original array is modified.
         Useful when you want to know how elements move rather than just sorting the values.
[==============================================================================}
function MArrayHelper.QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortRec(const L, R: Integer; var indexes: TIntegerArray);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, indexes);
    if (i < R) then
      QuickSortRec(i, R, indexes);
  end;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  if (l > 1) then
    QuickSortRec(0, (l - 1), Result);
end;

{==============================================================================]
  <QuickSortedly>
  @action: Returns the indices of the array elements in sorted order without modifying the original array.
  @note: Purely functional: the original array stays unchanged.
         The result is an array of indices indicating the sorted order.
[==============================================================================}
function MArrayHelper.QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortIndexedHelper(const arr: MArray; var indexes: TIntegerArray; const L, R: Integer; const aAscending: Boolean);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := arr[indexes[(L + R) div 2]];
    case aAscending of
      True:
      repeat
        while (arr[indexes[i]] < p) do
          Inc(i);
        while (arr[indexes[j]] > p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
      False:
      repeat
        while (arr[indexes[i]] > p) do
          Inc(i);
        while (arr[indexes[j]] < p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
    end;
    if (L < j) then
      QuickSortIndexedHelper(arr, indexes, L, j, aAscending);
    if (i < R) then
      QuickSortIndexedHelper(arr, indexes, i, R, aAscending);
  end;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  QuickSortIndexedHelper(Self, Result, 0, (l - 1), aAscending);
end;

{==============================================================================]
  <QuickSorted(aAscending: Boolean): MArray>
  @action: Returns array sorted by its own values, based on QuickSort algorithm.
  @note: None.
[==============================================================================}
function MArrayHelper.QuickSorted(const aAscending: Boolean = True): MArray; overload;
  procedure QS(var arr: MArray; const L, R: Integer);
  var
    i, j: Integer;
    p: MType;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while (aAscending and (arr[i] < p)) or ((not aAscending) and (arr[i] > p)) do
        Inc(i);
      while (aAscending and (arr[j] > p)) or ((not aAscending) and (arr[j] < p)) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QS(arr, L, j);
    if (i < R) then
      QS(arr, i, R);
  end;
var
  a: Integer;
begin
  a := Self.Length;
  Result := Self.Copy(0, a);
  if (a > 1) then
    QS(Result, 0, (a - 1));
end;

{==============================================================================]
  <QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QuickSort(const aAscending: Boolean = True): Integer; overload;
var
  p: MType;
  t, o: Integer;
  s: TRangeArray;
  x, r: TRange;
  procedure qsPush(const start, stop: Integer);
  begin
    SetLength(s, (t.Increment + 1));
    s[t].start := start;
    s[t].stop := stop;
  end;
  function qsPop(out start, stop: Integer): Boolean;
  begin
    Result := (t >= 0);
    if not Result then
      Exit;
    start := s[t].start;
    stop := s[t].stop;
    Dec(t); 
  end;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    t := -1;
    qsPush(0, Result);
    r.Create(0, Result);
    while qsPop(r.start, r.stop) do
      while r.Growing do
      begin
        x := r;
        p := Self[r.Middle];
        while x.Ascending do
        begin
          while (Sign(Self[x.start].Compare(p)) = o) do
            Inc(x.start);
          while (Sign(Self[x.stop].Compare(p)) = -o) do
            Dec(x.stop);
          if x.Ascending then
            Exchange(x.start.Increase, x.stop.Decrease);
        end;
        if ((x.stop - r.start) < (r.stop - x.start)) then
        begin
          if (x.start < r.stop) then
            qsPush(x.start, r.stop);
          r.stop := x.stop;
        end else
        begin
          if (r.start < x.stop) then
            qsPush(r.start, x.stop);
          r.start := x.start;
        end;
      end;
  end;
end;

{==============================================================================]
  <QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QuickSort3W(const aAscending: Boolean = True): Integer; overload;
  procedure SortLH(var arr: MArray; const L, H: Integer; const aAscending: Boolean = True);
  var
    a: MType;
    p, o: Integer;
    r: TRange;
  begin
    if (L >= H) then
      Exit;
    o := aAscending.Select(-1, 1);
    a := arr[L];
	r.Create(L, H);
    p := (L + 1);
    while (p <= r.stop) do
      if (Sign(arr[p].Compare(a)) = o) then
        Exchange(r.start.Increase, p.Increase)
      else
        if (Sign(arr[p].Compare(a)) = -o) then
          Exchange(r.stop.Decrease, p)
        else
          Inc(p);
    SortLH(arr, L, (r.start - 1), aAscending);
    SortLH(arr, (r.stop + 1), H, aAscending);
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    SortLH(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QSort(const aAscending: Boolean = True): Integer; overload;
  procedure _QuickSort(var arr: MArray; const start, stop: Integer; const aAscending: Boolean = True);
  var
    p: MType;
	o: Integer;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := aAscending.Select(-1, 1);
	  s.Create(start, stop);
      p := arr[s.Middle];
      repeat
        while (Sign(arr[s.start].Compare(p)) = o) do
          Inc(s.start);
        while (Sign(arr[s.stop].Compare(p)) = -o) do
          Dec(s.stop);
        if (s.start <= s.stop) then
          Exchange(s.start.Increase, s.stop.Decrease);
      until (s.start > s.stop);
      if (start < s.stop) then
        _QuickSort(arr, start, s.stop, aAscending);
      if (s.start < stop) then
        _QuickSort(arr, s.start, stop, aAscending);
    end;
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    _QuickSort(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <CoctailSort>
  @action: CoctailSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.CoctailSort(const aAscending: Boolean = True): Integer; overload;
var
  i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    repeat
      s := False;
      for i := 0 to (Result - 1) do
        if (Sign(Self[i + 1].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      for i := (Result - 1) downto 0 do
         if (Sign(Self[i + 1].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <CoctailSort2>
  @action: CoctailSort algorithm.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function MArrayHelper.CoctailSort2(const aAscending: Boolean = True): Integer; overload;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    b := -1;
    e := (Self.Size - 2);
    repeat
      s := False;
      Inc(b);
      for i := b to e do
        if not (Sign(Self[i].Compare(Self[i + 1])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      Dec(e);
      for i := e downto b do
        if not (Sign(Self[i].Compare(Self[i + 1])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <GnomeSort>
  @action: GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.GnomeSort(const aAscending: Boolean = True): Integer; overload;
var
  o, p: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    while (p <= Result) do
      if (Sign(Self[p].Compare(Self[p - 1])) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
          Dec(p);
      end else
        Inc(p);
  end;
end;

{==============================================================================]
  <GnomeSortOptimized>
  @action: Optimized GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
var
  p, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    l := 0;
    while (p <= Result) do
      if (Sign(Self[p].Compare(Self[p - 1])) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
        begin
          if (l <> 0) then
            l := p
          else
            Dec(p);
        end else
          Inc(p);
      end else
        if (l <> 0) then
        begin
          p := l;
          l := 0;
        end else
          Inc(p);
  end;
end;

{==============================================================================]
  <PancakeSort>
  @action: PancakeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.PancakeSort(const aAscending: Boolean = True): Integer; overload;
var
  i, j, l, m, x, o: Integer;
begin
  Result := High(Self);
  if (Result > 0 )then
  begin
    o := aAscending.Select(-1, 1);
    l := 0;
    for i := Result downto l do
    begin
      m := i;
      for j := l to (i - 1) do
        if (Sign(Self[m].Compare(Self[j])) = o) then
          m := j;
      if (m = i) then
        Continue;
      if (m <> l) then
      for x := l to (((m - l) - 1) div 2) do
        Exchange(x, (m - (x - l)));
      for x := l to (((i - l) - 1) div 2) do
        Exchange(x, (i - (x - l)));
    end;
  end;
end;

{==============================================================================]
  <BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function MArrayHelper.BubbleSort(const aAscending: Boolean = True): Integer; overload;
var
  i, j: Integer;
begin
  Result := High(Self);
  for i := Result downto 1 do
    for j := 0 to (i - 1) do
      if ((aAscending and (Self[j] > Self[j + 1])) or ((not aAscending) and (Self[j] < Self[j + 1]))) then
        Exchange(j, (j + 1));
end;

{==============================================================================]
  <BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function MArrayHelper.BubbleSort2(const aAscending: Boolean = True): Integer; overload;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 0 to (Result - 1) do
      for b := 1 to (Result - a) do
        if (Sign(Self[b].Compare(Self[b - 1])) = o) then
          Exchange(b, (b - 1));
  end;
end;

{==============================================================================]
  <BubbleSortOptimized>
  @action: Sorts arr with optimized BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function MArrayHelper.BubbleSortOptimized(const aAscending: Boolean = True): Integer; overload;
var
  i, j: Integer;
  s: Boolean;
begin
  Result := High(Self);
  for i := Result downto 1 do
  begin
    s := False;
    for j := 0 to (i - 1) do
      if ((aAscending and (Self[j] > Self[j + 1])) or ((not aAscending) and (Self[j] < Self[j + 1]))) then
      begin
        Exchange(j, (j + 1));
        s := True;
      end;
    if not s then
      Break;
  end;
end;

{==============================================================================]
  <CombSort>
  @action: CombSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.CombSort(const aAscending: Boolean = True): Integer; overload;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    g := Self.Size;
    s := True;
    while ((g > 1) or s) do
    begin
      g := Trunc(g / 1.3);
      if (g < 1) then
        g := 1;
      s := False;
      for i := 0 to (Result - g) do
        if (Sign(Self[i + g].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + g));
          s := True;
        end;
    end;
  end;
end;

{==============================================================================]
  <HeapSort>
  @action: HeapSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.HeapSort(const aAscending: Boolean = True): Integer; overload;
var
  a, b, r, c, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    a := (Result div 2);
    b := Result;
    while (a >= 0) do
    begin
      r := a;
      while (((r * 2) + 1) <= Result) do
      begin
        c := ((r * 2) + 1);
        if ((c < Result) and (Sign(Self[c].Compare(Self[c + 1])) = o)) then
          c := (c + 1);
        if (Sign(Self[r].Compare(Self[c])) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
      a := (a - 1);
    end;
    while (b > 0) do
    begin
      Exchange(0, b);
      b := (b - 1);
      r := 0;
      while (((r * 2) + 1) <= b) do
      begin
        c := ((r * 2) + 1);
        if ((c < b) and (Sign(Self[c].Compare(Self[c + 1])) = o)) then
          c := (c + 1);
        if (Sign(Self[r].Compare(Self[c])) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
    end;
  end;
end;

{==============================================================================]
  <InsertionSort>
  @action: InsertionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.InsertionSort(const aAscending: Boolean = True): Integer; overload;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 1 to Result do
      for b := a downto 1 do
        if (Sign(Self[b].Compare(Self[b - 1])) = o) then
		  Exchange(b, (b - 1))
		else
          Break;
  end;
end;

{==============================================================================]
  <SelectionSort>
  @action: SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSort(const aAscending: Boolean = True): Integer; overload;
var
  c, t, m, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for c := 0 to Result do
    begin
      m := c;
      for t := (c + 1) to Result do
        if (Sign(Self[t].Compare(Self[m])) = o) then
          m := t;
      Exchange(m, c);
    end;
  end;
end;

{==============================================================================]
  <SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
var
  i, s, o: Integer;
  x, y: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for i := 0 to (Result div 2) do
    begin
      y := x.Init(i, (Result - i));
      if (Sign(Self[x.start].Compare(Self[x.stop])) = -o) then
        Exchange(x.stop, x.start);
      for s := (y.start + 1) to (y.stop - 1) do
        if (Sign(Self[s].Compare(Self[x.start])) = o) then
          x.start := s
        else
          if (Sign(Self[s].Compare(Self[x.stop])) = -o) then
            x.stop := s;
      if (x.start <> y.start) then
        Exchange(y.start, x.start);
      if (x.stop <> y.stop) then
        Exchange(y.stop, x.stop);
    end;
  end;
end;

{==============================================================================]
  <SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
var
  s, i, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for i := 0 to (Result div 2) do
    begin
      r.Create(i, (Result - i));
      if (Sign(Self[r.stop].Compare(Self[r.start])) = o) then
        Exchange(r.start, r.stop);
      for s := (r.start + 1) to (r.stop - 1) do
        if (Sign(Self[s].Compare(Self[r.start])) = o) then
          Exchange(r.start, s)
        else
          if (Sign(Self[s].Compare(Self[r.stop])) = -o) then
            Exchange(s, r.stop);
      end;
  end;
end;

{==============================================================================]
  <ShellSort>
  @action: ShellSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.ShellSort(const aAscending: Boolean = True): Integer; overload;
var
  x, a, b, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    case (Result > 1) of
      True:
      begin
        l := Self.Length;
        x := 0;
        while (x < (l div 3)) do
          x := ((x * 3) + 1);
        while (x >= 1) do
        begin
          for a := x to (l - 1) do
          begin
            b := a;
            while ((b >= x) and (Sign(Self[b].Compare(Self[b - x])) = o)) do
	    begin
              Exchange(b, (b - x));
	      b.Decrease(x);
	    end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(Self[1].Compare(Self[0])) = o) then
        Exchange(0, 1);
    end;
  end;
end;

{==============================================================================]
  <MergeSort>
  @action: MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.MergeSort(const aAscending: Boolean = True): Integer; overload;
  procedure Merge(var arr, tmp: MArray; const Lo, Hi: Integer; const aAscending: Boolean = True);
  var
    l, r, i, m, o: Integer;
  begin
    if (Lo >= Hi) then
      Exit;
    o := aAscending.Select(-1, 1);
    m := (Lo + ((Hi - Lo) div 2));
    Merge(arr, tmp, Lo, m, aAscending);
    Merge(arr, tmp, (m + 1), Hi, aAscending);
    l := Lo;
    r := (m + 1);
    for i := Lo to Hi do
      tmp[i] := arr[i];
    for i := Lo to Hi do
      if (L > m) then
        arr[i] := tmp[r.Increase]
      else
        if (R > Hi) then
          arr[i] := tmp[l.Increase]
        else
          if (Sign(tmp[r].Compare(tmp[l])) = o) then
            arr[i] := tmp[r.Increase]
          else
            arr[i] := tmp[l.Increase];
  end;
var
  t: MArray;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    Merge(Self, t, 0, Result, aAscending);
  end;
end;

{==============================================================================]
  <MergeSortBU>
  @action: Bottom-up MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.MergeSortBU(const aAscending: Boolean = True): Integer; overload;
var
  t: MArray;
  w, i, s: Integer;
  l, r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    w := 1;
	SetLength(t, (Result + 1));
    while (w <= Result) do
    begin
      i := 0;
      while (i <= Result) do
      begin
	    l.Create(i, Min((i + (w - 1)), Result));
	    r.Create((l.stop + 1), Min((l.start + (2 * w) - 1), Result)); 
        for s := l.start to r.stop do
          t[s] := Self[s];
		s := i;
        while (l.Ascending and r.Ascending) do
		  if ((aAscending and (t[l.start] <= t[r.start])) or (not aAscending and (t[l.start] >= t[r.start]))) then
            Self[s.Increase] := t[l.start.Increase]
          else
            Self[s.Increase] := t[r.start.Increase];
        while l.Ascending do
          Self[s.Increase] := t[l.start.Increase];
        while r.Ascending do
          Self[s.Increase] := t[r.start.Increase];
        i.Increase(2 * w);
      end;
      w := (w * 2);
    end;
  end;
end;

{==============================================================================]
  <HybridSort>
  @action: Sorts the integer array (Self) in ascending or descending order
           using algorithm close to TimSort — a stable hybrid sorting method that
           combines insertion sort and merge sort for optimal performance.
  @note:   - Returns Length(Self)
           - Stable (preserves equal element order)
[==============================================================================}
function MArrayHelper.HybridSort(const aAscending: Boolean = True): Integer; overload;
const
  RUN_SIZE = 32;
  procedure INS(var arr: MArray; const L, R: Integer);
  var
    t: MType;
    i, j: Integer;
  begin
    for i := (L + 1) to R do
    begin
      t := arr[i];
      j := (i - 1);
      while ((j >= L) and ((aAscending and (arr[j] > t)) or ((not aAscending) and (arr[j] < t)))) do
      begin
	    arr[j + 1] := arr[j];
		Dec(j);
	  end;
      arr[j + 1] := t;
    end;
  end;
  procedure MRG(var arr: MArray; const L, M, R: Integer);
  var
    a, b, i, j, k: Integer;
    x, y: MArray;
  begin
    a := ((M - L) + 1);
    b := (R - M);
    SetLength(x, a);
    SetLength(y, b);
    for i := 0 to (a - 1) do
      x[i] := arr[L + i];
    for i := 0 to (b - 1) do
      y[i] := arr[(M + 1) + i];
    i := 0;
    j := 0;
    k := L;
    while ((i < a) and (j < b)) do
      if ((aAscending and (x[i] <= y[j])) or ((not aAscending) and (x[i] >= y[j]))) then
        arr[k.Increase] := x[i.Increase]
      else
        arr[k.Increase] := y[j.Increase];
    while (i < a) do
      arr[k.Increase] := x[i.Increase];
    while (j < b) do
      arr[k.Increase] := y[j.Increase];
  end;
var
  i, s, l, m, r: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  i := 0;
  while (i < Result) do
  begin
    if (((i + RUN_SIZE) - 1) < Result) then
      INS(Self, i, ((i + RUN_SIZE) - 1))
    else
      INS(Self, i, (Result - 1));
    Inc(i, RUN_SIZE);
  end;
  s := RUN_SIZE;
  while (s < Result) do
  begin
    l := 0;
    while (l < (Result - 1)) do
    begin
      m := ((l + s) - 1);
      r := ((l + (2 * s)) - 1);
      if (r >= Result) then
        r := (Result - 1);
      if (m < r) then
        MRG(Self, l, m, r);
      Inc(l, (2 * s));
    end;
    s := (s * 2);
  end;
end;

{==============================================================================]
  <Uniq>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function MArrayHelper.Uniq(const sSorted: Boolean = False): MArray; overload;
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    if not sSorted then
      Result := Self.QuickSorted.Pruned
    else
      Result := Self.Pruned;
end;

{==============================================================================]
  <Downtrending>
  @action: Returns True if the first element of the array is greater than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “falling” trend.
[==============================================================================}
function MArrayHelper.Downtrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] > Self[High(Self)]));
end;

{==============================================================================]
  <Uptrending>
  @action: Returns True if the first element of the array is less than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “rising” trend.
[==============================================================================}
function MArrayHelper.Uptrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] < Self[High(Self)]));
end;

{==============================================================================]
  <Notrending>
  @action: Returns True if the first element of the array is equal to the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates no significant trend.
[==============================================================================}
function MArrayHelper.Notrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] = Self[High(Self)]));
end;

{==============================================================================]
  <Trend>
  @action: Returns the trend of the array’s endpoints:
            1 = Uptrend (first < last),
           -1 = Downtrend (first > last),
            0 = Notrend (first = last or array too short).
  @note: Only meaningful for arrays with at least 2 elements.
         Comparison is done between the first and last elements only.
[==============================================================================}
function MArrayHelper.Trend: Integer; overload;
begin
  if ((Self.Size < 2) or (Self[Low(Self)] = Self[High(Self)])) then
    Result := 0
  else
    if (Self[Low(Self)] > Self[High(Self)]) then
      Result := -1
    else
      Result := 1;
end;

{==============================================================================]
  <Trending>
  @action: Returns True if the array is either Uptrending or Downtrending.
  @note: Only meaningful for arrays with at least 2 elements.
         Returns False if the array has no trend (Notrending).
[==============================================================================}
function MArrayHelper.Trending: Boolean; overload;
begin
  Result := (Self.Trend <> 0);
end;

{==============================================================================]
  <Rising>
  @action: Returns True if the array is monotonically non-decreasing,
           i.e., each element is less than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Rising by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function MArrayHelper.Rising: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] > Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Falling>
  @action: Returns True if the array is monotonically non-increasing,
           i.e., each element is greater than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Falling by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function MArrayHelper.Falling: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] < Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Direction>
  @action: Returns numeric trend across the entire array:
           1 = Rising (monotonically non-decreasing),
          -1 = Falling (monotonically non-increasing),
           0 = Notrending (mixed sequence or empty/single element).
  @note: Checks all elements. Inclusive comparisons (≤ / ≥).
[==============================================================================}
function MArrayHelper.Direction: Integer; overload;
begin
  if Self.Notrending then
    Result := 0
  else
    if Rising then
      Result := 1
    else
      Result := -1;
end;

{==============================================================================]
  <TrendFalling>
  @action: Returns True if the first element of the array is greater than or equal to the last element,
           indicating a non-increasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function MArrayHelper.TrendFalling: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] >= Self[High(Self)]));
end;

{==============================================================================]
  <TrendRising>
  @action: Returns True if the first element of the array is less than or equal to the last element,
           indicating a non-decreasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function MArrayHelper.TrendRising: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] <= Self[High(Self)]));
end;

{==============================================================================]
  <BinaryInsertionSort>
  @action: Sorts the array in ascending or descending order using binary
           insertion sort, which combines binary search and insertion.
  @note: This algorithm runs in O(n²) time in the worst case but uses binary
         search to minimize comparisons. It performs well on small or
         partially sorted datasets. Returns the number of elements sorted.
[==============================================================================}
function MArrayHelper.BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
  function BP(const value: MType; const hIndex: Integer): Integer;
  var
    L, R, M: Integer;
  begin
    L := 0;
    R := hIndex;
    while (L <= R) do
    begin
      M := ((L + R) div 2);
      if ((aAscending and (Self[M] > value)) or ((not aAscending) and (Self[M] < value))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    Result := L;
  end;
var
  k: MType;
  i, j, p: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  for i := 1 to (Result - 1) do
  begin
    k := Self[i];
    p := BP(k, (i - 1));
    j := (i + 1);
    while (j.Decrement > p) do
      Self[j] := Self[j - 1];
    Self[p] := k;
  end;
end;

{==============================================================================]
  <Sortedness>
  @action: Checks whether the array is monotonic (either ascending or descending).
           Performs a two-phase check: a fast global trend detection from both ends,
           followed by a full local adjacency check to ensure strict monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses Integer_Sign(Self[L], Self[R]) to detect initial trend.
         Efficient for large arrays due to early exit if disorder is detected.
         This version checks every element in both phases.
[==============================================================================}
function MArrayHelper.Sortedness: Boolean; overload;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or ((L.Increment > R.Decrement)));
  if (not Result) then
    Exit;
  L := -1;
  case (D > 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;

{==============================================================================]
  <SortednessEx>
  @action: Enhanced version of Sortedness with configurable stride.
           Performs a subsampled global trend check (using left and right indices
           at intervals of "stride") to quickly detect gross disorder,
           followed by a full local adjacency check if the array passes the global phase.
  @note: Default stride = 16; larger values reduce global comparisons but may delay detection
         of small local disorder. Returns True for arrays of length 0 or 1.
         Useful for extremely large arrays where global trend violation is likely.
[==============================================================================}
function MArrayHelper.SortednessEx(const stride: Integer = 16): Boolean; overload;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or (L.Increment(stride) >= R.Decrement(stride)));
  if not Result then
    Exit;
  L := -1;
  R := High(Self);
  case (D >= 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;

{==============================================================================]
  <Monotonic>
  @action: Checks whether the array is globally monotonic by simultaneously comparing
           elements from both ends toward the center, while also validating adjacent pairs.
           Detects ascending or descending trends dynamically based on endpoints.
  @note: Returns True for arrays of length 0 or 1.
         This approach may detect global disorder slightly earlier than adjacent-only checks.
         Performs both global and local comparisons in a single loop.
         Uses Integer_Increment and Integer_Decrement for safe index movement.
[==============================================================================}
function MArrayHelper.Monotonic: Boolean; overload;
var
  L, R: Integer;
begin
  L := -1;
  R := Self.Size;
  if (R > 1) then
  case (Self[L + 1] <= Self[R - 1]) of
    True:
    while (L.Increment < R.Decrement) do
      if ((Self[R] < Self[L]) or (Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R])) then
        Exit(False);
    False:
    while (L.Increment < R.Decrement) do
      if ((Self[R] > Self[L]) or (Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R])) then
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Monotone>
  @action: Checks whether the array is monotonic (ascending or descending) by performing
           a symmetric two-way scan from both ends toward the middle.
           Repeatedly evaluates adjacent pairs and global trend to determine monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses a repeat-until loop with early exit if a violation is detected.
         This function is a slightly simpler alternative to Sortedness, but checks both
         global and local conditions for each iteration.
[==============================================================================}
function MArrayHelper.Monotone: Boolean; overload;
var
  L, R: Integer;
begin
  L := 0;
  R := High(Self);
  if (R <= L) then
    Exit(True);
  case (Self[L] <= Self[R]) of
    True:
    repeat
      Result := not ((Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
    False:
    repeat
      Result := not ((Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
  end;
end;

{==============================================================================]
  <IsMonotone>
  @action: Determines whether the array is monotone — that is, entirely non-decreasing
           or non-increasing throughout its elements.
           Returns True if the array’s values either never decrease (monotone ascending)
           or never increase (monotone descending). Equal adjacent values are allowed.
           Returns False if the array changes direction (both rises and falls occur).
  @note:
    • Works correctly for arrays of any length.
      (Empty or single-element arrays are considered monotone.)
    • The function short-circuits for efficiency — exits early once a
      non-monotone pattern is detected.
[==============================================================================}
function MArrayHelper.IsMonotone: Boolean; overload;
var
  i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    case Self[i].Sign(Self[i - 1]) of
      0: Continue;
      1: D := False;
      -1: A := False;
    end;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <Monotonious>
  @action:
    Determines whether the integer array is monotone — that is, entirely
    non-decreasing or entirely non-increasing.

    The function iterates through the array, comparing each element with its
    predecessor. Two variables track whether any increases (`h`) or decreases
    (`l`) have been observed. If both an increase and a decrease occur, the
    array is not monotone, and the function immediately returns False. Otherwise,
    it returns True.
  @note:
    • Empty or single-element arrays are considered monotone (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses two integer flags (`h` for increases, `l` for decreases) instead of
      a single accumulator or Boolean pair.
    • Short-circuits for efficiency — exits as soon as both directions are seen.
    • This is functionally equivalent to other “direction-lock” or “accumulator”
      implementations but tracks high/low separately.
[==============================================================================}
function MArrayHelper.Monotonious: Boolean; overload;
var
  i, h, l: Integer;
begin
  l := 0;
  h := 0;
  for i := 1 to High(Self) do
  begin
    if (Self[i] = Self[i - 1]) then
      Continue;
    if (Self[i] > Self[i - 1]) then
      h := 1
    else if (Self[i] < Self[i - 1]) then
      l := -1;
    if ((h = 1) and (l = -1)) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Unidirectional>
  @action: Checks if the array is monotonic (either non-decreasing or non-increasing).
  @note: Returns True if all elements move in one direction, False otherwise.
[==============================================================================}
function MArrayHelper.Unidirectional: Boolean; overload;
label
  D;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] < Self[i - 1]) then
      goto D;
  Exit(True);
  D:
  for i := 1 to High(Self) do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Trendy>
  @action: Checks whether the array is monotonic — either entirely non-decreasing,
           non-increasing, or constant.
  @note: Returns True if the array changes in only one direction; False otherwise.
[==============================================================================}
function MArrayHelper.Trendy: Boolean; overload;
var
  i, h, l: Integer;
begin
  h := 0;
  l := 0;
  for i := 1 to High(Self) do
    if ((Self[i] > Self[i - 1]) and (h.Increment <= l)) then
      Break
    else if ((Self[i] < Self[i - 1]) and (l.Increment <= h)) then
      Break;
  Result := not ((h > 0) and (l > 0));
end;

{==============================================================================]
  <OnOrder>
  @action: Determines whether the array elements remain consistently ordered,
           either non-decreasing, non-increasing, or constant.
  @note: Returns True if the sequence does not reverse direction (monotonic in
         either direction). Returns False if the order changes (both rises and falls occur).
[==============================================================================}
function MArrayHelper.OnOrder: Boolean; overload;
var
  i, h, l: Integer;
begin
  h := 0;
  l := 0;
  for i := 1 to High(Self) do
    if ((h.Increment(Self[i] > Self[i - 1]) * l.Increment(Self[i] < Self[i - 1])) > 0) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Peaks>
  @action: Returns the indices of all local maxima in the array.
  @note: A local maximum is any element strictly greater than its immediate
         neighbors. Edge elements (index 0 or index High) are included when
         they satisfy the one-sided comparison. The result array is sized
         exactly to the number of detected peaks.
[==============================================================================}
function MArrayHelper.Peaks: TIntegerArray; overload;
var
  h, l, i: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if Self.Empty then
    Exit;
  l := 0;
  if ((h = 0) or (Self[0] > Self[1])) then
    Result[l.Increase] := 0;
  for i := 1 to (h - 1) do
    if ((Self[i] > Self[i - 1]) and (Self[i] > Self[i + 1])) then
      Result[l.Increase] := i;
  if ((h > 0) and (Self[h] > Self[h - 1])) then
    Result[l.Increase] := h;
  SetLength(Result, l);
end;

{==============================================================================]
  <Valleys>
  @action: Returns the indices of all local minima in the array.
  @note: A local minimum is any element strictly lower than its immediate
         neighbors. Edge elements (index 0 or index High) are included when
         they satisfy the one-sided comparison. The result array is sized
         exactly to the number of detected valleys.
[==============================================================================}
function MArrayHelper.Valleys: TIntegerArray; overload;
var
  h, l, i: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if Self.Empty then
    Exit;
  l := 0;
  if ((h = 0) or (Self[0] < Self[1])) then
    Result[l.Increase] := 0;
  for i := 1 to (h - 1) do
    if ((Self[i] < Self[i - 1]) and (Self[i] < Self[i + 1])) then
      Result[l.Increase] := i;
  if (h > 0) and (Self[h] < Self[h - 1]) then
    Result[l.Increase] := h;
  SetLength(Result, l);
end;

{==============================================================================]
  <Unionize>
  @action: Produces the sorted set-union of two integer arrays, eliminating
           duplicates while preserving the requested ordering direction.
  @note: Both source arrays must already be sorted in the same direction
         (ascending or descending). The result is returned as a newly
         allocated array sized exactly to the number of distinct merged
         elements.
[==============================================================================}
function MArrayHelper.Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l, a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, (a + b));
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while ((i < a) and (j < b)) do
  begin
    case ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j]))) of
      True:
      begin
        if ((not e) or (Self[i] <> v)) then
        begin
          v := Self[i];
          Result[l.Increase] := v;
          e := True;
        end;
        Inc(i);
      end;
      False:
      case ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j]))) of
        True:
        begin
          if ((not e) or (items[j] <> v)) then
          begin
            v := items[j];
            Result[l.Increase] := v;
            e := True;
          end;
          Inc(j);
        end;
        False:
        begin
          if ((not e) or (Self[i] <> v)) then
          begin
            v := Self[i];
            Result[l.Increase] := v;
            e := True;
          end;
          Inc(i);
          Inc(j);
        end;
      end;
    end;
  end;
  while (i < a) do
  begin
    if ((not e) or (Self[i] <> v)) then
    begin
      v := Self[i];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(i);
  end;
  while (j < b) do
  begin
    if ((not e) or (items[j] <> v)) then
    begin
      v := items[j];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(j);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Subtract>
  @action: Constructs and returns a new array representing the set difference
           of this array minus `items`. Only values present in this array and
           absent from `items` are included. The output is sorted according to
           `oAscending` and contains no duplicate values.
  @note: Both input arrays must be pre-sorted in the same direction specified
         by `oAscending`. The implementation performs a linear pass over both
         arrays and executes in O(m + n) time, where m and n are their
         respective lengths. This is the standard A − B set-difference
         operation.
[==============================================================================}
function MArrayHelper.Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l: Integer;
  a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, a);
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while (i < a) do
  begin
    while ((j < b) and ((oAscending and (items[j] < Self[i])) or ((not oAscending) and (items[j] > Self[i])))) do
      Inc(j);
    if (((j >= b) or ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j])))) and ((not e) or (Self[i] <> v))) then
    begin
      v := Self[i];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(i);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Intersect>
  @action: Returns a new array containing all elements that appear in BOTH this
           array and `items`. The result is sorted according to `oAscending`
           and contains no duplicates.
  @note: Both arrays must be sorted in the same order specified by `oAscending`.
         This implementation uses a linear merge approach with O(m + n) time
         complexity, which is optimal for this operation.
[==============================================================================}
function MArrayHelper.Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l, a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, Min(a, b));
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while ((i < a) and (j < b)) do
  case (Self[i] = items[j]) of
    True:
    begin
      if ((not e) or (Self[i] <> v)) then
      begin
        v := Self[i];
        Result[l.Increase] := v;
        e := True;
      end;
      Inc(i);
      Inc(j);
    end;
    False:
    if ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j]))) then
      Inc(i)
    else
      Inc(j);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <IntersectionCount>
  @action: Counts the number of elements that appear in both Self and Items, treating
           duplicates according to multiset semantics (each match consumes one element
           from each array).
  @note:
    - Both Self and Items must be sorted in the same order (ascending or
      descending) as indicated by oAscending.
    - Uses a linear merge algorithm; time complexity is O(N + M), where N =
      Length(Self), M = Length(Items).
    - Each element in Self can match at most one element in Items.
    - Duplicates in either array are handled pairwise:
        e.g., Self = [2,2,2], Items = [2,2] → Result = 2
    - Returns 0 if either array is empty.
[==============================================================================}
function MArrayHelper.IntersectionCount(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  h, s, i, j: Integer;
begin
  Result := 0;
  i := 0;
  j := 0;
  s := High(Self);
  h := High(Items);
  while ((i <= s) and (j <= h)) do
  case (Self[i] = items[j]) of
    True:
    begin
      Inc(Result);
      Inc(i);
      Inc(j);
    end;
    False:
    if ((Self[i] < items[j]) xor (not oAscending)) then
      Inc(i)
    else
      Inc(j);
  end;
end;

{==============================================================================]
  <Spanning>
  @action: Searches the array for the specified `item` and returns a TRange
           representing the inclusive index span where `item` occurs.
           Works for both ascending and descending arrays, as specified by `oAscending`.
           If the array is empty or the item is not found, returns a sentinel TRange
           with both `start` and `stop` set to Low(Integer).
  @note:
    - `oAscending` indicates whether the array is sorted in ascending order (True)
      or descending order (False).
    - Scans from both ends of the array:
        - `Result.start` increments until the first occurrence of `item` is found.
        - `Result.stop` decrements until the last occurrence of `item` is found.
    - Works correctly with negative numbers.
    - Returned TRange:
        - `Result.start <= Result.stop` → item found; range of indices inclusive.
        - `Result.start > Result.stop` → item not found; sentinel range returned.
    - Time complexity: O(n) (linear search).
[==============================================================================}
function MArrayHelper.Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
begin
  if Self.Empty then
    Exit(TRange.Construct(Low(Integer), Low(Integer)));
  Result.Create(0, High(Self));
  while ((Result.start < Result.stop) and ((oAscending and (Self[Result.start] < item)) or ((not oAscending) and (Self[Result.start] > item)))) do
    Inc(Result.start);
  while ((Result.stop >= Result.start) and ((oAscending and (Self[Result.stop] > item)) or ((not oAscending) and (Self[Result.stop] < item)))) do
    Dec(Result.stop);
  if (Result.start > Result.stop) then
    Result.Create(Low(Integer));
end;

{==============================================================================]
  <CountOf>
  @action: Counts how many elements in Self are present in the array items, assuming
           items is already sorted in either ascending or descending order.
  @note:
    - Membership testing is performed using binary search.
    - Items must be sorted prior to calling this function.
    - The iAscending flag specifies the sort direction of Items.
    - Each element in Self is counted independently; duplicates in Self are
      counted multiple times if present in Items.
    - Time complexity: O(N log M), where N = Length(Self),
      M = Length(Items).
[==============================================================================}
function MArrayHelper.CountOf(const items: MArray; const iAscending: Boolean = True): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  if (items.Length > 0) then
  for i := 0 to High(Self) do
    if (items.WithinBounds(Self[i], iAscending) and (items.BinarySearchBy(Self[i], iAscending) > -1)) then
      Inc(Result);
end;

{==============================================================================]
  <Counted>
  @action: Counts how many elements in Self are present in the array items, optionally
           sorting items internally if it is not already sorted.
  @note:
    - If iSorted = False, Items is copied and sorted before searching.
    - If iSorted = True, Items is assumed to be pre-sorted.
    - Binary search is used for membership testing.
    - Sort order is automatically inferred when Items is sorted.
    - Each element in Self is counted independently; duplicates in Self are
      counted multiple times if present in Items.
    - Time complexity:
        * iSorted = False: O(M log M + N log M)
        * iSorted = True : O(N log M)
      where N = Length(Self), M = Length(Items).
[==============================================================================}
function MArrayHelper.Counted(const items: MArray; const iSorted: Boolean = False): Integer; overload;
var
  s: MArray;
  i: Integer;
  a: Boolean;
begin
  Result := 0;
  if ((items.Length > 0) and (Self.Length > 0)) then
  case iSorted of
    False:
	  begin
	    s := items.QuickSorted;
      for i := 0 to High(Self) do
        if (items.WithinBounds(Self[i]) and (items.BinarySearchBy(Self[i]) > -1)) then
          Inc(Result);
    end;
    True:
    begin
      a := (items[0] <= items[High(items)]);
      for i := 0 to High(Self) do
        if (items.WithinBounds(Self[i], a) and (items.BinarySearchBy(Self[i], a) > -1)) then
          Inc(Result);
    end;
  end;
end;

{==============================================================================]
  <MinItem>
  @action: Returns minimum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MinItem: MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
    Result := Self[0];
  for i := 1 to High(Self) do
    Result := Min(Self[i], Result);
end;

{==============================================================================]
  <MinItem>
  @action: Returns minimum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MinItem(const null: MType): MType; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Min(Self[i], Result);
end;

{==============================================================================]
  <MaxItem>
  @action: Returns maximum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxItem: MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
    Result := Self[0];
  for i := 1 to High(Self) do
    Result := Max(Self[i], Result);
end;

{==============================================================================]
  <MaxItem>
  @action: Returns maximum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxItem(const null: MType): MType; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Max(Self[i], Result);
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Minimum(var index: Integer): MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
  begin
    index := 0;
    for i := 1 to High(Self) do
      if (Self[i] < Self[index]) then
        index := i;
    Result := Self[index];
  end else
    index := -1;
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Minimum: MType; overload;
var
  i: Integer;
begin
  Result := Self.Minimum(i);
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Maximum(var index: Integer): MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
  begin
    index := 0;
    for i := 1 to High(Self) do
      if (Self[i] > Self[index]) then
        index := i;
    Result := Self[index];
  end else
    index := -1;
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Maximum: MType; overload;
var
  i: Integer;
begin
  Result := Self.Maximum(i);
end;

{==============================================================================]
  <Minim>
  @action: Returns minimum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Minim(var index: Integer): MType; overload;
var
  i: Integer;
begin
  index := IfThen(Self.Empty, -1, 0);
  for i := 1 to High(Self) do
    if (Self[i] < Self[index]) then
      index := i;
  if (index > -1) then
    Result := Self[index];
end;

{==============================================================================]
  <Minim>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Minim: MType; overload;
var
  i: Integer;
begin
  Result := Self.Minim(i);
end;

{==============================================================================]
  <Maxim>
  @action: Returns maximum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Maxim(var index: Integer): MType; overload;
var
  i: Integer;
begin
  index := IfThen(Self.Empty, -1, 0);
  for i := 1 to High(Self) do
    if (Self[i] > Self[index]) then
      index := i;
  if (index > -1) then
    Result := Self[index];
end;

{==============================================================================]
  <Maxim>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Maxim: MType; overload;
var
  i: Integer;
begin
  Result := Self.Maxim(i);
end;

{==============================================================================]
  <WithinBounds>
  @action: Returns True if the specified item lies within the minimum and
           maximum bounds of the array.
  @note: The array must be sorted according to the value of oAscending.
         An empty array always returns False.
[==============================================================================}
function MArrayHelper.WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := not (Self.Empty or (item < Self[0]) or (item > Self[High(Self)]))
  else
    Result := not (Self.Empty or (item > Self[0]) or (item < Self[High(Self)]));
end;

{==============================================================================]
  <OutOfBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array, or if the array is empty.
  @note: This function is the logical inverse of WithinBounds and assumes
         the same sort-order invariant.
[==============================================================================}
function MArrayHelper.OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.WithinBounds(item, oAscending);
end;

{==============================================================================]
  <Accepts>
  @action: Returns True if the specified item is acceptable with respect to
           the array’s boundary constraints.
  @note: The array must contain at least one element.
         The array is assumed to be sorted according to oAscending.
         The check is inclusive of the first and last elements.
         An empty array rejects all values.
[==============================================================================}
function MArrayHelper.Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <Rejects>
  @action: Returns True if the specified item violates the array’s boundary
           constraints or if the array is empty.
  @note: This function is the logical inverse of Accepts.
         The array is assumed to be sorted according to oAscending.
         Boundary violations provide a strict (exclusive) rejection.
[==============================================================================}
function MArrayHelper.Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length = 0) or ((oAscending and ((item < Self[0]) or (item > Self[High(Self)]))) or ((not oAscending) and ((item > Self[0]) or (item < Self[High(Self)])))));
end;

{==============================================================================]
  <InsideBounds>
  @action  Returns True if the specified item lies within the minimum and
           maximum bounds of the array.
  @note    - The array must be sorted according to the value of oAscending.
           - Boundary values (first and last elements) are included.
           - Returns False if the array is empty.
           - Supports ascending or descending sorted arrays depending on oAscending.
[==============================================================================}
function MArrayHelper.InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <OutsideBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array or if the array is empty.
  @note: - Logical inverse of InsideBounds.
         - The array must be sorted according to the value of oAscending.
         - Supports ascending or descending sorted arrays depending on oAscending.
[==============================================================================}
function MArrayHelper.OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.InsideBounds(item, oAscending);
end;

{==============================================================================]
  <FibonacciSearch>
  @action: Executes a Fibonacci Search over the array.
           The routine locates the index of a target value using progressively
           shrinking search intervals determined by the Fibonacci sequence.
           The array may be sorted in ascending or descending order as
           specified by the oAscending parameter. Returns the index of the 
           matching element if found; otherwise returns -1.
  @note: Fibonacci Search is an alternative to binary search that partitions
         the search interval using Fibonacci ratios rather than powers of two.
         It preserves ordered-search correctness while enabling searches that
         favor sequential access patterns. Performance is comparable to 
         binary search for random-access arrays and may offer advantages for 
         memory-hierarchy–sensitive workloads. The input array must be
         pre-sorted in the order defined by oAscending.
[==============================================================================}
function MArrayHelper.FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  H, o, i: Integer;
  F: TRange;
begin
  H := High(Self);
  F.Create(0, 1);
  M := (F.stop + F.start);
  while (M < (H + 1)) do
  begin
    F.start := F.stop;
    F.stop := M;
    M := (F.stop + F.start);
  end;
  o := -1;
  while (M > 1) do
  begin
    i := Integer(o + F.start).ClampMax(H);
    case ((oAscending and (Self[i] < item)) or ((not oAscending) and (Self[i] > item))) of
      True:
      begin
        M := F.stop;
        F.stop := F.start;
        F.start := (M - F.stop);
        o := i;
      end;
      False:
      case ((oAscending and (Self[i] > item)) or ((not oAscending) and (Self[i] < item))) of
        True:
        begin
          M := F.start;
          F.stop := (F.stop - F.start);
          F.start := (M - F.stop);
        end;
        False: Exit(i);
      end;
    end;
  end;
  if ((F.stop = 1) and ((o + 1) <= H) and (Self[o + 1] = item)) then
    Exit(o + 1);
  Result := -1;
end;

{==============================================================================]
  <BinarySearchBy>
  @action: Performs a binary search over the array using a
           comparator-based comparison. Returns the index of the specified
           item if found, or -1 if the item is not present. Supports arrays
           sorted in ascending or descending order.
  @note: The input array must be pre-sorted according to the order specified
         by the oAscending parameter. This function uses a standard binary
         search algorithm: repeatedly divides the search interval in half
         until the target item is found or the interval is empty.
         Comparisons are performed using Integer_Compare, allowing for
         consistent ordering and potential extension to other comparison logic.
[==============================================================================}
function MArrayHelper.BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  R: TRange;
  M, C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := Self[M].Compare(item);
    if (C = 0) then
      Exit(M);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryHas>
  @action: Checks whether the specified item exists in the sorted integer array.
           Returns True if the item is found, otherwise False. If found, the
           index of the item is returned via the 'out' parameter.
  @note: The array must be pre-sorted according to the order specified by
         'oAscending'. Supports both ascending and descending arrays. Uses
          a standard binary search algorithm to efficiently locate the item.
[==============================================================================}
function MArrayHelper.BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
  C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := Self[index].Compare(item);
	if (C = 0) then
	  Exit(True);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  Result := False;
  index := -1;
end;

{==============================================================================]
  <BinaryGot>
  @action: Performs a binary search on the array to determine
           whether a specified value exists and returns its index if found.
  @note: Assumes the array is pre-sorted in either ascending or descending
         order, depending on the oAscending flag. Uses TRange utilities
         for interval reduction; returns -1 when the item is not present.
[==============================================================================}
function MArrayHelper.BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    if (Self[index] = item) then
      Exit(True);
    if ((oAscending and (Self[index] < item)) or ((not oAscending) and (Self[index] > item))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end; 

{==============================================================================]
  <BinaryExpSearch>
  @action: Performs an exponential (galloping) search to locate the specified
           item in a sorted TIntegerArray. Returns the index of the item if
           found; otherwise returns -1. Combines exponential range expansion
           with standard binary search within the identified range.
  @note: The array must be pre-sorted according to 'oAscending'. Efficient
         for large arrays or targets near the beginning. Supports ascending
         (default) and descending arrays. Time complexity is O(log n).
[==============================================================================}
function MArrayHelper.BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  B, L: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(-1);
  B := 1;
  while ((B < L) and ((oAscending and (Self[B] < item)) or ((not oAscending) and (Self[B] > item)))) do
    B := (B * 2);
  R.Create((B div 2), Min(B, (L - 1)));
  while (R.start <= R.stop) do
  begin
    Result := R.Pivot;
    if (Self[Result] = item) then
      Exit;
    if ((oAscending and (Self[Result] < item)) or ((not oAscending) and (Self[Result] > item))) then
      R.start := (Result + 1)
    else
      R.stop := (Result - 1);
  end;
  Result := -1;
end;

class function TBinarySearch.Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  Result := -1;
  L := 0;
  R := High(arr);
  while (L <= R) do
  begin
    M := (L + ((R - L) shr 1));
    if (arr[M] = item) then
      Exit(M);
    if ((ascending and (arr[M] < item)) or ((not ascending) and (arr[M] > item))) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
end;
{$ENDIF}

{==============================================================================]
  <Create>
  @action: Creates array with item where size is length of the array.
  @note: item is placed on every index in result.
[==============================================================================}
class function T1D.Create(const item: MType; const aSize: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, aSize));
  for i := 0 to High(Result) do
    Result[i] := item;
end;
{$ENDIF}