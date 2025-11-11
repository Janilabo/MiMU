{$DEFINE Integer}{$I config\Defines.inc}

{==============================================================================]
  <TIntegerArrayHelper.Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Bounds: TRange; overload;
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

function TIntegerArrayHelper.Bounds(var aSize: Integer): TRange; overload;
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
function TIntegerArrayHelper.BoundingRange: TRange;
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
function TIntegerArrayHelper.Boundaries: TRange;
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
function TIntegerArrayHelper.Range: TRange;
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
function TIntegerArrayHelper.Coverage: TRange;
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
function TIntegerArrayHelper.MinMax: TRange;
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
function TIntegerArrayHelper.Region: TRange; overload;
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
function TIntegerArrayHelper.Extent: TRange;
begin
  Result.Create(Self.MinVal, Self.MaxVal);
end;

{==============================================================================]
  <TIntegerArray.Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray;
begin
  Result := Self.Copy;
  TIA.Unique(Result);
end;

{==============================================================================]
  <TIntegerArrayHelper.Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray;
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
function TIntegerArrayHelper.Numberline: TIntegerArray;
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
function TIntegerArrayHelper.Sum: Int64;
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
function TIntegerArrayHelper.Density: Double;
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
function TIntegerArrayHelper.Occupancy: Double;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  Result := (Self.QuickSorted.Distinct / r.Construct(0, High(Self)).Size);
end;

{==============================================================================]
 <TIntegerArrayHelper.Saturated>
 @action: Returns the saturation of the integer array: fraction of the range
          covered by unique elements.
          0.0 = empty / no values, 1.0 = all possible values in range present.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Saturated: Double;
var
  m: specialize TFPGMap<Integer, Boolean>;
  i: Integer;
  r: TRange;
begin
  if Length(Self) = 0 then
    Exit(0.0);
  m := specialize TFPGMap<Integer, Boolean>.Create;
  r.Create(Self[0], Self[0]);
  try
    for i := 0 to High(Self) do
    begin
      r.Absorb(Self[i]);
      if (not m.IndexOf(Self[i]) >= 0) then
        m.Add(Self[i], True);
    end;
    if (r.Size = 0) then
      Result := 0.0
    else
      Result := (m.Count / r.Size);
  finally
    m.Free;
  end;
end;

{==============================================================================]
 <TIntegerArrayHelper.Mean>
 @action: The sum of all arr values divided by the length of arr.
 @note: None
