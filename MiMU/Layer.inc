procedure TLayerX.Clear;
begin
  SetLength(Self.X, 0);
  SetLength(Self.Y, 0);
  SetLength(Self.IDs, 0);
end;

procedure TLayerY.Clear;
begin
  SetLength(Self.X, 0);
  SetLength(Self.Y, 0);
  SetLength(Self.IDs, 0);
end;

constructor TLayerX.Create(const xArr: TIntegerArray; const yArr, yIDs: T2DIntegerArray); overload;
var
  i: Integer;
begin
  Self.X := xArr.Copy;
  SetLength(Self.Y, Length(yArr));
  for i := 0 to High(yArr) do
    Self.Y[i] := Copy(yArr[i], 0, Length(yArr[i]));
  SetLength(Self.IDs, Length(yIDs));
  for i := 0 to High(yIDs) do
    Self.IDs[i] := Copy(yIDs[i], 0, Length(yIDs[i]));
end;

constructor TLayerX.Create(const arr: TPointArray); overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Length(arr);
  Self.Clear;
  if (l = 0) then
    Exit;
  Self.X := arr.XAxis;
  c := Length(Self.X);
  SetLength(Self.Y, c);
  SetLength(Self.IDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (arr[j].X = Self.X[i]) then
        Inc(k);
    SetLength(Self.Y[i], k);
    SetLength(Self.IDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (arr[j].X = Self.X[i]) then
      begin
        Self.Y[i][k] := arr[j].Y;
        Self.IDs[i][k] := j;
        Inc(k);
      end;
    for j := 1 to (k - 1) do
    begin
      p := Self.Y[i][j];
      s := Self.IDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Self.Y[i][m] > p)) do
      begin
        Self.Y[i][m + 1] := Self.Y[i][m];
        Self.IDs[i][m + 1] := Self.IDs[i][m];
        Dec(m);
      end;
      Self.Y[i][m + 1] := p;
      Self.IDs[i][m + 1] := s;
    end;
  end;
end;

constructor TLayerY.Create(const yArr: TIntegerArray; const xArr, xIDs: T2DIntegerArray); overload;
var
  i: Integer;
begin
  Self.Y := yArr.Copy;
  SetLength(Self.X, Length(xArr));
  for i := 0 to High(xArr) do
    Self.X[i] := Copy(xArr[i], 0, Length(xArr[i]));
  SetLength(Self.IDs, Length(xIDs));
  for i := 0 to High(xIDs) do
    Self.IDs[i] := Copy(xIDs[i], 0, Length(xIDs[i]));
end;

constructor TLayerY.Create(const arr: TPointArray); overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Length(arr);
  Self.Clear;
  if (l = 0) then
    Exit;
  Self.Y := arr.YAxis;
  c := Length(Self.Y);
  SetLength(Self.X, c);
  SetLength(Self.IDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (arr[j].Y = Self.Y[i]) then
        Inc(k);
    SetLength(Self.X[i], k);
    SetLength(Self.IDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (arr[j].Y = Self.Y[i]) then
      begin
        Self.X[i][k] := arr[j].X;
        Self.IDs[i][k] := j;
        Inc(k);
      end;
    for j := 1 to (k - 1) do
    begin
      p := Self.X[i][j];
      s := Self.IDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Self.X[i][m] > p)) do
      begin
        Self.X[i][m + 1] := Self.X[i][m];
        Self.IDs[i][m + 1] := Self.IDs[i][m];
        Dec(m);
      end;
      Self.X[i][m + 1] := p;
      Self.IDs[i][m + 1] := s;
    end;
  end;
end;

class function TLayerX.Construct(const arr: TPointArray): TLayerX; overload;
var
  i, j, k: Integer;
  g, d: specialize TDictionary<Integer, specialize TList<Integer>>;
  r, p: specialize TList<Integer>;
begin
  SetLength(Result.Y, 0);
  SetLength(Result.X, 0);
  SetLength(Result.IDs, 0);
  if arr.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(arr) do
    begin
      if not g.TryGetValue(arr[i].X, r) then
      begin
        r := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(arr[i].X, r);
        d.Add(arr[i].X, p);
      end else
        p := d[arr[i].X];
      r.Add(arr[i].Y);
      p.Add(i);
    end;
    SetLength(Result.X, g.Count);
    SetLength(Result.Y, g.Count);
    SetLength(Result.IDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      Result.X[i] := k;
      r := g[k];
      p := d[k];
      r.Sort;
      SetLength(Result.Y[i], r.Count);
      SetLength(Result.IDs[i], r.Count);
      for j := 0 to (r.Count - 1) do
      begin
        Result.Y[i][j] := r[j];
        Result.IDS[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for r in g.Values do
      r.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

class function TLayerY.Construct(const arr: TPointArray): TLayerY; overload;
var
  i, j, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  c, p: specialize TList<Integer>;
begin
  SetLength(Result.X, 0);
  SetLength(Result.Y, 0);
  SetLength(Result.IDs, 0);
  if arr.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(arr) do
    begin
      if not g.TryGetValue(arr[i].Y, c) then
      begin
        c := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(arr[i].Y, c);
        d.Add(arr[i].Y, p);
      end else
        p := d[arr[i].Y];
      c.Add(arr[i].X);
      p.Add(i);
    end;
    SetLength(Result.Y, g.Count);
    SetLength(Result.X, g.Count);
    SetLength(Result.IDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      Result.Y[i] := k;
      c := g[k];
      p := d[k];
      c.Sort;
      SetLength(Result.X[i], c.Count);
      SetLength(Result.IDs[i], c.Count);
      for j := 0 to (c.Count - 1) do
      begin
        Result.X[i][j] := c[j];
        Result.IDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for c in g.Values do
      c.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;
