{$IFDEF Skeleton_Classes}
var
  i, g: Integer;
begin
  if (Self.Empty or (Self.Length <> weight.Length)) then
    Exit([]);
  g := 0;
  w := weight[0];
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to High(Self) do
  begin
    if (weight[i] <> w) then
    begin
      w := weight[i];
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], 0);
    end;
    SetLength(Result[g], (Result[g].Length + 1));
    Result[g][High(Result[g])] := Self[i];
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_Classify}
var
  i, c, l, s: Integer;
begin
  l := Self.Length;
  if ((l = 0) or (l <> weight.Length)) then
    Exit([]);
  c := 0;
  w := weight[0];
  SetLength(Result, l);
  SetLength(Result[0], l);
  Result[0][0] := Self[0];
  s := 1;
  for i := 1 to (l - 1) do
  begin
    if (weight[i] <> w) then
    begin
      SetLength(Result[c], s);
      s := 0;
      w := weight[i];
      SetLength(Result[c.Increment], (l - i));
    end;
    Result[c][s.Increase] := Self[i];
  end;
  SetLength(Result[c], s);
  SetLength(Result, (c + 1));
end;
{$ENDIF}

{$IFDEF Skeleton_Group}
var
  i, l, g: Integer;
begin
  l := Self.Length;
  if ((l = 0) or (weight.Size <> l))then
    Exit([]);
  if not wSorted then
    w := weight.QuickSorted
  else
    w := weight.Copy;
  w.BinaryPrune;
  Result.Recreate(w.Size);
  for i := 0 to High(Self) do
  begin
    g := w.BinarySearch(weight[i]);
    l := Result[g].Length;
    SetLength(Result[g], (l + 1));
    Result[g][l] := Self[i];
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_Pure}
var
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
  a := allowed.QuickSorted;
  for i := 0 to High(Self) do
    if not a.BinaryContains(Self[i]) then
      Exit(False);
  Result := True;
end;
{$ENDIF}

{$IFDEF Skeleton_TernarySearch}
var
  L, R: Integer;
  S: TRange;
begin
  Result := -1;
  S.Create(0, High(Self));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if (Self[L] = value) then
      Exit(L);
    if (Self[R] = value) then
      Exit(R);
    if ((oAscending and (value < Self[L])) or ((not oAscending) and (value > Self[L]))) then
      S.stop := (L - 1)
    else if ((oAscending and (value > Self[R])) or ((not oAscending) and (value < Self[R]))) then
      S.start := (R + 1)
    else
      S.Create((L + 1), (R - 1));
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_TernaryPeak}
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  if (Self[0] > Self[1]) then
    Exit(0);
  if (Self[H] > Self[H - 1]) then
    Exit(H);
  S.Create(1, (H - 1));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if ((Self[L] > Self[L - 1]) and (Self[L] > Self[L + 1])) then
      Exit(L);
    if ((Self[R] > Self[R - 1]) and (Self[R] > Self[R + 1])) then
      Exit(R);
    if (Self[L] < Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  for Result := S.start to S.stop do
    if ((Self[Result] > Self[Result - 1]) and (Self[Result] > Self[Result + 1])) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_TernaryValley}
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  if (Self[0] < Self[1]) then
    Exit(0);
  if (Self[H] < Self[H - 1]) then
    Exit(H);
  S.Create(1, (H - 1));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if ((Self[L] < Self[L - 1]) and (Self[L] < Self[L + 1])) then
      Exit(L);
    if ((Self[R] < Self[R - 1]) and (Self[R] < Self[R + 1])) then
      Exit(R);
    if (Self[L] > Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  for Result := S.start to S.stop do
    if ((Self[Result] < Self[Result - 1]) and (Self[Result] < Self[Result + 1])) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_TernaryMountain}
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  S.Create(0, High(Self));
  while (S.start < S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if (Self[L] < Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  Result := S.start;
end;
{$ENDIF}

{$IFDEF Skeleton_BSort}
var
  i, j, m, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
    o := aAscending.Select(-1, 1);
  for i := 1 to Result do
  begin
    a := Self[i];
    r.Create(0, (i - 1));
    while r.Ascending do
    begin
      m := r.Pivot;
      if (Sign(a - Self[m]) = o) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    for j := (i - 1) downto r.start do
      Self[j + 1] := Self[j];
    Self[r.start] := a;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySort}
var
  j, m, i, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for j := 1 to Result do
    begin
      a := Self[j];
      r.Create(0, j);
      while r.Grows do
      begin
        m := r.Pivot;
        if (Sign(Self[m] - a) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Self[i] := Self[i - 1];
      Self[r.start] := a;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySorted}
var
  j, m, i, n, o: Integer;
  r: TRange;
begin
  n := Self.Size;
  SetLength(Result, n);
  if (n > 0) then
  begin
    o := aAscending.Select(-1, 1);
    Result[0] := Self[0];
    for j := 1 to (n - 1) do
    begin
      a := Self[j];
      r.Create(0, j);
      while r.Grows do
      begin
        m := r.Pivot;
        if (Sign(Result[m] - a) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Result[i] := Result[i - 1];
      Result[r.start] := a;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryBoundL}
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  Result := r.start;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryBoundR}
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
  begin
    m := r.Pivot;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  Result := r.start;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryBoundLeft}
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryBoundRight}
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] <= value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] >= value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPos}
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPosL}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start < Self.Size) and (Self[r.start] = x)) then
    Result := r.Start;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPosR}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
  begin
    m := r.Pivot;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start > 0) and (Self[r.start - 1] = x)) then
    Result := (r.Start - 1);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPosOf}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := (value - Self[M]);
    if (C = 0) then
      Exit(M);
    if not oAscending then
      C := -C;
    if (C < 0) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPosition}