[==============================================================================}
function TIntegerArrayHelper.Mean: Double;
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
function TIntegerArrayHelper.Median: Double;
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
function TIntegerArrayHelper.Middle: Double;
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
function TIntegerArrayHelper.MostFreq(const null: Integer = -2147483648): Integer;
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
function TIntegerArrayHelper.LeastFreq(const null: Integer = -2147483648): Integer;
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
  <TIntegerArray.Succ>
  @action: Returns the next array index (currentIndex + 1).
  @note: If the next index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Succ(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  if ((Result > High(Self)) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Pred>
  @action: Returns the previous array index (currentIndex - 1).
  @note: If the previous index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Pred(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := currentIndex - 1;
  if ((Result < 0) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Successor>
  @action: Returns the next valid array index in the specified direction.
  @note: If aAscending = True, moves forward; if False, moves backward.
         Skips over elements considered missing by the range.
         Returns -1 if the end of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Successor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(1, -1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Predecessor>
  @action: Returns the previous valid array index in the specified direction.
  @note: If aAscending = True, moves backward; if False, moves forward.
         Skips over elements considered missing by the range.
         Returns -1 if the beginning of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Predecessor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(-1, 1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Next>
 @action: Returns the next valid array index by moving forward (incrementing).
  @note: Starts from currentIndex + 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the end of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Next(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  while ((Result <= High(Self)) and range.Missing(Self[Result])) do
    Inc(Result);
  if (Result > High(Self)) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Previous>
  @action: Returns the previous valid array index by moving backward (decrementing).
  @note: Starts from currentIndex - 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the beginning of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Previous(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex - 1);
  while ((Result >= 0) and range.Missing(Self[Result])) do
    Dec(Result);
  if (Result < 0) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Navigate>
  @action: Returns the next valid array index in the specified direction.
  @note: Starts from currentIndex and moves forward if aAscending = True,
         backward if aAscending = False. Skips over any elements that are
         considered missing according to the provided range.
         Returns -1 if no valid element exists before reaching the array bounds.
[==============================================================================}
function TIntegerArrayHelper.Navigate(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  s: Integer;
begin
  s := aAscending.Select(1, -1);
  Result := (currentIndex + s);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + s);
  if (Result < 0) or (Result > High(Self)) then
    Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Advance>
  @action: Moves forward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the next value that falls
           within the specified range.
  @note: - Traverses one element at a time in the order defined by aAscending.
         - If the sequence order is broken (e.g., next value < previous in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the end of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Advance(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
    False:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
  end;
  Result := -1;
end;

{==============================================================================]
  <TIntegerArray.Retreat>
  @action: Moves backward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the previous value that falls
           within the specified range.
  @note: - Traverses one element at a time in reverse order, as defined by aAscending.
         - If the sequence order is broken (e.g., previous value > next in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the beginning of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Retreat(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
    False:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else
        if range.Contains(Self[Result]) then
          Exit(Result);
  end;
  Result := -1;
end;  

{==============================================================================]
  <TIntegerArrayHelper.RadixSort>
  @action: RadixSort for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.RadixSort(const aAscending: Boolean = True): Integer;
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
function TIntegerArrayHelper.Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Split(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Split(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Sblit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Sblit(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Groups>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the ones with same values.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
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
  a.BinaryPrune;
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
function TIntegerArrayHelper.Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Group(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Group(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Groub(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Groub(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Strict splitting!
[==============================================================================}
function TIntegerArrayHelper.Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Clique(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Clique(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
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
function TIntegerArrayHelper.Knit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Knit(0, diff);
end;

{==============================================================================]
  <TIntegerArrayHelper.Reflect>
  @action: Returns reversed array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reflected: TIntegerArray; overload;
var
  i: Integer;
  s: SizeInt;
begin
  SetLength(Result, Length(Self));
  s := SizeOf(Integer);
  for i := 0 to High(Self) do
    Move(Self[High(Self) - i], Result[i], s);
end;

{==============================================================================]
  <TIntegerArrayHelper.Reflect>
  @action: Reverses array.
  @note: Returns Length(Self)
[==============================================================================}
function TIntegerArrayHelper.Reflect: Integer; overload;
var
  r: TRange;
  s: SizeInt;
  b: array of Byte;
  x, y: PByte;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  s := SizeOf(Integer);
  SetLength(b, s);
  r.Create(-1, Result);
  x := PByte(@Self[r.start + 1]);
  y := PByte(@Self[r.stop - 1]);
  while (r.start.Increment < r.stop.Decrement) do
  begin
    Move(x^, b[0], s);
    Move(y^, x^, s);
    Move(b[0], y^, s);
    Inc(x, s);
    Dec(y, s);
  end;
end;

{==============================================================================]
  <TIntegerArrayHelper.Invert>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
[==============================================================================}
function TIntegerArrayHelper.Invert: TIntegerArray;
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
function TIntegerArrayHelper.Inverted(const arrBounds: TRange): TIntegerArray; overload;
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

function TIntegerArrayHelper.Inverted: TIntegerArray; overload;
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <TIntegerArrayHelper.Inverse>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverse(const arrBounds: TRange): TIntegerArray; overload;
var
  l, i: Integer;
  r: TRange;
  b: TBooleanArray;
begin
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

function TIntegerArrayHelper.Inverse: TIntegerArray; overload;
begin
  if (Length(Self) > 1) then
    Result := Self.Inverse(Self.Bounds)
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TIntegerArrayHelper.MinVal>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.MinVal: Integer; overload;
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
function TIntegerArrayHelper.MaxVal: Integer; overload;
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
function TIntegerArrayHelper.Minimum(var index: Integer): Integer; overload;
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
function TIntegerArrayHelper.Minimum: Integer; overload;
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
function TIntegerArrayHelper.Maximum(var index: Integer): Integer; overload;
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
function TIntegerArrayHelper.Maximum: Integer; overload;
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
function TIntegerArrayHelper.Mirror: Boolean;
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
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean;
var
  a: TIntegerArray;
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
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
function TIntegerArrayHelper.NoneOf(const forbidden: TIntegerArray): Boolean;
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
function TIntegerArrayHelper.AnyOf(const candidates: TIntegerArray): Boolean;
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
function TIntegerArrayHelper.AllOf(const candidates: TIntegerArray): Boolean;
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
function TIntegerArrayHelper.Charify: TCharArray; overload;
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
function TIntegerArrayHelper.Charify(var str: string): TCharArray; overload;
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
function TIntegerArrayHelper.Stringify: string; overload;
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
function TIntegerArrayHelper.Stringify(var chars: TCharArray): string; overload;
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
function TIntegerArrayHelper.Special: Boolean;
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
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.FilterEven>
  @action: Returns array without even values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.ExtractOdd>
  @action: Returns odd values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.FilterOdd>
  @action: Returns array without odd values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <TIntegerArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reinit: Integer; overload;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Integer)), 0);
end;

{==============================================================================]
  <TIntegerArrayHelper.Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Integer is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TIntegerArrayHelper.Attach(const items: TIntegerArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  i := Length(items);
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Integer)));
end;

{==============================================================================]
  <TIntegerArrayHelper.Embed>
  @action: Inserts the contents of another integer array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TIntegerArrayHelper.Embed(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Length(Self);
  l := Length(items);
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Integer)));
  Move(items[0], Self[p], (l * SizeOf(Integer)));
  Result := Length(Self);
end;

{==============================================================================]
 <TIntegerArray.Broaden>
 @action: Expands outward from the specified starting index to find the
          contiguous range of indexes whose values are contained within
          the given numeric range (rValues).
 @note: Returns <-1..-1> if the array is empty, the starting index is invalid,
        or the value at the starting index is not within rValues.
        The returned TRange represents indexes in the array, not values.
[==============================================================================}
function TIntegerArrayHelper.Broaden(const rValues: TRange; const aIndex: Integer): TRange; overload;
var
  i: Integer;
begin
  if (Self.Empty or (not InRange(aIndex, 0, High(Self))) or (not rValues.Contains(Self[aIndex]))) then
    Exit(TRange.Construct(-1, -1));
  Result.Create(aIndex);
  for i := (aIndex - 1) downto 0 do
    if rValues.Contains(Self[i]) then
      Result.start := i
    else
      Break;
  for i := (aIndex + 1) to High(Self) do
    if rValues.Contains(Self[i]) then
      Result.stop := i
    else
      Break;
end;

{==============================================================================]
 <TIntegerArray.Broaden>
 @action: Searches the array for the first element contained within rValues
          and returns the contiguous range of indexes around it that are
          also within rValues. Supports optimized search if the array is
          sorted.
 @note: Returns <-1..-1> if the array is empty or no elements match rValues.
        If sSorted is True, performs a binary search for each value in the
        numeric range; if False, performs a linear search. The returned
        TRange represents indexes in the array, not values.
[==============================================================================}
function TIntegerArrayHelper.Broaden(const rValues: TRange; const sSorted: Boolean = False): TRange; overload;
var
  a: Boolean;
  i, p: Integer;
begin
  if not Self.Empty then
  case sSorted of
    True:
    begin
      a := Self.TrendRising;
      for i := rValues.Minimum to rValues.Maximum do
      begin
        p := Self.BinarySearch(i, a);
        if (p > -1) then
          Exit(Self.Broaden(rValues, p));
      end;
    end;
    False:
    for i := 0 to High(Self) do
      if rValues.Contains(Self[i]) then
        Exit(Self.Broaden(rValues, i));
  end;
  Result.Create(-1);
end;

{==============================================================================]
  <TIntegerArray.ToRanges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray).
           Each range represents a sequence of consecutive numbers (ascending or descending)
           found in the array. A new range starts whenever the consecutive trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - Single-element arrays produce a single range with identical Start and Stop.
         - Two-element arrays produce a single range covering the two values.
         - Direction of each range (ascending or descending) is determined automatically.
         - Useful for compressing sequences or detecting consecutive runs in arrays.
[==============================================================================}
function TIntegerArrayHelper.ToRanges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  for i := 2 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i]);
      end;
    end;
  end;
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <TIntegerArray.ToRanges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction as indicated by aAscending.
           Each range extends in the requested direction until a break occurs.
  @note: - If aAscending = True, only ascending sequences (+1) are allowed in a range.
         - If aAscending = False, only descending sequences (-1) are allowed in a range.
         - Sequences that match the specified direction or repeat the same value
           are merged into the same range.
         - Returns empty array for empty input and single-element array produces
           a single-element range.
         - Useful when you want ranges restricted to a specific direction.
[==============================================================================}
function TIntegerArrayHelper.ToRanges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  for i := 1 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  end;
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <TIntegerArray.Ranges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray)
           using overlapping ranges. Each range represents a sequence of consecutive
           integers (ascending or descending) in the array. A new range starts from
           the previous range’s stop whenever the sequence trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - If the array has one element, the range has Start = Stop.
         - If the array has two elements, the range covers both values.
         - The direction (ascending/descending) is determined automatically.
         - Overlapping ensures that each new range starts from the last stop.
         - Useful for compressing sequences or detecting consecutive runs.
[==============================================================================}
function TIntegerArrayHelper.Ranges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  i := 2;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i.Decrement]);
      end;
    end;
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <TIntegerArray.Ranges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction (ascending or descending) using overlapping ranges.
           Each range starts from the previous range’s stop and continues in the
           specified direction until the trend breaks.
  @note: - If aAscending = True, ranges only include ascending steps.
         - If aAscending = False, ranges only include descending steps.
         - Repeated values (0 sign) are included in the same range.
         - Returns empty array for empty input; single-element arrays produce
           a single-element range.
         - Useful for generating directional ranges with overlaps.
[==============================================================================}
function TIntegerArrayHelper.Ranges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  i := 1;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <arr.IsMonotonic>
  @action: Returns True if the array elements are monotonic (entirely non-decreasing or non-increasing).
  @note: Works for empty and single-element arrays (they are trivially monotonic).
[==============================================================================}
function TIntegerArrayHelper.IsMonotonic: Boolean; overload;
var
  c, i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (c > 0) then
      D := False
    else
      if (c < 0) then
        A := False;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <arr.Monotonicity>
  @action:
    Determines whether the array is monotonic — that is, whether all its
    elements are entirely non-decreasing or entirely non-increasing.

    The function compares each element with the previous one, establishing
    a direction based on the first non-equal pair. If any subsequent element
    violates this direction, the function immediately returns False.
  @note:
    • Empty or single-element arrays are considered monotonic (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses Sign(A - B) to determine the direction between consecutive elements.
    • Short-circuits for efficiency — exits as soon as a violation is detected.
[==============================================================================}
function TIntegerArrayHelper.Monotonicity: Boolean; overload;
var
  s, d, i: Integer;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    if (s = 0) then
      Continue;
    if (d = 0) then
      d := s
    else if (s <> d) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <arr.Monotony>
    Determines whether the array is monotone (entirely non-decreasing or 
    entirely non-increasing).
  @note:
    • Empty or single-element arrays are considered monotone (trivially True).  
    • Equal adjacent elements do not affect monotonicity.  
    • Uses Sign(A - B) from Math to compute relative order.  
    • Short-circuits for efficiency — exits as soon as a reversal is detected.  
    • This version differs from the “direction-lock” version by using an
      accumulated trend variable instead of separate Booleans for ascending
      and descending.
[==============================================================================}
function TIntegerArrayHelper.Monotony: Boolean; overload;
var
  i, t, s: Integer;
begin
  t := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    t := (t or s);
    if (((t = 1) and (s = -1)) or ((t = -1) and (s = 1))) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <TIntegerArray.BSort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BSort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <TIntegerArray.BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BinarySort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <TIntegerArray.BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const aAscending: Boolean = True): TIntegerArray; var a: Integer; {$DEFINE Skeleton_BinarySorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <TIntegerArray.BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <TIntegerArray.BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <TIntegerArray.BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <TIntegerArray.BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <TIntegerArray.BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearch}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <TIntegerArray.BinarySeek>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <TIntegerArray.BinaryContains>
  @action: Binary Contains function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryContains}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <TIntegerArray.BinaryCount>
  @action: Binary Count function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryCount}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <TIntegerArray.BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <TIntegerArray.BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <TIntegerArray.BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryAppend}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <TIntegerArray.BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; {$DEFINE Skeleton_BinaryAdd}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <TIntegerArray.BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <TIntegerArray.BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <TIntegerArray.BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPrune}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPrune}

{==============================================================================]
  <TIntegerArray.BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPruned(const aAscending: Boolean = True): TIntegerArray; {$DEFINE Skeleton_BinaryPruned}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPruned}

{==============================================================================]
  <TIntegerArray.BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUndupe: Integer; var u: TIntegerArray; {$DEFINE Skeleton_BinaryUndupe}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <TIntegerArray.BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduped: TIntegerArray; {$DEFINE Skeleton_BinaryUnduped}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <TIntegerArray.BinaryUnified>
  @action: Binary Search-based Unified method.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.BinaryUnified(const dAscending: Boolean = True): TIntegerArray; var u: TIntegerArray; {$DEFINE Skeleton_BinaryUnified}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnified}

