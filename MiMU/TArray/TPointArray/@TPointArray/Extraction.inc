{$IFDEF HELPERS}
function AsX(const rAscending: Boolean = True): TIntegerArray; overload;
function AsXs: TIntegerArray; overload;
function AsY(const rAscending: Boolean = True): TIntegerArray; overload;
function AsYs: TIntegerArray; overload;
function Axed: T2DIntegerArray; overload;
function Axed(var X, Y: TIntegerArray): Integer; overload;
function Axes(var X, Y: TIntegerArray): Integer; overload;
function GetX: TIntegerArray; overload;
function GetY: TIntegerArray; overload;
function Project(var sX, sY: TIntegerArray): TBox; overload;
function ToXs: TIntegerArray; overload;
function ToYs: TIntegerArray; overload;
function Unzip(var xArr, yArr: TIntegerArray): Integer; overload;
function XArr(const aAscending: Boolean = True): TIntegerArray; overload;
function XArray(const rAscending: Boolean = True): TIntegerArray; overload;
function XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
function Xs: TIntegerArray; overload;
function Xs(const aBox: TBox): TIntegerArray; overload;
function XVals(const aAscending: Boolean = True): TIntegerArray; overload;
function XValues: TIntegerArray; overload;
function Xz(const rReversed: Boolean = False): TIntegerArray; overload;
function YArr(const aAscending: Boolean = True): TIntegerArray; overload;
function YArray(const rAscending: Boolean = True): TIntegerArray; overload;
function YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
function Ys: TIntegerArray; overload;
function Ys(const aBox: TBox): TIntegerArray; overload;
function YVals(const aAscending: Boolean = True): TIntegerArray; overload;
function YValues: TIntegerArray; overload;
function Yz(const rReversed: Boolean = False): TIntegerArray; overload;
function Xd(const aIndices: TIntegerArray): TIntegerArray; overload;
function Yd(const aIndices: TIntegerArray): TIntegerArray; overload;
function Xy(const atY: Integer): TIntegerArray; overload;
function Yx(const atX: Integer): TIntegerArray; overload;
function Zip(const xArr, yArr: TIntegerArray): Integer; overload;
function Zip(const sAxes: T2DIntegerArray): Integer; overload;

function Xrev: TIntegerArray; overload;
function Yrev: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsX>
  @action: Extract all unique X coordinates from the point array, sort them according to the specified direction, and return them as an integer array.
  @note: 
  - Uses direct pointer arithmetic for high-performance coordinate extraction and in-place compaction.
  - Supports sorting in ascending (default) or descending order via rAscending.
  - Automatically removes duplicate values.
