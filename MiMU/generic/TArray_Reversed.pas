{==============================================================================]
 <TArray_Reversed>
 @action: Returns reversed version of array arr.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Reversed(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TDoubleArray
function TArray_Reversed(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TStringArray
function TArray_Reversed(const arr: TStringArray): TStringArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TCharArray
function TArray_Reversed(const arr: TCharArray): TCharArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TBooleanArray
function TArray_Reversed(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TPointArray
function TArray_Reversed(const arr: TPointArray): TPointArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TBoxArray
function TArray_Reversed(const arr: TBoxArray): TBoxArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;

// TRangeArray
function TArray_Reversed(const arr: TRangeArray): TRangeArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;
