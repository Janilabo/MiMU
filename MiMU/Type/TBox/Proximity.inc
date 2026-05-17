{$IFDEF METHODS}
function Cendist(const bx: TBox): Double; overload;
function Distance(const target: TPoint): Double; overload;
function Distance(const target: TBox): Double; overload;
function Medius(const bx: TBox): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cendist>
  @action: Returns distance between box centers (not surface-to-surface).
  @note: Different from surface distance - includes half-dimensions.
         Useful for physics/collision response calculations.
[==============================================================================}
function TBox.Cendist(const bx: TBox): Double; overload;
var
  s, b: TPoint;
begin
  s := Self.Center;
  b := bx.Center;
  Result := Sqrt(Sqr(s.X - b.X) + Sqr(s.Y - b.Y));
end;

{==============================================================================]
  <Distance>
  @action: Returns minimum Euclidean distance from target point to box (0 if inside).
  @note: Useful for proximity queries.
[==============================================================================}
function TBox.Distance(const target: TPoint): Double; overload;
var
  d: TPoint;
begin
  if (target.X < Self.X1) then
    d.X := (Self.X1 - target.X)
  else if (target.X > Self.X2) then
    d.X := (target.X - Self.X2)
  else
    d.X := 0;
  if (target.Y < Self.Y1) then
    d.Y := (Self.Y1 - target.Y)
  else if (target.Y > Self.Y2) then
    d.Y := (target.Y - Self.Y2)
  else
    d.Y := 0;
  Result := Sqrt((d.X * d.X) + (d.Y * d.Y));
end;

{==============================================================================]
  <Distance>
  @action: Returns minimum Euclidean distance between two axis-aligned boxes.
  @note: Returns 0 if boxes intersect or touch.
         Handles all box orientations (normalizes internally).
[==============================================================================}
function TBox.Distance(const target: TBox): Double; overload;
var
  d: TPoint;
begin
  if (Self.X2 < target.X1) then
    d.X := (target.X1 - Self.X2)
  else if (target.X2 < Self.X1) then
    d.X := (Self.X1 - target.X2)
  else
    d.X := 0;
  if (Self.Y2 < target.Y1) then
    d.Y := (target.Y1 - Self.Y2)
  else if (target.Y2 < Self.Y1) then
    d.Y := (Self.Y1 - target.Y2)
  else
    d.Y := 0;
  Result := Sqrt((d.X * d.X) + (d.Y * d.Y));
end;

{==============================================================================]
  <Medius>
  @action: Returns Euclidean distance between box centers.
  @note: From Latin medius (middle/center).
         Measures core-to-core, not surface-to-surface.
         Use DistanceTo for edge-to-edge separation.
[==============================================================================}
function TBox.Medius(const bx: TBox): Double; overload;
begin
  Result := Hypot((Self.Center.X - bx.Center.X), (Self.Center.Y - bx.Center.Y));
end;
{$ENDIF}
