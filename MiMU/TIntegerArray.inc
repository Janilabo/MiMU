{$DEFINE Integer}{$I config\Defines.inc}

{==============================================================================]
  <TIntegerArrayHelper.Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Bounds: TRange; overload; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i]
    else
      if (Self[i] > Result.stop) then
        Result.stop := Self[i];
end;

function TIntegerArrayHelper.Bounds(var aSize: Integer): TRange; overload; cdecl;
var
  i: Integer;
begin
  case Self.Empty of
    False:
	begin
	  Result := Self.Bounds;
	  aSize := Result.Size;
	end;
    True:
    begin
      Result.Create(-2147483648, -2147483648);
      aSize := 0;
    end;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.BoundingRange>
  @action: Returns bounding range around TIntegerArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BoundingRange: TRange; cdecl;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MinValue(Self), MaxValue(Self));
end;

{==============================================================================]
  <TPointArrayHelper.Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Boundaries: TRange; cdecl;
  function BR(const arr: TIntegerArray; const L, R: Integer): TRange;
  var
    M: Integer;
  begin
    if (L = R) then
      Exit(Result.Create(arr[L], arr[L]));
    M := ((L + R) div 2);
    Result := BR(arr, L, M).Union(BR(arr, (M + 1), R));
  end;
begin
  if Self.Empty then
    Exit(Default(TRange));
  Result := BR(Self, 0, High(Self));
end;

{==============================================================================]
  <TIntegerArrayHelper.Range>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Range: TRange; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i in Self do
    Result.Create(Min(Result.start, i), Max(Result.stop, i));
end;

{==============================================================================]
  <TIntegerArrayHelper.Coverage>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Coverage: TRange; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i];
  for i := 1 to High(Self) do
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
end;

{==============================================================================]
  <TIntegerArrayHelper.MinMax>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.MinMax: TRange; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
  begin
    Result.start := Min(Result.start, Self[i]);
    Result.stop := Max(Result.stop, Self[i]);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Region>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Region: TRange; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MaxInt, -MaxInt);
  for i := 0 to High(Self) do
  begin
    if (Self[i] < Result.start) then
      Result.start := Self[i];
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Extent>
  @action: Stores arr bounds to TRange.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Extent: TRange; cdecl;
begin
  Result.Create(Self.MinVal, Self.MaxVal);
end;

{==============================================================================]
  <TIntegerArray.Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray; cdecl;
begin
  Result := Self.Copy;
  TIA.Unique(Result);
end;

{==============================================================================]
  <TIntegerArrayHelper.Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray; cdecl;
var
  i, l: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  l := 0;
  if Self.Exists then
  begin
    SetLength(Result, Self.Size);
    r := Self.Bounds;
	b.Create(r.Size, False);
    for i := 0 to High(Self) do
      if b[Self[i] - r.start].Enable then
        Result[l.Increase] := Self[i];
    SetLength(b, 0);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.Numberline>
  @action: Returns numberline of array arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Numberline: TIntegerArray; cdecl;
var
  i, x, y: Integer;
  r: TRange;
begin
  y := High(Self);
  case y.Compare(0) of
    1:
    begin
      r.Create(Self[0], Self[0]);
      for x := 1 to y do
        if (Self[x] < r.start) then
          r.start := Self[x]
        else
          if (Self[x] > r.stop) then
            r.stop := Self[x];
      if (r.start <> r.stop) then
      begin
        SetLength(Result, r.Size);
        for i := r.start to r.stop do
          Result[i - r.start] := i;
      end else
        Result.Create(r.start);
    end;
    0: Result.Create(Self[0]);
    -1: SetLength(Result, 0);
  end;
end;

{==============================================================================]
 <TIntegerArrayHelper.Sum>
 @action: Returns the sum of all arr values together.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Sum: Int64; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
 <TIntegerArrayHelper.Density>
 @action: Returns the calculated density from given arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Density: Double; cdecl;
var
  a: TIntegerArray;
  c, i, j: Integer;
  u: Boolean;
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  r.Create(Self[0], Self[0]);
  SetLength(a, Length(Self));
  c := 0;
  for i := 0 to High(Self) do
  begin
    r.Absorb(Self[i]);
    u := True;
    for j := 0 to (c - 1) do
      if (a[j] = Self[i]) then
      begin
        u := False;
        Break;
      end;
    if u then
      a[c.Increase] := Self[i];
  end;
  if (r.Size = 0) then
    Result := 0
  else
    Result := (c / r.Size);
end;

