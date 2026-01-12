{$IFDEF HELPERS}
function BBox: TBox; overload;
function Boundaries: TBox;
function BoundingBox: TBox;
function Bounds: TBox; overload;
function Bounds(var width, height: Integer): TBox; overload;
function Box: TBox;
function Boxed: TBox;
function Coverage: TBox; overload;
function Extent: TBox;
function Horizontal: TRange; overload;
function MinMax: TBox;
function Region: TBox; overload;
function Vertical: TRange; overload;

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
  SetLength(a, Self.Size);
  SetLength(b, Self.Size);
  for i := 0 to High(Self) do
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
    else
      if (Self[i].X > Result.X2) then
        Result.X2 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y
    else
      if (Self[i].Y > Result.Y2) then
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
    else
      if (Self[i].X > b.X) then
        b.X := Self[i].X;
    if (Self[i].Y < a.Y) then
      a.Y := Self[i].Y
    else
      if (Self[i].Y > b.Y) then
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
    for i := 0 to High(Self) do
      if (Self[i].X < Result.start) then
        Result.start := Self[i].X
      else
        if (Self[i].X > Result.stop) then
          Result.stop := Self[i].X;
  end else
    Result := Default(TRange);
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
    for i := 0 to High(Self) do
      if (Self[i].Y < Result.start) then
        Result.start := Self[i].Y
      else
        if (Self[i].Y > Result.stop) then
          Result.stop := Self[i].Y;
  end else
    Result := Default(TRange);
end;
{$ENDIF}
