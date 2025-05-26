{==============================================================================]
 <TArray_Pick>
 @action: Outputs items with indexes (IDs) from arr and deletes while picking em.
 @note: Ignores invalid ID's (doesn't include those to output, they will be left out).
        DYNAMIC - you might need to set indexes in reversed order, in order to get em correctly!
[==============================================================================}

// TIntegerArray
function TArray_Pick(var arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TDoubleArray
function TArray_Pick(var arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TStringArray
function TArray_Pick(var arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TCharArray
function TArray_Pick(var arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TBooleanArray
function TArray_Pick(var arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TPointArray
function TArray_Pick(var arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TBoxArray
function TArray_Pick(var arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;

// TRangeArray
function TArray_Pick(var arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;
var
  l, h, t, i, r: Int32;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;