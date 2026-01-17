{$IFDEF METHODS}
function Flipped: TPoint;
function ReflectX(const axis: Integer = 0): TPoint;
function ReflectY(const axis: Integer = 0): TPoint;
function Reflect(const axis: Integer = 0): TPoint;
function Reflected: TPoint;
function Reflection(const axis: Integer = 0): TPoint;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flipped>
  @action: Returns the point with its coordinates flipped (same as Reflected).
  @note: This is a shorthand, stylistically different version of Reflected.
[==============================================================================}
function TPoint.Flipped: TPoint;
begin
  Result := Point(Self.Y, Self.X);
end;

function TPoint.ReflectX(const axis: Integer = 0): TPoint;
begin
  Result.X := ((2 * axis) - Self.X);
  Result.Y := Self.Y;
end;

function TPoint.ReflectY(const axis: Integer = 0): TPoint;
begin
  Result.X := Self.X;
  Result.Y := ((2 * axis) - Self.Y);
end;

function TPoint.Reflect(const axis: Integer = 0): TPoint;
begin
  Result.X := ((2 * axis) - Self.X);
  Result.Y := ((2 * axis) - Self.Y);
end;

{==============================================================================]
  <Reflected>
  @action: Reflects the point across the line y = x.
  @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Reflected: TPoint;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;

{==============================================================================]
  <Reflection>
  @action: Performs a point reflection (central symmetry) through the point
           (axis, axis), returning the reflected point.
  @param axis: The coordinate value defining the center of reflection as the
               point (axis, axis).
  @returns: A new TPoint reflected through the center point.
  @note: This reflects both X and Y coordinates using the formula: 2*axis - coord.
         Example: Point(3, 5).Reflection(10) = Point(17, 15)
         For line reflections (mirroring across X or Y axis only), use 
         dedicated ReflectX or ReflectY methods.
[==============================================================================}
function TPoint.Reflection(const axis: Integer = 0): TPoint;
var
  c, i: Integer;
  z: array[0..1] of Integer;
begin
  i := 0;
  for c in Self do
    z[i.Increase] := ((2 * axis) - c);
  Result := Point(z[0], z[1]);
end;
{$ENDIF}