{$IFDEF HELPERS}
function Cordon(const target: MType; const oAscending: Boolean = True): TRange; overload;
function Fathom(const item: MType; const oAscending: Boolean = True): Integer; overload;
function Sift(const item: MType; const oAscending: Boolean = True): Integer; overload;
function Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
function FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cordon>
  @action: Finds the range of indices (min..max) containing all occurrences of `target` in a sorted array using a stack-based divide-and-conquer strategy.
  @note: Returns `(start: -1, stop: -1)` if `target` is not present, if the array is empty, or if `target` falls outside the array's bounds.
         Supports both ascending and descending order via `oAscending`.
[==============================================================================}
function MArrayHelper.Cordon(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  s: TRangeArray;
  h, t, m: Integer;
  l, r, z: TRange;
  f: Boolean;
  procedure P(const aStart, aStop: Integer);
  begin
    if (aStart > aStop) then
      Exit;
    Inc(t);
    if (t >= s.Length) then
      SetLength(s, ((s.Length * 2) + 16));
    s[t].start := aStart;
    s[t].stop := aStop;
  end;
  procedure A(const aStart, aStop: Integer);
  begin
    if not f then
    begin
      Result.start := aStart;
      Result.stop := aStop;
      f := True;
    end else if (aStart < Result.start) then
      Result.start := aStart
    else if (aStop > Result.stop) then
      Result.stop := aStop;
  end;
  function C(const aStart, aStop: Integer): Boolean;
  begin
    if oAscending then
      Result := ((Self[aStart] <= target) and (Self[aStop] >= target))
    else
      Result := ((Self[aStart] >= target) and (Self[aStop] <= target));
  end;
begin
  Result.start := -1;
  Result.stop := -1;
  h := High(Self);
  if ((h = -1) or ((oAscending and ((target < Self[0]) or (target > Self[h]))) or ((not oAscending) and ((target > Self[0]) or (target < Self[h])))))  then
    Exit;
  f := False;
  SetLength(s, 16);
  t := -1;
  P(0, h);
  while (t >= 0) do
  begin
    z := s[t.Decrease];
    if not C(z.start, z.stop) then
      Continue;
    if (z.start = z.stop) then
    begin
      if (Self[z.start] = target) then
        A(z.start, z.stop);
      Continue;
    end else if ((Self[z.start] = target) and (Self[z.stop] = target)) then
    begin
      A(z.start, z.stop);
      Continue;
    end;
    m := (z.start + ((z.stop - z.start) div 2));
    l.start := z.start;
    l.stop := m;
    r.start := (m + 1);
    r.stop := z.stop;
    P(l.start, l.stop);
    P(r.start, r.stop);
  end;
end;

{==============================================================================]
  <Fathom>
  @action: Searches a sorted array (ascending or descending, per `oAscending`) for `item`,
           returning its index, or -1 if absent.
  @note: Not a true binary search — no midpoint bisection, no discarding of half the search
         space. Uses a linear scan of `i` combined with a lookahead window that doubles in
         size each iteration; once the window reaches the array's end (within O(log n)
         iterations), the remainder is scanned in one pass. Degrades to O(n) overall.
         Relies on `Increment` mutating and returning the post-mutation value (prefix-style);
         `i.Increment < s` and the loop body stay in lockstep only under that contract.
