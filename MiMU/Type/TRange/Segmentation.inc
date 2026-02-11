{$IFDEF HELPERS}
function Binned(const target: TRange): TRangeArray; overload;
function Chunked(const chunkSize: Integer = 2): TRangeArray; overload;
function Chunkify(const chunkSize: Integer = 2): TRangeArray; overload;
function Chunks(const partSize: Integer = 2): TRangeArray; overload;
function Distribute(const parts: Integer= 2): TRangeArray; overload;
function Distributed(const partCount: Integer = 2): TRangeArray; overload;
function Divide(const size: Integer = 2): TRangeArray; overload;
function Divided(const partCount: Integer = 2): TRangeArray; overload;
function Halve: TRangeArray; overload;
function Halved: TRangeArray; overload;
function Halves: TRangeArray; overload;
function Parted(const partSize: Integer = 2): TRangeArray; overload;
function Partition(const size: Integer = 2): TRangeArray; overload;
function Partitioned(const partSize: Integer = 2): TRangeArray; overload;
function Partitions(const partSize: Integer = 2): TRangeArray; overload;
function Parts(const partSize: Integer = 2): TRangeArray; overload;
function Sectioned(const target: TRange): TRangeArray; overload;
function Segmented(const partCount: Integer = 2): TRangeArray; overload;
function Separate(const partSize: Integer = 2): TRangeArray; overload;
function Sever(const atValue: Integer): TRangeArray; overload;
function Sever(const atValues: TIntegerArray): TRangeArray; overload;
function Sliced(const partCount: Integer = 2): TRangeArray; overload;
function Slices(const partCount: Integer = 2): TRangeArray; overload;
function Splinter(const partCount: Integer = 2): TRangeArray; overload;
function Subdiv(const partCount: Integer = 2): TRangeArray; overload;
function Subdivide(const partCount: Integer = 2): TRangeArray; overload;
function Subdivided(const partCount: Integer = 2): TRangeArray; overload;
function Subdivision(const partCount: Integer = 2): TRangeArray; overload;
function ToParts(const partSize: Integer = 2): TRangeArray; overload;
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
  <Chunks>
  @action: Splits the current range into contiguous subranges of at most
           partSize elements, preserving the range direction (Wind).
  @note: Returns an empty array if partSize < 1. If partSize >= Size,
         the result contains a single element equal to Self.
         The last chunk always terminates exactly at Self.stop.
[==============================================================================}
function TRangeHelper.Chunks(const partSize: Integer = 2): TRangeArray; overload;
var
  i, s, h, d, p: Integer;
  function MakeChunk(const starting: Integer; const isLast: Boolean): TRange;
  begin
    if isLast then
      Result.Create(starting, Self.stop)
    else
      Result.Create(starting, (starting + ((partSize - 1) * d)));
  end;
begin
  if (partSize < 1) then
    Exit([]);
  s := Self.Size;
  if (partSize >= s) then
    Exit([Self]);
  SetLength(Result, (((s + partSize) - 1) div partSize));
  h := High(Result);
  d := Self.Wind;
  p := Self.start;
  for i := 0 to h do
  begin
    Result[i] := MakeChunk(p, (i = h));
    p := (p + (partSize * d));
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
  <Distributed>
  @action: Splits the range into `partCount` contiguous subranges with
           near-equal cardinality, distributing any remainder elements
           across the first partitions.
  @note:
    - If `partCount` exceeds the range count, it is reduced to `Count`.
    - Subranges preserve the original range direction (`Wind`).
    - Partition sizes differ by at most one element.
    - Remainder elements (`Count mod partCount`) are assigned
      one-by-one to the leading partitions.
    - Returns an empty array if `partCount < 1`.
