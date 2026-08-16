{$IFDEF HELPERS}
function BinaryPrune(const aAscending: Boolean = True): Integer;
function BinaryPruned(const aAscending: Boolean = True): TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer;
var
  i, o: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  o := aAscending.Select(-1, 1);
  for i := 1 to High(Self) do
    if (Sign(Self[Result] - Self[i]) = o) then
      Self[Result.Increment] := Self[i];
  Result := (Result + 1);
  SetLength(Self, Result);
end;

{==============================================================================]
  <BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.BinaryPruned(const aAscending: Boolean = True): TIntegerArray;
var
  i, o, r: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  r := 0;
  o := aAscending.Select(-1, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Sign(Result[r] - Self[i]) = o) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;
{$ENDIF}
