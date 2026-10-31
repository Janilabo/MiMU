{$IFDEF HELPERS}
function BBox: TBox; overload;
function Bordure: TBox; overload;
function Boundaries: TBox;
function BoundingBox: TBox;
function Bounds: TBox; overload;
function Bounds(var width, height: Integer): TBox; overload;
function Bourne: TBox; overload;
function Box: TBox;
function Boxed: TBox;
function Coverage: TBox; overload;
function Extent: TBox;
function MinMax: TBox;
function Region: TBox; overload;

function Survey(var xWise, yWise: TRange): Integer; overload;

function Horizontal: TRange; overload;
function Vertical: TRange; overload;
function XBoundaries: TRange; overload;
function YBoundaries: TRange; overload;
function XBounds: TRange; overload;
function YBounds: TRange; overload;
function XRange: TRange; overload;
function YRange: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BBox>
  @action: Computes the minimal bounding box (TBox) that encloses all points
           in the TPointArray. It calculates the minimum and maximum X and Y
           coordinates among the points to define the box.
  @note:   - If the array is empty, the resulting TBox will be uninitialized.
           - If the array has only one point, the bounding box will be a
             degenerate box where X1=X2 and Y1=Y2.
           - Uses pointer-based iteration for efficiency.
[==============================================================================}
function TPointArrayHelper.BBox: TBox; overload;
var
  P, M: PPoint;
  L: Integer;
begin
  L := Self.Length;
  if (L > 0) then
  with Result do
  begin
    P := @Self[0];
    X1 := P^.X;
    Y1 := P^.Y;
    X2 := P^.X;
    Y2 := P^.Y;
    if (L = 1) then
      Exit;
    M := @Self[0];
    Inc(M, L);
    repeat
      if (X1 > P^.X) then
        X1 := P^.X
      else if (X2 < P^.X) then
        X2 := P^.X;
      if (Y1 > P^.Y) then
        Y1 := P^.Y
      else if (Y2 < P^.Y) then
        Y2 := P^.Y;
      Inc(P);
    until (P = M);
  end;
end;

{==============================================================================]
  <Bordure>
  @action: Calculates and returns the bounding box (TBox) that encompasses all points in the point array (TPointArray)
           using a pairwise unrolled loop.
  @note: Handles empty arrays (returning an uninitialized/default TBox) and single-point arrays specially.
         For larger arrays, it processes elements in pairs to compare and update minimum and maximum boundaries efficiently,
		 handling any remaining odd element at the end.
[==============================================================================}
function TPointArrayHelper.Bordure: TBox; overload;
var
  s, i: Integer;
  h, v: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(TBox.Construct(High(Integer), High(Integer), Low(Integer), Low(Integer)));
  if (s = 1) then
    Exit(TBox.Construct(Self[0].X, Self[0].Y, Self[0].X, Self[0].Y));
  if (Self[0].X < Self[1].X) then
  begin
    Result.X1 := Self[0].X;
    Result.X2 := Self[1].X;
  end else
  begin
    Result.X1 := Self[1].X;
    Result.X2 := Self[0].X;
  end;
  if (Self[0].Y < Self[1].Y) then
  begin
    Result.Y1 := Self[0].Y;
    Result.Y2 := Self[1].Y;
  end else
  begin
    Result.Y1 := Self[1].Y;
    Result.Y2 := Self[0].Y;
  end;
  i := 2;
  while ((i + 1) < s) do
  begin
    if (Self[i].X < Self[i + 1].X) then
    begin
      h.start := Self[i].X;
      h.stop := Self[i + 1].X;
    end else
    begin
      h.start := Self[i + 1].X;
      h.stop := Self[i].X;
    end;
    if (Self[i].Y < Self[i + 1].Y) then
    begin
      v.start := Self[i].Y;
      v.stop := Self[i + 1].Y;
    end else
    begin
      v.start := Self[i + 1].Y;
      v.stop := Self[i].Y;
    end;
    if (h.start < Result.X1) then
      Result.X1 := h.start;
    if (h.stop > Result.X2) then
      Result.X2 := h.stop;
    if (v.start < Result.Y1) then
      Result.Y1 := v.start;
    if (v.stop > Result.Y2) then
      Result.Y2 := v.stop;
    Inc(i, 2);
  end;
  if (i < s) then
  begin
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X
    else if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y
    else if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
  end;
