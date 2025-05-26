{==============================================================================]
 <TArray_Contains>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Contains(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TDoubleArray
function TArray_Contains(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TStringArray
function TArray_Contains(const arr: TStringArray; const item: string; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TCharArray
function TArray_Contains(const arr: TCharArray; const item: Char; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TBooleanArray
function TArray_Contains(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TPointArray
function TArray_Contains(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if ((item.X = arr[i].X) and (item.Y = arr[i].Y)) then
      Exit(True);
  Result := False;
end;

// TBoxArray
function TArray_Contains(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if ((item.X1 = arr[i].X1) and (item.Y1 = arr[i].Y1) and (item.X2 = arr[i].X2) and (item.Y2 = arr[i].Y2)) then
      Exit(True);
  Result := False;
end;

// TRangeArray
function TArray_Contains(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := start to High(arr) do
    if ((item.start = arr[i].start) and (item.stop = arr[i].stop)) then
      Exit(True);
  Result := False;
end;
