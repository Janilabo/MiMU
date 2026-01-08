{$IFDEF HELPERS}
function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload; cdecl;
function TArray(const aSize: Integer = 1): MArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function MTypeHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload; cdecl;
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
function MTypeHelper.TArray(const aSize: Integer = 1): MArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;
{$ENDIF}