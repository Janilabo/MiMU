{$IFDEF HELPERS}
function BinaryHinge(const oAscending: Boolean = True): Integer; overload;
function BinaryInflection(const oAscending: Boolean = True): Integer; overload;
function BinaryPivot(const oAscending: Boolean = True): Integer; overload;
function BinaryTransition(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <BinaryHinge>
  @action: Pointer-offset based binary search avoiding indexing bounds checks.
  @note: Raw memory read. Bitwise right-shift for fast midpoint evaluation.
[==============================================================================}
function TBooleanArrayHelper.BinaryHinge(const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
  P: PBoolean;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  P := @Self[0];
  L := 0;
  R := (Result - 1);
  while (L <= R) do
  begin
    M := ((L + R) shr 1);
    if ((P + M)^ = oAscending) then
    begin
      Result := M;
      R := (M - 1);
    end else
      L := (M + 1);
  end;
end; 

{==============================================================================|
  <BinaryInflection>
  @action: Exponential step-bounding followed by binary search for pivot index.
  @note: O(log K) complexity. Superior when the pivot point lies close to the start.
[==============================================================================}
function TBooleanArrayHelper.BinaryInflection(const oAscending: Boolean = True): Integer; overload;
var
  H, S, L, R, M: Integer;
begin
  H := High(Self);
  if (H = -1) then
    Exit(0);
  if (Self[0] = oAscending) then
    Exit(0);
  if (Self[H] <> oAscending) then
    Exit(H + 1);
  S := 1;
  while ((S <= H) and (Self[S] <> oAscending)) do
    S := (S * 2);
  L := (S div 2);
  R := Min(S, H);
  Result := (H + 1);
  while (L <= R) do
  begin
    M := (L + ((R - L) div 2));
    if (Self[M] = oAscending) then
    begin
      Result := M;
      R := (M - 1);
    end else
      L := (M + 1);
  end;
end;

{==============================================================================|
  <BinaryPivot>
  @action: Returns the starting index of the second partition in the sorted array.
           - Ascending [F, F, T, T]: Returns index of the FIRST True.
           - Descending [T, T, F, F]: Returns index of the FIRST False.
  @note: Returns Self.Length if the array contains only one uniform value type.
[==============================================================================}
function TBooleanArrayHelper.BinaryPivot(const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.Binary1st(True, True)
  else
    Result := Self.Binary1st(False, False);
  if (Result = -1) then
    Result := Self.Length;
end;

{==============================================================================|
  <BinaryTransition>
  @action: Direct inline binary search to locate the partition boundary index.
  @note: O(log N) complexity. Zero sub-method dispatch overhead.
[==============================================================================}
function TBooleanArrayHelper.BinaryTransition(const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  L := 0;
  R := (Result - 1);
  while (L <= R) do
  begin
    M := L + ((R - L) div 2);
    if (Self[M] = oAscending) then
    begin
      Result := M;
      R := (M - 1);
    end else
      L := (M + 1);
  end;
end;
{$ENDIF}
