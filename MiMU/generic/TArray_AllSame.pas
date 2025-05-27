{==============================================================================]
 <TArray_AllSame>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_AllSame(const arr: TIntegerArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end; 

// TDoubleArray
function TArray_AllSame(const arr: TDoubleArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;

// TStringArray
function TArray_AllSame(const arr: TStringArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;

// TCharArray
function TArray_AllSame(const arr: TCharArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;
 
// TBooleanArray
function TArray_AllSame(const arr: TBooleanArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;

// TPointArray
function TArray_AllSame(const arr: TPointArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;

// TBoxArray
function TArray_AllSame(const arr: TBoxArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;

// TRangeArray
function TArray_AllSame(const arr: TRangeArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;
