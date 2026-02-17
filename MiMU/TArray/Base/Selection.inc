{$IFDEF HELPERS}
function Devein(const dIDs: TIntegerArray; const dValue: MType): MArray; overload;
function Devein(const dIDs: TIntegerArray): MArray; overload;
function Exclude(const items: MArray; const index: Integer = 2147483647): MArray; overload;
function Expel(const eIDs: TIntegerArray): MArray; overload;
function Extract(const item: MType; const index: Integer = 0): MArray; overload;
function Extract(const items: MArray; const index: Integer = 0): MArray; overload;
function ExtractByIDs(const ID: TIntegerArray): MArray; overload;
function ExtractByIndexes(const ID: TIntegerArray): MArray; overload;
function ExtractByIndices(const ID: TIntegerArray): MArray; overload;
function ExtractEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function ExtractIDs(const allowed: TIntegerArray): MArray; overload;
function ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): MArray; overload;
function ExtractIndices(const ID: TIntegerArray): MArray; overload;
function Filter(const item: MType; const index: Integer = 0): MArray; overload;
function Filter(const items: MArray; const index: Integer = 0): MArray; overload;
function FilterByIDs(const ID: TIntegerArray): MArray; overload;
function FilterByIndexes(const ID: TIntegerArray): MArray; overload;
function FilterByIndices(const ID: TIntegerArray): MArray; overload;
function FilterEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function FilterIDs(const forbidden: TIntegerArray): MArray; overload;
function FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): MArray; overload;
function FilterIndices(const ID: TIntegerArray): MArray; overload;
function Keep(const items: MArray; const index: Integer = 0): MArray; overload;
function Pick(const items: MArray; const index: Integer = 0): MArray; overload;
function Reject(const items: MArray; const index: Integer = 2147483647): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Devein>
  @action: Creates a copy of the current array with elements at the specified indices removed.
           Elements at the positions listed in dIDs are excluded, and the resulting array is compacted.
  @note: The optional dValue parameter is used as a sentinel to mark elements for removal.
         The original array (Self) is not modified.
         If dIDs contains indices out of range, they are ignored. Empty arrays for Self or dIDs result in an unchanged copy.
[==============================================================================}
function MArrayHelper.Devein(const dIDs: TIntegerArray; const dValue: MType): MArray; overload;
var
  i, l: Integer;
  s: TRange;
begin
  Result := Self.Copy;
  if Self.Empty then
    Exit;
  if dIDs.Empty then
    Exit;
  s.Create(0, High(Self));
  for i := 0 to High(dIDs) do
    if s.Contains(dIDs[i]) then
      Result[dIDs[i]] := dValue;
  l := 0;
  for i := 0 to High(Result) do
    if (Result[i] <> dValue) then
      Result[l.Increase] := Result[i];
  SetLength(Result, l);
end;

function MArrayHelper.Devein(const dIDs: TIntegerArray): MArray; overload;
begin
  Result := Self.Devein(dIDs, Default(MType));
end;

{==============================================================================]
  <Exclude>
  @action: Returns a new array with elements from items excluded, up to and including the specified index.
  @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function MArrayHelper.Exclude(const items: MArray; const index: Integer = 2147483647): MArray; overload;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Self.Length;
  m := Min(index, (l - 1));
  SetLength(Result, l);
  d := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  for i := (m + 1) to (l - 1) do
    Result[i - d] := Self[i];
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
  <Expel>
  @action: Returns a copy of the current array (Self) with elements at the specified indices removed.
           The resulting array is compacted, excluding all elements listed in eIDs.
  @note: If the current array is empty, returns an empty array.
         If eIDs is empty, returns a copy of the original array.
         Indices in eIDs that are out of range are ignored.
         Uses -2147483648 as an internal sentinel to mark elements for removal.
[==============================================================================}
function MArrayHelper.Expel(const eIDs: TIntegerArray): MArray; overload;
var
  i, l: Integer;
  s: TRange;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  if eIDs.Empty then
    Exit(Self.Copy);
  r := Self.IDs;
  s.Create(0, High(Self));
  for i := 0 to High(eIDs) do
    if s.Contains(eIDs[i]) then
      r[eIDs[i]] := -2147483648;
  l := 0;
  SetLength(Result, s.Size);
  for i := s.start to s.stop do
    if (r[i] <> -2147483648) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <Extract>
  @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
  @note: Returns the items.