[==============================================================================}
function TPointArrayHelper.AsX(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, n, l: Integer;
  s: PPoint;
  r, c: PInteger;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  SetLength(Result, n);
  s := @Self[0];
  r := @Result[0];
  for i := 0 to (n - 1) do
  begin
    r^ := s^.X;
    Inc(s);
    Inc(r);
  end;
  if (n = 1) then
    Exit;
  Result.QuickSort(rAscending);
  r := @Result[0];
  c := r;
  l := 1;
  for i := 1 to (n - 1) do
  begin
    Inc(c);
    if (c^ <> r^) then
    begin
      Inc(r);
      r^ := c^;
      Inc(l);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <AsY>
  @action: Extract all unique Y coordinates from the point array, sort them according to the specified direction, and return them as an integer array.
  @note: 
  - Uses direct pointer arithmetic for high-performance coordinate extraction and in-place compaction.
  - Supports sorting in ascending (default) or descending order via rAscending.
  - Automatically removes duplicate values.
[==============================================================================}
function TPointArrayHelper.AsY(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, n, l: Integer;
  s: PPoint;
  r, c: PInteger;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  SetLength(Result, n);
  s := @Self[0];
  r := @Result[0];
  for i := 0 to (n - 1) do
  begin
    r^ := s^.Y;
    Inc(s);
    Inc(r);
  end;
  if (n = 1) then
    Exit;
  Result.QuickSort(rAscending);
  r := @Result[0];
  c := r;
  l := 1;
  for i := 1 to (n - 1) do
  begin
    Inc(c);
    if (c^ <> r^) then
    begin
      Inc(r);
      r^ := c^;
      Inc(l);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <AsXs>
  @action: Extract all unique X coordinates from a point array, maintaining them in sorted order.
  @note: 
  - Uses binary search to insert each X coordinate into a sorted tracking array in O(log N) time per element.
  - Skips duplicate X coordinates to ensure uniqueness.
  - Returns an ordered integer array of unique X values.
[==============================================================================}
function TPointArrayHelper.AsXs: TIntegerArray; overload;
var
  s: TIntegerArray;
  z, i, r, n, l, h, m: Integer;
begin
  z := Self.Length;
  if (z = 0) then
    Exit([]);
  SetLength(s, (z + 1));
  n := 0;
  r := 0;
  for i := 0 to Result.Alloc(z) do
  begin
    l := 0;
    h := n;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if (s[m] < Self[i].X) then
        l := (m + 1)
      else
        h := m;
    end;
    if ((l < n) and (s[l] = Self[i].X)) then
      Continue;
    Move(s[l], s[l + 1], ((n - l) * SizeOf(Integer)));
    s[l] := Self[i].X;
    Inc(n);
    Result[r.Increase] := Self[i].X;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <AsYs>
  @action: Extract all unique Y coordinates from a point array, maintaining them in sorted order.
  @note: 
  - Uses binary search to insert each Y coordinate into a sorted tracking array in O(log N) time per element.
  - Skips duplicate Y coordinates to ensure uniqueness.
  - Returns an ordered integer array of unique Y values.
[==============================================================================}
function TPointArrayHelper.AsYs: TIntegerArray; overload;
var
  s: TIntegerArray;
  z, i, r, n, l, h, m: Integer;
begin
  z := Self.Length;
  if (z = 0) then
    Exit([]);
  SetLength(s, (z + 1));
  n := 0;
  r := 0;
  for i := 0 to Result.Alloc(z) do
  begin
    l := 0;
    h := n;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if (s[m] < Self[i].Y) then
        l := (m + 1)
      else
        h := m;
    end;
    if ((l < n) and (s[l] = Self[i].Y)) then
      Continue;
    Move(s[l], s[l + 1], ((n - l) * SizeOf(Integer)));
    s[l] := Self[i].Y;
    Inc(n);
    Result[r.Increase] := Self[i].Y;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed: T2DIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 2, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[0][i] := Self[i].X;
    Result[1][i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed(var X, Y: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  for i := 0 to High(Self) do
  begin
    X[i] := Self[i].X;
    Y[i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Axes>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axes(var X, Y: TIntegerArray): Integer; overload;
var
  sX, sY, dX, dY: Pointer;
  p, c: SizeInt;
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  if (Result = 0) then
    Exit;
  c := SizeOf(Integer);
  p := SizeOf(TPoint);
  sX := @Self[0].X;
  sY := Pointer(PByte(sX) + c);
  dX := @X[0];
  dY := @Y[0];
  for i := 0 to High(Self) do
  begin
    Move(sX^, dX^, c);
    Move(sY^, dY^, c);
    Inc(PByte(sX), p);
    Inc(PByte(sY), p);
    Inc(PByte(dX), c);
    Inc(PByte(dY), c);
  end;
end;

{==============================================================================]
  <GetX>
  @action: Returns the unique X values in order of first appearance.
  @note: Counting-array flags over the X range: O(n + rangeX) time and memory.
         PascalScript-compatible. Prefer XAxis when sorted output is fine.
[==============================================================================}
function TPointArrayHelper.GetX: TIntegerArray; overload;
var
  i, r: Integer;
  x, y: TRange;
  s: TBooleanArray;
begin
  if (Self.Length = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(s, (x.stop - x.start + 1));
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if not s[Self[i].X - x.start] then
    begin
      s[Self[i].X - x.start] := True;
      Result[r.Increase] := Self[i].X;
    end;
  SetLength(Result, r);
end;

{==============================================================================]
  <GetY>
  @action: Returns the unique Y values in order of first appearance.
  @note: Counting-array flags over the Y range: O(n + rangeY) time and memory.
         PascalScript-compatible. Prefer YAxis when sorted output is fine.
[==============================================================================}
function TPointArrayHelper.GetY: TIntegerArray; overload;
var
  i, r: Integer;
  x, y: TRange;
  s: TBooleanArray;
begin
  if (Self.Length = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(s, (y.stop - y.start + 1));
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if not s[Self[i].Y - y.start] then
    begin
      s[Self[i].Y - y.start] := True;
      Result[r.Increase] := Self[i].Y;
    end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Project>
  @action: Projects the point array into separate X and Y coordinate arrays
           while computing and returning the axis-aligned bounding box.
  @note: The output arrays are resized to match Self.Length.
         Returns an empty/uninitialized TBox if the array is empty.
[==============================================================================}
function TPointArrayHelper.Project(var sX, sY: TIntegerArray): TBox; overload;
var
  i: Integer;
begin
  if (sY.SetSize(sX.SetSize(Self.Length)) = 0) then
    Exit;
  Result.Create(Self[0].X, Self[0].Y, Self[0].X, Self[0].Y);
  for i := 0 to High(Self) do
  begin
    sX[i] := Self[i].X;
    if (sX[i] < Result.X1) then
      Result.X1 := sX[i]
    else if (sX[i] > Result.X2) then
      Result.X2 := sX[i];
    sY[i] := Self[i].Y;
    if (sY[i] < Result.Y1) then
      Result.Y1 := sY[i]
    else if (sY[i] > Result.Y2) then
      Result.Y2 := sY[i];
  end;
end;

{==============================================================================]
  <ToXs>
  @action: Returns the unique X values in order of first appearance.
  @note: Dictionary-based, O(n) expected time, memory proportional to the number
         of distinct values. Use for huge sparse ranges.
[==============================================================================}
function TPointArrayHelper.ToXs: TIntegerArray; overload;
var
  i, r: Integer;
  d: specialize TDictionary<Integer, Boolean>;
begin
  r := 0;
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to Result.Alloc(Self.Length) do
      if not d.ContainsKey(Self[i].X) then
      begin
        d.Add(Self[i].X, True);
        Result[r.Increase] := Self[i].X;
      end;
  finally
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <ToXs>
  @action: Returns the unique Y values in order of first appearance.
  @note: Dictionary-based, O(n) expected time, memory proportional to the number
         of distinct values. Use for huge sparse ranges.
[==============================================================================}
function TPointArrayHelper.ToYs: TIntegerArray; overload;
var
  i, r: Integer;
  d: specialize TDictionary<Integer, Boolean>;
begin
  r := 0;
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to Result.Alloc(Self.Length) do
      if not d.ContainsKey(Self[i].Y) then
      begin
        d.Add(Self[i].Y, True);
        Result[r.Increase] := Self[i].Y;
      end;
  finally
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Unzip>
  @action: Stores arr X and Y values to xArr and yArr.
  @note: Returns Length(arr).
[==============================================================================}
function TPointArrayHelper.Unzip(var xArr, yArr: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := yArr.SetSize(xArr.SetSize(Self.Size));
  for i := 0 to (Result - 1) do
  begin
    xArr[i] := Self[i].X;
    yArr[i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <XArr>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XArr(const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self.Xs.QuickSorted(aAscending);
end;

{==============================================================================]
  <XArray>
  @action: Extracts a sorted array of all unique X-coordinates from the point array.
  @note: Returns an empty array if the point array is empty. The rAscending 
         parameter determines whether the resulting coordinates are ordered in 
         ascending (True, default) or descending (False) order.
[==============================================================================}
function TPointArrayHelper.XArray(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  m: TBooleanArray;
  r: TRange;
begin
  if (Self.Length = 0) then
    Exit([]);
  r := Self.XRange;
  SetLength(m, r.Size);
  l := 0;
  for i := 0 to High(Self) do
    if m[Self[i].X - r.start].TurnTrue then
      Inc(l);
  SetLength(Result, l);
  l := 0;
  case rAscending of
    True:
    for i := 0 to High(m) do
      if m[i] then
        Result[l.Increase] := (i + r.start);
    False:
    for i := High(m) downto 0 do
      if m[i] then
        Result[l.Increase] := (i + r.start);
  end;
end;

{==============================================================================]
  <XAxis>
  @action: Extracts all X-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique X values (duplicates removed).
         When rUnique = False, all X values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  Result.Clear;
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].X);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].X);
  end;
end;

{==============================================================================]
  <Xs>
  @action: Extracts the X-coordinates of all points in the array and returns
           them as a TIntegerArray. The order of values in the result matches
           the order of the points in the source array.
  @note: This is a direct projection operation; no filtering, sorting, or
         transformation is applied. The returned array always has the same
         length as the source.
[==============================================================================}
function TPointArrayHelper.Xs: TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Size) do
    Result[i] := Self[i].X;
end;

{==============================================================================]
  <Xs>
  @action: Extracts the X-coordinates of all points that lie inside aBox.
  @note: Bounds are inclusive. Result follows the order of appearance.
[==============================================================================}
function TPointArrayHelper.Xs(const aBox: TBox): TIntegerArray; overload;
var
  i, c: Integer;
begin
  c := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if ((Self[i].X >= aBox.X1) and (Self[i].X <= aBox.X2) and (Self[i].Y >= aBox.Y1) and (Self[i].Y <= aBox.Y2)) then
      Result[c.Increase] := Self[i].X;
  SetLength(Result, c);
end;

{==============================================================================]
  <XVals>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XVals(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  Result.Clear;
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].X, aAscending);
end;

{==============================================================================]
  <XValues>
  @action: Returns X-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.XValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Result.SetSize(Self.Length);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X;
end;

{==============================================================================]
  <Xz>
  @action: Extracts and compresses unique X coordinates from a point array into an integer array.
  @note: Traverses the point array (forward or in reverse based on rReversed),
         filtering out consecutive duplicate X values. Uses memory allocation and helper methods like Alloc and Increment,
		 then trims the final array length.
[==============================================================================}
function TPointArrayHelper.Xz(const rReversed: Boolean = False): TIntegerArray; overload;
var
  i, h, r: Integer;
begin
  h := Result.Alloc(Self.Length);
  if (h = -1) then
    Exit;
  Result[0] := Self[IfThen(rReversed, h, 0)].X;
  if (h = 0) then
    Exit;
  r := 0;
  case rReversed of
    False:
    for i := 1 to h do
      if (Self[i].X <> Result[r]) then
        Result[r.Increment] := Self[i].X;
    True:
    for i := (h - 1) downto 0 do
      if (Self[i].X <> Result[r]) then
        Result[r.Increment] := Self[i].X;
  end;
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <YArr>
  @action: Returns an array of all Y coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YArr(const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self.Ys.QuickSorted(aAscending);
end;

{==============================================================================]
  <YArray>
  @action: Extracts a sorted array of all unique Y-coordinates from the point array.
  @note: Returns an empty array if the point array is empty. The rAscending 
         parameter determines whether the resulting coordinates are ordered in 
         ascending (True, default) or descending (False) order.
[==============================================================================}
function TPointArrayHelper.YArray(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  m: TBooleanArray;
  r: TRange;
begin
  if (Self.Length = 0) then
    Exit([]);
  r := Self.YRange;
  SetLength(m, r.Size);
  l := 0;
  for i := 0 to High(Self) do
    if m[Self[i].Y - r.start].TurnTrue then
      Inc(l);
  SetLength(Result, l);
  l := 0;
  case rAscending of
    True:
    for i := 0 to High(m) do
      if m[i] then
        Result[l.Increase] := (i + r.start);
    False:
    for i := High(m) downto 0 do
      if m[i] then
        Result[l.Increase] := (i + r.start);
  end;
end;

{==============================================================================]
  <YAxis>
  @action: Extracts all Y-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique Y values (duplicates removed).
         When rUnique = False, all Y values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  Result.Clear;
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].Y);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].Y);
  end;
end;

{==============================================================================]
  <Ys>
  @action: Extracts the Y-coordinates of all points in the array and returns
           them as a TIntegerArray, preserving the original element order.
  @note: Performs a simple coordinate projection without any modification or
         reordering. The returned array has the same length as the input.
[==============================================================================}
function TPointArrayHelper.Ys: TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Size) do
    Result[i] := Self[i].Y;
end;

{==============================================================================]
  <Ys>
  @action: Extracts the Y-coordinates of all points that lie inside aBox.
  @note: Bounds are inclusive. Result follows the order of appearance.
[==============================================================================}
function TPointArrayHelper.Ys(const aBox: TBox): TIntegerArray; overload;
var
  i, c: Integer;
begin
  c := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if ((Self[i].X >= aBox.X1) and (Self[i].X <= aBox.X2) and (Self[i].Y >= aBox.Y1) and (Self[i].Y <= aBox.Y2)) then
      Result[c.Increase] := Self[i].Y;
  SetLength(Result, c);
end;

{==============================================================================]
  <YVals>
  @action: Returns an array of all Y coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YVals(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  Result.Clear;
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].Y, aAscending);
end;

{==============================================================================]
  <YValues>
  @action: Returns Y-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.YValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Result.SetSize(Self.Length);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y;
end;

{==============================================================================]
  <Yz>
  @action: Extracts and compresses unique Y coordinates from a point array into an integer array.
  @note: Traverses the point array (forward or in reverse based on rReversed), filtering out consecutive duplicate Y values.
         Uses memory allocation and helper methods like Alloc and Increment, then trims the final array length.
[==============================================================================}
function TPointArrayHelper.Yz(const rReversed: Boolean = False): TIntegerArray; overload;
var
  i, h, r: Integer;
begin
  h := Result.Alloc(Self.Length);
  if (h = -1) then
    Exit;
  Result[0] := Self[IfThen(rReversed, h, 0)].Y;
  if (h = 0) then
    Exit;
  r := 0;
  case rReversed of
    False:
    for i := 1 to h do
      if (Self[i].Y <> Result[r]) then
        Result[r.Increment] := Self[i].Y;
    True:
    for i := (h - 1) downto 0 do
      if (Self[i].Y <> Result[r]) then
        Result[r.Increment] := Self[i].Y;
  end;
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Xd>
  @action: Extracts the X-coordinates of the points at the given indices.
  @note: Result follows the order of aIndices. Out-of-range indices are skipped.
[==============================================================================}
function TPointArrayHelper.Xd(const aIndices: TIntegerArray): TIntegerArray; overload;
var
  i, r, h: Integer;
begin
  h := High(Self);
  r := 0;
  for i := 0 to Result.Alloc(aIndices.Length) do
    if ((aIndices[i] >= 0) and (aIndices[i] <= h)) then
      Result[r.Increase] := Self[aIndices[i]].X;
  SetLength(Result, r);
end;

{==============================================================================]
  <Yd>
  @action: Extracts the Y-coordinates of the points at the given indices.
  @note: Result follows the order of aIndices. Out-of-range indices are skipped.
[==============================================================================}
function TPointArrayHelper.Yd(const aIndices: TIntegerArray): TIntegerArray; overload;
var
  i, r, h: Integer;
begin
  h := High(Self);
  r := 0;
  for i := 0 to Result.Alloc(aIndices.Length) do
    if ((aIndices[i] >= 0) and (aIndices[i] <= h)) then
      Result[r.Increase] := Self[aIndices[i]].Y;
  SetLength(Result, r);
end;

{==============================================================================]
  <Xy>
  @action: Extracts all X coordinates from points that match a specified Y coordinate.
  @note: Pre-allocates memory for the result array based on the total point count,
         filters points where the Y coordinate equals atY, and trims the final array to the matched count.
[==============================================================================}
function TPointArrayHelper.Xy(const atY: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i].Y = atY) then
      Result[r.Increase] := Self[i].X;
  SetLength(Result, r);
