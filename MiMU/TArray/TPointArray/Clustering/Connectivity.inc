{$IFDEF HELPERS}
function Link(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 1): T2DPointArray; overload;
function Link(const xRadius, yRadius: Integer; const check: Integer = 1): T2DPointArray; overload;
function Chain(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
function Chain(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
function Connect(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
function Connect(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Link>
  @action: Build neighbour-based clusters by linking each point to up to check
           nearest neighbours inside radius (using metric). Candidate
           neighbours are discovered quickly via binary-range lookups on the
           precomputed X/Y index arrays (XTo2D + BinaryRange).
           Matching neighbour pairs are merged with a disjoint-set (union–find)
           so clusters are transitively connected: if A→B and B→C then A, B, C
           belong to the same cluster.
  @note: - radius is the floating-point distance threshold used to select
           candidate neighbours; the integer search bound d := Ceil(radius)
           is used to restrict binary-range queries for speed.
         - check limits how many nearest neighbours (per point) are
           examined/linked; larger values increase connectivity and cost.
         - Uses Euclidean or other `metric` only for the final Within/Dist
           test and for ordering neighbours by distance.
         - Union–find uses path compression and union-by-size for near-
           constant amortized cost; overall runtime is dominated by the
           spatial index lookups (≈ O(n log n) to build/scan) and the
           average-local-candidate work.
         - Deterministic: same input → same clusters. Returns array of
           clusters (T2DPointArray); cluster ordering is implementation-
           dependent.
[==============================================================================}
function TPointArrayHelper.Link(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 1): T2DPointArray; overload;
var
  i, j, r, c, l, g, d, e: Integer;
  f: Double;
  v, p, s, k, t, o: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
  function FindRoot(const a: Integer): Integer;
  begin
    if (p[a] <> a) then
      p[a] := FindRoot(p[a]);
    Result := p[a];
  end;
  procedure Unioned(const a, b: Integer);
  var
    r: TRange;
  begin
    r.Create(FindRoot(a), FindRoot(b));
    if (r.start = r.stop) then
      Exit;
    if (s[r.start] < s[r.stop]) then
      Swap(r.start, r.stop);
    p[r.stop] := r.start;
    Inc(s[r.start], s[r.stop]);
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (l - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      begin
        SetLength(n, 0);
        for c := x.start to x.stop do
        begin
          j := z[r][c];
          if ((i <> j) and Self[i].Within(Self[j], radius, metric)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := j;
            n[High(n)].distance := Self[i].Dist(Self[j], metric);
          end;
        end;
        for j := 0 to (High(n) - 1) do
          for c := (j + 1) to High(n) do
            if (n[j].distance > n[c].distance) then
            begin
              e := n[j].index;
              n[j].index := n[c].index;
              n[c].index := e;
              f := n[j].distance;
              n[j].distance := n[c].distance;
              n[c].distance := f;
            end;
        for j := 0 to Min(High(n), (check - 1)) do
          Unioned(i, n[j].index);
      end;
    end;
  end;
  SetLength(k, l);
  for i := 0 to (l - 1) do
    k[i] := -1;
  g := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (k[r] = -1) then
      k[r] := g.Increase;
  end;
  SetLength(t, g);
  for i := 0 to (l - 1) do
    Inc(t[k[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], t[i]);
  SetLength(o, g);
  for i := 0 to (l - 1) do
  begin
    r := k[FindRoot(i)];
    Result[r][o[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Link>
  @action: Build neighbour-based clusters by linking each point to up to check
           nearest neighbours inside an axis-aligned box given by
           xRadius/yRadius. Candidate neighbours are located via binary-
           range queries on the X/Y index arrays produced by
           XTo2D, and nearest candidates are ranked by
           Euclidean distance (Hypot) before linking.
           Matching neighbour pairs are merged using a disjoint-set
           (union–find) so clusters are transitively connected.
  @note: - This overload uses rectangular neighbourhoods: a candidate is
           considered only if its X/Y deltas are inside xRadius/yRadius;
           distance is used only to sort nearest candidates.
         - check limits how many nearest neighbours (per point) are
           considered/linked; increasing it increases connectivity and cost.
         - Uses binary-range lookups to avoid global O(n²) scanning — great
           for large point sets (expected ≈ O(n log n) dominated by indexing).
         - Union–find uses path compression and union-by-size for near-
           constant amortized cost; final clusters are produced by grouping
           points by their disjoint-set roots.
         - Deterministic: same input → same clusters. Returns a T2DPointArray
           (array of clusters); cluster ordering is implementation-dependent.
[==============================================================================}
function TPointArrayHelper.Link(const xRadius, yRadius: Integer; const check: Integer = 1): T2DPointArray; overload;
var
  i, j, r, c, l, g, e: Integer;
  f: Double;
  v, p, s, k, t, o: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
  function FindRoot(const a: Integer): Integer;
  begin
    if (p[a] <> a) then
      p[a] := FindRoot(p[a]);
    Result := p[a];
  end;
  procedure Unioned(const a, b: Integer);
  var
    r: TRange;
  begin
    r.Create(FindRoot(a), FindRoot(b));
    if (r.start = r.stop) then
      Exit;
    if (s[r.start] < s[r.stop]) then
      Swap(r.start, r.stop);
    p[r.stop] := r.start;
    Inc(s[r.start], s[r.stop]);
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (l - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
      begin
        SetLength(n, 0);
        for c := x.start to x.stop do
        begin
          j := z[r][c];
          if ((i <> j) and Self[i].Within(Self[j], xRadius, yRadius)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := j;
            n[High(n)].distance := Hypot((Self[i].X - Self[j].X), (Self[i].Y - Self[j].Y));
          end;
        end;
        for j := 0 to (High(n) - 1) do
          for c := (j + 1) to High(n) do
            if (n[j].distance > n[c].distance) then
            begin
              e := n[j].index;
              n[j].index := n[c].index;
              n[c].index := e;
              f := n[j].distance;
              n[j].distance := n[c].distance;
              n[c].distance := f;
            end;
        for j := 0 to Min(High(n), (check - 1)) do
          Unioned(i, n[j].index);
      end;
    end;
  end;
  SetLength(k, l);
  for i := 0 to (l - 1) do
    k[i] := -1;
  g := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (k[r] = -1) then
      k[r] := g.Increase;
  end;
  SetLength(t, g);
  for i := 0 to (l - 1) do
    Inc(t[k[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], t[i]);
  SetLength(o, g);
  for i := 0 to (l - 1) do
  begin
    r := k[FindRoot(i)];
    Result[r][o[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Chain>
  @action: Groups nearby points into connected chains using radius-based neighbor linking.
  @note: Each new chain starts from an unvisited point and expands by iteratively
         linking up to `check` nearest unlinked neighbors within the given radius.
         The process continues recursively until no further points can be connected.
         This version uses a simple full-scan distance check (no spatial indexing).
[==============================================================================}
function TPointArrayHelper.Chain(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, k, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  SetLength(u, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[c], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[c].Supply(Self[q]);
      SetLength(n, 0);
      for j := 0 to (l - 1) do
        if ((not u[j]) and Self[q].Within(Self[j], radius, metric)) then
        begin
          SetLength(n, (System.Length(n) + 1));
          n[High(n)].index := j;
          n[High(n)].distance := Self[q].Dist(Self[j], metric);
        end;
      for j := 0 to (High(n) - 1) do
        for k := (j + 1) to High(n) do
          if (n[j].distance > n[k].distance) then
	      begin
            Swap(n[j].index, n[k].index);
	        Swap(n[j].distance, n[k].distance);
	      end;
      for j := 0 to Min(High(n), (check - 1)) do
        if not u[n[j].index] then
        begin
          u[n[j].index] := True;
          s.Supply(n[j].index);
        end;
    end;
    Inc(c);
  end;
end;

{==============================================================================]
  <Chain>
  @action: Groups nearby points into connected chains using rectangular X/Y radii.
  @note: Similar to the distance-based Chain but uses axis-aligned rectangular bounds
         (xRadius, yRadius) for neighborhood checks instead of circular distance.
         Efficient for grid-aligned or anisotropic data where X and Y scales differ.
[==============================================================================}
function TPointArrayHelper.Chain(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, k, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  SetLength(u, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[c], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[c].Supply(Self[q]);
      SetLength(n, 0);
      for j := 0 to (l - 1) do
        if ((not u[j]) and Self[q].Within(Self[j], xRadius, yRadius)) then
        begin
          SetLength(n, (System.Length(n) + 1));
          n[High(n)].index := j;
          n[High(n)].distance := Hypot((Self[q].X - Self[j].X), (Self[q].Y - Self[j].Y));
        end;
      for j := 0 to (High(n) - 1) do
        for k := (j + 1) to High(n) do
          if (n[j].distance > n[k].distance) then
	      begin
            Swap(n[j].index, n[k].index);
	        Swap(n[j].distance, n[k].distance);
	      end;
      for j := 0 to Min(High(n), (check - 1)) do
        if not u[n[j].index] then
        begin
          u[n[j].index] := True;
          s.Supply(n[j].index);
        end;
    end;
    Inc(c);
  end;
end;

{==============================================================================]
  <Connect>
  @action: Connects points into clusters using spatial indexing (binary search + grid).
  @note: Uses precomputed X/Y grid slices (via TPointArray_XTo2D) and binary range
         search to quickly find neighbors within `radius`. Each cluster grows by
         recursively attaching up to `check` nearest neighbors that fall within range.
         Much faster than Chain for large point sets due to reduced search scope.
[==============================================================================}
function TPointArrayHelper.Connect(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, r, c, l, d, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  v: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[High(Result)], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[High(Result)].Supply(Self[q]);
      y := v.BinaryRange(TRange.Construct((Self[q].Y - d), (Self[q].Y + d)));
      if y.Employs(-1) then
        Continue;
      SetLength(n, 0);
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[q].X - d), (Self[q].X + d)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
          if (not u[z[r][c]]) and Self[q].Within(Self[z[r][c]], radius, metric) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := z[r][c];
            n[High(n)].distance := Self[q].Dist(Self[z[r][c]], metric);
          end;
      end;
      for j := 0 to (High(n) - 1) do
        for c := (j + 1) to High(n) do
          if (n[j].distance > n[c].distance) then
	  begin
            Swap(n[j].index, n[c].index);
	    Swap(n[j].distance, n[c].distance);
	  end;
      for j := 0 to Min(High(n), (check - 1)) do
      begin
        if u[n[j].index] then
          Continue;
        u[n[j].index] := True;
        s.Supply(n[j].index);
      end;
    end;
  end;
end;

{==============================================================================]
  <Connect>
  @action: Connects points into clusters using rectangular X/Y radii and spatial indexing.
  @note: Combines grid-based search (TPointArray_XTo2D) with axis-aligned neighbor
         bounds (xRadius, yRadius). Finds and links nearby points efficiently while
         respecting separate X and Y proximity limits. Ideal for non-uniform spacing.
[==============================================================================}
function TPointArrayHelper.Connect(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, r, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  v: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[High(Result)], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[High(Result)].Supply(Self[q]);
      y := v.BinaryRange(TRange.Construct((Self[q].Y - yRadius), (Self[q].Y + yRadius)));
      if y.Employs(-1) then
        Continue;
      SetLength(n, 0);
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[q].X - xRadius), (Self[q].X + xRadius)));
        if x.Employs(-1) then
          Continue;
        for c := x.start to x.stop do
          if ((not u[z[r][c]]) and Self[q].Within(Self[z[r][c]], xRadius, yRadius)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := z[r][c];
            n[High(n)].distance := Hypot((Self[q].X - Self[z[r][c]].X), (Self[q].Y - Self[z[r][c]].Y));
          end;
      end;
      for j := 0 to (High(n) - 1) do
        for c := (j + 1) to High(n) do
          if (n[j].distance > n[c].distance) then
	  begin
	    Swap(n[j].index, n[c].index);
	    Swap(n[j].distance, n[c].distance);
          end;  
      for j := 0 to Min(High(n), (check - 1)) do
      begin
        if u[n[j].index] then
          Continue;
        u[n[j].index] := True;
        s.Supply(n[j].index);
      end;
    end;
  end;
end;
{$ENDIF}
