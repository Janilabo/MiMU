{$IFDEF HELPERS}
function Cleave(const radius: Double = 2): T2DPointArray; overload;
function Fracture(const radius: Double = 2.0): T2DPointArray; overload;
function Mesh(const radius: Double = 2.0): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cleave>
  @action: Splits the point array into clusters by identifying axis-aligned coordinate gaps greater than the specified radius.
  @note: Uses fast coordinate sorting and bucket grouping along the X and Y axes. Returns an empty array if empty, or [Self] if single or no gaps are found.
[==============================================================================}
function TPointArrayHelper.Cleave(const radius: Double = 2): T2DPointArray; overload;
var
  kx, ky, ox, oy, sx, sy, cx, cy, p, q: TIntegerArray;
  n, d, i, j, k, g, h, r: Integer;
begin
  n := Self.Length;
  case n of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Floor(radius);
  SetLength(kx, n);
  SetLength(ky, n);
  for i := 0 to (n - 1) do
  begin
    kx[i] := Self[i].X;
    ky[i] := Self[i].Y;
  end;
  ox := kx.QuickSortition;
  oy := ky.QuickSortition;
  SetLength(sx, n);
  SetLength(sy, n);
  g := 0;
  sx[ox[0]] := 0;
  for i := 1 to (n - 1) do
  begin
    if ((kx[ox[i]] - kx[ox[i - 1]]) > d) then
      Inc(g);
    sx[ox[i]] := g;
  end;
  h := 0;
  sy[oy[0]] := 0;
  for i := 1 to (n - 1) do
  begin
    if ((ky[oy[i]] - ky[oy[i - 1]]) > d) then
      Inc(h);
    sy[oy[i]] := h;
  end;
  if ((g = 0) and (h = 0)) then
    Exit([Self]);
  SetLength(cy, (h + 2));
  for i := 0 to (n - 1) do
    Inc(cy[sy[i] + 1]);
  for i := 1 to (h + 1) do
    Inc(cy[i], cy[i - 1]);
  SetLength(p, n);
  for i := 0 to (n - 1) do
  begin
    p[cy[sy[i]]] := i;
    Inc(cy[sy[i]]);
  end;
  SetLength(cx, (g + 2));
  for i := 0 to (n - 1) do
    Inc(cx[sx[i] + 1]);
  for i := 1 to (g + 1) do
    Inc(cx[i], cx[i - 1]);
  SetLength(q, n);
  for i := 0 to (n - 1) do
  begin
    q[cx[sx[p[i]]]] := p[i];
    Inc(cx[sx[p[i]]]);
  end;
  r := 1;
  for i := 1 to (n - 1) do
    if ((sx[q[i]] <> sx[q[i - 1]]) or (sy[q[i]] <> sy[q[i - 1]])) then
      Inc(r);
  SetLength(Result, r);
  r := 0;
  j := 0;
  for i := 1 to n do
    if ((i = n) or (sx[q[i]] <> sx[q[j]]) or (sy[q[i]] <> sy[q[j]])) then
    begin
      SetLength(Result[r], (i - j));
      for k := j to (i - 1) do
        Result[r][k - j] := Self[q[k]];
      Inc(r);
      j := i;
    end;
end;

{==============================================================================]
  <Fracture>
  @action: Merges and partitions points into clusters by sorting along the X-axis 
           and evaluating interval spans within the given radius.
  @note: Uses a sorted linear scan to chain adjacent points where either X or Y distance
         is within the radius. Returns a T2DPointArray of segmented clusters.
[==============================================================================}
function TPointArrayHelper.Fracture(const radius: Double = 2.0): T2DPointArray; overload;
var
  l, i: Integer;
  s: TPointArray;
  r: TPointArray;
  d: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Floor(radius);
  s := Self.Clone;
  s.QuickSortByX;
  SetLength(Result, 0);
  r := [s[0]];
  for i := 1 to (l - 1) do
    if not ((Abs(s[i].X - s[i - 1].X) <= d) or (Abs(s[i].Y - s[i - 1].Y) <= d)) then
    begin
	  Result.Supply(r);
      r := [s[i]];
    end else
      r.Supply(s[i]);
  if (r.Length > 0) then
    Result.Supply(r);
end;

{==============================================================================]
  <Mesh>
  @action: Partitions points into clusters using a sliding sweep-line window
           to maintain and merge overlapping coordinate intervals.
  @note: Better handles complex overlapping chains where points bridge gaps across multi-point spans.
[==============================================================================}
function TPointArrayHelper.Mesh(const radius: Double = 2.0): T2DPointArray; overload;
var
  l, i, j, k: Integer;
  s: TPointArray;
  m: TBooleanArray;
  r: TPointArray;
  d: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Floor(radius);
  s := Self.Copy;
  s.QuickSortByX;
  SetLength(m, l);
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
    if not m[i] then
    begin
      r := [s[i]];
      m[i] := True;
      j := -1;
      while (j.Increment < r.Length) do
        for k := 0 to (l - 1) do
          if not m[k] then
            if ((Abs(r[j].X - s[k].X) <= d) and (Abs(r[j].Y - s[k].Y) <= d)) then
            begin
              m[k] := True;
              r.Supply(s[k]);
            end;
      SetLength(Result, (Result.Length + 1));
      Result[High(Result)] := r;
    end;
end;
{$ENDIF}
