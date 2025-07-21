{==============================================================================]
  <TRangeArrayHelper.Bounds: TRange>
  @action: Returns the bounds of TRange array as TRange.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Bounds: TRange; overload; cdecl;
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
function TRangeArrayHelper.Range: TRange; overload; cdecl;
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
function TRangeArrayHelper.TIA: TIntegerArray; cdecl;
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
function TRangeArrayHelper.T2DIA: T2DIntegerArray; cdecl;
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
function TRangeArrayHelper.Starting: TIntegerArray; overload; cdecl;
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
function TRangeArrayHelper.Stopping: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

function TRangeArrayHelper.Normalized: TRangeArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i].Create(Min(Self[i].start, Self[i].stop), Max(Self[i].start, Self[i].stop));
end;