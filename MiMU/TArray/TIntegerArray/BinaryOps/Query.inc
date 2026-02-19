{$IFDEF HELPERS}
function BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange;
function BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange;
function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload;
function BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange;
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange;
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
    end else if ((o * Self[m]) < (o * x)) then
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
function TIntegerArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload;
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryRangeEx>
  @action: Returns the range of indices containing values within `tolerance` of
           `value`. Uses binary search to find boundaries efficiently.
  @note: The array must be sorted according to `oAscending`. Unlike the expand
         function, this searches the entire array for the range, not just from
         a starting index. Time complexity is O(log n).
  @example: arr=[10,15,20,25,30,35], value=22, tolerance=5
            → includes 20,25 → range(2,3)
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
var
  m: TRange;
begin
  if (tolerance < 0) then
    Exit(TRange.Construct(-1, -1));
  m.Create((value - tolerance), (value + tolerance));
  Result.start := Self.BinaryBoundLeft(IfThen(oAscending, m.start, m.stop), oAscending);
  Result.stop := Self.BinaryBoundRight(IfThen(oAscending, m.stop, m.start), oAscending);
  if (Result.stop > 0) then
    Dec(Result.stop);
  if ((Result.start = -1) or (Result.start > High(Self)) or (Result.stop = -1) or (Result.stop < Result.start)) then
    Result := TRange.Construct(-1, -1);
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
function TIntegerArrayHelper.BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
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
  @action: Performs a binary search on a sorted integer array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TIntegerArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
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
function TIntegerArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
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
{$ENDIF}
