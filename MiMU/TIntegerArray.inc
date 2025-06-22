{==============================================================================]
  <TIntegerArrayHelper.Descending>
  @action: Returns true if array arr is in descending order.
  @note: CAUTION! Does not work with arrays that contain only unique values.
         [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function TIntegerArrayHelper.Descending: Boolean; cdecl;
var
  i: Integer;
begin
  Result := False;
  for i := 1 to High(Self) do
    if (Self[i] > Self[i - 1]) then
      Exit(False)
    else
      Result := (Result or (Self[i] < Self[i - 1]));
end;

{==============================================================================]
  <TIntegerArrayHelper.Ascending>
  @action: Returns true if array arr is in asscending order.
  @note: CAUTION! Does not work with arrays that contain only unique values.
         [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function TIntegerArrayHelper.Ascending: Boolean; cdecl;
var
  i: Integer;
begin
  Result := False;
  for i := 1 to High(Self) do
    if (Self[i] < Self[i - 1]) then
      Exit(False)
    else
      Result := (Result or (Self[i] > Self[i - 1]));
end;

{==============================================================================]
  <TIntegerArrayHelper.Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Bounds: TRange; overload; cdecl;
var
  i: Integer;
begin
  if (High(Self) = -1) then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i]
    else
      if (Self[i] > Result.stop) then
        Result.stop := Self[i];
end;

function TIntegerArrayHelper.Bounds(var size: Integer): TRange; overload; cdecl;
var
  i: Integer;
begin
  case (High(Self) = -1) of
    False:
	begin
	  Result := Self.Bounds;
	  size := Result.Size;
	end;
    True:
    begin
      Result.Create(-2147483648, -2147483648);
      size := 0;
    end;
  end;
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
  if (High(Self) = -1) then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
  begin
    Result.start := Min(Result.start, Self[i]);
    Result.stop := Max(Result.stop, Self[i]);
  end;
end;

{==============================================================================]
  <TIntegerArray_Unique>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unique: Integer; cdecl;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(Self);
  if (y > 0) then
  begin
    z := 0;
    r := Self.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
      if b[Self[x] - r.start].Enable then
        Self[z.Increase] := Self[x];
    SetLength(b, 0);
    SetLength(Self, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;

{==============================================================================]
  <TIntegerArrayHelper.Uniqued>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Uniqued: TIntegerArray; cdecl;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  z := 0;
  y := High(Self);
  if (y > 0) then
  begin
    SetLength(Result, (y + 1));
    r := Self.Bounds;
	b.Create(r.Size, False);
    for x := 0 to y do
      if b[Self[x] - r.start].Enable then
        Result[z.Increase] := Self[x];
    SetLength(b, 0);
  end;
  SetLength(Result, z);
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
  <TIntegerArray_Min>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Lowest: Integer; cdecl;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <TIntegerArrayHelper.Highest>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Highest: Integer; cdecl;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <TIntegerArrayHelper.Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with ascending as False.
[==============================================================================}
function TIntegerArrayHelper.Mini(const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
var
  h, i, s: Integer;
begin
  h := High(Self);
  if ((h = -1) or (ascending and (start > h)) or ((not ascending) and (start < 0))) then
    Exit(-1);
  case ascending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
  end;
end;

function TIntegerArrayHelper.Mini(const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
begin
  Result := Self.Mini(ascending, start);
end;

{==============================================================================]
  <TIntegerArrayHelper.Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with ascending as False.
[==============================================================================}
function TIntegerArrayHelper.Maxi(const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
var
  h, i, s: Integer;
begin
  h := High(Self);
  if ((h = -1) or (ascending and (start > h)) or ((not ascending) and (start < 0))) then
    Exit(-1);
  case ascending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
  end;
end;

function TIntegerArrayHelper.Maxi(const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
begin
  Result := Self.Maxi(ascending, start);
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
  c, i, j, h, l: Integer;
  u: Boolean;
begin
  if (Length(Self) = 0) then
    Exit(0.0);
  l := Self[0];
  h := Self[0];
  SetLength(a, Length(Self));
  c := 0;
  for i := 0 to High(Self) do
  begin
    if (Self[i] < l) then
      l := Self[i]
    else
      if (Self[i] > h) then
        h := Self[i];
    u := True;
    for j := 0 to (c - 0) do
      if (a[j] = Self[i]) then
      begin
        u := False;
        Break;
      end;
    if u then
      a[c.Increase] := Self[i];
  end;
  Result := (Double(c) / (Abs(l - h) + 1));
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
 <TIntegerArrayHelper.Mode>
 @action: The value that occurs most frequently in arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Mode: Integer; cdecl;
var
  c, a: TIntegerArray;
  h, i, j, l: Integer;
begin
  h := High(Self);
  case h.Compare(0) of
    1:
    begin
      SetLength(c, 0);
      SetLength(a, 0);
      for i := 0 to High(Self) do
      begin
        l := -1;
        for j := 0 to High(a) do
        begin
          if (Self[i] = a[j]) then
          begin
            l := j;
            Break;
          end;
        end;
        if (l = -1) then
        begin
          a.Append(Self[i]);
          c.Append(1);
        end else
          Inc(c[l]);
      end;
      Result := a[c.Maxi];
    end;
    0: Result := 0;
    -1: Result := -2147483648;
  end;
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
            Swap(a[s], a[s + 1]);
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
 <TIntegerArrayHelper.Center>
 @action: The value at the center position of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Center: Integer; cdecl;
begin
  if (Length(Self) = 0) then
    Exit(-2147483648);
  Result := Self[Length(Self) div 2];
end;

{==============================================================================]
 <TIntegerArrayHelper.MFrequent>
 @action: Returns the most frequent/common value from arr.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.MFrequent(const null: Integer = -2147483648): Integer; cdecl;
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
      for x := 0 to High(Self) do
        Inc(b[(Self[x] - r.start)]);
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
 <TIntegerArrayHelper.LFrequent>
 @action: Returns the least frequent/common value from TIA.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArrayHelper.LFrequent(const null: Integer = -2147483648): Integer; cdecl;
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
      for x := 0 to High(Self) do
        Inc(b[(Self[x] - r.start)]);
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
  <TIntegerArrayHelper.BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArrayHelper.BubbleSort(const ascending: Boolean = True): Integer; cdecl;
var
  a, b: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  for a := 0 to (Result - 1) do
    for b := 1 to Result do
      if ((ascending and (Self[b - 1] > Self[b])) or (not ascending and (Self[b - 1] < Self[b]))) then
        Swap(Self[b], Self[b - 1]);
end;

{==============================================================================]
  <TIntegerArrayHelper.BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArrayHelper.BubbleSort2(const ascending: Boolean = True): Integer; cdecl;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    for a := 0 to (Result - 1) do
      for b := 1 to (Result - a) do
        if (Sign(Self[b] - Self[b - 1]) = o) then
          Swap(Self[b], Self[b - 1]);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BubbleSortOptimized>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArrayHelper.BubbleSortOptimized(const ascending: Boolean = True): Integer; cdecl;
var
  i, j, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  o := ascending.Select(-1, 1);
  for i := 0 to (Result - 1) do
  begin
    s := False;
    for j := 1 to (Result - i) do
      if (Sign(Self[j] - Self[j - 1]) = o) then
      begin
        Swap(Self[j - 1], Self[j]);
        s := True;
      end;
    if not s then
      Break;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.QuickSort(const ascending: Boolean = True): Integer; cdecl;
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
    o := ascending.Select(-1, 1);
    t := -1;
    qsPush(0, High(Self));
    r.Create(0, High(Self));
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
            Swap(Self[x.start], Self[x.stop]);
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
function TIntegerArrayHelper.QuickSort3W(const ascending: Boolean = True): Integer; cdecl;
  procedure SortLH(var arr: TIntegerArray; const L, H: Integer; const ascending: Boolean = True);
  var
    a, b, p, x, o: Integer;
  begin
    if (L >= H) then
      Exit;
    o := ascending.Select(-1, 1);
    x := arr[L];
    a := L;
    b := H;
    p := (L + 1);
    while (p <= b) do
      if (Sign(arr[p] - x) = o) then
      begin
        Swap(arr[a], arr[p]);
        Inc(p);
        Inc(a);
      end else
      if (Sign(arr[p] - x) = -o) then
      begin
        Swap(arr[b], arr[p]);
        Dec(b);
      end else
        Inc(p);
    SortLH(arr, L, (a - 1), ascending);
    SortLH(arr, (b + 1), H, ascending);
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    SortLH(Self, 0, Result, ascending);
end;

{==============================================================================]
  <TIntegerArrayHelper.QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.QSort(const ascending: Boolean = True): Integer; cdecl;
  procedure _QuickSort(var arr: TIntegerArray; const start, stop: Integer; const ascending: Boolean = True);
  var
    p, o: Integer;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := ascending.Select(-1, 1);
      p := arr[(start + stop) div 2];
      s.Create(start, stop);
      repeat
        while (Sign(arr[s.start] - p) = o) do
          Inc(s.start);
        while (Sign(arr[s.stop] - p) = -o) do
          Dec(s.stop);
        if (s.start <= s.stop) then
        begin
          Swap(arr[s.start], arr[s.stop]);
          Inc(s.start);
          Dec(s.stop);
        end;
      until (s.start > s.stop);
      if (start < s.stop) then
        _QuickSort(arr, start, s.stop, ascending);
      if (s.start < stop) then
        _QuickSort(arr, s.start, stop, ascending);
    end;
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    _QuickSort(Self, 0, Result, ascending);
end;

{==============================================================================]
  <TIntegerArrayHelper.CoctailSort>
  @action: CoctailSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.CoctailSort(const ascending: Boolean = True): Integer; cdecl;
var
  i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    repeat
      s := False;
      for i := 0 to (Result - 1) do
        if (Sign(Self[i + 1] - Self[i]) = o) then
        begin
          Swap(Self[i], Self[i + 1]);
          s := True;
        end;
      if not s then
        Break;
      s := False;
      for i := (Result - 1) downto 0 do
         if (Sign(Self[i + 1] - Self[i]) = o) then
        begin
          Swap(Self[i], Self[i + 1]);
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
function TIntegerArrayHelper.CoctailSort2(const ascending: Boolean = True): Integer; cdecl;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    b := -1;
    e := (Length(Self) - 2);
    repeat
      s := False;
      Inc(b);
      for i := b to e do
        if not (Sign(Self[i] - Self[i + 1]) = o) then
        begin
          Swap(Self[i], Self[i + 1]);
          s := True;
        end;
      if not s then
        Break;
      s := False;
      Dec(e);
      for i := e downto b do
        if not (Sign(Self[i] - Self[i + 1]) = o) then
        begin
          Swap(Self[i], Self[i + 1]);
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
function TIntegerArrayHelper.CombSort(const ascending: Boolean = True): Integer; cdecl;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
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
          Swap(Self[i], Self[i + g]);
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
function TIntegerArrayHelper.GnomeSort(const ascending: Boolean = True): Integer; cdecl;
var
  o, p, t: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    p := 1;
    while (p < (Result + 1)) do
      if (Sign(Self[p] - Self[p - 1]) = o) then
      begin
        Swap(Self[p], Self[p - 1]);
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
function TIntegerArrayHelper.GnomeSortOptimized(const ascending: Boolean = True): Integer; cdecl;
var
  p, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    p := 1;
    l := 0;
    while (p < Length(Self)) do
      if (Sign(Self[p] - Self[p - 1]) = o) then
      begin
        Swap(Self[p], Self[p - 1]);
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
function TIntegerArrayHelper.HeapSort(const ascending: Boolean = True): Integer; cdecl;
var
  a, b, r, c, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
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
          Swap(Self[r], Self[c]);
          r := c;
        end else
          Break;
      end;
      a := (a - 1);
    end;
    while (b > 0) do
    begin
      Swap(Self[0], Self[b]);
      b := (b - 1);
      r := 0;
      while (((r * 2) + 1) <= b) do
      begin
        c := ((r * 2) + 1);
        if ((c < b) and (Sign(Self[c] - Self[c + 1]) = o)) then
          c := (c + 1);
        if (Sign(Self[r] - Self[c]) = o) then
        begin
          Swap(Self[r], Self[c]);
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
function TIntegerArrayHelper.InsertionSort(const ascending: Boolean = True): Integer; cdecl;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    for a := 1 to Result do
      for b := a downto 1 do
      begin
        if not (Sign(Self[b] - Self[b - 1]) = o) then
          Break;
        Swap(Self[b], Self[b - 1]);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSort>
  @action: SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSort(const ascending: Boolean = True): Integer; cdecl;
var
  c, t, m, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    for c := 0 to Result do
    begin
      m := c;
      for t := (c + 1) to Result do
        if (Sign(Self[t] - Self[m]) = o) then
          m := t;
      Swap(Self[m], Self[c]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSortBidirectional(const ascending: Boolean = True): Integer; cdecl;
var
  a, b, x, i, t, h, l, s, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    t := Length(Self);
    s := ((t - 1) div 2);
    for i := 0 to s do
    begin
      l := i;
      h := ((t - 1) - i);
      a := l;
      b := h;
      if (Sign(Self[l] - Self[h]) = -o) then
        Swap(Self[h], Self[l]);
      for x := (a + 1) to (b - 1) do
        if (Sign(Self[x] - Self[l]) = o) then
          l := x
        else
          if (Sign(Self[x] - Self[h]) = -o) then
            h := x;
      if (l <> a) then
        Swap(Self[a], Self[l]);
      if (h <> b) then
        Swap(Self[b], Self[h]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.SelectionSortBidirectional2(const ascending: Boolean = True): Integer; cdecl;
var
  a, b, x, i, l, s, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    l := Length(Self);
    s := ((l - 1) div 2);
    for i := 0 to s do
    begin
      a := i;
      b := ((l - 1) - i);
      if (Sign(Self[b] - Self[a]) = o) then
        Swap(Self[a], Self[b]);
      for x := (a + 1) to (b - 1) do
        if (Sign(Self[x] - Self[a]) = o) then
          Swap(Self[a], Self[x])
        else
          if (Sign(Self[x] - Self[b]) = -o) then
            Swap(Self[x], Self[b]);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.PancakeSort>
  @action: PancakeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.PancakeSort(const ascending: Boolean = True): Integer; cdecl;
var
  i, j, l, m, x, o: Integer;
begin
  Result := High(Self);
  if (Result > 0 )then
  begin
    o := ascending.Select(-1, 1);
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
        Swap(Self[x], Self[m - (x - l)]);
      for x := l to (((i - l) - 1) div 2) do
        Swap(Self[x], Self[i - (x - l)]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.MergeSort>
  @action: MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.MergeSort(const ascending: Boolean = True): Integer; cdecl;
  procedure Merge(var arr, tmp: TIntegerArray; const Lo, Hi: Integer; const ascending: Boolean = True);
  var
    L, R, i, m, o: Integer;
  begin
    if (Lo >= Hi) then
      Exit;
    o := ascending.Select(-1, 1);
    m := (Lo + (Hi - Lo) div 2);
    Merge(arr, tmp, Lo, m, ascending);
    Merge(arr, tmp, (m + 1), Hi, ascending);
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
    Merge(Self, t, 0, Result, ascending);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.MergeSortBU>
  @action: Bottom-up MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.MergeSortBU(const ascending: Boolean = True): Integer; cdecl;
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
          if ((ascending and (t[l] <= t[r])) or (not ascending and (t[l] >= t[r]))) then
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
function TIntegerArrayHelper.ShellSort(const ascending: Boolean = True): Integer; cdecl;
var
  x, a, b, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
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
              Swap(Self[b], Self[b - x]);
              b := (b - x);
            end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(Self[1] - Self[0]) = o) then
        Swap(Self[0], Self[1]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BSort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const ascending: Boolean = True): Integer; cdecl;
var
  i, j, a, l, r, m, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
    o := ascending.Select(-1, 1);
  for i := 1 to Result do
  begin
    a := Self[i];
    l := 0;
    r := (i - 1);
    while (l <= r) do
    begin
      m := ((l + r) div 2);
      if (Sign(a - Self[m]) = o) then
        r := (m - 1)
      else
        l := (m + 1);
    end;
    for j := (i - 1) downto l do
      Self[j + 1] := Self[j];
    Self[l] := a;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const ascending: Boolean = True): Integer; cdecl;
var
  j, l, h, m, p, i, a, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := ascending.Select(-1, 1);
    for j := 1 to Result do
    begin
      a := Self[j];
      l := 0;
      h := j;
      while (l < h) do
      begin
        m := ((l + h) div 2);
        if (Sign(Self[m] - a) = o) then
          l := (m + 1)
        else
          h := m;
      end;
      p := l;
      for i := j downto (p + 1) do
        Self[i] := Self[i - 1];
      Self[p] := a;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const ascending: Boolean = True): TIntegerArray; cdecl;
var
  j, l, h, m, p, i, n, a, o: Integer;
begin
  n := Length(Self);
  SetLength(Result, n);
  if (n > 0) then
  begin
    o := ascending.Select(-1, 1);
    Result[0] := Self[0];
    for j := 1 to (n - 1) do
    begin
      a := Self[j];
      l := 0;
      h := j;
      while (l < h) do
      begin
        m := ((l + h) div 2);
        if (Sign(Result[m] - a) = o) then
          l := (m + 1)
        else
          h := m;
      end;
      p := l;
      for i := j downto (p + 1) do
        Result[i] := Result[i - 1];
      Result[p] := a;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both ascending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  l, m, h, o: Integer;
begin
  l := 0;
  h := Length(Self);
  o := ascending.Select(1, -1);
  while (l < h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) < (o * x)) then
      l := (m + 1)
    else
      h := m;
  end;
  Result := l;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both ascending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  l, m, h, o: Integer;
begin
  l := 0;
  h := Length(Self);
  o := ascending.Select(1, -1);
  while (l < h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) <= (o * x)) then
      l := (m + 1)
    else
      h := m;
  end;
  Result := l;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both ascending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  l, m, h, o: Integer;
begin
  Result := -1;
  l := 0;
  h := Length(Self);
  o := ascending.Select(1, -1);
  while (l < h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) < (o * x)) then
      l := (m + 1)
    else
      h := m;
  end;
  if ((l < Length(Self)) and (Self[l] = x)) then
    Result := l;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both ascending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  l, m, h, o: Integer;
begin
  Result := -1;
  l := 0;
  h := Length(Self);
  o := ascending.Select(1, -1);
  while (l < h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) <= (o * x)) then
      l := (m + 1)
    else
      h := m;
  end;
  if ((l > 0) and (Self[l - 1] = x)) then
    Result := (l - 1);
end;

{==============================================================================]
  <TIntegerArrayHelper.BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  l, h, m, o: Integer;
begin
  Result := -1;
  l := 0;
  h := High(Self);
  o := ascending.Select(1, -1);
  while ((l <= h) and (Result = -1)) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) = (o * x)) then
      Result := m
    else
      if ((o * Self[m]) < (o * x)) then
        l := (m + 1)
      else
        h := (m - 1);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryContains>
  @action: Binary Contains function for TIntegerArrays.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryContains(const x: Integer; const ascending: Boolean = True): Boolean; cdecl;
