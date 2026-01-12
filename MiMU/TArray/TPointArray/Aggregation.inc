{$IFDEF HELPERS}
function X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
function XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
function XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
function Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
function YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
function YTo2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function YTo2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <X2D>
  @action: Groups all X-coordinates by their corresponding Y-coordinate.
  @note: Returns 2D array of X values where Result[i] contains all X's for Y = yArr[i].
   - The output parameter yArr receives the sorted list of unique Y values.
   - If no points exist, Result = [].
   - If only one Y value exists, Result = [yArr].
   - When xOrder = True (default), X values are inserted in sorted order
     using BinaryAppend.
   - The xAscending flag determines the sorting direction when xOrder = True.
     (True = ascending, False = descending)
   - When xOrder = False, X values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  yArr := Self.YAxis;
  l := yArr.Length;
  case l of
    0: Exit([]);
    1: Exit([yArr]);
  end;
  SetLength(Result, l);
  case xOrder of
    True:
    for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].BinaryAppend(Self[i].X, xAscending);
	False:
	for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].Supply(Self[i].X);
  end;
end;

{==============================================================================]
  <XAs2D>
  @action: Groups X-coordinates by unique Y values and sorts each X-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Result[i][*] = sorted X values for Y = yArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  x, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
        d.Add(Self[i].Y, p);
      end else
        p := d[Self[i].Y];
      x.Add(Self[i].X);
      p.Add(i);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      p := d[k];
      x.Sort;
      SetLength(Result[i], x.Count);
      SetLength(selfIDs[i], x.Count);
      for j := 0 to (x.Count - 1) do
      begin
        Result[i][j] := x[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for x in g.Values do
      x.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <XAs2D>
  @action: Groups X-coordinates by unique Y values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Order of X values matches original point order.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  x: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
      end;
      x.Add(Self[i].X);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      Result[i.Increase] := x.ToArray;
    end;
  finally
    for x in g.Values do
      x.Free;
    g.Free;
  end;
end;

{==============================================================================]
 <XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted X values.
 @note: The X values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := yArr.Size;
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
      begin
        Result[i][k] := Self[j].X;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := yArr.Size;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Result[i][k.Increase] := Self[j].X;
  end;
end;

{==============================================================================]
  <Y2D>
  @action: Groups all Y-coordinates by their corresponding X-coordinate.
  @note: Returns 2D array of Y values where Result[i] contains all Y's for X = xArr[i].
   - The output parameter xArr receives the sorted list of unique X values.
   - If no points exist, Result = [].
   - If only one X value exists, Result = [xArr].
   - When yOrder = True (default), Y values are inserted in sorted order
     using BinaryAppend.
   - The yAscending flag determines the sorting direction when yOrder = True.
     (True = ascending, False = descending)
   - When yOrder = False, Y values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  xArr := Self.XAxis;
  l := xArr.Length;
  case l of
    0: Exit([]);
    1: Exit([xArr]);
  end;
  SetLength(Result, l);
  case yOrder of
    True:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].BinaryAppend(Self[i].Y, yAscending);
    False:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].Supply(Self[i].Y);
  end;
end;

{==============================================================================]
  <YAs2D>
  @action: Groups Y-coordinates by unique X values and sorts each Y-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Result[i][*] = sorted Y values for X = xArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g, d: specialize TDictionary<Integer, specialize TList<Integer>>;
  y, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
        d.Add(Self[i].X, p);
      end else
        p := d[Self[i].X];
      y.Add(Self[i].Y);
      p.Add(i);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      p := d[k];
      y.Sort;
      SetLength(Result[i], y.Count);
      SetLength(selfIDs[i], y.Count);
      for j := 0 to (y.Count - 1) do
      begin
        Result[i][j] := y[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for y in g.Values do
      y.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <YAs2D>
  @action: Groups Y-coordinates by unique X values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Order of Y values matches original point order.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  y: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
      end;
      y.Add(Self[i].Y);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      Result[i.Increase] := y.ToArray;
    end;
  finally
    for y in g.Values do
      y.Free;
    g.Free;
  end;
end;

{==============================================================================]
 <YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted Y values.
 @note: The Y values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := xArr.Size;
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
      begin
        Result[i][k] := Self[j].Y;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);	
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Self.Length;
  SetLength(xArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := xArr.Size;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Result[i][k.Increase] := Self[j].Y;
  end;
end;
{$ENDIF}
