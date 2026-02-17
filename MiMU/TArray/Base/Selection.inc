{$IFDEF HELPERS}
function Devein(const dIDs: TIntegerArray; const dValue: MType): MArray; overload;
function Devein(const dIDs: TIntegerArray): MArray; overload;
function DumpID(const ID: TIntegerArray): Integer; overload;
function DumpIDs(const ID: TIntegerArray): Integer; overload;
function DumpIndexes(const ID: TIntegerArray): Integer; overload;
function DumpIndices(const ID: TIntegerArray): Integer; overload;
function Exclude(const items: MArray; const index: Integer = 2147483647): MArray; overload;
function Expel(const eIDs: TIntegerArray): MArray; overload;
function Extract(const item: MType; const index: Integer = 0): MArray; overload;
function Extract(const items: MArray; const index: Integer = 0): MArray; overload;
function ExtractByIDs(const ID: TIntegerArray): MArray; overload;
function ExtractByIndexes(const ID: TIntegerArray): MArray; overload;
function ExtractByIndices(const ID: TIntegerArray): MArray; overload;
function ExtractEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function ExtractID(const ID: TIntegerArray): MArray; overload;
function ExtractIDs(const allowed: TIntegerArray): MArray; overload;
function ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): MArray; overload;
function ExtractIndexList(const ID: TIntegerArray): MArray; overload;
function ExtractIndices(const ID: TIntegerArray): MArray; overload;
function ExtractWithIDs(const ID: TIntegerArray): MArray; overload;
function ExtractWithIndices(const ID: TIntegerArray): MArray; overload;
function Filter(const item: MType; const index: Integer = 0): MArray; overload;
function Filter(const items: MArray; const index: Integer = 0): MArray; overload;
function FilterByIDs(const ID: TIntegerArray): MArray; overload;
function FilterByIndexes(const ID: TIntegerArray): MArray; overload;
function FilterByIndices(const ID: TIntegerArray): MArray; overload;
function FilterEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function FilterID(const ID: TIntegerArray): MArray; overload;
function FilterIDs(const forbidden: TIntegerArray): MArray; overload;
function FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): MArray; overload;
function FilterIndexList(const ID: TIntegerArray): MArray; overload;
function FilterIndices(const ID: TIntegerArray): MArray; overload;
function FilterWithIDs(const ID: TIntegerArray): MArray; overload;
function FilterWithIndices(const ID: TIntegerArray): MArray; overload;
function Keep(const items: MArray; const index: Integer = 0): MArray; overload;
function KeepID(const ID: TIntegerArray): Integer; overload;
function KeepIDs(const ID: TIntegerArray): Integer; overload;
function KeepIndexes(const ID: TIntegerArray): Integer; overload;
function KeepIndices(const ID: TIntegerArray): Integer; overload;
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
  <DumpID>
  @action: Retains only elements whose zero-based indexes are listed in `ID`.
           Uses a hash set for O(1) index lookup, compacts the array in-place,
           and updates its length.
  @note:
    • Indexes outside the range [0..Length(Self)-1] are ignored.
    • Element order is preserved.
    • Time complexity: O(n + m), where n = Length(Self) and m = Length(ID).
    • Memory complexity: O(m) for the hash set.
    • Returns the new array length after compaction.
