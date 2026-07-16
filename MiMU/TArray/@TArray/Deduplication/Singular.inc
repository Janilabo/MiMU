{$IFDEF HELPERS}
function Dedup(const Item: MType; const sIndex: Integer = 0): Integer; overload;
function Deduped(const Item: MType): MArray; overload;
function Singlify(const item: MType): Integer; overload;
function Singlified(const item: MType): MArray; overload;
function Singularize(const item: MType): Integer; overload;
function Singularized(const item: MType): MArray; overload;
function Soloize(const item: MType): Integer; overload;
function Soloized(const item: MType): MArray; overload;
function Uniquify(const item: MType; const sIndex: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Dedup>
  @action: Ensures that at most one occurrence of `item` exists in the
           subrange [sIndex .. end] by removing subsequent duplicates
           while preserving relative order.
  @note: The first occurrence encountered at or after `sIndex`
         is retained. Elements before `sIndex` are not examined.
         Returns the number of removed duplicates. The array is
         modified in place.
[==============================================================================}
function MArrayHelper.Dedup(const Item: MType; const sIndex: Integer = 0): Integer; overload;
var
  l, i: Integer;
  s: Boolean;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  s := False;
  for i := Max(0, sIndex) to (l - 1) do
  case (Self[i] = item) of
    True:
    if s then
      Inc(Result)
    else
      s := True;
    False: Self[i - Result] := Self[i];
  end;
  if (Result > 0) then
    SetLength(Self, (l - Result));
end;

{==============================================================================]
  <Deduped>
  @action: Returns a new array based on the current array with at most one
           occurrence of `Item`. All subsequent duplicates of `Item` are removed,
           preserving the original order of elements.
  @note: The first occurrence of `Item` is retained. The original array
         is not modified. The returned array may have fewer elements than
         the original.
[==============================================================================}
function MArrayHelper.Deduped(const Item: MType): MArray; overload;
var
  l, i, r: Integer;
  s: Boolean;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  s := False;
  r := 0;
  for i := 0 to (l - 1) do
  case (Self[i] = item) of
    True:
    if not s then
    begin
      s := True;
      Result[i - r] := Self[i];
    end else
      Inc(r);
    False: Result[i - r] := Self[i];
  end;
  if (r > 0) then
    SetLength(Result, (l - r));
end;

{==============================================================================]
  <Singlify>
  @action: Removes duplicate occurrences of a specific item, keeping only the first.
  @note: Useful for ensuring a item appears exactly once in the array.
[==============================================================================}
function MArrayHelper.Singlify(const item: MType): Integer; overload;
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
function MArrayHelper.Singlified(const item: MType): MArray; overload;
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
function MArrayHelper.Singularize(const item: MType): Integer; overload;
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
function MArrayHelper.Singularized(const item: MType): MArray; overload;
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
function MArrayHelper.Soloize(const item: MType): Integer; overload;
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
function MArrayHelper.Soloized(const item: MType): MArray; overload;
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

{==============================================================================]
  <Uniquify>
  @action: Ensures that at most one occurrence of `item` exists in the
           subrange [sIndex .. end] by removing subsequent duplicates
           while preserving relative order.
  @note: The first occurrence encountered at or after `sIndex`
         is retained. Elements before `sIndex` are not examined.
         Returns the number of removed duplicates. The array is
         modified in place.
[==============================================================================}
function MArrayHelper.Uniquify(const item: MType; const sIndex: Integer = 0): Integer; overload;
var
  l, i: Integer;
  r: Boolean;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  r := False;
  for i := Max(0, sIndex) to (l - 1) do
    if (Self[i] <> item) then
      Self[i - Result] := Self[i]
    else if not r then
      r := True
    else
      Inc(Result);
  if (Result > 0) then
    SetLength(Self, (l - Result));
end;
{$ENDIF}