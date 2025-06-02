{==============================================================================]
  <TIntegerArray_Descending>
  @action: Returns true if array arr is in descending order.
  @note: CAUTION! Does not work with arrays that contain only unique values.
         [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function TIntegerArray_Descending(const arr: TIntegerArray): Boolean; cdecl;
var
  i: Int32;
begin
  Result := False;
  for i := 1 to High(arr) do
    if (arr[i] > arr[(i - 1)]) then
      Exit(False)
    else
      Result := (Result or (arr[i] < arr[(i - 1)]));
end;

{==============================================================================]
  <TIntegerArray_Asscending>
  @action: Returns true if array arr is in asscending order.
  @note: CAUTION! Does not work with arrays that contain only unique values.
         [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function TIntegerArray_Ascending(const arr: TIntegerArray): Boolean; cdecl;
var
  i: Int32;
begin
  Result := False;
  for i := 1 to High(arr) do
    if (arr[i] < arr[(i - 1)]) then
      Exit(False)
    else
      Result := (Result or (arr[i] > arr[(i - 1)]));
end;

{==============================================================================]
  <TIntegerArray_Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArray_Bounds(const arr: TIntegerArray): TRange; cdecl;
var
  i: Int32;
begin
  if (High(arr) > -1) then
    Result := TRange_Create(arr[0], arr[0]);
  for i := 1 to High(arr) do
    if (arr[i] < Result.start) then
      Result.start := arr[i]
    else
      if (arr[i] > Result.stop) then
        Result.stop := arr[i];
end;

{==============================================================================]
  <TIntegerArray_Min>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function TIntegerArray_Min(const arr: TIntegerArray): Int32; cdecl;
var
  i: Int32;
begin
  if (High(arr) > -1) then
    Result := arr[0];
  for i := 1 to High(arr) do
    if (arr[i] < Result) then
      Result := arr[i];
end;

{==============================================================================]
  <TIntegerArray_Max>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function TIntegerArray_Max(const arr: TIntegerArray): Int32; cdecl;
var
  i: Int32;
begin
  if (High(arr) > -1) then
    Result := arr[0];
  for i := 1 to High(arr) do
    if (arr[i] < Result) then
      Result := arr[i];
end;

{==============================================================================]
  <TIntegerArray_Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with ascending as False.
[==============================================================================}
function TIntegerArray_Mini(const arr: TIntegerArray; const ascending: Boolean = True; const start: Int32 = -1): Int32; overload; cdecl;
var
  h, i, s: Int32;
begin
  h := High(arr);
  if ((h = -1) or (ascending and (start > h)) or ((not ascending) and (start < 0))) then
    Exit(-1);
  case ascending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (arr[i] < arr[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (arr[i] < arr[Result]) then
          Result := i;
    end;
  end;
end;

function TIntegerArray_Mini(const arr: TIntegerArray; const start: Int32; const ascending: Boolean = True): Int32; overload; cdecl;
begin
  Result := TIntegerArray_Mini(arr, ascending, start);
end;

{==============================================================================]
  <TIntegerArray_Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with ascending as False.
[==============================================================================}
function TIntegerArray_Maxi(const arr: TIntegerArray; const ascending: Boolean = True; const start: Int32 = -1): Int32; overload; cdecl;
var
  h, i, s: Int32;
begin
  h := High(arr);
  if ((h = -1) or (ascending and (start > h)) or ((not ascending) and (start < 0))) then
    Exit(-1);
  case ascending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (arr[i] > arr[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (arr[i] > arr[Result]) then
          Result := i;
    end;
  end;
end;

function TIntegerArray_Maxi(const arr: TIntegerArray; const start: Int32; const ascending: Boolean = True): Int32; overload; cdecl;
begin
  Result := TIntegerArray_Maxi(arr, ascending, start);
end;

{==============================================================================]
 <TIntegerArray_Sum>
 @action: Returns the sum of all arr values together.
 @note: None
[==============================================================================}
function TIntegerArray_Sum(const arr: TIntegerArray): Int64; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + arr[i]);
end;

{==============================================================================]
 <TIntegerArray_Density>
 @action: Returns the calculated density from given arr.
 @note: None
[==============================================================================}
function TIntegerArray_Density(const arr: TIntegerArray): Double; cdecl;
var
  a: TIntegerArray;
  c, i, j, h, l: Int32;
  u: Boolean;
begin
  if (Length(arr) = 0) then
    Exit(0.0);
  l := arr[0];
  h := arr[0];
  SetLength(a, Length(arr));
  c := 0;
  for i := 0 to High(arr) do
  begin
    if (arr[i] < l) then
      l := arr[i]
    else
      if (arr[i] > h) then
        h := arr[i];
    u := True;
    for j := 0 to (c - 0) do
      if (a[j] = arr[i]) then
      begin
        u := False;
        Break;
      end;
    if u then
    begin
      a[c] := arr[i];
      Inc(c);
    end;
  end;
  Result := (Double(c) / (Abs(l - h) + 1));
end;

{==============================================================================]
 <TIntegerArray_Mean>
 @action: The sum of all arr values divided by the length of arr.
 @note: None
[==============================================================================}
function TIntegerArray_Mean(const arr: TIntegerArray): Double; cdecl;
begin
  Result := (TIntegerArray_Sum(arr) / Length(arr));
end;

{==============================================================================]
 <TIntegerArray_Mode>
 @action: The value that occurs most frequently in arr.
 @note: None
[==============================================================================}
function TIntegerArray_Mode(const arr: TIntegerArray): Int32; cdecl;
var
  c, a: TIntegerArray;
  i, j, l: Int32;
begin
  case Int32_Compare(High(arr), 0) of
    1:
    begin
      SetLength(c, 0);
      SetLength(a, 0);
      for i := 0 to High(arr) do
      begin
        l := -1;
        for j := 0 to High(a) do
        begin
          if (arr[i] = a[j]) then
          begin
            l := j;
            Break;
          end;
        end;
        if (l = -1) then
        begin
          TArray_Append(a, arr[i]);
          TArray_Append(c, 1);
        end else
          Inc(c[l]);
      end;
      Result := a[TIntegerArray_Maxi(c)];
    end;
    0: Result := 0;
    -1: Result := -2147483648;
  end;
end;

{==============================================================================]
 <TIntegerArray_Median>
 @action: The middle value when the arr is sorted:
          -Odd number of elements => the exact middle.
          -Even number => the average of the two middle elements.
 @note: None
[==============================================================================}
function TIntegerArray_Median(const arr: TIntegerArray): Double; cdecl;
var
  a: TIntegerArray;
  i, j, n, t, s: Int32;
begin
  n := Length(arr);
  if (n = 0) then
    Exit(-2147483648);
  a := Copy(arr, 0, n);
  for i := 0 to (n - 2) do
    if a[i] > a[(i + 1)] then
    begin
      for j := 0 to (n - 2) do
        for s := 0 to ((n - j) - 2) do
          if (a[s] > a[(s + 1)]) then
          begin
            t := a[s];
            a[s] := a[(s + 1)];
            a[(s + 1)] := t;
          end;
      Break;
    end;
  if ((n mod 2) = 1) then
    Result := a[(n div 2)]
  else
    Result := ((a[n div 2 - 1] + a[(n div 2)]) / 2);
end;

{==============================================================================]
 <TIntegerArray_Middle>
 @action: The value(s) at the center position(s) of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function TIntegerArray_Middle(const arr: TIntegerArray): Double; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  if (l = 0) then
    Exit(-2147483648);
  if ((l mod 2) = 1) then
    Result := arr[(l div 2)]
  else
    Result := ((arr[((l div 2) - 1)] + arr[(l div 2)]) / 2.0);
end;

{==============================================================================]
 <TIntegerArray_Center>
 @action: The value at the center position of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function TIntegerArray_Center(const arr: TIntegerArray): Int32; cdecl;
begin
  if (Length(arr) = 0) then
    Exit(-2147483648);
  Result := arr[(Length(arr) div 2)];
end;

{==============================================================================]
 <TIntegerArray_MostFrequent>
 @action: Returns the most frequent/common value from arr.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArray_MostFrequent(const arr: TIntegerArray; const null: Int32 = -2147483648): Int32; cdecl;
var
  x, t: Int32;
  b: TIntegerArray;
  r: TRange;
begin
  case Int32_Compare(High(arr), 0) of
    1:
    begin
      r := TIntegerArray_Bounds(arr);
      SetLength(b, TRange_Size(r));
      for x := 0 to (r.stop - r.start) do
        b[x] := 0;
      for x := 0 to High(arr) do
        Inc(b[(arr[x] - r.start)]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if (b[x] > b[t]) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := arr[0];
    -1: Result := null;
  end;
end;

{==============================================================================]
 <TIntegerArray_LeastFrequent>
 @action: Returns the least frequent/common value from TIA.
 @note: Be careful with values! Try to avoid using too low or high values!
        Such as: -200,000,000 or +200,000,000. Heavy memory-usage could possibly cause crashing.
[==============================================================================}
function TIntegerArray_LeastFrequent(const arr: TIntegerArray; const null: Int32 = -2147483648): Int32; cdecl;
var
  x, t: Int32;
  b: TIntegerArray;
  r: TRange;
begin
  case Int32_Compare(High(arr), 0) of
    1:
    begin
      r := TIntegerArray_Bounds(arr);
      SetLength(b, TRange_Size(r));
      for x := 0 to (r.stop - r.start) do
        b[x] := 0;
      for x := 0 to High(arr) do
        Inc(b[(arr[x] - r.start)]);
      t := 0;
      for x := 0 to (r.stop - r.start) do
        if ((b[x] > 0) and (b[x] < b[t])) then
          t := x;
      Result := (t + r.start);
      SetLength(b, 0);
    end;
    0: Result := arr[0];
    -1: Result := null;
  end;
end; 

{==============================================================================]
  <TIntegerArray_BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArray_BubbleSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  a, b: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  for a := 0 to (Result - 1) do
    for b := 1 to Result do
      if ((ascending and (arr[(b - 1)] > arr[b])) or (not ascending and (arr[(b - 1)] < arr[b]))) then
        Swap(arr[b], arr[(b - 1)]);
end;

{==============================================================================]
  <TIntegerArray_BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArray_BubbleSort2(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  a, b, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    for a := 0 to (Result - 1) do
      for b := 1 to (Result - a) do
        if (Sign(arr[b] - arr[(b - 1)]) = o) then
          Swap(arr[b], arr[(b - 1)]);
  end;
end;

{==============================================================================]
  <TIntegerArray_BubbleSortOptimized>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to ascending and descending order. Returns High(arr)!
[==============================================================================}
function TIntegerArray_BubbleSortOptimized(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  i, j, o: Int32;
  s: Boolean;
begin
  Result := High(arr);
  if (Result < 1) then
    Exit;
  o := Boolean_X(ascending, -1, 1);
  for i := 0 to (Result - 1) do
  begin
    s := False;
    for j := 1 to (Result - i) do
      if (Sign(arr[j] - arr[(j - 1)]) = o) then
      begin
        Swap(arr[(j - 1)], arr[j]);
        s := True;
      end;
    if not s then
      Break;
  end;
end;

{==============================================================================]
  <TIntegerArray_QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function TIntegerArray_QuickSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  t, p, o: Int32;
  s: TRangeArray;
  x, r: TRange;
  procedure Push(const start, stop: Int32);
  begin
    Inc(t);
    SetLength(s, (t + 1));
    s[t].start := start;
    s[t].stop := stop;
  end;
  function Pop(out start, stop: Int32): Boolean;
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
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    t := -1;
    Push(0, High(arr));
    r := TRange_Create(0, High(arr));
    while Pop(r.start, r.stop) do
    begin
      while (r.start < r.stop) do
      begin
        x := r;
        p := arr[((r.start + r.stop) div 2)];
        while (x.start <= x.stop) do
        begin
          while (Sign(arr[x.start] - p) = o) do
            Inc(x.start);
          while (Sign(arr[x.stop] - p) = -o) do
            Dec(x.stop);
          if (x.start <= x.stop) then
          begin
            Swap(arr[x.start], arr[x.stop]);
            Inc(x.start);
            Dec(x.stop);
          end;
        end;
        if ((x.stop - r.start) < (r.stop - x.start)) then
        begin
          if (x.start < r.stop) then
            Push(x.start, r.stop);
          r.stop := x.stop;
        end else
        begin
          if (r.start < x.stop) then
            Push(r.start, x.stop);
          r.start := x.start;
        end;
	  end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function TIntegerArray_QuickSort3W(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
  procedure SortLH(var arr: TIntegerArray; const L, H: Int32; const ascending: Boolean = True);
  var
    a, b, p, x, o: Int32;
  begin
    if (L >= H) then
      Exit;
    o := Boolean_X(ascending, -1, 1);
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
  Result := High(arr);
  if (Result > 0) then
    SortLH(arr, 0, Result, ascending);
end;

{==============================================================================]
  <TIntegerArray_QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function TIntegerArray_QSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
  procedure QuickSort(var arr: TIntegerArray; const start, stop: Int32; const ascending: Boolean = True);
  var
    p, o: Int32;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := Boolean_X(ascending, -1, 1);
      p := arr[((start + stop) div 2)];
      s := TRange_Create(start, stop);
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
        QuickSort(arr, start, s.stop, ascending);
      if (s.start < stop) then
        QuickSort(arr, s.start, stop, ascending);
    end;
  end;
begin
  Result := High(arr);
  if (Result > 0) then
    QuickSort(arr, 0, Result, ascending);
end;

{==============================================================================]
  <TIntegerArray_CoctailSort>
  @action: CoctailSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_CoctailSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  i, o: Int32;
  s: Boolean;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    repeat
      s := False;
      for i := 0 to (Result - 1) do
        if (Sign(arr[(i + 1)] - arr[i]) = o) then
        begin
          Swap(arr[i], arr[(i + 1)]);
          s := True;
        end;
      if not s then
        Break;
      s := False;
      for i := (Result - 1) downto 0 do
         if (Sign(arr[(i + 1)] - arr[i]) = o) then
        begin
          Swap(arr[i], arr[(i + 1)]);
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <TIntegerArray_CoctailSort>
  @action: CoctailSort algorithm for TIntegerArrays.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function TIntegerArray_CoctailSort2(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  b, e, i, o: Int32;
  s: Boolean;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    b := -1;
    e := (Length(arr) - 2);
    repeat
      s := False;
      Inc(b);
      for i := b to e do
        if not (Sign(arr[i] - arr[(i + 1)]) = o) then
        begin
          Swap(arr[i], arr[(i + 1)]);
          s := True;
        end;
      if not s then
        Break;
      s := False;
      Dec(e);
      for i := e downto b do
        if not (Sign(arr[i] - arr[(i + 1)]) = o) then
        begin
          Swap(arr[i], arr[(i + 1)]);
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <TIntegerArray_CombSort>
  @action: CombSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_CombSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  i, g, o: Int32;
  s: Boolean;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    g := Length(arr);
    s := true;
    while ((g > 1) or s) do
    begin
      g := Trunc(g / 1.3);
      if (g < 1) then
        g := 1;
      s := False;
      for i := 0 to (Result - g) do
        if (Sign(arr[(i + g)] - arr[i]) = o) then
        begin
          Swap(arr[i], arr[(i + g)]);
          s := True;
        end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_GnomeSort>
  @action: GnomeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_GnomeSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  o, p, t: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    p := 1;
    while (p < (Result + 1)) do
      if (Sign(arr[p] - arr[(p - 1)]) = o) then
      begin
        Swap(arr[p], arr[(p - 1)]);
        if (p > 1) then
          Dec(p);
      end else
        Inc(p);
  end;
end;

function TIntegerArray_GnomeSortOptimized(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  p, l, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    p := 1;
    l := 0;
    while (p < Length(arr)) do
      if (Sign(arr[p] - arr[(p - 1)]) = o) then
      begin
        Swap(arr[p], arr[(p - 1)]);
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
  <TIntegerArray_HeapSort>
  @action: HeapSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_HeapSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  a, b, r, c, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    a := (Result div 2);
    b := Result;
    while (a >= 0) do
    begin
      r := a;
      while (((r * 2) + 1) <= Result) do
      begin
        c := ((r * 2) + 1);
        if ((c < Result) and (Sign(arr[c] - arr[(c + 1)]) = o)) then
          c := (c + 1);
        if (Sign(arr[r] - arr[c]) = o) then
        begin
          Swap(arr[r], arr[c]);
          r := c;
        end else
          Break;
      end;
      a := (a - 1);
    end;
    while (b > 0) do
    begin
      Swap(arr[0], arr[b]);
      b := (b - 1);
      r := 0;
      while (((r * 2) + 1) <= b) do
      begin
        c := ((r * 2) + 1);
        if ((c < b) and (Sign(arr[c] - arr[(c + 1)]) = o)) then
          c := (c + 1);
        if (Sign(arr[r] - arr[c]) = o) then
        begin
          Swap(arr[r], arr[c]);
          r := c;
        end else
          Break;
      end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_InsertionSort>
  @action: InsertionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_InsertionSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  a, b, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    for a := 1 to Result do
      for b := a downto 1 do
      begin
        if not (Sign(arr[b] - arr[(b - 1)]) = o) then
          Break;
        Swap(arr[b], arr[(b - 1)]);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArray_SelectionSort>
  @action: SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_SelectionSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  c, t, m, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    for c := 0 to Result do
    begin
      m := c;
      for t := (c + 1) to Result do
        if (Sign(arr[t] - arr[m]) = o) then
          m := t;
      Swap(arr[m], arr[c]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_SelectionSortBidirectional(var arr: TIntegerArray; const ascending: Boolean = True): Int32;
var
  a, b, x, i, t, h, l, s, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    t := Length(arr);
    s := ((t - 1) div 2);
    for i := 0 to s do
    begin
      l := i;
      h := ((t - 1) - i);
      a := l;
      b := h;
      if (Sign(arr[l] - arr[h]) = -o) then
        Swap(arr[h], arr[l]);
      for x := (a + 1) to (b - 1) do
        if (Sign(arr[x] - arr[l]) = o) then
          l := x
        else
          if (Sign(arr[x] - arr[h]) = -o) then
            h := x;
      if (l <> a) then
        Swap(arr[a], arr[l]);
      if (h <> b) then
        Swap(arr[b], arr[h]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_SelectionSortBidirectional2(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  a, b, x, i, l, s, o: Integer;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    l := Length(arr);
    s := ((l - 1) div 2);
    for i := 0 to s do
    begin
      a := i;
      b := ((l - 1) - i);
      if (Sign(arr[b] - arr[a]) = o) then
        Swap(arr[a], arr[b]);
      for x := (a + 1) to (b - 1) do
        if (Sign(arr[x] - arr[a]) = o) then
          Swap(arr[a], arr[x])
        else
          if (Sign(arr[x] - arr[b]) = -o) then
            Swap(arr[x], arr[b]);
      end;
  end;
end;

{==============================================================================]
  <TIntegerArray_PancakeSort>
  @action: PancakeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_PancakeSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  i, j, l, m, x, o: Int32;
begin
  Result := High(arr);
  if (Result > 0 )then
  begin
    o := Boolean_X(ascending, -1, 1);
    l := 0;
    for i := Result downto l do
    begin
      m := i;
      for j := l to (i - 1) do
        if (Sign(arr[m] - arr[j]) = o) then
          m := j;
      if (m = i) then
        Continue;
      if (m <> l) then
      for x := l to (((m - l) - 1) div 2) do
        Swap(arr[x], arr[(m - (x - l))]);
      for x := l to (((i - l) - 1) div 2) do
        Swap(arr[x], arr[(i - (x - l))]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_MergeSort>
  @action: MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_MergeSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
  procedure Merge(var arr, tmp: TIntegerArray; const Lo, Hi: Int32; const ascending: Boolean = True);
  var
    L, R, i, m, o: Int32;
  begin
    if (Lo >= Hi) then
      Exit;
    o := Boolean_X(ascending, -1, 1);
    m := (Lo + (Hi - Lo) div 2);
    Merge(arr, tmp, Lo, m, ascending);
    Merge(arr, tmp, (m + 1), Hi, ascending);
    L := Lo;
    R := (m + 1);
    for i := Lo to Hi do
      tmp[i] := arr[i];
    for i := Lo to Hi do
      if (L > m) then
      begin
        arr[i] := tmp[R];
        Inc(R);
      end else
        if (R > Hi) then
        begin
          arr[i] := tmp[L];
          Inc(L);
        end else
          if (Sign(tmp[R] - tmp[L]) = o) then
          begin
            arr[i] := tmp[R];
            Inc(R);
          end else
          begin
            arr[i] := tmp[L];
            Inc(L);
          end;
  end;
var
  l: Int32;
  t: TIntegerArray;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    Merge(arr, t, 0, Result, ascending);
  end;
end;

{==============================================================================]
  <TIntegerArray_MergeSortBU>
  @action: Bottom-up MergeSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_MergeSortBU(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  t: TIntegerArray;
  n, w, i, a, b, m, l, r, k: Int32;
begin
  Result := High(arr);
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
          t[k] := arr[k];
        L := a;
        R := (m + 1);
        k := a;
        while ((l <= m) and (r <= b)) do
        begin
          if ((ascending and (t[l] <= t[r])) or (not ascending and (t[l] >= t[r]))) then
          begin
            arr[k] := t[l];
            Inc(l);
          end else
          begin
            arr[k] := t[r];
            Inc(r);
          end;
          Inc(k);
        end;
        while (l <= m) do
        begin
          arr[k] := t[l];
          Inc(l);
          Inc(k);
        end;
        while (r <= b) do
        begin
          arr[k] := t[r];
          Inc(r);
          Inc(k);
        end;
        i := (i + (2 * w));
      end;
      w := (w * 2);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_ShellSort>
  @action: ShellSort algorithm for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_ShellSort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  x, a, b, l, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    case (Result > 1) of
      True:
      begin
        l := Length(arr);
        x := 0;
        while (x < (l div 3)) do
          x := ((x * 3) + 1);
        while (x >= 1) do
        begin
          for a := x to (l - 1) do
          begin
            b := a;
            while ((b >= x) and (Sign(arr[b] - arr[(b - x)]) = o)) do
            begin
              Swap(arr[b], arr[(b - x)]);
              b := (b - x);
            end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(arr[1] - arr[0]) = o) then
        Swap(arr[0], arr[1]);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArray_BinarySort(var arr: TIntegerArray; const ascending: Boolean = True): Int32; cdecl;
var
  j, l, h, m, p, i, a, o: Int32;
begin
  Result := High(arr);
  if (Result > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    for j := 1 to Result do
    begin
      a := arr[j];
      l := 0;
      h := j;
      while (l < h) do
      begin
        m := ((l + h) div 2);
        if (Sign(arr[m] - a) = o) then
          l := (m + 1)
        else
          h := m;
      end;
      p := l;
      for i := j downto (p + 1) do
        arr[i] := arr[(i - 1)];
      arr[p] := a;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArray_BinarySorted(const arr: TIntegerArray; const ascending: Boolean = True): TIntegerArray; cdecl;
var
  j, l, h, m, p, i, n, a, o: Int32;
begin
  n := Length(arr);
  SetLength(Result, n);
  if (n > 0) then
  begin
    o := Boolean_X(ascending, -1, 1);
    Result[0] := arr[0];
    for j := 1 to (n - 1) do
    begin
      a := arr[j];
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
        Result[i] := Result[(i - 1)];
      Result[p] := a;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (ASCENDING ORDER)
[==============================================================================}
function TIntegerArray_BinarySearch(const arr: TIntegerArray; const x: Int32): Int32; cdecl;
var
  l, h, m: Int32;
begin
  Result := -1;
  l := 0;
  h := High(arr);
  while ((l <= h) and (Result = -1)) do
  begin
    m := ((l + h) div 2);
    if (arr[m] = x) then
      Result := m
    else
      if (arr[m] < x) then
        l := (m + 1)
      else
        h := (m - 1);
  end;
end;

{==============================================================================]
  <TIntegerArray_BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (ASCENDING ORDER)
[==============================================================================}
function TIntegerArray_BinaryAppend(var arr: TIntegerArray; const x: Int32): Int32; cdecl;
var
  h, m, i: Int32;
begin
  Result := 0;
  h := High(arr);
  while (Result <= h) do
  begin
    m := ((Result + h) div 2);
    if (arr[m] < x) then
      Result := (m + 1)
    else
      h := (m - 1);
  end;
  SetLength(arr, (Length(arr) + 1));
  for i := High(arr) downto (Result + 1) do
    arr[i] := arr[(i - 1)];
  arr[Result] := x;
end;

{==============================================================================]
  <TIntegerArray_BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (ASCENDING ORDER)
[==============================================================================}
function TIntegerArray_BinaryAdd(const arr: TIntegerArray; const x: Int32): TIntegerArray; cdecl;
var
  l, h, m, p, i: Int32;
begin
  l := 0;
  h := High(arr);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if (arr[m] < x) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  p := l;
  SetLength(Result, (Length(arr) + 1));
  for i := 0 to (p - 1) do
    Result[i] := arr[i];
  Result[p] := x;
  for i := p to High(arr) do
    Result[(i + 1)] := arr[i];
end;

{==============================================================================]
  <TIntegerArray_BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (ASCENDING ORDER)
[==============================================================================}
function TIntegerArray_BinarySearchF(const arr: TIntegerArray; const x: TRange): Int32; cdecl;
var
  l, h, m: Int32;
  f: TRange;
begin
  Result := -1;
  f := TRange_Normalize(x);
  l := 0;
  h := High(arr);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if (arr[m] < f.start) then
      l := (m + 1)
    else
      if (arr[m] > f.stop) then
        h := (m - 1)
    else
    begin
      Result := m;
      h := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray_BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (ASCENDING ORDER)
[==============================================================================}
function TIntegerArray_BinarySearchL(const arr: TIntegerArray; const x: TRange): Int32; cdecl;
var
  l, h, m: Int32;
  f: TRange;
begin
  Result := -1;
  f := TRange_Normalize(x);
  l := 0;
  h := High(arr);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if (arr[m] < f.start) then
      l := (m + 1)
    else
      if (arr[m] > f.stop) then
        h := (m - 1)
      else
      begin
        Result := m;
        l := (m + 1);
      end;
  end;
end;
