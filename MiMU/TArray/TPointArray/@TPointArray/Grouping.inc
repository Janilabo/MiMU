{$IFDEF HELPERS}
function XGrouped: T2DPointArray; overload;
function YGrouped: T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <XGrouped>
  @action: Groups points sharing the same X (columns). Returns new T2DPointArray.
  @note: Non-mutating; Self is left untouched.
   - Groups are ordered by X ascending, points inside a group by Y ascending.
   - Result[i] is one column; empty Self returns [].
   - Two stable counting passes, O(n + rangeX + rangeY) time and memory.
[==============================================================================}
function TPointArrayHelper.XGrouped: T2DPointArray; overload;
var
  s, i, j, g: Integer;
  c, r, z: TIntegerArray;
  t: TPointArray;
  x, y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(r, (y.stop - y.start + 2));
  SetLength(c, (x.stop - x.start + 1));
  SetLength(z, (x.stop - x.start + 1));
  for i := 0 to (s - 1) do
  begin
    Inc(r[Self[i].Y - y.start + 1]);
    Inc(c[Self[i].X - x.start]);
  end;
  for i := 1 to High(r) do
    Inc(r[i], r[i - 1]);
  for i := 0 to t.Alloc(s) do
    t[r[Self[i].Y - y.start].Increase] := Self[i];
  g := 0;
  for i := 0 to High(c) do
    if (c[i] > 0) then
      z[i] := g.Increase;
  SetLength(Result, g);
  for i := 0 to High(c) do
    if (c[i] > 0) then
    begin
      SetLength(Result[z[i]], c[i]);
      c[i] := 0;
    end;
  for i := 0 to (s - 1) do
  begin
    j := (t[i].X - x.start);
    Result[z[j]][c[j]] := t[i];
    Inc(c[j]);
  end;
end;

{==============================================================================]
  <YGrouped>
  @action: Groups points sharing the same Y (rows). Returns new T2DPointArray.
  @note: Non-mutating; Self is left untouched.
   - Groups are ordered by Y ascending, points inside a group by X ascending.
   - Result[i] is one row; empty Self returns [].
   - Two stable counting passes, O(n + rangeX + rangeY) time and memory.
[==============================================================================}
function TPointArrayHelper.YGrouped: T2DPointArray; overload;
var
  s, i, j, g: Integer;
  c, r, z: TIntegerArray;
  t: TPointArray;
  x, y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(c, (x.stop - x.start + 2));
  SetLength(r, (y.stop - y.start + 1));
  SetLength(z, (y.stop - y.start + 1));
  for i := 0 to (s - 1) do
  begin
    Inc(c[Self[i].X - x.start + 1]);
    Inc(r[Self[i].Y - y.start]);
  end;
  for i := 1 to High(c) do
    Inc(c[i], c[i - 1]);
  for i := 0 to t.Alloc(s) do
    t[c[Self[i].X - x.start].Increase] := Self[i];
  g := 0;
  for i := 0 to High(r) do
    if (r[i] > 0) then
      z[i] := g.Increase;
  SetLength(Result, g);
  for i := 0 to High(r) do
    if (r[i] > 0) then
    begin
      SetLength(Result[z[i]], r[i]);
      r[i] := 0;
    end;
  for i := 0 to (s - 1) do
  begin
    j := (t[i].Y - y.start);
    Result[z[j]][r[j]] := t[i];
    Inc(r[j]);
  end;
end;
{$ENDIF}
