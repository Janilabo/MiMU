{==============================================================================]
 <TArray_Holds>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}

// TIntegerArray
function TArray_Holds(const arr, chain: TIntegerArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TDoubleArray
function TArray_Holds(const arr, chain: TDoubleArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TStringArray
function TArray_Holds(const arr, chain: TStringArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TCharArray
function TArray_Holds(const arr, chain: TCharArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TBooleanArray
function TArray_Holds(const arr, chain: TBooleanArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TPointArray
function TArray_Holds(const arr, chain: TPointArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := ((arr[(a + x)].X <> chain[x].X) or (arr[(a + x)].Y <> chain[x].Y));
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TBoxArray
function TArray_Holds(const arr, chain: TBoxArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := ((arr[(a + x)].X1 <> chain[x].X1) or (arr[(a + x)].Y1 <> chain[x].Y1) or (arr[(a + x)].X2 <> chain[x].X2) or (arr[(a + x)].Y2 <> chain[x].Y2));
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

// TRangeArray
function TArray_Holds(const arr, chain: TRangeArray): Boolean; overload; cdecl;
var
  a, b, x, y, z: Int32;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := ((arr[(a + x)].start <> chain[x].start) or (arr[(a + x)].stop <> chain[x].stop));
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;
