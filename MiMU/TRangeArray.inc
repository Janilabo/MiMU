{$DEFINE TRange}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  HArr = type helper for TArr {$I config\1D.inc}
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
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\1D.inc}

{==============================================================================]
  <TRangeArrayHelper.Bounds: TRange>
  @action: Returns the bounds of TRange array as TRange.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Bounds: TRange; overload;
var
  i: Integer;
  r: TRange;
begin
  if (Length(Self) > 0) then
  begin
    Result := Self[0].Normalize;
    for i := 1 to High(Self) do
    begin
      r := Self[i].Normalize;
	  if (r.start < Result.start) then
	    Result.start := r.start
	  else
	    if (r.stop > Result.stop) then
	      Result.stop := r.stop;
    end;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <TRangeArrayHelper.Range: TRange>
  @action: Returns the bounds of TRange array as TRange.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Range: TRange; overload;
var
  i: Integer;
  r: TRange;
begin
  if (Length(Self) > 0) then
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
  <TRangeArrayHelper.TIA>
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
  <TRangeArrayHelper.T2DIA>
  @action: Returns TRanges from arr as T2DIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.T2DIA: T2DIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
   for i := 0 to High(Self) do
    Result[i] := Self[i].TIA;
end;

{==============================================================================]
  <TRangeArrayHelper.Starting>
  @action: Returns start values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Starting: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
  <TRangeArrayHelper.Stopping>
  @action: Returns stop values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Stopping: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

function TRangeArrayHelper.Normalized: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
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
  if (Length(Self) > 1) then
  begin
    SetLength(n, Length(Self));
    n := Self.Normalized;
    SortNormRanges(n);
    SetLength(Result, (Length(Self) - 1));
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
 <TRangeArrayHelper.Starts>
 @action: Returns start-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TRangeArrayHelper.Starts: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
 <TRangeArrayHelper.Stops>
 @action: Returns stop-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TRangeArrayHelper.Stops: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

{==============================================================================]
 <TRangeArrayHelper.StartValues>
 @action: Returns start-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TRangeArrayHelper.StartValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].start;
end;

{==============================================================================]
 <TRangeArrayHelper.StopValues>
 @action: Returns stop-values from arr as TIntegerArray.
 @note: None.
[==============================================================================}
function TRangeArrayHelper.StopValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].stop;
end;

{==============================================================================]
 <TRangeArrayHelper.Unzip>
 @action: Stores arr start and stop values to startArr and stopArr.
 @note: Returns Length(arr).
[==============================================================================}
function TRangeArrayHelper.Unzip(var startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Length(Self);
  SetLength(startArr, Result);
  SetLength(stopArr, Result);
  for i := 0 to (Result - 1) do
  begin
    startArr[i] := Self[i].start;
    stopArr[i] := Self[i].stop;
  end;
end;

{==============================================================================]
 <TRangeArrayHelper.Zip>
 @action: Zips TPointArray with startArr and stopArr.
 @note: Uses minimum length(!), if startArr differs from stopArr size.
[==============================================================================}
function TRangeArrayHelper.Zip(const startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Min(Length(startArr), Length(stopArr));
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
  begin
    Self[i].start := startArr[i];
    Self[i].stop := stopArr[i];
  end;
end;
{$ENDIF}

{$UNDEF TRange}