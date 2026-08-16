{$IFDEF HELPERS}
function BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): MArray; overload;
function BinarySort(const aAscending: Boolean = True): Integer; overload;
function BinarySorted(const aAscending: Boolean = True): MArray; overload;
function BSort(const aAscending: Boolean = True): Integer; overload;
function BSorted(const aAscending: Boolean = True): MArray; Overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryInsertingSort>
  @action: Sorts the array in place using a binary-insertion approach.
           Each element is inserted into its correct position in the partially
           sorted portion of the array by performing a binary search to find
           the insertion point.
  @note:
    • Sorting is done in place, overwriting the original array.  
    • The optional parameter aAscending specifies sort order:
        - True  → ascending
        - False → descending  
    • Equality is determined using the Compare method of MType.  
    • Time complexity: O(n log n) for binary search + O(n²) for shifting,
      overall O(n²) in the worst case.  
    • Space complexity: O(n) due to the temporary copy used during sorting.  
    • Returns the length of the array.
[==============================================================================}
function MArrayHelper.BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
var
  a, i, m, c: Integer;
  s: MArray;
  r: TRange;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  SetLength(Self, 1);
  a := IfThen(aAscending, 1, -1);
  for i := 1 to (Result - 1) do
  begin
    r.Create(0, High(Self));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
	  c := s[i].Compare(Self[m]);
      if (c = 0) then
      begin
        r.start := m;
        Break;
      end;
      if (c = a) then
        r.start := (m + 1)
      else
	    r.stop := (m - 1);
    end;
    Insert(s[i], Self, r.start);
  end;
end;

{==============================================================================]
  <BinaryInsertingSorted>
  @action: Returns a new array containing all elements of the original array,
           sorted using binary-insertion. The original array is not modified.
  @note:
    • The returned array preserves the sorted order: ascending or descending,
      based on aAscending.  
    • Each element is inserted into the result array using binary search
      to find its correct position.  
    • Equality is determined using the Compare method of MType.  
    • Time complexity: O(n log n) for binary search + O(n²) for shifting,
      overall O(n²) worst case.  
    • Space complexity: O(n) due to building the new array.  
    • If the array contains fewer than two elements, a copy is returned unchanged.
[==============================================================================}
function MArrayHelper.BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
var
  l, a, i, m, c: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  Result := [Self[0]];
  a := IfThen(aAscending, 1, -1);
  for i := 1 to (l - 1) do
  begin
    r.Create(0, High(Result));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
	  c := Self[i].Compare(Result[m]);
      if (c = 0) then
      begin
        r.start := m;
        Break;
      end;
      if (c = a) then
        r.start := (m + 1)
      else
	    r.stop := (m - 1);
    end;
    Insert(Self[i], Result, r.start);
  end;
end;

{==============================================================================]
  <BinaryInsertionSort>
  @action: Sorts the array in ascending or descending order using binary
           insertion sort, which combines binary search and insertion.
  @note: This algorithm runs in O(n²) time in the worst case but uses binary
         search to minimize comparisons. It performs well on small or
         partially sorted datasets. Returns the number of elements sorted.
