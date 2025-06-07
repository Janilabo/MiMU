{==============================================================================]
 <TArray_Set>
 @action: Returns array arr filled with item to indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}

// TIntegerArray
function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end; 

// TDoubleArray
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TStringArray
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TCharArray
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TBooleanArray
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TPointArray
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TBoxArray
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TRangeArray
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

{==============================================================================]
 <TArray_Set>
 @action: Returns array arr filled with items to indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}

// TIntegerArray
function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TDoubleArray
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TStringArray
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TCharArray
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TBooleanArray
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TPointArray
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TBoxArray
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TRangeArray
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;
var
  i, l: Int32;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

{==============================================================================]
 <TArray_Set>
 @action: Returns array arr filled with items to starting from custom start index.
 @note: Unsafe method! No safety checking.
[==============================================================================}

// TIntegerArray
function TArray_Set(const arr: TIntegerArray; const index: Int32; const items: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TDoubleArray
function TArray_Set(const arr: TDoubleArray; const index: Int32; const items: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TStringArray
function TArray_Set(const arr: TStringArray; const index: Int32; const items: TStringArray): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TCharArray
function TArray_Set(const arr: TCharArray; const index: Int32; const items: TCharArray): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TBooleanArray
function TArray_Set(const arr: TBooleanArray; const index: Int32; const items: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TPointArray
function TArray_Set(const arr: TPointArray; const index: Int32; const items: TPointArray): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TBoxArray
function TArray_Set(const arr: TBoxArray; const index: Int32; const items: TBoxArray): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;

// TRangeArray
function TArray_Set(const arr: TRangeArray; const index: Int32; const items: TRangeArray): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;