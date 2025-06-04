{==============================================================================]
 <TArray_Create> 
 @action: Creates array with item, size as 1.
 @note: [item]
[==============================================================================}

// TIntegerArray
function TArray_Create(const item: Int32): TIntegerArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TDoubleArray
function TArray_Create(const item: Double): TDoubleArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TStringArray
function TArray_Create(const item: string): TStringArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TCharArray
function TArray_Create(const item: Char): TCharArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TBooleanArray
function TArray_Create(const item: Boolean): TBooleanArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TPointArray
function TArray_Create(const item: TPoint): TPointArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TBoxArray
function TArray_Create(const item: TBox): TBoxArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

// TRangeArray
function TArray_Create(const item: TRange): TRangeArray; overload; cdecl;
begin
  SetLength(Result, 1);
  Result[0] := item;
end;

{==============================================================================]
 <TArray_Create> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}

// TIntegerArray
function TArray_Create(const size: Int32; const item: Int32): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TDoubleArray
function TArray_Create(const size: Int32; const item: Double): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TStringArray
function TArray_Create(const size: Int32; const item: string): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TCharArray
function TArray_Create(const size: Int32; const item: Char): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TBooleanArray
function TArray_Create(const size: Int32; const item: Boolean): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TPointArray
function TArray_Create(const size: Int32; const item: TPoint): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TBoxArray
function TArray_Create(const size: Int32; const item: TBox): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

// TRangeArray
function TArray_Create(const size: Int32; const item: TRange): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;