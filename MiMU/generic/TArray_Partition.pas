{==============================================================================]
 <TArray_Partition>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}

// TIntegerArray
function TArray_Partition(const arr: TIntegerArray; const size: Int32): T2DIntegerArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TDoubleArray
function TArray_Partition(const arr: TDoubleArray; const size: Int32): T2DDoubleArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TStringArray
function TArray_Partition(const arr: TStringArray; const size: Int32): T2DStringArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TCharArray
function TArray_Partition(const arr: TCharArray; const size: Int32): T2DCharArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TBooleanArray
function TArray_Partition(const arr: TBooleanArray; const size: Int32): T2DBooleanArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TPointArray
function TArray_Partition(const arr: TPointArray; const size: Int32): T2DPointArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TBoxArray
function TArray_Partition(const arr: TBoxArray; const size: Int32): T2DBoxArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;

// TRangeArray
function TArray_Partition(const arr: TRangeArray; const size: Int32): T2DRangeArray; overload; cdecl;
var
  p, i, j, s, r, l: Int32;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;
