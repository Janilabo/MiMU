{$IFDEF HELPERS}
function BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload;
function BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
function BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryLookup(const value: Double): Integer; overload;
function BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: Double; const aAscending: Boolean = True): Integer;
function BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload;
function BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySeek(const x: Double; const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================} 
function TDoubleArrayHelper.BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
var
  H, D: Double;
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
  <BinaryFind>
  @action: Performs a binary search on a sorted double array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload;
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

function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
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

function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
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
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload;
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

function TDoubleArrayHelper.BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
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

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified double value within
           a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TDoubleArrayHelper.BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinaryLookup(const value: Double): Integer; overload;
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
function TDoubleArrayHelper.BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload;
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
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload;
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
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload;
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

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
var
  C: Double;
  M: Integer;
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
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TDoubleArrayHelper.BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload;
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
  <BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch(const x: Double; const aAscending: Boolean = True): Integer;
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
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
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
  <BinarySearchEx>
  @action: Performs a binary search on a sorted double array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload;
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
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
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

function TDoubleArrayHelper.BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
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

function TDoubleArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
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
  <BinarySeek>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySeek(const x: Double; const aAscending: Boolean = True): Integer;
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
{$ENDIF}
