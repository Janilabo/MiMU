{$DEFINE Integer}{$I ..\Configuration\Defines.inc}

{$IFDEF TYPES}
TIA = class
public
  class function Init(var arr: TIntegerArray): Integer; overload; 
  class function Reverse(var arr: TIntegerArray): Boolean; overload; 
  class function Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
  class function Unique(var arr: TIntegerArray): Integer; overload; 
  class function Combine(const A, B: TIntegerArray): TIntegerArray; overload;
end;
{$ENDIF}

{$IFDEF HELPERS}
TIntegerArrayHelper = type helper for TIntegerArray
  {$I Core.inc}
  function Bounds: TRange; overload;
  function Bounds(var aSize: Integer): TRange; overload;
  function BRange: TRange; overload;
  function BoundingRange: TRange;
  function Boundaries: TRange;
  function Range: TRange;
  function Coverage: TRange;
  function MinMax: TRange;
  function Region: TRange; overload;
  function Extent: TRange;
  function Undupe: TIntegerArray;
  function Unduped: TIntegerArray;
  function Numberline: TIntegerArray;
  function Sum: Int64;
  function Density: Double;
  function Occupancy: Double;
  function Saturated: Double;
  function Mean: Double;
  function Median: Double;
  function Middle: Double;
  function MostFreq(const null: Integer = -2147483648): Integer;
  function LeastFreq(const null: Integer = -2147483648): Integer;
  function Succ(const currentIndex: Integer; const range: TRange): Integer; overload;
  function Pred(const currentIndex: Integer; const range: TRange): Integer; overload;
  function Successor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
  function Predecessor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
  function Next(const currentIndex: Integer; const range: TRange): Integer; overload;
  function Previous(const currentIndex: Integer; const range: TRange): Integer; overload;
  function Navigate(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
  function Advance(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
  function Retreat(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
  function RadixSort(const aAscending: Boolean = True): Integer;
  function Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Split(const diff: Integer): T2DIntegerArray; overload;
  function Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Sblit(const diff: Integer): T2DIntegerArray; overload;
  function Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
  function Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Group(const diff: Integer): T2DIntegerArray; overload;
  function Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Groub(const diff: Integer): T2DIntegerArray; overload;
  function Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Clique(const diff: Integer): T2DIntegerArray; overload;
  function Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
  function Knit(const diff: Integer): T2DIntegerArray; overload;
  function Reflected: TIntegerArray; overload;
  function Reflect: Integer; overload;
  function Invert: TIntegerArray;
  function Inverted(const arrBounds: TRange): TIntegerArray; overload;
  function Inverted: TIntegerArray; overload;
  function Inverse(const arrBounds: TRange): TIntegerArray; overload;
  function Inverse: TIntegerArray; overload;
  function Mirror: Boolean;
  function Pure(const allowed: TIntegerArray): Boolean; overload;
  function Reinit: Integer; overload;
  function Charify: TCharArray; overload;
  function Charify(var str: string): TCharArray; overload;
  function Stringify: string; overload;
  function Stringify(var chars: TCharArray): string; overload;
  function Special: Boolean;
  function ExtractEven: TIntegerArray; overload;
  function FilterEven: TIntegerArray; overload;
  function ExtractOdd: TIntegerArray; overload;
  function FilterOdd: TIntegerArray; overload;
  function Attach(const items: TIntegerArray): Integer; overload;
  function Embed(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload;
  function Broaden(const rValues: TRange; const aIndex: Integer): TRange; overload;
  function Broaden(const rValues: TRange; const sSorted: Boolean = False): TRange; overload;
  function ToRanges: TRangeArray; overload;
  function ToRanges(const aAscending: Boolean): TRangeArray; overload;
  function Ranges: TRangeArray; overload;
  function Ranges(const aAscending: Boolean): TRangeArray; overload;
  function IsMonotonic: Boolean; overload;
  function Monotonicity: Boolean; overload;
  function Monotony: Boolean; overload;
  function Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
  function Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
  function Spanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function Splay(const index: Integer; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
  function Splay(const index: Integer; const limits: TRange; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
  function Trace(const index: Integer; const tolerance: Integer = 1): TRange; overload;
  function Trace(const index: Integer; const limits: TRange; const tolerance: Integer = 1): TRange; overload;
  function ExpandGradient(const index: Integer; const tolerance: Integer): TRange;
  function CountingSort(const aAscending: Boolean = True): Integer;
  function SegmentedCountingSort(const aAscending: Boolean = True; const bucketSize: Integer = 1024): Integer;
  function TernarySearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function TernaryPeak: Integer; overload;
  function TernaryValley: Integer; overload;
  function TernaryMountain: Integer; overload;
  function BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BSort(const aAscending: Boolean = True): Integer;
  function BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinarySort(const aAscending: Boolean = True): Integer;
  function BinarySorted(const aAscending: Boolean = True): TIntegerArray;
  function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
  function BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload;
  function BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
  function BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
  function BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean;
  function BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
  function BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange;
  function BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange;
  function BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray;
  function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
  function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
  function BinaryPrune(const aAscending: Boolean = True): Integer;
  function BinaryPruned(const aAscending: Boolean = True): TIntegerArray;
  function BinaryUndupe: Integer;
  function BinaryUnduped: TIntegerArray;
  function BinaryUnified(const dAscending: Boolean = True): TIntegerArray;
  function BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean;
  function BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean;
  function BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryLeftmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
  function BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryRightmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
  function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
  function BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload;
  function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
  function BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryRemove(const val: Integer; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
  function BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload;
  function BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload;
  function BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload;
  function BinaryDeduplicated(const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryUnduplicated(const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryUpdate(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload;
  function BinaryDelete(const x: Integer; const aAscending: Boolean = True): Boolean; overload;
  function BinaryReplace(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload;
  function BinaryReplaceAll(const oValue, nValue: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySinglify(const item: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySinglified(const item: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryLookup(const value: Integer): Integer; overload;
  function BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer; overload;
  function BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
  function BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
  function BinaryScan(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryScanned(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
  function BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryGrouped(const aAscending: Boolean = True): T2DIntegerArray; overload;
  function BinaryGroup(const aAscending: Boolean = True): T2DIntegerArray; overload;
  function BinaryGroups(const aAscending: Boolean = True): T2DIntegerArray; overload;
  function BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
  function BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
  function BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
  function BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryExists(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
  function BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
  function BinaryFit(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
  function BinaryUnfit(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
  function BinaryIncludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
  function BinaryExcludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
  function BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
  function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinaryUnique(const oAscending: Boolean = True): Integer; overload;
  function BinaryUniqued(const oAscending: Boolean = True): TIntegerArray; overload;
  function BinaryUniq(const oAscending: Boolean = True): Integer; overload;
  function BinaryUniqd(const oAscending: Boolean = True): TIntegerArray; overload;
  function BinaryExistent(const item: Integer; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Bounds: TRange; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i]
    else
      if (Self[i] > Result.stop) then
        Result.stop := Self[i];
end;

function TIntegerArrayHelper.Bounds(var aSize: Integer): TRange; overload;
begin
  case Self.Empty of
    False:
	begin
	  Result := Self.Bounds;
	  aSize := Result.Size;
	end;
    True:
    begin
      Result.Create(-2147483648, -2147483648);
      aSize := 0;
    end;
  end;
end;

{==============================================================================]
  <BRange>
  @action: Computes the minimal and maximal values in a TIntegerArray and
           returns them as a TRange record. start contains the minimum value,
           stop contains the maximum value.
  @note: - If the array is empty, the resulting TRange will be uninitialized.
         - If the array has only one element, start and stop will be equal.
         - Uses pointer-based iteration for efficiency.
[==============================================================================}
function TIntegerArrayHelper.BRange: TRange; overload;
var
  P, M: PInteger;
  L: Integer;
begin
  L := Self.Length;
  if (L > 0) then
  with Result do
  begin
    P := @Self[0];
    start := P^;
    stop := P^;
    if (L = 1) then
      Exit;
    M := @Self[0];
    Inc(M, L);
    repeat
      if (start > P^) then
        start := P^
      else if (stop < P^) then
        stop := P^;
      Inc(P);
    until (P = M);
  end;
end;

{==============================================================================]
  <BoundingRange>
  @action: Returns bounding range around TIntegerArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BoundingRange: TRange;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MinValue(Self), MaxValue(Self));
end;

{==============================================================================]
  <Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Boundaries: TRange;
  function BR(const arr: TIntegerArray; const L, R: Integer): TRange;
  var
    M: Integer;
  begin
    if (L = R) then
      Exit(Result.Create(arr[L], arr[L]));
    M := ((L + R) div 2);
    Result := BR(arr, L, M).Union(BR(arr, (M + 1), R));
  end;
begin
  if Self.Empty then
    Exit(Default(TRange));
  Result := BR(Self, 0, High(Self));
end;

{==============================================================================]
  <Range>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Range: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i in Self do
    Result.Create(Min(Result.start, i), Max(Result.stop, i));
end;

{==============================================================================]
  <Coverage>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Coverage: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i];
  for i := 1 to High(Self) do
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
end;

{==============================================================================]
  <MinMax>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.MinMax: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
  begin
    Result.start := Min(Result.start, Self[i]);
    Result.stop := Max(Result.stop, Self[i]);
  end;
end;

{==============================================================================]
  <Region>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Region: TRange; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MaxInt, -MaxInt);
  for i := 0 to High(Self) do
  begin
    if (Self[i] < Result.start) then
      Result.start := Self[i];
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
  end;
end;

{==============================================================================]
  <Extent>
  @action: Stores arr bounds to TRange.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Extent: TRange;
begin
  Result.Create(Self.MinItem, Self.MaxItem);
end;

{==============================================================================]
  <Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray;
begin
  Result := Self.Copy;
  TIA.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray;
var
  i, l: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  l := 0;
  if Self.Exists then
  begin
    SetLength(Result, Self.Size);
    r := Self.Bounds;
	b.Create(r.Size, False);
    for i := 0 to High(Self) do
      if b[Self[i] - r.start].Enable then
        Result[l.Increase] := Self[i];
    SetLength(b, 0);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Numberline>
  @action: Returns numberline of array arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Numberline: TIntegerArray;
var
  i, x, y: Integer;
  r: TRange;
begin
  y := High(Self);
  case y.Compare(0) of
    1:
    begin
      r.Create(Self[0], Self[0]);
      for x := 1 to y do
        if (Self[x] < r.start) then
          r.start := Self[x]
        else
          if (Self[x] > r.stop) then
            r.stop := Self[x];
      if (r.start <> r.stop) then
      begin
        SetLength(Result, r.Size);
        for i := r.start to r.stop do
          Result[i - r.start] := i;
      end else
        Result.Create(r.start);
    end;
    0: Result.Create(Self[0]);
    -1: SetLength(Result, 0);
  end;
end;

{==============================================================================]
 <Sum>
 @action: Returns the sum of all arr values together.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Sum: Int64;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
 <Density>
 @action: Returns the calculated density from given arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Density: Double;
var
  a: TIntegerArray;
  c, i, j: Integer;
  u: Boolean;
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  r.Create(Self[0], Self[0]);
  SetLength(a, Self.Size);
  c := 0;
  for i := 0 to High(Self) do
  begin
    r.Absorb(Self[i]);
    u := True;
    for j := 0 to (c - 1) do
      if (a[j] = Self[i]) then
      begin
        u := False;
        Break;
      end;
    if u then
      a[c.Increase] := Self[i];
  end;
  if (r.Size = 0) then
    Result := 0
  else
    Result := (c / r.Size);
end;

{==============================================================================]
 <Occupancy>
 @action: Returns the calculated density from given arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Occupancy: Double;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  Result := (Self.QuickSorted.Distinct / r.Construct(0, High(Self)).Size);
end;

{==============================================================================]
 <Saturated>
 @action: Returns the saturation of the integer array: fraction of the range
          covered by unique elements.
          0.0 = empty / no values, 1.0 = all possible values in range present.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Saturated: Double;
var
  m: specialize TFPGMap<Integer, Boolean>;
  i: Integer;
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  m := specialize TFPGMap<Integer, Boolean>.Create;
  r.Create(Self[0], Self[0]);
  try
    for i := 0 to High(Self) do
    begin
      r.Absorb(Self[i]);
      if (not m.IndexOf(Self[i]) >= 0) then
        m.Add(Self[i], True);
    end;
    if (r.Size = 0) then
      Result := 0.0
    else
      Result := (m.Count / r.Size);
  finally
    m.Free;
  end;
end;

{==============================================================================]
 <Mean>
 @action: The sum of all arr values divided by the length of arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Mean: Double;
begin
  Result := (Self.Sum / Self.Size);
end;

{==============================================================================]
 <Median>
 @action: The middle value when the arr is sorted:
          -Odd number of elements => the exact middle.
          -Even number => the average of the two middle elements.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Median: Double;
var
  a: TIntegerArray;
  i, j, n, s: Integer;
begin
  n := Self.Size;
  if (n = 0) then
    Exit(-2147483648);
  a := Self.Copy;
  for i := 0 to (n - 2) do
    if (a[i] > a[i + 1]) then
    begin
      for j := 0 to (n - 2) do
        for s := 0 to ((n - j) - 2) do
          if (a[s] > a[s + 1]) then
            Exchange(s, (s + 1));
      Break;
    end;
  if ((n mod 2) = 1) then
    Result := a[n div 2]
  else
    Result := ((a[(n div 2) - 1] + a[n div 2]) / 2);
end;

{==============================================================================]
 <Middle>
 @action: The value(s) at the center position(s) of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Middle: Double;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(-2147483648);
  if ((l mod 2) = 1) then
    Result := Self[l div 2]
  else
    Result := ((Self[(l div 2) - 1] + Self[l div 2]) / 2.0);
end;

{==============================================================================]
 <MostFreq>
 @action: Returns the most frequent/common value from arr.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.MostFreq(const null: Integer = -2147483648): Integer;
var
  h, x, t: Integer;
  b: TIntegerArray;
  r: TRange;
begin
  h := High(Self);
  case h.Compare(0) of
    1:
    begin
      r := Self.Bounds;
      b.Create(r.Size, 0);
      for x := 0 to h do
        Inc(b[Self[x] - r.start]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if (b[x] > b[t]) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := Self[0];
    -1: Result := null;
  end;
end;

{==============================================================================]
 <LeastFreq>
 @action: Returns the least frequent/common value from TIA.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.LeastFreq(const null: Integer = -2147483648): Integer;
var
  h, x, t: Integer;
  b: TIntegerArray;
  r: TRange;
begin
  h := High(Self);
  case h.Compare(0) of
    1:
    begin
      r := Self.Bounds;
      b.Create(r.Size, 0);
      for x := 0 to h do
        Inc(b[Self[x] - r.start]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if ((b[x] > 0) and (b[x] < b[t])) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := Self[0];
    -1: Result := null;
  end;
end;

{==============================================================================]
  <Succ>
  @action: Returns the next array index (currentIndex + 1).
  @note: If the next index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Succ(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  if ((Result > High(Self)) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <Pred>
  @action: Returns the previous array index (currentIndex - 1).
  @note: If the previous index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Pred(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := currentIndex - 1;
  if ((Result < 0) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <Successor>
  @action: Returns the next valid array index in the specified direction.
  @note: If aAscending = True, moves forward; if False, moves backward.
         Skips over elements considered missing by the range.
         Returns -1 if the end of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Successor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(1, -1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <Predecessor>
  @action: Returns the previous valid array index in the specified direction.
  @note: If aAscending = True, moves backward; if False, moves forward.
         Skips over elements considered missing by the range.
         Returns -1 if the beginning of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Predecessor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(-1, 1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <Next>
 @action: Returns the next valid array index by moving forward (incrementing).
  @note: Starts from currentIndex + 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the end of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Next(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  while ((Result <= High(Self)) and range.Missing(Self[Result])) do
    Inc(Result);
  if (Result > High(Self)) then
    Result := -1;
end;

{==============================================================================]
  <Previous>
  @action: Returns the previous valid array index by moving backward (decrementing).
  @note: Starts from currentIndex - 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the beginning of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Previous(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex - 1);
  while ((Result >= 0) and range.Missing(Self[Result])) do
    Dec(Result);
  if (Result < 0) then
    Result := -1;
end;

{==============================================================================]
  <Navigate>
  @action: Returns the next valid array index in the specified direction.
  @note: Starts from currentIndex and moves forward if aAscending = True,
         backward if aAscending = False. Skips over any elements that are
         considered missing according to the provided range.
         Returns -1 if no valid element exists before reaching the array bounds.
[==============================================================================}
function TIntegerArrayHelper.Navigate(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  s: Integer;
begin
  s := aAscending.Select(1, -1);
  Result := (currentIndex + s);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + s);
  if (Result < 0) or (Result > High(Self)) then
    Result := -1;
end;

{==============================================================================]
  <Advance>
  @action: Moves forward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the next value that falls
           within the specified range.
  @note: - Traverses one element at a time in the order defined by aAscending.
         - If the sequence order is broken (e.g., next value < previous in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the end of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Advance(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
    False:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
  end;
  Result := -1;
end;

{==============================================================================]
  <Retreat>
  @action: Moves backward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the previous value that falls
           within the specified range.
  @note: - Traverses one element at a time in reverse order, as defined by aAscending.
         - If the sequence order is broken (e.g., previous value > next in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the beginning of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Retreat(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
    False:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
  end;
  Result := -1;
end;  

{==============================================================================]
  <RadixSort>
  @action: RadixSort for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.RadixSort(const aAscending: Boolean = True): Integer;
var
  a, n: TIntegerArray;
  c: array[0..9] of Integer;
  x, y, i, j, m, e: Integer;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  SetLength(n, (Result + 1));
  SetLength(a, (Result + 1));
  x := 0;
  y := 0;
  for i := 0 to Result do
    if (Self[i] < 0) then
      n[x.Increase] := -Self[i]
    else
      a[y.Increase] := Self[i];
  SetLength(n, x);
  SetLength(a, y);
  if (x > 0) then
  begin
    m := n[0];
    for i := 1 to (x - 1) do
      if (n[i] > m) then
        m := n[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (x - 1) do
        Inc(c[(n[i] div e) mod 10]);
      for j := 8 downto 0 do
        c[j] := (c[j] + c[j + 1]);
      SetLength(Self, x);
      for i := (x - 1) downto 0 do
        Self[c[((n[i] div e) mod 10)].Decrement] := n[i];
      for i := 0 to (x - 1) do
        n[i] := Self[i];
      e := (e * 10);
    end;
    for i := 0 to (x - 1) do
      n[i] := -n[i];
  end;
  if (y > 0) then
  begin
    m := a[0];
    for i := 1 to (y - 1) do
      if (a[i] > m) then
        m := a[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (y - 1) do
        Inc(c[(a[i] div e) mod 10]);
      for j := 1 to 9 do
        c[j] := (c[j] + c[j - 1]);
      SetLength(Self, y);
      for i := (y - 1) downto 0 do
        Self[c[(a[i] div e) mod 10].Decrement] := a[i];
      for i := 0 to (y - 1) do
        a[i] := Self[i];
      e := (e * 10);
    end;
  end;
  if aAscending then
    Self := (n + a)
  else
    Self := (a.Reversed + n.Reversed);
end;

{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          for b := 0 to (l - 1) do
	  begin
	    m := ((Self[i] = Result[a][b]) or s.Value(Abs(Self[i] - Result[a][b])));
	    if not m then
              Continue;
	    SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
	  if m then
	    Break;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Split(0, diff);
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, a.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        l := Result[j].Length;
        for k := 0 to (l - 1) do
        begin
          m := ((a[i] = Result[j][k]) or s.Value(Abs(a[i] - Result[j][k])));
          if not m then
            Continue;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
	if m then
	  Break;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Sblit(0, diff);
end;

{==============================================================================]
  <Groups>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the ones with same values.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
var
  i, l, g: Integer;
  a: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  if not aSorted then
    a := Self.QuickSorted
  else
    a := Self.Copy;
  a.BinaryPrune;
  SetLength(Result, 0);
  SetLength(Result, a.Size);
  for i := 0 to High(Self) do
  begin
    g := a.BinarySearch(Self[i]);
    l := Result[g].Length;
    SetLength(Result[g], (l + 1));
    Result[g][l] := Self[i];
  end;
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
          if ((Self[i] = Result[a][0]) or s.Value(Abs(Self[i] - Result[a][0]))) then
          begin
            m := True;
            l := Result[a].Length;
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Group(0, diff);
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l: Integer;
  s: TRange;
  m: Boolean;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Self.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        if ((a[i] = Result[j][0]) or s.Value(Abs(a[i] - Result[j][0]))) then
        begin
          l := Result[j].Length;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          m := True;
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Groub(0, diff);
end;

{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Strict splitting!
[==============================================================================}
function TIntegerArrayHelper.Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          m := True;
          for b := 0 to (l - 1) do
            if ((Self[i] = Result[a][b]) or (not m)) then
              Break
            else
              m := s.Value(Abs(Self[i] - Result[a][b]));
          if m then
          begin
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Clique(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Clique(0, diff);
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, a.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        m := True;
        l := Result[j].Length;
        for k := 0 to (l - 1) do
          if ((a[i] = Result[j][k]) or (not m)) then
            Break
          else
            m := s.Value(Abs(a[i] - Result[j][k]));
        if m then
        begin
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Knit(0, diff);
end;

{==============================================================================]
  <Reflect>
  @action: Returns reversed array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reflected: TIntegerArray; overload;
var
  i: Integer;
  s: SizeInt;
begin
  SetLength(Result, Self.Size);
  s := SizeOf(Integer);
  for i := 0 to High(Self) do
    Move(Self[High(Self) - i], Result[i], s);
end;

{==============================================================================]
  <Reflect>
  @action: Reverses array.
  @note: Returns Length(Self)
[==============================================================================}
function TIntegerArrayHelper.Reflect: Integer; overload;
var
  r: TRange;
  s: SizeInt;
  b: array of Byte;
  x, y: PByte;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := SizeOf(Integer);
  SetLength(b, s);
  r.Create(-1, Result);
  x := PByte(@Self[r.start + 1]);
  y := PByte(@Self[r.stop - 1]);
  while (r.start.Increment < r.stop.Decrement) do
  begin
    Move(x^, b[0], s);
    Move(y^, x^, s);
    Move(b[0], y^, s);
    Inc(x, s);
    Dec(y, s);
  end;
end;

{==============================================================================]
  <Invert>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
[==============================================================================}
function TIntegerArrayHelper.Invert: TIntegerArray;
var
  c, l, i, x, r: Integer;
  b: TBooleanArray;
  a: TRange;
begin
  r := 0;
  if Self.Exists then
  begin
    a := Self.Bounds;
    if (a.start <> a.stop) then
    begin
      c := 0;
      l := a.Size;
      b.Create(l, False);
      for x := 0 to High(Self) do
        if b[Self[x] - a.start].Enable then
          Inc(c);
      SetLength(Result, (l - c));
      if (Result.Size > 0) then
      for i := 0 to (l - 1) do
        if not b[i] then
          Result[r.Increase] := (i + a.start);
      SetLength(b, 0);
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Inverted>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverted(const arrBounds: TRange): TIntegerArray; overload;
var
  i, r: Integer;
  b: TRange;
begin
  b := arrBounds.Normalize;
  SetLength(Result, b.Size);
  r := 0;
  for i := b.Start to b.Stop do
    if not Self.Contains(i) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

function TIntegerArrayHelper.Inverted: TIntegerArray; overload;
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <Inverse>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverse(const arrBounds: TRange): TIntegerArray; overload;
var
  l, i: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  r := arrBounds.Normalize;
  b.Create(arrBounds.Size, False);
  for i := 0 to High(Self) do
    if not ((Self[i] < r.start) or (Self[i] > r.stop)) then
      b[Self[i] - r.start] := True;
  l := 0;
  SetLength(Result, b.Size);
  for i := r.start to r.stop do
    if not b[i - r.start] then
      Result[l.Increase] := i;
  SetLength(Result, l);
end;

function TIntegerArrayHelper.Inverse: TIntegerArray; overload;
begin
  if (Self.Size > 1) then
    Result := Self.Inverse(Self.Bounds)
  else
    SetLength(Result, 0);
end;

{==============================================================================]
 <Mirror>
 @action: Mirrors arr
 @note: None.
[==============================================================================}
function TIntegerArrayHelper.Mirror: Boolean;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if not Result then
    Exit;
  i := -1;
  while (i.Increment < l.Decrement) do
  begin
    Self[i] := (Self[i] xor Self[l]);
    Self[l] := (Self[i] xor Self[l]);
    Self[i] := (Self[i] xor Self[l]);
  end;
end;

{==============================================================================]
  <Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean; overload; var a: TIntegerArray; {$DEFINE Skeleton_Pure}{$I Skeletons.inc}{$UNDEF Skeleton_Pure}

{==============================================================================]
  <Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Charify: TCharArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Chr(Self[i]);
end;

{==============================================================================]
  <Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores str version to variable.
[==============================================================================}
function TIntegerArrayHelper.Charify(var str: string): TCharArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  SetLength(str, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[i] := Chr(Self[i]);
    str[i + 1] := Result[i];
  end;
end;

{==============================================================================]
  <Stringify>
  @action: Converts TIntegerArray to string.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Stringify: string; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i + 1] := Chr(Self[i]);
end;

{==============================================================================]
  <Stringify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores charset version to variable.
[==============================================================================}
function TIntegerArrayHelper.Stringify(var chars: TCharArray): string; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  SetLength(chars, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[i + 1] := Chr(Self[i]);
    chars[i] := Result[i];
  end;
end;

{==============================================================================]
  <Special>
  @action: Returns true if parity of every pair of adjacent element differs each other.
  @note: An element in each pair must be even and other must be odd.
[==============================================================================}
function TIntegerArrayHelper.Special: Boolean;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i].Parity = Self[i - 1].Parity) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <ExtractEven>
  @action: Returns even values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterEven>
  @action: Returns array without even values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <ExtractOdd>
  @action: Returns odd values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterOdd>
  @action: Returns array without odd values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Integer)), 0);
end;

{==============================================================================]
  <Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Integer is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TIntegerArrayHelper.Attach(const items: TIntegerArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Integer)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another integer array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TIntegerArrayHelper.Embed(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Integer)));
  Move(items[0], Self[p], (l * SizeOf(Integer)));
  Result := Self.Size;
end;

{==============================================================================]
 <Broaden>
 @action: Expands outward from the specified starting index to find the
          contiguous range of indexes whose values are contained within
          the given numeric range (rValues).
 @note: Returns <-1..-1> if the array is empty, the starting index is invalid,
        or the value at the starting index is not within rValues.
        The returned TRange represents indexes in the array, not values.
[==============================================================================}
function TIntegerArrayHelper.Broaden(const rValues: TRange; const aIndex: Integer): TRange; overload;
var
  i: Integer;
begin
  if (Self.Empty or (not InRange(aIndex, 0, High(Self))) or (not rValues.Contains(Self[aIndex]))) then
    Exit(TRange.Construct(-1, -1));
  Result.Create(aIndex);
  for i := (aIndex - 1) downto 0 do
    if rValues.Contains(Self[i]) then
      Result.start := i
    else
      Break;
  for i := (aIndex + 1) to High(Self) do
    if rValues.Contains(Self[i]) then
      Result.stop := i
    else
      Break;
end;

{==============================================================================]
 <Broaden>
 @action: Searches the array for the first element contained within rValues
          and returns the contiguous range of indexes around it that are
          also within rValues. Supports optimized search if the array is
          sorted.
 @note: Returns <-1..-1> if the array is empty or no elements match rValues.
        If sSorted is True, performs a binary search for each value in the
        numeric range; if False, performs a linear search. The returned
        TRange represents indexes in the array, not values.
[==============================================================================}
function TIntegerArrayHelper.Broaden(const rValues: TRange; const sSorted: Boolean = False): TRange; overload;
var
  a: Boolean;
  i, p: Integer;
begin
  if not Self.Empty then
  case sSorted of
    True:
    begin
      a := Self.TrendRising;
      for i := rValues.Minimum to rValues.Maximum do
      begin
        p := Self.BinarySearch(i, a);
        if (p > -1) then
          Exit(Self.Broaden(rValues, p));
      end;
    end;
    False:
    for i := 0 to High(Self) do
      if rValues.Contains(Self[i]) then
        Exit(Self.Broaden(rValues, i));
  end;
  Result.Create(-1);
end;

{==============================================================================]
  <ToRanges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray).
           Each range represents a sequence of consecutive numbers (ascending or descending)
           found in the array. A new range starts whenever the consecutive trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - Single-element arrays produce a single range with identical Start and Stop.
         - Two-element arrays produce a single range covering the two values.
         - Direction of each range (ascending or descending) is determined automatically.
         - Useful for compressing sequences or detecting consecutive runs in arrays.
[==============================================================================}
function TIntegerArrayHelper.ToRanges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  for i := 2 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i]);
      end;
    end;
  end;
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <ToRanges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction as indicated by aAscending.
           Each range extends in the requested direction until a break occurs.
  @note: - If aAscending = True, only ascending sequences (+1) are allowed in a range.
         - If aAscending = False, only descending sequences (-1) are allowed in a range.
         - Sequences that match the specified direction or repeat the same value
           are merged into the same range.
         - Returns empty array for empty input and single-element array produces
           a single-element range.
         - Useful when you want ranges restricted to a specific direction.
[==============================================================================}
function TIntegerArrayHelper.ToRanges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  for i := 1 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  end;
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <Ranges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray)
           using overlapping ranges. Each range represents a sequence of consecutive
           integers (ascending or descending) in the array. A new range starts from
           the previous range’s stop whenever the sequence trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - If the array has one element, the range has Start = Stop.
         - If the array has two elements, the range covers both values.
         - The direction (ascending/descending) is determined automatically.
         - Overlapping ensures that each new range starts from the last stop.
         - Useful for compressing sequences or detecting consecutive runs.
[==============================================================================}
function TIntegerArrayHelper.Ranges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  i := 2;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i.Decrement]);
      end;
    end;
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <Ranges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction (ascending or descending) using overlapping ranges.
           Each range starts from the previous range’s stop and continues in the
           specified direction until the trend breaks.
  @note: - If aAscending = True, ranges only include ascending steps.
         - If aAscending = False, ranges only include descending steps.
         - Repeated values (0 sign) are included in the same range.
         - Returns empty array for empty input; single-element arrays produce
           a single-element range.
         - Useful for generating directional ranges with overlaps.
[==============================================================================}
function TIntegerArrayHelper.Ranges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  i := 1;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <IsMonotonic>
  @action: Returns True if the array elements are monotonic (entirely non-decreasing or non-increasing).
  @note: Works for empty and single-element arrays (they are trivially monotonic).
[==============================================================================}
function TIntegerArrayHelper.IsMonotonic: Boolean; overload;
var
  c, i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (c > 0) then
      D := False
    else
      if (c < 0) then
        A := False;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <Monotonicity>
  @action:
    Determines whether the array is monotonic — that is, whether all its
    elements are entirely non-decreasing or entirely non-increasing.

    The function compares each element with the previous one, establishing
    a direction based on the first non-equal pair. If any subsequent element
    violates this direction, the function immediately returns False.
  @note:
    • Empty or single-element arrays are considered monotonic (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses Sign(A - B) to determine the direction between consecutive elements.
    • Short-circuits for efficiency — exits as soon as a violation is detected.
[==============================================================================}
function TIntegerArrayHelper.Monotonicity: Boolean; overload;
var
  s, d, i: Integer;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    if (s = 0) then
      Continue;
    if (d = 0) then
      d := s
    else if (s <> d) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Monotony>
    Determines whether the array is monotone (entirely non-decreasing or 
    entirely non-increasing).
  @note:
    • Empty or single-element arrays are considered monotone (trivially True).  
    • Equal adjacent elements do not affect monotonicity.  
    • Uses Sign(A - B) from Math to compute relative order.  
    • Short-circuits for efficiency — exits as soon as a reversal is detected.  
    • This version differs from the “direction-lock” version by using an
      accumulated trend variable instead of separate Booleans for ascending
      and descending.
[==============================================================================}
function TIntegerArrayHelper.Monotony: Boolean; overload;
var
  i, t, s: Integer;
begin
  t := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    t := (t or s);
    if (((t = 1) and (s = -1)) or ((t = -1) and (s = 1))) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Fuse>
  @action: Merge the contents of Self with the given items array using a standard merge-operation.
           Both arrays must already be sorted in the order specified by oAscending.
           The function produces a single sorted array containing all elements,
           from both sources, preserving duplicates. The merged result
           replaces Self and the final length of the array is returned.
  @note: - Both Self and items must be pre-sorted in the same ordering; the routine
           does not perform any sorting beyond the merge step.
         - All values from Self and items are preserved; no deduplication occurs.
         - The resulting array is always sorted according to oAscending.
         - Operation runs in O(n + m) time and allocates temporary storage equal to
           the length of Self.
         - The merge preserves element stability with respect to the original Self
           and items ordering.
[==============================================================================}
function TIntegerArrayHelper.Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  l, a, i, j, k: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  a := items.Size;
  Result := (l + a);
  if (a = 0) then
    Exit;
  if (l = 0) then
  begin
    Self := items.Copy;
    Exit;
  end;
  s := Self.Copy;
  SetLength(Self, Result);
  i := 0;
  j := 0;
  k := 0;
  case oAscending of
    True:
    while ((i < l) and (j < a)) do
      if (s[i] <= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
    False:
    while ((i < l) and (j < a)) do
      if (s[i] >= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
  end;
  while (i < l) do
    Self[k.Increase] := s[i.Increase];
  while (j < a) do
    Self[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <Combinate>
  @action:  Merges the contents of Self and items into a single sorted array and removes
            duplicate values during the merge. The merge preserves the specified ordering
            (ascending or descending) and guarantees that the resulting array contains only
            unique values in correct sorted order.
  @note: Combine & Unduplicate
[==============================================================================}
function TIntegerArrayHelper.Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  s: TIntegerArray;
  l, a, i, j, k, v, c: Integer;
begin
  l := Self.Length;
  a := items.Size;
  if ((l = 0) and (a = 0)) then
  begin
    SetLength(Self, 0);
    Exit(0);
  end;
  s := Self.Copy;
  SetLength(Self, (l + a));
  i := 0;
  j := 0;
  k := 0;
  v := IfThen(oAscending, 2147483647, -2147483648);
  while ((i < l) or (j < a)) do
  begin
    c := 0;
    case oAscending of
      True:
      if ((i < l) and ((j >= a) or (s[i] <= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
      False:
      if ((i < l) and ((j >= a) or (s[i] >= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
    end;
    if ((k = 0) or (c <> v)) then
    begin
      Self[k.Increase] := c;
      v := c;
    end;
  end;
  if (k <> Self.Size) then
    SetLength(Self, k);
  Result := k;
end;

{==============================================================================]
  <Spanning>
  @action: Searches the integer array for elements that fall within the specified
           `range` and returns a TRange representing the inclusive index span of
           matching elements. Supports both ascending and descending arrays via
           the `oAscending` parameter. If the array is empty or no elements match
           the range, returns a sentinel TRange with both `start` and `stop` set
           to Low(Integer).
  @note:
    - The input `range` is normalized first using Normalize, ensuring
      that `range.start <= range.stop`.
    - `oAscending` specifies the sort order of the array:
        - True → ascending order
        - False → descending order
    - Scans from both ends:
        - `Result.start` increments from the beginning until the first element
          within the range is found.
        - `Result.stop` decrements from the end until the last element within the
          range is found.
    - Returns:
        - `Result.start <= Result.stop` → span found; inclusive index range of elements.
        - `Result.start > Result.stop` → no elements in range; sentinel range returned.
    - Works with negative numbers and handles both ascending and descending arrays.
[==============================================================================}
function TIntegerArrayHelper.Spanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(TRange.Construct(Low(Integer), Low(Integer)));
  r := range.Normalize;
  Result.Create(0, High(Self));
  while ((Result.start < Result.stop) and ((oAscending and (Self[Result.start] < r.start)) or ((not oAscending) and (Self[Result.start] > r.stop)))) do
    Inc(Result.start);
  while ((Result.stop >= Result.start) and ((oAscending and (Self[Result.stop] > r.stop)) or ((not oAscending) and (Self[Result.stop] < r.start)))) do
    Dec(Result.stop);
  if (Result.start > Result.stop) then
    Result.Create(Low(Integer));
end;

{==============================================================================]
  <Splay>
  @action: Expands from the given `index` to include all adjacent elements within
           `tolerance` of the value at arr[index]. Returns a TRange with the
           start and stop indices of all qualifying elements.
  @note: The array must be sorted according to `oAscending`. The expansion is
         contiguous - it stops at the first element outside the tolerance range.
         Time complexity is O(k) where k is the size of the resulting range.
  @example: arr=[10,12,13,15,20,25], index=1 (value 12), tolerance=3
            → expands to include 10,12,13,15 → range(0,3)
[==============================================================================}
function TIntegerArrayHelper.Splay(const index: Integer; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
var
  H: Integer;
  m: TRange;
begin
  H := High(Self);
  if ((index < 0) or (index > H) or (tolerance < 0)) then
    Exit(TRange.Construct(-1, -1));
  m.Create((Self[index] - tolerance), (Self[index] + tolerance));
  Result.Create(index);
  case oAscending of
    True:
    begin
      while ((Result.start > 0) and (Self[Result.start - 1] >= m.start)) do
        Dec(Result.start);
      while ((Result.stop < H) and (Self[Result.stop + 1] <= m.stop)) do
        Inc(Result.stop);
    end;
    False:
    begin
      while (Result.start > 0) and (Self[Result.start - 1] <= m.stop) do
        Dec(Result.start);
      while (Result.stop < High(Self)) and (Self[Result.stop + 1] >= m.start) do
        Inc(Result.stop);
    end;
  end;
end;

{==============================================================================]
  <Splay>
  @action: Expands from the given `index` to include all adjacent elements within
           `tolerance` of the value at arr[index], constrained by `limits`.
           Returns a TRange with the start and stop indices of all qualifying
           elements within the specified index bounds.
  @note: The array must be sorted according to `oAscending`. The expansion is
         contiguous and stops at the first element outside the tolerance range
         or when reaching the limit boundaries. Time complexity is O(k) where
         k is the size of the resulting range.
  @param limits: TRange specifying the index boundaries (start and stop) within
                 which to perform the expansion. Expansion will not go beyond
                 these index limits.
  @example: arr=[10,12,13,15,20,25,30], index=2 (value 13), limits=(1,5), tol=3
            → expands within indices 1-5 to include 12,13,15 → range(1,3)
            (stops at 20 even though in tolerance, due to index limit at 5)
[==============================================================================}
function TIntegerArrayHelper.Splay(const index: Integer; const limits: TRange; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
var
  m, r: TRange;
begin
  r.start := Max(0, Min(limits.start, limits.stop));
  r.stop := Min(High(Self), Max(limits.start, limits.stop));
  if ((tolerance < 0) or (index < r.start) or (index > r.stop)) then
    Exit(TRange.Construct(-1, -1));
  m.Create((Self[index] - tolerance), (Self[index] + tolerance));
  Result.Create(index);
  case oAscending of
    True:
    begin
      while ((Result.start > r.start) and (Self[Result.start - 1] >= m.start)) do
        Dec(Result.start);
      while (Result.stop < r.stop) and (Self[Result.stop + 1] <= m.stop) do
        Inc(Result.stop);
    end;
    False:
    begin
      while (Result.start > r.start) and (Self[Result.start - 1] <= m.stop) do
        Dec(Result.start);
      while (Result.stop < r.stop) and (Self[Result.stop + 1] >= m.start) do
        Inc(Result.stop);
    end;
  end;
end;

{==============================================================================]
  <Trace>
  @action: Expands from `index` while adjacent elements differ by at most
           `tolerance` from their immediate neighbor. Creates a "smooth" range
           where no two consecutive elements have a gap larger than tolerance.
  @note: This creates contiguous ranges where the
         step between each pair is ≤ tolerance. Unlike absolute tolerance,
         this allows gradual drift across the range.
  @example: arr=[10,12,14,16,25,27,29], index=2, tolerance=3
            → includes 10,12,14,16 (each step ≤3), stops at 25 (gap of 9)
            → range(0,3)
[==============================================================================}
function TIntegerArrayHelper.Trace(const index: Integer; const tolerance: Integer = 1): TRange; overload;
var
  H: Integer;
begin
  H := High(Self);
  if ((index < 0) or (index > H) or (tolerance < 0)) then
    Exit(TRange.Construct(-1, -1));
  Result.Create(index);
  while (Result.start > 0) do
    if (Abs(Self[Result.start] - Self[Result.start - 1]) <= tolerance) then
      Dec(Result.start)
    else
      Break;
  while (Result.stop < H) do
    if (Abs(Self[Result.stop + 1] - Self[Result.stop]) <= tolerance) then
      Inc(Result.stop)
    else
      Break;
end;

{==============================================================================]
  <Trace>
  @action: Expands from `index` while adjacent elements differ by at most
           `tolerance`, constrained by `limits`. Creates a "smooth" range
           where no two consecutive elements have a gap larger than tolerance.
  @note: Expansion is constrained within the index
         boundaries specified by `limits`. Time complexity is O(k) where k
         is the size of the resulting range.
  @param limits: TRange specifying the index boundaries (start and stop) within
                 which to perform the expansion.
  @example: arr=[10,12,14,16,25,27], index=2, tolerance=3, limits=(0,4)
            → includes 10,12,14,16 (each step ≤3), stops at index 4 due to limit
[==============================================================================}
function TIntegerArrayHelper.Trace(const index: Integer; const limits: TRange; const tolerance: Integer = 1): TRange; overload;
var
  m: TRange;
begin
  m.Create(Max(0, Min(limits.start, limits.stop)), Min(High(Self), Max(limits.start, limits.stop)));
  if ((tolerance < 0) or (index < m.start) or (index > m.stop)) then
    Exit(TRange.Construct(-1, -1));
  Result.Create(index);
  while (Result.start > m.start) do
    if (Abs(Self[Result.start] - Self[Result.start - 1]) <= tolerance) then
      Dec(Result.start)
    else
      Break;
  while (Result.stop < m.stop) do
    if (Abs(Self[Result.stop + 1] - Self[Result.stop]) <= tolerance) then
      Inc(Result.stop)
    else
      Break;
end;

{==============================================================================]
  <ExpandGradient>
  @action: Expands from `index` while the rate of change (gradient) between
           consecutive elements stays within `tolerance`. Useful for finding
           regions with similar slope.
  @note: For sorted arrays, this finds ranges where values increase/decrease
         at a consistent rate. Tolerance represents maximum allowed change in
         gradient (second derivative).
  @example: arr=[10,12,14,16,20,25,31], index=2, tolerance=1
            → gradient changes: 2,2,2,4,5,6 → stops when gradient jumps by >1
[==============================================================================}
function TIntegerArrayHelper.ExpandGradient(const index: Integer; const tolerance: Integer): TRange;
var
  H: Integer;
  B, C: Integer;
begin
  Result.start := -1;
  Result.stop := -1;
  H := High(Self);
  if ((index < 0) or (index > H) or (tolerance < 0)) then
    Exit(TRange.Construct(-1, -1));
  if (H < 1) then
    Exit(TRange.Construct(index, index));
  Result.start := index;
  Result.stop := index;
  if (index > 0) then
    B := Abs(Self[index] - Self[index - 1])
  else if (index < High(Self)) then
    B := Abs(Self[index + 1] - Self[index])
  else
    B := 0;
  while (Result.start > 1) do
  begin
    C := Abs(Self[Result.start] - Self[Result.start - 1]);
    if (Abs(C - B) > tolerance) then
      Break;
    Dec(Result.start);
    B := C;
  end;
  if (index < H) then
    B := Abs(Self[index + 1] - Self[index])
  else if (index > 0) then
    B := Abs(Self[index] - Self[index - 1]);
  while (Result.stop < (H - 1)) do
  begin
    C := Abs(Self[Result.stop + 1] - Self[Result.stop]);
    if (Abs(C - B) > tolerance) then
      Break;
    Inc(Result.stop);
    B := C;
  end;
end;

{==============================================================================]
  <CountingSort>
  @action: Sorts the integer array using the classical counting sort algorithm.
           Works efficiently when the range of integer values is relatively small.
  @note: 
    - This method handles negative and positive integers.
    - The algorithm counts the occurrences of each integer and writes them back
      in sorted order.
    - Always sorts in ascending order; descending order is not supported in this version.
    - Counting array size is based on the range of values in the array, so large
      ranges may use significant memory.
[==============================================================================}
function TIntegerArrayHelper.CountingSort(const aAscending: Boolean = True): Integer;
var
  c: TIntegerArray;
  i, j, s, o: Integer;
  m: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  o := -m.start;
  SetLength(c, m.Size);
  for i := 0 to High(Self) do
    Inc(c[Self[i] + o]);
  s := 0;
  for i := 0 to m.Span do
    for j := 1 to c[i] do
      Self[s.Increase] := (i - o);
  if not aAscending then
    Self.Reverse;
end;

{==============================================================================]
 <SegmentedCountingSort>
 @action: Performs a counting sort over the integer array using a small
          bucket-based approach. Supports ascending or descending order.
 @note:   Returns the number of elements in the array (Length(Self)).
          Sorting is done in-place using an auxiliary array.
          Efficient for moderate-sized integer ranges with many repeated values.
[==============================================================================}
function TIntegerArrayHelper.SegmentedCountingSort(const aAscending: Boolean = True; const bucketSize: Integer = 1024): Integer;
var
  i, l: Integer;
  c, s: TIntegerArray;
  m, r: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  SetLength(s, Self.Size);
  l := 0;
  if aAscending then
  begin
    r.start := m.start;
    while (r.start <= m.stop) do
    begin
      r.stop := Integer((r.start + bucketSize) - 1).ClampMax(m.stop);
      SetLength(c, ((r.stop - r.start) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.start) and (Self[i] <= r.stop) then
          Inc(c[Self[i] - r.start]);
      for i := 0 to High(c) do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.start + i);
      Inc(r.start, bucketSize);
    end;
  end
  else
  begin
    r.start := m.stop;
    while (r.start >= m.start) do
    begin
      r.stop := Integer((r.start - bucketSize) + 1).ClampMin(m.start);
      SetLength(c, ((r.start - r.stop) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.stop) and (Self[i] <= r.start) then
          Inc(c[Self[i] - r.stop]);
      for i := High(c) downto 0 do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.stop + i);
      Dec(r.start, bucketSize);
    end;
  end;
  for i := 0 to High(Self) do
    Self[i] := s[i];
end;

{==============================================================================]
  <TernarySearch>
  @action: Performs a ternary search over the array to locate the specified value.
           The routine splits the current search interval into three segments,
           compares the target value against the two internal partition points,
           and repeatedly narrows the interval until the value is found or the range is exhausted.

  @note: Requires the array to be pre-sorted in either ascending or descending order depending on oAscending.
         Returns the index of the matching element when found; otherwise returns -1.
         This implementation executes in logarithmic time relative to array length,
         but is generally not faster than binary search in practical scenarios due to the additional comparisons.
[==============================================================================}
function TIntegerArrayHelper.TernarySearch(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_TernarySearch}{$I Skeletons.inc}{$UNDEF Skeleton_TernarySearch}

{==============================================================================]
  <TernaryPeak>
  @action: Performs a ternary-search-style scan to locate a single local maximum.
  @note: The algorithm attempts to find any valid local maximum with
         sublinear search behavior by iteratively narrowing the search
         interval. Edge maxima are detected up front. If no valid local
         maximum exists in the interior segment, the function returns -1.
         The method guarantees O(log n) probe behavior in the expected case
         but completes with a linear fallback scan when necessary.
[==============================================================================}
function TIntegerArrayHelper.TernaryPeak: Integer; overload; {$DEFINE Skeleton_TernaryPeak}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryPeak}

{==============================================================================]
  <TernaryValley>
  @action: Performs a ternary-search-style scan to locate a single local minimum.
  @note: The algorithm mirrors the logic used in TernaryPeak but inverts
         all comparisons to detect a valley rather than a peak. Edge
         minima are tested first. If no valid local minimum exists in the
         narrowed search interval, the function returns -1. Expected
         complexity is O(log n) with a linear fallback validation.
[==============================================================================}
function TIntegerArrayHelper.TernaryValley: Integer; overload; {$DEFINE Skeleton_TernaryValley}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryValley}

{==============================================================================]
  <TernaryMountain>
  @action: Identifies an index at or near the global maximum by using a
           ternary-search-inspired unimodal search.
  @note: Assumes the array can be treated as unimodal (first rising,
         eventually falling). The method contracts the search range by
         comparing values at symmetric trisection points. No explicit
         local-maximum validation is performed; the algorithm simply
         converges to the region containing the highest value encountered.
         Returns the index of the final converged position.
[==============================================================================}
function TIntegerArrayHelper.TernaryMountain: Integer; overload; {$DEFINE Skeleton_TernaryMountain}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryMountain}

{==============================================================================]
  <BSearch>
  @action: Performs a binary search on the current integer array using a 
           branchless, arithmetic-driven search strategy. The routine locates 
           the index of a target value within a sorted array, supporting both 
           ascending and descending order based on the supplied flag.
  @note: This implementation uses mask-based comparisons and branchless 
         interval updates to avoid data-dependent branching. It is designed 
         to provide predictable control flow and consistent performance 
         regardless of input distribution. The function returns the index of 
         one matching element if the value is present; otherwise, it returns 
         -1. The input array must be pre-sorted in the specified order.
[==============================================================================}
function TIntegerArrayHelper.BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, C, D, F: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  F := Ord(not oAscending);
  while (R.start <= R.stop) do
  begin
    M := ((R.start + R.stop) shr 1);
    C := (Self[M] - value);
    Result.Increase(Integer((((UInt32(C) or UInt32(-C)) shr 31) xor 1) and 1) * (M - Result));
    D := (Integer(UInt32(C) shr 31) xor F);
    R.start := (R.start + (D * ((M + 1) - R.start)));
    R.stop := (R.stop - ((1 - D) * (R.stop - (M - 1))));
  end;
end;

{==============================================================================]
  <BMerge>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  i.Create(0, items.Size);
  s.Create(0, Self.Size);
  SetLength(Result, (i.stop + s.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BMerged>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BSort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BSort}{$I Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BinarySort}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const aAscending: Boolean = True): TIntegerArray; var a: Integer; {$DEFINE Skeleton_BinarySorted}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given value in the array.
  @note: Returns the index of the first element greater than or equal to the value for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundLeft}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundLeft}

{==============================================================================]
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given value in the array.
  @note: Returns the index of the first element strictly greater than the value for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundRight}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundRight}

{==============================================================================]
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPos}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPos}

{==============================================================================]
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload; var C: Integer; {$DEFINE Skeleton_BinaryPosOf}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosOf}

{==============================================================================]
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPosition}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosition}

function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}
function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}

{==============================================================================]
  <BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <BinarySearch>
  @action: Searches the integer array for any element whose value falls within the specified range.
           The search is performed using a binary-search strategy based on the assumption that the array is sorted either ascending or descending.
           If an element within the range is found, its index is returned; otherwise, the function returns –1.

  @note: The routine returns the index of the first matching element encountered during the binary-search traversal,
         not necessarily the lowest or highest index satisfying the range.
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  r, s: TRange;
begin
  if Self.Empty then
    Exit(-1);
  r := x.Normalize;
  s.Create(0, High(Self));
  if TRange.Construct(Self[0], Self[s.stop]).Contains(r) then
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    if InRange(Self[M], r.start, r.stop) then
      Exit(M);
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.start <= Self[M]))) then
      s.stop := (M - 1)
    else
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySeek>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <BinaryContains>
  @action: Binary Contains function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryContains}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

function TIntegerArrayHelper.BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0);
  r := x.Normalize;
  Result := Self.BinaryLeftmost(r, aAscending);
  if (Result > -1) then
    Result := ((Self.BinaryRightmost(r, aAscending) - Result) + 1)
  else
    Result := 0;
end;

{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryAppend}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; {$DEFINE Skeleton_BinaryAdd}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPrune}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPrune}

{==============================================================================]
  <BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPruned(const aAscending: Boolean = True): TIntegerArray; {$DEFINE Skeleton_BinaryPruned}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPruned}

{==============================================================================]
  <BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUndupe: Integer; var u: TIntegerArray; {$DEFINE Skeleton_BinaryUndupe}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduped: TIntegerArray; {$DEFINE Skeleton_BinaryUnduped}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <BinaryUnified>
  @action: Binary Search-based Unified method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUnified(const dAscending: Boolean = True): TIntegerArray; var u: TIntegerArray; {$DEFINE Skeleton_BinaryUnified}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnified}

{==============================================================================]
  <BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryGrow}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryShrink}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note: 
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerBound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note: 
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUpperBound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note: 
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TIntegerArrayHelper.BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRightmost}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRightmost}

{==============================================================================]
  <BinarySearch>
  @action: Searches the integer array for the last (highest-index) element whose value lies within the specified range.
           The operation uses a binary-search strategy based on the assumption that the array is sorted either ascending or descending.
           If a matching element is found, the index of the latest such occurrence is returned; otherwise the function returns –1.
  @note: After detecting any in-range element, the routine performs a forward scan to reach the final contiguous match.
[==============================================================================}
function TIntegerArrayHelper.BinaryRightmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  r, s: TRange;
begin
  if Self.Empty then
    Exit(-1);
  r := x.Normalize;
  s.Create(0, High(Self));
  if TRange.Construct(Self[0], Self[s.stop]).Contains(r) then
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    if InRange(Self[M], r.start, r.stop) then
    begin
      while ((M < s.stop) and InRange(Self[M + 1], r.start, r.stop)) do
        Inc(M);
      Exit(M);
    end;
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note: 
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLeftmost}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLeftmost}

{==============================================================================]
  <BinaryLeftmost>
  @action: Searches the integer array for the first (lowest-index) element whose value lies within the specified range.
           The search uses a binary-search strategy under the assumption that the array is sorted either ascending or descending.
           If a matching element is found, the index of the earliest such occurrence is returned; otherwise the function returns –1.
  @note: After locating any in-range element, the routine performs a backward scan to reach the earliest contiguous match.
[==============================================================================}
function TIntegerArrayHelper.BinaryLeftmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  r, s: TRange;
begin
  if Self.Empty then
    Exit(-1);
  r := x.Normalize;
  s.Create(0, High(Self));
  if TRange.Construct(Self[0], Self[s.stop]).Contains(r) then
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    if InRange(Self[M], r.start, r.stop) then
    begin
      while ((M > 0) and InRange(Self[M - 1], r.start, r.stop)) do
        Dec(M);
      Exit(M);
    end;
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <BinarySpan>
  @action: Performs a binary search on a sorted integer array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TIntegerArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

{==============================================================================]
  <BinaryMerge>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

{==============================================================================]
  <BinaryMerged>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

{==============================================================================]
  <BinaryCombine>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted integer array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TIntegerArrayHelper.BinaryRemove(const val: Integer; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRemove}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRemove}

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search on a sorted integer array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <BinarySearchEx>
  @action: Performs a binary search on a sorted integer array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <BinaryInsert>
  @action: Insert an integer into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TIntegerArrayHelper.BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryInsert}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsert}

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

{==============================================================================]
  <BinaryDeduplicate>
  @action: Rebuilds the array in place by removing duplicate elements using binary search.
  @note: Creates a temporary copy of the original array and appends only unique values back.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending according to aAscending).
         Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload; var u: TIntegerArray; {$DEFINE Skeleton_BinaryDeduplicate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicate}

{==============================================================================]
  <BinaryUnduplicate>
  @action: Removes duplicate elements from the array in place using binary search.
  @note: Keeps only the first occurrence of each unique value.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending as specified).
         Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnduplicate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicate}