end;

{==============================================================================]
  <Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boundaries: TBox;
  function BR(const arr: TPointArray; const L, R: Integer): TBox;
  var
    M: Integer;
  begin
    if (L = R) then
      Exit(Result.Create(arr[L].X, arr[L].Y, arr[L].X, arr[L].Y));
    M := ((L + R) div 2);
    Result := BR(arr, L, M).Union(BR(arr, (M + 1), R));
  end;
begin
  if Self.Empty then
    Exit(Default(TBox));
  Result := BR(Self, 0, High(Self));
end;

{==============================================================================]
  <BoundingBox>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.BoundingBox: TBox;
var
  i: Integer;
  a, b: TIntegerArray;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  for i := 0 to a.Alloc(b.SetSize(Self.Size)) do
  begin
    a[i] := Self[i].X;
    b[i] := Self[i].Y;
  end;
  Result.Create(MinValue(a), MinValue(b), MaxValue(a), MaxValue(b));
end;

{==============================================================================]
  <Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Bounds: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Make(Self[0]);
  for i := 1 to High(Self) do
  begin
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X
    else if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y
    else if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
  end;
end;

{==============================================================================]
  <Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: Stores width and height of bounds to width and height variables.
[==============================================================================}
function TPointArrayHelper.Bounds(var width, height: Integer): TBox; overload;
begin
  case Self.Empty of
    False:
    begin
      Result := Self.Bounds;
      Result.Size(width, height);
    end;
    True:
    begin
      Result.Create(-2147483648);
      width := 0;
      height := 0;
    end;
  end;
end;

{==============================================================================]
  <Bourne>
  @action: Calculates and returns the bounding box (TBox) that encompasses all points within the point array (TPointArray).
  @note: Returns an empty/inverted bounding box if the array is empty. Iterates through all points,
         updating the minimum and maximum X and Y coordinates using the branchless Minor and Major helper functions.
[==============================================================================}
function TPointArrayHelper.Bourne: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(TBox.Construct(High(Integer), High(Integer), Low(Integer), Low(Integer)));
  Result.Build(Self[0]);
  for i := 1 to High(Self) do
  begin
    Result.X1 := Minor(Result.X1, Self[i].X);
    Result.Y1 := Minor(Result.Y1, Self[i].Y);
    Result.X2 := Major(Result.X2, Self[i].X);
    Result.Y2 := Major(Result.Y2, Self[i].Y);
  end;
end;

{==============================================================================]
  <Box>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Box: TBox;
var
  P: TPoint;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for P in Self do
    Result.Create(Min(Result.X1, p.X), Min(Result.Y1, p.Y), Max(Result.X2, p.X), Max(Result.Y2, p.Y));
end;

{==============================================================================]
  <Boxed>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boxed: TBox;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for i := 1 to High(Self) do
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X;
  for i := 1 to High(Self) do
    if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
  for i := 1 to High(Self) do
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y;
  for i := 1 to High(Self) do
    if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
end;

{==============================================================================]
  <Coverage>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Coverage: TBox; overload;
var
  i: Integer;
  a, b: TPoint;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  a := Point(High(Integer), High(Integer));
  b := Point(Low(Integer), Low(Integer));
  for i := 0 to High(Self) do
  begin
    if (Self[i].X < a.X) then
      a.X := Self[i].X
    else if (Self[i].X > b.X) then
      b.X := Self[i].X;
    if (Self[i].Y < a.Y) then
      a.Y := Self[i].Y
    else if (Self[i].Y > b.Y) then
      b.Y := Self[i].Y;
  end;
  Result.Create(a.X, a.Y, b.X, b.Y);
