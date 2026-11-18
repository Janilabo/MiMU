{$IFDEF HELPERS}
function Nearby(const target: TPoint; const radius: Double; const distFunc: TDistance): TPointArray; overload;
function Nearby(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function Nearby(const target: TPoint; const xRadius, yRadius: Integer): TPointArray; overload;
function Nearby(const targets: TPointArray; const radius: Double; const distFunc: TDistance): TPointArray; overload;
function Nearby(const targets: TPointArray; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function Nearby(const targets: TPointArray; const xRadius, yRadius: Integer): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  Result.Clear;
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
  Result.Clear;
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
  Result.Clear;
  if targets.Empty then
    Exit;
  f := Distance(distFunc);
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
  Result.Clear;
  if not targets.Empty then
  for i := 0 to High(Self) do
    for j := 0 to High(targets) do
      if Self[i].Within(targets[j], xRadius, yRadius) then
      begin
        Result.Supply(Self[i]);
	    Break;
      end;
end;
{$ENDIF}
