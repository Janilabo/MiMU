{==============================================================================]
 <TArray_Fill>
 @action: Fills whole arr with item.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Fill(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TDoubleArray
function TArray_Fill(const arr: TDoubleArray; const item: Double; const start: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TStringArray
function TArray_Fill(const arr: TStringArray; const item: string; const start: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TCharArray
function TArray_Fill(const arr: TCharArray; const item: Char; const start: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBooleanArray
function TArray_Fill(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TPointArray
function TArray_Fill(const arr: TPointArray; const item: TPoint; const start: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBoxArray
function TArray_Fill(const arr: TBoxArray; const item: TBox; const start: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TRangeArray
function TArray_Fill(const arr: TRangeArray; const item: TRange; const start: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, start);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

{==============================================================================]
 <TArray_Fill>
 @action: Fills whole arr with items.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Fill(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TDoubleArray
function TArray_Fill(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TStringArray
function TArray_Fill(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TCharArray
function TArray_Fill(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBooleanArray
function TArray_Fill(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TPointArray
function TArray_Fill(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBoxArray
function TArray_Fill(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TRangeArray
function TArray_Fill(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], start, count));
  end;
  s := Max(0, start);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((start + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;
