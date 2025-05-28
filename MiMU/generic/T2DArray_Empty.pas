{==============================================================================]
 <T2DArray_Empty>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}

// T2DIntegerArray
function T2DArray_Empty(const arr: T2DIntegerArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DDoubleArray
function T2DArray_Empty(const arr: T2DDoubleArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DStringArray
function T2DArray_Empty(const arr: T2DStringArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DCharArray
function T2DArray_Empty(const arr: T2DCharArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DBooleanArray
function T2DArray_Empty(const arr: T2DBooleanArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DPointArray
function T2DArray_Empty(const arr: T2DPointArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DBoxArray
function T2DArray_Empty(const arr: T2DBoxArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;

// T2DRangeArray
function T2DArray_Empty(const arr: T2DRangeArray): Boolean; overload; cdecl;
begin
  Result := (Length(arr) = 0);
end;