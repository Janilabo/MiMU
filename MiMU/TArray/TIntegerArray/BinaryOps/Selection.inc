{$IFDEF HELPERS}
function BinaryCapture(const items: TIntegerArray; const iAscending: Boolean = True): TIntegerArray; overload;
function BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryIsolate(const items: TIntegerArray; const iAscending: Boolean = True): TIntegerArray; overload;
function BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCapture>
  @action: Performs a range-optimized membership intersection between the current
           array (Self) and the supplied array (items). Returns a new array containing
           only the values from Self that exist in items.
  @note:
    - Assumes items are sorted according to iAscending.
    - Uses a contiguous TRange derived from the first and last elements of items.
    - Internally builds a boolean lookup table spanning the computed range,
      enabling O(n + m) time complexity (n = Self length, m = items length).
    - Preserves the original order of elements as they appear in Self.
    - If items is empty, returns an empty array.
    - If Self is empty, returns an empty array (preallocated then truncated).
    - Duplicate values in Self are preserved if they match items.
[==============================================================================}
function TIntegerArrayHelper.BinaryCapture(const items: TIntegerArray; const iAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  e: TBooleanArray;
  r: TRange;
begin
  if items.Empty then
    Exit([]);
  SetLength(Result, Self.Length);
  if Self.Empty then
    Exit;
  case iAscending of
    True: r.Create(items[0], items[High(items)]);
    False: r.Create(items[High(items)], items[0]);
  end;
  e.Create(r.Size, False);
  for i := 0 to High(items) do
    e[items[i] - r.start] := True;
  l := 0;
  for i := 0 to High(Self) do
    if (r.Contains(Self[i]) and e[Self[i] - r.start]) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryExtract>
  @action: Returns all integers from Self that lie within the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, R.Size);
  for i := R.start to R.stop do
    Result[i - R.start] := Self[i];
end;

function TIntegerArrayHelper.BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  v: TIntegerArray;
  h, i, r: Integer;
begin
  if (Self.Empty or values.Empty) then
    Exit([]);
  v := values.QuickSorted;
  h := High(v);
  SetLength(Result, Self.Size);
  r := 0;
  case aAscending of
    True:
    for i := 0 to High(Self) do
      if (Self[i] > v[h]) then
        Break
      else if ((Self[i] >= v[0]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
    False:
    for i := 0 to High(Self) do
      if (Self[i] < v[0]) then
        Break
      else if ((Self[i] <= v[h]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns all integers from Self that lie outside the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, L, h: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, (L - R.Size));
  h := 0;
  for i := 0 to (L - 1) do
    if ((i < R.start) or (i > R.stop)) then
      Result[h.Increase] := Self[i];
end;

function TIntegerArrayHelper.BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, r: Integer;
begin
  if Self.Empty then
    Exit([]);
  if values.Empty then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if not values.BinaryContains(Self[i], aAscending) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryIsolate>
  @action: Performs a range-optimized exclusion (set difference) between the current
           array (Self) and the supplied array (items). Returns a new array containing
           only the values from Self that do NOT exist in items.
  @note:
    - Assumes items are sorted according to iAscending.
    - Uses a contiguous TRange derived from the first and last elements of items.
    - Internally builds a boolean lookup table spanning the computed range,
      enabling O(n + m) time complexity.
    - Preserves the original order of elements as they appear in Self.
    - If items is empty, returns a copy of Self.
    - If Self is empty, returns an empty array.
    - Duplicate values in Self are preserved if not excluded.
[==============================================================================}
function TIntegerArrayHelper.BinaryIsolate(const items: TIntegerArray; const iAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  f: TBooleanArray;
  r: TRange;
begin
  if items.Empty then
    Exit(Self.Copy);
  SetLength(Result, Self.Length);
  if Self.Empty then
    Exit;
  case iAscending of
    True: r.Create(items[0], items[High(items)]);
    False: r.Create(items[High(items)], items[0]);
  end;
  f.Create(r.Size, False);
  for i := 0 to High(items) do
    f[items[i] - r.start] := True;
  l := 0;
  for i := 0 to High(Self) do
    if (r.Missing(Self[i]) or not f[Self[i] - r.start]) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
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

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
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
