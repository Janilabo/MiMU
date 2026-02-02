{$IFDEF HELPERS}
function Binned(const target: TRange): TRangeArray; overload;
function Chunked(const chunkSize: Integer = 2): TRangeArray; overload;
function Chunkify(const chunkSize: Integer = 2): TRangeArray; overload;
function Distribute(const parts: Integer): TRangeArray; overload;
function Divide(const size: Integer): TRangeArray; overload;
function Partition(const size: Integer): TRangeArray; overload;
function Sectioned(const target: TRange): TRangeArray; overload;
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
function TRangeHelper.Distribute(const parts: Integer): TRangeArray; overload;
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
function TRangeHelper.Divide(const size: Integer): TRangeArray; overload;
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
function TRangeHelper.Partition(const size: Integer): TRangeArray; overload;
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
