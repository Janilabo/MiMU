{$IFDEF HELPERS}
function Decrementation(const N: Integer = 1): Integer; overload;
function Addend(const N: Integer): Integer; overload;
function Addended(const N: Integer): TIntegerArray; overload;
function Delend(const N: Integer): Integer; overload;
function Delended(const N: Integer): TIntegerArray; overload;
function Incrementation(const N: Integer = 1): Integer; overload;
function Minus(const N: Integer = 1): TIntegerArray; overload;
function Plus(const N: Integer = 1): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := (N + Self[i]);
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
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := (N - Self[i]);
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
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  s := @Self[0];
  r := @Result[0];
  for i := 0 to (l - 1) do
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
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  s := @Self[0];
  r := @Result[0];
  for i := 0 to (l - 1) do
  begin
    r^ := (s^ + N);
    Inc(s);
    Inc(r);
  end;
end;
{$ENDIF}