{==============================================================================]
 <TIntegerArrayHelper.Occupancy>
 @action: Returns the calculated density from given arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Occupancy: Double; cdecl;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  Result := (Self.QuickSorted.Distinct / r.Construct(0, High(Self)).Size);
end;

{==============================================================================]
 <TIntegerArrayHelper.Mean>
 @action: The sum of all arr values divided by the length of arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Mean: Double; cdecl;
begin
  Result := (Self.Sum / Length(Self));
end;

{==============================================================================]
 <TIntegerArrayHelper.Median>
 @action: The middle value when the arr is sorted:
          -Odd number of elements => the exact middle.
          -Even number => the average of the two middle elements.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Median: Double; cdecl;
var
  a: TIntegerArray;
  i, j, n, s: Integer;
begin
  n := Length(Self);
  if (n = 0) then
    Exit(-2147483648);
  a := Self.Copy;
  for i := 0 to (n - 2) do
    if (a[i] > a[i + 1]) then
    begin
      for j := 0 to (n - 2) do
        for s := 0 to ((n - j) - 2) do
          if (a[s] > a[s + 1]) then
            Exchange(s, (s + 1));
      Break;
    end;
  if ((n mod 2) = 1) then
    Result := a[n div 2]
  else
    Result := ((a[(n div 2) - 1] + a[n div 2]) / 2);
end;

{==============================================================================]
 <TIntegerArrayHelper.Middle>
 @action: The value(s) at the center position(s) of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Middle: Double; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit(-2147483648);
  if ((l mod 2) = 1) then
    Result := Self[l div 2]
  else
    Result := ((Self[(l div 2) - 1] + Self[l div 2]) / 2.0);
end;

{==============================================================================]
 <TIntegerArrayHelper.MostFreq>
 @action: Returns the most frequent/common value from arr.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.MostFreq(const null: Integer = -2147483648): Integer; cdecl;
var
  h, x, t: Integer;
  b: TIntegerArray;
  r: TRange;
