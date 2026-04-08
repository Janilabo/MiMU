{$IFDEF HELPERS}
function Bisected: TRangeArray; overload;
function Coalesce: TRangeArray; overload;
function Collapse: TRangeArray; overload;
function Condense(const oAscending: Boolean = True): TRangeArray; overload;
function Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
function Consolidated(const rAscending: Boolean = True): TRangeArray; overload;
function Defragment(const rAscending: Boolean = True): TRangeArray; overload;
function Fuse: TRangeArray; overload;
function Fused: TRangeArray; overload;
function Gridded: TRangeArray; overload;
function Heaped: TRangeArray; overload;
function Meld(const rSort: Boolean = True): TRangeArray; overload;
function Melted(const oAscending: Boolean = True): TRangeArray; overload;
function Merge: TRangeArray; overload;
function Merged: TRangeArray; overload;
function Mergified(const threshold: Integer = -1): TRangeArray; overload;
function Mergify(const threshold: Integer = -1): Integer; overload;
function Restacked: TRangeArray; overload;
function Scanlined: TRangeArray; overload;
function Simplify: TRangeArray; overload;
function Squashed: TRangeArray; overload;
function Squeeze(const rAscending: Boolean = True): TRangeArray; overload;
function Stream(const oAscending: Boolean = True): TRangeArray; overload;
function Streamed(const oAscending: Boolean = True): TRangeArray; overload;
function Streamline: TRangeArray; overload;
function Unionized(const oAscending: Boolean = True): TRangeArray; overload;
function Unite(const mAdjacent: Boolean = True): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bisected>
  @action: Merge overlapping and adjacent ranges using divide and conquer
  @note:
    - Recursively splits the array in half, solves each side independently,
      then merges two already-sorted, non-overlapping interval arrays.
    - Adjacent ranges (stop + 1 = start) are merged at every level.
    - Time complexity: O(n log² n) — O(log n) levels, O(n) merge per level.
    - Normalizes input before recursing.
[==============================================================================}
function TRangeArrayHelper.Bisected: TRangeArray; overload;
  function MP(const A, B: TRangeArray): TRangeArray;
  var
    i, j, l, x, y: Integer;
    c, n: TRange;
  begin
    x := A.Length;
    if (x = 0) then
      Exit(B);
    y := B.Length;
    if (y = 0) then
      Exit(A);
    SetLength(Result, (x + y));
    i := 0;
    j := 0;
    l := 0;
    if (A[0].start <= B[0].start) then
    begin
      c := A[0];
      Inc(i);
    end else
    begin
      c := B[0];
      Inc(j);
    end;
    while ((i < x) or (j < y)) do
    begin
      if ((i < x) and ((j >= y) or (A[i].start <= B[j].start))) then
        n := A[i.Increase]
      else
        n := B[j.Increase];
      if (n.start > (c.stop + 1)) then
      begin
        Result[l.Increase] := c;
        c := n;
      end else
        c.stop := Max(c.stop, n.stop);
    end;
    Result[l.Increase] := c;
    SetLength(Result, l);
  end;
  function DnC(const S: TRangeArray): TRangeArray;
  var
    l, m: Integer;
  begin
    l := S.Length;
    if (l <= 1) then
      Exit(S);
    m := (l div 2);
    Result := MP(DnC(System.Copy(S, 0, m)), DnC(System.Copy(S, m, (l - m))));
  end;
begin
  if (Self.Length < 2) then
    Exit(Self.Normalized);
  Result := DnC(Self.Normalized);
end;

{==============================================================================]
  <Coalesce>
  @action: Coalesce overlapping and adjacent ranges
  @note: Input normalized and sorted; adjacency = (start <= stop + 1)
[==============================================================================}
function TRangeArrayHelper.Coalesce: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, 0);
  R := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (R.stop + 1)) of
    True:
    if (S[i].stop > R.stop) then
      R.stop := S[i].stop;
    False:
    begin
      SetLength(Result, (Result.Length + 1));
      Result[High(Result)] := R;
      R := S[i];
    end;
  end;
  SetLength(Result, (Result.Length + 1));
  Result[High(Result)] := R;
end;

{==============================================================================]
  <Collapse>
  @action: Coalesce overlapping and adjacent ranges with preallocated result
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); uses index accumulator
[==============================================================================}
function TRangeArrayHelper.Collapse: TRangeArray; overload;
var
  S: TRangeArray;
  C: TRange;
  i, r: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, S.Length);
  r := 0;
  C := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (C.stop + 1)) of
    True:
    if (S[i].stop > C.stop) then
      C.stop := S[i].stop;
    False:
    begin
      Result[r.Increase] := C;
      C := S[i];
    end;
  end;
  Result[r.Increase] := C;
  SetLength(Result, r);
