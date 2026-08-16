{$IFDEF HELPERS}
function BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload;
function BinaryDeduplicated(const aAscending: Boolean = True): MArray; overload;
function BinarySinglified(const item: MType; const aAscending: Boolean = True): MArray; overload;
function BinarySinglify(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload;
function BinaryUnduplicated(const aAscending: Boolean = True): MArray; overload;
function BinaryUndupe: Integer; overload;
function BinaryUnduped: MArray; overload;
function BinaryUnified(const dAscending: Boolean = True): MArray; overload;
function BinaryUniq(const oAscending: Boolean = True): Integer; overload;
function BinaryUniqd(const oAscending: Boolean = True): MArray; overload;
function BinaryUnique(const oAscending: Boolean = True): Integer; overload;
function BinaryUniqued(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryDeduplicate>
  @action: Rebuilds the array in place by removing duplicate elements using binary search.
  @note: Creates a temporary copy of the original array and appends only unique values back.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending according to aAscending).
         Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function MArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload;
var
  u: MArray;
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(0);
  for i := 0 to (u.Capture(Self) - 1) do
    if (Self.BinarySearch(u[i], aAscending) = -1) then
      Self.Supply(u[i]);
  Result := (l - Self.Size);
end;

{==============================================================================]
  <BinaryDeduplicated>
  @action: Return a new array containing unique elements from the current one.
  @note: The original array remains unchanged.
         Uses binary search to avoid inserting duplicates.
         Sorting is recommended before calling for best results.
[==============================================================================}
function MArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if (Result.BinarySearch(Self[i], aAscending) = -1) then
      Result.Supply(Self[i]);
end;

{==============================================================================]
  <BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function MArrayHelper.BinarySinglified(const item: MType; const aAscending: Boolean = True): MArray; overload;
var
  i, l, p: Integer;
begin
  p := Self.BinaryLefty(item, aAscending);
  if (p = -1) then
    Exit(Self.Copy);
  l := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if ((i = p) or (Self[i] <> item)) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function MArrayHelper.BinarySinglify(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  i, l, s, p: Integer;
begin
  p := Self.BinaryLefty(item, aAscending);
  if (p = -1) then
    Exit(0);
  s := Self.Size;
  l := p;
  for i := (p + 1) to (s - 1) do
    if (Self[i] <> item) then
      Self[l.Increment] := Self[i];
  Result := (s - (l + 1));
  if (Result > 0) then
    SetLength(Self, (l + 1));
end;

{==============================================================================]
  <BinaryUnduplicate>
  @action: Removes duplicate elements from the array in place using binary search.
  @note: Keeps only the first occurrence of each unique value.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending as specified).
         Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function MArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload;
var
  i, u, l: Integer;
begin
  l := Self.Length;
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

{==============================================================================]
  <BinaryUnduplicated>
  @action: Return a deduplicated copy of the current array using in-place logic.
  @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
         Requires sorted input for correct results.
[==============================================================================}
function MArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): MArray; overload;
var
  i, u: Integer;
begin
  Result := Self.Copy;
  if (Self.Size < 2) then
    Exit;
  u := 0;
  for i := 1 to High(Self) do
    if (Result.BinarySearchRange(Result[i], 0, u, aAscending) = -1) then
      Result[u.Increment] := Result[i];
  SetLength(Result, (u + 1));
end;

{==============================================================================]
  <BinaryUndupe>
  @action: Removes duplicate elements from Self in place, using a
           disposable sorted structure to test each element for
           uniqueness via binary search. Preserves Self's original
           relative order. Truncates Self to the deduplicated length
           and returns that new length.
  @note: Arrays of fewer than 2 elements are returned unchanged, as
         they are trivially unique.
