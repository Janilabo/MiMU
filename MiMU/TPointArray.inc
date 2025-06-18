{==============================================================================]
  <TPointArray_Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArray_Bounds(const arr: TPointArray): TBox; overload; cdecl;
var
  i: Integer;
begin
  if (High(arr) = -1) then
    Exit(TBox_Form(-2147483648));
  Result := TBox_At(arr[0]);
  for i := 1 to High(arr) do
  begin
    if (arr[i].X < Result.X1) then
      Result.X1 := arr[i].X
    else
      if (arr[i].X > Result.X2) then
        Result.X2 := arr[i].X;
    if (arr[i].Y < Result.Y1) then
      Result.Y1 := arr[i].Y
    else
      if (arr[i].Y > Result.Y2) then
        Result.Y2 := arr[i].Y;
  end;
end;

{==============================================================================]
  <TPointArray_Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: Stores width and height of bounds to width and height variables.
[==============================================================================}
function TPointArray_Bounds(const arr: TPointArray; var width, height: Integer): TBox; overload; cdecl;
begin
  case (High(arr) = -1) of
    False:
	begin
	  Result := TPointArray_Bounds(arr);
	  TBox_Size(Result, width, height);
	end;
    True:
	begin
      Result := TBox_Form(-2147483648);
	  width := 0;
	  height := 0;
	end;
  end;
end;

{==============================================================================]
  <TPointArray_Unique>
  @action: Removes duplicates from arr.
  @note: Returns number of duplicate items that were removed from arr.
[==============================================================================}
function TPointArray_Unique(var arr: TPointArray): Integer; cdecl;
var
  i, r, l, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Length(arr);
  if (l > 1) then
  begin
    r := 0;
    b := TPointArray_Bounds(arr, w, h);
    m := T2DArray_Create(w, h, False);
    for i := 0 to (l - 1) do
	  if m[(arr[i].X - b.X1)][(arr[i].Y - b.Y1)].Enable then
        arr[r.Increase] := arr[i];
    SetLength(arr, r);
    SetLength(m, 0);
  end;
  Result := (l - Length(arr));
end;

{==============================================================================]
  <TPointArray_Uniqued>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArray_Uniqued(const arr: TPointArray): TPointArray; cdecl;
var
  i, r, l, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  l := Length(arr);
  if (l > 0) then
  begin
    b := TPointArray_Bounds(arr, w, h);
	m := T2DArray_Create(w, h, False);
	SetLength(Result, l);
    for i := 0 to (l - 1) do
      if m[(arr[i].X - b.X1)][(arr[i].Y - b.Y1)].Enable then
        Result[r.Increase] := arr[i];
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <TPointArray_Uniqued>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArray_Invert(const arr: TPointArray): TPointArray; cdecl;
var
  i, x, y, w, h, r, l: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if (High(arr) > 0) then
  begin
    b := TPointArray_Bounds(arr, w, h);
	m := T2DArray_Create(w, h, False);
    x := 0;
    for i := 0 to High(arr) do
      if m[(arr[i].X - b.X1)][(arr[i].Y - b.Y1)].Enable then
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
 <TPointArray_Edge>
 @action: Returns with all the edge-points from arr.
          Supports both, 4-way and 8-way direction scanning styles.
 @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArray_Edge(const arr: TPointArray; const scan8W: Boolean = False): TPointArray; cdecl;
var
  i, l, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Length(arr);
  if (l > 4) then
  begin
    b := TBox_Expand(TPointArray_Bounds(arr));
    TBox_Size(b, w, h);
    m := T2DArray_Create(w, h, False);
    for i := 0 to (l - 1) do
      m[(arr[i].X - b.X1)][(arr[i].Y - b.Y1)] := True;
    SetLength(Result, (w * h));
    w := (w - 2);
    h := (h - 2);
    r := 0;
    case scan8W of
      False:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[(x - 1)][y] and m[x][(y - 1)] and m[(x + 1)][y] and m[x][(y + 1)])) then
		    Result[r.Increase].Create((x + b.X1), (y + b.Y1));
      True:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[(x - 1)][y] and m[x][(y - 1)] and m[(x + 1)][y] and m[x][(y + 1)] and m[(x - 1)][(y - 1)] and m[(x - 1)][(y + 1)] and m[(x + 1)][(y - 1)] and m[(x + 1)][(y + 1)])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    end;
    SetLength(Result, r);
    SetLength(m, 0);
  end else
    Result := Copy(arr, 0, Length(arr));
end;

{==============================================================================]
  <TPointArray_FloodFill
  @action:: Outputs Flood Filled points from TPointArray or non-TPointArray points inside an area,
            starting from start, based on FloodFill() action.
            Supports custom area by area as TBox.
  note: Make sure start is inside your area. Doesn't pay attention to ANYTHING outside area. :)
[==============================================================================}
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
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
  l := Length(arr);
  if ((l > 0) and ((start.X >= area.X1) and (start.Y >= area.Y1) and (start.X <= area.X2) and (start.Y <= area.Y2))) then
  begin
    o := False;
    TBox_Size(area, w, h);
	c := T2DArray_Create(w, h, False);
    for i := 0 to (l - 1) do
    begin
      if not o then
        o := ((start.X = arr[i].X) and (start.Y = arr[i].Y));
      if (((arr[i].X - area.X1) > -1) and ((arr[i].Y - area.Y1) > -1) and ((arr[i].Y - area.Y1) < h) and ((arr[i].X - area.X1) < w)) then
        c[(arr[i].X - area.X1)][(arr[i].Y - area.Y1)] := True;
    end;
    s := not o;
    if scan8W then
      f := 7
    else
      f := 3;
    SetLength(a, (f + 1));
    SetLength(q, (w * h));
	z := T2DArray_Create(w, h, False);
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
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;
begin
  Result := TPointArray_FloodFill(arr, start, TPointArray_Bounds(arr), scan8W);
end;
