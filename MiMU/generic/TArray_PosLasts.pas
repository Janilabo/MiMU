{==============================================================================]
 <TArray_PosLasts>
 @action: Returns last index positions from arr which matched with item.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_PosLasts(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_PosLasts(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_PosLasts(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_PosLasts(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_PosLasts(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_PosLasts(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if ((arr[i].X = item.X) and (arr[i].Y = item.Y)) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_PosLasts(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if ((arr[i].X1 = item.X1) and (arr[i].Y1 = item.Y1) and (arr[i].X2 = item.X2) and (arr[i].Y2 = item.Y2)) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_PosLasts(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if ((arr[i].start = item.start) and (arr[i].stop = item.stop)) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TArray_PosLasts>
 @action: Returns last index positions from arr which matches with items.
 @note: None.
[==============================================================================}

//TIntegerArray
function TArray_PosLasts(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TDoubleArray
function TArray_PosLasts(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TStringArray
function TArray_PosLasts(const arr: TStringArray; const items: TStringArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TCharArray
function TArray_PosLasts(const arr: TCharArray; const items: TCharArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TBooleanArray
function TArray_PosLasts(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TPointArray
function TArray_PosLasts(const arr: TPointArray; const items: TPointArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TBoxArray
function TArray_PosLasts(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TRangeArray
function TArray_PosLasts(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Min(start, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;