[==============================================================================}
function MArrayHelper.BinaryUndupe: Integer; overload;
var
  s: MArray;
  i: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Length);
  Result := s.Empten;
  for i := 0 to High(Self) do
    if s.BinaryFeed(Self[i]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <BinaryUnduped>
  @action: Returns a new array containing Self's unique elements,
           built via sorted binary insertion. Output is sorted
           to Self's original order.
  @note: An empty Self returns an empty array.
[==============================================================================}
function MArrayHelper.BinaryUnduped: MArray; overload;
var
  s: MArray;
  i, r: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Clone);
  r := s.Empten;
  for i := 0 to Result.Alloc(Self.Length) do
    if s.BinaryFeed(Self[i]) then
	  Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryUnified>
  @action: Returns a new deduplicated copy of Self, scanned forward
           (dAscending = True) or backward (dAscending = False)
           through Self's elements, using a disposable sorted
           structure to test uniqueness. Output preserves scan
           order, not sorted order.
  @note: Arrays of fewer than 2 elements return a copy of Self
         unchanged.
[==============================================================================}
function MArrayHelper.BinaryUnified(const dAscending: Boolean = True): MArray; overload;
var
  s: MArray;
  i, r: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Copy);
  r := s.Empten;
  case dAscending of
    True:
    for i := 0 to Result.Alloc(Self.Length) do
      if s.BinaryFeed(Self[i]) then
        Result[r.Increase] := Self[i];
    False:
    for i := Result.Alloc(Self.Length) downto 0 do
      if s.BinaryFeed(Self[i]) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryUniq>
  @action: Removes duplicate items from an already monotonic array (ascending
           or descending), preserving only unique items and returning the final
           count.
  @note: Unlike BinaryUnique, this routine does not sort the array. It assumes
         the array is already ordered in the direction specified by oAscending.
         It performs a linear scan to compact unique values and truncates the
         array afterward.
[==============================================================================}
function MArrayHelper.BinaryUniq(const oAscending: Boolean = True): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(l);
  Result := 1;
  case oAscending of
    True:
    for i := 1 to (l - 1) do
      if (Self[i] > Self[Result - 1]) then
        Self[Result.Increase] := Self[i];
    False:
    for i := 1 to (l - 1) do
      if (Self[i] < Self[Result - 1]) then
        Self[Result.Increase] := Self[i];
  end;
  if (Result < l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <BinaryUniqd>
  @action: Returns a new array containing only the unique items from the source
           array, assuming the source is already ordered (ascending or descending),
           without modifying the original array.
  @note: This routine does not perform sorting. It creates a copy of the source
         array and then performs a linear uniqueness pass based on the direction
         specified by oAscending. Only strictly increasing (or strictly
         decreasing) transitions are preserved. The result is compacted in-place
         and truncated to the number of unique items.
[==============================================================================}
function MArrayHelper.BinaryUniqd(const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  if (Result.Size < 2) then
    Exit;
  l := 1;
  case oAscending of
    True:
    for i := 1 to High(Result) do
      if (Result[i] > Result[l - 1]) then
        Result[l.Increase] := Result[i];
    False:
    for i := 1 to High(Result) do
      if (Result[i] < Result[l - 1]) then
        Result[l.Increase] := Result[i];
  end;
  if (Result.Size > l) then
    SetLength(Result, l);
end;

{==============================================================================]
  <BinaryUnique>
  @action: Sorts the array using binary sort, removes duplicate values in-place,
           and returns the final number of unique elements.
  @note: This routine always performs a full binary sort prior to uniqueness
         filtering. After sorting, it compacts the array by overwriting
         duplicates and truncating the underlying storage to the count of
         uniques.
[==============================================================================}
function MArrayHelper.BinaryUnique(const oAscending: Boolean = True): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(l);
  Self.BinarySort(oAscending);
  Result := 1;
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  if (Result < l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <BinaryUniqued>
  @action: Returns a new array containing the unique values of the source array,
           sorted according to the specified order, without modifying the
           original array.
  @note: The function makes a full copy of the source array, applies a binary
         sort, removes duplicates by in-place compaction of the copy, and
         trims the resulting array to the count of unique elements.
[==============================================================================}
function MArrayHelper.BinaryUniqued(const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  if (Result.Size < 2) then
    Exit;
  Result.BinarySort(oAscending);
  l := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  if (Result.Size > l) then
    SetLength(Result, l);
end;
{$ENDIF}
