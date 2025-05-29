{==============================================================================]
 <TArray_Undersize>
 @action: Returns true if size of arr is UNDER the limit.
 @note: None.	
[==============================================================================} 

// TIntegerArray
function TArray_Undersize(const arr: TIntegerArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end; 

// TDoubleArray
function TArray_Undersize(const arr: TDoubleArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TStringArray
function TArray_Undersize(const arr: TStringArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TCharArray
function TArray_Undersize(const arr: TCharArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TBooleanArray
function TArray_Undersize(const arr: TBooleanArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TPointArray
function TArray_Undersize(const arr: TPointArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TBoxArray
function TArray_Undersize(const arr: TBoxArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;

// TRangeArray
function TArray_Undersize(const arr: TRangeArray; const limit: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) < limit);
end;