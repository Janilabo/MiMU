{$IFDEF HELPERS}
function Broaden(const rValues: TRange; const aIndex: Integer): TRange; overload;
function Broaden(const rValues: TRange; const sSorted: Boolean = False): TRange; overload;
function ExpandGradient(const index: Integer; const tolerance: Integer): TRange;
function Spanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function Splay(const index: Integer; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
function Splay(const index: Integer; const limits: TRange; const tolerance: Integer = 1; const oAscending: Boolean = True): TRange; overload;
function Trace(const index: Integer; const tolerance: Integer = 1): TRange; overload;
function Trace(const index: Integer; const limits: TRange; const tolerance: Integer = 1): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