[==============================================================================}
function TRangeHelper.Distributed(const partCount: Integer = 2): TRangeArray; overload;
var
  i, l, c, s, r, d: Integer;
  o: TIntegerArray;
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
  SetLength(o, (l + 1));
  o[0] := 0;
  for i := 1 to l do
    o[i] := (o[i-1] + (s + Ord(i <= r)));
  for i := 0 to (l - 1) do
    Result[i].Create((Self.Start + (o[i] * d)), (Self.Start + ((o[i + 1] - 1) * d)));
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
  <Divided>
  @action: Splits the range into `partCount` contiguous subranges using
           proportional index division across the total element count.

  @note:
    - Partition boundaries are computed via scaled integer division
      (`(Count * index) div partCount`).
    - Subranges preserve the original range direction (`Wind`).
    - Produces contiguous, non-overlapping partitions covering
      the full range.
    - Partition sizes are near-equal and may differ by at most one.
    - If `partCount` exceeds the range count, it is reduced to `Count`.
    - Returns an empty array if `partCount < 1`.
[==============================================================================}
function TRangeHelper.Divided(const partCount: Integer = 2): TRangeArray; overload;
var
  i, l, c, d: Integer;
  function PartStarts(const idx: Integer): Integer;
  begin
    Result := (Self.Start + (((c * idx) div l) * d));
  end;
  function PartStops(const idx: Integer): Integer;
  begin
    Result := (Self.Start + (((c * (idx + 1)) div l - 1) * d));
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
    Result[i].Create(PartStarts(i), PartStops(i));
end;

{==============================================================================]
  <Halve>
  @action: Splits the range into two contiguous subranges at the midpoint.
  @returns: Array of two ranges representing the first and second half.
  @note:
    - The split index is calculated as (Size div 2).
    - For odd counts, the extra element is placed in the second half.
    - Preserves range direction (ascending/descending) via Wind.
    - For single-element ranges (Size = 1), returns a single range
      constructed from Start to Stop (no second empty range).
    - The first range spans from Start to (Midpoint - Wind).
    - The second range spans from Midpoint to Stop.
[==============================================================================}
function TRangeHelper.Halve: TRangeArray; overload;
var
  s, m, h, d: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([TRange.Construct(Self.start, Self.stop)]);
  SetLength(Result, 2);
  d := Self.Wind;
  h := (s div 2);
  m := (Self.start + (h * d));
  Result[0].Create(Self.start, (m - d));
  Result[1].Create(m, Self.stop);
end;

{==============================================================================]
  <Halved>
  @action: Splits the range into two contiguous subranges using the arithmetic
           midpoint between Start and Stop.
  @returns: Array of two ranges representing the lower and upper halves.
  @note:
    - The midpoint is calculated as:
        m := Start + ((Stop - Start) div 2)
      (integer division).
    - The first range spans from Start to m.
    - The second range spans from (m + Wind) to Stop.
    - Preserves range direction (ascending/descending) via Wind.
    - For Size = 1, returns two identical single-element ranges.
    - For Size = 2, returns two single-element ranges:
        [Start..Start] and [Stop..Stop].
    - For larger ranges, elements are partitioned contiguously
      with no overlap and no gaps.
[==============================================================================}
function TRangeHelper.Halved: TRangeArray; overload;
var
  m: Integer;
begin
  case Self.Size of
    1: Exit([TRange.Construct(Self.start, Self.stop), TRange.Construct(Self.start, Self.stop)]);
    2: Exit([TRange.Construct(Self.start, Self.start), TRange.Construct(Self.stop, Self.stop)]);
  end;
  SetLength(Result, 2);
  m := (Self.start + ((Self.stop - Self.start) div 2));
  Result[0].Create(Self.start, m);
  Result[1].Create((m + Self.Wind), Self.stop);
end;

{==============================================================================]
  <Halves>
  @action: Splits the range into two contiguous subranges at the arithmetic
           midpoint between Start and Stop.
  @returns: Array containing either one or two ranges.
  @note:
    - If the range is singular (Single element), returns a single
      range identical to Self.
    - Otherwise returns two ranges.
    - The midpoint is calculated as:
        m := Start + ((Stop - Start) div 2)
      (integer division).
    - The first range spans from Start to m.
    - The second range spans from (m + Wind) to Stop.
    - Preserves range direction (ascending/descending) via Wind.
    - The resulting ranges are contiguous, with no overlap and no gaps.
    - For odd-length ranges, the midpoint element belongs to
      the first range.
