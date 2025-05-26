{==============================================================================]
 <TArray_PosLast>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}

// TIntegerArray
function TArray_PosLast(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TDoubleArray
function TArray_PosLast(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TStringArray
function TArray_PosLast(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TCharArray
function TArray_PosLast(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TBooleanArray
function TArray_PosLast(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;

// TPointArray
function TArray_PosLast(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if ((arr[Result].X = item.X) and (arr[Result].Y = item.Y)) then
      Exit;
  Result := -1;
end;

// TBoxArray
function TArray_PosLast(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if ((arr[Result].X1 = item.X1) and (arr[Result].Y1 = item.Y1) and (arr[Result].X2 = item.X2) and (arr[Result].Y2 = item.Y2)) then
      Exit;
  Result := -1;
end;

// TRangeArray
function TArray_PosLast(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): Int32; overload; cdecl;
begin
  for Result := Min(High(arr), start) downto 0 do
    if ((arr[Result].start = item.start) and (arr[Result].stop = item.stop)) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <TArray_Pos>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}

//TIntegerArray
function TArray_PosLast(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TDoubleArray
function TArray_PosLast(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TStringArray
function TArray_PosLast(const arr: TStringArray; const items: TStringArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TCharArray
function TArray_PosLast(const arr: TCharArray; const items: TCharArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TBooleanArray
function TArray_PosLast(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;

//TPointArray
function TArray_PosLast(const arr: TPointArray; const items: TPointArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if ((arr[Result].X = items[i].X) and (arr[Result].Y = items[i].Y)) then
        Exit;
  Result := -1;
end;

//TBoxArray
function TArray_PosLast(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if ((arr[Result].X1 = items[i].X1) and (arr[Result].Y1 = items[i].Y1) and (arr[Result].X2 = items[i].X2) and (arr[Result].Y2 = items[i].Y2)) then
        Exit;
  Result := -1;
end;

//TRangeArray
function TArray_PosLast(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
var
  h, i: Int32;
begin
  h := High(items);
  for Result := Min(High(arr), start) downto 0 do
    for i := 0 to h do
      if ((arr[Result].start = items[i].start) and (arr[Result].stop = items[i].stop)) then
        Exit;
  Result := -1;
end;