{$IFDEF HELPERS}
function Cantoned: TPointArray; overload;
function Moored: TPointArray; overload;
function Patrolled: TPointArray; overload;
function Quantized: TPointArray; overload;
function Sounded: TPointArray; overload;
function Stitched: TPointArray; overload;
function Stitched2: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cantoned>
  @action: Generates a stepped/quantized point array by splitting every segment between consecutive points at its midpoint step.
  @note: Segment length is the Chebyshev distance Max(|dx|, |dy|). The first half
         of each segment (midpoint included) is filled with Self[i], the rest with
         Self[i + 1]; the last point closes the result. Zero-length segments add
         nothing. Result length is the sum of the segment lengths + 1.
[==============================================================================}
function TPointArrayHelper.Cantoned: TPointArray; overload;
var
  h, i, j, r, d: Integer;
  c: TPoint;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  r := 0;
  for i := 0 to (h - 1) do
  begin
    c.X := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > c.X) then
      c.X := c.Y;
    Inc(r, c.X);
  end;
  SetLength(Result, (r + 1));
  r := 0;
  for i := 0 to (h - 1) do
  begin
    d := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > d) then
      d := c.Y;
    if (d > 0) then
    begin
      for j := 0 to (d div 2) do
        Result[r.Increase] := Self[i];
      for j := ((d div 2) + 1) to (d - 1) do
        Result[r.Increase] := Self[i + 1];
    end;
  end;
  Result[r] := Self[h];
end;

{==============================================================================]
  <Moored>
  @action: Generates a stepped/quantized point array via nearest-neighbour interpolation between consecutive points.
  @note: Segment length is the Chebyshev distance Max(|dx|, |dy|). Every step j of
         a segment is assigned the nearer endpoint: Self[i] while j <= (d - j)
         (ties go to Self[i]), otherwise Self[i + 1]. Per-step test, single inner loop.
[==============================================================================}
function TPointArrayHelper.Moored: TPointArray; overload;
var
  h, i, j, r, d: Integer;
  c: TPoint;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  r := 0;
  for i := 0 to (h - 1) do
  begin
    c.X := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > c.X) then
      c.X := c.Y;
    Inc(r, c.X);
  end;
  SetLength(Result, (r + 1));
  r := 0;
  for i := 0 to (h - 1) do
  begin
    d := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > d) then
      d := c.Y;
    for j := 0 to (d - 1) do
      if (j <= (d - j)) then
        Result[r.Increase] := Self[i]
      else
        Result[r.Increase] := Self[i + 1];
  end;
  Result[r] := Self[h];
end;

{==============================================================================]
  <Patrolled>
  @action: Generates a stepped/quantized point array via a forward-sweeping nearest-neighbour interpolation along the whole path.
  @note: Sweeps one global step index r from 0 to the total length and advances
         the active segment (i, first step s, length d) whenever r crosses its end.
         Zero-length segments are skipped by the advance loop. The nearer endpoint
         of the active segment is assigned to each step; ties go to Self[i].
[==============================================================================}
function TPointArrayHelper.Patrolled: TPointArray; overload;
var
  h, i, r, s, d, t: Integer;
  c: TPoint;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  t := 0;
  for i := 0 to (h - 1) do
  begin
    c.X := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > c.X) then
      c.X := c.Y;
    Inc(t, c.X);
  end;
  i := -1;
  s := 0;
  d := 0;
  for r := 0 to Result.Alloc(t + 1) do
  begin
    while ((i < (h - 1)) and (r >= (s + d))) do
    begin
      Inc(s, d);
      Inc(i);
      d := Abs(Self[i + 1].X - Self[i].X);
      c.Y := Abs(Self[i + 1].Y - Self[i].Y);
      if (c.Y > d) then
        d := c.Y;
    end;
    if ((r - s) <= (d - (r - s))) then
      Result[r] := Self[i]
    else
      Result[r] := Self[i + 1];
  end;
end;

{==============================================================================]
  <Quantized>
  @action: Single-pass Chebyshev quantization using dynamic array growth.
  @note: Eliminates the first calculation loop at the cost of slight reallocation overhead.
[==============================================================================}
function TPointArrayHelper.Quantized: TPointArray; overload;
var
  h, i, j, d: Integer;
  c: TPoint;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  Result := [Self[0]];
  for i := 0 to (h - 1) do
  begin
    d := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > d) then
      d := c.Y;
    for j := 0 to (d - 1) do
      if (j <= (d - j)) then
        Result.Supply(Self[i])
      else
        Result.Supply(Self[i + 1]);
  end;
  Result.Supply(Self[h]);
