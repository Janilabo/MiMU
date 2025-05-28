{==============================================================================]
 <T2DArray_Merge> 
 @action: Merges 2D array to 1D.
 @note: None.
[==============================================================================}

// T2DIntegerArray
function T2DArray_Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;  

// T2DDoubleArray
function T2DArray_Merge(const arr: T2DDoubleArray): TDoubleArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DStringArray
function T2DArray_Merge(const arr: T2DStringArray): TStringArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DCharArray
function T2DArray_Merge(const arr: T2DCharArray): TCharArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DBooleanArray
function T2DArray_Merge(const arr: T2DBooleanArray): TBooleanArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DPointArray
function T2DArray_Merge(const arr: T2DPointArray): TPointArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DBoxArray
function T2DArray_Merge(const arr: T2DBoxArray): TBoxArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;

// T2DRangeArray
function T2DArray_Merge(const arr: T2DRangeArray): TRangeArray; overload; cdecl;
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;