{==============================================================================]
  <TPointHelper.Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPointHelper.Create(const X, Y: Integer): TPoint; cdecl; inline;
begin
  Self.X := X;
  Self.Y := Y;
  Result.X := X;
  Result.Y := Y;
end;

{==============================================================================]
  <TPointHelper.Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPointHelper.Build(const X, Y: Integer): TPoint; cdecl; inline;
begin
  Self.X := X;
  Self.Y := Y;
  Result.X := X;
  Result.Y := Y;
end;

{==============================================================================]
  <TPointHelper.InBox>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TPointHelper.InBox(const bx: TBox): Boolean; cdecl; inline;
begin
  Result := ((Self.X >= bx.X1) and (Self.Y >= bx.Y1) and (Self.X <= bx.X2) and (Self.Y <= bx.Y2));
end;

{==============================================================================]
  <TPointHelper.InCircle>
  @action: Returns true if pt is inside the given circle,
          that is defined by the center point and radius.
  @note: None.
[==============================================================================}
function TPointHelper.InCircle(const center: TPoint; const radius: Double): Boolean; cdecl; inline;
begin
  Result := (Sqr((Self.X - center.X) / radius) + Sqr((Self.Y - center.Y) / radius) <= 1);
end;

{==============================================================================]
  <TPointHelper.InEllipse>
  @action: Returns true if pt is inside the given ellipse,
          defined by the center point and X-radius and Y-radius.
  @note: None.
[==============================================================================}
function TPointHelper.InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; cdecl; inline;
begin
  Result := (Sqr((Self.X - center.X) / XRadius) + Sqr((Self.Y - center.Y) / YRadius) <= 1);
end;

{==============================================================================]
 <TPointHelper.AngleDegrees>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPointHelper.AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; cdecl;
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
 <TPointHelper.AngleRadians>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPointHelper.AngleRadians(const target: TPoint): Double; cdecl;
var
  a: Double;
begin
  a := ArcTan2((target.Y - Self.Y), (target.X - Self.X));
  Result := a.FixRadians;
end;

{==============================================================================]
 <TPointHelper.DistEuclidean>
 @action: Calculates the distance from source to target.
 @note: Euclidean.
[==============================================================================}
function TPointHelper.DistEuclidean(const target: TPoint): Double; cdecl;
begin
  Result := Sqrt(Power((Self.x - target.x), 2) + Power((Self.y - target.y), 2));
end;

{==============================================================================]
 <TPointHelper.DistEuclidean2>
 @action: Calculates the distance from source to target.
 @note: Euclidean v2
[==============================================================================}
function TPointHelper.DistEuclidean2(const target: TPoint): Double; cdecl;
begin
  Result := Sqrt(Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y));
end;

{==============================================================================]
 <TPointHelper.DistSquaredEuclidean>
 @action: Calculates the distance from source to target.
 @note: Squared Euclidean
[==============================================================================}
function TPointHelper.DistSquaredEuclidean(const target: TPoint): Double; cdecl;
begin
  Result := (((Self.X - target.X) * (Self.X - target.X)) + ((Self.Y - target.Y) * (Self.Y - target.Y)));
end;

{==============================================================================]
 <TPointHelper.DistManhattan>
 @action: Calculates the distance from source to target.
 @note: Manhattan
[==============================================================================}
function TPointHelper.DistManhattan(const target: TPoint): Double; cdecl;
begin
  Result := (Abs(Self.X - target.X) + Abs(Self.Y - target.Y));
end;

{==============================================================================]
 <TPointHelper.DistChebyshev>
 @action: Calculates the distance from source to target.
 @note: Chebyshev
[==============================================================================}
function TPointHelper.DistChebyshev(const target: TPoint): Double; cdecl;
begin
  Result := Max(Abs(Self.X - target.X), Abs(Self.Y - target.Y));
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
function TPointHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray; cdecl;
var
  r, c, i, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y + (r * (spaceVertical + 1)));
      for c := 0 to (columns - 1) do
      begin
        i := ((r * columns) + c);
        x := (Self.X + (c * (spaceHorizontal + 1)));
		Result[i].Create(x, y);
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
function TPointHelper.Row(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
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
function TPointHelper.Column(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
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
