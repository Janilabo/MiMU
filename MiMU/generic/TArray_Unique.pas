{==============================================================================]
 <TArray_Unique>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}

// TIntegerArray
function TArray_Unique(var arr: TIntegerArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TDoubleArray
function TArray_Unique(var arr: TDoubleArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TStringArray
function TArray_Unique(var arr: TStringArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TCharArray
function TArray_Unique(var arr: TCharArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TBooleanArray
function TArray_Unique(var arr: TBooleanArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TPointArray
function TArray_Unique(var arr: TPointArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := ((arr[i].X = arr[j].X) and (arr[i].Y = arr[j].Y));
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TBoxArray
function TArray_Unique(var arr: TBoxArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := ((arr[i].X1 = arr[j].X1) and (arr[i].Y1 = arr[j].Y1) and (arr[i].X2 = arr[j].X2) and (arr[i].Y2 = arr[j].Y2));
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;

// TRangeArray
function TArray_Unique(var arr: TRangeArray): Int32; overload; cdecl;
var
  a, l, i, j: Int32;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := ((arr[i].start = arr[j].start) and (arr[i].stop = arr[j].stop));
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;