{==============================================================================]
  <BinaryDeduplicated>
  @action: Return a new array containing unique elements from the current one.
  @note: The original array remains unchanged.
         Uses binary search to avoid inserting duplicates.
         Sorting is recommended before calling for best results.
[==============================================================================}
function TIntegerArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryDeduplicated}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicated}

{==============================================================================]
  <BinaryUnduplicated>
  @action: Return a deduplicated copy of the current array using in-place logic.
  @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
         Requires sorted input for correct results.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryUnduplicated}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function TIntegerArrayHelper.BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}

{==============================================================================]
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TIntegerArrayHelper.BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
  <BinaryUpdate>
  @action: Updates the first occurrence of an element in the sorted array.
  @note: Searches for old_value using binary search. If found, replaces it with new_value.
         Returns True if updated, False if the value was not found.
         After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TIntegerArrayHelper.BinaryUpdate(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUpdate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUpdate}

{==============================================================================]
  <BinaryDelete>
  @action: Removes the first occurrence of a specific value from a sorted array.
  @note: Uses binary search to locate the target efficiently.
         Returns True if the value was found and deleted, otherwise False.
         Works for ascending or descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryDelete(const x: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryDelete}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDelete}

{==============================================================================]
  <BinaryReplace>
  @action: Replaces a specific value in a sorted array with a new one.
  @note: Uses binary search to locate and delete the old value,
         then reinserts the new one while maintaining sorted order.
         Returns True if the old value was found and replaced, otherwise False.
         Complexity: O(log n + n)
