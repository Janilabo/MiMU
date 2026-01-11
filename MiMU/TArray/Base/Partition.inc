{$IFDEF HELPERS}
function Collated: M2DArray; overload;
function Components(const connections: TConnectionArray): M2DArray; overload;
function Distincted: M2DArray; overload;
function Distribute(const parts: Integer): M2DArray; overload;
function Partition(const pSize: Integer): M2DArray; overload;
function Runs: M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Collated>
  @action: Groups the elements of the array into subarrays keyed by their value.
           Each distinct MType value is assigned a unique group index, and all
           occurrences of that value are collected into the corresponding
           subarray. The result is a 2-dimensional array where each row contains
           all instances of a specific MType.
  @note: Uses a dictionary to map each unique MType to its group position,
         preserving the order in which unique values first appear. The
         original ordering of elements within each group is preserved as well.
         This operation performs a stable categorization, not a clone.
[==============================================================================}
function MArrayHelper.Collated: M2DArray; overload;
var
  m: specialize TDictionary<MType, Integer>;
  i, p: Integer;
begin
  m := specialize TDictionary<MType, Integer>.Create;
  try
    SetLength(Result, 0);
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i], p) then
      begin
        p := System.Length(Result);
        m.Add(Self[i], p);
        SetLength(Result, (p + 1));
        SetLength(Result[p], 0);
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;

{==============================================================================]
  <Components>
  @action: Groups elements of the array into connected components based on provided connections.
           Each connection is treated as undirected. Returns a 2D array where each inner array
           represents one group of connected elements.
  @param: connections - an array of TConnection, each containing two indices (Id1, Id2) 
           in Self that are connected.
  @returns: M2DArray - 2D array of grouped elements from Self.
  @note: Duplicate connections are ignored. Self must contain at least as many elements as
         the maximum index in any connection.
[==============================================================================}
function MArrayHelper.Components(const connections: TConnectionArray): M2DArray; overload;
var
  i, l: Integer;
  v: TBooleanArray;
  n: T2DIntegerArray;
  s: TIntegerArray;
  procedure DFS(const startPos: Integer; var group: MArray);
  var
    h, c, k: Integer;
  begin
    SetLength(s, 0);
    s := s + [startPos];
    while s.Occupied do
    begin
      h := High(s);
      c := s[h];
      SetLength(s, h);
      if v[c] then
        Continue;
      v[c] := True;
      group := (group + [Self[c]]);
      for k := 0 to High(n[c]) do
        if not v[n[c][k]] then
          s := (s + [n[c][k]]);
    end;
  end;
begin
  l := Self.Size;
  if l = 0 then
    Exit([]);
  SetLength(n, l);
  SetLength(v, l);
  for i := 0 to High(connections) do
    if (InRange(connections[i].id1, 0, (l - 1)) and InRange(connections[i].id2, 0, (l - 1))) then
    begin
      n[connections[i].id1] := (n[connections[i].id1] + [connections[i].id2]);
      n[connections[i].id2] := (n[connections[i].id2] + [connections[i].id1]);
    end;
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if not v[i] then
    begin
      SetLength(Result, (System.Length(Result) + 1));
      SetLength(Result[High(Result)], 0);
      DFS(i, Result[High(Result)]);
    end;
  end;
end;

{==============================================================================]
  <Distincted>
  @action: Groups the array into subarrays by unique values. Each subarray
           in the result contains all occurrences of one distinct integer from Self,
           preserving the order of first appearance.
  @note: The function preserves the original order of first occurrence for each unique
         value. It uses an auxiliary array 'm' to track which values have already
         been grouped. Duplicate values in Self are added to the same group.
         The resulting 2D array has one group per unique value.
[==============================================================================}
function MArrayHelper.Distincted: M2DArray; overload;
var
  m: MArray;
  i, l: Integer;
begin
  SetLength(m, 0);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    l := m.Pos(Self[i]);
    if (l = -1) then
    begin
      l := m.Length;
      SetLength(m, (l + 1));
      SetLength(Result, (l + 1));
      m[l] := Self[i];
    end;
    Result[l].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <Distribute>
  @action: Distributes array arr to 2D array by number of parts.
  @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
[==============================================================================}
function MArrayHelper.Distribute(const parts: Integer): M2DArray; overload;
var
  l, p, b, r, i, j, s, c: Integer;
begin
  l := Self.Length;
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
        Result[i][j] := Self[s.Increase];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Partition>
  @action: Partitions array arr to 2D array by size of parts.
  @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
function MArrayHelper.Partition(const pSize: Integer): M2DArray; overload;
var
  p, i, j, s, r, l: Integer;
begin
  if ((pSize > 0) and Self.Populated) then
  begin
    l := Self.Length;
    p := ((l + (pSize - 1)) div pSize);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * pSize);
      if ((s + pSize) > l) then
        r := (l - s)
      else
        r := pSize;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := Self[s + j];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Runs>
  @action: Groups consecutive identical values into sub-arrays.
  @note: Input must be sorted for meaningful grouping; a new group is started
         whenever the value differs from the previous element.
[==============================================================================}
function MArrayHelper.Runs: M2DArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  r := -1;
  for i := 0 to High(Self) do
  begin
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      SetLength(Result, (r.Increment + 1));
    Result[r].Supply(Self[i]);
  end;
end;
{$ENDIF}
