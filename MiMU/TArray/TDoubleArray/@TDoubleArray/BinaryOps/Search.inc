{$IFDEF HELPERS}
function BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearch2(const x: Double; const aAscending: Boolean = True): Integer;
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
  <BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch2(const x: Double; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  s: Double;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  s := (o * x);
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
    else if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
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
  while r.Asceal do
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
