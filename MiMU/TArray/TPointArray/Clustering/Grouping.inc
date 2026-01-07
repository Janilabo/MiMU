{$IFDEF HELPERS}
function AdjFill(const scan8W: Boolean = True): T2DPointArray;
function AFill(const scan8W: Boolean = True): T2DPointArray;
function CFill(const scan8W: Boolean = True): T2DPointArray;
function Grouped(const adjacency8: Boolean = True): T2DPointArray; overload;
function Groupify(const adjacency8: Boolean = True): T2DPointArray; overload;
function Grouping(const adjacency8: Boolean = True): T2DPointArray; overload;
function Groups(const adjacency8: Boolean = True): T2DPointArray; overload;
function Neighborify(const adjacency8: Boolean = True): T2DPointArray; overload;
function NFill(const scan8W: Boolean = True): T2DPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AdjFill>
  @action:
    Groups points into connected components based on grid adjacency.
    Supports 4-way (N, S, E, W) or 8-way (adds diagonals) connectivity.
  @note:
    • Assumes all points have integer coordinates.
    • Uses binary search within pre-sorted 2D index for O(log N) neighbor lookup.
    • Much faster than radius-based flood fills when only adjacent cells connect.
    • Returns: T2DPointArray of adjacency-connected clusters.
    • Complexity: O(N · log N) (binary searches dominate), O(N) for dense grids.
    • Memory: boolean visited array + BFS queue.
[==============================================================================}
function TPointArrayHelper.AdjFill(const scan8W: Boolean = True): T2DPointArray;
var
  a, l, i, k, r, c, f, g: Integer;
  h, z: T2DIntegerArray;
  v, q, x, y: TIntegerArray;
  u: TBooleanArray;
  n, p: TPoint;
  s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  case scan8W of
    True:
    begin
      X := [1, -1,  0,  0,  1,  1, -1, -1];
      Y := [0,  0,  1, -1,  1, -1,  1, -1];
    end;
    False:
    begin
      X := [1, -1,  0,  0];
      Y := [0,  0,  1, -1];
    end;
  end;
  a := x.Size;
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, l);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 1);
    q[0] := i;
    u[i] := True;
    SetLength(Result[g], 0);
    while (s.start < s.stop) do
    begin
      f := q[s.start.Increase];
      p := Self[f];
      Result[g].Supply(p);
      for k := 0 to (a - 1) do
      begin
        n := Point((p.X + x[k]), (p.Y + y[k]));
        r := v.BinarySearch(n.Y);
        if InRange(r, 0, High(v)) then
        begin
          c := h[r].BinarySearch(n.X);
          if (InRange(c, 0, High(h[r])) and (not u[z[r][c]])) then
          begin
            u[z[r][c]] := True;
            q[s.stop.Increase] := z[r][c];
          end;
        end;
      end;
    end;
    Inc(g);
  end;
  SetLength(Result, g);
end;

{==============================================================================]
  <AFill>
  @action: Performs adjacency-based flood fill over a bounded 2D grid.
           Groups connected points (4-way or 8-way) into separate clusters
           using a boolean occupancy map for constant-time neighbor lookup.
  @note: "A" stands for Adjacent Fill.
         - When scan8W = True → 8-way connectivity (includes diagonals).
         - When scan8W = False → 4-way connectivity (orthogonal only).
         This version is grid-optimized and typically faster than NFill
         for dense or uniformly spaced point sets.
