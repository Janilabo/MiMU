{$IFDEF HELPERS}
function Compact: Integer; overload;
function Compacted: MArray; overload;
function Compacted(const threshold: Integer): MArray; overload;
function Compress: Integer; overload;
function Compressed: MArray; overload;
function Compressed(const threshold: Integer): MArray; overload;
function Deduplicated: MArray; overload;
function Prune: Integer; overload;
function Pruned: MArray; overload;
function Pruned(const threshold: Integer): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compact>
  @action: Removes adjacent duplicates.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Compact: Integer; overload;
var
  i: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Size);
  Result := 1;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Compacted>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Compacted: MArray; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit([]);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Result.Supply(Self[i]);
end;

{==============================================================================]
  <Compacted>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Compacted(const threshold: Integer): MArray; overload;
var
  i, j: Integer;
  k: Boolean;
  r: Integer;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  r := 0;
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    k := True;
    for j := Max(0, (r - threshold)) to (r - 1) do
      if (Result[j] = Self[i]) then
      begin
        k := False;
        Break;
      end;
    if k then
    begin
      if (Result.Size <= r) then
        SetLength(Result, (r + 1));
      Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Compressed>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Compressed: MArray; overload;
var
  r, i, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l > 1) then
  begin
    r := 0;
    for i := 1 to (l - 1) do
      if not (Self[i] = Result[r]) then
        Result[r.Increment] := Self[i];
    SetLength(Result, (r + 1));
  end;
end;

{==============================================================================]
  <Compressed>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Compressed(const threshold: Integer): MArray; overload;
var
  w, r, i: Integer;
  d: Boolean;
begin
  Result := Self.Copy;
  if (Self.Empty or (threshold < 1)) then
    Exit;
  w := 0;
  for r := 0 to High(Result) do
  begin
    d := False;
    for i := Max(0, (w - threshold)) to (w - 1) do
      if (Result[i] = Result[r]) then
      begin
        d := True;
        Break;
      end;
    if not d then
      Result[w.Increase] := Result[r];
  end;
  SetLength(Result, w);
end;

{==============================================================================]
  <Compress>
  @action: Removes all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Compress: Integer; overload;
var
  i: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Size);
  Result := 1;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Deduplicated>
  @action: Removes adjacent duplicates and returns a new compacted array.
  @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function MArrayHelper.Deduplicated: MArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit();
  l := 0;
  for i := 0 to High(Self) do
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <Pruned>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Pruned: MArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l = 1) then
    Exit;
  r := 0;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[i - 1]) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Pruned>
  @action: Produces a new array by removing all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Custom threshold possibility.
[==============================================================================}
function MArrayHelper.Pruned(const threshold: Integer): MArray; overload;
var
  w: MArray;
  e: MType;
  h, t, c, i, j: Integer;
  d: Boolean;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  SetLength(Result, 0);
  SetLength(w, threshold);
  h := 0;
  t := 0;
  c := 0;
  for i := 0 to High(Self) do
  begin
    e := Self[i];
    d := False;
    for j := 0 to (c - 1) do
      if (w[(h + j) mod threshold] = e) then
      begin
        d := True;
        Break;
      end;
    if not d then
    begin
      SetLength(Result, (Result.Size + 1));
      Result[High(Result)] := e;
      w[t] := e;
      t := ((t + 1) mod threshold);
      if (c < threshold) then
        Inc(c)
      else
        h := ((h + 1) mod threshold);
    end;
  end;
end;

{==============================================================================]
  <Prune>
  @action: Removes all immediately repeated values,
           effectively run-length–compressing the input.
  @note: Only consecutive duplicates are removed; values separated by others
         are left untouched. The relative order of the remaining elements
         is unchanged.
[==============================================================================}
function MArrayHelper.Prune: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[Result]) then
      Self[Result.Increment] := Self[i];
  if not Self.Empty then
    SetLength(Self, Result.Increment);
end;
{$ENDIF}