[==============================================================================}
function TIntegerArrayHelper.BinaryReplace(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryReplace}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryReplace}

{==============================================================================]
  <BinaryReplaceAll>
  @action: Replaces all occurrences of a specified value (oValue) with another
           value (nValue) in the array, preserving binary order if necessary.
  @note: Returns the number of replacements performed. If any substitution
         breaks sorted order, the array is re-sorted automatically using
         BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryReplaceAll(const oValue, nValue: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryReplaceAll}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryReplaceAll}

{==============================================================================]
  <BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function TIntegerArrayHelper.BinarySinglify(const item: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySinglify}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySinglify}

{==============================================================================]
  <BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function TIntegerArrayHelper.BinarySinglified(const item: Integer; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinarySinglified}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySinglified}

{==============================================================================]
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified integer value within
           a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TIntegerArrayHelper.BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryLookup(const value: Integer): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

{==============================================================================]
  <BinaryInterpolationSearch>
  @action: Performs an interpolation search on a sorted integer array to find the index of a given value.
  @note: This algorithm estimates the probable position of the target using linear interpolation
         between the low and high bounds, resulting in faster performance than binary search
         for uniformly distributed data. Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    case aAscending of
	  True:
      begin
        if ((x < Self[L]) or (x > Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((x - Self[L]) * (H - L)) div (Self[H] - Self[L]));
      end;
      False:
      begin
        if ((x > Self[L]) or (x < Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((Self[L] - x) * (H - L)) div (Self[L] - Self[H]));
      end;
    end;
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryProbabilisticSearch>
  @action: Performs a probabilistic variant of binary interpolation search, introducing a random bias
           to the estimated midpoint to improve robustness on non-uniform or noisy data.
  @note: The optional `bias` parameter (default = 0.0) adjusts how much random variation is applied
         to the interpolation estimate. A small bias can prevent worst-case patterns and clustering effects.
         Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    if (Self[L] = Self[H]) then
	  M := ((L + H) div 2)
    else
      if aAscending then
        M := (L + Trunc(EnsureRange((((x - Self[L]) / (Self[H] - Self[L])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)))
      else
        M := (L + Trunc(EnsureRange((((Self[L] - x) / (Self[L] - Self[H])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)));
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;

function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
begin
  Result := Self.BinaryProbabilisticSearch(x, bias, aAscending);
end;

{==============================================================================]
  <BinaryPinpoint>
  @action: Finds the index of the element closest in value to the specified integer.
  @note: - The array must be sorted in ascending or descending order as specified by aAscending.
         - Returns the index of the exact match if found, otherwise the index of the nearest element
           by absolute distance to x.
         - Runs in O(log n) time using BinaryRank to locate the insertion position and then compares
           adjacent elements to choose the closest one.
[==============================================================================}
function TIntegerArrayHelper.BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
var
  H, D: Integer;
begin
  H := High(Self);
  case H of
    -1: Exit(-1);
    0: Exit(0);
  end;
  Result := Self.BinaryRank(x, aAscending);
  if (Result > H) then
    Exit(H);
  if (Result < 0) then
    Exit(0);
  if (Self[Result] = x) then
    Exit;
  D := x.Distance(Self[Result]);
  if (Result = 0) then
     Exit(IfThen((D < x.Distance(Self[Result + 1])), Result, (Result + 1)));
  if (Result = H) then
    Exit(IfThen((D < x.Distance(Self[Result - 1])), Result, (Result - 1)));
  if (D > x.Distance(Self[Result - 1])) then
    Dec(Result)
  else
    if (D > x.Distance(Self[Result + 1])) then
      Inc(Result);
end;

{==============================================================================]
  <BinaryScan>
  @action: Performs a binary range scan on a sorted integer array to locate
           all indexes whose values lie within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses two binary searches to determine the first and last matching
           indexes that fall inside the range boundaries.
         - Returns an index list (TIntegerArray) identifying all matching
           elements.
         - Efficient O(log n + k) performance, where k is the number of
           matching elements.
[==============================================================================}
function TIntegerArrayHelper.BinaryScan(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  M, i: Integer;
  a, r, o: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  o.Create(0, High(Self));
  r.Create(-1);
  if (o.stop > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[o.stop]) or (a.start < Self[o.start])) then
    begin
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] >= a.start) then
        begin
          r.start := M;
          o.stop := (M - 1);
        end else
          o.start := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      o.start := r.start;
      o.stop := High(Self);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] <= a.stop) then
        begin
          r.stop := M;
          o.start := (M + 1);
        end else
          o.stop := (M - 1);
      end;
    end;
    False:
    if not ((a.stop > Self[o.start]) or (a.start < Self[o.stop])) then
    begin
      r.Create(-1);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] <= a.stop) then
        begin
          r.start := M;
          o.stop := (M - 1);
        end else
          o.start := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      o.start := r.start;
      o.stop := High(Self);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] >= a.start) then
        begin
          r.stop := M;
          o.start := (M + 1);
        end else
          o.stop := (M - 1);
      end;
    end;
  end;
  if not r.Employs(-1) then
  for i := r.start to r.stop do
    Result.Supply(i);
