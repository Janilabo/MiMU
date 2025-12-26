{$IFDEF HELPERS}
function BinaryExtract(const area: TBox): TPointArray; overload;
function BinaryFilter(const area: TBox): TPointArray; overload;
function BinaryYPoints(const yValue: Integer): TPointArray; overload;
function BinaryXPoints(const xValue: Integer): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryExtract>
  @action: Returns all points within the specified rectangular area, using
           binary search on the Y-coordinate to minimize the scanned range.
  @note:   The array must be sorted in ascending Y order (scanline order).
           Only points satisfying:
               area.X1 ≤ X ≤ area.X2
               area.Y1 ≤ Y ≤ area.Y2
           are included in the output. The returned array preserves the
           original ordering of points with no duplicates.
[==============================================================================}
function TPointArrayHelper.BinaryExtract(const area: TBox): TPointArray; overload;
var
  R, Y: TRange;
  h, M, i, p, s: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  h := High(Self);
  R.Create(0, h);
  y.Create(-1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y >= area.Y1) then
    begin
      y.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (y.start = -1) then
    Exit;
  R.Create(y.start, h);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y <= area.Y2) then
    begin
      y.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  if (y.stop = -1) then
    Exit;
  s := 0;
  for i := y.start to y.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Inc(s);
  if (s = 0) then
    Exit;
  SetLength(Result, s);
  p := 0;
  for i := y.start to y.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result[p.Increase] := Self[i];
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns a new array containing all points that lie outside the
           specified rectangular area. The function uses binary search on the
           Y-coordinate to exclude the interior scanline interval efficiently.
  @note:   The array must be sorted in ascending Y order (scanline order).
           Points are excluded if and only if they satisfy:
               area.X1 ≤ X ≤ area.X2
               area.Y1 ≤ Y ≤ area.Y2
           All remaining points are preserved in their original order.
[==============================================================================}
function TPointArrayHelper.BinaryFilter(const area: TBox): TPointArray; overload;
var
  h, M, i, s, p: Integer;
  R, Y: TRange;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  h := High(Self);
  R.Create(0, h);
  Y.Create(-1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y >= area.Y1) then
    begin
      Y.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (Y.start = -1) then
    Exit(Self.Copy);
  R.Create(Y.start, h);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y <= area.Y2) then
    begin
      Y.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  if (Y.stop = -1) then
    Exit(Self.Copy);
  s := Y.start;
  Inc(s, (h - Y.stop));
  for i := Y.start to Y.stop do
    if ((Self[i].X < area.X1) or (Self[i].X > area.X2)) then
      Inc(s);
  if (s = 0) then
    Exit;
  SetLength(Result, s);
  p := 0;
  for i := 0 to (Y.start - 1) do
    Result[p.Increase] := Self[i];
  for i := Y.start to Y.stop do
    if ((Self[i].X < area.X1) or (Self[i].X > area.X2)) then
      Result[p.Increase] := Self[i];
  for i := (Y.stop + 1) to h do
    Result[p.Increase] := Self[i];
end;

{==============================================================================]
  <BinaryYPoints>
  @action:
    Returns a TPointArray containing all points with the specified Y-value.
    Uses binary search to locate the first and last indices with that Y.
  @note:
    - The array must be sorted by Y ascending.
    - Returns an empty array if no points match the given Y-value.
    - Efficient: O(log n) search to find the matching range.
[==============================================================================}
function TPointArrayHelper.BinaryYPoints(const yValue: Integer): TPointArray; overload;
var
  h, m, f, l, i: Integer;
  r: TRange;
begin
  h := High(Self);
  SetLength(Result, 0);
  if (h < 0) then
    Exit;
  r.Create(0, h);
  f := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m].Y >= yValue) then
    begin
      if (Self[m].Y = yValue) then
        f := m;
      r.stop := (m - 1);
    end else
      r.start := (m + 1);
  end;
  if (f = -1) then
    Exit;
  r.Create(0, h);
  l := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m].Y <= yValue) then
    begin
      if (Self[m].Y = yValue) then
        l := m;
      r.start := (m + 1);
    end else
      r.stop := (m - 1);
  end;
  SetLength(Result, ((l - f) + 1));
  for i := 0 to High(Result) do
    Result[i] := Self[f + i];
end;

{==============================================================================]
  <BinaryXPoints>
  @action:
    Returns a TPointArray containing all points with the specified X-value.
    For each Y-row in the array, it uses BinaryYPoints to get all points in that row,
    then performs a binary search within the row to find points with X = XValue.
  @note:
    - The array must be sorted in **scanline order** (Y ascending, then X ascending within each Y).
    - Returns an empty array if no points match the given X-value.
    - Efficient: O(R * log N) where R = number of distinct Y-rows, N = points per row.
    - Depends only on BinaryYPoints; does not rely on BinaryYRange or BinaryYs.
[==============================================================================}
function TPointArrayHelper.BinaryXPoints(const xValue: Integer): TPointArray; overload;
var
  h, i, a, c, y, m: Integer;
  p: TPointArray;
  r, s: TRange;
begin
  h := High(Self);
  SetLength(Result, 0);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    p := Self.BinaryYPoints(y);
    if p.Empty then
    begin
      Inc(i);
      Continue;
    end;
    s.Create(0, High(p));
    r.start := -1;
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (p[m].X >= xValue) then
      begin
        if (p[m].X = xValue) then
          r.start := m;
        s.stop := (m - 1);
      end else
        s.start := (m + 1);
    end;
    if (r.start = -1) then
    begin
      Inc(i);
      Continue;
    end;
    s.Create(0, High(p));
    r.stop := -1;
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (p[m].X <= xValue) then
      begin
        if (p[m].X = xValue) then
          r.stop := m;
        s.start := (m + 1);
      end else
        s.stop := (m - 1);
    end;
    if (r.stop >= r.start) then
    begin
      a := ((r.stop - r.start) + 1);
      c := Result.Size;
      SetLength(Result, (c + a));
      for m := 0 to (a - 1) do
        Result[c + m] := p[r.start + m];
    end;
    Inc(i, p.Size);
  end;
end;
{$ENDIF}
