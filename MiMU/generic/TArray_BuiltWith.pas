{==============================================================================]
 <TArray_Built> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_BuiltWith(const arr, allowed: TIntegerArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TDoubleArray
function TArray_BuiltWith(const arr, allowed: TDoubleArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TStringArray
function TArray_BuiltWith(const arr, allowed: TStringArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TCharArray
function TArray_BuiltWith(const arr, allowed: TCharArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TBooleanArray
function TArray_BuiltWith(const arr, allowed: TBooleanArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TPointArray
function TArray_BuiltWith(const arr, allowed: TPointArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TBoxArray
function TArray_BuiltWith(const arr, allowed: TBoxArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;

// TRangeArray
function TArray_BuiltWith(const arr, allowed: TRangeArray): Boolean; overload; cdecl;
var
  i, x, y: Int32;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;