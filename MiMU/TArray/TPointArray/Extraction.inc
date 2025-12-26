{$IFDEF HELPERS}
function Xs: TIntegerArray; overload;
function Ys: TIntegerArray; overload;
function XValues: TIntegerArray; overload;
function YValues: TIntegerArray; overload;
function XVals(const aAscending: Boolean = True): TIntegerArray;
function YVals(const aAscending: Boolean = True): TIntegerArray;
function XArr(const aAscending: Boolean = True): TIntegerArray;
function YArr(const aAscending: Boolean = True): TIntegerArray;
function XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
function YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
function Axes(var X, Y: TIntegerArray): Integer; overload;
function Axed: T2DIntegerArray; overload;
function Axed(var X, Y: TIntegerArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Xs>
  @action: Extracts the X-coordinates of all points in the array and returns
           them as a TIntegerArray. The order of values in the result matches
           the order of the points in the source array.
  @note: This is a direct projection operation; no filtering, sorting, or
         transformation is applied. The returned array always has the same
         length as the source.
[==============================================================================}
function TPointArrayHelper.Xs: TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].X;
end;

{==============================================================================]
  <Ys>
  @action: Extracts the Y-coordinates of all points in the array and returns
           them as a TIntegerArray, preserving the original element order.
  @note: Performs a simple coordinate projection without any modification or
         reordering. The returned array has the same length as the input.
[==============================================================================}
function TPointArrayHelper.Ys: TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y;
end;

{==============================================================================]
  <XValues>
  @action: Returns X-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.XValues: TIntegerArray; overload; 
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X;
end;

{==============================================================================]
  <YValues>
  @action: Returns Y-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.YValues: TIntegerArray; overload; 
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y;
end;

{==============================================================================]
  <XVals>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].X, aAscending);
end;

{==============================================================================]
  <YVals>
  @action:  Returns an array of all Y coordinates from the point array,
            optionally sorted in ascending or descending order.
  @note:    Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].Y, aAscending);
end;

{==============================================================================]
  <XArr>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Xs.QuickSorted(aAscending);
end;

{==============================================================================]
  <YArr>
  @action: Returns an array of all Y coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Ys.QuickSorted(aAscending);
end;

{==============================================================================]
  <XAxis>
  @action: Extracts all X-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique X values (duplicates removed).
         When rUnique = False, all X values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].X);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].X);
  end;
end;

{==============================================================================]
  <YAxis>
  @action: Extracts all Y-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique Y values (duplicates removed).
         When rUnique = False, all Y values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].Y);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].Y);
  end;
end;

{==============================================================================]
  <Axes>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axes(var X, Y: TIntegerArray): Integer; overload; 
var
  sX, sY, dX, dY: Pointer;
  p, c: SizeInt;
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  if (Result = 0) then
    Exit;
  c := SizeOf(Integer);
  p := SizeOf(TPoint);
  sX := @Self[0].X;
  sY := Pointer(PByte(sX) + c);
  dX := @X[0];
  dY := @Y[0];
  for i := 0 to High(Self) do
  begin
    Move(sX^, dX^, c);
    Move(sY^, dY^, c);
    Inc(PByte(sX), p);
    Inc(PByte(sY), p);
    Inc(PByte(dX), c);
    Inc(PByte(dY), c);
  end;
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed: T2DIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, 2, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[0][i] := Self[i].X;
    Result[1][i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed(var X, Y: TIntegerArray): Integer; overload; 
var
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  for i := 0 to High(Self) do
  begin
    X[i] := Self[i].X;
    Y[i] := Self[i].Y;
  end;
end;
{$ENDIF}
