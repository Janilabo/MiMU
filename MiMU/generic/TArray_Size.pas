{==============================================================================]
 <TArray_Size>
 @action: Set's arr length to size.
 @note: size > Length(arr) => Result will give how many elements were added
        size < Length(arr) => Result will give how many elements got deleted (it will be negative value!)
		size = Length(arr) => Returns 0.

        begin
          WriteLn(TArray_Length(a, 1, 1), ': ', a); //1: [1]
          WriteLn(TArray_Length(a, 4, 2), ': ', a); //3: [1, 2, 2, 2]
          WriteLn(TArray_Length(a, 2, -1), ': ', a); //-2: [1, 2]
          WriteLn(TArray_Length(a, 3, 3), ': ', a);  //1: [1, 2, 3]
        end.		
[==============================================================================}

// TIntegerArray
function TArray_Size(var arr: TIntegerArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end; 

// TDoubleArray
function TArray_Size(var arr: TDoubleArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TStringArray
function TArray_Size(var arr: TStringArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TCharArray
function TArray_Size(var arr: TCharArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TBooleanArray
function TArray_Size(var arr: TBooleanArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TPointArray
function TArray_Size(var arr: TPointArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TBoxArray
function TArray_Size(var arr: TBoxArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

// TRangeArray
function TArray_Size(var arr: TRangeArray; const size: Int32): Int32; overload; cdecl;
var
  l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;

{==============================================================================]
 <TArray_Size>
 @action: Set's arr length to size.
 @note: Uses null for created indexes.
[==============================================================================}

// TIntegerArray
function TArray_Size(var arr: TIntegerArray; const size: Int32; const null: Int32): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TDoubleArray
function TArray_Size(var arr: TDoubleArray; const size: Int32; const null: Double): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TStringArray
function TArray_Size(var arr: TStringArray; const size: Int32; const null: string): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TCharArray
function TArray_Size(var arr: TCharArray; const size: Int32; const null: Char): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TBooleanArray
function TArray_Size(var arr: TBooleanArray; const size: Int32; const null: Boolean): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TPointArray
function TArray_Size(var arr: TPointArray; const size: Int32; const null: TPoint): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TBoxArray
function TArray_Size(var arr: TBoxArray; const size: Int32; const null: TBox): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

// TRangeArray
function TArray_Size(var arr: TRangeArray; const size: Int32; const null: TRange): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;

{==============================================================================]
 <TArray_Size>
 @action: Returns array length.
 @note: Just normal Length() for this last one, with single parameter.		
[==============================================================================}

// TIntegerArray
function TArray_Size(const arr: TIntegerArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end; 

// TDoubleArray
function TArray_Size(const arr: TDoubleArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TStringArray
function TArray_Size(const arr: TStringArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TCharArray
function TArray_Size(const arr: TCharArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TBooleanArray
function TArray_Size(const arr: TBooleanArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TPointArray
function TArray_Size(const arr: TPointArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TBoxArray
function TArray_Size(const arr: TBoxArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;

// TRangeArray
function TArray_Size(const arr: TRangeArray): Int32; overload; cdecl;
begin
  Result := Length(arr);
end;