end;

{==============================================================================]
  <Extent>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Extent: TBox;
var
  h, v: TIntegerArray;
  z: Integer;
begin
  z := (Self.Unzip(h, v) - 1);
  if (z > -1) then
  begin
    h.QuickSort;
    v.QuickSort;
    Result.Create(h[0], v[0], h[z], v[z]);
  end;
end;

{==============================================================================]
  <MinMax>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.MinMax: TBox;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for i := 0 to High(Self) do
  begin
    Result.X1 := Min(Self[i].X, Result.X1);
    Result.Y1 := Min(Self[i].Y, Result.Y1);
    Result.X2 := Max(Self[i].X, Result.X2);
    Result.Y2 := Max(Self[i].Y, Result.Y2);
  end;
end;

{==============================================================================]
  <Region>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Region: TBox; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(Result.Create(-2147483648));
  Result.Create(MaxInt, MaxInt, -MaxInt, -MaxInt);
  for i := 0 to (l - 1) do
  begin
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y;
    if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
    if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
  end;
end;

{==============================================================================]
  <Survey>
  @action: Measures the axis-wise extents of the point array in a single pass.
  @note: Non-mutating; Self is left untouched.
   - xWise = [minX .. maxX], yWise = [minY .. maxY], both ascending
     (start <= stop).
   - Returns Self.Length (the number of points surveyed).
   - Empty Self returns 0 and leaves xWise/yWise untouched.
   - A single point yields degenerate ranges (start = stop on both axes).
[==============================================================================}
function TPointArrayHelper.Survey(var xWise, yWise: TRange): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  xWise.Create(Self[0].X);
  yWise.Create(Self[0].Y);
  for i := 1 to (Result - 1) do
  begin
    if (Self[i].X < xWise.start) then
      xWise.start := Self[i].X
    else if (Self[i].X > xWise.stop) then
      xWise.stop := Self[i].X;
    if (Self[i].Y < yWise.start) then
      yWise.start := Self[i].Y
    else if (Self[i].Y > yWise.stop) then
      yWise.stop := Self[i].Y;
  end;
end;

{==============================================================================]
  <Horizontal>
  @action: Returns Horizontal-axis from TPointArray as TRange.
  @note: MinMax X-values.
[==============================================================================}
function TPointArrayHelper.Horizontal: TRange; overload;
var
  i: Integer;
begin
  if Self.Exists then
  begin
    Result.Create(Self[0].X, Self[0].X);
    for i := 1 to High(Self) do
      if (Self[i].X < Result.start) then
        Result.start := Self[i].X
      else if (Self[i].X > Result.stop) then
        Result.stop := Self[i].X;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <Vertical>
  @action: Returns Vertical-axis from TPointArray as TRange.
  @note: MinMax Y-values.
[==============================================================================}
function TPointArrayHelper.Vertical: TRange; overload;
var
  i: Integer;
begin
  if Self.Exists then
  begin
    Result.Create(Self[0].Y, Self[0].Y);
    for i := 1 to High(Self) do
      if (Self[i].Y < Result.start) then
        Result.start := Self[i].Y
      else if (Self[i].Y > Result.stop) then
        Result.stop := Self[i].Y;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <XBoundaries>
  @action: Returns the minimum and maximum X coordinates (horizontal bounds) of the point array using pairwise comparisons.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.XBoundaries: TRange; overload;
