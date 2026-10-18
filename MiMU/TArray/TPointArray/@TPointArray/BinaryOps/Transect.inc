{$IFDEF HELPERS}
function BinaryXy(const atY: Integer): TIntegerArray; overload;
function BinaryYx(const atX: Integer): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryXy>
  @action: Extracts all X coordinates from points that match a specified Y coordinate,
           using binary search.
  @note: Requires Self to be sorted by Y, then X. The matching points form one
         contiguous block, located with a lower and upper bound search. The result
         is sorted ascending. Returns an empty array if no point matches.
[==============================================================================}
function TPointArrayHelper.BinaryXy(const atY: Integer): TIntegerArray; overload;
var
  s, l, h, m, b, i: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  l := 0;
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (Self[m].Y < atY) then
      l := (m + 1)
    else
      h := m;
  end;
  b := l;
  if ((b >= s) or (Self[b].Y <> atY)) then
    Exit([]);
  h := s;
  while (l < h) do
  begin
    m := ((l + h) shr 1);
    if (Self[m].Y <= atY) then
      l := (m + 1)
    else
      h := m;
  end;
  SetLength(Result, (l - b));
  for i := b to (l - 1) do
    Result[i - b] := Self[i].X;
end;

{==============================================================================]
  <BinaryYx>
  @action: Extracts all Y coordinates from points that match a specified X coordinate,
           using binary search.
  @note: Requires Self to be sorted by Y, then X. Matching points are not contiguous
         in this order, so each Y row is located by binary search for its end, then
         searched for atX within the row (X is sorted inside a row). The result is
         sorted ascending. Cost is O(rows * log n), so it is fastest when rows are long.
[==============================================================================}
function TPointArrayHelper.BinaryYx(const atX: Integer): TIntegerArray; overload;
var
  s, i, r, y, e, l, h, m: Integer;
begin
  s := Self.Length;
  if (Result.SetSize(s) = 0) then
    Exit;
  r := 0;
  i := 0;
  while (i < s) do
  begin
    y := Self[i].Y;
    l := (i + 1);
    h := s;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if (Self[m].Y <= y) then
        l := (m + 1)
      else
        h := m;
    end;
    e := l;
    l := i;
    h := e;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if (Self[m].X < atX) then
        l := (m + 1)
      else
        h := m;
    end;
    while ((l < e) and (Self[l].X = atX)) do
    begin
      Result[r.Increase] := y;
      Inc(l);
    end;
    i := e;
  end;
  SetLength(Result, r);
end;
{$ENDIF}
