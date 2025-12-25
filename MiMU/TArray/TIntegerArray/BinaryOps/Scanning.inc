{$IFDEF HELPERS}
function BinaryScan(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanned(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryScan>
  @action: Performs a binary range scan on a sorted integer array to locate
           all indexes whose values lie within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses two binary searches to determine the first and last matching
           indexes that fall inside the range boundaries.
         - Returns an index list (TIntegerArray) identifying all matching
           elements.
         - Efficient O(log n + k) performance, where k is the number of
           matching elements.
[==============================================================================}
function TIntegerArrayHelper.BinaryScan(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  M, i: Integer;
  a, r, o: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  o.Create(0, High(Self));
  r.Create(-1);
  if (o.stop > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[o.stop]) or (a.start < Self[o.start])) then
    begin
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] >= a.start) then
        begin
          r.start := M;
          o.stop := (M - 1);
        end else
          o.start := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      o.start := r.start;
      o.stop := High(Self);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] <= a.stop) then
        begin
          r.stop := M;
          o.start := (M + 1);
        end else
          o.stop := (M - 1);
      end;
    end;
    False:
    if not ((a.stop > Self[o.start]) or (a.start < Self[o.stop])) then
    begin
      r.Create(-1);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] <= a.stop) then
        begin
          r.start := M;
          o.stop := (M - 1);
        end else
          o.start := (M + 1);
      end;
      if (r.start = -1) then
        Exit;
      o.start := r.start;
      o.stop := High(Self);
      while (o.start <= o.stop) do
      begin
        M := o.Pivot;
        if (Self[M] >= a.start) then
        begin
          r.stop := M;
          o.start := (M + 1);
        end else
          o.stop := (M - 1);
      end;
    end;
  end;
  if not r.Employs(-1) then
  for i := r.start to r.stop do
    Result.Supply(i);
end;

{==============================================================================]
  <BinaryScanned>
  @action: Performs a binary range scan on a sorted integer array to locate
           all values lying within the specified TRange.
  @note: - The array must be sorted in either ascending or descending order,
           as indicated by the aAscending flag (default = True).
         - Uses a single binary search to locate any element inside the range,
           then expands linearly in both directions to include all adjacent
           elements that also satisfy the range condition.
         - Returns a TIntegerArray containing the actual matching values
           (not indexes).
         - Offers O(log n + k) complexity and is well-suited for contiguous
           numeric segments.
[==============================================================================}
function TIntegerArrayHelper.BinaryScanned(const area: TRange; const aAscending: Boolean = True): TIntegerArray;
var
  M, S: Integer;
  a, r, o: TRange;
begin
  a := area.Normalize;
  SetLength(Result, 0);
  o.Create(0, High(Self));
  S := o.stop;
  r.Create(-1);
  if (o.stop > -1) then
  case aAscending of
    True:
    if not ((a.stop > Self[o.stop]) or (a.start < Self[o.start])) then
    while (o.start <= o.stop) do
    begin
      M := o.Pivot;
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] >= a.start)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] <= a.stop)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] > a.stop) then
          o.stop := (M - 1)
        else
          o.start := (M + 1);
      end;
    end;
    False:
    if not ((a.stop > Self[o.start]) or (a.start < Self[o.stop])) then
    while (o.start <= o.stop) do
    begin
      M := o.Pivot;
      case a.Contains(Self[M]) of
        True:
        begin
          r.Create(M);
          while ((r.start > 0) and (Self[r.start - 1] <= a.stop)) do
            Dec(r.start);
          while ((r.stop < S) and (Self[r.stop + 1] >= a.start)) do
            Inc(r.stop);
          Exit(r.ToArray);
        end;
        False:
        if (Self[M] < a.start) then
          o.stop := (M - 1)
        else
          o.start := (M + 1);
      end;
    end;
  end;
end;
{$ENDIF}
