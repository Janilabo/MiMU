{$IFDEF HELPERS}
function Edge(const scan8W: Boolean = False): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Edge>
  @action: Returns with all the edge-points from arr.
           Supports both, 4-way and 8-way direction scanning styles.
  @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArrayHelper.Edge(const scan8W: Boolean = False): TPointArray; overload;
var
  i, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  if (Self.Length > 4) then
  begin
    b := Self.Bounds;
    b := b.Expand;
    b.Size(w, h);
    m := T2D.Create(False, w, h);
    for i := 0 to High(Self) do
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
{$ENDIF}
