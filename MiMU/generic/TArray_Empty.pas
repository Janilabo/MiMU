{==============================================================================]
 <TArray_Empty>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Empty(const arr: TIntegerArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TDoubleArray
function TArray_Empty(const arr: TDoubleArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TStringArray
function TArray_Empty(const arr: TStringArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TCharArray
function TArray_Empty(const arr: TCharArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TBooleanArray
function TArray_Empty(const arr: TBooleanArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TPointArray
function TArray_Empty(const arr: TPointArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TBoxArray
function TArray_Empty(const arr: TBoxArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// TRangeArray
function TArray_Empty(const arr: TRangeArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;