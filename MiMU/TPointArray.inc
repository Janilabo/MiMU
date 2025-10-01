{$DEFINE TPoint}{$I config\Defines.inc}

{==============================================================================]
  <TPointArrayHelper.Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Bounds: TBox; overload; cdecl;
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
  <TPointArrayHelper.Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: Stores width and height of bounds to width and height variables.
[==============================================================================}
function TPointArrayHelper.Bounds(var width, height: Integer): TBox; overload; cdecl;
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
  <TPointArrayHelper.BoundingBox>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.BoundingBox: TBox; cdecl;
var
  i: Integer;
  a, b: TIntegerArray;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  SetLength(a, Length(Self));
  SetLength(b, Length(Self));
  for i := 0 to High(Self) do
  begin
    a[i] := Self[i].X;
    b[i] := Self[i].Y;
  end;
  Result.Create(MinValue(a), MinValue(b), MaxValue(a), MaxValue(b));
end;

{==============================================================================]
  <TPointArrayHelper.Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boundaries: TBox; cdecl;
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
  <TPointArrayHelper.Box>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Box: TBox; cdecl;
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
  <TPointArrayHelper.MinMax>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.MinMax: TBox; cdecl;
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
  <TPointArrayHelper.Boxed>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boxed: TBox; cdecl;
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
  <TPointArrayHelper.Region>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Region: TBox; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
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
  <TPointArrayHelper.Coverage>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Coverage: TBox; overload; cdecl;
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
  <TPointArrayHelper.Undupe>
  @action: Removes duplicates from arr.
  @note: Returns number of duplicate items that were removed from arr.
[==============================================================================}
function TPointArrayHelper.Undupe: TPointArray; cdecl;
begin
  Result := Self.Copy;
  TPA.Unique(Result);
end;

{==============================================================================]
  <TPointArrayHelper.Unduped>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Unduped: TPointArray; cdecl;
var
  i, r, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if Self.Exists then
  begin
    b := Self.Bounds(w, h);
    m := T2D.Create(False, w, h);
    SetLength(Result, Length(Self));
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Result[r.Increase] := Self[i];
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TPointArrayHelper.Invert>
  @action: Returns inverted version of arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Invert: TPointArray; cdecl;
var
  i, x, y, w, h, r, l: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if (High(Self) > 0) then
  begin
    b := Self.Bounds(w, h);
	m := T2D.Create(False, w, h);
    x := 0;
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Inc(x);
    SetLength(Result, ((w * h) - x));
    if (Length(Result) > 0) then
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if not m[x][y] then
          Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TPointArrayHelper.Inverted>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverted(const arrBounds: TBox): TPointArray; overload; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, arrBounds.Area);
  r := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not Self.Contains(Point(x, y)) then
        Result[r.Increase] := Point(x, y);
  SetLength(Result, r);
end;

function TPointArrayHelper.Inverted: TPointArray; overload; cdecl;
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <TPointArrayHelper.Inverse>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverse(const arrBounds: TBox): TPointArray; overload; cdecl;
var
  w, h, l, i, x, y: Integer;
  b: T2DBooleanArray;
begin
  if (Length(Self) < 2) then
    Exit([]);
  SetLength(Result, arrBounds.Size(w, h));
  b := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    if arrBounds.Contains(Self[i]) then
      b[Self[i].Y - arrBounds.Y1][Self[i].X - arrBounds.X1] := True;
  l := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not b[y - arrBounds.Y1][x - arrBounds.X1] then
        Result[l.Increase] := Point(x, y);
  SetLength(Result, l);
end;

function TPointArrayHelper.Inverse: TPointArray; overload; cdecl;
begin
  Result := Self.Inverse(Self.Bounds);
end;

{==============================================================================]
 <TPointArrayHelper.Edge>
 @action: Returns with all the edge-points from arr.
          Supports both, 4-way and 8-way direction scanning styles.
 @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArrayHelper.Edge(const scan8W: Boolean = False): TPointArray; cdecl;
