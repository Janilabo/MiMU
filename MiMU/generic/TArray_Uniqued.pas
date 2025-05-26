{==============================================================================]
 <TArray_Uniqued>
 @action: Removes all duplicates from arr.
 @note: Returns the unique version of arr.
[==============================================================================}

// TIntegerArray
function TArray_Uniqued(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TDoubleArray
function TArray_Uniqued(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TStringArray
function TArray_Uniqued(const arr: TStringArray): TStringArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TCharArray
function TArray_Uniqued(const arr: TCharArray): TCharArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TBooleanArray
function TArray_Uniqued(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TPointArray
function TArray_Uniqued(const arr: TPointArray): TPointArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if ((arr[i].X <> Result[j].X) or (arr[i].Y <> Result[j].Y)) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TBoxArray
function TArray_Uniqued(const arr: TBoxArray): TBoxArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if ((arr[i].X1 <> Result[j].X1) or (arr[i].Y1 <> Result[j].Y1) or (arr[i].X2 <> Result[j].X2) or (arr[i].Y2 <> Result[j].Y2)) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;

// TRangeArray
function TArray_Uniqued(const arr: TRangeArray): TRangeArray; overload; cdecl;
var
  i, j, l, c: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if ((arr[i].start <> Result[j].start) or (arr[i].stop <> Result[j].stop)) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;