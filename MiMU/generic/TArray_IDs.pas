{==============================================================================]
 <TArray_IDs>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_IDs(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TDoubleArray
function TArray_IDs(const arr: TDoubleArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TStringArray
function TArray_IDs(const arr: TStringArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TCharArray
function TArray_IDs(const arr: TCharArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TBooleanArray
function TArray_IDs(const arr: TBooleanArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TPointArray
function TArray_IDs(const arr: TPointArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TBoxArray
function TArray_IDs(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

// TRangeArray
function TArray_IDs(const arr: TRangeArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

{==============================================================================]
 <TArray_IDs>
 @action: Returns items from arr by IDs.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}

// TIntegerArray
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TDoubleArray
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TStringArray
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TCharArray
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TBooleanArray
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TPointArray
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TBoxArray
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

// TRangeArray
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;

{==============================================================================]
 <TArray_IDs>
 @action: Returns arr with IDs replaced as item.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}

// TIntegerArray
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TDoubleArray
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TStringArray
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;
 
// TCharArray
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TBooleanArray
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TPointArray
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TBoxArray
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

// TRangeArray
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;

{==============================================================================]
 <TArray_IDs>
 @action: Returns arr with IDs replaced as items.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}

// TIntegerArray
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TDoubleArray
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TStringArray
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;
 
// TCharArray
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TBooleanArray
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TPointArray
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TBoxArray
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;

// TRangeArray
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;
var
  i, l: Int32;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;