{==============================================================================]
 <TArray_Uniques>
 @action: Returns the indexes of unique array (arr) items.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Uniques(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TDoubleArray
function TArray_Uniques(const arr: TDoubleArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TStringArray
function TArray_Uniques(const arr: TStringArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TCharArray
function TArray_Uniques(const arr: TCharArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TBooleanArray
function TArray_Uniques(const arr: TBooleanArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TPointArray
function TArray_Uniques(const arr: TPointArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and ((arr[x].X = arr[y].X) and (arr[x].Y = arr[y].Y)));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TBoxArray
function TArray_Uniques(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and ((arr[x].X1 = arr[y].X1) and (arr[x].Y1 = arr[y].Y1) and (arr[x].X2 = arr[y].X2) and (arr[x].Y2 = arr[y].Y2)));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

// TRangeArray
function TArray_Uniques(const arr: TRangeArray): TIntegerArray; overload; cdecl;
var
  h, r, x, y: Int32;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and ((arr[x].start = arr[y].start) and (arr[x].stop = arr[y].stop)));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;