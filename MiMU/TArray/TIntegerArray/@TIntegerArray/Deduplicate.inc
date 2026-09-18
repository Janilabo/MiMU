{$IFDEF HELPERS}
function Distill(const N: UInt32 = 999; const rAscending: Boolean = True): TIntegerArray; overload;
function Distill(const minVal, maxVal: Integer; const rAscending: Boolean = True): TIntegerArray; overload;
function Mapique(const N: UInt32 = 999): TIntegerArray; overload;
function Mapique(const minVal, maxVal: Integer): TIntegerArray; overload;
function Undupe: TIntegerArray; overload;
function Unduped: TIntegerArray; overload;
function Unduplicate: Integer; overload;
function Unital(const aMin, aMax: Integer): TIntegerArray; overload;
function Unital(const N: UInt32 = 999): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distill>
  @action: Returns a sorted array of unique elements within a symmetric range [-N..N] using a direct-address boolean map.
  @note: Achieves O(n + N) time complexity. Values outside [-N..N] will cause an out-of-bounds access on map m.
[==============================================================================}
function TIntegerArrayHelper.Distill(const N: UInt32 = 999; const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, r, v: Integer;
  m: TBooleanArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Cloned);
  r := 0;
  SetLength(m, ((N * 2) + 1));
  for i := 0 to High(Self) do
    m[Self[i] + N] := True;
  SetLength(Result, Self.Length);
  case rAscending of
    True:
    for v := -N to N do
      if m[v + N] then
        Result[r.Increase] := v;
    False:
    for v := N downto -N do
      if m[v + N] then
        Result[r.Increase] := v;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Distill>
  @action: Returns a sorted array of unique elements within [minVal..maxVal] using a direct-address boolean map.
  @note: Achieves O(n + k) time complexity, where k is the span (maxVal - minVal + 1). Replaces comparative sorting with a linear count-map pass.
[==============================================================================}
function TIntegerArrayHelper.Distill(const minVal, maxVal: Integer; const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, r: Integer;
  m: TBooleanArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Cloned);
  r := 0;
  SetLength(m, ((maxVal - minVal) + 1));
  for i := 0 to High(Self) do
    m[Self[i] - minVal] := True;
  SetLength(Result, Self.Length);
  case rAscending of
    True:
    for i := minVal to maxVal do
      if m[i - minVal] then
        Result[r.Increase] := i;
    False:
    for i := maxVal downto minVal do
      if m[i - minVal] then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Mapique>
  @action: Returns a new array with unique elements by mapping integer values within a symmetric signed range [-N..N] to a boolean lookup table.
  @note: Operates in O(n) linear time with O(N) auxiliary space. Values outside the range [-N..N] will cause out-of-bounds access on array m. Assumes m[...].Enable sets the boolean flag and evaluates to True on first visit.
[==============================================================================}
function TIntegerArrayHelper.Mapique(const N: UInt32 = 999): TIntegerArray; overload;
var
  i, r: Integer;
  m: TBooleanArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Cloned);
  r := 0;
  SetLength(m, ((N * 2) + 1));
  for i := 0 to Result.Alloc(Self.Length) do
    if m[Self[i] + N].Enable then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Mapique>
  @action: Returns a new array containing only distinct elements,
           removing duplicates in O(n) time using a boolean lookup map across a specified value range.
  @note: Preserves original insertion order. Operates in linear time at the cost of O(k) memory,
         where k is the span (maxVal - minVal + 1). Assumes m[...].Enable sets the flag and returns True on its first call.
[==============================================================================}
function TIntegerArrayHelper.Mapique(const minVal, maxVal: Integer): TIntegerArray; overload;
var
  i, r: Integer;
  m: TBooleanArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Cloned);
  r := 0;
  SetLength(m, ((maxVal - minVal) + 1));
  for i := 0 to Result.Alloc(Self.Length) do
    if m[Self[i] - minVal].Enable then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray; overload;
begin
  Result := Self.Copy;
  CIntegerArray.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray; overload;
var
  i, l: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    l := 0;
    r := Self.Bounds;
	b.Create(r.Size, False);
    for i := 0 to High(Self) do
      if b[Self[i] - r.start].Enable then
        Result[l.Increase] := Self[i];
    SetLength(b, 0);
	SetLength(Result, l);
  end;
end;

{==============================================================================]
  <Unduplicate>
  @action: Removes all duplicate elements from the array, leaving only the
           first occurrence of each value. The operation modifies the array
           in place.
  @note: - Returns the number of elements removed.  
         - Preserves the original order of first occurrences.  
         - Uses a temporary Boolean array to track which values have been
           seen (based on the array’s bounds).  
         - If the array is empty or contains a single element, no changes
           are made and the result is 0.
[==============================================================================}
function TIntegerArrayHelper.Unduplicate: Integer; overload;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(Self);
  if (y > 0) then
  begin
    z := 0;
    r := Self.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
    begin
      if b[Self[x] - r.start] then
        Continue;
      b[Self[x] - r.start] := True;
      Self[z.Increase] := Self[x];
    end;
    SetLength(b, 0);
    SetLength(Self, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;

{==============================================================================]
  <Unital>
  @action: Removes duplicates from arr in O(n) via pigeonhole indexing —
           values used directly as offsets into a seen-buffer, no
           comparisons. aMin/aMax bound the value range and must be known
           by the caller; memory cost is (aMax - aMin + 1) Booleans.
  @note: Returns the unique version of arr, first-occurrence order
         preserved. TIntegerArray-only.
		 Values outside [aMin, aMax] are out of bounds.
[==============================================================================}
function TIntegerArrayHelper.Unital(const aMin, aMax: Integer): TIntegerArray; overload;
var
  m: TBooleanArray;
  l, i, c, s: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Cloned);
  for i := 0 to m.Alloc((aMax - aMin) + 1) do
    m[i] := False;
  c := 0;
  for i := 0 to Result.Alloc(l) do
    if not m[Self[i] - aMin] then
    begin
      m[Self[i] - aMin] := True;
      Result[c.Increase] := Self[i];
    end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Unital>
  @action: Convenience overload of Unital for values symmetric around zero —
           equivalent to Unital(-N, N) without the caller computing the pair.
  @note: Returns the unique version of arr, first-occurrence order
         preserved. Default N = 999 covers [-999, 999]; values outside
         [-N, N] are out of bounds.
[==============================================================================}
function TIntegerArrayHelper.Unital(const N: UInt32 = 999): TIntegerArray; overload;
var
  m: TBooleanArray;
  l, i, c, s: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Cloned);
  for i := 0 to m.Alloc((N * 2) + 1) do
    m[i] := False;
  c := 0;
  for i := 0 to Result.Alloc(l) do
    if not m[Self[i] + N] then
    begin
      m[Self[i] + N] := True;
      Result[c.Increase] := Self[i];
    end;
  SetLength(Result, c);
end;
{$ENDIF}
