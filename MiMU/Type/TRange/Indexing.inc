{$IFDEF METHODS}
function AsID(const oAscending: Boolean = True): TIntegerArray; overload;
function AsIDs: TIntegerArray; overload;
function AsIndexes: TIntegerArray; overload;
function GetIDs: TIntegerArray; overload;
function GetIndexes: TIntegerArray; overload;
function IDs: TIntegerArray; overload;
function IDs(const dValue: Integer): Integer; overload;
function IDs(const dVals: TIntegerArray): TIntegerArray; overload;
function Indexed: TIntegerArray; overload;
function Indexes: TIntegerArray; overload;
function Indexing: TIntegerArray; overload;
function Indiced: TIntegerArray; overload;
function Indices: TIntegerArray; overload;
function IndexList: TIntegerArray; overload;
function Keys: TIntegerArray; overload;
function LoadID(var target: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Positions: TIntegerArray; overload;
function ToIDs: TIntegerArray; overload;
function ToIndexes: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsID>
  @action: Constructs and returns a positional identifier vector for the
           current range instance.
  @note: • If the range is Singular, returns [0].
         • Result length equals Self.Size.
         • oAscending = True  →  [0, 1, 2, ..., Size - 1]
           oAscending = False →  [Size - 1, ..., 2, 1, 0]
         • Generation is arithmetic-progression based (±1 step).
         • Does not depend on the range’s actual Start/Stop values —
           only on its computed Size.
[==============================================================================}
function TRange.AsID(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s: Integer;
begin
  if Self.Singular then
    Exit([0]);
  s := IfThen(oAscending, 1, -1);
  SetLength(Result, Self.Size);
  Result[0] := oAscending.Select(0, High(Result));
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + s);
end;

{==============================================================================]
  <AsIDs>
  @action: Returns an integer array of length equal to the range size, where each
           element is assigned a zero-based sequential ID corresponding to its
           position in the array.
  @note:
    - The generated IDs always start at 0 and increase monotonically.
    - The actual numeric values of `Self.start` and `Self.stop` are NOT used,
      except to determine the array length via `Size`.
    - IDs are generated in fixed-size chunks (CHUNK_SIZE = 10), which is an
      implementation detail and does not affect the final result.
    - The resulting array is equivalent to:
          Result[i] := i
      for all valid indices.
    - Useful when a range needs to be mapped to stable, compact identifiers
      (e.g., indexing, lookup tables, parallel arrays).
[==============================================================================}
function TRange.AsIDs: TIntegerArray; overload;
const
  CHUNK_SIZE = 10;
var
  i, o, s, c: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  o := 0;
  while (o < s) do
  begin
    c := (s - o);
    if (c > CHUNK_SIZE) then
      c := CHUNK_SIZE;
    for i := 0 to (c - 1) do
      Result[o + i] := (o + i);
    Inc(o, CHUNK_SIZE);
  end;
end;

{==============================================================================]
  <AsIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.AsIndexes: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to (s div 2) do
  begin
    Result[i] := i;
    Result[(s - 1) - i] := ((s - 1) - i);
  end;
end;

{==============================================================================]
  <GetIDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.GetIDs: TIntegerArray; overload;
  procedure Fill(var arr: TIntegerArray; const idx: Integer);
  begin
    if (idx < 0) then
      Exit;
    arr[idx] := idx;
    Fill(arr, (idx - 1));
  end;
begin
  SetLength(Result, Self.Size);
  Fill(Result, High(Result));
end;

{==============================================================================]
  <GetIndexes>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.GetIndexes: TIntegerArray; overload;
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
function TRange.Indexed: TIntegerArray; overload;
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
function TRange.Indexes: TIntegerArray; overload;
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
  <Indexing>
  @action: Generates and returns an array of integer “IDs” corresponding to the range, 
           using the digits 0..9 as a repeated base pattern. The length of the resulting 
           array is equal to the size of the range (`Size := Abs(stop - start) + 1`).
  @note:
    - The array is filled in blocks of 10 using the constant `BASE_DIGITS = [0..9]`.  
      If the range size is not a multiple of 10, the final block is truncated to fit.
    - This method does **not** take the actual `start` or `stop` values of the range 
      into account except for determining the array length.
    - The pattern produces a repeated sequence of 0..9, so the first elements are
      always 0,1,2,...9, then repeated with offsets.
    - Useful when you need a simple repeating ID pattern for indexing, mapping, 
      or placeholder purposes.
[==============================================================================}
function TRange.Indexing: TIntegerArray; overload;
var
  b, i, o, d, s: Integer;
begin
  b := System.Length(BASE_DIGITS);
  s := Self.Size;
  SetLength(Result, s);
  o := -b;
  while (o.Increment(b) < s) do
    for i := 0 to Min((b - 1), ((s - o) - 1)) do
      Result[o + i] := (BASE_DIGITS[i] + o);
end;

{==============================================================================]
  <Indiced>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Indiced: TIntegerArray; overload;
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
function TRange.Indices: TIntegerArray; overload;
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
function TRange.IndexList: TIntegerArray; overload;
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
function TRange.Keys: TIntegerArray; overload;
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
  <LoadID>
  @action: Loads the target array with positional identifiers derived from
           the current range instance.
  @note: • Returns Self.Size.
         • Ensures target.Length = Self.Size (resizes if required).
         • oAscending = True  →  [0, 1, 2, ..., Size - 1]
           oAscending = False →  [Size - 1, ..., 2, 1, 0]
         • If the range is Singular, target[0] is initialized and the
           method exits.
         • Sequence is generated as an arithmetic progression (±1 step).
         • Independent of the range’s actual boundary values; relies
           solely on computed Size.
[==============================================================================}
function TRange.LoadID(var target: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  i, s: Integer;
begin
  Result := Self.Size;
  if (target.Length <> Result) then
    SetLength(target, Result);
  target[0] := oAscending.Select(0, (Result - 1));
  if Self.Singular then
    Exit;
  s := IfThen(oAscending, 1, -1);
  for i := 1 to (Result - 1) do
    target[i] := (target[i - 1] + s);
end;

{==============================================================================]
  <Position>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.Positions: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := 0;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + 1);
end;

{==============================================================================]
  <ToIDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.ToIDs: TIntegerArray; overload;
var
  s, b, o, i: Integer;
  P: PInteger;
begin
  s := Self.Size;
  b := System.Length(BASE_DIGITS);
  SetLength(Result, s);
  o := 0;
  while (o < s) do
  begin
    i := (s - o);
    if (i > b) then
	  i := b;
    Move(BASE_DIGITS[0], Result[o], (i * SizeOf(Integer)));
    P := @Result[o];
    for i := 1 to i do
    begin
      P^ := (P^ + o);
      Inc(P);
    end;
    Inc(o, b);
  end;
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
function TRange.ToIndexes: TIntegerArray; overload;
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
