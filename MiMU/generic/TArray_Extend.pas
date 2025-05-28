{==============================================================================]
 <TArray_Extend>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}

// TIntegerArray
function TArray_Extend(const arr: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TDoubleArray
function TArray_Extend(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TStringArray
function TArray_Extend(const arr: TStringArray; const item: string): TStringArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TCharArray
function TArray_Extend(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TBooleanArray
function TArray_Extend(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TPointArray
function TArray_Extend(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

// TBoxArray
function TArray_Extend(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;
// TRangeArray
function TArray_Extend(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;

{==============================================================================]
 <TArray_Extend>
 @action: Extends arr with items. Returns it.
 @note: Places items to the left side of the array.
[==============================================================================}

// TIntegerArray
function TArray_Extend(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TDoubleArray
function TArray_Extend(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TStringArray
function TArray_Extend(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TCharArray
function TArray_Extend(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TBooleanArray
function TArray_Extend(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TPointArray
function TArray_Extend(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TBoxArray
function TArray_Extend(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

// TRangeArray
function TArray_Extend(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;
