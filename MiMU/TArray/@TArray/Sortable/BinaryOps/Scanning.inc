{$IFDEF HELPERS}
function BinaryCluster(const start: Integer; const allowed: MArray; const aAscending: Boolean = True): TRange; overload;
function BinaryHits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryHitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryIndices(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInquire(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInquiry(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryInterval(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryRadar(const aMin, aMax: MType; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScan(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScan2(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanned(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanner(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function BinarySweep(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCluster>
  @action: Starting at <start>, expands left and right to determine the maximal
           contiguous range of elements whose values are contained in <allowed>.
           Membership is verified using binary search on <allowed>.
  @note:
    - <start> must be a valid index within the array.
    - The element at <start> must exist in <allowed>.
    - <allowed> must be sorted according to <aAscending>.
    - Returns (-1, -1) if:
        * <start> is invalid,
        * <allowed> is empty, or
        * Self[<start>] is not contained in <allowed>.
    - Time complexity: O(k log m), where:
        k = size of the resulting cluster,
        m = length of <allowed>.
[==============================================================================}
function MArrayHelper.BinaryCluster(const start: Integer; const allowed: MArray; const aAscending: Boolean = True): TRange; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if not ((start > -1) and (start < l) and (allowed.Length > 0) and (allowed.BinarySearchBy(Self[start], aAscending) > -1)) then
    Exit(TRange.Construct(-1, -1));
  Result := TRange.Construct(start, start);
  while ((Result.start > -1) and (allowed.BinarySearchBy(Self[Result.start - 1], aAscending) > -1)) do
    Dec(Result.start);
  l := Self.Length;
  while ((Result.stop < l) and (allowed.BinarySearchBy(Self[Result.stop + 1], aAscending) > -1)) do
    Inc(Result.stop);
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
  <BinaryIndices>
  @action: Performs batch membership position lookup between the current array and
           a sorted query array. Returns the list of indices in the current array
           where elements exist in the provided `items` collection.
  @note:
    - The query array `items` is internally sorted before searching.
    - Binary search is used for membership testing.
    - Duplicate matches may result in multiple indices being returned.
    - The function excludes non-existent matches (no -1 values are returned).
    - Time complexity is approximately O(n log m), where:
        n = length of Self
        m = length of items
    - If `items` is empty, the function returns an empty array.
    - The search ordering follows `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryIndices(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, c: Integer;
  t: MArray;
begin
  if items.Empty then
    Exit([]);
  SetLength(Result, Self.Length);
  c := 0;
  t := items.QuickSorted(oAscending);
  for i := 0 to High(Result) do
    if (t.BinarySearchBy(Self[i], oAscending) > -1) then
      Result[c.Increase] := i;
  SetLength(Result, c);
end;

{==============================================================================]
  <BinaryInquire>
  @action: Finds and returns the indices of all elements in the sorted underlying array (Self) that match any of the items in the lookup array,
           utilizing binary search bounds (lower and upper bounds) for each item.
  @note: Calculates the exact lower and upper boundaries via a nested helper function B for every item in items,
         aggregates the total count of matching elements, and flattens all corresponding index ranges into a single resulting integer array.
         Supports sorting specified by oAscending.
[==============================================================================}
function MArrayHelper.BinaryInquire(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k, s, r: Integer;
  l, u: TIntegerArray;
  function B(const item: MType; const upper: Boolean): Integer;
  var
    h, m: Integer;
    z: Boolean;
  begin
    Result := 0;
    h := s;
    while (Result < h) do
    begin
      m := ((Result + h) shr 1);
      if oAscending then
        z := ((Self[m] < item) or (upper and (Self[m] = item)))
      else
        z := ((Self[m] > item) or (upper and (Self[m] = item)));
      if z then
        Result := (m + 1)
      else
        h := m;
    end;
  end;
begin
  s := Self.Length;
  k := High(items);
  if ((s = 0) or (k = -1)) then
    Exit([]);
  SetLength(l, (k + 1));
  SetLength(u, (k + 1));
  r := 0;
  for i := 0 to k do
  begin
    l[i] := B(items[i], False);
    u[i] := B(items[i], True);
    Inc(r, (u[i] - l[i]));
  end;
  SetLength(Result, r);
  r := 0;
  for i := 0 to k do
    for j := l[i] to (u[i] - 1) do
      Result[r.Increase] := j;
end;

{==============================================================================]
  <BinaryInquiry>
  @action: Finds and returns the indices of elements in a sorted array (Self) that match the specified lookup items
           using an optimized binary search approach with a running search cursor.
  @note: Leverages a stateful cursor (c) that updates with each lookup, reducing the search space for subsequent items.
         Like BinarySweep, it handles potentially unsorted lookup arrays (items) by resetting the cursor when an item falls out of order,
		 and respects the sorting order defined by oAscending.
[==============================================================================}
function MArrayHelper.BinaryInquiry(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, c, l, h, m, s, r: Integer;
  v: MType;
begin
  s := Self.Length;
  SetLength(Result, 0);
  if ((s = 0) or (items.Length = 0)) then
    Exit;
  r := 0;
  c := 0;
  for i := 0 to High(items) do
  begin
    v := items[i];
    if ((i > 0) and ((oAscending and (v < items[i - 1])) or ((not oAscending) and (v > items[i - 1])))) then
      c := 0;
    l := c;
    h := s;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if ((oAscending and (Self[m] < v)) or ((not oAscending) and (Self[m] > v))) then
        l := (m + 1)
      else
        h := m;
    end;
    c := l;
    while ((l < s) and (Self[l] = v)) do
    begin
      if (r = Result.Length) then
        SetLength(Result, Max((r * 2), 16));
      Result[r.Increase] := l.Increase;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryInterval>
  @action: Performs a binary search for <item> in a sorted array and returns the
           contiguous interval (range) of all elements equal to <item>.
  @note:
    - The array must be sorted in ascending or descending order as specified
      by <oAscending>.
    - If <item> is not found, the returned range has Start = -1.
    - Time complexity: O(log n + k), where k is the number of equal elements.
[==============================================================================}
function MArrayHelper.BinaryInterval(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  l: Integer;
begin
  Result.Create(Self.BinarySearchBy(item, oAscending));
  if (Result.start = -1) then
    Exit;
  while ((Result.start > -1) and (Self[Result.start - 1] = item)) do
    Dec(Result.start);
  l := Self.Length;
  while ((Result.stop < l) and (Self[Result.stop + 1] = item)) do
    Inc(Result.stop);
end;

{==============================================================================]
  <BinaryRadar>
  @action: Uses binary search to locate all elements falling within the inclusive range [`aMin`, `aMax`] in a sorted array and returns an array containing their index positions.
  @note: Invokes `BinaryBracket` to determine boundary indices in O(log N) time, then generates a contiguous sequence of index offsets from `r.start` to `r.stop`.
         Returns an empty array if no elements match the range.
[==============================================================================}
function MArrayHelper.BinaryRadar(const aMin, aMax: MType; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  r: TRange;
begin
  r := Self.BinaryBracket(aMin, aMax, oAscending);
  if ((r.start = -1) or (r.stop = -1)) then
    Exit([]);
  for i := 0 to Result.Alloc(r.Size) do
    Result[i] := (i + r.start);
end;

{==============================================================================]
  <BinaryScan>
  @action: Searches Self for matching items using binary search and collects all target index positions.
  @note: Requires Self to be sorted. Handles duplicates and dynamically expands the Result array.
[==============================================================================}
function MArrayHelper.BinaryScan(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, h, m, s, r: Integer;
  v: MType;
begin
  s := Self.Length;
  r := 0;
  SetLength(Result, 0);
  for i := 0 to High(items) do
  begin
    v := items[i];
    l := 0;
    h := s;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if ((oAscending and (Self[m] < v)) or ((not oAscending) and (Self[m] > v))) then
        l := (m + 1)
      else
        h := m;
    end;
    while ((l < s) and (Self[l] = v)) do
    begin
      if (r = Result.Length) then
        SetLength(Result, Max((r * 2), 16));
      Result[r.Increase] := l.Increase;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryScan2>
  @action: Finds and returns the indices of elements in a sorted underlying array (Self) that match any of the items in the lookup array,
           using binary search with exponential bounding to find match ranges.
  @note: For each item in items, performs a binary search to locate the start of matching elements,
         then uses an exponential step-up followed by binary search to find the end boundary (b[i]).
		 It accumulates the size of all matches, aggregates them, and flattens the resulting index ranges into a single integer array, respecting order.
[==============================================================================}
function MArrayHelper.BinaryScan2(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k, p, t, l, h, m, s, r: Integer;
  v: MType;
  a, b: TIntegerArray;
begin
  s := Self.Length;
  k := High(items);
  if ((s = 0) or (k = -1)) then
    Exit([]);
  SetLength(a, (k + 1));
  SetLength(b, (k + 1));
  r := 0;
  for i := 0 to k do
  begin
    v := items[i];
    l := 0;
    h := s;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if ((oAscending and (Self[m] < v)) or ((not oAscending) and (Self[m] > v))) then
        l := (m + 1)
      else
        h := m;
    end;
    a[i] := l;
    b[i] := l;
    if ((l < s) and (Self[l] = v)) then
    begin
      p := l;
      t := 1;
      while (((p + t) < s) and (Self[p + t] = v)) do
      begin
        Inc(p, t);
        t := (t shl 1);
      end;
      l := (p + 1);
      h := Min((p + t), s);
      while (l < h) do
      begin
        m := ((l + h) shr 1);
        if (Self[m] = v) then
          l := (m + 1)
        else
          h := m;
      end;
      b[i] := l;
      Inc(r, (l - a[i]));
    end;
  end;
  SetLength(Result, r);
  r := 0;
  for i := 0 to k do
    for j := a[i] to (b[i] - 1) do
      Result[r.Increase] := j;
end;

{==============================================================================]
  <BinaryScanned>
  @action: Scans the sorted array using binary bounds for multiple items and returns all matching index positions.
  @note: Uses BinaryBourne to locate ranges for each item, flattening all matched index ranges into a single integer array.
[==============================================================================}
function MArrayHelper.BinaryScanned(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, s, h: Integer;
  r: TRangeArray;
begin
  if ((Self.Length = 0) or (items.Length = 0)) then
    Exit([]);
  l := 0;
  for i := 0 to r.Alloc(items.Length) do
    if Self.BinaryBourne(items[i], r[l], oAscending) then
      Inc(l);
  if (l = 0) then
    Exit([]);
  SetLength(r, l);
  h := Result.SetSize(r.Sizing);
  for i := (l - 1) downto 0 do
    for s := r[i].stop downto r[i].start do
      Result[h.Decrement] := s;
end;

{==============================================================================]
  <BinaryScanner>
  @action: Finds and returns the indices of elements in the underlying array (Self)
           that match any of the specified lookup items using binary search.
  @note: Leverages BinaryBourne to locate matching index ranges for each item in the lookup array,
         accumulates their sizes, and flattens all collected ranges into a single resulting integer array.
		 Respects the sorting order specified by oAscending
[==============================================================================}
function MArrayHelper.BinaryScanner(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s, l, h: Integer;
  r: TRangeArray;
begin
  if ((Self.Length = 0) or (items.Length = 0)) then
    Exit([]);
  l := 0;
  h := 0;
  for i := 0 to r.Alloc(items.Length) do
    if Self.BinaryBourne(items[i], r[l], oAscending) then
      Inc(h, r[l.Increase].Size);
  if (l = 0) then
    Exit([]);
  SetLength(Result, h);
  h := 0;
  for i := 0 to (l - 1) do
    for s := r[i].start to r[i].stop do
      Result[h.Increase] := s;
end;

{==============================================================================]
  <BinarySweep>
  @action: Finds and returns the indices of elements in a sorted array (Self),
           that match the specified lookup items using a hybrid binary search and linear sweep approach.
  @note: Assumes the underlying array (Self) is sorted (matching oAscending). Unlike standard Sweep,
         BinarySweep safely handles lookup arrays (items) that may not be strictly sorted
         by dynamically falling back to a binary search whenever a lookup item falls out of order.
[==============================================================================}
function MArrayHelper.BinarySweep(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k, l, h, m, s, r: Integer;
  v: MType;
begin
  s := Self.Length;
  if ((s = 0) or (items.Length = 0)) then
    Exit([]);
  r := 0;
  j := 0;
  SetLength(Result, 0);
  for i := 0 to High(items) do
  begin
    v := items[i];
    if ((i > 0) and ((oAscending and (v < items[i - 1])) or ((not oAscending) and (v > items[i - 1])))) then
    begin
      l := 0;
      h := s;
      while (l < h) do
      begin
        m := ((l + h) shr 1);
        if ((oAscending and (Self[m] < v)) or ((not oAscending) and (Self[m] > v))) then
          l := (m + 1)
        else
          h := m;
      end;
      j := l;
    end;
    while ((j < s) and ((oAscending and (Self[j] < v)) or ((not oAscending) and (Self[j] > v)))) do
      Inc(j);
    k := j;
    while ((k < s) and (Self[k] = v)) do
    begin
      if (r = Result.Length) then
        SetLength(Result, Max((r * 2), 16));
      Result[r.Increase] := k.Increase;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}
