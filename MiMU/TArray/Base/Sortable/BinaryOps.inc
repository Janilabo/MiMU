{$IFDEF HELPERS}
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryIdentify(const aIndex: Integer; const iItems: MArray; const iAscending: Boolean = True): Integer; overload;
function BinaryInsertingSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertingSorted(const aAscending: Boolean = True): MArray; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function BinaryInsertionSorted(const aAscending: Boolean = True): MArray; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySpot(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryExpSearch>
  @action: Performs an exponential (galloping) search to locate the specified
           item in a sorted TIntegerArray. Returns the index of the item if
           found; otherwise returns -1. Combines exponential range expansion
           with standard binary search within the identified range.
  @note: The array must be pre-sorted according to 'oAscending'. Efficient
         for large arrays or targets near the beginning. Supports ascending
         (default) and descending arrays. Time complexity is O(log n).
[==============================================================================}
function MArrayHelper.BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  B, L: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(-1);
  B := 1;
  while ((B < L) and ((oAscending and (Self[B] < item)) or ((not oAscending) and (Self[B] > item)))) do
    B := (B * 2);
  R.Create((B div 2), Min(B, (L - 1)));
  while (R.start <= R.stop) do
  begin
    Result := R.Pivot;
    if (Self[Result] = item) then
      Exit;
    if ((oAscending and (Self[Result] < item)) or ((not oAscending) and (Self[Result] > item))) then
      R.start := (Result + 1)
    else
      R.stop := (Result - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryGot>
  @action: Performs a binary search on the array to determine
           whether a specified value exists and returns its index if found.
  @note: Assumes the array is pre-sorted in either ascending or descending
         order, depending on the oAscending flag. Uses TRange utilities
         for interval reduction; returns -1 when the item is not present.
[==============================================================================}
function MArrayHelper.BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    if (Self[index] = item) then
      Exit(True);
    if ((oAscending and (Self[index] < item)) or ((not oAscending) and (Self[index] > item))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end;

{==============================================================================]
  <BinaryHas>
  @action: Checks whether the specified item exists in the sorted integer array.
           Returns True if the item is found, otherwise False. If found, the
           index of the item is returned via the 'out' parameter.
  @note: The array must be pre-sorted according to the order specified by
         'oAscending'. Supports both ascending and descending arrays. Uses
          a standard binary search algorithm to efficiently locate the item.
[==============================================================================}
function MArrayHelper.BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  R: TRange;
  C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := Self[index].Compare(item);
	if (C = 0) then
	  Exit(True);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  Result := False;
  index := -1;
end;

{==============================================================================]
  <BinaryHits>
  @action: Performs a binary search for each value in the supplied array
           `items` against the current integer array and returns the indices
           of all values that are found.
  @note:   The current array (`Self`) must be sorted according to the
           `oAscending` flag prior to calling this method. The result contains
           only successful hit indices, in the same order as the `items`
           parameter. Items not found are silently ignored.
[==============================================================================}
function MArrayHelper.BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, p, k: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  SetLength(Result, items.Length);
  k := 0;
  for i := 0 to High(items) do
  begin
    p := Self.BinarySearchBy(items[i], oAscending);
    if (p >= 0) then
      Result[k.Increase] := p;
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <BinaryHitsOf>
  @action: Performs a binary search for each element in the supplied array `items`
           against the current array (`Self`) and returns the indices of all elements
           that are found.
           For every value in `items`, `BinarySearch` is invoked on `Self`. If the value
           exists, the index returned by `BinarySearch` is collected into the result
           array. The result therefore represents the hit positions within `Self`,
           not within `items`.
  @note:
    - `Self` must be sorted according to the order specified by `oAscending`
      for `BinarySearch` to operate correctly.
    - If either `Self` or `items` is empty, the function returns an empty array.
    - If the same value appears multiple times in `items`, its hit index in
      `Self` may appear multiple times in the result.
    - The function performs two passes over `items`: one to count hits and one
      to populate the result array.
[==============================================================================}
function MArrayHelper.BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, p, r: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  r := 0;
  for i := 0 to High(items) do
    if (Self.BinarySearchBy(items[i], oAscending) >= 0) then
      Inc(r);
  SetLength(Result, r);
  r := 0;
  for i := 0 to High(items) do
  begin
    p := Self.BinarySearchBy(items[i], oAscending);
    if (p >= 0) then
      Result[r.Increase] := p;
  end;
end;

{==============================================================================]
  <BinaryIdentify>
  @action: Performs a binary search to find the position of the element at aIndex
           within a sorted array (items). Returns the zero-based index of the matching element.
  @note:
    • The array (items) must be sorted in ascending or descending order,
      as specified by iAscending.
    • Returns -1 if:
      - aIndex is out of bounds, or
      - the value is not found in items.
    • This method is optimized for large arrays, providing O(log n) search
      complexity compared to a linear scan.
[==============================================================================}
function MArrayHelper.BinaryIdentify(const aIndex: Integer; const iItems: MArray; const iAscending: Boolean = True): Integer; overload;
begin
  if ((aIndex  > -1) and (aIndex < Self.Length)) then
    Result := iItems.BinarySearchBy(Self[aIndex], iAscending)
  else
    Result := -1;
end;

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
  <BinarySearchBy>
  @action: Performs a binary search over the array using a
           comparator-based comparison. Returns the index of the specified
           item if found, or -1 if the item is not present. Supports arrays
           sorted in ascending or descending order.
  @note: The input array must be pre-sorted according to the order specified
         by the oAscending parameter. This function uses a standard binary
         search algorithm: repeatedly divides the search interval in half
         until the target item is found or the interval is empty.
         Comparisons are performed using Integer_Compare, allowing for
         consistent ordering and potential extension to other comparison logic.
[==============================================================================}
function MArrayHelper.BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  R: TRange;
  M, C: Integer;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    C := Self[M].Compare(item);
    if (C = 0) then
      Exit(M);
    if ((oAscending and (C < 0)) or ((not oAscending) and (C > 0))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySpot>
  @action: Performs a high-speed binary search to locate the index of a item 
           value or identify its ideal insertion point within a sorted array.        
  @note: 
    - The array MUST be pre-sorted according to the [oAscending] parameter.
    - If Found: Returns the 0-based index [0..High].
    - If Not Found: Returns the bitwise NOT of the start index (not R.start), 
      representing the position where the item should be inserted to 
      preserve order.
    - Complexity: O(log n).
[==============================================================================}
function MArrayHelper.BinarySpot(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M)
    else if (oAscending = (Self[M] < item)) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := not R.start;
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts the item x into the array at the correct position to maintain
           sorted order. Supports both ascending and descending order.
  @note:
    • The array must already be sorted according to aAscending.  
    • If aAscending = True, ascending order is assumed;  
      if aAscending = False, descending order is assumed.  
    • The value is not inserted if it already exists in the array.  
    • Returns True if the value was inserted, False if it already exists.  
    • Search complexity: O(log n).  
    • Insertion (element shift) complexity: O(n).  
    • Overall complexity: O(n).  
    • The array is resized when insertion occurs.
[==============================================================================}
function MArrayHelper.BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
	if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> item));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := item;
end;
{$ENDIF}
