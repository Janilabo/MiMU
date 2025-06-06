{==============================================================================]
 <TArray_Copy>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}

// TIntegerArray
function TArray_Copy(const arr: TIntegerArray; const index: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TDoubleArray
function TArray_Copy(const arr: TDoubleArray; const index: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TStringArray
function TArray_Copy(const arr: TStringArray; const index: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TCharArray
function TArray_Copy(const arr: TCharArray; const index: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TBooleanArray
function TArray_Copy(const arr: TBooleanArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TPointArray
function TArray_Copy(const arr: TPointArray; const index: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TBoxArray
function TArray_Copy(const arr: TBoxArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

// TRangeArray
function TArray_Copy(const arr: TRangeArray; const index: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
begin
  Result := Copy(arr, index, count);  
end;

{==============================================================================]
 <TArray_Copy>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[==============================================================================}

// TIntegerArray
function TArray_Copy(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Copy(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Copy(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Copy(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Copy(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Copy(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Copy(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Copy(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;
var
  i, h, l, r: Int32;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;