{$IFDEF METHODS}
function AsIndexes: TIntegerArray;
function GetIndexes: TIntegerArray;
function IDs: TIntegerArray; overload;
function IDs(const dValue: Integer): Integer; overload;
function IDs(const dVals: TIntegerArray): TIntegerArray; overload;
function Indexed: TIntegerArray;
function Indexes: TIntegerArray;
function Indiced: TIntegerArray;
function Indices: TIntegerArray;
function IndexList: TIntegerArray;
function Keys: TIntegerArray;
function Positions: TIntegerArray;
function ToIndexes: TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.AsIndexes: TIntegerArray;
var
  i, h, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  h := (s div 2);
  for i := 0 to h do
  begin
    Result[i] := i;
    Result[(s - 1) - i] := ((s - 1) - i);
  end;
end;

{==============================================================================]
  <GetIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.GetIndexes: TIntegerArray;
var
  s, i: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to ((s - 1) div 2) do
    Result[i * 2] := (i * 2);
  for i := 0 to ((s - 2) div 2) do
    Result[(i * 2) + 1] := ((i * 2) + 1);
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dValue: Integer): Integer; overload;
begin
  case Self.Ascending of
    True:
    if ((dValue < Self.start) or (dValue > Self.stop)) then
      Result := -2147483648
    else
      Result := (dValue - Self.start);
    False:
    if ((dValue > Self.start) or (dValue < Self.stop)) then
      Result := -2147483648
    else
      Result := (Self.start - dValue);
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dVals: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dVals) + 1));
  for i := 0 to High(dVals) do
    Result[i] := Self.IDs(dVals[i]);
end;

{==============================================================================]
  <Indexed>
  @action: Returns an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Implemented using loop unrolling for improved performance.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.Indexed: TIntegerArray;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  while ((i + 3) < s) do
  begin
    Result[i + 0] := (i + 0);
    Result[i + 1] := (i + 1);
    Result[i + 2] := (i + 2);
    Result[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  for s := i to High(Result) do
    Result[s] := s;
end;

{==============================================================================]
  <Indexes>
  @action: Returns an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Straightforward reference implementation.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.Indexes: TIntegerArray;
  function Output(const rSize: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, rSize);
    for i := 0 to (rSize - 1) do
      Result[i] := i;
  end;
begin
  Result := Output(Self.Size);
end;

{==============================================================================]
  <Indiced>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Indiced: TIntegerArray;
begin
  SetLength(Result, 0);
  while (Result.Length < Self.Size) do
    Result.Supply(System.Length(Result));
end;

{==============================================================================]
  <Indices>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Indices: TIntegerArray;
var
  l, r: Integer;
begin
  SetLength(Result, Self.Size);
  l := -1;
  r := Result.Length;
  while (l.Increment < r.Decrement) do
  begin
    Result[l] := l;
    Result[r] := r;
  end;
  if (l = r) then
    Result[l] := l;
end;

{==============================================================================]
  <IndexList>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IndexList: TIntegerArray;
var
  l: specialize TList<Integer>;
  i: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    for i := 0 to (Self.Size - 1) do
      l.Add(i);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Keys>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Keys: TIntegerArray;
label
  b, e;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  b:
  if (i >= s) then
    goto e;
  Result[i] := i;
  Inc(i);
  goto b;
  e:
end; 

{==============================================================================]
  <Position>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Positions: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := 0;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + 1);
end; 

{==============================================================================]
  <ToIndexes>
  @action: Produces an array of zero-based indices corresponding to the
           elements of the range.
  @note: The resulting array has length Size and contains the values
         [0, 1, 2, ..., Size-1].
         Implemented using direct pointer iteration for efficiency.
         Independent of range direction (ascending or descending).
[==============================================================================}
function TRange.ToIndexes: TIntegerArray;
var
  i: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^ := i;
    Inc(p);
  end;
end;
{$ENDIF}