var
  O, M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  O := IfThen(oAscending, 1, -1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (value.Compare(Self[M]) * O) of
      0: Exit(M);
      -1: R.stop := (M - 1);
      1: R.start := (M + 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryHybridSearch}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while ((R.stop - R.start) > threshold) do
  begin
    M := R.Pivot;
    if (Self[M] = value) then
      Exit(M);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  for M := R.start to R.stop do
    if (Self[M] = value) then
      Exit(M);
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearch}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while (r.Ascending and (Result = -1)) do
  begin
    m := r.Pivot;
    if ((o * Self[m]) = (o * x)) then
      Result := m
    else
      if ((o * Self[m]) < (o * x)) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySeek}
var
  i: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while r.Ascends do
  begin
    i := r.Pivot;
    if (Self[i] = x) then
      Exit(i);
    if ((aAscending and (Self[i] < x)) or ((not aAscending) and (Self[i] > x))) then
      r.start := (i + 1)
    else
      r.stop := (i - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryContains}
begin
  Result := (Self.BinarySearch(x, aAscending) > -1);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryCount}
var
  r: TRange;
begin
  r := Self.BinaryLocate(x, aAscending);
  Result := IfThen((r.start > -1), r.Size, 0);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLocate}
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLocation}
var
  h, m, o: Integer;
  f: Boolean;
begin
  f := False;
  h := High(Self);
  Result.Create(0, h);
  o := aAscending.Select(1, -1);
  while (Result.Ascending and (not f)) do
  begin
    m := Result.Pivot;
    f := ((o * Self[m]) = (o * x));
    if f then
	begin
      Result.Create(m, m);
      while ((Result.start > 0) and (Self[Result.start - 1] = x)) do
        Dec(Result.start);
      while ((Result.stop < h) and (Self[Result.stop + 1] = x)) do
        Inc(Result.stop);
    end else
      if ((o * Self[m]) < (o * x)) then
        Result.start := (m + 1)
      else
        Result.stop := (m - 1);
  end;
  if not f then
    Result.Create(-1, -1);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryAppend}
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := r.start;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := x;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryAdd}
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  SetLength(Result, (Self.Size + 1));
  for i := 0 to (r.start - 1) do
    Result[i] := Self[i];
  Result[r.start] := x;
  for i := r.start to High(Self) do
    Result[i + 1] := Self[i];
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchF}
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        r.stop := (m - 1)
    else
    begin
      Result := m;
      r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchL}
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        r.stop := (m - 1)
      else
      begin
        Result := m;
        r.start := (m + 1);
      end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPrune}
