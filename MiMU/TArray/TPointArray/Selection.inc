{$IFDEF HELPERS}
function Edge(const scan8W: Boolean = False): TPointArray;
function Nearby(const target: TPoint; const radius: Double; const distFunc: TDistance): TPointArray; overload;
function Nearby(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function Nearby(const target: TPoint; const xRadius, yRadius: Integer): TPointArray; overload;
function Nearby(const targets: TPointArray; const radius: Double; const distFunc: TDistance): TPointArray; overload;
function Nearby(const targets: TPointArray; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function Nearby(const targets: TPointArray; const xRadius, yRadius: Integer): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Edge>
  @action: Returns with all the edge-points from arr.
           Supports both, 4-way and 8-way direction scanning styles.
  @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArrayHelper.Edge(const scan8W: Boolean = False): TPointArray;
var
  i, l, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Self.Length;
  if (l > 4) then
  begin
    b := Self.Bounds;
    b := b.Expand;
    b.Size(w, h);
    m := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
      m[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
    SetLength(Result, (w * h));
    w := (w - 2);
    h := (h - 2);
    r := 0;
    case scan8W of
      False:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
      True:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1] and m[x - 1][y - 1] and m[x - 1][y + 1] and m[x + 1][y - 1] and m[x + 1][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    end;
    SetLength(Result, r);
    SetLength(m, 0);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a given radius
           of a specified target point, using the provided distance function.
  @note: If no distance function is provided, a default (Euclidean) distance
         function is used. This checks distance from each point in Self to
         the target point.
[==============================================================================}
function TPointArrayHelper.Nearby(const target: TPoint; const radius: Double; const distFunc: TDistance): TPointArray; overload;
var
  i: Integer;
  f: TDistance;
begin
  f := Distance(distFunc);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if Self[i].Within(target, radius, f) then
      Result.Supply(Self[i]);
end;

function TPointArrayHelper.Nearby(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
begin
  Result := Self.Nearby(target, radius, Distance(metric));
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a rectangular
           area centered on a specified target point, defined by horizontal
           and vertical radii.
  @note: Checks each point in Self for inclusion using separate X and Y
         tolerances instead of a circular distance metric.
[==============================================================================}
function TPointArrayHelper.Nearby(const target: TPoint; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if Self[i].Within(target, xRadius, yRadius) then
      Result.Supply(Self[i]);
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a given radius
           of any point in the specified array of target points, using the
           provided distance function.
  @note: If no distance function is provided, a default (Euclidean) distance
         function is used. Each point in Self is included if it is within
         the radius of at least one target point.
[==============================================================================}
function TPointArrayHelper.Nearby(const targets: TPointArray; const radius: Double; const distFunc: TDistance): TPointArray; overload;
var
  i, j: Integer;
  f: TDistance;
begin
  if targets.Empty then
    Exit([]);
  f := Distance(distFunc);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    for j := 0 to High(targets) do
      if Self[i].Within(targets[j], radius, f) then
      begin
        Result.Supply(Self[i]);
	    Break;
      end;
end;

function TPointArrayHelper.Nearby(const targets: TPointArray; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
begin
  Result := Self.Nearby(targets, radius, Distance(metric));
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within rectangular
           areas around any point in the specified array of target points,
           defined by horizontal and vertical radii.
  @note: Each point in Self is included if it lies within the rectangular
         bounds of at least one target point. Useful for grid or axis-aligned
         proximity checks.
[==============================================================================}
function TPointArrayHelper.Nearby(const targets: TPointArray; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j: Integer;
begin
  if targets.Empty then
    Exit([]);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    for j := 0 to High(targets) do
      if Self[i].Within(targets[j], xRadius, yRadius) then
      begin
        Result.Supply(Self[i]);
	    Break;
      end;
end;
{$ENDIF}
