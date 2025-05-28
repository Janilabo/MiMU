{==============================================================================]
 <TArray_Combine>
 @action: Combines arrays a and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}

// TIntegerArray
function TArray_Combine(const a, b: TIntegerArray): TIntegerArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TDoubleArray
function TArray_Combine(const a, b: TDoubleArray): TDoubleArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TStringArray
function TArray_Combine(const a, b: TStringArray): TStringArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TCharArray
function TArray_Combine(const a, b: TCharArray): TCharArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TBooleanArray
function TArray_Combine(const a, b: TBooleanArray): TBooleanArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TPointArray
function TArray_Combine(const a, b: TPointArray): TPointArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TBoxArray
function TArray_Combine(const a, b: TBoxArray): TBoxArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;

// TRangeArray
function TArray_Combine(const a, b: TRangeArray): TRangeArray; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;