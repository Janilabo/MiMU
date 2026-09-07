{$IFDEF HELPERS}
function LineTo(const target: TPoint): TPointArray; overload;
function Ring(const radius: UInt32 = 0): TPointArray; overload;
function Scanline(const radius: UInt32 = 0): TPointArray; overload;
function Scanline(const pt: TPoint; const radius: UInt32 = 0): UInt32; overload;
function Spiral(const radius: UInt32 = 0): TPointArray; overload;
function Unring(const index: UInt32 = 0): TPoint; overload;
function Unscanline(const index: UInt32; const radius: UInt32 = 0): TPoint; overload;
function Unspiral(const index: UInt32 = 0): TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <LineTo>
  @action: Generates a continuous grid line of points from Self to pt (inclusive)
           using Bresenham's Line Algorithm.
  @note:   Result[0] is always Self. The total number of points returned is
           Max(Abs(pt.X - Self.X), Abs(pt.Y - Self.Y)) + 1.
[==============================================================================}
function TPointHelper.LineTo(const target: TPoint): TPointArray; overload;
var
  x, y, r, e, z: Integer;
  s, d: TPoint;
begin
  d := Point(Abs(target.X - Self.X), Abs(target.Y - Self.Y));
  s := Point(IfThen((Self.X < target.X), 1, -1), IfThen((Self.Y < target.Y), 1, -1));
  if (d.X > d.Y) then
    SetLength(Result, (d.X + 1))
  else
    SetLength(Result, (d.Y + 1));
  x := Self.X;
  y := Self.Y;
  e := (d.X - d.Y);
  r := 0;
  while True do
  begin
    Result[r.Increase] := Point(x, y);
    if ((x = target.X) and (y = target.Y)) then
      Break;
    z := (2 * e);
    if (z > -d.Y) then
    begin
      Dec(e, d.Y);
      Inc(x, s.X);
    end;
    if (z < d.X) then
    begin
      Inc(e, d.X);
      Inc(y, s.Y);
    end;
  end;
end;

{==============================================================================]
  <Ring>
  @action: Generates a square grid centered at Self arranged as complete
           concentric rings outward (radius 0 = 1 point, radius 1 = 9 points,
           radius 2 = 25 points...). Within each ring 'r', points walk clockwise
           around the perimeter starting at top-left (-r, -r).
  @note: Produces (2*radius + 1)^2 points. Every index range [(2r-1)^2 .. (2r+1)^2 - 1]
         forms a completely closed perimeter boundary around Self.
[==============================================================================}
function TPointHelper.Ring(const radius: UInt32 = 0): TPointArray; overload;
var
  r, l, s, i, x, y: Integer;
  c: TPoint;
begin
  if (radius = 0) then
    Exit([Self]);
  Result.SetSize(Sqr((Int64(radius) * 2) + 1));
  Result[0] := Self;
  c := Self;
  i := 1;
  for r := 1 to Integer(radius) do
  begin
    l := (2 * r);
    x := (c.X - r);
    y := (c.Y - r);
    for s := 1 to l do
      Result[i.Increase] := Point(x.Increase, y);
    for s := 1 to l do
      Result[i.Increase] := Point(x, y.Increase);
    for s := 1 to l do
      Result[i.Increase] := Point(x.Decrease, y);
    for s := 1 to l do
      Result[i.Increase] := Point(x, y.Decrease);
  end;
end;

{==============================================================================]
  <Scanline>
  @action: Generates a square grid centered at Self covered row-by-row, from
           top-left to bottom-right (left-to-right on each row, moving down).
  @note:   radius = 0 returns 1 point (Self). radius = 1 returns 9 points
           covering a 3x3 block from (-1,-1) to (+1,+1). The total count
           is always (2*radius + 1)^2.
[==============================================================================}
function TPointHelper.Scanline(const radius: UInt32 = 0): TPointArray; overload;
var
  x, y, r: Integer;
  b: TBox;
begin
  Result.SetSize(Sqr((Integer(radius) * 2) + 1));
  r := Integer(radius);
  b := Box((Self.X - r), (Self.Y - r), (Self.X + r), (Self.Y + r));
  r := 0;
  for y := b.Y1 to b.Y2 do
    for x := b.X1 to b.X2 do
      Result[r.Increase] := Point(x, y);
end;

{==============================================================================]
  <Scanline>
  @action: Calculates the 0-based step index of a target point within a scanline
           grid of given radius centered at Self in O(1) constant time.
  @note:   Inverse of Unscanline.
[==============================================================================}
function TPointHelper.Scanline(const pt: TPoint; const radius: UInt32 = 0): UInt32; overload;
begin
  Result := UInt32(((pt.Y - (Self.Y - Integer(radius))) * ((Integer(radius) * 2) + 1)) + (pt.X - (Self.X - Integer(radius))));