end;

{==============================================================================]
  <Yx>
  @action: Extracts all Y coordinates from points that match a specified X coordinate.
  @note: Pre-allocates memory for the result array based on the total point count,
         filters points where the X coordinate equals atX, and trims the final array to the matched count.
[==============================================================================}
function TPointArrayHelper.Yx(const atX: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i].X = atX) then
      Result[r.Increase] := Self[i].Y;
  SetLength(Result, r);
end;

{==============================================================================]
  <Zip>
  @action: Zips TPointArray with xArr and yArr.
  @note: Uses minimum length(!), if xArr differs from yArr size.
[==============================================================================}
function TPointArrayHelper.Zip(const xArr, yArr: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.SetSize(Min(xArr.Size, yArr.Size));
  for i := 0 to (Result - 1) do
    Self[i] := Point(xArr[i], yArr[i]);
end;

{==============================================================================]
  <Zip>
  @action: Zips TPointArray with the X and Y arrays of a 2D integer array.
  @note: Expects axes[0] to hold X-values and axes[1] Y-values (as produced by
         Axed). Returns Self.Length; Self is emptied if axes has fewer than
         two rows.
[==============================================================================}
function TPointArrayHelper.Zip(const sAxes: T2DIntegerArray): Integer; overload;
begin
  if (sAxes.Length < 2) then
  begin
    SetLength(Self, 0);
    Exit(0);
  end;
  Result := Self.Zip(sAxes[0], sAxes[1]);
end;

{==============================================================================]
  <Xrev>
  @action: Extracts the X-coordinates of the point array in reverse order.
  @note: Result[0] is the X of the last point.
[==============================================================================}
function TPointArrayHelper.Xrev: TIntegerArray; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Self[h - i].X;
end;

{==============================================================================]
  <Yrev>
  @action: Extracts the Y-coordinates of the point array in reverse order.
  @note: Result[0] is the Y of the last point.
[==============================================================================}
function TPointArrayHelper.Yrev: TIntegerArray; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Self[h - i].Y;
end;
{$ENDIF}