[==============================================================================}
function MArrayHelper.Extract(const item: MType; const index: Integer = 0): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] = item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Extract>
  @action: Keeps (extracts) all values in arr that are in items. Starts scan from start index.
  @note: Returns the items.
[==============================================================================}
function MArrayHelper.Extract(const items: MArray; const index: Integer = 0): MArray; overload;
var
  i, l, r: Integer;
begin
  r := 0;
  if items.Populated then
  begin
    l := Self.Length;
    SetLength(Result, (l - index));
    for i := index to (l - 1) do
      if items.Contains(Self[i]) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <ExtractByIDs>
  @action: Returns a new array containing the elements of Self located at the
           specified IDs (indexes).
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only IDs within the valid range [0..Length-1] are considered.
    - Duplicate IDs are ignored.
    - The result preserves the original order of elements in Self.
    - If Self is empty, or no valid IDs are supplied, an empty array is returned.
    - Internally uses a hash set for O(1) membership checks.
[==============================================================================}
function MArrayHelper.ExtractByIDs(const ID: TIntegerArray): MArray; overload;
var
  d: specialize TDictionary<Integer, Byte>;
  i, r, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := specialize TDictionary<Integer, Byte>.Create;
  try
    for i in ID do
      if ((i >= 0) and (i < l)) then
        d.TryAdd(i, 0);
    if (d.Count = 0) then
      Exit([]);
    SetLength(Result, d.Count);
    r := 0;
    for i := 0 to High(Self) do
      if d.ContainsKey(i) then
        Result[r.Increase] := Self[i];
    SetLength(Result, r);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <ExtractByIndexes>
  @action: Returns a new array containing the elements at the specified indexes.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only indexes within the valid range [0..Length-1] are considered.
    - Indexes are canonicalized (sorted and deduplicated) before extraction.
    - The result is ordered by ascending index.
    - If Self is empty, or no valid indexes are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractByIndexes(const ID: TIntegerArray): MArray; overload;
var
  e: TIntegerArray;
  i, j, r, n, k: Integer;
begin
  if Self.Empty then
    Exit([]);
  e := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if e.Empty then
    Exit([]);
  e := e.Canonical;
  n := Self.Length;
  k := e.Length;
  SetLength(Result, k);
  i := -1;
  j := 0;
  r := 0;
  while ((i.Increment < n) and (j < k)) do
    if (i = e[j]) then
    begin
      Result[r.Increase] := Self[i];
      Inc(j);
    end;
end;

{==============================================================================]
  <ExtractByIndices>
  @action: Returns a new array containing the elements of Self located at the
           specified indices.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Indices outside the valid range [0..Length-1] are ignored.
    - Indices are canonicalized (sorted and deduplicated) prior to extraction.
    - The resulting array is ordered by ascending index.
    - If Self is empty, or no valid indices are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractByIndices(const ID: TIntegerArray): MArray; overload;
var
  c, i, r, l: Integer;
  e: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  e := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if e.Empty then
    Exit([]);
  e := e.Canonical;
  c := 0;
  r := 0;
  i := -1;
  SetLength(Result, e.Length);
  l := Result.Length;
  repeat
    if (i.Increment < e[c]) then
      Continue;
    Result[r.Increase] := Self[i];
    Inc(c);
  until (r >= l);
end;

{==============================================================================]
  <ExtractEvery>
  @action: Keeps (extracts) all X values from array. Starts scan from start index.
  @note: Returns the items.
[==============================================================================}
function MArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
var
  i, h, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <ExtractIDs>
  @action: Keeps (extracts) all allowed index values from array.
  @note: None.
