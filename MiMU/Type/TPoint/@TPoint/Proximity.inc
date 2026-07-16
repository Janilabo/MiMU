{$IFDEF METHODS}
function Beyond(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
function Far(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
function Far(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
function Near(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
function Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
function Within(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Beyond(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
function Beyond(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
function Far(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
function Far(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
function Near(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
function Near(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
function Within(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
function Within(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Beyond>
  @action: Determines whether this point lies outside a rectangular area centered
           on another point, defined by horizontal and vertical radii.
  @note: Logical inverse of Within. Returns True if the point exceeds the
         xRadius tolerance on the X axis, the yRadius tolerance on the Y axis,
         or both. Useful for early-exit checks or out-of-range detection.
[==============================================================================}
function TPoint.Beyond(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Abs(Self.X - target.X) > xRadius) or (Abs(Self.Y - target.Y) > yRadius));
end;

{==============================================================================]
  <Beyond>
  @action: Determines whether this point lies beyond a given distance (radius)
           of another point, using the specified distance function.
  @note: Logical inverse of Within. Returns True if the computed distance
         strictly exceeds the radius. If no distance function is provided,
         Euclidean distance should be used as the default metric.
[==============================================================================}
function TPointHelper.Beyond(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) > radius);
end;

{==============================================================================]
  <Beyond>
  @action: Determines whether this point lies beyond a given radius of another
           point using a specified distance metric.
  @note: Logical inverse of Within. `metric` specifies a predefined distance
         metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses
         `Distance(metric)` to resolve the distance function.
[==============================================================================}
function TPointHelper.Beyond(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
begin
  Result := Self.Beyond(target, radius, Distance(metric));
end;

{==============================================================================]
  <Far>
  @action:  Determines whether the current point is beyond a given radius of the target point using a custom distance function.
  @note: Logical inverse of Near. `distFunc` is a user-provided function that
         calculates the distance between two points. Useful for non-standard
         distance metrics.
[==============================================================================}
function TPointHelper.Far(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) > radius);
end;

{==============================================================================]
  <Far>
  @action: Determines whether the current point is beyond a given radius of the target point using a specified distance metric.
  @note: Logical inverse of Near. `metric` specifies a predefined distance
         metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses
         `Distance(metric)` to resolve the distance function.
[==============================================================================}
function TPointHelper.Far(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
begin
  Result := Self.Far(target, radius, Distance(metric));
end;

{==============================================================================]
  <Far>
  @action: Determines whether the current point lies outside a circular radius of the target point using Euclidean distance.
  @note: Logical inverse of Near. Computes the squared Euclidean distance
         (`dx*dx + dy*dy`) and compares it to the squared radius for efficiency,
         avoiding a sqrt call.
[==============================================================================}
function TPoint.Far(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
var
  h, v: Double;
begin
  h := (Self.X - target.X);
  v := (Self.Y - target.Y);
  Result := (((h * h) + (v * v)) > (radius * radius));
end;

{==============================================================================]
  <Far>
  @action: Determines whether the current point lies outside an axis-aligned rectangular area around the target point.
  @note: Logical inverse of Near. Returns True if the X or Y distance exceeds
         `xRadius` or `yRadius` respectively. Uses `DistanceX` and `DistanceY`
         for clarity.
[==============================================================================}
function TPoint.Far(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Self.DistanceX(target) > xRadius) or (Self.DistanceY(target) > yRadius));
end;

{==============================================================================]
  <Near>
  @action: Determines whether the current point is within a given radius of the target point using a custom distance function.
  @note: `distFunc` is a user-provided function that calculates the distance between two points. Useful for non-standard distance metrics.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
  <Near>
  @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
  @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
begin
  Result := Self.Near(target, radius, Distance(metric));
end;

{==============================================================================]
  <Near>
  @action: Determines whether the current point is within a circular radius of the target point using Euclidean distance.
  @note: Computes the squared Euclidean distance (`dx*dx + dy*dy`) and compares it to the squared radius for efficiency.
[==============================================================================}
function TPoint.Near(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
var
  h, v: Double;
begin
  h := (Self.X - target.X);
  v := (Self.Y - target.Y);
  Result := (((h * h) + (v * v)) <= (radius * radius));
end;

{==============================================================================]
  <Near>
  @action: Determines whether the current point is within an axis-aligned rectangular area around the target point.
  @note: Checks whether the X and Y distances are within `xRadius` and `yRadius` respectively. Uses `DistanceX` and `DistanceY` for clarity.
[==============================================================================}
function TPoint.Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Self.DistanceX(target) <= xRadius) and (Self.DistanceY(target) <= yRadius));
end;

{==============================================================================]
  <Within>
  @action: Determines whether this point lies within a given distance (radius)
           of another point, using the specified distance function.
  @note: If no distance function is provided, Euclidean distance should be
         used as the default metric.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
  <Within>
  @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
  @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
begin
  Result := Self.Within(target, radius, Distance(metric));
end;

{==============================================================================]
  <Within>
  @action: Determines whether this point lies within a rectangular area centered
           on another point, defined by horizontal and vertical radii.
  @note: Useful for grid or axis-aligned range checks where separate X/Y
         tolerances are used instead of a circular radius.
[==============================================================================}
function TPoint.Within(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Abs(Self.X - target.X) <= xRadius) and (Abs(Self.Y - target.Y) <= yRadius));
end;
{$ENDIF}