[==============================================================================}
function TRangeHelper.Halves: TRangeArray; overload;
var
  m: Integer;
begin
  if Self.Singular then
    Exit([TRange.Construct(Self.start, Self.stop)]);
  SetLength(Result, 2);
  m := (Self.start + ((Self.stop - Self.start) div 2));
  Result[0].Create(Self.start, m);
  Result[1].Create((m + Self.Wind), Self.stop);
end; 

{==============================================================================]
  <Parted>
  @action: Partitions the range into contiguous directional subranges
           of at most partSize elements.
  @note: Returns an empty array if partSize < 1. If partSize >= Size,
         the result contains a single element equal to Self.
         The final part may contain fewer than partSize elements.
         Range direction (Wind) is preserved.
[==============================================================================}
function TRangeHelper.Parted(const partSize: Integer = 2): TRangeArray; overload;
var
  s, d, p, n, c: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  s := Self.Size;
  if (partSize >= s) then
    Exit([Self]);
  SetLength(Result, ((s + (partSize - 1)) div partSize));
  d := Self.Wind;
  p := Self.start;
  c := 0;
  repeat
    n := (p + ((partSize - 1) * d));
    if (((d > 0) and (n > Self.stop)) or ((d < 0) and (n < Self.stop))) then
      n := Self.stop;
    Result[c.Increase].Create(p, n);
    p := (n + d);
  until (p = (Self.stop + d));
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
  <Partitioned>
  @action: Divides the range into chunks of a fixed size.
  @param partSize: The size of each partition (number of elements per chunk)
  @returns: Array of ranges, each containing partSize elements (last may be smaller)
  @note: - If partSize < 1, returns empty array.
         - Last partition may contain fewer elements than partSize.
         - Preserves range direction (ascending/descending).
         - Returns single-element partitions if partSize = 1.
[==============================================================================}
function TRangeHelper.Partitioned(const partSize: Integer = 2): TRangeArray; overload;
var
  i, c, d, p: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  c := (((Self.Count + partSize) - 1) div partSize);
  SetLength(Result, c);
  d := Self.Wind;
  p := Self.start;
  for i := 0 to (c - 2) do
  begin
    Result[i].Create(p, (p + (partSize - 1) * d));
    p := (p + (partSize * d));
  end;
  Result[c - 1].Create(p, Self.stop);
end;

{==============================================================================]
  <Partitions>
  @action: Splits the current range into consecutive subranges of a specified size.
  @note: Returns an empty array if partSize < 1. 
         Returns the original range as a single segment if partSize >= Count.
         The final segment may contain fewer elements if Count is not
         evenly divisible by partSize. The original Wind (direction)
         is preserved.
[==============================================================================}
function TRangeHelper.Partitions(const partSize: Integer = 2): TRangeArray; overload;
var
  i, c, l, d, p, s: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  c := Self.Count;
  if (partSize >= c) then
    Exit([Self]);
  SetLength(Result, (((c + partSize) - 1) div partSize));
  d := Self.Wind;
  p := Self.start;
  l := c;
  for i := 0 to High(Result) do
  begin
    s := Min(partSize, l);
    Result[i].Create(p, (p + ((s - 1) * d)));
    p := (p + (s * d));
    Dec(l, s);
  end;
end;

{==============================================================================]
  <Parts>
  @action: Partitions the range into directional subranges containing
           up to partSize elements each.
  @note: The final subrange may contain fewer than partSize elements.
         Range direction is preserved. Invalid partSize (< 1)
         yields an empty result.