var
  i, s: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(Default(TRange));
  if ((s and 1) = 1) then
  begin
    Result := TRange.Construct(Self[0].X);
    i := -1;
  end else
  begin
    if (Self[0].X < Self[1].X) then
      Result := TRange.Construct(Self[0].X, Self[1].X)
    else
      Result := TRange.Construct(Self[1].X, Self[0].X);
    i := 0;
  end;
  while (i.Increment < (s - 1)) do
    if (Self[i].X < Self[i + 1].X) then
    begin
      if (Self[i].X < Result.start) then
        Result.start := Self[i].X;
      if (Self[i + 1].X > Result.stop) then
        Result.stop := Self[i + 1].X;
    end else
    begin
      if (Self[i + 1].X < Result.start) then
        Result.start := Self[i + 1].X;
      if (Self[i].X > Result.stop) then
        Result.stop := Self[i].X;
    end;
end;

{==============================================================================]
  <YBoundaries>
  @action: Returns the minimum and maximum Y coordinates (vertical bounds) of the point array using pairwise comparisons.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.YBoundaries: TRange; overload;
var
  i, s: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(Default(TRange));
  if ((s and 1) = 1) then
  begin
    Result := TRange.Construct(Self[0].Y);
    i := -1;
  end else
  begin
    if (Self[0].Y < Self[1].Y) then
      Result := TRange.Construct(Self[0].Y, Self[1].Y)
    else
      Result := TRange.Construct(Self[1].Y, Self[0].Y);
    i := 0;
  end;
  while (i.Increment < (s - 1)) do
    if (Self[i].Y < Self[i + 1].Y) then
    begin
      if (Self[i].Y < Result.start) then
        Result.start := Self[i].Y;
      if (Self[i + 1].Y > Result.stop) then
        Result.stop := Self[i + 1].Y;
    end else
    begin
      if (Self[i + 1].Y < Result.start) then
        Result.start := Self[i + 1].Y;
      if (Self[i].Y > Result.stop) then
        Result.stop := Self[i].Y;
    end;
end;

{==============================================================================]
  <XBounds>
  @action: Returns the minimum and maximum X coordinates (horizontal bounds) of the point array.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.XBounds: TRange; overload;
var
  i, l, h: Integer;
begin
  if (Self.Length = 0) then
    Exit(Default(TRange));
  l := Self[0].X;
  h := l;
  for i := 1 to High(Self) do
    if (Self[i].X < l) then
      l := Self[i].X
    else if (Self[i].X > h) then
      h := Self[i].X;
  Result.Create(l, h);
end;

{==============================================================================]
  <YBounds>
  @action: Returns the minimum and maximum Y coordinates (vertical bounds) of the point array.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.YBounds: TRange; overload;
var
  i, l, h: Integer;
begin
  if (Self.Length = 0) then
    Exit(Default(TRange));
  l := Self[0].Y;
  h := l;
  for i := 1 to High(Self) do
    if (Self[i].Y < l) then
      l := Self[i].Y
    else if (Self[i].Y > h) then
      h := Self[i].Y;
  Result.Create(l, h);
end;

{==============================================================================]
  <XRange>
  @action: Returns the minimum and maximum X coordinates (range) of the points in the array.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.XRange: TRange; overload;
var
  i: Integer;
begin
  if (Self.Length = 0) then
    Exit(Default(TRange));
  Result := TRange.Construct(Self[0].X);
  for i := 1 to High(Self) do
    if (Self[i].X < Result.start) then
      Result.start := Self[i].X
    else if (Self[i].X > Result.stop) then
      Result.stop := Self[i].X;
end;

{==============================================================================]
  <YRange>
  @action: Returns the minimum and maximum Y coordinates (range) of the points in the array.
  @note: Returns a default TRange if the point array is empty.
[==============================================================================}
function TPointArrayHelper.YRange: TRange; overload;
var
  i: Integer;
begin
  if (Self.Length = 0) then
    Exit(Default(TRange));
  Result := TRange.Construct(Self[0].Y);
  for i := 1 to High(Self) do
    if (Self[i].Y < Result.start) then
      Result.start := Self[i].Y
    else if (Self[i].Y > Result.stop) then
      Result.stop := Self[i].Y;
end;
{$ENDIF}
