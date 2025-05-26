{==============================================================================]
 <TArray_Get>
 @action: Copy of an array arr.
 @note: Just an alternative.
[==============================================================================}

// TIntegerArray
function TArray_Get(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TDoubleArray
function TArray_Get(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TStringArray
function TArray_Get(const arr: TStringArray): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TCharArray
function TArray_Get(const arr: TCharArray): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TBooleanArray
function TArray_Get(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TPointArray
function TArray_Get(const arr: TPointArray): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TBoxArray
function TArray_Get(const arr: TBoxArray): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

// TRangeArray
function TArray_Get(const arr: TRangeArray): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;

{==============================================================================]
 <TArray_Get>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}

// TIntegerArray
function TArray_Get(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end; 

// TDoubleArray
function TArray_Get(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TStringArray
function TArray_Get(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TCharArray
function TArray_Get(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TBooleanArray
function TArray_Get(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TPointArray
function TArray_Get(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TBoxArray
function TArray_Get(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;

// TRangeArray
function TArray_Get(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;
var
  i: Int32;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;