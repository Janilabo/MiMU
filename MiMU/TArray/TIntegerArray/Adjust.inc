{$IFDEF HELPERS}
function Decrementation(const N: Integer = 1): Integer; overload;
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
