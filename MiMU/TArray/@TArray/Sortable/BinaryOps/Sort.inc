{$IFDEF HELPERS}
function BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
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
{$ENDIF}