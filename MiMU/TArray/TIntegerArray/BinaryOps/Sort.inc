{$IFDEF HELPERS}
function BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload;
function BinarySort(const aAscending: Boolean = True): Integer;
function BinarySorted(const aAscending: Boolean = True): TIntegerArray;
function BSort(const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCountingSort>
  @action: Sorts the integer array using a hybrid approach that combines counting sort
           for densely clustered values with binary insertion for outliers.
           Automatically adapts to the data distribution based on the maxRange parameter.
  @note: 
    - If the range of array values is smaller than or equal to maxRange, a full counting
      sort is applied.
    - If the range exceeds maxRange, the method counts values within a central cluster
      (centered at the array’s midpoint) and uses binary insertion for values outside
      that cluster.
    - Supports ascending (default) or descending order.
    - Handles negative and positive integers.
    - The counting array size is bounded by maxRange + 1 to avoid excessive memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
var
  c, l: TIntegerArray;
  i, j, r, o: Integer;
  m: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds(r);
  case (r <= maxRange) of
    True:
    begin
      SetLength(c, r);
      for i := 0 to High(Self) do
        Inc(c[Self[i] - m.start]);
      j := 0;
      case aAscending of
        True:
        for i := 0 to (r - 1) do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
        False:
        for i := r - 1 downto 0 do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
      end;
    end;
    False:
    begin
      o := m.Center;
      r := 200;
      SetLength(c, ((r * 2) + 1));
      SetLength(l, 0);
      for i := 0 to High(Self) do
        if InRange(Self[i], (o - r), (o + r)) then
          Inc(c[Self[i] - (o - r)])
        else
          l.BinaryAppend(Self[i]);
      j := 0;
      case aAscending of
        True:
        begin
          for i := 0 to High(c) do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := 0 to High(l) do
            Self[j.Increase] := l[i];
        end;
        False:
        begin
          for i := High(c) downto 0 do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := High(l) downto 0 do
            Self[j.Increase] := l[i];
        end;
      end;
    end;
  end;
end;

function TIntegerArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
var
  K: Integer;
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

function TIntegerArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload;
var
  K, i, j, L, R, M, P: Integer;
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
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const aAscending: Boolean = True): Integer;
var
  a, j, m, i, o: Integer;
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
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const aAscending: Boolean = True): TIntegerArray;
var
  a, j, m, i, n, o: Integer;
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
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const aAscending: Boolean = True): Integer;
var
  a, i, j, m, o: Integer;
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
