{==============================================================================]
 <TArray_Extract>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 

// TIntegerArray
function TArray_ExtractEvery(const arr: TIntegerArray; const X: Int32 = 1; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TDoubleArray
function TArray_ExtractEvery(const arr: TDoubleArray; const X: Int32 = 1; const index: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TStringArray
function TArray_ExtractEvery(const arr: TStringArray; const X: Int32 = 1; const index: Int32 = 0): TStringArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TCharArray
function TArray_ExtractEvery(const arr: TCharArray; const X: Int32 = 1; const index: Int32 = 0): TCharArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TBooleanArray
function TArray_ExtractEvery(const arr: TBooleanArray; const X: Int32 = 1; const index: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TPointArray
function TArray_ExtractEvery(const arr: TPointArray; const X: Int32 = 1; const index: Int32 = 0): TPointArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TBoxArray
function TArray_ExtractEvery(const arr: TBoxArray; const X: Int32 = 1; const index: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;

// TRangeArray
function TArray_ExtractEvery(const arr: TRangeArray; const X: Int32 = 1; const index: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, h, l: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;