{==============================================================================]
 <TArray_Clone>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}

// TIntegerArray
function TArray_Clone(const arr: TIntegerArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TDoubleArray
function TArray_Clone(const arr: TDoubleArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TStringArray
function TArray_Clone(const arr: TStringArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TCharArray
function TArray_Clone(const arr: TCharArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TBooleanArray
function TArray_Clone(const arr: TBooleanArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TPointArray
function TArray_Clone(const arr: TPointArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TBoxArray
function TArray_Clone(const arr: TBoxArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TRangeArray
function TArray_Clone(const arr: TRangeArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (startIndex < 0) then
      c := (startIndex + count)
    else
      c := Min(count, (Length(arr) - startIndex));
    s := Max(0, startIndex);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;