end;

{==============================================================================]
  <Condense>
  @action: Merges overlapping and adjacent ranges in a TRangeArray into the minimal set
           of disjoint contiguous ranges. Returns the result in ascending or descending order.
  @note:
    - Normalizes all ranges internally before merging.
    - Adjacent ranges (stop + 1 = start) are merged automatically.
    - Efficient linear merge after sorting.
    - If oAscending = False, the resulting ranges are reversed.
    - Result contains the minimal number of ranges covering all integers from the input.
[==============================================================================}
function TRangeArrayHelper.Condense(const oAscending: Boolean = True): TRangeArray; overload;
var
  s: TRangeArray;
  r: TRange;
  i, l: Integer;
begin
  if (Self.Length = 0) then
    Exit([]);
  s := Self.Normalized;
  s.Sort(True);
  SetLength(Result, s.Length);
  l := 0;
  r := s[0];
  for i := 1 to High(s) do
    if (s[I].start > (r.stop + 1)) then
    begin
      Result[l.Increase] := r;
      r := s[I];
    end else if (s[I].stop > r.stop) then
      r.stop := s[I].stop;
  Result[l.Increase] := r;
  SetLength(Result, l);
  if not oAscending then
  for i := 0 to ((l div 2) - 1) do
  begin
    r := Result[i];
    Result[i] := Result[l - 1 - i];
    Result[l - 1 - i] := r;
  end;
end;

{==============================================================================]
  <Consolidate>
  @action: Expands ranges into unique integer values using ordered insertion,
           then reconstructs contiguous ranges into a compact, non-overlapping array.
           Produces a new array ordered by rAscending.
  @note: Steps:
           1. Iterates all ranges and inserts each value via BinaryGrow (sorted, no duplicates).
           2. Tracks resulting element count (s).
           3. Rebuilds contiguous ranges from the ordered integer set.
         Time complexity: O(m log m) due to incremental ordered insertion,
         where m = total number of elements across all ranges.
         Avoids separate sort/compress pass (unlike Defragment).
         Produces normalized, non-overlapping ranges. Original array is not modified.
         Output direction controlled solely by rAscending.
[==============================================================================}
function TRangeArrayHelper.Consolidate(const rAscending: Boolean = True): TRangeArray; overload;
var
  s, i, j, l, d: Integer;
  r: TIntegerArray;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  s := 0;
  SetLength(r, 0);
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s.Increase(r.BinaryGrow(j, rAscending));
  SetLength(Result, s);
  d := IfThen(rAscending, 1, -1);
  l := 0;
  Result[0].Create(r[0]);
  for i := 1 to (s - 1) do
    if (r[i] = (Result[l].stop + d)) then
      Result[l].stop := r[i]
    else
      Result[l.Increment].Create(r[i]);
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Consolidated>
  @action: Returns a compact version of the array where all overlapping or 
           adjacent segments are fused into single ranges.
  @note: - Uses a Geometric Sweep (O(n log n)).
         - Normalizes all input to ensure physical overlaps are detected.
         - Merges segments that touch (e.g., [1..5] and [6..10] become [1..10]).
         - If rAscending is False, the result is returned in Descending 
           order (e.g., [20..10, 5..1]).
[==============================================================================}
function TRangeArrayHelper.Consolidated(const rAscending: Boolean = True): TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  case Self.Length of
    0: Exit([]);
    1:
    if rAscending then
      Exit([Self[0].Normalize])
    else
      Exit([Self[0].Descended]);
  end;
  S := Self.Normalized;
  S.SortByStart(True);
  SetLength(Result, S.Length);
  l := 0;
  R := S[0];
  for i := 1 to High(S) do
  case (S[i].start <= (R.stop + 1)) of
    True:
    if (S[i].stop > R.stop) then
      R.stop := S[i].stop;
    False:
    begin
      Result[l.Increase] := R;
      R := S[i];
    end;
  end;
  Result[l.Increase] := R;
  SetLength(Result, l);
  if not rAscending then
    Result := Result.Descended.Reversed;
end;

