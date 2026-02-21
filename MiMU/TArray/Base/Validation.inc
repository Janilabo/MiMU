{$IFDEF HELPERS}
function AllDistinct: Boolean; overload;
function AllEqual: Boolean; overload;
function AllSame: Boolean; overload;
function AllUnique: Boolean; overload;
function BuiltWith(const blocks: MArray): Boolean; overload;
function BuiltWithout(const forbidden: MArray): Boolean; overload;
function Comprised(const items: MArray): Boolean; overload;
function Constant(const item: MType): Boolean; overload;
function Constant: Boolean; overload;
function Contains(const item: MType; const index: Integer = 0): Boolean; overload;
function Contains(const item: MType; const limit: TRange): Boolean; overload;
function ContainsAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function ContainsAtMost(const item: MType; const limit: Integer): Boolean; overload;
function Dull(const item: MType): Boolean; overload;
function Dull: Boolean; overload;
function EndsWith(const aItem: MType): Boolean; overload;
function EndsWith(const aItem: MArray): Boolean; overload;
function Equalized(const rIndex: Integer = 0): Boolean; overload;
function Exact(const items: MArray): Boolean; overload;
function Excessive: Boolean; overload;
function Fits(const maxValue: Integer): Boolean; overload;
function Fits(const target: TRange): Boolean; overload;
function FreeOf(const forbidden: MArray): Boolean; overload;
function GotAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function GotAtMost(const item: MType; const limit: Integer): Boolean; overload;
function Got(const item: MType; const limit: TRange): Boolean; overload;
function HasAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function HasAtMost(const item: MType; const limit: Integer): Boolean; overload;
function Has(const item: MType; const limit: TRange): Boolean; overload;
function Heterogeneous: Boolean; overload;
function Holds(const chain: MArray): Boolean; overload;
function Homogeneous(const item: MType): Boolean; overload;
function Homogeneous: Boolean; overload;
function IsConstant(const item: MType): Boolean; overload;
function IsConstant: Boolean; overload;
function IsDistinct: Boolean; overload;
function MadeOf(const allowed: MArray): Boolean; overload;
function Occurs(const item: MType; const occurrence: Integer = 1): Boolean; overload;
function Presence(const item: MType; const occurrence: Integer = 1): Boolean; overload;
function StartsWith(const aItem: MType): Boolean; overload;
function StartsWith(const aItem: MArray): Boolean; overload;
function Subset(const items: MArray): Boolean; overload;
function Uniform: Boolean; overload;
function Uniform(const item: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllDistinct>
  @action: Returns True if all elements contained in the array are pairwise distinct.
           Returns False immediately when a duplicate element is detected.
  @note:
    • Arrays with fewer than two elements are considered distinct by definition.
    • Uniqueness is determined using the equality and hash semantics (THashSet).
[==============================================================================}
function MArrayHelper.AllDistinct: Boolean; overload;
var
  h: specialize THashSet<MType>;
  i: MType;
begin
  if (Self.Length < 2) then
    Exit(True);
  h := specialize THashSet<MType>.Create;
  try
    for i in Self do
      if not h.Add(i) then
        Exit(False);
    Result := True;
  finally
    h.Free;
  end;
end;

{==============================================================================]
  <AllEqual>
  @action: Returns true if all values in arr are equal (arr contains only equal values).
  @note: Returns FALSE with empty array!
[==============================================================================}
function MArrayHelper.AllEqual: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <AllSame>
  @action: Returns true if all values in arr are the same (arr contains only equal values).
  @note: Returns FALSE with empty array!
[==============================================================================}
function MArrayHelper.AllSame: Boolean; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  Result := (l > 0);
  i := 0;
  while (Result and (i.Increment < l)) do
    Result := (Self[0] = Self[i]);
end;

{==============================================================================]
  <AllUnique>
  @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
  @note: None
[==============================================================================}
function MArrayHelper.AllUnique: Boolean; overload;
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
  <BuiltWith>
  @action: Returns true is arr is built with blocks.
  @note: This function requires blocks array to be unique (no duplicates allowed for it).
[==============================================================================}
function MArrayHelper.BuiltWith(const blocks: MArray): Boolean; overload;
var
  i, p: Integer;
  u: TBooleanArray;
begin
  if (Self.Empty or blocks.Empty) then
    Exit(False);
  SetLength(u, blocks.Size);
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
  <BuiltWithout>
  @action: Checks if array arr does not have any forbidden items.
  @note: None.
[==============================================================================}
function MArrayHelper.BuiltWithout(const forbidden: MArray): Boolean; overload;
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
  <Comprised>
  @action: Returns true if arr is built of items only.
  @note:
[==============================================================================}
function MArrayHelper.Comprised(const items: MArray): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Size;
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := items.Contains(Self[l]);
end;

{==============================================================================]
  <Constant>
  @action: Returns true if arr consists of item ONLY.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Constant(const item: MType): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Size;
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := (Self[l] = item);
end;

{==============================================================================]
  <Constant>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Constant: Boolean; overload;
begin
  Result := (Self.Occupied and Self.Constant(Self[0]));
end;

{==============================================================================]
  <Contains>
  @action: Looks array for item starting from start index. If found, Result will be True.
  @note: None.
[==============================================================================}
function MArrayHelper.Contains(const item: MType; const index: Integer = 0): Boolean; overload;
var
  i: Integer;
begin
  for i := index to High(Self) do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Contains>
  @action: Determines whether the array contains a number of occurrences of item
           within the inclusive range specified by limit (normalized).
  @note:
    - Stops scanning early if occurrences exceed the maximum or cannot reach the minimum.
    - Uses 0-based indexing for arrays.
    - limit.Normalize ensures that limit.start <= limit.stop.
[==============================================================================}
function MArrayHelper.Contains(const item: MType; const limit: TRange): Boolean; overload;
var
  i, c, r: Integer;
  n: TRange;
begin
  n := limit.Normalize;
  c := 0;
  r := Self.Length;
  for i := 0 to High(Self) do
  begin
    if (Self[i] = item) then
      Inc(c);
    Dec(r);
    if (c > n.stop) then
      Exit(False);
    if ((c + r) < n.start) then
      Exit(False);
  end;
  Result := InRange(c, n.start, n.stop);
end;

{==============================================================================]
  <ContainsAtLeast>
  @action: Determines whether the array contains at least limit occurrences of item.
  @note:
    - Returns True if limit < 1.
    - Stops scanning early once the limit is reached.
    - Performs early-exit optimization if remaining elements cannot reach the limit.
    - Uses 0-based indexing for arrays.
[==============================================================================}
function MArrayHelper.ContainsAtLeast(const item: MType; const limit: Integer): Boolean; overload;
var
  i, c, r: Integer;
begin
  if (limit < 1) then
    Exit(True);
  c := 0;
  r := Self.Length;
  for i := 0 to High(Self) do
  begin
    if (Self[i] = item) then
      Inc(c);
    Dec(r);
    if (c >= limit) then
      Exit(True);
    if ((c + r) < limit) then
      Exit(False);
  end;
  Result := False;
end;

{==============================================================================]
  <ContainsAtMost>
  @action: Determines whether the array contains at most limit occurrences of item.
  @note:
    - Returns False if limit < 0.
    - Stops scanning early once the limit is exceeded.
    - Performs early-exit optimization if remaining elements cannot exceed the limit.
    - Uses 0-based indexing for arrays.
[==============================================================================}
function MArrayHelper.ContainsAtMost(const item: MType; const limit: Integer): Boolean; overload;
var
  i, c, r: Integer;
begin
  if (limit < 0) then
    Exit(False);
  c := 0;
  r := Self.Length;
  for i := 0 to High(Self) do
  begin
    if (Self[i] = item) then
      Inc(c);
    Dec(r);
    if (c > limit) then
      Exit(False);
    if ((c + r) <= limit) then
      Exit(True);
  end;
  Result := True;
end;

{==============================================================================]
  <Dull>
  @action: Returns True if the array is non-empty and every element in the array
           is equal to the specified item.
  @note:
    • Returns False for an empty array.
    • Stops at the first element that differs from item.
[==============================================================================}
function MArrayHelper.Dull(const item: MType): Boolean; overload;
var
  e: MType;
begin
  for e in Self do
    if (e <> item) then
      Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <Dull>
  @action: Returns True if the array is non-empty and all elements in the array
           are equal to each other.
  @note:
    • Returns False for an empty array.
    • Internally compares all elements against the first element.
    • Equivalent to Dull(Self[0]) when Length > 0.
[==============================================================================}
function MArrayHelper.Dull: Boolean; overload;
begin
  Result := ((Self.Length > 0) and Self.Dull(Self[0]));
end;

{==============================================================================]
  <EndsWith>
  @action: Checks whether the array is non-empty and its last element is equal
           to the specified item.
  @note: This overload performs a simple boundary comparison only. It does not
         verify sequence suffix matching when a collection is supplied.
[==============================================================================}
function MArrayHelper.EndsWith(const aItem: MType): Boolean; overload;
begin
  Result := ((Self.Length > 0) and (Self[High(Self)] = aItem));
end;

{==============================================================================]
  <EndsWith>
  @action: Returns True if the array is non-empty and the last element of the array
           matches any element contained in the provided array parameter.
  @note: This implementation checks only the last array element against members
         of aItem. It does not perform full suffix sequence comparison.
[==============================================================================}
function MArrayHelper.EndsWith(const aItem: MArray): Boolean; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if (h > -1) then
  for i := 0 to High(aItem) do
    if (Self[h] = aItem[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Equalized>
  @action: Checks whether all elements in the integer array are equal to each other.
           Uses a recursive comparison starting from the specified index.
  @note:
    • Returns False for an empty array.  
    • If rIndex >= High(Self), the recursion has reached the last element,
      so the remaining array is trivially equal.  
    • Recursively compares each element to the next element in the array.
[==============================================================================}
function MArrayHelper.Equalized(const rIndex: Integer = 0): Boolean; overload;
begin
  if Self.Empty then
    Exit(False);
  if (rIndex >= High(Self)) then
    Exit(True);
  Result := ((Self[rIndex] = Self[rIndex + 1]) and Self.Equalized(rIndex + 1));
end;

{==============================================================================]
  <Exact>
  @action: Returns true if arr consists of items.
  @note: arr must contain ALL the items for this function to return True.
         Any extra items will cause Result to be False also.
         items[1,2,3]
         arr[1,2,3,1,2,3] => True
         arr[2,3,2,3] => False
         arr[2,1,3,4] => False
         This function requires items array to be unique. No duplicates allowed for it!
[==============================================================================}
function MArrayHelper.Exact(const items: MArray): Boolean; overload;
var
  i, j: Integer;
  f: TBooleanArray;
begin
  if items.Empty then
    Exit(Self.Empty);
  f.Create(items.Size, False);
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
  <Excessive>
  @action: Returns true if arr contains any duplicates in it.
  @note: None.
[==============================================================================}
function MArrayHelper.Excessive: Boolean; overload;
type
  TDict = specialize TDictionary<MType, Boolean>;
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
  <Fits>
  @action: Returns true if arr size is at maximum maxValue.
  @note: None.
[==============================================================================}
function MArrayHelper.Fits(const maxValue: Integer): Boolean; overload;
begin
  Result := (Self.Size <= maxValue);
end;

{==============================================================================]
  <Fits>
  @action: Returns true if arr size is between target start and stop.
  @note: None.
[==============================================================================}
function MArrayHelper.Fits(const target: TRange): Boolean; overload;
begin
  Result := InRange(Self.Size, Min(target.start, target.stop), Max(target.start, target.stop));
end;

{==============================================================================]
  <FreeOf>
  @action: Checks if array arr does not have any forbidden items.
  @note: None.
[==============================================================================}
function MArrayHelper.FreeOf(const forbidden: MArray): Boolean; overload;
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
  <GotAtLeast>
  @action: Determines if the array contains at least a specified number of occurrences of an item.
  @note:
    - Uses the Count(item) function internally.
    - Returns False if limit is greater than the actual occurrences.
    - Single-pass (delegated to Count) and zero-based indexing.
[==============================================================================}
function MArrayHelper.GotAtLeast(const item: MType; const limit: Integer): Boolean; overload;
begin
  Result := (Self.Count(item) >= limit);
end;

{==============================================================================]
  <GotAtMost>
  @action: Determines if the array contains at most a specified number of occurrences of an item.
  @note:
    - Uses the Count(item) function internally.
    - Returns False if the occurrences exceed the specified limit.
    - Single-pass (delegated to Count) and zero-based indexing.
[==============================================================================}
function MArrayHelper.GotAtMost(const item: MType; const limit: Integer): Boolean; overload;
begin
  Result := (Self.Count(item) <= limit);
end;

{==============================================================================]
  <Got>
  @action: Determines if the array contains a number of occurrences of an item within a specified inclusive range.
  @note:
    - Uses the Count(item) function internally.
    - The range is represented by TRange, which must implement Contains.
    - Returns True if Count(item) is within [limit.start, limit.stop].
    - Single-pass (delegated to Count) and zero-based indexing.
[==============================================================================}
function MArrayHelper.Got(const item: MType; const limit: TRange): Boolean; overload;
begin
  Result := limit.Contains(Self.Count(item));
end;

{==============================================================================]
  <HasAtLeast>
  @action: Determines whether the array contains at least limit occurrences of item.
  @note:
    - Returns True as soon as the count reaches limit (early exit).
    - Returns False if the array contains fewer than limit occurrences.
    - Uses zero-based indexing (0..High(Self)).
    - Optimized for large arrays; no temporary allocations are made.
[==============================================================================}
function MArrayHelper.HasAtLeast(const item: MType; const limit: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  for i := 0 to High(Self) do
    if (Self[i] = item) then
    case (c >= limit) of
      True: Exit(True);
      False: Inc(c);
    end;
  Result := (c >= limit);
end;

{==============================================================================]
  <HasAtMost>
  @action: Determines whether the array contains at most limit occurrences of item.
  @note:
    - Returns False if the number of occurrences exceeds limit.
    - Early exit is used for efficiency.
    - Uses zero-based indexing (0..High(Self)).
    - Optimized for large arrays; no temporary allocations are made.
[==============================================================================}
function MArrayHelper.HasAtMost(const item: MType; const limit: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  for i := 0 to High(Self) do
    if (Self[i] = item) then
    case (c > limit) of
      True: Exit(False);
      False: Inc(c);
    end;
  Result := (c <= limit);
end;

{==============================================================================]
  <Has>
  @action: Determines whether the number of occurrences of item in the array
           falls within the inclusive range specified by limit.
  @note:
    - `limit` is normalized first, ensuring that limit.start <= limit.stop.
    - Early exits are used for efficiency:
        * Exits False if the count exceeds the upper bound (`limit.stop`).
        * Exits False if it becomes impossible to reach the lower bound (limit.start)
          given the remaining elements in the array.
    - Uses zero-based indexing (0..High(Self)).
    - Optimized for large arrays; no temporary allocations are made.
[==============================================================================}
function MArrayHelper.Has(const item: MType; const limit: TRange): Boolean; overload;
var
  i, c, r: Integer;
  n: TRange;
begin
  n := limit.Normalize;
  c := 0;
  r := Self.Length;
  for i := 0 to High(Self) do
  begin
    if (Self[i] = item) then
    case(c > n.stop) of
      True: Exit(False);
      False: Inc(c);
    end;
    Dec(r);
    if ((c + r) < n.start) then
      Exit(False);
  end;
  Result := InRange(c, n.start, n.stop);
end;

{==============================================================================]
  <Heterogeneous>
  @action: Returns True if the array is non-empty and all elements are pairwise
           distinct (i.e. no two elements are equal).
  @note:
    • Returns False for an empty array.
    • Uses a recursive pairwise comparison strategy.
    • Time complexity: O(n²).
    • Space complexity: O(n) due to recursion depth.
    • Equality is evaluated using the = operator of MType.
    • Functionally equivalent to an injectivity/distinctness check,
      but significantly less efficient than hash- or sort-based methods.
[==============================================================================}
function MArrayHelper.Heterogeneous: Boolean; overload;
var
  h: Integer;
  function Check(const idx: Integer): Boolean;
  var
    i: Integer;
  begin
    if (idx >= h) then
      Exit(True);
    for i := (idx + 1) to h do
      if (Self[i] = Self[idx]) then
        Exit(False);
    Result := Check(idx + 1);
  end;
begin
  h := High(Self);
  Result := ((h > -1) and Check(0));
end;

{==============================================================================]
  <Holds>
  @action: Returns true if arr contains (holds) WHOLE chain of items in it.
  @note: Starting from any index and ending to any index!
[==============================================================================}
function MArrayHelper.Holds(const chain: MArray): Boolean; overload;
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
  <Homogeneous>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Homogeneous(const item: MType): Boolean; overload;
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
  <Homogeneous>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Homogeneous: Boolean; overload;
begin
  Result := (Self.Exists and Homogeneous(Self[0]));
end;

{==============================================================================]
  <IsConstant>
  @action: Returns true if arr consists of item ONLY.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.IsConstant(const item: MType): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  repeat
    Result := ((h > -1) and (Self[h] = item));
  until ((Result = False) or (h.Decrement < 0));
end;

{==============================================================================]
  <IsConstant>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.IsConstant: Boolean; overload;
begin
  Result := ((not Self.Empty) and Self.IsConstant(Self[0]));
end;

{==============================================================================]
  <IsDistinct>
  @action: Returns True if all elements in the array are unique.
           Returns False immediately upon detecting a duplicate element.
  @note:
    • An empty array is considered distinct.
    • Internally uses TDictionary to detect duplicates.
[==============================================================================}
function MArrayHelper.IsDistinct: Boolean; overload;
var
  d: specialize TDictionary<MType, Byte>;
  v: MType;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  try
    for v in Self do
      if not d.TryAdd(v, 0) then
        Exit(False);
    Result := True;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <MadeOf>
  @action: Checks if array arr contains only allowed items.
  @note: None.
[==============================================================================}
function MArrayHelper.MadeOf(const allowed: MArray): Boolean; overload;
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
  <Occurs>
  @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
  @note: Supports lookup for 0 items. Loops array through from beginning to end.	
[==============================================================================}
function MArrayHelper.Occurs(const item: MType; const occurrence: Integer = 1): Boolean; overload;
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
  <Presence>
  @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
  @note: Supports lookup for 0 items. Loops array through from end to beginning.	
[==============================================================================}
function MArrayHelper.Presence(const item: MType; const occurrence: Integer = 1): Boolean; overload;
var
  l, o: Integer;
begin
  if (occurrence < 0) then
    Exit(False);
  case (occurrence = 0) of
    False:
    begin
      o := 0;
      l := Self.Length;
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
  <StartsWith>
  @action: Checks whether the array is non-empty and its first element is equal
           to the specified item.
  @note: This overload performs a simple boundary comparison only. It does not
         verify sequence prefix matching when a collection is supplied.
[==============================================================================}
function MArrayHelper.StartsWith(const aItem: MType): Boolean; overload;
begin
  Result := ((Self.Length > 0) and (Self[0] = aItem));
end;

{==============================================================================]
  <StartsWith>
  @action: Returns True if the array is non-empty and the first element of the array
           matches any element contained in the provided array parameter.
  @note: This implementation checks only the first array element against members
         of aItem. It does not perform full prefix sequence comparison.
[==============================================================================}
function MArrayHelper.StartsWith(const aItem: MArray): Boolean; overload;
var
  i: Integer;
begin
  if (Self.Length > 0) then
  for i := 0 to High(aItem) do
    if (Self[0] = aItem[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Subset>
  @action: Returns true if arr is subset of items.
  @note: None.
[==============================================================================}
function MArrayHelper.Subset(const items: MArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not items.Contains(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Uniform>
  @action: Returns true if arr is consistent with only 1 item.
  @note: Returns True with empty arrays!
[==============================================================================}
function MArrayHelper.Uniform: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[0]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Uniform>
  @action: Returns true if arr is consistent with only custom item.
  @note: Returns True with empty arrays!
[==============================================================================}
function MArrayHelper.Uniform(const item: MType): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] <> item) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
