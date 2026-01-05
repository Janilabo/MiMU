{$IFDEF HELPERS}
function BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
function BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload;
function BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload;
function BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLookup(const value: Integer): Integer; overload;
function BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer; overload;
function BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
function BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
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
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  O, M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  O := IfThen(oAscending, 1, -1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (value.Compare(Self[M]) * O) of
      0: Exit(M);
      -1: R.stop := (M - 1);
      1: R.start := (M + 1);
    end;
  end;
end;

function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while ((R.stop - R.start) > threshold) do
  begin
    M := R.Pivot;
    if (Self[M] = value) then
      Exit(M);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  for M := R.start to R.stop do
    if (Self[M] = value) then
      Exit(M);
end;

function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while ((R.stop - R.start) > threshold) do
  begin
    M := R.Pivot;
    if (Self[M] = value) then
      Exit(M);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  for M := R.start to R.stop do
    if (Self[M] = value) then
      Exit(M);
end;

{==============================================================================]
  <BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while (r.Ascending and (Result = -1)) do
  begin
    m := r.Pivot;
    if ((o * Self[m]) = (o * x)) then
      Result := m
    else
      if ((o * Self[m]) < (o * x)) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
  end;
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
  <BinarySeek>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer;
var
  i: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while r.Ascends do
  begin
    i := r.Pivot;
    if (Self[i] = x) then
      Exit(i);
    if ((aAscending and (Self[i] < x)) or ((not aAscending) and (Self[i] > x))) then
      r.start := (i + 1)
    else
      r.stop := (i - 1);
  end;
end;

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search on a sorted integer array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = val) then
      Exit(m);
    if (IfThen(aAscending, Ord(Self[m] < val), Ord(Self[m] > val)) <> 0) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinarySearchEx>
  @action: Performs a binary search on a sorted integer array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload;
var
  m, l, r: Integer;
  s: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Center;
    if (Self[m] = ignore) then
    begin
      l := (m - 1);
      r := (m + 1);
      while ((l >= s.start) or (r <= s.stop)) do
      begin
        if ((l >= s.start) and (Self[l] <> ignore)) then
        begin
          m := l;
          Break;
        end;
        if ((r <= s.stop) and (Self[r] <> ignore)) then
        begin
          m := r;
          Break;
        end;
        Dec(l);
        Inc(r);
      end;
      if ((l < s.start) and (r > s.stop)) then
        Exit(-1);
    end;
    case (Self[m] = x) of
      False:
      if IfThen(aAscending, (Self[m] < x), (Self[m] > x)) then
        s.start := (m + 1)
      else
        s.stop := (m - 1);
      True: Exit(m);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(rLeft, rRight);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
      Exit(M)
    else
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TIntegerArrayHelper.BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = x) of
      True:
      begin
        while ((m > 0) and (Self[m - 1] = x)) do
          Dec(m);
        Exit(m);
      end;
      False:
      if ((aAscending and (Self[m] < x)) or ((not aAscending) and (Self[m] > x))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  Result := r.start;
end;

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m] = x) then
      Exit(m)
    else
      if ((aAscending and (Self[m] < x)) or ((not aAscending) and (Self[m] > x))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified integer value within
           a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TIntegerArrayHelper.BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload;
var
  R, M: Integer;
begin
  Result := 0;
  R := Self.Size;
  while (Result < R) do
  begin
    M := ((Result + R) div 2);
    if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
      Result := (M + 1)
    else
      R := M;
  end;
end;

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryLookup(const value: Integer): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop > -1) then
  case (Self[R.start] <= Self[R.stop]) of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
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

function TIntegerArrayHelper.BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
  function BS(const L, R: Integer): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if (Self[M] = value) then
      Exit(M);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;

function TIntegerArrayHelper.BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
begin
  if ((L > R) or (L < 0) or (R > High(Self))) then
    Exit(-1);
  M := (L + ((R - L) div 2));
  if (Self[M] = value) then
    Exit(M);
  if ((aAscending and (value < Self[M])) or ((not aAscending) and (value > Self[M]))) then
    Result := Self.BinarySearchSpan(value, L, (M - 1), aAscending)
  else
    Result := Self.BinarySearchSpan(value, (M + 1), R, aAscending);
end;

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
function TIntegerArrayHelper.BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  case oAscending of
    True:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < value) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
    False:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > value) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;

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
function TIntegerArrayHelper.BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  if ((N < 0) or (N > High(Self))) then
    Exit(-1);
  Result := Self.BinarySearchFirst(value, oAscending);
  if (Result > -1) then
    Inc(Result, N);
  if ((Result > -1) and ((Result > High(Self)) or (Self[Result] <> value))) then
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
{$ENDIF}
