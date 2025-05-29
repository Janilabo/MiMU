{==============================================================================]
 <T2DArray_Length> 
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}

// T2DIntegerArray
function T2DArray_Length(const arr: T2DIntegerArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DDoubleArray
function T2DArray_Length(const arr: T2DDoubleArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DStringArray
function T2DArray_Length(const arr: T2DStringArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DCharArray
function T2DArray_Length(const arr: T2DCharArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DBooleanArray
function T2DArray_Length(const arr: T2DBooleanArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DPointArray
function T2DArray_Length(const arr: T2DPointArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DBoxArray
function T2DArray_Length(const arr: T2DBoxArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

// T2DRangeArray
function T2DArray_Length(const arr: T2DRangeArray; var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;

{==============================================================================]
 <T2DArray_Length> 
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}

// T2DIntegerArray
function T2DArray_Length(const arr: T2DIntegerArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DDoubleArray
function T2DArray_Length(const arr: T2DDoubleArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DStringArray
function T2DArray_Length(const arr: T2DStringArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DCharArray
function T2DArray_Length(const arr: T2DCharArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DBooleanArray
function T2DArray_Length(const arr: T2DBooleanArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DPointArray
function T2DArray_Length(const arr: T2DPointArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DBoxArray
function T2DArray_Length(const arr: T2DBoxArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;

// T2DRangeArray
function T2DArray_Length(const arr: T2DRangeArray): Int64; overload; cdecl;
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;