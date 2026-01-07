{$IFDEF HELPERS}
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload;
function BinarySort(const aAscending: Boolean = True): Integer;
function BinarySorted(const aAscending: Boolean = True): TDoubleArray;
function BSort(const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TDoubleArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
var
  K: Double;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Size;
  for i := 1 to (Result - 1) do
  begin
    K := Self[i];
    P := 0;
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if ((oAscending and (K < Self[M])) or ((not oAscending) and (K > Self[M]))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Self[j + 1] := Self[j.Decrease];
    Self[P] := K;
  end;
end;

function TDoubleArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload;
var
  K: Double;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Copy;
  for i := 1 to High(Result) do
  begin
    K := Result[i];
    P := 0;
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if ((oAscending and (K < Result[M])) or ((not oAscending) and (K > Result[M]))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Result[j + 1] := Result[j.Decrease];
    Result[P] := K;
  end;
end;

{==============================================================================]
  <BinarySort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BinarySort(const aAscending: Boolean = True): Integer;
var
  a: Double;
  j, m, i, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for j := 1 to Result do
    begin
      a := Self[j];
      r.Create(0, j);
      while r.Grows do
      begin
        m := r.Pivot;
        if (Sign(Self[m] - a) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Self[i] := Self[i - 1];
      Self[r.start] := a;
    end;
  end;
end;

{==============================================================================]
  <BinarySorted>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TDoubleArrayHelper.BinarySorted(const aAscending: Boolean = True): TDoubleArray;
var
  a: Double;
  j, m, i, n, o: Integer;
  r: TRange;
begin
  n := Self.Size;
  SetLength(Result, n);
  if (n > 0) then
  begin
    o := aAscending.Select(-1, 1);
    Result[0] := Self[0];
    for j := 1 to (n - 1) do
    begin
      a := Self[j];
      r.Create(0, j);
      while r.Grows do
      begin
        m := r.Pivot;
        if (Sign(Result[m] - a) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Result[i] := Result[i - 1];
      Result[r.start] := a;
    end;
  end;
end;

{==============================================================================]
  <BSort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BSort(const aAscending: Boolean = True): Integer;
var
  a: Double;
  i, j, m, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
    o := aAscending.Select(-1, 1);
  for i := 1 to Result do
  begin
    a := Self[i];
    r.Create(0, (i - 1));
    while r.Ascending do
    begin
      m := r.Pivot;
      if (Sign(a - Self[m]) = o) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    for j := (i - 1) downto r.start do
      Self[j + 1] := Self[j];
    Self[r.start] := a;
  end;
end;
{$ENDIF}