var
  i, l, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Length(Self);
  if (l > 4) then
  begin
    b := Self.Bounds;
    b := b.Expand;
    b.Size(w, h);
    m := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
      m[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
    SetLength(Result, (w * h));
    w := (w - 2);
    h := (h - 2);
    r := 0;
    case scan8W of
      False:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
      True:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1] and m[x - 1][y - 1] and m[x - 1][y + 1] and m[x + 1][y - 1] and m[x + 1][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    end;
    SetLength(Result, r);
    SetLength(m, 0);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
  <TPointArrayHelper.FloodFill>
  @action:: Outputs Flood Filled points from TPointArray or non-TPointArray points inside an area,
            starting from start, based on FloodFill() action.
            Supports custom area by area as TBox.
  note: Make sure start is inside your area. Doesn't pay attention to ANYTHING outside area. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
  procedure GetAdjacent(var adj: TPointArray; const n: TPoint; const FF8W: Boolean);
  begin
    adj[0].Create(n.x, (n.y - 1));
    adj[3].Create(n.x, (n.y + 1));
    adj[1].Create((n.x + 1), n.y);
    adj[2].Create((n.x - 1), n.y);
    if FF8W then
    begin
      adj[4].Create((n.x - 1), (n.y - 1));
      adj[5].Create((n.x + 1), (n.y - 1));
      adj[6].Create((n.x - 1), (n.y + 1));
      adj[7].Create((n.x + 1), (n.y + 1));
    end;
  end;
var
  l, i, w, h, x, y, f, t, r: Integer;
  q, a: TPointArray;
  p: TPoint;
  c, z: T2DBooleanArray;
  o, s: Boolean;
begin
  r := 0;
  l := Length(Self);
  if ((l > 0) and ((start.X >= area.X1) and (start.Y >= area.Y1) and (start.X <= area.X2) and (start.Y <= area.Y2))) then
  begin
    o := False;
    area.Size(w, h);
    c := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
    begin
      if not o then
        o := ((start.X = Self[i].X) and (start.Y = Self[i].Y));
      if (((Self[i].X - area.X1) > -1) and ((Self[i].Y - area.Y1) > -1) and ((Self[i].Y - area.Y1) < h) and ((Self[i].X - area.X1) < w)) then
        c[Self[i].X - area.X1][Self[i].Y - area.Y1] := True;
    end;
    s := not o;
    if scan8W then
      f := 7
    else
      f := 3;
    SetLength(a, (f + 1));
    SetLength(q, (w * h));
    z := T2D.Create(False, w, h);
    q[0] := start;
    l := 0;
    while (l > -1) do
    begin
      GetAdjacent(a, q[l], scan8W);
      for i := 0 to f do
      begin
        p := a[i];
        x := (p.X - area.X1);
        y := (p.Y - area.Y1);
        if ((x > -1) and (y > -1) and (x < w) and (y < h) and (c[x][y] = not s)) then
        begin
          c[x][y] := s;
          z[x][y] := True;
          q[l.Increase] := p;
        end;
      end;
      l := (l - 1);
    end;
    SetLength(c, 0);
    SetLength(q, 0);
    SetLength(a, 0);
    SetLength(Result, (w * h));
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if z[x][y] then
          Result[r.Increase].Create((x + area.X1), (y + area.Y1));
    SetLength(z, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArray_FloodFill
 @action: Outputs Flood Filled points from TPointArray or non-TPointArray points inside arr Bounds,
          starting from start, based on FloodFill() action.
 @note: Make sure start is inside TPA Bounds.
        Doesn't pay attention to ANYTHING outside those boundaries. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;
begin
  Result := Self.FloodFill(start, Self.Bounds, scan8W);
end;

{==============================================================================]
 <TPointArrayHelper.Xs>
 @action: Returns X-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Xs: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].X;
end;

{==============================================================================]
 <TPointArrayHelper.Ys>
 @action: Returns Y-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Ys: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y;
end;

{==============================================================================]
 <TPointArrayHelper.X>
 @action: Returns X-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TPointArrayHelper.XValues: TIntegerArray; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X;
end;

{==============================================================================]
 <TPointArrayHelper.Y>
 @action: Returns Y-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TPointArrayHelper.YValues: TIntegerArray; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y;
end;

{==============================================================================]
 <TPointArrayHelper.Unzip>
 @action: Stores arr X and Y values to xArr and yArr.
 @note: Returns Length(arr).
[==============================================================================}
function TPointArrayHelper.Unzip(var xArr, yArr: TIntegerArray): Integer; cdecl;
var
  i: Integer;
begin
  Result := Length(Self);
  SetLength(xArr, Result);
  SetLength(yArr, Result);
  for i := 0 to (Result - 1) do
  begin
    xArr[i] := Self[i].X;
    yArr[i] := Self[i].Y;
  end;
end;

{==============================================================================]
 <TPointArrayHelper.Zip>
 @action: Zips TPointArray with xArr and yArr.
 @note: Uses minimum length(!), if xArr differs from yArr size.
[==============================================================================}
function TPointArrayHelper.Zip(const xArr, yArr: TIntegerArray): Integer; cdecl;
var
  i: Integer;
begin
  Result := Min(Length(xArr), Length(yArr));
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
    Self[i] := Point(xArr[i], yArr[i]);
end;

{==============================================================================]
  <TPointArrayHelper.Extent>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Extent: TBox; cdecl;
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
 <TPointArrayHelper.Horizontal>
 @action: Returns Horizontal-axis from TPointArray as TRange.
 @note: MinMax X-values.
[==============================================================================}
function TPointArrayHelper.Horizontal: TRange; overload; cdecl;
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
 <TPointArrayHelper.Vertical>
 @action: Returns Vertical-axis from TPointArray as TRange.
 @note: MinMax Y-values.
[==============================================================================}
function TPointArrayHelper.Vertical: TRange; overload; cdecl;
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

{==============================================================================]
 <TPointArrayHelper.Split>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const xRadius, yRadius: Double): T2DPointArray; overload; cdecl;
