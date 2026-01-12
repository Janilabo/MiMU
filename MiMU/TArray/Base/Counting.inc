{$IFDEF HELPERS}
function Count(const item: MType): Integer; overload;
function Count(const items: MArray): Integer; overload;
function IntersectionCounted(const items: MArray): Integer; overload;
function Uniformity: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Count>
  @action: Counts how many times the specified item appears in the array.
  @note:
    - Returns 0 if the array is empty or the item is not found.
    - Uses zero-based indexing (0..High(Self)).
    - Single-pass, no extra memory allocation.
[==============================================================================}
function MArrayHelper.Count(const item: MType): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if (Self[i] = item) then
      Inc(Result);
end;

{==============================================================================]
  <Count>
  @action: Counts how many elements of the array appear in the given set of items.
  @note:
    - Returns 0 if either the array or the items array is empty.
    - Each match increments the count once; duplicates in items are considered normally.
    - Uses zero-based indexing (0..High(Self)).
    - Single-pass over Self, but each element performs a search over items (O(n*m)).
[==============================================================================}
function MArrayHelper.Count(const items: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  if (items.Length > 0) then
  for i := 0 to High(Self) do
    if items.Contains(Self[i]) then
      Inc(Result);
end;

{==============================================================================]
  <IntersectionCounted>
  @action: Counts the number of distinct elements in Self that also exist in Items.
           Each element is counted at most once, regardless of duplicates in either array.
  @note:
    - Does not require the arrays to be sorted.
    - Uses a hash-based dictionary to track membership; time complexity is roughly O(N + M),
      where N = Length(Self), M = Length(Items).
    - Works for any type supported by MType that can be used as a dictionary key
      (must support hashing and equality comparison).
    - Each matched element is removed from the dictionary to ensure distinct counting.
    - Returns 0 if either array is empty.
[==============================================================================}
function MArrayHelper.IntersectionCounted(const items: MArray): Integer; overload;
var
  S: specialize TDictionary<MType, Byte>;
  i: Integer;
begin
  Result := 0;
  if (items.Empty or Self.Empty) then
    Exit;
  S := specialize TDictionary<MType, Byte>.Create;
  try
    for i := 0 to High(items) do
      S.TryAdd(items[i], 0);
    for i := 0 to High(Self) do
      if S.ContainsKey(Self[i]) then
      begin
        Inc(Result);
        S.Remove(Self[i]);
      end;
  finally
    S.Free;
  end;
end;

{==============================================================================]
  <Uniformity>
  @action: Returns 1.0 if all elements equal, 0.0 if all different,
           or something in between based on unique-value ratio.
  @note: None.
 [==============================================================================}
function MArrayHelper.Uniformity: Double; overload;
begin
  if not Self.Empty then
    Result := (1.0 / Self.Distinct)
  else
    Result := 0.0;
end;
{$ENDIF}