{==============================================================================]
  <TIntegerArray.BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryGrow}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <TIntegerArray.BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryShrink(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryShrink}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <TIntegerArray.BinaryLowerBound>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryLowerBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <TIntegerArray.BinaryUpperBound>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryUpperBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <TIntegerArray.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <TIntegerArray.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <TIntegerArray.BinarySpan>
  @action: Performs a binary search on a sorted integer array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TIntegerArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

{==============================================================================]
  <TIntegerArray.BinaryMerge>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

{==============================================================================]
  <TIntegerArray.BinaryMerged>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

{==============================================================================]
  <TIntegerArray.BinaryCombine>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <arr.BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted integer array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TIntegerArrayHelper.BinaryRemove(const val: Integer; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRemove}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRemove}

{==============================================================================]
  <arr.BinaryFind>
  @action: Performs a binary search on a sorted integer array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <arr.BinarySearchEx>
  @action: Performs a binary search on a sorted integer array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <arr.BinaryInsert>
  @action: Insert an integer into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TIntegerArrayHelper.BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryInsert}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryInsert}

{==============================================================================]
 <arr.BinarySearchRange>
 @action: Perform a binary search for a value within a specific index range.
 @note: Returns the index of the found element or -1 if not present.
        Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

{==============================================================================]
 <arr.BinaryDeduplicate>
 @action: Rebuilds the array in place by removing duplicate elements using binary search.
 @note: Creates a temporary copy of the original array and appends only unique values back.
        Returns the number of elements removed.
        Requires the array to be sorted (ascending or descending according to aAscending).
        Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload; var u: TIntegerArray; {$DEFINE Skeleton_BinaryDeduplicate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicate}