[==============================================================================}
function TRangeHelper.Parts(const partSize: Integer = 2): TRangeArray; overload;
var
  c, d, p: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  c := Self.Count;
  if (partSize >= c) then
    Exit([Self]);
  SetLength(Result, 0);
  d := Self.Wind;
  p := Self.start;
  while (((d > 0) and (p <= Self.stop)) or ((d < 0) and (p >= Self.stop))) do
  begin
    SetLength(Result, (Result.Length + 1));
    if not (((d > 0) and (p + ((partSize - 1) * d) > Self.stop)) or ((d < 0) and (p + ((partSize - 1) * d) < Self.stop))) then
    begin
      Result[High(Result)].Create(p, (p + ((partSize - 1) * d)));
      p := p + partSize * d;
    end else
      Result[High(Result)].Create(p, Self.stop);
    if (Result[High(Result)].stop = Self.stop) then
      Break;
    p := (Result[High(Result)].stop + d);
  end;
end; 

{==============================================================================]
  <Sectioned>
  @action: Divide the target range into sequential, non-overlapping subranges
           of the same size as Self.
  @note: Any remainder at the end of the target range is discarded.
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
  <Separate>
  @action: Splits the current TRange into an array of contiguous subranges,
           each containing at most partSize elements, preserving the original
           range direction (Wind).
  @note:
    - If partSize < 1, an empty array is returned.
    - If partSize >= Size, the result contains a single element equal to Self.
    - Subranges are created sequentially from Start, following Wind.
    - The final subrange may contain fewer than partSize elements
      if Size is not an exact multiple of partSize.
    - Time complexity: O(n / partSize)
    - Space complexity: O(n / partSize)
[==============================================================================}
function TRangeHelper.Separate(const partSize: Integer = 2): TRangeArray; overload;
label
  loop, done;
var
  s, i, c, d, p, l: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  s := Self.Size;
  if (partSize >= s) then
  begin
    SetLength(Result, 1);
    Result[0] := Self;
    Exit;
  end;
  c := (((s + partSize) - 1) div partSize);
  SetLength(Result, c);
  d := Self.Wind;
  p := Self.start;
  i := 0;
  loop:
  if (i >= c) then
    goto done;
  if (i = (c - 1)) then
    l := (s - (i * partSize) - 1)
  else
    l := (partSize - 1);
  Result[i].Create(p, (p + (l * d)));
  p := (p + ((l + 1) * d));
  Inc(i);
  goto loop;
  done:
end;

{==============================================================================]
  <Sever>
  @action: Splits the range at the specified value, producing up to two
           contiguous subranges.
  @param atValue: The value at which the range is to be severed.
  @returns: Array containing either one or two ranges.
  @note:
    - If atValue equals Start, or if atValue is not contained within
      the range, the original range is returned unchanged (single entry).
    - Otherwise, two ranges are returned.
    - The first range spans from Start to (atValue - Wind).
    - The second range spans from atValue to Stop.
    - Preserves range direction (ascending/descending) via Wind.
    - The resulting ranges are contiguous, with no overlap and no gaps.
    - The split value (atValue) becomes the first element of the
      second range.
[==============================================================================}
function TRangeHelper.Sever(const atValue: Integer): TRangeArray; overload;
begin
  if ((atValue = Self.start) or not Self.Contains(atValue)) then
    Exit([TRange.Construct(Self.start, Self.stop)]);
  SetLength(Result, 2);
  Result[0].Create(Self.start, (atValue - Self.Wind));
  Result[1].Create(atValue, Self.stop);
end;

{==============================================================================]
  <Sever>
  @action: Splits the range at multiple specified values, producing a sequence
           of contiguous subranges.
  @param atValues: Array of candidate split values.
  @returns: Array of one or more ranges resulting from the splits.
  @note:
    - If atValues is empty, the original range is returned unchanged.
    - Only values that exist within the range are considered.
    - Split values are:
        * Extracted to those contained in the range,
        * Deduplicated (Compress),
        * Sorted according to the range direction.
    - Splitting proceeds sequentially from Start toward Stop.
    - For each valid split value v:
        * A range is created from the current cursor to (v - Wind).
        * The cursor is then advanced to v.
    - The final range spans from the last cursor position to Stop.
    - Values equal to the current cursor (including Start) are ignored.
    - Preserves range direction (ascending/descending) via Wind.
    - Resulting ranges are contiguous, non-overlapping, and gap-free.
    - If no valid split values remain after filtering, the original
      range is returned as a single entry.
