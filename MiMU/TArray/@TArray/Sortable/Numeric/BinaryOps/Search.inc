{$IFDEF HELPERS}
function BinaryEstimate(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryInterp(const target: MType; const oAscending: Boolean = True): Double; overload;
function BinaryPinpoint(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryApproximateSearch(const value: MType; const tolerance: MType = 0; const oAscending: Boolean = True): Integer; overload;
function BinarySearchApproximate(const value: MType; const tolerance: MType = 0; const oAscending: Boolean = True): Integer; overload;
function BinaryQuest(const item: MType; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryEstimate>
  @action: Estimates the index of a given item in a sorted array using interpolation search.
  @note:
    • O(log n) on average (interpolation-based)
    • Requires sorted array (ascending or descending)
    • Returns index if item is found
    • Returns -1 if item is not present or out of bounds
    • Uses linear interpolation to estimate likely position
[==============================================================================}
function MArrayHelper.BinaryEstimate(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, h: MType;
  p: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  if ((R.stop < 0) or (oAscending and ((item < Self[R.start]) or (item > Self[R.stop]))) or ((not oAscending) and ((item > Self[R.start]) or (item < Self[R.stop])))) then
    Exit;
  while (R.start <= R.stop) do
  begin
    l := Self[R.start];
    h := Self[R.stop];
    if (l = h) then
      if (l = item) then
        Exit(R.start)
	  else
        Break;
    p := (R.start + Trunc((Double(item) - l) / (Double(h) - l) * (R.stop - R.start)));
    if ((p < R.start) or (p > R.stop)) then
      Break;
    if (Self[p] = item) then
      Exit(p);
    if ((oAscending and (Self[p] < item)) or ((not oAscending) and (Self[p] > item))) then
      R.start := (p + 1)
    else
      R.stop := (p - 1);
  end;
end;

{==============================================================================]
  <BinaryInterp>
  @action: Performs an **interpolation search** on a sorted array to estimate
           the fractional index of a given target value.
           Behavior:
           - Finds the lower and upper bounds (L and R) around the target.
           - If L = R or the values at L and R are equal, returns L.
           - Otherwise, returns a fractional index computed by linear interpolation:
               Result := L + (target - Self[L]) / (Self[R] - Self[L])
           The fractional index can be used to **estimate the position** of the target
           between array elements, useful for smooth scaling or interpolation tasks.
  @note:   The array must already be sorted according to `oAscending`.
           - Returns a **Double**, not an index.
           - If the target is outside the array bounds, the formula may produce
             a fractional index beyond 0..Length-1.
           - Returns -1 if L or R are not found (i.e., array is empty or target not within bounds).
           - Time complexity is O(log n), using binary search to find bounds first.
           - Works best for **uniformly distributed data**; accuracy decreases for skewed distributions.
[==============================================================================}
function MArrayHelper.BinaryInterp(const target: MType; const oAscending: Boolean = True): Double; overload;
var
  L, R: Integer;
begin
  L := Self.BinaryLeftBound(target, oAscending);
  R := Self.BinaryRightBound(target, oAscending);
  if ((L = R) or (Self[R] = Self[L])) then
    Exit(L);
  Result := (L + ((target - Self[L]) / (Self[R] - Self[L])));
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
function MArrayHelper.BinaryPinpoint(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  D: MType;
  H: Integer;
begin
  H := High(Self);
  case H of
    -1: Exit(-1);
    0: Exit(0);
  end;
  Result := Self.BinaryRank(item, aAscending);
  if (Result > H) then
    Exit(H);
  if (Result < 0) then
    Exit(0);
  if (Self[Result] = item) then
    Exit;
  D := item.Distance(Self[Result]);
  if (Result = 0) then
     Exit(IfThen((D < item.Distance(Self[Result + 1])), Result, (Result + 1)));
  if (Result = H) then
    Exit(IfThen((D < item.Distance(Self[Result - 1])), Result, (Result - 1)));
  if (D > item.Distance(Self[Result - 1])) then
    Dec(Result)
  else if (D > item.Distance(Self[Result + 1])) then
    Inc(Result);
end;

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function MArrayHelper.BinaryPosOf(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  C: MType;
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := (item - Self[M]);
    if (C = 0) then
      Exit(M);
    if not oAscending then
      C := -C;
    if (C < 0) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
end;

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================}
function MArrayHelper.BinaryApproximateSearch(const value: MType; const tolerance: MType = 0; const oAscending: Boolean = True): Integer; overload;
var
  H, D: MType;
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if (Self.Empty or (tolerance < 0)) then
    Exit;
  H := High(Integer);
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      D := Abs(Self[M] - value);
      if (D = 0) then
        Exit(M);
      if ((D <= tolerance) and (D < H)) then
      begin
        Result := M;
        H := D;
      end;
      if (Self[M] < value) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      D := Abs(Self[M] - value);
      if (D = 0) then
        Exit(M);
      if ((D <= tolerance) and (D < H)) then
      begin
        Result := M;
        H := D;
      end;
      if (Self[M] > value) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function MArrayHelper.BinarySearchApproximate(const value: MType; const tolerance: MType = 0; const oAscending: Boolean = True): Integer; overload;
var
  c: Integer;
begin
  c := Self.BinaryClosest(value, oAscending);
  if ((c = -1) or (Abs(Self[c] - value) > tolerance)) then
    Result := -1
  else
    Result := c;
end;

{==============================================================================]
  <BinaryQuest>
  @action: Binary search for item in the array, returning its index.
  @note:
    - Self must already be sorted according to aAscending.
    - Returns -1 if item is not found.
    - If item appears multiple times, the returned index is whichever
      match the binary search happens to land on first — not guaranteed
      to be the first or last occurrence. Use BinaryLeftpos/BinaryRightpos
      if a specific boundary is required.
[==============================================================================}
function MArrayHelper.BinaryQuest(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  s: MType;
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  s := (o * item);
  r.Create(0, High(Self));
  while (r.Asceal and (Result = -1)) do
  begin
    m := r.Pivot;
    if ((o * Self[m]) = s) then
      Result := m
    else if ((o * Self[m]) < s) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
end;
{$ENDIF}
