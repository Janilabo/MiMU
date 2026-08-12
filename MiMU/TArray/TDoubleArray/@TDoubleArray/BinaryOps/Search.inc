{$IFDEF HELPERS}
function BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearch2(const x: Double; const aAscending: Boolean = True): Integer;
function BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
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
{$ENDIF}
