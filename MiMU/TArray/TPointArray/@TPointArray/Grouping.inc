{$IFDEF HELPERS}
function XGrouped: T2DPointArray; overload;
function XGroupify(const oAscending: Boolean = True): T2DPointArray; overload;
function XGrouping: T2DPointArray; overload;
function XGroups(const oAscending: Boolean = True): T2DPointArray; overload;
function YGrouped: T2DPointArray; overload;
function YGroupify(const oAscending: Boolean = True): T2DPointArray; overload;
function YGrouping: T2DPointArray; overload;
function YGroups(const oAscending: Boolean = True): T2DPointArray; overload;
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
  <XGroupify>
  @action: Groups the points in the TPointArray by their X-coordinate into a T2DPointArray.
  @note: Sorts the array using QuickSortByYX (based on oAscending) and then groups consecutive points that share the same X-coordinate.
[==============================================================================}
function TPointArrayHelper.XGroupify(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i, g, b, s: Integer;
  r: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := Self.Copy;
  r.QuickSortByYX(oAscending);
  g := 1;
  for i := 1 to (s - 1) do
    if (r[i].X <> r[i - 1].X) then
      Inc(g);
  SetLength(Result, g);
  g := 0;
  b := 0;
  for i := 1 to s do
    if ((i = s) or (r[i].X <> r[i - 1].X)) then
    begin
      SetLength(Result[g], (i - b));
      Move(r[b], Result[g][0], ((i - b) * SizeOf(TPoint)));
      Inc(g);
      b := i;
    end;
end;

{==============================================================================]
  <XGrouping>
  @action: Groups the points in the TPointArrayHelper by their X-coordinate into a T2DPointArray without sorting.
  @note: Uses a counting/survey approach based on the X range of the points to group them in linear time complexity.
[==============================================================================}
function TPointArrayHelper.XGrouping: T2DPointArray; overload;
var
  s, i, j, g: Integer;
  c, z: TIntegerArray;
  x, y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(c, (x.stop - x.start + 1));
  SetLength(z, (x.stop - x.start + 1));
  for i := 0 to (s - 1) do
    Inc(c[Self[i].X - x.start]);
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
    j := (Self[i].X - x.start);
    Result[z[j]][c[j]] := Self[i];
    Inc(c[j]);
  end;
end;

{==============================================================================]
  <XGroups>
  @action: Groups points into a 2D point array by their X coordinates using a sorted linear scan.
  @note: Copies and sorts the points using QuickSortByYX, then partitions them into sub-arrays based on matching X values.
         Pre-allocates memory and trims dynamic array sizes for optimization.
[==============================================================================}
function TPointArrayHelper.XGroups(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i, g, s, l, p: Integer;
  r: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := Self.Copy;
  r.QuickSortByYX(oAscending);
  SetLength(Result, s);
  SetLength(Result[0], s);
  Result[0][0] := r[0];
  g := 0;
  p := 1;
  for i := 1 to High(r) do
    if (r[i].X <> r[i - 1].X) then
    begin
      SetLength(Result[g], p);
      p := 1;
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], ((s - i) + 1));
      Result[g][0] := r[i];
    end else
      Result[g][p.Increase] := r[i];
  SetLength(Result[g], p);
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

{==============================================================================]
  <YGroupify>
  @action: Groups the points in the TPointArray by their Y-coordinate into a T2DPointArray.
  @note: Sorts the array using QuickSortByXY (based on oAscending) and then groups consecutive points that share the same Y-coordinate.
[==============================================================================}
function TPointArrayHelper.YGroupify(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i, g, b, s: Integer;
  r: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := Self.Copy;
  r.QuickSortByXY(oAscending);
  g := 1;
  for i := 1 to (s - 1) do
    if (r[i].Y <> r[i - 1].Y) then
      Inc(g);
  SetLength(Result, g);
  g := 0;
  b := 0;
  for i := 1 to s do
    if ((i = s) or (r[i].Y <> r[i - 1].Y)) then
    begin
      SetLength(Result[g], (i - b));
      Move(r[b], Result[g][0], ((i - b) * SizeOf(TPoint)));
      Inc(g);
      b := i;
    end;
end;

{==============================================================================]
  <YGrouping>
  @action: Groups the points in the TPointArrayHelper by their Y-coordinate into a T2DPointArray without sorting.
  @note: Uses a counting/survey approach based on the Y range of the points to group them in linear time complexity.
[==============================================================================}
function TPointArrayHelper.YGrouping: T2DPointArray; overload;
var
  s, i, j, g: Integer;
  r, z: TIntegerArray;
  x, y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Self.Survey(x, y);
  SetLength(r, (y.stop - y.start + 1));
  SetLength(z, (y.stop - y.start + 1));
  for i := 0 to (s - 1) do
    Inc(r[Self[i].Y - y.start]);
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
    j := (Self[i].Y - y.start);
    Result[z[j]][r[j]] := Self[i];
    Inc(r[j]);
  end;
end;

{==============================================================================]
  <YGroups>
  @action: Groups points into a 2D point array by their Y coordinates using a sorted linear scan.
  @note: Copies and sorts the points using QuickSortByXY, then partitions them into sub-arrays based on matching Y values.
         Pre-allocates memory and trims dynamic array sizes for optimization.
[==============================================================================}
function TPointArrayHelper.YGroups(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i, g, s, l, p: Integer;
  r: TPointArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := Self.Copy;
  r.QuickSortByXY(oAscending);
  SetLength(Result, s);
  SetLength(Result[0], s);
  Result[0][0] := r[0];
  g := 0;
  p := 1;
  for i := 1 to High(r) do
    if (r[i].Y <> r[i - 1].Y) then
    begin
      SetLength(Result[g], p);
      p := 1;
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], ((s - i) + 1));
      Result[g][0] := r[i];
    end else
      Result[g][p.Increase] := r[i];
  SetLength(Result[g], p);
end;
{$ENDIF}
