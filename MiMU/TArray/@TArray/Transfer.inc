{$IFDEF HELPERS}
function Deliver(var target: MArray; aIndex: Integer = 0): Boolean; overload;
function Deliver(var target: MArray; const aIndexes: TIntegerArray): Integer; overload;
function Fetch(const source: MArray; aIndex: Integer = 0): MType; overload;
function Fetch(const source: MArray; const aIndexes: TIntegerArray): MArray; overload;
function Place(var target: MArray; aIndex: Integer = 0): MType; overload;
function Place(var target: MArray; const aIndexes: TIntegerArray): MArray; overload;
function Receive(const source: MArray; aIndex: Integer = 0): Boolean; overload;
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
begin
  for i := 0 to Result.Alloc(AIndexes.Length) do
  begin
    Result := Self[aIndexes[i]];
    Self[aIndexes[i]] := source[aIndexes[i]];
  end;
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
  i, h, s, l: Integer;
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