end;

{==============================================================================]
  <BinaryScanned>
  @action: Performs a binary range scan on a sorted integer array to locate
           all values lying within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses a single binary search to locate any element inside the range,
           then expands linearly in both directions to include all adjacent
           elements that also satisfy the range condition.
         - Returns a TIntegerArray containing the actual matching values
           (not indexes).
         - Offers O(log n + k) complexity and is well-suited for contiguous
           numeric segments.
[==============================================================================}
function TIntegerArrayHelper.BinaryScanned(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  M, S: Integer;
  a, r, o: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  o.Create(0, High(Self));
  S := o.stop;
  r.Create(-1);
  if (o.stop > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[o.stop]) or (a.start < Self[o.start])) then
    while (o.start <= o.stop) do
    begin
      M := o.Pivot;
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] >= a.start)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] <= a.stop)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] > a.stop) then
          o.stop := (M - 1)
        else
          o.start := (M + 1);
      end;
    end;
    False:
    if not ((a.stop > Self[o.start]) or (a.start < Self[o.stop])) then
    while (o.start <= o.stop) do
    begin
      M := o.Pivot;
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] <= a.stop)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] >= a.start)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] < a.start) then
          o.stop := (M - 1)
        else
          o.start := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryGrouped>
  @action: Groups the elements of the array into subarrays of identical values.
           Works efficiently on arrays that are already sorted (ascending).
           Uses binary search to locate all occurrences of each value.
  @note:
    - For ascending order (aAscending = True), assumes Self is sorted ascending.
    - For descending order (aAscending = False), internally sorts a copy of Self
      using TArray_QuickSorted and then reverses the resulting groups.
    - Complexity is O(n + (max-min) * log n) where max-min is the integer range.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrouped(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, r, l, m, v: Integer;
  s: TRange;
  t: TIntegerArray;
begin
  SetLength(Result, 0);
  case Self.Size of
    0: Exit;
    1: Exit([Self]);
  end;
  case aAscending of
    True:
    begin
      r := 0;
      for v := Self[0] to Self[High(Self)] do
      begin
        s.Create(0, High(Self));
        while (s.start <= s.stop) do
        begin
          m := s.Center;
          case Self[m].Compare(v) of
            0:
            begin
              l := m;
              while ((l > 0) and (Self[l - 1] = v)) do
                Dec(l);
              i := m;
              while ((i < High(Self)) and (Self[i + 1] = v)) do
                Inc(i);
              SetLength(Result, (r + 1));
              SetLength(Result[r], ((i - l) + 1));
              Move(Self[l], Result[r][0], (((i - l) + 1) * SizeOf(Integer)));
              Inc(r);
              Break;
            end;
            -1: s.start := (m + 1);
            1: s.stop := (m - 1);
          end;
        end;
      end;
    end;
    False:
    begin
      Result := Self.QuickSorted.BinaryGrouped(True);
	  i := 0;
      l := High(Result);
      while (i < l) do
      begin
        t := Result[i];
        Result[i] := Result[l];
        Result[l] := t;
        Inc(i);
        Dec(l);
      end;
	end;
  end;
end;

{==============================================================================]
  <BinaryGroup>
  @action: Groups the elements of the array into subarrays of identical values,
           maintaining the groups in sorted order. Works efficiently on unsorted arrays.
           Uses binary search to locate existing groups or binary-insert to create new ones.
  @note:
    - Groups are kept in ascending order if aAscending = True, descending if False.
    - Complexity is O(n log k), where n = number of elements and k = number of unique values.
    - Fully compatible with unsorted input.
    - Relies on dynamic array insertion for both group keys and result subarrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryGroup(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  k: TIntegerArray;
  i, m, p: Integer;
  f: Boolean;
  r: TRange;
begin
  SetLength(Result, 0);
  SetLength(k, 0);
  for i := 0 to High(Self) do
  begin
	r.Create(0, High(k));
    f := False;
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      case (k[m] = Self[i]) of
        True:
        begin
          f := True;
          p := m;
          Break;
        end;
        False:
        if ((k[m] < Self[i]) xor (not aAscending)) then
          r.start := (m + 1)
        else
          r.stop := (m - 1);
      end;
    end;
    if not f then
    begin
      p := r.start;
      Insert(Self[i], k, p);
      Insert(nil, Result, p);
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <BinaryGroups>
  @action: Groups the integer array into binary-value groups, returning a 2D array where each row contains
           the values belonging to a specific binary grouping. Iterates in ascending or descending order
           depending on the aAscending flag.
  @note: The input array (Self) must be sorted; otherwise the grouping order and bounds will be incorrect.
         The resulting number of groups may be smaller than the preallocated size and is trimmed afterward.
         Group determination relies on TIntegerArray_BinaryValues and successful insertion by TArray_Supply.
[==============================================================================}
function TIntegerArrayHelper.BinaryGroups(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  r, h, i, l: Integer;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    case aAscending of
      True:
      begin
        l := Min((h + 1), ((Self[h] - Self[0]) + 1));
        SetLength(Result, l);
        for i := Self[0] to Self[h] do
          if (Result[r].Supply(Self.BinaryValues(i, aAscending)) > -1) then
            Inc(r);
      end;
      False:
      begin
        l := Min((h + 1), ((Self[0] - Self[h]) + 1));
        SetLength(Result, l);
        for i := Self[0] downto Self[h] do
          if (Result[r].Supply(Self.BinaryValues(i, aAscending)) > -1) then
            Inc(r);
      end;
    end;
    if (r < l) then
      SetLength(Result, r);
  end;
end; 

{==============================================================================]
  <BinaryCountingSort>
  @action: Sorts the integer array using a hybrid approach that combines counting sort
           for densely clustered values with binary insertion for outliers.
           Automatically adapts to the data distribution based on the maxRange parameter.
  @note: 
    - If the range of array values is smaller than or equal to maxRange, a full counting
      sort is applied.
    - If the range exceeds maxRange, the method counts values within a central cluster
      (centered at the array’s midpoint) and uses binary insertion for values outside
      that cluster.
    - Supports ascending (default) or descending order.
    - Handles negative and positive integers.
    - The counting array size is bounded by maxRange + 1 to avoid excessive memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
var
  c, l: TIntegerArray;
  i, j, r, o: Integer;
  m: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds(r);
  case (r <= maxRange) of
    True:
    begin
      SetLength(c, r);
      for i := 0 to High(Self) do
        Inc(c[Self[i] - m.start]);
      j := 0;
      case aAscending of
        True:
        for i := 0 to (r - 1) do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
        False:
        for i := r - 1 downto 0 do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
      end;
    end;
    False:
    begin
      o := m.Center;
      r := 200;
      SetLength(c, ((r * 2) + 1));
      SetLength(l, 0);
      for i := 0 to High(Self) do
        if InRange(Self[i], (o - r), (o + r)) then
          Inc(c[Self[i] - (o - r)])
        else
          l.BinaryAppend(Self[i]);
      j := 0;
      case aAscending of
        True:
        begin
          for i := 0 to High(c) do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := 0 to High(l) do
            Self[j.Increase] := l[i];
        end;
        False:
        begin
          for i := High(c) downto 0 do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := High(l) downto 0 do
            Self[j.Increase] := l[i];
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFirst}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFirst}

{==============================================================================]
  <BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLast}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLast}

