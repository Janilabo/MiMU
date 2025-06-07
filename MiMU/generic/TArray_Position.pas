{==============================================================================]
 <TArray_Position>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}

// TIntegerArray
function TArray_Position(const arr: TIntegerArray; const item: Int32; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TDoubleArray
function TArray_Position(const arr: TDoubleArray; const item: Double; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TStringArray
function TArray_Position(const arr: TStringArray; const item: string; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TCharArray
function TArray_Position(const arr: TCharArray; const item: Char; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TBooleanArray
function TArray_Position(const arr: TBooleanArray; const item: Boolean; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TPointArray
function TArray_Position(const arr: TPointArray; const item: TPoint; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TBoxArray
function TArray_Position(const arr: TBoxArray; const item: TBox; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TRangeArray
function TArray_Position(const arr: TRangeArray; const item: TRange; const index: Int32 = 0): Int32; overload; cdecl;
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <TArray_Position>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}

//TIntegerArray
function TArray_Position(const arr: TIntegerArray; const items: TIntegerArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TDoubleArray
function TArray_Position(const arr: TDoubleArray; const items: TDoubleArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TStringArray
function TArray_Position(const arr: TStringArray; const items: TStringArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TCharArray
function TArray_Position(const arr: TCharArray; const items: TCharArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TBooleanArray
function TArray_Position(const arr: TBooleanArray; const items: TBooleanArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TPointArray
function TArray_Position(const arr: TPointArray; const items: TPointArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TBoxArray
function TArray_Position(const arr: TBoxArray; const items: TBoxArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TRangeArray
function TArray_Position(const arr: TRangeArray; const items: TRangeArray; const index: Int32 = 0): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;