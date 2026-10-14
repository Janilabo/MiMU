{$IFDEF HELPERS}
function BinaryClosestPair(var A, B: TPoint): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryClosestPair>
  @action: Finds the closest pair of points in the point array using binary range searching,
           returning the distance as the function result and the two points via parameters A and B.
  @note: Uses an optimized spatial indexing approach with sorted 2D coordinate arrays and binary range lookups,
         to efficiently find the closest pair, avoiding O(N^2) brute-force complexity.
[==============================================================================}
function TPointArrayHelper.BinaryClosestPair(var A, B: TPoint): Double; overload;
var
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  l, i, j, r, k, w, p, q: Integer;
  x, y: TRange;
  s, d: TPoint;
  o, e: Int64;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(-1);
  h := Self.XTo2D(v, z);
  o := High(Int64);
  p := -1;
  for r := 0 to High(h) do
    for j := 0 to High(h[r]) do
    begin
      q := z[r][j];
      if (p <> -1) then
      begin
        d := Point((Self[q].X - Self[p].X), (Self[q].Y - Self[p].Y));
        e := ((d.X * d.X) + (d.Y * d.Y));
        if (e < o) then
        begin
          o := e;
          A := Self[p];
          B := Self[q];
        end;
      end;
      p := q;
    end;
  for i := 0 to (l - 1) do
  begin
    if (o = 0) then
      Break;
    s := Self[i];
    k := Trunc(Sqrt(o));
    y := v.BinaryRange(TRange.Construct((s.Y - k), (s.Y + k)));
    if y.Employs(-1) then
      Continue;
    for r := y.start to y.stop do
    begin
      d.Y := (v[r] - s.Y);
      if ((d.Y * d.Y) >= o) then
        Continue;
      w := Trunc(Sqrt(o - (d.Y * d.Y)));
      x := h[r].BinaryRange(TRange.Construct((s.X - w), (s.X + w)));
      if not x.Employs(-1) then
      for j := x.start to x.stop do
        if not (z[r][j] = i) then
        begin
          d.X := (h[r][j] - s.X);
          e := ((d.X * d.X) + (d.Y * d.Y));
          if (e < o) then
          begin
            o := e;
            A := s;
            B := Self[z[r][j]];
          end;
        end;
    end;
  end;
  Result := Sqrt(o);
end;
{$ENDIF}
