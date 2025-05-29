{==============================================================================]
 <TArray_SizeMax>
 @action: Returns true if size is at equal/lesser than y.
 @note: 	
[==============================================================================}

// TIntegerArray
function TArray_SizeMax(const arr: TIntegerArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end; 

// TDoubleArray
function TArray_SizeMax(const arr: TDoubleArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TStringArray
function TArray_SizeMax(const arr: TStringArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TCharArray
function TArray_SizeMax(const arr: TCharArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TBooleanArray
function TArray_SizeMax(const arr: TBooleanArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TPointArray
function TArray_SizeMax(const arr: TPointArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TBoxArray
function TArray_SizeMax(const arr: TBoxArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;

// TRangeArray
function TArray_SizeMax(const arr: TRangeArray; const y: Int32): Boolean; overload; cdecl;
begin
  Result := (Length(arr) <= y);
end;