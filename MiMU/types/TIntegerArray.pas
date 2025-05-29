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
 @action: Returns the arithmetic mean of arr values.
 @note: None
[==============================================================================}
function TIntegerArray_Mean(const arr: TIntegerArray): Double; cdecl;
begin
  Result := (TIntegerArray_Sum(arr) / Length(arr));
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