var
  i, j, k, l, g: Integer;
  p: TPointArray;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit;
  p := Self.QuickSorted(Self.Xs);
  l := 0;
  Result[0] := [p[0]];
  for i := 1 to High(p) do
  begin
    g := -1;
    for j := 0 to l do
    begin
      for k := 0 to High(Result[j]) do
        if (Abs(p[i].X - Result[j][k].X) > xRadius) then
          Break
        else
          if (Abs(p[i].Y - Result[j][k].Y) <= yRadius) then
          begin
            g := l;
            Break;
          end;
      if (g > -1) then
        Break;
    end;
    if (g = -1) then
      Result[l.Increment] := [p[i]]
    else
      Result[g] := (Result[g] + [p[i]]);
  end;
  SetLength(Result, (l + 1));
end;

{==============================================================================]
 <TPointArrayHelper.Split>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double): T2DPointArray; overload; cdecl;
begin
  Result := Self.Split(radius, radius);
end;

function TPointArrayHelper.Cluster(const dist: Integer): T2DPointArray; overload; cdecl;
var
  w, h, i, j, l, g, p, x, y, r, d: Integer;
  s: T2DBooleanArray;
  c: T2DIntegerArray;
  q: TPointArray;
  a, b: TBox;
  z: TPoint;
  v: Boolean;