end; 

{==============================================================================]
  <Sounded>
  @action: Generates a stepped/quantized point array via a binary-search-based nearest-neighbour interpolation along the whole path.
  @note: Builds the cumulative start step of every segment once, then finds the
         active segment of each step in O(log h) with a binary search over those
         offsets. Same results as Patrolled; differs in how the segment is located.
[==============================================================================}
function TPointArrayHelper.Sounded: TPointArray; overload;
var
  h, i, l, m, u, r, d, j: Integer;
  c: TPoint;
  o: TIntegerArray;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(o, (h + 1));
  for i := 0 to (h - 1) do
  begin
    c.X := Abs(Self[i + 1].X - Self[i].X);
    c.Y := Abs(Self[i + 1].Y - Self[i].Y);
    if (c.Y > c.X) then
      c.X := c.Y;
    o[i + 1] := (o[i] + c.X);
  end;
  for r := 0 to Result.Alloc(o[h] + 1) do
  begin
    l := 0;
    u := (h - 1);
    while (l < u) do
    begin
      m := (l + ((u - l + 1) div 2));
      if (o[m] <= r) then
        l := m
      else
        u := (m - 1);
    end;
    j := (r - o[l]);
    d := (o[l + 1] - o[l]);
    if (j <= (d - j)) then
      Result[r] := Self[l]
    else
      Result[r] := Self[l + 1];
  end;
end;

{==============================================================================]
  <Stitched>
  @action: Generates a continuous line-connected point array between all points.
  @note: Uses standard Bresenham's line algorithm for smooth pixel-perfect traversal.
[==============================================================================}
function TPointArrayHelper.Stitched: TPointArray; overload;
var
  i, e, t: Integer;
  d, s, r: TPoint;
begin
  if (Self.Length < 2) then
    Exit(Self.Copy);
  SetLength(Result, 0);
  Result.Supply(Self[0]);
  for i := 0 to (High(Self) - 1) do
  begin
    r := Self[i];
    d.X := Abs(Self[i + 1].X - r.X);
    d.Y := Abs(Self[i + 1].Y - r.Y);
    if (Self[i].X < Self[i + 1].X) then
      s.X := 1
    else
      s.X := -1;
    if (Self[i].Y < Self[i + 1].Y) then
      s.Y := 1
    else
      s.Y := -1;
    e := (d.X - d.Y);
    while ((r.X <> Self[i + 1].X) or (r.Y <> Self[i + 1].Y)) do
    begin
      t := (2 * e);
      if (t > -d.Y) then
      begin
        e := (e - d.Y);
        r.X := (r.X + s.X);
      end;
      if (t < d.X) then
      begin
        e := (e + d.X);
        r.Y := (r.Y + s.Y);
      end;
      Result.Supply(r);
    end;
  end;
end;

{==============================================================================]
  <Stitched2>
  @action: Generates a continuous, pixel-dense point array by connecting all consecutive points with Bresenham's line algorithm.
  @note: Pre-calculates the exact total path length using the sum of Chebyshev distances 
         Max(|dx|, |dy|) to allocate the result array upfront, avoiding dynamic reallocations 
         during the rasterization loop.
[==============================================================================}
function TPointArrayHelper.Stitched2: TPointArray; overload;
var
  i, e, t, c, l: Integer;
  d, s, r, p: TPoint;
begin
  if (Self.Length < 2) then
    Exit(Self.Copy);
  l := 1;
  for i := 0 to (High(Self) - 1) do
    l := (l + Max(Abs(Self[i + 1].X - Self[i].X), Abs(Self[i + 1].Y - Self[i].Y)));
  SetLength(Result, l);
  Result[0] := Self[0];
  c := 1;
  for i := 0 to (High(Self) - 1) do
  begin
    r := Self[i];
    p := Self[i + 1];
    d.X := Abs(p.X - r.X);
    d.Y := Abs(p.Y - r.Y);
    if (r.X < p.X) then
	  s.X := 1
	else
	  s.X := -1;
    if (r.Y < p.Y) then
	  s.Y := 1
	else
	  s.Y := -1;
    e := (d.X - d.Y);
    while ((r.X <> p.X) or (r.Y <> p.Y)) do
    begin
      t := (2 * e);
      if (t > -d.Y) then
      begin
        e := (e - d.Y);
        r.X := (r.X + s.X);
      end;
      if (t < d.X) then
      begin
        e := (e + d.X);
        r.Y := (r.Y + s.Y);
      end;
      Result[c.Increase] := r;
    end;
  end;
end;
{$ENDIF}
