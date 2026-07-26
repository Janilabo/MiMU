{$IFDEF METHODS}
function Border: TPointArray; overload;
function Border(const pX, pY: Integer): Boolean; overload;
function Border(const pt: TPoint): Boolean; overload;
function Bordering(var pixels: TPointArray): Integer; overload;
function Boundarify: TPointArray; overload;
function Boundary: TPointArray; overload;
function Contour: TPointArray; overload;
function CornerPoints: TPointArray; overload;
function CornerPts: TPointArray; overload;
function Corners: TPointArray; overload;
function Edge: TPointArray; overload;
function Edge(const pX, pY: Integer): Boolean; overload;
function Edge(const pt: TPoint): Boolean; overload;
function Margin: TPointArray; overload;
function Outline: TPointArray; overload;
function Outline(const pX, pY: Integer): Boolean; overload;
function Outline(const pt: TPoint): Boolean; overload;
function Perimetrify: TPointArray; overload;
function Shell: TPointArray; overload;
function Verge: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Border>
  @action: Returns TBox border points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Border: TPointArray; overload;
var
  s, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for s := Self.X1 to Self.X2 do
    Result[i.Increase] := Point(s, Self.Y1);
  for s := (Self.Y1 + 1) to (Self.Y2 - 1) do
    Result[i.Increase] := Point(Self.X2, s);
  for s := Self.X2 downto Self.X1 do
    Result[i.Increase] := Point(s, Self.Y2);
  for s := (Self.Y2 - 1) downto (Self.Y1 + 1) do
    Result[i.Increase] := Point(Self.X1, s);
end;

function TBox.Border(const pX, pY: Integer): Boolean; overload;
begin
  with Self do
    Result := ((((pX = X1) or (pX = X2)) and ((pY >= Y1) and (pY <= Y2))) or (((pY = Y1) or (pY = Y2)) and ((pX >= X1) and (pX <= X2))));
end;

