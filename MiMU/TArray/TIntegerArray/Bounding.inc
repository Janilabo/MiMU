{$IFDEF HELPERS}
function Boundaries: TRange;
function BoundingRange: TRange;
function Bounds: TRange; overload;
function Bounds(var aSize: Integer): TRange; overload;
function BRange: TRange; overload;
function Coverage: TRange;
function Extent: TRange;
function GetMinMax(var AMin, AMax: Integer): Boolean; overload;
function GetRange(const rAscending: Boolean = True): TRange; overload;
function MinMax: TRange;
function Range: TRange;
function Region: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Boundaries: TRange;
  function BR(const arr: TIntegerArray; const L, R: Integer): TRange;
  var
    M: Integer;
  begin
    if (L = R) then
      Exit(Result.Create(arr[L], arr[L]));
    M := ((L + R) div 2);
    Result := BR(arr, L, M).Union(BR(arr, (M + 1), R));
  end;
begin
  if Self.Empty then
    Exit(Default(TRange));
  Result := BR(Self, 0, High(Self));
end;

{==============================================================================]
  <BoundingRange>
  @action: Returns bounding range around TIntegerArray arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BoundingRange: TRange;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MinValue(Self), MaxValue(Self));
end;

{==============================================================================]
  <Bounds>
  @action: Stores arr bounds to TRange.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Bounds: TRange; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i]
    else if (Self[i] > Result.stop) then
      Result.stop := Self[i];
end;

function TIntegerArrayHelper.Bounds(var aSize: Integer): TRange; overload;
begin
  case Self.Empty of
    False:
	begin
	  Result := Self.Bounds;
	  aSize := Result.Size;
	end;
    True:
    begin
      Result.Create(-2147483648, -2147483648);
      aSize := 0;
    end;
  end;
end;

{==============================================================================]
  <BRange>
  @action: Computes the minimal and maximal values in a TIntegerArray and
           returns them as a TRange record. start contains the minimum value,
           stop contains the maximum value.
  @note: - If the array is empty, the resulting TRange will be uninitialized.
         - If the array has only one element, start and stop will be equal.
         - Uses pointer-based iteration for efficiency.
[==============================================================================}
function TIntegerArrayHelper.BRange: TRange; overload;
var
  P, M: PInteger;
  L: Integer;
begin
  L := Self.Length;
  if (L > 0) then
  with Result do
  begin
    P := @Self[0];
    start := P^;
    stop := P^;
    if (L = 1) then
      Exit;
    M := @Self[0];
    Inc(M, L);
    repeat
      if (start > P^) then
        start := P^
      else if (stop < P^) then
        stop := P^;
      Inc(P);
    until (P = M);
  end;
end;

{==============================================================================]
  <Coverage>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Coverage: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(Self[0]);
  for i := 1 to High(Self) do
    if (Self[i] < Result.start) then
      Result.start := Self[i];
  for i := 1 to High(Self) do
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
end;

{==============================================================================]
  <Extent>
  @action: Stores arr bounds to TRange.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Extent: TRange;
begin
  Result.Create(Self.MinItem, Self.MaxItem);
end;

{==============================================================================]
  <GetMinMax>
  @action: Computes the inclusive range (minimum and maximum values) of the 
           integer array in a single linear pass.
  @note: 
    - Returns True if the array contains elements; otherwise returns False.
    - Uses Math.Min and Math.Max which can be faster than branching on 
      modern CPUs.
    - Complexity: O(n) time, O(1) space.
    - If the array has one element, AMin and AMax will be equal.
[==============================================================================}
function TIntegerArrayHelper.GetMinMax(var AMin, AMax: Integer): Boolean; overload;
var
  i, v: Integer;
begin
  Result := (Self.Length > 0);
  if not Result then
    Exit;
  AMin := Self[0];
  AMax := Self[0];
  for i := 1 to High(Self) do
  begin
    v := Self[i];
    AMin := Min(AMin, v);
    AMax := Max(AMax, v);
  end;
end;

{==============================================================================]
  <GetRange>
  @action: Scans the array to identify the boundary values, returning them as a
           TRange record.
  @note: 
    - If rAscending is True (default): Start = Min, Stop = Max.
    - If rAscending is False: Start = Max, Stop = Min.
    - Returns an uninitialized TRange if the array is empty.
    - Optimized with a case-switch for single-element arrays to avoid loops.
    - Complexity: O(n) linear scan.
[==============================================================================}
function TIntegerArrayHelper.GetRange(const rAscending: Boolean = True): TRange; overload;
var
  i, l, v: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit;
	1: Exit(TRange.Construct(Self[0], Self[0]));
  end;
  Result.start := Self[0];
  Result.stop := Self[0];
  case rAscending of
    True:
    for i := 1 to (l - 1) do
    begin
      v := Self[i];
      Result.start := Min(Result.start, v);
      Result.stop := Max(Result.stop, v);
	end;
	False:
    for i := 1 to (l - 1) do
    begin
      v := Self[i];
      Result.start := Max(Result.start, v);
      Result.stop := Min(Result.stop, v);
	end;
  end;
end;    

{==============================================================================]
  <MinMax>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.MinMax: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i := 1 to High(Self) do
  begin
    Result.start := Min(Result.start, Self[i]);
    Result.stop := Max(Result.stop, Self[i]);
  end;
end;

{==============================================================================]
  <Range>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Range: TRange;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result := Result.Create(Self[0], Self[0]);
  for i in Self do
    Result.Create(Min(Result.start, i), Max(Result.stop, i));
end;

{==============================================================================]
  <Region>
  @action: Stores arr bounds to TRange.
  @note: Returns -2147483648..-2147483648 with empty array.
[==============================================================================}
function TIntegerArrayHelper.Region: TRange; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648, -2147483648));
  Result.Create(MaxInt, -MaxInt);
  for i := 0 to High(Self) do
  begin
    if (Self[i] < Result.start) then
      Result.start := Self[i];
    if (Self[i] > Result.stop) then
      Result.stop := Self[i];
  end;
end;
{$ENDIF}
