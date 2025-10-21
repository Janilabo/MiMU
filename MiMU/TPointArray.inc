{$DEFINE TPoint}{$I config\Defines.inc}

{==============================================================================]
  <TPointArrayHelper.Bounds>
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
  <TPointArrayHelper.Bounds>
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
  <TPointArrayHelper.BoundingBox>
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
  <TPointArrayHelper.Box>
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
  <TPointArrayHelper.MinMax>
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
  <TPointArrayHelper.Boxed>
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
  <TPointArrayHelper.Region>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Region: TBox; overload; 
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
  <TPointArrayHelper.Undupe>
  @action: Removes duplicates from arr.
  @note: Returns number of duplicate items that were removed from arr.
[==============================================================================}
function TPointArrayHelper.Undupe: TPointArray; 
begin
  Result := Self.Copy;
  TPA.Unique(Result);
end;

{==============================================================================]
  <TPointArrayHelper.Unduped>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Unduped: TPointArray; 
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
function TPointArrayHelper.Invert: TPointArray; 
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
function TPointArrayHelper.Inverted(const arrBounds: TBox): TPointArray; overload; 
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

function TPointArrayHelper.Inverted: TPointArray; overload; 
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <TPointArrayHelper.Inverse>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverse(const arrBounds: TBox): TPointArray; overload; 
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

function TPointArrayHelper.Inverse: TPointArray; overload; 
begin
  Result := Self.Inverse(Self.Bounds);
end;

{==============================================================================]
 <TPointArrayHelper.Edge>
 @action: Returns with all the edge-points from arr.
          Supports both, 4-way and 8-way direction scanning styles.
 @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArrayHelper.Edge(const scan8W: Boolean = False): TPointArray; 
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
function TPointArrayHelper.FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; 
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
function TPointArrayHelper.FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; 
begin
  Result := Self.FloodFill(start, Self.Bounds, scan8W);
end;

{==============================================================================]
 <TPointArrayHelper.Xs>
 @action: Returns X-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Xs: TIntegerArray; overload; 
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
function TPointArrayHelper.Ys: TIntegerArray; overload; 
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
function TPointArrayHelper.XValues: TIntegerArray; overload; 
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
function TPointArrayHelper.YValues: TIntegerArray; overload; 
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
function TPointArrayHelper.Unzip(var xArr, yArr: TIntegerArray): Integer; 
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
function TPointArrayHelper.Zip(const xArr, yArr: TIntegerArray): Integer; 
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
 <TPointArrayHelper.Horizontal>
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
 <TPointArrayHelper.Vertical>
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

{==============================================================================]
 <TPointArray.Neighborify>
 @action: Groups points into clusters of connected neighbors based on 4- or 8-directional adjacency.
 @note: Uses a flood-fill algorithm on a bounding-box grid. Returns a T2DPointArray where each sub-array is a connected component.
        Empty arrays return [] and single-point arrays return [Self].
[==============================================================================}
function TPointArrayHelper.Neighborify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  w, h, l: Integer;
  v, g: T2DBooleanArray;
  d, q: TPointArray;
  s: TRange;
  i, j, x, y, z, r: Integer;
  p: TPoint;
  b: TBox;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds(w, h);
  SetLength(g, w, h);
  SetLength(v, w, h);
  for i := 0 to (l - 1) do
    g[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
  if adjacency8 then
    d := [Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1), Point(1, 0), Point(1, -1), Point(0, -1)]
  else
    d := [Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)];
  r := 0;
  SetLength(Result, l);
  for i := 0 to (w - 1) do
    for j := 0 to (h - 1) do
      if (g[i][j] and (not v[i][j])) then
      begin
        SetLength(q, 1);
        q[0] := Point(i, j);
        s.Create(0, 1);
        while (s.start < s.stop) do
        begin
          p := q[s.start.Increase];
          if v[p.X][p.Y] then
            Continue;
          v[p.X][p.Y] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := Point((p.X + b.X1), (p.Y + b.Y1));
          for z := 0 to High(d) do
          begin
            x := (p.X + d[z].X);
            y := (p.Y + d[z].Y);
            if ((x >= 0) and (x < w) and (y >= 0) and (y < h) and g[x][y] and (not v[x][y])) then
            begin
              if (s.stop >= Length(q)) then
                SetLength(q, (Length(q) * 2));
              q[s.stop.Increase] := Point(x, y);
            end;
          end;
        end;
        if (Length(Result[r]) > 0) then
          Inc(r);
      end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArray.Regionize>
 @action: Groups points in the array into clusters based on rectangular neighborhoods
          defined by X and Y radii.
 @note: Clusters are formed by examining a box of size XRadius x YRadius around each
        point. Points within the same box are grouped together. This version does not
        use a distance function; it is grid/box-based.
[==============================================================================}
function TPointArrayHelper.Regionize(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  x, y, i, l, r, c, t, f: Integer;
  g, d: TStringList;
  p, n: TPoint;
  q: TPointArray;
  k: string;
  a, b: TBox;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Length(Result[r]) + 1));
        Result[r][High(Result[r])] := p;
        a := p.Boxed(xRadius, yRadius).Clamp(b);
        for y := a.Y1 to a.Y2 do
          for x := a.X1 to a.X2 do
          begin
            n := Point(x, y);
            k := KeyStr(n);
            if (g.Find(k, f) and (not d.Find(k, f))) then
            begin
              SetLength(q, (c + 1));
              q[c.Increase] := n;
            end;
          end;
      end;
      if Length(Result[r]) > 0 then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArray.Regionize>
 @action: Groups points in the array into clusters based on a distance threshold.
 @note: Clusters are formed by examining all points within the array using the
        provided distance function. Points within the specified radius (Double)
        of any cluster member are added to the same cluster. This version supports
        arbitrary distance metrics via the TDistanceFunction parameter.
