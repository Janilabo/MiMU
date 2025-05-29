{==============================================================================]
 <TArray_SizeBetween>
 @action: Returns true if size is at equal/greater than x and equal/lesser than y.
 @note: 	
[==============================================================================}

// TIntegerArray
function TArray_SizeBetween(const arr: TIntegerArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end; 

// TDoubleArray
function TArray_SizeBetween(const arr: TDoubleArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TStringArray
function TArray_SizeBetween(const arr: TStringArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TCharArray
function TArray_SizeBetween(const arr: TCharArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TBooleanArray
function TArray_SizeBetween(const arr: TBooleanArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TPointArray
function TArray_SizeBetween(const arr: TPointArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TBoxArray
function TArray_SizeBetween(const arr: TBoxArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;

// TRangeArray
function TArray_SizeBetween(const arr: TRangeArray; const x, y: Int32): Boolean; overload; cdecl;
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;