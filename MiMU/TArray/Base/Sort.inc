{$IFDEF HELPERS}
function MergeSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function MergeSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function QuickSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
function QuickSorted(const weight: TIntegerArray; const aAscending: Boolean = True): MArray; overload;
function QuickSorted(const weight: TDoubleArray; const aAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <MergeSortWeighted>
  @action: Performs an in-place merge sort on the current integer array (Self),
           ordering both Self and the given weight array according to the
           weight values. Supports ascending or descending order.
  @note: - Self and weight must be of equal length.
         - Sorting is stable (preserves relative order of equal weights).
         - Returns the length of Self after sorting.
         - When aAscending = True, smaller weights appear first.
[==============================================================================}
function MArrayHelper.MergeSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSW(var arr: MArray; var wgt: TIntegerArray; const L, R: Integer);
  var
    s: MArray;
    w: TIntegerArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSW(arr, wgt, L, m);
    MSW(arr, wgt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(w, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (wgt[i] <= wgt[j])) or ((not aAscending) and (wgt[i] >= wgt[j]))) of
        True:
        begin
          s[k] := arr[i];
          w[k] := wgt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          w[k] := wgt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      w[k] := wgt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      w[k] := wgt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      wgt[L + k] := w[k];
    end;
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    MSW(Self, weight, 0, (Result - 1));
end;

function MArrayHelper.MergeSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSW(var arr: MArray; var wgt: TDoubleArray; const L, R: Integer);
  var
    s: MArray;
    w: TDoubleArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSW(arr, wgt, L, m);
    MSW(arr, wgt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(w, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (wgt[i] <= wgt[j])) or ((not aAscending) and (wgt[i] >= wgt[j]))) of
        True:
        begin
          s[k] := arr[i];
          w[k] := wgt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          w[k] := wgt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      w[k] := wgt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      w[k] := wgt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      wgt[L + k] := w[k];
    end;
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    MSW(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSortWeighted>
  @action: Sorts the array Self in-place according to the values in the weight array.
           Both Self and weight are swapped together so that each element in Self
           maintains correspondence with its weight. Comparisons and pivot selection
           are determined by the weight array.
  @note: Supports ascending or descending order based on weight (controlled by aAscending).
         Returns the length of Self. Useful when you want to reorder an array according
         to external weights while preserving pairings.
[==============================================================================}
function MArrayHelper.QuickSortWeighted(var weight: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS(var A: MArray; var W: TIntegerArray; const L, R: Integer);
  var
    i, j, p: Integer;
  begin
    i := L;
    j := R;
    p := W[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (W[i] < p) do
          Inc(i);
        while (W[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (W[i] > p) do
          Inc(i);
        while (W[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS(A, W, L, j);
    if (i < R) then
      QS(A, W, i, R);
  end;
begin
  Result := Self.Size;
  if ((Result > 0) and (Result = weight.Size)) then
    QS(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSortWeighted>
  @action: Sorts the array Self in-place according to the values in the weight array.
           Both Self and weight are swapped together so that each element in Self
           maintains correspondence with its weight. Comparisons and pivot selection
           are determined by the weight array.
  @note: Supports ascending or descending order based on weight (controlled by aAscending).
         Returns the length of Self. Useful when you want to reorder an array according
         to external weights while preserving pairings.
[==============================================================================}
function MArrayHelper.QuickSortWeighted(var weight: TDoubleArray; const aAscending: Boolean = True): Integer; overload;
  procedure QS(var A: MArray; var W: TDoubleArray; const L, R: Integer);
  var
    p: Double;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := W[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (W[i] < p) do
          Inc(i);
        while (W[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (W[i] > p) do
          Inc(i);
        while (W[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(W[i], W[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS(A, W, L, j);
    if (i < R) then
      QS(A, W, i, R);
  end;
begin
  Result := Self.Size;
  if ((Result > 0) and (Result = weight.Size)) then
    QS(Self, weight, 0, (Result - 1));
end;

{==============================================================================]
  <QuickSorted>
  @action: Returns arr sorted by weight, based on QuickSort algorithm.
  @note: Weight and arr must be the same length! Otherwise returns empty array.
[==============================================================================}
function MArrayHelper.QuickSorted(const weight: TIntegerArray; const aAscending: Boolean = True): MArray; overload;
var
  w: Integer;
procedure QS_IDs(var aID: TIntegerArray; const L, R: Integer);
var
  c: Integer;
  a: TRange;
begin
  a.Create(L, R);
  w := weight[aID[a.Pivot]];
  repeat
    c := weight[aID[a.start]].Compare(w);
    while (aAscending and (c < 0)) or ((not aAscending) and (c > 0)) do
      c := weight[aID[a.start.Increment]].Compare(w);
    c := weight[aID[a.stop]].Compare(w);
    while (aAscending and (c > 0)) or ((not aAscending) and (c < 0)) do
      c := weight[aID[a.stop.Decrement]].Compare(w);
    if a.Ascending then
      Swap(aID[a.start.Increase], aID[a.stop.Decrease]);
  until a.Drops;
  if (L < a.stop) then
    QS_IDs(aID, L, a.stop);
  if (a.start < R) then
    QS_IDs(aID, a.start, R);
end;
var
  n, i: Integer;
  r: TIntegerArray;
begin
  n := Self.Size;
  if ((n > 0) and (n = weight.Size)) then
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

function MArrayHelper.QuickSorted(const weight: TDoubleArray; const aAscending: Boolean = True): MArray; overload;
var
  w: Double;
procedure QS_IDs(var aID: TIntegerArray; const L, R: Integer);
var
  c: Integer;
  a: TRange;
begin
  a.Create(L, R);
  w := weight[aID[a.Pivot]];
  repeat
    c := weight[aID[a.start]].Compare(w);
    while (aAscending and (c < 0)) or ((not aAscending) and (c > 0)) do
      c := weight[aID[a.start.Increment]].Compare(w);
    c := weight[aID[a.stop]].Compare(w);
    while (aAscending and (c > 0)) or ((not aAscending) and (c < 0)) do
      c := weight[aID[a.stop.Decrement]].Compare(w);
    if a.Ascending then
      Swap(aID[a.start.Increase], aID[a.stop.Decrease]);
  until a.Drops;
  if (L < a.stop) then
    QS_IDs(aID, L, a.stop);
  if (a.start < R) then
    QS_IDs(aID, a.start, R);
end;
var
  n, i: Integer;
  r: TIntegerArray;
begin
  n := Self.Size;
  if ((n > 0) and (n = weight.Size)) then
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