[==============================================================================}
function MArrayHelper.ExtractIDs(const allowed: TIntegerArray): MArray; overload;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(allowed) do
    if ((allowed[i] > -1) and (allowed[i] < l)) then
      m[allowed[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <ExtractIndexes>
  @action: Keeps (extracts) all allowed index values from array.
  @note: If allowed is not in ascending order, aSorted needs to be False.
[==============================================================================}
function MArrayHelper.ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): MArray; overload;
var
  h, i, l: Integer;
  a: TIntegerArray;
begin
  l := Self.Length;
  if ((l = 0) or allowed.Empty) then
    Exit([]);
  SetLength(Result, l);
  if not aSorted then
    a := allowed.QuickSorted
  else
    a := allowed.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if a.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <ExtractIndices>
  @action: Returns a new array containing the elements of Self located at the
           specified indices.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Indices outside the valid range [0..Length-1] are ignored.
    - Indices are canonicalized (sorted and deduplicated) before extraction.
    - The result is ordered by ascending index.
    - If Self is empty, or no valid indices are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractIndices(const ID: TIntegerArray): MArray; overload;
var
  i: Integer;
  e: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  e := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if e.Empty then
    Exit([]);
  e := e.Canonical;
  SetLength(Result, e.Length);
  for i := 0 to High(e) do
    Result[i] := Self[e[i]];
end;

{==============================================================================]
  <Filter>
  @action: Removes all values from arr that are found in items.
  @note: None
[==============================================================================}
function MArrayHelper.Filter(const item: MType; const index: Integer = 0): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] <> item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Filter>
  @action: Removes all values from arr that are found in items.
  @note: None
