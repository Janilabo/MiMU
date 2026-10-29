{$IFDEF HELPERS}
function Cantoned: TPointArray; overload;
function Moored: TPointArray; overload;
function Patrolled: TPointArray; overload;
function Sounded: TPointArray; overload;
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
{$ENDIF}