[==============================================================================}
function TPointArrayHelper.AFill(const scan8W: Boolean = True): T2DPointArray;
var
  m: T2DBooleanArray;
  w, h, i, j, c: Integer;
  q, d: TPointArray;
  s: TRange;
  b: TBox;
  p, n: TPoint;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds(w, h);
  SetLength(m, h, w);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  if scan8W then
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(1, -1), Point(-1, 1), Point(-1, -1)]
  else
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  SetLength(Result, Self.Size);
  c := 0;
  for i := 0 to High(Self) do
  begin
    if not m[Self[i].Y - b.Y1][Self[i].X - b.X1] then
      Continue;
    s.Create(0, 0);
    SetLength(q, Self.Size);
    q[0] := Self[i];
    m[q[0].Y - b.Y1][q[0].X - b.X1] := False;
    while (s.start <= s.stop) do
    begin
      p := q[s.start.Increase];
      Result[c].Supply(p);
      for j := 0 to High(d) do
      begin
        n := Point((p.X + d[j].X), (p.Y + d[j].Y));
        if not (b.Contains(n) and m[n.Y - b.Y1][n.X - b.X1]) then
          Continue;
        m[n.Y - b.Y1, n.X - b.X1] := False;
        q[s.stop.Increment] := n;
      end;
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <CFill>
  @action: Groups adjacent points (4-way or 8-way) using a Union-Find
           (disjoint set) structure for efficient neighbor merging.
  @note: "C" stands for Cell/Connectivity Fill.
         - scan8W = True  →  8-way connectivity
         - scan8W = False →  4-way connectivity
         Unlike AFill, this method does not perform a flood search — it
         merges connected cells directly using disjoint sets.
[==============================================================================}
function TPointArrayHelper.CFill(const scan8W: Boolean = True): T2DPointArray;
var
  b: TBox;
  m: T2DIntegerArray;
  w, h, i, j, r, c: Integer;
  a: TPoint;
  d: TPointArray;
  p, s, l: TIntegerArray;
  function FindRoot(a: Integer): Integer;
  begin
    while (p[a] <> a) do
    begin
      p[a] := p[p[a]];
      a := p[a];
    end;
    Result := a;
  end;
  procedure UnionSets(a, b: Integer);
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
  if Self.Empty then
    Exit([]);
  b := Self.Bounds(w, h);
  SetLength(m, h, w);
  for i := 0 to High(m) do
    for j := 0 to High(m[i]) do
      m[i, j] := -1;
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := i;
  if scan8W then
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(1, -1), Point(-1, 1), Point(-1, -1)]
  else
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  SetLength(p, Self.Size);
  SetLength(s, Self.Size);
  for i := 0 to High(Self) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to High(Self) do
    for j := 0 to High(d) do
    begin
      a := Point((Self[i].X + d[j].X), (Self[i].Y + d[j].Y));
      if (b.Contains(a) and (m[a.Y - b.Y1][a.X - b.X1] <> -1)) then
        UnionSets(i, m[a.Y - b.Y1][a.X - b.X1]);
    end;
  SetLength(l, Self.Size);
  for i := 0 to High(Self) do
    l[i] := -1;
  c := 0;
  for i := 0 to High(Self) do
  begin
    r := FindRoot(i);
    if (l[r] = -1) then
      l[r] := c.Increase;
  end;
  SetLength(Result, c);
  for i := 0 to High(Self) do
    Result[l[FindRoot(i)]].Supply(Self[i]);
end;

