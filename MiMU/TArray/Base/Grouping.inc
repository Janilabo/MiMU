{$IFDEF HELPERS}
function Classes: M2DArray; overload;
function Classes(const weight: TIntegerArray): M2DArray; overload;
function Classes(const weight: TDoubleArray): M2DArray; overload;
function Classify: M2DArray; overload;
function Classify(const weight: TIntegerArray): M2DArray; overload;
function Classify(const weight: TDoubleArray): M2DArray; overload;
function Group: M2DArray; overload;
function Group(const weight: TIntegerArray; const wSorted: Boolean = False): M2DArray; overload;
function Group(const weight: TDoubleArray; const wSorted: Boolean = False): M2DArray; overload;
function Grouped(const groups: TIntegerArray): M2DArray; overload;
function Groupify(const groups: TIntegerArray): M2DArray; overload;
function Grouping(const groups: TIntegerArray): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Classes>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function MArrayHelper.Classes: M2DArray; overload;
var
  i, g: Integer;
  v: MType;
begin
  if Self.Empty then
    Exit([]);
  g := 0;
  v := Self[0];
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to High(Self) do
  begin
    if not (Self[i] = v) then
    begin
      v := Self[i];
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], 0);
    end;
    SetLength(Result[g], (Result[g].Size + 1));
    Result[g][High(Result[g])] := Self[i];
  end;
end;

{==============================================================================]
  <Classes>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function MArrayHelper.Classes(const weight: TIntegerArray): M2DArray; overload; var w: Integer; {$DEFINE Skeleton_Classes}{$I ../Skeletons.inc}{$UNDEF Skeleton_Classes}
function MArrayHelper.Classes(const weight: TDoubleArray): M2DArray; overload; var w: Double; {$DEFINE Skeleton_Classes}{$I ../Skeletons.inc}{$UNDEF Skeleton_Classes}

{==============================================================================]
  <Classify>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function MArrayHelper.Classify: M2DArray; overload;
var
  i, h, g, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  SetLength(Result[0], l);
  Result[0][0] := Self[0];
  g := 0;
  h := 0;
  for i := 1 to High(Self) do
  case (Self[i] = Result[g][0]) of
    False:
    begin
      SetLength(Result[g], (h + 1));
      Result[g][h] := Result[g][0];
      h := 0;
      SetLength(Result[g.Increment], (l - i));
      Result[g][0] := Self[i];
    end;
	True: Result[g][h.Increase] := Self[i];
  end;
  SetLength(Result[g], (h + 1));
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Classify>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function MArrayHelper.Classify(const weight: TIntegerArray): M2DArray; overload; var w: Integer; {$DEFINE Skeleton_Classify}{$I ../Skeletons.inc}{$UNDEF Skeleton_Classify}
function MArrayHelper.Classify(const weight: TDoubleArray): M2DArray; overload; var w: Double; {$DEFINE Skeleton_Classify}{$I ../Skeletons.inc}{$UNDEF Skeleton_Classify}

{==============================================================================]
  <Group>
  @action: Groups array arr to 2D array by items.
  @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function MArrayHelper.Group: M2DArray; overload;
var
  h, i, r, g, l: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit([]);
  g := -1;
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (Self[i] = Result[r][0]);
      if f then
      begin
        l := Result[r].Length;
        SetLength(Result[r], (l + 1));
        Result[r][l] := Self[i];
        Break;
      end;
    end;
    if not f then
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Group>
  @action: Groups array arr to 2D array by items.
  @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function MArrayHelper.Group(const weight: TIntegerArray; const wSorted: Boolean = False): M2DArray; overload; var w: TIntegerArray; {$DEFINE Skeleton_Group}{$I ../Skeletons.inc}{$UNDEF Skeleton_Group}
function MArrayHelper.Group(const weight: TDoubleArray; const wSorted: Boolean = False): M2DArray; overload; var w: TDoubleArray; {$DEFINE Skeleton_Group}{$I ../Skeletons.inc}{$UNDEF Skeleton_Group}

