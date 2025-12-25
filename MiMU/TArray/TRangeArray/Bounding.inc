{$IFDEF HELPERS}
function Bounds: TRange; overload;
function Range: TRange; overload;
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
{$ENDIF}
