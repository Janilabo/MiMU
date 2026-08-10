{$IFDEF HELPERS}
function X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
function XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
function XAt2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XIn2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
function Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
function YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
function YAt2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
function YIn2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
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
  i, j, k, v, s, m: Integer;
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
      for j := 1 to (x.Count - 1) do
      begin
        v := x[j];
        s := p[j];
        m := (j - 1);
        while ((m >= 0) and (x[m] > v)) do
        begin
          x[m + 1] := x[m];
          p[m + 1] := p[m];
          Dec(m);
        end;
        x[m + 1] := v;
        p[m + 1] := s;
      end;
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
  <XAt2D>
  @action: Groups X-coordinates by unique Y values and sorts each X-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: x and p are built as before (parallel, lockstep). Instead of sorting
         either list directly, an index permutation is sorted by x[idx], then
         both Result and selfIDs are written through that permutation in one
         pass — x and p themselves are never reordered, so nothing can desync.
[==============================================================================}
function TPointArrayHelper.XAt2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k, n, t, c: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  x, p: specialize TList<Integer>;
  o: TIntegerArray;
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
      n := x.Count;
      SetLength(o, n);
      for j := 0 to (n - 1) do
        o[j] := j;
      for j := 1 to (n - 1) do
      begin
        t := o[j];
        c := (j - 1);
        while ((c >= 0) and (x[o[c]] > x[t])) do
		begin
          o[c + 1] := o[c];
		  Dec(c);
		 end;
        o[c + 1] := t;
      end;
      SetLength(Result[i], n);
      SetLength(selfIDs[i], n);
      for j := 0 to (n - 1) do
      begin
        Result[i][j] := x[o[j]];
        selfIDs[i][j] := p[o[j]];
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
  <XIn2D>
  @action: Groups X-coordinates by unique Y values and sorts each X-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Builds one index permutation over all points, sorted primarily by Y
         then by X, and splits it into groups on Y boundaries in a single
         linear pass. No TDictionary/TList involved — likely faster for large
         point counts since there's no per-unique-Y hashing/allocation.
[==============================================================================}
function TPointArrayHelper.XIn2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  n, i, j, t, c, g, r: Integer;
  o: TIntegerArray;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  n := Self.Length;
  if (n = 0) then
    Exit;
  for i := 0 to o.Alloc(n) do
    o[i] := i;
  for i := 1 to (n - 1) do
  begin
    t := o[i];
    j := i - 1;
    while ((j >= 0) and ((Self[o[j]].Y > Self[t].Y) or ((Self[o[j]].Y = Self[t].Y) and (Self[o[j]].X > Self[t].X)))) do
    begin
      o[j + 1] := o[j];
      Dec(j);
    end;
    o[j + 1] := t;
  end;
  c := 1;
  for i := 1 to (n - 1) do
    if (Self[o[i]].Y <> Self[o[i - 1]].Y) then
      Inc(c);
  SetLength(yArr, c);
  SetLength(Result, c);
  SetLength(selfIDs, c);
  g := 0;
  r := 0;
  for i := 1 to n do
    if ((i = n) or (Self[o[i]].Y <> Self[o[r]].Y)) then
    begin
      yArr[g] := Self[o[r]].Y;
      SetLength(Result[g], (i - r));
      SetLength(selfIDs[g], (i - r));
      for j := r to (i - 1) do
      begin
        Result[g][j - r] := Self[o[j]].X;
        selfIDs[g][j - r] := o[j];
      end;
      Inc(g);
      r := i;
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
  l, i, j, k, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  for i := 0 to selfIDs.Alloc(Result.SetSize(yArr.Size)) do
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
  l, i, j, k: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  for i := 0 to Result.Alloc(yArr.Size) do
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
  i, j, k, v, s, m: Integer;
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
      for j := 1 to (y.Count - 1) do
      begin
        v := y[j];
        s := p[j];
        m := (j - 1);
        while ((m >= 0) and (y[m] > v)) do
        begin
          y[m + 1] := y[m];
          p[m + 1] := p[m];
          Dec(m);
        end;
        y[m + 1] := v;
        p[m + 1] := s;
      end;
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
  <YAt2D>
  @action: Groups Y-coordinates by unique X values and sorts each Y-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: y and p are built as before (parallel, lockstep). Instead of sorting
         either list directly, an index permutation is sorted by y[idx], then
         both Result and selfIDs are written through that permutation in one
         pass — y and p themselves are never reordered, so nothing can desync.
[==============================================================================}
function TPointArrayHelper.YAt2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k, n, t, c: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  y, p: specialize TList<Integer>;
  o: TIntegerArray;
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
      n := y.Count;
      SetLength(o, n);
      for j := 0 to (n - 1) do
        o[j] := j;
      for j := 1 to (n - 1) do
      begin
        t := o[j];
        c := (j - 1);
        while ((c >= 0) and (y[o[c]] > y[t])) do
		begin
          o[k + 1] := o[c];
		  Dec(c);
		end;
        o[c + 1] := t;
      end;
      SetLength(Result[i], n);
      SetLength(selfIDs[i], n);
      for j := 0 to (n - 1) do
      begin
        Result[i][j] := y[o[j]];
        selfIDs[i][j] := p[o[j]];
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
  <YIn2D>
  @action: Groups Y-coordinates by unique X values and sorts each Y-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Builds one index permutation over all points, sorted primarily by X
         then by Y, and splits it into groups on X boundaries in a single
         linear pass. No TDictionary/TList involved — likely faster for large
         point counts since there's no per-unique-X hashing/allocation.
[==============================================================================}
function TPointArrayHelper.YIn2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  n, i, j, t, c, g, r: Integer;
  o: TIntegerArray;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  n := Self.Length;
  if (n = 0) then
    Exit;
  for i := 0 to o.Alloc(n) do
    o[i] := i;
  for i := 1 to (n - 1) do
  begin
    t := o[i];
    j := (i - 1);
    while ((j >= 0) and ((Self[o[j]].X > Self[t].X) or ((Self[o[j]].X = Self[t].X) and (Self[o[j]].Y > Self[t].Y)))) do
    begin
      o[j + 1] := o[j];
      Dec(j);
    end;
    o[j + 1] := t;
  end;
  c := 1;
  for i := 1 to (n - 1) do
    if (Self[o[i]].X <> Self[o[i - 1]].X) then
      Inc(c);
  SetLength(xArr, c);
  SetLength(Result, c);
  SetLength(selfIDs, c);
  g := 0;
  r := 0;
  for i := 1 to n do
    if ((i = n) or (Self[o[i]].X <> Self[o[r]].X)) then
    begin
      xArr[g] := Self[o[r]].X;
      SetLength(Result[g], (i - r));
      SetLength(selfIDs[g], (i - r));
      for j := r to (i - 1) do
      begin
        Result[g][j - r] := Self[o[j]].Y;
        selfIDs[g][j - r] := o[j];
      end;
      Inc(g);
      r := i;
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
  l, i, j, k, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  for i := 0 to selfIDs.Alloc(Result.SetSize(xArr.Size)) do
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
  for i := 0 to Result.Alloc(xArr.Size) do
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
