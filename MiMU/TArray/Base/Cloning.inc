{$IFDEF HELPERS}
function Clonage: MArray; overload;
function Clone(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Clone(const ID: TIntegerArray): MArray; overload;
function Cloned: MArray; overload;
function Clonement: MArray; overload;
function Clonify: MArray; overload;
function Copied: MArray; overload;
function Ditto: MArray; overload;
function Copy(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Doublet(const fromIndex: Integer = 0; const toIndex: Integer = 2147483647): MArray; overload;
function Dupe: MArray; overload;
function Duplicate(const xTimes: Integer = 1): MArray; overload;
function Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): MArray; overload;
function EndWith(const aItem: MType): MArray; overload;
function EndWith(const aItem: MArray): MArray; overload;
function Firsty: MType; overload;
function Firsty(const null: MType): MType; overload;
function FromLeft(const count: Integer; const index: Integer = 2147483647): MArray; overload;
function FromRight(const count: Integer; const index: Integer = 0): MArray; overload;
function Get: MArray; overload;
function Get(const ID: TIntegerArray): MArray; overload;
function Get(const ID: TRange): MArray; overload;
function Heady: MType; overload;
function Lasty: MType; overload;
function Lasty(const null: MType): MType; overload;
function Next(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Piece(const sIndexes: TRange): MArray; overload;
function Previous(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Replica(const oAscending: Boolean = True): MArray; overload;
function Replicate(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Slice(const r: TRange): MArray; overload;
function Slice(const r: TRangeArray): MArray; overload;
function StartWith(const aItem: MType): MArray; overload;
function StartWith(const aItem: MArray): MArray; overload;
function Taily: MType; overload;
function Twinned: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clonage>
  @action: Creates and returns a deep or optimized copy of the current multidimensional or custom array.
  @note: Uses direct small-size optimization for lengths 0 to 3, and a 4-pointer inward-converging 
         loop (C4 procedure) for larger arrays to maximize cache locality and performance.
[==============================================================================}
function MArrayHelper.Clonage: MArray; overload;
  procedure C4(const l, f, b, r: Integer);
  begin
    Result[l] := Self[l];
    Result[f] := Self[f];
    Result[b] := Self[b];
    Result[r] := Self[r];
  end;
var
  s, l, r, b, f, i: Integer;
begin
  s := Self.Length;
  case s of
    0: Exit([]);
    1: Exit([Self[0]]);
    2: Exit([Self[0], Self[1]]);
    3: Exit([Self[0], Self[1], Self[2]]);
  end;
  SetLength(Result, s);
  l := 0;
  r := (s - 1);
  b := (r div 2);
  f := Ceil(r / 2);
  for i := 1 to (s div 2) do
    C4(l.Increase, f.Increase, b.Decrease, r.Decrease);
end;

{==============================================================================]
  <Clone>
  @action: Returns copy of an array arr.
  @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function MArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  i, s, c: Integer;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Self.Size - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[i - s] := Self[i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Clone>
  @action: Outputs array of items from arr by indexes (ID).
  @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[==============================================================================}
function MArrayHelper.Clone(const ID: TIntegerArray): MArray; overload;
var
  i, h, l, r: Integer;
begin
  r := 0;
  if (ID.Populated and Self.Populated) then
  begin
    h := High(Self);
    l := ID.Size;
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((ID[i] <= h) and (ID[i] > -1)) then
        Result[r.Increase] := Self[ID[i]];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Cloned>
  @action: Simply returns a clone of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Cloned: MArray; overload;
var
  r: TRange;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Self.Size);
  r.Create(-1, Result.Size);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.start];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.stop];
  end;
end;

{==============================================================================]
  <Clonement>
  @action: Creates and returns a copy of the current MArray using an inline 
           4-pointer indexing strategy.
  @note: Uses direct small-size optimization for lengths 0 to 3. For larger arrays, 
         it mirrors elements inward from the edges (l, r) and outward from the 
         center (b, f) simultaneously, using Inc2/Dec2 to update boundaries.
[==============================================================================}
function MArrayHelper.Clonement: MArray; overload;
var
  d: Double;
  s, b, f, l, r, i, c: Integer;
begin
  s := Self.Length;
  case s of
    0: Exit([]);
    1: Exit([Self[0]]);
    2: Exit([Self[0], Self[1]]);
    3: Exit([Self[0], Self[1], Self[2]]);
  end;
  SetLength(Result, s);
  r := (s - 1);
  d := (r / 2);
  b := Floor(d);
  l := 0;
  f := Ceil(d);
  c := b;
  for i := 1 to c do
  begin
    Result[l] := Self[l];
    Result[b] := Self[b];
    Result[f] := Self[f];
    Result[r] := Self[r];
	Inc2(l, f);
	Dec2(b, r);
  end;
end;

{==============================================================================]
  <Clonify>
  @action: Creates and returns a copy of the current MArray using a parallelized 
           or quadrant-segmented indexing strategy.
  @note: Divides the array into four conceptual segments based on the midpoints 
         (l, m, r) and copies elements into the result array across multiple offset 
         positions simultaneously within a single loop structure.
[==============================================================================}
function MArrayHelper.Clonify: MArray; overload;
var
  i, s, m, l, r: Integer;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  m := (s div 2);
  l := (m div 2);
  r := (m + (s - m) div 2);
  for i := 0 to (s - 1) do
  begin
    if (i < l) then
      Result[i] := Self[i];
    if ((i + l) < m) then
      Result[i + l] := Self[i + l];
    if ((i + m) < r) then
      Result[i + m] := Self[i + m];
    if ((i + r) < s) then
      Result[i + r] := Self[i + r];
  end;
end;

{==============================================================================]
  <Copy>
  @action: Returns copy of an array arr.
  @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function MArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  if (index < l) then
  begin
    i := Max(index, 0);
    c := count;
    if ((i + c) > l) then
      c := (l - i);
    SetLength(Result, c);
    for l := 0 to (c - 1) do
      Result[l] := Self[l + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Copied>
  @action: Simply returns a copy of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Copied: MArray; overload;
var
  h, i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[i];
    Result[(l - i) - 1] := Self[(l - i) - 1];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;

{==============================================================================]
  <Ditto>
  @action: Returns a new array that is a direct duplicate (clone) of the 
           original array.
  @note: Initializes a range structure spanning from index 0 to the high index 
         of the array. If the target array allocation succeeds, it uses a 
         two-pointer repeat-until loop, copying elements to their identical 
         positions from both ends inward. Relies on custom integer helpers 
         (start.Increment and stop.Decrement) to advance the bounds and 
         terminate the loop.
[==============================================================================}
function MArrayHelper.Ditto: MArray; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  if (Result.SetSize(R.stop + 1) > 0) then
  repeat
    Result[R.start] := Self[R.start];
    Result[R.stop] := Self[R.stop];
  until (R.start.Increment > R.stop.Decrement);
end; 

{==============================================================================]
  <Doublet>
  @action: Returns a sub-array (slice) defined by the specified index range.
  @note  : Creates and returns a new MArray containing elements from
           fromIndex to toIndex (inclusive).
           If Self is empty (High = -1), returns [].
[==============================================================================}
function MArrayHelper.Doublet(const fromIndex: Integer = 0; const toIndex: Integer = 2147483647): MArray; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  Result := Self.Get(TRange.Construct(fromIndex.Clamp(0, h), toIndex.Clamp(0, h)));
end;

{==============================================================================]
  <Dupe>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Dupe: MArray; overload;
var
  i, l, j: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if ((l mod 2) <> 0) then
  begin
    j := (l div 2);
    Result[j] := Self[j];
  end;
  if (l > 1) then
  for i := 0 to ((l div 2) - 1) do
  begin
    j := ((l - i) - 1);
    Result[i] := Self[i];
    Result[j] := Self[j];
  end;
end;

{==============================================================================]
  <Duplicate>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Duplicate(const xTimes: Integer = 1): MArray; overload;
var
  m, i, j, l: Integer;
begin
  l := Self.Length;
  m := Max(0, xTimes);
  SetLength(Result, (m * l));
  if (l > 0) then
  for i := 0 to (m - 1) do
    for j := 0 to (l - 1) do
      Result[(i * l) + j] := Self[j];
end;

{==============================================================================]
  <Elements>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): MArray; overload;
var
  h, i, j, l, c, s: Integer;
  r: TIntegerArray;
begin
  if (Self.Empty or returnIDs.Empty) then
    Exit([]);
  if returnSort then
    r := returnIDs.QuickSorted
  else
    r := returnIDs.Copy;
  h := High(r);
  s := High(Self);
  SetLength(Result, Self.Size);
  l := 0;
  c := 0;
  for i := 0 to s do
  case ((c > h) or (r[c] > s)) of
    False:
    for j := c to h do
      if not (r[j] = i) then
      begin
        c := (j + IfThen((r[j] < 0), 1, 0));
        Break;
      end else
        Result[l.Increase] := Self[i];
    True: Break;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <EndWith>
  @action: Returns a new array containing the elements of the current array
           from index 0 up to and including the last occurrence of aItem.
  @note: If aItem is not found, the resulting array length will be zero
         or reflect the final decremented index state. No explicit
         validation is performed for a missing match. Element order
         remains unchanged.
[==============================================================================}
function MArrayHelper.EndWith(const aItem: MType): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  while (l.Decrement > -1) do
    if (Self[l] = aItem) then
      Break;
  SetLength(Result, (l + 1));
  for r := 0 to l do
    Result[r] := Self[r];
end;

{==============================================================================]
  <EndWith>
  @action: Returns a new array containing the elements of the current array
           from index 0 up to and including the last occurrence of any
           element contained in aItem.
  @note: If either the source array or aItem is empty, an empty array
         is returned. If no matching element is found, no explicit
         guard is applied and the result depends on the final index
         value after backward traversal. Element order is preserved.
[==============================================================================}
function MArrayHelper.EndWith(const aItem: MArray): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  if ((l > 0) and (aItem.Length > 0)) then
  begin
    while (l.Decrement > -1) do
      if aItem.Contains(Self[l]) then
        Break;
    SetLength(Result, (l + 1));
    for r := 0 to l do
      Result[r] := Self[r];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Firsty>
  @action: Returns the first element (index 0) of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value.
[==============================================================================}
function MArrayHelper.Firsty: MType; overload;
begin
  if (Self.Length > 0) then
    Result := Self[0];
end;

{==============================================================================]
  <Firsty>
  @action: Returns the first element of the array, or a provided 
           fallback value if the array is empty.
  @note: Returns null with empty arrays.
[==============================================================================}
function MArrayHelper.Firsty(const null: MType): MType; overload;
begin
  if (Self.Length = 0) then
    Result := null
  else
    Result := Self[0];
end;

{==============================================================================]
  <FromLeft>
  @action: Returns count of array items from left-side by index.
  @note: None
[==============================================================================}
function MArrayHelper.FromLeft(const count: Integer; const index: Integer = 2147483647): MArray; overload;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Min(High(Self), index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m - count), (m - 1)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <FromRight>
  @action: Returns count of array items from right-side by index.
  @note: None
[==============================================================================}
function MArrayHelper.FromRight(const count: Integer; const index: Integer = 0): MArray; overload;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Max(0, index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m + 1), (m + count)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Get>
  @action: Copy of an array arr.
  @note: Just an alternative.
[==============================================================================}
function MArrayHelper.Get: MArray; overload;
var
  a: MType;
  i: Integer;
begin
  SetLength(Result, Self.Size);
  i := 0;
  for a in Self do
    Result[i.Increase] := a;
 end;

{==============================================================================]
  <Get>
  @action: Outputs array of items from arr by indexes (IDs).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Get(const ID: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, ID.Size);
  for i := 0 to High(ID) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
  <Get>
  @action: Outputs array of items from arr by indexes (IDs).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Get(const ID: TRange): MArray; overload;
var
  i, a: Integer;
begin
  SetLength(Result, ID.Size);
  a := 0;
  case ID.Ascending of
    True:
    for i := ID.start to ID.stop do
      Result[a.Increase] := Self[i];
	False:
    for i := ID.start downto ID.stop do
      Result[a.Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Heady>
  @action: Returns the head (first element) of the array.
  @note: Fast access via index 0. Will throw an out-of-bounds error if the 
         array is completely empty.
[==============================================================================}
function MArrayHelper.Heady: MType; overload;
begin
  Result := Self[0];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value for MType.
[==============================================================================}
function MArrayHelper.Lasty: MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l > 0) then
    Result := Self[l - 1];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array, or a provided fallback 
           value if the array is empty.
  @note: Safe alternative to the parameterless Lasty when dealing with empty arrays.
[==============================================================================}
function MArrayHelper.Lasty(const null: MType): MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Result := null
  else
    Result := Self[l - 1];
end;

{==============================================================================]
  <Next>
  @action: Returns next items from array by index and count.
  @note: None.	
[==============================================================================}
function MArrayHelper.Next(const index: Integer; const count: Integer = 2147483647): MArray; overload;
var
  m, i: Integer;
begin
  if ((index >= 0) and (index < (Self.Size - 1)) and (count > 0)) then
  begin
    m := Min((Self.Size - (index + 1)), count);
    SetLength(Result, m);
    for i := 0 to (m - 1) do
      Result[i] := Self[(index + 1) + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Piece>
  @action: Copies a range-defined slice from the array into a new array
  @note: Respects range direction; reverses result if range is descending	
[==============================================================================}
function MArrayHelper.Piece(const sIndexes: TRange): MArray; overload;
var
  s: Integer;
begin
  s := sIndexes.Size;
  SetLength(Result, s);
  Move(Self[sIndexes.Minimum], Result[0], (s * SizeOf(MType)));
  if sIndexes.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Previous>
  @action: Returns previous array items from index by count.
  @note: None.
[==============================================================================}
function MArrayHelper.Previous(const index: Integer; const count: Integer = 2147483647): MArray; overload;
var
  m, l, i: Integer;
begin
  if ((index > 0) and (index < Self.Size) and (count > 0)) then
  begin
    m := Max(0, (index - count));
    l := (((index - 1) - m) + 1);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      Result[i] := Self[m + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Replica>
  @action: Returns a new array containing the same elements as the current
           array, ordered according to the specified sorting direction.
  @note:   - If `oAscending` is True (default), the returned array is sorted
             in ascending order.
           - If `oAscending` is False, the returned array is sorted in
             descending order.
           - The original array remains unchanged.
           - This function creates a sorted copy (non-destructive).
[==============================================================================}
function MArrayHelper.Replica(const oAscending: Boolean = True): MArray; overload;
begin
  Result := Self.Get(Self.ID(oAscending));
end;

{==============================================================================]
  <Replicate>
  @action: Returns a new array containing a contiguous slice of elements
           copied from the current array, starting at `index` and
           including up to `count` elements.
  @note: - If `index` is greater than or equal to the array length,
           an empty array is returned.
         - Negative `index` values are treated as 0.
         - If `count` exceeds the available number of elements,
           it is clamped to the remaining length.
         - The original array remains unchanged.
         - The default `count` value (MaxInt) effectively means
           “copy until the end”.
[==============================================================================}
function MArrayHelper.Replicate(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (index >= l) then
    Exit([]);
  i := Max(index, 0);
  SetLength(Result, IfThen(((i + count) > l), (l - i), count));
  for l := 0 to High(Result) do
    Result[l] := Self[l + i];
end;

{==============================================================================]
  <Slice>
  @action: Returns array slice with TRange r.
  @note: Make sure you use correct indexes and there is enough buffer in array!
         No safety checks for this function.
[==============================================================================}
function MArrayHelper.Slice(const r: TRange): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, r.Size);
  case r.Ascending of
    True:
    for i := r.start to r.stop do
      Result[i - r.start] := Self[i];
    False:
    for i := r.start downto r.stop do
      Result[i - r.start] := Self[i];
  end;
end;

{==============================================================================]
  <Slice>
  @action: Returns array slice with multiple TRanges by r.
  @note: Make sure you use correct indexes and there is enough buffer in array!
         No safety checks for this function.
[==============================================================================}
function MArrayHelper.Slice(const r: TRangeArray): MArray; overload;
var
  i, j, l: Integer;
begin
  if r.Empty then
    Exit([]);
  l := 0;
  for i := 0 to High(r) do
    l := (l + r[i].Size);
  SetLength(Result, l);
  for i := High(r) downto 0 do
  case r[i].Ascending of
    True:
    for j := r[i].stop downto r[i].start do
      Result[l.Decrement] := Self[j];
    False:
    for j := r[i].stop to r[i].start do
      Result[l.Decrement] := Self[j];
  end;
end;

{==============================================================================]
  <StartWith>
  @action: Returns a new array containing the elements of the current array
           starting from the first occurrence of aItem through to the end
           of the array. The matching element is included in the result.
  @note: If aItem is not found, the resulting array length will be
         (Length - (-1)), which may not be the intended behavior.
         No explicit check is performed for a missing match.
         The operation preserves original element order.
[==============================================================================}
function MArrayHelper.StartWith(const aItem: MType): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  i := -1;
  while (i.Increment < l) do
    if (Self[i] = aItem) then
      Break;
  SetLength(Result, (l - i));
  for r := i to (l - 1) do
    Result[r - i] := Self[r];
end;

{==============================================================================]
  <StartWith>
  @action: Returns a new array containing the elements of the current array
           starting from the first occurrence of any element contained in
           aItem through to the end of the array. The matching element is
           included in the result.
  @note: If either the source array or aItem is empty, an empty array
         is returned. If no matching element is found, no explicit
         guard is applied and the resulting length depends on the
         computed index value. Element order is preserved.
[==============================================================================}
function MArrayHelper.StartWith(const aItem: MArray): MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  if ((l > 0) and (aItem.Length > 0)) then
  begin
    i := -1;
    while (i.Increment < l) do
      if aItem.Contains(Self[i]) then
        Break;
    SetLength(Result, (l - i));
    for r := i to (l - 1) do
      Result[r - i] := Self[r];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Taily>
  @action: Returns the tail (last element) of the array.
  @note: Uses High() to target the final index. Will throw a range check error 
         if the array is empty.
[==============================================================================}
function MArrayHelper.Taily: MType; overload;
begin
  Result := Self[High(Self)];
end;

{==============================================================================]
  <Twinned>
  @action: Returns a new array that is a direct duplicate (clone) of the 
           original array.
  @note: Allocates a new array of identical length and uses a two-pointer 
         while-loop meeting in the middle to copy elements from both ends 
         simultaneously. Relies on custom integer helpers (L.Increment and 
         R.Decrement) to adjust bounds and handle iteration.
[==============================================================================}
function MArrayHelper.Twinned: MArray; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  SetLength(Result, R);
  if (R = 0) then
    Exit;
  L := -1;
  while (L.Increment <= R.Decrement) do
  begin
    Result[L] := Self[L];
    Result[R] := Self[R];
  end;
end;
{$ENDIF}
