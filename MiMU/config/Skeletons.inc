{$IFDEF Skeleton_Swap}
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}

{$IFDEF Skeleton_Max}
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Min}
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Compare}
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_Precede}
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;
{$ENDIF}

{$IFDEF Skeleton_Ascending}
begin
  Result := (Self <= target);
end;
{$ENDIF}

{$IFDEF Skeleton_Descending}
begin
  Result := (Self >= target);
end;
{$ENDIF} 

{$IFDEF Skeleton_IfThen}
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_Select}
begin
  if Self then
    Result := bTrue
  else
    Result := bFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_Select2}
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := sTrue
    else
      Result[i] := sFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_Evaluate}
begin
  case Self of
    True: Result := bTrue;
    False: Result := bFalse;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_Increase}
begin
  Result := Self;
  Self := (Self + N);
end;
{$ENDIF}

{$IFDEF Skeleton_Decrease}
begin
  Result := Self;
  Self := (Self - N);
end;
{$ENDIF}

{$IFDEF Skeleton_Increment}
begin
  Self := (Self + N);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_Decrement}
begin
  Self := (Self - N);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_ClampMin}
begin
  if (Self < limit) then
    Result := limit
  else
    Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_ClampMax}
begin
  if (Self > limit) then
    Result := limit
  else
    Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_Clamp}
begin
  if (Self < minimum) then
    Result := minimum
  else
    if(Self > maximum) then
      Result := maximum
    else
      Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_LimitMin}
begin
  Result := Max(Self, limit);
end;
{$ENDIF}

{$IFDEF Skeleton_LimitMax}
begin
  Result := Min(Self, limit);
end;
{$ENDIF}

{$IFDEF Skeleton_Limit}
begin
  Result := EnsureRange(Self, minimum, maximum);
end;
{$ENDIF}

{$IFDEF Skeleton_ConstraintMin}
begin
  Result := (Self < limit);
  if Result then
    Self := limit;
end;
{$ENDIF}

{$IFDEF Skeleton_ConstraintMax}
begin
  Result := (Self > limit);
  if Result then
    Self := limit;
end;
{$ENDIF}

{$IFDEF Skeleton_Constraint}
begin
  Result := (Self.ConstraintMin(minimum) or Self.ConstraintMax(maximum));
end;
{$ENDIF}

{$IFDEF Skeleton_QuickSorted}
  procedure QS_IDs(var aID: TIntegerArray; const L, R: Integer);
  var
    c: Integer;
    a: TRange;
  begin
    a.Create(L, R);
    w := weight[aID[a.Central]];
    repeat
      c := weight[aID[a.start]].Compare(w);
      while (aAscending and (c < 0)) or ((not aAscending) and (c > 0)) do
        c := weight[aID[a.start.Increment]].Compare(w);
      c := weight[aID[a.stop]].Compare(w);
      while (aAscending and (c > 0)) or ((not aAscending) and (c < 0)) do
        c := weight[aID[a.stop.Decrement]].Compare(w);
      if a.Ascending then
        Swap(aID[a.start.Increase], aID[a.stop.Decrease]);
    until a.Drops;
    if (L < a.stop) then
      QS_IDs(aID, L, a.stop);
    if (a.start < R) then
      QS_IDs(aID, a.start, R);
  end;
var
  n, i: Integer;
  r: TIntegerArray;
begin
  n := Length(Self);
  if ((n > 0) and (n = Length(weight))) then
  begin
    SetLength(Result, n);
    Result := Self.Copy;
    SetLength(r, n);
    for i := 0 to (n - 1) do
      r[i] := i;
    QS_IDs(r, 0, (n - 1));
    for i := 0 to (n - 1) do
      Result[i] := Self[r[i]];
  end else
    SetLength(Result, 0);
end;
{$ENDIF}

{$IFDEF Skeleton_Classes}
var
  i, g: Integer;
begin
  if ((Length(Self) = 0) or (Length(Self) <> Length(weight))) then
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
    SetLength(Result[g], (Length(Result[g]) + 1));
    Result[g][High(Result[g])] := Self[i];
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_Classify}
var
  i, c, l, s: Integer;
