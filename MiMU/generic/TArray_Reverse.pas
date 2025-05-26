{==============================================================================]
 <TArray_Reverse>
 @action: Reverses items in array.
 @note: Returns true with success (array contains 2 or more items)
[==============================================================================}

// TIntegerArray
function TArray_Reverse(var arr: TIntegerArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TDoubleArray
function TArray_Reverse(var arr: TDoubleArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TStringArray
function TArray_Reverse(var arr: TStringArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TCharArray
function TArray_Reverse(var arr: TCharArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TBooleanArray
function TArray_Reverse(var arr: TBooleanArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TPointArray
function TArray_Reverse(var arr: TPointArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TBoxArray
function TArray_Reverse(var arr: TBoxArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;

// TRangeArray
function TArray_Reverse(var arr: TRangeArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;
