{$IFDEF HELPERS}
function FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload;
function FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <FloodFill>
  @action:: Outputs Flood Filled points from TPointArray or non-TPointArray points inside an area,
            starting from start, based on FloodFill() action.
            Supports custom area by area as TBox.
  note: Make sure start is inside your area. Doesn't pay attention to ANYTHING outside area. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; 
var
  l, i, w, h, x, y, f, r: Integer;
  q, a: TPointArray;
  p: TPoint;
  c, z: T2DBooleanArray;
  o, s: Boolean;
begin
  r := 0;
  l := Self.Length;
  if ((l > 0) and area.Contains(start)) then
  begin
    o := False;
    area.Size(w, h);
    c := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
    begin
      if not o then
        o := (start = Self[i]);
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
      q[l].Adjacent(a, scan8W);
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
  <FloodFill>
  @action: Outputs Flood Filled points from TPointArray or non-TPointArray points inside arr Bounds,
           starting from start, based on FloodFill() action.
  @note: Make sure start is inside TPA Bounds.
         Doesn't pay attention to ANYTHING outside those boundaries. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; 
begin
  Result := Self.FloodFill(start, Self.Bounds, scan8W);
end;
{$ENDIF}