{==============================================================================]
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst1}

{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst2}

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast1}

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast2}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryValues1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryValues1}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryValues2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryValues2}

{==============================================================================]
  <BinaryExtract>
  @action: Returns all integers from Self that lie within the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, R.Size);
  for i := R.start to R.stop do
    Result[i - R.start] := Self[i];
end;

function TIntegerArrayHelper.BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  v: TIntegerArray;
  h, i, r: Integer;
begin
  if (Self.Empty or values.Empty) then
    Exit([]);
  v := values.QuickSorted;
  h := High(v);
  SetLength(Result, Self.Size);
  r := 0;
  case aAscending of
    True:
    for i := 0 to High(Self) do
      if (Self[i] > v[h]) then
        Break
      else if ((Self[i] >= v[0]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
    False:
    for i := 0 to High(Self) do
      if (Self[i] < v[0]) then
        Break
      else if ((Self[i] <= v[h]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns all integers from Self that lie outside the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, L, h: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, (L - R.Size));
  h := 0;
  for i := 0 to (L - 1) do
    if ((i < R.start) or (i > R.stop)) then
      Result[h.Increase] := Self[i];
end;

function TIntegerArrayHelper.BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i, r: Integer;
begin
  if Self.Empty then
    Exit([]);
  if values.Empty then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if not values.BinaryContains(Self[i], aAscending) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryAmount>
  @action: Returns count of x
  @note: Alternative for BinaryCount
[==============================================================================}
function TIntegerArrayHelper.BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

function TIntegerArrayHelper.BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r, s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  r := x.Normalize;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

function TIntegerArrayHelper.BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndexOf}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIndexOf}

function TIntegerArrayHelper.BinaryExists(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExists}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryExists}