{==============================================================================]
 <arr.BinaryUnduplicate>
 @action: Removes duplicate elements from the array in place using binary search.
 @note: Keeps only the first occurrence of each unique value.
        Returns the number of elements removed.
        Requires the array to be sorted (ascending or descending as specified).
        Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnduplicate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicate}

{==============================================================================]
 <arr.BinaryDeduplicated>
 @action: Return a new array containing unique elements from the current one.
 @note: The original array remains unchanged.
        Uses binary search to avoid inserting duplicates.
        Sorting is recommended before calling for best results.
[==============================================================================}
function TIntegerArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryDeduplicated}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicated}

{==============================================================================]
 <arr.BinaryUnduplicated>
 @action: Return a deduplicated copy of the current array using in-place logic.
 @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
        Requires sorted input for correct results.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryUnduplicated}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
 <arr.BinaryCombined>
 @action: Merge two sorted arrays into one sorted array.
 @note: Both arrays must be sorted in the same order (ascending or descending).
        The result is a new array that combines both inputs, preserving order.
        Complexity: O(n + m)
[==============================================================================}
function TIntegerArrayHelper.BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}

{==============================================================================]
 <arr.BinaryRank>
 @action: Returns the insertion index (rank) of a value in the sorted array.
 @note: If the value exists, its first occurrence index is returned.
        If not found, returns the position where it should be inserted
        to maintain sort order.
        Works for ascending or descending arrays.
        Complexity: O(log n)
