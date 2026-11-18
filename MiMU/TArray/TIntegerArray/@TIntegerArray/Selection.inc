{$IFDEF HELPERS}
function Extract(const values: TRange): TIntegerArray; overload;
function Extracted(const values: TRange): TIntegerArray; overload;
function ExtractEven: TIntegerArray; overload;
function ExtractOdd: TIntegerArray; overload;
function ExtractValues(const values: TRange): TIntegerArray; overload;
function ExtractValues(const values: TRangeArray): TIntegerArray; overload;
function Extractify(const values: TRange): TIntegerArray; overload;

function Filter(const values: TRange): TIntegerArray; overload;
function Filtered(const values: TRange): TIntegerArray; overload;
function FilterEven: TIntegerArray; overload;
function FilterOdd: TIntegerArray; overload;
function FilterValues(const values: TRange): TIntegerArray; overload;
function FilterValues(const values: TRangeArray): TIntegerArray; overload;
function Filterify(const values: TRange): TIntegerArray; overload;

function Primes: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Extract>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that fall within the specified normalized range (inclusive).
  @note:
- The original array order is preserved.
- Elements outside the given range are excluded.
- Range normalization is performed via values.Normalize prior to evaluation.
- Membership check uses explicit bounds testing (greater than or equal to start,
      and less than or equal to stop).
- The result array is preallocated to the source length and trimmed
      to the number of retained elements.
[==============================================================================}
function TIntegerArrayHelper.Extract(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
  v: TRange;
begin
  r := 0;
  v := values.Normalize;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i] >= v.start) then
      if (Self[i] <= v.stop) then
        Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Extracted>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that are contained within the specified TRange, utilizing an
           intermediate index-mapping approach.
  @note:
    - The original array order is preserved.
    - Elements outside the given range are excluded.
    - Uses a two-pass approach: the first pass records the indices of matching
      elements into an intermediate array (`m`), and the second pass populates
      the result.
  - Membership testing is performed via TRange.Contains.
  - The result array is sized precisely via SetSize based on the match count.
[==============================================================================}
function TIntegerArrayHelper.Extracted(const values: TRange): TIntegerArray; overload;
var
  i, r, s: Integer;
  m: TIntegerArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  SetLength(m, s);
  for i := 0 to High(Self) do
    if values.Contains(Self[i]) then
      m[r.Increase] := i;
  if (Result.SetSize(r) > 0) then
  for i := High(Self) downto 0 do
    Result[r.Decrement] := Self[m[i]];
end;

{==============================================================================]
  <ExtractEven>
  @action: Returns even values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
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
  if (Result.SetSize(Self.Length) = 0) then
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
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
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
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if v.BinaryContains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Extractify>
  @action: Returns a new TIntegerArray containing only the elements of the source 
           array that ARE contained within the specified TRange.
  @note:
    - The original array order is preserved.
    - Elements outside the given range are excluded.
    - Uses a two-pass approach (first counting matches, then backward population).
    - Membership testing is performed via TRange.Contains.
    - The result array is sized precisely via SetSize based on the match count.
[==============================================================================}
function TIntegerArrayHelper.Extractify(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 0 to High(Self) do
    if values.Contains(Self[i]) then
      Inc(r);
  if (Result.SetSize(r) > 0) then
  for i := High(Self) downto 0 do
    if values.Contains(Self[i]) then
      Result[r.Decrement] := Self[i];
end;

{==============================================================================]
  <Filter>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that fall outside the specified normalized range.
  @note:
    - The original array order is preserved.
    - Elements strictly within the given range (inclusive) are excluded.
    - Range normalization is performed via values.Normalize prior to evaluation.
    - Exclusion check uses explicit boundary comparisons (less than start or
      greater than stop).
    - The result array is preallocated to the source length and trimmed
      to the number of retained elements.
[==============================================================================}
function TIntegerArrayHelper.Filter(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
  v: TRange;
begin
  r := 0;
  v := values.Normalize;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i] < v.start) then
      Result[r.Increase] := Self[i]
    else if (Self[i] > v.stop) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Filtered>
  @action: Returns a new TIntegerArray containing only the elements of the source
           array that are NOT contained within the specified TRange, utilizing
           an intermediate index-mapping approach.
  @note:
- The original array order is preserved.
- Elements inside the given range are excluded.
- Uses a two-pass approach: the first pass records the indices of non-matching
      elements into an intermediate array (`m`), and the second pass populates
      the result.
- Membership testing is performed via TRange.Contains (negated).
- The result array is sized precisely via SetSize based on the non-match count.
[==============================================================================}
function TIntegerArrayHelper.Filtered(const values: TRange): TIntegerArray; overload;
var
  i, r, s: Integer;
  m: TIntegerArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  SetLength(m, s);
  for i := 0 to High(Self) do
    if not values.Contains(Self[i]) then
      m[r.Increase] := i;
  if (Result.SetSize(r) > 0) then
  for i := High(Self) downto 0 do
    Result[r.Decrement] := Self[m[i]];
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
  if (Result.SetSize(Self.Length) = 0) then
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
  if (Result.SetSize(Self.Length) = 0) then
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
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
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
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if not v.BinaryContains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Filterify>
  @action: Returns a new TIntegerArray containing only the elements of the source 
           array that are NOT contained within the specified TRange (mirroring 
           FilterValues, but implemented via a two-pass backward population).
  @note:
    - The original array order is preserved.
    - Elements inside the given range are excluded.
    - Uses a two-pass approach (first counting non-matches, then backward population).
    - Membership testing is performed via TRange.Contains.
    - The result array is sized precisely via SetSize based on the non-match count.
[==============================================================================}
function TIntegerArrayHelper.Filterify(const values: TRange): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 0 to High(Self) do
    if not values.Contains(Self[i]) then
      Inc(r);
  if (Result.SetSize(r) > 0) then
  for i := High(Self) downto 0 do
    if not values.Contains(Self[i]) then
      Result[r.Decrement] := Self[i];
end;

function TIntegerArrayHelper.Primes: TIntegerArray; overload;
begin
  Result := Where(@IsPrime);
end;
{$ENDIF}
