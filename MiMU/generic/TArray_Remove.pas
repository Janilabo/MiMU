{==============================================================================]
 <TArray_Remove>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start position.
[==============================================================================}

// TIntegerArray
function TArray_Remove(var arr: TIntegerArray; const item: Int32; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TIntegerArray; const item: Int32; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TDoubleArray
function TArray_Remove(var arr: TDoubleArray; const item: Double; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TDoubleArray; const item: Double; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TStringArray
function TArray_Remove(var arr: TStringArray; const item: string; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TStringArray; const item: string; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TCharArray
function TArray_Remove(var arr: TCharArray; const item: Char; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TCharArray; const item: Char; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TBooleanArray
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TPointArray
function TArray_Remove(var arr: TPointArray; const item: TPoint; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TPointArray; const item: TPoint; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TBoxArray
function TArray_Remove(var arr: TBoxArray; const item: TBox; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TBoxArray; const item: TBox; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

// TRangeArray
function TArray_Remove(var arr: TRangeArray; const item: TRange; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  l, i, r, m: Int32;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (start >= l)) then
    Exit(0);
  m := Max(0, start);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TRangeArray; const item: TRange; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, item, 0, all);
end;

{==============================================================================]
 <TArray_Remove>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start position.
[==============================================================================}

// TIntegerArray
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TDoubleArray
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TStringArray
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TStringArray; const items: TStringArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TCharArray
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TCharArray; const items: TCharArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TBooleanArray
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TPointArray
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TPointArray; const items: TPointArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TBoxArray
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;

// TRangeArray
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
var
  a, b, l, i, r, m: Int32;
  d, s: Boolean;
begin
  l := Length(arr);
  b := High(items);
  if ((l = 0) or (start >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, start);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;

function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const all: Boolean): Int32; overload; cdecl;
begin
  Result := TArray_Remove(arr, items, 0, all);
end;