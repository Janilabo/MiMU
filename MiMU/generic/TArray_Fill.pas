{==============================================================================]
 <TArray_Fill>
 @action: Fills whole arr with item.
 @note: None
[==============================================================================}

// TIntegerArray
function TArray_Fill(const arr: TIntegerArray; const item: Int32; const index: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TDoubleArray; const item: Double; const index: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TStringArray; const item: string; const index: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TCharArray; const item: Char; const index: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TBooleanArray; const item: Boolean; const index: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TPointArray; const item: TPoint; const index: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TBoxArray; const item: TBox; const index: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TRangeArray; const item: TRange; const index: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  h, i, s, t: Int32;
begin
  s := Max(0, index);
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
function TArray_Fill(const arr: TIntegerArray; const items: TIntegerArray; const index: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TDoubleArray
function TArray_Fill(const arr: TDoubleArray; const items: TDoubleArray; const index: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TStringArray
function TArray_Fill(const arr: TStringArray; const items: TStringArray; const index: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TCharArray
function TArray_Fill(const arr: TCharArray; const items: TCharArray; const index: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBooleanArray
function TArray_Fill(const arr: TBooleanArray; const items: TBooleanArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TPointArray
function TArray_Fill(const arr: TPointArray; const items: TPointArray; const index: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TBoxArray
function TArray_Fill(const arr: TBoxArray; const items: TBoxArray; const index: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;

// TRangeArray
function TArray_Fill(const arr: TRangeArray; const items: TRangeArray; const index: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
var
  h, i, s, t, l: Int32;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;
