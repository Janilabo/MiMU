{==============================================================================]
 <2DTArray_Create> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}

// T2DIntegerArray
function T2DArray_Create(const size1D, size2D: Int32; const item: Int32): T2DIntegerArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DDoubleArray
function T2DArray_Create(const size1D, size2D: Int32; const item: Double): T2DDoubleArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DStringArray
function T2DArray_Create(const size1D, size2D: Int32; const item: string): T2DStringArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DCharArray
function T2DArray_Create(const size1D, size2D: Int32; const item: Char): T2DCharArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DBooleanArray
function T2DArray_Create(const size1D, size2D: Int32; const item: Boolean): T2DBooleanArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DPointArray
function T2DArray_Create(const size1D, size2D: Int32; const item: TPoint): T2DPointArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DBoxArray
function T2DArray_Create(const size1D, size2D: Int32; const item: TBox): T2DBoxArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

// T2DRangeArray
function T2DArray_Create(const size1D, size2D: Int32; const item: TRange): T2DRangeArray; overload; cdecl;
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;