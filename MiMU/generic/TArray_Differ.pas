{==============================================================================]
 <TArray_Differ>
 @action: Returns true if arr differs from target.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Differ(const arr, target: TIntegerArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TDoubleArray
function TArray_Differ(const arr, target: TDoubleArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TStringArray
function TArray_Differ(const arr, target: TStringArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TCharArray
function TArray_Differ(const arr, target: TCharArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;
 
// TBooleanArray
function TArray_Differ(const arr, target: TBooleanArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TPointArray
function TArray_Differ(const arr, target: TPointArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TBoxArray
function TArray_Differ(const arr, target: TBoxArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;

// TRangeArray
function TArray_Differ(const arr, target: TRangeArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;
