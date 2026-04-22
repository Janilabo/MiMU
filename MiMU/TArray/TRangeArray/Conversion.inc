{$IFDEF HELPERS}
function Digitize: TIntegerArray; overload;
function Digitized: TIntegerArray; overload;
function Digitted(const sIDs: TRange): TIntegerArray; overload;
function Digitted: TIntegerArray; overload;
function Material(const chunkSize: Integer = 16): TIntegerArray; overload;
function Materialize: TIntegerArray; overload;
function Materialized: TIntegerArray; overload;
function T2DIA: T2DIntegerArray; overload;
function TIA: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Digitize>
  @action: Converts the range structures into a flat sequence of all contained
           integers, preserving the direction (polarity) of each range.
  @note:
    - Pass 1: Accumulates total capacity to prevent reallocations.
    - Pass 2: Uses a reverse-fill sentinel (r.Decrement) to inject values.
    - Result: A "digitized" version of the coordinate data.
[==============================================================================}
function TRangeArrayHelper.Digitize: TIntegerArray; overload;
var
  i, r, s: Integer;
begin
  r := 0;
  for i := 0 to High(Self) do
    Inc(r, Self[i].Size);
  SetLength(Result, r);
  if (r = 0) then
    Exit;
  for i := High(Self) downto 0 do
  case Self[i].Ascending of
    True:
    for s := Self[i].stop downto Self[i].start do
      Result[r.Decrement] := s;
    False:
    for s := Self[i].stop to Self[i].start do
      Result[r.Decrement] := s;
  end;
end;

{==============================================================================]
  <Digitized>
  @action: Expands all ranges into a contiguous TIntegerArray by writing each
           range’s full sequence of integer values into the result buffer.
           Ranges are processed in reverse order, but written into precomputed
           positions so the final array preserves the original order.
  @note: Performs a single allocation using total size precomputation.
         Uses block writes (forward/backward) for efficiency instead of
         per-element appends. Returns an empty array if no ranges exist.
         Despite the name, this does not operate on numeric digits.
[==============================================================================}
function TRangeArrayHelper.Digitized: TIntegerArray; overload;
  procedure A(var arr: TIntegerArray; const index, from, size: Integer);
  var
    i: Integer;
  begin
    for i := 0 to (size - 1) do
      arr[index + i] := (from + i);
  end;
  procedure D(var arr: TIntegerArray; const index, from, size: Integer);
  var
    i: Integer;
  begin
    for i := 0 to (size - 1) do
      arr[index + i] := (from - i);
  end;
var
  i, s: Integer;
begin
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Size);
  SetLength(Result, s);
  for i := High(Self) downto 0 do
    if Self[i].Ascending then
      A(Result, s.Decrement(Self[i].Size), Self[i].start, Self[i].Size)
    else
      D(Result, s.Decrement(Self[i].Size), Self[i].start, Self[i].Size);
end;

{==============================================================================]
  <Digitted>
  @action: Extracts and flattens a specific sub-selection of ranges into a 
           discrete TIntegerArray.
  @param: sIDs - The range of indices in the array to process (e.g., 0..5).
  @note: 
    - Uses Binary Recursion (Bisection) to merge data streams.
    - Safety: Clips requested indices against array bounds via Intersect.
    - Polarity: Automatically reverses the final array if sIDs is descending.
[==============================================================================}
function TRangeArrayHelper.Digitted(const sIDs: TRange): TIntegerArray; overload;
  function Return(const arr: TRangeArray; const aStart, aStop: Integer): TIntegerArray;
  var
    M: Integer;
    L, R: TIntegerArray;
  begin
    if (aStart = aStop) then
      Exit(arr[aStart].Digits);
    M := ((aStart + aStop) div 2);
    L := Return(arr, aStart, M);
    R := Return(arr, (M + 1), aStop);
    Result := (L + R);
  end;
var
  s: TRange;
begin
  if (Self.Empty or (not sIDs.Intersect(TRange.Construct(0, High(Self)), s))) then
    Exit([]);
  Result := Return(Self, s.start, s.stop);
  if sIDs.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Digitted>
  @action: Returns all integers from all ranges in the array.
  @note: Default entry point for full array digitization.
[==============================================================================}
function TRangeArrayHelper.Digitted: TIntegerArray; overload;
begin
  Result := Self.Digitted(TRange.Construct(0, High(Self)));