[==============================================================================}
function TRangeHelper.Sever(const atValues: TIntegerArray): TRangeArray; overload;
var
  i, l, d, c: Integer;
  s: TIntegerArray;
begin
  if atValues.Empty then
    Exit([TRange.Construct(Self.start, Self.stop)]);
  s := atValues.Extract(Self.All);
  if s.Empty then
    Exit([TRange.Construct(Self.start, Self.stop)]);
  s.Compress;
  s.QuickSort(Self.Ascending);
  d := Self.Wind;
  SetLength(Result, (System.Length(s) + 1));
  l := 0;
  c := Self.Start;
  for i := 0 to High(s) do
  begin
    if not (Self.Contains(s[i]) and (s[i] <> c)) then
      Continue;
    Result[l.Increase].Create(c, (s[i] - d));
    c := s[i];
  end;
  Result[l.Increase].Create(c, Self.stop);
  SetLength(Result, l);
end; 

{==============================================================================]
  <Segmented>
  @action: ?
  @note: ?
[==============================================================================}
function TRangeHelper.Segmented(const partCount: Integer = 2): TRangeArray; overload;
var
  c, i, l, d, p: Integer;
  s: TIntegerArray;
  procedure CalculateSizes;
  var
    j: Integer;
  begin
    for j := 0 to (l - 1) do
      s[j] := ((c div l) + Ord(j < (c mod l)));
  end;
begin
  if (partCount < 1) then
    Exit([]);
  c := Self.Count;
  l := Min(partCount, c);
  SetLength(Result, l);
  if (l = 1) then
    Exit([Self]);
  SetLength(s, l);
  CalculateSizes;
  d := Self.Wind;
  p := Self.start;
  for i := 0 to (l - 1) do
  begin
    Result[i].Create(p, (p + ((s[i] - 1) * d)));
    p := (p + (s[i] * d));
  end;
end;

{==============================================================================]
  <Sliced>
  @action: Divides the current range into up to partCount contiguous slices of
           proportional size using index-based partitioning. The entire range is
           covered without overlap, and the original direction (ascending or
           descending) is preserved. If partCount exceeds the number of elements,
           it is limited to Self.Count.
  @note: Slice boundaries are computed using integer division of
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
  <Slices>
  @action: ?
  @note: ?
[==============================================================================}
function TRangeHelper.Slices(const partCount: Integer = 2): TRangeArray; overload;
label
  loop, done;
var
  i, l, c, s, r, d, p, a: Integer;
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
  p := Self.start;
  i := 0;
  loop:
  if (i >= l) then
    goto done;
  if (i < (l - 1)) then
  begin
    a := IfThen((i < r), s, (s - 1));
    Result[i].Create(p, (p + (a * d)));
    p := (p + ((a + 1) * d));
  end else
    Result[i].Create(p, Self.stop);
  Inc(i);
  goto loop;
  done:
end;

{==============================================================================]
  <Splinter>
  @action: Recursively partitions the current range into partCount contiguous
           subranges using a divide-and-conquer strategy. The range is repeatedly
           split into two halves until the requested number of parts is produced.
           The resulting subranges collectively cover the entire original range,
           preserve its direction (ascending or descending), and do not overlap.
  @note: Partitioning is performed by recursively bisecting each intermediate
         range at its midpoint. The number of subdivisions assigned to each half
         is determined by integer division (parts div 2) and the remainder.
         This produces balanced, tree-structured splits rather than strictly
         sequential allocation. If partCount exceeds Self.Count, it is limited
         accordingly. Returns an empty array if partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Splinter(const partCount: Integer = 2): TRangeArray; overload;
  procedure Split(const rng: TRange; const parts: Integer; var idx: Integer);
  var
    m, h: Integer;
  begin
    if (parts > 1) then
    begin
      h := (rng.Count div 2);
      m := (rng.Start + (h * rng.Wind));
      Split(TRange.Construct(rng.start, m), (parts div 2), idx);
      Split(TRange.Construct((m + rng.Wind), rng.stop), (parts - (parts div 2)), idx);
    end else
      Result[idx.Increase] := rng;
  end;
