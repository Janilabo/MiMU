{$IFDEF HELPERS}
function TArray(const aSize: Integer = 1): TArr; overload;
function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
{$ENDIF}

{$IFDEF METHODS}
function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline;
function Swap(var A, B: TVar): Boolean; overload; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function THelper.TArray(const aSize: Integer = 1): TArr; overload;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;

{==============================================================================]
 <T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function THelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
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

function Swap(var A, B: TVar): Boolean; overload; inline; var C: TVar; {$DEFINE Skeleton_Swap}{$I Skeletons.inc}{$UNDEF Skeleton_Swap}

function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline; {$DEFINE Skeleton_IfThen}{$I Skeletons.inc}{$UNDEF Skeleton_IfThen}
{$ENDIF}
