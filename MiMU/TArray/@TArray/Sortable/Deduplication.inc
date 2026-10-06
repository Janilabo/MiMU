{$IFDEF HELPERS}
function Cleaned(const oAscending: Boolean = True): MArray; overload;
function Monotonized(const oAscending: Boolean = True): MArray; overload;
function Sortique(const rAscending: Boolean = True): MArray; overload;
function Uniqal(const aKeepFirst: Boolean = True): MArray; overload;
function Winnowed(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
function WinnowedByMax(const aMax: MType; const oAscending: Boolean = True): MArray; overload;
function WinnowedByMin(const aMin: MType; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cleaned>
  @action: Returns a sorted copy of the array with all duplicate elements removed.
  @note: Uses an in-place deduplication algorithm after sorting to ensure a 
         unique set of values. Ideal for normalizing boundary data before 
         performing continuity or gap analysis.
[==============================================================================}
function MArrayHelper.Cleaned(const oAscending: Boolean = True): MArray; overload;
var
  i, r: Integer;
begin
  case Self.Length of
    0: Exit([]);
    1: Exit(Self.Copy);
  end;
  Result := Self.QuickSorted(oAscending);
  r := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[r - 1]) then
      Result[r.Increase] := Result[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Monotonized>
  @action: Returns a new array containing a strictly monotonic (increasing or decreasing) sequence.
  @note: Scans left-to-right and drops any element that does not strictly exceed (True) or stay below (False) the previously retained element.
[==============================================================================}
function MArrayHelper.Monotonized(const oAscending: Boolean = True): MArray; overload;
var
  r, i: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  Result[0] := Self[0];
  case oAscending of
    True:
    for i := 1 to High(Self) do
      if (Self[i] > Result[r]) then
        Result[r.Increment] := Self[i];
    False:
    for i := 1 to High(Self) do
      if (Self[i] < Result[r]) then
        Result[r.Increment] := Self[i];
  end;
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Sortique>
  @action: Returns a sorted array containing only distinct elements, applying QuickSort followed by an adjacent deduplication pass.
  @note:  Faster than Uniquify for larger arrays due to single-pass adjacent comparison after sorting, but alters original element order.
          Operates in O(n log n) average time complexity.
[==============================================================================}
function MArrayHelper.Sortique(const rAscending: Boolean = True): MArray; overload;
var
  i, r: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Cloned);
  Result := Self.QuickSorted(rAscending);
  r := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[r - 1]) then
      Result[r.Increase] := Result[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Uniqal>
  @action: Removes all duplicates from arr via sort-then-compact, O(n log n).
           aKeepFirst controls whether the first or last original occurrence
           of each duplicate value survives; ordered-only tier (Leads/Trails).
  @note: Returns the unique version of arr, in original relative order.
         Reuses QuickSortition rather than duplicating sort logic. Supersedes
         both Uniqued (first-only, O(n^2)) and Uniqed (last-only, O(n^2)).
[==============================================================================}
function MArrayHelper.Uniqal(const aKeepFirst: Boolean = True): MArray; overload;
var
  s: TIntegerArray;
  a: TBooleanArray;
  l, i, j, k, c, r, p: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Cloned);
  s := Self.QuickSortition;
  for i := 0 to a.Alloc(l) do
    a[i] := False;
  i := 0;
  while (i < l) do
  begin
    r := i;
    j := (i + 1);
    while ((j < l) and (not (Self[s[j]].Leads(Self[s[r]]) or Self[s[j]].Trails(Self[s[r]])))) do
      Inc(j);
    p := s[r];
    for k := (r + 1) to (j - 1) do
      if (aKeepFirst = (s[k] < p)) then
        p := s[k];
    a[p] := True;
    i := j;
  end;
  c := 0;
  for i := 0 to Result.Alloc(l) do
    if a[i] then
      Result[c.Increase] := Self[i];
  SetLength(Result, c);
end;

{==============================================================================]
  <Winnowed>
  @action: Returns the distinct elements of Self that lie within [aMin, aMax],
           ordered by oAscending. Filters first so only surviving elements are
           sorted, then compacts adjacent duplicates in place.
  @note: Non-mutating. Self need not be sorted. Returns [] if Self is empty or
         aMin > aMax (bounds are not swapped). Ordered-only tier (< > = <>).
         Requires a mutating QuickSort(oAscending) on MArray.
[==============================================================================}
function MArrayHelper.Winnowed(const aMin, aMax: MType; const oAscending: Boolean = True): MArray; overload;
var
  s, i, r, l: Integer;
begin
  s := Self.Length;
  if ((s = 0) or (aMin > aMax)) then
    Exit([]);
  r := 0;
  for i := 0 to Result.Alloc(s) do
    if not ((Self[i] < aMin) or (Self[i] > aMax)) then
      Result[r.Increase] := Self[i];
  if (Result.SetSize(r) < 2) then
    Exit;
  Result.QuickSort(oAscending);
  l := 1;
  for i := 1 to (r - 1) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <WinnowedByMax>
  @action: Returns the distinct elements of Self that are <= aMax, ordered by
           oAscending. Filters first so only surviving elements are sorted,
           then compacts adjacent duplicates in place.
  @note: Non-mutating. Self need not be sorted. aMax is an inclusive ceiling:
         elements greater than aMax are discarded. Returns [] if Self is empty
         or nothing survives. Ordered-only tier (< > = <>). Requires a
         mutating QuickSort(oAscending) on MArray.
[==============================================================================}
function MArrayHelper.WinnowedByMax(const aMax: MType; const oAscending: Boolean = True): MArray; overload;
var
  s, i, r, l: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := 0;
  for i := 0 to Result.Alloc(s) do
    if not (Self[i] > aMax) then
      Result[r.Increase] := Self[i];
  if (Result.SetSize(r) < 2) then
    Exit;
  Result.QuickSort(oAscending);
  l := 1;
  for i := 1 to (r - 1) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <WinnowedByMin>
  @action: Returns the distinct elements of Self that are >= aMin, ordered by
           oAscending. Filters first so only surviving elements are sorted,
           then compacts adjacent duplicates in place.
  @note: Non-mutating. Self need not be sorted. aMin is an inclusive floor:
         elements less than aMin are discarded. Returns [] if Self is empty
         or nothing survives. Ordered-only tier (< > = <>). Requires a
         mutating QuickSort(oAscending) on MArray.
[==============================================================================}
function MArrayHelper.WinnowedByMin(const aMin: MType; const oAscending: Boolean = True): MArray; overload;
var
  s, i, r, l: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  r := 0;
  for i := 0 to Result.Alloc(s) do
    if not (Self[i] < aMin) then
      Result[r.Increase] := Self[i];
  if (Result.SetSize(r) < 2) then
    Exit;
  Result.QuickSort(oAscending);
  l := 1;
  for i := 1 to (r - 1) do
    if (Result[i] <> Result[l - 1]) then
      Result[l.Increase] := Result[i];
  SetLength(Result, l);
end; 
{$ENDIF}