var
  i, o: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  o := aAscending.Select(-1, 1);
  for i := 1 to High(Self) do
    if (Sign(Self[Result] - Self[i]) = o) then
      Self[Result.Increment] := Self[i];
  Result := (Result + 1);
  SetLength(Self, Result);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPruned}
var
  i, o, r: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  r := 0;
  o := aAscending.Select(-1, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Sign(Result[r] - Self[i]) = o) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryGrow}
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> x));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := x;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryShrink}
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size > r.start) and (Self[r.start] = x));
  if not Result then
    Exit;
  for i := r.start to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Size - 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUndupe}
var
  i: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Size);
  Result := 0;
  for i := 0 to High(Self) do
    if u.BinaryGrow(Self[i]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnduped}
var
  i: Integer;
begin
  if Self.Empty then
    Exit([]);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    Result.BinaryGrow(Self[i]);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnified}
var
  i, l: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  l := 0;
  case dAscending of
    True:
    for i := 0 to High(Self) do
      if u.BinaryGrow(Self[i]) then
        Result[l.Increase] := Self[i];
    False:
    for i := High(Self) downto 0 do
      if u.BinaryGrow(Self[i]) then
        Result[l.Increase] := Self[i];
  end;
  SetLength(Result, l);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLowerBound}
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{$ENDIF}

{$IFDEF Skeleton_BinaryUpperBound}
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] > x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] < x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRightmost}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
      False:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLeftmost}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRange1}
var
  r: TRange;
begin
  if Self.Empty then
    Exit(TRange.Construct(-1, -1));
  r := x.Normalize;
  case aAscending of
    True:
    begin
      Result.start := Self.BinaryFirst(r.start, aAscending);
      if (Result.start > -1) then
        Result.stop := Self.BinaryLast(r.stop, aAscending);
    end;
    False:
    begin
      Result.start := Self.BinaryFirst(r.stop, aAscending);
      if (Result.start > -1) then
        Result.stop := Self.BinaryLast(r.start, aAscending);
    end;
  end;
  if Result.Employs(-1) then
    Result.Create(-1, -1);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRange2}
begin
  Result.start := Self.BinaryPosL(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryPosR(x, aAscending)
  else
    Result.stop := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySpan}
var
  m: Integer;
  n, r: TRange;
begin
  if Self.Empty then
    Exit(Result.Create(-1, -1));
  n := x.Normalize;
  r.Create(0, High(Self));
  case aAscending of
    True:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] < n.start) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] > n.stop) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if ((r.start > High(Self)) or (r.start < 0)) then
    Exit(Result.Create(-1, -1));
  Result.start := r.start;
  r.stop := High(Self);
  case aAscending of
    True:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] <= n.stop) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m] >= n.start) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  Result.stop := r.stop;
  if ((Result.start > Result.stop) or (Result.start < 0) or (Result.stop > High(Self))) then
    Result.Create(-1, -1);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryMerge}
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryMerged}
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryCombine}
var
  l: specialize TFPGList<MType>;
  r: Integer;
  s, i: TRange;
begin
  l := specialize TFPGList<MType>.Create;
  try
    i.Create(0, items.Size);
    s.Create(0, Self.Size);
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if ((aAscending and (Self[s.start] <= items[i.start])) or ((not aAscending) and (Self[s.start] >= items[i.start]))) then
        l.Add(Self[s.start.Increase])
      else
        l.Add(items[i.start.Increase]);
    while (s.start < s.stop) do
      l.Add(Self[s.start.Increase]);
    while (i.start < i.stop) do
      l.Add(items[i.start.Increase]);
    SetLength(Result, l.Count);
    for r := 0 to (l.Count - 1) do
      Result[r] := l[r];
  finally
    l.Free;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRemove}
