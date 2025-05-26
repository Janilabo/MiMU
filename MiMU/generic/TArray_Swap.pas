{==============================================================================]
 <TArray_Swap> 
 @action: Swaps array a and array b.
 @note: a will be b and b will be a.
[==============================================================================}

// TIntegerArray
function TArray_Swap(var a, b: TIntegerArray): Int32; overload; cdecl;
var
  c: TIntegerArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TDoubleArray
function TArray_Swap(var a, b: TDoubleArray): Int32; overload; cdecl;
var
  c: TDoubleArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TStringArray
function TArray_Swap(var a, b: TStringArray): Int32; overload; cdecl;
var
  c: TStringArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TCharArray
function TArray_Swap(var a, b: TCharArray): Int32; overload; cdecl;
var
  c: TCharArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TBooleanArray
function TArray_Swap(var a, b: TBooleanArray): Int32; overload; cdecl;
var
  c: TBooleanArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TPointArray
function TArray_Swap(var a, b: TPointArray): Int32; overload; cdecl;
var
  c: TPointArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TBoxArray
function TArray_Swap(var a, b: TBoxArray): Int32; overload; cdecl;
var
  c: TBoxArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;

// TRangeArray
function TArray_Swap(var a, b: TRangeArray): Int32; overload; cdecl;
var
  c: TRangeArray;
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end;