end;

{==============================================================================]
  <Material>
  @action: Expands all ranges into a contiguous TIntegerArray, producing the
           full sequence of integer values represented by the range set.
           Each range contributes its elements in logical order
           (ascending or descending).
  @note: Precomputes offsets, starting values, and step directions for each
         range, then performs a single allocation for the result buffer.
         Expansion is executed in fixed-size chunks (chunkSize) to reduce
         loop overhead and improve cache locality.
         Direction is encoded as a step (+1 / -1) for branchless iteration.
         Returns an empty array if no ranges are present.
[==============================================================================}
function TRangeArrayHelper.Material(const chunkSize: Integer = 16): TIntegerArray; overload;
var
  o, c, d: TIntegerArray;
  i, j, l, p, r, m: Integer;
begin
  l := Self.Length;
  SetLength(o, (l + 1));
  SetLength(c, l);
  SetLength(d, l);
  o[0] := 0;
  for i := 0 to (l - 1) do
  begin
    o[i + 1] := (o[i] + Self[i].Size);
    c[i] := Self[i].start;
    d[i] := (1 - (2 * Ord(Self[i].Descending)));
  end;
  SetLength(Result, o[High(o)]);
  for i := 0 to (l - 1) do
  begin
    p := o[i];
    r := Self[i].Size;
    while (r > 0) do
    begin
      m := Min(r, chunkSize);
      for j := 0 to (m - 1) do
        Result[p.Increase] := c[i].Increase(d[i]);
      Dec(r, m);
    end;
  end;
end;

{==============================================================================]
  <Materialize>
  @action: Expands all ranges in the array into a contiguous TIntegerArray.
           Each TRange contributes its full sequence of values in order,
           respecting its Ascending/Descending direction.
  @note: Precomputes total output size for a single allocation, ensuring
         O(n) time and no intermediate resizing. Returns an empty array
         if no ranges are present.
[==============================================================================}
function TRangeArrayHelper.Materialize: TIntegerArray; overload;
var
  o: TIntegerArray;
  i, j, p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(o, (l + 1));
  o[0] := 0;
  for i := 0 to (l - 1) do
    o[i + 1] := (o[i] + Self[i].Size);
  SetLength(Result, o[High(o)]);
  for i := 0 to (l - 1) do
  begin
    p := o[i];
    case Self[i].Ascending of
      True:
      for j := Self[i].start to Self[i].stop do
        Result[p.Increase] := j;
      False:
      for j := Self[i].start downto Self[i].stop do
        Result[p.Increase] := j;
    end;
  end;
end;

{==============================================================================]
  <Materialized>
  @action: Expands all ranges into a contiguous TIntegerArray, producing the
           full sequence of integer values represented by the range set.
           Each range contributes its elements in logical order
           (ascending or descending).
  @note: Computes total size up front and performs a single allocation.
         Fills the result buffer in reverse using a decrementing index,
         avoiding intermediate offsets or prefix arrays.
         Direction is encoded as a step (+1 / -1) for branchless iteration.
         Returns an empty array if no ranges are present.
[==============================================================================}
function TRangeArrayHelper.Materialized: TIntegerArray; overload;
var
  i, j, s, o, v: Integer;
begin
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Size);
  SetLength(Result, s);
  for i := High(Self) downto 0 do
  begin
    o := (1 - (2 * Ord(Self[i].Descending)));
    v := Self[i].stop;
    for j := (Self[i].Size - 1) downto 0 do
      Result[s.Decrement] := v.Decrease(o);
  end;
end;

{==============================================================================]
  <T2DIA>
  @action: Returns TRanges from arr as T2DIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.T2DIA: T2DIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
   for i := 0 to High(Self) do
    Result[i] := Self[i].TIA;
end;

{==============================================================================]
  <TIA>
  @action: Returns TRanges from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.TIA: TIntegerArray; overload;
var
  i, j, l: Integer;
  r: TIntegerArray;
begin
  l := 0;
  for i := 0 to High(Self) do
    l := (l + Self[i].Size);
  SetLength(Result, l);
  for i := High(Self) downto 0 do
  begin
    r := Self[i].TIA;
    for j := High(r) downto 0 do
      Result[l.Decrement] := r[j];
  end;
end;
{$ENDIF}