begin
  l := Length(Self);
  if ((l = 0) or (l <> Length(weight))) then
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
  l := Length(Self);
  if ((l = 0) or (Length(weight) <> l))then
    Exit([]);
  if not wSorted then
    w := weight.QuickSorted
  else
    w := weight.Copy;
  w.BinaryPrune;
  Result.Recreate(Length(w));
  for i := 0 to High(Self) do
  begin
    g := w.BinarySearch(weight[i]);
    l := Length(Result[g]);
    SetLength(Result[g], (l + 1));
    Result[g][l] := Self[i];
  end;
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
      m := r.Middle;
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
        m := r.Middle;
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
  n := Length(Self);
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
        m := r.Middle;
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
  r.Create(0, Length(Self));
  while r.Grows do
  begin
    m := r.Middle;
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
  r.Create(0, Length(Self));
  while r.Grows do
  begin
    m := r.Middle;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  Result := r.start;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryPosL}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Length(Self));
  while r.Grows do
  begin
    m := r.Middle;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start < Length(Self)) and (Self[r.start] = x)) then
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
  r.Create(0, Length(Self));
  while r.Grows do
  begin
    m := r.Middle;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start > 0) and (Self[r.start - 1] = x)) then
    Result := (r.Start - 1);
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
    m := r.Middle;
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
    m := Result.Middle;
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
    m := r.Middle;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := r.start;
  SetLength(Self, (Length(Self) + 1));
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
    m := r.Middle;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  SetLength(Result, (Length(Self) + 1));
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
    m := r.Middle;
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
    m := r.Middle;
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
  SetLength(Result, Length(Self));
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
    m := r.Middle;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Length(Self) = r.start) or (Self[r.start] <> x));
  if not Result then
    Exit;
  SetLength(Self, (Length(Self) + 1));
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
    m := r.Middle;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Length(Self) > r.start) and (Self[r.start] = x));
  if not Result then
    Exit;
  for i := r.start to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Length(Self) - 1));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUndupe}
var
  i: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Length(Self));
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
  if (Length(Self) < 2) then
    Exit(Self.Copy);
  SetLength(Result, Length(Self));
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
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Middle;
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

{$IFDEF Skeleton_BinaryUpperBound}
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Middle;
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

{$IFDEF Skeleton_BinaryRange1}
var
  r: TRange;
begin
  if Self.Empty then
    Exit(Result.Create(-1, -1));
  r := x.Normalize;
  Result.start := Self.BinaryLowerBound(r.start, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryUpperBound(r.stop, aAscending)
  else
    Result.stop := -1;
  if ((Result.start = -1) or (Result.stop = -1) or (Result.start > Result.stop)) then
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
  if (Length(Self) = 0) then
    Exit(Result.Create(-1, -1));
  n := x.Normalize;
  r.Create(0, High(Self));
  case aAscending of
    True:
    while (r.start <= r.stop) do
    begin
      m := r.Center;
      if (Self[m] < n.start) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Center;
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
      m := r.Center;
      if (Self[m] <= n.stop) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
    False:
    while (r.start <= r.stop) do
    begin
      m := r.Center;
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
  s.Create(0, Length(Self));
  i.Create(0, Length(items));
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
  s.Create(0, Length(Self));
  i.Create(0, Length(items));
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
  l: specialize TFPGList<TVar>;
  r: Integer;
  s, i: TRange;
begin
  l := specialize TFPGList<TVar>.Create;
  try
    i.Create(0, Length(items));
    s.Create(0, Length(Self));
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
  l := Length(Self);
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
  Result := (l - Length(Self));
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
    m := s.Center;
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
  if (Length(Self) = 0) then
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
  l, r, m, i: Integer;
begin
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  if (Result > 0) then
  begin
    l := 0;
    r := (Result - 1);
    while (l <= r) do
    begin
      m := ((l + r) div 2);
      if ((aAscending and (Self[m] >= x)) or ((not aAscending) and (Self[m] <= x))) then
      begin
        Result := m;
        r := (m - 1);
      end else
        l := (m + 1);
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
  L, M, R: Integer;
begin
  Result := -1;
  L := rLeft;
  R := rRight;
  while (L <= R) do
  begin
    M := ((L + R) div 2);
    if (Self[M] = x) then
      Exit(M)
    else
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        R := (M - 1);
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryDeduplicate}
var
  i, l: Integer;
begin
  l := Length(Self);
  if (l < 2) then
    Exit(0);
  u := Self.Copy;
  SetLength(Self, 0);
  for i := 0 to (l - 1) do
    if (Self.BinarySearch(u[i], aAscending) = -1) then
      Self.Supply(u[i]);
  Result := (l - Length(Self));
end;
{$ENDIF}

{$IFDEF Skeleton_BinaryUnduplicate}
var
  i, u, l: Integer;
begin
  l := Length(Self);
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
  if (Length(Self) < 2) then
    Exit;
  u := 0;
  for i := 1 to High(Self) do
    if (Result.BinarySearchRange(Result[i], 0, u, aAscending) = -1) then
      Result[u.Increment] := Result[i];
  SetLength(Result, (u + 1));
end;
{$ENDIF}