{==============================================================================]
  <Defragment>
  @action: Expands all ranges into individual integer points, sorts and compresses them,
           then reconstructs contiguous ranges into a compact, non-overlapping array.
           Can produce ascending or descending ranges based on rAscending.
  @note: Steps:
           1. Computes total size of all ranges.
           2. Fills a temporary integer array with all values in all ranges.
           3. Sorts the integers (ascending or descending).
           4. Compresses duplicates.
           5. Rebuilds contiguous ranges into TRangeArray.
         Time complexity: O(n + m log m), where n = number of ranges, m = total elements.
         Produces fully normalized, non-overlapping ranges. Original array is not modified.
         Does not preserve original Ascending flags; controlled entirely by rAscending.
[==============================================================================}
function TRangeArrayHelper.Defragment(const rAscending: Boolean = True): TRangeArray; overload;
var
  s, i, j, l, d: Integer;
  r: TIntegerArray;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Size);
  SetLength(r, s);
  l := 0;
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      r[l.Increase] := j;
  r.QuickSort(rAscending);
  r.Compress;
  SetLength(Result, r.Length);
  Result[0].Create(r[0]);
  d := IfThen(rAscending, 1, -1);
  l := 0;
  for i := 1 to High(r) do
    if (r[i] = (Result[l].stop + d)) then
      Result[l].stop := r[i]
    else
      Result[l.Increment].Create(r[i]);
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Fuse>
  @action: Combines overlapping or adjacent ranges into a single, non-overlapping array.
           Produces a new array; original array is not modified. Always normalizes
           ranges before merging.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`) via Self.Normalized.
           2. Sorts ranges by `start`.
           3. Iteratively merges overlapping or adjacent ranges (stop + 1).
           4. Writes merged ranges into Result, compacting array length.
         Time complexity: O(n log n) due to sorting; merge pass is O(n).
         Safe as long as all ranges have valid bounds. Does not preserve any Ascending flag.
[==============================================================================}
function TRangeArrayHelper.Fuse: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  S := Self.Normalized;
  S.SortByStart;
  SetLength(Result, S.Length);
  R := S[0];
  l := 0;
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      Result[l.Increase] := R;
      R := S[i];
    end else
      R.stop := Max(R.stop, S[i].stop);
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Fused>
  @action: Merge overlapping and adjacent ranges using supply-based append
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); result grows via Supply
[==============================================================================}
function TRangeArrayHelper.Fused: TRangeArray; overload;
var
  S: TRangeArray;
  R: Integer;
  i: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S.Copy);
  S.SortByStart;
  Result := [S[0]];
  R := 0;
  for i := 1 to High(S) do
    if not (S[i].start <= (Result[R].stop + 1)) then
      R := Result.Supply(S[i])
    else if (S[i].stop > Result[R].stop) then
      Result[R].stop := S[i].stop;
end;

{==============================================================================]
  <Gridded>
  @action: Merge ranges via coordinate compression on boundary endpoints
  @note:
    - Collects all unique start and (stop + 1) values as breakpoints.
    - Sorts and deduplicates breakpoints.
    - Marks each cell [bp[k]..bp[k+1]-1] as covered if any input range spans it.
    - Reconstructs contiguous covered cells into merged ranges.
    - Distinct from Scanlined: no delta accumulation; direct per-cell coverage test.
    - Time complexity: O(n log n).
[==============================================================================}
function TRangeArrayHelper.Gridded: TRangeArray; overload;
var
  b: TIntegerArray;
  c: TBooleanArray;
  s, i, j, k, l, n: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([Self[0].Normalized]);
  SetLength(b, (s * 2));
  for i := 0 to (s - 1) do
  begin
    b[i * 2] := Min(Self[i].start, Self[i].stop);
    b[i * 2 + 1] := (Max(Self[i].start, Self[i].stop) + 1);
  end;
  b.QuickSort(True);
  b.Compress;
  n := b.Length;
  SetLength(c, (n - 1));
  for k := 0 to (n - 2) do
  begin
    c[k] := False;
    for i := 0 to (s - 1) do
      if ((b[k] >= Min(Self[i].start, Self[i].stop)) and ((b[k + 1] - 1) <= Max(Self[i].start, Self[i].stop))) then
      begin
        c[k] := True;
        Break;
      end;
  end;
  SetLength(Result, s);
  l := 0;
  k := 0;
  while (k < (n - 1)) do
  case c[k] of
    True:
    begin
      j := k;
      while ((k < (n - 1)) and c[k]) do
        Inc(k);
      Result[l.Increase].Create(b[j], (b[k] - 1));
    end;
    False: Inc(k);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Heaped>
  @action: Merge overlapping and adjacent ranges using a min-heap on start value
  @note:
    - Inserts all normalized ranges into a min-heap keyed by start.
    - Repeatedly extracts the minimum-start range and merges if adjacent/overlapping.
    - No separate sort pass; the heap enforces processing order.
    - Useful for incremental / online inputs.
    - Time complexity: O(n log n).
[==============================================================================}
function TRangeArrayHelper.Heaped: TRangeArray; overload;
var
  h: TRangeArray;
  s, i, l: Integer;
  q, t: TRange;
  procedure SD(idx: Integer);
  var
    c: Integer;
  begin
    repeat
      c := ((idx * 2) + 1);
      if (c >= s) then
        Break;
      if (((c + 1) < s) and (h[c + 1].start < h[c].start)) then
        Inc(c);
      if (h[idx].start <= h[c].start) then
        Break;
      h.Exch(idx, c);
      idx := c;
    until False;
  end;
  function HPop: TRange;
  begin
    Result := h[0];
    Dec(s);
    h[0] := h[s];
    if (s > 1) then
      SD(0);
  end;
  procedure HPush(const R: TRange);
  var
    j, p: Integer;
  begin
    h[s] := R;
    j := s;
    Inc(s);
    while (j > 0) do
    begin
      p := ((j - 1) div 2);
      if (h[p].start <= h[j].start) then
        Break;
      h.Exch(j, p);
      j := p;
    end;
  end;
begin
  if (Self.Length < 2) then
    Exit(Self.Normalized);
  SetLength(h, Self.Length);
  s := 0;
  for i := 0 to High(Self) do
    HPush(Self[i].Normalize);
  SetLength(Result, Self.Length);
  l := 0;
  q := HPop;
  while (s > 0) do
  begin
    t := HPop;
    if (t.start > (q.stop + 1)) then
    begin
      Result[l] := q;
      Inc(l);
      q := t;
    end else
      q.stop := Max(q.stop, t.stop);
  end;
  Result[l.Increase] := q;
  SetLength(Result, l);
end;

{==============================================================================]
  <Meld>
  @action: Merges overlapping ranges in a TRangeArray into the smallest set of disjoint ranges.
           Produces a union of all overlapping intervals. Optional sorting ensures
           ranges are processed in ascending start order.
  @note:
    - Only strictly overlapping ranges are merged; adjacent ranges are preserved as separate.
    - Sorting (`rSort`) is optional; if False, assumes input is pre-sorted.
    - Normalizes all ranges internally to ensure start ≤ stop.
    - Returns a copy of the input if fewer than 2 ranges exist.
    - Result preserves order of merged ranges.
[==============================================================================}
function TRangeArrayHelper.Meld(const rSort: Boolean = True): TRangeArray; overload;
var
  n: TRangeArray;
  i, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  n := Self.Normalized;
  if rSort then
    n.SortByStart;
  SetLength(Result, l);
  r := 0;
  Result[0] := n[0];
  for i := 1 to (l - 1) do
    if Result[r].Overlap(n[i]) then
      Result[r].stop := Max(Result[r].stop, n[i].stop)
    else
      Result[r.Increment] := n[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Melted>
  @action: Flattens all ranges into individual integers, sorts them, removes duplicates,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - The parameter oAscending controls the final order of the reconstructed ranges.
    - Duplicate integers across overlapping ranges are removed automatically.
    - Useful for creating a fully “coalesced” representation of a set of ranges.
    - Internally expands ranges to integers, sorts, and merges—so large ranges may temporarily consume more memory.
    - The result contains disjoint ranges covering the same integers as the input.
[==============================================================================}
function TRangeArrayHelper.Melted(const oAscending: Boolean = True): TRangeArray; overload;
var
  n: TRangeArray;
  s: TIntegerArray;
  i, j, r, l: Integer;
begin
  l := 0;
  n := Self.Normalized;
  for i := 0 to High(n) do
    Inc(l, ((n[i].stop - n[i].start) + 1));
  SetLength(s, l);
  l := 0;
  for i := 0 to High(n) do
    for j := n[i].start to n[i].stop do
      s[l.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, s.Length);
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if (s[i] = s[i - 1]) then
      Continue
    else if (s[i] = (Result[r].stop + j)) then
      Result[R].stop := s[i]
    else
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Merge>
  @action: Merges overlapping or adjacent ranges into a normalized, non-overlapping array.
           Produces a new array; does not modify the original. Preserves the original
           ascending/descending direction if all ranges share the same Ascending flag.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`) via Self.Normalized.
           2. Sorts ranges by `start`.
           3. Iteratively merges overlapping or adjacent ranges (stop + 1).
           4. Writes merged ranges into Result, compacting the array length.
           5. Reverses each merged range if original direction is descending.
         Time complexity: O(n log n) due to sort; merge pass is O(n).
         Safe as long as all ranges have valid bounds and share the same direction.