function TIntegerArrayHelper.BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan1}
function TIntegerArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan2}

function TIntegerArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload; var K: Integer; {$DEFINE Skeleton_BinaryInsertSorted}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSorted}
function TIntegerArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload; var K: Integer; {$DEFINE Skeleton_BinaryInsertSort}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSort}

{==============================================================================]
  <BinaryFloor>
  @action: Returns the index of the greatest array element that is less than or
           equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical floor. For descending
         order, the search logic is reversed but the returned index still
         represents the element whose value is the nearest lower-or-equal
         bound relative to `value`.
[==============================================================================}
function TIntegerArrayHelper.BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFloor}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFloor}

{==============================================================================]
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `value`.
[==============================================================================}
function TIntegerArrayHelper.BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCeil}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCeil}

{==============================================================================]
  <BinaryTrunc>
  @action: Returns the index of the array element closest to `value` when
           truncating towards zero. For positive values, behaves like Floor
           (rounds down). For negative values, behaves like Ceil (rounds up
           towards zero). If no appropriate element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. This mimics the
         behavior of mathematical truncation, which always rounds towards zero.
[==============================================================================}
function TIntegerArrayHelper.BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryTrunc}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryTrunc}

{==============================================================================]
  <BinaryRound>
  @action: Returns the index of the array element nearest to `value`. If two
           elements are equidistant, returns the one with the lower index
           (tie-breaking towards floor). If no elements exist, returns -1.
  @note: The array must be sorted according to `oAscending`. This performs
         rounding to the nearest element, similar to mathematical rounding
         with ties going to the lower value.
