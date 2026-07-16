{$IFDEF HELPERS}
function BuiltWith(const blocks: MArray): Boolean; overload;
function BuiltWithout(const forbidden: MArray): Boolean; overload;
function Comprised(const items: MArray): Boolean; overload;
function Constant(const item: MType): Boolean; overload;
function Constant: Boolean; overload;
function Contains(const item: MType; const index: Integer = 0): Boolean; overload;
function Contains(const item: MType; const limit: TRange): Boolean; overload;
function ContainsAll(const sItems: MArray): Boolean; overload;
function ContainsAny(const sItems: MArray): Boolean; overload;
function ContainsAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function ContainsAtMost(const item: MType; const limit: Integer): Boolean; overload;
function CountAtLeast(const target: Integer; const mItem: MType): Boolean; overload;
function CountAtMost(const target: Integer; const mItem: MType): Boolean; overload;
function CountBetween(const minTarget, maxTarget: Integer; const mItem: MType): Boolean; overload;
function CountExactly(const target: Integer; const mItem: MType): Boolean; overload;
function Dull(const item: MType): Boolean; overload;
function Dull: Boolean; overload;
function EndsWith(const aItem: MType): Boolean; overload;
function EndsWith(const aItem: MArray): Boolean; overload;
function Exact(const items: MArray): Boolean; overload;
function Existence(const mItem: MType): Boolean; overload;
function Existency(const mItem: MType): Boolean; overload;
function Existing(const mItem: MType): Boolean; overload;
function Extant(const mItem: MType; const backwardScan: Boolean = False): Boolean; overload;
function FreeOf(const forbidden: MArray): Boolean; overload;
function GotAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function GotAtMost(const item: MType; const limit: Integer): Boolean; overload;
function Got(const item: MType; const limit: TRange): Boolean; overload;
function Has(const item: MType; const limit: TRange): Boolean; overload;
function HasAtLeast(const item: MType; const limit: Integer): Boolean; overload;
function HasAtMost(const item: MType; const limit: Integer): Boolean; overload;
function HasMajority(const mItem: MType): Boolean; overload;
function HasNone(const mItem: MType): Boolean; overload;
function HasOnly(const mItem: MType): Boolean; overload;
function Holds(const chain: MArray): Boolean; overload;
function MadeOf(const allowed: MArray): Boolean; overload;
function MeetsBetween(const minTarget, maxTarget: Integer; const mItem: MType): Boolean; overload;
function MeetsCeiling(const target: Integer; const mItem: MType): Boolean; overload;
function MeetsExact(const target: Integer; const mItem: MType): Boolean; overload;
function MeetsFloor(const target: Integer; const mItem: MType): Boolean; overload;
function Occurs(const item: MType; const occurrence: Integer = 1): Boolean; overload;
function Presence(const item: MType; const occurrence: Integer = 1): Boolean; overload;
function StartsWith(const aItem: MType): Boolean; overload;
function StartsWith(const aItem: MArray): Boolean; overload;
function Subset(const items: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <ContainsAll>
  @action: Checks if every single one of the specified values exists in the array.
  @note: Returns false immediately if any target value is missing.
[==============================================================================}
function MArrayHelper.ContainsAll(const sItems: MArray): Boolean; overload;
var
  i: MType;
begin
  for i in sItems do
    if not Self.Contains(i) then
	  Exit(False);
  Result := True;
end;

{==============================================================================]
  <ContainsAny>
  @action: Checks if the array contains at least one of the specified values.
  @note: Returns true on the very first match found.
[==============================================================================}
function MArrayHelper.ContainsAny(const sItems: MArray): Boolean; overload;
var
  i: MType;
begin
  for i in sItems do
    if Self.Contains(i) then
	  Exit(True);
  Result := False;
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
  <CountAtLeast>
  @action: Returns True if the array contains at least 'target' elements matching 'mItem'.
  @param: target Minimum number of matches required (inclusive threshold).
  @param: mItem The specific element value to search and match against.
  @return: True if match count >= target, otherwise False.
  @note: Implements short-circuit optimization. Exits early with True the exact
         moment the required target threshold is reached, or False if the
         target exceeds the total array length.
[==============================================================================}
function MArrayHelper.CountAtLeast(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if (target <= 0) then
    Exit(True);
  if (target > l) then
    Exit(False);
   c := 0;
  for i := 0 to (l - 1) do
    if ((Self[i] = mItem) and (c.Increment >= target)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <CountAtMost>
  @action: Returns True if the array contains at most 'target' elements matching 'mItem'.
  @param: target Maximum number of matches permitted (inclusive cap).
  @param: mItem The specific element value to search and match against.
  @return: True if match count <= target, otherwise False.
  @note: Implements short-circuit optimization. Exits early with False the exact
         moment the count of matching elements increments past the allowed target limit.
[==============================================================================}
function MArrayHelper.CountAtMost(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if (target < 0) then
    Exit(False);
  if (target >= l) then
    Exit(True);
  c := 0;
  for i := 0 to (l - 1) do
    if ((Self[i] = mItem) and (c.Increment > target)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <CountBetween>
  @action: Returns True if the number of elements matching 'mItem' falls within
           the inclusive range of minTarget to maxTarget.
  @param: minTarget Minimum number of matches required (inclusive floor).
  @param: maxTarget Maximum number of matches allowed (inclusive ceiling).
  @param: mItem The specific element value to search and match against.
  @return: True if minTarget <= match count <= maxTarget, otherwise False.
  @note: Implements advanced predictive short-circuit optimization. Continuously
         checks if maxTarget is exceeded (immediate False), if minTarget can no
         longer be achieved mathematically (immediate False), or if the remaining
         elements guarantee a safe landing inside the range bounds (immediate True).
[==============================================================================}
function MArrayHelper.CountBetween(const minTarget, maxTarget: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l, r: Integer;
begin
  l := Self.Length;
  if ((maxTarget < 0) or (minTarget > maxTarget) or (minTarget > l)) then
    Exit(False);
  if (minTarget <= 0) then
    if (maxTarget >= l) then
      Exit(True);
  c := 0;
  for i := 0 to (l - 1) do
    if (Self[i] = mItem) then
    begin
      if (c.Increment > maxTarget) then
        Exit(False);
      r := (l - 1 - i);
      if ((c + r) < minTarget) then
        Exit(False);
      if ((c >= minTarget) and ((c + r) <= maxTarget)) then
        Exit(True);
    end;
  Result := ((c >= minTarget) and (c <= maxTarget));
end;

{==============================================================================]
  <CountExactly>
  @action: Returns True if the array contains exactly 'target' elements matching 'mItem'.
  @param: target The exact number of matches required.
  @param: mItem The specific element value to search and match against.
  @return: True if match count == target, otherwise False.
  @note: Implements rigorous dual-sided predictive short-circuiting. Exits early
         with False if matches exceed the target, or if the number of remaining
         unprocessed elements makes it mathematically impossible to reach the target.
         Optimized fast-paths exist for extreme targets (0 or array length).
[==============================================================================}
function MArrayHelper.CountExactly(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if ((target < 0) or (target > l)) then
    Exit(False);
  if (target = 0) then
  begin
    for i := 0 to (l - 1) do
      if (Self[i] = mItem) then
        Exit(False);
    Exit(True);
  end;
  if (target = l) then
  begin
    for i := 0 to (l - 1) do
      if (Self[i] <> mItem) then
        Exit(False);
    Exit(True);
  end;
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] = mItem) and (c.Increment > target)) then
      Exit(False);
    if ((c + (l - 1 - i)) < target) then
      Exit(False);
  end;
  Result := (c = target);
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
  <Existence>
  @action: Checks if a specific item exists within the array by scanning it from end to start.
  @note: Returns True if found, False otherwise. Time complexity is O(N).
[==============================================================================}
function MArrayHelper.Existence(const mItem: MType): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while ((h > -1) and (Self[h] <> mItem)) do
    Dec(h);
  Result := (h > -1);
end;

{==============================================================================]
  <Existency>
  @action: Explicitly loops backward through the array to check if the specified item exists.
  @note: Scans from the highest index down to 0, short-circuiting and returning True immediately if a match is found.
[==============================================================================}
function MArrayHelper.Existency(const mItem: MType): Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 0 do
    if (Self[i] = mItem) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Existing>
  @action: Iterates through the array to determine if the specified item is present.
  @note: Uses a for-in enumerator for a forward-scan; stops and returns True immediately upon the first match (short-circuiting).
[==============================================================================}
function MArrayHelper.Existing(const mItem: MType): Boolean; overload;
var
  s: MType;
begin
  for s in Self do
    if (s = mItem) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Extant>
  @action: Checks whether a specific item exists within the array.
  @note: If 'backwardScan' is False, the array is scanned normally from 0 to High. 
         If 'backwardScan' is True, the array is scanned in reverse from High downto 0.
[==============================================================================}
function MArrayHelper.Extant(const mItem: MType; const backwardScan: Boolean = False): Boolean; overload;
begin
  if not backwardScan then
    Result := (Self.Count(mItem) > 0)
  else
    Result := (Self.CountOf(mItem) > 0);
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
  <HasMajority>
  @action: Returns True if strictly more than half of the elements in the array match 'mItem'.
  @param: mItem The element value to evaluate for dominance.
  @return: True if match count > (Length / 2); False otherwise.
  @note: Implements predictive short-circuit optimization. Exits with True early
         if the match count can no longer be beaten, or False early if the
         remaining elements are insufficient to reach a majority.
[==============================================================================}
function MArrayHelper.HasMajority(const mItem: MType): Boolean; overload;
var
  i, c, l, h: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(False);
  h := (l div 2);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] = mItem) and (c.Increment > h)) then
      Exit(True);
    if ((c + (l - i - 1)) <= h) then
      Exit(False);
  end;
  Result := (c > h);
end;

{==============================================================================]
  <HasNone>
  @action: Returns True if the array contains zero elements matching 'mItem'.
  @param: mItem The specific element value that must not exist in the array.
  @return: True if no matches are found; False if at least one match exists.
  @note: Implements early short-circuiting, exiting with False the exact moment 
         a matching element is encountered. Vacuously true for empty arrays.
[==============================================================================}
function MArrayHelper.HasNone(const mItem: MType): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] = mItem) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <HasOnly>
  @action: Returns True if every single element in the array matches 'mItem'.
  @param: mItem The specific element value that all elements must equal.
  @return: True if all elements match and the array is not empty; False otherwise.
  @note: Implements early short-circuiting, exiting with False the exact moment 
         a non-matching element is encountered. Returns False for empty arrays 
         to guarantee the array is exclusively populated by 'mItem'.
