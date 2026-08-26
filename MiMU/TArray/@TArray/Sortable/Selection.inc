{$IFDEF HELPERS}
function Allow(const aMin, aMax: MType): Integer; overload;
function Deny(const aMin, aMax: MType): Integer; overload;
function Extractify(const aMin, aMax: MType): MArray; overload;
function Filterify(const aMin, aMax: MType): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Allow>
  @action: Retains only the elements within the inclusive range [`aMin`, `aMax`] in-place,
           truncating the array and returning the count of remaining elements.
  @note: Modifies `Self` directly using an in-place two-pointer filter algorithm to achieve O(N) time and O(1) auxiliary space complexity without allocating temporary arrays.
[==============================================================================}
function MArrayHelper.Allow(const aMin, aMax: MType): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if ((Self[i] >= aMin) and (Self[i] <= aMax)) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Deny>
  @action: Removes all elements within the inclusive range [`aMin`, `aMax`] in-place, keeping only values strictly outside the range, and returns the count of remaining elements.
  @note: Functions as the in-place inverse of `Allow`. Uses single-pass index overwriting and resizes `Self` via `SetLength` to eliminate memory allocation overhead.
[==============================================================================}
function MArrayHelper.Deny(const aMin, aMax: MType): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if ((Self[i] < aMin) or (Self[i] > aMax)) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Extractify>
  @action: Extracts all elements from the array that fall within the inclusive range [`aMin`, `aMax`] and returns them as a new array.
  @note: Performs a linear $O(N)$ scan across the array. Pre-allocates memory using `Result.Alloc(Self.Length)` to avoid repeated dynamic array reallocations during insertion,
         then truncates the result array to the actual count of extracted items (`l`) before returning.
[==============================================================================}
function MArrayHelper.Extractify(const aMin, aMax: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if ((Self[i] >= aMin) and (Self[i] <= aMax)) then
      Result[l.Increase] := Self[i];
  if (l < Result.Length) then
    SetLength(Result, l);
end;

{==============================================================================]
  <Filterify>
  @action: Filters out all elements from the array that fall within the inclusive range [`aMin`, `aMax`],
           returning a new array with only the elements outside this range.
  @note: Acts as the logical inverse of `Extractify`. Pre-allocates capacity up to `Self.Length` to minimize memory allocation overhead during iteration,
         followed by a final truncation (`SetLength`) to fit the count of retained elements (`l`).
[==============================================================================}
function MArrayHelper.Filterify(const aMin, aMax: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if not ((Self[i] >= aMin) and (Self[i] <= aMax)) then
      Result[l.Increase] := Self[i];
  if (l < Result.Length) then
    SetLength(Result, l);
end;
{$ENDIF}