[==============================================================================}
function TIntegerArrayHelper.BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRound}

{==============================================================================]
  <BinaryPoint>
  @action: Determines the positional index at which `value` should be inserted
           to preserve the array's sorted order. Returns the first index whose
           element is not less than `value` when ascending, or not greater than
           `value` when descending. If all elements are less (ascending) or
           greater (descending), returns Length(Self).
  @note: This routine does not search for an existing match. It calculates the
         stable insertion point (lower-bound position) using binary search.
         The array must already be sorted according to `oAscending`. The
         returned index will always be in the range 0..Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPoint}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPoint}

{==============================================================================]
  <BinaryClosest>
  @action: Returns the index of the element closest to the given value in the array.
  @note:
    - If the exact value exists, returns its index.
    - If the value does not exist, returns the index of the closest element.
    - Handles both ascending and descending sorted arrays (controlled by oAscending).
    - Returns -1 if the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryClosest}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryClosest}

{==============================================================================]
  <BinaryFarthest>
  @action: Returns the index of the array element farthest from the given value.
  @note: Compares only the first and last elements. In case of a tie (both endpoints equally far),
         `oAscending = True` selects the lower index (first element),
         `oAscending = False` selects the higher index (last element). Returns -1 for empty arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFarthest}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFarthest}

{==============================================================================]
  <BinarySearchNth>
  @action: Returns the index of the N-th occurrence of the given value in the array.
  @note:
    - Uses binary search to locate the first occurrence of the value, then adds N to find the N-th occurrence.
    - Returns -1 if:
        * N is out of bounds (negative or larger than the array size),
        * the value is not found,
        * or the N-th occurrence does not exist.
    - Works for both ascending and descending sorted arrays (controlled by oAscending).