[==============================================================================}
function MArrayHelper.Filter(const items: MArray; const index: Integer = 0): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  if items.Empty then
    Exit(Self.Copy(index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <FilterByIDs>
  @action: Returns a new array with the elements at the specified IDs (indexes) removed.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only IDs within the valid range [0..Length-1] are considered.
    - Duplicate IDs are ignored.
    - The relative order of remaining elements is preserved.
    - If Self is empty, an empty array is returned.
    - If no valid IDs are supplied, a copy of Self is returned.
    - Internally uses a hash set for O(1) membership checks.
[==============================================================================}
function MArrayHelper.FilterByIDs(const ID: TIntegerArray): MArray; overload;
var
  d: specialize TDictionary<Integer, Byte>;
  i, r, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := specialize TDictionary<Integer, Byte>.Create;
  try
    for i in ID do
      if ((i >= 0) and (i < l)) then
        d.TryAdd(i, 0);
    if (d.Count = 0) then
      Exit(Self.Copy);
    SetLength(Result, l);
    r := 0;
    for i := 0 to High(Self) do
      if not d.ContainsKey(i) then
        Result[r.Increase] := Self[i];
    SetLength(Result, r);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <FilterByIndexes>
  @action: Returns a new array with the elements at the specified indexes excluded.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only indexes within the valid range [0..Length-1] are considered.
    - Indexes are canonicalized (sorted and deduplicated) before filtering.
    - The relative order of remaining elements is preserved.
    - If Self is empty, an empty array is returned.
    - If no valid indexes are supplied, a copy of Self is returned.
[==============================================================================}
function MArrayHelper.FilterByIndexes(const ID: TIntegerArray): MArray; overload;
var
  f: TIntegerArray;
  i, j, r, n, k: Integer;
begin
  if Self.Empty then
    Exit([]);
  f := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if f.Empty then
    Exit(Self.Copy);
  f := f.Canonical;
  n := Self.Length;
  k := f.Length;
  SetLength(Result, (n - k));
  i := -1;
  j := 0;
  r := 0;
  while (i.Increment < n) do
    if ((j < k) and (i = f[j])) then
      Inc(j)
    else
      Result[r.Increase] := Self[i];
end;

{==============================================================================]
  <FilterByIndices>
  @action: Returns a new array with the elements at the specified indices excluded.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Indices outside the valid range [0..Length-1] are ignored.
    - Indices are canonicalized (sorted and deduplicated) before filtering.
    - The relative order of remaining elements is preserved.
    - If Self is empty, an empty array is returned.
    - If no valid indices are supplied, a copy of Self is returned.
[==============================================================================}
function MArrayHelper.FilterByIndices(const ID: TIntegerArray): MArray; overload;
var
  j, c, i, r, l: Integer;
  f: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  f := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if f.Empty then
    Exit(Self.Copy);
  f := f.Canonical;
  c := 0;
  r := 0;
  i := -1;
  j := f.Length;
  SetLength(Result, (Self.Length - j));
  l := Result.Length;
  repeat
    if (i.Increment < f[c]) then
      Result[r.Increase] := Self[i]
    else
      Inc(c);
  until ((r = l) or (c = j));
  if (r < l) then
  for i := (f[c - 1] + 1) to High(Self) do
    Result[r.Increase] := Self[i];
end;

{==============================================================================]
  <FilterEvery>
  @action: Filters every/each X item from arr.
  @note: Custom index
[==============================================================================}
function MArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
var
  i, h, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <FilterIDs>
  @action: Returns the array without values from forbidden indexes.
  @note: None.
[==============================================================================}
function MArrayHelper.FilterIDs(const forbidden: TIntegerArray): MArray; overload;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(forbidden) do
    if ((forbidden[i] > -1) and (forbidden[i] < l)) then
      m[forbidden[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if not m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <FilterIndexes>
  @action: Returns the array without values from forbidden indexes.
  @note: If forbidden is not in ascending order, fSorted needs to be False.
[==============================================================================}
function MArrayHelper.FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): MArray; overload;
var
  h, i, l: Integer;
  f: TIntegerArray;
begin
  if forbidden.Empty then
    Exit(Self.Copy);
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if not fSorted then
    f := forbidden.QuickSorted
  else
    f := forbidden.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if not f.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
  <FilterIndices>
  @action: Returns a new array with the elements at the specified indices removed.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Indices outside the valid range [0..Length-1] are ignored.
    - Indices are canonicalized (sorted and deduplicated) before processing.
    - Relative order of remaining elements is preserved.
    - If Self is empty, an empty array is returned.
    - If no valid indices are supplied, a copy of Self is returned.
[==============================================================================}
function MArrayHelper.FilterIndices(const ID: TIntegerArray): MArray; overload;
var
  j, c, i, r: Integer;
  f: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  f := ID.ExtractValues(TRange.Construct(0, High(Self)));
  if f.Empty then
    Exit(Self.Copy);
  f := f.Canonical;
  c := 0;
  j := 0;
  r := 0;
  SetLength(Result, (Self.Length - f.Length));
  repeat
    for i := c to (f[j] - 1) do
      Result[r.Increase] := Self[i];
    c := (f[j] + 1);
    Inc(j);
  until (j = f.Length);
  for i := (f[j - 1] + 1) to High(Self) do
    Result[r.Increase] := Self[i];
end;

{==============================================================================]
  <Keep>
  @action: Keeps items in array, removes others.
  @note: Supports custom start index! Returns the modified arr.
[==============================================================================}
function MArrayHelper.Keep(const items: MArray; const index: Integer = 0): MArray; overload;
var
  m, i, l, r: Integer;
begin
  l := Self.Length;
  m := Max(0, index);
  case (items.Populated and (m < l)) of
    True:
    begin
      r := 0;
      SetLength(Result, l);
      for i := 0 to (m - 1) do
        Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
          Result[i - r] := Self[i]
        else
          Inc(r);
      SetLength(Result, (l - r));
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
  <Pick>
  @action: Alternative method for arr.Keep
  @note: None.
[==============================================================================}
function MArrayHelper.Pick(const items: MArray; const index: Integer = 0): MArray; overload;
var
  i, m, l: Integer;
begin
  l := Self.Length;
  m := Max(0, index);
  case (items.Populated and (m < l)) of
    True:
    begin
      SetLength(Result, m);
      for i := 0 to (m - 1) do
        Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
        begin
          SetLength(Result, (Result.Size + 1));
          Result[High(Result)] := Self[i];
        end;
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
  <Reject>
  @action: Returns a new array with elements from items excluded, up to and including the specified index.
  @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function MArrayHelper.Reject(const items: MArray; const index: Integer = 2147483647): MArray; overload;
var
  i, l, m, c: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Self.Length;
  m := Min(index, (l - 1));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Inc(c);
  SetLength(Result, (c + (l - (m + 1))));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[c.Increase] := Self[i];
  for i := (m + 1) to (l - 1) do
    Result[c.Increase] := Self[i];
end;
{$ENDIF}
