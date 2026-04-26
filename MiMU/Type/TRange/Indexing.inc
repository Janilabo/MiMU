{$IFDEF METHODS}
function AsID(const oAscending: Boolean = True): TIntegerArray; overload;
function AsIDs: TIntegerArray; overload;
function AsIndexes: TIntegerArray; overload;
function AsIndices: TIntegerArray; overload;
function Entries: TIntegerArray; overload;
function GetIDs: TIntegerArray; overload;
function GetIndexes: TIntegerArray; overload;
function GetIndices: TIntegerArray; overload;
function Identifiers: TIntegerArray; overload;
function IDs: TIntegerArray; overload;
function IDs(const dValue: Integer): Integer; overload;
function IDs(const dVals: TIntegerArray): TIntegerArray; overload;
function Indexed: TIntegerArray; overload;
function Indexes: TIntegerArray; overload;
function Indexing: TIntegerArray; overload;
function Indiced: TIntegerArray; overload;
function Indices: TIntegerArray; overload;
function IndexList: TIntegerArray; overload;
function Keys: TIntegerArray; overload;
function LoadID(var target: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Paged(const pageSize: Integer = 2): T2DIntegerArray; overload;
function Pagenize(const pageSize: Integer = 2): T2DIntegerArray; overload;
function Pages(const pageSize: Integer = 2): T2DIntegerArray; overload;
function Paging(const pageSize: Integer = 2): T2DIntegerArray; overload;
function Positional: TIntegerArray; overload;
function Positionally: TIntegerArray; overload;
function Positions: TIntegerArray; overload;
function Serialization: TIntegerArray; overload;
function Slots: TIntegerArray; overload;
function Slotted: TIntegerArray; overload;
function ToIDs: TIntegerArray; overload;
function ToIndexes: TIntegerArray; overload;
function ToIndices: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsID>
  @action: Constructs and returns a positional identifier vector for the
           current range instance.
  @note: • If the range is Singular, returns [0].
         • Result length equals Self.Size.
         • oAscending = True  →  [0, 1, 2, ..., Size - 1]
           oAscending = False →  [Size - 1, ..., 2, 1, 0]
         • Generation is arithmetic-progression based (±1 step).
         • Does not depend on the range’s actual Start/Stop values —
           only on its computed Size.
[==============================================================================}
function TRange.AsID(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s: Integer;
begin
  if Self.Singular then
    Exit([0]);
  s := IfThen(oAscending, 1, -1);
  SetLength(Result, Self.Size);
  Result[0] := oAscending.Select(0, High(Result));
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + s);
end;

{==============================================================================]
  <AsIDs>
  @action: Returns an integer array of length equal to the range size, where each
           element is assigned a zero-based sequential ID corresponding to its
           position in the array.
  @note:
    - The generated IDs always start at 0 and increase monotonically.
    - The actual numeric values of `Self.start` and `Self.stop` are NOT used,
      except to determine the array length via `Size`.
    - IDs are generated in fixed-size chunks (CHUNK_SIZE = 10), which is an
      implementation detail and does not affect the final result.
    - The resulting array is equivalent to:
          Result[i] := i
      for all valid indices.
    - Useful when a range needs to be mapped to stable, compact identifiers
      (e.g., indexing, lookup tables, parallel arrays).
[==============================================================================}
function TRange.AsIDs: TIntegerArray; overload;
const
  CHUNK_SIZE = 10;
var
  i, o, s, c: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  o := 0;
  while (o < s) do
  begin
    c := (s - o);
    if (c > CHUNK_SIZE) then
      c := CHUNK_SIZE;
    for i := 0 to (c - 1) do
      Result[o + i] := (o + i);
    Inc(o, CHUNK_SIZE);
  end;
end;

{==============================================================================]
  <AsIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.AsIndexes: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to (s div 2) do
  begin
    Result[i] := i;
    Result[(s - 1) - i] := ((s - 1) - i);
  end;
end;

{==============================================================================]
  <AsIndices>
  @action: Builds a zero-based index array using exponential block growth.
  @note: Produces the sequence [0, 1, 2, ..., Size-1] by repeatedly duplicating
         the initialized prefix and offsetting it. The working segment grows
         exponentially (h := h * 2), reducing iteration overhead compared to
         linear filling. Handles non power-of-two sizes by limiting each copy
         to the remaining capacity. Relies on Move for bulk transfer and
         assumes Size >= 1.
[==============================================================================}
function TRange.AsIndices: TIntegerArray; overload;
var
  h, s, i, z: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([0]);
  SetLength(Result, s);
  Result[0] := 0;
  h := 1;
  z := SizeOf(Integer);
  while (h < s) do
  begin
    i := Min(h, (s - h));
    Move(Result[0], Result[h], (i * z));
    for i := h to Min(((h + i) - 1), (s - 1)) do
      Result[i] := (Result[i] + h);
    h := (h * 2);
  end;
end;

{==============================================================================]
  <Entries>
  @action: Fills array with zero-based indices via enumerator iteration
  @note: Identical to Labels; sequential assignment using Range enumerator
[==============================================================================}
function TRange.Entries: TIntegerArray; overload;
var
  i: Integer;
  e: TRangeEnumerator;
begin
  SetLength(Result, Self.Size);
  e := Range(0, High(Result)).GetEnumerator;
  i := 0;
  while e.MoveNext do
    Result[i.Increase] := e.Current;
end;

{==============================================================================]
  <GetIDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.GetIDs: TIntegerArray; overload;
  procedure F(var arr: TIntegerArray; const idx: Integer);
  begin
    if (idx < 0) then
      Exit;
    arr[idx] := idx;
    F(arr, (idx - 1));
  end;
begin
  SetLength(Result, Self.Size);
  F(Result, High(Result));
end;

{==============================================================================]
  <GetIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.GetIndexes: TIntegerArray; overload;
var
  s, i: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to ((s - 1) div 2) do
    Result[i * 2] := (i * 2);
  for i := 0 to ((s - 2) div 2) do
    Result[(i * 2) + 1] := ((i * 2) + 1);
end;

{==============================================================================]
  <GetIndices>
  @action: Generates a zero-based sequential index array for the range.
  @note: Returns the sequence [0, 1, 2, ..., Size-1] by initializing the
         array with 1s (except the first element set to 0) and performing
         a prefix sum. Functionally equivalent to Slots, using a simple
         linear accumulation strategy. Assumes Size >= 1.
[==============================================================================}
function TRange.GetIndices: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([0]);
  SetLength(Result, s);
  FillDWord(Result[0], s, 1);
  Result[0] := 0;
  for i := 1 to (s - 1) do
    Result[i] := (Result[i - 1] + Result[i]);
end;

{==============================================================================]
  <Identifiers>
  @action: Fills array with zero-based indices using recursive midpoint assignment
  @note: Divide-and-conquer; writes center-out; avoids sequential iteration
[==============================================================================}
function TRange.Identifiers: TIntegerArray; overload;
  procedure Return(var arr: TIntegerArray; const lo, hi: Integer);
  var
    m: Integer;
  begin
    if (lo > hi) then
	  Exit;
	m := ((lo + hi) div 2);
    arr[m] := m;
    Return(arr, lo, (m - 1));
    Return(arr, (m + 1), hi);
  end;
begin
  SetLength(Result, Self.Size);
  if (Result.Length > 0) then
    Return(Result, 0, High(Result));
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dValue: Integer): Integer; overload;
begin
  case Self.Ascending of
    True:
    if ((dValue < Self.start) or (dValue > Self.stop)) then
      Result := -2147483648
    else
      Result := (dValue - Self.start);
    False:
    if ((dValue > Self.start) or (dValue < Self.stop)) then
      Result := -2147483648
    else
      Result := (Self.start - dValue);
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dVals: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dVals) + 1));
  for i := 0 to High(dVals) do
    Result[i] := Self.IDs(dVals[i]);
