{$IFDEF HELPERS}
function Distinct: Integer; overload;
function Waste: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distinct>
  @action: Returns the number of unique elements in array
  @note: None.
[==============================================================================}
function MArrayHelper.Distinct: Integer; overload;
var
  i, j: Integer;
  u: Boolean;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
  begin
    u := True;
    for j := 0 to (i - 1) do
      if (Self[i] = Self[j]) then
      begin
        u := False;
        Break;
      end;
    if u then
      Inc(Result);
  end;
end;

{==============================================================================]
  <Waste>
  @action: Returns total count of Duplicates in array, which is considered as "Waste"
  @note: None.
[==============================================================================}
function MArrayHelper.Waste: Integer; overload;
type
  TDict = specialize TDictionary<MType, Integer>;
var
  d: TDict;
  i: Integer;
  v: MType;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  d := TDict.Create;
  try
    for v in Self do
      if d.ContainsKey(v) then
        d[v] := (d[v] + 1)
      else
        d.Add(v, 1);
    for i in d.Values do
      if (i > 1) then
        Result := (Result + (i - 1));
  finally
    d.Free;
  end;
end;
{$ENDIF}