[==============================================================================}
function MArrayHelper.HasOnly(const mItem: MType): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] <> mItem) then
      Exit(False);
  Result := (Self.Length > 0);
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
  <MeetsBetween>
  @action: Returns True if the number of elements matching 'mItem' falls within
           the inclusive range of minTarget to maxTarget.
  @param: minTarget Minimum number of matches required (inclusive floor).
  @param: maxTarget Maximum number of matches allowed (inclusive ceiling).
  @param: mItem The specific element value to search and match against.
  @return: True if minTarget <= match count <= maxTarget, otherwise False.
  @note: Implements an advanced, predictive lookahead algorithm. Continuously
         evaluates if maxTarget is exceeded (immediate False), if minTarget is
         statistically unreachable (immediate False), or if remaining array
         capacity guarantees a final count within the target bounds (immediate True).
[==============================================================================}
function MArrayHelper.MeetsBetween(const minTarget, maxTarget: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if ((maxTarget < 0) or (minTarget > maxTarget) or (minTarget > l)) then
    Exit(False);
  if ((minTarget <= 0) and (maxTarget >= l)) then
    Exit(True);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] = mItem) and (c.Increment > maxTarget)) then
      Exit(False);
    if ((c + (l - i - 1)) < minTarget) then
      Exit(False);
    if ((c >= minTarget) and ((c + (l - i - 1)) <= maxTarget)) then
      Exit(True);
  end;
  Result := ((c >= minTarget) and (c <= maxTarget));