var
  l, p, i, j: Integer;
  s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinarySearch(val, aAscending);
  if (p > -1) then
  case all of
    True:
    begin
      s.start := p;
      while ((s.start > 0) and (Self[s.start - 1] = val)) do
        Dec(s.start);
      s.stop := p;
      while ((s.stop < High(Self)) and (Self[s.stop + 1] = val)) do
        Inc(s.stop);
      j := s.start;
      for i := (s.stop + 1) to High(Self) do
        Self[j.Increase] := Self[i];
      SetLength(Self, j);
    end;
    False:
    begin
      for i := p to (High(Self) - 1) do
        Self[i] := Self[i + 1];
      SetLength(Self, (High(Self)));
    end;
  end;
  Result := (l - Self.Size);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFind}
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = val) then
      Exit(m);
    if (IfThen(aAscending, Ord(Self[m] < val), Ord(Self[m] > val)) <> 0) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchEx}
var
  m, l, r: Integer;
  s: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Center;
    if (Self[m] = ignore) then
    begin
      l := (m - 1);
      r := (m + 1);
      while ((l >= s.start) or (r <= s.stop)) do
      begin
        if ((l >= s.start) and (Self[l] <> ignore)) then
        begin
          m := l;
          Break;
        end;
        if ((r <= s.stop) and (Self[r] <> ignore)) then
        begin
          m := r;
          Break;
        end;
        Dec(l);
        Inc(r);
      end;
      if ((l < s.start) and (r > s.stop)) then
        Exit(-1);
    end;
    case (Self[m] = x) of
      False:
      if IfThen(aAscending, (Self[m] < x), (Self[m] > x)) then
        s.start := (m + 1)
      else
        s.stop := (m - 1);
      True: Exit(m);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryInsert}
var
  m, i: Integer;
  r: TRange;
begin
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  if (Result > 0) then
  begin
    r.Create(0, (Result - 1));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if ((aAscending and (Self[m] >= x)) or ((not aAscending) and (Self[m] <= x))) then
      begin
        Result := m;
        r.stop := (m - 1);
      end else
        r.start := (m + 1);
    end;
    for i := High(Self) downto (Result + 1) do
      Self[i] := Self[i - 1];
    Self[Result] := x;
  end else
    Self[0] := x;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchRange}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(rLeft, rRight);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
      Exit(M)
    else
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryDeduplicate}
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(0);
  u := Self.Copy;
  SetLength(Self, 0);
  for i := 0 to (l - 1) do
    if (Self.BinarySearch(u[i], aAscending) = -1) then
      Self.Supply(u[i]);
  Result := (l - Self.Size);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnduplicate}
var
  i, u, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(0);
  u := 0;
  for i := 1 to (l - 1) do
    if (Self.BinarySearchRange(Self[i], 0, u, aAscending) = -1) then
      Self[u.Increment] := Self[i];
  Result := (l - (u + 1));
  if (Result > 0) then
    SetLength(Self, (u + 1)); 
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryDeduplicated}
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if (Result.BinarySearch(Self[i], aAscending) = -1) then
      Result.Supply(Self[i]);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnduplicated}
var
  i, u: Integer;
begin
  Result := Self.Copy;
  if (Self.Size < 2) then
    Exit;
  u := 0;
  for i := 1 to High(Self) do
    if (Result.BinarySearchRange(Result[i], 0, u, aAscending) = -1) then
      Result[u.Increment] := Result[i];
  SetLength(Result, (u + 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryCombined}
var
  i, j, k, s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  SetLength(Result, (s + o));
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
    if ((aAscending and (Self[i] <= items[j])) or ((not aAscending) and (Self[i] >= items[j]))) then
      Result[k.Increase] := Self[i.Increase]
    else
      Result[k.Increase] := items[j.Increase];
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
  if (k < Result.Size) then
    SetLength(Result, k);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRank}
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = x) of
      True:
      begin
        while ((m > 0) and (Self[m - 1] = x)) do
          Dec(m);
        Exit(m);
      end;
      False:
      if ((aAscending and (Self[m] < x)) or ((not aAscending) and (Self[m] > x))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  Result := r.start;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryIndex}
var
  m: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m] = x) then
      Exit(m)
    else
      if ((aAscending and (Self[m] < x)) or ((not aAscending) and (Self[m] > x))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUpdate}
var
  p: Integer;
begin
  Result := False;
  p := Self.BinaryIndex(oValue, aAscending);
  Result := (p <> -1);
  if Result then
    Self[p] := nValue;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryDelete}