function TBox.Border(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Border(pt.X, pt.Y);
end;

{==============================================================================]
  <Bordering>
  @action: Populates an array with all pixel coordinates forming the outer border of the box and returns the pixel count.
  @note: Allocates buffer memory, iterates through the box grid to collect edge points (where x or y lies on the boundary),
         and truncates the resulting `pixels` array to the exact count.
[==============================================================================}
function TBox.Bordering(var pixels: TPointArray): Integer; overload;
var
  r, c: Integer;
begin
  Result := 0;
  SetLength(pixels, ((2 * Self.Width) + (2 * Self.Height)));
  for r := Self.Y1 to Self.Y2 do
    for c := Self.X1 to Self.X2 do
      if ((c = Self.X1) or (c = Self.X2) or (r = Self.Y1) or (r = Self.Y2)) then
        pixels[Result.Increase] := Point(c, r);
  SetLength(pixels, Result);
end;

{==============================================================================]
  <Boundarify>
  @action: Returns every distinct pixel forming the outer border of the box, degenerating gracefully for lines, points, and empty boxes.
  @note: For a full 2D box, walks the top/bottom rows (inclusive of corners) then the left/right columns (exclusive of the already-counted corner rows),
         filling the result array back-to-front via SetSize + Decrement so the point count matches Perim/Perimeter/Perimetry exactly.
         Degenerates to a single Verticalize/Horizontalize range for 1D line segments, a single point for zero-dimension boxes, and an empty array for invalid/empty boxes.
[==============================================================================}
function TBox.Boundarify: TPointArray; overload;
var
  s, r: Integer;
begin
  case Self.Dimension of
    2:
    begin
      r := Result.SetSize(((Self.Width * 2) + (Self.Height * 2)) - 4);
      for s := Self.X2 downto Self.X1 do
      begin
        Result[r.Decrement] := Point(s, Self.Y2);
        Result[r.Decrement] := Point(s, Self.Y1);
      end;
      for s := (Self.Y2 - 1) downto (Self.Y1 + 1) do
      begin
        Result[r.Decrement] := Point(Self.X2, s);
        Result[r.Decrement] := Point(Self.X1, s);
      end;
    end;
    1:
    if (Self.X1 = Self.X2) then
      Result := TRange.Construct(Self.Y1, Self.Y2).Verticalize(Self.X1)
    else
      Result := TRange.Construct(Self.X1, Self.X2).Horizontalize(Self.Y1);
    0: Result := [Point(Self.X1, Self.Y1)];
	-1: Result := [];
  end;
end;

{==============================================================================]
  <Boundary>
  @action: Returns all points that form the hollow outline of the box.
  @note: Populates an array with all boundary (perimeter) coordinates. 
        Safely handles 2D boxes, 1D line segments, and single-pixel points.
[==============================================================================}
function TBox.Boundary: TPointArray; overload;
var
  s, r: Integer;
begin
  if ((Self.Width <= 1) or (Self.Height <= 1)) then
    SetLength(Result, (Self.Width * Self.Height))
  else
    SetLength(Result, (2 * ((Self.Width + Self.Height) - 2)));
  r := 0;
  for s := Self.X1 to Self.X2 do
  begin
    Result[r.Increase] := Point(s, Self.Y1);
    if (Self.Y1 <> Self.Y2) then
      Result[r.Increase] := Point(s, Self.Y2);
  end;
  for s := (Self.Y1 + 1) to (Self.Y2 - 1) do
  begin
    Result[r.Increase] := Point(Self.X1, s);
    if (Self.X1 <> Self.X2) then
      Result[r.Increase] := Point(Self.X2, s);
  end;
end;

{==============================================================================]
  <Contour>
  @action: Returns TBox contour points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Contour: TPointArray; overload;
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
function TBox.CornerPoints: TPointArray; overload;
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
function TBox.CornerPts: TPointArray; overload;
begin
  Result := [Point(Self.X1, Self.Y1), Point(Self.X2, Self.Y1), Point(Self.X2, Self.Y2), Point(Self.X1, Self.Y2)];
end;

{==============================================================================]
  <Corners>
  @action: Returns corner points of bx.
  @note: Outputs only unique TPoints.
[==============================================================================}
function TBox.Corners: TPointArray; overload;
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

function TBox.Edge(const pX, pY: Integer): Boolean; overload;
begin
  with Self do
    Result := (((pX = X1) or (pX = X2) or (pY = Y1) or (pY = Y2)) and ((pX >= X1) and (pX <= X2) and (pY >= Y1) and (pY <= Y2)));
end;

function TBox.Edge(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Edge(pt.X, pt.Y);
end;

{==============================================================================]
  <Margin>
  @action: Returns every distinct pixel forming the outer border of the box, walked one step at a time in clockwise order starting from the top-left corner.
  @note: Classifies each step's position via Which against X1/X2 and Y1/Y2, letting the corner/edge transition table be expressed as nested case-of blocks rather than if/else chains.
         Degenerate boxes (width or height <= 1, or invalid/inverted bounds) defer entirely to Self.All rather than a specialized dispatch.
[==============================================================================}
function TBox.Margin: TPointArray; overload;
var
  i: Integer;
  p: TPoint;
  procedure R; overload;
  begin
    case p.X.Which(Self.X1, Self.X2) of
      0:
      case p.Y.Which(Self.Y1, Self.Y2) of
        0: Inc(p.X);
        1: Dec(p.Y);
      else
        Dec(p.Y);
      end;
      1:
      case p.Y.Which(Self.Y1, Self.Y2) of
        0: Inc(p.Y);
        1: Dec(p.X);
      else
        Inc(p.Y);
      end;
    else if (p.Y = Self.Y1) then
      Inc(p.X)
    else if (p.Y = Self.Y2) then
      Dec(p.X);
    end;
    Result[i] := p;
  end;
begin
  if ((Self.X2 <= Self.X1) or (Self.Y2 <= Self.Y1)) then
    Exit(Self.All);
  p := Point(Self.X1, (Self.Y1 + 1));
  for i := 0 to Result.Alloc(Self.Perimeter) do
    R;
end;

{==============================================================================]
  <Outline>
  @action: Returns TBox outline points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Outline: TPointArray; overload;
var
  s, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for s := Self.X1 to Self.X2 do
  begin
    Result[i.Increase] := Point(s, Self.Y1);
    Result[i.Increase] := Point(s, Self.Y2);
  end;
  for s := (Self.Y1 + 1) to (Self.Y2 - 1) do
  begin
    Result[i.Increase] := Point(Self.X1, s);
    Result[i.Increase] := Point(Self.X2, s);
  end;
end;

function TBox.Outline(const pX, pY: Integer): Boolean; overload;
begin
  Result := ((not ((pX < X1) or (pX > X2) or (pY < Y1) or (pY > Y2))) and ((pX = X1) or (pX = X2) or (pY = Y1) or (pY = Y2)));
end;

function TBox.Outline(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Outline(pt.X, pt.Y);
end;

{==============================================================================]
  <Perimetrify>
  @action: Generates and returns an array of coordinates outlining the box border in a continuous perimeter loop.
  @returns: A TPointArray containing all boundary pixels ordered along the 4 edges.
[==============================================================================}
function TBox.Perimetrify: TPointArray; overload;
var
  h, v, r: Integer;
begin
  if ((Self.Width <= 1) or (Self.Height <= 1)) then
    Exit(Self.All);
  r := Result.SetSize(Self.Perimeter);
  for v := (Self.Y1 + 1) to Self.Y2 do
    Result[r.Decrement] := Point(Self.X1, v);
  for h := (Self.X1 + 1) to Self.X2 do
    Result[r.Decrement] := Point(h, Self.Y2);
  for v := (Self.Y2 - 1) downto Self.Y1 do
    Result[r.Decrement] := Point(Self.X2, v);
  for h := (Self.X2 - 1) downto Self.X1 do
    Result[r.Decrement] := Point(h, Self.Y1);
end;

{==============================================================================]
  <Shell>
  @action: Returns an array of points representing the outline/perimeter of
           the box.
  @returns: Array of TPoint containing all border points in clockwise order.
  @note: Includes corners and edges. Useful for drawing box outlines or
         collision detection along the perimeter.
[==============================================================================}
function TBox.Shell: TPointArray; overload;
var
  i, r: Integer;
begin
  if ((Self.Width <= 1) or (Self.Height <= 1)) then
    Exit(Self.All);
  SetLength(Result, ((2 * (Self.Width + Self.Height)) - 4));
  r := 0;
  for i := Self.X1 to Self.X2 do
    Result[r.Increase] := Point(i, Self.Y1);
  for i := (Self.Y1 + 1) to Self.Y2 do
    Result[r.Increase] := Point(Self.X2, i);
  for i := (Self.X2 - 1) downto Self.X1 do
    Result[r.Increase] := Point(i, Self.Y2);
  for i := (Self.Y2 - 1) downto (Self.Y1 + 1) do
    Result[r.Increase] := Point(Self.X1, i);
end;

{==============================================================================]
  <Verge>
  @action: Returns every distinct pixel forming the outer border of the box, walked one step at a time in clockwise order starting from the top-left corner.
  @note: Uses no explicit direction state — each step is inferred purely from the current point's position relative to the four edges, corners triggering a turn.
         Degenerate boxes (width or height <= 1, or invalid/inverted bounds) defer entirely to Self.All rather than a specialized dispatch.
[==============================================================================}
function TBox.Verge: TPointArray; overload;
var
  i: Integer;
  p: TPoint;
  procedure R; overload;
  begin
    case (p.X = Self.X1) of
      False:
      case (p.X = Self.X2) of
        True:
        if (p.Y = Self.Y1) then
          Inc(p.Y)
        else if (p.Y = Self.Y2) then
          Dec(p.X)
        else
          Inc(p.Y);
        False:
        if (p.Y = Self.Y1) then
          Inc(p.X)
        else if (p.Y = Self.Y2) then
          Dec(p.X);
      end;
      True:
      if (p.Y = Self.Y1) then
        Inc(p.X)
      else if (p.Y = Self.Y2) then
        Dec(p.Y)
      else
        Dec(p.Y);
    end;
    Result[i] := p;
  end;
begin
  if ((Self.X2 <= Self.X1) or (Self.Y2 <= Self.Y1)) then
    Exit(Self.All);
  p := Point(Self.X1, (Self.Y1 + 1));
  for i := 0 to Result.Alloc(Self.Perimeter) do
    R;
end;
{$ENDIF}
