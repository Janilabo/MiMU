{$IFDEF HELPERS}
function Addend(const N: Integer): Integer; overload;
function Addended(const N: Integer): TIntegerArray; overload;
function Deced(const N: Integer): TIntegerArray; overload;
function Decrem(const N: Integer = 1): Integer; overload;
function Decrementation(const N: Integer = 1): Integer; overload;
function Delend(const N: Integer): Integer; overload;
function Delended(const N: Integer): TIntegerArray; overload;
function Inced(const N: Integer): TIntegerArray; overload;
function Increm(const N: Integer = 1): Integer; overload;
function Incrementation(const N: Integer = 1): Integer; overload;
function Minus(const N: Integer = 1): TIntegerArray; overload;
function Plus(const N: Integer = 1): TIntegerArray; overload;
function Ramp(const rStep: Integer = 1; const rOffset: Integer = 0; const rMode: Integer = 0): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Addend>
  @action: Adds N to each element IN-PLACE.
  @note: Modifies the original array. Returns length for chaining.
  @example: [1,2,3].Addend(10) → [11,12,13]
[==============================================================================}
function TIntegerArrayHelper.Addend(const N: Integer): Integer; overload;
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
function TIntegerArrayHelper.Addended(const N: Integer): TIntegerArray; overload;
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
  @returns: New TIntegerArray where Result[i] = Self[i] - N
  @note:
    - Non-mutating: Original array is NOT modified
    - Past tense name indicates "already decremented" (result state)
    - This performs x - N, NOT N - x (see Delended for that)
    - Time complexity: O(n)
    - Memory: Allocates a new array of same length
[==============================================================================}
function TIntegerArrayHelper.Deced(const N: Integer): TIntegerArray; overload;
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
function TIntegerArrayHelper.Decrem(const N: Integer = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Dec(Self[i], N);
end;

{==============================================================================]
  <Decrementation>
  @action: Decrements every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function TIntegerArrayHelper.Decrementation(const N: Integer = 1): Integer; overload;
var
  p: PInteger;
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
function TIntegerArrayHelper.Delend(const N: Integer): Integer; overload;
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
function TIntegerArrayHelper.Delended(const N: Integer): TIntegerArray; overload;
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
  @returns: New TIntegerArray where Result[i] = Self[i] + N
  @note:
    - Non-mutating: Original array is NOT modified
    - Past tense name indicates "already incremented" (result state)
    - Time complexity: O(n)
    - Memory: Allocates a new array of same length
[==============================================================================}
function TIntegerArrayHelper.Inced(const N: Integer): TIntegerArray; overload;
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
function TIntegerArrayHelper.Increm(const N: Integer = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Inc(Self[i], N);
end;

{==============================================================================]
  <Incrementation>
  @action: Increments every element in the array by N.
  @returns: The number of elements modified (array length).
  @note: Modifies the array in-place. Returns length for chaining.
[==============================================================================}
function TIntegerArrayHelper.Incrementation(const N: Integer = 1): Integer; overload;
var
  p: PInteger;
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
  @action: Decrements every element in the array by a specified integer value.
  @note: Performs a linear transformation across the entire set. If N is not
         provided, it defaults to a decrement of 1.
[==============================================================================}
function TIntegerArrayHelper.Minus(const N: Integer = 1): TIntegerArray; overload;
var
  s, r: PInteger;
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
  @action: Increments every element in the array by a specified integer value.
  @note: Uses pointer arithmetic for high-performance iteration. Returns a new
         array without modifying the original (non-destructive).
[==============================================================================}
function TIntegerArrayHelper.Plus(const N: Integer = 1): TIntegerArray; overload;
var
  s, r: PInteger;
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
  @returns: New TIntegerArray with ramp operation applied.
  @note:
    **Modes:**
    - Mode 0 (Add):        Result[i] := Self[i] + current
    - Mode 1 (Subtract):   Result[i] := Self[i] - current
    - Mode 2 (Complement): Result[i] := current - Self[i]
    - Mode 3 (Add Twice):  Result[i] := current + Self[i]
[==============================================================================}
function TIntegerArrayHelper.Ramp(const rStep: Integer = 1; const rOffset: Integer = 0; const rMode: Integer = 0): TIntegerArray; overload;
var
  i, r: Integer;
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
