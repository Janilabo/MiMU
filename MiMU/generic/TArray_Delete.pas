{==============================================================================]
 <TArray_Delete>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}

// TIntegerArray
function TArray_Delete(var arr: TIntegerArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TDoubleArray
function TArray_Delete(var arr: TDoubleArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TStringArray
function TArray_Delete(var arr: TStringArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TCharArray
function TArray_Delete(var arr: TCharArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TBooleanArray
function TArray_Delete(var arr: TBooleanArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TPointArray
function TArray_Delete(var arr: TPointArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TBoxArray
function TArray_Delete(var arr: TBoxArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

// TRangeArray
function TArray_Delete(var arr: TRangeArray; const index: Int32 = 0): Boolean; overload; cdecl;
var
  i, h: Int32;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;

{==============================================================================]
 <TArray_Delete>
 @action: Deletes array items from arr by indexes (IDs).
 @note: Returns amount of items that were deleted succesfully by IDs.
[==============================================================================}

// TIntegerArray
function TArray_Delete(var arr: TIntegerArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TDoubleArray
function TArray_Delete(var arr: TDoubleArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TStringArray
function TArray_Delete(var arr: TStringArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TCharArray
function TArray_Delete(var arr: TCharArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TBooleanArray
function TArray_Delete(var arr: TBooleanArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TPointArray
function TArray_Delete(var arr: TPointArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TBoxArray
function TArray_Delete(var arr: TBoxArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;

// TRangeArray
function TArray_Delete(var arr: TRangeArray; const IDs: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;