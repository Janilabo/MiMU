{==============================================================================]
 <TArray_Append>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}

// TIntegerArray
function TArray_Append(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TDoubleArray
function TArray_Append(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TStringArray
function TArray_Append(var arr: TStringArray; const item: string): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TCharArray
function TArray_Append(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TBooleanArray
function TArray_Append(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TPointArray
function TArray_Append(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TBoxArray
function TArray_Append(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

// TRangeArray
function TArray_Append(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;

{==============================================================================]
 <TArray_Append>
 @action: Adds all items items to arr.
 @note: Returns the highest index in the end.
[==============================================================================}

// TIntegerArray
function TArray_Append(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TDoubleArray
function TArray_Append(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TStringArray
function TArray_Append(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TCharArray
function TArray_Append(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TBooleanArray
function TArray_Append(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TPointArray
function TArray_Append(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TBoxArray
function TArray_Append(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;

// TRangeArray
function TArray_Append(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  Result := (Length(arr) + h);
  if (h = -1) then
    Exit;
  SetLength(arr, (Result + 1));
  for i := 0 to h do
    arr[(Result - i)] := items[(h - i)];
end;