[==============================================================================}
function TRangeArrayHelper.Merge: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  a: Boolean;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  a := Self[0].Ascending;
  S := Self.Normalized;
  S.SortByStart;
  SetLength(Result, S.Length);
  l := 0;
  R := S[0];
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      if not a then
        R.Reverse;
      Result[l.Increase] := R;
      R := S[i];
    end else
      R.stop := Max(R.stop, S[i].stop);
  if not a then
    R.Reverse;
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Merged>
  @action: In-place merge of overlapping and adjacent ranges
  @note: Operates on normalized copy; adjacency = (start <= stop + 1); compacts via index overwrite
[==============================================================================}
function TRangeArrayHelper.Merged: TRangeArray; overload;
var
  i, r: Integer;
begin
  Result := Self.Normalized;
  if (Result.Length < 2) then
    Exit;
  r := 0;
  Result.SortByStart;
  for i := 1 to High(Result) do
    if (Result[i].start <= (Result[r].stop + 1)) then
      Result[r].stop := Max(Result[r].stop, Result[i].stop)
    else
      Result[r.Increment] := Result[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Mergified>
  @action: Returns a new array of merged ranges from the original array.
           Overlapping or nearby ranges (within optional 'threshold') are combined
           into minimal contiguous ranges.
  @note:
    - Non-destructive: does not modify the original array.
    - Threshold defaults to -1 (only strictly overlapping ranges are merged).
    - Useful for creating a canonical, merged representation of ranges.
[==============================================================================}
function TRangeArrayHelper.Mergified(const threshold: Integer = -1): TRangeArray; overload;
var
  s: TRangeArray;
  h, j, i, l: Integer;
  c, r: TRange;
begin
  s := Self.Normalized;
  h := High(s);
  if (h < 1) then
    Exit;
  for i := 0 to (h - 1) do
    for j := (i + 1) to h do
      if (s[i].start > s[j].start) then
        Swap(s[i], s[j]);
  SetLength(Result, (h + 1));
  l := 0;
  c := s[0];
  for i := 1 to h do
  begin
    r := s[i];
    if (r.start > (c.stop + threshold + 1)) then
    begin
      Result[l.Increase] := c;
      c := r;
    end else if (r.stop > c.stop) then
      c.stop := r.stop;
  end;
  Result[l] := c;
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Mergify>
  @action: Merges overlapping or nearby ranges into contiguous ranges.
           Ranges within the optional 'threshold' distance are combined.
  @note:
    - Operates in-place and updates the array.
    - Returns the number of merged ranges.
    - Threshold defaults to -1 (only strictly overlapping ranges are merged).
    - Useful for cleaning up scattered, overlapping, or adjacent ranges.
[==============================================================================}
function TRangeArrayHelper.Mergify(const threshold: Integer = -1): Integer; overload;
var
  h, i, w: Integer;
begin
  h := High(Self);
  Result := 0;
  if (h < 1) then
    Exit;
  Self.Normalizify;
  Self.SortByStart;
  for i := 1 to h do
    if (Self[i].start > (Self[Result].stop + threshold + 1)) then
      Self[Result.Increment] := Self[i]
    else if (Self[i].stop > Self[Result].stop) then
      Self[Result].stop := Self[i].stop;
  SetLength(Self, Result.Increment);
end;

{==============================================================================]
  <Restacked>
  @action: Merge overlapping and adjacent ranges into a minimal set
  @note:
    - Input is normalized and sorted by Start
    - Adjacent ranges are merged (Start <= Prev.Stop + 1)
    - Uses stack to accumulate merged ranges
    - Time complexity: O(n log n) due to sorting
    - Requires Normalized to ensure Start <= Stop
[==============================================================================}
function TRangeArrayHelper.Restacked: TRangeArray; overload;
var
  r: TRangeArray;
  i: Integer;
  t: TRange;
  s: specialize TStack<TRange>;
begin
  if (Self.Length < 2) then
    Exit(Self.Normalized);
  r := Self.Normalized;
  r.SortByStart;
  s := specialize TStack<TRange>.Create;
  try
    s.Push(r[0]);
    for i := 1 to High(r) do
      if (r[i].start <= (s.Peek.stop + 1)) then
      begin
        t := s.Pop;
        t.stop := Max(t.stop, r[i].stop);
        s.Push(t);
      end else
        s.Push(r[i]);
    Result := s.ToArray;
  finally
    s.Free;
  end;
end;

{==============================================================================
  <Scanlined>
  @action: Merge ranges using scanline (event sweep) algorithm
  @note:
    - Converts each range into two events: (start, +1) and (stop + 1, -1)
    - Sorts events by position (ascending)
    - Accumulates active count (coverage depth)
    - New segment starts when count transitions 0 -> >0
    - Segment ends when count transitions >0 -> 0
    - Adjacent ranges are merged due to (stop + 1) encoding
    - Handles overlapping, nested, and unordered ranges
    - Time complexity: O(n log n) due to sorting
    - Output is normalized and non-overlapping
==============================================================================}
function TRangeArrayHelper.Scanlined: TRangeArray; overload;
type
  TDeltaPoint = record
    position: Integer;
    delta: Integer;
  end;
var
  P: array of TDeltaPoint;
  h, i, o, c, s, z: Integer;
  procedure QS(L, R: Integer);
  var
    I, J, T: Integer;
    D: TDeltaPoint;
  begin
    I := L;
    J := R;
    T := P[L + (R - L) div 2].position;
    repeat
      while (P[I].position < T) do
        Inc(I);
      while (P[J].position > T) do
        Dec(J);
      if (I <= J) then
      begin
        D := P[I];
        P[I] := P[J];
        P[J] := D;
        Inc(I);
        Dec(J);
      end;
    until (I > J);
    if (L < J) then
      QS(L, J);
    if (I < R) then
      QS(I, R);
  end;
begin
  z := Self.Length;
  if (z = 0) then
    Exit([]);
  SetLength(P, (z * 2));
  for i := 0 to (z - 1) do
  begin
    P[i * 2].position := Min(Self[i].start, Self[i].stop);
    P[i * 2].delta := 1;
    P[i * 2 + 1].position := (Max(Self[i].start, Self[i].stop) + 1);
    P[i * 2 + 1].delta := -1;
  end;
  h := High(P);
  if (h > 0) then
    QS(0, h);
  SetLength(Result, z);
  o := 0;
  c := 0;
  for i := 0 to h do
  begin
    if (c = 0) then
      s := P[i].position;
    Inc(c, P[i].delta);
    if ((c = 0) and ((i = h) or (P[i + 1].position > P[i].position))) then
      Result[o.Increase].Create(s, (P[i].position - 1));
  end;
  SetLength(Result, o);
end;

{==============================================================================]
  <Simplify>
  @action: Normalizes, sorts, and merges overlapping or adjacent ranges into a
           minimal non-overlapping set.
  @note: Steps:
           1. Normalizes all ranges (`start <= stop`).
           2. Sorts ranges by `Minimum` (ascending).
           3. Sequentially merges overlapping or adjacent ranges (stop + 1).
           4. Compacts result to final length.
         Time complexity: O(n log n) due to sort; merge pass O(n).
         Produces normalized, non-overlapping ranges. Original array is not modified.
         Equivalent to Fuse after normalization; does not preserve direction.
[==============================================================================}
function TRangeArrayHelper.Simplify: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  S := Self.Normalized;
  S.SortByMinimum(True);
  SetLength(Result, S.Length);
  R := S[0];
  l := 0;
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      Result[l.Increase] := R;
      R := S[i];
    end else
	  R.stop := Max(R.stop, S[i].stop);
  Result[l.Increase] := R;
  SetLength(Result, l);
end;

{==============================================================================]
  <Squashed>
  @action: Incrementally merge overlapping and adjacent ranges into result
  @note: Input normalized and sorted; adjacency = (start <= stop + 1); grows result dynamically
[==============================================================================}
function TRangeArrayHelper.Squashed: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  i, h: Integer;
begin
  S := Self.Normalized;
  if (S.Length < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(Result, 0);
  h := -1;
  for i := 0 to High(S) do
  begin
    R := S[i];
    if (h = -1) then
    begin
      SetLength(Result, (h.Increment + 1));
      Result[h] := R;
      Continue;
    end;
    if (R.Start > (Result[h].Stop + 1)) then
    begin
      SetLength(Result, (h.Increment + 1));
      Result[h] := R;
    end else if (R.Stop > Result[h].Stop) then
      Result[h].Stop := R.Stop;
  end;
end;

{==============================================================================]
  <Squeeze>
  @action: Returns a new TRangeArray with all values from the original ranges
           flattened, sorted, deduplicated, and regrouped into contiguous streaks.
  @returns: TRangeArray containing normalized ranges covering all unique values.
  @note:
    - Converts the original TRangeArray to a flat integer array (TIA).
    - Sorts the integers in ascending order.
    - Removes duplicate values.
    - Converts consecutive sequences of integers back into contiguous ranges.
    - The resulting ranges are minimal: no overlapping ranges and no duplicates.
    - Original ranges with gaps between them may be merged if the sequences
      of values are contiguous.
    - Preserves ascending order for each resulting streak.
	- rAscending for Ascending or Descending order for the returning array.
[==============================================================================}
function TRangeArrayHelper.Squeeze(const rAscending: Boolean = True): TRangeArray; overload;
begin
  Result := Self.TIA.QuickSorted(rAscending).Compressed.Streaks;
end;

{==============================================================================]
  <Stream>
  @action: Flattens all ranges into individual integers, removes duplicates, sorts them,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - Produces a fully canonical, minimal set of disjoint ranges.
    - Duplicates and overlapping integers are automatically removed.
    - The parameter oAscending controls the ordering of the output.
    - Internally flattens ranges to integers, so large ranges may consume more memory temporarily.
[==============================================================================}
function TRangeArrayHelper.Stream(const oAscending: Boolean = True): TRangeArray; overload;
var
  i, j, r, l: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(s, Self.Sized);
  r := 0;
  for i := 0 to (l - 1) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s[r.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, l);
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if ((Result[r].stop + j) = s[i]) then
      Result[r].stop := s[i]
    else if (s[i] <> s[i - 1]) then
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Streamed>
  @action: Flattens all ranges to individual integers, sorts and deduplicates them,
           and reconstructs contiguous ranges in ascending or descending order.
  @note:
    - The parameter oAscending controls the ordering of the output ranges.
    - Duplicates and overlapping ranges are removed automatically.
    - Produces a canonical, minimal set of disjoint ranges covering all integers.
    - May consume more memory temporarily for large ranges, due to flattening.
    - Result is fully normalized and ordered.
[==============================================================================}
function TRangeArrayHelper.Streamed(const oAscending: Boolean = True): TRangeArray; overload;
var
  i, j, r, l: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(s, Self.Sized);
  r := 0;
  for i := 0 to (l - 1) do
    for j := Self[i].Minimum to Self[i].Maximum do
      s[r.Increase] := j;
  s.QuickSort(oAscending);
  SetLength(Result, l);
  s.Compress;
  r := 0;
  Result[0].Create(s[0]);
  j := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if ((Result[r].stop + j) = s[i]) then
      Result[r].stop := s[i]
    else
      Result[r.Increment].Create(s[i]);
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Streamline>
  @action: Produces a canonical union of all ranges in the array. 
           Handles reversed, overlapping, or disordered ranges, 
           and outputs the minimal set of disjoint, contiguous ranges.
  @note:
    - Internally uses a bitmap to track all integers in all ranges.
    - All duplicates, overlaps, and reversed ranges are automatically handled.
    - Result covers every integer present in any input range exactly once.
    - This is effectively a “streamed union” operation.
[==============================================================================}
function TRangeArrayHelper.Streamline: TRangeArray; overload;
var
  a, h, i, p, s, o: Integer;
  n: TRangeArray;
  r: TRange;
  b: TBooleanArray;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(n, (h + 1));
  r := Self[0].Normalized;
  for i := 0 to h do
  begin
    if (Self[i].start <= Self[i].stop) then
      n[i] := Self[i]
    else
      n[i] := Self[i].Reversed;
    if (n[i].start < r.start) then
      r.start := n[i].start;
    if (n[i].stop > r.stop) then
      r.stop := n[i].stop;
  end;
  o := -r.start;
  SetLength(b, (r.stop + o + 2));
  for i := 0 to High(n) do
    for p := n[i].start to n[i].stop do
      b[p + o] := True;
  SetLength(Result, 0);
  p := 0;
  a := High(b);
  while (p <= a) do
    if b[p] then
    begin
      s := p;
      while ((p <= a) and b[p]) do
        Inc(p);
      Result.Supply(TRange.Construct((s - o), (p - 1 - o)));
    end else
      Inc(p);
end;

{==============================================================================]
  <Unionized>
  @action: Produces the union of all ranges by merging any that overlap or are
           directly adjacent, using a Disjoint Set Union (Union-Find, DSU) structure.
           Each input range is treated as a node in a connectivity graph.
           Two nodes are unioned if their ranges intersect or touch
           (i.e. adjacency is considered mergeable). The resulting connected
           components represent merged ranges.
           The final output contains one consolidated range per DSU component.
  @note:
    - Preprocessing:
        * Input is first normalized (Self.Normalized).
        * Then sorted by start (TRangeArray_SortByStart).
    - Union condition:
        For consecutive ranges i and i+1:
          S[i+1].start <= (h[F(i)] + 1)
        This merges:
          * overlapping ranges
          * directly adjacent ranges (gap = 0)
    - DSU internals:
        * p[] : parent links (path compression applied in F)
        * z[] : rank/height heuristic (union by rank)
        * l[] : component minimum bound
        * h[] : component maximum bound
        On union:
          * roots are merged using rank heuristic
          * bounds are updated:
              l[root] = min(l[a], l[b])
              h[root] = max(h[a], h[b])
    - Optimization:
        Only adjacent pairs are tested after sorting. This is sufficient
        because any transitive overlap/adjacency chain will propagate
        through consecutive unions.
    - Output construction:
        * Each DSU root represents a merged range.
        * Traversal order depends on oAscending:
            True  → forward order, ranges as [lo, hi]
            False → reverse order, ranges as [hi, lo]
    - Complexity:
        * Sorting:        O(n log n)
        * Union-Find:     O(n α(n))  (α = inverse Ackermann)
        * Overall:        O(n log n)
    - Characteristics:
        * Non-destructive: operates on a normalized copy (S).
        * Stable merging independent of input ordering.
        * Conceptually models merging as graph connectivity rather than
          sequential interval folding.
    - Edge cases:
        * n < 2 → returns normalized input directly.
        * Assumes normalized ranges have valid start ≤ stop.
[==============================================================================}
function TRangeArrayHelper.Unionized(const oAscending: Boolean = True): TRangeArray; overload;
var
  p, z, l, h: TIntegerArray;
  n, i, r: Integer;
  S: TRangeArray;
  function F(x: Integer): Integer;
  begin
    while (p[x] <> x) do
    begin
      p[x] := p[p[x]];
      x := p[x];
    end;
    Result := x;
  end;
  procedure U(const x, y: Integer);
  var
    a, b: Integer;
  begin
    a := F(x);
    b := F(y);
    if (a = b) then
      Exit;
    if (z[a] < z[b]) then
      Swap(a, b);
    p[b] := a;
    if (z[a] = z[b]) then
      Inc(z[a]);
    l[a] := Min(l[a], l[b]);
    h[a] := Max(h[a], h[b]);
  end;
begin
  S := Self.Normalized;
  n := S.Length;
  if (n < 2) then
    Exit(S);
  S.SortByStart;
  SetLength(p, n);
  SetLength(z, n);
  SetLength(l, n);
  SetLength(h, n);
  for i := 0 to (n - 1) do
  begin
    p[i] := i;
    z[i] := 0;
    l[i] := S[i].start;
    h[i] := S[i].stop;
  end;
  for i := 0 to (n - 2) do
    if (S[i + 1].start <= (h[F(i)] + 1)) then
      U(i, (i + 1));
  SetLength(Result, n);
  r := 0;
  case oAscending of
    True:
    for i := 0 to (n - 1) do
      if (F(i) = i) then
        Result[r.Increase].Create(l[i], h[i]);
    False:
    for i := (n - 1) downto 0 do
      if (F(i) = i) then
        Result[r.Increase].Create(h[i], l[i]);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Unite>
  @action: Merges overlapping or adjacent ranges in a TRangeArray into the smallest
           set of disjoint ranges. Produces a canonical union of all ranges.
  @note:
    - If mAdjacent is True, ranges that are immediately contiguous (stop + 1 >= start)
      are merged as well.
    - If mAdjacent is False, only strictly overlapping ranges are merged.
    - Input ranges are normalized and sorted internally before merging.
    - Returns an empty array if the input array has fewer than two ranges.
    - Result preserves ascending order by start value.
[==============================================================================}
function TRangeArrayHelper.Unite(const mAdjacent: Boolean = True): TRangeArray; overload;
var
  i, l, r: Integer;
  m: Boolean;
begin
  Result := Self.Normalized;
  l := Result.Length;
  if (l < 2) then
    Exit;
  Result.SortByStart;
  r := 0;
  for i := 1 to (l - 1) do
  begin
    if mAdjacent then
      m := (Result[i].start <= (Result[r].stop + 1))
    else
      m := Result[r].Overlap(Result[i]);
    if m then
      Result[r].stop := Max(Result[r].stop, Result[i].stop)
    else
      Result[r.Increment] := Result[i];
  end;
  SetLength(Result, (r + 1));
end;
{$ENDIF}
