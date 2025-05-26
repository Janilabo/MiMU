{==============================================================================]
 <TArray_Push>
 @action: Places item in array with arr.
 @note: Returns placed index.
[==============================================================================}

// TIntegerArray
function TArray_Push(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TDoubleArray
function TArray_Push(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TStringArray
function TArray_Push(var arr: TStringArray; const item: string): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TCharArray
function TArray_Push(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TBooleanArray
function TArray_Push(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TPointArray
function TArray_Push(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TBoxArray
function TArray_Push(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TRangeArray
function TArray_Push(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;