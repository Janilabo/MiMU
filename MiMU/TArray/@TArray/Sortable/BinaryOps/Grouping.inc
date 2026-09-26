{$IFDEF HELPERS}
function BinaryCongress(const oAscending: Boolean = True): M2DArray; overload;
function BinaryGroup(const aAscending: Boolean = True): M2DArray; overload;
function BinaryGrouped(const oAscending: Boolean = True): M2DArray; overload;
function BinaryGroupify(const oAscending: Boolean = True): M2DArray; overload;
function BinaryGrouping(const rAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCongress>
  @action: Groups duplicate values into ordered 2D sub-arrays by performing a 
          binary search insertion into a dynamically sorted key index (`r`).
  @note: 
  - Standard Binary Search Loop: Performs a classic binary lookup ($O(\log U)$) 
    against unique sorted key registry `r`, correctly defaulting insertion index 
    `p := l` upon search exhaustion (`l > h`).
  - Sorted key maintenance: Respects `oAscending` during comparisons to insert new 
    keys into `r` in strict sorted order without requiring a global array pre-sort.
  - Mirrored array expansion: When encountering a new key (`f = False`), extends 
    and right-shifts elements in both `r` and `Result` starting at index `p` to 
    preserve row-to-key alignment.
  - Match append: Appends matching values using `Result[p].Supply(Self[i])` once 
    the target row index `p` is resolved.
[==============================================================================}
function MArrayHelper.BinaryCongress(const oAscending: Boolean = True): M2DArray; overload;
var
  s, i, l, h, m, p, g: Integer;
  r: MArray;
  f: Boolean;
begin
  s := Self.Length;
  for i := 0 to (s - 1) do
  begin
    l := 0;
    h := High(r);
    f := False;
    while (l <= h) do
    begin
      m := (l + ((h - l) div 2));
      if (Self[i] = r[m]) then
      begin
        f := True;
        p := m;
        Break;
      end else if ((oAscending and (Self[i] < r[m])) or ((not oAscending) and (Self[i] > r[m]))) then
        h := (m - 1)
      else
        l := (m + 1);
    end;
    if not f then
      p := l;
    if not f then
    begin
      SetLength(r, (r.Length + 1));
      for g := High(r) downto (p + 1) do
        r[g] := r[g - 1];
      SetLength(Result, (Result.Length + 1));
      for g := High(Result) downto (p + 1) do
        Result[g] := Result[g - 1];
      r[p] := Self[i];
      Result[p] := [Self[i]];
    end else
      Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <BinaryGroup>
  @action: Groups the elements of the array into subarrays of identical values,
           maintaining the groups in sorted order. Works efficiently on unsorted
           input, without requiring Self to be pre-sorted.
  @note:
    - Groups are kept in ascending order if aAscending = True, descending if False.
    - Locating an existing group is O(log k) via binary search, where k is the
      number of distinct values seen so far. Creating a new group is O(k) due
      to the underlying dynamic-array Insert shifting subsequent elements.
    - Overall complexity is O(n log k) when k is small relative to n (few
      distinct values, many repeats), degrading toward O(n·k) — i.e. O(n²)
      in the worst case — when most elements are distinct.
    - Fully compatible with unsorted input.
[==============================================================================}
function MArrayHelper.BinaryGroup(const aAscending: Boolean = True): M2DArray; overload;
var
  s: MArray;
  i, m, p: Integer;
  f: Boolean;
  r: TRange;
begin
  SetLength(Result, 0);
  SetLength(s, 0);
  for i := 0 to High(Self) do
  begin
	r.Create(0, High(s));
    f := False;
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      case (s[m] = Self[i]) of
        True:
        begin
          f := True;
          p := m;
          Break;
        end;
        False:
        if ((s[m] < Self[i]) xor (not aAscending)) then
          r.start := (m + 1)
        else
          r.stop := (m - 1);
      end;
    end;
    if not f then
    begin
      p := r.start;
      Insert(Self[i], s, p);
      Insert(nil, Result, p);
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <BinaryGrouped>
  @action: Groups contiguous identical elements from a sorted array into a 2D array.
  @note: Uses BinaryLast bounded to remaining elements [i..s-1] in O(log N) time per distinct value.
         Requires the input array to be sorted according to oAscending (ascending or descending).
[==============================================================================}
function MArrayHelper.BinaryGrouped(const oAscending: Boolean = True): M2DArray; overload;
var
  l, r, i, s: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  SetLength(Result, s);
  i := 0;
  l := 0;
  while (i < s) do
  begin
    for r := 0 to Result[l].Alloc((Self.BinaryLast(Self[i], i, (s - 1), oAscending) - i) + 1) do
      Result[l][r] := Self[i];
    Inc(i, Result[l.Increase].Length);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryGroupify>
  @action: Splits a sorted array into runs of equal values, returning one
           sub-array per distinct value, in the order set by oAscending.
  @note:
    - Requires Self to already be sorted in the direction given by oAscending;
      it does not sort.
    - Finds the end of each run with BinaryRightern, so the cost is
      O(g log n) for g distinct values, which beats a linear sweep when runs
      are long.
    - Returns an empty array for an empty input.
[==============================================================================}
function MArrayHelper.BinaryGroupify(const oAscending: Boolean = True): M2DArray; overload;
var
  s, r, i: Integer;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  r := -1;
  i := 0;
  while ((r = -1) or (i.Increment(Result[r].Length) < s)) do
    Result[r.Increment] := Self[i].TArray((Self.BinaryRightern(Self[i], oAscending) - i) + 1);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <BinaryGrouping>
  @action: Groups duplicate values into pre-sorted 2D sub-arrays using binary 
          tree/search insertion.
  @note: 
    - Unique value extraction: Uses `BinaryGrow` in Pass 1 to build a uniquely sorted 
      reference array containing one instance of each distinct element.
    - Histogram counting: Uses BinarySearch in Pass 2 to tally occurrence frequencies 
      for each unique value into array.
    - Matrix allocation & population: Allocates row capacities according to occurrence 
      counts and fills each row `Result[i]` with repeated 
      instances of r[i].
    - Result structure: Produces a 2D array where each sub-array contains all identical 
      duplicates of a single value, ordered monotonically by row according to rAscending.
[==============================================================================}
function MArrayHelper.BinaryGrouping(const rAscending: Boolean = True): M2DArray; overload;
var
  i, j, s: Integer;
  r: MArray;
  c: TIntegerArray;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  Result[0] := [Self[0]];
  if (s > 1) then
  begin
    r := [Self[0]];
    for i := 1 to (s - 1) do
      r.BinarySupply(Self[i], rAscending);
    SetLength(c, r.Length);
    for i := 0 to (s - 1) do
      Inc(c[r.BinarySearch(Self[i], rAscending)]);
    SetLength(Result, r.Length);
    for i := 0 to High(Result) do
      for j := 0 to Result[i].Alloc(c[i]) do
        Result[i][j] := r[i];
  end;
end;
{$ENDIF}