var
  i: Integer;
begin
  if (partCount < 1) then
    Exit([]);
  SetLength(Result, Min(partCount, Self.Count));
  i := 0;
  Split(Self, Result.Length, i);
end;

{==============================================================================]
  <Subdiv>
  @action: Divides the current range into up to partCount contiguous subranges of
           near-equal size. The total element count is first evenly distributed,
           then any remainder elements are assigned one per subrange starting
           from the first. All generated subranges are contiguous, non-overlapping,
           preserve the original direction (ascending or descending), and together
           exactly reconstruct the original range.
  @note: The number of resulting subranges is Min(partCount, Self.Count).
         Subrange sizes differ by at most one element. Size distribution is
         precomputed into a temporary array before constructing the resulting
         ranges. Returns an empty array if partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Subdiv(const partCount: Integer = 2): TRangeArray; overload;
var
  c, i, l, s, r, d, p: Integer;
  z: TIntegerArray;
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
  SetLength(z, l);
  for i := 0 to (l - 1) do
    z[i] := (s + Ord(i < r));
  d := Self.Wind;
  p := Self.start;
  for i := 0 to (l - 1) do
  begin
    Result[i].Create(p, (p + (z[i] - 1) * d));
    p := (p + (z[i] * d));
  end;
end;

{==============================================================================]
  <Subdivide>
  @action: Divides the range into at most partCount contiguous subranges
           and returns them as an array (partCount is the maximum number of partitions to produce)
  @return: Array of contiguous subranges covering the original range.
  @note: - If partCount < 1, returns an empty array.
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
  @note: A TRangeArray containing Min(partCount, Self.Count) subranges.
         Returns an empty array if partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Subdivided(const partCount: Integer = 2): TRangeArray; overload;
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
  <Subdivision>
  @action: Partitions the current range into up to partCount contiguous subranges,
           distributing elements as evenly as possible. Each subdivision is created
           sequentially from the current start position, preserving the original
           direction (ascending or descending). The combined result fully reconstructs
           the original range without gaps or overlap. If partCount exceeds the
           number of elements, it is limited to Self.Count.
  @note: Subrange sizes are computed dynamically based on the number of remaining
         elements and remaining partitions, ensuring that sizes differ by at most
         one element. This approach guarantees balanced distribution even when the
         total element count is not evenly divisible. Returns an empty array if
         partCount < 1 or if the range is empty.
[==============================================================================}
function TRangeHelper.Subdivision(const partCount: Integer = 2): TRangeArray; overload;
var
  c, i, l, r, s, d, p: Integer;
begin
  if (partCount < 1) then
    Exit([]);
  c := Self.Count;
  l := Min(partCount, c);
  SetLength(Result, l);
  if (l = 1) then
    Exit([Self]);
  d := Self.Wind;
  p := Self.Start;
  r := c;
  i := -1;
  while (i.Increment < l) do
  begin
    s := ((r + ((l - i) - 1)) div (l - i));
    Result[i].Create(p, (p + (s - 1) * d));
    p := (p + (s * d));
    Dec(r, s);
  end;
end;

{==============================================================================]
  <ToParts>
  @action: Splits the range into contiguous directional subranges
           of at most partSize elements using index-based computation.
  @note: Returns an empty array if partSize < 1. If partSize >= Size,
         the result contains a single element equal to Self.
         The final part may contain fewer than partSize elements.
         Range direction (Wind) is preserved.
[==============================================================================}
function TRangeHelper.ToParts(const partSize: Integer = 2): TRangeArray; overload;
var
  s, i, c, d: Integer;
begin
  if (partSize < 1) then
    Exit([]);
  s := Self.Size;
  if (partSize >= s) then
    Exit([Self]);
  c := (((s + partSize) - 1) div partSize);
  SetLength(Result, c);
  d := Self.Wind;
  for i := 0 to (c - 1) do
    Result[i].Create((Self.start + ((i * partSize) * d)), (Self.start + ((Min((i + 1) * partSize, s) - 1) * d)));
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
