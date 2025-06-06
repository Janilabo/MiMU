{==============================================================================]
 <TArray_Positions>
 @action: Returns index positions from arr which matched with item.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Positions(const arr: TIntegerArray; const item: Int32; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Positions(const arr: TDoubleArray; const item: Double; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Positions(const arr: TStringArray; const item: string; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Positions(const arr: TCharArray; const item: Char; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Positions(const arr: TBooleanArray; const item: Boolean; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Positions(const arr: TPointArray; const item: TPoint; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Positions(const arr: TBoxArray; const item: TBox; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Positions(const arr: TRangeArray; const item: TRange; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <TArray_Positions>
 @action: Returns index positions from arr which matches with items.
 @note: None.
[==============================================================================}

//TIntegerArray
function TArray_Positions(const arr: TIntegerArray; const items: TIntegerArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TDoubleArray
function TArray_Positions(const arr: TDoubleArray; const items: TDoubleArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TStringArray
function TArray_Positions(const arr: TStringArray; const items: TStringArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TCharArray
function TArray_Positions(const arr: TCharArray; const items: TCharArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TBooleanArray
function TArray_Positions(const arr: TBooleanArray; const items: TBooleanArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TPointArray
function TArray_Positions(const arr: TPointArray; const items: TPointArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TBoxArray
function TArray_Positions(const arr: TBoxArray; const items: TBoxArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;

//TRangeArray
function TArray_Positions(const arr: TRangeArray; const items: TRangeArray; const index: Int32 = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Int32;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;