[==============================================================================}
function TPointArrayHelper.Regionize(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, l, r, c, t, f: Integer;
  g, d: TStringList;
  p, n: TPoint;
  q: TPointArray;
  k: string;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Length(Result[r]) + 1));
        Result[r][High(Result[r])] := p;
        for j := 0 to (l - 1) do
        begin
          n := Self[j];
          if ((not d.Find(KeyStr(n), f)) and (distFunc(p, n) <= radius)) then
          begin
            SetLength(q, (c + 1));
            q[c.Increase] := n;
          end;
        end;
      end;
      if (Length(Result[r]) > 0) then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Regionize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Regionize(radius, @Euclidean);
end;

{==============================================================================]
 <TPointArray.CSplit>
 @action: Groups points into clusters based on horizontal (X-axis) proximity.
 @note: Sorts by column (X) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.CSplit(const radius: Double; const distFunc: TDistanceFunction; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.CSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.CSplit(radius, @Euclidean, sSorted);
end;

function TPointArrayHelper.CSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create((p.X - xRadius), (p.X + xRadius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.RSplit>
 @action: Groups points into clusters based on vertical (Y-axis) proximity.
 @note: Sorts by row (Y) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.RSplit(const radius: Double; const distFunc: TDistanceFunction; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.RSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.RSplit(radius, @Euclidean, sSorted);
end;

function TPointArrayHelper.RSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create((p.Y - yRadius), (p.Y + yRadius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.XSplit>
 @action: Splits the point array into clusters based on X/Y coordinate proximity.
 @note: Optimized for arrays sorted by X (ascending). 
        Each group contains points within |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
        If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.XSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      m.Create((p.X - xRadius), (p.X + xRadius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.XSplit>
 @action: Splits the point array into clusters using a custom distance function.
 @note: Efficient for data already sorted by X.
        Points are grouped if distFunc(p, q) ≤ radius.
        The X-range window limits comparisons for performance (O(n log n) typical).
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double; const distFunc: TDistanceFunction; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.XSplit>
 @action: Splits the point array into clusters using Euclidean distance.
 @note: Shorthand for XSplit(radius, @Euclidean, sSorted).
        Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.XSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
 <TPointArray.YSplit>
 @action: Splits the point array into clusters based on Y/X coordinate proximity.
 @note: Optimized for arrays sorted by Y (ascending).
        Each group contains points within |ΔY| ≤ yRadius and |ΔX| ≤ xRadius.
        If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.YSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      m.Create((p.Y - yRadius), (p.Y + yRadius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.YSplit>
 @action: Splits the point array into clusters using a custom distance function.
 @note: Efficient for data already sorted by Y.
        Points are grouped if distFunc(p, q) ≤ radius.
        Y-sorted scanning limits comparisons for faster clustering.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double; const distFunc: TDistanceFunction; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and (distFunc(p, a[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArray.YSplit>
 @action: Splits the point array into clusters using Euclidean distance.
 @note: Shorthand for YSplit(radius, @Euclidean, sSorted).
        Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.YSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
 <TPointArrayHelper.Split>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if ((Abs(Result[c][r].X - p[s].X) <= xRadius) and (Abs(Result[c][r].Y - p[s].Y) <= yRadius)) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
 <TPointArrayHelper.Split>
 @action: Splits TPointArray to groups by radius.
 @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if (distFunc(Result[c][r], p[s]) <= radius) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
 <TPointArrayHelper.Split>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Split(radius, @Euclidean);
end;

{==============================================================================]
 <TPointArrayHelper.SplitEx>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Length(Self);
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and (Abs(p.X - Self[k].X) <= xRadius) and (Abs(p.Y - Self[k].Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArrayHelper.SplitEx>
 @action: Splits TPointArray to groups by radius.
 @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Length(Self);
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Length(Result[r])) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and (distFunc(p, Self[k]) <= radius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
 <TPointArrayHelper.SplitEx>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.SplitEx(radius, @Euclidean);
end;

{==============================================================================]
  <TPointArray.Clusters>
  @action: Group points in the array into clusters based on a distance threshold.
  @note: Uses a breadth-first region-growing approach.
         Each cluster contains points whose pairwise distances are within radius.
         Uses the provided distance function.
[==============================================================================}
function TPointArrayHelper.Clusters(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, p, u: TPoint;
  a: Boolean;
  l: TRange;
  d, m, o: Double;
begin
  z := Length(Self);
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
  p := Point(b.X1, b.Y1);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  SetLength(q, z);
  d := Max(radius, 0);
  o := (d * d);
  m := Min(d, Max(w, h));
  r := 0;
  e := 0;
  for i := 0 to (z - 1) do
  begin
    g:= Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (c[g.X][g.Y] <= 0) then
      Continue;
    n := c[g.X][g.Y];
    SetLength(Result, (r + 1));
    SetLength(Result[r], n);
    for v := 0 to (n - 1) do
      Result[r][v] := Self[i];
    if (e.Increment(n) > (z - 1)) then
      Exit;
    l.Create(0);
    q[l.stop.Increase] := Result[r][0];
    c[g.X][g.Y] := 0;
    while (l.start < l.stop) do
    begin
      k := q[l.start.Increase];
      f := k.Boxed(Ceil(m)).Clamp(b);
      for y := f.Y1 to f.Y2 do
      begin
        if s[f.X2 - b.X1][y - b.Y1] then
          Continue;
        a := True;
        for x := f.X1 to f.X2 do
        begin
          u := Point((x - b.X1), (y - b.Y1));
          if not (c[u.X][u.Y] > 0) then
            Continue;
          if (distFunc(k, Point(x, y)) <= o) then
          begin
            t := Length(Result[r]);
            SetLength(Result[r], (t + c[u.X][u.Y]));
            for v := 0 to (c[u.X][u.Y] - 1) do
              Result[r][t + v] := Point(x, y);
            q[l.stop.Increase] := Result[r][t];
            if (e.Increment(c[u.X][u.Y]) > (z - 1)) then
              Exit;
            c[u.X][u.Y] := 0;
          end else
            a := False;
        end;
        if a then
          s[f.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
    Inc(r);
  end;
end;

function TPointArrayHelper.Clusters(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusters(radius, @Euclidean);
end;

{==============================================================================]
  <TPointArray.Clusters>
  @action: Group points in the array into rectangular clusters based on X and Y radii.
  @note: Clustering is anisotropic — points are grouped if their |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
         No distance function is used.
[==============================================================================}
function TPointArrayHelper.Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, o, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, p, u, m: TPoint;
  a: Boolean;
  l: TRange;
begin
  z := Length(Self);
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
  p := Point(b.X1, b.Y1);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  SetLength(q, z);
  m := Point(Min(Max(0, xRadius), w), Min(Max(0, yRadius), h));
  r := 0;
  e := 0;
  for i := 0 to (z - 1) do
  begin
    g:= Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (c[g.X][g.Y] <= 0) then
      Continue;
    n := c[g.X][g.Y];
    SetLength(Result, (r + 1));
    SetLength(Result[r], n);
    for v := 0 to (n - 1) do
      Result[r][v] := Self[i];
    if (e.Increment(n) > (z - 1)) then
      Exit;
    l.Create(0);
    q[l.stop.Increase] := Result[r][0];
    c[g.X][g.Y] := 0;
    while (l.start < l.stop) do
    begin
      k := q[l.start.Increase];
      f := k.Boxed(Max(m.X, m.Y)).Clamp(b);
      for y := f.Y1 to f.Y2 do
      begin
        if s[f.X2 - b.X1][y - b.Y1] then
          Continue;
        a := True;
        for x := f.X1 to f.X2 do
        begin
          u := Point((x - b.X1), (y - b.Y1));
          if not (c[u.X][u.Y] > 0) then
            Continue;
          if ((Abs(k.X - x) <= m.X) and (Abs(k.Y - y) <= m.Y)) then
          begin
            t := Length(Result[r]);
            SetLength(Result[r], (t + c[u.X][u.Y]));
            for v := 0 to (c[u.X][u.Y] - 1) do
              Result[r][t + v] := Point(x, y);
            q[l.stop.Increase] := Result[r][t];
            if (e.Increment(c[u.X][u.Y]) > (z - 1)) then
              Exit;
            c[u.X][u.Y] := 0;
          end else
            a := False;
        end;
        if a then
          s[f.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
    Inc(r);
  end;
end;

{==============================================================================]
  <TPointArray.Cluster>
  @action: Groups the points in the array into clusters based on a given distance threshold.
  @note: Uses a grid-based breadth-first search (BFS) approach; points are added to a cluster 
         if their distance from any member is less than or equal to radius.
		 Supports custom distance functions via distFunc (default is Euclidean).
[==============================================================================}
function TPointArrayHelper.Cluster(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  w, h, i, j, c, r, x, y: Integer;
  d: Double;
  b, a: TBox;
  e: Boolean;
  v: T2DBooleanArray;
  g: array of T2DPointArray;
  q: TPointArray;
  z, p, n: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Length(Self));
  b := Self.Bounds(w, h);
  d := Max(0, radius);
  c := Ceil(d);
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (Length(g[n.X][n.Y]) + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or (Length(g[n.X][n.Y]) = 0)) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (Length(q) > 0) do
    begin
      z := q[High(q)];
      SetLength(q, High(q));
      a.Create((z.X - c), (z.Y - c), (z.X + c), (z.Y + c)).Constraint(b);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
        begin
          if v[x - b.X1][y - b.Y1] then
            Continue;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
          begin
            p := g[x - b.X1][y - b.Y1][j];
            if (distFunc(z, p) <= d) then
            begin
              SetLength(Result[r], (Length(Result[r]) + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (Length(q) + 1));
              q[High(q)] := p;
              g[x - b.X1][y - b.Y1][j] := Point(-1, -1);
            end;
          end;
          e := True;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
            if (g[x - b.X1][y - b.Y1][j].X <> -1) then
              e := False;
          if e then
            v[x - b.X1][y - b.Y1] := True;
        end;
    end;
    if (Length(Result[r]) > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Cluster(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Cluster(radius, @Euclidean);
end;

{==============================================================================]
  <TPointArray.Cluster>
  @action: Groups points into clusters using separate X and Y distance limits.
  @note: Clusters are formed within rectangular (axis-aligned) bounds where the 
         absolute difference in X and Y coordinates does not exceed xRadius and yRadius. 
         Faster than the distance-function version but not rotation invariant.
[==============================================================================}
function TPointArrayHelper.Cluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  w, h, i, j, r, x, y: Integer;
  b, a: TBox;
  e: Boolean;
  v: T2DBooleanArray;
  g: array of T2DPointArray;
  q: TPointArray;
  z, p, n, d, c: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Length(Self));
  b := Self.Bounds(w, h);
  d := Point(Max(0, xRadius), Max(0, yRadius));
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (Length(g[n.X][n.Y]) + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or (Length(g[n.X][n.Y]) = 0)) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (Length(q) > 0) do
    begin
      z := q[High(q)];
      SetLength(q, High(q));
      a.Create((z.X - d.X), (z.Y - d.Y), (z.X + d.X), (z.Y + d.Y)).Constraint(b);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
        begin
          if v[x - b.X1][y - b.Y1] then
            Continue;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
          begin
            p := g[x - b.X1][y - b.Y1][j];
            if ((Abs(z.X - p.X) <= xRadius) and (Abs(z.Y - p.Y) <= yRadius)) then
            begin
              SetLength(Result[r], (Length(Result[r]) + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (Length(q) + 1));
              q[High(q)] := p;
              g[x - b.X1][y - b.Y1][j] := Point(-1, -1);
            end;
          end;
          e := True;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
            if (g[x - b.X1][y - b.Y1][j].X <> -1) then
              e := False;
          if e then
            v[x - b.X1][y - b.Y1] := True;
        end;
    end;
    if (Length(Result[r]) > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Clustered(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Length(Self));
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (Length(q) > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and (distFunc(p, Self[j]) <= radius)) then
        begin
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (Length(q) + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Clustered(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clustered(radius, @Euclidean);
end;

function TPointArrayHelper.Clustered(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Length(Self));
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (Length(q) > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and ((Abs(p.X - Self[j].X) <= xRadius) and (Abs(p.Y - Self[j].Y) <= yRadius))) then
        begin
          SetLength(Result[r], (Length(Result[r]) + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (Length(q) + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Clusterify(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Length(Self));
  SetLength(Result, Length(Self));
  r := 0;
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    l := 1;
    v[i] := True;
    SetLength(q, 1);
    q[0] := i;
    s := 1;
    while (s > 0) do
    begin
      c := q[s - 1];
      Dec(s);
      SetLength(q, s);
      p := Self[c];
      for j := 0 to High(Self) do
        if ((not v[j]) and (distFunc(p, Self[j]) <= radius)) then
        begin
          v[j] := True;
          SetLength(Result[r], (l + 1));
          Result[r][l.Increase] := Self[j];
          SetLength(q, (s + 1));
          q[s.Increase] := j;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Clusterify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterify(radius, @Euclidean);
end;

function TPointArrayHelper.Clusterify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Length(Self) of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Length(Self));
  SetLength(Result, Length(Self));
  r := 0;
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    l := 1;
    v[i] := True;
    SetLength(q, 1);
    q[0] := i;
    s := 1;
    while (s > 0) do
    begin
      c := q[s - 1];
      Dec(s);
      SetLength(q, s);
      p := Self[c];
      for j := 0 to High(Self) do
        if ((not v[j]) and ((Abs(p.X - Self[j].X) <= xRadius) and (Abs(p.Y - Self[j].Y) <= yRadius))) then
        begin
          v[j] := True;
          SetLength(Result[r], (l + 1));
          Result[r][l.Increase] := Self[j];
          SetLength(q, (s + 1));
          q[s.Increase] := j;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TPointArrayHelper.Clusterize>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload; 
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
	  if (distFunc(Self[i], Self[j]) <= radius) then
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

function TPointArrayHelper.Clusterize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterize(radius, @Distance);
end;

{==============================================================================]
 <TPointArrayHelper.Clusterize>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const xRadius, yRadius: Integer): T2DPointArray; overload; 
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
 <TPointArray.Grouped>
 @action: Partitions the points in the array into groups of connected points
          based on adjacency (4- or 8-connectivity). Each group is returned
          as a separate T2DPointArray within the result array.
 @note: The adjacency method is determined by the 'adjacency8' parameter:
        - True  => 8-connectivity (including diagonals)
        - False => 4-connectivity (orthogonal neighbors only)
        Returns a T2DPointArray where each element is a group of connected points.
        Uses a BFS (breadth-first search) algorithm internally to find the groups.
[==============================================================================}
function TPointArrayHelper.Grouped(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  q: TIntegerArray;
  d: TPointArray;
  r: TRange;
  i, j, p, g, k, l: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := Length(Result);
    SetLength(Result, (g + 1));
    SetLength(q, l);
    r.Create(0, 0);
    q[r.stop.Increase] := i;
    v[i] := True;
    while (r.start < r.stop) do
    begin
      p := q[r.start.Increase];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := Self[p];
      for j := 0 to High(d) do
        for k := 0 to (l - 1) do
          if ((not v[k]) and ((Self[k].X = (Self[p].X + d[j].X)) and (Self[k].Y = (Self[p].Y + d[j].Y)))) then
          begin
            v[k] := True;
            q[r.stop.Increase] := k;
          end;
    end;
  end;
end;

{==============================================================================]
 <TPointArray.Groupify>
 @action: Partitions the points in the array into connected groups (clusters)
          based on adjacency. Two points are considered connected if they
          are neighbors according to 4- or 8-connectivity.
 @note: The adjacency method is determined by the 'adjacency8' parameter:
        - True  => 8-connectivity (including diagonals)
        - False => 4-connectivity (orthogonal neighbors only)
        Returns a T2DPointArray where each element is a group of connected points.
        Uses a union-find (disjoint-set) algorithm internally for efficiency.
[==============================================================================}
function TPointArrayHelper.Groupify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  p: TIntegerArray;
  i, j, k, l: Integer;
  d: TPointArray;
  c, n: Integer;
  r, m: TIntegerArray;
  function FindRoot(const x: Integer): Integer;
  begin
    if (p[x] = x) then
      Exit(x);
    p[x] := FindRoot(p[x]);
    Exit(p[x]);
  end;
  procedure Unioned(const x, y: Integer);
  var
    h, v: Integer;
  begin
    h := FindRoot(x);
    v := FindRoot(y);
    if (h <> v) then
      p[v] := h;
  end;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  p := Self.IDs;
  d := Point(0, 0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    for j := 0 to High(d) do
    begin
      k := Self.Pos(Point((Self[i].X + d[j].X), (Self[i].Y + d[j].Y)));
      if (k <> -1) then
        Unioned(i, k);
    end;
  c := 0;
  SetLength(r, l);
  for i := 0 to (l - 1) do
  begin
    r[i] := FindRoot(i);
    if (r[i] = i) then
      Inc(c);
  end;
  SetLength(m, l);
  n := 0;
  for i := 0 to (l - 1) do
    if (r[i] = i) then
      m[i] := n.Increase
    else
      m[i] := m[r[i]];
  SetLength(Result, c);
  for i := 0 to (l - 1) do
  begin
    c := m[r[i]];
    SetLength(Result[c], (Length(Result[c]) + 1));
    Result[c][High(Result[c])] := Self[i];
  end;
end;

{==============================================================================]
 <TPointArray.Groups>
 @action: Partitions the points in the array into connected groups using
          an iterative depth-first search (DFS). Each group is returned as
          a TPointArray within the resulting T2DPointArray.
 @note: adjacency8 = True uses 8-connectivity (diagonals included),
       False uses 4-connectivity (orthogonal neighbors only).
       The function uses a manual stack to avoid recursion.
       Returns a T2DPointArray where each element represents a group of
       connected points.
[==============================================================================}
function TPointArrayHelper.Groups(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  d: TPointArray;
  s: TIntegerArray;
  c, n, g, l, i, j, t: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := Length(Result);
    SetLength(Result, (g + 1));
    SetLength(s, l);
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    while (t) > 0 do
    begin
      c := s[t.Decrement];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := Self[c];
      for j := 0 to High(d) do
        for n := 0 to (l - 1) do
          if ((not v[n]) and (Self[n].X = Self[c].X + d[j].X) and (Self[n].Y = Self[c].Y + d[j].Y)) then
          begin
            v[n] := True;
            s[t.Increase] := n;
          end;
      end;
    end;
end;

{==============================================================================]
 <TPointArray.Grouping>
 @action: Partitions the points in the array into connected groups using a
          recursive depth-first search (DFS). Each group is returned as a 
          separate TPointArray within the resulting T2DPointArray.
 @note: The adjacency method is determined by the 'adjacency8' parameter:
        - True  => 8-connectivity (includes diagonals)
        - False => 4-connectivity (orthogonal neighbors only)
        Returns a T2DPointArray where each element represents a group of 
        connected points.
        Internally uses DFS to traverse and collect all points belonging
        to the same connected component.
[==============================================================================}
function TPointArrayHelper.Grouping(const adjacency8: Boolean = True): T2DPointArray; overload;
  procedure DFS(const arr: TPointArray; const index: Integer; const directions: TPointArray; var visited: TBooleanArray; var group: TPointArray);
  var
    i, j: Integer;
  begin
    visited[index] := True;
    SetLength(group, (Length(group) + 1));
    group[High(group)] := arr[index];
    for i := 0 to High(directions) do
      for j := 0 to High(arr) do
        if (not visited[j]) and (arr[j].X = (arr[index].X + directions[i].X)) and (arr[j].Y = (arr[index].Y + directions[i].Y)) then
          DFS(arr, j, directions, visited, group);
  end;
var
  v: TBooleanArray;
  d: TPointArray;
  i, l: Integer;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    if not v[i] then
    begin
      SetLength(Result, (Length(Result) + 1));
      DFS(Self, i, d, v, Result[High(Result)]);
    end;
end;

{==============================================================================]
 <TPointArrayHelper.Segment>
 @action: Splits TPointArray to groups by radius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload; 
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
        if ((not v[k]) and (distFunc(Self[j], Self[k]) <= radius)) then
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

function TPointArrayHelper.Segment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Segment(radius, @Distance);
end;

{==============================================================================]
 <TPointArrayHelper.Segment>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
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
        if ((not v[k]) and ((Abs(Self[j].X - Self[k].X) <= xRadius) and (Abs(Self[j].Y - Self[k].Y) <= yRadius))) then
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
function TPointArrayHelper.Fragment(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload; 
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
        if ((not v[k]) and (distFunc(Self[j], Self[k]) <= radius)) then
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

function TPointArrayHelper.Fragment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Fragment(radius, @Distance);
end;

{==============================================================================]
 <TPointArrayHelper.Fragment>
 @action: Splits TPointArray to groups by xRadius and yRadius.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
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
        if ((not v[k]) and ((Abs(Self[j].X - Self[k].X) <= xRadius) and (Abs(Self[j].Y - Self[k].Y) <= yRadius))) then
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
 <TPointArrayHelper.XClassify>
 @action: Classifies TPointArray to groups by X-value
 @note: None.
[==============================================================================}
function TPointArrayHelper.XClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
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
function TPointArrayHelper.YClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
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
 <TPointArrayHelper.Axes>
 @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Axes(var X, Y: TIntegerArray): Integer; overload; 
var
  sX, sY, dX, dY: Pointer;
  p, c: SizeInt;
  i: Integer;
begin
  Result := Length(Self);
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
 <TPointArrayHelper.Axed>
 @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Axed: T2DIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, 2, Length(Self));
  for i := 0 to High(Self) do
  begin
    Result[0][i] := Self[i].X;
    Result[1][i] := Self[i].Y;
  end;
end;

{==============================================================================]
 <TPointArrayHelper.Axed>
 @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
 @note: None.
[==============================================================================}
function TPointArrayHelper.Axed(var X, Y: TIntegerArray): Integer; overload; 
var
  i: Integer;
begin
  Result := Length(Self);
  specialize SetSize<Integer>(X, Y, Result);
  for i := 0 to High(Self) do
  begin
    X[i] := Self[i].X;
    Y[i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all TPoint elements to (0,0), while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Reinit: Integer; 
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(TPoint)), 0);
end;

{==============================================================================]
  <TPointArrayHelper.SortByRow>
  @action: Sorts array Row-by-Row.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByRow(const aAscending: Boolean = True): Integer; overload; 
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Length(Self);
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[(Self[i].X - b.X1)][(Self[i].Y - b.Y1)]);
	case aAscending of
	  True:
      for y := 0 to (b.Y2 - b.Y1) do
        for x := 0 to (b.X2 - b.X1) do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := 0 to (c[x][y] - 1) do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	  False:
      for y := (b.Y2 - b.Y1) downto 0 do
        for x := (b.X2 - b.X1) downto 0 do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := (c[x][y] - 1) downto 0 do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	end;
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <TPointArrayHelper.SortByColumn>
  @action: Sorts array Column-by-Column.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByColumn(const aAscending: Boolean = True): Integer; overload; 
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Length(Self);
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[(Self[i].X - b.X1)][(Self[i].Y - b.Y1)]);
	case aAscending of
	  True:
      for x := 0 to (b.X2 - b.X1) do
        for y := 0 to (b.Y2 - b.Y1) do
          if (c[x][y] > 0) then
          begin
            for i := 0 to (c[x][y] - 1) do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
	  False:
      for x := (b.X2 - b.X1) downto 0 do
        for y := (b.Y2 - b.Y1) downto 0 do
          if (c[x][y] > 0) then
          begin
            for i := (c[x][y] - 1) downto 0 do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
    end;		  
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <TPointArrayHelper.SortedByIndex>
  @action: Returns array sorted by indexes in array bounding box.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SortedByIndex(const aAscending: Boolean = True): TPointArray; overload; 
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    Result := Self.QuickSorted(Self.Bounds.IDs(Self), aAscending);
end;

{==============================================================================]
  <TPointArrayHelper.Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since TPoint is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TPointArrayHelper.Attach(const items: TPointArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  i := Length(items);
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(TPoint)));
end;

{==============================================================================]
  <TPointArrayHelper.Embed>
  @action: Inserts the contents of another TPoint array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TPointArrayHelper.Embed(const items: TPointArray; const index: Integer = 2147483647): Integer; overload;
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
    Move(Self[p], Self[p + l], (t * SizeOf(TPoint)));
  Move(items[0], Self[p], (l * SizeOf(TPoint)));
  Result := Length(Self);
end;

{==============================================================================]
  <TPointArrayHelper.FrameLinks>
  @action: For each point in the array that lies within the given area, generates
           a “frame” around the point (a box of size determined by dist) and a
           vertical line from the point to the top of the box. Returns a new
           TPointArray containing all these border and line points.
  @note:   Uses the Attach helper to efficiently append points. The size of the
           resulting array depends on the borders of all valid points. Points
           outside the area are ignored.
[==============================================================================}
function TPointArrayHelper.FrameLinks(const dist: Integer; const area: TBox): TPointArray; overload;
var
  b: TBox;
  i: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
    if area.Contains(Self[i]) then
    begin
      b.Create(Max(area.X1, (Self[i].X - dist)), Max(area.Y1, (Self[i].Y - dist)), Min(area.X2, (Self[i].X + dist)), Min(area.Y2, (Self[i].Y + dist)));
      Result.Attach(b.Border);
      Result.Attach(Self[i].ToY(b.Y1 + 1));
    end;
end;

function TPointArrayHelper.FrameLinks(const dist: Integer = 1): TPointArray; overload;
begin
  Result := Self.FrameLinks(dist, Self.Bounds);
end;

{==============================================================================]
  <TPointArray.XVals>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].X, aAscending);
end;

{==============================================================================]
  <TPointArray.YVals>
  @action:  Returns an array of all Y coordinates from the point array,
            optionally sorted in ascending or descending order.
  @note:    Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].Y, aAscending);
end;

{==============================================================================]
  <TPointArray.XArr>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Xs.QuickSorted(aAscending);
end;

{==============================================================================]
  <TPointArray.YArr>
  @action: Returns an array of all Y coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Ys.QuickSorted(aAscending);
end;

{==============================================================================]
 <TPointArray.XAxis>
 @action: Extracts all X-coordinate values from the point array.
 @note: When rUnique = True, the resulting array is sorted and contains
        only unique X values (duplicates removed).
        When rUnique = False, all X values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
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
 <TPointArray.YAxis>
 @action: Extracts all Y-coordinate values from the point array.
 @note: When rUnique = True, the resulting array is sorted and contains
        only unique Y values (duplicates removed).
        When rUnique = False, all Y values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
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
 <TPointArray.X2D>
 @action: Groups all X-coordinates by their corresponding Y-coordinate.
 @note: Returns 2D array of X values where Result[i] contains all X's for Y = yArr[i].
   - The output parameter yArr receives the sorted list of unique Y values.
   - If no points exist, Result = [].
   - If only one Y value exists, Result = [yArr].
   - When xOrder = True (default), X values are inserted in sorted order
     using BinaryAppend.
   - The xAscending flag determines the sorting direction when xOrder = True.
     (True = ascending, False = descending)
   - When xOrder = False, X values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  yArr := Self.YAxis;
  l := Length(yArr);
  case l of
    0: Exit([]);
    1: Exit([yArr]);
  end;
  SetLength(Result, Length(yArr));
  case xOrder of 
    True:
    for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].BinaryAppend(Self[i].X, xAscending);
	False:
	for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].Supply(Self[i].X);
  end;
end;

{==============================================================================]
 <TPointArray.Y2D>
 @action: Groups all Y-coordinates by their corresponding X-coordinate.
 @note: Returns 2D array of Y values where Result[i] contains all Y's for X = xArr[i].
   - The output parameter xArr receives the sorted list of unique X values.
   - If no points exist, Result = [].
   - If only one X value exists, Result = [xArr].
   - When yOrder = True (default), Y values are inserted in sorted order
     using BinaryAppend.
   - The yAscending flag determines the sorting direction when yOrder = True.
     (True = ascending, False = descending)
   - When yOrder = False, Y values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  xArr := Self.XAxis;
  l := Length(xArr);
  case l of
    0: Exit([]);
    1: Exit([xArr]);
  end;
  SetLength(Result, Length(xArr));
  case yOrder of
    True:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].BinaryAppend(Self[i].Y, yAscending);
    False:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].Supply(Self[i].Y);
  end;
end;

{==============================================================================]
 <TPointArray.Blobs>
 @action: Groups the points in the array into contiguous spatial clusters ("blobs")
          based on the specified xRadius and yRadius. Each blob is a TPointArray
          containing points that are all within the proximity ranges of each other.
 @note: Uses a breadth-first search style traversal combined with binary range
        searches on sorted X/Y arrays for efficiency. The result is a T2DPointArray,
        where each element represents a blob. Empty or single-element arrays are
        handled specially. This method may allocate intermediate arrays.
[==============================================================================}
function TPointArrayHelper.Blobs(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, s, g, t, z, l: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < Length(q)) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if ((r.start = -1) or (r.stop = -1)) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if ((c.start = -1) or (c.stop = -1)) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to l - 1 do
            if ((Self[z].X = n.X) and (Self[z].Y = n.Y)) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            SetLength(q, (Length(q) + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Length(Result[g]) > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, p, g, t, z, l, d: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < Length(q)) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if ((r.start = -1) or (r.stop = -1)) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if ((c.start = -1) or (c.stop = -1)) then
	      Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if ((Self[z].X = n.X) and (Self[z].Y = n.Y)) then
	      Break;
          if ((z < l) and (not m[z]) and (distFunc(a, n) <= radius)) then
          begin
            m[z] := True;
            SetLength(q, (Length(q) + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Length(Result[g]) > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobs(radius, @Euclidean);
end;

{==============================================================================]
 <TPointArray.Blobify>
 @action: Similar to Blobs, but optimized with a pre-allocated queue to reduce
          repeated memory allocations. Groups the points into spatially connected
          blobs based on xRadius and yRadius.
 @note: Uses a breadth-first traversal combined with binary range searches on
        sorted X/Y arrays. Internal queue is pre-sized for better performance.
        Returns a T2DPointArray of blobs. Handles empty or single-element arrays
        correctly. Consider using this version when processing large point sets
        for efficiency.
[==============================================================================}
function TPointArrayHelper.Blobify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, s, g, t, z, l: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    k.Create(0, 1);
    q[0] := Self[i];
    m[i] := True;
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if ((r.start = -1) or (r.stop = -1)) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if ((c.start = -1) or (c.stop = -1)) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if ((Self[z].X = n.X) and (Self[z].Y = n.Y)) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Length(Result[g]) > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double; const distFunc: TDistanceFunction): T2DPointArray; overload;
var
  i, j, p, g, z, l, d: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Length(Self);
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, (l * 2));
    q[0] := Self[i];
    m[i] := True;
    k.Create(0, 1);
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Length(Result[g]) + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if ((r.start = -1) or (r.stop = -1)) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if ((c.start = -1) or (c.stop = -1)) then
		  Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if ((Self[z].X = n.X) and (Self[z].Y = n.Y)) then
              Break;
          if ((z < l) and (not m[z]) and (distFunc(a, n) <= radius)) then
          begin
            m[z] := True;
            if (k.stop >= Length(q)) then
              SetLength(q, (Length(q) * 2));
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Length(Result[g]) > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobify(radius, @Euclidean);
end;

{==============================================================================]
 <TPointArray.YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted Y values.
 @note: The Y values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Length(Self);
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := Length(xArr);
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
      begin
        Result[i][k] := Self[j].Y;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);	
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <TPointArray.YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Length(Self);
  SetLength(xArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := Length(xArr);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Result[i][k.Increase] := Self[j].Y;
  end;
end;

{==============================================================================]
 <TPointArray.XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted X values.
 @note: The X values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Length(Self);
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := Length(yArr);
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
      begin
        Result[i][k] := Self[j].X;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <TPointArray.XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Length(Self);
  SetLength(yArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := Length(yArr);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Result[i][k.Increase] := Self[j].X;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.YAs2D>
  @action: Groups Y-coordinates by unique X values and sorts each Y-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Result[i][*] = sorted Y values for X = xArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g, d: specialize TDictionary<Integer, specialize TList<Integer>>;
  y, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
        d.Add(Self[i].X, p);
      end else
        p := d[Self[i].X];
      y.Add(Self[i].Y);
      p.Add(i);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      p := d[k];
      y.Sort;
      SetLength(Result[i], y.Count);
      SetLength(selfIDs[i], y.Count);
      for j := 0 to (y.Count - 1) do
      begin
        Result[i][j] := y[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for y in g.Values do
      y.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.YAs2D>
  @action: Groups Y-coordinates by unique X values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Order of Y values matches original point order.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  y: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
      end;
      y.Add(Self[i].Y);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      Result[i.Increase] := y.ToArray;
    end;
  finally
    for y in g.Values do
      y.Free;
    g.Free;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.XAs2D>
  @action: Groups X-coordinates by unique Y values and sorts each X-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Result[i][*] = sorted X values for Y = yArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  x, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
        d.Add(Self[i].Y, p);
      end else
        p := d[Self[i].Y];
      x.Add(Self[i].X);
      p.Add(i);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      p := d[k];
      x.Sort;
      SetLength(Result[i], x.Count);
      SetLength(selfIDs[i], x.Count);
      for j := 0 to (x.Count - 1) do
      begin
        Result[i][j] := x[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for x in g.Values do
      x.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <TPointArrayHelper.XAs2D>
  @action: Groups X-coordinates by unique Y values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Order of X values matches original point order.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  x: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
      end;
      x.Add(Self[i].X);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      Result[i.Increase] := x.ToArray;
    end;
  finally
    for x in g.Values do
      x.Free;
    g.Free;
  end;
end;

{==============================================================================]
  <TPointArray.DBSCAN>
  @action: Performs density-based clustering on a TPointArray using a fixed
           radius and custom distance function.
  @params:
    radius   - The maximum distance between points to be considered neighbors.
    minPts   - Minimum number of points required to form a dense region (core point).
    distFunc - Function used to compute distance between two TPoints.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Points not belonging to any cluster are ignored (treated as noise).
[==============================================================================}
function TPointArrayHelper.DBSCAN(const radius: Double; const minPts: Integer; const distFunc: TDistanceFunction): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and (distFunc(Self[index], Self[i]) <= radius)) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (Length(r) < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < Length(r)) do
    begin
      n := RegionQuery(r[i]);
      if (Length(n) >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  s := Length(Self);
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;

{==============================================================================]
  <TPointArray.DBSCAN>
  @action: Convenience overload that performs DBSCAN using standard Euclidean
           distance.
  @params:
    radius - Maximum neighbor distance.
    minPts - Minimum number of points to form a cluster.
  @returns: T2DPointArray of clusters.
  @note: Internally calls the main DBSCAN method with Euclidean distance.
[==============================================================================}
function TPointArrayHelper.DBSCAN(const radius: Double; const minPts: Integer): T2DPointArray; overload;
begin
  Result := Self.DBSCAN(radius, minPts, @Euclidean);
end;

{==============================================================================]
  <TPointArray.DBSCAN>
  @action: Performs density-based clustering using separate X and Y radii,
           allowing anisotropic neighborhoods.
  @params:
    xRadius - Maximum horizontal distance to consider points neighbors.
    yRadius - Maximum vertical distance to consider points neighbors.
    minPts  - Minimum number of points to form a cluster.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Useful for clustering pixel-based data or TPAs where horizontal and
         vertical spacing differs. Rectangular neighborhood used for efficiency.
[==============================================================================}
function TPointArrayHelper.DBSCAN(const xRadius, yRadius: Integer; const minPts: Integer): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  function InRange(const A, B: TPoint): Boolean;
  begin
    Result := ((Abs(A.X - B.X) <= xRadius) and (Abs(A.Y - B.Y) <= yRadius));
  end;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and InRange(Self[index], Self[i])) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (Length(r) < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < Length(r)) do
    begin
      n := RegionQuery(r[i]);
      if (Length(n) >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  s := Length(Self);
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;

{$UNDEF TPoint}
