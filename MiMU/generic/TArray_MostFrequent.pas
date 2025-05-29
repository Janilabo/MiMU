{==============================================================================]
 <TArray_MostFrequent> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_MostFrequent(const arr: TIntegerArray): Int32; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TDoubleArray
function TArray_MostFrequent(const arr: TDoubleArray): Double; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TStringArray
function TArray_MostFrequent(const arr: TStringArray): string; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TCharArray
function TArray_MostFrequent(const arr: TCharArray): Char; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TBooleanArray
function TArray_MostFrequent(const arr: TBooleanArray): Boolean; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TPointArray
function TArray_MostFrequent(const arr: TPointArray): TPoint; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TBoxArray
function TArray_MostFrequent(const arr: TBoxArray): TBox; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TRangeArray
function TArray_MostFrequent(const arr: TRangeArray): TRange; cdecl; overload;
var
  i, j, c, m: Int32;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;