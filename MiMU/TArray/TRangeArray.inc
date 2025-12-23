{$DEFINE TRange}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
TRangeArrayHelper = type helper for TRangeArray
  {$I ./Core.inc}
  function Bounds: TRange; overload;
  function Range: TRange; overload;
  function TIA: TIntegerArray;
  function T2DIA: T2DIntegerArray;
  function Starting: TIntegerArray; overload;
  function Stopping: TIntegerArray; overload;
  function Normalized: TRangeArray; overload;
  function Gaps: TRangeArray; overload;
  function Starts: TIntegerArray; overload;
  function Stops: TIntegerArray; overload;
  function StartValues: TIntegerArray; overload;
  function StopValues: TIntegerArray; overload;
  function Unzip(var startArr, stopArr: TIntegerArray): Integer;
  function Zip(const startArr, stopArr: TIntegerArray): Integer;
  function SortBySize(const oAscending: Boolean = True): Integer;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$IFNDEF CLASSES}
{$DEFINE FField := start}{$I ./Configuration/F.inc}
{$DEFINE FField := stop}{$I ./Configuration/F.inc}
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bounds: TRange>
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
  <Range: TRange>
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
  <TIA>
  @action: Returns TRanges from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.TIA: TIntegerArray;
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

{==============================================================================]
  <T2DIA>
  @action: Returns TRanges from arr as T2DIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.T2DIA: T2DIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
   for i := 0 to High(Self) do
    Result[i] := Self[i].TIA;
end;

{==============================================================================]
  <Starting>
  @action: Returns start values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Starting: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
  <Stopping>
  @action: Returns stop values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Stopping: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

function TRangeArrayHelper.Normalized: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i].Create(Min(Self[i].start, Self[i].stop), Max(Self[i].start, Self[i].stop));
end;

function TRangeArrayHelper.Gaps: TRangeArray; overload;
var
  i, g: Integer;
  n: TRangeArray;
  a, b: Integer;
  procedure SortNormRanges(var r: TRangeArray);
  var
    a, b: Integer;
  begin
    for a := 0 to (High(r) - 1) do
      for b := (a + 1) to High(r) do
        if (r[a].start > r[b].start) then
	  Swap(r[a], r[b])
  end;
begin
  g := 0;
  if (Self.Size > 1) then
  begin
    SetLength(n, Self.Size);
    n := Self.Normalized;
    SortNormRanges(n);
    SetLength(Result, (Self.Size - 1));
    for i := 0 to (High(n) - 1) do
    begin
      a := (n[i].stop + 1);
      b := (n[i + 1].start - 1);
      if (a <= b) then
        Result[g.Increase].Create(a, b);
    end;
  end;
  SetLength(Result, g);
end;

{==============================================================================]
  <Starts>
  @action: Returns start-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Starts: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
  <Stops>
  @action: Returns stop-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Stops: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

{==============================================================================]
  <StartValues>
  @action: Returns start-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.StartValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].start;
end;

{==============================================================================]
  <StopValues>
  @action: Returns stop-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.StopValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].stop;
end;

{==============================================================================]
  <Unzip>
  @action: Stores arr start and stop values to startArr and stopArr.
  @note: Returns Length(arr).
[==============================================================================}
function TRangeArrayHelper.Unzip(var startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Self.Length;
  SetLength(startArr, Result);
  SetLength(stopArr, Result);
  for i := 0 to (Result - 1) do
  begin
    startArr[i] := Self[i].start;
    stopArr[i] := Self[i].stop;
  end;
end;

{==============================================================================]
  <Zip>
  @action: Zips TPointArray with startArr and stopArr.
  @note: Uses minimum length(!), if startArr differs from stopArr size.
[==============================================================================}
function TRangeArrayHelper.Zip(const startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Min(startArr.Size, stopArr.Size);
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
  begin
    Self[i].start := startArr[i];
    Self[i].stop := stopArr[i];
  end;
end;

{==============================================================================]
  <SortBySize>
  @action: Sorts the TRangeArray in-place by the size of its elements.
           The sorting order is determined by the oAscending parameter:
             - True: ascending (smallest to largest)
             - False: descending (largest to smallest)
  @note: Returns the number of elements in the array.
         If the array has fewer than 2 elements, no sorting is performed.
[==============================================================================}
function TRangeArrayHelper.SortBySize(const oAscending: Boolean = True): Integer;
begin
  Result := Self.Length;
  if (Result > 1) then
  case oAscending of
    True: specialize QuickSort<TRange>(Self, @TRange.CompareSizeAscending);
    False: specialize QuickSort<TRange>(Self, @TRange.CompareSizeDescending);
  end;
end;
{$ENDIF}

{$UNDEF TRange}
