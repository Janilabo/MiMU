{$I Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
function Add(const item: TVar; const duplicates: Boolean = True): TArr; overload;
function Add(const items: TArr; const duplicates: Boolean = True): TArr; overload;
function AllEqual: Boolean; overload;
function AllSame: Boolean; overload;
function AllUnique: Boolean; overload;
function Any(const null: TVar): TVar; overload;
function Any: TVar; overload;
function Append(const item: TVar; const duplicates: Boolean = True): TArr; overload;
function Append(const items: TArr; const duplicates: Boolean = True): TArr; overload;
function As2D(const rows, columns: Integer): T2DArr; overload;
function As2D(const width: Integer): T2DArr; overload;
function Backwards: TArr; overload;
function Blend(const items: TArr; const index: Integer = 2147483647): TArr; overload;
function Build(const item: TVar; const aSize: Integer = 1): TArr; overload;
function BuiltWith(const blocks: TArr): Boolean; overload;
function MadeOf(const allowed: TArr): Boolean; overload;
function FreeOf(const forbidden: TArr): Boolean; overload;
function BuiltWithout(const forbidden: TArr): Boolean; overload;
function Blit(const items: TArr; const index: Integer = 0): Integer; overload;
function Classes: T2DArr; overload;
function Classes(const weight: TIntegerArray): T2DArr; overload;
function Classes(const weight: TDoubleArray): T2DArr; overload;
function Classify: T2DArr; overload;
function Classify(const weight: TIntegerArray): T2DArr; overload;
function Classify(const weight: TDoubleArray): T2DArr; overload;
function Clear: Boolean; overload;
function Clone(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
function Clone(const ID: TIntegerArray): TArr; overload;
function Cloned: TArr; overload;
function Collated: T2DArr; overload;
function Combine(const b: TArr): TArr; overload;
function Components(const connections: TConnectionArray): T2DArr; overload;
function Compact: Integer; overload;
function Compacted: TArr; overload;
function Compacted(const threshold: Integer): TArr; overload;
function Compress: Integer; overload;
function Compressed: TArr; overload;
function Compressed(const threshold: Integer): TArr; overload;
function Comprised(const items: TArr): Boolean; overload;
function Constant(const item: TVar): Boolean; overload;
function Constant: Boolean; overload;
function Contains(const item: TVar; const index: Integer = 0): Boolean; overload;
function Copied: TArr; overload;
function Copy(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
function Create(const item: TVar): TArr; overload;
function Create(const aSize: Integer; const item: TVar): TArr; overload;
function Deduplicated: TArr; overload;
function Delete(const index: Integer = 0): TArr; overload;
function Delete(const ID: TIntegerArray): TArr; overload;
function Differ(const target: TArr): Boolean; overload;
function Disordered: TArr; overload;
function Distinct: Integer; overload;
function Distincted: T2DArr; overload;
function Distribute(const parts: Integer): T2DArr; overload;
function Diversified: TArr; overload;
function DiversifiedEx(const dAscending: Boolean = True): TArr; overload;
function Domain: TRange; overload;
function Drop(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload;
function Dump(const items: TArr; const index: Integer = 0): TArr; overload;
function Dupe: TArr; overload;
function Duplicate(const xTimes: Integer = 1): TArr; overload;
function Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): TArr; overload;
function Emplace(const item: TVar; const index: Integer = 0): Integer; overload;
function Empty: Boolean; overload;
function Equal(const target: TArr): Boolean; overload;
function Erase(const item: TVar; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload;
function Erase(const item: TVar; const all: Boolean): TArr; overload;
function Erase(const items: TArr; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload;
function Erase(const items: TArr; const all: Boolean): TArr; overload;
function Exact(const items: TArr): Boolean; overload;
function Excessive: Boolean; overload; 
function Exch(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(const aIndex, bIndex: Integer): Boolean; overload;
function Exchange(var b: TArr): Integer; overload;
function Exchange(const swaps: TConnectionArray): TArr; overload;
function Exchanges(const target: TArr): TConnectionArray; overload;
function Exclude(const items: TArr; const index: Integer = 2147483647): TArr; overload;
function Exists: Boolean; overload;
function Devein(const dIDs: TIntegerArray; const dValue: TVar): TArr; overload;
function Devein(const dIDs: TIntegerArray): TArr; overload;
function Expel(const eIDs: TIntegerArray): TArr; overload;
function Extend(const item: TVar): TArr; overload;
function Extend(const items: TArr): TArr; overload;
function Extract(const item: TVar; const index: Integer = 0): TArr; overload;
function Extract(const items: TArr; const index: Integer = 0): TArr; overload;
function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload;
function ExtractIDs(const allowed: TIntegerArray): TArr; overload;
function ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): TArr; overload;
function Feed(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload;
function Fill(const item: TVar; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
function Fill(const items: TArr; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
function Filter(const item: TVar; const index: Integer = 0): TArr; overload;
function Filter(const items: TArr; const index: Integer = 0): TArr; overload;
function FilterEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload;
function FilterIDs(const forbidden: TIntegerArray): TArr; overload;
function FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): TArr; overload;
function Find(const ID: TRange; const item: TVar): Integer; overload;
function Find(const ID: TIntegerArray; const item: TVar): Integer; overload;
function Find(const ID: TRange; const items: TArr): Integer; overload;
function Find(const ID: TIntegerArray; const items: TArr): Integer; overload;
function First: Integer; overload;
function First(const item: TVar): Integer; overload;
function First(const items: TArr): Integer; overload;
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Fits(const maxValue: Integer): Boolean; overload;
function Fits(const target: TRange): Boolean; overload;
function Flip: Boolean; overload;
function Free: Integer; overload;
function FromLeft(const count: Integer; const index: Integer = 2147483647): TArr; overload;
function FromRight(const count: Integer; const index: Integer = 0): TArr; overload;
function Get: TArr; overload;
function Get(const ID: TIntegerArray): TArr; overload;
function Get(const ID: TRange): TArr; overload;
function Group: T2DArr; overload;
function Group(const weight: TIntegerArray; const wSorted: Boolean = False): T2DArr; overload;
function Group(const weight: TDoubleArray; const wSorted: Boolean = False): T2DArr; overload;
function Grouped(const groups: TIntegerArray): T2DArr; overload;
function Groupify(const groups: TIntegerArray): T2DArr; overload;
function Grouping(const groups: TIntegerArray): T2DArr; overload;
function Grow(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload;
function Holds(const chain: TArr): Boolean; overload;
function Homogeneous(const item: TVar): Boolean; overload;
function Homogeneous: Boolean; overload;
function ID(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const ID: TIntegerArray): TArr; overload;
function IDs(const ID: TIntegerArray; const item: TVar): TArr; overload;
function IDs(const ID: TIntegerArray; const items: TArr): TArr; overload;
function Includes(const item: TVar; const index: Integer = 2147483647): Boolean; overload;
function Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
function Indices(const aAscending: Boolean = True): TIntegerArray; overload;
function Inject(const items: TArr; const index: Integer = 2147483647): Integer; overload;
function Keep(const items: TArr; const index: Integer = 0): TArr; overload;
function Kill: Integer; overload;
function Last: Integer; overload;
function Last(const item: TVar): Integer; overload;
function Last(const items: TArr): Integer; overload;
function LeastCommon: TVar; overload;
function LeastFrequent: TVar; overload;
function Len: Integer; overload;
function Loc(const item: TVar; const index: Integer = 2147483647): Integer; overload;
function Loc(const items: TArr; const index: Integer = 2147483647): Integer; overload;
function Location(const item: TVar; const index: Integer = 2147483647): Integer; overload;
function Location(const items: TArr; const index: Integer = 2147483647): Integer; overload;
function Locations(const item: TVar; const index: Integer = 2147483647): TIntegerArray; overload;
function Locations(const items: TArr; const index: Integer = 2147483647): TIntegerArray; overload;
function Locations: TIntegerArray; overload;
function Mix(const mixings: Integer = 1): Boolean; overload;
function Mixed(const mixings: Integer = 1): TArr; overload;
function MostCommon: TVar; overload;
function MostFrequent: TVar; overload;
function Movement(const moves: TConnectionArray): TArr; overload;
function Movements(const target: TArr): TConnectionArray; overload;
function Multi(const threshold: Integer = 2): Boolean; overload;
function Multi(const threshold: TRange): Boolean; overload;
function Next(const index: Integer; const count: Integer = 2147483647): TArr; overload;
function Occurs(const item: TVar; const occurrence: Integer = 1): Boolean; overload;
function Overlay(const items: TArr; const index: Integer; const init: TVar): TArr; overload;
function Overlay(const items: TArr; const index: Integer = 0): TArr; overload;
function Oversize(const limit: Integer): Boolean; overload;
function Partition(const pSize: Integer): T2DArr; overload;
function Patch(const index: Integer; const items: TArr): Integer; overload;
function Plain: Boolean; overload;
function Pick(const items: TArr; const index: Integer = 0): TArr; overload;
function Pop: TVar; overload;
function Pop(const null: TVar): TVar; overload;
function Populate(const items: TArr; const times: Integer = 1): Boolean; overload;
function Populate(const item: TVar; const times: Integer = 1): Boolean; overload;
function Populated(const population: TRange): Boolean; overload;
function Populated(const populationMin: Integer = 1; const populationMax: Integer = 2147483647): Boolean; overload;
function Pos(const item: TVar; const index: Integer = 0): Integer; overload;
function Pos(const items: TArr; const index: Integer = 0): Integer; overload;
function Position(const item: TVar; const index: Integer = 0): Integer; overload;
function Position(const items: TArr; const index: Integer = 0): Integer; overload;
function Positions(const item: TVar; const index: Integer = 0): TIntegerArray; overload;
function Positions(const items: TArr; const index: Integer = 0): TIntegerArray; overload;
function Positions: TIntegerArray; overload;
function Prepend(const items: TArr; const index: Integer = 0): Integer; overload;
function Presence(const item: TVar; const occurrence: Integer = 1): Boolean; overload;
function Previous(const index: Integer; const count: Integer = 2147483647): TArr; overload;
function Prune: Integer; overload;
function Pruned: TArr; overload;
function Pruned(const threshold: Integer): TArr; overload;
function Pull: TArr; overload;
function Purified(const dAscending: Boolean = True): TArr; overload;
function Purify(const dAscending: Boolean = True): Integer; overload;
function Push(const item: TVar): TArr; overload;
function Push(const items: TArr): TArr; overload;
function Put(const ID: TIntegerArray; const item: TVar): TArr; overload;
function Put(const ID: TIntegerArray; const items: TArr): TArr; overload;
function Put(const index: Integer; const items: TArr): TArr; overload;
function Randomized: TArr; overload;
function Range(const subArray: TArr; const index: Integer = 0): TRange; overload;
function Ranges(const subArray: TArr; const index: Integer = 0): TRangeArray; overload;
function Recreate(const arrSize: Integer): Boolean; overload;
function Reject(const items: TArr; const index: Integer = 2147483647): TArr; overload;
function Remove(const item: TVar; const index: Integer = 0; const all: Boolean = True): TArr; overload;
function Remove(const item: TVar; const all: Boolean): TArr; overload;
function Remove(const items: TArr; const index: Integer = 0; const all: Boolean = True): TArr; overload;
function Remove(const items: TArr; const all: Boolean): TArr; overload;
function Reposition(const oldIndex, newIndex: Integer): Boolean; overload;
function Reset: Integer; overload;
function Resize(const aChange: Integer): Integer; overload;
function Resize(const aChange: Integer; const null: TVar): Integer; overload;
function Reversal: TArr; overload;
function Reverse: Boolean; overload;
function Reversed: TArr; overload;
function Reversify: Boolean; overload;
function Reversion: TArr; overload;
function Runs: T2DArr; overload;
function Sample(const sSize: Integer): TArr; overload;
function Scan(const ID: TRange; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TIntegerArray; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TRange; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TIntegerArray; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scramble(const swaps: Integer = -1): TArr; overload;
function Shake(const shakes: Integer = 1): TArr; overload;
function Shift: TVar; overload;
function Shift(const sCount: Integer): TArr; overload;
function Shuffle(const shuffles: Integer = 1): TArr; overload;
function Singlify(const item: TVar): Integer; overload;
function Singlified(const item: TVar): TArr; overload;
function Singular: Boolean; overload;
function Singularize(const item: TVar): Integer; overload;
function Singularized(const item: TVar): TArr; overload;
function Soloize(const item: TVar): Integer; overload;
function Soloized(const item: TVar): TArr; overload;
function Size: Integer; overload;
function Size(const aSize: Integer): TArr; overload;
function Size(const aSize: Integer; const null: TVar): TArr; overload;
function SizeBetween(const sMin, sMax: Integer): Boolean; overload;
function SizeMax(const target: Integer): Boolean; overload;
function SizeMin(const target: Integer): Boolean; overload;
function Slice(const r: TRange): TArr; overload;
function Slice(const r: TRangeArray): TArr; overload;
function Slots: TIntegerArray; overload;
function Some: TArr; overload;
function Some(const amount: Integer): TArr; overload;
function Span: TRange; overload;
function Span(const subArray: TArr; const index: Integer = 2147483647): TRange; overload;
function Spans(const subArray: TArr; const index: Integer = 2147483647): TRangeArray; overload;
function Strip(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload;
function SubarrayLocation(const pattern: TArr): Integer; overload;
function SubarrayLocations(const pattern: TArr): TIntegerArray; overload;
function SubarrayPosition(const pattern: TArr): Integer; overload;
function SubarrayPositions(const pattern: TArr): TIntegerArray; overload;
function Subset(const items: TArr): Boolean; overload;
function Supply(const item: TVar): Integer; overload;
function Supply(const items: TArr): Integer; overload;
function Swapped(var target: TArr): Integer; overload;
function SwapMerged(var target: TArr): TArr; overload;
function SwappedMerge(var target: TArr): TArr; overload;
function To2D(const rows, columns: Integer): T2DArr; overload;
function To2D(const height: Integer): T2DArr; overload;
function ToIndexes: TIntegerArray; overload;
function Trade(var b: TArr): Integer; overload;
function Undersize(const limit: Integer): Boolean; overload;
function Uncluttered: TArr; overload;
function Uniform: Boolean; overload;
function Uniform(const item: TVar): Boolean; overload;
function Uniformity: Double; overload;
function Unified(const dAscending: Boolean = True): TArr; overload;
function Unify(const dAscending: Boolean = True): Integer; overload;
function Unduplicated: TArr; overload;
function Uniqued: TArr; overload;
function Uniques: TIntegerArray; overload;
function Unshift(const item: TVar): TArr; overload;
function Unshift(const items: TArr): TArr; overload;
function Void: Boolean; overload;
function Waste: Integer; overload;
function Zigzag(const zAscending: Boolean = True): TArr; overload;
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
function Descend: TArr; overload;
function Ascend: TArr; overload;
function Descending: Boolean; overload;
function Ascending: Boolean; overload;
function Decreasing: Boolean; overload;
function Increasing: Boolean; overload;
function Downward: Boolean; overload;
function Upward: Boolean; overload;
function Lowest: TVar; overload;
function Highest: TVar; overload;
function Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function Mode: TVar; overload;
function Center: TVar; overload;
function MergeSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
function MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
function QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
function QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSorted(const aAscending: Boolean = True): TArr; overload;
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
function Uniq(const sSorted: Boolean = False): TArr; overload;
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
{$ENDIF}
function MergeSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function MergeSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
function QuickSorted(const weight: TIntegerArray; const aAscending: Boolean = True): TArr; overload;
function QuickSorted(const weight: TDoubleArray; const aAscending: Boolean = True): TArr; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <arr.Add(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the array with added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
function HArr.Add(const item: TVar; const duplicates: Boolean = True): TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  if ((not duplicates) and Self.Contains(item)) then
    SetLength(Result, l)
  else
    Result[l] := item;
end;

{==============================================================================]
 <arr.Add(items: TArray; duplicates: Boolean): TArray>
 @action: Appends arr with items. Returns the array with added items.
 @note: Adds item to the right side of the array.
[==============================================================================}
function HArr.Add(const items: TArr; const duplicates: Boolean = True): TArr; overload;
var
  a, h, i, s: Integer;
begin
  s := Length(Self);
  i := Length(items);
  SetLength(Result, (s + i));
  if ((i = 0) and (s = 0)) then
    Exit;
  h := High(items);
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  case duplicates of
    False:
    begin
      a := 0;
      for i := 0 to h do
        if not Result.Contains(items[i]) then
          Result[s + a.Increase] := items[i];
      SetLength(Result, (s + a));
    end;
    True:
    for i := 0 to h do
      Result[i] := items[i];
  end;
end;

{==============================================================================]
 <arr.AllEqual: Boolean>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function HArr.AllEqual: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.AllSame: Boolean>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function HArr.AllSame: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.AllUnique: Boolean>
 @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
 @note: None
[==============================================================================}
function HArr.AllUnique: Boolean; overload;
var
  h, a, b: Integer;
begin
  h := High(Self);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (Self[a] = Self[b]) then
        Exit(False);
  Result := (h > -1);
end;

{==============================================================================]
  <arr.Any>
  @action: Returns random array item from Self.
  @note: Returns null with empty arrays.
[==============================================================================}
function HArr.Any(const null: TVar): TVar; overload;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[Random(Self.Size)];
end;

{==============================================================================]
  <arr.Any>
  @action: Returns random array item from Self.
  @note: Make sure array has at least 1 item! This one is unsafe and returns error else.
[==============================================================================}
function HArr.Any: TVar; overload;
begin
  Result := Self[Low(Self) + Random(Self.Size)];
end;

{==============================================================================]
 <arr.Append(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
function HArr.Append(const item: TVar; const duplicates: Boolean = True): TArr; overload;
begin
  Result := Self.Copy;
  if ((not duplicates) and Self.Contains(item)) then
    Exit;
  SetLength(Result, (Length(Self) + 1));
  Result[Length(Self)] := item;
end;

{==============================================================================]
 <arr.Append(items: TArray; duplicates; Boolean): TArray>
 @action: Adds all items items to arr.
 @note: Returns the highest index in the end.
[==============================================================================}
function HArr.Append(const items: TArr; const duplicates: Boolean = True): TArr; overload;
var
  a, h, i: Integer;
begin
  Result := Self.Copy;
  if Items.Empty then
    Exit;
  h := High(items);
  a := High(Self);
  SetLength(Result, ((a + h) + 2));
  case duplicates of
    False:
    begin
      for i := 0 to h do
        if not Self.Contains(items[i]) then
          Result[a.Increment] := items[i];
      SetLength(Result, (a + 1));
    end;
    True:
    for i := 0 to h do
      Result[a.Increment] := items[i];
  end;
end;

{==============================================================================]
 <arr.As2D(rows, columns: Integer): T2DArray>
 @action: Converts 1D array to 2D by rows and columns.
 @note: TIA := [1,2,3,4,5,6];
		TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
        TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function HArr.As2D(const rows, columns: Integer): T2DArr; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, rows, columns);
  for i := 0 to ((rows * columns) - 1) do
    if (i < l) then
      Result[i div columns][i mod columns] := Self[i];
end;

{==============================================================================]
 <arr.As2D(width: Integer): T2DArray>
 @action: Converts 1D array to 2D by width.
 @note: None.
[==============================================================================}
function HArr.As2D(const width: Integer): T2DArr; overload;
var
  l, h, i, r, c: Integer;
begin
  l := Length(Self);
  h := Ceil(l / width);
  SetLength(Result, h, width);
  i := 0;
  for r := 0 to (h - 1) do
    for c := 0 to (width - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.Backwards: TArray>
 @action: Returns arr as reversed.
 @note: Alternative for Reversed methods
[==============================================================================}
function HArr.Backwards: TArr; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  i := 0;
  while (l > 0) do
    Result[i.Increase] := Self[l.Decrement];
end;

{==============================================================================]
 <arr.Blit(items: TArray; index: Integer: Integer>
 @action: Simply puts items to array index, fast.
 @note: No safety checks. Make sure buffer is enough!
[==============================================================================}
function HArr.Blit(const items: TArr; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := (index + Length(items));
  for i := 0 to High(items) do
    Self[index + i] := items[i]; 
end;

{==============================================================================]
 <arr.Build(item: VarType; aSize: Integer): TArray> 
 @action: Creates array with item where aSize is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
function HArr.Build(const item: TVar; const aSize: Integer = 1): TArr; overload;
begin
  Result := Self.Create(aSize, item);
end;

{==============================================================================]
 <arr.MadeOf(allowed: TArray): Boolean> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}
function HArr.MadeOf(const allowed: TArr): Boolean; overload;
var
  a, s: TRange;
  i: Integer;
begin
  if (Self.Empty or allowed.Empty) then
    Exit(False);
  s.Create(0, High(Self));
  a.Create(0, High(allowed));
  repeat
    i := a.start;
    repeat
      Result := (Self[s.stop] = allowed[i]);
    until (Result or (i.Increment > a.stop));
  until ((not Result) or (s.stop.Decrement < s.start));
end;

{==============================================================================]
 <arr.FreeOf(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
function HArr.FreeOf(const forbidden: TArr): Boolean; overload;
var
  s, f: TRange;
  i: Integer;
begin
  if (Self.Empty or forbidden.Empty) then
    Exit(True);
  s.Create(0, High(Self));
  f.Create(0, High(forbidden));	
  repeat
    i := f.start;
    repeat
      Result := not (Self[s.stop] = forbidden[i]);
    until ((i.Increment > f.stop) or (not Result));
  until ((not Result) or (s.stop.Decrement < s.start));
end;

{==============================================================================]
 <arr.Blend(items: TArray; index: Integer): TArray> 
 @action: Blends items with array, cleverly.
 @note: None.
[==============================================================================}
function Harr.Blend(const items: TArr; const index: Integer = 2147483647): TArr; overload;
var
  s, l, p, r, i: Integer;
begin
  s := Length(Self);
  if (s = 0) then
    Exit(items.Copy);
  l := Length(items);
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
 <arr.BuiltWithout(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
function HArr.BuiltWithout(const forbidden: TArr): Boolean; overload;
var
  i, j: Integer;
begin
  if not (Self.Empty or forbidden.Empty) then
  for i := 0 to High(Self) do
    for j := 0 to High(forbidden) do
      if (Self[i] = forbidden[j]) then
        Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.BuiltWith(blocks TArray): Boolean>
  @action: Returns true is arr is built with blocks.
  @note: This function requires blocks array to be unique (no duplicates allowed for it).
[==============================================================================}
function HArr.BuiltWith(const blocks: TArr): Boolean; overload;
var
  i, p: Integer;
  u: TBooleanArray;
begin
  if (Self.Empty or blocks.Empty) then
    Exit(False);
  SetLength(u, Length(blocks));
  for i := 0 to High(Self) do
  begin
    p := blocks.Pos(Self[i]);
    if (p = -1) then
      Exit(False);
    u[p] := True;
  end;
  for i := 0 to High(blocks) do
    if not u[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TArray.Classes: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function HArr.Classes: T2DArr; overload;
var
  i, g: Integer;
  v: TVar;
begin
  if Self.Empty then
    Exit([]);
  g := 0;
  v := Self[0];
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to High(Self) do
  begin
    if not (Self[i] = v) then
    begin
      v := Self[i];
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], 0);
    end;
    SetLength(Result[g], (Length(Result[g]) + 1));
    Result[g][High(Result[g])] := Self[i];
  end;
end;

{==============================================================================]
  <TArray.Classes: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function HArr.Classes(const weight: TIntegerArray): T2DArr; overload; var w: Integer; {$DEFINE Skeleton_Classes}{$I Skeletons.inc}{$UNDEF Skeleton_Classes}
function HArr.Classes(const weight: TDoubleArray): T2DArr; overload; var w: Double; {$DEFINE Skeleton_Classes}{$I Skeletons.inc}{$UNDEF Skeleton_Classes}

{==============================================================================]
  <TArray.Classify: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function HArr.Classify: T2DArr; overload;
var
  i, h, g, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  SetLength(Result[0], l);
  Result[0][0] := Self[0];
  g := 0;
  h := 0;
  for i := 1 to High(Self) do
  case (Self[i] = Result[g][0]) of
    False:
    begin
      SetLength(Result[g], (h + 1));
      Result[g][h] := Result[g][0];
      h := 0;
      SetLength(Result[g.Increment], (l - i));
      Result[g][0] := Self[i];
    end;
	True: Result[g][h.Increase] := Self[i];
  end;
  SetLength(Result[g], (h + 1));
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <TArray.Classify: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function HArr.Classify(const weight: TIntegerArray): T2DArr; overload; var w: Integer; {$DEFINE Skeleton_Classify}{$I Skeletons.inc}{$UNDEF Skeleton_Classify}
function HArr.Classify(const weight: TDoubleArray): T2DArr; overload; var w: Double; {$DEFINE Skeleton_Classify}{$I Skeletons.inc}{$UNDEF Skeleton_Classify}

{==============================================================================]
  <arr.Clear: Boolean>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function HArr.Clear: Boolean; overload;
begin
  Result := (Length(Self) > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Clone(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function HArr.Clone(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
var
  i, s, c: Integer;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(Self) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[i - s] := Self[i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Clone(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (ID).
 @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[==============================================================================}
function HArr.Clone(const ID: TIntegerArray): TArr; overload;
var
  i, h, l, r: Integer;
begin
  r := 0;
  if (ID.Populated and Self.Populated) then
  begin
    h := High(Self);
    l := Length(ID);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((ID[i] <= h) and (ID[i] > -1)) then
        Result[r.Increase] := Self[ID[i]];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Cloned: TArray>
 @action: Simply returns a clone of array.
 @note: None.
[==============================================================================}
function HArr.Cloned: TArr; overload;
var
  n: Integer;
  r: TRange;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Length(Self));
  r.Create(-1, Length(Result));
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.start];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.stop];
  end;
end;

function HArr.Collated: T2DArr; overload;
var
  m: specialize TDictionary<TVar, Integer>;
  i, p: Integer;
begin
  m := specialize TDictionary<TVar, Integer>.Create;
  try
    SetLength(Result, 0);
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i], p) then
      begin
        p := Length(Result);
        m.Add(Self[i], p);
        SetLength(Result, (p + 1));
        SetLength(Result[p], 0);
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;


{==============================================================================]
 <arr.Compact: Integer>
 @action: Removes adjacent duplicates.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Compact: Integer; overload;
var
  i: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Length(Self));
  Result := 1;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Compacted: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Compacted: TArr; overload;
var
  i: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
	  Result.Supply(Self[i]);
end;

{==============================================================================]
 <arr.Compacted: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Compacted(const threshold: Integer): TArr; overload;
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
      if (Length(Result) <= r) then
        SetLength(Result, (r + 1));
      Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Combine(b: TArray): TArray>
 @action: Combines arrays arr and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}
function HArr.Combine(const b: TArr): TArr; overload;
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Length(Self));
end;

{==============================================================================]
 <arr.Components>
  @action: Groups elements of the array into connected components based on provided connections.
           Each connection is treated as undirected. Returns a 2D array where each inner array
           represents one group of connected elements.
  @param: connections - an array of TConnection, each containing two indices (Id1, Id2) 
           in Self that are connected.
  @returns: T2DArr - 2D array of grouped elements from Self.
  @note: Duplicate connections are ignored. Self must contain at least as many elements as
         the maximum index in any connection.
[==============================================================================}
function HArr.Components(const connections: TConnectionArray): T2DArr; overload;
var
  i, l: Integer;
  v: TBooleanArray;
  n: T2DIntegerArray;
  s: TIntegerArray;
  procedure DFS(const startPos: Integer; var group: TArr);
  var
    h, c, k: Integer;
  begin
    SetLength(s, 0);
    s := s + [startPos];
    while (Length(s) > 0) do
    begin
      h := High(s);
      c := s[h];
      SetLength(s, h);
      if v[c] then
        Continue;
      v[c] := True;
      group := (group + [Self[c]]);
      for k := 0 to High(n[c]) do
        if not v[n[c][k]] then
          s := (s + [n[c][k]]);
    end;
  end;
begin
  l := Length(Self);
  if l = 0 then
    Exit([]);
  SetLength(n, l);
  SetLength(v, l);
  for i := 0 to High(connections) do
    if (InRange(connections[i].id1, 0, (l - 1)) and InRange(connections[i].id2, 0, (l - 1))) then
    begin
      n[connections[i].id1] := (n[connections[i].id1] + [connections[i].id2]);
      n[connections[i].id2] := (n[connections[i].id2] + [connections[i].id1]);
    end;
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if not v[i] then
    begin
      SetLength(Result, (Length(Result) + 1));
      SetLength(Result[High(Result)], 0);
      DFS(i, Result[High(Result)]);
    end;
  end;
end;

{==============================================================================]
 <arr.Compressed: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Compressed: TArr; overload;
var
  r, i, l: Integer;
begin
  l := Length(Self);
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
 <arr.Compressed: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Compressed(const threshold: Integer): TArr; overload;
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
 <arr.Compress: Integer>
 @action: Removes all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Compress: Integer; overload;
var
  i: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Length(Self));
  Result := 1;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Comprised(items: TArray): Boolean>
 @action: Returns true if arr is built of items only.
 @note: 
[==============================================================================}
function HArr.Comprised(const items: TArr): Boolean; overload;
var
  l: Integer;
begin
  l := Length(Self);
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := items.Contains(Self[l]);
end;

{==============================================================================]
 <arr.Constant(item: VarType): Boolean>
 @action: Returns true if arr consists of item ONLY.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Constant(const item: TVar): Boolean; overload;
var
  l: Integer;
begin
  l := Length(Self);
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := (Self[l] = item);
end;

{==============================================================================]
 <arr.Constant: Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Constant: Boolean; overload;
begin
  Result := ((Length(Self) > 0) and Constant(Self[0]));
end;

{==============================================================================]
 <arr.Contains(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}
function HArr.Contains(const item: TVar; const index: Integer = 0): Boolean; overload;
var
  i: Integer;
begin
  for i := index to High(Self) do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Copy(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function HArr.Copy(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
var
  i, c, l: Integer;
begin
  l := Length(Self);
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
 <arr.Copied: TArray>
 @action: Simply returns a copy of array.
 @note: None.
[==============================================================================}
function HArr.Copied: TArr; overload;
var
  h, i, l: Integer;
begin
  l := Length(Self);
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
 <arr.Create(item: VarType): TArray> 
 @action: Creates array with item, size as 1. Returns old Self.
 @note: [item]
[==============================================================================}
function HArr.Create(const item: TVar): TArr; overload;
begin
  Result := Self.Clone;
  SetLength(Self, 1);
  Self[0] := item;
end;

{==============================================================================]
 <arr.Create(aSize: Integer; item: VarType): TArray> 
 @action: Creates array with item where aSize is length of the array. Returns old Self.
 @note: item is placed on every index in result.
[==============================================================================}
function HArr.Create(const aSize: Integer; const item: TVar): TArr; overload;
var
  i: Integer;
begin
  Result := Self.Clone;
  SetLength(Self, Max(0, aSize));
  for i := 0 to High(Self) do
    Self[i] := item;
end;

{==============================================================================]
 <arr.Deduplicated: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Deduplicated: TArr; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit();
  l := 0;
  for i := 0 to High(Self) do
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
 <arr.Delete(index: Integer): TArray>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}
function HArr.Delete(const index: Integer = 0): TArr; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  if not ((index <= h) and (index > -1)) then
    Exit(Self.Copy);
  SetLength(Result, h);
  for i := 0 to (index - 1) do
    Result[i] := Self[i];
  for i := index to (h - 1) do
    Result[i] := Self[i + 1];
end;

{==============================================================================]
 <arr.Delete(ID: TIntegerArray): Integer>
 @action: Deletes array items from arr by indexes (ID).
 @note: Returns amount of items that were deleted succesfully by ID's.
[==============================================================================}
function HArr.Delete(const ID: TIntegerArray): TArr; overload;
var
  i, l, r: Integer;
begin
  if ID.Empty then
    Exit(Self.Copy);
  l := Length(Self);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
    if not ID.Contains(i) then
      Result[i - r] := Self[i]
    else
      r := (r + 1);
  SetLength(Result, (l - r));
end;

{==============================================================================]
 <arr.Devein>
 @action: Creates a copy of the current array with elements at the specified indices removed.
          Elements at the positions listed in dIDs are excluded, and the resulting array is compacted.
 @note:   The optional dValue parameter is used as a sentinel to mark elements for removal.
          The original array (Self) is not modified.
          If dIDs contains indices out of range, they are ignored. Empty arrays for Self or dIDs result in an unchanged copy.
[==============================================================================}
function HArr.Devein(const dIDs: TIntegerArray; const dValue: TVar): TArr; overload;
var
  i, l: Integer;
  s: TRange;
begin
  Result := Self.Copy;
  if Self.Empty then
    Exit;
  if dIDs.Empty then
    Exit;
  s.Create(0, High(Self));
  for i := 0 to High(dIDs) do
    if s.Contains(dIDs[i]) then
      Result[dIDs[i]] := dValue;
  l := 0;
  for i := 0 to High(Result) do
    if (Result[i] <> dValue) then
      Result[l.Increase] := Result[i];
  SetLength(Result, l);
end;

function HArr.Devein(const dIDs: TIntegerArray): TArr; overload;
begin
  Result := Self.Devein(dIDs, Default(TVar));
end;

{==============================================================================]
 <arr.Differ(target: TArray): Boolean>
 @action: Returns true if arr differs from target.
 @note: None
[==============================================================================}
function HArr.Differ(const target: TArr): Boolean; overload;
var
  i: Integer;
begin
  Result := (Length(Self) <> Length(target));
  if not Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
end;

{==============================================================================]
 <arr.Distinct>
 @action: Returns the number of unique elements in array 
 @note: None.
 [==============================================================================}
function HArr.Distinct: Integer; overload;
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
 <arr.Distincted>
  @action: Groups the integer array into subarrays by unique values. Each subarray
           in the result contains all occurrences of one distinct integer from Self,
           preserving the order of first appearance.
  @note: The function preserves the original order of first occurrence for each unique
         value. It uses an auxiliary array 'm' to track which values have already
         been grouped. Duplicate values in Self are added to the same group.
         The resulting 2D array has one group per unique value.
[==============================================================================}
function HArr.Distincted: T2DArr; overload;
var
  m: TArr;
  i, l: Integer;
begin
  SetLength(m, 0);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    l := m.Pos(Self[i]);
    if (l = -1) then
    begin
      l := Length(m);
      SetLength(m, (l + 1));
      SetLength(Result, (l + 1));
      m[l] := Self[i];
    end;
    Result[l].Supply(Self[i]);
  end;
end;

{==============================================================================]
 <arr.Disordered>
 @action: Returns array with randomized order (disorder)
 @note: [1,2,3] => [1,3,2] | [2,1,3] | [2,3,1] | [3,2,1] ...
 [==============================================================================}
function HArr.Disordered: TArr; overload;
var
  m: TBooleanArray;
  i, r, l: Integer;
begin
  l := Length(Self);
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
 <arr.Distribute(parts: Integer): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
function HArr.Distribute(const parts: Integer): T2DArr; overload;
var
  l, p, b, r, i, j, s, c: Integer;
begin
  l := Length(Self);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
        Result[i][j] := Self[s.Increase];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Diversified: TArray>
 @action: Alternative for Unique methods
 @note: None.
 [==============================================================================}
function HArr.Diversified: TArr; overload;
var
  d: specialize TDictionary<TVar, Boolean>;
  i: Integer;
  k: TVar;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
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
 <arr.DiversifiedEx: TArray>
 @action: Alternative for Unique methods
 @note: None.
 [==============================================================================}
function HArr.DiversifiedEx(const dAscending: Boolean = True): TArr; overload;
var
  l: specialize TList<TVar>;
  d: specialize TDictionary<TVar, Boolean>;
  i: Integer;
begin
  l := specialize TList<TVar>.Create;
  d := specialize TDictionary<TVar, Boolean>.Create;
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
 <arr.Domain: TRange>
  @action: Returns the valid index range of the array.
  @note: 
    - If the array is empty, start and stop are set to -1.
    - Otherwise, start = 0 and stop = Length(Self) - 1.
[==============================================================================}
function HArr.Domain: TRange; overload;
begin
  Result.stop := (Length(Self) - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
 <arr.Drop(item: VarType; eraseDuplicates: Boolean): TArray>
 @action: Removes item(s) from arr and returns it.
 @note: 	
[==============================================================================}
function HArr.Drop(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Positions(item)
  else
    p := [Self.Pos(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
 <TArray_Dump(items: TArray; index: Integer): TArray>
 @action: Deletes items from array, keeps others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
function HArr.Dump(const items: TArr; const index: Integer = 0): TArr; overload;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
  SetLength(Result, l);
  d := 0;
  m := Max(0, index);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
 <arr.Dupe: TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function HArr.Dupe: TArr; overload;
var
  i, l, j: Integer;
begin
  l := Length(Self);
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
 <arr.Duplicate(xTimes: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function HArr.Duplicate(const xTimes: Integer = 1): TArr; overload;
var
  m, i, j, l: Integer;
begin
  l := Length(Self);
  m := Max(0, xTimes);
  SetLength(Result, (m * l));
  if (l > 0) then
  for i := 0 to (m - 1) do
    for j := 0 to (l - 1) do
      Result[(i * l) + j] := Self[j];
end;

{==============================================================================]
 <arr.Elements(returnIDs: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function HArr.Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): TArr; overload;
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
  SetLength(Result, Length(Self));
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
 <arr.Emplace(item: VarType; index: Integer): Integer>
 @action: Inserts item to index in arr. Returns the index it was inserted to.
 @note: Alternative for Insert().
[==============================================================================}
function HArr.Emplace(const item: TVar; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  SetLength(Self, (Length(Self) + 1));
  Result := index.Clamp(0, High(Self));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
function HArr.Empty: Boolean; overload;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Equal(target: TArray): Boolean>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}
function HArr.Equal(const target: TArr): Boolean; overload;
var
  i: Integer;
begin
  Result := (Length(Self) = Length(target));
  if Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(False);
end;

{==============================================================================]
 <arr.Erase(item: VarType; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Erase(const item: TVar; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload;
var
  j, i, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  if not (Self.Empty or (index < 0)) then
  begin
    l := Length(Self);
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      if (Self[i] = item) then
      begin
        r[i] := True;
        Inc(d);
        f := True;
      end;
      if (f and (not all)) then
        Break;
    end;
    j := 0;
	SetLength(Result, (l - d));
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
 <arr.Erase(item: VarType; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Erase(const item: TVar; const all: Boolean): TArr; overload;
begin
  Result := Self.Erase(item, 2147483647, all);
end;

{==============================================================================]
 <arr.Erase(items: TArray; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Erase(const items: TArr; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload;
var
  h, i, j, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin 
  if (Self.Populated and items.Populated and (index >= 0)) then
  begin
    h := High(items);
    l := Length(Self);
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      for j := 0 to h do
        if (Self[i] = items[j]) then
        begin
          r[i] := True;
          Inc(d);
          f := True;
          Break;
        end;
      if (f and (not all)) then
        Break;
    end;
	j := 0;
	SetLength(Result, (l - d)); 
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
 <arr.Erase(items: TArray; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Erase(const items: TArr; const all: Boolean): TArr; overload;
begin
  Result := Self.Erase(items, 2147483647, all);
end;

{==============================================================================]
 <arr.Exact(items: TArray): Boolean>
 @action: Returns true if arr consists of items.
 @note: arr must contain ALL the items for this function to return True.
        Any extra items will cause Result to be False also.
		items[1,2,3]
		arr[1,2,3,1,2,3] => True
		arr[2,3,2,3] => False
		arr[2,1,3,4] => False
		This function requires items array to be unique. No duplicates allowed for it!
[==============================================================================}
function HArr.Exact(const items: TArr): Boolean; overload;
var
  i, j: Integer;
  f: TBooleanArray;
begin
  if (Length(items) = 0) then
    Exit(Length(Self) = 0);
  SetLength(f, Length(items));
  f.Create(Length(items), False);
  for i := 0 to High(Self) do
  begin
    j := items.Pos(Self[i]);
    if (j = -1) then
      Exit(False);
    f[j] := True;
  end;
  Result := f.Uniform(True);
end;

{==============================================================================]
 <arr.Excessive: Boolean>
 @action: Returns true if arr contains any duplicates in it.
 @note: None.
[==============================================================================}
function HArr.Excessive: Boolean; overload; 
type
  TDict = specialize TDictionary<TVar, Boolean>;
var
  d: TDict;
  i: Integer;
begin
  d := TDict.Create;
  try
    for i := Low(Self) to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True)
      else
        Exit(True);
  finally
    d.Free;
  end;
  Result := False;
end;

{==============================================================================]
 <arr.Exch(aIndex, bIndex: Integer): Boolean>
 @action: Fast version of Exchange().
 @note: Unsafe, no checking.
[==============================================================================}
function HArr.Exch(const aIndex, bIndex: Integer): Boolean; overload;
var
  c: TVar;
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;

{==============================================================================]
 <arr.Exchange(aIndex, bIndex: Integer): Boolean>
 @action: Swap items aIndex and bIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
function HArr.Exchange(const aIndex, bIndex: Integer): Boolean; overload;
var
  c: TVar;
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
 <arr.Exchange(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function HArr.Exchange(var b: TArr): Integer; overload;
var
  a: TArr;
begin
  Result := (Length(Self) + Length(b));
  if (Result = 0) then
    Exit;
  a := Self.Dupe;
  Self := b.Dupe;
  b := a.Dupe;
  SetLength(a, 0);
end;

{==============================================================================]
  <arr.Exchange>
  @action: Applies a sequence of swaps (from <arr.Exchanges>) to the current
           array (Self), producing a new array reflecting all swaps performed.
  @note: - Each swap exchanges two indices (id1,id2).
         - The input swap list must be compatible with the array length.
         - Commonly used to replay sorting animations or verify transformations.
[==============================================================================}
function HArr.Exchange(const swaps: TConnectionArray): TArr; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(swaps) do
    Swap(Result[swaps[i].id1], Result[swaps[i].id2]);
end;

{==============================================================================]
  <arr.Exchanges>
  @action: Generates a sequence of adjacent swaps (id1,id2) required to
           transform the current array (Self) into the target array.
           Each swap exchanges two neighboring elements.
  @note: - Returns an array of TConnection records (id1,id2 swapped).
         - The swaps are replayable with <arr.Exchange>.
         - Ideal for sorting visualizations or swap-based replay systems.
         - All swaps are adjacent, producing stable step-by-step transitions.
[==============================================================================}
function HArr.Exchanges(const target: TArr): TConnectionArray; overload;
var
  i, j: Integer;
  s: TArr;
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
      SetLength(Result, (Length(Result) + 1));
      Result[High(Result)].Create((j - 1), j);
      s[j] := s[j - 1];
      s[j.Decrement] := target[i];
    end;
  end;
end;

{==============================================================================]
 <arr.Exclude(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function HArr.Exclude(const items: TArr; const index: Integer = 2147483647): TArr; overload;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
  m := Min(index, (l - 1));
  SetLength(Result, l);
  d := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  for i := (m + 1) to (l - 1) do
    Result[i - d] := Self[i];
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
 <arr.Exists: Boolean>
 @action: Returns true if array length is not 0.
 @note: Alternative for arr.Populated.
[==============================================================================}
function HArr.Exists: Boolean; overload;
begin
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.Expel>
 @action: Returns a copy of the current array (Self) with elements at the specified indices removed.
          The resulting array is compacted, excluding all elements listed in eIDs.
 @note: If the current array is empty, returns an empty array.
        If eIDs is empty, returns a copy of the original array.
        Indices in eIDs that are out of range are ignored.
        Uses -2147483648 as an internal sentinel to mark elements for removal.
[==============================================================================}
function HArr.Expel(const eIDs: TIntegerArray): TArr; overload;
var
  i, l: Integer;
  s: TRange;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  if eIDs.Empty then
    Exit(Self);
  r := Self.IDs;
  s.Create(Low(Self), High(Self));
  for i := 0 to High(eIDs) do
    if s.Contains(eIDs[i]) then
      r[eIDs[i]] := -2147483648;
  l := 0;
  SetLength(Result, s.Size);
  for i := s.start to s.stop do
    if (r[i] <> -2147483648) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
 <arr.Extend(item: VarType): TArray>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}
function HArr.Extend(const item: TVar): TArr; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[i + 1] := Self[i];
  Result[0] := item;
end;

{==============================================================================]
 <arr.Extend(items: TArray): TArray>
 @action: Extends arr with items. Returns it.
 @note: Places items to the left side of the array.
[==============================================================================}
function HArr.Extend(const items: TArr): TArr; overload;
var
  i, h, l: Integer;
begin
  h := High(Self);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[i + l] := Self[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
 <arr.Extract(item: VarType; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
function HArr.Extract(const item: TVar; const index: Integer = 0): TArr; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] = item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Extract(items: TArray; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are in items. Starts scan from start index.
 @note: Returns the items.
[==============================================================================}
function HArr.Extract(const items: TArr; const index: Integer = 0): TArr; overload;
var
  i, l, r: Integer;
begin
  r := 0;
  if items.Populated then
  begin
    l := Length(Self);
    SetLength(Result, (l - index));
    for i := index to (l - 1) do
      if items.Contains(Self[i]) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.ExtractEvery(X: Integer; index: Integer): TArray>
 @action: Keeps (extracts) all X values from array. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
function HArr.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload;
var
  i, h, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.ExtractIDs(allowed: TIntegerArray): TArray>
 @action: Keeps (extracts) all allowed index values from array.
 @note: None.
[==============================================================================}
function HArr.ExtractIDs(const allowed: TIntegerArray): TArr; overload;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(allowed) do
    if ((allowed[i] > -1) and (allowed[i] < l)) then
      m[allowed[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.ExtractIndexes(allowed: TIntegerArray; aSorted: Boolean): TArray>
 @action: Keeps (extracts) all allowed index values from array.
 @note: If allowed is not in ascending order, aSorted needs to be False.
[==============================================================================}
function HArr.ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): TArr; overload;
var
  h, i, l: Integer;
  a: TIntegerArray;
begin
  l := Length(Self);
  if ((l = 0) or allowed.Empty) then
    Exit([]);
  SetLength(Result, l);
  if not aSorted then
    a := allowed.QuickSorted
  else
    a := allowed.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if a.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Feed(item: VarType; allowDuplicates: Boolean): Integer>
 @action: Feeds item to array and returns the index position it was added to.
 @note: Returns -1 if duplicates are not allowed and array already includes item.
[==============================================================================}
function HArr.Feed(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload;
begin
  if ((not allowDuplicates) and Self.Includes(item)) then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Fill(item: VarType; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with item.
 @note: Returns the filled array.
[==============================================================================}
function HArr.Fill(const item: TVar; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
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
 <arr.Fill(items: TArray; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with items.
 @note: None
[==============================================================================}
function HArr.Fill(const items: TArr; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload;
var
  h, i, s, t, l: Integer;
begin
  h := High(Self);
  l := Length(items);
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
 <arr.Filter(item: VarType; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
function HArr.Filter(const item: TVar; const index: Integer = 0): TArr; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] <> item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Filter(items: TArray; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
function HArr.Filter(const items: TArr; const index: Integer = 0): TArr; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  if items.Empty then
    Exit(Self.Copy(index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.FilterEvery(X: Integer; index: Integer): TArray>
 @action: Filters every/each X item from arr.
 @note: Custom index
[==============================================================================}
function HArr.FilterEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload;
var
  i, h, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.FilterIDs(forbidden: TIntegerArray): TArray>
 @action: Returns the array without values from forbidden indexes.
 @note: None.
[==============================================================================}
function HArr.FilterIDs(const forbidden: TIntegerArray): TArr; overload;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(forbidden) do
    if ((forbidden[i] > -1) and (forbidden[i] < l)) then
      m[forbidden[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if not m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.FilterIndexes(forbidden: TIntegerArray; fSorted: Boolean): TArray>
 @action: Returns the array without values from forbidden indexes.
 @note: If forbidden is not in ascending order, fSorted needs to be False.
[==============================================================================}
function HArr.FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): TArr; overload;
var
  h, i, l: Integer;
  f: TIntegerArray;
begin
  if forbidden.Empty then
    Exit(Self.Copy);
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if not fSorted then
    f := forbidden.QuickSorted
  else
    f := forbidden.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if not f.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Find(item: VarType; ID: TRange): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TRange; const item: TVar): Integer; overload;
begin
  if Self.Populated then
  case ID.Ascending of
    True:
    for Result := ID.start to ID.stop do
      if (Self[Result] = item) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if (Self[Result] = item) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Find(item: VarType; ID: TIntegerArray): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TIntegerArray; const item: TVar): Integer; overload;
var
  i: Integer;
begin
  if Self.Populated then
  for i := 0 to High(ID) do
    if (Self[ID[i]] = item) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
 <arr.Find(items: TArray; ID: TRange): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TRange; const items: TArr): Integer; overload;
begin
  if (Self.Populated and items.Populated) then
  case ID.Ascending of
    True:
    for Result := ID.start to ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Find(items: TArray; ID: TIntegerArray): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TIntegerArray; const items: TArr): Integer; overload;
var
  i: Integer;
begin
  if (Self.Populated and items.Populated) then
  for i := 0 to High(ID) do
    if items.Contains(Self[ID[i]]) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
 <arr.First: Integer>
 @action: Returns the first index of arr.
 @note: With empty array result will be -1!
[==============================================================================}
function HArr.First: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, 0);
end;

{==============================================================================]
 <arr.First(item: VarType): Integer>
 @action: Returns the first index that matches item in arr.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.First(const item: TVar): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.First(items: TArray): Integer>
 @action: Returns the first arr index that matches any of the items.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.First(const items: TArr): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function HArr.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function HArr.Fit(const aSize: Integer): Integer; overload;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to fit within the specified range.
  @note: 
    - Returns the final array length. 
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function HArr.Fit(const aBounds: TRange): Integer; overload;
var
  l: Integer;
  b: TRange;
begin
  l := Length(Self);
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
 <arr.Fits(maxValue: Integer): Integer>
 @action: Returns true if arr size is at maximum maxValue.
 @note: None.
[==============================================================================}
function HArr.Fits(const maxValue: Integer): Boolean; overload;
begin
  Result := (Length(Self) <= maxValue);
end;

{==============================================================================]
 <arr.Fits(target: TRange): Integer>
 @action: Returns true if arr size is between target start and stop.
 @note: None.
[==============================================================================}
function HArr.Fits(const target: TRange): Boolean; overload;
begin
  Result := not ((Length(Self) < Min(target.start, target.stop)) or (Length(Self) > Max(target.start, target.stop)));
end;

{==============================================================================]
 <arr.Flip: Boolean>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}
function HArr.Flip: Boolean; overload;
var
  r: TRange;
begin
  r.Create(0, (Length(Self) - 1));
  Result := (r.stop > 0);
  while (r.start < r.stop) do
    Exchange(r.start.Increase, r.stop.Decrease);
end;

{==============================================================================]
 <arr.Free: Integer>
 @action: Result := Length(Self) + SetLength(Self, 0) combo. 
 @note: None.
[==============================================================================}
function HArr.Free: Integer; overload;
begin
  Result := Length(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.FromLeft(count, index): TArray>
 @action: Returns count of array items from left-side by index.
 @note: None
[==============================================================================}
function HArr.FromLeft(const count: Integer; const index: Integer = 2147483647): TArr; overload;
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
 <arr.FromRight(count, index): TArray>
 @action: Returns count of array items from right-side by index.
 @note: None
[==============================================================================}
function HArr.FromRight(const count: Integer; const index: Integer = 0): TArr; overload;
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
 <arr.Get: TArray>
 @action: Copy of an array arr.
 @note: Just an alternative.
[==============================================================================}
function HArr.Get: TArr; overload;
var
  a: TVar;
  i: Integer;
begin
  SetLength(Result, Length(Self));
  i := 0;
  for a in Self do
    Result[i.Increase] := a;
 end;

{==============================================================================]
 <arr.Get(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Get(const ID: TIntegerArray): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(ID) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
 <arr.Get(ID: TRange): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Get(const ID: TRange): TArr; overload;
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
 <arr.Group: T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function HArr.Group: T2DArr; overload;
var
  h, i, r, g, l: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit([]);
  g := -1;
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (Self[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := Self[i];
        Break;
      end;
    end;
    if not f then
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
 <arr.Group: T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function HArr.Group(const weight: TIntegerArray; const wSorted: Boolean = False): T2DArr; overload; var w: TIntegerArray; {$DEFINE Skeleton_Group}{$I Skeletons.inc}{$UNDEF Skeleton_Group}
function HArr.Group(const weight: TDoubleArray; const wSorted: Boolean = False): T2DArr; overload; var w: TDoubleArray; {$DEFINE Skeleton_Group}{$I Skeletons.inc}{$UNDEF Skeleton_Group}

{==============================================================================]
 <arr.Grouped>
 @action: Groups the current array (Self) into sub-arrays based on the
          integer group IDs provided in groups, without performing any
          sorting. Unique group IDs are detected in the order they first
          appear, and each corresponding sub-array is filled accordingly.
 @note: • Requires Length(Self) = Length(groups).
        • Preserves the first-appearance order of groups.
        • Simpler but slower: overall O(n²) due to nested lookups.
        • Uses arr.Supply to dynamically append unique IDs and points.
        • Best suited for small datasets or when original group order must
          be maintained.
[==============================================================================}
function HArr.Grouped(const groups: TIntegerArray): T2DArr; overload;
var
  u: TIntegerArray;
  g, i, j, k, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  l := Length(Self);
  if ((l = 0) or (l <> Length(groups))) then
    Exit;
  SetLength(u, 0);
  for i := 0 to (l - 1) do
  begin
    f := False;
    for j := 0 to High(u) do
      if (groups[i] = u[j]) then
      begin
        f := True;
        Break;
      end;
    if not f then
      u.Supply(groups[i]);
  end;
  SetLength(Result, Length(u));
  for i := 0 to (l - 1) do
    for j := 0 to High(u) do
      if (groups[i] = u[j]) then
      begin
        Result[j].Supply(Self[i]);
        Break;
      end;
end;

{==============================================================================]
 <arr.Grouping>
 @action: Groups the current array (Self) into sub-arrays based on the
          integer group IDs provided in groups. Items that share the same
          group value are placed in the same sub-array. The operation first
          sorts all item indices by their group ID using arr.QuickSorted,
          then builds the resulting cluster list in a single forward pass.
 @note: • Requires Length(Self) = Length(groups).
        • Runs in O(n log n) time due to sorting.
        • The resulting clusters are ordered by ascending group ID.
        • Uses dynamic array resizing during construction.
        • Suitable for large datasets where grouping speed matters more
          than preserving the original order.
[==============================================================================}
function HArr.Grouping(const groups: TIntegerArray): T2DArr; overload;
var
  i, l, g, c: Integer;
  p: TIntegerArray;
begin
  l := Length(Self);
  SetLength(Result, 0);
  if ((l = 0) or (l <> Length(groups))) then
    Exit;
  SetLength(p, l);
  for i := 0 to (l - 1) do
    p[i] := i;
  p := p.QuickSorted(groups);
  g := groups[p[0]];
  c := 0;
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to (l - 1) do
  begin
    if (groups[p[i]] <> g) then
    begin
      g := groups[p[i]];
      SetLength(Result, (c.Increment + 1));
      SetLength(Result[c], 0);
    end;
	Result[c].Supply(Self[p[i]]);
  end;
end;

{==============================================================================]
 <arr.Groupify>
 @action: Groups the current array (Self) into sub-arrays according to the
          integer group identifiers provided in groups. Each unique group value
          becomes a separate sub-array in the result, containing all elements
          from Self whose corresponding index in groups matches that group.
 @note: • Requires `Length(Self) = Length(groups).
        • Returns an empty result if the input is empty or lengths differ.
        • Uses a TDictionary<Integer, TArr> internally for O(1) average
          grouping performance.
        • The resulting order of groups in Result is **not deterministic**
          because TDictionary.Values does not preserve insertion or sorted
          order.
        • Best suited for large datasets where grouping speed is more
          important than predictable output order.
[==============================================================================}
function HArr.Groupify(const groups: TIntegerArray): T2DArr; overload;
var
  m: specialize TDictionary<Integer, TArr>;
  l, i, g: Integer;
begin
  SetLength(Result, 0);
  l := Length(Self);
  if ((l = 0) or (l <> Length(groups))) then
    Exit;
  m := specialize TDictionary<Integer, TArr>.Create;
  try
    for i := 0 to (l - 1) do
    begin
      g := groups[i];
      if not m.ContainsKey(g) then
        m.Add(g, []);
      m[g] := (m[g] + [Self[i]]);
    end;
    Result := m.Values.ToArray;
  finally
    m.Free;
  end;
end;

{==============================================================================]
 <arr.Grow(item: VarType; allowDuplicates: Boolean): Integer>
 @action: Feeds item to array and returns the index position it was added to.
 @note: Returns -1 if duplicates are not allowed and array already contains item.
[==============================================================================}
function HArr.Grow(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload;
begin
  if ((not allowDuplicates) and Self.Contains(item)) then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Holds(chain: TArray): Boolean>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}
function HArr.Holds(const chain: TArr): Boolean; overload;
var
  a, b, x, y, z: Integer;
  n: Boolean;
begin
  z := High(Self);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (Self[a + x] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

{==============================================================================]
 <arr.Homogeneous(item: VarType): Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Homogeneous(const item: TVar): Boolean; overload;
var
  h, i: Integer;
begin
  i := -1;
  h := High(Self);
  Result := (h > -1);
  while (Result and (i.Increase < h)) do
    Result := (Self[i] = item);
end;

{==============================================================================]
 <arr.Homogeneous: Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Homogeneous: Boolean; overload;
begin
  Result := ((Length(Self) > 0) and Homogeneous(Self[0]));
end;

{==============================================================================]
 <arr.ID(aAscending: Boolean): TIntegerArray>
 @action: Returns indexes of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.ID(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, b, s: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  b := (Integer(not aAscending) * (l - 1));
  s := IfThen(aAscending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := (b + (s * i));
end;

{==============================================================================]
 <arr.IDs(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.IDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i: Integer;
begin
  SetLength(Result, Length(Self));
  h := High(Self);
  case aAscending of
    True:
    for i := 0 to h do
      Result[i] := i;
    False:
    for i := h downto 0 do
      Result[h - i] := i;
  end;
end;

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray): TArray>
 @action: Returns items from arr by IDs.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function HArr.IDs(const ID: TIntegerArray): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; item: VarType): TArray>
 @action: Returns arr with IDs replaced as item.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function HArr.IDs(const ID: TIntegerArray; const item: TVar): TArr; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; items: TArray): TArray>
 @action: Returns arr with IDs replaced as items.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
function HArr.IDs(const ID: TIntegerArray; const items: TArr): TArr; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  l := Length(items);
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
 <arr.Includes(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
 @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}
function HArr.Includes(const item: TVar; const index: Integer = 2147483647): Boolean; overload;
var
  i: Integer;
begin
  for i := Min(High(Self), index) downto 0 do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Indexed(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if Self.Populated then
  case aAscending of
    True:
    while (l.Decrement > -1) do
      Result[l] := l;
    False:
    while (l.Decrement > -1) do
      Result[(Length(Self) - l) - 1] := l;
  end;
end;

{==============================================================================]
 <arr.Indexes(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := IfThen(aAscending, i, ((l - i) - 1));
end;

{==============================================================================]
 <arr.Indices(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indices(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, h: Integer;
begin
  l := Low(Self);
  h := High(Self);
  SetLength(Result, ((h - l) + 1));
  case aAscending of
    False:  
    for i := l to h do
      Result[h - i] := i;
	True:
    for i := l to h do
      Result[i - l] := i;
  end;
end;

{==============================================================================]
 <arr.Inject>
  @action: Inserts the specified items into the current array at the given index.
           Elements at and after that index are shifted to make room for the
           inserted items.
  @note: If the index exceeds the current length, the items are appended.
         If the index is less than zero, insertion occurs at the beginning.
         Passing an empty array leaves the original array unchanged.
         Returns the new total number of elements after insertion.
[==============================================================================}
function HArr.Inject(const items: TArr; const index: Integer = 2147483647): Integer; overload;
var
  i, s, l, p: Integer;
begin
  s := Length(Self);
  l := Length(items);
  if (l = 0) then
    Exit(s);
  p := Max(Min(s, index), 0);
  SetLength(Self, (s + l));
  for i := (s - 1) downto p do
    Self[i + l] := Self[i];
  for i := 0 to (l - 1) do
    Self[p + i] := items[i];
end;    

{==============================================================================]
 <arr.Keep(items: TArray; index: Integer): TArray>
 @action: Keeps items in array, removes others.
 @note: Supports custom start index! Returns the modified arr.
[==============================================================================}
function HArr.Keep(const items: TArr; const index: Integer = 0): TArr; overload;
var
  m, i, l, r: Integer;
begin
  l := Length(Self);
  m := Max(0, index);
  case (items.Populated and (m < l)) of
    True:
    begin
      r := 0;
	  SetLength(Result, l);
	  for i := 0 to (m - 1) do
	    Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
          Result[i - r] := Self[i]
        else
          Inc(r);
	  SetLength(Result, (l - r));
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
 <arr.Kill: Integer>
 @action: Combination of Length(arr) + SetLength(arr, 0).
 @note: Returns the length of the arr!
[==============================================================================}
function HArr.Kill: Integer; overload;
begin
  Result := Length(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Last: Integer>
 @action: Returns the last index of arr.
 @note: With empty array result will be -1!
[==============================================================================}
function HArr.Last: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, (Self.Size - 1));
end;

{==============================================================================]
 <arr.Last(item: VarType): Integer>
 @action: Returns the last index that matches item in arr.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.Last(const item: TVar): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Last(items: TArray): Integer>
 @action: Returns the last arr index that matches any of the items.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.Last(const items: TArr): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.LeastCommon>
 @action: Returns the least common array item.
 @note: None
[==============================================================================}
function HArr.LeastCommon: TVar; overload;
var
  d: specialize TDictionary<TVar, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(TVar));
  Result := Self[0];
  m := MaxInt;
  d := specialize TDictionary<TVar, Integer>.Create;
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
 <arr.LeastFrequent: VarType> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}
function HArr.LeastFrequent: TVar; overload;
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
 <arr.Len: Integer>
 @action: Simply Result := Length(arr);
 @note: None.
[==============================================================================}
function HArr.Len: Integer; overload;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Loc(item: VarType; index: Integer): Integer>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Loc(const item: TVar; const index: Integer = 2147483647): Integer; overload;
begin
  for Result := Min(High(Self), index) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Loc(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function HArr.Loc(const items: TArr; const index: Integer = 2147483647): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if items.Populated then
  for Result := Min(High(Self), index) downto 0 do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Location(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Location(const item: TVar; const index: Integer = 2147483647): Integer; overload;
var
  l: Integer;
begin
  l := Length(Self);
  Result := Min(l, (index + 1));
  while (Result.Decrement > -1) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Location(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function HArr.Location(const items: TArr; const index: Integer = 2147483647): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    l := Length(Self);
    Result := Min(l, (index + 1));
    while (Result.Decrement > -1) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Locations(item: VarType; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matched with item.
 @note: None.
[==============================================================================}
function HArr.Locations(const item: TVar; const index: Integer = 2147483647): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Locations(items: TArray; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matches with items.
 @note: None.
[==============================================================================}
function HArr.Locations(const items: TArr; const index: Integer = 2147483647): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Locations: TIntegerArray>
 @action: Simply returns arr indexes.
 @note: None.
[==============================================================================}
function HArr.Locations: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  r := 0;
  for i := High(Result) downto 0 do
    Result[r.Increase] := i;  
end; 

{==============================================================================]
 <arr.MergeSortWeighted>
 @action: Performs an in-place merge sort on the current integer array (Self),
          ordering both Self and the given weight array according to the
          weight values. Supports ascending or descending order.
 @note: - Self and weight must be of equal length.
        - Sorting is stable (preserves relative order of equal weights).
        - Returns the length of Self after sorting.
        - When aAscending = True, smaller weights appear first.
[==============================================================================}
function HArr.MergeSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSW(var arr: TArr; var wgt: TIntegerArray; const L, R: Integer);
  var
    s: TArr;
    w: TIntegerArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSW(arr, wgt, L, m);
    MSW(arr, wgt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(w, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (wgt[i] <= wgt[j])) or ((not aAscending) and (wgt[i] >= wgt[j]))) of
        True:
        begin
          s[k] := arr[i];
          w[k] := wgt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          w[k] := wgt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      w[k] := wgt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      w[k] := wgt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      wgt[L + k] := w[k];
    end;
  end;
begin
  Result := Length(Self);
  if (Result > 1) then
    MSW(Self, weight, 0, (Result - 1));
end;

function HArr.MergeSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSW(var arr: TArr; var wgt: TDoubleArray; const L, R: Integer);
  var
    s: TArr;
    w: TDoubleArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSW(arr, wgt, L, m);
    MSW(arr, wgt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(w, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (wgt[i] <= wgt[j])) or ((not aAscending) and (wgt[i] >= wgt[j]))) of
        True:
        begin
          s[k] := arr[i];
          w[k] := wgt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          w[k] := wgt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      w[k] := wgt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      w[k] := wgt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      wgt[L + k] := w[k];
    end;
  end;
begin
  Result := Length(Self);
  if (Result > 1) then
    MSW(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
 <arr.Mix(mixings: Integer): Boolean>
 @action: Ramdomizes array with custom mixings.
 @note: None.
[==============================================================================}
function HArr.Mix(const mixings: Integer = 1): Boolean; overload;
var
  l, i, m: Integer;
begin
  Result := ((mixings > 0) and Self.Populated);
  if not Result then
    Exit;
  l := Length(Self);
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Exchange(Random(l), Random(l));
end;

{==============================================================================]
 <arr.Mixed(mixings: Integer): TArray>
 @action: Returns ramdomized array by mixing.
 @note: None.
[==============================================================================}
function HArr.Mixed(const mixings: Integer = 1): TArr; overload;
var
  l, i, m: Integer;
begin
  l := Length(Self);
  Result := Self.Copy;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
 <arr.MostCommon>
 @action: Returns the most common array item.
 @note: None
[==============================================================================}
function HArr.MostCommon: TVar; overload;
var
  d: specialize TDictionary<TVar, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(TVar));
  Result := Self[0];
  m := 0;
  d := specialize TDictionary<TVar, Integer>.Create;
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
 <arr.MostFrequent: VarType> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}
function HArr.MostFrequent: TVar; overload;
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
  <arr.Movement>
  @action: Applies a sequence of movements (from <arr.Movements>) to the
           current array (Self), returning the resulting array.
  @note: - Each movement shifts elements between indices, not just swapping.
         - Movements preserve the array’s relative ordering behavior.
         - The input move set is assumed valid for the given array.
[==============================================================================}
function HArr.Movement(const moves: TConnectionArray): TArr; overload;
var
  t: TVar;
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
  <arr.Movements>
  @action: Generates a list of element movements required to transform the
           current array (Self) into the target array. Each movement represents
           relocating an element from one index to another, shifting intervening
           elements accordingly (like insertion).
  @note: - Returns an array of TConnection records (id1 = from, id2 = to).
         - The operations are positional (preserve relative order of others).
         - Can be reversed/applied using <arr.Movement>.
         - Useful for visualizing "element movement" sorting.
[==============================================================================}
function HArr.Movements(const target: TArr): TConnectionArray; overload;
var
  t: TVar;
  i, j, k: Integer;
  s: TArr;
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
      SetLength(Result, (Length(Result) + 1));
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
 <arr.Multi(threshold: Integer): Boolean>
 @action: Returns true if array contains at least threshold of items in it.
 @note: None.	
[==============================================================================}
function HArr.Multi(const threshold: Integer = 2): Boolean; overload;
begin
  Result := (Length(Self) >= threshold);
end;

{==============================================================================]
 <arr.Multi(threshold: Integer): Boolean>
 @action: Returns true if array contains at least threshold of items in it.
 @note: None.	
[==============================================================================}
function HArr.Multi(const threshold: TRange): Boolean; overload;
var
  r: TRange;
begin
  r:= threshold.Normalize;
  Result := InRange(Length(Self), r.start, r.stop);
end;

{==============================================================================]
 <arr.Next(index: Integer; count: Integer): TArray>
 @action: Returns next items from array by index and count.
 @note: None.	
[==============================================================================}
function HArr.Next(const index: Integer; const count: Integer = 2147483647): TArr; overload;
var
  m, i: Integer;
begin
  if ((index >= 0) and (index < (Length(Self) - 1)) and (count > 0)) then
  begin
    m := Min((Length(Self) - (index + 1)), count);
    SetLength(Result, m);
    for i := 0 to (m - 1) do
      Result[i] := Self[(index + 1) + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Occurs(item: VarType; occurrence: Integer): Boolean>
 @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
 @note: Supports lookup for 0 items. Loops array through from beginning to end.	
[==============================================================================}
function HArr.Occurs(const item: TVar; const occurrence: Integer = 1): Boolean; overload;
var
  o, p: Integer;
begin
  if (occurrence < 0) then
    Exit(False);
  case (occurrence = 0) of
    False:
    begin
      o := 0;
      p := -1;
      while (o <= occurrence) do
      begin
        p := Self.Pos(item, (p + 1));
        if (p = -1) then
          Break;
        o := (o + 1);
      end;
      Result := (o = occurrence);
    end;
    True: Result := (Self.Pos(item) = -1);
  end;
end;

{==============================================================================]
 <arr.Overlay(items: TArray; index: Integer; init: VarType): TArray>
 @action: Overlays items to array index.
 @note: Returns the array with overlay action.		
[==============================================================================}
function HArr.Overlay(const items: TArr; const index: Integer; const init: TVar): TArr; overload;
var
  s, l, r, i, a, j: Integer;
begin
  l := Length(items);
  if (l = 0) then
    Exit(Self.Copy);
  s := Length(Self);
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

function HArr.Overlay(const items: TArr; const index: Integer = 0): TArr; overload;
begin
  Result := Self.Overlay(items, index, Default(TVar));
end;

{==============================================================================]
 <arr.Oversize(limit: Integer): Boolean>
 @action: Returns true if size of arr is OVER the limit.
 @note: None.	
[==============================================================================}
function HArr.Oversize(const limit: Integer): Boolean; overload;
begin
  Result := (Length(Self) > limit);
end;

{==============================================================================]
 <arr.Partition(pSize: Integer): T2DArray>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
function HArr.Partition(const pSize: Integer): T2DArr; overload;
var
  p, i, j, s, r, l: Integer;
begin
  if ((pSize > 0) and Self.Populated) then
  begin
    l := Length(Self);
    p := ((l + (pSize - 1)) div pSize);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * pSize);
      if ((s + pSize) > l) then
        r := (l - s)
      else
        r := pSize;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := Self[s + j];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Patch(index: Integer; items: TArray): Integer>
 @action: Simply puts items to array index.
 @note: Uses SetLength incase index + items goes over the current length.
        If index is below 0 it will automatically set max length.
[==============================================================================}
function HArr.Patch(const index: Integer; const items: TArr): Integer; overload;
var
  j, i: Integer;
begin
  if items.Empty then
    Exit(index);
  i := IfThen((index < 0), Length(Self), index);
  Result := (i + Length(items));
  if (Result > Length(Self)) then
    SetLength(Self, Result);
  for j := 0 to High(items) do
    Self[i + j] := items[j];
end;

{==============================================================================]
 <arr.Pick(items: TArray; index: Integer): TArray>
 @action: Alternative method for arr.Keep
 @note: None.
[==============================================================================}
function HArr.Pick(const items: TArr; const index: Integer = 0): TArr; overload;
var
  i, m, l: Integer;
begin
  l := Length(Self);
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
          SetLength(Result, (Length(Result) + 1));
          Result[High(Result)] := Self[i];
        end;
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
 <arr.Plain: Boolean>
 @action: Returns true if all array items are identical.
 @note: None.
[==============================================================================}
function HArr.Plain: Boolean; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  if (l <= 1) then
    Exit(True);
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Pop: VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
function HArr.Pop: TVar; overload;
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
 <arr.Pop(null: VarType): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: Returns null if array contains no items.
[==============================================================================}
function HArr.Pop(const null: TVar): TVar; overload;
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
 <arr.Populate(items: TArray; times: Integer): Boolean>
 @action: Populates array with items, x-times.
 @note: Returns true if items is not empty and times is more than 0.
[==============================================================================}
function HArr.Populate(const items: TArr; const times: Integer = 1): Boolean; overload;
var
  i, j, l: Integer;
begin
  l := Length(items);
  SetLength(Self, (l * times));
  Result := (Length(Self) > 0);
  if Result then
  for i := 0 to (l - 1) do
    for j := 0 to (times - 1) do
      Self[i + (j * l)] := items[i];
end;

{==============================================================================]
 <arr.Populate(item: VarType; times: Integer): Boolean>
 @action: Populates array with item, x-times.
 @note: Returns true if times is more than 0.
[==============================================================================}
function HArr.Populate(const item: TVar; const times: Integer = 1): Boolean; overload;
var
  i: Integer;
begin;
  SetLength(Self, times);
  Result := (Length(Self) > 0);
  if Result then
  for i := 0 to (times - 1) do
    Self[i] := item;
end;

{==============================================================================]
 <arr.Populated(population: TRange): Boolean>
 @action: Returns true if arr Length is between population TRange (start, stop).
 @note: None.
[==============================================================================}
function HArr.Populated(const population: TRange): Boolean; overload;
begin
  Result := InRange(Length(Self), population.Minimum, population.Maximum);
end;

{==============================================================================]
 <arr.Populated(populationMin, populationMax: Integer): Boolean>
 @action: Returns true if arr Length is between populationMin and populationMax.
 @note: Strict! Min should NOT be higher than Max.
[==============================================================================}
function HArr.Populated(const populationMin: Integer = 1; const populationMax: Integer = 2147483647): Boolean; overload;
begin
  Result := InRange(Length(Self), populationMin, populationMax);
end;  

{==============================================================================]
 <arr.Pos(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Pos(const item: TVar; const index: Integer = 0): Integer; overload;
begin
  for Result := Max(0, index) to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Pos(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function HArr.Pos(const items: TArr; const index: Integer = 0): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(Self) do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Position(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Position(const item: TVar; const index: Integer = 0): Integer; overload;
var
  l: Integer;
begin
  Result := Max(-1, (index - 1));
  l := Length(Self);
  while (Result.Increment < l) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Position(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function HArr.Position(const items: TArr; const index: Integer = 0): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    Result := Max(-1, (index - 1));
    l := Length(Self);
    while (Result.Increment < l) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Positions(item: VarType; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matched with item.
 @note: None.
[==============================================================================}
function HArr.Positions(const item: TVar; const index: Integer = 0): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Positions(items: TArray; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matches with items.
 @note: None.
[==============================================================================}
function HArr.Positions(const items: TArr; const index: Integer = 0): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and items.Populated) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Positions: TIntegerArray>
 @action: Simply returns arr indexes.
 @note: None.
[==============================================================================}
function HArr.Positions: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := i;  
end;

{==============================================================================]
 <arr.Prepend>
  @action: Inserts the specified items into the current array starting at the
           given index (default = 0). Elements at and after that index are
           shifted to follow the newly inserted items.
  @note: If the index is less than 0, insertion occurs at the beginning.
         If the index exceeds the array length, the items are appended.
         Returns the new total number of elements after insertion.
[==============================================================================}
function HArr.Prepend(const items: TArr; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  i := Max(Min(index, Length(Self)), 0);
  Self := (Self.Copy(0, i) + items + Self.Copy(i, (Length(Self) - i)));
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Presence(item: VarType; occurrence: Integer): Boolean>
 @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
 @note: Supports lookup for 0 items. Loops array through from end to beginning.	
[==============================================================================}
function HArr.Presence(const item: TVar; const occurrence: Integer = 1): Boolean; overload;
var
  l, o: Integer;
begin
  if (occurrence < 0) then
    Exit(False);
  case (occurrence = 0) of
    False:
    begin
      o := 0;
      l := Length(Self);
      while (o <= occurrence) do
      begin
        l := Self.Loc(item, (l - 1));
        if (l = -1) then
          Break;
        o := (o + 1);
      end;
      Result := (o = occurrence);
    end;
    True: Result := (Self.Loc(item) = -1);
  end;
end;

{==============================================================================]
 <arr.Previous(index: Integer; count: Integer): TIntegerArray>
 @action: Returns previous array items from index by count.
 @note: None.
[==============================================================================}
function HArr.Previous(const index: Integer; const count: Integer = 2147483647): TArr; overload;
var
  m, l, i: Integer;
begin
  if ((index > 0) and (index < Length(Self)) and (count > 0)) then
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
 <arr.Pruned: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Pruned: TArr; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
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
 <arr.Pruned: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Pruned(const threshold: Integer): TArr; overload;
var
  w: TArr;
  e: TVar;
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
      SetLength(Result, (Length(Result) + 1));
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
 <arr.Prune: Integer>
 @action: Removes all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Prune: Integer; overload;
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
 <arr.Pull: TArr>
 @action: Returns the contents of the array and leaves it empty.
 @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function HArr.Pull: TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Purified: TArr>
 @action: Returns array with unique items
 @note: None.
[==============================================================================}
function HArr.Purified(const dAscending: Boolean = True): TArr; overload;
var
  d: specialize TDictionary<TVar, Boolean>;
  l: specialize TList<TVar>;
  i: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  l := specialize TList<TVar>.Create;
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
 <arr.Purify: Integer>
 @action: Removes duplicates
 @note: None
[==============================================================================}
function HArr.Purify(const dAscending: Boolean = True): Integer; overload;
var
  d: specialize TDictionary<TVar, Boolean>;
  c: TArr;
  i: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
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
 <arr.Put(ID: TIntegerArray; item: VarType): TArray>
 @action: Returns array arr filled with item to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Put(const ID: TIntegerArray; const item: TVar): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
 <arr.Put(ID: TIntegerArray; items: TArray): TArray>
 @action: Returns array arr filled with items to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Put(const ID: TIntegerArray; const items: TArr): TArr; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  l := Length(items);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
 <arr.Put(index: Integer; items: TArray): TArray>
 @action: Returns array arr filled with items to starting from custom start index.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Put(const index: Integer; const items: TArr): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(items) do
    Result[index + i] := items[i];
end;

{==============================================================================]
 <arr.Push(item: VarType): Integer>
 @action: Places item in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
function HArr.Push(const item: TVar): TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  Result[l] := item;
end;

{==============================================================================]
 <arr.Push(items: TArray): Integer>
 @action: Places items in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
function HArr.Push(const items: TArr): TArr; overload;
var
  h, i, l: Integer;
begin
  h := High(items);
  l := Length(Self);
  SetLength(Result, (l + (h + 1)));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  for i := 0 to h do
    Result[l + i] := items[i];
end;

{==============================================================================]
  <arr.QuickSortWeighted>
  @action: Sorts the array Self in-place according to the values in the weight array.
           Both Self and weight are swapped together so that each element in Self
           maintains correspondence with its weight. Comparisons and pivot selection
           are determined by the weight array.
  @note: Supports ascending or descending order based on weight (controlled by aAscending).
         Returns the length of Self. Useful when you want to reorder an array according
         to external weights while preserving pairings.
[==============================================================================}
function HArr.QuickSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS(var A: TArr; var W: TIntegerArray; const L, R: Integer);
  var
    i, j, p: Integer;
  begin
    i := L;
    j := R;
    p := W[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (W[i] < p) do
          Inc(i);
        while (W[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (W[i] > p) do
          Inc(i);
        while (W[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS(A, W, L, j);
    if (i < R) then
      QS(A, W, i, R);
  end;
begin
  Result := Length(Self);
  if ((Result > 0) and (Result = Length(weight))) then
    QS(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
  <arr.QuickSortWeighted>
  @action: Sorts the array Self in-place according to the values in the weight array.
           Both Self and weight are swapped together so that each element in Self
           maintains correspondence with its weight. Comparisons and pivot selection
           are determined by the weight array.
  @note: Supports ascending or descending order based on weight (controlled by aAscending).
         Returns the length of Self. Useful when you want to reorder an array according
         to external weights while preserving pairings.
[==============================================================================}
function HArr.QuickSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS(var A: TArr; var W: TDoubleArray; const L, R: Integer);
  var
    p: Double;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := W[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (W[i] < p) do
          Inc(i);
        while (W[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (W[i] > p) do
          Inc(i);
        while (W[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS(A, W, L, j);
    if (i < R) then
      QS(A, W, i, R);
  end;
begin
  Result := Length(Self);
  if ((Result > 0) and (Result = Length(weight))) then
    QS(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
  <HArr.QuickSorted(weight: TIntegerArray/TDoubleArray; aAscending: Boolean): TArray>
  @action: Returns arr sorted by weight, based on QuickSort algorithm.
  @note: Weight and arr must be the same length! Otherwise returns empty array.
[==============================================================================}
function HArr.QuickSorted(const weight: TIntegerArray; const aAscending: Boolean = True): TArr; overload; var w: Integer; {$DEFINE Skeleton_QuickSorted}{$I Skeletons.inc}{$UNDEF Skeleton_QuickSorted}
function HArr.QuickSorted(const weight: TDoubleArray; const aAscending: Boolean = True): TArr; overload; var w: Double; {$DEFINE Skeleton_QuickSorted}{$I Skeletons.inc}{$UNDEF Skeleton_QuickSorted}

{==============================================================================]
  <arr.Randomized>
  @action: Returns randomized copy of array
  @note: None.
[==============================================================================}
function HArr.Randomized: TArr; overload;
var
  s, l, r: Integer;
  i: TIntegerArray;
begin
  l := Length(Self);
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
  <arr.Range>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index to max.
[==============================================================================}
function HArr.Range(const subArray: TArr; const index: Integer = 0): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Length(Self);
  s := Length(subArray);
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
  <arr.Ranges>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index to max.
[==============================================================================}
function HArr.Ranges(const subArray: TArr; const index: Integer = 0): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Length(Self);
  s := Length(subArray);
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
 <arr.Recreate: Boolean>
 @action: Clear the array and reallocate to arrSize (negative = previous length).
 @note: Returns True if array was non-empty and arrSize <> 0.
[==============================================================================}
function HArr.Recreate(const arrSize: Integer): Boolean; overload;
var
  l: Integer;
begin
  l := Length(Self);
  Result := ((Length(Self) > 0) or (arrSize <> 0));
  SetLength(Self, 0);
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
end;

{==============================================================================]
 <arr.Reject(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function HArr.Reject(const items: TArr; const index: Integer = 2147483647): TArr; overload;
var
  i, l, m, c: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
  m := Min(index, (l - 1));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Inc(c);
  SetLength(Result, (c + (l - (m + 1))));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[c.Increase] := Self[i];
  for i := (m + 1) to (l - 1) do
    Result[c.Increase] := Self[i];
end;

{==============================================================================]
 <arr.Remove(item: VarType; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Remove(const item: TVar; const index: Integer = 0; const all: Boolean = True): TArr; overload;
var
  l, i, r, m: Integer;
  s: Boolean;
begin
  l := Length(Self);
  if ((l = 0) or (index >= l)) then
    Exit(Self.Copy);
  m := Max(0, index);
  s := False;
  r := 0;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if (s or (Self[i] <> item)) then
      Result[r.Increase + m] := Self[i]
    else
      s := not all;
  SetLength(Result, (r + m));
end;

{==============================================================================]
 <arr.Remove(item: VarType; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Remove(const item: TVar; const all: Boolean): TArr; overload;
begin
  Result := Self.Remove(item, 0, all);
end;

{==============================================================================]
 <arr.Remove(items: TArray; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Remove(const items: TArr; const index: Integer = 0; const all: Boolean = True): TArr; overload;
var
  a, b, l, i, r, m: Integer;
  d, s: Boolean;
begin
  l := Length(Self);
  b := High(items);
  if ((l = 0) or (index >= l) or (b = -1)) then
    Exit(Self.Copy);
  m := Max(0, index);
  r := 0;
  s := False;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (Self[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
      Result[r.Increase + m] := Self[i]
    else
      d := not s;
  end;
  SetLength(Result, (r + m));
end;

{==============================================================================]
 <arr.Remove(items: TArray; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Remove(const items: TArr; const all: Boolean): TArr; overload;
begin
  Result := Self.Remove(items, 0, all);
end;

{==============================================================================]
 <arr.Reposition(oldIndex, newIndex: Integer): Boolean>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
function HArr.Reposition(const oldIndex, newIndex: Integer): Boolean; overload;
var
  s: TVar;
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
 <arr.Reset: Integer>
 @action: Resets all elements of the array to default values while preserving its structure.
 @note: Returns the number of elements that were reset.
[==============================================================================}
function HArr.Reset: Integer; overload;
begin
  Result := Length(Self);
  SetLength(Self, 0);
  SetLength(Self, Result);
end; 

{==============================================================================]
 <arr.Resize(aChange: Integer): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
[==============================================================================}
function HArr.Resize(const aChange: Integer): Integer; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Self, (l + aChange));
  Result := (Length(Self) - l);
end;

{==============================================================================]
 <arr.Resize(aChange: Integer; null: VarType): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
		Supports null for filling created indexes.
[==============================================================================}
function HArr.Resize(const aChange: Integer; const null: TVar): Integer; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Self, aChange);
  Result := (Length(Self) - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;

{==============================================================================]
 <arr.Reversal>
 @action: Returns array with items in reversed order.
 @note: None.
[==============================================================================}
function HArr.Reversal: TArr; overload;
var
  n: Integer;
  r: TRange;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Length(Self));
  r.Create(-1, Length(Result));
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.stop];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.start];
  end;
end;

{==============================================================================]
 <arr.Reverse: Boolean>
 @action: Reverses items in array.
 @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
function HArr.Reverse: Boolean; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Exchange(i, ((l - i) - 1));
end;

{==============================================================================]
 <arr.Reversed: TArray>
 @action: Returns reversed version of array arr.
 @note: None.
[==============================================================================}
function HArr.Reversed: TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
 <arr.Reversify>
  @action: Reverses the order of elements in a 1D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function HArr.Reversify: Boolean; overload;
var
  s: TArr;
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if not Result then
    Exit;
  SetLength(s, l);
  for i := 0 to (l - 1) do
    s[i] := Self[(l - 1) - i];
  Self := s;
end;

{==============================================================================]
 <arr.Reversion>
 @action: Returns array with items in reversed order.
 @note: None.
[==============================================================================}
function HArr.Reversion: TArr; overload;
var
  h, i, l: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[(l - i) - 1];
    Result[(l - i) - 1] := Self[i];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;

{==============================================================================]
 <arr.Runs>
  @action: Groups consecutive identical values into sub-arrays.
  @note: Input must be sorted for meaningful grouping; a new group is started
         whenever the value differs from the previous element.
[==============================================================================}
function HArr.Runs: T2DArr; overload;
var
  i, r: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  r := -1;
  for i := 0 to High(Self) do
  begin
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      SetLength(Result, (r.Increment + 1));
    Result[r].Supply(Self[i]);
  end;
end;

{==============================================================================]
 <arr.Sample(sSize): TArray>
 @action: Returns sample from array by sSize.
 @note: None.
[==============================================================================}
function HArr.Sample(const sSize: Integer): TArr; overload;
var
  i: Integer;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  r := Self.Domain.Sample(sSize);
  SetLength(Result, Length(r));
  for i := 0 to High(Result) do
    Result[i] := Self[r[i]];
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Scan(const ID: TRange; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Populated then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
        if (r >= limit) then
	  Break
        else
          if (Self[i] = item) then
            Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
        if (r >= limit) then
          Break
        else
          if (Self[i] = item) then
	    Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Scan(const ID: TIntegerArray; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Empty then
  begin
    SetLength(Result, Length(ID));
    for i := 0 to High(ID) do
      if (r >= limit) then
        Break
      else
        if (Self[ID[i]] = item) then
	  Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(items: TArray; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Scan(const ID: TRange; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
        if (r >= limit) then
          Break
        else
          if items.Contains(Self[i]) then
            Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
        if (r >= limit) then
          Break
        else
          if items.Contains(Self[i]) then
            Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Scan(const ID: TIntegerArray; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
  begin
    SetLength(Result, Length(ID));
    for i := 0 to High(ID) do
      if (r >= limit) then
        Break
      else
        if items.Contains(Self[ID[i]]) then
	  Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scramble: TIntegerArray>
 @action: Returns scrambled array, that is randomized with offset and swapping. 
 @note: Supports custom swaps.
[==============================================================================}
function HArr.Scramble(const swaps: Integer = -1): TArr; overload;
var
  o, i, l, s: Integer;
begin
  l := Length(Self);
  o := Random(l);
  s := IfThen((swaps < 0), l, swaps);
  Result := Self.Copy(o, (l - o)) + Self.Copy(0, o);
  for i := 1 to s do
    Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
 <arr.Shake: TArray>
 @action: Returns array as randomized with shaking it.
 @note: None.
[==============================================================================}
function HArr.Shake(const shakes: Integer = 1): TArr; overload;
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
 <arr.Shift: VarType>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}
function HArr.Shift: TVar; overload;
var
  i, l: Integer;
begin
  l := (Length(Self) - 1);
  if (l < 0) then
    Exit;
  Result := Self[0];
  for i := 0 to (l - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, l);
end;

{==============================================================================]
 <arr.Shift(sCount: Integer): TArray>
 @action: Shortens the array with first SCOUNT element(s).
 @note: Returns the removed arr[x]s.
[==============================================================================}
function HArr.Shift(const sCount: Integer): TArr; overload;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  s := Max(0, Min(sCount, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  for i := s to High(Self) do
    Self[i - s] := Self[i];
  SetLength(Self, (Length(Self) - s));
end;

{==============================================================================]
 <arr.Shuffle: TArray>
 @action: Returns array as randomized with shuffling it.
 @note: None.
[==============================================================================}
function HArr.Shuffle(const shuffles: Integer = 1): TArr; overload;
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
  <arr.Singlify>
  @action: Removes duplicate occurrences of a specific item, keeping only the first.
  @note: Useful for ensuring a item appears exactly once in the array.
[==============================================================================}
function HArr.Singlify(const item: TVar): Integer; overload;
var
  i, l: Integer;
  f: Boolean;
begin
  Result := Length(Self);
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
  <arr.Singlified>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function HArr.Singlified(const item: TVar): TArr; overload;
var
  i, l: Integer;
  f: Boolean;
begin
  SetLength(Result, Length(Self));
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
  <arr.Singularize>
  @action: Removes duplicate items in the array, keeping only the first occurrence of each unique value.
  @note: The operation modifies the current array in-place. The order of the first appearances
         is preserved. Returns the number of items removed.
[==============================================================================}
function HArr.Singularize(const item: TVar): Integer; overload;
var
  d: specialize TDictionary<TVar, Boolean>;
  i, l: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  try
    l := 0;
    for i := 0 to High(Self) do
      if ((Self[i] <> item) or (not d.ContainsKey(item))) then
      begin
	    if (Self[i] = item) then
          d.Add(item, True);
        Self[l.Increase] := Self[i];
      end;
    Result := (Length(Self) - l);
    if (Result > 0) then
      SetLength(Self, l);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <arr.Singularized>
  @action: Returns a new array containing only the first occurrence of each unique item.
  @note: The original array remains unchanged. The resulting array preserves
         the order of the first appearances.
[==============================================================================}
function HArr.Singularized(const item: TVar): TArr; overload;
var
  d: specialize TDictionary<TVar, Boolean>;
  i, c: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  try
    SetLength(Result, Length(Self));
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
 <arr.Singular: Boolean>
 @action: Returns true if all array items are identical.
 @note: None.
[==============================================================================}
function HArr.Singular: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end; 

{==============================================================================]
 <arr.Size: Integer> 
 @action: Returns array length.
 @note: Simply Result := Length(arr);
[==============================================================================}
function HArr.Size: Integer; overload;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Size(aSize: Integer): TArray>
 @action: Set's arr length to aSize.
 @note: None.
[==============================================================================}
function HArr.Size(const aSize: Integer): TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
 <arr.Size(arr: TArray; aSize: Integer; null: VarType): TArray>
 @action: Set's arr length to size.
 @note: Uses null for created indexes.
[==============================================================================}
function HArr.Size(const aSize: Integer; const null: TVar): TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
  for i := l to (aSize - 1) do
    Result[i] := null;
end;

{==============================================================================]
 <arr.SizeBetween(arr: TArray; sMin, sMax: Integer): Boolean>
 @action: Returns true if size is at equal/greater than sMin and equal/lesser than sMax.
 @note: 	
[==============================================================================}
function HArr.SizeBetween(const sMin, sMax: Integer): Boolean; overload;
begin
  Result := InRange(Length(Self), sMin, sMax);
end;

{==============================================================================]
 <arr.SizeMax(target: Integer): Boolean>
 @action: Returns true if size is at equal/lesser than target.
 @note: 	
[==============================================================================}
function HArr.SizeMax(const target: Integer): Boolean; overload;
begin
  Result := (Length(Self) <= target);
end;

{==============================================================================]
 <arr.SizeMin(target: Integer): Boolean>
 @action: Returns true if size is at equal/greater than target.
 @note: 	
[==============================================================================}
function HArr.SizeMin(const target: Integer): Boolean; overload;
begin
  Result := (Length(Self) >= target);
end;

{==============================================================================]
 <arr.Slice>
 @action: Returns array slice with TRange r.
 @note: Make sure you use correct indexes and there is enough buffer in array!
        No safety checks for this function. 
[==============================================================================}
function HArr.Slice(const r: TRange): TArr; overload;
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
 <arr.Slice>
 @action: Returns array slice with multiple TRanges by r.
 @note: Make sure you use correct indexes and there is enough buffer in array!
        No safety checks for this function. 
[==============================================================================}
function HArr.Slice(const r: TRangeArray): TArr; overload;
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
 <arr.Slots: TIntegerArray>
 @action: Returns indexes of array.
 @note: None.
[==============================================================================}
function HArr.Slots: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to (Length(Self) - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <arr.Soloize>
  @action: Removes all occurrences of a specific item from the array.
  @note: Returns the number of items removed. If none found, the array is unchanged.
[==============================================================================}
function HArr.Soloize(const item: TVar): Integer; overload;
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
  <arr.Soloized>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function HArr.Soloized(const item: TVar): TArr; overload;
var
  i, l, s: Integer;
begin
  SetLength(Result, Length(Self));
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
  <arr.Some>
  @action: Returns random amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function HArr.Some: TArr; overload;
begin
  Result := Self.Shuffle.Copy(0, Max(Random(Self.Size + 1), 1));
end;

{==============================================================================]
  <arr.Some>
  @action: Returns amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function HArr.Some(const amount: Integer): TArr; overload;
begin
  Result := Self.Shuffle.Copy(0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <arr.Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function HArr.Span: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := IfThen((Result.stop = -1), -1, 0);
end;

{==============================================================================]
  <arr.Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function HArr.Span(const subArray: TArr; const index: Integer = 2147483647): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Length(Self);
  s := Length(subArray);
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
  <arr.Spans>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function HArr.Spans(const subArray: TArr; const index: Integer = 2147483647): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Length(Self);
  s := Length(subArray);
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
 <arr.Strip(item: VarType; eraseDuplicates: Boolean): TArray>
 @action: Removes item(s) from arr and returns it.
 @note: 	
[==============================================================================}
function HArr.Strip(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Locations(item)
  else
    p := [Self.Loc(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
 <arr.SubarrayLocation(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function HArr.SubarrayLocation(const pattern: TArr): Integer; overload;
var
  i, j, l, s, p: Integer;
begin
  l := Length(Self);
  p := Length(pattern);
  if ((p > 0) and (p <= l)) then
  for i := (l - p) downto 0 do
  begin
    s := 0;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
        Break
      else
        s := (s + 1);
    if (s = p) then
      Exit(i);
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.SubarrayLocations(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [4,1]	
[==============================================================================}
function HArr.SubarrayLocations(const pattern: TArr): TIntegerArray; overload;
var
  i, j, l, s, r, p: Integer;
begin
  l := Length(Self);
  p := Length(pattern);
  SetLength(Result, 0);
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
    for i := (l - p) downto 0 do
    begin
      s := 0;
      for j := 0 to (p - 1) do
        if (Self[i + j] <> pattern[j]) then
          Break
        else
          s := (s + 1);
      if (s = p) then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.SubarrayPosition(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 1	
[==============================================================================}
function HArr.SubarrayPosition(const pattern: TArr): Integer; overload;
var
  i, j, l, p: Integer;
  f: Boolean;
begin
  l := Length(Self);
  p := Length(pattern);
  if ((p > 0) and (p <= l)) then
  for i := 0 to (l - p) do
  begin
    f := True;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(i);
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.SubarrayPositions(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [1,4]	
[==============================================================================}
function HArr.SubarrayPositions(const pattern: TArr): TIntegerArray; overload;
var
  i, j, l, p, r: Integer;
  f: Boolean;
begin
  l := Length(Self);
  p := Length(pattern);
  SetLength(Result, 0);
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
    for i := 0 to (l - p) do
    begin
      f := True;
      for j := 0 to (p - 1) do
        if (Self[i + j] <> pattern[j]) then
        begin
          f := False;
          Break;
        end;
      if f then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Subset(items: TArray): Boolean>
 @action: Returns true if arr is subset of items.
 @note: None.
[==============================================================================}
function HArr.Subset(const items: TArr): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not items.Contains(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Supply(item: VarType): Integer>
 @action: Adds item to the end of the array.
 @note: Returns the index where item was inserted.
[==============================================================================}
function HArr.Supply(const item: TVar): Integer; overload;
begin
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Supply(item: TArray): Integer>
 @action: Adds items to the end of the array.
 @note: Returns the index where items were inserted.
[==============================================================================}
function HArr.Supply(const items: TArr): Integer; overload;
var
  i: Integer;
begin
  if items.Empty then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + Length(items)));
  for i := 0 to High(items) do
    Self[Result + i] := items[i];
end;

{==============================================================================]
 <arr.Swapped>
 @action: Swaps the contents of this array with the given target array.
 @note: The swap is O(1) because dynamic arrays are reference-counted.
        Returns Length(Self) + Length(target) after the swap.
[==============================================================================}
function HArr.Swapped(var target: TArr): Integer; overload;
var
  t: TArr;
begin
  t := Self;
  Self := target;
  target := t;
  Result := (Length(Self) + Length(target));
end;

{==============================================================================]
 <arr.SwapMerged>
  @action: Swaps the contents of Self and target arrays manually using an
           auxiliary array, and returns a new array containing all elements
           from both arrays combined in the **original order** (before swap).
  @note: The swap is performed by copying elements from Self and target
         into a temporary array in reverse order, then assigning them back.
         This method works but is less efficient (O(n)) because every element
         is copied. Use this if the merged array should reflect the **pre-swap
         ordering**.
[==============================================================================}
function HArr.SwapMerged(var target: TArr): TArr; overload;
var
  r, t, s, i: Integer;
begin
  s := Length(Self);
  t := Length(target);
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
 <arr.SwappedMerge>
  @action: Swaps the contents of Self and target arrays using the reference
           swap method (Self.Swapped), and returns a new array containing all
           elements from both arrays combined in the **post-swap order**.
  @note: This implementation is more efficient (O(1) for the swap) because
         it swaps references rather than copying elements individually.
         The merged array is then constructed by iterating over Self and
         target. This is preferred for large dynamic arrays, and the
         resulting array reflects the swapped positions of Self and target.
[==============================================================================}
function HArr.SwappedMerge(var target: TArr): TArr; overload;
var
  t, s, i: Integer;
begin
  s := Length(Self);
  t := Length(target);
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
 <arr.To2D(rows, columns: Integer): T2DArray>
 @action: Converts 1D array to 2D by rows and columns.
 @note: Make sure Length(array) equals rows*columns (otherwise returns [])! Working examples below.
		TIA := [1,2,3,4,5,6];
		TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
        TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function HArr.To2D(const rows, columns: Integer): T2DArr; overload;
var
  i, r, c, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, rows, columns);
  i := 0;
  for r := 0 to (rows - 1) do
    for c := 0 to (columns - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.To2D(height: Integer): T2DArray>
 @action: Converts 1D array to 2D by height.
 @note: 
[==============================================================================}
function HArr.To2D(const height: Integer): T2DArr; overload;
var
  l, w, i, r, c: Integer;
begin
  l := Length(Self);
  w := Ceil(l / height);
  SetLength(Result, height, w);
  i := 0;
  for r := 0 to (height - 1) do
    for c := 0 to (w - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.ToIndexes: TIntegerArray>
 @action: Returns indexes of array.
 @note: None.
[==============================================================================}
function HArr.ToIndexes: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  l := Low(Self);
  for i := l to High(Self) do
    Result[i - l] := i;
end;

{==============================================================================]
 <arr.Trade(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function HArr.Trade(var b: TArr): Integer; overload;
var
  a: TArr;
begin
  Result := (Length(Self) + Length(b));
  if (Result > 0) then
  begin
    a := Self.Copy;
    Self := b.Copy;
    b := a.Copy;
    SetLength(a, 0);
  end;
end;

{==============================================================================]
 <arr.Undersize(limit: Integer): Boolean>
 @action: Returns true if size of arr is UNDER the limit.
 @note: None.	
[==============================================================================} 
function HArr.Undersize(const limit: Integer): Boolean; overload;
begin
  Result := (Length(Self) < limit);
end;

{==============================================================================]
 <arr.Uncluttered: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function HArr.Uncluttered: TArr; overload;
type
  TDict = specialize TDictionary<TVar, Boolean>;
var
  d: TDict;
  r, i, l: Integer;
begin
  l := Length(Self);
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
 <arr.Uniform: Boolean>
 @action: Returns true if arr is consistent with only 1 item.
 @note: Returns True with empty arrays!
[==============================================================================}
function HArr.Uniform: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[0]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Uniform(item: VarType): Boolean>
 @action: Returns true if arr is consistent with only custom item.
 @note: Returns True with empty arrays!
[==============================================================================}
function HArr.Uniform(const item: TVar): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] <> item) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Uniformity>
 @action: Returns 1.0 if all elements equal, 0.0 if all different,
          or something in between based on unique-value ratio. 
 @note: None.
 [==============================================================================}
function HArr.Uniformity: Double; overload;
begin
  if not Self.Empty then
    Result := (1.0 / Self.Distinct)
  else
    Result := 0.0;
end;

{==============================================================================]
 <arr.Unified>
 @action: Uniques array
 @note: None.
 [==============================================================================}
function HArr.Unified(const dAscending: Boolean = True): TArr; overload;
var
  d: specialize TDictionary<TVar, Byte>;
  i, n: Integer;
begin
  d := specialize TDictionary<TVar, Byte>.Create;
  try
    SetLength(Result, Length(Self));
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
 <arr.Unify>
 @action: Uniques array
 @note: None.
 [==============================================================================}
function HArr.Unify(const dAscending: Boolean = True): Integer; overload;
var
  s: TArr;
  d: specialize TDictionary<TVar, Byte>;
  l, i: Integer;
begin
  d := specialize TDictionary<TVar, Byte>.Create;
  Result := 0;
  try
    l := Length(Self);
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
 <arr.Unduplicated: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function HArr.Unduplicated: TArr; overload;
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  Result := Self.Copy;
  l := Length(Result);
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
 <arr.Uniqued: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the unique version of arr.
[==============================================================================}
function HArr.Uniqued: TArr; overload;
var
  i, j, l, c: Integer;
begin
  l := Length(Self);
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
 <arr.Uniques: TIntegerArray>
 @action: Returns the indexes of unique array (arr) items.
 @note: None.
[==============================================================================}
function HArr.Uniques: TIntegerArray; overload;
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
 <arr.Unshift(item: VarType): TArray>
 @action: Grows arr with item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function HArr.Unshift(const item: TVar): TArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := l downto 1 do
    Result[i] := Self[i - 1];
  Result[0] := item;
end;

{==============================================================================]
 <arr.Unshift(items: TArray): TArray>
 @action: Grows arr with items. Returns the index of last added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function HArr.Unshift(const items: TArr): TArr; overload;
var
  l, i, r: Integer;
begin
  if items.Empty then
    Exit(Self.Copy);
  l := Length(items);
  r := (Length(Self) + l);
  SetLength(Result, r);
  for i := (r - 1) downto l do
    Result[i] := Self[i - l];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
 <arr.Void: Boolean>
 @action: Returns true if array is void (empty)
 @note: Alternative for Empty.
[==============================================================================}
function HArr.Void: Boolean; overload;
begin
  Result := (Low(Self) > High(Self));
end;

{==============================================================================]
 <arr.Waste: Integer>
 @action: Returns total count of Duplicates in array, which is "Waste"
 @note: None.
[==============================================================================}
function HArr.Waste: Integer; overload;
type
  TDict = specialize TDictionary<TVar, Integer>;
var
  d: TDict;
  i: Integer;
  v: TVar;
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
 <arr.Zigzag>
 @action  Creates a new array whose elements are taken alternately from the
          start and end of the source array, producing an outside-in “zigzag” order.
 @note    For odd-length arrays, the middle element appears last.
[==============================================================================}
function HArr.Zigzag(const zAscending: Boolean = True): TArr; overload;
var
  l, r: Integer;
  s: TRange;
begin
  l := Length(Self);
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

{==============================================================================]
 <T1D.Create(item: VarType; aSize: Integer)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
class function T1D.Create(const item: TVar; const aSize: Integer = 1): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, aSize));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

{$IFDEF Sortable}
{==============================================================================]
  <HArr.Sortable>
  @action: Checks whether the array contains at least two different elements.
           Returns True if sorting would change the array order.
  @note: Arrays with all equal elements, a single element, or empty arrays
         return False.
[==============================================================================}
function HArr.Sortable: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <HArr.Sorted>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.Sorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to (High(Self) - 1) do
    if (aAscending and (Self[i] > Self[i + 1])) or ((not aAscending) and (Self[i] < Self[i + 1])) then
      Exit(False);
  Result := (not Self.Empty);
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the entire array is sorted in ascending or descending order.
 @note:   Returns True if all elements are in the correct order according to aAscending.
[==============================================================================}
function HArr.IsSorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the elements between iStart and iStop are in correct
          ascending or descending order.
 @note: The range [iStart..iStop] is automatically normalized and clamped to
        valid array bounds. Returns True if all elements within the range
        follow the specified order.
[==============================================================================}
function HArr.IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload;
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
 <arr.IsSorted>
 @action: Determines whether the array elements within the specified range
          (given as TRange) are ordered in ascending or descending order.
 @note: Internally calls the (iStart, iStop) overload. The range is
        automatically normalized and clamped to valid array bounds.
        Returns True if all elements within the range follow the specified order.
[==============================================================================}
function HArr.IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := Self.IsSorted(indexes.start, indexes.stop, aAscending);
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the element at the specified index is correctly
          positioned relative to its immediate neighbors according to
          ascending or descending order.
 @note: Returns True if the element at the given index maintains proper
        order with adjacent elements. Boundary or single-element arrays are
        considered sorted. Returns False for out-of-range indices.
[==============================================================================}
function HArr.IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload;
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
  <HArr.InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.InOrder(const aAscending: Boolean = True): Boolean; overload;
var
  i, l: Integer;
begin
  i := -1;
  l := Length(Self);
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
  <HArr.Orderly>
  @action: Returns true if array arr is in ascending AND/OR descending order.
  @note: None.
[==============================================================================}
function HArr.Orderly: Boolean; overload;
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
  <HArr.Ordered>
  @action: Returns true if array arr is in ascending AND/OR descending order by aAscending.
  @note: Recursive alternative.
[==============================================================================}
function HArr.Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
begin
  if (index >= High(Self)) then
    Exit(True);
  if ((aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  Result := Self.Ordered(aAscending, (index + 1));
end;

{==============================================================================]
  <HArr.Order>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 1 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function HArr.Order: Integer; overload;
var
  i, l: Integer;
  a, d: Boolean;
begin
  l := Length(Self);
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
  <HArr.Orientation>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 0 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function HArr.Orientation: Integer; overload;
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
  <HArr.Ascend>
  @action: Returns array arr sorted to asscending order.
  @note: None.
[==============================================================================}
function HArr.Ascend: TArr; overload;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  p: TVar;
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
  if (Length(Result) > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <HArr.Descend>
  @action: Returns array arr sorted to descending order.
  @note: None.
[==============================================================================}
function HArr.Descend: TArr; overload;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  p, s: TVar;
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
  if (Length(Result) > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <HArr.Descending>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function HArr.Descending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] < Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Ascending>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function HArr.Ascending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] > Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Decreasing>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = True | [1,0] = True |
[==============================================================================}
function HArr.Decreasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Increasing>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = True | [1,0] = False |
[==============================================================================}
function HArr.Increasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] < Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Downward>
  @action: Returns true if array arr is in descending order.
  @note: Returns true with empty []array! Unlike Descending, Decreasing.
[==============================================================================}
function HArr.Downward: Boolean; overload;
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
  <HArr.Upward>
  @action: Returns true if array arr is in ascending order.
  @note: Returns true with empty [] array! Unlike Ascending, Increasing.
[==============================================================================}
function HArr.Upward: Boolean; overload;
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
  <HArr.Lowest>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function HArr.Lowest: TVar; overload;
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
  <HArr.Highest>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function HArr.Highest: TVar; overload;
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
  <HArr.Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with aAscending as False.
[==============================================================================}
function HArr.Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
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

function HArr.Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Mini(aAscending, start);
end;

{==============================================================================]
  <HArr.Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with aAscending as False.
[==============================================================================}
function HArr.Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
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

function HArr.Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Maxi(aAscending, start);
end;

{==============================================================================]
 <HArr.Mode>
 @action: The value that occurs most frequently in arr.
 @note: None
[==============================================================================}
function HArr.Mode: TVar; overload;
var
  a: TArr;
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
 <HArr.Center>
 @action: The value at the center position of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function HArr.Center: TVar; overload;
begin
  if (Length(Self) > 0) then
    Result := Self[Length(Self) div 2];
end;

{==============================================================================]
  <arr.MergeSortIndexed>
  @action: Sorts the current integer array (Self) using merge sort while
           tracking the original indices of each element.
  @note: - Returns an array of indices representing the order of elements in the sorted array.
         - The original array (Self) is modified in-place.
         - Sorting is stable (preserves order of equal elements).
         - Useful for retrieving both sorted data and their original positions.
[==============================================================================}
function HArr.MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure MSI(var arr: TArr; var indexes: TIntegerArray; const L, R: Integer);
  var
    s: TArr;
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
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := i;
  if (Length(Self) > 1) then
    MSI(Self, Result, 0, High(Result));
end;

{==============================================================================]
 <arr.MergeSortPair>
 @action: Performs an in-place merge sort on the current array (Self),
          reordering both Self and its associated partner array so that the
          elements of partner remain paired with their corresponding elements
          in Self. Sorting is based on the values in Self.
 @note: - Self and partner must have the same length.
        - Sorting is stable: equal values in Self preserve their original order.
        - Returns Length(Self).
        - Set aAscending = False for descending order.
[==============================================================================}
function HArr.MergeSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
  procedure MSP(var arr, prt: TArr; const L, R: Integer);
  var
    s, p: TArr;
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
  Result := Length(Self);
  if (Result > 1) then
    MSP(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <arr.QuickSortPair>
  @action: Sorts the array in-place while simultaneously reordering a partner array 
           to maintain element correspondence. Supports ascending or descending order.
  @note: Useful when you have a key array and a related value array that must stay paired.
         The method returns the length of the array.
[==============================================================================}
function HArr.QuickSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
  procedure QS2(var A, B: TArr; const L, R: Integer);
  var
    p: TVar;
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
  Result := Length(Self);
  if (Result > 0) then
    QS2(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <arr.PartitionSort>
  @action: Sorts the array (Self) in ascending or descending order using a
           stable partition-based recursive sorting algorithm.
  @note:   - Returns Length(Self)
           - The algorithm is conceptually similar to QuickSort but uses
             stable partitioning (no in-place swaps).
           - Equal elements preserve their original order (stable).
           - Uses auxiliary arrays, trading memory for stability.
           - Also known as "Stable QuickSort".
[==============================================================================}
function HArr.PartitionSort(const aAscending: Boolean = True): Integer; overload;
  procedure PS(var A: TArr; const L, R: Integer);
  var
    p: TVar;
	i, t: Integer;
    s, e, b: TArr;
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
    if (Length(s) > 1) then
      PS(s, 0, High(s));
    if (Length(b) > 1) then
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
  Result := Length(Self);
  if (Result > 1) then
    PS(Self, 0, (Result - 1));
end;

{==============================================================================]
  <arr.QuickSortSwapped>
  @action: Sorts the array in ascending or descending order and records all swaps performed.
  @note: Returns a dynamic array of TConnection records, each representing the indices of elements swapped during the sort.
         Useful for visualizations or undoing the sort.
[==============================================================================}
function HArr.QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
  procedure QuickSortRec(const L, R: Integer; var swaps: TConnectionArray);
  var
    p: TVar;
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
          SetLength(swaps, (Length(swaps) + 1));
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
          SetLength(swaps, (Length(swaps) + 1));
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
  if Length(Self) > 1 then
    QuickSortRec(0, High(Self), Result);
end;

{==============================================================================]
  <arr.QuickSortIndexed>
  @action: Sorts the array while tracking the original indices.
  @note: Returns an array of indices representing the order of elements in the sorted array.
         The original array is modified.
         Useful when you want to know how elements move rather than just sorting the values.
[==============================================================================}
function HArr.QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortRec(const L, R: Integer; var indexes: TIntegerArray);
  var
    p: TVar;
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
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  if (l > 1) then
    QuickSortRec(0, (l - 1), Result);
end;

{==============================================================================]
  <arr.QuickSortedly>
  @action: Returns the indices of the array elements in sorted order without modifying the original array.
  @note: Purely functional: the original array stays unchanged.
         The result is an array of indices indicating the sorted order.
[==============================================================================}
function HArr.QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortIndexedHelper(const arr: TArr; var indexes: TIntegerArray; const L, R: Integer; const aAscending: Boolean);
  var
    p: TVar;
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
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  QuickSortIndexedHelper(Self, Result, 0, (l - 1), aAscending);
end;

{==============================================================================]
  <HArr.QuickSorted(aAscending: Boolean): TArr>
  @action: Returns array sorted by its own values, based on QuickSort algorithm.
  @note: None.
[==============================================================================}
function HArr.QuickSorted(const aAscending: Boolean = True): TArr; overload;
  procedure QS(var arr: TArr; const L, R: Integer);
  var
    i, j: Integer;
    p: TVar;
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
  a := Length(Self);
  Result := Self.Copy(0, a);
  if (a > 1) then
    QS(Result, 0, (a - 1));
end;

{==============================================================================]
  <arr.QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function HArr.QuickSort(const aAscending: Boolean = True): Integer; overload;
var
  p: TVar;
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
  <arr.QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function HArr.QuickSort3W(const aAscending: Boolean = True): Integer; overload;
  procedure SortLH(var arr: TArr; const L, H: Integer; const aAscending: Boolean = True);
  var
    a: TVar;
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
  <arr.QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function HArr.QSort(const aAscending: Boolean = True): Integer; overload;
  procedure _QuickSort(var arr: TArr; const start, stop: Integer; const aAscending: Boolean = True);
  var
    p: TVar;
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
  <arr.CoctailSort>
  @action: CoctailSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.CoctailSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.CoctailSort2>
  @action: CoctailSort algorithm.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function HArr.CoctailSort2(const aAscending: Boolean = True): Integer; overload;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    b := -1;
    e := (Length(Self) - 2);
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
  <arr.GnomeSort>
  @action: GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.GnomeSort(const aAscending: Boolean = True): Integer; overload;
var
  o, p, t: Integer;
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
  <arr.GnomeSortOptimized>
  @action: Optimized GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
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
  <arr.PancakeSort>
  @action: PancakeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.PancakeSort(const aAscending: Boolean = True): Integer; overload;
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
  <HArr.BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSort2(const aAscending: Boolean = True): Integer; overload;
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
  <HArr.BubbleSortOptimized>
  @action: Sorts arr with optimized BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSortOptimized(const aAscending: Boolean = True): Integer; overload;
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
  <arr.CombSort>
  @action: CombSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.CombSort(const aAscending: Boolean = True): Integer; overload;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    g := Length(Self);
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
  <arr.HeapSort>
  @action: HeapSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.HeapSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.InsertionSort>
  @action: InsertionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.InsertionSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.SelectionSort>
  @action: SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
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
  <arr.SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
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
  <arr.ShellSort>
  @action: ShellSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.ShellSort(const aAscending: Boolean = True): Integer; overload;
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
        l := Length(Self);
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
  <arr.MergeSort>
  @action: MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.MergeSort(const aAscending: Boolean = True): Integer; overload;
  procedure Merge(var arr, tmp: TArr; const Lo, Hi: Integer; const aAscending: Boolean = True);
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
  t: TArr;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    Merge(Self, t, 0, Result, aAscending);
  end;
end;

{==============================================================================]
  <arr.MergeSortBU>
  @action: Bottom-up MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.MergeSortBU(const aAscending: Boolean = True): Integer; overload;
var
  t: TArr;
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
  <arr.HybridSort>
  @action: Sorts the integer array (Self) in ascending or descending order
           using algorithm close to TimSort — a stable hybrid sorting method that
           combines insertion sort and merge sort for optimal performance.
  @note:   - Returns Length(Self)
           - Stable (preserves equal element order)
[==============================================================================}
function HArr.HybridSort(const aAscending: Boolean = True): Integer; overload;
const
  RUN_SIZE = 32;
  procedure INS(var arr: TArr; const L, R: Integer);
  var
    t: TVar;
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
  procedure MRG(var arr: TArr; const L, M, R: Integer);
  var
    a, b, i, j, k: Integer;
    x, y: TArr;
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
  Result := Length(Self);
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
  <HArr.Uniq: TArr>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function HArr.Uniq(const sSorted: Boolean = False): TArr; overload;
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
  <arr.Downtrending>
  @action: Returns True if the first element of the array is greater than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “falling” trend.
[==============================================================================}
function HArr.Downtrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] > Self[High(Self)]));
end;

{==============================================================================]
  <arr.Uptrending>
  @action: Returns True if the first element of the array is less than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “rising” trend.
[==============================================================================}
function HArr.Uptrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] < Self[High(Self)]));
end;

{==============================================================================]
  <arr.Notrending>
  @action: Returns True if the first element of the array is equal to the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates no significant trend.
[==============================================================================}
function HArr.Notrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] = Self[High(Self)]));
end;

{==============================================================================]
  <arr.Trend>
  @action: Returns the trend of the array’s endpoints:
            1 = Uptrend (first < last),
           -1 = Downtrend (first > last),
            0 = Notrend (first = last or array too short).
  @note: Only meaningful for arrays with at least 2 elements.
         Comparison is done between the first and last elements only.
[==============================================================================}
function HArr.Trend: Integer; overload;
begin
  if ((Length(Self) < 2) or (Self[Low(Self)] = Self[High(Self)])) then
    Result := 0
  else
    if (Self[Low(Self)] > Self[High(Self)]) then
      Result := -1
    else
      Result := 1;
end;

{==============================================================================]
  <arr.Trending>
  @action: Returns True if the array is either Uptrending or Downtrending.
  @note: Only meaningful for arrays with at least 2 elements.
         Returns False if the array has no trend (Notrending).
[==============================================================================}
function HArr.Trending: Boolean; overload;
begin
  Result := (Self.Trend <> 0);
end;

{==============================================================================]
  <arr.Rising>
  @action: Returns True if the array is monotonically non-decreasing,
           i.e., each element is less than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Rising by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function HArr.Rising: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] > Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.Falling>
  @action: Returns True if the array is monotonically non-increasing,
           i.e., each element is greater than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Falling by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function HArr.Falling: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] < Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.Direction>
  @action: Returns numeric trend across the entire array:
           1 = Rising (monotonically non-decreasing),
          -1 = Falling (monotonically non-increasing),
           0 = Notrending (mixed sequence or empty/single element).
  @note: Checks all elements. Inclusive comparisons (≤ / ≥).
[==============================================================================}
function HArr.Direction: Integer; overload;
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
  <arr.TrendFalling>
  @action: Returns True if the first element of the array is greater than or equal to the last element,
           indicating a non-increasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function HArr.TrendFalling: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] >= Self[High(Self)]));
end;

{==============================================================================]
  <arr.TrendRising>
  @action: Returns True if the first element of the array is less than or equal to the last element,
           indicating a non-decreasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function HArr.TrendRising: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] <= Self[High(Self)]));
end;

{==============================================================================]
 <arr.BinaryInsertionSort>
 @action: Sorts the array in ascending or descending order using binary
          insertion sort, which combines binary search and insertion.
 @note: This algorithm runs in O(n²) time in the worst case but uses binary
        search to minimize comparisons. It performs well on small or
        partially sorted datasets. Returns the number of elements sorted.
[==============================================================================}
function HArr.BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
  function BP(const value: TVar; const hIndex: Integer): Integer;
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
  k: TVar;
  i, j, p: Integer;
begin
  Result := Length(Self);
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
  <arr.Sortedness>
  @action: Checks whether the array is monotonic (either ascending or descending).
           Performs a two-phase check: a fast global trend detection from both ends,
           followed by a full local adjacency check to ensure strict monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses Integer_Sign(Self[L], Self[R]) to detect initial trend.
         Efficient for large arrays due to early exit if disorder is detected.
         This version checks every element in both phases.
[==============================================================================}
function HArr.Sortedness: Boolean; overload;
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
  <arr.SortednessEx>
  @action: Enhanced version of Sortedness with configurable stride.
           Performs a subsampled global trend check (using left and right indices
           at intervals of "stride") to quickly detect gross disorder,
           followed by a full local adjacency check if the array passes the global phase.
  @note: Default stride = 16; larger values reduce global comparisons but may delay detection
         of small local disorder. Returns True for arrays of length 0 or 1.
         Useful for extremely large arrays where global trend violation is likely.
[==============================================================================}
function HArr.SortednessEx(const stride: Integer = 16): Boolean; overload;
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
  <arr.Monotonic>
  @action: Checks whether the array is globally monotonic by simultaneously comparing
           elements from both ends toward the center, while also validating adjacent pairs.
           Detects ascending or descending trends dynamically based on endpoints.
  @note: Returns True for arrays of length 0 or 1.
         This approach may detect global disorder slightly earlier than adjacent-only checks.
         Performs both global and local comparisons in a single loop.
         Uses Integer_Increment and Integer_Decrement for safe index movement.
[==============================================================================}
function HArr.Monotonic: Boolean; overload;
var
  L, R: Integer;
begin
  L := -1;
  R := Length(Self);
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
  <arr.Monotone>
  @action: Checks whether the array is monotonic (ascending or descending) by performing
           a symmetric two-way scan from both ends toward the middle.
           Repeatedly evaluates adjacent pairs and global trend to determine monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses a repeat-until loop with early exit if a violation is detected.
         This function is a slightly simpler alternative to Sortedness, but checks both
         global and local conditions for each iteration.
[==============================================================================}
function HArr.Monotone: Boolean; overload;
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
  <arr.IsMonotone>
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
function HArr.IsMonotone: Boolean; overload;
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
  <arr.Monotonious>
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
function HArr.Monotonious: Boolean; overload;
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
  <arr.Unidirectional>
  @action: Checks if the array is monotonic (either non-decreasing or non-increasing).
  @note: Returns True if all elements move in one direction, False otherwise.
[==============================================================================}
function HArr.Unidirectional: Boolean; overload;
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
  <arr.Trendy>
  @action: Checks whether the array is monotonic — either entirely non-decreasing,
           non-increasing, or constant.
  @note: Returns True if the array changes in only one direction; False otherwise.
[==============================================================================}
function HArr.Trendy: Boolean; overload;
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
  <arr.OnOrder>
  @action: Determines whether the array elements remain consistently ordered,
           either non-decreasing, non-increasing, or constant.
  @note: Returns True if the sequence does not reverse direction (monotonic in
         either direction). Returns False if the order changes (both rises and falls occur).
[==============================================================================}
function HArr.OnOrder: Boolean; overload;
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
{$ENDIF}
{$ENDIF}
