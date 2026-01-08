{$IFDEF HELPERS}
function Singlify(const item: MType): Integer; overload; cdecl;
function Singlified(const item: MType): MArray; overload; cdecl;
function Singularize(const item: MType): Integer; overload; cdecl;
function Singularized(const item: MType): MArray; overload; cdecl;
function Soloize(const item: MType): Integer; overload; cdecl;
function Soloized(const item: MType): MArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Singlify>
  @action: Removes duplicate occurrences of a specific item, keeping only the first.
  @note: Useful for ensuring a item appears exactly once in the array.
[==============================================================================}
function MArrayHelper.Singlify(const item: MType): Integer; overload; cdecl;
var
  i, l: Integer;
  f: Boolean;
begin
  Result := Self.Size;
  l := 0;
  f := False;
  for i := 0 to (Result - 1) do
    if ((not f) or (Self[i] <> item)) then
    begin
      Self[l.Increase] := Self[i];
      if (Self[i] = item) then
        f := True;
    end;
  if (Result.Decrement(l) > 0) then
    SetLength(Self, l);
end;

{==============================================================================]
  <Singlified>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function MArrayHelper.Singlified(const item: MType): MArray; overload; cdecl;
var
  i, l: Integer;
  f: Boolean;
begin
  SetLength(Result, Self.Size);
  l := 0;
  f := False;
  for i := 0 to High(Self) do
    if ((not f) or (Self[i] <> item)) then
    begin
      Result[l.Increase] := Self[i];
      if (Self[i] = item) then
        f := True;
    end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Singularize>
  @action: Removes duplicate items in the array, keeping only the first occurrence of each unique value.
  @note: The operation modifies the current array in-place. The order of the first appearances
         is preserved. Returns the number of items removed.
[==============================================================================}
function MArrayHelper.Singularize(const item: MType): Integer; overload; cdecl;
var
  d: specialize TDictionary<MType, Boolean>;
  i, l: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    l := 0;
    for i := 0 to High(Self) do
      if ((Self[i] <> item) or (not d.ContainsKey(item))) then
      begin
	    if (Self[i] = item) then
          d.Add(item, True);
        Self[l.Increase] := Self[i];
      end;
    Result := (Self.Size - l);
    if (Result > 0) then
      SetLength(Self, l);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Singularized>
  @action: Returns a new array containing only the first occurrence of each unique item.
  @note: The original array remains unchanged. The resulting array preserves
         the order of the first appearances.
[==============================================================================}
function MArrayHelper.Singularized(const item: MType): MArray; overload; cdecl;
var
  d: specialize TDictionary<MType, Boolean>;
  i, c: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    SetLength(Result, Self.Size);
    c := 0;
    for i := 0 to High(Self) do
      if ((Self[i] <> item) or (not d.ContainsKey(item))) then
      begin
        if (Self[i] = item) then
          d.Add(item, True);
        Result[c.Increase] := Self[i];
      end;
    SetLength(Result, c);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Soloize>
  @action: Removes all occurrences of a specific item from the array.
  @note: Returns the number of items removed. If none found, the array is unchanged.
[==============================================================================}
function MArrayHelper.Soloize(const item: MType): Integer; overload; cdecl;
var
  i, l: Integer;
begin
  l := 0;
  Result := 0;
  for i := 0 to High(Self) do
    if ((Self[i] = item) and (Result.Increase > 0)) then
      Continue
    else
      Self[l.Increase] := Self[i];
  if (Result > 0) then
    SetLength(Self, l);
end;

{==============================================================================]
  <Soloized>
  @action: Returns a new array containing only a single instance of the specified item.
  @note: Duplicates of item beyond the first occurrence are removed in the result.
         The original array remains unchanged.
[==============================================================================}
function MArrayHelper.Soloized(const item: MType): MArray; overload; cdecl;
var
  i, l, s: Integer;
begin
  SetLength(Result, Self.Size);
  s := 0;
  l := 0;
  for i := 0 to High(Self) do
    if ((Self[i] = item) and (s.Increase > 0)) then
      Continue
    else
      Result[l.Increase] := Self[i];
  if (s > 0) then
    SetLength(Result, l);
end;
{$ENDIF}