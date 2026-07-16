{$IFDEF HELPERS}
function DBSCAN(const radius: Double; const minPts: Integer; const distFunc: TDistance): T2DPointArray; overload;
function DBSCAN(const radius: Double = 1.0; const minPts: Integer = 2; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
function DBSCAN(const xRadius, yRadius: Integer; const minPts: Integer): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DBSCAN>
  @action: Performs density-based clustering on a TPointArray using a fixed
           radius and custom distance function.
  @params:
    radius   - The maximum distance between points to be considered neighbors.
    minPts   - Minimum number of points required to form a dense region (core point).
    distFunc - Function used to compute distance between two TPoints.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Points not belonging to any cluster are ignored (treated as noise).
[==============================================================================}
function TPointArrayHelper.DBSCAN(const radius: Double; const minPts: Integer; const distFunc: TDistance): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  d: TDistance;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and Self[index].Within(Self[i], radius, d)) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (r.Size < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < r.Size) do
    begin
      n := RegionQuery(r[i]);
      if (n.Size >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  d := Distance(distFunc);
  s := Self.Size;
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;

function TPointArrayHelper.DBSCAN(const radius: Double = 1.0; const minPts: Integer = 2; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
begin
  Result := Self.DBSCAN(radius, minPts, Distance(metric));
end;

{==============================================================================]
  <DBSCAN>
  @action: Performs density-based clustering using separate X and Y radii,
           allowing anisotropic neighborhoods.
  @params:
    xRadius - Maximum horizontal distance to consider points neighbors.
    yRadius - Maximum vertical distance to consider points neighbors.
    minPts  - Minimum number of points to form a cluster.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Useful for clustering pixel-based data or TPAs where horizontal and
         vertical spacing differs. Rectangular neighborhood used for efficiency.
[==============================================================================}
function TPointArrayHelper.DBSCAN(const xRadius, yRadius: Integer; const minPts: Integer): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and Self[index].Within(Self[i], xRadius, yRadius)) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (r.Size < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < r.Size) do
    begin
      n := RegionQuery(r[i]);
      if (n.Size >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  s := Self.Size;
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;
{$ENDIF}