var
  p, l, i: Integer;
begin
  p := Self.BinaryIndex(x, aAscending);
  Result := (p <> -1);
  if not Result then
    Exit;
  l := Self.Length;
  for i := p to (l - 2) do
    Self[i] := Self[i + 1];
  SetLength(Self, (l - 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryReplace}
begin
  Result := Self.BinaryDelete(oValue, aAscending);
  if (Result and (oValue <> nValue)) then
    Self.BinaryInsert(nValue, aAscending);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryReplaceAll}
var
  i, p: Integer;
  r: Boolean;
begin
  Result := 0;
  p := Self.BinaryPosL(oValue);
  if (p = -1) then
    Exit;
  r := False;
  for i := p to High(Self) do
    if (Self[i] = oValue) then
    begin
      Self[i] := nValue;
      Inc(Result);
      if ((not r) and (not Self.IsSorted(i, aAscending))) then
        r := True;
    end else
	  Break;
  if r then
    Self.BinaryInsertionSort(aAscending);
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySinglify}
var
  i, l, s, p: Integer;
begin
  p := Self.BinaryPosL(item, aAscending);
  if (p = -1) then
    Exit(0);
  s := Self.Size;
  l := p;
  for i := (p + 1) to (s - 1) do
    if (Self[i] <> item) then
      Self[l.Increment] := Self[i];
  Result := (s - (l + 1));
  if (Result > 0) then
    SetLength(Self, (l + 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySinglified}
var
  i, l, p: Integer;
begin
  p := Self.BinaryPosL(item, aAscending);
  if (p = -1) then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  l := 0;
  for i := 0 to High(Self) do
    if ((i = p) or (Self[i] <> item)) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchFirst}
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = value) of
      True:
      begin
        Result := M;
        R.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchLast}
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = value) of
      True:
      begin
        Result := M;
        R.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLocalize}
var
  R, M: Integer;
begin
  Result := 0;
  R := Self.Size;
  while (Result < R) do
  begin
    M := ((Result + R) div 2);
    if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
      Result := (M + 1)
    else
      R := M;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLookup}
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop > -1) then
  case (Self[R.start] <= Self[R.stop]) of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = value) then
        Exit(M);
      if (value > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFirst}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    case ((o * Self[m]) < (o * x)) of
      False:
      begin
        Result := m;
        r.stop := (m - 1);
      end;
      True: r.start := (m + 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLast}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    case ((o * Self[m]) > (o * x)) of
      False:
      begin
        Result := m;
        r.start := (m + 1);
      end;
      True: r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFindFirst1}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFindFirst2}
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFindLast1}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFindLast2}
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryValues1}
var
  i: Integer;
  r: TRange;
begin
  r := Self.BinaryRange(value, aAscending);
  if r.Employs(-1) then
    Exit([]);
  SetLength(Result, r.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[r.start + i];
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryValues2}
var
  h, i: Integer;
  r: TRange;
begin
  r := Self.BinaryRange(values, aAscending);
  if r.Employs(-1) then
    Exit([]);
  SetLength(Result, r.Size);
  h := High(Result);
  case values.Ascending of
    True:
    for i := 0 to h do
      Result[i] := Self[r.start + i];
    False:
    for i := h downto 0 do
      Result[h - i] := Self[r.start + i];
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryIndexOf}
  function BS(const L, R: Integer): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if (Self[M] = value) then
      Exit(M);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryExists}
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    if (Self[M] = value) then
      Exit(True);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchSpan1}
var
  M: Integer;
begin
  if ((L > R) or (L < 0) or (R > High(Self))) then
    Exit(-1);
  M := (L + ((R - L) div 2));
  if (Self[M] = value) then
    Exit(M);
  if ((aAscending and (value < Self[M])) or ((not aAscending) and (value > Self[M]))) then
    Result := Self.BinarySearchSpan(value, L, (M - 1), aAscending)
  else
    Result := Self.BinarySearchSpan(value, (M + 1), R, aAscending);
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchSpan2}
  function BSS(const range: TRange; const L, R: Integer; const aAscending: Boolean): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if InRange(Self[M], range.start, range.stop) then
      Exit(M);
    if ((aAscending and (range.stop < Self[M])) or ((not aAscending) and (range.start > Self[M]))) then
      Result := BSS(range, L, (M - 1), aAscending)
    else if ((aAscending and (range.start > Self[M])) or ((not aAscending) and (range.stop < Self[M]))) then
      Result := BSS(range, (M + 1), R, aAscending);
  end;
