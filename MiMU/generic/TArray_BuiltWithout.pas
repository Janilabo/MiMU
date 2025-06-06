{==============================================================================]
 <TArray_BuiltWithout> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_BuiltWithout(const arr, forbidden: TIntegerArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TDoubleArray
function TArray_BuiltWithout(const arr, forbidden: TDoubleArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TStringArray
function TArray_BuiltWithout(const arr, forbidden: TStringArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TCharArray
function TArray_BuiltWithout(const arr, forbidden: TCharArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TBooleanArray
function TArray_BuiltWithout(const arr, forbidden: TBooleanArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TPointArray
function TArray_BuiltWithout(const arr, forbidden: TPointArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TBoxArray
function TArray_BuiltWithout(const arr, forbidden: TBoxArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;

// TRangeArray
function TArray_BuiltWithout(const arr, forbidden: TRangeArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;
