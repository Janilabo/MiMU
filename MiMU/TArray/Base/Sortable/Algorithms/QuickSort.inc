{$IFDEF HELPERS}
function QuickSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
function QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
function QuickSorted(const aAscending: Boolean = True): MArray; overload;
function QuickSort(const aAscending: Boolean = True): Integer; overload;
function QuickSort3W(const aAscending: Boolean = True): Integer; overload;
function QSort(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <QuickSortPair>
  @action: Sorts the array in-place while simultaneously reordering a partner array 
           to maintain element correspondence. Supports ascending or descending order.
  @note: Useful when you have a key array and a related value array that must stay paired.
         The method returns the length of the array.
[==============================================================================}
function MArrayHelper.QuickSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS2(var A, B: MArray; const L, R: Integer);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := A[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (A[i] < p) do
          Inc(i);
        while (A[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (A[i] > p) do
          Inc(i);
        while (A[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS2(A, B, L, j);
    if (i < R) then
      QS2(A, B, i, R);
  end;
begin
  Result := Self.Size;
  if (Result > 0) then
    QS2(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSortSwapped>
  @action: Sorts the array in ascending or descending order and records all swaps performed.
  @note: Returns a dynamic array of TConnection records, each representing the indices of elements swapped during the sort.
         Useful for visualizations or undoing the sort.
[==============================================================================}
function MArrayHelper.QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
  procedure QuickSortRec(const L, R: Integer; var swaps: TConnectionArray);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (System.Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (System.Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, swaps);
    if (i < R) then
      QuickSortRec(i, R, swaps);
  end;
begin
  SetLength(Result, 0);
  if (Self.Size > 1) then
    QuickSortRec(0, High(Self), Result);
end;

{==============================================================================]
  <QuickSortIndexed>
  @action: Sorts the array while tracking the original indices.
  @note: Returns an array of indices representing the order of elements in the sorted array.
         The original array is modified.
         Useful when you want to know how elements move rather than just sorting the values.
[==============================================================================}
function MArrayHelper.QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortRec(const L, R: Integer; var indexes: TIntegerArray);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, indexes);
    if (i < R) then
      QuickSortRec(i, R, indexes);
  end;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  if (l > 1) then
    QuickSortRec(0, (l - 1), Result);
end;

{==============================================================================]
  <QuickSortedly>
  @action: Returns the indices of the array elements in sorted order without modifying the original array.
  @note: Purely functional: the original array stays unchanged.
         The result is an array of indices indicating the sorted order.
[==============================================================================}
function MArrayHelper.QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortIndexedHelper(const arr: MArray; var indexes: TIntegerArray; const L, R: Integer; const aAscending: Boolean);
  var
    p: MType;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := arr[indexes[(L + R) div 2]];
    case aAscending of
      True:
      repeat
        while (arr[indexes[i]] < p) do
          Inc(i);
        while (arr[indexes[j]] > p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
      False:
      repeat
        while (arr[indexes[i]] > p) do
          Inc(i);
        while (arr[indexes[j]] < p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
    end;
    if (L < j) then
      QuickSortIndexedHelper(arr, indexes, L, j, aAscending);
    if (i < R) then
      QuickSortIndexedHelper(arr, indexes, i, R, aAscending);
  end;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  QuickSortIndexedHelper(Self, Result, 0, (l - 1), aAscending);
end;

{==============================================================================]
  <QuickSorted(aAscending: Boolean): MArray>
  @action: Returns array sorted by its own values, based on QuickSort algorithm.
  @note: None.
[==============================================================================}
function MArrayHelper.QuickSorted(const aAscending: Boolean = True): MArray; overload;
  procedure QS(var arr: MArray; const L, R: Integer);
  var
    i, j: Integer;
    p: MType;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while (aAscending and (arr[i] < p)) or ((not aAscending) and (arr[i] > p)) do
        Inc(i);
      while (aAscending and (arr[j] > p)) or ((not aAscending) and (arr[j] < p)) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QS(arr, L, j);
    if (i < R) then
      QS(arr, i, R);
  end;
var
  a: Integer;
begin
  a := Self.Length;
  Result := Self.Copy(0, a);
  if (a > 1) then
    QS(Result, 0, (a - 1));
end;

{==============================================================================]
  <QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QuickSort(const aAscending: Boolean = True): Integer; overload;
var
  p: MType;
  t, o: Integer;
  s: TRangeArray;
  x, r: TRange;
  procedure qsPush(const start, stop: Integer);
  begin
    SetLength(s, (t.Increment + 1));
    s[t].start := start;
    s[t].stop := stop;
  end;
  function qsPop(out start, stop: Integer): Boolean;
  begin
    Result := (t >= 0);
    if not Result then
      Exit;
    start := s[t].start;
    stop := s[t].stop;
    Dec(t); 
  end;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    t := -1;
    qsPush(0, Result);
    r.Create(0, Result);
    while qsPop(r.start, r.stop) do
      while r.Growing do
      begin
        x := r;
        p := Self[r.Middle];
        while x.Ascending do
        begin
          while (Sign(Self[x.start].Compare(p)) = o) do
            Inc(x.start);
          while (Sign(Self[x.stop].Compare(p)) = -o) do
            Dec(x.stop);
          if x.Ascending then
            Exchange(x.start.Increase, x.stop.Decrease);
        end;
        if ((x.stop - r.start) < (r.stop - x.start)) then
        begin
          if (x.start < r.stop) then
            qsPush(x.start, r.stop);
          r.stop := x.stop;
        end else
        begin
          if (r.start < x.stop) then
            qsPush(r.start, x.stop);
          r.start := x.start;
        end;
      end;
  end;
end;

{==============================================================================]
  <QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QuickSort3W(const aAscending: Boolean = True): Integer; overload;
  procedure SortLH(var arr: MArray; const L, H: Integer; const aAscending: Boolean = True);
  var
    a: MType;
    p, o: Integer;
    r: TRange;
  begin
    if (L >= H) then
      Exit;
    o := aAscending.Select(-1, 1);
    a := arr[L];
	r.Create(L, H);
    p := (L + 1);
    while (p <= r.stop) do
      if (Sign(arr[p].Compare(a)) = o) then
        Exchange(r.start.Increase, p.Increase)
      else
        if (Sign(arr[p].Compare(a)) = -o) then
          Exchange(r.stop.Decrease, p)
        else
          Inc(p);
    SortLH(arr, L, (r.start - 1), aAscending);
    SortLH(arr, (r.stop + 1), H, aAscending);
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    SortLH(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function MArrayHelper.QSort(const aAscending: Boolean = True): Integer; overload;
  procedure _QuickSort(var arr: MArray; const start, stop: Integer; const aAscending: Boolean = True);
  var
    p: MType;
	o: Integer;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := aAscending.Select(-1, 1);
	  s.Create(start, stop);
      p := arr[s.Middle];
      repeat
        while (Sign(arr[s.start].Compare(p)) = o) do
          Inc(s.start);
        while (Sign(arr[s.stop].Compare(p)) = -o) do
          Dec(s.stop);
        if (s.start <= s.stop) then
          Exchange(s.start.Increase, s.stop.Decrease);
      until (s.start > s.stop);
      if (start < s.stop) then
        _QuickSort(arr, start, s.stop, aAscending);
      if (s.start < stop) then
        _QuickSort(arr, s.start, stop, aAscending);
    end;
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    _QuickSort(Self, 0, Result, aAscending);
end;
{$ENDIF}