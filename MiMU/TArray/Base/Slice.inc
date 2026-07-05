{$IFDEF HELPERS}
function Back(const N: Integer = 1): MArray; overload;
function Backery(const N: Integer = 1): MArray; overload;
function Backmost(const N: Integer = 1): MArray; overload;
function Backpart(const N: Integer = 1): MArray; overload;
function Backside(const N: Integer = 1; const R: MArray = nil): MArray; overload;
function Backsy(const N: Integer = 1): MArray; overload;
function Front(const N: Integer = 1): MArray; overload;
function Frontery(const N: Integer = 1): MArray; overload;
function Frontmost(const N: Integer = 1): MArray; overload;
function Frontside(const N: Integer = 1; const R: MArray = nil): MArray; overload;
function Frontpart(const N: Integer = 1): MArray; overload;
function Frontsy(const N: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Back>
  @action: Returns a new array containing the last N elements of the current array.
  @note: If N is greater than the array's length, the entire array is returned. 
         If N is less than or equal to 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Back(const N: Integer = 1): MArray; overload;
begin
  Result := System.Copy(Self, (Self.Length - Max(0, Min(N, Self.Length))), Self.Length);
end;

{==============================================================================]
  <Backery>
  @action: Extracts the last N elements from the end of the array and returns them in REVERSE order.
  @note: Like Frontery, this utilizes structural recursion with heavy array 
         slicing and prepending, making it O(N) in memory allocations and time complexity.
[==============================================================================}
function MArrayHelper.Backery(const N: Integer = 1): MArray; overload;
begin
  if ((N <= 0) or (Self.Length = 0)) then
    Exit(nil);
  Result := ([Self[Self.Length - Min(N, Self.Length)]] + System.Copy(Self, 1, Self.Length - 1).Backery(N - 1));
end;

{==============================================================================]
  <Backmost>
  @action: Returns a new array containing the last N elements of the current array, 
           manually resizing and copying the elements.
  @note: Automatically caps the output size to the source array's length. 
         If N is greater than the array's length, the entire array is returned.
         If N <= 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Backmost(const N: Integer = 1): MArray; overload;
var
  o, i: Integer;
begin
  o := (Self.Length - Result.SetSize(Max(0, Min(N, Self.Length))));
  for i := 0 to High(Result) do
    Result[i] := Self[o + i];
end;

{==============================================================================]
  <Backpart>
  @action: Returns the last N elements of Self, in original order.
  @note: Reverse scan (High downto 0) with an early Break once N elements
         are collected; prepends each matched element so original order
         is preserved despite the backward traversal.
[==============================================================================}
function MArrayHelper.Backpart(const N: Integer = 1): MArray; overload;
var
  r, i: Integer;
begin
  Result := nil;
  r := -1;
  for i := High(Self) downto 0 do
    if (r.Increment < N) then
      Result := ([Self[i]] + Result)
    else
      Break;
end;

{==============================================================================]
  <Backside>
  @action: Returns the last N elements of Self, in original order.
  @note: Tail-recursive with an accumulator (R) passed forward instead of
         built on return; shrinks Self from the back each call and
         prepends the trailing element to R so order is preserved.
[==============================================================================}
function MArrayHelper.Backside(const N: Integer = 1; const R: MArray = nil): MArray; overload;
begin
  if ((N <= 0) or (Self.Length = 0)) then
    Exit(R);
  Result := System.Copy(Self, 0, (Self.Length - 1)).Backside((N - 1), ([Self[Self.Length - 1]] + R));
end;

{==============================================================================]
  <Backsy>
  @action: Returns a new array containing the last N elements of the current array.
  @note: If N is greater than the array length, it safely returns the entire array. 
         If N is 0 or negative, it returns an empty array. Prevents out-of-bounds errors.
[==============================================================================}
function MArrayHelper.Backsy(const N: Integer = 1): MArray; overload;
var
  l, m: Integer;
begin
  l := Self.Length;
  m := Max(0, Min(N, l));
  Result := System.Copy(Self, (l - m), m);
end;

{==============================================================================]
  <Front>
  @action: Returns a new array containing the first N elements of the current array.
  @note: If N is greater than the array's length, the entire array is returned.
         If N is less than or equal to 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Front(const N: Integer = 1): MArray; overload;
begin
  Result := System.Copy(Self, 0, Max(0, N));
end;

{==============================================================================]
  <Frontery>
  @action: Extracts the first N elements from the start of the array and returns them in REVERSE order.
  @note: Highly inefficient for large arrays or large N due to O(N) recursive 
         array copying (System.Copy) and array concatenation (+) at each step.
[==============================================================================}
function MArrayHelper.Frontery(const N: Integer = 1): MArray; overload;
begin
  if ((N <= 0) or (Self.Length = 0)) then
    Exit(nil);
  Result := (System.Copy(Self, 0, Self.Length - 1).Frontery(N - 1) + [Self[Min(N, Self.Length) - 1]]);
end;

{==============================================================================]
  <Frontmost>
  @action: Returns a new array containing the first N elements of the current array,
           manually resizing and copying the elements.
  @note: Automatically caps the output size to the source array's length.
         If N is greater than the array's length, the entire array is returned.
         If N <= 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Frontmost(const N: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.SetSize(Max(0, Min(N, Self.Length))) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Frontpart>
  @action: Returns the first N elements of Self, in original order.
  @note: Forward scan with an early Break once N elements are collected;
         uses r.Increment (a TIntegerHelper method) as a running counter
         rather than a separate Inc(r) statement or loop-index comparison.
[==============================================================================}
function MArrayHelper.Frontpart(const N: Integer = 1): MArray; overload;
var
  r, i: Integer;
begin
  Result := nil;
  r := -1;
  for i := 0 to High(Self) do
    if (r.Increment < N) then
      Result := (Result + [Self[i]])
    else
      Break;
end;

{==============================================================================]
  <Frontside>
  @action: Returns the first N elements of Self, in original order.
  @note: Tail-recursive with an accumulator (R) passed forward instead of
         built on return; shrinks Self from the front each call and
         appends the leading element to R so order is preserved.
[==============================================================================}
function MArrayHelper.Frontside(const N: Integer = 1; const R: MArray = nil): MArray; overload;
begin
  if ((N <= 0) or (Self.Length = 0)) then
    Exit(R);
  Result := System.Copy(Self, 1, (Self.Length - 1)).Frontside((N - 1), (R + [Self[0]]));
end;

{==============================================================================]
  <Frontsy>
  @action: Returns a new array containing the first N elements of the current array.
  @note: If N is greater than the array length, it safely returns the entire array. 
         If N is 0 or negative, it returns an empty array. Prevents out-of-bounds errors
[==============================================================================}
function MArrayHelper.Frontsy(const N: Integer = 1): MArray; overload;
begin
  Result := Self;
  SetLength(Result, Max(0, Min(N, Self.Length)));
end;
{$ENDIF}
