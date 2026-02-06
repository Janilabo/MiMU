{$IFDEF HELPERS}
function Binned(const target: TRange): TRangeArray; overload;
function Chunked(const chunkSize: Integer = 2): TRangeArray; overload;
function Chunkify(const chunkSize: Integer = 2): TRangeArray; overload;
function Distribute(const parts: Integer= 2): TRangeArray; overload;
function Divide(const size: Integer = 2): TRangeArray; overload;
function Partition(const size: Integer = 2): TRangeArray; overload;
function Sectioned(const target: TRange): TRangeArray; overload;
function Sliced(const partCount: Integer = 2): TRangeArray; overload;
function Subdivide(const partCount: Integer = 2): TRangeArray; overload;
function Subdivided(const partCount: Integer = 2): TRangeArray; cdecl;
function Windows(const target: TRange): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Binned>
  @action: Generate grid-aligned subranges (bins) of the same size as Self
           inside the target range.
  @note:   Subranges are aligned in steps of SelfSize from the start of target.
           Any remainder that does not fit evenly is ignored.
[==============================================================================}
function TRangeHelper.Binned(const target: TRange): TRangeArray; overload;
var
  i, s: Integer;
  t: TRange;
begin
  t := target.Normalize;
  s := Self.Size;
  if (s > t.Size) then
    Exit([]);
  SetLength(Result, (t.Size div s));
  for i := 0 to High(Result) do
  begin
    Result[i].start := (t.start + (s * i));
    Result[i].stop := (Result[i].start + (s - 1));
  end;
end;

{==============================================================================]
  <Chunked>
  @action: Splits the range into an array of contiguous sub-ranges (chunks), each
           containing at most chunkSize elements, preserving the original range
           direction (ascending or descending).
  @note: The last chunk may be smaller than chunkSize. The stop value of the final
         chunk is always aligned with Self.stop. No validation is performed on
         chunkSize; values <= 0 will produce undefined results.
[==============================================================================}
function TRangeHelper.Chunked(const chunkSize: Integer = 2): TRangeArray; overload;
var
  h, i, d: Integer;
begin
  SetLength(Result, ((Self.Size + (chunkSize - 1)) div chunkSize));
  h := High(Result);
  d := IfThen(Self.Descending, -1, 1);
  for i := 0 to h do
  begin
    Result[i].start := (Self.start + (i * chunkSize * d));
    if (i = h) then
      Result[i].stop := Self.stop
    else
      Result[i].stop := (Result[i].start + ((chunkSize - 1) * d));
  end;
end;

{==============================================================================]
  <Chunkify>
  @action: Splits the range into an array of contiguous sub-ranges (chunks), each
           containing at most chunkSize elements, preserving the original range
          direction (ascending or descending).
  @note:
    - Returns an empty array if chunkSize < 1.
    - The last chunk may contain fewer than chunkSize elements.
    - The stop value of the final chunk is always aligned with Self.stop.
[==============================================================================}
function TRangeHelper.Chunkify(const chunkSize: Integer = 2): TRangeArray; overload;
var
  h, c, i, p, d: Integer;
begin
  if (chunkSize < 1) then
    Exit([]);
  c := ((Self.Size + (chunkSize - 1)) div chunkSize);
  SetLength(Result, c);
  h := (c - 1);
  d := IfThen(Self.Descending, -1, 1);
  p := Self.start;
  for i := 0 to h do
  begin
    Result[i].start := p;
    if (i = h) then
      Result[i].stop := Self.stop
    else
      Result[i].stop := (p + (d * (chunkSize - 1)));
    p := (Result[i].stop + d);
  end;
end;

{==============================================================================]
  <Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Distribute(const parts: Integer = 2): TRangeArray; overload;
var
  i, s, e, a, b, p: Integer;
  r: TRange;
begin
  if (parts > 0) then
  begin
    r := Self.Normalize;
    s := r.Size;
    p := Min(s, parts);
    e := (s mod p);
    a := r.start;
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      b := (a + ((s div p) - 1));
      if (i < e) then
        Inc(b);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Divide>
  @action: Partitions range to TRangeArray by size of parts
  @note: Alternative for TRange_Partition.
[==============================================================================}
function TRangeHelper.Divide(const size: Integer = 2): TRangeArray; overload;
var
  a, b, i: Integer;
  r: TRange;
begin
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, (((r.Size + size) - 1) div size));
    a := r.start;
    for i := 0 to High(Result) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Partition>
  @action: Partitions range to TRangeArray by size of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Partition(const size: Integer = 2): TRangeArray; overload;
var
  a, b, l: Integer;
  r: TRange;
begin
  l := 0;
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, r.Size);
    a := r.start;
    while (a <= r.stop) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[l.Increase].Create(b, a)
      else
        Result[l.Increase].Create(a, b);
      a := (b + 1);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Sectioned>
  @action: Divide the target range into sequential, non-overlapping subranges
           of the same size as Self.
  @note:   Any remainder at the end of the target range is discarded.
