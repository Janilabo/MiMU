{$IFDEF HELPERS}
function Dispatch(var A: MArray): Integer; overload;
function Dispatch(var A, B: MArray): Integer; overload;
function Dispatch(var A, B, C: MArray): Integer; overload;

function Dispatchify(var A: MArray): Integer; overload;
function Dispatchify(var A, B: MArray): Integer; overload;
function Dispatchify(var A, B, C: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Dispatch>
  @action: Copies all elements of the array into `A` and returns the element count.
  @note: Uses `A.Alloc(Result)` as the upper bound while copying elements sequentially.
[==============================================================================}
function MArrayHelper.Dispatch(var A: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to A.Alloc(Result) do
    A[i] := Self[i];
end;

{==============================================================================]
  <Dispatch>
  @action: Copies all elements of the array into both `A` and `B`, returning the element count.
  @note: Pre-allocates `A` and `B` to `Result` via `SetLength` before copying elements.
[==============================================================================}
function MArrayHelper.Dispatch(var A, B: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  SetLength(A, Result);
  SetLength(B, Result);
  for i := 0 to (Result - 1) do
  begin
    A[i] := Self[i];
    B[i] := Self[i];
  end;
end;

{==============================================================================]
  <Dispatch>
  @action: Copies all elements of the array into `A`, `B`, and `C`, returning the element count.
  @note: Pre-allocates `A`, `B`, and `C` to `Result` via `SetLength` before copying elements.
[==============================================================================}
function MArrayHelper.Dispatch(var A, B, C: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
  for i := 0 to (Result - 1) do
  begin
    A[i] := Self[i];
    B[i] := Self[i];
	C[i] := Self[i];
  end;
end;

{==============================================================================]
  <Dispatchify>
  @action: Copies all elements from the source array into destination array A
           using a two-pointer sweep from both ends toward the middle.
  @note: Resizes A to Self.Length and returns that length. Guard against an
         empty array (Self.Length = 0) to avoid out-of-bounds access when
         r is initialized to -1.
[==============================================================================}
function MArrayHelper.Dispatchify(var A: MArray): Integer; overload;
var
  i, r: Integer;
begin
  Result := Self.Length;
  if (A.SetSize(Result) = 0) then
    Exit;
  r := (Result - 1);
  for i := 0 to (r div 2) do
  begin
    A[i] := Self[i];
    A[r] := Self[r];
    Dec(r);
  end;
end;

{==============================================================================]
  <Dispatchify>
  @action: Copies all elements from the source array into both destination
           arrays A and B using a two-pointer sweep from both ends.
  @note: Resizes both A and B to Self.Length and returns that length. Returns
         0 early if the source array is empty to prevent out-of-bounds
         indexing when r = -1.
[==============================================================================}
function MArrayHelper.Dispatchify(var A, B: MArray): Integer; overload;
var
  i, r: Integer;
begin
  Result := Self.Length;
  SetLength(A, Result);
  SetLength(B, Result);
  if (Result = 0) then
    Exit;
  r := (Result - 1);
  for i := 0 to (r div 2) do
  begin
    A[i] := Self[i];
    B[i] := Self[i];
    A[r] := Self[r];
    B[r] := Self[r];
    Dec(r);
  end;
end;

{==============================================================================]
  <Dispatchify>
  @action: Copies all elements from the source array into destination arrays A,
           B, and C using a two-pointer sweep from both ends toward the center.
  @note: Resizes A, B, and C to Self.Length and returns that length. Exits
         early when Self.Length = 0 so the loop does not index Self[0] and
         Self[-1] on an empty array.
[==============================================================================}
function MArrayHelper.Dispatchify(var A, B, C: MArray): Integer; overload;
var
  i, r: Integer;
begin
  Result := Self.Length;
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
  if (Result = 0) then
    Exit;
  r := (Result - 1);
  for i := 0 to (r div 2) do
  begin
    A[i] := Self[i];
    B[i] := Self[i];
	C[i] := Self[i];
    A[r] := Self[r];
    B[r] := Self[r];
	C[r] := Self[r];
    Dec(r);
  end;
end;
{$ENDIF}
