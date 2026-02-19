{$IFDEF HELPERS}
function BCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function BCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Cluster(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Cluster(const radius: Double = 1.0): T2DPointArray; overload;
function Cluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Clustered(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Clustered(const radius: Double = 1.0): T2DPointArray; overload;
function Clustered(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Clusterify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Clusterify(const radius: Double = 1.0): T2DPointArray; overload;
function Clusterify(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Clusterize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Clusterize(const radius: Double = 1.0): T2DPointArray; overload;
function Clusterize(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Clusters(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Clusters(const radius: Double = 1.0): T2DPointArray; overload;
function Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
function RCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
function RCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function ProximityCluster(const xRadius, yRadius: Integer; const method: Integer = 0): T2DPointArray; overload;
function ProximityCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const method: Integer = 0): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BCluster>
  @action: Performs radius-based clustering using binary search.
           Each point is assigned to a cluster based on proximity.
  @params: -radius: Maximum distance for points to be considered neighbors.
           -metric: Distance metric (Chebyshev, Euclidean, Manhattan, etc.)
  @result: T2DPointArray where each subarray contains points of one cluster
[==============================================================================}
function TPointArrayHelper.BCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  h, z: T2DIntegerArray;
  d, l, i, j, r, g: Integer;
  x, y, s: TRange;
  t: TPoint;
  c, q, p, v: TIntegerArray;
  procedure Enqueue(const index: Integer);
  begin
    q[s.stop.Increment] := index;
    c[index] := g;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  SetLength(c, l);
  for i := 0 to (l - 1) do
    c[i] := -1;
  h := Self.XTo2D(v, z);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if (c[i] <> -1) then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    c[i] := g;
    while (s.start <= s.stop) do
    begin
      t := Self[q[s.start.Increase]];
      y := v.BinaryRange(TRange.Construct((t.Y - d), (t.Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((t.X - d), (t.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((c[z[r][j]] = -1) and t.Within(Self[z[r][j]], radius, metric)) then
            Enqueue(z[r][j]);
      end;
    end;
    Inc(g);
  end;
  SetLength(p, g);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Inc(p[c[i]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], p[i]);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Result[c[i]][p[c[i]].Increase] := Self[i];
end;

{==============================================================================]
  <BCluster>
  @action: Performs radius-based clustering using binary search.
           Each point is assigned to a cluster based on proximity.
  @params: -radius: Maximum distance for points to be considered neighbors.
           -metric: Distance metric (Chebyshev, Euclidean, Manhattan, etc.)
  @result: T2DPointArray where each subarray contains points of one cluster
[==============================================================================}
function TPointArrayHelper.BCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  h, z: T2DIntegerArray;
  l, i, j, r, g: Integer;
  x, y, s: TRange;
  t: TPoint;
  c, q, p, v: TIntegerArray;
  procedure Enqueue(const index: Integer);
  begin
    q[s.stop.Increment] := index;
    c[index] := g;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(c, l);
  for i := 0 to (l - 1) do
    c[i] := -1;
  h := Self.XTo2D(v, z);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if (c[i] <> -1) then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    c[i] := g;
    while (s.start <= s.stop) do
    begin
      t := Self[q[s.start.Increase]];
      y := v.BinaryRange(TRange.Construct((t.Y - yRadius), (t.Y + yRadius)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((t.X - xRadius), (t.X + xRadius)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((c[z[r][j]] = -1) and t.Within(Self[z[r][j]], xRadius, yRadius)) then
            Enqueue(z[r][j]);
      end;
    end;
    Inc(g);
  end;
  SetLength(p, g);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Inc(p[c[i]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], p[i]);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Result[c[i]][p[c[i]].Increase] := Self[i];
end;

{==============================================================================]
  <Cluster>
  @action: Groups the points in the array into clusters based on a given distance threshold.
  @note: Uses a grid-based breadth-first search (BFS) approach; points are added to a cluster
         if their distance from any member is less than or equal to radius.
		 Supports custom distance functions via distFunc (default is Euclidean).
[==============================================================================}
function TPointArrayHelper.Cluster(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
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
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  b := Self.Bounds(w, h);
  d := Max(0, radius);
  c := Ceil(d);
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (g[n.X][n.Y].Size + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or g[n.X][n.Y].Empty) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
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
              SetLength(Result[r], (Result[r].Size + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (q.Size + 1));
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
    if (Result[r].Size > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Cluster(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Cluster(radius, @Euclidean);
end;

{==============================================================================]
  <Cluster>
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
  z, p, n, d: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  b := Self.Bounds(w, h);
  d := Point(Max(0, xRadius), Max(0, yRadius));
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (g[n.X][n.Y].Size + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or g[n.X][n.Y].Empty) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
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
            if z.Within(p, xRadius, yRadius) then
            begin
              SetLength(Result[r], (Result[r].Size + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (q.Size + 1));
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
    if (Result[r].Size > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clustered>
  @action: Groups points into clusters based on pairwise proximity using the
           supplied distance function and radius threshold. Each cluster is a
           connected component where every point is reachable from any other
           through successive neighbor relationships.
  @note: The algorithm performs a flood-fill/region-growing traversal. A point
         joins a cluster if it lies within `radius` of any member of that
         cluster according to `distFunc`. Complexity is O(N²) in the worst
         case. Returns an array of clusters, each cluster being a dynamic
         array of TPoint. Input array ordering is preserved in cluster
         discovery; no sorting is performed.
[==============================================================================}
function TPointArrayHelper.Clustered(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and p.Within(Self[j], radius, distFunc)) then
        begin
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (q.Size + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clustered>
  @action: Groups points into proximity-based clusters using Euclidean distance
           with a caller-specified radius.
  @note: This overload is equivalent to calling the primary variant with the
         built-in Euclidean distance function. See the primary documentation
         for clustering semantics and performance considerations.
[==============================================================================}
function TPointArrayHelper.Clustered(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clustered(radius, @Euclidean);
end;

{==============================================================================]
  <Clustered>
  @action: Generates clusters by treating two points as neighbors when their
           coordinate-wise separations fall within the specified horizontal and
           vertical radii. Clusters are constructed as connected components under
           this axis-aligned proximity rule.
  @note: Uses a rectangular neighborhood test (Chebyshev-like, but not metric)
         rather than a general distance function. Points are aggregated via a
         flood-fill process identical in structure to the radius-based
         overload. Worst-case complexity is O(N²). Ordering of the input array
         determines cluster enumeration order.
[==============================================================================}
function TPointArrayHelper.Clustered(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and p.Within(Self[j], xRadius, yRadius)) then
        begin
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (q.Size + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clusterify>
  @action: Performs index-based clustering of the point array using a breadth-
           first expansion. A point joins a cluster when its distance from any
           existing cluster member is within the specified radius according to
           the given distance function. Returns an array of clusters, each
           represented as a TPoint array.
  @note: The algorithm uses an integer queue referencing element indices,
         avoiding redundant point copies during traversal. This variant is
         functionally equivalent to `Clustered` but may offer clearer index
         management and slightly reduced per-iteration overhead. Input order
         determines the order in which clusters are discovered. Worst-case
         complexity is O(N²).
[==============================================================================}
function TPointArrayHelper.Clusterify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  SetLength(Result, Self.Size);
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
        if ((not v[j]) and p.Within(Self[j], radius, distFunc)) then
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
  <Clusterify>
  @action: Creates proximity-based clusters using Euclidean distance and the
           specified radius. Equivalent to the primary variant but uses the
           built-in Euclidean metric by default.
  @note: See the main overload for details regarding traversal, performance
         profile, and cluster generation semantics.
[==============================================================================}
function TPointArrayHelper.Clusterify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterify(radius, @Euclidean);
end;

{==============================================================================]
  <Clusterify>
  @action: Produces clusters by treating two points as neighbors when their
           coordinate differences fall within the specified horizontal and
           vertical radii. Clusters are formed as connected components under
           this axis-aligned proximity constraint.
  @note: Uses an index queue and a rectangular neighborhood test, identical in
         structure to the radius/distance-function variant. No sorting of the
         input array is performed; clusters are emitted in the order in which
         unvisited points are encountered. Complexity is O(N²) in the worst
         case due to exhaustive neighbor checks.
[==============================================================================}
function TPointArrayHelper.Clusterify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  SetLength(Result, Self.Size);
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
        if ((not v[j]) and (p.Within(Self[j], xRadius, yRadius))) then
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
  <Clusterize>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
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
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(p, l);
  for i := 0 to (l - 1) do
    p[i] := i;
  for i := 0 to (l - 1) do
    for j := (i + 1) to (l - 1) do
	  if Self[i].Within(Self[j], radius, distFunc) then
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
      m[r] := System.Length(Result);
      SetLength(Result, (System.Length(Result) + 1));
      Result[m[r]] := [];
    end;
    Result[m[r]] := (Result[m[r]] + [Self[i]]);
  end;
end;

function TPointArrayHelper.Clusterize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterize(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Clusterize>
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
  SetLength(p, Self.Size);
  for i := 0 to High(Self) do
    p[i] := i;
  for i := 0 to (High(Self) - 1) do
    for j := (i + 1) to High(Self) do
      if Self[i].Within(Self[j], xRadius, yRadius) then
        PUnioned(i, j);
  SetLength(m, Self.Size);
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
  <Clusters>
  @action: Group points in the array into clusters based on a distance threshold.
  @note: Uses a breadth-first region-growing approach.
         Each cluster contains points whose pairwise distances are within radius.
         Uses the provided distance function.
[==============================================================================}
function TPointArrayHelper.Clusters(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, u: TPoint;
  a: Boolean;
  l: TRange;
  d, m, o: Double;
begin
  z := Self.Size;
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
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
          if k.Within(Point(x, y), o, distFunc) then
          begin
            t := Result[r].Size;
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
  <Clusters>
  @action: Group points in the array into rectangular clusters based on X and Y radii.
  @note: Clustering is anisotropic — points are grouped if their |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
         No distance function is used.
[==============================================================================}
function TPointArrayHelper.Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, u, m: TPoint;
  a: Boolean;
  l: TRange;
begin
  z := Self.Size;
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
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
          if k.Within(Point(x, y), m.X, m.Y) then
          begin
            t := Result[r].Size;
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
  <RCluster>
  @action: Groups points into rectangular clusters based on X/Y radius thresholds.
  @note: Uses a grid-based flood-fill algorithm; points are considered connected
         if their absolute X and Y distances are within (xRadius, yRadius).
[==============================================================================}
function TPointArrayHelper.RCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
type
  TCell = record
    indices: TIntegerArray;
  end;
  TCellArray = array of TCell;
  TGrid = array of TCellArray;
var
  v: TBooleanArray;
  g: TGrid;
  e, f, w, h, i, j, l, t, r, x, y, z: Integer;
  s: TIntegerArray;
  b: TBox;
  c, p, d: TPoint;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  b := Self.Bounds;
  e := (xRadius * 2 + 1);
  f := (yRadius * 2 + 1);
  w := ((b.X2 - b.X1) div e + 1);
  h := ((b.Y2 - b.Y1) div f + 1);
  SetLength(g, w, h);
  for i := 0 to High(Self) do
    g[((Self[i].X - b.X1) div e)][((Self[i].Y - b.Y1) div f)].indices.Supply(i);
  SetLength(v, l);
  SetLength(s, l);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    z := 0;
    SetLength(Result[r], 0);
    while (t > 0) do
    begin
      c := Self[s[t.Decrement]];
      SetLength(Result[r], z.Increment);
      Result[r][z - 1] := c;
      p := Point(((c.X - b.X1) div e), ((c.Y - b.Y1) div f));
      for x := Max(0, (p.X - 1)) to Min((w - 1), (p.X + 1)) do
        for y := Max(0, (p.Y - 1)) to Min((h - 1), (p.Y + 1)) do
          for j := 0 to High(g[x, y].indices) do
          begin
            if v[g[x, y].indices[j]] then
              Continue;
            d := Point(Abs(c.X - Self[g[x, y].indices[j]].X), Abs(c.Y - Self[g[x, y].indices[j]].Y));
            if ((d.X <= xRadius) and (d.Y <= yRadius)) then
            begin
              v[g[x, y].indices[j]] := True;
              s[t.Increase] := g[x, y].indices[j];
            end;
          end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <RCluster>
  @action: Groups points into clusters based on a custom distance metric and radius.
  @note: Supports user-defined metrics (e.g. Euclidean, Manhattan, Chebyshev).
         Uses grid partitioning for spatial acceleration and a stack-based region grow.
[==============================================================================}
function TPointArrayHelper.RCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
type
  TCell = record
    indices: TIntegerArray;
  end;
  TCellArray = array of TCell;
  TGrid = array of TCellArray;
var
  v: TBooleanArray;
  g: TGrid;
  k, w, h, i, j, l, t, r, x, y, z: Integer;
  s: TIntegerArray;
  b: TBox;
  c, p: TPoint;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  k := (Trunc(Radius * 2) + 1);
  b := Self.Bounds;
  w := ((b.X2 - b.X1) div k + 1);
  h := ((b.Y2 - b.Y1) div k + 1);
  SetLength(g, w, h);
  for i := 0 to High(Self) do
    g[((Self[i].X - b.X1) div k)][((Self[i].Y - b.Y1) div k)].indices.Supply(i);
  SetLength(v, l);
  SetLength(s, l);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    z := 0;
    SetLength(Result[r], 0);
    while (t > 0) do
    begin
      c := Self[s[t.Decrement]];
      SetLength(Result[r], z.Increment);
      Result[r][z - 1] := c;
      p := Point(((c.X - b.X1) div k), ((c.Y - b.Y1) div k));
      for x := Max(0, (p.X - 1)) to Min((w - 1), (p.X + 1)) do
        for y := Max(0, (p.Y - 1)) to Min((h - 1), (p.Y + 1)) do
          for j := 0 to High(g[x, y].indices) do
            if v[g[x, y].indices[j]] then
              Continue
			else if c.Within(Self[g[x, y].indices[j]], radius, metric) then
            begin
              v[g[x, y].indices[j]] := True;
              s[t.Increase] := g[x, y].indices[j];
            end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <ProximityCluster>
  @action:
    Groups points into spatial clusters based on rectangular proximity.
    Two points belong to the same cluster if their X and Y differences are
    both within the specified radii.
  @params:
    xRadius : Integer
      Maximum horizontal distance (in coordinate units) between two points
      to be considered neighbors.
    yRadius : Integer
      Maximum vertical distance (in coordinate units) between two points
      to be considered neighbors.
    method  : Integer = 0
      Determines the output grouping method:
        0 - Use Groupify
        1 - Use Grouping
        2 - Use Grouped
  @returns:
    T2DPointArray containing one subarray per detected cluster.
[==============================================================================}
function TPointArrayHelper.ProximityCluster(const xRadius, yRadius: Integer; const method: Integer = 0): T2DPointArray; overload;
var
  i, j, k, c, l: Integer;
  g, y: TIntegerArray;
  x, s: T2DIntegerArray;
  h, v: TRange;
  procedure MC(const a, b: Integer);
  var
    o, n, m: Integer;
  begin
    if (a = b) then
      Exit;
    o := g[b];
    n := g[a];
    for m := 0 to High(g) do
      if (g[m] = o) then
        g[m] := n;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := Self.IDs;
  x := Self.XTo2D(y, s);
  for c := 0 to High(x) do
  begin
    h.Create(c);
    while ((h.start > 0) and (Abs(y[h.start - 1] - y[c]) <= xRadius)) do
      Dec(h.start);
    while ((h.stop < High(x)) and (Abs(y[h.stop + 1] - y[c]) <= xRadius)) do
      Inc(h.stop);
    for i := 0 to High(x[c]) do
      for j := h.start to h.stop do
      begin
        v.start := x[j].BinaryFirst(x[c][i] - yRadius);
        if not (v.start = -1) then
          v.stop := x[j].BinaryLast(x[c][i] + yRadius);
        if not v.Employs(-1) then
        for k := v.start to v.stop do
          if Self[s[c][i]].Within(Self[s[j][k]], xRadius, yRadius) then
            MC(s[c][i], s[j][k]);
      end;
  end;
  case method of
    0: Result := Self.Groupify(g);
    1: Result := Self.Grouping(g);
    2: Result := Self.Grouped(g);
  end;
end;

{==============================================================================]
  <ProximityCluster>
  @action:
    Clusters points in the array based on geometric proximity using a
    distance metric. Points closer than the given radius are merged
    into the same cluster.
  @params:
    radius : Double = 1.0
      Maximum distance between two points (according to the selected metric)
      for them to belong to the same cluster.
    metric : TMetrics = dmEuclidean
      Distance metric used to compute proximity:
        dmEuclidean - standard geometric distance
        dmManhattan - sum of absolute component differences
        dmChebyshev - maximum component difference
    method : Integer = 0
      Determines which grouping procedure is used to construct the result:
        0 - Groupify
        1 - Grouping
        2 - Grouped
  @returns:
    T2DPointArray in which each subarray represents one proximity-based cluster.
[==============================================================================}
function TPointArrayHelper.ProximityCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const method: Integer = 0): T2DPointArray; overload;
var
  i, j, k, c, l, d: Integer;
  g, y: TIntegerArray;
  x, s: T2DIntegerArray;
  h, v: TRange;
  procedure MC(const a, b: Integer);
  var
    o, n, m: Integer;
  begin
    if (a = b) then Exit;
    o := g[b];
    n := g[a];
    for m := 0 to High(g) do
      if (g[m] = o) then
        g[m] := n;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := Self.IDs;
  x := Self.XTo2D(y, s);
  d := Ceil(radius);
  for c := 0 to High(x) do
  begin
    h.Create(c);
    while ((h.start > 0) and (Abs(y[h.start - 1] - y[c]) <= d)) do
      Dec(h.start);
    while ((h.stop < High(x)) and (Abs(y[h.stop + 1] - y[c]) <= d)) do
      Inc(h.stop);
    for i := 0 to High(x[c]) do
      for j := h.start to h.stop do
      begin
        v.start := x[j].BinaryFirst(x[c][i] - d);
        if not (v.start = -1) then
          v.stop := x[j].BinaryLast(x[c][i] + d);
        if not v.Employs(-1) then
        for k := v.start to v.stop do
          if Self[s[c][i]].Within(Self[s[j][k]], radius, metric) then
            MC(s[c][i], s[j][k]);
      end;
  end;
  case method of
    0: Result := Self.Groupify(g);
    1: Result := Self.Grouping(g);
    2: Result := Self.Grouped(g);
  end;
end;
{$ENDIF}