[==============================================================================}
function MArrayHelper.DumpID(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  d: specialize TDictionary<Integer, Boolean>;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  if ID.Empty then
    Exit(l);
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to High(ID) do
      if ((ID[i] >= 0) and (ID[i] < l)) then
        d.AddOrSetValue(ID[i], True);
    Result := 0;
    for i := 0 to (l - 1) do
      if not d.ContainsKey(i) then
        Self[Result.Increase] := Self[i];
    SetLength(Self, Result);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <DumpIDs>
  @action: Removes elements from the array whose zero-based indexes are specified
           in `ID`. The input index list is normalized prior to removal, then the
           array is compacted in-place and its length reduced accordingly.
  @note:
    • `ID` is first restricted to the valid index range [0..Length(Self)-1]
      and canonicalized (sorted and de-duplicated) before processing.
    • Element order is preserved according to their original position.
    • Executes in O(n + m log m) time due to canonicalization,
      where n = Length(Self) and m = Length(ID).
    • Uses O(m) auxiliary storage for the normalized index set.
    • Returns the new length of the array after compaction.
[==============================================================================}
function MArrayHelper.DumpIDs(const ID: TIntegerArray): Integer; overload;
var
  h, l, i, j: Integer;
  r: TIntegerArray;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  r := ID.ExtractValues(TRange.Construct(0, (l - 1))).Canonical;
  j := 0;
  h := High(r);
  for i := 0 to (l - 1) do
    if ((j > h) or (i < r[j])) then
      Self[Result.Increase] := Self[i]
    else
      Inc(j);
  SetLength(Self, Result);
end;

{==============================================================================]
  <DumpIndexes>
  @action: Removes elements from the array whose zero-based indexes are specified
           in `ID`. Remaining elements are compacted in-place and the array length
           is reduced accordingly.
  @note:
    • Indexes outside the valid range [0..Length(Self)-1] are ignored.
    • Element order is preserved according to their original position.
    • Duplicate values in `ID` have no additional effect.
    • Executes in O(n + m) time with O(n) temporary boolean storage,
      where n = Length(Self) and m = Length(ID).
    • Returns the new length of the array after compaction.
[==============================================================================}
function MArrayHelper.DumpIndexes(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  r: TBooleanArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  SetLength(r, l);
  for i := 0 to High(ID) do
    if ((ID[i] >= 0) and (ID[i] < l)) then
      r[ID[i]] := True;
  Result := 0;
  for i := 0 to (l - 1) do
    if not r[i] then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <DumpIndices>
  @action: Removes elements from the array whose zero-based indexes are specified
           in `ID`. The index list is first normalized and sorted, then a binary
           search is used to determine which elements to remove. Remaining elements
           are compacted in-place and the array length is reduced.
  @note:
    • `ID` is restricted to the valid index range [0..Length(Self)-1] and
      quick-sorted prior to processing.
    • Element order is preserved according to their original positions.
    • Binary search ensures O(log m) lookup per element, resulting in
      O(n log m) total time, where n = Length(Self) and m = Length(ID).
    • Returns the new length of the array after compaction.
[==============================================================================}
function MArrayHelper.DumpIndices(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  s: TIntegerArray;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  s := ID.ExtractValues(TRange.Construct(0, (l - 1))).QuickSorted;
  for i := 0 to (l - 1) do
    if not s.BinaryContains(i) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
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
  <ExtractID>
  @action: Creates and returns a new array containing elements referenced by the
           zero-based identifiers specified in `ID`. Elements are copied in the
           order provided by `ID`.
  @note:
    • Returns an empty array if the source array is empty or `ID` is empty.
    • Extraction stops immediately if an invalid index (< 0 or > High(Self))
      is encountered; only successfully copied elements are returned.
    • The resulting array preserves the order of identifiers as given in `ID`.
    • Does not canonicalize, sort, or de-duplicate `ID`.
    • Time complexity: O(m), where m = Length(ID).
    • Allocates up to Length(ID) elements, then truncates if early termination occurs.
[==============================================================================}
function MArrayHelper.ExtractID(const ID: TIntegerArray): MArray; overload;
label
  finish;
var
  h, i, j: Integer;
begin
  h := High(Self);
  if ((h = -1) or ID.Empty) then
    Exit([]);
  SetLength(Result, ID.Length);
  j := 0;
  for i := 0 to High(ID) do
    if ((ID[i] < 0) or (ID[i] > h)) then
      goto finish
    else
      Result[j.Increase] := Self[ID[i]];
  Exit;
  finish:
  SetLength(Result, j);
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
  <ExtractIndexList>
  @action: Returns a new array containing the elements of Self located at the
           specified indices.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only indices within the valid range [0..Length-1] are considered.
    - Indices are processed in the order provided; no sorting or deduplication is performed.
    - Duplicate indices will produce duplicate elements in the result.
    - The result preserves the order defined by the input ID array.
    - Internally uses a TList to accumulate results before converting to an array.
    - If no valid indices are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractIndexList(const ID: TIntegerArray): MArray; overload;
var
  l: specialize TList<MType>;
  s, i: Integer;
begin
  l := specialize TList<MType>.Create;
  s := Self.Length;
  try
    for i := 0 to High(ID) do
      if ((ID[i] >= 0) and (ID[i] < s)) then
        l.Add(Self[ID[i]]);
    Result := l.ToArray;
  finally
    l.Free;
  end;
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
  <ExtractWithIDs>
  @action: Returns a new array containing the elements at the specified IDs.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only IDs within the valid range [0..Length-1] are considered.
    - Duplicate IDs are ignored.
    - Indices are canonicalized (sorted and deduplicated) before extraction.
    - The result preserves ascending index order.
    - Consecutive indices are copied in contiguous blocks using `Move` for maximum efficiency.
    - If Self is empty, or no valid IDs are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractWithIDs(const ID: TIntegerArray): MArray; overload;
var
  e: TIntegerArray;
  h, i, j, r, k, s, f: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  e := ID.ExtractValues(TRange.Construct(0, h));
  if e.Empty then
    Exit([]);
  e := e.Canonical;
  k := e.Length;
  SetLength(Result, k);
  r := 0;
  j := 0;
  while (j < k) do
  begin
    s := e[j];
    f := s;
    Inc(j);
    while ((j < k) and (e[j] = (f + 1))) do
    begin
      f := e[j];
      Inc(j);
    end;
    Move(Self[s], Result[r], (((f - s) + 1) * SizeOf(Self[0])));
    Inc(r, ((f - s) + 1));
  end;
end;

{==============================================================================]
  <ExtractWithIndices>
  @action: Returns a new array containing the elements at the specified indices.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only indices within the valid range [0..Length-1] are considered.
    - Duplicate indices do not produce duplicate elements (each index is included at most once).
    - The result preserves ascending index order.
    - Uses a boolean mask to mark included positions before constructing the result.
    - If Self is empty or no valid indices are supplied, an empty array is returned.
[==============================================================================}
function MArrayHelper.ExtractWithIndices(const ID: TIntegerArray): MArray; overload;
var
  m: TBooleanArray;
  l, i, j, c: Integer;
begin
  l := Self.Length;
  if ((l = 0) or ID.Empty) then
    Exit([]);
  SetLength(m, l);
  for i := 0 to High(m) do
    m[i] := False;
  for i := 0 to High(ID) do
    if ((ID[i] >= 0) and (ID[i] < l)) then
      m[ID[i]] := True;
  c := 0;
  for i := 0 to High(m) do
    if m[i] then
      Inc(c);
  SetLength(Result, c);
  j := 0;
  for i := 0 to (l - 1) do
    if m[i] then
      Result[j.Increase] := Self[i];
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
  <FilterID>
  @action: Returns a new array containing all elements of the source array
           except those whose zero-based identifiers are specified in `ID`.
  @note:
    • Returns an empty array if the source array is empty.
    • Uses a boolean exclusion mask sized to Length(Self).
    • If an invalid index (< 0 or >= Length(Self)) is encountered,
      mask population stops immediately; only previously validated
      identifiers are applied.
    • Element order is preserved.
    • Duplicate identifiers in `ID` have no additional effect.
    • Time complexity: O(n + m), where n = Length(Self) and m = Length(ID).
    • Space complexity: O(n) due to the temporary boolean mask.
[==============================================================================}
function MArrayHelper.FilterID(const ID: TIntegerArray): MArray; overload;
label
  process;
var
  l, i, j: Integer;
  e: TBooleanArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  e.Create(l, False);
  for i := 0 to High(ID) do
    if ((ID[i] < 0) or (ID[i] >= l)) then
      goto process
    else
      e[ID[i]] := True;
  process:
  SetLength(Result, l);
  j := 0;
  for i := 0 to (l - 1) do
    if not e[i] then
      Result[j.Increase] := Self[i];
  SetLength(Result, j);
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
  <FilterIndexList>
  @action: Returns a new array with the elements at the specified indices removed.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Indices are sorted before processing to ensure safe descending deletion.
    - Deletion is performed from highest to lowest index to avoid reindexing errors.
    - Only indices within the valid range [0..Count-1] are considered.
    - Duplicate indices may cause multiple deletion attempts; only valid positions are removed.
    - Relative order of remaining elements is preserved.
    - Internally uses a TList copy of Self and converts the result back to an array.
    - If no valid indices are supplied, a copy of Self is returned.
[==============================================================================}
function MArrayHelper.FilterIndexList(const ID: TIntegerArray): MArray; overload;
var
  l: specialize TList<MType>;
  i: Integer;
  s: TIntegerArray;
begin
  l := specialize TList<MType>.Create;
  try
    l.AddRange(Self);
    s := ID.QuickSorted;
    for i := High(s) downto 0 do
      if ((s[i] >= 0) and (s[i] < l.Count)) then
        l.Delete(s[i]);
    Result := l.ToArray;
  finally
    l.Free;
  end;
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
  <FilterWithIDs>
  @action: Returns a new array with the elements at the specified IDs removed.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only IDs within the valid range [0..Length-1] are considered.
    - Duplicate IDs are ignored.
    - Indices are canonicalized (sorted and deduplicated) before filtering.
    - The relative order of remaining elements is preserved.
    - Uses contiguous memory copy (`Move`) for efficiency, especially with consecutive blocks.
    - If Self is empty, an empty array is returned.
    - If no valid IDs are supplied, a copy of Self is returned.
[==============================================================================}
function MArrayHelper.FilterWithIDs(const ID: TIntegerArray): MArray; overload;
var
  f: TIntegerArray;
  h, i, j, r, k, s, e: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  f := ID.ExtractValues(TRange.Construct(0, h));
  if f.Empty then
    Exit(Self.Copy);
  f := f.Canonical;
  k := f.Length;
  SetLength(Result, ((h + 1) - k));
  r := 0;
  s := 0;
  for j := 0 to (k - 1) do
  begin
    e := (f[j] - 1);
    if (e >= s) then
    begin
      Move(Self[s], Result[r], (((e - s) + 1) * SizeOf(Self[0])));
      Inc(r, ((e - s) + 1));
    end;
    s := (f[j] + 1);
  end;
  if (s <= h) then
  begin
    Move(Self[s], Result[r], (((h - s) + 1) * SizeOf(Self[0])));
    Inc(r, ((h - s) + 1));
  end;
end;

{==============================================================================]
  <FilterWithIndices>
  @action: Returns a new array with the elements at the specified indices removed.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Only indices within the valid range [0..Length-1] are considered.
    - Duplicate indices are effectively ignored.
    - The relative order of remaining elements is preserved.
    - Uses a boolean mask to mark excluded positions before constructing the result.
    - If Self is empty, an empty array is returned.
[==============================================================================}
function MArrayHelper.FilterWithIndices(const ID: TIntegerArray): MArray; overload;
var
  m: TBooleanArray;
  l, i, j, s: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(m, l);
  for i := 0 to High(m) do
    m[i] := True;
  for i := 0 to High(ID) do
    if ((ID[i] >= 0) and (ID[i] < l)) then
      m[ID[i]] := False;
  s := 0;
  for i := 0 to High(m) do
    if m[i] then
      Inc(s);
  SetLength(Result, s);
  j := 0;
  for i := 0 to (l - 1) do
    if m[i] then
      Result[j.Increase] := Self[i];
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
  <KeepID>
  @action: Retains only elements whose zero-based indexes are listed in `ID`.
           Uses a hash set for O(1) index lookup, compacts the array in-place,
           and updates its length.
  @note:
    • Indexes outside the range [0..Length(Self)-1] are ignored.
    • Element order is preserved.
    • Time complexity: O(n + m), where n = Length(Self) and m = Length(ID).
    • Memory complexity: O(m) for the hash set.
    • Returns the new array length after compaction.
[==============================================================================}
function MArrayHelper.KeepID(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  d: specialize TDictionary<Integer, Boolean>;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  if ID.Empty then
  begin
    SetLength(Self, 0);
	Exit(0);
  end;
  d := specialize TDictionary<Integer, Boolean>.Create;
  try
    for i := 0 to High(ID) do
      if ((ID[i] >= 0) and (ID[i] < l)) then
        d.AddOrSetValue(ID[i], True);
    Result := 0;
    for i := 0 to (l - 1) do
      if d.ContainsKey(i) then
        Self[Result.Increase] := Self[i];
    SetLength(Self, Result);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <KeepIDs>
  @action: Rebuilds the array in-place so that only elements whose zero-based
           indexes are specified in `ID` are retained. The resulting array
           contains the referenced elements in ascending index order.
  @note:
    • `ID` is restricted to the valid index range [0..Length(Self)-1]
      and canonicalized (sorted and de-duplicated) prior to access.
    • Resulting element order follows the canonicalized index sequence
      (ascending original index order).
    • Executes in O(n + m log m) time due to canonicalization,
      where n = Length(Self) and m = Length(ID).
    • Uses O(m) auxiliary storage for the normalized index set.
    • Returns the new length of the array after reconstruction.
[==============================================================================}
function MArrayHelper.KeepIDs(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  r: TIntegerArray;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  r := ID.ExtractValues(TRange.Construct(0, (l - 1))).Canonical;
  for i := 0 to High(r) do
    Self[Result.Increase] := Self[r[i]];
  SetLength(Self, Result);
end; 

{==============================================================================]
  <KeepIndexes>
  @action: Filters the array in-place by retaining only elements whose zero-based
           indexes are specified in `ID`. Elements not referenced in `ID` are removed.
           The array is compacted and its length is reduced accordingly.
  @note:
    • Indexes outside the valid range [0..Length(Self)-1] are ignored.
    • Element order is preserved according to their original position in Self
      (not the order of indexes in `ID`).
    • Duplicate values in `ID` have no additional effect.
    • Executes in O(n + m) time with O(n) temporary boolean storage,
      where n = Length(Self) and m = Length(ID).
    • Returns the new length of the array after compaction.
[==============================================================================}
function MArrayHelper.KeepIndexes(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  r: TBooleanArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  SetLength(r, l);
  for i := 0 to High(ID) do
    if ((ID[i] >= 0) and (ID[i] < l)) then
      r[ID[i]] := True;
  Result := 0;
  for i := 0 to (l - 1) do
    if r[i] then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <KeepIndices>
  @action: Retains only elements in the array whose zero-based indexes are specified
           in `ID`. The index list is first normalized and sorted, then a binary
           search is used to determine which elements to keep. The array is
           compacted in-place and its length updated.
  @note:
    • `ID` is restricted to the valid index range [0..Length(Self)-1] and
      quick-sorted prior to processing.
    • Element order is preserved according to their original positions.
    • Binary search ensures O(log m) lookup per element, resulting in
      O(n log m) total time, where n = Length(Self) and m = Length(ID).
    • Returns the new length of the array after compaction.
[==============================================================================}
function MArrayHelper.KeepIndices(const ID: TIntegerArray): Integer; overload;
var
  l, i: Integer;
  s: TIntegerArray;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  s := ID.ExtractValues(TRange.Construct(0, (l - 1))).QuickSorted;
  for i := 0 to (l - 1) do
    if s.BinaryContains(i) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
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
