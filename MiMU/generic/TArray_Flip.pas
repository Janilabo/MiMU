{==============================================================================]
 <TArray_Flip>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}

// TIntegerArray
function TArray_Flip(var arr: TIntegerArray): Boolean; overload; cdecl;
var
  i, l, a: Int32;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TDoubleArray
function TArray_Flip(var arr: TDoubleArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: Double;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TStringArray
function TArray_Flip(var arr: TStringArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: string;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TCharArray
function TArray_Flip(var arr: TCharArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: Char;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TBooleanArray
function TArray_Flip(var arr: TBooleanArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: Boolean;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TPointArray
function TArray_Flip(var arr: TPointArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: TPoint;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TBoxArray
function TArray_Flip(var arr: TBoxArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: TBox;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;

// TRangeArray
function TArray_Flip(var arr: TRangeArray): Boolean; overload; cdecl;
var
  i, l: Int32;
  a: TRange;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    a := arr[i];
    arr[i] := arr[l];
    arr[l] := a;
    Inc(i);
    Dec(l);
  end;
end;
