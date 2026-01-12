{$IFDEF HELPERS}
function Binned(const target: TRange): TRangeArray; overload;
function Distribute(const parts: Integer): TRangeArray;
function Divide(const size: Integer): TRangeArray;
function Partition(const size: Integer): TRangeArray;
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
  <Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Distribute(const parts: Integer): TRangeArray;
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
function TRangeHelper.Divide(const size: Integer): TRangeArray;
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
function TRangeHelper.Partition(const size: Integer): TRangeArray;
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