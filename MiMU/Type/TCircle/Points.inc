{$IFDEF TYPES}
function Points: TPointArray; 
function TPA: TPointArray; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <TPA>
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
 <Points>
 @action: Returns all the points of TCircle.
 @note: None.
[==============================================================================}
function TCircle.Points: TPointArray;
var
  x, y: Integer;
begin
  SetLength(Result, 0);
  for x := Trunc(Self.Center.X - Self.Radius) to Trunc(Self.Center.X + Self.Radius) do
    for y := Trunc(Self.Center.Y - Self.Radius) to Trunc(Self.Center.Y + Self.Radius) do
      if (Sqr(x - Self.Center.X) + Sqr(y - Self.Center.Y) <= Sqr(Self.Radius)) then
        Result := (Result + [Point(x, y)]);
end;
{$ENDIF}