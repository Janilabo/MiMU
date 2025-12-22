{$IFDEF TYPES}
function BorderPoints(const count: Integer): TPointArray; 
function Border: TPointArray; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <BorderPoints>
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
 <Border>
 @action: Returns border points of TCircle.
 @note: None.
[==============================================================================}
function TCircle.Border: TPointArray;
var
  d: Integer;
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
{$ENDIF}