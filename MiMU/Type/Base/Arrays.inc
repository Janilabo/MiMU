{$IFDEF FUNCTIONS}
function AsArray3(const A, B, C: MType): MArray; overload;
function Retro3(const A, B, C: MType): MArray; overload;
function Rev3(const A, B, C: MType): MArray; overload;
function Shuffled3(const A, B, C: MType): MArray; overload;
function ToArray3(const A, B, C: MType): MArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload;
function TArray(const aSize: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <AsArray3>
 @action: Constructs and returns an MArray containing the three provided MType elements.
 @note: Explicitly allocates memory for a 3-element dynamic array using SetLength 
        and assigns each element sequentially via direct indexing.
[==============================================================================}
function AsArray3(const A, B, C: MType): MArray; overload;
begin
  SetLength(Result, 3);
  Result[0] := A;
  Result[1] := B;
  Result[2] := C;
end;

{==============================================================================]
  <Rev3>
  @action: Returns a new array containing the three values in reverse order.
  @note: Original values remain unchanged. Short for "Reverse 3".
  @param A, B, C: Three items to be reversed
  @return: Dynamic array with order [C, B, A]
  @example: Rev3(1, 2, 3) → [3, 2, 1]
  @example: Rev3('A', 'B', 'C') → ['C', 'B', 'A']
  @example: Rev3(True, False, True) → [True, False, True]
[==============================================================================}
function Retro3(const A, B, C: MType): MArray; overload;
begin
  SetLength(Result, 3);
  Result[0] := C;
  Result[1] := B;
  Result[2] := A;
end;

{==============================================================================]
  <Rev3>
  @action: Returns array in reverse order (short for Reverse3).
  @example: Rev3(1,2,3) → [3,2,1]
[==============================================================================}
function Rev3(const A, B, C: MType): MArray; overload;
begin
  Result := [C, B, A];
end;

{==============================================================================]
  <Shuffled3>
  @action: Returns array in random order (opposite of Sorted3).
  @note: Returns a random permutation of the three values.
[==============================================================================}
function Shuffled3(const A, B, C: MType): MArray; overload;
begin
  case Random(6) of
    0: Result := [A, B, C];
    1: Result := [A, C, B];
    2: Result := [B, A, C];
    3: Result := [B, C, A];
    4: Result := [C, A, B];
    5: Result := [C, B, A];
  end;
end;

{==============================================================================]
 <ToArray3>
 @action: Constructs and returns an MArray containing the three provided MType elements.
 @note: Utilizes modern Delphi open array constructor syntax ([A, B, C]) to 
        implicitly initialize and populate the dynamic array in a single expression.
[==============================================================================}
function ToArray3(const A, B, C: MType): MArray; overload;
begin
  Result := [A, B, C];
end;

{==============================================================================]
 <T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function MTypeHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload;
var
  i, j: Integer;
begin
  SetLength(Result, size1D);
  for i := 0 to High(Result) do
  begin
    SetLength(Result[i], size2D);
    for j := 0 to High(Result[i]) do
      Result[i][j] := Self;
  end;
end;

{==============================================================================]
 <TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function MTypeHelper.TArray(const aSize: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;
{$ENDIF}