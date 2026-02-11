{$IFDEF HELPERS}
function Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Consolidate: TRangeArray; overload;
function Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Fusion: TRangeArray; overload;
function Merge(const rAscending: Boolean = True): TRangeArray; overload;
function Merged(const rAscending: Boolean = True): TRangeArray; overload;
function Rangified: TRangeArray; overload;
function Rangify: TRangeArray; overload;
function Sequences: TRangeArray; overload;
function Strands: TRangeArray; overload;
function Streaks: TRangeArray; overload;
function Streams: TRangeArray; overload;
function ToTRA(const buffer: Integer = 0): TRangeArray; overload;
function ToTRangeArray: TRangeArray; overload;
function TRA: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Combinate>
  @action: Merges the contents of Self and items into a single sorted array and removes
           duplicate values during the merge. The merge preserves the specified ordering
           (ascending or descending) and guarantees that the resulting array contains only
           unique values in correct sorted order.
  @note: Combine & Unduplicate
[==============================================================================}
function TIntegerArrayHelper.Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  s: TIntegerArray;
  l, a, i, j, k, v, c: Integer;
begin
  l := Self.Length;
  a := items.Size;
  if ((l = 0) and (a = 0)) then
  begin
    SetLength(Self, 0);
    Exit(0);
  end;
  s := Self.Copy;
  SetLength(Self, (l + a));
  i := 0;
  j := 0;
  k := 0;
  v := IfThen(oAscending, 2147483647, -2147483648);
  while ((i < l) or (j < a)) do
  begin
    c := 0;
    case oAscending of
      True:
      if ((i < l) and ((j >= a) or (s[i] <= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
      False:
      if ((i < l) and ((j >= a) or (s[i] >= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
    end;
    if ((k = 0) or (c <> v)) then
    begin
      Self[k.Increase] := c;
      v := c;
    end;
  end;
  if (k <> Self.Size) then
    SetLength(Self, k);
  Result := k;
end;

{==============================================================================]
  <Consolidate>
  @action: Collapses adjacent integer values into contiguous ranges without
           altering the original ordering of the array.
           Returns an array of TRange records, where each range represents a contiguous
           sequence of integers detected while iterating the source array.
  @note:
    - The source array is processed in its existing order; no sorting
      is performed.
    - Correct consolidation requires the array to already be ordered
      such that adjacent values differ by at most ±1.
    - Consecutive values differing by +1 extend the current range upward.
    - Consecutive values differing by −1 extend the current range downward.
    - Duplicate values are ignored.
    - An empty source array returns an empty result.
[==============================================================================}
function TIntegerArrayHelper.Consolidate: TRangeArray; overload;
var
  h, i, c: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  SetLength(Result, (h + 1));
  c := 0;
  Result[c].Create(Self[0], Self[0]);
  for i := 1 to h do
  begin
    if (Self[i] = (Result[c].stop + 1)) then
      Result[c].stop := Self[i]
    else if (Self[i] = (Result[c].stop - 1)) then
      Result[c].start := Self[i]
    else if (Self[i] = Result[c].stop) then
      Continue
    else
      Result[c.Increment].Create(Self[i], Self[i]);
  end;
  if (c <= h) then
    SetLength(Result, (c + 1));
end;

{==============================================================================]
  <Fuse>
  @action: Merge the contents of Self with the given items array using a standard merge-operation.
           Both arrays must already be sorted in the order specified by oAscending.
           The function produces a single sorted array containing all elements,
           from both sources, preserving duplicates. The merged result
           replaces Self and the final length of the array is returned.
  @note: - Both Self and items must be pre-sorted in the same ordering; the routine
           does not perform any sorting beyond the merge step.
         - All values from Self and items are preserved; no deduplication occurs.
         - The resulting array is always sorted according to oAscending.
         - Operation runs in O(n + m) time and allocates temporary storage equal to
           the length of Self.
         - The merge preserves element stability with respect to the original Self
           and items ordering.
[==============================================================================}
function TIntegerArrayHelper.Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  l, a, i, j, k: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  a := items.Size;
  Result := (l + a);
  if (a = 0) then
    Exit;
  if (l = 0) then
  begin
    Self := items.Copy;
    Exit;
  end;
  s := Self.Copy;
  SetLength(Self, Result);
  i := 0;
  j := 0;
  k := 0;
  case oAscending of
    True:
    while ((i < l) and (j < a)) do
      if (s[i] <= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
    False:
    while ((i < l) and (j < a)) do
      if (s[i] >= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
  end;
  while (i < l) do
    Self[k.Increase] := s[i.Increase];
  while (j < a) do
    Self[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <Fusion>
  @action: Aggregates neighboring integer values into contiguous TRange segments
           when successive elements differ by at most ±1. Each resulting range
           is normalized so that Start holds the minimum and Stop the maximum
           value observed within the fused cluster.
  @note:
    - Returns an empty TRangeArray when the source array is empty.
    - The input order is preserved; no sorting is performed.
    - Fusion condition:
      Self[i + 1] ∈ [Self[i] - 1 .. Self[i] + 1]
      This supports increasing sequences, decreasing sequences,
      and duplicate values.
    - During fusion:
        • The range is initialized with Create(Self[i]).
        • For each accepted neighbor, the index is advanced first,
          then Start/Stop are adjusted to maintain:
          Start = Min(cluster values)
          Stop  = Max(cluster values)
      This guarantees Start ≤ Stop regardless of traversal direction.
    - Initial capacity equals Length and is trimmed to the actual
      number of produced ranges.
    - Time complexity: O(n)
    - Space complexity: O(n)
[==============================================================================}
function TIntegerArrayHelper.Fusion: TRangeArray; overload;
var
  h, i, l: Integer;
begin
  if Self.Empty then
    Exit([]);
  h := High(Self);
  SetLength(Result, (h + 1));
  l := 0;
  i := 0;
  while (i <= h) do
  begin
	Result[l].Create(Self[i]);
    while ((i < h) and InRange(Self[i + 1], (Self[i] - 1), (Self[i] + 1))) do
	begin
	  Inc(i);
	  if (Self[i] < Result[l].start) then
	    Result[l].start := Self[i]
      else if (Self[i] > Result[l].stop) then
	    Result[l].stop := Self[i];
	end;
    Inc(l);
    Inc(i);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Merge>
  @action: Consolidates the integer values of the array into a minimal set of
           contiguous TRange instances. Adjacent values (based on ordering
           direction) are coalesced into a single range.
  @note:
    - If the array is empty, an empty TRangeArray is returned.
    - The input array is first sorted using QuickSorted according to rAscending.
    - Duplicate values are ignored.
    - Contiguity is determined by a step of:
      +1 when rAscending = True
      -1 when rAscending = False
    - Each resulting range is inclusive: Create(StartValue, EndValue).
    - Time complexity:
      O(n log n) due to sorting
    - Space complexity:
      O(n)
[==============================================================================}
function TIntegerArrayHelper.Merge(const rAscending: Boolean = True): TRangeArray; overload;
var
  i, s, e, c, d: Integer;
  a: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  a := Self.QuickSorted(rAscending);
  SetLength(Result, a.Length);
  c := 0;
  s := a[0];
  e := a[0];
  d := IfThen(rAscending, 1, -1);
  for i := 1 to High(a) do
  begin
    if (a[i] = e) then
      Continue;
    if (a[i] <> (e + d)) then
    begin
      Result[c.Increase].Create(s, e);
      s := a[i];
    end;
    e := a[i];
  end;
  Result[c.Increase].Create(s, e);
  SetLength(Result, c);
end;

{==============================================================================]
  <Merged>
  @action: Returns a set of integer ranges created by merging adjacent values
           in the array. rAscending determines the sort order used before merging.
           If True (default), values are sorted ascending and merged when
           successive elements differ by +1.
           If False, values are sorted descending and merged when successive
           elements differ by −1.
           Result is an array of TRange records, where each range represents
		   a maximal contiguous sequence of integers from the source array.
  @note:
    - The source array is not modified.
    - The array is internally sorted prior to merging.
    - Duplicate values are implicitly collapsed into the same range.
    - An empty source array returns an empty result.
[==============================================================================}
function TIntegerArrayHelper.Merged(const rAscending: Boolean = True): TRangeArray; overload;
var
  h, i, l, r, c: Integer;
  s: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  s := Self.QuickSorted(rAscending);
  h := High(Self);
  SetLength(Result, (h + 1));
  c := 0;
  l := 0;
  case rAscending of
    True:
    while (l <= h) do
    begin
      r := l;
      while ((r < h) and (s[r + 1] <= (s[r] + 1))) do
        Inc(r);
      Result[c.Increase].Create(s[l], s[r]);
      l := (r + 1);
    end;
    False:
    while (l <= h) do
    begin
      r := l;
      while ((r < h) and (s[r + 1] >= (s[r] - 1))) do
        Inc(r);
      Result[c.Increase].Create(s[l], s[r]);
      l := (r + 1);
    end;
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Rangified>
  @action: Partitions the integer array into maximal consecutive (±1 step) monotonic
           runs and converts each run into a TRange.
  @note:
    - The array is processed in its current order; it is not sorted.
    - A new range starts when:
        • The step between adjacent elements is not ±1, or
        • The direction changes (increasing ↔ decreasing).
    - Duplicate values break a run (step = 0).
    - An empty array returns an empty TRangeArray.
    - Each resulting range is created as: TRange.Create(StartValue, EndValue)
      where StartValue and EndValue correspond to the first and last
      elements of the run.
[==============================================================================}
function TIntegerArrayHelper.Rangified: TRangeArray; overload;
var
  i, l, n, s, p: Integer;
begin
  SetLength(Result, 0);
  l := Self.Length;
  if (l = 0) then
    Exit;
  n := 0;
  p := 0;
  for i := 1 to (l - 1) do
  begin
    s := (Self[i] - Self[i - 1]);
    if ((Abs(s) <> 1) or ((p <> 0) and (s <> p))) then
    begin
      Result.Supply(TRange.Construct(Self[n], Self[i - 1]));
      n := i;
      p := 0;
      Continue;
    end;
    p := s;
  end;
  Result.Supply(TRange.Construct(Self[n], Self[l - 1]));
end;

{==============================================================================]
  <Rangify>
  @action: Partitions the integer array into maximal consecutive (±1 step) monotonic
           runs and converts each run into a TRange.
  @note:
    - The array is processed in its current order; it is not sorted.
    - A new range starts when:
        • The step between adjacent elements is not ±1, or
        • The direction changes (increasing ↔ decreasing).
    - Duplicate values break a run (step = 0).
    - An empty array returns an empty TRangeArray.
    - Each resulting range is created as: TRange.Create(StartValue, EndValue)
      where StartValue and EndValue correspond to the first and last
      elements of the run.
[==============================================================================}
function TIntegerArrayHelper.Rangify: TRangeArray; overload;
var
  i, c, l, p, s: Integer;
  b: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(b, l);
  b[0] := 0;
  c := 1;
  p := 0;
  for i := 1 to (l - 1) do
  begin
    s := (Self[i] - Self[i - 1]);
    if (Abs(s) <> 1) then
    begin
      b[c.Increase] := i;
      p := 0;
      Continue;
    end;
    if ((i > 1) and (p <> 0) and (s <> p)) then
      b[c.Increase] := i;
    p := s;
  end;
  b[c] := l;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    Result[i].Create(Self[b[i]], Self[b[i + 1] - 1]);
end;

{==============================================================================]
  <Sequences>
  @action: Splits the integer array into consecutive ascending or descending ranges,
           returning them as an array of TRange.
  @note: Handles both ascending and descending sequences.
         Single elements are returned as ranges with identical start and stop values.
[==============================================================================}
function TIntegerArrayHelper.Sequences: TRangeArray; overload;
  function PS(const left, right: Integer): TRangeArray;
  var
    i, d, c: Integer;
  begin
    if (left > right) then
      Exit([]);
    if (left = right) then
      Exit([TRange.Construct(Self[left], Self[left])]);
    SetLength(Result, ((right - left) + 1));
    c := 0;
    i := left;
    while (i <= right) do
    begin
      if (i = right) then
        d := 0
      else if (Self[i + 1] = (Self[i] + 1)) then
        d := 1
      else if (Self[i + 1] = (Self[i] - 1)) then
        d := -1
      else
        d := 0;
      Result[c].start := Self[i];
      while ((i < right) and (((d = 1) and (Self[i + 1] = (Self[i] + 1))) or ((d = -1) and (Self[i + 1] = (Self[i] - 1))))) do
        Inc(i);
      Result[c].stop := Self[i];
      Inc(c);
      Inc(i);
    end;
    SetLength(Result, c);
  end;
begin
  Result := PS(0, High(Self));
end;

{==============================================================================]
  <Strands>
  @action: Splits the integer array into contiguous sequences (“strands”) where
           consecutive elements consistently increase or decrease by 1, and
           returns them as ranges.
           An array of TRange records, each representing a maximal ascending or
           descending sequence from the original array.
  @note:
    - The source array is processed in its original order; no sorting occurs.
    - A strand continues as long as consecutive elements differ by +1 (ascending)
      or -1 (descending). Any change in direction or non-consecutive value
      ends the strand.
    - Single elements not part of a strand become degenerate ranges
      (Start = Stop).
    - Empty arrays return an empty result.
[==============================================================================}
function TIntegerArrayHelper.Strands: TRangeArray; overload;
var
  h, c, i: Integer;
  function HasNext(var idx: Integer): Boolean;
  begin
    Result := (idx <= h);
  end;
  function NextRange(var idx: Integer): TRange;
  var
    s, d: Integer;
  begin
    if (idx = h) then
      Exit(TRange.Construct(Self[idx.Increase]));
    s := idx;
    if (Self[idx + 1] = (Self[idx] + 1)) then
      d := 1
    else if (Self[idx + 1] = (Self[idx] - 1)) then
      d := -1
    else
      d := 0;
    while ((idx < h) and (((d = 1) and (Self[idx + 1] = (Self[idx] + 1))) or ((d = -1) and (Self[idx + 1] = (Self[idx] - 1))))) do
      Inc(idx);
    Result.Create(Self[s], Self[idx.Increase]);
  end;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  SetLength(Result, (h + 1));
  c := 0;
  i := 0;
  while HasNext(i) do
    Result[c.Increase] := NextRange(i);
  SetLength(Result, c);
end;

{==============================================================================]
  <Streaks>
  @action: Identifies contiguous sequences of integers (“streaks”) in the array
           where consecutive elements consistently increase or decrease by 1,
           and returns them as ranges.
           Returns an array of TRange records, where each range represents a maximal
           ascending or descending streak.
  @note:
    - The source array is not modified; processing is order-sensitive.
    - A streak continues as long as consecutive elements differ by +1
      (ascending) or -1 (descending). Any change or pause ends the streak.
    - Single elements not part of a streak become degenerate ranges
      (Start = Stop).
    - Empty arrays return an empty result.
[==============================================================================}
function TIntegerArrayHelper.Streaks: TRangeArray; overload;
var
  h, i, c, d: Integer;
  function PeekDirection(const idx: Integer): Integer;
  begin
    if (idx >= h) then
      Result := 0
    else if (Self[idx + 1] = (Self[idx] + 1)) then
      Result := 1
    else if (Self[idx + 1] = (Self[idx] - 1)) then
      Result := -1
    else
      Result := 0;
  end;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  c := 0;
  i := -1;
  while (i.Increment <= h) do
  begin
    Result[c].start := Self[i];
    d := PeekDirection(i);
    while ((i < h) and (d <> 0) and (PeekDirection(i) = d)) do
      Inc(i);
    Result[c].stop := Self[i];
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Streams>
  @action: Converts an integer array into contiguous ranges (“streams”) by grouping
           consecutive elements that increment or decrement by 1, taking into account
           changes in direction to start a new stream.
           Returns a TRangeArray, where each range represents a maximal contiguous
           sequence of ascending or descending integers from the original array.
  @note:
    - The source array is processed in its original order; no sorting occurs.
    - A new stream begins whenever:
        * A non-consecutive element is encountered (difference ≠ ±1), or
        * A direction reversal occurs after at least two consecutive elements.
    - Single elements not part of a sequence become degenerate ranges
      (Start = Stop).
    - Empty arrays return an empty TRangeArray.
[==============================================================================}
function TIntegerArrayHelper.Streams: TRangeArray; overload;
var
  i, j, c, l: Integer;
  b: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(b, l);
  b[0] := 0;
  c := 1;
  for i := 1 to (l - 1) do
    if (((Self[i] <> (Self[i - 1] + 1)) and (Self[i] <> (Self[i - 1] - 1))) or ((i > 1) and (((Self[i - 1] = (Self[i - 2] + 1)) and (Self[i] = (Self[i - 1] - 1))) or ((Self[i - 1] = (Self[i - 2] - 1)) and (Self[i] = (Self[i - 1] + 1)))))) then
      b[c.Increase] := i;
  b[c] := l;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    Result[i].Create(Self[b[i]], Self[b[i + 1] - 1]);
end;

{==============================================================================]
  <ToTRA>
  @action: Converts a TIntegerArray into a TRangeArray by grouping consecutive
           or near-consecutive values into ranges.
  @param buffer: Determines how close values must be to form a range:
                  -1 : merge only overlapping values (duplicates).  
                   0 : merge touching values (adjacent integers).  
                  ≥1 : merge values separated by gaps ≤ buffer.
  @returns: TRangeArray containing ranges representing contiguous sequences
            according to the buffer parameter.
  @note:
    - The integer array is first sorted ascending (`QuickSorted`).  
    - Iterates through the sorted values, extending the current range if
      the next value is within `(stop + 1 + buffer)`.  
    - If the next value exceeds this limit, a new range is started.  
    - The resulting ranges are ascending, non-overlapping, and cover
      all values in the array.  
    - Empty input arrays return an empty `TRangeArray`.  
    - Duplicates in the original array are naturally merged into ranges.
[==============================================================================}
function TIntegerArrayHelper.ToTRA(const buffer: Integer = 0): TRangeArray; overload;
var
  s: TIntegerArray;
  c: TRange;
  b, i: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  b := Max(buffer, -1);
  s := Self.QuickSorted;
  c.Create(s[0]);
  for i := 1 to High(s) do
  case (s[i] <= ((c.stop + 1) + b)) of
    False:
    begin
      Result.Supply(c);
      c.Create(s[i]);
    end;
    True:
    if (s[i] > c.stop) then
      c.stop := s[i];
  end;
  Result.Supply(c);
end;

{==============================================================================]
  <ToTRangeArray>
  @action: Converts the integer array into an array of TRange values, where each range
           represents a maximal contiguous sequence of ascending or descending integers.
           Adjacent values differing by +1 form ascending ranges; values differing by −1
           form descending ranges. Non-contiguous values start new ranges.
  @note:
    - The input array is processed in its existing order (no sorting is performed).
    - Both ascending and descending sequences are supported.
    - Single elements are returned as ranges with identical start/stop values.
    - An empty array returns an empty result.
[==============================================================================}
function TIntegerArrayHelper.ToTRangeArray: TRangeArray; overload;
const
  STATE_NO = 0;
  STATE_ASC = 1;
  STATE_DESC = 2;
var
  h, i, s, c: Integer;
begin
  h := High(Self);
  case h of
    -1: Exit;
    0: Exit([TRange.Construct(Self[0])]);
  end;
  SetLength(Result, (h + 1));
  Result[0].Create(Self[0]);
  c := 0;
  s := STATE_NO;
  for i := 1 to h do
  case s of
    STATE_NO:
    case Self[i].Difference(Result[c].stop) of
      -1:
      begin
        Result[c].stop := Self[i];
        s := STATE_ASC;
      end;
      1:
      begin
        Result[c].stop := Self[i];
        s := STATE_DESC;
      end;
    else
      Result[c.Increment].Create(Self[i]);
    end;
    STATE_ASC:
    if not (Self[i] = (Result[c].stop + 1)) then
    begin
      Result[c.Increment].Create(Self[i]);
      s := STATE_NO;
    end else
      Result[c].stop := Self[i];
    STATE_DESC:
    if not (Self[i] = (Result[c].stop - 1)) then
    begin
      Result[c.Increment].Create(Self[i]);
      s := STATE_NO;
    end else
      Result[c].stop := Self[i];
  end;
  SetLength(Result, (c + 1));
end;

{==============================================================================]
  <TRA>
  @action: Converts the integer array into contiguous ranges while preserving
           the original element order and detected progression direction.
           Returns an array of TRange records representing maximal contiguous sequences
           of integers encountered during sequential traversal of the array.
  @note:
    - The source array is processed in its existing order; no sorting
      is performed.
    - Ranges are formed only when consecutive elements differ by ±1.
    - Direction of progression is tracked:
        * +1 extends an ascending sequence.
        * −1 extends a descending sequence.
      A change in direction terminates the current range.
    - Duplicate values are ignored.
    - Non-adjacent values terminate the current range.
    - Arrays with fewer than two elements return an empty result.
[==============================================================================}
function TIntegerArrayHelper.TRA: TRangeArray; overload;
var
  h, i, c, d: Integer;
  r: TRange;
begin
  h := High(Self);
  case h of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0])]);
  end;
  SetLength(Result, (h + 1));
  c := 0;
  r.Create(Self[0]);
  d := 0;
  for i := 1 to h do
  case Self[i].Compare(r.stop) of
    0: Continue;
    1:
    begin
      case ((d = 0) or (d = 1)) of
        True:
        begin
          r.stop := Self[i];
          d := 1;
        end;
        False:
        begin
          Result[c.Increase] := r;
          r.Create(Self[i]);
          d := 0;
        end;
      end;
    end;
    -1:
    case ((d = 0) or (d = -1)) of
      True:
      begin
        r.stop := Self[i];
        d := -1;
      end;
      False:
      begin
        Result[c.Increase] := r;
        r.Create(Self[i]);
        d := 0;
      end;
    end;
  else
    begin
      Result[c.Increase] := r;
      r.Create(Self[i]);
      d := 0;
    end;
  end;
  Result[c.Increase] := r;
  SetLength(Result, c);
end;
{$ENDIF}
