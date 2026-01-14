{$IFDEF HELPERS}
function BinaryExpSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryGot(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHas(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
function BinarySearchBy(const item: MType; const oAscending: Boolean = True): Integer; overload;
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
{$ENDIF}