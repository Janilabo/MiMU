{$IFDEF HELPERS}
function Deliver(var target: MArray; const aIndex: Integer = 0): Boolean; overload;
function Deliver(var target: MArray; const aIndexes: TIntegerArray): Integer; overload;
function Fetch(const source: MArray; const aIndex: Integer = 0): MType; overload;
function Fetch(const source: MArray; const aIndexes: TIntegerArray): MArray; overload;
function Inlay(const source: MArray; const sIndexes: TIntegerArray): Integer; overload;
function Inlay(const source: MArray; const sIndexes: TRange): Integer; overload;
function Inlay(const source: MArray; const sIndex: Integer): Integer; overload;
function Inlay(const source: MArray; const sIndexA, sIndexB: Integer): Integer; overload;
function Onlay(var target: MArray; const sIndexes: TIntegerArray): Integer; overload;
function Onlay(var target: MArray; const sIndexes: TRange): Integer; overload;
function Onlay(var target: MArray; const sIndex: Integer): Integer; overload;
function Onlay(var target: MArray; const sIndexA, sIndexB: Integer): Integer; overload;
function Place(var target: MArray; const aIndex: Integer = 0): MType; overload;
function Place(var target: MArray; const aIndexes: TIntegerArray): MArray; overload;
function Receive(const source: MArray; const aIndex: Integer = 0): Boolean; overload;
function Receive(const source: MArray; const aIndexes: TIntegerArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Deliver>
  @action: Copies a single element from the current array (`Self`) to a matching index in a `target` array.
  @note: Bounds checking is performed on both arrays using `aIndex`.
         Returns `True` if the index is valid for both arrays and the value was successfully copied, otherwise returns `False`.
[==============================================================================}
function MArrayHelper.Deliver(var target: MArray; const aIndex: Integer = 0): Boolean; overload;
begin
  Result := ((aIndex >= 0) and (aIndex < Self.Length) and (aIndex < target.Length));
  if Result then
    target[aIndex] := Self[aIndex];
end;

{==============================================================================]
  <Deliver>
  @action: Copies multiple elements from the current array (`Self`) to a `target` array at the specific indices provided by `aIndexes`.
  @note: Safely performs bounds-checking on each index against both the source and target lengths.
         Elements at out-of-bound indices are skipped, and the function returns the total count of successfully transferred elements.
[==============================================================================}
function MArrayHelper.Deliver(var target: MArray; const aIndexes: TIntegerArray): Integer; overload;
var
  i, h, s, l: Integer;
begin
  l := target.Length;
  s := Self.Length;
  if ((l = 0) or (s = 0)) then
    Exit(0);
  Result := aIndexes.Length;
  for i := 0 to High(aIndexes) do
    if ((aIndexes[i] >= 0) and (aIndexes[i] < s) and (aIndexes[i] < l)) then
      target[aIndexes[i]] := Self[aIndexes[i]]
    else
      Dec(Result);
end;


{==============================================================================]
  <Fetch>
  @action: Swaps an element from a `source` array into the current array (`Self`) at `aIndex`, returning the element's *original* value from `Self`.
  @note: This method contains NO bounds checking. It will cause a runtime Access Violation or Range Check Error if `aIndex` is out of bounds for either `Self` or `source`.
[==============================================================================}
function MArrayHelper.Fetch(const source: MArray; const aIndex: Integer = 0): MType; overload;
begin
  Result := Self[aIndex];
  Self[aIndex] := source[aIndex];
end;

{==============================================================================]
  <Fetch>
  @action: Swaps elements between a `source` array and the current array (`Self`) at the indices specified by `aIndexes`,
           returning an array containing the original values from `Self`.
  @note: CRITICAL NOTE: This method contains no bounds checking and contains compilation bugs.
         Indexing outside valid boundaries will trigger runtime access violations.
[==============================================================================}
function MArrayHelper.Fetch(const source: MArray; const aIndexes: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(AIndexes.Length) do
  begin
    Result[i] := Self[aIndexes[i]];
    Self[aIndexes[i]] := source[aIndexes[i]];
  end;
end;

{==============================================================================]
  <Inlay>
  @action: Copies values from `source` into `Self` at each index in `sIndexes`, leaving all other elements of `Self` untouched.
  @note: Returns the number of indices written (equal to `sIndexes.Length`). Indices are not validated for bounds or duplicates.
         No bounds or duplicate-index checking is performed — the caller is responsible for ensuring all indices are valid for both `source` and `Self`.
		 Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Inlay(const source: MArray; const sIndexes: TIntegerArray): Integer; overload;
var
  s: Integer;
begin
  Result := sIndexes.Length;
  for s := 0 to (Result - 1) do
    Self[sIndexes[s]] := source[sIndexes[s]];
end;

{==============================================================================]
  <Inlay>
  @action: Copies values from `source` into `Self` at each index spanned by `sIndexes`,
           walking from `sIndexes.start` in the direction given by `sIndexes.Direction`, leaving all other elements of `Self` untouched.
  @note: Returns the number of indices written (equal to `sIndexes.Size`). Supports both ascending and descending ranges via `Direction`.
         No bounds checking is performed — the caller must ensure the full range is valid for both `source` and `Self`.
		 Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Inlay(const source: MArray; const sIndexes: TRange): Integer; overload;
var
  s, d, i: Integer;
begin
  Result := sIndexes.Size;
  d := sIndexes.Direction;
  for s := 0 to (Result - 1) do
  begin
    i := (sIndexes.start + (s * d));
    Self[i] := source[i];
  end;
end;

{==============================================================================]
  <Inlay>
  @action: Copies the single value at `sIndex` from `source` into `Self`, leaving all other elements of `Self` untouched.
  @note: Always returns 1. Single-index convenience overload of the array-indexed variant.
         No bounds checking is performed — the caller must ensure `sIndex` is valid for both `source` and `Self`.
		 Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Inlay(const source: MArray; const sIndex: Integer): Integer; overload;
begin
  Result := 1;
  Self[sIndex] := source[sIndex];
end;

{==============================================================================]
  <Inlay>
  @action: Copies the values at `sIndexA` and `sIndexB` from `source` into `Self`, leaving all other elements of `Self` untouched.
  @note: Always returns 2. Two-index convenience overload; does not check whether `sIndexA` and `sIndexB` are equal.
         No bounds checking is performed — the caller must ensure both indices are valid for both `source` and `Self`.
		 Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Inlay(const source: MArray; const sIndexA, sIndexB: Integer): Integer; overload;
begin
  Result := 2;
  Self[sIndexA] := source[sIndexA];
  Self[sIndexB] := source[sIndexB];
end;

{==============================================================================]
  <Onlay>
  @action: Copies values from `Self` onto `target` at each index in `dIndexes`, leaving all other elements of `target` untouched.
  @note: Returns the number of indices written (equal to `dIndexes.Length`). No bounds or duplicate-index checking is performed — the caller is responsible for ensuring all indices are valid for both `Self` and `target`. Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Onlay(var target: MArray; const sIndexes: TIntegerArray): Integer; overload;
var
  s: Integer;
begin
  Result := sIndexes.Length;
  for s := 0 to (Result - 1) do
    target[sIndexes[s]] := Self[sIndexes[s]];
end;

{==============================================================================]
  <Onlay>
  @action: Copies values from `Self` onto `target` at each index spanned by `sIndexes`, walking from `sIndexes.start` in the direction given by `sIndexes.Direction`, leaving all other elements of `target` untouched.
  @note: Returns the number of indices written (equal to `sIndexes.Size`). Supports both ascending and descending ranges via `Direction`. No bounds checking is performed — the caller must ensure the full range is valid for both `Self` and `target`. Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Onlay(var target: MArray; const sIndexes: TRange): Integer; overload;
var
  s, d, i: Integer;
begin
  Result := sIndexes.Size;
  d := sIndexes.Direction;
  for s := 0 to (Result - 1) do
  begin
    i := (sIndexes.start + (s * d));
    target[i] := Self[i];
  end;
end;

{==============================================================================]
  <Onlay>
  @action: Copies the single value at `sIndex` from `Self` onto `target`, leaving all other elements of `target` untouched.
  @note: Always returns 1. Single-index convenience overload of the array-indexed variant. No bounds checking is performed — the caller must ensure `sIndex` is valid for both `Self` and `target`. Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Onlay(var target: MArray; const sIndex: Integer): Integer; overload;
begin
  Result := 1;
  target[sIndex] := Self[sIndex];
end;

{==============================================================================]
  <Onlay>
  @action: Copies the values at `sIndexA` and `sIndexB` from `Self` onto `target`, leaving all other elements of `target` untouched.
  @note: Always returns 2. Two-index convenience overload; does not check whether `sIndexA` and `sIndexB` are equal. No bounds checking is performed — the caller must ensure both indices are valid for both `Self` and `target`. Failsafes are intentionally omitted to keep the method efficient.
[==============================================================================}
function MArrayHelper.Onlay(var target: MArray; const sIndexA, sIndexB: Integer): Integer; overload;
begin
  Result := 2;
  target[sIndexA] := Self[sIndexA];
  target[sIndexB] := Self[sIndexB];
end;

{==============================================================================]
  <Place>
  @action: Swaps an element from the current array (`Self`) into a `target` array at `aIndex`, returning the element's *original* value from `target`.
  @note: This method contains NO bounds checking. It will cause a runtime Access Violation or Range Check Error if `aIndex` is out of bounds for either `Self` or `target`.
[==============================================================================}
function MArrayHelper.Place(var target: MArray; const aIndex: Integer = 0): MType; overload;
begin
  Result := target[aIndex];
  target[aIndex] := Self[aIndex];
end;

{==============================================================================]
  <Place>
  @action: Swaps elements between the current array (`Self`) and a `target` array at the indices specified by `aIndexes`,
           returning an array containing the original values from `target`.
  @note: CRITICAL NOTE: This method contains no bounds checking.
         Indexing outside valid boundaries for `Self` or `target` will trigger runtime access violations.
[==============================================================================}
function MArrayHelper.Place(var target: MArray; const aIndexes: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(aIndexes.Length) do
  begin
    Result[i] := target[aIndexes[i]];
    target[aIndexes[i]] := Self[aIndexes[i]];
  end;
end;

{==============================================================================]
  <Receive>
  @action: Copies a single element from a `source` array into the current array (`Self`) at the specified index.
  @note: Bounds checking is performed on both arrays using `aIndex`. Returns `True` if the transfer succeeded, otherwise returns `False`.
[==============================================================================}
function MArrayHelper.Receive(const source: MArray; const aIndex: Integer = 0): Boolean; overload;
begin
  Result := ((aIndex >= 0) and (aIndex < Self.Length) and (aIndex < source.Length));
  if Result then
    Self[aIndex] := source[aIndex];
end;

{==============================================================================]
  <Receive>
  @action: Copies multiple elements from a `source` array into the current array (`Self`) at the specific indices provided by `aIndexes`.
  @note: Safely performs bounds-checking on each index against both arrays.
         Out-of-bound indices are ignored, and the function returns the total count of successfully transferred elements.
[==============================================================================}
function MArrayHelper.Receive(const source: MArray; const aIndexes: TIntegerArray): Integer; overload;
var
  i, s, l: Integer;
begin
  l := source.Length;
  s := Self.Length;
  if ((l = 0) or (s = 0)) then
    Exit(0);
  Result := aIndexes.Length;
  for i := 0 to High(aIndexes) do
    if ((aIndexes[i] >= 0) and (aIndexes[i] < s) and (aIndexes[i] < l)) then
      Self[aIndexes[i]] := source[aIndexes[i]]
    else
      Dec(Result);
end;
{$ENDIF}
