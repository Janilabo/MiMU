{$IFDEF HELPERS}
function Binified(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Binified(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function Binify(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Binify(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function Bins(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function Bins(const xRadius, yRadius: Integer): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Binified>
  @action: Performs spatial clustering of points using separate integer radii
           for X and Y axes. Points that are within xRadius horizontally and
           yRadius vertically are grouped into the same cluster.
  @note: Uses binary-search arrays (h and v) for fast neighbor lookup. BFS-style
         propagation ensures that all connected points are included in the cluster.
         Deterministic and works entirely with integer distances.
[==============================================================================}
function TPointArrayHelper.Binified(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  l, i, j, r, c, a, n: Integer;
  h, z: T2DIntegerArray;
  v, p, q: TIntegerArray;
  x, y, s: TRange;
begin
  a := Self.Length;
  if (a = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(p, a);
  for i := 0 to (a - 1) do
    p[i] := -1;
  SetLength(Result, 0);
  SetLength(Result, a);
  l := 0;
  for i := 0 to (a - 1) do
  begin
    if (p[i] <> -1) then
      Continue;
    SetLength(Result[l], 0);
    SetLength(q, a);
    s.Create(0, 0);
    q[s.start.Increase] := i;
    p[i] := System.Length(Result);
    while (s.stop < s.start) do
    begin
      j := q[s.stop.Increase];
      SetLength(Result[l], (Result[l].Size + 1));
      Result[l][High(Result[l])] := Self[j];
      y := v.BinaryRange(TRange.Construct((Self[j].Y - yRadius), (Self[j].Y + yRadius)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[j].X - xRadius), (Self[j].X + xRadius)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
        begin
          n := z[r][c];
          if (p[n] = -1) then
          begin
            p[n] := System.Length(Result);
            q[s.start.Increase] := n;
          end;
        end;
      end;
    end;
    Inc(l);
  end;
end;

{==============================================================================]
  <Binified>
  @action: Performs spatial clustering of points using a floating-point radius
           and a distance metric. Points within the specified radius according
           to the metric are grouped into the same cluster.
  @note: Uses binary-search arrays (h and v) for fast neighbor lookup. BFS-style
         propagation ensures transitive connectivity. Deterministic and metric-aware.
         The integer value d = Ceil(radius) is used for approximate bounding during
         binary search. Suitable for Euclidean, Manhattan, or custom distance metrics.
[==============================================================================}
function TPointArrayHelper.Binified(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  l, i, j, r, c, a, n, d: Integer;
  h, z: T2DIntegerArray;
  v, p, q: TIntegerArray;
  x, y, s: TRange;
begin
  a := Self.Size;
  if (a = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, a);
  for i := 0 to (a - 1) do
    p[i] := -1;
  SetLength(Result, 0);
  SetLength(Result, a);
  l := 0;
  for i := 0 to (a - 1) do
  begin
    if (p[i] <> -1) then
      Continue;
    SetLength(Result[l], 0);
    SetLength(q, a);
    s.Create(0, 0);
    q[s.start.Increase] := i;
    p[i] := System.Length(Result);
    while (s.stop < s.start) do
    begin
      j := q[s.stop.Increase];
      SetLength(Result[l], (Result[l].Size + 1));
      Result[l][High(Result[l])] := Self[j];
      y := v.BinaryRange(TRange.Construct((Self[j].Y - d), (Self[j].Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[j].X - d), (Self[j].X + d)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
        begin
          n := z[r][c];
          if ((p[n] = -1) and Self[j].Within(Self[n], radius, metric)) then
          begin
            p[n] := System.Length(Result);
            q[s.start.Increase] := n;
          end;
        end;
      end;
    end;
    Inc(l);
  end;
end;

{==============================================================================]
  <Binify>
  @action: Groups points into clusters using axis-aligned neighborhood radii.
           Uses a binary-search-optimized spatial indexing approach to
           efficiently merge points within (xRadius, yRadius) bounds.
  @note: Overload for integer-based clustering; works on 2D points.
         Clustering is performed using union-find to merge overlapping neighborhoods.
[==============================================================================}
function TPointArrayHelper.Binify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  n, i, c, r: Integer;
  h, z: T2DIntegerArray;
  v, q: TIntegerArray;
  m, l, p: TIntegerArray;
  x, y: TRange;
  function FindRoot(const index: Integer): Integer;
  begin
    if (q[index] = index) then
      Exit(index);
    q[index] := FindRoot(q[index]);
    Result := q[index];
  end;
  procedure Unioned(const a, b: Integer);
  var
    i, j: Integer;
  begin
    i := FindRoot(a);
    j := FindRoot(b);
    if (i = j) then
      Exit;
    q[j] := i;
  end;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(q, n);
  for i := 0 to (n - 1) do
    q[i] := i;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
        for c := x.start to x.stop do
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(l, c);
  for i := 0 to (n - 1) do
    Inc(l[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], l[i]);
  SetLength(p, c);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][p[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Binify>
  @action: Groups points into clusters using a distance threshold and a specified metric.
           Uses binary-search-optimized spatial indexing and union-find to efficiently
           merge points within the given radius according to the metric.
  @note: Overload for floating-point / metric-aware clustering.
         The metric can be Euclidean, Manhattan, or any user-defined TMetrics.
         Efficient for large point sets due to spatial partitioning and union-find.
[==============================================================================}
function TPointArrayHelper.Binify(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  n, i, c, r, k, d: Integer;
  h, z: T2DIntegerArray;
  v, q, m, l, p: TIntegerArray;
  x, y: TRange;
  procedure InitUnionFind;
  var
    j: Integer;
  begin
    SetLength(q, n);
    for j := 0 to (n - 1) do
      q[j] := j;
  end;
  function FindRoot(const index: Integer): Integer;
  begin
    if (q[index] = index) then
      Exit(index);
    q[index] := FindRoot(q[index]);
    Result := q[index];
  end;
  procedure Unioned(const a, b: Integer);
  var
    i, j: Integer;
  begin
    i := FindRoot(a);
    j := FindRoot(b);
    if (i <> j) then
      q[j] := i;
  end;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  InitUnionFind;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      for k := x.start to x.stop do
        if Self[i].Within(Self[z[r][k]], radius, metric) then
          Unioned(i, z[r][k]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(l, c);
  for i := 0 to (n - 1) do
    Inc(l[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], l[i]);
  SetLength(p, c);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][p[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Bins>
  @action: Cluster points into bins (clusters) using a floating-point radius and
           a distance metric. For each point, candidate neighbors are found via
           binary-range lookups on precomputed X/Y index arrays (h and v). Pairs
           within the radius (according to Metric) are unioned using a
           disjoint-set (union–find) structure; final clusters are produced by
           enumerating disjoint-set roots.
  @note:  Uses d := Ceil(radius) as an integer search bound to limit the
          binary-range queries; the precise inclusion test is performed with
          pt.Within(Self[i], Self[j], radius, metric). Implementation uses
          path compression and union-by-size for near-constant amortized
          union/find cost. Complexity dominated by neighbor lookups (≈ O(n log n)
          for spatial indexing) and O(n) memory for helper arrays. Deterministic
          and suitable for large point sets.
[==============================================================================}
function TPointArrayHelper.Bins(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  i, r, c, n, d, g: Integer;
  v, p, s, m, k, t: TIntegerArray;
  h, z: T2DIntegerArray;
  x, y: TRange;
  function FindRoot(i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure Unioned(i, j: Integer);
  var
    a, b: TPoint;
  begin
    a := Point(FindRoot(i), FindRoot(j));
    if (a.X = a.Y) then
      Exit;
    b := IfThen((s[a.X] < s[a.Y]), a, a.Flip);
    p[b.X] := b.Y;
    Inc(s[b.Y], s[b.X]);
  end;
begin
  n := Self.Size;
  if (n = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, n);
  SetLength(s, n);
  for i := 0 to (n - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      for c := x.start to x.stop do
        if Self[i].Within(Self[z[r][c]], radius, metric) then
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  g := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := g.Increase;
  end;
  SetLength(k, g);
  for i := 0 to (n - 1) do
    Inc(k[m[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], k[i]);
  SetLength(t, g);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][t[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Bins>
  @action: Cluster points into bins using separate axis-aligned radii (xRadius,
           yRadius). Candidate neighbors are located with binary-range queries on
           the precomputed X/Y index arrays (h and v). Pairs whose X and Y
           separations satisfy the rectangular neighborhood check are merged
           with a disjoint-set (union–find) structure; final clusters are
           collected from the union–find roots.
  @note:  This overload performs axis-aligned (rectangular) neighborhood checks
          and therefore does not use a distance metric. It uses binary-range
          indexing to avoid O(n²) pairwise checks and union-by-size + path
          compression for efficient merging. Complexity is dominated by the
          binary-range searches; memory is O(n). Use this overload when you
          want fast, axis-aligned binning instead of metric (circular) grouping.
[==============================================================================}
function TPointArrayHelper.Bins(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, r, c, n, g: Integer;
  p, s, m, k, t: TIntegerArray;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
  function FindRoot(i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure Unioned(i, j: Integer);
  var
    a, b: TPoint;
  begin
    a := Point(FindRoot(i), FindRoot(j));
    if (a.X = a.Y) then
      Exit;
    b := IfThen((s[a.X] < s[a.Y]), a, a.Flip);
    p[b.X] := b.Y;
    Inc(s[b.Y], s[b.X]);
  end;
begin
  n := Self.Size;
  if (n = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(p, n);
  SetLength(s, n);
  for i := 0 to (n - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
      for c := x.start to x.stop do
        if Self[i].Within(Self[z[r][c]], xRadius, yRadius) then
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  g := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := g.Increase;
  end;
  SetLength(k, g);
  for i := 0 to (n - 1) do
    Inc(k[m[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], k[i]);
  SetLength(t, g);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][t[r].Increase] := Self[i];
  end;
end;
{$ENDIF}