[==============================================================================}
function TIntegerArrayHelper.BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchNth}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchNth}

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================} 
function TIntegerArrayHelper.BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload; var H, D: Integer; {$DEFINE Skeleton_BinaryApproximateSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryApproximateSearch}

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchApproximate}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchApproximate}

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLowerCount}

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHigherCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHigherCount}

{==============================================================================]
  <BinaryRangeEx>
  @action: Returns the range of indices containing values within `tolerance` of
           `value`. Uses binary search to find boundaries efficiently.
  @note: The array must be sorted according to `oAscending`. Unlike the expand
         function, this searches the entire array for the range, not just from
         a starting index. Time complexity is O(log n).
  @example: arr=[10,15,20,25,30,35], value=22, tolerance=5
            → includes 20,25 → range(2,3)
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
var
  m: TRange;
begin
  if (tolerance < 0) then
    Exit(TRange.Construct(-1, -1));
  m.Create((value - tolerance), (value + tolerance));
  Result.start := Self.BinaryBoundLeft(IfThen(oAscending, m.start, m.stop), oAscending);
  Result.stop := Self.BinaryBoundRight(IfThen(oAscending, m.stop, m.start), oAscending);
  if (Result.stop > 0) then
    Dec(Result.stop);
  if ((Result.start = -1) or (Result.start > High(Self)) or (Result.stop = -1) or (Result.stop < Result.start)) then
    Result := TRange.Construct(-1, -1);
end;

{==============================================================================]
  <BinaryFit>
  @action: Returns True if the specified value falls within the sortable domain
           represented by the current array. In other words, it verifies that
           the value is within the inclusive bounds defined by the first and
           last elements of the array, assuming that the array is sorted in the
           direction indicated by oAscending.
  @note: This function does not perform a binary search. It simply checks
         whether the value is eligible for a binary lookup or insertion
         attempt. For empty arrays, the function always returns False. When
         oAscending = False, the comparison logic is inverted to support
         descending-sorted arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryFit(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryFit}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFit}

{==============================================================================]
  <BinaryUnfit>
  @action: Returns True if the specified value is outside the inclusive bounds
           of the array, or if the array is empty. This indicates that the
           value cannot exist in the array and is not a candidate for a binary
           search within the current bounds.
  @note: This routine is essentially the logical inverse of BinaryFit. It is
         useful as a pre-check before performing binary search or before
         attempting bounded insertion logic. When oAscending = False, the
         boundary comparisons are reversed to support descending-sorted
         arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnfit(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUnfit}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnfit}

{==============================================================================]
  <BinaryIncludes>
  @action: Determines whether the specified value exists in this array by using
           a binary search. The array is assumed to be pre-sorted in the order
           specified by oAscending.
  @note: Performs boundary checks before invoking the binary search for
         efficiency. Returns True only if the array is non-empty, the value
         lies within the array’s sorted bounds, and the binary search locates
         the element.
[==============================================================================}
function TIntegerArrayHelper.BinaryIncludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryIncludes}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIncludes}

{==============================================================================]
  <BinaryExcludes>
  @action: Determines whether the specified value does not exist in this array
           by using a binary search. The array is assumed to be pre-sorted in
           the order specified by oAscending.
  @note: Performs boundary checks before invoking the binary search. Returns
         True if the array is empty, if the value lies outside the array’s
         sorted bounds, or if the binary search fails to locate the value.
[==============================================================================}
function TIntegerArrayHelper.BinaryExcludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExcludes}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryExcludes}

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - This function performs a binary search to find the first and last occurrences
      of the given value in the array.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of the value.
    - If the value is not found, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TIntegerArrayHelper.BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanning1}

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of values within a specified range in a sorted array.
  @note:
    - This function performs a binary search to find the first and last elements in the array
      that lie within the given range.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of elements within the range.
    - If no elements fall within the range, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of elements in the array that are within the specified range.
[==============================================================================}
function TIntegerArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanning2}

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - Performs a binary search to locate any occurrence of the value.
    - Once found, expands linearly left and right to determine the full span.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TIntegerArrayHelper.BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf1}

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of elements within a specified value range in a sorted array.
  @note:
    - Performs a binary search to locate any element within the target range.
    - Once found, expands linearly left and right to determine the full span of elements inside the range.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if no elements are within the specified range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TIntegerArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf2}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific value in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf1}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of elements within a specified value range in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if no elements fall within the range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf2}

{==============================================================================]
  <BinaryUnique>
  @action: Sorts the array using binary sort, removes duplicate values in-place,
           and returns the final number of unique elements.
  @note: This routine always performs a full binary sort prior to uniqueness
         filtering. After sorting, it compacts the array by overwriting
         duplicates and truncating the underlying storage to the count of
         uniques.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnique(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnique}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnique}

{==============================================================================]
  <BinaryUniqued>
  @action: Returns a new array containing the unique values of the source array,
           sorted according to the specified order, without modifying the
           original array.
  @note: The function makes a full copy of the source array, applies a binary
         sort, removes duplicates by in-place compaction of the copy, and
         trims the resulting array to the count of unique elements.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniqued(const oAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryUniqued}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniqued}

{==============================================================================]
  <BinaryUniq>
  @action: Removes duplicate values from an already monotonic array (ascending
           or descending), preserving only unique values and returning the final
           count.
  @note: Unlike BinaryUnique, this routine does not sort the array. It assumes
         the array is already ordered in the direction specified by oAscending.
         It performs a linear scan to compact unique values and truncates the
         array afterward.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniq(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUniq}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniq}

{==============================================================================]
  <BinaryUniqd>
  @action: Returns a new array containing only the unique values from the source
           array, assuming the source is already ordered (ascending or descending),
           without modifying the original array.
  @note: This routine does not perform sorting. It creates a copy of the source
         array and then performs a linear uniqueness pass based on the direction
         specified by oAscending. Only strictly increasing (or strictly
         decreasing) transitions are preserved. The result is compacted in-place
         and truncated to the number of unique values.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniqd(const oAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryUniqd}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniqd}

{==============================================================================]
  <BinaryExistent>
  @action: Performs a binary search on the integer array to determine if a
           specified item exists. Returns True if found and provides the
           item's index via the out parameter.
  @note: Assumes the array is pre-sorted in ascending or descending order,
         depending on the oAscending flag. Uses a directional multiplier
         for handling sort order efficiently. Returns -1 in the index
         parameter when the item is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryExistent(const item: Integer; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  C, D: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  D := ((Ord(oAscending) * 2) - 1);
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := ((Self[index] - item) * D);
    if (C = 0) then
      Exit(True);
    if (C < 0) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end;

class function TIA.Init(var arr: TIntegerArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function TIA.Unique(var arr: TIntegerArray): Integer; overload; 
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(arr);
  if (y > 0) then
  begin
    z := 0;
    r := arr.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
      if b[arr[x] - r.start].Enable then
        arr[z.Increase] := arr[x];
    SetLength(b, 0);
    SetLength(arr, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;

class function TIA.Reverse(var arr: TIntegerArray): Boolean; overload; 
var
  a: TIntegerArray;
  i: Integer;
begin
  Result := (Length(arr) > 1);
  if not Result then
    Exit;
  SetLength(a, Length(arr));
  for i := 0 to High(arr) do
    a[i] := arr[High(arr) - i];
  Move(a[0], arr[0], (Length(arr) * SizeOf(Integer)));
end;

class function TIA.Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if (Length(arr) = 0) then
    Exit;
  Move(arr[0], Result[0], (Length(arr) * SizeOf(Integer)));
  for i := 0 to (High(Result) div 2) do
  begin
    r := Result[i];
    Move(Result[High(Result) - i], Result[i], SizeOf(Integer));
    Move(r, Result[High(Result) - i], SizeOf(Integer));
  end;
end;

class function TIA.Combine(const A, B: TIntegerArray): TIntegerArray; overload; 
var
  x, y: Integer;
begin
  x := Length(A);
  y := Length(B);
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(A[0], Result[0], (x * SizeOf(Integer)));
  if (y > 0) then
    Move(B[0], Result[x], (y * SizeOf(Integer)));
end;
{$ENDIF}

{$UNDEF Integer}