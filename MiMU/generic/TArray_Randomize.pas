{==============================================================================]
 <TArray_Clone>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}

// TIntegerArray
function TArray_Randomize(var arr: TIntegerArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y, a: Int32;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TDoubleArray
function TArray_Randomize(var arr: TDoubleArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: Double;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TStringArray
function TArray_Randomize(var arr: TStringArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: string;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TCharArray
function TArray_Randomize(var arr: TCharArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: Char;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TBooleanArray
function TArray_Randomize(var arr: TBooleanArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: Boolean;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TPointArray
function TArray_Randomize(var arr: TPointArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: TPoint;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TBoxArray
function TArray_Randomize(var arr: TBoxArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: TBox;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;

// TRangeArray
function TArray_Randomize(var arr: TRangeArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
var
  l, i, s, x, y: Int32;
  a: TRange;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
      a := arr[x];
      arr[x] := arr[y];
      arr[y] := a;
    end;
end;