begin
  Result := (Self.BinarySearch(x, ascending) > -1);
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both ascending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const ascending: Boolean = True): TRange; cdecl;
begin
  Result.start := Self.BinaryPosL(x, ascending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, ascending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const ascending: Boolean = True): TRange; cdecl;
var
  s, l, h, m, o: Integer;
  r: Boolean;
begin
  r := False;
  l := 0;
  h := High(Self);
  s := h;
  o := ascending.Select(1, -1);
  while ((l <= h) and (not r)) do
  begin
    m := ((l + h) div 2);
    r := ((o * Self[m]) = (o * x));
    if r then
	begin
      Result.Create(m, m);
      while ((Result.start > 0) and (Self[Result.start - 1] = x)) do
        Dec(Result.start);
      while ((Result.stop < s) and (Self[Result.stop + 1] = x)) do
        Inc(Result.stop);
    end else
      if ((o * Self[m]) < (o * x)) then
        l := (m + 1)
      else
        h := (m - 1);
  end;
  if not r then
    Result.Create(-1, -1);
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
var
  h, m, i, o: Integer;
begin
  Result := 0;
  h := High(Self);
  o := ascending.Select(1, -1);
  while (Result <= h) do
  begin
    m := ((Result + h) div 2);
    if ((o * Self[m]) < (o * x)) then
      Result := (m + 1)
    else
      h := (m - 1);
  end;
  SetLength(Self, (Length(Self) + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := x;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const ascending: Boolean = True): TIntegerArray; cdecl;
var
  l, h, m, p, i, o: Integer;
begin
  l := 0;
  h := High(Self);
  o := ascending.Select(1, -1);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) < (o * x)) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  p := l;
  SetLength(Result, (Length(Self) + 1));
  for i := 0 to (p - 1) do
    Result[i] := Self[i];
  Result[p] := x;
  for i := p to High(Self) do
    Result[i + 1] := Self[i];
