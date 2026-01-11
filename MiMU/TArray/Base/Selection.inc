{$IFDEF HELPERS}
function Devein(const dIDs: TIntegerArray; const dValue: MType): MArray; overload;
function Devein(const dIDs: TIntegerArray): MArray; overload;
function Exclude(const items: MArray; const index: Integer = 2147483647): MArray; overload;
function Expel(const eIDs: TIntegerArray): MArray; overload;
function Extract(const item: MType; const index: Integer = 0): MArray; overload;
function Extract(const items: MArray; const index: Integer = 0): MArray; overload;
function ExtractEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function ExtractIDs(const allowed: TIntegerArray): MArray; overload;
function ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): MArray; overload;
function Filter(const item: MType; const index: Integer = 0): MArray; overload;
function Filter(const items: MArray; const index: Integer = 0): MArray; overload;
function FilterEvery(const X: Integer = 1; const index: Integer = 0): MArray; overload;
function FilterIDs(const forbidden: TIntegerArray): MArray; overload;
function FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): MArray; overload;
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
    Exit(Self);
  r := Self.IDs;
  s.Create(Low(Self), High(Self));
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