[==============================================================================}
function TRangeHelper.Sectioned(const target: TRange): TRangeArray; overload;
var
  p, r, s, m: Integer;
  f, t: TRange;
begin
  s := Self.Size;
  t := target.Normalize;
  if (s > t.Size) then
    Exit([]);
  f := Self.Frame;
  m := ((t.stop - s) + 1);
  SetLength(Result, (t.Size div s));
  r := 0;
  p := (t.start - s);
  while (p.Increment(s) <= m) do
    Result[r.Increase].Create((f.start + p), (f.stop + p));
end;

{==============================================================================]
  <Sliced>
  @action: Divides the current range into up to partCount contiguous slices of
           proportional size using index-based partitioning. The entire range is
           covered without overlap, and the original direction (ascending or
           descending) is preserved. If partCount exceeds the number of elements,
           it is limited to Self.Count.
  @note:
    Slice boundaries are computed using integer division of
    (Count * index) div sliceCount. This produces evenly distributed
    partitions with sizes differing by at most one element.
    Returns an empty array if partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Sliced(const partCount: Integer = 2): TRangeArray; overload;
var
  i, l, d, c: Integer;
  function StartSlice(const idx: Integer): Integer;
  begin
    Result := (Self.start + ((c * idx) div l) * d);
  end;
begin
  if (partCount < 1) then
    Exit([]);
  c := Self.Count;
  l := Min(partCount, c);
  SetLength(Result, l);
  if (l = 1) then
    Exit([Self]);
  d := Self.Wind;
  for i := 0 to (l - 1) do
    Result[i].Create(StartSlice(i), (StartSlice(i + 1) - d));
end;

{==============================================================================]
  <Subdivide>
  @action: Divides the range into at most partCount contiguous subranges
           and returns them as an array (partCount is the maximum number of partitions to produce)
  @return: Array of contiguous subranges covering the original range.
  @note:   - If partCount < 1, returns an empty array.
           - The actual number of partitions is Min(partCount, Count).
           - Partitions are distributed as evenly as possible.
             Any remainder elements are allocated one-per-partition
             starting from the first partition.
           - Preserves the original range direction (ascending/descending).
           - The union of all returned subranges equals the original range.
[==============================================================================}
function TRangeHelper.Subdivide(const partCount: Integer = 2): TRangeArray; overload;
var
  c, d, i, l, p, r, s, z: Integer;
begin
  if (partCount < 1) then
    Exit([]);
  c := Self.Count;
  l := Min(partCount, c);
  SetLength(Result, l);
  if (l = 1) then
  begin
    Result[0] := Self;
    Exit;
  end;
  s := (c div l);
  r := (c mod l);
  d := Self.Wind;
  z := Self.Start;
  for i := 0 to (l - 2) do
  begin
    p := IfThen((i < r), s, (s - 1));
    Result[I].Create(z, (z + (p * d)));
    z := (z + ((p + 1) * d));
  end;
  Result[l - 1].Create(z, Self.Stop);
end;

{==============================================================================]
  <Subdivided>
  @action: Splits the current range into up to partCount contiguous subranges of
           nearly equal size. The resulting subranges collectively cover the entire
           original range without overlap and preserve its direction (ascending or
           descending). If partCount exceeds the number of elements, it is limited
           to Self.Count. Any remainder elements are distributed one per subrange
           starting from the first.
  @note:
    A TRangeArray containing Min(partCount, Self.Count) subranges.
    Returns an empty array if partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Subdivided(const partCount: Integer = 2): TRangeArray; cdecl;
var
  i, c, l, s, r, d, p, z: Integer;
begin
  if (partCount < 1) then
    Exit([]);
  c := Self.Count;
  l := Min(partCount, c);
  SetLength(Result, l);
  if (l = 1) then
    Exit([Self]);
  s := (c div l);
  r := (c mod l);
  d := Self.Wind;
  p := Self.start;
  for i := 0 to (l - 1) do
  begin
    z := (s + Ord(i < r) - 1);
    if (i < (l - 1)) then
    begin
      Result[i].Create(p, (p + (z * d)));
      p := (p + (z + 1) * d);
    end else
      Result[i].Create(p, Self.stop);
  end;
end;

{==============================================================================]
  <Windows>
  @action: Generate all possible subranges (sliding windows) of Self inside
           the target range. These windows may overlap.
  @note:   The number of results is (TargetSize - SelfSize + 1).
[==============================================================================}
function TRangeHelper.Windows(const target: TRange): TRangeArray; overload;
var
  r, s: Integer;
  f, t: TRange;
begin
  s := Self.Size;
  if (target.Size < s) then
    Exit([]);
  t.Create(Min(target.start, target.stop), ((Max(target.start, target.stop) - s) + 1));
  SetLength(Result, t.Size);
  r := 0;
  f := Self.Frame;
  for s := t.start to t.stop do
    Result[r.Increase].Create((f.start + s), (f.stop + s));
end;
{$ENDIF}
