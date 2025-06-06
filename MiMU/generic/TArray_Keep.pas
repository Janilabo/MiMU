{==============================================================================]
 <TArray_Keep>
 @action: Keeps items in array, removes others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}

// TIntegerArray
function TArray_Keep(var arr: TIntegerArray; const items: TIntegerArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TDoubleArray
function TArray_Keep(var arr: TDoubleArray; const items: TDoubleArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TStringArray
function TArray_Keep(var arr: TStringArray; const items: TStringArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TCharArray
function TArray_Keep(var arr: TCharArray; const items: TCharArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TBooleanArray
function TArray_Keep(var arr: TBooleanArray; const items: TBooleanArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TPointArray
function TArray_Keep(var arr: TPointArray; const items: TPointArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TBoxArray
function TArray_Keep(var arr: TBoxArray; const items: TBoxArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;

// TRangeArray
function TArray_Keep(var arr: TRangeArray; const items: TRangeArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;