begin
  if (L < 0) or (R > High(Self)) then
    Exit(-1);
  Result := BSS(range.Normalize, L, R, aAscending);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryInsertSorted}
var
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Copy;
  for i := 1 to High(Result) do
  begin
    K := Result[i];
    P := 0;
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if ((oAscending and (K < Result[M])) or ((not oAscending) and (K > Result[M]))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Result[j + 1] := Result[j.Decrease];
    Result[P] := K;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryInsertSort}
var
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Size;
  for i := 1 to (Result - 1) do
  begin
    K := Self[i];
    P := 0;
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if ((oAscending and (K < Self[M])) or ((not oAscending) and (K > Self[M]))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Self[j + 1] := Self[j.Decrease];
    Self[P] := K;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFloor}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryCeil}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryTrunc}
begin
  if (value >= 0) then
    Result := Self.BinaryFloor(value, oAscending)
  else
    Result := Self.BinaryCeil(value, oAscending);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRound}
var
  c, f: Integer;
begin
  if Self.Empty then
    Exit(-1);
  f := Self.BinaryFloor(value, oAscending);
  c := Self.BinaryCeil(value, oAscending);
  if (f = -1) then
    Exit(c);
  if ((c = -1) or (f = c))then
    Exit(f);
  Result := IfThen((Abs(Self[f] - value) <= Abs(Self[c] - value)), f, c);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPoint}
var
  M: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  case oAscending of
    True:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < value) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
    False:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > value) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;
{$ENDIF} 

{$IFDEF Skeleton_BinaryClosest}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  case oAscending of
    True:
    begin
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = value) then
          Exit(M)
        else if (Self[M] < value) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
      if (R.stop < 0) then
        Result := R.start
      else if (R.start > High(Self)) then
        Result := R.stop
      else if ((Abs(Self[R.stop] - value) <= Abs(Self[R.start] - value))) then
        Result := R.stop
      else
        Result := R.start;
    end;
    False:
    begin
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = value) then
          Exit(M)
        else if (Self[M] > value) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
      if (R.stop < 0) then
        Result := R.start
      else if (R.start > High(Self)) then
        Result := R.stop
      else if ((Abs(Self[R.stop] - value) <= Abs(Self[R.start] - value))) then
        Result := R.stop
      else
        Result := R.start;
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFarthest}
begin
  Result := High(Self);
  if (Result < 0) then
    Exit;
  if (Abs(Self[0] - value) = Abs(Self[Result] - value)) then
    Exit(IfThen(oAscending, 0, Result));
  Result := IfThen((Abs(Self[0] - value) > Abs(Self[Result] - value)), 0, Result);
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchNth}
begin
  if ((N < 0) or (N > High(Self))) then
    Exit(-1);
  Result := Self.BinarySearchFirst(value, oAscending);
  if (Result > -1) then
    Inc(Result, N);
  if ((Result > -1) and ((Result > High(Self)) or (Self[Result] <> value))) then
    Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryApproximateSearch}
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if (Self.Empty or (tolerance < 0)) then
    Exit;
  H := High(Integer);
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      D := Abs(Self[M] - value);
      if (D = 0) then
        Exit(M);
      if ((D <= tolerance) and (D < H)) then
      begin
        Result := M;
        H := D;
      end;
      if (Self[M] < value) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      D := Abs(Self[M] - value);
      if (D = 0) then
        Exit(M);
      if ((D <= tolerance) and (D < H)) then
      begin
        Result := M;
        H := D;
      end;
      if (Self[M] > value) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySearchApproximate}
var
  c: Integer;
