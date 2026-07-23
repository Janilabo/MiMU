{$IFDEF HELPERS}
function Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Clique(const diff: Integer): T2DIntegerArray; overload;
function Cluster(const diff: UInt32 = 0; const oAscending: Boolean = True): T2DIntegerArray; overload;
function Cluster(const oAscending: Boolean; const diff: UInt32 = 0): T2DIntegerArray; overload;
function Cluster(const minDiff, maxDiff: UInt32; const oAscending: Boolean = True): T2DIntegerArray; overload;
function Cluster(const oAscending: Boolean; const minDiff, maxDiff: UInt32): T2DIntegerArray; overload;
function Clustered(const radius: UInt32 = 0; const oAscending: Boolean = True): T2DIntegerArray; overload;
function Clusters(const radius: UInt32 = 0): T2DIntegerArray; overload;
function Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Groub(const diff: Integer): T2DIntegerArray; overload;
function Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Group(const diff: Integer): T2DIntegerArray; overload;
function Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
function Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Knit(const diff: Integer): T2DIntegerArray; overload;
function Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Sblit(const diff: Integer): T2DIntegerArray; overload;
function Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Split(const diff: Integer): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Strict splitting!
[==============================================================================}
function TIntegerArrayHelper.Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (High(Self) > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to High(Self) do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          m := True;
          for b := 0 to (l - 1) do
            if ((Self[i] = Result[a][b]) or (not m)) then
              Break
            else
              m := s.Value(Abs(Self[i] - Result[a][b]));
          if m then
          begin
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
	  SetLength(Result, r);
    end;
  end; 
end;

{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Clique(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Clique(0, diff);
end;

{==============================================================================]
  <Cluster>
  @action: Groups sorted integer values into sub-arrays (clusters) based on a maximum absolute difference threshold between consecutive elements.
  @note: First sorts the array according to `oAscending`. If the absolute difference between the last clustered element and the current element exceeds `diff`,
         a new cluster is started. Automatically trims output dimensions to fit.
[==============================================================================}
function TIntegerArrayHelper.Cluster(const diff: UInt32 = 0; const oAscending: Boolean = True): T2DIntegerArray; overload;
var
  s: TIntegerArray;
  i, l, r, g: Integer;
begin
  g := Result.SetSize(Self.Length);
  if (g = 0) then
    Exit;
  r := 0;
  s := Self.QuickSorted(oAscending);
  Result[0] := [s[0]];
  SetLength(Result[0], g);
  l := 0;
  for i := 1 to High(s) do
    if (Result[r][l].Difference(s[i]) > diff) then
    begin
      SetLength(Result[r.Increase], (l + 1));
      SetLength(Result[r], (g - i));
      Result[r][0] := s[i];
      l := 0;
    end else
      Result[r][l.Increment] := s[i];
  SetLength(Result[r], (l + 1));
  SetLength(Result, (r + 1));
end;

function TIntegerArrayHelper.Cluster(const oAscending: Boolean; const diff: UInt32 = 0): T2DIntegerArray; overload;
begin
  Result := Self.Cluster(diff, oAscending);
end;

{==============================================================================]
  <Cluster>
  @action: Groups sorted integer values into sub-arrays (clusters) where consecutive elements must fall within a specific difference range (`minDiff` to `maxDiff`).
  @note: First sorts the array according to `oAscending`. An element is added to the current cluster only if its absolute difference from the previous element satisfies `minDiff <= difference <= maxDiff`; otherwise,
         a new cluster begins.
[==============================================================================}
function TIntegerArrayHelper.Cluster(const minDiff, maxDiff: UInt32; const oAscending: Boolean = True): T2DIntegerArray; overload;
var
  s: TIntegerArray;
  i, l, r, g, d: Integer;
begin
  g := Result.SetSize(Self.Length);
  if (g = 0) then
    Exit;
  r := 0;
  s := Self.QuickSorted(oAscending);
  Result[0] := [s[0]];
  SetLength(Result[0], g);
  l := 0;
  for i := 1 to High(s) do
  begin
    d := Result[r][l].Difference(s[i]);
    if ((d < minDiff) or (d > maxDiff)) then
    begin
      SetLength(Result[r.Increase], (l + 1));
      SetLength(Result[r], (g - i));
      Result[r][0] := s[i];
      l := 0;
    end else
      Result[r][l.Increment] := s[i];
  end;
  SetLength(Result[r], (l + 1));
  SetLength(Result, (r + 1));
end;

function TIntegerArrayHelper.Cluster(const oAscending: Boolean; const minDiff, maxDiff: UInt32): T2DIntegerArray; overload;
begin
  Result := Self.Cluster(minDiff, maxDiff, oAscending);
end;

{==============================================================================]
  <Clustered>
  @action: Groups integers into clusters based on whether consecutive sorted elements fall within a maximum distance (radius).
  @note: Sorts the array according to `oAscending` before grouping. Starts a new sub-array whenever the absolute difference between adjacent elements exceeds `radius`.
         Returns a dynamic 2D array trimmed to the exact number of created clusters.
[==============================================================================}
function TIntegerArrayHelper.Clustered(const radius: UInt32 = 0; const oAscending: Boolean = True): T2DIntegerArray; overload;
var
  s, r: TIntegerArray;
  i, c: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  s := Self.QuickSorted(oAscending);
  c := 0;
  r := [];
  case oAscending of
    True:
    for i := 0 to High(s) do
      if ((i = 0) or ((s[i] - s[i - 1]) > radius)) then
      begin
        if (r.Length > 0) then
          Result[c.Increase] := r;
        r := [s[i]];
      end else
        r.Supply(s[i]);
    False:
    for i := 0 to High(s) do
      if (i = 0) or ((s[i - 1] - s[i]) > radius) then
      begin
        if (r.Length > 0) then
          Result[c.Increase] := r;
        r := [s[i]];
      end else
        r.Supply(s[i]);
  end;
  if (r.Length > 0) then
    Result[c.Increase] := r;
  SetLength(Result, c);
end;

{==============================================================================]
  <Clusters>
  @action: Groups the integers in the array into clusters based on a given distance threshold.
  @note: Uses a 1D range-bucket breadth-first search (BFS) approach; values are added to a cluster
         if their absolute difference from any member is less than or equal to radius.
[==============================================================================}
function TIntegerArrayHelper.Clusters(const radius: UInt32 = 0): T2DIntegerArray; overload;
var
  s, i, j, c, r, x, p, d, z: Integer;
  a, b: TRange;
  v: TBooleanArray;
  g: T2DIntegerArray;
  q: TIntegerArray;
  e: Boolean;
begin
  case Self.Length of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, Self.Length);
  b := Self.Bounds;
  s := (b.stop - b.start);
  d := Max(0, radius);
  c := Ceil(d);
  SetLength(g, (s + 1));
  SetLength(v, (s + 1));
  for i := 0 to High(Self) do
    g[Self[i] - b.start].Supply(Self[i]);
  r := 0;
  for i := 0 to High(Self) do
  begin
    if (v[Self[i] - b.start] or g[Self[i] - b.start].Empty) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Length > 0) do
    begin
      z := q[High(q)];
      SetLength(q, High(q));
      a.start := Max(0, ((z - b.start) - c));
      a.stop := Min(s, ((z - b.start) + c));
      for x := a.start to a.stop do
      begin
        if v[x] then
          Continue;
        for j := 0 to High(g[x]) do
          if ((not (g[x][j] = Low(Integer))) and (Abs(z - g[x][j]) <= d)) then
          begin
            Result[r].Supply(g[x][j]);
            q.Supply(g[x][j]);
            g[x][j] := Low(Integer);
          end;
        e := True;
        for j := 0 to High(g[x]) do
          if (g[x][j] <> Low(Integer)) then
          begin
            e := False;
            Break;
          end;
        if e then
          v[x] := True;
      end;
    end;
    if (Result[r].Length > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r: Integer;
  s: TRange;
  m: Boolean;
begin
  if (Result.SetSize(Self.Size) > 0) then
  begin
    a := Self.BinarySorted;
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        if ((a[i] = Result[j][0]) or s.Value(Abs(a[i] - Result[j][0]))) then
        begin
	  Result[j].Supply(a[i]);
          m := True;
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    a.Empten;
    SetLength(Result, r);
  end;
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Groub(0, diff);
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (High(Self) > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to High(Self) do
      begin
        m := False;
        for a := 0 to (r - 1) do
          if ((Self[i] = Result[a][0]) or s.Value(Abs(Self[i] - Result[a][0]))) then
          begin
            m := True;
	    Result[a].Supply(Self[i]);
            Break;
          end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
      SetLength(Result, r);
    end;
  end;
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Group(0, diff);
end;

{==============================================================================]
  <Groups>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the ones with same values.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
var
  i: Integer;
  a: TIntegerArray;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  if not aSorted then
    a := Self.QuickSorted
  else
    a := Self.Copy;
  a.BinaryPrune;
  for i := 0 to High(Self) do
    Result[a.BinarySearch(Self[i])].Supply(Self[i]);
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    a := Self.BinarySorted;
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        m := True;
        l := Result[j].Length;
        for k := 0 to (l - 1) do
          if ((a[i] = Result[j][k]) or (not m)) then
            Break
          else
            m := s.Value(Abs(a[i] - Result[j][k]));
        if m then
        begin
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    a.Empten;
    SetLength(Result, r);
  end;
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Knit(0, diff);
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    a := Self.BinarySorted;
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        l := Result[j].Length;
        for k := 0 to (l - 1) do
        begin
          m := ((a[i] = Result[j][k]) or s.Value(Abs(a[i] - Result[j][k])));
          if not m then
            Continue;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
	if m then
	  Break;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    a.Empten;
    SetLength(Result, r);
  end;
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Sblit(0, diff);
end;

{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (High(Self) > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to High(Self) do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          for b := 0 to (l - 1) do
	  begin
	    m := ((Self[i] = Result[a][b]) or s.Value(Abs(Self[i] - Result[a][b])));
	    if not m then
              Continue;
	    SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
	  if m then
	    Break;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
      SetLength(Result, r);
    end;
  end;
end;

{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Split(0, diff);
end;
{$ENDIF}
