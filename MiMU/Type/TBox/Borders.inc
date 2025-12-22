{$IFDEF TYPES}
function Border: TPointArray; overload; 
function Border(const X, Y: Integer): Boolean; overload; 
function Border(const pt: TPoint): Boolean; overload; 
function Edge: TPointArray; overload; 
function Edge(const X, Y: Integer): Boolean; overload; 
function Edge(const pt: TPoint): Boolean; overload; 
function Outline: TPointArray; overload; 
function Outline(const X, Y: Integer): Boolean; overload; 
function Outline(const pt: TPoint): Boolean; overload; 
function Contour: TPointArray;
function CornerPoints: TPointArray; 
function CornerPts: TPointArray; 
function Corners: TPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Border>
  @action: Returns TBox border points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Border: TPointArray; overload;
var
  x, y, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for x := Self.X1 to Self.X2 do
    Result[i.Increase] := Point(x, Self.Y1);
  for y := (Self.Y1 + 1) to (Self.Y2 - 1) do
    Result[i.Increase] := Point(Self.X2, y);
  for x := Self.X2 downto Self.X1 do
    Result[i.Increase] := Point(x, Self.Y2);
  for y := (Self.Y2 - 1) downto (Self.Y1 + 1) do
    Result[i.Increase] := Point(Self.X1, y);
end;

function TBox.Border(const X, Y: Integer): Boolean; overload;
begin
  with Self do
    Result := ((((X = X1) or (X = X2)) and ((Y >= Y1) and (Y <= Y2))) or (((Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2))));
end;

function TBox.Border(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Border(pt.X, pt.Y);
end;

{==============================================================================]
  <Edge>
  @action: Returns TBox edge points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Edge: TPointArray; overload;
var
  i, d, s: Integer;
  p: TPoint;
  c: TPointArray;
begin
  Self.Size(i, d);
  if ((i = 1) or (d = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (i + d)) - 4));
  p := Point(Self.X1, Self.Y1);
  i := 0;
  c := [Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)];
  for d := 0 to 3 do
  begin
    s := IfThen(d.Even, (Self.X2 - Self.X1), (Self.Y2 - Self.Y1));
    while (s > 0) do
    begin
      Result[i.Increase] := p;
      if (s.Decrease >= 0) then
        p := Point((p.X + c[d].X), (p.Y + c[d].Y));
    end;
  end;
end;

function TBox.Edge(const X, Y: Integer): Boolean; overload;
begin
  with Self do
    Result := (((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2) and (Y >= Y1) and (Y <= Y2)));
end;

function TBox.Edge(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Edge(pt.X, pt.Y);
end;

{==============================================================================]
  <Outline>
  @action: Returns TBox outline points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Outline: TPointArray; overload;
var
  x, y, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for x := Self.X1 to Self.X2 do
  begin
    Result[i.Increase] := Point(x, Self.Y1);
    Result[i.Increase] := Point(x, Self.Y2);
  end;
  for y := (Self.Y1 + 1) to (Self.Y2 - 1) do
  begin
    Result[i.Increase] := Point(Self.X1, y);
    Result[i.Increase] := Point(Self.X2, y);
  end;
end;

function TBox.Outline(const X, Y: Integer): Boolean; overload;
begin
  Result := ((not ((X < X1) or (X > X2) or (Y < Y1) or (Y > Y2))) and ((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)));
end;

function TBox.Outline(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Outline(pt.X, pt.Y);
end;

{==============================================================================]
  <Contour>
  @action: Returns TBox contour points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Contour: TPointArray;
var
  z: TIntegerArray;
  s: TSegment;
  i, l: Integer;
begin
  if not Self.Rectangular then
    Exit(Self.Points);
  SetLength(Result, Self.Circumference);
  z := [Self.X1, Self.Y1, Self.X2, Self.Y1, Self.X2, (Self.Y1 + 1), Self.X2, Self.Y2, (Self.X2 - 1), Self.Y2, Self.X1, Self.Y2, Self.X1, (Self.Y2 - 1), Self.X1, (Self.Y1 + 1)];
  l := 0;
  for i := 0 to 3 do
    l := Result.Blit(s.Create(z[(i * 4)], z[(i * 4) + 1], z[(i * 4) + 2], z[(i * 4) + 3]).Points, l);
end;

{==============================================================================]
  <CornerPoints>
  @action: Returns all 4 corner points of bx.
  @note: None
[==============================================================================}
function TBox.CornerPoints: TPointArray;
begin
  SetLength(Result, 4);
  Result[0].X := Self.X1;
  Result[0].Y := Self.Y1;
  Result[1].X := Self.X2;
  Result[1].Y := Self.Y1;
  Result[2].X := Self.X2;
  Result[2].Y := Self.Y2;
  Result[3].X := Self.X1;
  Result[3].Y := Self.Y2;
end;

{==============================================================================]
  <CornerPts>
  @action: Returns all 4 corner points of bx.
  @note: Gives also duplicates, if TBox is not rectangular.
[==============================================================================}
function TBox.CornerPts: TPointArray;
begin
  Result := [Point(Self.X1, Self.Y1), Point(Self.X2, Self.Y1), Point(Self.X2, Self.Y2), Point(Self.X1, Self.Y2)];
end;

{==============================================================================]
  <Corners>
  @action: Returns corner points of bx.
  @note: Outputs only unique TPoints.
[==============================================================================}
function TBox.Corners: TPointArray;
var
  p: TPoint;
begin
  SetLength(Result, 0);
  case ((Ord(Boolean(Self.X1 = Self.X2)) shl 1) or Ord(Boolean(Self.Y1 = Self.Y2))) of
    0: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1), p.Create(Self.X2, Self.Y2), p.Create(Self.X1, Self.Y2)];
    1: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1)];
    2: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X1, Self.Y2)];
    3: Result := [p.Create(Self.X1, Self.Y1)];
  end;
end;
{$ENDIF}