{==============================================================================]
  <Grouped>
  @action: Groups the current array (Self) into sub-arrays based on the
           integer group IDs provided in groups, without performing any
           sorting. Unique group IDs are detected in the order they first
           appear, and each corresponding sub-array is filled accordingly.
  @note: • Requires Length(Self) = Length(groups).
         • Preserves the first-appearance order of groups.
         • Simpler but slower: overall O(n²) due to nested lookups.
         • Uses arr.Supply to dynamically append unique IDs and points.
         • Best suited for small datasets or when original group order must
           be maintained.
[==============================================================================}
function MArrayHelper.Grouped(const groups: TIntegerArray): M2DArray; overload;
var
  u: TIntegerArray;
  i, j, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  l := Self.Length;
  if ((l = 0) or (l <> groups.Size)) then
    Exit;
  SetLength(u, 0);
  for i := 0 to (l - 1) do
  begin
    f := False;
    for j := 0 to High(u) do
      if (groups[i] = u[j]) then
      begin
        f := True;
        Break;
      end;
    if not f then
      u.Supply(groups[i]);
  end;
  SetLength(Result, u.Size);
  for i := 0 to (l - 1) do
    for j := 0 to High(u) do
      if (groups[i] = u[j]) then
      begin
        Result[j].Supply(Self[i]);
        Break;
      end;
end;

{==============================================================================]
  <Grouping>
  @action: Groups the current array (Self) into sub-arrays based on the
           integer group IDs provided in groups. Items that share the same
           group value are placed in the same sub-array. The operation first
           sorts all item indices by their group ID using arr.QuickSorted,
           then builds the resulting cluster list in a single forward pass.
  @note: • Requires Length(Self) = Length(groups).
         • Runs in O(n log n) time due to sorting.
         • The resulting clusters are ordered by ascending group ID.
         • Uses dynamic array resizing during construction.
         • Suitable for large datasets where grouping speed matters more
           than preserving the original order.
[==============================================================================}
function MArrayHelper.Grouping(const groups: TIntegerArray): M2DArray; overload;
var
  i, l, g, c: Integer;
  p: TIntegerArray;
begin
  l := Self.Length;
  SetLength(Result, 0);
  if ((l = 0) or (l <> groups.Size)) then
    Exit;
  SetLength(p, l);
  for i := 0 to (l - 1) do
    p[i] := i;
  p := p.QuickSorted(groups);
  g := groups[p[0]];
  c := 0;
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to (l - 1) do
  begin
    if (groups[p[i]] <> g) then
    begin
      g := groups[p[i]];
      SetLength(Result, (c.Increment + 1));
      SetLength(Result[c], 0);
    end;
	Result[c].Supply(Self[p[i]]);
  end;
end;

{==============================================================================]
  <Groupify>
  @action: Groups the current array (Self) into sub-arrays according to the
           integer group identifiers provided in groups. Each unique group value
           becomes a separate sub-array in the result, containing all elements
           from Self whose corresponding index in groups matches that group.
  @note: • Requires `Length(Self) = Length(groups).
         • Returns an empty result if the input is empty or lengths differ.
         • Uses a TDictionary<Integer, MArray> internally for O(1) average
           grouping performance.
         • The resulting order of groups in Result is **not deterministic**
           because TDictionary.Values does not preserve insertion or sorted
           order.
         • Best suited for large datasets where grouping speed is more
           important than predictable output order.
[==============================================================================}
function MArrayHelper.Groupify(const groups: TIntegerArray): M2DArray; overload;
var
  m: specialize TDictionary<Integer, MArray>;
  l, i, g: Integer;
begin
  SetLength(Result, 0);
  l := Self.Length;
  if ((l = 0) or (l <> groups.Size)) then
    Exit;
  m := specialize TDictionary<Integer, MArray>.Create;
  try
    for i := 0 to (l - 1) do
    begin
      g := groups[i];
      if not m.ContainsKey(g) then
        m.Add(g, []);
      m[g] := (m[g] + [Self[i]]);
    end;
    Result := m.Values.ToArray;
  finally
    m.Free;
  end;
end;
{$ENDIF}