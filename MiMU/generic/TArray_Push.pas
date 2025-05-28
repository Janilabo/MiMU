{==============================================================================]
 <TArray_Push>
 @action: Places item in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}

// TIntegerArray
function TArray_Push(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TDoubleArray
function TArray_Push(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TStringArray
function TArray_Push(var arr: TStringArray; const item: string): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TCharArray
function TArray_Push(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TBooleanArray
function TArray_Push(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TPointArray
function TArray_Push(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TBoxArray
function TArray_Push(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

// TRangeArray
function TArray_Push(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;

{==============================================================================]
 <TArray_Push>
 @action: Places items in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}

// TIntegerArray
function TArray_Push(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TDoubleArray
function TArray_Push(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TStringArray
function TArray_Push(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TCharArray
function TArray_Push(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TBooleanArray
function TArray_Push(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TPointArray
function TArray_Push(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TBoxArray
function TArray_Push(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;

// TRangeArray
function TArray_Push(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;