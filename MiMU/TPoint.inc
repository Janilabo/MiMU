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
 <TPointHelper.ToY>
 @action: Returns an array of points forming a vertical line from Self to yGoal.
 @note:   X remains constant; Y increments or decrements depending on yGoal.
[==============================================================================}
function TPointHelper.ToY(const yGoal: Integer): TPointArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, (Abs(yGoal - Self.Y) + 1));
  r := 0;
  case (Self.Y > yGoal) of
    True:
    for i := Self.Y downto yGoal do
      Result[r.Increase] := Point(Self.X, i);
    False:
    for i := Self.Y to yGoal do
      Result[r.Increase] := Point(Self.X, i);
  end;
end;

{==============================================================================]
 <TPointHelper.ToX>
 @action: Returns an array of points forming a horizontal line from Self to xGoal.
 @note:   Y remains constant; X increments or decrements depending on xGoal.
[==============================================================================}
function TPointHelper.ToX(const xGoal: Integer): TPointArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, (Abs(xGoal - Self.X) + 1));
  r := 0;
  case (Self.X > xGoal) of
    True:
    for i := Self.X downto xGoal do
      Result[r.Increase] := Point(i, Self.Y);
    False:
    for i := Self.X to xGoal do
      Result[r.Increase] := Point(i, Self.Y);
  end;
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

{==============================================================================]
  <TPoint.Neighbour>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note:  Uses explicit comparisons of absolute differences.
          Excludes `Self` from being a neighbor in 8-way mode.
[==============================================================================}
function TPoint.Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (((d.X <= 1) and (d.Y <= 1)) and (not ((d.X = 0) and (d.Y = 0))))
  else
    Result := (((d.X = 1) and (d.Y = 0)) or ((d.X = 0) and (d.Y = 1)));
end;

{==============================================================================]
  <TPoint.Neighbor>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note: Uses a more concise method with Chebyshev distance (Max(dx, dy)) for 8-way
         and Manhattan distance (dx + dy) for 4-way. Excludes `Self` automatically
         because distance 0 is not considered adjacency.
[==============================================================================}
function TPoint.Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (Max(d.X, d.Y) = 1)
  else
    Result := ((d.X + d.Y) = 1);
end;

{==============================================================================]
  <TPoint.Adjacent>
  @action: Checks whether the given point p is directly adjacent to `Self`.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Efficient exact comparison. Self is not considered adjacent.
[==============================================================================}
function TPoint.Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
  c: TPoint;
begin
  c := Point((p.X - Self.X), (p.Y - Self.Y)); 
  for i := 0 to IfThen(adjacency8, 7, 3) do
    if ((c.X = o[i].X) and (c.Y = o[i].Y)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TPoint.Adjacent>
  @action: Returns all points adjacent to Self as a TPointArray.
           Can return either 4-way (orthogonal) or 8-way (including diagonals).
  @note: Creates a new dynamic array on each call.
[==============================================================================}
function TPointHelper.Adjacent(const adjacency8: Boolean = True): TPointArray; overload;
begin
  if adjacency8 then
    Exit([Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1)), Point((Self.X + 1), (Self.Y + 1)), Point((Self.X + 1), (Self.Y - 1)), Point((Self.X - 1), (Self.Y + 1)), Point((Self.X - 1), (Self.Y - 1))]);
  Result := [Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1))];
end;

{==============================================================================]
  <TPoint.Neighbours>
  @action: Returns all neighboring points of Self as a TPointArray.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Dynamic array is allocated for each call. Offset array ensures correct order.
[==============================================================================}
function TPointHelper.Neighbours(const adjacency8: Boolean = True): TPointArray; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
begin
  SetLength(Result, IfThen(adjacency8, 8, 4));
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X + o[i].X), (Self.Y + o[i].Y));
end;

{==============================================================================]
  <TPoint.Neighbors>
  @action: Returns all neighboring points of Self as a TPointArray (alternative spelling).
           Supports 4-way or 8-way adjacency.
  @note: The first 4 points are orthogonal neighbors; the next 4 (if adjacency8) are diagonals.
[==============================================================================}
function TPointHelper.Neighbors(const adjacency8: Boolean = True): TPointArray; overload;
begin
  with Self do
    Result := [Point((X + 1), Y), Point(X, (Y + 1)), Point((X - 1), Y), Point(X, (Y - 1)),
               Point((X + 1), (Y + 1)), Point((X + 1), (Y - 1)), Point((X - 1), (Y + 1)), Point((X - 1), (Y - 1))];
  if not adjacency8 then
    SetLength(Result, 4);
end;

{==============================================================================]
  <TPoint.Linked>
  @action: Determines whether both the current point (Self) and the given point p
           are present in the provided TPointArray. Returns True if both points
           are contained in the array, False otherwise.
  @note:   Uses the Contains helper of TPointArray for membership checks. This
           method only checks array membership; it does not imply any geometric
           connection or adjacency between the points.
[==============================================================================}
function TPointHelper.Linked(const p: TPoint; const link: TPointArray): Boolean; overload;
begin
  Result := (link.Contains(Self) and link.Contains(p));
end;
{$UNDEF TPoint}
