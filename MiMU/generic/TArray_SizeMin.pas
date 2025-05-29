{==============================================================================]
 <TArray_SizeMin>
 @action: Returns true if size is at equal/greater than x.
 @note: 	
[==============================================================================}

// TIntegerArray
function TArray_SizeMin(const arr: TIntegerArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end; 

// TDoubleArray
function TArray_SizeMin(const arr: TDoubleArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TStringArray
function TArray_SizeMin(const arr: TStringArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TCharArray
function TArray_SizeMin(const arr: TCharArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TBooleanArray
function TArray_SizeMin(const arr: TBooleanArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TPointArray
function TArray_SizeMin(const arr: TPointArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TBoxArray
function TArray_SizeMin(const arr: TBoxArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;

// TRangeArray
function TArray_SizeMin(const arr: TRangeArray; const x: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) >= x);
end;