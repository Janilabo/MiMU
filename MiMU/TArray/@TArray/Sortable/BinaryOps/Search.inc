{$IFDEF HELPERS}
function BinaryAddress(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryConverge(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryEntry(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFind(const item: mType; const aAscending: Boolean): Integer; overload;
function BinaryFind(const item: mType; const scan: TRange; const ascending: Boolean = True): Integer; overload;
function BinaryFindID(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindIndex(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGallopingSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryHybridSearch(const item: MType; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
function BinaryHybridSearch(const item: MType; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryIndex(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryIndexFor(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryIndexOf(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryInsertPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryLocalize(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryLookup(const item: MType): Integer; overload;
function BinaryMetaSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPlace(const target: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPoint(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPos(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryPositionOf(const item: MType; const chunkRadius: Integer = 5; const oAscending: Boolean = True): Integer; overload;
function BinaryPositionOf(const item: MType; const oAscending: Boolean; const chunkRadius: Integer = 5): Integer; overload;
function BinaryProbe(const item: MType; const oAscending: Boolean = True; const probeRadius: Integer = 5): Integer; overload;
function BinaryProbe(const item: MType; const probeRadius: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryProxy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryRank(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinarySearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySearchEx(const item: MType; const ignore: MType; const aAscending: Boolean = True): Integer; overload;
function BinarySearchNth(const item: MType; const N: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchRange(const item: MType; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const item: MType; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySeek(const item: MType; const aAscending: Boolean = True): Integer; overload;
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
  <BinaryFind>
  @action: Performs a binary search on a sorted array to locate a specific item.
  @note: The array must be sorted in either ascending or descending order,
         as specified by `aAscending`. If the item is found, its index is
         returned; otherwise, -1 is returned. This function assumes there are
         no ignored or placeholder values in the array.
[==============================================================================}
function MArrayHelper.BinaryFind(const item: mType; const aAscending: Boolean): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  Result := -1;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Exit(m);
    if (IfThen(aAscending, Ord(Self[m] < item), Ord(Self[m] > item)) <> 0) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search for `item` within the sub-range `scan` of
           a sorted array.
  @note: `scan` is normalized and clamped to the array bounds before the
         search begins, so out-of-range or reversed bounds are handled
         safely. The array (within `scan`) must be sorted in either
         ascending or descending order, as specified by `ascending`. If the
         item is found, its index is returned; otherwise, -1 is returned.
         This function assumes there are no ignored or placeholder values
         in the array.
[==============================================================================}
function MArrayHelper.BinaryFind(const item: mType; const scan: TRange; const ascending: Boolean = True): Integer; overload;
var
  M: Integer;
  S: TRange;
begin
  if Self.Empty then
    Exit(-1);
  S := scan.Normalize;
  S.start := Max(0, S.start);
  S.stop := Min(High(Self), S.stop);
  while (S.start <= S.stop) do
  begin
    M := S.Pivot;
    if (Self[M] = item) then
      Exit(M);
    case ascending of
      True:
      if (Self[M] < item) then
        S.start := (M + 1)
      else
        S.stop := (M - 1);
      False:
      if (Self[M] > item) then
        S.start := (M + 1)
      else
        S.stop := (M - 1);
    end;
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
  <BinaryHybridSearch>
  @action: Searches a sorted array for `item`, narrowing the range with
           binary search until it shrinks to `threshold` elements or fewer,
           then finishing with a linear scan over the remainder.
  @note: The array must be sorted in either ascending or descending order,
         as specified by `oAscending`. Falling back to a linear scan below
         `threshold` avoids the overhead of pivot calculation and branch
         misprediction on small ranges, where a straight scan is typically
         faster. If the item is found, its index is returned; otherwise,
         -1 is returned. This function assumes there are no ignored or
         placeholder values in the array.
[==============================================================================}
function MArrayHelper.BinaryHybridSearch(const item: MType; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while ((R.stop - R.start) > threshold) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    if ((oAscending and (item < Self[M])) or ((not oAscending) and (item > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  for M := R.start to R.stop do
    if (Self[M] = item) then
      Exit(M);
end;

function MArrayHelper.BinaryHybridSearch(const item: MType; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while ((R.stop - R.start) > threshold) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M);
    if ((oAscending and (item < Self[M])) or ((not oAscending) and (item > Self[M]))) then
      R.stop := (M - 1)
    else
      R.start := (M + 1);
  end;
  for M := R.start to R.stop do
    if (Self[M] = item) then
      Exit(M);
end;

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given item in the sorted array using binary search.
  @note: If the item is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function MArrayHelper.BinaryIndex(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m] = item) then
      Exit(m)
    else if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
end;

{==============================================================================]
  <BinaryIndexFor>
  @action: Performs a recursive binary search for `item` in a sorted array,
           returning its index.
  @note: The array must be sorted in either ascending or descending order,
         as specified by `oAscending`. Pivot is computed as `(L + H) shr 1`.
         If the item is found, its index is returned; otherwise, -1 is
         returned. This function assumes there are no ignored or
         placeholder values in the array.
[==============================================================================}
function MArrayHelper.BinaryIndexFor(const item: MType; const oAscending: Boolean = True): Integer; overload;
  function BS(const L, H: Integer): Integer;
  var
    M: Integer;
  begin
    if (L > H) then
      Exit(-1);
    M := ((L + H) shr 1);
    if (Self[M] = item) then
      Exit(M);
    if ((Self[M] < item) = oAscending) then
      Result := BS((M + 1), H)
    else
      Result := BS(L, (M - 1));
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryIndexOf>
  @action: Performs a recursive binary search for `item` in a sorted array,
           returning its index.
  @note: The array must be sorted in either ascending or descending order,
         as specified by `oAscending`. Pivot is computed as
         `L + (R - L) div 2` to avoid integer overflow on large bounds.
         If the item is found, its index is returned; otherwise, -1 is
         returned. This function assumes there are no ignored or
         placeholder values in the array.
[==============================================================================}
function MArrayHelper.BinaryIndexOf(const item: MType; const oAscending: Boolean = True): Integer; overload;
  function BS(const L, R: Integer): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if (Self[M] = item) then
      Exit(M);
    if ((oAscending and (item < Self[M])) or ((not oAscending) and (item > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
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
  <BinaryLocalize>
  @action: Determines the insertion position for a specified item within
           a sorted array.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the item should be inserted to maintain sort order.
         - If the item already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function MArrayHelper.BinaryLocalize(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  R, M: Integer;
begin
  Result := 0;
  R := Self.Size;
  while (Result < R) do
  begin
    M := ((Result + R) div 2);
    if ((aAscending and (Self[M] < item)) or ((not aAscending) and (Self[M] > item))) then
      Result := (M + 1)
    else
      R := M;
  end;
end;

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified item.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the item if found; otherwise returns -1.
  @note: The array must be monotonic (fully ascending or fully descending).
         If the array contains duplicates, the function returns an arbitrary occurrence.
         This method does not modify the array.
[==============================================================================}
function MArrayHelper.BinaryLookup(const item: MType): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop > -1) then
  case (Self[R.start] <= Self[R.stop]) of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = item) then
        Exit(M);
      if (item < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = item) then
        Exit(M);
      if (item > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
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
  <BinaryPoint>
  @action: Determines the positional index at which `item` should be inserted
           to preserve the array's sorted order. Returns the first index whose
           element is not less than `item` when ascending, or not greater than
           `item` when descending. If all elements are less (ascending) or
           greater (descending), returns Length(Self).
  @note: This routine does not search for an existing match. It calculates the
         stable insertion point (lower-bound position) using binary search.
         The array must already be sorted according to `oAscending`. The
         returned index will always be in the range 0..Length(Self).
[==============================================================================}
function MArrayHelper.BinaryPoint(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  case oAscending of
    True:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < item) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
    False:
    begin
      Result := Self.Size;
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > item) of
          False:
          begin
            Result := M;
            R.stop := (M - 1);
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryPos>
  @action: Performs a binary search on a sorted array using standard operator comparisons (< and =).
           Returns the index of the matching item.
  @note: Operates on both ascending and descending sorted arrays.
[==============================================================================}
function MArrayHelper.BinaryPos(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = item) then
        Exit(M);
      if (item < Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = item) then
        Exit(M);
      if (item > Self[M]) then
        R.stop := (M - 1)
      else
        R.start := (M + 1);
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryPosition>
  @action: Performs a binary search on a sorted array using the object's custom `.Compare()` method adjusted by sort order.
  @note: Returns the index of the matching item.
[==============================================================================}
function MArrayHelper.BinaryPosition(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  O, M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  O := IfThen(oAscending, 1, -1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (item.Compare(Self[M]) * O) of
      0: Exit(M);
      -1: R.stop := (M - 1);
      1: R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryPositionOf>
  @action: Performs a binary search for `item`, but at each pivot also
           probes a fixed-radius chunk of neighboring elements first; if
           `item` falls within that chunk's value range, delegates to a
           bounded `BinaryFind` over just that chunk instead of continuing
           the full-range search.
  @note: The array must be sorted in either ascending or descending order,
         as specified by `ascending`. `chunkRadius` controls how many
         elements on either side of the pivot are checked per iteration.
         If the item is found, its index is returned; otherwise, -1 is
         returned. This function assumes there are no ignored or
         placeholder values in the array.
[==============================================================================}
function MArrayHelper.BinaryPositionOf(const item: MType; const chunkRadius: Integer = 5; const oAscending: Boolean = True): Integer; overload;
var
  H, M: Integer;
  S, R: TRange;
begin
  H := High(Self);
  S.Create(0, H);
  while (S.start <= S.stop) do
  begin
    M := S.Pivot;
    if (Self[M] = item) then
      Exit(M);
    R.Create(Max(0, (M - chunkRadius)), Min(H, (M + chunkRadius)));
    if (Self[R.start] = item) then
      Exit(R.start)
    else if (Self[R.stop] = item) then
      Exit(R.stop);
    if ((oAscending and ((item >= Self[R.start]) and (item <= Self[R.stop]))) or ((not oAscending) and ((item <= Self[R.start]) and (item >= Self[R.stop])))) then
      Exit(Self.BinaryFind(item, R, oAscending));
    case oAscending of
      True:
      if (Self[M] < item) then
        S.start := (M + 1)
      else
        S.stop := (M - 1);
      False:
      if (Self[M] > item) then
        S.start := (M + 1)
      else
        S.stop := (M - 1);
    end;
  end;
  Result := -1;
end;

function MArrayHelper.BinaryPositionOf(const item: MType; const oAscending: Boolean; const chunkRadius: Integer = 5): Integer; overload;
begin
  Result := Self.BinaryPositionOf(item, chunkRadius, oAscending);
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
  <BinaryRank>
  @action: Returns the insertion index (rank) of a item in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function MArrayHelper.BinaryRank(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        while ((m > 0) and (Self[m - 1] = item)) do
          Dec(m);
        Exit(m);
      end;
      False:
      if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  Result := r.start;
end;

{==============================================================================]
  <BinarySearch>
  @action: Searches for the index of a specified item in a sorted array using binary search. Returns -1 if the item is not found.
  @note: Uses efficient XOR boolean logic (`(Self[m] < item) xor (not oAscending)`) to support both ascending and descending sorted arrays without branching or helper overhead.
[==============================================================================}
function MArrayHelper.BinarySearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m: Integer;
  s: TRange;
begin
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Pivot;
    if (Self[m] = item) then
      Exit(m);
    if ((Self[m] < item) xor (not oAscending)) then
      s.start := (m + 1)
    else
      s.stop := (m - 1);
  end;
  Result := -1;
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
  <BinarySearchEx>
  @action: Performs a binary search on a sorted array to locate a specific item,
           skipping over ignored elements and supporting both ascending and descending order.
  @note: The array must be pre-sorted according to the `aAscending` flag. Elements equal
         to `ignore` are bypassed when searching. Returns the index of a matching element
         (not guaranteed to be the first if duplicates exist), or -1 if the item is not
         found or if all elements are ignored.
[==============================================================================}
function MArrayHelper.BinarySearchEx(const item: MType; const ignore: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, l, r: Integer;
  s: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  while (s.start <= s.stop) do
  begin
    m := s.Center;
    if (Self[m] = ignore) then
    begin
      l := (m - 1);
      r := (m + 1);
      while ((l >= s.start) or (r <= s.stop)) do
      begin
        if ((l >= s.start) and (Self[l] <> ignore)) then
        begin
          m := l;
          Break;
        end;
        if ((r <= s.stop) and (Self[r] <> ignore)) then
        begin
          m := r;
          Break;
        end;
        Dec(l);
        Inc(r);
      end;
      if ((l < s.start) and (r > s.stop)) then
        Exit(-1);
    end;
    case (Self[m] = item) of
      False:
      if IfThen(aAscending, (Self[m] < item), (Self[m] > item)) then
        s.start := (m + 1)
      else
        s.stop := (m - 1);
      True: Exit(m);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchNth>
  @action: Returns the index of the N-th occurrence of the given item in the array.
  @note:
    - Uses binary search to locate the first occurrence of the item, then adds N to find the N-th occurrence.
    - Returns -1 if:
        * N is out of bounds (negative or larger than the array size),
        * the item is not found,
        * or the N-th occurrence does not exist.
    - Works for both ascending and descending sorted arrays (controlled by oAscending).
[==============================================================================}
function MArrayHelper.BinarySearchNth(const item: MType; const N: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  if ((N < 0) or (N > High(Self))) then
    Exit(-1);
  Result := Self.BinarySearchFirst(item, oAscending);
  if (Result > -1) then
    Inc(Result, N);
  if ((Result > -1) and ((Result > High(Self)) or (Self[Result] <> item))) then
    Result := -1;
end;

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a item within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function MArrayHelper.BinarySearchRange(const item: MType; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(rLeft, rRight);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(M)
    else if ((aAscending and (Self[M] < item)) or ((not aAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinarySearchSpan>
  @action: Performs a recursive binary search for an exact item within a specified
           sub-range [L, R] of a sorted array, supporting ascending or descending order.
  @note: The array must be pre-sorted according to `aAscending` across the given
         [L, R] span. Returns the index of `item` if found, or -1 if L > R, L < 0,
         R exceeds the array's upper bound, or `item` is not present within [L, R].
[==============================================================================}
function MArrayHelper.BinarySearchSpan(const item: MType; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
begin
  if ((L > R) or (L < 0) or (R > High(Self))) then
    Exit(-1);
  M := (L + ((R - L) div 2));
  if (Self[M] = item) then
    Exit(M);
  if ((aAscending and (item < Self[M])) or ((not aAscending) and (item > Self[M]))) then
    Result := Self.BinarySearchSpan(item, L, (M - 1), aAscending)
  else
    Result := Self.BinarySearchSpan(item, (M + 1), R, aAscending);
end;

{==============================================================================]
  <BinarySeek>
  @action: Binary Search function for arrays. Searches item from arr and returns the index.
  @note: Works with sorted arrays, ascending or descending.
[==============================================================================}
function MArrayHelper.BinarySeek(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    i := r.Pivot;
    if (Self[i] = item) then
      Exit(i);
    if ((aAscending and (Self[i] < item)) or ((not aAscending) and (Self[i] > item))) then
      r.start := (i + 1)
    else
      r.stop := (i - 1);
  end;
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