end;

{==============================================================================]
  <Spiral>
  @action: Walks a continuous square spiral outward from Self, one cell at a
           time, cycling direction up -> right -> down -> left with step
           lengths 1, 1, 2, 2, 3, 3, 4, 4, ... (classic Ulam-spiral
           construction), and returns the visited cells in walk order.
  @note: radius = 0 returns only Self (length 1). radius = 2 returns 25
         points covering the full 5x5 block, ending mid-leg the instant
         that count is reached. This is a single connected path, not a set
         of disjoint concentric rings — each cell is derived from the one
         before it (Result[r-1]), so the array is meaningful only in order,
         never as an unordered set.
[==============================================================================}
function TPointHelper.Spiral(const radius: UInt32 = 0): TPointArray; overload;
const
  w: array[0..3] of Integer = (0, 1, 0, -1);
  h: array[0..3] of Integer = (-1, 0, 1, 0);
var
  s, r, i, d, l, t: Integer;
begin
  s := Result.SetSize(Sqr((Int64(radius) * 2) + 1));
  Result[0] := Self;
  r := 0;
  t := 0;
  while (r < s) do
  begin
    d := (t mod 4);
    l := ((t div 2) + 1);
    for i := 1 to l do
      if (r.Increment < s) then
	    Result[r] := Point((Result[r - 1].X + w[d]), (Result[r - 1].Y + h[d]))
	  else
        Break;
    Inc(t);
  end;
end;

{==============================================================================]
  <Unringed>
  @action: Computes the point at a given step index along Self's ringed walk
           (see Ringed) in pure O(1) constant time without loops.
  @note:   Identifies ring layer 'r' via integer square root, then computes
           the exact side and perimeter offset along that ring.
[==============================================================================}
function TPointHelper.Unring(const index: UInt32 = 0): TPoint; overload;
var
  r, l, i, d, s: Integer;
  p: TPoint;
procedure A(const x, y: Integer);
begin
  Result.X := (Result.X + x);
  Result.Y := (Result.Y + y);
end;
begin
  if (index = 0) then
    Exit(Self);
  r := ((Trunc(Sqrt(index)) + 1) div 2);
  i := (index - (Sqr(2 * (r - 1) + 1) - 1) - 1);
  l := (2 * r);
  d := (i div l);
  s := (i mod l);
  Result := Self;
  case d of
    0: A((-r + s), -r);
    1: A(r, (-r + s));
    2: A((r - s), r);
    3: A(-r, (r - s));
  end;
end;

{==============================================================================]
  <Unscanline>
  @action: Computes the point at a given step index along Self's scanline walk
           for a grid of specified radius in pure O(1) constant time.
  @note:   Uses integer division and modulo against the row width (2*radius + 1)
           to directly map index to (X, Y) coordinates relative to Self.
[==============================================================================}
function TPointHelper.Unscanline(const index: UInt32; const radius: UInt32 = 0): TPoint; overload;
var
  w, r, c: Integer;
begin
  if ((index = 0) and (radius = 0)) then
    Exit(Self);
  w := ((Integer(radius) * 2) + 1);
  r := (Integer(index) div w);
  c := (Integer(index) mod w);
  Result.X := ((Self.X - Integer(radius)) + c);
  Result.Y := ((Self.Y - Integer(radius)) + r);
end;

{==============================================================================]
  <Unspiral>
  @action: Computes the point at a given step index along Self's spiral walk
           (see Spiral) without materializing the array — jumps leg by leg
           (up -> right -> down -> left, lengths 1,1,2,2,3,3,...), consuming
           each leg in a single step when index reaches or passes its end.
  @note: index = 0 returns Self. Result is identical to Spiral(radius)[index]
         for any radius large enough that index is in range, but costs
         O(sqrt(index)) rather than O(index) since whole legs are skipped
         in one jump instead of being walked cell by cell.
[==============================================================================}
function TPointHelper.Unspiral(const index: UInt32 = 0): TPoint; overload;
const
  w: array[0..3] of Integer = (0, 1, 0, -1);
  h: array[0..3] of Integer = (-1, 0, 1, 0);
var
  x, y, r, d, l, t, s: Integer;
begin
  if (index = 0) then
    Exit(Self);
  x := Self.X;
  y := Self.Y;
  r := Integer(index);
  t := 0;
  while (r > 0) do
  begin
    d := (t mod 4);
    l := ((t div 2) + 1);
    s := l;
    if (s > r) then
      s := r;
    Inc(x, (w[d] * s));
    Inc(y, (h[d] * s));
    Dec(r, s);
    Inc(t);
  end;
  Result := Point(x, y);
end;
{$ENDIF}
