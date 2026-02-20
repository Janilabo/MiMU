{$IFDEF HELPERS}
function Clone(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Clone(const ID: TIntegerArray): MArray; overload;
function Cloned: MArray; overload;
function Copied: MArray; overload;
function Copy(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Doublet(const fromIndex: Integer = 0; const toIndex: Integer = 2147483647): MArray; overload;
function Dupe: MArray; overload;
function Duplicate(const xTimes: Integer = 1): MArray; overload;
function Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): MArray; overload;
function FromLeft(const count: Integer; const index: Integer = 2147483647): MArray; overload;
function FromRight(const count: Integer; const index: Integer = 0): MArray; overload;
function Get: MArray; overload;
function Get(const ID: TIntegerArray): MArray; overload;
function Get(const ID: TRange): MArray; overload;
function Next(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Previous(const index: Integer; const count: Integer = 2147483647): MArray; overload;
function Replica(const oAscending: Boolean = True): MArray; overload;
function Replicate(const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Slice(const r: TRange): MArray; overload;
function Slice(const r: TRangeArray): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