begin
  h := High(Self);
  case h.Compare(0) of
    1:
    begin
      r := Self.Bounds;
      b.Create(r.Size, 0);
      for x := 0 to h do
        Inc(b[Self[x] - r.start]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if (b[x] > b[t]) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := Self[0];
    -1: Result := null;
  end;
end;

{==============================================================================]
 <TIntegerArrayHelper.LeastFreq>
 @action: Returns the least frequent/common value from TIA.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.LeastFreq(const null: Integer = -2147483648): Integer; cdecl;
var
  h, x, t: Integer;
  b: TIntegerArray;
  r: TRange;
begin
  h := High(Self);
  case h.Compare(0) of
    1:
    begin
      r := Self.Bounds;
      b.Create(r.Size, 0);
      for x := 0 to h do
        Inc(b[Self[x] - r.start]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if ((b[x] > 0) and (b[x] < b[t])) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := Self[0];
    -1: Result := null;
  end;
end; 

{==============================================================================]
  <TIntegerArrayHelper.BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArrayHelper.BubbleSort2(const aAscending: Boolean = True): Integer; cdecl;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 0 to (Result - 1) do
      for b := 1 to (Result - a) do
        if (Sign(Self[b] - Self[b - 1]) = o) then
          Exchange(b, (b - 1));
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.QuickSort(const aAscending: Boolean = True): Integer; cdecl;
var
  t, p, o: Integer;
  s: TRangeArray;
  x, r: TRange;
  procedure qsPush(const start, stop: Integer);
  begin
    Inc(t);
    SetLength(s, (t + 1));
    s[t].start := start;
    s[t].stop := stop;
  end;
  function qsPop(out start, stop: Integer): Boolean;
  begin
    if (t < 0) then
    begin
      Result := False;
      Exit;
    end;
    start := s[t].start;
    stop := s[t].stop;
    Dec(t);
    Result := True;
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
    begin
      while (r.start < r.stop) do
      begin
        x := r;
        p := Self[(r.start + r.stop) div 2];
        while (x.start <= x.stop) do
        begin
          while (Sign(Self[x.start] - p) = o) do
            Inc(x.start);
          while (Sign(Self[x.stop] - p) = -o) do
            Dec(x.stop);
          if (x.start <= x.stop) then
          begin
            Exchange(x.start, x.stop);
            Inc(x.start);
            Dec(x.stop);
          end;
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
end;

{==============================================================================]
  <TIntegerArrayHelper.QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.QuickSort3W(const aAscending: Boolean = True): Integer; cdecl;
  procedure SortLH(var arr: TIntegerArray; const L, H: Integer; const aAscending: Boolean = True);
  var
    a, b, p, x, o: Integer;
  begin
    if (L >= H) then
      Exit;
    o := aAscending.Select(-1, 1);
    x := arr[L];
    a := L;
    b := H;
    p := (L + 1);
    while (p <= b) do
      if (Sign(arr[p] - x) = o) then
      begin
        Exchange(a, p);
        Inc(p);
        Inc(a);
      end else
      if (Sign(arr[p] - x) = -o) then
      begin
        Exchange(b, p);
        Dec(b);
      end else
        Inc(p);
    SortLH(arr, L, (a - 1), aAscending);
    SortLH(arr, (b + 1), H, aAscending);
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    SortLH(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <TIntegerArrayHelper.QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.QSort(const aAscending: Boolean = True): Integer; cdecl;
  procedure _QuickSort(var arr: TIntegerArray; const start, stop: Integer; const aAscending: Boolean = True);
  var
    p, o: Integer;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := aAscending.Select(-1, 1);
      p := arr[(start + stop) div 2];
      s.Create(start, stop);
      repeat
        while (Sign(arr[s.start] - p) = o) do
          Inc(s.start);
        while (Sign(arr[s.stop] - p) = -o) do
          Dec(s.stop);
        if (s.start <= s.stop) then
        begin
          Exchange(s.start, s.stop);
          Inc(s.start);
          Dec(s.stop);
        end;
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

{==============================================================================]
  <TIntegerArrayHelper.CoctailSort>
  @action: CoctailSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.CoctailSort(const aAscending: Boolean = True): Integer; cdecl;
var
  i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    repeat
      s := False;
      for i := 0 to (Result - 1) do
        if (Sign(Self[i + 1] - Self[i]) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      for i := (Result - 1) downto 0 do
         if (Sign(Self[i + 1] - Self[i]) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.CoctailSort2>
  @action: CoctailSort algorithm for TIntegerArrays.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.CoctailSort2(const aAscending: Boolean = True): Integer; cdecl;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    b := -1;
    e := (Length(Self) - 2);
    repeat
      s := False;
      Inc(b);
      for i := b to e do
        if not (Sign(Self[i] - Self[i + 1]) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      Dec(e);
      for i := e downto b do
        if not (Sign(Self[i] - Self[i + 1]) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.CombSort>
  @action: CombSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.CombSort(const aAscending: Boolean = True): Integer; cdecl;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    g := Length(Self);
    s := True;
    while ((g > 1) or s) do
    begin
      g := Trunc(g / 1.3);
      if (g < 1) then
        g := 1;
      s := False;
      for i := 0 to (Result - g) do
        if (Sign(Self[i + g] - Self[i]) = o) then
        begin
          Exchange(i, (i + g));
          s := True;
        end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.GnomeSort>
  @action: GnomeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.GnomeSort(const aAscending: Boolean = True): Integer; cdecl;
var
  o, p, t: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    while (p <= Result) do
      if (Sign(Self[p] - Self[p - 1]) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
          Dec(p);
      end else
        Inc(p);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.GnomeSortOptimized>
  @action: Optimized GnomeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.GnomeSortOptimized(const aAscending: Boolean = True): Integer; cdecl;
var
  p, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    l := 0;
    while (p <= Result) do
      if (Sign(Self[p] - Self[p - 1]) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
        begin
          if (l <> 0) then
            l := p
          else
            Dec(p);
        end else
          Inc(p);
      end else
        if (l <> 0) then
        begin
          p := l;
          l := 0;
        end else
          Inc(p);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.HeapSort>
  @action: HeapSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.HeapSort(const aAscending: Boolean = True): Integer; cdecl;
var
  a, b, r, c, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    a := (Result div 2);
    b := Result;
    while (a >= 0) do
    begin
      r := a;
      while (((r * 2) + 1) <= Result) do
      begin
        c := ((r * 2) + 1);
        if ((c < Result) and (Sign(Self[c] - Self[c + 1]) = o)) then
          c := (c + 1);
        if (Sign(Self[r] - Self[c]) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
      a := (a - 1);
    end;
    while (b > 0) do
    begin
      Exchange(0, b);
      b := (b - 1);
      r := 0;
      while (((r * 2) + 1) <= b) do
      begin
        c := ((r * 2) + 1);
        if ((c < b) and (Sign(Self[c] - Self[c + 1]) = o)) then
          c := (c + 1);
        if (Sign(Self[r] - Self[c]) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.InsertionSort>
  @action: InsertionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.InsertionSort(const aAscending: Boolean = True): Integer; cdecl;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 1 to Result do
      for b := a downto 1 do
      begin
        if not (Sign(Self[b] - Self[b - 1]) = o) then
          Break;
        Exchange(b, (b - 1));
      end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSort>
  @action: SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSort(const aAscending: Boolean = True): Integer; cdecl;
var
  c, t, m, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for c := 0 to Result do
    begin
      m := c;
      for t := (c + 1) to Result do
        if (Sign(Self[t] - Self[m]) = o) then
          m := t;
      Exchange(m, c);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSortBidirectional(const aAscending: Boolean = True): Integer; cdecl;
var
  a, b, x, i, h, l, s, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    s := (Result div 2);
    for i := 0 to s do
    begin
      l := i;
      h := (Result - i);
      a := l;
      b := h;
      if (Sign(Self[l] - Self[h]) = -o) then
        Exchange(h, l);
      for x := (a + 1) to (b - 1) do
        if (Sign(Self[x] - Self[l]) = o) then
          l := x
        else
          if (Sign(Self[x] - Self[h]) = -o) then
            h := x;
      if (l <> a) then
        Exchange(a, l);
      if (h <> b) then
        Exchange(b, h);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; cdecl;
var
  a, b, x, i, s, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    s := (Result div 2);
    for i := 0 to s do
    begin
      a := i;
      b := (Result - i);
      if (Sign(Self[b] - Self[a]) = o) then
        Exchange(a, b);
      for x := (a + 1) to (b - 1) do
        if (Sign(Self[x] - Self[a]) = o) then
          Exchange(a, x)
        else
          if (Sign(Self[x] - Self[b]) = -o) then
            Exchange(x, b);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.PancakeSort>
  @action: PancakeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.PancakeSort(const aAscending: Boolean = True): Integer; cdecl;
var
  i, j, l, m, x, o: Integer;
begin
  Result := High(Self);
  if (Result > 0 )then
  begin
    o := aAscending.Select(-1, 1);
    l := 0;
    for i := Result downto l do
    begin
      m := i;
      for j := l to (i - 1) do
        if (Sign(Self[m] - Self[j]) = o) then
          m := j;
      if (m = i) then
        Continue;
      if (m <> l) then
      for x := l to (((m - l) - 1) div 2) do
        Exchange(x, (m - (x - l)));
      for x := l to (((i - l) - 1) div 2) do
        Exchange(x, (i - (x - l)));
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.MergeSort>
  @action: MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.MergeSort(const aAscending: Boolean = True): Integer; cdecl;
  procedure Merge(var arr, tmp: TIntegerArray; const Lo, Hi: Integer; const aAscending: Boolean = True);
  var
    L, R, i, m, o: Integer;
  begin
    if (Lo >= Hi) then
      Exit;
    o := aAscending.Select(-1, 1);
    m := (Lo + (Hi - Lo) div 2);
    Merge(arr, tmp, Lo, m, aAscending);
    Merge(arr, tmp, (m + 1), Hi, aAscending);
    L := Lo;
    R := (m + 1);
    for i := Lo to Hi do
      tmp[i] := arr[i];
    for i := Lo to Hi do
      if (L > m) then
        arr[i] := tmp[R.Increase]
      else
        if (R > Hi) then
          arr[i] := tmp[L.Increase]
        else
          if (Sign(tmp[R] - tmp[L]) = o) then
            arr[i] := tmp[R.Increase]
          else
            arr[i] := tmp[L.Increase];
  end;
var
  l: Integer;
  t: TIntegerArray;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    Merge(Self, t, 0, Result, aAscending);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.MergeSortBU>
  @action: Bottom-up MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.MergeSortBU(const aAscending: Boolean = True): Integer; cdecl;
var
  t: TIntegerArray;
  n, w, i, a, b, m, l, r, k: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    n := (Result + 1);
    SetLength(t, n);
    w := 1;
    while (w < n) do
    begin
      i := 0;
      while (i < n) do
      begin
        a := i;
        m := Min((i + (w - 1)), (n - 1));
        b := Min((i + (2 * w) - 1), (n - 1));
        for k := a to b do
          t[k] := Self[k];
        L := a;
        R := (m + 1);
        k := a;
        while ((l <= m) and (r <= b)) do
        begin
          if ((aAscending and (t[l] <= t[r])) or (not aAscending and (t[l] >= t[r]))) then
            Self[k] := t[l.Increase]
          else
            Self[k] := t[r.Increase];
          Inc(k);
        end;
        while (l <= m) do
          Self[k.Increase] := t[l.Increase];
        while (r <= b) do
          Self[k.Increase] := t[r.Increase];
        i := (i + (2 * w));
      end;
      w := (w * 2);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.ShellSort>
  @action: ShellSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.ShellSort(const aAscending: Boolean = True): Integer; cdecl;
var
  x, a, b, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    case (Result > 1) of
      True:
      begin
        l := Length(Self);
        x := 0;
        while (x < (l div 3)) do
          x := ((x * 3) + 1);
        while (x >= 1) do
        begin
          for a := x to (l - 1) do
          begin
            b := a;
            while ((b >= x) and (Sign(Self[b] - Self[b - x]) = o)) do
            begin
              Exchange(b, (b - x));
              b := (b - x);
            end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(Self[1] - Self[0]) = o) then
        Exchange(0, 1);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.RadixSort>
  @action: RadixSort for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.RadixSort(const aAscending: Boolean = True): Integer; cdecl;
var
  a, n: TIntegerArray;
  c: array[0..9] of Integer;
  x, y, p, i, j, m, e: Integer;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  SetLength(n, (Result + 1));
  SetLength(a, (Result + 1));
  x := 0;
  y := 0;
  for i := 0 to Result do
    if (Self[i] < 0) then
      n[x.Increase] := -Self[i]
    else
      a[y.Increase] := Self[i];
  SetLength(n, x);
  SetLength(a, y);
  if (x > 0) then
  begin
    m := n[0];
    for i := 1 to (x - 1) do
      if (n[i] > m) then
        m := n[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (x - 1) do
        Inc(c[(n[i] div e) mod 10]);
      for j := 8 downto 0 do
        c[j] := (c[j] + c[j + 1]);
      SetLength(Self, x);
      for i := (x - 1) downto 0 do
        Self[c[((n[i] div e) mod 10)].Decrement] := n[i];
      for i := 0 to (x - 1) do
        n[i] := Self[i];
      e := (e * 10);
    end;
    for i := 0 to (x - 1) do
      n[i] := -n[i];
  end;
  if (y > 0) then
  begin
    m := a[0];
    for i := 1 to (y - 1) do
      if (a[i] > m) then
        m := a[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (y - 1) do
        Inc(c[(a[i] div e) mod 10]);
      for j := 1 to 9 do
        c[j] := (c[j] + c[j - 1]);
      SetLength(Self, y);
      for i := (y - 1) downto 0 do
        Self[c[(a[i] div e) mod 10].Decrement] := a[i];
      for i := 0 to (y - 1) do
        a[i] := Self[i];
      e := (e * 10);
    end;
  end;
  if aAscending then
    Self := (n + a)
  else
    Self := (a.Reversed + n.Reversed);
end;

{==============================================================================]
  <TIntegerArrayHelper.Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Length(Result[a]);
          for b := 0 to (l - 1) do
		  begin
		    m := ((Self[i] = Result[a][b]) or s.Value(Abs(Self[i] - Result[a][b])));
			if not m then
              Continue;
		    SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
		  if m then
		    Break;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Split(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Length(a));
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        l := Length(Result[j]);
        for k := 0 to (l - 1) do
		begin
          m := ((a[i] = Result[j][k]) or s.Value(Abs(a[i] - Result[j][k])));
          if not m then
            Continue;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
		if m then
		  Break;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Sblit(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Groups>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the ones with same values.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Groups(const aSorted: Boolean = False): T2DIntegerArray; overload; cdecl;
var
  i, l, g: Integer;
  a: TIntegerArray;
begin
  l := Length(Self);
  if (l = 0) then
    Exit([]);
  if not aSorted then
    a := Self.QuickSorted
  else
    a := Self.Copy;
  a.BinaryUnique;
  SetLength(Result, 0);
  SetLength(Result, Length(a));
  for i := 0 to High(Self) do
  begin
    g := a.BinarySearch(Self[i]);
    l := Length(Result[g]);
    SetLength(Result[g], (l + 1));
    Result[g][l] := Self[i];
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
          if ((Self[i] = Result[a][0]) or s.Value(Abs(Self[i] - Result[a][0]))) then
          begin
            m := True;
            l := Length(Result[a]);
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Group(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a: TIntegerArray;
  i, j, r, l: Integer;
  s: TRange;
  m: Boolean;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Self.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        if ((a[i] = Result[j][0]) or s.Value(Abs(a[i] - Result[j][0]))) then
        begin
          l := Length(Result[j]);
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          m := True;
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Groub(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Strict splitting!
[==============================================================================}
function TIntegerArrayHelper.Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Length(Result[a]);
          m := True;
          for b := 0 to (l - 1) do
            if ((Self[i] = Result[a][b]) or (not m)) then
              Break
            else
              m := s.Value(Abs(Self[i] - Result[a][b]));
          if m then
          begin
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Clique(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Clique(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Length(a));
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        m := True;
        l := Length(Result[j]);
        for k := 0 to (l - 1) do
          if ((a[i] = Result[j][k]) or (not m)) then
            Break
          else
            m := s.Value(Abs(a[i] - Result[j][k]));
        if m then
        begin
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const diff: Integer): T2DIntegerArray; overload; cdecl;
begin
  Result := Self.Knit(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Invert>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
[==============================================================================}
function TIntegerArrayHelper.Invert: TIntegerArray; cdecl;
var
  c, l, i, x, r: Integer;
  b: TBooleanArray;
  a: TRange;
begin
  r := 0;
  if Self.Exists then
  begin
    a := Self.Bounds;
    if (a.start <> a.stop) then
    begin
      c := 0;
      l := a.Size;
      b.Create(l, False);
      for x := 0 to High(Self) do
        if b[Self[x] - a.start].Enable then
          Inc(c);
      SetLength(Result, (l - c));
      if (Length(Result) > 0) then
      for i := 0 to (l - 1) do
        if not b[i] then
          Result[r.Increase] := (i + a.start);
      SetLength(b, 0);
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TIntegerArrayHelper.Inverted>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverted(const arrBounds: TRange): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
  b: TRange;
begin
  b := arrBounds.Normalize;
  SetLength(Result, b.Size);
  r := 0;
  for i := b.Start to b.Stop do
    if not Self.Contains(i) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

function TIntegerArrayHelper.Inverted: TIntegerArray; overload; cdecl;
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <TIntegerArrayHelper.Inverse>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverse(const arrBounds: TRange): TIntegerArray; overload; cdecl;
var
  l, i: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  if (Length(Self) < 2) then
    Exit;
  r := arrBounds.Normalize;
  b.Create(arrBounds.Size, False);
  for i := 0 to High(Self) do
    if not ((Self[i] < r.start) or (Self[i] > r.stop)) then
      b[Self[i] - r.start] := True;
  l := 0;
  SetLength(Result, Length(b));
  for i := r.start to r.stop do
    if not b[i - r.start] then
      Result[l.Increase] := i;
  SetLength(Result, l);
end;

function TIntegerArrayHelper.Inverse: TIntegerArray; overload; cdecl;
begin
  Result := Self.Inverse(Self.Bounds);
end;

{==============================================================================]
  <TIntegerArrayHelper.MinVal>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.MinVal: Integer; overload; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(2147483647);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Min(Self[i], Result);
end;

{==============================================================================]
  <TIntegerArrayHelper.MaxVal>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.MaxVal: Integer; overload; cdecl;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(-2147483648);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Max(Self[i], Result);
end;

{==============================================================================]
  <TIntegerArrayHelper.Minimum>
  @action: Returns minimum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Minimum(var index: Integer): Integer; overload; cdecl;
var
  i: Integer;
begin
  index := -1;
  if Self.Empty then
    Exit(2147483647);
  index := 0;
  for i := 1 to High(Self) do
    if (Self[i] < Self[index]) then
      index := i;
  Result := Self[index];
end;

{==============================================================================]
  <TIntegerArrayHelper.Minimum>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Minimum: Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := Self.Minimum(i);
end;

{==============================================================================]
  <TIntegerArrayHelper.Maximum>
  @action: Returns maximum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Maximum(var index: Integer): Integer; overload; cdecl;
var
  i: Integer;
begin
  index := -1;
  if Self.Empty then
    Exit(-2147483648);
  index := 0;
  for i := 1 to High(Self) do
    if (Self[i] > Self[index]) then
      index := i;
  Result := Self[index];
end;

{==============================================================================]
  <TIntegerArrayHelper.Maximum>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Maximum: Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := Self.Maximum(i);
end;

{==============================================================================]
 <TIntegerArrayHelper.Mirror>
 @action: Mirrors arr
 @note: None.
[==============================================================================}
function TIntegerArrayHelper.Mirror: Boolean; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if not Result then
    Exit;
  i := -1;
  while (i.Increment < l.Decrement) do
  begin
    Self[i] := (Self[i] xor Self[l]);
    Self[l] := (Self[i] xor Self[l]);
    Self[i] := (Self[i] xor Self[l]);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean; cdecl;
var
  a: TIntegerArray;
  i: Integer;
begin
  a := allowed.QuickSorted;
  for i := 0 to High(Self) do
    if not a.BinaryContains(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TIntegerArrayHelper.NoneOf>
  @action: Returns true if arr does not contain any items from forbidden.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.NoneOf(const forbidden: TIntegerArray): Boolean; cdecl;
var
  d: specialize TDictionary<Integer, Boolean>;
  i: Integer;
begin
  Result := True;
  if (Self.Empty or forbidden.Empty) then
    Exit;
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to High(forbidden) do
      d[forbidden[i]] := True;
    for i := 0 to High(Self) do
      if d.ContainsKey(Self[i]) then
        Exit(False); 
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.AnyOf>
  @action: Returns True if arr contains at least one item from candidates.
  @note: Always False if arr or candidates is empty.
[==============================================================================}
function TIntegerArrayHelper.AnyOf(const candidates: TIntegerArray): Boolean; cdecl;
var
  d: specialize TDictionary<Integer, Boolean>;
  i: Integer;
begin
  Result := False;
  if (Self.Empty or candidates.Empty) then
    Exit;
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to High(candidates) do
      d[candidates[i]] := True;
    for i := 0 to High(Self) do
      if d.ContainsKey(Self[i]) then
        Exit(True);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.AllOf>
  @action: Returns True if arr contains all items from candidates.
  @note: Always True if candidates is empty. False if arr is empty but candidates is not.
[==============================================================================}
function TIntegerArrayHelper.AllOf(const candidates: TIntegerArray): Boolean; cdecl;
var
  d: specialize TDictionary<Integer, Boolean>;
  i: Integer;
begin
  if candidates.Empty then
    Exit(True);
  if Self.Empty then
    Exit(False);
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to High(Self) do
      d[Self[i]] := True;
    for i := 0 to High(candidates) do
      if not d.ContainsKey(candidates[i]) then
        Exit(False);
    Result := True;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Charify: TCharArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Chr(Self[i]);
end;

{==============================================================================]
  <TIntegerArrayHelper.Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores str version to variable.
[==============================================================================}
function TIntegerArrayHelper.Charify(var str: string): TCharArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  SetLength(str, Length(Self));
  for i := 0 to High(Self) do
  begin
    Result[i] := Chr(Self[i]);
    str[i + 1] := Result[i];
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Stringify>
  @action: Converts TIntegerArray to string.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Stringify: string; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i + 1] := Chr(Self[i]);
end;

{==============================================================================]
  <TIntegerArrayHelper.Stringify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores charset version to variable.
[==============================================================================}
function TIntegerArrayHelper.Stringify(var chars: TCharArray): string; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  SetLength(chars, Length(Self));
  for i := 0 to High(Self) do
  begin
    Result[i + 1] := Chr(Self[i]);
    chars[i] := Result[i];
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Special>
  @action: Returns true if parity of every pair of adjacent element differs each other.
  @note: An element in each pair must be even and other must be odd.
[==============================================================================}
function TIntegerArrayHelper.Special: Boolean; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i].Parity = Self[i - 1].Parity) then
	  Exit(False);
  Result := True;
end;

{==============================================================================]
  <TIntegerArrayHelper.ExtractEven>
  @action: Returns even values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if ((Self[i] mod 2) = 0) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.FilterEven>
  @action: Returns array without even values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterEven: TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not ((Self[i] mod 2) = 0) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.ExtractOdd>
  @action: Returns odd values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractOdd: TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if ((Self[i] mod 2) <> 0) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.FilterOdd>
  @action: Returns array without odd values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterOdd: TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not ((Self[i] mod 2) <> 0) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reinit: Integer; overload; cdecl;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Integer)), 0);
end;

{==============================================================================]
  <TIntegerArrayHelper.BSort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const aAscending: Boolean = True): Integer; cdecl; var a: Integer; {$DEFINE Skeleton_BSort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <TIntegerArrayHelper.BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; cdecl; var a: Integer; {$DEFINE Skeleton_BinarySort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <TIntegerArrayHelper.BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const aAscending: Boolean = True): TIntegerArray; cdecl; var a: Integer; {$DEFINE Skeleton_BinarySorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <TIntegerArrayHelper.BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryBoundL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <TIntegerArrayHelper.BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryBoundR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <TIntegerArrayHelper.BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryPosL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <TIntegerArrayHelper.BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryPosR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <TIntegerArrayHelper.BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearch}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <TIntegerArrayHelper.BinarySeek>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySeek}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <TIntegerArrayHelper.BinaryContains>
  @action: Binary Contains function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryContains}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <TIntegerArrayHelper.BinaryCount>
  @action: Binary Count function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryCount}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <TIntegerArrayHelper.BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange; cdecl; {$DEFINE Skeleton_BinaryLocate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <TIntegerArrayHelper.BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange; cdecl; {$DEFINE Skeleton_BinaryLocation}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <TIntegerArrayHelper.BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryAppend}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <TIntegerArrayHelper.BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; cdecl; {$DEFINE Skeleton_BinaryAdd}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <TIntegerArrayHelper.BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearchF}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <TIntegerArrayHelper.BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearchL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <TIntegerArrayHelper.BinaryUnique>
  @action: Binary Search-based Unique method.
  @note: Alternative for TArray_Unique, for TIntegerArrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnique(const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryUnique}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnique}

{==============================================================================]
  <TIntegerArrayHelper.BinaryUniqued>
  @action: Binary Search-based Uniqued method.
  @note: Alternative for TArray_Uniqued, for TIntegerArrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniqued(const aAscending: Boolean = True): TIntegerArray; cdecl; {$DEFINE Skeleton_BinaryUniqued}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUniqued}

{==============================================================================]
  <TIntegerArrayHelper.BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUndupe(const aAscending: Boolean = True): TIntegerArray; cdecl; {$DEFINE Skeleton_BinaryUndupe}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <TIntegerArrayHelper.BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryGrow}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <TIntegerArrayHelper.BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryShrink}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <TIntegerArrayHelper.BinaryLowerBound>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerBound(const x: Integer; const aAscending: Boolean): Integer; cdecl; {$DEFINE Skeleton_BinaryLowerBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <TIntegerArrayHelper.BinaryUpperBound>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryUpperBound(const x: Integer; const aAscending: Boolean): Integer; cdecl; {$DEFINE Skeleton_BinaryUpperBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <TIntegerArrayHelper.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; cdecl; {$DEFINE Skeleton_BinaryRange1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <TIntegerArrayHelper.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload; cdecl; {$DEFINE Skeleton_BinaryRange2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <TIntegerArray.BinaryMerge>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; cdecl; {$DEFINE Skeleton_BinaryMerge}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

{==============================================================================]
  <TIntegerArray.BinaryMerged>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; cdecl; {$DEFINE Skeleton_BinaryMerged}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

{==============================================================================]
  <TIntegerArray.BinaryCombine>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; cdecl; {$DEFINE Skeleton_BinaryCombine}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <TIntegerArray.BMerge>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  a, b, i, j, l: Integer;
begin
  a := Length(Self);
  b := Length(items);
  SetLength(Result, (a + b));
  i := 0;
  j := 0;
  l := 0;
  case aAscending of
    True:
    while ((i < a) and (j < b)) do
      if (Self[i] <= items[j]) then
        Result[l.Increase] := Self[i.Increase]
      else
        Result[l.Increase] := items[j.Increase];
    False:
    while ((i < a) and (j < b)) do
      if (Self[i] >= items[j]) then
        Result[l.Increase] := Self[i.Increase]
      else
        Result[l.Increase] := items[j.Increase];
  end;
  if (i < a) then
    Move(Self[i], Result[l.Increase(a - i)], ((a - i) * SizeOf(Integer)));
  if (j < b) then
    Move(items[j], Result[l], ((b - j) * SizeOf(Integer)));
end;

{==============================================================================]
  <TIntegerArray.BMerged>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  a, b, i, j, l: Integer;
begin
  a := Length(Self);
  b := Length(items);
  SetLength(Result, (a + b));
  i := 0;
  j := 0;
  l := 0;
  while ((i < a) and (j < b)) do
    if Self[i].Precede(items[j], aAscending) then
      Result[l.Increase] := Self[i.Increase]
    else
      Result[l.Increase] := items[j.Increase];
  if (i < a) then
    Move(Self[i], Result[l.Increase(a - i)], ((a - i) * SizeOf(Integer)));
  if (j < b) then
    Move(items[j], Result[l], ((b - j) * SizeOf(Integer)));
end;

{$UNDEF Integer}