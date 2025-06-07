{==============================================================================]
 <TArray_FilterEvery>
 @action: Filters every/each X item from arr.
 @note: Custom index
[==============================================================================}

// TIntegerArray
function TArray_FilterEvery(const arr: TIntegerArray; const X: Int32 = 1; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TDoubleArray
function TArray_FilterEvery(const arr: TDoubleArray; const X: Int32 = 1; const index: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TStringArray
function TArray_FilterEvery(const arr: TStringArray; const X: Int32 = 1; const index: Int32 = 0): TStringArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TCharArray
function TArray_FilterEvery(const arr: TCharArray; const X: Int32 = 1; const index: Int32 = 0): TCharArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TBooleanArray
function TArray_FilterEvery(const arr: TBooleanArray; const X: Int32 = 1; const index: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TPointArray
function TArray_FilterEvery(const arr: TPointArray; const X: Int32 = 1; const index: Int32 = 0): TPointArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TBoxArray
function TArray_FilterEvery(const arr: TBoxArray; const X: Int32 = 1; const index: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TRangeArray
function TArray_FilterEvery(const arr: TRangeArray; const X: Int32 = 1; const index: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;