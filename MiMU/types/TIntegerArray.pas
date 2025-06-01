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
