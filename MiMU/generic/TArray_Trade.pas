{==============================================================================]
 <TArray_Trade> 
 @action: Swaps array a and array b.
 @note: a will be b and b will be a.
[==============================================================================}

// TIntegerArray
function TArray_Trade(var a, b: TIntegerArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TIntegerArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TDoubleArray
function TArray_Trade(var a, b: TDoubleArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TDoubleArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TStringArray
function TArray_Trade(var a, b: TStringArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TStringArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TCharArray
function TArray_Trade(var a, b: TCharArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TCharArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TBooleanArray
function TArray_Trade(var a, b: TBooleanArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TBooleanArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TPointArray
function TArray_Trade(var a, b: TPointArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TPointArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TBoxArray
function TArray_Trade(var a, b: TBoxArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TBoxArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;

// TRangeArray
function TArray_Trade(var a, b: TRangeArray): Int32; overload; cdecl;
var
  x, y: Int32;
  c: TRangeArray;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;