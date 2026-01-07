{$IFDEF HELPERS}
function BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange;
function BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange;
function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange;
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TDoubleArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange;
var
  h, m, o: Integer;
  f: Boolean;
begin
  f := False;
  h := High(Self);
  Result.Create(0, h);
  o := aAscending.Select(1, -1);
  while (Result.Ascending and (not f)) do
  begin
    m := Result.Pivot;
    f := ((o * Self[m]) = (o * x));
    if f then
	begin
      Result.Create(m, m);
      while ((Result.start > 0) and (Self[Result.start - 1] = x)) do
        Dec(Result.start);
      while ((Result.stop < h) and (Self[Result.stop + 1] = x)) do
        Inc(Result.stop);
    end else
      if ((o * Self[m]) < (o * x)) then
        Result.start := (m + 1)
      else
        Result.stop := (m - 1);
  end;
  if not f then
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(TRange.Construct(-1, -1));
  r := x.Normalize;
  case aAscending of
    True:
    begin
      Result.start := Self.BinaryFirst(r.start, aAscending);
      if (Result.start > -1) then
        Result.stop := Self.BinaryLast(r.stop, aAscending);
    end;
    False:
    begin
      Result.start := Self.BinaryFirst(r.stop, aAscending);
      if (Result.start > -1) then
        Result.stop := Self.BinaryLast(r.start, aAscending);
    end;
  end;
  if Result.Employs(-1) then
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload;
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific value in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) of
      False:
      begin
        r.stop := (m - 1);
        if (Self[m] = value) then
          Result.start := m;
      end;
      True: r.start := (m + 1);
    end;
  end;
  if Result.start = -1 then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of elements within a specified value range in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if no elements fall within the range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  n, r: TRange;
begin
  Result.Create(-1, -1);
  n := range.Normalize;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) of
      False:
      begin
        if ((Self[m] >= n.start) and (Self[m] <= n.stop)) then
          Result.start := m;
        r.stop := (m - 1);
      end;
      True: r.start := (m + 1);
    end;
  end;
  if (Result.start = -1) then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((Self[m] >= n.start) and (Self[m] <= n.stop)) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpan>
  @action: Performs a binary search on a sorted double array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TDoubleArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  n, r: TRange;
begin
  if Self.Empty then
    Exit(Result.Create(-1, -1));
  n := x.Normalize;
  r.Create(0, High(Self));
  case aAscending of
    True:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] < n.start) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] > n.stop) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if ((r.start > High(Self)) or (r.start < 0)) then
    Exit(Result.Create(-1, -1));
  Result.start := r.start;
  r.stop := High(Self);
  case aAscending of
    True:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] <= n.stop) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] >= n.start) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  Result.stop := r.stop;
  if ((Result.start > Result.stop) or (Result.start < 0) or (Result.stop > High(Self))) then
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - This function performs a binary search to find the first and last occurrences
      of the given value in the array.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of the value.
    - If the value is not found, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of values within a specified range in a sorted array.
  @note:
    - This function performs a binary search to find the first and last elements in the array
      that lie within the given range.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of elements within the range.
    - If no elements fall within the range, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of elements in the array that are within the specified range.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  n, r: TRange;
begin
  r.Create(0, High(Self));
  n := range.Normalize;
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.start))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.stop)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - Performs a binary search to locate any occurrence of the value.
    - Once found, expands linearly left and right to determine the full span.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] = value)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] = value)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of elements within a specified value range in a sorted array.
  @note:
    - Performs a binary search to locate any element within the target range.
    - Once found, expands linearly left and right to determine the full span of elements inside the range.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if no elements are within the specified range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  n, r: TRange;
begin
  Result.Create(-1, -1);
  n := range.Normalize;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] >= n.start) and (Self[Result.start - 1] <= n.stop)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] >= n.start) and (Self[Result.stop + 1] <= n.stop)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload;
var
  i: Integer;
  r: TRange;
begin
  r := Self.BinaryRange(value, aAscending);
  if r.Employs(-1) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[r.start + i];
end;

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload;
var
  h, i: Integer;
  r: TRange;
begin
  r := Self.BinaryRange(values, aAscending);
  if r.Employs(-1) then
    Exit([]);
  SetLength(Result, r.Size);
  h := High(Result);
  case values.Ascending of
    True:
    for i := 0 to h do
      Result[i] := Self[r.start + i];
    False:
    for i := h downto 0 do
      Result[h - i] := Self[r.start + i];
  end;
end;
{$ENDIF}
