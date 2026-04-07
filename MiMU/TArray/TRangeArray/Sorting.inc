{$IFDEF HELPERS}
function Sort(const oAscending: Boolean = True): Integer; overload;
function SortByMaximum(const oAscending: Boolean = True): Integer; overload;
function SortByMinimum(const oAscending: Boolean = True): Integer; overload;
function SortBySize(const oAscending: Boolean = True): Integer; overload;
function SortBySizes(var rSizes: TIntegerArray; const oAscending: Boolean): Integer; overload;
function SortBySizing(const oAscending: Boolean): Integer; overload;
function SortByStart(const oAscending: Boolean = True): Integer; overload;
function SortByStop(const oAscending: Boolean = True): Integer; overload;
function SortedByMaximum(const oAscending: Boolean = True): TRangeArray; overload;
function SortedByMinimum(const oAscending: Boolean = True): TRangeArray; overload;
function SortedBySize(const rAscending: Boolean): TRangeArray; overload;
function SortedByStart(const oAscending: Boolean = True): TRangeArray; overload;
function SortedByStop(const oAscending: Boolean = True): TRangeArray; overload;
function SortedWithSize(const rAscending: Boolean): TRangeArray; overload;
function SortingBySize(const oAscending: Boolean): Integer; overload;
function SortWithSizing(const oAscending: Boolean): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sort>
  @action: Sorts ranges in-place using quicksort, ordering by start then stop via Comparison.
  @note: Direction controlled by oAscending (True=ascending, False=descending);
         uses middle pivot and recursive partitioning;
		 unstable sort; average O(n log n), worst O(n^2); returns element count.
