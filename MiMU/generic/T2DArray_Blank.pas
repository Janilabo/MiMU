{==============================================================================]
 <T2DArray_Blank>
 @action: Returns true if array is blank (no inventory, only empty indexes of []).
 @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
        NOTE: Returns false if array is empty (1D Length = 0)!
[==============================================================================}

// T2DIntegerArray
function T2DArray_Blank(const arr: T2DIntegerArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DDoubleArray
function T2DArray_Blank(const arr: T2DDoubleArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DStringArray
function T2DArray_Blank(const arr: T2DStringArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DCharArray
function T2DArray_Blank(const arr: T2DCharArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DBooleanArray
function T2DArray_Blank(const arr: T2DBooleanArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DPointArray
function T2DArray_Blank(const arr: T2DPointArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DBoxArray
function T2DArray_Blank(const arr: T2DBoxArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;

// T2DRangeArray
function T2DArray_Blank(const arr: T2DRangeArray): Boolean; overload; cdecl;
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;