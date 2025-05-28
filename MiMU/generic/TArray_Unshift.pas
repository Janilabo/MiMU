{==============================================================================]
 <TArray_Unshift>
 @action: Grows arr with item. Returns the index of added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}

// TIntegerArray
function TArray_Unshift(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TDoubleArray
function TArray_Unshift(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TStringArray
function TArray_Unshift(var arr: TStringArray; const item: string): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TCharArray
function TArray_Unshift(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TBooleanArray
function TArray_Unshift(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TPointArray
function TArray_Unshift(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TBoxArray
function TArray_Unshift(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

// TRangeArray
function TArray_Unshift(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
var
  i: Int32;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;

{==============================================================================]
 <TArray_Unshift>
 @action: Grows arr with items. Returns the index of last added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}

// TIntegerArray
function TArray_Unshift(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
var
  h, l, i: Int32;
begin
  h := High(items);
  if (h = -1) then
    Exit(High(arr));
  l := Length(arr);
  Result := (l + h);
  SetLength(arr, (Result + 1));
  for i := Result downto (h + 1) do
    arr[i] := arr[(i - (h + 1))];
  for i := 0 to h do
    arr[i] := items[i];
end;

// TDoubleArray
function TArray_Unshift(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
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
function TArray_Unshift(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;
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
