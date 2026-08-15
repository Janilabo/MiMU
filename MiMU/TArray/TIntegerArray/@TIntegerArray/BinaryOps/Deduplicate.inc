{$IFDEF HELPERS}
function BinaryPrune(const aAscending: Boolean = True): Integer;
function BinaryPruned(const aAscending: Boolean = True): TIntegerArray;
function BinaryUnique(const oAscending: Boolean = True): Integer; overload;
function BinaryUniqued(const oAscending: Boolean = True): TIntegerArray; overload;
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

{==============================================================================]
  <BinaryUnique>
  @action: Sorts the array using binary sort, removes duplicate values in-place,
           and returns the final number of unique elements.
  @note: This routine always performs a full binary sort prior to uniqueness
         filtering. After sorting, it compacts the array by overwriting
         duplicates and truncating the underlying storage to the count of
         uniques.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnique(const oAscending: Boolean = True): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(l);
  Self.BinarySort(oAscending);
  Result := 1;
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  if (Result < l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <BinaryUniqued>
  @action: Returns a new array containing the unique values of the source array,
           sorted according to the specified order, without modifying the
           original array.
  @note: The function makes a full copy of the source array, applies a binary
         sort, removes duplicates by in-place compaction of the copy, and
         trims the resulting array to the count of unique elements.
[==============================================================================}
function TIntegerArrayHelper.BinaryUniqued(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  if (Result.Size < 2) then
    Exit;
  Result.BinarySort(oAscending);
  l := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  if (Result.Size > l) then
    SetLength(Result, l);
end;
{$ENDIF}
