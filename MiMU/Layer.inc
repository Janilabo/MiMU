procedure TXLayer.Clear;
begin
  SetLength(Self.X, 0);
  SetLength(Self.Y, 0);
  SetLength(Self.IDs, 0);
end;

procedure TYLayer.Clear;
begin
  SetLength(Self.X, 0);
  SetLength(Self.Y, 0);
  SetLength(Self.IDs, 0);
end;

constructor TXLayer.Create(const xArr: TIntegerArray; const yArr, yIDs: T2DIntegerArray); overload;
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

constructor TXLayer.Create(const arr: TPointArray); overload;
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

constructor TYLayer.Create(const yArr: TIntegerArray; const xArr, xIDs: T2DIntegerArray); overload;
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

constructor TYLayer.Create(const arr: TPointArray); overload;
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
