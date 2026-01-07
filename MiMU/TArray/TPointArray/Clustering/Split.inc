{$IFDEF HELPERS}
function CSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
function CSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
function CSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload; 
function RSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
function RSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
function RSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
function Split(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Split(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Split(const radius: Double = 1.0): T2DPointArray; overload;
function SplitEx(const xRadius, yRadius: Integer): T2DPointArray; overload;
function SplitEx(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function SplitEx(const radius: Double = 1.0): T2DPointArray; overload;
function XSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
function XSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
function XSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
function YSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
function YSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
function YSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CSplit>
  @action: Groups points into clusters based on horizontal (X-axis) proximity.
  @note: Sorts by column (X) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.CSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.CSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.CSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <CSplit>
  @action: Splits the point set into disjoint clusters using a column-oriented
           expansion rule. A working copy of the array is optionally sorted by
           (X, then Y). Each cluster is formed by starting from an unassigned
           seed point and adding all points whose horizontal separation from
           the seed is within xRadius and whose vertical separation is within
           yRadius. Newly added points become additional expansion sources until
           no further points qualify.
  @note: This method is the column-ordered analogue to RSplit. When sSorted
         is False, the input is first sorted by column (X-major order), which
         determines the order in which seeds are encountered but does not
         affect cluster membership. The expansion process is a simple iterative
         scan: for every point already in the cluster, all remaining points are
         tested for axis-aligned proximity (rectangular window). Complexity is
         O(N²) in the worst case. No metric distance is evaluated—only direct
         coordinate comparisons.
[==============================================================================}
function TPointArrayHelper.CSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create((p.X - xRadius), (p.X + xRadius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <RSplit>
  @action: Groups points into clusters based on vertical (Y-axis) proximity.
  @note: Sorts by row (Y) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.RSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.RSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.RSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <RSplit>
  @action: Partitions the point set into disjoint groups based on axis-aligned
           proximity criteria, optionally assuming the input is already sorted
           by (Y, then X). Each group is built by repeatedly expanding from a
           seed point and adding all unassigned points whose vertical separation
           from the seed is within yRadius and whose horizontal separation is
           within xRadius. Returns an array of these groups.
  @note: This procedure implements a row-oriented regional split. If sSorted
         is False, the method first creates a working copy of the input and
         sorts it by Y (and secondarily by X). The grouping uses a simple
         expansion pass (not a queue-based BFS) in which newly added points
         are appended to the cluster and subsequently used as additional
         expansion seeds. Ordering of the sorted working array influences
         cluster formation order but not final cluster membership. Worst-case
         complexity is O(N²). No distance metric is used—only coordinate-wise
         comparisons.
[==============================================================================}
function TPointArrayHelper.RSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create((p.Y - yRadius), (p.Y + yRadius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if Result[c][r].Within(p[s], xRadius, yRadius) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by radius.
  @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if Result[c][r].Within(p[s], radius, distFunc) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Split(radius, @Euclidean);
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Self.Length;
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and p.Within(Self[k], xRadius, yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by radius.
  @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Self.Length;
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and p.Within(Self[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.SplitEx(radius, @Euclidean);
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters based on X/Y coordinate proximity.
  @note: Optimized for arrays sorted by X (ascending).
         Each group contains points within |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
         If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.XSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create((p.X - xRadius), (p.X + xRadius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters using a custom distance function.
  @note: Efficient for data already sorted by X.
         Points are grouped if distFunc(p, q) ≤ radius.
         The X-range window limits comparisons for performance (O(n log n) typical).
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters using Euclidean distance.
  @note: Shorthand for XSplit(radius, @Euclidean, sSorted).
         Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.XSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters based on Y/X coordinate proximity.
  @note: Optimized for arrays sorted by Y (ascending).
         Each group contains points within |ΔY| ≤ yRadius and |ΔX| ≤ xRadius.
         If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.YSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create((p.Y - yRadius), (p.Y + yRadius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters using a custom distance function.
  @note: Efficient for data already sorted by Y.
         Points are grouped if distFunc(p, q) ≤ radius.
         Y-sorted scanning limits comparisons for faster clustering.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters using Euclidean distance.
  @note: Shorthand for YSplit(radius, @Euclidean, sSorted).
         Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.YSplit(radius, @Euclidean, sSorted);
end;
{$ENDIF}