[==============================================================================}
function TRangeArrayHelper.Sort(const oAscending: Boolean = True): Integer; overload;
  procedure QS(L, R: Integer);
  var
    I, J: Integer;
    P: TRange;
  begin
    I := L;
    J := R;
    P := Self[(L + R) div 2];
    repeat
      case oAscending of
        True:
        begin
          while (Self[I].Comparison(P) < 0) do
            Inc(I);
          while (Self[J].Comparison(P) > 0) do
            Dec(J);
        end;
        False:
        begin
          while (Self[I].Comparison(P) > 0) do
            Inc(I);
          while (Self[J].Comparison(P) < 0) do
            Dec(J);
        end;
      end;
      if (I <= J) then
	    Swap(Self[I.Increase], Self[J.Decrease]);
    until (I > J);
    if (L < J) then
      QS(L, J);
    if (I < R) then
      QS(I, R);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortByMaximum>
  @action: Sorts array in-place by `Maximum` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Depends on `Maximum` accessor (e.g. normalized upper bound).
         Modifies Self directly. Recursion depth depends on distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByMaximum(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].Maximum;
    repeat
      while ((oAscending and (Self[i].Maximum < p)) or ((not oAscending) and (Self[i].Maximum > p))) do
        Inc(i);
      while ((oAscending and (Self[j].Maximum > p)) or ((not oAscending) and (Self[j].Maximum < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortByMinimum>
  @action: Sorts array in-place by `Minimum` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Depends on `Minimum` accessor (e.g. normalized lower bound).
         Modifies Self directly. Recursion depth depends on distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByMinimum(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].Minimum;
    repeat
      while ((oAscending and (Self[i].Minimum < p)) or ((not oAscending) and (Self[i].Minimum > p))) do
        Inc(i);
      while ((oAscending and (Self[j].Minimum > p)) or ((not oAscending) and (Self[j].Minimum < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortBySize>
  @action: Sorts the TRangeArray in-place by the size of its elements.
           The sorting order is determined by the oAscending parameter:
             - True: ascending (smallest to largest)
             - False: descending (largest to smallest)
  @note: Returns the number of elements in the array.
         If the array has fewer than 2 elements, no sorting is performed.
[==============================================================================}
function TRangeArrayHelper.SortBySize(const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Length;
  if (Result > 1) then
  case oAscending of
    True: Result := specialize QuickSort<TRange>(Self, @TRange.CompareSizeAscending);
    False: Result := specialize QuickSort<TRange>(Self, @TRange.CompareSizeDescending);
  end;
end;

{==============================================================================]
  <SortBySizes>
  @action: Sorts Self in-place using the provided rSizes as sort keys.
             - Ascending  (oAscending = True)  : smallest -> largest
             - Descending (oAscending = False) : largest  -> smallest (via reverse)
           Reorders rSizes alongside Self to preserve index alignment.
  @note: Implements LSD radix sort (base 10) over rSizes.
           - Stable sorting per digit pass
           - Non-comparative (integer key based)
           - Time complexity: O(d * n)
         where:
         n = number of elements
         d = number of digits in max(rSizes)
           - Space complexity: O(n + 10)
         Preconditions:
           - Length(Self) = Length(rSizes)
           - Result >= 2 (otherwise no operation is performed)
         Implementation details:
           - Iterates digits from least to most significant (e = 1, 10, 100, ...)
           - Counting array c[0..9] accumulates digit frequencies
           - Reverse traversal ensures stability
           - Temporary buffers:
             r : reordered elements
             s : reordered sizes
         Final descending order is achieved by symmetric in-place reversal
         of both Self and rSizes.
         Returns the number of elements (Length).
[==============================================================================}
function TRangeArrayHelper.SortBySizes(var rSizes: TIntegerArray; const oAscending: Boolean): Integer; overload;
var
  r: TRangeArray;
  s: TIntegerArray;
  h, i, j, e, d, m: Integer;
  c: array[0..9] of Integer;
begin
  Result := Self.Length;
  h := High(rSizes);
  if ((Result < 2) or (Result <> (h + 1))) then
    Exit;
  SetLength(s, Result);
  m := 0;
  for i := 0 to h do
    if (rSizes[i] > m) then
      m := rSizes[i];
  e := 1;
  SetLength(r, Result);
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[(rSizes[i] div e) mod 10]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
    begin
      d := ((rSizes[i] div e) mod 10);
      Dec(c[d]);
      r[c[d]] := Self[i];
      s[c[d]] := rSizes[i];
    end;
    for i := 0 to h do
    begin
      Self[i] := r[i];
      rSizes[i] := s[i];
    end;
    e := (e * 10);
  end;
  if not oAscending then
  for i := 0 to ((Result div 2) - 1) do
  begin
    d := (Result - 1 - i);
    r[i] := Self[i];
    s[i] := rSizes[i];
    Self[i] := Self[d];
    rSizes[i] := rSizes[d];
    Self[d] := r[i];
    rSizes[d] := s[i];
  end;
end;

{==============================================================================]
  <SortBySizing>
  @action: Sorts the array in-place by TRange.Size.
            - Ascending  (oAscending = True)  : smallest -> largest
            - Descending (oAscending = False) : largest  -> smallest
  @note: Uses insertion sort.
          - Stable (preserves order of equal elements)
          - Time complexity:
              Best    : O(n)
              Average : O(n^2)
              Worst   : O(n^2)
          - Space complexity: O(1) (in-place)
         Optimized for small or nearly sorted datasets.
         Returns the number of elements (Length).
[==============================================================================}
function TRangeArrayHelper.SortBySizing(const oAscending: Boolean): Integer; overload;
var
  i, j, s: Integer;
  r: TRange;
begin
  Result := Self.Length;
  for i := 1 to (Result - 1) do
  begin
    r := Self[i];
    s := r.Size;
    j := (i - 1);
    while ((j >= 0) and ((oAscending and (Self[j].Size > s)) or ((not oAscending) and (Self[j].Size < s)))) do
    begin
      Self[j + 1] := Self[j];
      Dec(j);
    end;
    Self[j + 1] := r;
  end;
end;

{==============================================================================]
  <SortByStart>
  @action: Sorts array in-place by `start` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Modifies Self directly. Recursion depth depends on data distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByStart(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].start;
    repeat
      while ((oAscending and (Self[i].start < p)) or ((not oAscending) and (Self[i].start > p))) do
        Inc(i);
      while ((oAscending and (Self[j].start > p)) or ((not oAscending) and (Self[j].start < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortByStop>
  @action: Sorts array in-place by `stop` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Modifies Self directly. Recursion depth depends on data distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByStop(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].stop;
    repeat
      while ((oAscending and (Self[i].stop < p)) or ((not oAscending) and (Self[i].stop > p))) do
        Inc(i);
      while ((oAscending and (Self[j].stop > p)) or ((not oAscending) and (Self[j].stop < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortedByMaximum>
  @action: Returns new array sorted by `Maximum` using QuickSort (asc/desc).
  @note: Non-destructive (works on copy). Not stable. Avg O(n log n), worst O(n^2).
         Mid pivot ((l+r) div 2). Bidirectional partition (i/j).
         Swap uses Increase/Decrease side-effects.
         Depends on `Maximum` accessor (normalized upper bound).
         Recursion depth depends on distribution. Length preserved.
[==============================================================================}
function TRangeArrayHelper.SortedByMaximum(const oAscending: Boolean = True): TRangeArray; overload;
  procedure QS(var A: TRangeArray; L, R: Integer);
  var
    I, J, P: Integer;
  begin
    I := L;
    J := R;
    P := A[(L + R) div 2].Maximum;
    repeat
      while ((oAscending and (A[I].Maximum < P)) or ((not oAscending) and (A[I].Maximum > P))) do
        Inc(I);
      while ((oAscending and (A[J].Maximum > P)) or ((not oAscending) and (A[J].Maximum < P))) do
        Dec(J);
      if (I <= J) then
        Swap(A[I.Increase], A[J.Decrease]);
    until (I > J);
    if (L < J) then
      QS(A, L, J);
    if (I < R) then
      QS(A, I, R);
  end;
begin
  Result := Self.Copy;
  if (Result.Length > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <SortedByMinimum>
  @action: Returns new array sorted by `Minimum` using QuickSort (asc/desc).
  @note: Non-destructive (works on copy). Not stable. Avg O(n log n), worst O(n^2).
         Mid pivot ((l+r) div 2). Bidirectional partition (i/j).
         Swap uses Increase/Decrease side-effects.
         Depends on `Minimum` accessor (normalized lower bound).
         Recursion depth depends on distribution. Length preserved.
[==============================================================================}
function TRangeArrayHelper.SortedByMinimum(const oAscending: Boolean = True): TRangeArray; overload;
  procedure QS(var A: TRangeArray; L, R: Integer);
  var
    I, J, P: Integer;
  begin
    I := L;
    J := R;
    P := A[(L + R) div 2].Minimum;
    repeat
      while ((oAscending and (A[I].Minimum < P)) or ((not oAscending) and (A[I].Minimum > P))) do
        Inc(I);
      while ((oAscending and (A[J].Minimum > P)) or ((not oAscending) and (A[J].Minimum < P))) do
        Dec(J);
      if (I <= J) then
        Swap(A[I.Increase], A[J.Decrease]);
    until (I > J);
    if (L < J) then
      QS(A, L, J);
    if (I < R) then
      QS(A, I, R);
  end;
begin
  Result := Self.Copy;
  if (Result.Length > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <SortedBySize>
  @action: Returns a new array sorted by TRange.Size.
             - Ascending  (rAscending = True)  : smallest -> largest
             - Descending (rAscending = False) : largest  -> smallest (via reverse)
  @note: Uses LSD radix sort (base 10) on Size values.
           - Non-comparative integer sorting
           - Stable (preserves order of equal elements)
           - Time complexity: O(d * n)
             where:
             n = number of elements
             d = number of digits in max(Size)
           - Space complexity: O(n + k)
             where:
             k = radix (10)
         Implementation details:
           - Operates on a copy (original array is not modified)
           - Uses counting sort per digit pass
           - Auxiliary arrays:
             s : caches Size values
             r : temporary output buffer
             c : digit frequency (0..9)
         Efficient for large datasets with bounded integer sizes.
[==============================================================================}
function TRangeArrayHelper.SortedBySize(const rAscending: Boolean): TRangeArray; overload;
var
  r: TRangeArray;
  s: TIntegerArray;
  h, m, e, i, l: Integer;
  c: array[0..9] of Integer;
begin
  l := Self.Length;
  Result := Self.Copy;
  if (l = 0) then
    Exit;
  SetLength(s, l);
  m := 0;
  h := (l - 1);
  for i := 0 to h do
  begin
    s[i] := Result[i].Size;
    if (s[i] > m) then
      m := s[i];
  end;
  e := 1;
  SetLength(r, l);
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[((s[i] div e) mod 10)]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
      r[c[(s[i] div e) mod 10].Decrement] := Result[i];
    for i := 0 to h do
      Result[i] := r[i];
    for i := 0 to h do
      s[i] := Result[i].Size;
    e := (e * 10);
  end;
  if not rAscending then
    Result.Reverse;
end; 

{==============================================================================]
  <SortedByStart>
  @action: Returns new array sorted by `start` using QuickSort (asc/desc).
  @note: Non-destructive (works on copy). Not stable. Avg O(n log n), worst O(n^2).
         Mid pivot ((l+r) div 2). Bidirectional partition (i/j).
         Swap uses Increase/Decrease side-effects.
         Operates on raw `start` field (no normalization implied).
         Recursion depth depends on distribution. Length preserved.
[==============================================================================}
function TRangeArrayHelper.SortedByStart(const oAscending: Boolean = True): TRangeArray; overload;
  procedure QS(var A: TRangeArray; L, R: Integer);
  var
    I, J, P: Integer;
  begin
    I := L;
    J := R;
    P := A[(L + R) div 2].start;
    repeat
      while ((oAscending and (A[I].start < P)) or ((not oAscending) and (A[I].start > P))) do
        Inc(I);
      while ((oAscending and (A[J].start > P)) or ((not oAscending) and (A[J].start < P))) do
        Dec(J);
      if (I <= J) then
        Swap(A[I.Increase], A[J.Decrease]);
    until (I > J);
    if (L < J) then
      QS(A, L, J);
    if (I < R) then
      QS(A, I, R);
  end;
begin
  Result := Self.Copy;
  if (Result.Length > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <SortedByStop>
  @action: Returns new array sorted by `stop` using QuickSort (asc/desc).
  @note: Non-destructive (works on copy). Not stable. Avg O(n log n), worst O(n^2).
         Mid pivot ((l+r) div 2). Bidirectional partition (i/j).
         Swap uses Increase/Decrease side-effects.
         Operates on raw `stop` field (no normalization implied).
         Recursion depth depends on distribution. Length preserved.
[==============================================================================}
function TRangeArrayHelper.SortedByStop(const oAscending: Boolean = True): TRangeArray; overload;
  procedure QS(var A: TRangeArray; L, R: Integer);
  var
    I, J, P: Integer;
  begin
    I := L;
    J := R;
    P := A[(L + R) div 2].stop;
    repeat
      while ((oAscending and (A[I].stop < P)) or ((not oAscending) and (A[I].stop > P))) do
        Inc(I);
      while ((oAscending and (A[J].stop > P)) or ((not oAscending) and (A[J].stop < P))) do
        Dec(J);
      if (I <= J) then
        Swap(A[I.Increase], A[J.Decrease]);
    until (I > J);
    if (L < J) then
      QS(A, L, J);
    if (I < R) then
      QS(A, I, R);
  end;
begin
  Result := Self.Copy;
  if (Result.Length > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <SortedWithSize>
  @action: Returns a new array sorted by TRange.Size.
             - Ascending  (rAscending = True)  : smallest -> largest
             - Descending (rAscending = False) : largest  -> smallest (via reverse)
             Self remains unchanged.
  @note: Uses LSD radix sort (base 10) on Size values.
           - Stable sorting
           - Non-comparative (integer key based)
           - Time complexity: O(d * n)
             where:
             n = number of elements
             d = number of digits in max(Size)
           - Space complexity: O(n + 10)
         Preconditions:
           - Handles empty input (returns [])
		 Implementation details:
           - Operates on a copy (Result := Self.Copy)
           - Extracts Size values into auxiliary array s
           - Processes digits from least to most significant
           - Counting sort per digit using c[0..9]
           - Reverse iteration ensures stability
           - Temporary buffer r used for redistribution
         Descending order is produced via final in-place reversal.
		 Efficient for larger datasets with bounded integer sizes.
[==============================================================================}
function TRangeArrayHelper.SortedWithSize(const rAscending: Boolean): TRangeArray; overload;
var
  r: TRangeArray;
  s: TIntegerArray;
  h, m, e, i, d, l: Integer;
  c: array[0..9] of Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  Result := Self.Copy;
  SetLength(s, l);
  m := 0;
  h := (l - 1);
  for i := 0 to h do
  begin
    s[i] := Result[i].Size;
    if (s[i] > m) then
      m := s[i];
  end;
  e := 1;
  SetLength(r, l);
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[((s[i] div e) mod 10)]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
    begin
      d := ((s[i] div e) mod 10);
      Dec(c[d]);
      r[c[d]] := Result[i];
    end;
    for i := 0 to h do
      Result[i] := r[i];
    for i := 0 to h do
      s[i] := Result[i].Size;
    e := (e * 10);
  end;
  if not rAscending then
    Result.Reverse;
end;

{==============================================================================]
  <SortingBySize>
  @action: Sorts Self in-place by TRange.Size.
             - Ascending  (oAscending = True)  : smallest -> largest
             - Descending (oAscending = False) : largest  -> smallest
  @note: Uses an in-place merge sort variant.
           - Stable (preserves order of equal elements)
           - Comparison-based sorting
           - Time complexity:
               Best    : O(n log n)
               Average : O(n^2)   (due to element shifting in merge step)
               Worst   : O(n^2)
           - Space complexity: O(1) auxiliary (in-place merge)
         Implementation details:
           - Recursive divide phase (MSA)
           - Merge phase (MA) performed in-place by shifting elements
             instead of using an external buffer
           - Stability preserved via controlled insertion of right-side elements
           - Sorting direction handled directly in comparison logic
         Trade-off:
           - Avoids extra memory allocation
           - Higher cost during merge due to repeated shifts
         Returns the number of elements (Length).
[==============================================================================}
function TRangeArrayHelper.SortingBySize(const oAscending: Boolean): Integer; overload;
procedure MA(var arr: TRangeArray; left, mid, right: Integer; const oAscending: Boolean);
var
  i, j, k: Integer;
  a: TRange;
begin
  i := left;
  j := (mid + 1);
  while ((i <= mid) and (j <= right)) do
  begin
    if not ((oAscending and (arr[i].Size <= arr[j].Size)) or ((not oAscending) and (arr[i].Size >= arr[j].Size))) then
    begin
      a := arr[j];
      for k := j downto (i + 1) do
        arr[k] := arr[k - 1];
      arr[i] := a;
      Inc(j);
      Inc(mid);
    end;
    Inc(i);
  end;
end;
procedure MSA(var arr: TRangeArray; left, right: Integer; const oAscending: Boolean);
var
  m: Integer;
begin
  if (left >= right) then
    Exit;
  m := ((left + right) div 2);
  MSA(arr, left, m, oAscending);
  MSA(arr, (m + 1), right, oAscending);
  MA(arr, left, m, right, oAscending);
end;
begin
  Result := Self.Length;
  if (Result > 0) then
    MSA(Self, 0, (Result - 1), oAscending);
end;

{==============================================================================]
  <SortWithSizing>
  @action: Sorts Self in-place by TRange.Size using merge sort.
             - Ascending  (oAscending = True)  : smallest -> largest
             - Descending (oAscending = False) : largest  -> smallest
  @note: Uses top-down merge sort (divide and conquer).
           - Stable (preserves order of equal elements)
           - Comparison-based sorting
           - Time complexity:
               Best    : O(n log n)
               Average : O(n log n)
               Worst   : O(n log n)
           - Space complexity: O(n) (temporary buffer)
         Implementation details:
           - Recursively splits array into halves (MSA)
           - Merges sorted halves using auxiliary buffer (MA)
           - Comparison is performed on TRange.Size
           - Direction controlled directly in merge step
             (no post-reversal required)
         Suitable for large datasets with consistent performance.
		 Returns the number of elements (Length).
[==============================================================================}
function TRangeArrayHelper.SortWithSizing(const oAscending: Boolean): Integer; overload;
procedure MA(var arr: TRangeArray; var temp: TRangeArray; left, mid, right: Integer; const oAscending: Boolean);
var
  i, j, k: Integer;
begin
  i := left;
  j := (mid + 1);
  k := left;
  while ((i <= mid) and (j <= right)) do
    if ((oAscending and (arr[i].Size <= arr[j].Size)) or ((not oAscending) and (arr[i].Size >= arr[j].Size))) then
      temp[k.Increase] := arr[i.Increase]
    else
      temp[k.Increase] := arr[j.Increase];
  while i <= mid do
    temp[k.Increase] := arr[i.Increase];
  while j <= right do
    temp[k.Increase] := arr[j.Increase];
  for i := left to right do
    arr[i] := temp[i];
end;
procedure MSA(var arr: TRangeArray; var temp: TRangeArray; left, right: Integer; const oAscending: Boolean);
var
  m: Integer;
begin
  if (left >= right) then
    Exit;
  m := ((left + right) div 2);
  MSA(arr, temp, left, m, oAscending);
  MSA(arr, temp, (m + 1), right, oAscending);
  MA(arr, temp, left, m, right, oAscending);
end;
var
  t: TRangeArray;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  SetLength(t, Result);
  MSA(Self, t, 0, (Result - 1), oAscending);
end;
{$ENDIF}
