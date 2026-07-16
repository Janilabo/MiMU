{$IFDEF HELPERS}
function Boundaries: TRange; overload;
function Bounding(const rAscending: Boolean = True): TRange; overload;
function Bounds: TRange; overload;
function BRange: TRange; overload;
function Extent: TRange; overload;
function MaxMin: TRange; overload;
function MinMax: TRange; overload;
function Range: TRange; overload;
function Spannage: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boundaries>
  @action: Returns the single bounding TRange that spans the entire array —
           from the lowest Minimum to the highest Maximum across all ranges.
  @note:
    - Does not merge or normalize; just finds outer bounds.
    - Returns a null range if array is empty.
[==============================================================================}
function TRangeArrayHelper.Boundaries: TRange; overload;
var
  i, m: Integer;
begin
  if Self.Empty then
    Exit(TRange.Null);
  Result.Create(Self[0].Minimum, Self[0].Maximum);
  for i := 1 to High(Self) do
  begin
    m := Self[i].Minimum;
    if (m < Result.start) then
      Result.start := m;
	m := Self[i].Maximum;
    if (m > Result.stop) then
      Result.stop := m;
  end;
end;

{==============================================================================]
  <Bounding>
  @action: Calculates the absolute outer boundaries of the array by sorting 
           all coordinate points.
  @param: rAscending - If True, returns [AbsoluteMin..AbsoluteMax]. 
                       If False, returns [AbsoluteMax..AbsoluteMin].
  @note: Uses Deconstruction and QuickSort. This ensures the result is 
         derived from the true extremes of the entire coordinate pool.
[==============================================================================}
function TRangeArrayHelper.Bounding(const rAscending: Boolean = True): TRange; overload;
var
  s: TIntegerArray;
begin
  case Self.Length of
    0: Exit(TRange.Null);
    1:
    if rAscending then
      Exit(Self[0].Ascend)
    else
      Exit(Self[0].Descend);
  end;
  s := Self.Deconstruct.QuickSorted(rAscending);
  Result.Create(s[0], s[High(s)]);
end;

{==============================================================================]
  <Bounds>
  @action: Returns the bounds of TRange array as TRange.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Bounds: TRange; overload;
var
  i: Integer;
  r: TRange;
begin
  if (Self.Size > 0) then
  begin
    Result := Self[0].Normalize;
    for i := 1 to High(Self) do
    begin
      r := Self[i].Normalize;
      if (r.start < Result.start) then
        Result.start := r.start
      else if (r.stop > Result.stop) then
        Result.stop := r.stop;
    end;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <BRange>
  @action: Returns the absolute bounding TRange (Extent) of the array.
  @note: Uses an unrolled loop with an Integer-Helper-driven condition. 
         Processes two records per iteration for maximum throughput.
[==============================================================================}
function TRangeArrayHelper.BRange: TRange; overload;
var
  P: PRange;
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit(TRange.Null);
    1: Exit(Self[0].Ascend);
  end;
  P := @Self[0];
  Result := TRange.Construct(Min(P^.start, P^.stop), Max(P^.start, P^.stop));
  Inc(P);
  i := -1;
  while (i.Increment(2) <= (l - 2)) do
  begin
    Result.start := Min(Result.start, Min(P^.start, P^.stop));
    Result.stop := Max(Result.stop, Max(P^.start, P^.stop));
    Inc(P);
    Result.start := Min(Result.start, Min(P^.start, P^.stop));
    Result.stop := Max(Result.stop, Max(P^.start, P^.stop));
    Inc(P);
  end;
  if (i < l) then
    Result := TRange.Construct(Min(Result.start, Min(P^.start, P^.stop)), Max(Result.stop,  Max(P^.start, P^.stop)));
end;

{==============================================================================]
  <Extent>
  @action: Returns a single TRange representing the absolute outer boundaries 
           of the entire array.
  @returns: A TRange where .start is the global Minimum and .stop is the 
            global Maximum. Returns TRange.Null if the array is empty.
  @note: Uses a high-performance pointer walk. This is the "Bounding Box" 
         of your coordinate data.
[==============================================================================}
function TRangeArrayHelper.Extent: TRange; overload;
var
  P: PRange;
  i: Integer;
begin
  if Self.Empty then
    Exit(TRange.Null);
  P := @Self[0];
  if (P^.start < P^.stop) then
  begin
    Result.start := P^.start;
    Result.stop := P^.stop;
  end else
  begin
    Result.start := P^.stop;
    Result.stop := P^.start;
  end;
  for i := 1 to High(Self) do
  begin
    Inc(P);
    if (P^.start < Result.start) then
      Result.start := P^.start
    else if (P^.start > Result.stop) then
      Result.stop := P^.start;
    if (P^.stop < Result.start) then
      Result.start := P^.stop
    else if (P^.stop > Result.stop) then
      Result.stop := P^.stop;
  end;
end;

{==============================================================================]
  <MaxMin>
  @action: Returns an inverted bounding range where .start is the absolute 
           Maximum and .stop is the absolute Minimum.
  @note: Useful for descending coordinate systems or mirrored projections.
         Uses branchless sentinel logic for peak performance.
[==============================================================================}
function TRangeArrayHelper.MaxMin: TRange; overload;
begin
  Result := Self.MinMax.Reversed;
end;

{==============================================================================]
  <MinMax>
  @action: Returns a standard bounding range where .start is the absolute 
           Minimum and .stop is the absolute Maximum.
  @note: This is the definitive "Extent" or "Envelope" of the array.
         Guarantees a positive width (start <= stop).
[==============================================================================}
function TRangeArrayHelper.MinMax: TRange; overload;
var
  P: PRange;
  i: Integer;
begin
  if Self.Empty then
    Exit(TRange.Null);
  P := @Self[0];
  if (P^.start < P^.stop) then
  begin
    Result.start := P^.start;
    Result.stop := P^.stop;
  end else
  begin
    Result.start := P^.stop;
    Result.stop := P^.start;
  end;
  for i := 1 to High(Self) do
  begin
    Inc(P);
    Result.start := Min(Result.start, Min(P^.start, P^.stop));
    Result.stop := Max(Result.stop, Max(P^.start, P^.stop));
  end;
end;

{==============================================================================]
  <Range>
  @action: Returns the bounds of TRange array as TRange.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Range: TRange; overload;
var
  i: Integer;
begin
  if (Self.Size > 0) then
  begin
    Result := Self[0].Normalize;
    for i := 1 to High(Self) do
    begin
      Result.start := Min(Min(Self[i].start, Self[i].stop), Result.start);
      Result.stop := Max(Max(Self[i].start, Self[i].stop), Result.stop);
    end;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <Spannage>
  @action: Returns the absolute outer-envelope TRange of the collection.
  @note: Uses binary-reduction to "bridge" all sub-ranges into one span.
[==============================================================================}
function TRangeArrayHelper.Spannage: TRange; overload;
  function Return(const aL, aH: Integer): TRange;
  var
    M: Integer;
    L, R: TRange;
  begin
    if (aL = aH) then
      Exit(Self[aL].Normalize);
    M := ((aL + aH) div 2);
    L := Return(aL, M);
    R := Return((M + 1), aH);
    Result.start := Min(L.start, R.start);
    Result.stop := Max(L.stop, R.stop);
  end;
begin
  if Self.Empty then
    Exit(TRange.Null);
  Result := Return(0, High(Self));
end;
{$ENDIF}
