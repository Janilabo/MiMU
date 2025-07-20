{==============================================================================]
  <TPointArrayHelper.Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Bounds: TBox; overload; cdecl;
var
  i: Integer;
begin
  if (High(Self) = -1) then
    Exit(Box(-2147483648));
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
  case (High(Self) = -1) of
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
  i, r, l, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  l := Length(Self);
  if (l > 0) then
  begin
    b := Self.Bounds(w, h);
    m := T2D.Create(False, w, h);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Result[r.Increase] := Self[i];
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TPointArrayHelper.Invert>
  @action: Returns arr without duplicates.
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
