{$IFDEF HELPERS}
function TArray(const aSize: Integer = 1): TArr; overload;
function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
function AppearsIn(const target: TArr): Integer; overload;
{$ENDIF}

{$IFDEF METHODS}
function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline;
function Swap(var A, B: TVar): Boolean; overload; inline;
{$IFDEF Sortable}
function Swop(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}
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

{==============================================================================]
 <AppearsIn>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function THelper.AppearsIn(const target: TArr): Integer; overload;
var
  R: TRange;
begin
  Result := 0;
  if target.Empty then
    Exit;
  R.Create(0, High(target));
  while ((R.stop - R.start) > 3) do
  begin
    Inc(Result, (Ord(target[R.start] = Self) + Ord(target[R.start + 1] = Self) + Ord(target[R.start + 2] = Self) + Ord(target[R.start + 3] = Self)));
    Inc(R.start, 4);
  end;
  while (R.start <= R.stop) do
    Inc(Result, Ord(target[R.start.Increase] = Self));
end;

function Swap(var A, B: TVar): Boolean; overload; inline; var C: TVar; {$DEFINE Skeleton_Swap}{$I Skeletons.inc}{$UNDEF Skeleton_Swap}

function IfThen(const state: Boolean; const sTrue, sFalse: TVar): TVar; overload; inline; {$DEFINE Skeleton_IfThen}{$I Skeletons.inc}{$UNDEF Skeleton_IfThen}

{$IFDEF Sortable}
function Swop(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TVar>(A, B, oAscending); end;
function Swop(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TVar>(A, B, C, oAscending); end;

function Sort(var A, B: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TVar>(A, B, oAscending); end;
function Sort(var A, B, C: TVar; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TVar>(A, B, C, oAscending); end;
{$ENDIF}
{$ENDIF}
