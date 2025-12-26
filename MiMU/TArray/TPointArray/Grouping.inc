{$IFDEF HELPERS}
function ToRows: T2DPointArray;
function ToColumns: T2DPointArray;
function AsRows: T2DPointArray;
function AsColumns: T2DPointArray;
function Rows: T2DPointArray;
function Columns: T2DPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ToRows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: The Y values are sorted and deduplicated before grouping, so the resulting
         row order follows ascending Y. Each subarray of the result contains all
         points that share the same Y value.
[==============================================================================}
function TPointArrayHelper.ToRows: T2DPointArray;
var
  i: Integer;
  y: TIntegerArray;
begin
  y := Self.Ys.QuickSorted.BinaryPruned;
  SetLength(Result, y.Size);
  for i := 0 to High(Self) do
    Result[y.BinarySearch(Self[i].Y)].Supply(Self[i]);
end;

{==============================================================================]
  <ToColumns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: The X values are sorted and deduplicated before grouping, so the resulting
         column order follows ascending X. Each subarray of the result contains all
         points that share the same X value.
[==============================================================================}
function TPointArrayHelper.ToColumns: T2DPointArray;
var
  i: Integer;
  x: TIntegerArray;
begin
  x := Self.Xs.QuickSorted.BinaryPruned;
  SetLength(Result, x.Size);
  for i := 0 to High(Self) do
    Result[x.BinarySearch(Self[i].x)].Supply(Self[i]);
end;

{==============================================================================]
  <AsRows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: The original order of Y values is preserved — rows are created in the
         order each Y first appears in the source array. No sorting or pruning
         is performed.
[==============================================================================}
function TPointArrayHelper.AsRows: T2DPointArray;
var
  i, j: Integer;
  y: TIntegerArray;
  p: Integer;
begin
  SetLength(Result, 0);
  SetLength(y, 0);
  for i := 0 to High(Self) do
  begin
    p := -1;
    for j := 0 to High(y) do
      if (y[j] = Self[i].Y) then
      begin
        p := j;
        Break;
      end;
    if (p = -1) then
    begin
      p := y.Size;
      SetLength(y, (p + 1));
      y[p] := Self[i].Y;
      SetLength(Result, (p + 1));
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <AsColumns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: The original order of X values is preserved — columns are created in the
         order each X first appears in the source array. No sorting or pruning
         is performed.
[==============================================================================}
function TPointArrayHelper.AsColumns: T2DPointArray;
var
  i, j: Integer;
  x: TIntegerArray;
  p: Integer;
begin
  SetLength(Result, 0);
  SetLength(x, 0);
  for i := 0 to High(Self) do
  begin
    p := -1;
    for j := 0 to High(x) do
      if (x[j] = Self[i].X) then
      begin
        p := j;
        Break;
      end;
    if (p = -1) then
    begin
      p := x.Size;
      SetLength(x, (p + 1));
      x[p] := Self[i].X;
      SetLength(Result, (p + 1));
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <Rows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: Each unique Y value defines one row. The order of rows matches the order
         in which distinct Y values first appear in the source array (unsorted).
         Uses a dictionary for O(1) coordinate lookup, providing fast grouping
         while preserving the original encounter order.
[==============================================================================}
function TPointArrayHelper.Rows: T2DPointArray;
var
  i, p: Integer;
  m: specialize TDictionary<Integer, Integer>;
  o: TIntegerArray;
begin
  m := specialize TDictionary<Integer, Integer>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i].Y, p) then
      begin
        p := o.Size;
        SetLength(o, (p + 1));
        o[p] := Self[i].Y;
        m.Add(Self[i].Y, p);
        SetLength(Result, (p + 1));
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;

{==============================================================================]
  <Columns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: Each unique X value defines one column. The order of columns matches the
         order in which distinct X values first appear in the source array (unsorted).
         Uses a dictionary for O(1) coordinate lookup, providing fast grouping
         while preserving the original encounter order.
[==============================================================================}
function TPointArrayHelper.Columns: T2DPointArray;
var
  i, p: Integer;
  m: specialize TDictionary<Integer, Integer>;
  o: TIntegerArray;
begin
  m := specialize TDictionary<Integer, Integer>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i].X, p) then
      begin
        p := o.Size;
        SetLength(o, (p + 1));
        o[p] := Self[i].X;
        m.Add(Self[i].X, p);
        SetLength(Result, (p + 1));
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;
{$ENDIF}
