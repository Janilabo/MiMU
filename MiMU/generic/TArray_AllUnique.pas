{==============================================================================]
 <TArray_AllUnique>
 @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_AllUnique(const arr: TIntegerArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;

// TDoubleArray
function TArray_AllUnique(const arr: TDoubleArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;

// TStringArray
function TArray_AllUnique(const arr: TStringArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;

// TCharArray
function TArray_AllUnique(const arr: TCharArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;
 
// TBooleanArray
function TArray_AllUnique(const arr: TBooleanArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;

// TPointArray
function TArray_AllUnique(const arr: TPointArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if ((arr[a].X = arr[b].X) and (arr[a].Y = arr[b].Y)) then
        Exit(False);
  Result := (h > -1);
end;

// TBoxArray
function TArray_AllUnique(const arr: TBoxArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if ((arr[a].X1 = arr[b].X1) and (arr[a].Y1 = arr[b].Y1) and (arr[a].X1 = arr[b].X1) and (arr[a].Y1 = arr[b].Y1)) then
        Exit(False);
  Result := (h > -1);
end;

// TRangeArray
function TArray_AllUnique(const arr: TRangeArray): Boolean; overload; cdecl;
var
  h, a, b: Int32;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if ((arr[a].start = arr[b].start) and (arr[a].stop = arr[b].stop)) then
        Exit(False);
  Result := (h > -1);
end;
