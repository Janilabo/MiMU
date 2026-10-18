{$IFDEF HELPERS}
function XwithY(const valueY: Integer): TIntegerArray; overload;
function Xy(const atY: Integer): TIntegerArray; overload;
function Xy2(const atY: Integer): TIntegerArray; overload;
function Xyed(const atY: Integer): TIntegerArray; overload;
function Xys(const atY: Integer): TIntegerArray; overload;

function YwithX(const valueX: Integer): TIntegerArray; overload;
function Yx(const atX: Integer): TIntegerArray; overload;
function Yx2(const atX: Integer): TIntegerArray; overload;
function Yxed(const atX: Integer): TIntegerArray; overload;
function Yxs(const atX: Integer): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <XwithY>
  @action: Extracts all X coordinates from points that match a specified Y coordinate.
  @note: Branchless single pass. Every X is written at the current write index, and the
         index advances only when Y matches (via Increase with a 0/1 step), so a
         non-match is simply overwritten by the next write. The write index never
         exceeds the read index, so the Self.Length allocation is always safe. Output
         is in original array order. Returns an empty array if Self is empty or no
         point matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.XwithY(const valueY: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    Result[r.Increase(Ord(Self[i].Y = valueY))] := Self[i].X;
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
  <Xy2>
  @action: Extracts all X coordinates from points that match a specified Y coordinate.
  @note: Composed from Yvalued: first collects the indices of every point on row atY,
         then maps each index to its X. Two passes with an intermediate index array,
         but the result is allocated at its exact size. Output is in original array
         order, identical to Xy. Returns an empty array if Self is empty or no point
         matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.Xy2(const atY: Integer): TIntegerArray; overload;
var
  i: Integer;
  x: TIntegerArray;
begin
  x := Self.Yvalued(atY);
  for i := 0 to Result.Alloc(x.Length) do
    Result[i] := Self[x[i]].X;
end;

{==============================================================================]
  <Xyed>
  @action: Extracts all X coordinates from points that match a specified Y coordinate,
           returned in ascending order.
  @note: Works on a sorted copy (QuickSortByYX), so Self is left untouched. After
         sorting, the matching points form one contiguous block, located with a lower
         and upper bound binary search, and their X values are copied out. Returns an
         empty array if Self is empty or no point matches atY. Exact duplicate points
         are kept. Cost is O(n log n) per call because of the sort.
[==============================================================================}
function TPointArrayHelper.Xyed(const atY: Integer): TIntegerArray; overload;
var
  s, l, h, m, f, i: Integer;
  p: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  p := Self.Copy;
  p.QuickSortByYX;
  l := 0;
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (p[m].Y < atY) then
      l := (m + 1)
    else
      h := m;
  end;
  f := l;
  if (f >= s) or (p[f].Y <> atY) then
    Exit([]);
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (p[m].Y <= atY) then
      l := (m + 1)
    else
      h := m;
  end;
  SetLength(Result, (l - f));
  for i := f to (l - 1) do
    Result[i - f] := p[i].X;
end;

{==============================================================================]
  <Xys>
  @action: Extracts all X coordinates from points that match a specified Y coordinate,
           returned in ascending order.
  @note: Works on a sorted copy (QuickSortByYX), so Self is left untouched. Scans the
         sorted copy linearly, collects the X values of the contiguous Y block, and
         stops at the first Y greater than atY. Returns an empty array if Self is
         empty or no point matches atY. Exact duplicate points are kept. Cost is
         dominated by the O(n log n) sort.
[==============================================================================}
function TPointArrayHelper.Xys(const atY: Integer): TIntegerArray; overload;
var
  i, r: Integer;
  p: TPointArray;
begin
  p := Self.Copy;
  p.QuickSortByYX;
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (p[i].Y > atY) then
      Break
    else if (p[i].Y = atY) then
      Result[r.Increase] := p[i].X;
  SetLength(Result, r);
end;

{==============================================================================]
  <YwithX>
  @action: Extracts all Y coordinates from points that match a specified X coordinate.
  @note: Branchless single pass. Every Y is written at the current write index, and the
         index advances only when X matches (via Increase with a 0/1 step), so a
         non-match is simply overwritten by the next write. The write index never
         exceeds the read index, so the Self.Length allocation is always safe. Output
         is in original array order. Returns an empty array if Self is empty or no
         point matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.YwithX(const valueX: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    Result[r.Increase(Ord(Self[i].X = valueX))] := Self[i].Y;
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
  <Yx2>
  @action: Extracts all Y coordinates from points that match a specified X coordinate.
  @note: Composed from Xvalued: first collects the indices of every point on column
         atX, then maps each index to its Y. Two passes with an intermediate index
         array, but the result is allocated at its exact size. Output is in original
         array order, identical to Yx. Returns an empty array if Self is empty or no
         point matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.Yx2(const atX: Integer): TIntegerArray; overload;
var
  i: Integer;
  y: TIntegerArray;
begin
  y := Self.Xvalued(atX);
  for i := 0 to Result.Alloc(y.Length) do
    Result[i] := Self[y[i]].Y;
end;

{==============================================================================]
  <Yxed>
  @action: Extracts all Y coordinates from points that match a specified X coordinate,
           returned in ascending order.
  @note: Works on a sorted copy (QuickSortByXY), so Self is left untouched. After
         sorting, the matching points form one contiguous block, located with a lower
         and upper bound binary search, and their Y values are copied out. Returns an
         empty array if Self is empty or no point matches atX. Exact duplicate points
         are kept. Cost is O(n log n) per call because of the sort.
[==============================================================================}
function TPointArrayHelper.Yxed(const atX: Integer): TIntegerArray; overload;
var
  s, l, h, m, f, i: Integer;
  p: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  p := Self.Copy;
  p.QuickSortByXY;
  l := 0;
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (p[m].X < atX) then
      l := (m + 1)
    else
      h := m;
  end;
  f := l;
  if ((f >= s) or (p[f].X <> atX)) then
    Exit([]);
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (p[m].X <= atX) then
      l := (m + 1)
    else
      h := m;
  end;
  SetLength(Result, (l - f));
  for i := f to (l - 1) do
    Result[i - f] := p[i].Y;
end;

{==============================================================================]
  <Yxs>
  @action: Extracts all Y coordinates from points that match a specified X coordinate,
           returned in ascending order.
  @note: Works on a sorted copy (QuickSortByXY), so Self is left untouched. Scans the
         sorted copy linearly, collects the Y values of the contiguous X block, and
         stops at the first X greater than atX. Returns an empty array if Self is
         empty or no point matches atX. Exact duplicate points are kept. Cost is
         dominated by the O(n log n) sort.
[==============================================================================}
function TPointArrayHelper.Yxs(const atX: Integer): TIntegerArray; overload;
var
  i, r: Integer;
  p: TPointArray;
begin
  p := Self.Copy;
  p.QuickSortByXY;
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (p[i].X > atX) then
      Break
    else if (p[i].X = atX) then
      Result[r.Increase] := p[i].Y;
  SetLength(Result, r);
end;
{$ENDIF}
