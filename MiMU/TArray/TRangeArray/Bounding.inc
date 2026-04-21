{$IFDEF HELPERS}
function Boundaries: TRange; overload;
function Bounds: TRange; overload;
function Range: TRange; overload;
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
{$ENDIF}