[==============================================================================}
function MArrayHelper.Fathom(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  i, d, s, m, r: Integer;
begin
  s := Self.Length;
  i := -1;
  d := 1;
  case oAscending of
    True:
    while (i.Increment < s) do
    begin
      if (Self[i] = item) then
        Exit(i);
      m := Min((i + d), (s - 1));
      if ((item > Self[i]) and (item <= Self[m])) then
      for r := (i + 1) to m do
        if (Self[r] = item) then
          Exit(r)
        else if (Self[r] > item) then
          Exit(-1);
      d := (d * 2);
    end;
    False:
    while (i.Increment < s) do
    begin
      if (Self[i] = item) then
        Exit(i);
      m := Min((i + d), (s - 1));
      if ((item < Self[i]) and (item >= Self[m])) then
      for r := (i + 1) to m do
        if (Self[r] = item) then
          Exit(r)
        else if (Self[r] < item) then
          Exit(-1);
      d := (d * 2);
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <Sift>
  @action: Searches a sorted array (ascending or descending, per `oAscending`) for `item`,
           returning its index, or -1 if absent.
  @note: Exponential/galloping search — unlike `Fathom`, the probe position itself advances
         exponentially (`Result := m + 1`, where `m` was already `Result + r`), reaching
         the array's tail in O(log n) outer iterations rather than relying on the lookahead
         window alone. `Break`s out to the sorted-order overshoot fallback the instant
         `Self[Result]` passes `item`. Uses a plain local (`i`) as the inner scan counter
         rather than reusing `Result`, so the return value only ever comes from an explicit
         `Exit`.
[==============================================================================}
function MArrayHelper.Sift(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  i, l, r, m: Integer;
begin
  Result := 0;
  l := Self.Length;
  r := 1;
  case oAscending of
    True:
    while (Result < l) do
      if (Self[Result] = item) then
        Exit
      else if (Self[Result] > item) then
        Break
      else
      begin
        m := Min((Result + r), (l - 1));
        if ((Self[Result] < item) and (item <= Self[m])) then
        begin
          for i := Result to m do
            if (Self[i] = item) then
              Exit(i);
          Exit(-1);
        end else
        begin
          Result := (m + 1);
          r := (r * 2);
        end;
      end;
    False:
    while (Result < l) do
      if (Self[Result] = item) then
        Exit
      else if (Self[Result] < item) then
        Break
      else
      begin
        m := Min((Result + r), (l - 1));
        if ((Self[Result] > item) and (item >= Self[m])) then
        begin
          for i := Result to m do
            if (Self[i] = item) then
              Exit(i);
          Exit(-1);
        end else
        begin
          Result := (m + 1);
          r := (r * 2);
        end;
      end;
  end;
  Result := -1;
end;

{==============================================================================]
  <Spanning>
  @action: Searches the array for the specified `item` and returns a TRange
           representing the inclusive index span where `item` occurs.
           Works for both ascending and descending arrays, as specified by `oAscending`.
           If the array is empty or the item is not found, returns a sentinel TRange
           with both `start` and `stop` set to Low(Integer).
  @note:
    - `oAscending` indicates whether the array is sorted in ascending order (True)
      or descending order (False).
    - Scans from both ends of the array:
        - `Result.start` increments until the first occurrence of `item` is found.
        - `Result.stop` decrements until the last occurrence of `item` is found.
    - Works correctly with negative numbers.
    - Returned TRange:
        - `Result.start <= Result.stop` → item found; range of indices inclusive.
        - `Result.start > Result.stop` → item not found; sentinel range returned.
    - Time complexity: O(n) (linear search).
[==============================================================================}
function MArrayHelper.Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
begin
  if Self.Empty then
    Exit(TRange.Construct(Low(Integer), Low(Integer)));
  Result.Create(0, High(Self));
  while ((Result.start < Result.stop) and ((oAscending and (Self[Result.start] < item)) or ((not oAscending) and (Self[Result.start] > item)))) do
    Inc(Result.start);
  while ((Result.stop >= Result.start) and ((oAscending and (Self[Result.stop] > item)) or ((not oAscending) and (Self[Result.stop] < item)))) do
    Dec(Result.stop);
  if (Result.start > Result.stop) then
    Result.Create(Low(Integer));
end;

{==============================================================================]
  <FibonacciSearch>
  @action: Executes a Fibonacci Search over the array.
           The routine locates the index of a target value using progressively
           shrinking search intervals determined by the Fibonacci sequence.
           The array may be sorted in ascending or descending order as
           specified by the oAscending parameter. Returns the index of the
           matching element if found; otherwise returns -1.
  @note: Fibonacci Search is an alternative to binary search that partitions
         the search interval using Fibonacci ratios rather than powers of two.
         It preserves ordered-search correctness while enabling searches that
         favor sequential access patterns. Performance is comparable to
         binary search for random-access arrays and may offer advantages for
         memory-hierarchy–sensitive workloads. The input array must be
         pre-sorted in the order defined by oAscending.
[==============================================================================}
function MArrayHelper.FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  H, o, i: Integer;
  F: TRange;
begin
  H := High(Self);
  F.Create(0, 1);
  M := (F.stop + F.start);
  while (M < (H + 1)) do
  begin
    F.start := F.stop;
    F.stop := M;
    M := (F.stop + F.start);
  end;
  o := -1;
  while (M > 1) do
  begin
    i := Integer(o + F.start).ClampMax(H);
    case ((oAscending and (Self[i] < item)) or ((not oAscending) and (Self[i] > item))) of
      True:
      begin
        M := F.stop;
        F.stop := F.start;
        F.start := (M - F.stop);
        o := i;
      end;
      False:
      case ((oAscending and (Self[i] > item)) or ((not oAscending) and (Self[i] < item))) of
        True:
        begin
          M := F.start;
          F.stop := (F.stop - F.start);
          F.start := (M - F.stop);
        end;
        False: Exit(i);
      end;
    end;
  end;
  if ((F.stop = 1) and ((o + 1) <= H) and (Self[o + 1] = item)) then
    Exit(o + 1);
  Result := -1;
end;
{$ENDIF}
