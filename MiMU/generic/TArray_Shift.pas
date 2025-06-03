{==============================================================================]
 <TArray_Shift>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}

// TIntegerArray
function TArray_Shift(var arr: TIntegerArray): Int32; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TDoubleArray
function TArray_Shift(var arr: TDoubleArray): Double; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TStringArray
function TArray_Shift(var arr: TStringArray): string; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TCharArray
function TArray_Shift(var arr: TCharArray): Char; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TBooleanArray
function TArray_Shift(var arr: TBooleanArray): Boolean; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TPointArray
function TArray_Shift(var arr: TPointArray): TPoint; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TBoxArray
function TArray_Shift(var arr: TBoxArray): TBox; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

// TRangeArray
function TArray_Shift(var arr: TRangeArray): TRange; overload; cdecl;
var
  i, l: Int32;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;

{==============================================================================]
 <TArray_Shift>
 @action: Shortens the array with first SHIFT element(s).
 @note: Returns the removed arr[x]s.
[==============================================================================}

// TIntegerArray
function TArray_Shift(var arr: TIntegerArray; const shift: Int32): TIntegerArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TDoubleArray
function TArray_Shift(var arr: TDoubleArray; const shift: Int32): TDoubleArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TStringArray
function TArray_Shift(var arr: TStringArray; const shift: Int32): TStringArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TCharArray
function TArray_Shift(var arr: TCharArray; const shift: Int32): TCharArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TBooleanArray
function TArray_Shift(var arr: TBooleanArray; const shift: Int32): TBooleanArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TPointArray
function TArray_Shift(var arr: TPointArray; const shift: Int32): TPointArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TBoxArray
function TArray_Shift(var arr: TBoxArray; const shift: Int32): TBoxArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;

// TRangeArray
function TArray_Shift(var arr: TRangeArray; const shift: Int32): TRangeArray; overload; cdecl;
var
  i, l, s: Int32;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;