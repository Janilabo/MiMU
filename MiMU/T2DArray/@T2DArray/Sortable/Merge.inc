{$IFDEF HELPERS}
function Flattify(const oAscending: Boolean = True): MArray; overload;
function Flatty(const oAscending: Boolean = True): MArray; overload;
function KMerge(const oAscending: Boolean = True): MArray; overload;
function Marshal(const oAscending: Boolean = True; const method: UInt32 = 0): MArray; overload;
function Marshal(const method: UInt32): MArray; overload;
function Meld(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flattify>
  @action: Flattens a 2D array into a sorted 1D array result.
  @note: Uses an N-way merge scan. Input sub-arrays must be pre-sorted for 
         the result to be valid.
[==============================================================================}
function M2DArrayHelper.Flattify(const oAscending: Boolean = True): MArray; overload;
var
  h, s, i, r, b: Integer;
  a: TIntegerArray;
  f: Boolean;
  v: MType;
begin
  h := High(Self);
  if (h < 0) then
    Exit([]);
  s := 0;
  for i := 0 to a.Alloc(h + 1) do
  begin
    s := (s + Self[i].Length);
    a[i] := 0;
  end;
  for i := 0 to Result.Alloc(s) do
  begin
    f := False;
    b := -1;
    for r := 0 to h do
    begin
      if (a[r] >= Self[r].Length) then
        Continue;
      if not f then
      begin
        v := Self[r][a[r]];
        b := r;
        f := True;
      end else if ((oAscending and (Self[r][a[r]] < v)) or ((not oAscending) and (Self[r][a[r]] > v))) then
      begin
        v := Self[r][a[r]];
        b := r;
      end;
    end;
    if (b <> -1) then
    begin
      Result[i] := v;
      Inc(a[b]);
    end;
  end;
end;

{==============================================================================]
  <Flatty>
  @action: Flattens a 2D array into a 1D array while maintaining sorted order.
  @note: Uses an N-way merge algorithm.
         Assumes sub-arrays are already sorted (to oAscending).
[==============================================================================}
function M2DArrayHelper.Flatty(const oAscending: Boolean = True): MArray; overload;
var
  h, s, i, r, b: Integer;
  a: TIntegerArray;
  f: Boolean;
  v: MType;
begin
  s := 0;
  h := a.Alloc(Self.Length);
  for i := 0 to h do
  begin
    s := (s + Self[i].Length);
    a[i] := 0;
  end;
  case oAscending of
    True:
    for i := 0 to Result.Alloc(s) do
    begin
      f := False;
      b := -1;
      for r := 0 to h do
      begin
        if (a[r] >= Self[r].Length) then
          Continue;
        if not f then
        begin
          v := Self[r][a[r]];
          b := r;
          f := True;
        end else if (Self[r][a[r]] < v) then
        begin
          v := Self[r][a[r]];
          b := r;
        end;
      end;
      if (b <> -1) then
      begin
        Result[i] := v;
        Inc(a[b]);
      end;
    end;
    False:
    for i := 0 to Result.Alloc(s) do
    begin
      f := False;
      b := -1;
      for r := 0 to h do
      begin
        if (a[r] >= Self[r].Length) then
          Continue;
        if not f then
        begin
          v := Self[r][a[r]];
          b := r;
          f := True;
        end else if (Self[r][a[r]] > v) then
        begin
          v := Self[r][a[r]];
          b := r;
        end;
      end;
      if (b <> -1) then
      begin
        Result[i] := v;
        Inc(a[b]);
      end;
    end;
  end;
end;

{==============================================================================]
  <KMerge>
  @action: Performs a k-way merge across all rows of a 2D array, each assumed to
           be individually sorted, producing a single flat, fully sorted array. Order is
           ascending by default, or descending when oAscending is False.
  @note: Repeatedly selects the smallest (or largest) unconsumed head element
         across all non-empty rows and appends it to the result, advancing that row's
         cursor and dropping any row that becomes exhausted. Rows need not be equal
         in length; empty rows are skipped entirely.
[==============================================================================}
function M2DArrayHelper.KMerge(const oAscending: Boolean = True): MArray; overload;
var
  s: M2DArray;
  l, r, i, k: Integer;
  m: TIntegerArray;
  a: TRangeArray;
begin
  s := Self.Gleaned;
  if (s.Length = 0) then
    Exit([]);
  r := 0;
  l := 0;
  for i := 0 to m.Alloc(a.SetSize(s.Length)) do
  begin
    Inc(l, s[i].Length);
    m[r.Increase] := i;
    a[i].Create(0, High(s[i]));
  end;
  SetLength(Result, l);
  k := -1;
  case oAscending of
    True:
    while (r > 0) do
    begin
      l := 0;
      for i := 1 to (r - 1) do
        if (s[m[l]][a[m[l]].start] > s[m[i]][a[m[i]].start]) then
          l := i;
      Result[k.Increment] := s[m[l]][a[m[l]].start];
      Inc(a[m[l]].start);
      if a[m[l]].Descending then
        m[l] := m[r.Decrement];
    end;
    False:
    while (r > 0) do
    begin
      l := 0;
      for i := 1 to (r - 1) do
        if (s[m[l]][a[m[l]].start] < s[m[i]][a[m[i]].start]) then
          l := i;
      Result[k.Increment] := s[m[l]][a[m[l]].start];
      Inc(a[m[l]].start);
      if a[m[l]].Descending then
        m[l] := m[r.Decrement];
    end;
  end;
end;

{==============================================================================]
  <Marshal>
  @action: Flattens a 2D array into a single 1D array and sorts it using a
           selectable sorting algorithm, ascending by default.
  @note: Unlike Flattify/Flatty/KMerge/Meld, sub-arrays need NOT be
         pre-sorted — this concatenates all rows via Merge and then applies
         a full sort, rather than relying on an N-way merge scan. method
         selects the sort implementation: 0 QuickSort, 1 QuickSort3W,
         2 QSort, 3 MergeSort, 4 MergeSortBU, 5 ShellSort, 6 HeapSort,
         7 InsertionSort, 8 BubbleSort, 9 CombSort, 10 SelectionSort;
         any other value falls back to HybridSort.
[==============================================================================}
function M2DArrayHelper.Marshal(const oAscending: Boolean = True; const method: UInt32 = 0): MArray; overload;
begin
  Result := Self.Merge;
  if (Result.Length > 1) then
  case method of
    0: Result.QuickSort(oAscending);
    1: Result.QuickSort3W(oAscending);
	2: Result.QSort(oAscending);
    3: Result.MergeSort(oAscending);
    4: Result.MergeSortBU(oAscending);
    5: Result.ShellSort(oAscending);
    6: Result.HeapSort(oAscending);
    7: Result.InsertionSort(oAscending);
    8: Result.BubbleSort(oAscending);
    9: Result.CombSort(oAscending);
	10: Result.SelectionSort(oAscending);
  else
    Result.HybridSort(oAscending);
  end;
end;

function M2DArrayHelper.Marshal(const method: UInt32): MArray; overload;
begin
  Result := Self.Marshal(True, method);
end;

{==============================================================================]
  <Meld>
  @action: Performs a k-way merge across all rows of a 2D array, each assumed to
           be individually sorted, producing a single flat, fully sorted array. Order is
           ascending by default, or descending when oAscending is False.
  @note: Repeatedly selects the smallest (or largest) unconsumed head element
         across all non-empty rows and appends it to the result, advancing that row's
         cursor and dropping any row that becomes exhausted. Rows need not be equal
         in length; empty rows are skipped entirely.
[==============================================================================}
function M2DArrayHelper.Meld(const oAscending: Boolean = True): MArray; overload;
var
  l, r, i, k: Integer;
  m: TIntegerArray;
  a: TRangeArray;
begin
  if (Result.SetSize(Self.Total) = 0) then
    Exit;
  r := 0;
  for i := 0 to m.Alloc(a.SetSize(Self.Length)) do
    if (Self[i].Length > 0) then
    begin
      m[r.Increase] := i;
      a[i].Create(0, High(Self[i]));
    end;
  SetLength(m, r);
  k := -1;
  case oAscending of
    True:
    while (r > 0) do
    begin
      l := 0;
      for i := 1 to (r - 1) do
        if (Self[m[l]][a[m[l]].start] > Self[m[i]][a[m[i]].start]) then
          l := i;
      Result[k.Increment] := Self[m[l]][a[m[l]].start];
      Inc(a[m[l]].start);
      if a[m[l]].Descending then
        m[l] := m[r.Decrement];
    end;
    False:
    while (r > 0) do
    begin
      l := 0;
      for i := 1 to (r - 1) do
        if (Self[m[l]][a[m[l]].start] < Self[m[i]][a[m[i]].start]) then
          l := i;
      Result[k.Increment] := Self[m[l]][a[m[l]].start];
      Inc(a[m[l]].start);
      if a[m[l]].Descending then
        m[l] := m[r.Decrement];
    end;
  end;
end;
{$ENDIF}