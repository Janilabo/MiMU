{==============================================================================]
  <field>
  @action: Returns field values from array.
  @note: None.
[==============================================================================}
function FField(const arr: TArr): FArr; overload;
{$IFDEF IMPLEMENTATION}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].FField;
end;
{$ENDIF}

{==============================================================================]
  <field>
  @action: Returns arr indexes from array as TIntegerArray where values match val.
  @note: None.
[==============================================================================}
function FField(const arr: TArr; const val: FVar): TIntegerArray; overload;
{$IFDEF IMPLEMENTATION}
var
  i, r: Integer;
begin
  r := 0;
  if arr.Exists then
    SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    if (arr[i].FField = val) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
  <field>
  @action: Returns arr indexes from array as TIntegerArray where values match vals.
  @note: None.
[==============================================================================}
function FField(const arr: TArr; const vals: FArr): TIntegerArray; overload;
{$IFDEF IMPLEMENTATION}
var
  i, r: Integer;
  d: specialize TDictionary<FVar, Boolean>;
begin
  r := 0;
  if (arr.Exists and (Length(vals) > 0)) then
  begin
    d := specialize TDictionary<FVar, Boolean>.Create;
    try
      for i := 0 to High(vals) do
        d.TryAdd(vals[i], True);
      SetLength(Result, Length(arr));
      for i := 0 to High(arr) do
        if d.ContainsKey(arr[i].FField) then
          Result[r.Increase] := i;
    finally
      d.Free;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}
