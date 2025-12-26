{$IFDEF HELPERS}
function Clusters(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Clusters(const radius: Double = 1.0): T2DPointArray; overload;
function Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
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
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
