{==============================================================================]
  <TCircle.Create>
  @action: Create a TCircle with center point and radius
  @note: None.
[==============================================================================}
constructor TCircle.Create(const cCenter: TPoint; const cRadius: Double); overload;
begin
  Self.center := cCenter;
  Self.radius := cRadius;
end;

{==============================================================================]
  <TCircle.Create>
  @action: Create a TCircle with center point and radius
  @note: None.
[==============================================================================}
constructor TCircle.Create(const centerX, centerY: Integer; const cRadius: Double); overload;
begin
  Self.center := Point(centerX, centerY);
  Self.radius := cRadius;
end;

{==============================================================================]
  <TCircle.Construct>
  @action: Constructs TCircle with cCenter and cRadius.
  @note: None.
[==============================================================================}
class function TCircle.Construct(const cCenter: TPoint; const cRadius: Double): TCircle; overload;
begin
  Result.center := cCenter;
  Result.radius := cRadius;
end;

{==============================================================================]
  <TCircle.Construct>
  @action: Constructs TCircle with centerX, centerY and radius.
  @note: None.
[==============================================================================}
class function TCircle.Construct(const centerX, centerY: Integer; const cRadius: Double): TCircle; overload;
begin
  Result.center := Point(centerX, centerY);
  Result.radius := cRadius;
end;

{==============================================================================]
  <TCircle.Contains>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Contains(const pt: TPoint): Boolean;
begin
  Result := ((Sqr(pt.X - Self.Center.X) + Sqr(pt.Y - Self.Center.Y)) <= Sqr(Self.Radius));
end;

{==============================================================================]
  <TCircle.Item>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Item(const pt: TPoint): Boolean;
begin
  Result := (Hypot((pt.X - Self.Center.X), (pt.Y - Self.Center.Y)) <= Self.Radius);
end;

{==============================================================================]
  <TCircle.Pixel>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Pixel(const pt: TPoint): Boolean;
begin
  Result := ((((pt.X - Self.Center.X) * (pt.X - Self.Center.X)) + ((pt.Y - Self.Center.Y) * (pt.Y - Self.Center.Y))) <= (Self.Radius * Self.Radius));
end;

{==============================================================================]
  <TCircle.Bounds>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Bounds: TBox;
begin
  Result := Box(Floor(Self.Center.X - Self.Radius), Floor(Self.Center.Y - Self.Radius), Ceil(Self.Center.X + Self.Radius), Ceil(Self.Center.Y + Self.Radius));
end;

{==============================================================================]
  <TCircle.Boundaries>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Boundaries: TBox;
begin
  Result := Box(Trunc(Self.Center.X - Self.Radius), Trunc(Self.Center.Y - Self.Radius), (Trunc(Self.Center.X + Self.Radius) + 1), (Trunc(Self.Center.Y + Self.Radius) + 1));
end;

{==============================================================================]
  <TCircle.BoundingBox>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.BoundingBox: TBox;
var
  r: Integer;
begin
  r := Round(Self.Radius);
  Result := Box((Self.Center.X - R), (Self.Center.Y - R), (Self.Center.X + R), (Self.Center.Y + R));
end;

{==============================================================================]
  <TCircle.Envelope>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Envelope: TBox;
var
  r: Integer;
begin
  r := Round(2 * Self.Radius);
  with Result do
  begin
    X1 := Round(Self.Center.X - Self.Radius);
    Y1 := Round(Self.Center.Y - Self.Radius);
    X2 := (X1 + r);
    Y2 := (Y1 + r);
  end;
end;

{==============================================================================]
  <TCircle.TPA>
  @action: Returns TCircle points as TPointArray.
  @note: None.
[==============================================================================}
function TCircle.TPA: TPointArray;
var
  b: TBox;
  x, y, p: Integer;
begin
  b := Self.Bounds;
  SetLength(Result, b.Area);
  p := 0;
  for y := b.Y1 to b.Y2 do
    for x := b.X1 to b.X2 do
      if Self.Contains(Point(x, y)) then
        Result[p.Increase] := Point(x, y);
end;

{==============================================================================]
 <TCircle.Points>
 @action: Returns all the points of TCircle.
 @note: None.
[==============================================================================}
function TCircle.Points: TPointArray;
var
  x, y: Integer;
  p: TPointArray;
begin
  SetLength(Result, 0);
  for x := Trunc(Self.Center.X - Self.Radius) to Trunc(Self.Center.X + Self.Radius) do
    for y := Trunc(Self.Center.Y - Self.Radius) to Trunc(Self.Center.Y + Self.Radius) do
      if (Sqr(x - Self.Center.X) + Sqr(y - Self.Center.Y) <= Sqr(Self.Radius)) then
        Result := (Result + [Point(x, y)]);
end;

{==============================================================================]
 <TCircle.BorderPoints>
 @action: Returns border points of TCircle.
 @note: Supports custom count.
[==============================================================================}
function TCircle.BorderPoints(const count: Integer): TPointArray;
var
  i: Integer;
  a: Double;
begin
  SetLength(Result, count);
  for i := 0 to (count - 1) do
  begin
    a := (2 * Pi * i / count);
    Result[i].X := Round(Self.Center.X + Self.Radius * Cos(a));
    Result[i].Y := Round(Self.Center.Y + Self.Radius * Sin(a));
  end;
end;

{==============================================================================]
 <TCircle.Border>
 @action: Returns border points of TCircle.
 @note: None.
[==============================================================================}
function TCircle.Border: TPointArray;
var
  x, y, d: Integer;
  c: TPoint;
  procedure AddPoint(p: TPoint);
  begin
    Result := (Result + [Point((Self.Center.X + p.X), (Self.Center.Y + p.Y)),
                         Point((Self.Center.X - p.X), (Self.Center.Y + p.Y)),
                         Point((Self.Center.X + p.X), (Self.Center.Y - p.Y)),
                         Point((Self.Center.X - p.X), (Self.Center.Y - p.Y)),
                         Point((Self.Center.X + p.Y), (Self.Center.Y + p.X)),
                         Point((Self.Center.X - p.Y), (Self.Center.Y + p.X)),
                         Point((Self.Center.X + p.Y), (Self.Center.Y - p.X)),
                         Point((Self.Center.X - p.Y), (Self.Center.Y - p.X))]);
  end;
begin
  SetLength(Result, 0);
  c.X := 0;
  c.Y := Round(Self.Radius);
  d := (3 - 2 * c.Y);
  while (c.X <= c.Y) do
  begin
    AddPoint(c);
    if (d >= 0) then
    begin
      d := (d + 4 * (c.X - c.Y) + 10);
      Dec(c.Y);
    end else
      d := (d + 4 * c.X + 6);
    Inc(c.X);
  end;
end; 