end;

{==============================================================================]
  <MeetsCeiling>
  @action: Returns True if the array contains at most 'target' elements matching 'mItem'.
  @param: target Maximum number of matches permitted (inclusive ceiling capacity).
  @param: mItem The specific element value to search and match against.
  @return: True if match count <= target, otherwise False.
  @note: Implements lookahead short-circuiting. Exits with False early if the match
         count increments past the target limit, or exits with True early if the
         remaining potential elements cannot push the counter over the target ceiling.
[==============================================================================}
function MArrayHelper.MeetsCeiling(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, c, m, l: Integer;
begin
  if (target < 0) then
    Exit(False);
  l := Self.Length;
  if (target >= l) then
    Exit(True);
  c := 0;
  m := l;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] = mItem) and (c.Increment > target)) then
      Exit(False);
    if ((c + m.Decrement) <= target) then
      Exit(True);
  end;
  Result := (c <= target);
end;

{==============================================================================]
  <MeetsExact>
  @action: Returns True if the array contains exactly 'target' elements matching 'mItem'.
  @param: target The exact number of matches required.
  @param: mItem The specific element value to search and match against.
  @return: True if match count == target, otherwise False.
  @note: Implements rigorous dual-sided predictive short-circuiting. Exits early
         with False the moment the match count exceeds the target, or when the
         unprocessed array pool is mathematically too small to reach the target.
[==============================================================================}
function MArrayHelper.MeetsExact(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if ((target < 0) or (target > l)) then
    Exit(False);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] = mItem) and (c.Increment > target)) then
      Exit(False);
    if ((c + (l - i - 1)) < target) then
      Exit(False);
  end;
  Result := (c = target);
end;

{==============================================================================]
  <MeetsFloor>
  @action: Returns True if the array contains at least 'target' elements matching 'mItem'.
  @param: target Minimum number of matches required (inclusive floor threshold).
  @param: mItem The specific element value to search and match against.
  @return: True if match count >= target, otherwise False.
  @note: Implements a branchless accumulation scan starting from the back of
         the array moving forward. It exits the moment the required target quota
         is fulfilled or the array boundaries are exhausted.
[==============================================================================}
function MArrayHelper.MeetsFloor(const target: Integer; const mItem: MType): Boolean; overload;
var
  i, l: Integer;
begin
  if (target <= 0) then
    Exit(True);
  l := Self.Length;
  if (target > l) then
    Exit(False);
  i := 0;
  while ((l.Decrease > 0) and (i < target)) do
    Inc(i, Ord(Self[l] = mItem));
  Result := (i >= target);
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
{$ENDIF}
