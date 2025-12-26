{$IFDEF HELPERS}
function CorePointsMax(const maximumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
function CorePointsMax(const maximumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function CorePointsMin(const minimumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
function CorePointsMin(const minimumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function CorePoints(const allowedNeighbours: TRange; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
function CorePoints(const allowedNeighbours: TRange; const xRadius, yRadius: Integer): TPointArray; overload;
function XClassify(const pSorted: Boolean = False): T2DPointArray; overload;
function YClassify(const pSorted: Boolean = False): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CorePointsMax>
  @action: Returns all points that have **no more than `maximumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *sparse* points or "edge" points in a spatial 
         distribution. Early-breaks when neighbour count exceeds the limit.
[==============================================================================}
function TPointArrayHelper.CorePointsMax(const maximumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, s: TRange;
begin
  l := Self.Length;
  if ((maximumNeighbours < 0) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  for i := 0 to High(Self) do
  begin
    c := 0;
    b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    for j := b.start to b.stop do
    begin
      s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if ((not s.Employs(-1)) and (c.Increment(s.Size) > maximumNeighbours)) then
        Break;
    end;
    if (c <= maximumNeighbours) then
      Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMax>
  @action: Returns all points that have **no more than `maximumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *sparse* points or "edge" points in a spatial 
         distribution. Early-breaks when neighbour count exceeds the limit.
[==============================================================================}
function TPointArrayHelper.CorePointsMax(const maximumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if ((maximumNeighbours < 0) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  z := Ceil(radius);
  for i := 0 to High(Self) do
  begin
    c := 0;
    p := Self[i];
    b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
    for j := b.start to b.stop do
    begin
      q := x[j];
      s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
      if s.Employs(-1) then
        Continue;
      for k := s.start to s.stop do
        if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment > maximumNeighbours)) then
          Break;
      if (c > maximumNeighbours) then
        Break;
    end;
    if (c <= maximumNeighbours) then
      Result[r.Increase] := p;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMin>
  @action: Returns all points that have **at least `minimumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *core* points in a density-based clustering context 
         (e.g. DBSCAN). Early-breaks when minimum is reached.
[==============================================================================}
function TPointArrayHelper.CorePointsMin(const minimumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, s: TRange;
begin
  l := Self.Length;
  if ((minimumNeighbours > l) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  for i := 0 to High(Self) do
  begin
    c := 0;
    b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    for j := b.start to b.stop do
    begin
      s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if ((not s.Employs(-1)) and (c.Increment(s.Size) >= minimumNeighbours)) then
      begin
        Result[r.Increase] := Self[i];
        Break;
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMin>
  @action: Returns all points that have **at least `minimumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *core* points in a density-based clustering context 
         (e.g. DBSCAN). Early-breaks when minimum is reached.
[==============================================================================}
function TPointArrayHelper.CorePointsMin(const minimumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if ((minimumNeighbours > l) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  z := Ceil(radius);
  for i := 0 to High(Self) do
  begin
    c := 0;
    p := Self[i];
    b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
    for j := b.start to b.stop do
    begin
      q := x[j];
      s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
      if s.Employs(-1) then
        Continue;
      for k := s.start to s.stop do
        if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment >= minimumNeighbours)) then
        begin
          Result[r.Increase] := p;
          Break;
        end;
      if (c >= minimumNeighbours) then
        Break;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePoints>
  @action: Returns all points whose number of neighbours lies **within the 
           inclusive range `allowedNeighbours`** for the given rectangular or 
           metric radius.
  @note: Generalized version of `CorePointsMin` and `CorePointsMax`. 
         Supports both integer radii (grid-based) and floating-point radii 
         with custom distance metrics. Automatically ignores points outside 
         the defined neighbour range.
[==============================================================================}
function TPointArrayHelper.CorePoints(const allowedNeighbours: TRange; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s, n: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  n := allowedNeighbours.Normalize;
  r := 0;
  if (n.start < l) then
  begin
    SetLength(Result, l);
    x := Self.X2D(y);
    z := Ceil(radius);
    for i := 0 to High(Self) do
    begin
      c := 0;
      p := Self[i];
      b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
      for j := b.start to b.stop do
      begin
        q := x[j];
        s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
        if s.Employs(-1) then
          Continue;
        for k := s.start to s.stop do
          if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment > n.stop)) then
            Break;
        if (c > n.stop) then
          Break;
      end;
      if InRange(c, n.start, n.stop) then
        Result[r.Increase] := p;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePoints>
  @action: Returns all points whose number of neighbours lies **within the 
           inclusive range `allowedNeighbours`** for the given rectangular or 
           metric radius.
  @note: Generalized version of `CorePointsMin` and `CorePointsMax`. 
         Supports both integer radii (grid-based) and floating-point radii 
         with custom distance metrics. Automatically ignores points outside 
         the defined neighbour range.
[==============================================================================}
function TPointArrayHelper.CorePoints(const allowedNeighbours: TRange; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, n, s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  n := allowedNeighbours.Normalize;
  r := 0;
  if (n.start < l) then
  begin
    SetLength(Result, l);
    x := Self.X2D(y);
    for i := 0 to High(Self) do
    begin
      c := 0;
      b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
      for j := b.start to b.stop do
      begin
        s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
        if ((not s.Employs(-1)) and (c.Increment(s.Size) > n.stop)) then
          Break;
      end;
      if InRange(c, n.start, n.stop) then
        Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <XClassify>
  @action: Classifies TPointArray to groups by X-value
  @note: None.
[==============================================================================}
function TPointArrayHelper.XClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Xs)
  else
    p := Self.Copy;
  Result := p.Classes(p.Xs);
end;

{==============================================================================]
  <YClassify>
  @action: Classifies TPointArray to groups by X-value
  @note: None.
[==============================================================================}
function TPointArrayHelper.YClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Ys)
  else
    p := Self.Copy;
  Result := p.Classes(p.Ys);
end;
{$ENDIF}
