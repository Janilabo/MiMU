{$IFDEF HELPERS}
function BinaryAddress(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryConverge(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryEntry(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindID(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindIndex(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGallopingSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryInsertPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryMetaSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPlace(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryProbe(const item: MType; const oAscending: Boolean = True; const probeRadius: Integer = 5): Integer; overload;
function BinaryProbe(const item: MType; const probeRadius: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryProxy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySpot(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryUniformSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAddress>
  @action: Performs a binary search to find the **index of a specific item** in a sorted array.
           Behavior:
           - If the item exists in the array, returns its index.
           - If the item does not exist, returns `not InsertIndex`, where `InsertIndex` 
             is the position where the item could be inserted to maintain the array’s sort order.
           Supports both ascending and descending arrays using the `oAscending` parameter.
  @param oAscending
           Indicates the sort order of the array:
           - True  → ascending order
           - False → descending order
  @note:   The array must already be sorted according to `oAscending`.
           Uses a closed interval binary search [start..stop].
           Return value follows the Delphi “InsertIndex” convention:
             - Non-negative index → exact match found
             - Negative value → `not InsertIndex`, the bitwise complement of the insertion position
           Time complexity is O(log n).
[==============================================================================}
function MArrayHelper.BinaryAddress(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := not R.start;
end;

{==============================================================================]
  <BinaryConverge>
  @action: Performs binary search convergence and returns the candidate index
           reached by the search path.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function searches for the specified item and returns:
           - The index of the item if found.
           - Otherwise the terminal convergence candidate index of the binary
             search path.
         Returns:
           0..Length(Self)-1 -> array index candidate
           -1                -> array is empty
         This function does not guarantee that the item exists in the array.
         It represents the final convergence position of the binary search
         traversal.
[==============================================================================}
function MArrayHelper.BinaryConverge(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    Result := M;
    if (Self[M] = item) then
      Break;
    if ((Self[M] < item) = oAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryEntry>
  @action: Perform a binary search on a sorted array (ascending or descending)
  @note: Returns the index if found; otherwise returns not R.start (negative insert position)
[==============================================================================}
function MArrayHelper.BinaryEntry(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(not 0);
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = target) then
        Exit(M);
      if (Self[M] < target) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = target) then
        Exit(M);
      if (Self[M] > target) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  Result := not R.start;
end;

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
  <BinaryFindID>
  @action: Locates the specified item in the sorted array using binary search
           and returns its array index position.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns the 0-based index position of the first
         occurrence of the item in the array.
         Returns:
           0..Length(Self)-1 -> array index of the item
           -1                -> item does not exist in the array
         Internally uses BinaryBoundLower to determine the candidate
         position and verifies equality before returning the index.
[==============================================================================}
function MArrayHelper.BinaryFindID(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryBoundLower(item, oAscending);
  if not ((Result < Self.Length) and (Self[Result] = item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryFindIndex>
  @action: Locates the specified item in the sorted array using binary search
           and returns its array index position.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns the 0-based index position of the first
         occurrence of the item in the array.
         Returns:
           0..Length(Self)-1 -> array index of the item
           -1                -> item does not exist in the array
         Internally uses BinaryBoundLower to determine the candidate
         position and verifies equality before returning the index.
[==============================================================================}
function MArrayHelper.BinaryFindIndex(const item: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryBoundLower(item, oAscending);
  if ((Result = Self.Length) or (Self[Result] <> item)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryGallopingSearch>
  @action: Performs an exponential (galloping) range expansion to locate a bounded
           interval that may contain the specified item, followed by a binary search
           refinement within that interval.
           Returns the zero-based index of the matching element if found;
           otherwise returns -1.
  @note:
    - The array must be globally sorted in either ascending or descending
      order, as specified by oAscending.
    - Time complexity is O(log k), where k is the index distance to the target.
    - Particularly efficient when the sought element is located near the
      beginning of the array.
    - If duplicate values exist, any matching index may be returned.
[==============================================================================}
function MArrayHelper.BinaryGallopingSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  B, H, M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  H := High(Self);
  B := 1;
  case oAscending of
    True:
    begin
      while ((B <= H) and (Self[B] < item)) do
        B := (B shl 1);
      R.Create((B shr 1), Min(B, H));
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = item) then
          Exit(M);
        if (Self[M] < item) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
    end;
    False:
    begin
      while ((B <= H) and (Self[B] > item)) do
        B := (B shl 1);
      R.Create((B shr 1), Min(B, H));
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = item) then
          Exit(M);
        if (Self[M] > item) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryInsertPosition>
  @action: Returns the insertion position where the specified item should be
           inserted to maintain sorted array order.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         The function returns:
           0 .. Length(Self)
           Position where item should be inserted.
         If the item already exists, the insertion position will be the
         first occurrence boundary.
[==============================================================================}
function MArrayHelper.BinaryInsertPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Length;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if not ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
    begin
      Result := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
end;

{==============================================================================]
  <BinaryMetaSearch>
  @action: Performs a binary-like search on a sorted array to find the index of a given item.
  @note:
    • O(log n)
    • Requires sorted array (ascending or descending)
    • Returns index of item if found
    • Returns -1 if item is not in the array
    • Uses a binary meta-step approach instead of classic binary search
[==============================================================================}
function MArrayHelper.BinaryMetaSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l, p, i, s: Integer;
begin
  l := Self.Length;
  i := (1 shl Trunc(Log2(l)));
  p := 0;
  while (i > 0) do
  begin
    s := (p or i);
    if ((s < l) and ((oAscending and (Self[s] <= item)) or ((not oAscending) and (Self[s] >= item)))) then
      p := s;
    i := (i shr 1);
  end;
  if ((p < l) and (Self[p] = item)) then
    Result := p
  else
    Result := -1;
end;

{==============================================================================]
  <BinaryPlace>
  @action: Performs a standard binary search to find the exact index of the target 
           value in a sorted array (ascending or descending depending on `oAscending`).
           Behavior:
           - If the target exists in the array, returns its index.
           - If the target does not exist, returns `not InsertIndex` 
             where `InsertIndex` is the position where the target could be inserted
             to maintain the array’s sort order.
  @note:   The array must already be sorted according to `oAscending`.
           Uses a closed interval binary search [start..stop].
           Return value follows the Delphi “InsertIndex” convention:
             - Non-negative index → exact match found
             - Negative value → `not InsertIndex`, the bitwise complement of the insertion position
           Time complexity is O(log n).
[==============================================================================}
function MArrayHelper.BinaryPlace(const target: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = target) then
      Exit(M);
    if ((oAscending and (Self[M] < target)) or ((not oAscending) and (Self[M] > target))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := not R.start;
end;

{==============================================================================]
  <BinaryProbe>
  @action: Performs a hybrid divide-and-conquer search for `item` within the
           current array. At each binary pivot, the function first checks the
           pivot element and then linearly probes a symmetric neighborhood
           around the pivot defined by `probeRadius`. If no match is found
           within the probe window, the binary reduction continues.
           Returns the index of a matching element if found; otherwise returns -1.
  @note:
    - The array must be sorted according to `oAscending`.
    - The probe window at each iteration is:
        [M - probeRadius .. M + probeRadius]
      clamped to the current search bounds.
    - Effective window width is (2 * probeRadius + 1).
    - If duplicates exist, any matching index may be returned.
    - Worst-case time complexity remains O(log n), but each iteration
      incurs up to O(probeRadius) additional comparisons.
    - If probeRadius is 0, behavior degenerates to standard binary search.
    - No internal validation of sortedness is performed.
    - If the array is empty, returns -1.
[==============================================================================}
function MArrayHelper.BinaryProbe(const item: MType; const oAscending: Boolean = True; const probeRadius: Integer = 5): Integer; overload;
var
  M, I: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    for I := Max(R.start, (M - probeRadius)) to Min(R.stop, (M + probeRadius)) do
      if (Self[I] = item) then
        Exit(I);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := -1;
end;

function MArrayHelper.BinaryProbe(const item: MType; const probeRadius: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.BinaryProbe(item, oAscending, probeRadius);
end;

{==============================================================================]
  <BinaryProxy>
  @action: Performs a binary search for a value in a sorted array and returns
           the index of the last pivot inspected during the search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the matching element if `item` exists
           - Otherwise the index of the last pivot examined during the
             binary search (a position near where the item would appear)
           - -1 if the array is empty
         This method provides a fast approximate location that can be used
         as a starting point for nearby searches or adjustments.
[==============================================================================}
function MArrayHelper.BinaryProxy(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  Result := 0;
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
  <BinaryUniformSearch>
  @action: Performs a stepwise power-of-two probing search on a sorted array using
           precomputed uniform binary stepping. The algorithm first determines the
           largest exponential step size not exceeding the search interval and then
           repeatedly halves the step size while moving the probe index.
           Returns the index of the matching element if found; otherwise returns -1.
  @note:
    - The array must be monotonically sorted according to oAscending.
    - This algorithm is a variant of meta-binary (uniform binary) search.
    - Pivot movement is performed using fixed exponential step offsets rather
      than dynamic midpoint division.
    - Division operations are eliminated inside the main probing loop.
    - Time complexity is O(log n).
    - If duplicate values exist, any matching index may be returned.
    - If Self is empty, the function returns -1.
[==============================================================================}
function MArrayHelper.BinaryUniformSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  S, M, K: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  S := 1;
  while (S <= (R.stop - R.start)) do
    S := (S shl 1);
  S := (S shr 1);
  while (S > 0) do
  begin
    K := (R.start + S);
    if ((K <= R.stop) and ((oAscending and (Self[K] <= item)) or ((not oAscending) and (Self[K] >= item)))) then
      R.start := K;
    S := (S shr 1);
  end;
  if ((R.start <= R.stop) and (Self[R.start] = item)) then
    Exit(R.start);
  Result := -1;
end;
{$ENDIF}