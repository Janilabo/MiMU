{$IFDEF HELPERS}
function BinaryFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
function BinaryFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
function BinaryFilled(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
function BFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFloodFill>
  @action:
    Performs a breadth-first flood fill (BFS) on the point array, grouping all
    points that lie within the specified radius (using the selected distance
    metric) into connected components.
  @note:
    • Uses a dynamically resizing queue to perform BFS traversal.
    • Employs a 2D spatial index (via TPointArray_XTo2D) to limit neighbor
      searches to points whose coordinates fall within ±Ceil(radius).
    • Each unvisited point becomes the seed of a new component; all reachable
      points are enqueued and marked as visited.
    • Returns: T2DPointArray where each subarray contains one connected cluster.
    • Complexity: O(N · K) on average (K = nearby points per lookup),
      worst case O(N²) when every point connects.
    • Memory: boolean visited array, integer queue, and spatial index buffers.
    • Recommended for small–medium point sets or when iterative BFS is preferred.
[==============================================================================}
function TPointArrayHelper.BinaryFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, j, r, c, d: Integer;
  h, z: T2DIntegerArray;
  q, v: TIntegerArray;
  u: TBooleanArray;
  x, y, s: TRange;
  p: TPoint;
  procedure Enqueue(const index: Integer);
  begin
    if u[index] then
      Exit;
    u[index] := True;
    if (s.stop.Increment > High(q)) then
      SetLength(q, (q.Size * 2));
    q[s.stop] := index;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(Radius);
  SetLength(u, l);
  SetLength(Result, 0);
  SetLength(Result, l);
  h := Self.XTo2D(v, z);
  SetLength(q, Max(256, (l div 10)));
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 0);
    q[s.stop] := i;
    u[i] := True;
    while (s.start <= s.stop) do
    begin
      p := Self[q[s.start.Increase]];
      Result[c].Supply(p);
      y := v.BinaryRange(TRange.Construct((p.Y - d), (p.Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((p.X - d), (p.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((not u[z[r][j]]) and p.Within(Self[z[r][j]], radius, metric)) then
            Enqueue(z[r][j]);
      end;
    end;
    if (Result[c].Size > 0) then
      Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <BinaryFill>
  @action:
    Uses a Union–Find (Disjoint-Set) structure to group points into connected
    components.  Points within the given radius (and metric) are merged into
    the same set; each root represents one cluster.
  @note:
    • Builds a 2D spatial index for efficient candidate lookup.
    • For each point, only bins within ±Ceil(radius) in X/Y are searched.
    • Applies union-by-size and path-compression for nearly-constant merge cost.
    • After all unions, unique roots define the final clusters.
    • Returns: T2DPointArray of all connected components.
    • Complexity: O(N · α(N)) amortized (almost linear).
    • Memory: integer arrays p (parent), s (size), m (root→component id).
    • Fixed logic: component counter increments only when a new root is found.
    • Best suited for large datasets where BFS would be too expensive.
[==============================================================================}
function TPointArrayHelper.BinaryFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  i, j, r, l, c, d: Integer;
  p, s, m: TIntegerArray;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
  t, n: TPoint;
  function FindRoot(const i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure UnionPoints(i, j: Integer);
  begin
    i := FindRoot(i);
    j := FindRoot(j);
    if (i <> j) then
    case (s[i] < s[j]) of
      True:
      begin
        p[i] := j;
        Inc(s[j], s[i]);
      end;
      False:
      begin
        p[j] := i;
        Inc(s[i], s[j]);
      end;
    end;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  h := Self.XTo2D(v, z);
  for i := 0 to (l - 1) do
  begin
    t := Self[i];
    y := v.BinaryRange(TRange.Construct((t.Y - d), (t.Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((t.X - d), (t.X + d)));
      if not x.Employs(-1) then
      for j := x.start to x.stop do
      begin
        n := Self[z[r][j]];
        if t.Within(n, radius, metric) then
          UnionPoints(i, z[r][j]);
      end;
    end;
  end;
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if m[r] = -1 then
    begin
      m[r] := c;
      Inc(c);
    end;
  end;
  SetLength(Result, c);
  for i := 0 to (l - 1) do
    Result[m[FindRoot(i)]].Supply(Self[i]);
end;

{==============================================================================]
  <BinaryFilled>
  @action:
    Optimized Union–Find flood fill that iterates directly over the 2D grid
    and unites only point pairs (f > e) within radius, eliminating duplicate
    comparisons and producing compact pre-allocated output clusters.
  @note:
    • Traverses all grid cells returned by TPointArray.XTo2D.
    • Checks neighboring bins within ±Ceil(radius) in both axes.
    • Uses path-halving in FindRoot and union-by-size in UnionSets.
    • Avoids redundant pair checks by enforcing f > e condition.
    • Builds exact component sizes before allocating Result arrays,
      avoiding dynamic reallocation during population.
    • Complexity: O(N · α(N)) amortized; typically fastest variant.
    • Memory: integer arrays p, s, m, t, k; minimal overhead.
    • Returns: compact T2DPointArray of connected components.
    • Recommended for large point clouds—highest performance and scalability.
[==============================================================================}
function TPointArrayHelper.BinaryFilled(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, e, f, g, q, n, j, c, r, o, d: Integer;
  h, z: T2DIntegerArray;
  x, y: TRange;
  v, p, s, m, t, k: TIntegerArray;
  function FindRoot(a: Integer): Integer;
  begin
    while (p[a] <> a) do
    begin
      p[a] := p[p[a]];
      a := p[a];
    end;
    Result := a;
  end;
  procedure UnionSets(const a, b: Integer);
  var
    x, y: Integer;
  begin
    x := FindRoot(a);
    y := FindRoot(b);
    if (x <> y) then
    case (s[x] < s[y]) of
      True:
      begin
        p[x] := y;
        Inc(s[y], s[x]);
      end;
      False:
      begin
        p[y] := x;
        Inc(s[x], s[y]);
      end;
    end;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for g := 0 to High(h) do
    for q := 0 to High(h[g]) do
    begin
      e := z[g][q];
      y := v.BinaryRange(TRange.Construct((Self[e].Y - d), (Self[e].Y + d)));
      if not y.Employs(-1) then
      for n := y.start to y.stop do
      begin
        x := h[n].BinaryRange(TRange.Construct((Self[e].X - d), (Self[e].X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
        begin
          f := z[n][j];
          if ((f > e) and Self[e].Within(Self[f], radius, metric)) then
            UnionSets(e, f);
        end;
      end;
    end;
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(t, c);
  for i := 0 to (l - 1) do
    Inc(t[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], t[i]);
  SetLength(k, c);
  for i := 0 to (l - 1) do
  begin
    o := m[FindRoot(i)];
    Result[o][k[o].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <BFloodFill>
  @action:
    Performs a breadth-first flood fill (BFS) similar to BinaryFloodFill but
    uses a pre-allocated queue sized to the total number of points, providing
    predictable performance and avoiding queue resizing.
  @note:
    • Pre-allocates queue (length = total points) and manages it via TRange
      (r.start/r.stop) as queue head/tail indices.
    • Uses 2D spatial index to quickly find potential neighbors.
    • Marks visited points (u[]) and collects connected components into Result.
    • Returns: T2DPointArray of connected clusters.
    • Complexity: O(N · K) average; O(N²) in the worst fully connected case.
    • Memory: boolean visited array + full-length queue.
    • Difference vs BinaryFloodFill:
        – No dynamic queue growth (fixed maximum size).
        – Slightly simpler and faster for large uniform point sets.
    • Ideal when deterministic memory footprint is desired.
[==============================================================================}
function TPointArrayHelper.BFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, k, j, d, f, c: Integer;
  h, z: T2DIntegerArray;
  q, v: TIntegerArray;
  u: TBooleanArray;
  x, y, r: TRange;
  a, b: TPoint;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(Radius);
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(q, l);
    r.Create(0, 1);
    q[0] := i;
    u[i] := True;
    while (r.start < r.stop) do
    begin
      a := Self[q[r.start.Increase]];
      Result[c].Supply(a);
      y := v.BinaryRange(TRange.Construct((a.Y - d), (a.Y + d)));
      if not y.Employs(-1) then
      for k := y.start to y.stop do
      begin
        x := h[k].BinaryRange(TRange.Construct((a.X - d), (a.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
        begin
          f := z[k][j];
          if u[f] then
            Continue;
          b := Self[f];
          if a.Within(b, radius, metric) then
          begin
            u[f] := True;
            q[r.stop.Increase] := f;
          end;
        end;
      end;
    end;
    if (Result[c].Size > 0) then
      Inc(c);
  end;
  SetLength(Result, c);
end;
{$ENDIF}
