{==============================================================================]
 <TArray_AllEqual>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_AllEqual(const arr: TIntegerArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end; 

// TDoubleArray
function TArray_AllEqual(const arr: TDoubleArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end;

// TStringArray
function TArray_AllEqual(const arr: TStringArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end;

// TCharArray
function TArray_AllEqual(const arr: TCharArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end;
 
// TBooleanArray
function TArray_AllEqual(const arr: TBooleanArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end;

// TPointArray
function TArray_AllEqual(const arr: TPointArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if ((arr[l].X <> arr[i].X) or (arr[l].Y <> arr[i].Y)) then
      Exit(False);
  Result := (Length(arr) > 0);
end;

// TBoxArray
function TArray_AllEqual(const arr: TBoxArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if ((arr[l].X1 <> arr[i].X1) or (arr[l].Y1 <> arr[i].Y1) or (arr[l].X2 <> arr[i].X2) or (arr[l].Y2 <> arr[i].Y2)) then
      Exit(False);
  Result := (Length(arr) > 0);
end;

// TRangeArray
function TArray_AllEqual(const arr: TRangeArray): Boolean; overload; cdecl;
var
  h, i, l: Int32;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if ((arr[l].start <> arr[i].start) or (arr[l].stop <> arr[i].stop)) then
      Exit(False);
  Result := (Length(arr) > 0);
end;
