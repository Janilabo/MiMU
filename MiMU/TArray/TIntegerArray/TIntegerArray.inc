{$DEFINE Integer}{$I ../../Type/Defines.inc}{$DEFINE BASE}

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
  {$I ../TArray.inc}
  {$I TIntegerArray.pph}
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
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TIntegerArray.pph}
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
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean; overload; var a: TIntegerArray; {$DEFINE Skeleton_Pure}{$I ../Skeletons.inc}{$UNDEF Skeleton_Pure}

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
function TIntegerArrayHelper.TernarySearch(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_TernarySearch}{$I ../Skeletons.inc}{$UNDEF Skeleton_TernarySearch}

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
function TIntegerArrayHelper.TernaryPeak: Integer; overload; {$DEFINE Skeleton_TernaryPeak}{$I ../Skeletons.inc}{$UNDEF Skeleton_TernaryPeak}

{==============================================================================]
  <TernaryValley>
  @action: Performs a ternary-search-style scan to locate a single local minimum.
  @note: The algorithm mirrors the logic used in TernaryPeak but inverts
         all comparisons to detect a valley rather than a peak. Edge
         minima are tested first. If no valid local minimum exists in the
         narrowed search interval, the function returns -1. Expected
         complexity is O(log n) with a linear fallback validation.
[==============================================================================}
function TIntegerArrayHelper.TernaryValley: Integer; overload; {$DEFINE Skeleton_TernaryValley}{$I ../Skeletons.inc}{$UNDEF Skeleton_TernaryValley}

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
function TIntegerArrayHelper.TernaryMountain: Integer; overload; {$DEFINE Skeleton_TernaryMountain}{$I ../Skeletons.inc}{$UNDEF Skeleton_TernaryMountain}

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

{$UNDEF BASE}{$UNDEF Integer}
