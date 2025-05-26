{==============================================================================]
 <TArray_Group>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}

// TIntegerArray
function TArray_Group(const arr: TIntegerArray): T2DIntegerArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TDoubleArray
function TArray_Group(const arr: TDoubleArray): T2DDoubleArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TStringArray
function TArray_Group(const arr: TStringArray): T2DStringArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TCharArray
function TArray_Group(const arr: TCharArray): T2DCharArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TBooleanArray
function TArray_Group(const arr: TBooleanArray): T2DBooleanArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TPointArray
function TArray_Group(const arr: TPointArray): T2DPointArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := ((arr[i].X = Result[r][0].X) and (arr[i].Y = Result[r][0].Y));
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TBoxArray
function TArray_Group(const arr: TBoxArray): T2DBoxArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := ((arr[i].X1 = Result[r][0].X1) and (arr[i].Y1 = Result[r][0].Y1) and (arr[i].X2 = Result[r][0].X2) and (arr[i].Y2 = Result[r][0].Y2));
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

// TRangeArray
function TArray_Group(const arr: TRangeArray): T2DRangeArray; overload; cdecl;
var
  a, h, i, r, g, l: Int32;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := ((arr[i].start = Result[r][0].start) and (arr[i].stop = Result[r][0].stop));
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;