[==============================================================================}
function TIntegerArrayHelper.BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
 <arr.BinaryIndex>
 @action: Returns the index of a given value in the sorted array using binary search.
 @note: If the value is not found, returns -1.
        Works for both ascending and descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
 <arr.BinaryUpdate>
 @action: Updates the first occurrence of an element in the sorted array.
 @note: Searches for old_value using binary search. If found, replaces it with new_value.
        Returns True if updated, False if the value was not found.
        After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TIntegerArrayHelper.BinaryUpdate(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUpdate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpdate}

{==============================================================================]
 <arr.BinaryDelete>
 @action: Removes the first occurrence of a specific value from a sorted array.
 @note: Uses binary search to locate the target efficiently.
        Returns True if the value was found and deleted, otherwise False.
        Works for ascending or descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryDelete(const x: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryDelete}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDelete}

{==============================================================================]
 <arr.BinaryReplace>
 @action: Replaces a specific value in a sorted array with a new one.
 @note:   Uses binary search to locate and delete the old value,
          then reinserts the new one while maintaining sorted order.
          Returns True if the old value was found and replaced, otherwise False.
          Complexity: O(log n + n)
[==============================================================================}
function TIntegerArrayHelper.BinaryReplace(const oValue, nValue: Integer; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryReplace}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryReplace}

