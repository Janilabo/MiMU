{$IFDEF HELPERS}
function AsIDs(const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndexes(const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndices(const aAscending: Boolean = True): TIntegerArray; overload;
function GetIDs: TIntegerArray; overload;
function ID(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const ID: TIntegerArray): MArray; overload;
function IDs(const ID: TIntegerArray; const item: MType): MArray; overload;
function IDs(const ID: TIntegerArray; const items: MArray): MArray; overload;
function Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
function Indices(const aAscending: Boolean = True): TIntegerArray; overload;
function Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
function LoadID(var target: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function LoadIDs(var target: TIntegerArray): Integer; overload;
function LoadIndexes(var target: TIntegerArray): Integer; overload;
function LoadIndices(var target: TIntegerArray): Integer; overload;
function Slots: TIntegerArray; overload;
function ToIDs(const aAscending: Boolean = True): TIntegerArray; overload;
function ToIndexes: TIntegerArray; overload;
function ToIndices(const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsIDs>
  @action: Generates an array of zero-based indexes representing the current
           array. The resulting array can be ascending (0..Length-1) or descending
           (Length-1..0) depending on the `aAscending` parameter.
  @note:
    • If the array is empty, an empty array is returned.
    • Uses direct pointer arithmetic for efficient population.
    • Time complexity: O(n), where n = Length(Self).
    • Returns a new TIntegerArray containing all indexes of Self.
    • Default order is ascending.
[==============================================================================}
function MArrayHelper.AsIDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  P: PInteger;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
	1: Exit([0]);
  end;
  SetLength(Result, l);
  P := @Result[0];
  case aAscending of
    True:
    for i := 0 to (l - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
	False:
	for i := (l - 1) downto 0 do
    begin
      P^ := i;
      Inc(P);
    end;
  end;
end;

{==============================================================================]
  <AsIndexes>
  @action: Generates an array of zero-based indexes representing the elements
           of the current array. Supports ascending (0..Length-1) or descending
           (Length-1..0) order via the `aAscending` parameter.
  @note:
    • Returns an empty array if the source array is empty.
    • Returns [0] if the array has a single element.
    • Uses `Increment` and `Decrement` helpers along with `Result.Supply`
      for in-place efficient population.
    • Time complexity: O(n), where n = Length(Self).
    • The resulting array contains all indexes of Self in the requested order.
[==============================================================================}
function MArrayHelper.AsIndexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, 0);
  i := -1;
  case aAscending of
    True:
    while (i.Increment < l) do
      Result.Supply(i);
    False:
    while (l.Decrement > i) do
      Result.Supply(l);
  end;
end;

{==============================================================================]
  <AsIndices>
  @action: Generates and returns a positional index vector for the current
           array instance.
  @note: The resulting TIntegerArray has Length = Self.Length and contains
         only positional offsets — element values are not inspected.
         Ordering:
           • aAscending = True  →  [0, 1, 2, ..., Length - 1]
           • aAscending = False →  [Length - 1, ..., 2, 1, 0]
         If Self.Length = 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.AsIndices(const aAscending: Boolean = True): TIntegerArray; overload;
label
  ready;
var
  i, l: Integer;
  P: PInteger;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l < 1) then
    goto ready;
  P := PInteger(Result);
  case aAscending of
    True:
    for i := 0 to (l - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
    False:
    repeat
      P^ := l.Decrement;
      Inc(P);
    until (l = 0);
  end;
  ready:
end;

{==============================================================================]
  <GetIDs>
  @action: Generates an array of zero-based indexes representing the elements
           of the current array. Optimized for performance by filling multiple
           indexes per iteration when possible.
  @note:
    • Returns an empty array if the source array is empty.
    • Returns [0] if the array has a single element.
    • Uses an unrolled loop to assign four indexes per iteration for speed,
      then completes remaining indexes with a standard loop.
    • Time complexity: O(n), where n = Length(Self).
    • The resulting array always contains indexes 0..Length(Self)-1
      in ascending order.
[==============================================================================}
function MArrayHelper.GetIDs: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, l);
  i := 0;
  while (i <= (l - 4)) do
  begin
    Result[i] := i;
    Result[i + 1] := (i + 1);
    Result[i + 2] := (i + 2);
    Result[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  for i := i to (l - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <ID>
  @action: Returns indexes of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.ID(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, b, s: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  b := (Integer(not aAscending) * (l - 1));
  s := IfThen(aAscending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := (b + (s * i));
end;

{==============================================================================]
  <IDs>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.IDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i: Integer;
begin
  SetLength(Result, Self.Size);
  h := High(Self);
  case aAscending of
    True:
    for i := 0 to h do
      Result[i] := i;
    False:
    for i := h downto 0 do
      Result[h - i] := i;
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns items from arr by IDs.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, ID.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
  <IDs>
  @action: Returns arr with IDs replaced as item.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray; const item: MType): MArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
  <IDs>
  @action: Returns arr with IDs replaced as items.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray; const items: MArray): MArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  l := items.Length;
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
  <Indexed>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if Self.Populated then
  case aAscending of
    True:
    while (l.Decrement > -1) do
      Result[l] := l;
    False:
    while (l.Decrement > -1) do
      Result[(Self.Size - l) - 1] := l;
  end;
end;

{==============================================================================]
  <Indexes>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := IfThen(aAscending, i, ((l - i) - 1));
end;

{==============================================================================]
  <Indexing>
  @action: Returns an array of all valid indexes of the dynamic array.
           Supports ascending or descending order.
  @note:
    - Ascending: [0..Length(Self)-1]
    - Descending: [Length(Self)-1..0]
    - Uses efficient two-pointer approach for small/medium arrays.
    - Optional divide-and-conquer recursive variant can be used for huge arrays.
[==============================================================================}
function MArrayHelper.Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
procedure RI(var return: TIntegerArray; const L, R: Integer);
var
  M: Integer;
begin
  if (L > R) then
    Exit;
  if (L = R) then
  begin
    if aAscending then
      return[L] := L
    else
      return[L] := (High(return) - L);
    Exit;
  end;
  M := (L + ((R - L) div 2));
  RI(return, L, M);
  RI(return, (M + 1), R);
end;
begin
  SetLength(Result, Self.Size);
  if (Result.Size >  0) then
    RI(Result, 0, High(Self));
end;

{==============================================================================]
  <Indices>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
var
  r: TRange;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  r.Create(0, High(Self));
  case aAscending of
    True:
    repeat
      Result[r.start] := r.start;
      Result[r.stop] := r.stop;
    until (r.start.Increment > r.stop.Decrement);
    False:
    repeat
      Result[r.start] := r.stop;
      Result[r.stop] := r.start;
    until (r.start.Increment > r.stop.Decrement);
  end;
end;

{==============================================================================]
  <Indices>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indices(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, h: Integer;
begin
  l := Low(Self);
  h := High(Self);
  SetLength(Result, ((h - l) + 1));
  case aAscending of
    False:
    for i := l to h do
      Result[h - i] := i;
	True:
    for i := l to h do
      Result[i - l] := i;
  end;
end;

{==============================================================================]
  <LoadID>
  @action: Loads the target array with positional identifiers corresponding
           to the current array instance, optionally ordered ascending or
           descending.
  @note: • Returns Self.Length.
         • Ensures target.Length = Self.Length (resizes if required).
         • aAscending = True  →  [0, 1, 2, ..., Length - 1]
           aAscending = False →  [Length - 1, ..., 2, 1, 0]
         • Uses pointer-based sequential writes.
         • If Length = 0, target is resized to zero and 0 is returned.
         • Time complexity: O(n)
[==============================================================================}
function MArrayHelper.LoadID(var target: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  P: PInteger;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  P := @target[0];
  case aAscending of
    True:
    for i := 0 to (Result - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
	False:
	for i := (Result - 1) downto 0 do
    begin
      P^ := i;
      Inc(P);
    end;
  end;
end;

{==============================================================================]
  <LoadIDs>
  @action: Loads the target array with ascending positional identifiers
           (0..Length-1) corresponding to the current array instance.
  @note: • Returns Self.Length.
         • Ensures target.Length = Self.Length (resizes if required).
         • Writes sequential indices using pointer-based iteration.
         • If Length = 0, target is resized to zero and 0 is returned.
         • Time complexity: O(n)
[==============================================================================}
function MArrayHelper.LoadIDs(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
  P: PInteger;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  P := @target[0];
  for i := 0 to (Result - 1) do
  begin
    P^ := i;
    Inc(P);
  end;
end;

{==============================================================================]
  <LoadIndexes>
  @action: Loads the target array with ascending positional indexes
           (0..Length-1) corresponding to the current array instance.
  @note: • Returns Self.Length.
         • Ensures target.Length = Self.Length (resizes if required).
         • Uses direct indexed assignment.
         • Safe for zero-length arrays.
         • Time complexity: O(n)
[==============================================================================}
function MArrayHelper.LoadIndexes(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  for i := 0 to (Result - 1) do
    target[i] := i;
end;

{==============================================================================]
  <LoadIndices>
  @action: Loads the target array with ascending positional indices
           (0..Length-1) corresponding to the current array instance.
  @note: • Returns Self.Length.
         • Ensures target.Length = Self.Length (resizes if required).
         • Uses loop unrolling (×4) for reduced loop overhead and
           improved write throughput on large arrays.
         • Handles remaining elements via tail loop.
         • If Length = 0, target is resized to zero and 0 is returned.
         • Time complexity: O(n)
[==============================================================================}
function MArrayHelper.LoadIndices(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  i := 0;
  while (i <= (Result - 4)) do
  begin
    target[i] := i;
    target[i + 1] := (i + 1);
    target[i + 2] := (i + 2);
    target[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  while (i < Result) do
  begin
    target[i] := i;
    Inc(i);
  end;
end;

{==============================================================================]
  <Slots>
  @action: Returns indexes of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Slots: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to (Self.Size - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <ToIDs>
  @action: Generates an array of zero-based identifiers (IDs) representing the
           elements of the current array. Supports ascending (0..Length-1) or
           descending (Length-1..0) order via the `aAscending` parameter.
  @note:
    • Returns an empty array if the source array is empty.
    • Returns [0] if the array contains a single element.
    • Uses a simple arithmetic step with a `goto` loop for efficient
      population of the result array.
    • Time complexity: O(n), where n = Length(Self).
    • The resulting array contains all IDs in ascending or descending order.
[==============================================================================}
function MArrayHelper.ToIDs(const aAscending: Boolean = True): TIntegerArray; overload;
label
  filling;
var
  i, s, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, l);
  s := IfThen(aAscending, 1, -1);
  Result[0] := IfThen(aAscending, 0, (l - 1));
  i := 1;
  filling:
  Result[i] := (Result[i - 1] + s);
  if (i.Increment < l) then
    goto filling;
end;

{==============================================================================]
  <ToIndexes>
  @action: Returns indexes of array.
  @note: None.
[==============================================================================}
function MArrayHelper.ToIndexes: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Length);
  l := Low(Self);
  for i := l to High(Self) do
    Result[i - l] := i;
end;

{==============================================================================]
  <ToIndices>
  @action: Generates an array of zero-based indices representing the elements
           of the current array. The resulting sequence may be ascending
           (0..Length-1) or descending (Length-1..0) depending on `aAscending`.
  @note:
    • Returns an empty array if the source array is empty.
    • Returns [0] if the array contains a single element.
    • Populates the result in reverse storage order while controlling
      logical direction via a signed step value.
    • Uses `Increment` / `Decrement` helpers and a `goto` loop for
      compact, branch-minimal iteration.
    • Time complexity: O(n), where n = Length(Self).
    • The resulting array always contains a complete index set.
[==============================================================================}
function MArrayHelper.ToIndices(const aAscending: Boolean = True): TIntegerArray; overload;
label
  filling;
var
  i, s, h, r: Integer;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([0]);
  end;
  SetLength(Result, (h + 1));
  s := IfThen(aAscending, -1, 1);
  r := IfThen(aAscending, (h + 1), -1);
  filling:
  Result[h] := r.Increment(s);
  if (h.Decrement > -1) then
    goto filling;
end;
{$ENDIF}