{==============================================================================]
  <Grouped>
  @action: Partitions the points in the array into groups of connected points
           based on adjacency (4- or 8-connectivity). Each group is returned
           as a separate T2DPointArray within the result array.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (including diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element is a group of connected points.
         Uses a BFS (breadth-first search) algorithm internally to find the groups.
[==============================================================================}
function TPointArrayHelper.Grouped(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  q: TIntegerArray;
  d: TPointArray;
  r: TRange;
  i, j, p, g, k, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := System.Length(Result);
    SetLength(Result, (g + 1));
    SetLength(q, l);
    r.Create(0, 0);
    q[r.stop.Increase] := i;
    v[i] := True;
    while (r.start < r.stop) do
    begin
      p := q[r.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := Self[p];
      for j := 0 to High(d) do
        for k := 0 to (l - 1) do
          if ((not v[k]) and (Self[k] = (Self[p] + d[j]))) then
          begin
            v[k] := True;
            q[r.stop.Increase] := k;
          end;
    end;
  end;
end;

{==============================================================================]
  <Groupify>
  @action: Partitions the points in the array into connected groups (clusters)
           based on adjacency. Two points are considered connected if they
           are neighbors according to 4- or 8-connectivity.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (including diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element is a group of connected points.
         Uses a union-find (disjoint-set) algorithm internally for efficiency.
[==============================================================================}
function TPointArrayHelper.Groupify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  p: TIntegerArray;
  i, j, k, l: Integer;
  d: TPointArray;
  c, n: Integer;
  r, m: TIntegerArray;
  function FindRoot(const x: Integer): Integer;
  begin
    if (p[x] = x) then
      Exit(x);
    p[x] := FindRoot(p[x]);
    Exit(p[x]);
  end;
  procedure Unioned(const x, y: Integer);
  var
    h, v: Integer;
  begin
    h := FindRoot(x);
    v := FindRoot(y);
    if (h <> v) then
      p[v] := h;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  p := Self.IDs;
  d := Point(0, 0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    for j := 0 to High(d) do
    begin
      k := Self.Pos(Point((Self[i].X + d[j].X), (Self[i].Y + d[j].Y)));
      if (k <> -1) then
        Unioned(i, k);
    end;
  c := 0;
  SetLength(r, l);
  for i := 0 to (l - 1) do
  begin
    r[i] := FindRoot(i);
    if (r[i] = i) then
      Inc(c);
  end;
  SetLength(m, l);
  n := 0;
  for i := 0 to (l - 1) do
    if (r[i] = i) then
      m[i] := n.Increase
    else
      m[i] := m[r[i]];
  SetLength(Result, c);
  for i := 0 to (l - 1) do
  begin
    c := m[r[i]];
    SetLength(Result[c], (Result[c].Size + 1));
    Result[c][High(Result[c])] := Self[i];
  end;
end;

{==============================================================================]
  <Grouping>
  @action: Partitions the points in the array into connected groups using a
           recursive depth-first search (DFS). Each group is returned as a
           separate TPointArray within the resulting T2DPointArray.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (includes diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element represents a group of
         connected points.
         Internally uses DFS to traverse and collect all points belonging
         to the same connected component.
[==============================================================================}
function TPointArrayHelper.Grouping(const adjacency8: Boolean = True): T2DPointArray; overload;
  procedure DFS(const arr: TPointArray; const index: Integer; const directions: TPointArray; var visited: TBooleanArray; var group: TPointArray);
  var
    i, j: Integer;
  begin
    visited[index] := True;
    SetLength(group, (group.Size + 1));
    group[High(group)] := arr[index];
    for i := 0 to High(directions) do
      for j := 0 to High(arr) do
        if ((not visited[j]) and (arr[j] = (arr[index] + directions[i]))) then
          DFS(arr, j, directions, visited, group);
  end;
var
  v: TBooleanArray;
  d: TPointArray;
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    if not v[i] then
    begin
      SetLength(Result, (System.Length(Result) + 1));
      DFS(Self, i, d, v, Result[High(Result)]);
    end;
end;

{==============================================================================]
  <Groups>
  @action: Partitions the points in the array into connected groups using
           an iterative depth-first search (DFS). Each group is returned as
           a TPointArray within the resulting T2DPointArray.
  @note: adjacency8 = True uses 8-connectivity (diagonals included),
         False uses 4-connectivity (orthogonal neighbors only).
         The function uses a manual stack to avoid recursion.
         Returns a T2DPointArray where each element represents a group of
         connected points.
[==============================================================================}
function TPointArrayHelper.Groups(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  d: TPointArray;
  s: TIntegerArray;
  c, n, g, l, i, j, t: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := System.Length(Result);
    SetLength(Result, (g + 1));
    SetLength(s, l);
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    while (t) > 0 do
    begin
      c := s[t.Decrement];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := Self[c];
      for j := 0 to High(d) do
        for n := 0 to (l - 1) do
          if ((not v[n]) and (Self[n] = (Self[c] + d[j]))) then
          begin
            v[n] := True;
            s[t.Increase] := n;
          end;
      end;
    end;
end;

{==============================================================================]
  <Neighborify>
  @action: Groups points into clusters of connected neighbors based on 4- or 8-directional adjacency.
  @note: Uses a flood-fill algorithm on a bounding-box grid. Returns a T2DPointArray where each sub-array is a connected component.
         Empty arrays return [] and single-point arrays return [Self].
[==============================================================================}
function TPointArrayHelper.Neighborify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  w, h, l: Integer;
  v, g: T2DBooleanArray;
  d, q: TPointArray;
  s: TRange;
  i, j, x, y, z, r: Integer;
  p: TPoint;
  b: TBox;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds(w, h);
  SetLength(g, w, h);
  SetLength(v, w, h);
  for i := 0 to (l - 1) do
    g[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
  if adjacency8 then
    d := [Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1), Point(1, 0), Point(1, -1), Point(0, -1)]
  else
    d := [Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)];
  r := 0;
  SetLength(Result, l);
  for i := 0 to (w - 1) do
    for j := 0 to (h - 1) do
      if (g[i][j] and (not v[i][j])) then
      begin
        SetLength(q, 1);
        q[0] := Point(i, j);
        s.Create(0, 1);
        while (s.start < s.stop) do
        begin
          p := q[s.start.Increase];
          if v[p.X][p.Y] then
            Continue;
          v[p.X][p.Y] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Point((p.X + b.X1), (p.Y + b.Y1));
          for z := 0 to High(d) do
          begin
            x := (p.X + d[z].X);
            y := (p.Y + d[z].Y);
            if ((x >= 0) and (x < w) and (y >= 0) and (y < h) and g[x][y] and (not v[x][y])) then
            begin
              if (s.stop >= q.Size) then
                SetLength(q, (q.Size * 2));
              q[s.stop.Increase] := Point(x, y);
            end;
          end;
        end;
        if (Result[r].Size > 0) then
          Inc(r);
      end;
  SetLength(Result, r);
end;

{==============================================================================]
  <NFill>
  @action: Performs adjacency-based flood fill using binary search for neighbor detection.
           Groups connected points (4-way or 8-way) into separate clusters.
  @note: "N" stands for Neighbor Fill.
         - When scan8W = True → uses 8-way connectivity (includes diagonals).
         - When scan8W = False → uses 4-way connectivity (up, down, left, right).
         The method uses binary search on sorted X/Y axes via TPointArray.XTo2D
         for efficient detection of neighboring points without spatial hashing.
[==============================================================================}
function TPointArrayHelper.NFill(const scan8W: Boolean = True): T2DPointArray;
var
  i, j, k, r, c, l, t: Integer;
  h, z: T2DIntegerArray;
  v, q: TIntegerArray;
  u: TBooleanArray;
  p, n: TPoint;
  x, y, s: TRange;
  o: TPointArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if scan8W then
    o := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(-1, -1), Point(1, -1), Point(-1, 1)]
  else
    o := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  h := Self.XTo2D(v, z);
  SetLength(Result, l);
  SetLength(u, l);
  SetLength(q, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    u[i] := True;
    while (s.start <= s.stop) do
    begin
      p := Self[q[s.start.Increase]];
      Result[c].Supply(p);
      for k := 0 to High(o) do
      begin
        n := Point((p.X + o[k].X), (p.Y + o[k].Y));
        y := v.BinaryRange(TRange.Construct(n.Y, n.Y));
        if not y.Employs(-1) then
        for r := y.start to y.stop do
        begin
          x := h[r].BinaryRange(TRange.Construct(n.X, n.X));
          if not x.Employs(-1) then
          for j := x.start to x.stop do
          begin
            t := z[r][j];
            if not u[t] and (Self[t].X = n.X) and (Self[t].Y = n.Y) then
            begin
              u[t] := True;
              q[s.stop.Increment] := t;
            end;
          end;
        end;
      end;
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;
{$ENDIF}