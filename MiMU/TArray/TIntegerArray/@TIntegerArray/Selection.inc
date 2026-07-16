{$IFDEF HELPERS}
function ExtractEven: TIntegerArray; overload;
function ExtractOdd: TIntegerArray; overload;
function ExtractValues(const values: TRange): TIntegerArray; overload;
function ExtractValues(const values: TRangeArray): TIntegerArray; overload;
function FilterEven: TIntegerArray; overload;
function FilterOdd: TIntegerArray; overload;
function FilterValues(const values: TRange): TIntegerArray; overload;
function FilterValues(const values: TRangeArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ExtractEven>
  @action: Returns even values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <ExtractOdd>
  @action: Returns odd values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <ExtractValues>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that are contained within the specified TRange.
  @note:
    - The original array order is preserved.
    - Elements outside the given range are excluded.
    - If no elements match, an empty array is returned.
    - The result array is preallocated to the source length and trimmed
      to the number of matched elements.
    - Membership testing is performed via TRange.Contains.
[==============================================================================}
function TIntegerArrayHelper.ExtractValues(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Length);
  r := 0;
  for i := 0 to High(Self) do
    if values.Contains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <ExtractValues>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that fall within any of the specified ranges in TRangeArray.
  @note:
    - The original array order is preserved.
    - If the provided range array is empty, an empty array is returned.
    - The ranges are first transformed into a flattened integer set
      (via TIA), sorted, and pruned to ensure uniqueness.
    - Membership testing is performed using binary search
      (BinaryContains) for efficiency.
    - Time complexity:
        • O(m log m) for preprocessing the range values
        • O(n log m) for filtering the source array
      where n = source length, m = total values represented by ranges.
    - The result array is preallocated to the source length and trimmed
      to the number of matched elements.
[==============================================================================}
function TIntegerArrayHelper.ExtractValues(const values: TRangeArray): TIntegerArray; overload;
var
  i, r: Integer;
  v: TIntegerArray;
begin
  if values.Empty then
    Exit([]);
  v := values.TIA.QuickSorted.Pruned;
  SetLength(Result, Self.Length);
  r := 0;
  for i := 0 to High(Self) do
    if v.BinaryContains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <FilterEven>
  @action: Returns array without even values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterOdd>
  @action: Returns array without odd values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterValues>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that are NOT contained within the specified TRange.
  @note:
    - The original array order is preserved.
    - Elements inside the given range are excluded.
    - If all elements fall within the range, an empty array is returned.
    - If no elements fall within the range, a copy of the original values
      is returned (via preallocation and trim).
    - Membership testing is performed via TRange.Contains.
    - The result array is preallocated to the source length and trimmed
      to the number of retained elements.
[==============================================================================}
function TIntegerArrayHelper.FilterValues(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Length);
  r := 0;
  for i := 0 to High(Self) do
    if not values.Contains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <FilterValues>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that are NOT contained within any of the specified ranges in TRangeArray.
  @note:
    - The original array order is preserved.
    - If the provided range array is empty, a clone of the source array
      is returned.
    - The ranges are first flattened into an integer set (via TIA),
      sorted, and pruned to ensure uniqueness.
    - Membership testing is performed using binary search
      (BinaryContains) for efficiency.
    - Time complexity:
        • O(m log m) for preprocessing the range values
        • O(n log m) for filtering the source array
      where n = source length, m = total values represented by ranges.
    - The result array is preallocated to the source length and trimmed
      to the number of retained elements.
[==============================================================================}
function TIntegerArrayHelper.FilterValues(const values: TRangeArray): TIntegerArray; overload;
var
  i, r: Integer;
  v: TIntegerArray;
begin
  if values.Empty then
    Exit(Self.Cloned);
  v := values.TIA.QuickSorted.Pruned;
  SetLength(Result, Self.Length);
  r := 0;
  for i := 0 to High(Self) do
    if not v.BinaryContains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;
{$ENDIF}
