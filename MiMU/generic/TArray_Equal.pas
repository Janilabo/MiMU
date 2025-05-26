{==============================================================================]
 <TArray_Equal>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Equal(const arr, target: TIntegerArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;

// TDoubleArray
function TArray_Equal(const arr, target: TDoubleArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;

// TStringArray
function TArray_Equal(const arr, target: TStringArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;

// TCharArray
function TArray_Equal(const arr, target: TCharArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;
 
// TBooleanArray
function TArray_Equal(const arr, target: TBooleanArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;

// TPointArray
function TArray_Equal(const arr, target: TPointArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if ((arr[i].X <> target[i].X) or (arr[i].Y <> target[i].Y)) then
      Exit(False);
end;

// TBoxArray
function TArray_Equal(const arr, target: TBoxArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if ((arr[i].X1 <> target[i].X1) or (arr[i].Y1 <> target[i].Y1) or (arr[i].X2 <> target[i].X2) or (arr[i].Y2 <> target[i].Y2)) then
      Exit(False);
end;

// TRangeArray
function TArray_Equal(const arr, target: TRangeArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if ((arr[i].start <> target[i].start) or (arr[i].stop <> target[i].stop)) then
      Exit(False);
end;
