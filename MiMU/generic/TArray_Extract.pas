{==============================================================================]
 <TArray_Extract>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 

// TIntegerArray
function TArray_Extract(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Extract(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Extract(const arr: TStringArray; const item: string; const start: Int32 = 0): TStringArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Extract(const arr: TCharArray; const item: Char; const start: Int32 = 0): TCharArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Extract(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Extract(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): TPointArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if ((arr[i].X = item.X) and (arr[i].Y = item.Y)) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Extract(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if ((arr[i].X1 = item.X1) and (arr[i].Y1 = item.Y1) and (arr[i].X2 = item.X2) and (arr[i].Y2 = item.Y2)) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end; 

// TRangeArray
function TArray_Extract(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  l := Length(arr);
  SetLength(Result, (l - start));
  r := 0;
  for i := start to (l - 1) do
    if ((arr[i].start = item.stop) and (arr[i].start = item.stop)) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TArray_Extract>
 @action: Keeps (extracts) all values in arr that are in items. Starts scan from start index.
 @note: Returns the items.
[==============================================================================}

// TIntegerArray
function TArray_Extract(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end; 

// TDoubleArray
function TArray_Extract(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): TDoubleArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Extract(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): TStringArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Extract(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): TCharArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Extract(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): TBooleanArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Extract(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): TPointArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Extract(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): TBoxArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Extract(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): TRangeArray; overload; cdecl;
var
  i, l, r: Int32;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(arr);
    SetLength(Result, (l - start));
    for i := start to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
