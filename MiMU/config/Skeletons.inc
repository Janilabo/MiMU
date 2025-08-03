{$IFDEF Skeleton_Swap}
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}

{$IFDEF Skeleton_Max}
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Min}
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Compare}
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_IfThen}
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_QuickSorted}
  procedure QS_IDs(var aID: TIntegerArray; const L, R: Integer);
  var
    i, j, c: Integer;
  begin
    i := L;
    j := R;
    w := weight[aID[(L + R) shr 1]];
    repeat
      c := weight[aID[i]].Compare(w);
      while (aAscending and (c < 0)) or ((not aAscending) and (c > 0)) do
        c := weight[aID[i.Increment]].Compare(w);
      c := weight[aID[j]].Compare(w);
      while (aAscending and (c > 0)) or ((not aAscending) and (c < 0)) do
        c := weight[aID[j.Decrement]].Compare(w);
      if (i <= j) then
        Swap(aID[i.Increase], aID[j.Decrease]);
    until (i > j);
    if (L < j) then
	  QS_IDs(aID, L, j);
    if (i < R) then
	  QS_IDs(aID, i, R);
  end;
var
  n, i: Integer;
  r: TIntegerArray;
begin
  n := Length(Self);
  if ((n > 0) and (n = Length(weight))) then
  begin
    SetLength(Result, n);
    Result := Self.Copy;
    SetLength(r, n);
    for i := 0 to (n - 1) do
      r[i] := i;
    QS_IDs(r, 0, (n - 1));
    for i := 0 to (n - 1) do
      Result[i] := Self[r[i]];
  end else
    SetLength(Result, 0);
end;
{$ENDIF}

{$IFDEF Skeleton_ScanParameter1}
function Start(const arr: TRangeArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].start;
end;

function Start(const arr: TRangeArray; const val: Integer): TIntegerArray; overload; cdecl;
var
  i, r, l: Integer;
begin
  r := 0;
  l := Length(arr);
  if (l > 0) then
    SetLength(Result, l);
  for i := 0 to (l - 1) do
    if (arr[i].start = val) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;
{$ENDIF}