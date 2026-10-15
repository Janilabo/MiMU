{$IFDEF HELPERS}
function BinaryClosestPair(var A, B: TPoint): Double; overload;
function BisectClosestPair(var A, B: TPoint): Double; overload;
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

{==============================================================================]
  <BisectClosestPair>
  @action: Finds the closest pair of points in the point array using binary search (bisection) over the squared distance space,
           returning the minimum distance and setting points A and B.
  @note: Uses a bisection (binary search) strategy on the distance range combined with 2D spatial index lookups (XTo2D, BinaryRange)
         to efficiently test whether a closer pair exists within a given squared distance threshold.
[==============================================================================}
function TPointArrayHelper.BisectClosestPair(var A, B: TPoint): Double; overload;
var
  n, z: T2DIntegerArray;
  v: TIntegerArray;
  s: Integer;
  l, h, m: Int64;
  function O(const n: Int64): Integer;
  begin
    Result := Trunc(Sqrt(n));
    while ((Int64(Result) * Result) > n) do
      Dec(Result);
    while ((Int64(Result + 1) * (Result + 1)) <= n) do
      Inc(Result);
  end;
  function G(const D: Int64): Boolean;
  var
    p, j, k, w, f: Integer;
    x, y: TRange;
    t: TPoint;
    q: Int64;
  begin
    k := O(D);
    for p := 0 to (s - 1) do
    begin
      t := Self[p];
      y := v.BinaryRange(TRange.Construct((t.Y - k), (t.Y + k)));
      if not y.Employs(-1) then
      for f := y.start to y.stop do
      begin
        q := (Int64(v[f]) - t.Y);
        q := (D - (q * q));
        if (q < 0) then
          Continue;
        w := O(q);
        x := n[f].BinaryRange(TRange.Construct((t.X - w), (t.X + w)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if (z[f][j] <> p) then
          begin
            A := t;
            B := Self[z[f][j]];
            Exit(True);
          end;
      end;
    end;
    Result := False;
  end;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(-1);
  n := Self.XTo2D(v, z);
  h := (Sqr((Int64(Self[1].X) - Self[0].X) + Sqr(Int64(Self[1].Y) - Self[0].Y)));
  l := 0;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if G(m) then
      h := m
    else
      l := (m + 1);
  end;
  G(l);
  Result := Sqrt(l);
end;
{$ENDIF}
