{==============================================================================]
 <TArray_Filter>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Filter(const arr: TIntegerArray; const item: Int32; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Filter(const arr: TDoubleArray; const item: Double; const index: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Filter(const arr: TStringArray; const item: string; const index: Int32 = 0): TStringArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Filter(const arr: TCharArray; const item: Char; const index: Int32 = 0): TCharArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Filter(const arr: TBooleanArray; const item: Boolean; const index: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Filter(const arr: TPointArray; const item: TPoint; const index: Int32 = 0): TPointArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Filter(const arr: TBoxArray; const item: TBox; const index: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Filter(const arr: TRangeArray; const item: TRange; const index: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TArray_Filter>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Filter(const arr: TIntegerArray; const items: TIntegerArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Filter(const arr: TDoubleArray; const items: TDoubleArray; const index: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Filter(const arr: TStringArray; const items: TStringArray; const index: Int32 = 0): TStringArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Filter(const arr: TCharArray; const items: TCharArray; const index: Int32 = 0): TCharArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Filter(const arr: TBooleanArray; const items: TBooleanArray; const index: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Filter(const arr: TPointArray; const items: TPointArray; const index: Int32 = 0): TPointArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Filter(const arr: TBoxArray; const items: TBoxArray; const index: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Filter(const arr: TRangeArray; const items: TRangeArray; const index: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;