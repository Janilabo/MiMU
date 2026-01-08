{$IFDEF HELPERS}
function HybridSort(const aAscending: Boolean = True): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <HybridSort>
  @action: Sorts the integer array (Self) in ascending or descending order
           using algorithm close to TimSort — a stable hybrid sorting method that
           combines insertion sort and merge sort for optimal performance.
  @note:   - Returns Length(Self)
           - Stable (preserves equal element order)
[==============================================================================}
function MArrayHelper.HybridSort(const aAscending: Boolean = True): Integer; overload; cdecl;
const
  RUN_SIZE = 32;
  procedure INS(var arr: MArray; const L, R: Integer);
  var
    t: MType;
    i, j: Integer;
  begin
    for i := (L + 1) to R do
    begin
      t := arr[i];
      j := (i - 1);
      while ((j >= L) and ((aAscending and (arr[j] > t)) or ((not aAscending) and (arr[j] < t)))) do
      begin
	    arr[j + 1] := arr[j];
		Dec(j);
	  end;
      arr[j + 1] := t;
    end;
  end;
  procedure MRG(var arr: MArray; const L, M, R: Integer);
  var
    a, b, i, j, k: Integer;
    x, y: MArray;
  begin
    a := ((M - L) + 1);
    b := (R - M);
    SetLength(x, a);
    SetLength(y, b);
    for i := 0 to (a - 1) do
      x[i] := arr[L + i];
    for i := 0 to (b - 1) do
      y[i] := arr[(M + 1) + i];
    i := 0;
    j := 0;
    k := L;
    while ((i < a) and (j < b)) do
      if ((aAscending and (x[i] <= y[j])) or ((not aAscending) and (x[i] >= y[j]))) then
        arr[k.Increase] := x[i.Increase]
      else
        arr[k.Increase] := y[j.Increase];
    while (i < a) do
      arr[k.Increase] := x[i.Increase];
    while (j < b) do
      arr[k.Increase] := y[j.Increase];
  end;
var
  i, s, l, m, r: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  i := 0;
  while (i < Result) do
  begin
    if (((i + RUN_SIZE) - 1) < Result) then
      INS(Self, i, ((i + RUN_SIZE) - 1))
    else
      INS(Self, i, (Result - 1));
    Inc(i, RUN_SIZE);
  end;
  s := RUN_SIZE;
  while (s < Result) do
  begin
    l := 0;
    while (l < (Result - 1)) do
    begin
      m := ((l + s) - 1);
      r := ((l + (2 * s)) - 1);
      if (r >= Result) then
        r := (Result - 1);
      if (m < r) then
        MRG(Self, l, m, r);
      Inc(l, (2 * s));
    end;
    s := (s * 2);
  end;
end;
{$ENDIF}