{$IFDEF HELPERS}
function Back(const N: Integer = 1): MArray; overload;
function Backmost(const N: Integer = 1): MArray; overload;
function Front(const N: Integer = 1): MArray; overload;
function Frontmost(const N: Integer = 1): MArray; overload;
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
  Result := System.Copy(Self, (Self.Length - Max(0, N)), Self.Length);
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
{$ENDIF}
