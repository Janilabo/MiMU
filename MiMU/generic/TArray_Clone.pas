{==============================================================================]
 <TArray_Clone>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}

// TIntegerArray
function TArray_Clone(const arr: TIntegerArray; const index: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TDoubleArray
function TArray_Clone(const arr: TDoubleArray; const index: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TStringArray
function TArray_Clone(const arr: TStringArray; const index: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TCharArray
function TArray_Clone(const arr: TCharArray; const index: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TBooleanArray
function TArray_Clone(const arr: TBooleanArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TPointArray
function TArray_Clone(const arr: TPointArray; const index: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TBoxArray
function TArray_Clone(const arr: TBoxArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;

// TRangeArray
function TArray_Clone(const arr: TRangeArray; const index: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  i, s, c: Int32;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;