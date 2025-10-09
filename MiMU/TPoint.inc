{$DEFINE TPoint}{$I config\Defines.inc}

{==============================================================================]
  <TPoint.Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const pX, pY: Integer); overload;
begin
  Self.X := pX;
  Self.Y := pY;
end;

{==============================================================================]
  <TPoint.Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <TPoint.Create>
  @action: Constructs new TPoint with pX and pY.
  @note: None.
[==============================================================================}
class function TPoint.Construct(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <TPoint.Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPoint.Build(const pX, pY: Integer): TPoint; inline;
begin
  Self.X := pX;
  Self.Y := pY;
  Result := Self;
end;

{==============================================================================]
  <TPoint.Inside>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TPointHelper.Inside(const bx: TBox): Boolean; inline;
begin
  Result := ((Self.X >= bx.X1) and (Self.Y >= bx.Y1) and (Self.X <= bx.X2) and (Self.Y <= bx.Y2));
end;

{==============================================================================]
  <TPoint.InCircle>
  @action: Returns true if pt is inside the given circle,
          that is defined by the center point and radius.
  @note: None.
[==============================================================================}
function TPoint.InCircle(const center: TPoint; const radius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / radius) + Sqr((Self.Y - center.Y) / radius) <= 1);
end;

{==============================================================================]
  <TPoint.InEllipse>
  @action: Returns true if pt is inside the given ellipse,
          defined by the center point and X-radius and Y-radius.
  @note: None.
[==============================================================================}
function TPoint.InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / XRadius) + Sqr((Self.Y - center.Y) / YRadius) <= 1);
end;

{==============================================================================]
 <TPoint.AngleDegrees>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPoint.AngleDegrees(const target: TPoint; const compass: Boolean = False): Double;
var
  a: Double;
begin
  if compass then
    a := ((ArcTan2((target.Y - Self.Y), (target.X - Self.X)) * (180.0 / Pi)) + 90.0)
  else
    a := (ArcTan2((target.Y - Self.Y), (target.X - Self.X)) * (180.0 / Pi));
  Result := a.FixDegrees;
end;

{==============================================================================]
 <TPoint.AngleRadians>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPoint.AngleRadians(const target: TPoint): Double;
var
  a: Double;
begin
  a := ArcTan2((target.Y - Self.Y), (target.X - Self.X));
  Result := a.FixRadians;
end;

{==============================================================================]
 <TPoint.DistEuclidean>
 @action: Calculates the distance from source to target.
 @note: Euclidean.
[==============================================================================}
function TPoint.DistEuclidean(const target: TPoint): Double;
begin
  Result := Sqrt(Power((Self.x - target.x), 2) + Power((Self.y - target.y), 2));
end;

{==============================================================================]
 <TPoint.DistEuclidean2>
 @action: Calculates the distance from source to target.
 @note: Euclidean v2
[==============================================================================}
function TPoint.DistEuclidean2(const target: TPoint): Double;
begin
  Result := Sqrt(Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y));
end;

{==============================================================================]
 <TPoint.DistSquaredEuclidean>
 @action: Calculates the distance from source to target.
 @note: Squared Euclidean
[==============================================================================}
function TPoint.DistSquaredEuclidean(const target: TPoint): Double;
begin
  Result := (((Self.X - target.X) * (Self.X - target.X)) + ((Self.Y - target.Y) * (Self.Y - target.Y)));
end;

{==============================================================================]
 <TPoint.DistManhattan>
 @action: Calculates the distance from source to target.
 @note: Manhattan
[==============================================================================}
function TPoint.DistManhattan(const target: TPoint): Double;
begin
  Result := (Abs(Self.X - target.X) + Abs(Self.Y - target.Y));
end;

{==============================================================================]
 <TPoint.DistChebyshev>
 @action: Calculates the distance from source to target.
 @note: Chebyshev
[==============================================================================}
function TPoint.DistChebyshev(const target: TPoint): Double;
begin
  Result := Max(Abs(Self.X - target.X), Abs(Self.Y - target.Y));
end;

{==============================================================================]
  <TPointHelper.Create>
  @action: Returns TPoint 0,0.
  @note: None.
[==============================================================================}
function TPointHelper.Create: TPoint; overload;
begin
  Self.X := 0;
  Self.Y := 0;
  Result := Self;
end;

{==============================================================================]
  <TPointHelper.Clamp>
  @action: Clamps pt in area, if it is not inside area.
  @note: None.
[==============================================================================}
function TPointHelper.Clamp(const area: TBox): TPoint;
begin
  Result.X := specialize IfThenElse<Integer>((Self.X < area.X1), (Self.X > area.X2), area.X1, area.X2, Self.X);
  Result.Y := specialize IfThenElse<Integer>((Self.Y < area.Y1), (Self.Y > area.Y2), area.Y1, area.Y2, Self.Y);
end;

{==============================================================================]
 <TPointHelper.Grid>
 @action: Outputs/builds grid of points with parameters;
          pt = starting point, used for starting coordinates.
          rows, columns = count of rows and columns
          spaceHorizontal = space between columns
          spaceVertical = space between rows
 @note: None.
[==============================================================================}
function TPointHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray;
var
  r, c, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y + (r * (spaceVertical + 1)));
      for c := 0 to (columns - 1) do
      begin
        x := (Self.X + (c * (spaceHorizontal + 1)));
		Result[(r * columns) + c].Create(x, y);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TPointHelper.Row>
 @action: Outputs column of points. Starting from pt,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TPointHelper.Row(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create((Self.X + (i * (space + 1))), Self.Y);
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TPointHelper.Column>
 @action: Outputs column of points. Starting from pt,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TPointHelper.Column(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create(Self.X, (Self.Y + (i * (space + 1))));
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <_TPoint.Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <_TPoint.Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const value: Integer = 0): TPoint; overload;
begin
  Result := _TPoint.Create(value, value);
end;

{$UNDEF TPoint}