{==============================================================================]
 <arr.BinaryReplaceAll>
 @action: Replaces all occurrences of a specified value (oValue) with another
          value (nValue) in the array, preserving binary order if necessary.
 @note:   Returns the number of replacements performed. If any substitution
          breaks sorted order, the array is re-sorted automatically using
          BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryReplaceAll(const oValue, nValue: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryReplaceAll}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryReplaceAll}

{==============================================================================]
  <arr.BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function TIntegerArrayHelper.BinarySinglify(const item: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySinglify}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySinglify}

{==============================================================================]
  <arr.BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function TIntegerArrayHelper.BinarySinglified(const item: Integer; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinarySinglified}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySinglified}

{==============================================================================]
 <TIntegerArray.BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
 <TIntegerArray.BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
 <TIntegerArray.BinaryLocalize>
  @action: Determines the insertion position for a specified integer value within
           a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TIntegerArrayHelper.BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
 <TIntegerArray.BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryLookup(const value: Integer): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

{==============================================================================]
  <TIntegerArray.BinaryInterpolationSearch>
  @action: Performs an interpolation search on a sorted integer array to find the index of a given value.
  @note: This algorithm estimates the probable position of the target using linear interpolation
         between the low and high bounds, resulting in faster performance than binary search
         for uniformly distributed data. Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    case aAscending of
	  True:
      begin
        if ((x < Self[L]) or (x > Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((x - Self[L]) * (H - L)) div (Self[H] - Self[L]));
      end;
      False:
      begin
        if ((x > Self[L]) or (x < Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((Self[L] - x) * (H - L)) div (Self[L] - Self[H]));
      end;
    end;
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;


{==============================================================================]
  <TIntegerArray.BinaryProbabilisticSearch>
  @action: Performs a probabilistic variant of binary interpolation search, introducing a random bias
           to the estimated midpoint to improve robustness on non-uniform or noisy data.
  @note: The optional `bias` parameter (default = 0.0) adjusts how much random variation is applied
         to the interpolation estimate. A small bias can prevent worst-case patterns and clustering effects.
         Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    if (Self[L] = Self[H]) then
	  M := ((L + H) div 2)
    else
      if aAscending then
        M := (L + Trunc(EnsureRange((((x - Self[L]) / (Self[H] - Self[L])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)))
      else
        M := (L + Trunc(EnsureRange((((Self[L] - x) / (Self[L] - Self[H])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)));
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;


function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
begin
  Result := Self.BinaryProbabilisticSearch(x, bias, aAscending);
end;

{==============================================================================]
  <TIntegerArray.BinaryPinpoint>
  @action: Finds the index of the element closest in value to the specified integer.
  @note: - The array must be sorted in ascending or descending order as specified by aAscending.
         - Returns the index of the exact match if found, otherwise the index of the nearest element
           by absolute distance to x.
         - Runs in O(log n) time using BinaryRank to locate the insertion position and then compares
           adjacent elements to choose the closest one.
[==============================================================================}
function TIntegerArrayHelper.BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
var
  H, L, R, D: Integer;
begin
  H := High(Self);
  case H of
    -1: Exit(-1);
    0: Exit(0);
  end;
  Result := Self.BinaryRank(x, aAscending);
  if (Result > H) then
    Exit(H);
  if (Result < 0) then
    Exit(0);
  if (Self[Result] = x) then
    Exit;
  D := x.Distance(Self[Result]);
  if (Result = 0) then
     Exit(IfThen((D < x.Distance(Self[Result + 1])), Result, (Result + 1)));
  if (Result = H) then
    Exit(IfThen((D < x.Distance(Self[Result - 1])), Result, (Result - 1)));
  if (D > x.Distance(Self[Result - 1])) then
    Dec(Result)
  else
    if (D > x.Distance(Self[Result + 1])) then
      Inc(Result);
end;

{==============================================================================]
  <TIntegerArray.BinaryScan>
  @action: Performs a binary range scan on a sorted integer array to locate
           all indexes whose values lie within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses two binary searches to determine the first and last matching
           indexes that fall inside the range boundaries.
         - Returns an index list (TIntegerArray) identifying all matching
           elements.
         - Efficient O(log n + k) performance, where k is the number of
           matching elements.
[==============================================================================}
function TIntegerArrayHelper.BinaryScan(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  L, H, M, i: Integer;
  a, r: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  H := High(Self);
  L := 0;
  r.Create(-1);
  if (H > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[H]) or (a.start < Self[L])) then
    begin
      while (L <= H) do
      begin
        M := ((L + H) div 2);
        if (Self[M] >= a.start) then
        begin
          r.start := M;
          H := (M - 1);
        end else
          L := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      L := r.start;
      H := High(Self);
      while (L <= H) do
      begin
        M := ((L + H) div 2);
        if (Self[M] <= a.stop) then
        begin
          r.stop := M;
          L := (M + 1);
        end else
          H := (M - 1);
      end;
    end;
    False:
    if not ((a.stop > Self[L]) or (a.start < Self[H])) then
    begin
      r.Create(-1);
      while (L <= H) do
      begin
        M := ((L + H) div 2);
        if (Self[M] <= a.stop) then
        begin
          r.start := M;
          H := (M - 1);
        end else
          L := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      L := r.start;
      H := High(Self);
      while (L <= H) do
      begin
        M := ((L + H) div 2);
        if (Self[M] >= a.start) then
        begin
          r.stop := M;
          L := (M + 1);
        end else
          H := (M - 1);
      end;
    end;
  end;
  if not r.Employs(-1) then
  for i := r.start to r.stop do
    Result.Supply(i);
end;

{==============================================================================]
  <TIntegerArray.BinaryScanned>
  @action: Performs a binary range scan on a sorted integer array to locate
           all values lying within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses a single binary search to locate any element inside the range,
           then expands linearly in both directions to include all adjacent
           elements that also satisfy the range condition.
         - Returns a TIntegerArray containing the actual matching values
           (not indexes).
         - Offers O(log n + k) complexity and is well-suited for contiguous
           numeric segments.
[==============================================================================}
function TIntegerArrayHelper.BinaryScanned(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  L, H, M, i, S: Integer;
  a, r: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  H := High(Self);
  S := H;
  L := 0;
  r.Create(-1);
  if (H > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[H]) or (a.start < Self[L])) then
    while (L <= H) do
    begin
      M := ((L + H) div 2);
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] >= a.start)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] <= a.stop)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] > a.stop) then
          H := (M - 1)
        else
          L := (M + 1);
      end;
    end;
    False:
    if not ((a.stop > Self[L]) or (a.start < Self[H])) then
    while (L <= H) do
    begin
      M := ((L + H) div 2);
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] <= a.stop)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] >= a.start)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] < a.start) then
          H := (M - 1)
        else
          L := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <TIntegerArray.BMerge>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  i.Create(0, Length(items));
  s.Create(0, Length(Self));
  SetLength(Result, (i.stop + s.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <TIntegerArray.BMerged>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Length(Self));
  i.Create(0, Length(items));
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <TIntegerArray.CountingSort>
  @action: Sorts the integer array using the classical counting sort algorithm.
           Works efficiently when the range of integer values is relatively small.
  @note: 
    - This method handles negative and positive integers.
    - The algorithm counts the occurrences of each integer and writes them back
      in sorted order.
    - Always sorts in ascending order; descending order is not supported in this version.
    - Counting array size is based on the range of values in the array, so large
      ranges may use significant memory.
[==============================================================================}
function TIntegerArrayHelper.CountingSort(const aAscending: Boolean = True): Integer;
var
  c: TIntegerArray;
  i, j, s, o: Integer;
  m: TRange;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  o := -m.start;
  SetLength(c, m.Size);
  for i := 0 to High(Self) do
    Inc(c[Self[i] + o]);
  s := 0;
  for i := 0 to m.Span do
    for j := 1 to c[i] do
      Self[s.Increase] := (i - o);
  if not aAscending then
    Self.Reverse;
end;

{==============================================================================]
 <TIntegerArray.SegmentedCountingSort>
 @action: Performs a counting sort over the integer array using a small
          bucket-based approach. Supports ascending or descending order.
 @note:   Returns the number of elements in the array (Length(Self)).
          Sorting is done in-place using an auxiliary array.
          Efficient for moderate-sized integer ranges with many repeated values.
[==============================================================================}
function TIntegerArrayHelper.SegmentedCountingSort(const aAscending: Boolean = True; const bucketSize: Integer = 1024): Integer;
var
  i, j, l: Integer;
  c, s: TIntegerArray;
  m, r: TRange;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  SetLength(s, Length(Self));
  l := 0;
  if aAscending then
  begin
    r.start := m.start;
    while (r.start <= m.stop) do
    begin
      r.stop := Integer((r.start + bucketSize) - 1).ClampMax(m.stop);
      SetLength(c, ((r.stop - r.start) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.start) and (Self[i] <= r.stop) then
          Inc(c[Self[i] - r.start]);
      for i := 0 to High(c) do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.start + i);
      Inc(r.start, bucketSize);
    end;
  end
  else
  begin
    r.start := m.stop;
    while (r.start >= m.start) do
    begin
      r.stop := Integer((r.start - bucketSize) + 1).ClampMin(m.start);
      SetLength(c, ((r.start - r.stop) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.stop) and (Self[i] <= r.start) then
          Inc(c[Self[i] - r.stop]);
      for i := High(c) downto 0 do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.stop + i);
      Dec(r.start, bucketSize);
    end;
  end;
  for i := 0 to High(Self) do
    Self[i] := s[i];
end; 

{==============================================================================]
  <TIntegerArray.BinaryCountingSort>
  @action: Sorts the integer array using a hybrid approach that combines counting sort
           for densely clustered values with binary insertion for outliers.
           Automatically adapts to the data distribution based on the maxRange parameter.
  @note: 
    - If the range of array values is smaller than or equal to maxRange, a full counting
      sort is applied.
    - If the range exceeds maxRange, the method counts values within a central cluster
      (centered at the array’s midpoint) and uses binary insertion for values outside
      that cluster.
    - Supports ascending (default) or descending order.
    - Handles negative and positive integers.
    - The counting array size is bounded by maxRange + 1 to avoid excessive memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
var
  c, l: TIntegerArray;
  i, j, v, r, o: Integer;
  m: TRange;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  m := Self.Bounds(r);
  case (r <= maxRange) of
    True:
    begin
      SetLength(c, r);
      for i := 0 to High(Self) do
        Inc(c[Self[i] - m.start]);
      j := 0;
      case aAscending of
        True:
        for i := 0 to (r - 1) do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
        False:
        for i := r - 1 downto 0 do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
      end;
    end;
    False:
    begin
      o := m.Center;
      r := 200;
      SetLength(c, ((r * 2) + 1));
      SetLength(l, 0);
      for i := 0 to High(Self) do
        if InRange(Self[i], (o - r), (o + r)) then
          Inc(c[Self[i] - (o - r)])
        else
          l.BinaryAppend(Self[i]);
      j := 0;
      case aAscending of
        True:
        begin
          for i := 0 to High(c) do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := 0 to High(l) do
            Self[j.Increase] := l[i];
        end;
        False:
        begin
          for i := High(c) downto 0 do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := High(l) downto 0 do
            Self[j.Increase] := l[i];
        end;
      end;
    end;
  end;
end;

{$UNDEF Integer}
