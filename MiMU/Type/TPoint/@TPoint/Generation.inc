{$IFDEF HELPERS}
function LineTo(const target: TPoint): TPointArray; overload;
function Ring(const radius: UInt32 = 0): TPointArray; overload;
function Scanline(const radius: UInt32 = 0): TPointArray; overload;
function Scanline(const pt: TPoint; const radius: UInt32 = 0): UInt32; overload;
function Spiral(const radius: UInt32 = 0): TPointArray; overload;
function Unring(const index: UInt32 = 0): TPoint; overload;
function Unscanline(const index: UInt32; const radius: UInt32 = 0): TPoint; overload;
function Unspiral(const index: UInt32 = 0): TPoint; overload;
function Unspiral(const target: TPoint): UInt32; overload;
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
    0: Result.Increase((-r + s), -r);
    1: Result.Increase(r, (-r + s));
    2: Result.Increase((r - s), r);
    3: Result.Increase(-r, (r - s));
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
  r, d, l, t, s: Integer;
begin
  Result := Self;
  if (index = 0) then
    Exit;
  r := Integer(index);
  t := 0;
  while (r > 0) do
  begin
    d := (t mod 4);
    l := ((t div 2) + 1);
    s := l;
    if (s > r) then
      s := r;
    Result.Increase((w[d] * s), (h[d] * s));
    Dec(r, s);
    Inc(t);
  end;
end;

{==============================================================================]
  <Unspiral>
  @action: Given a `target` point, returns its index in the continuous square (Ulam) spiral
           walk centered on `Self` — the inverse of `Unspiral(index): TPoint`.
  @note: Walks leg-by-leg (up, right, down, left; lengths 1,1,2,2,3,3,...) rather than
         cell-by-cell, checking each leg's value-range bracket in O(1) before advancing —
         O(distance) iterations overall, the same complexity class as the index-to-point
         overload's O(sqrt(index)), since index scales with distance squared. `Self` itself
         returns 0 via an explicit short-circuit before the loop.
[==============================================================================}
function TPointHelper.Unspiral(const target: TPoint): UInt32; overload;
const
  w: array[0..3] of Integer = (0, 1, 0, -1);
  h: array[0..3] of Integer = (-1, 0, 1, 0);
var
  t, m, l, a: Integer;
  r, d: TPoint;
begin
  d := Point((target.X - Self.X), (target.Y - Self.Y));
  if ((d.X = 0) and (d.Y = 0)) then
    Exit(0);
  r := Point(0, 0);
  t := 0;
  a := 0;
  while True do
  begin
    m := (t mod 4);
    l := ((t div 2) + 1);
    case m of
      0: if ((d.X = r.X) and (d.Y <= r.Y) and (d.Y >= (r.Y - l))) then
           Exit(a + (r.Y - d.Y));
      1: if ((d.Y = r.Y) and (d.X >= r.X) and (d.X <= (r.X + l))) then
           Exit(a + (d.X - r.X));
      2: if ((d.X = r.X) and (d.Y >= r.Y) and (d.Y <= (r.Y + l))) then
           Exit(a + (d.Y - r.Y));
      3: if ((d.Y = r.Y) and (d.X <= r.X) and (d.X >= (r.X - l))) then
           Exit(a + (r.X - d.X));
    end;
    r.Increase((w[m] * l), (h[m] * l));
    Inc(a, l);
    Inc(t);
  end;
end;
{$ENDIF}
