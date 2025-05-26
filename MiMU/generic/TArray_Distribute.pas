{==============================================================================]
 <TArray_Distribute>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
[==============================================================================}

// TIntegerArray
function TArray_Distribute(const arr: TIntegerArray; const parts: Int32): T2DIntegerArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TDoubleArray
function TArray_Distribute(const arr: TDoubleArray; const parts: Int32): T2DDoubleArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TStringArray
function TArray_Distribute(const arr: TStringArray; const parts: Int32): T2DStringArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TCharArray
function TArray_Distribute(const arr: TCharArray; const parts: Int32): T2DCharArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TBooleanArray
function TArray_Distribute(const arr: TBooleanArray; const parts: Int32): T2DBooleanArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TPointArray
function TArray_Distribute(const arr: TPointArray; const parts: Int32): T2DPointArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TBoxArray
function TArray_Distribute(const arr: TBoxArray; const parts: Int32): T2DBoxArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

// TRangeArray
function TArray_Distribute(const arr: TRangeArray; const parts: Int32): T2DRangeArray; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;
