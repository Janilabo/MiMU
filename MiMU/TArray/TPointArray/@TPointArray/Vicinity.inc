{$IFDEF HELPERS}
function ClosestPair(var A, B: TPoint): Double; overload;
function ClosestPoints(var A, B: TPoint): Double; overload;
function NearestPair(var A, B: TPoint): Double; overload;
function NearestPoints(var A, B: TPoint): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ClosestPair>
  @action: Finds the closest pair of points in the point array using an optimized recursive divide-and-conquer algorithm,
           with integrated merge sort, returning the minimum distance and setting points A and B.
  @note: Operates in O(N log N) time complexity. Pre-allocates scratch buffers,
         and maintains Y-order during recursion to avoid repeated sorting overhead.
[==============================================================================}
function TPointArrayHelper.ClosestPair(var A, B: TPoint): Double; overload;
var
  r, t, c: TPointArray;
  l: Integer;
  o: Int64;
  procedure D(const p, q: TPoint);
  var
    e, h, v: Int64;
  begin
    h := (p.X - q.X);
    v := (p.Y - q.Y);
    e := ((h * h) + (v * v));
    if (e < o) then
    begin
      o := e;
      A := p;
      B := q;
    end;
  end;
  procedure S(const lo, hi: Integer);
  var
    i, j, k, n, m, z: Integer;
    p: TPoint;
    h, v: Int64;
  begin
    if ((hi - lo) <= 3) then
    begin
      for i := lo to (hi - 1) do
        for j := (i + 1) to (hi - 1) do
          D(r[i], r[j]);
      for i := (lo + 1) to (hi - 1) do
      begin
        p := r[i];
        j := (i - 1);
        while ((j >= lo) and (r[j].Y > p.Y)) do
        begin
          r[j + 1] := r[j];
          Dec(j);
        end;
        r[j + 1] := p;
      end;
      Exit;
    end;
    m := ((lo + hi) shr 1);
    z := r[m].X;
    S(lo, m);
    S(m, hi);
    i := lo;
    j := m;
    k := lo;
    while ((i < m) and (j < hi)) do
      if (r[i].Y <= r[j].Y) then
        t[k.Increase] := r[i.Increase]
      else
        t[k.Increase] := r[j.Increase];
    while (i < m) do
      t[k.Increase] := r[i.Increase];
    while (j < hi) do
      t[k.Increase] := r[j.Increase];
    for i := lo to (hi - 1) do
      r[i] := t[i];
    n := 0;
    for i := lo to (hi - 1) do
    begin
      h := (r[i].X - z);
      if ((h * h) < o) then
      begin
        for j := (n - 1) downto 0 do
        begin
          v := (r[i].Y - c[j].Y);
          if ((v * v) >= o) then
            Break;
          D(c[j], r[i]);
        end;
        c[n.Increase] := r[i];
      end;
    end;
  end;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(-1);
  r := Self.Copy;
  r.QuickSortByYX(True);
  SetLength(t, l);
  SetLength(c, l);
  o := High(Int64);
  S(0, l);
  Result := Sqrt(o);
end;

{==============================================================================]
  <ClosestPoints>
  @action: Analyze, document, and evaluate the algorithm for finding the closest pair of points in a TPointArray.
  @note: Implements an optimized grid-based spatial search to find the minimum distance between any two points in the array,
         returning the distance as a Double and assigning the two points to the var parameters A and B.
[==============================================================================}
function TPointArrayHelper.ClosestPoints(var A, B: TPoint): Double; overload;
var
  g: T2DIntegerArray;
  x, y: TRange;
  s, i, k, r, w, h, m, o, q: Integer;
  z, e: Int64;
  c, t, d, p: TPoint;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(-1);
  Self.Survey(x, y);
  w := ((x.stop - x.start) + 1);
  h := ((y.stop - y.start) + 1);
  SetLength(g, w, h);
  for i := 0 to (s - 1) do
  begin
    c.X := (Self[i].X - x.start);
    c.y := (Self[i].Y - y.start);
    if (g[c.X][c.Y] <> 0) then
    begin
      A := Self[g[c.X][c.Y] - 1];
      B := Self[i];
      Exit(0);
    end;
    g[c.X][c.Y] := (i + 1);
  end;
  z := High(Int64);
  m := Max(w, h);
  for i := 0 to (s - 1) do
  begin
    t := Self[i];
    c.X := (t.X - x.start);
    c.Y := (t.Y - y.start);
    r := 1;
    while ((r <= m) and ((Int64(r) * r) < z)) do
    begin
      for q := Max(0, (c.Y - r)) to Min((h - 1), (c.Y + r)) do
      begin
        if (Abs(q - c.Y) = r) then
          k := 1
        else
          k := (2 * r);
        o := (c.X - r);
        while (o <= (c.X + r)) do
        begin
          if ((o >= 0) and (o < w) and (g[o][q] <> 0)) then
          begin
            e := (Sqr(o - c.X) + Sqr(q - c.Y));
            if (e < z) then
            begin
              z := e;
              A := t;
              B := Self[g[o][q] - 1];
            end;
          end;
          Inc(o, k);
        end;
      end;
      Inc(r);
    end;
  end;
  Result := Sqrt(z);
end;

{==============================================================================]
  <NearestPair>
  @action: Finds the closest pair of points in the point array using a brute-force search,
           returning the distance as the function result and the two points via parameters A and B.
  @note: Uses a straightforward O(N^2) double-loop algorithm.
         Best suited for small point arrays where avoiding the overhead of sorting or spatial indexing is preferred.
[==============================================================================}
function TPointArrayHelper.NearestPair(var A, B: TPoint): Double; overload;
var
  i, j, l: Integer;
  d: TPoint;
  e, o: Int64;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(-1);
  o := High(Int64);
  for i := 0 to (l - 2) do
  begin
    for j := (i + 1) to (l - 1) do
    begin
      d := Point((Self[j].X - Self[i].X), (Self[j].Y - Self[i].Y));
      e := ((Int64(d.X) * d.X) + (Int64(d.Y) * d.Y));
      if (e < o) then
      begin
        o := e;
        A := Self[i];
        B := Self[j];
      end;
    end;
  end;
  Result := Sqrt(o);
end;

{==============================================================================]
  <NearestPoints>
  @action: Finds the closest pair of points in the point array using a sweep-line algorithm,
           returning the distance as the function result and the two points via parameters A and B.
  @note: First sorts the array using QuickSortByXY, then maintains a sliding window of active points based on X coordinates,
         achieving an O(N log N) time complexity with low overhead.
[==============================================================================}
function TPointArrayHelper.NearestPoints(var A, B: TPoint): Double; overload;
var
  i, j, l, c: Integer;
  s: TPointArray;
  m, d, v: Int64;
  p1, p2: TPoint;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(-1);
  s := Self.Copy;
  s.QuickSortByXY(True);
  m := High(Int64);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    while ((c < i) and (Sqr(Int64(s[i].X - s[c].X)) >= m)) do
      Inc(c);
    for j := c to (i - 1) do
    begin
      v := Sqr(s[i].Y - s[j].Y);
      if (v >= m) then
        Continue;
      d := (Sqr(s[i].X - s[j].X) + v);
      if (d < m) then
      begin
        m := d;
        A := s[j];
        B := s[i];
      end;
    end;
  end;
  Result := Sqrt(m);
end;
{$ENDIF}
