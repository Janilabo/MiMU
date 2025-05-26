{==============================================================================]
 <TArray_Add>
 @action: Appends arr with item. Returns the array with added item.
 @note: Adds item to the right side of the array.
[==============================================================================}

// TIntegerArray
function TArray_Add(const arr: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TDoubleArray
function TArray_Add(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TStringArray
function TArray_Add(const arr: TStringArray; const item: string): TStringArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TCharArray
function TArray_Add(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TBooleanArray
function TArray_Add(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TPointArray
function TArray_Add(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TBoxArray
function TArray_Add(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

// TRangeArray
function TArray_Add(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  Result[l] := item;
end;

{==============================================================================]
 <TArray_Add>
 @action: Appends arr with items. Returns the array with added items.
 @note: Adds item to the right side of the array.
[==============================================================================}

// TIntegerArray
function TArray_Add(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TDoubleArray
function TArray_Add(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TStringArray
function TArray_Add(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TCharArray
function TArray_Add(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TBooleanArray
function TArray_Add(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TPointArray
function TArray_Add(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TBoxArray
function TArray_Add(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;

// TRangeArray
function TArray_Add(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl;
var
  h, i, l: Int32;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  for i := 0 to h do
    Result[(l + i)] := items[i];
end;