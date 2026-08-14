{$IFDEF HELPERS}
function Addend(const N: MType): Integer; overload;
function Addended(const N: MType): MArray; overload;
function Deced(const N: MType): MArray; overload;
function Decrem(const N: MType = 1): Integer; overload;
function Decrementation(const N: MType = 1): Integer; overload;
function Delend(const N: MType): Integer; overload;
function Delended(const N: MType): MArray; overload;
function Inced(const N: MType): MArray; overload;
function Increm(const N: MType = 1): Integer; overload;
function Incrementation(const N: MType = 1): Integer; overload;
function Minus(const N: MType = 1): MArray; overload;
function Plus(const N: MType = 1): MArray; overload;
function Ramp(const rStep: MType = 1; const rOffset: MType = 0; const rMode: Integer = 0): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Addend>
  @action: Adds N to each element IN-PLACE.
  @note: Modifies the original array. Returns length for chaining.
  @example: [1,2,3].Addend(10) → [11,12,13]
[==============================================================================}
function MArrayHelper.Addend(const N: MType): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i] := (N + Self[i]);
end;

{==============================================================================]
  <Addended>
  @action: Returns NEW array with N added to each element.
  @note: Original array unchanged.
  @example: [1,2,3].Addended(10) → [11,12,13]
[==============================================================================}
function MArrayHelper.Addended(const N: MType): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (N + Self[i]);
end;

{==============================================================================]
  <Deced>
  @action: Returns a new array with each element decremented by N.
  @param N: Value to subtract from each element (default: none, must be specified)
  @returns: New array where Result[i] = Self[i] - N
  @note:
    - Non-mutating: Original array is NOT modified
    - Past tense name indicates "already decremented" (result state)
    - This performs x - N, NOT N - x (see Delended for that)
    - Time complexity: O(n)
    - Memory: Allocates a new array of same length
[==============================================================================}
function MArrayHelper.Deced(const N: MType): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (Self[i] - N);
end;

{==============================================================================]
  <Decrem>
  @action: Decrements every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function MArrayHelper.Decrem(const N: MType = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i] := (Self[i] - N);
end;

{==============================================================================]
  <Decrementation>
  @action: Decrements every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function MArrayHelper.Decrementation(const N: MType = 1): Integer; overload;
var
  p: MPointer;
  i: Integer;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  p := @Self[0];
  for i := 0 to (Result - 1) do
  begin
    p^ := (p^ - N);
    Inc(p);
  end;
end;

{==============================================================================]
  <Delend>
  @action: Subtracts each element FROM N IN-PLACE (N - x).
  @note: Modifies the original array. Returns length for chaining.
  @example: [1,2,3].Delend(10) → [9,8,7]
[==============================================================================}
function MArrayHelper.Delend(const N: MType): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i] := (N - Self[i]);
end;

{==============================================================================]
  <Delended>
  @action: Returns NEW array with each element = N - Self[i].
  @note: Original array unchanged.
  @example: [1,2,3].Delended(10) → [9,8,7]
[==============================================================================}
function MArrayHelper.Delended(const N: MType): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (N - Self[i]);
end;

{==============================================================================]
  <Inced>
  @action: Returns a new array with each element incremented by N.
  @param N: Value to add to each element (default: none, must be specified)
  @returns: New array where Result[i] = Self[i] + N
  @note:
    - Non-mutating: Original array is NOT modified
    - Past tense name indicates "already incremented" (result state)
    - Time complexity: O(n)
    - Memory: Allocates a new array of same length
[==============================================================================}
function MArrayHelper.Inced(const N: MType): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (Self[i] + N);
end;

{==============================================================================]
  <Increm>
  @action: Increments every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function MArrayHelper.Increm(const N: MType = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i] := (Self[i] + N);
end;

{==============================================================================]
  <Incrementation>
  @action: Increments every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function MArrayHelper.Incrementation(const N: MType = 1): Integer; overload;
var
  p: MPointer;
  i: Integer;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  p := @Self[0];
  for i := 0 to (Result - 1) do
  begin
    p^ := (p^ + N);
    Inc(p);
  end;
end;

{==============================================================================]
  <Minus>
  @action: Decrements every element in the array by a specified N value.
  @note: Performs a linear transformation across the entire set. If N is not
         provided, it defaults to a decrement of 1.
[==============================================================================}
function MArrayHelper.Minus(const N: MType = 1): MArray; overload;
var
  s, r: MPointer;
  i: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  s := @Self[0];
  r := @Result[0];
  for i := 0 to High(Result) do
  begin
    r^ := (s^ - N);
    Inc(s);
    Inc(r);
  end;
end;

{==============================================================================]
  <Plus>
  @action: Increments every element in the array by a specified N value.
  @note: Uses pointer arithmetic for high-performance iteration. Returns a new
         array without modifying the original (non-destructive).
[==============================================================================}
function MArrayHelper.Plus(const N: MType = 1): MArray; overload;
var
  s, r: MPointer;
  i: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  s := @Self[0];
  r := @Result[0];
  for i := 0 to High(Result) do
  begin
    r^ := (s^ + N);
    Inc(s);
    Inc(r);
  end;
end;

{==============================================================================]
  <Ramp>
  @action: Applies a progressive linear ramp operation to all array elements.
  @param rStep: Amount the offset increases by each position (default: 1)
  @param rOffset: Initial displacement added to the first step (default: 0)
  @param rMode: Operation mode (0-3, default: 0)
  @returns: New array with ramp operation applied.
  @note:
    **Modes:**
    - Mode 0 (Add):        Result[i] := Self[i] + current
    - Mode 1 (Subtract):   Result[i] := Self[i] - current
    - Mode 2 (Complement): Result[i] := current - Self[i]
    - Mode 3 (Add Twice):  Result[i] := current + Self[i]
[==============================================================================}
function MArrayHelper.Ramp(const rStep: MType = 1; const rOffset: MType = 0; const rMode: Integer = 0): MArray; overload;
var
  r: MType;
  i: Integer;
begin
  if not InRange(rMode, 0, 3) then
    Exit(Self.Copy);
  r := (rStep + rOffset);
  for i := 0 to Result.Alloc(Self.Length) do
  case rMode of
    0: Result[i] := (Self[i] + r.Increase(rStep));
    1: Result[i] := (Self[i] - r.Increase(rStep));
    2: Result[i] := (r.Increase(rStep) - Self[i]);
    3: Result[i] := (r.Increase(rStep) + Self[i]);
  end;
end; 
{$ENDIF}
