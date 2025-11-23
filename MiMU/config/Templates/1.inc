{==============================================================================]
  <field(arr: TArray; val: VALUE): TIntegerArray>
  @action: Returns arr indexes from array as TIntegerArray where values match val.
  @note: None.
[==============================================================================}
function XFIELD(const arr: XARRAY; const val: XVALUE): TIntegerArray; overload;
{$IFDEF IMPLEMENTATION}
var
  i, r: Integer;
begin
  r := 0;
  if arr.Exists then
    SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    if (arr[i].XFIELD = val) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
  <field(arr: TArray; xVals: TIntegerArray): TIntegerArray>
  @action: Returns arr indexes from array as TIntegerArray where values match vals.
  @note: None.
[==============================================================================}
function XFIELD(const arr: XARRAY; const vals: XVALUES): TIntegerArray; overload;
{$IFDEF IMPLEMENTATION}
var
  i, r: Integer;
  d: specialize TDictionary<XVALUE, Boolean>;
begin
  r := 0;
  if (arr.Exists and (Length(vals) > 0)) then
  begin
    d := specialize TDictionary<XVALUE, Boolean>.Create;
    try
      for i := 0 to High(vals) do
        d.TryAdd(vals[i], True);
      SetLength(Result, Length(arr));
      for i := 0 to High(arr) do
        if d.ContainsKey(arr[i].XFIELD) then
          Result[r.Increase] := i;
    finally
      d.Free;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}