[==============================================================================}
function MArrayHelper.BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
  function BP(const value: MType; const hIndex: Integer): Integer;
  var
    L, R, M: Integer;
  begin
    L := 0;
    R := hIndex;
    while (L <= R) do
    begin
      M := ((L + R) div 2);
      if ((aAscending and (Self[M] > value)) or ((not aAscending) and (Self[M] < value))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    Result := L;
  end;
var
  k: MType;
  i, j, p: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  for i := 1 to (Result - 1) do
  begin
    k := Self[i];
    p := BP(k, (i - 1));
    j := (i + 1);
    while (j.Decrement > p) do
      Self[j] := Self[j - 1];
    Self[p] := k;
  end;
end;

{==============================================================================]
  <BinaryInsertionSorted>
  @action: Returns a new array sorted using the Binary Insertion Sort algorithm.
           The insertion position for each element is determined via binary search
           within the already sorted left partition.
  @note:
    - Stable sorting algorithm.
    - In-place with respect to the returned copy (original array is unchanged).
    - Comparison complexity: O(n log n).
    - Data movement complexity: O(n²) due to element shifting.
    - Performs efficiently on small or nearly sorted datasets.
[==============================================================================}
function MArrayHelper.BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
var
  s, i, j, m, p: Integer;
  k: MType;
  r: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  Result := Self.Copy;
  for i := 1 to (s - 1) do
  begin
    k := Result[i];
    p := 0;
    r.Create(0, (i - 1));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if ((aAscending and (k < Result[m])) or ((not aAscending) and (k > Result[m]))) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    p := r.start;
    j := i;
    while (j.Decrement >= p) do
      Result[j + 1] := Result[j];
    Result[p] := k;
  end;
end;

{==============================================================================]
  <BinaryInsertSort>
  @action: Sorts Self in place using binary insertion sort — for each
           element, its correct position among the already-sorted prefix
           is located via binary search (O(log n)), then elements are
           shifted right to make room.
  @note:
    - Sorts according to oAscending.
    - Stable: equal elements retain their original relative order, since
      ties are resolved by inserting the new element after existing
      equal elements (Loses returns False on equality, pushing the
      search right).
    - Time complexity: O(n log n) comparisons via binary search, but
      O(n²) overall due to the linear-time element shift on each
      insertion — same asymptotic class as standard insertion sort,
      just with fewer comparisons.
    - Returns Self.Length.
[==============================================================================}
function MArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
var
  s: MType;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Length;
  for i := 1 to (Result - 1) do
  begin
    s := Self[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if s.Loses(Self[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Self[j + 1] := Self[j.Decrease];
    Self[P] := s;
  end;
end;

{==============================================================================]
  <BinaryInsertSorted>
  @action: Returns a new array containing the elements of Self sorted via
           binary insertion sort. Self is not modified.
  @note:
    - Sorts according to oAscending.
    - Stable: equal elements retain their original relative order (ties
      resolve by inserting the new element after existing equal elements,
      since Loses returns False on equality).
    - Time complexity: O(n log n) comparisons via binary search, but
      O(n²) overall due to the linear-time element shift on each
      insertion — same asymptotic class as standard insertion sort.
[==============================================================================}
function MArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): MArray; overload;
var
  s: MType;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Copy;
  for i := 1 to High(Result) do
  begin
    s := Result[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if s.Loses(Result[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Result[j + 1] := Result[j.Decrease];
    Result[P] := s;
  end;
end;

{==============================================================================]
  <BinarySort>
  @action: Sorts Self in place using binary insertion sort, locating each
           element's position via three-way comparison (Compare).
  @note:
    - Sorts according to aAscending.
    - Returns High(Self).
    - Ties are resolved leftward: a newly-placed element is inserted
      before any existing equal elements, not after.
[==============================================================================}
function MArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; overload;
var
  a, j, m, i, o: Integer;
  s: MType;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for j := 1 to Result do
    begin
      s := Self[j];
      r.Create(0, j);
      while r.Ascends do
      begin
        m := r.Pivot;
        if (Self[m].Compare(s) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Self[i] := Self[i - 1];
      Self[r.start] := s;
    end;
  end;
end;

{==============================================================================]
  <BinarySorted>
  @action: Returns a new array containing the elements of Self sorted via
           binary insertion sort, locating each element's position via
           three-way comparison (Compare). Self is not modified.
  @note:
    - Sorts according to aAscending.
    - Ties are resolved leftward: a newly-placed element is inserted
      before any existing equal elements, not after.
[==============================================================================}
function MArrayHelper.BinarySorted(const aAscending: Boolean = True): MArray; overload;
var
  j, m, i, o: Integer;
  s: MType;
  r: TRange;
begin
  if (Result.SetSize(Self.Length) > 0) then
  begin
    o := aAscending.Select(-1, 1);
    Result[0] := Self[0];
    for j := 1 to High(Result) do
    begin
      s := Self[j];
      r.Create(0, j);
      while r.Ascends do
      begin
        m := r.Pivot;
        if (Result[m].Compare(s) = o) then
          r.start := (m + 1)
        else
          r.stop := m;
      end;
      for i := j downto (r.start + 1) do
        Result[i] := Result[i - 1];
      Result[r.start] := s;
    end;
  end;
end;

{==============================================================================]
  <BSort>
  @action: Sorts Self in place using binary insertion sort, locating each
           element's position via three-way comparison (Compare) and
           inserting with the RTL's dynamic-array Insert procedure.
  @note:
    - Sorts according to aAscending.
    - Not guaranteed stable.
    - Time complexity: O(n log n) comparisons via binary search; O(n²)
      overall due to per-insertion shift cost (via Insert).
[==============================================================================}
function MArrayHelper.BSort(const aAscending: Boolean = True): Integer; overload;
var
  C, i, M: Integer;
  s: MArray;
  R: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  SetLength(Self, 1);
  for i := 1 to (Result - 1) do
  begin
    R.Create(0, High(Self));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Self[M].Compare(s[i])
      else
        C := s[i].Compare(Self[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
	    begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(s[i], Self, R.start);
  end;
end;

{==============================================================================]
  <BSorted>
  @action: Returns a new array containing the elements of Self sorted via
           binary insertion sort, locating each element's position via
           three-way comparison (Compare) and inserting with the RTL's
           dynamic-array Insert procedure. Self is not modified.
  @note:
    - Sorts according to aAscending.
    - Not guaranteed stable.
    - Time complexity: O(n log n) comparisons via binary search; O(n²)
      overall due to per-insertion shift cost (via Insert).
[==============================================================================}
function MArrayHelper.BSorted(const aAscending: Boolean = True): MArray; Overload;
var
  C, i, M: Integer;
  R: TRange;
begin
  if (Self.Size < 2) then
    Exit(Self.Copy);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
  begin
    R.Create(0, High(Result));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Result[M].Compare(Self[i])
      else
        C := Self[i].Compare(Result[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
        begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(Self[i], Result, R.start);
  end;
end;
{$ENDIF}
