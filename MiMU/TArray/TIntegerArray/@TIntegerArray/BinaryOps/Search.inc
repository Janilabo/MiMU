{$IFDEF HELPERS}
function BinaryAdaptiveSearch(const item: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryEstimate(const item: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryInterp(const target: Integer; const oAscending: Boolean = True): Double; overload;
function BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer; overload;
function BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
function BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySnap(const target: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAdaptiveSearch>
  @action: Performs an adaptive divide-and-conquer search for `item` within the
           current sorted integer array. The pivot index is estimated using
           linear interpolation between the current range bounds, rather than
           using the midpoint. The search range is then reduced in a binary
           manner based on comparison results.
           Returns the index of a matching element if found; otherwise returns -1.
  @note:
    - The array must be monotonically sorted according to `oAscending`.
    - Pivot estimation uses interpolation:
        index ≈ start + (item - A[start]) * (range_length) / (A[stop] - A[start])
    - The computed pivot is clamped to the active search range to
      prevent out-of-bounds access.
    - If A[start] = A[stop], interpolation degenerates to a single-point check.
    - Average complexity: O(log log n) for uniformly distributed values.
    - Worst-case complexity: O(n) for highly skewed or clustered data.
    - If duplicates exist, any matching index may be returned.
    - No validation of sortedness is performed.
    - If the array is empty, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinaryAdaptiveSearch(const item: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  case oAscending of
    True:
    while ((R.start <= R.stop) and (item >= Self[R.start]) and (item <= Self[R.stop])) do
    begin
      if (Self[R.stop] = Self[R.start]) then
        M := R.start
      else
        M := (R.start + (Int64(item - Self[R.start]) * (R.stop - R.start)) div (Self[R.stop] - Self[R.start]));
      if (M < R.start) then
        M := R.start
      else if (M > R.stop) then
        M := R.stop;
      if (Self[M] = item) then
        Exit(M);
      if (Self[M] < item) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while ((R.start <= R.stop) and (item <= Self[R.start]) and (item >= Self[R.stop])) do
    begin
      if (Self[R.stop] = Self[R.start]) then
        M := R.start
      else
        M := (R.start + (Int64(item - Self[R.start]) * (R.stop - R.start)) div (Self[R.stop] - Self[R.start]));
      if (M < R.start) then
        M := R.start
      else if (M > R.stop) then
        M := R.stop;
      if (Self[M] = item) then
        Exit(M);
      if (Self[M] > item) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================}
function TIntegerArrayHelper.BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
var
  H, D, M: Integer;
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
  <BinaryEstimate>
  @action: Estimates the index of a given item in a sorted array using interpolation search.
  @note:
    • O(log n) on average (interpolation-based)
    • Requires sorted array (ascending or descending)
    • Returns index if item is found
    • Returns -1 if item is not present or out of bounds
    • Uses linear interpolation to estimate likely position
[==============================================================================}
function TIntegerArrayHelper.BinaryEstimate(const item: Integer; const oAscending: Boolean = True): Integer; overload;
var
  p, l, h: Integer;
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
  @action: Performs an **interpolation search** on a sorted integer array to estimate
           the fractional index of a given target value.
           Behavior:
           - Finds the lower and upper bounds (L and R) around the target.
           - If L = R or the values at L and R are equal, returns L.
           - Otherwise, returns a fractional index computed by linear interpolation:
               Result := L + (target - Self[L]) / (Self[R] - Self[L])
           The fractional index can be used to **estimate the position** of the target
           between array elements, useful for smooth scaling or interpolation tasks.
  @note:   The array must already be sorted according to `oAscending`.
           - Returns a **Double**, not an integer index.
           - If the target is outside the array bounds, the formula may produce
             a fractional index beyond 0..Length-1.
           - Returns -1 if L or R are not found (i.e., array is empty or target not within bounds).
           - Time complexity is O(log n), using binary search to find bounds first.
           - Works best for **uniformly distributed data**; accuracy decreases for skewed distributions.
[==============================================================================}
function TIntegerArrayHelper.BinaryInterp(const target: Integer; const oAscending: Boolean = True): Double; overload;
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
    else if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
      L := (M + 1)
    else
      H := (M - 1);
  end;
  Result := -1;
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
  else if (D > x.Distance(Self[Result + 1])) then
    Inc(Result);
end;

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  C, M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := (value - Self[M]);
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
    else if aAscending then
      M := (L + Trunc(EnsureRange((((x - Self[L]) / (Self[H] - Self[L])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)))
    else
      M := (L + Trunc(EnsureRange((((Self[L] - x) / (Self[L] - Self[H])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)));
    if (Self[M] = x) then
      Exit(M)
    else if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
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
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else if ((aAscending and (r.start > Self[M])) or ((not aAscending) and (r.start < Self[M]))) then
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
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
  <BinarySearchSpan>
  @action: Performs a recursive binary search within a specified sub-range [L, R] of a
           sorted array to locate any element whose value falls inside a given TRange,
           supporting ascending or descending order.
  @note: The array must be pre-sorted according to `aAscending` across the given
         [L, R] span. `range` is normalized internally, so its start/stop order does
         not matter. Returns the index of an element whose value lies within `range`
         (not guaranteed to be the first such element in the array), or -1 if none is
         found, or if L < 0 or R exceeds the array's upper bound.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BSS(const range: TRange; const L, R: Integer; const aAscending: Boolean): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if InRange(Self[M], range.start, range.stop) then
      Exit(M);
    if ((aAscending and (range.stop < Self[M])) or ((not aAscending) and (range.start > Self[M]))) then
      Result := BSS(range, L, (M - 1), aAscending)
    else if ((aAscending and (range.start > Self[M])) or ((not aAscending) and (range.stop < Self[M]))) then
      Result := BSS(range, (M + 1), R, aAscending);
  end;
begin
  if (L < 0) or (R > High(Self)) then
    Exit(-1);
  Result := BSS(range.Normalize, L, R, aAscending);
end;

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
  <BinarySnap>
  @action: Finds the index of the element **closest to the target value** in a sorted array.
           It uses BinaryLeft (first index ≥ target) and BinaryRight (last index ≤ target) 
           to determine the nearest element. The comparison is based on absolute difference.
           Behavior:
           - If the target exactly matches an element, returns that index.
           - If the target falls between two elements, returns the index of the element 
             with the smaller absolute difference.
           - If only one boundary exists (target outside array), returns that boundary.
  @param target is the value to snap to.
  @param oAscending indicates the sort order of the array.
           True  → ascending order
           False → descending order
  @note: The array must already be sorted according to `oAscending`.
         Time complexity is O(log n) because it performs two binary searches.
         Handles integer overflows safely by converting differences to Int64.
[==============================================================================}
function TIntegerArrayHelper.BinarySnap(const target: Integer; const oAscending: Boolean = True): Integer; overload;
var
  L, R: Integer;
begin
  L := Self.BinaryLeftBound(target, oAscending);
  R := Self.BinaryRightBound(target, oAscending);
  if (L = R) then
    Exit(L);
  if (L = -1) then
    Exit(R);
  if (R = -1) then
    Exit(L);
  if (Abs(Int64(Self[L]) - target) <= Abs(Int64(Self[R]) - target)) then
    Result := L
  else
    Result := R;
end;
{$ENDIF}
