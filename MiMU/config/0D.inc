{$I Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
function TArray(const aSize: Integer = 1): TArr; overload;
function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <var.TArray(aSize: Integer): TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function HVar.TArray(const aSize: Integer = 1): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;

{==============================================================================]
 <var.T2DArray(size1D, size2D: Integer): T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function HVar.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
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
{$ENDIF}