begin
  c := Self.BinaryClosest(value, oAscending);
  if ((c = -1) or (Abs(Self[c] - value) > tolerance)) then
    Result := -1
  else
    Result := c;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryLowerCount}
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundLeft(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(l, 0)
  else
    Result := oAscending.Select(p, (l - p));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryHigherCount}
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundRight(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(0, l)
  else
    Result := oAscending.Select((l - p), p);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryFit}
begin
  if oAscending then
    Result := ((not Self.Empty) and (value >= Self[0]) and (value <= Self[High(Self)]))
  else
    Result := ((not Self.Empty) and (value <= Self[0]) and (value >= Self[High(Self)]));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnfit}
begin
  if oAscending then
    Result := (Self.Empty or (value < Self[0]) or (value > Self[High(Self)]))
  else
    Result := (Self.Empty or (value > Self[0]) or (value < Self[High(Self)]));
end;
{$ENDIF} 

{$IFDEF Skeleton_BinaryIncludes}
begin
  Result := (Self.BinaryFit(value, oAscending) and (Self.BinaryPos(value, oAscending) > -1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryExcludes}
begin
  Result := (Self.BinaryUnfit(value, oAscending) or (Self.BinaryPos(value, oAscending) = -1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySpanning1}
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySpanning2}
var
  m: Integer;
  n, r: TRange;
begin
  r.Create(0, High(Self));
  n := range.Normalize;
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.start))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.stop)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySpanOf1}
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] = value)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] = value)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinarySpanOf2}
var
  m: Integer;
  n, r: TRange;
begin
  Result.Create(-1, -1);
  n := range.Normalize;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case InRange(Self[m], n.start, n.stop) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] >= n.start) and (Self[Result.start - 1] <= n.stop)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] >= n.start) and (Self[Result.stop + 1] <= n.stop)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRangeOf1}
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) of
      False:
      begin
        r.stop := (m - 1);
        if (Self[m] = value) then
          Result.start := m;
      end;
      True: r.start := (m + 1);
    end;
  end;
  if Result.start = -1 then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = value) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < value)) or ((not oAscending) and (Self[m] > value))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryRangeOf2}
var
  m: Integer;
  n, r: TRange;
begin
  Result.Create(-1, -1);
  n := range.Normalize;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) of
      False:
      begin
        if ((Self[m] >= n.start) and (Self[m] <= n.stop)) then
          Result.start := m;
        r.stop := (m - 1);
      end;
      True: r.start := (m + 1);
    end;
  end;
  if (Result.start = -1) then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((Self[m] >= n.start) and (Self[m] <= n.stop)) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < n.start)) or ((not oAscending) and (Self[m] > n.stop))) then
        r.start := (m + 1)
      else if ((oAscending and (Self[m] > n.stop)) or ((not oAscending) and (Self[m] < n.start))) then
        r.stop := (m - 1);
    end;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnique}
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(l);
  Self.BinarySort(oAscending);
  Result := 1;
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  if (Result < l) then
    SetLength(Self, Result);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUniqued}
var
  i, l: Integer;
begin
  Result := Self.Copy;
  if (Result.Size < 2) then
    Exit;
  Result.BinarySort(oAscending);
  l := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  if (Result.Size > l) then
    SetLength(Result, l);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUniq}
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(l);
  Result := 1;
  case oAscending of
    True:
    for i := 1 to (l - 1) do
      if (Self[i] > Self[Result - 1]) then
        Self[Result.Increase] := Self[i];
    False:
    for i := 1 to (l - 1) do
      if (Self[i] < Self[Result - 1]) then
        Self[Result.Increase] := Self[i];
  end;
  if (Result < l) then
    SetLength(Self, Result);
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUniqd}
var
  i, l: Integer;
begin
  Result := Self.Copy;
  if (Result.Size < 2) then
    Exit;
  l := 1;
  case oAscending of
    True:
    for i := 1 to High(Result) do
      if (Result[i] > Result[l - 1]) then
        Result[l.Increase] := Result[i];
    False:
    for i := 1 to High(Result) do
      if (Result[i] < Result[l - 1]) then
        Result[l.Increase] := Result[i];
  end;
  if (Result.Size > l) then
    SetLength(Result, l);
end;
{$ENDIF}