end;

{==============================================================================]
  <TIntegerArrayHelper.BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const ascending: Boolean = True): Integer; cdecl;
var
  l, h, m, o: Integer;
  f: TRange;
begin
  Result := -1;
  f := x.Normalize;
  l := 0;
  h := High(Self);
  o := ascending.Select(1, -1);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) < (o * f.start)) then
      l := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        h := (m - 1)
    else
    begin
      Result := m;
      h := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (ascending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const ascending: Boolean = True): Integer; cdecl;
var
  l, h, m, o: Integer;
  f: TRange;
begin
  Result := -1;
  f := x.Normalize;
  l := 0;
  h := High(Self);
  o := ascending.Select(1, -1);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if ((o * Self[m]) < (o * f.start)) then
      l := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        h := (m - 1)
      else
      begin
        Result := m;
        l := (m + 1);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryUnique>
  @action: Binary Search-based Unique method.
  @note: Alternative for TArray_Unique, for TIntegerArrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnique(const ascending: Boolean = True): Integer; cdecl;
var
  i, o: Integer;
begin
  Result := 0;
  if (High(Self) = -1) then
    Exit;
  o := ascending.Select(-1, 1);
  for i := 1 to High(Self) do
    if (Sign(Self[Result] - Self[i]) = o) then
      Self[Result.Increment] := Self[i];
  Result := (Result + 1);
  SetLength(Self, Result);
