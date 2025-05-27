{==============================================================================]
 <TArray_Includes>
 @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
 @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}

// TIntegerArray
function TArray_Includes(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TDoubleArray
function TArray_Includes(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TStringArray
function TArray_Includes(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TCharArray
function TArray_Includes(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TBooleanArray
function TArray_Includes(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TPointArray
function TArray_Includes(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TBoxArray
function TArray_Includes(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;

// TRangeArray
function TArray_Includes(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := Min(High(arr), start) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;
