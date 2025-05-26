{==============================================================================]
 <TArray_Build> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}

// TIntegerArray
function TArray_Build(const item: Int32; const size: Int32 = 1): TIntegerArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TDoubleArray
function TArray_Build(const item: Double; const size: Int32 = 1): TDoubleArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TStringArray
function TArray_Build(const item: string; const size: Int32 = 1): TStringArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TCharArray
function TArray_Build(const item: Char; const size: Int32 = 1): TCharArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TBooleanArray
function TArray_Build(const item: Boolean; const size: Int32 = 1): TBooleanArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TPointArray
function TArray_Build(const item: TPoint; const size: Int32 = 1): TPointArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TBoxArray
function TArray_Build(const item: TBox; const size: Int32 = 1): TBoxArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;

// TRangeArray
function TArray_Build(const item: TRange; const size: Int32 = 1): TRangeArray; overload; cdecl;
begin
  Result := TArray_Create(size, item);
end;