end;

{==============================================================================]
  <TIntegerArrayHelper.BinaryUniqued>
  @action: Binary Search-based Uniqued method.
  @note: Alternative for TArray_Uniqued, for TIntegerArrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniqued(const ascending: Boolean = True): TIntegerArray; cdecl;
var
  i, o, r: Integer;
begin
  SetLength(Result, Length(Self));
  if (High(Self) = -1) then
    Exit;
  r := 0;
  o := ascending.Select(-1, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Sign(Result[r] - Self[i]) = o) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
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
        begin
          SetLength(Result[r], 1);
          Result[r.Increase][0] := Self[i];
        end;
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
  h, i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  h := High(Self);
  if (h > -1) then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Length(a));
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to h do
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
      begin
        SetLength(Result[r], 1);
        Result[r.Increase][0] := a[i];
      end;
    end;
    SetLength(a, 0);
  end;
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
        begin
          SetLength(Result[r], 1);
          Result[r.Increase][0] := Self[i];
        end;
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
  h, i, j, r, l: Integer;
  s: TRange;
  m: Boolean;
begin
  h := High(Self);
  if (h > -1) then
  begin
    a := Self.BinarySorted;
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to h do
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
      begin
        SetLength(Result[r], 1);
        Result[r.Increase][0] := a[i];
      end;
    end;
  end;
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
  <TIntegerArrayHelper.Invert>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
[==============================================================================}
function TIntegerArrayHelper.Invert: TIntegerArray; cdecl;
var
  c, l, i, x, y, r: Integer;
  b: TBooleanArray;
  a: TRange;
begin
  r := 0;
  y := High(Self);
  if (y > 0) then
  begin
    a := Self.Bounds;
    if (a.start <> a.stop) then
    begin
      c := 0;
      l := a.Size;
      b.Create(l, False);
      for x := 0 to y do
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
