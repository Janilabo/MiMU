{==============================================================================]
 <TArray_LeastFrequent> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_LeastFrequent(const arr: TIntegerArray): Int32; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TDoubleArray
function TArray_LeastFrequent(const arr: TDoubleArray): Double; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TStringArray
function TArray_LeastFrequent(const arr: TStringArray): string; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TCharArray
function TArray_LeastFrequent(const arr: TCharArray): Char; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TBooleanArray
function TArray_LeastFrequent(const arr: TBooleanArray): Boolean; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TPointArray
function TArray_LeastFrequent(const arr: TPointArray): TPoint; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TBoxArray
function TArray_LeastFrequent(const arr: TBoxArray): TBox; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;

// TRangeArray
function TArray_LeastFrequent(const arr: TRangeArray): TRange; cdecl; overload;
var
  i, j, c, m: Int32;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;