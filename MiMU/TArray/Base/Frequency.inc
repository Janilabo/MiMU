{$IFDEF HELPERS}
function LeastCommon: MType; overload; cdecl;
function LeastFrequent: MType; overload; cdecl;
function MostCommon: MType; overload; cdecl;
function MostFrequent: MType; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <LeastCommon>
  @action: Returns the least common array item.
  @note: None
[==============================================================================}
function MArrayHelper.LeastCommon: MType; overload; cdecl;
var
  d: specialize TDictionary<MType, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(MType));
  Result := Self[0];
  m := MaxInt;
  d := specialize TDictionary<MType, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] < m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <LeastFrequent> 
  @action: Returns the least frequent arr item.
  @note: None.
[==============================================================================}
function MArrayHelper.LeastFrequent: MType; overload; cdecl;
var
  i, j, c, m: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit;
  m := 2147483647;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (Self[j] = Self[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := Self[i];
    end;
  end;
end;

{==============================================================================]
  <MostCommon>
  @action: Returns the most common array item.
  @note: None
[==============================================================================}
function MArrayHelper.MostCommon: MType; overload; cdecl;
var
  d: specialize TDictionary<MType, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(MType));
  Result := Self[0];
  m := 0;
  d := specialize TDictionary<MType, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] > m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <MostFrequent> 
  @action: Returns the most frequent arr item.
  @note: None.
[==============================================================================}
function MArrayHelper.MostFrequent: MType; overload; cdecl;
var
  i, j, c, m: Integer;
begin
  if Self.Empty then
    Exit;
  m := 0;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := Self[i];
    end;
  end;
end;
{$ENDIF}