end;

{==============================================================================]
  <Indexed>
  @action: Returns an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Implemented using loop unrolling for improved performance.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.Indexed: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  while ((i + 3) < s) do
  begin
    Result[i + 0] := (i + 0);
    Result[i + 1] := (i + 1);
    Result[i + 2] := (i + 2);
    Result[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  for s := i to High(Result) do
    Result[s] := s;
end;

{==============================================================================]
  <Indexes>
  @action: Returns an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Straightforward reference implementation.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.Indexes: TIntegerArray; overload;
  function Output(const rSize: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, rSize);
    for i := 0 to (rSize - 1) do
      Result[i] := i;
  end;
begin
  Result := Output(Self.Size);
end;

{==============================================================================]
  <Indexing>
  @action: Generates and returns an array of integer “IDs” corresponding to the range, 
           using the digits 0..9 as a repeated base pattern. The length of the resulting 
           array is equal to the size of the range (`Size := Abs(stop - start) + 1`).
  @note:
    - The array is filled in blocks of 10 using the constant `BASE_DIGITS = [0..9]`.  
      If the range size is not a multiple of 10, the final block is truncated to fit.
    - This method does **not** take the actual `start` or `stop` values of the range 
      into account except for determining the array length.
    - The pattern produces a repeated sequence of 0..9, so the first elements are
      always 0,1,2,...9, then repeated with offsets.
    - Useful when you need a simple repeating ID pattern for indexing, mapping, 
      or placeholder purposes.
[==============================================================================}
function TRange.Indexing: TIntegerArray; overload;
var
  b, i, o, d, s: Integer;
begin
  b := System.Length(BASE_DIGITS);
  s := Self.Size;
  SetLength(Result, s);
  o := -b;
  while (o.Increment(b) < s) do
    for i := 0 to Min((b - 1), ((s - o) - 1)) do
      Result[o + i] := (BASE_DIGITS[i] + o);
end;

{==============================================================================]
  <Indiced>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Indiced: TIntegerArray; overload;
begin
  SetLength(Result, 0);
  while (Result.Length < Self.Size) do
    Result.Supply(System.Length(Result));
end;

{==============================================================================]
  <Indices>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Indices: TIntegerArray; overload;
var
  l, r: Integer;
begin
  SetLength(Result, Self.Size);
  l := -1;
  r := Result.Length;
  while (l.Increment < r.Decrement) do
  begin
    Result[l] := l;
    Result[r] := r;
  end;
  if (l = r) then
    Result[l] := l;
end;

{==============================================================================]
  <IndexList>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IndexList: TIntegerArray; overload;
var
  l: specialize TList<Integer>;
  i: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    for i := 0 to (Self.Size - 1) do
      l.Add(i);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Keys>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Keys: TIntegerArray; overload;
label
  loop, finish;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  loop:
  if (i >= s) then
    goto finish;
  Result[i] := i;
  Inc(i);
  goto loop;
  finish:
end;

{==============================================================================]
  <LoadID>
  @action: Loads the target array with positional identifiers derived from
           the current range instance.
  @note: • Returns Self.Size.
         • Ensures target.Length = Self.Size (resizes if required).
         • oAscending = True  →  [0, 1, 2, ..., Size - 1]
           oAscending = False →  [Size - 1, ..., 2, 1, 0]
         • If the range is Singular, target[0] is initialized and the
           method exits.
         • Sequence is generated as an arithmetic progression (±1 step).
         • Independent of the range’s actual boundary values; relies
           solely on computed Size.
[==============================================================================}
function TRange.LoadID(var target: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  i, s: Integer;
begin
  Result := Self.Size;
  if (target.Length <> Result) then
    SetLength(target, Result);
  target[0] := oAscending.Select(0, (Result - 1));
  if Self.Singular then
    Exit;
  s := IfThen(oAscending, 1, -1);
  for i := 1 to (Result - 1) do
    target[i] := (target[i - 1] + s);
end;

{==============================================================================]
  <Paged>
  @action: Distributes zero-based indices into a two-dimensional array of
           fixed-size blocks (pages).
  @note:
    - The total number of indices generated is equal to Self.Size.
    - Each page has a length of PageSize, except potentially the last page.
    - Useful for UI virtualization, multi-threaded processing, or avoiding
      large contiguous memory allocations.
[==============================================================================}
function TRange.Paged(const pageSize: Integer = 2): T2DIntegerArray; overload;
var
  s, c, i, p, r, l: Integer;
begin
  if (pageSize < 1) then
    Exit([]);
  s := Self.Size;
  c := ((s + pageSize - 1) div pageSize);
  SetLength(Result, c);
  for p := 0 to (c - 1) do
  begin
    r := (s - (p * pageSize));
    if (r < pageSize) then
      l := r
    else
      l := pageSize;
    SetLength(Result[p], l);
    for i := 0 to (l - 1) do
      Result[p][i] := ((p * pageSize) + i);
  end;
end;

{==============================================================================]
  <Pagenize>
  @action: Partitions the zero-based index sequence of the range into a 
           two-dimensional array of discrete pages.
  @note: 
    - Uses TRange.Construct to create a temporary "Index Range" for each page.
    - Calls .Items on each sub-range to populate the nested arrays.
    - This approach is highly maintainable as it relies on existing 
      range-to-array logic rather than manual pointer or loop math.
[==============================================================================}
function TRange.Pagenize(const pageSize: Integer = 2): T2DIntegerArray; overload;
var
  p, s: Integer;
begin
  if (pageSize < 1) then
    Exit([]);
  s := Self.Size;
  SetLength(Result, ((s + pageSize - 1) div pageSize));
  for p := 0 to High(Result) do
    Result[p] := TRange.Construct((p * pageSize), Min((((p + 1) * pageSize) - 1), (s - 1))).Items;
end;

{==============================================================================]
  <Pages>
  @action: Distributes zero-based indices into a two-dimensional array of
           fixed-size blocks (pages).
  @note:
    - The total number of indices generated is equal to Self.Size.
    - Each page has a length of PageSize, except potentially the last page.
    - Useful for UI virtualization, multi-threaded processing, or avoiding
      large contiguous memory allocations.
[==============================================================================}
function TRange.Pages(const pageSize: Integer = 2): T2DIntegerArray; overload;
var
  s, i, j, l, r: Integer;
  P: PInteger;
begin
  if (pageSize < 1) then
    Exit([]);
  s := Self.Size;
  SetLength(Result, ((s + pageSize - 1) div pageSize));
  r := 0;
  for i := 0 to High(Result) do
  begin
    l := Min(pageSize, (s - (i * pageSize)));
    SetLength(Result[i], l);
    if (l > 0) then
    begin
      P := @Result[i][0];
      for j := 1 to l do
      begin
        P^ := r.Increase;
        Inc(P);
      end;
    end;
  end;
end; 

{==============================================================================]
  <Paging>
  @action: Slices the range indices into a two-dimensional paginated structure 
           using optimized bulk memory transfers.
  @note: 
    - First generates a linear index array using Self.ToIndices.
    - Uses System.Move to rapidly copy segments of the linear array into 
      individual pages.
    - Highly efficient for large ranges where manual iteration is a bottleneck.
[==============================================================================}
function TRange.Paging(const pageSize: Integer = 2): T2DIntegerArray; overload;
var
  s, c, p, r, l, o, z: Integer;
  i: TIntegerArray;
begin
  if (pageSize < 1) then
    Exit([]);
  s := Self.Size;
  c := ((s + pageSize - 1) div pageSize);
  SetLength(Result, c);
  i := Self.ToIndices;
  z := SizeOf(Integer);
  for p := 0 to (c - 1) do
  begin
    o := (p * pageSize);
    l := Min(pageSize, (s - o));
    SetLength(Result[p], l);
    if (l > 0) then
      Move(i[o], Result[p][0], (l * z));
  end;
end;

{==============================================================================]
  <Positional>
  @action: Returns zero-based positional indices [0..Size-1]
  @note: Uses Range(0, Size-1); empty if Size = 0
[==============================================================================}
function TRange.Positional: TIntegerArray; overload;
begin
  Result := Range(0, (Self.Size - 1)).Items;
end;

{==============================================================================]
  <Positionally>
  @action: Generates a zero-based index array using pairwise packed writes.
  @note: Produces the sequence [0, 1, 2, ..., Size-1] by writing two indices
         at a time via 64-bit packing (PInt64), combining consecutive 32-bit
         integers into a single operation. This reduces loop iterations and
         can improve performance on aligned memory. If Size is odd, the final
         element is assigned separately. Assumes contiguous memory layout
         and proper alignment for 64-bit access.
[==============================================================================}
function TRange.Positionally: TIntegerArray; overload;
var
  i, n: Integer;
  p: PInt64;
begin
  n := Self.Size;
  SetLength(Result, n);
  p := PInt64(@Result[0]);
  i := 0;
  while ((i + 2) <= n) do
  begin
    p^ := (Int64(Cardinal(i)) or (Int64(Cardinal(i + 1)) shl 32));
    Inc(p);
    Inc(i, 2);
  end;
  if ((n and 1) = 1) then
    Result[n - 1] := (n - 1);
end;

{==============================================================================]
  <Positions>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Positions: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := 0;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + 1);
end;

{==============================================================================]
  <Serialization>
  @action: Generates a zero-based sequential index array using block-doubling.
  @note: Produces the sequence [0, 1, 2, ..., Size-1] by iteratively copying
         and offsetting previously built segments. The algorithm doubles the
         initialized portion on each iteration (h := h * 2) via System.Move,
         then applies an offset to form the next contiguous block. Any remaining
         tail (when Size is not a power of two) is handled separately. This
         approach minimizes per-element initialization overhead compared to
         naive iteration, leveraging bulk memory operations.
[==============================================================================}
function TRange.Serialization: TIntegerArray; overload;
var
  i, l, h, r, s: Integer;
begin
  l := Self.Size;
  if (l = 1) then
    Exit([0]);
  SetLength(Result, l);
  s := SizeOf(Integer);
  Result[0] := 0;
  h := 1;
  while ((h * 2) <= l) do
  begin
    System.Move(Result[0], Result[h], (h * s));
    for i := h to ((h * 2) - 1) do
      Result[i] := (Result[i] + h);
    h := (h * 2);
  end;
  r := (l - h);
  if (r > 0) then
  begin
    System.Move(Result[0], Result[h], (r * s));
    for i := h to (l - 1) do
      Result[i] := (Result[i] + h);
  end;
end;

{==============================================================================]
  <Slots>
  @action: Generates a zero-based index sequence matching the range size.
  @note: Returns an array of length Size containing cumulative increments,
         producing the sequence [0, 1, 2, ..., Size-1]. Internally initializes
         all elements to 1 (except the first set to 0) and performs a prefix
         sum. Special-cases Size = 1 to return [0]. Assumes Size >= 1.
[==============================================================================}
function TRange.Slots: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([0]);
  SetLength(Result, s);
  FillDWord(Result[0], s, 1);
  Result[0] := 0;
  for i := 1 to (s - 1) do
    Result[i] := (Result[i - 1] + Result[i]);
end;

{==============================================================================]
  <Slotted>
  @action: Generates a zero-based index array corresponding to the range size.
  @note: Returns the sequence [0, 1, 2, ..., Size-1] by initializing the array
         to zero and incrementing each element by its index. Functionally
         equivalent to GetIndices/Slots, but implemented via direct indexing
         rather than prefix accumulation. Assumes Size >= 0.
[==============================================================================}
function TRange.Slotted: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  FillDWord(Result[0], s, 0);
  for i := 0 to (s - 1) do
    Inc(Result[i], i);
end;

{==============================================================================]
  <ToIDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.ToIDs: TIntegerArray; overload;
var
  s, b, o, i: Integer;
  P: PInteger;
begin
  s := Self.Size;
  b := System.Length(BASE_DIGITS);
  SetLength(Result, s);
  o := 0;
  while (o < s) do
  begin
    i := (s - o);
    if (i > b) then
	  i := b;
    Move(BASE_DIGITS[0], Result[o], (i * SizeOf(Integer)));
    P := @Result[o];
    for i := 1 to i do
    begin
      P^ := (P^ + o);
      Inc(P);
    end;
    Inc(o, b);
  end;
end;

{==============================================================================]
  <ToIndexes>
  @action: Produces an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Implemented using direct pointer iteration for efficiency.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.ToIndexes: TIntegerArray; overload;
var
  i: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^ := i;
    Inc(p);
  end;
end;

{==============================================================================]
  <ToIndices>
  @action: Produces a zero-based index array for the range using block expansion.
  @note: Generates the sequence [0, 1, 2, ..., Size-1] by first initializing
         a small prefix (up to BLOCK_SIZE), then repeatedly copying that block
         and applying an offset. This reduces loop overhead versus naive
         per-element assignment and improves cache locality. Handles arbitrary
         sizes by processing remaining elements in the final partial block.
         Assumes Size >= 1.
[==============================================================================}
function TRange.ToIndices: TIntegerArray; overload;
const
  BLOCK_SIZE = 256;
var
  i, s, o, c, z: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([0]);
  SetLength(Result, s);
  c := Min(s, BLOCK_SIZE);
  for i := 0 to (c - 1) do
    Result[i] := i;
  o := BLOCK_SIZE;
  z := SizeOf(Integer);
  while (o < s) do
  begin
    c := Min(BLOCK_SIZE, (s - o));
    Move(Result[0], Result[o], (c * z));
    for i := o to ((o + c) - 1) do
      Result[i] := (Result[i] + o);
    Inc(o, BLOCK_SIZE);
  end;
end;
{$ENDIF}
