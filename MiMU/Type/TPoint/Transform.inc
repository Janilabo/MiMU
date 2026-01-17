{$IFDEF METHODS}
function Flip: TPoint;
function Flipped: TPoint;
function ReflectX(const axis: Integer = 0): TPoint;
function ReflectY(const axis: Integer = 0): TPoint;
function Reflect(const axis: Integer = 0): TPoint;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flip>
  @action: Reflects the point across the line y = x.
  @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Flip: TPoint;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;

{==============================================================================]
  <Flipped>
  @action: Returns the point with its coordinates flipped (same as Flip).
  @note: This is a shorthand, stylistically different version of Flip.
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
{$ENDIF}