begin
  SetLength(Result, 0);
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  r := 0;
  b := Self.Bounds(w, h);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  d := Min(Ceil(Max(dist, 0.0)), Max(w, h));
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  for i := 0 to High(Self) do
  begin
    if (c[Self[i].X - b.X1][Self[i].Y - b.Y1] = 0) then
      Continue;
    g := Length(Result);
    SetLength(Result, (g + 1));
    SetLength(Result[g], c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
    for j := 0 to (c[Self[i].X - b.X1][Self[i].Y - b.Y1] - 1) do
      Result[g][j] := Self[i];
    if (r.Increment(c[Self[i].X - b.X1][Self[i].Y - b.Y1]) > High(Self)) then
      Exit;
    q := [Self[i]];
    c[Self[i].X - b.X1][Self[i].Y - b.Y1] := 0;
    p := 1;
    while (p > 0) do
    begin
      p := High(q);
      z := q[p];
      a.Create((z.X - d), (z.Y - d), (z.X + d), (z.Y + d));
      SetLength(q, p);
      a.Constraint(b);
      for y := a.Y1 to a.Y2 do
      begin
        if s[a.X2 - b.X1][y - b.Y1] then
          Continue;
        v := True;
        for x := a.X1 to a.X2 do
          if ((c[x - b.X1][y - b.Y1] > 0) and (Round(Sqrt(Sqr(z.X - x) + Sqr(z.Y - y))) <= dist)) then
          begin
            l := Length(Result[g]);
            SetLength(Result[g], (l + c[x - b.X1][y - b.Y1]));
            for j := 0 to (c[x - b.X1][y - b.Y1] - 1) do
              Result[g][l + j] := Point(x, y);
            if (r.Increment(c[x - b.X1][y - b.Y1]) > h) then
              Exit;
            c[x - b.X1][y - b.Y1] := 0;
            SetLength(q, (p + 1));
            q[p.Increase] := Result[g][l];
          end else
            v := False;
        if v then
          s[a.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
  end;
end;

function TPointArrayHelper.Cluster(const width, height: Integer): T2DPointArray; overload; cdecl;
var
  w, h, i, l, g, p, x, y, o, r: Integer;
  s: T2DBooleanArray;
  c: T2DIntegerArray;
  q: TPointArray;
  a, b: TBox;
  z: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  r := 0;
  b := Self.Bounds(w, h);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  w := Min(width, w);
  h := Min(height, h);
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  for i := 0 to High(Self) do
  begin
    if (c[Self[i].X - b.X1][Self[i].Y - b.Y1] = 0) then
      Continue;
    g := Length(Result);
    SetLength(Result, (g + 1));
    SetLength(Result[g], c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
    for o := 0 to (c[Self[i].X - b.X1][Self[i].Y - b.Y1] - 1) do
      Result[g][o] := Self[i];
    if (r.Increment(c[Self[i].X - b.X1][Self[i].Y - b.Y1]) > High(Self)) then
      Exit;
    q := [Self[i]];
    c[Self[i].X - b.X1][Self[i].Y - b.Y1] := 0;
    p := 1;
    while (p > 0) do
    begin
      p := High(q);
      z := q[p];
      a.Create((z.X - w), (z.Y - h), (z.X + w), (z.Y + h));
      SetLength(q, p);
      a.Constraint(b);
      for y := a.Y1 to a.Y2 do
      begin
        if s[a.X2 - b.X1][y - b.Y1] then
          Continue;
        for x := a.X1 to a.X2 do
          if (c[x - b.X1][y - b.Y1] > 0) then
          begin
            l := Length(Result[g]);
            SetLength(Result[g], (l + c[x - b.X1][y - b.Y1]));
            for o := 0 to (c[x - b.X1][y - b.Y1] - 1) do
              Result[g][l + o] := Point(x, y);
            if (r.Increment(c[x - b.X1][y - b.Y1]) > High(Self)) then
              Exit;
            c[x - b.X1][y - b.Y1] := 0;
            SetLength(q, (p + 1));
            q[p.Increase] := Result[g][l];
          end;
        s[a.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
  end;
end;

{==============================================================================]
 <TPointArrayHelper.Segment>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const radius: Double): T2DPointArray; overload; cdecl;
var
  b, f, l, i, j, k, p, r, c: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
begin
  l := Length(Self);
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(q, l);
    f := 0;
    b := 0;
    q[b.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (f < b) do
    begin
      j := q[f.Increase];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if not v[k] then
          if (Hypot((Self[j].X - Self[k].X), (Self[j].Y - Self[k].Y)) <= radius) then
          begin
            v[k] := True;
            q[b.Increase] := k;
          end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArrayHelper.Fragment>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const radius: Double): T2DPointArray; overload; cdecl;
var
  h, l, i, j, k, r, p, c: Integer;
  v: TBooleanArray;
  s: TIntegerArray;
begin
  l := Length(Self);
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(s, l);
    h := 0;
    s[h.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (h > 0) do
    begin
      j := s[h.Decrement];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if not v[k] then
          if (Hypot((Self[j].X - Self[k].X), (Self[j].Y - Self[k].Y)) <= radius) then
          begin
            v[k] := True;
            s[h.Increase] := k;
          end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArrayHelper.Clusterize>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const radius: Double): T2DPointArray; overload; cdecl;
var
  m, p: TIntegerArray;
  r, l, i, j: Integer;
  function PFind(x: Integer): Integer;
  var
    s: Integer;
  begin
    Result := x;
    while (p[Result] <> Result) do
      Result := p[Result];
    while (p[x] <> x) do
    begin
      s := p[x];
      p[x] := Result;
      x := s;
    end;
  end;
  procedure PUnioned(a, b: Integer);
  var
    f, t: Integer;
  begin
    f := PFind(a);
    t := PFind(b);
    if (f <> t) then
      p[t] := f;
  end;
begin
  l := Length(Self);
  if (l = 0) then
    Exit([]);
  SetLength(p, l);
  for i := 0 to (l - 1) do
    p[i] := i;
  for i := 0 to (l - 1) do
    for j := (i + 1) to (l - 1) do
      if (Hypot((Self[i].X - Self[j].X), (Self[i].Y - Self[j].Y)) <= radius) then
        PUnioned(i, j);
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    r := PFind(i);
    if (m[r] = -1) then
    begin
      m[r] := Length(Result);
      SetLength(Result, (Length(Result) + 1));
      Result[m[r]] := [];
    end;
    Result[m[r]] := (Result[m[r]] + [Self[i]]);
  end;
end;

{==============================================================================]
 <TPointArrayHelper.Clusterize>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const xRadius, yRadius: Double): T2DPointArray; overload; cdecl;
var
  m, p: TIntegerArray;
  i, j, r, c: Integer;
  function PFind(x: Integer): Integer;
  var
    s: Integer;
  begin
    Result := x;
    while (p[Result] <> Result) do
      Result := p[Result];
    while (p[x] <> x) do
    begin
      s := p[x];
      p[x] := Result;
      x := s;
    end;
  end;
  procedure PUnioned(a, b: Integer);
  var
    f, t: Integer;
  begin
    f := PFind(a);
    t := PFind(b);
    if (f <> t) then
      p[t] := f;
  end;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  SetLength(p, Length(Self));
  for i := 0 to High(Self) do
    p[i] := i;
  for i := 0 to (High(Self) - 1) do
    for j := (i + 1) to High(Self) do
      if ((Abs(Self[i].X - Self[j].X) <= xRadius) and (Abs(Self[i].Y - Self[j].Y) <= yRadius)) then
        PUnioned(i, j);
  SetLength(m, Length(Self));
  for i := 0 to High(m) do
    m[i] := -1;
  c := 0;
  for i := 0 to High(Self) do
  begin
    r := PFind(i);
    if (m[r] = -1) then
    begin
      m[r] := c;
      SetLength(Result, (c + 1));
      SetLength(Result[c.Increase], 0);
    end;
    Result[m[r]] := (Result[m[r]] + [Self[i]]);
  end;
end;

{==============================================================================]
 <TPointArrayHelper.XClassify>
 @action: Classifies TPointArray to groups by X-value
 @note: None.
[==============================================================================}
function TPointArrayHelper.XClassify(const pSorted: Boolean = False): T2DPointArray; overload; cdecl;
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Xs)
  else
    p := Self.Copy;
  Result := p.Classes(p.Xs);
end;

{==============================================================================]
 <TPointArrayHelper.YClassify>
 @action: Classifies TPointArray to groups by X-value
 @note: None.
[==============================================================================}
function TPointArrayHelper.YClassify(const pSorted: Boolean = False): T2DPointArray; overload; cdecl;
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Ys)
  else
    p := Self.Copy;
  Result := p.Classes(p.Ys);
end;

{==============================================================================]
  <TPointArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all TPoint elements to (0,0), while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Reinit: Integer; cdecl;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(TPoint)), 0);
end;

{$UNDEF TPoint}
