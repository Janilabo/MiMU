{$IFDEF HELPERS}
function Cordon(const target: MType; const oAscending: Boolean = True): TRange; overload;
function Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
function Swath(const target: MType; const oAscending: Boolean = True): TRange; overload;
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
  if ((Result.start > Result.stop) or (Self[Result.start] <> item)) then
    Result.Create(Low(Integer));
end;

{==============================================================================]
  <Swath>
  @action: Performs a linear scan on a sorted array to locate the start and end indices of a contiguous block of elements equal to target.
  @note: Uses binary-search-style early termination during the initial scan based on the oAscending flag.
         Once the first matching element is located, it scans forward linearly to find the last identical element.
		 Operates in O(N) worst-case time complexity and returns a TRange of inclusive indices, or (-1, -1) if target is missing.
[==============================================================================}
function MArrayHelper.Swath(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  h: Integer;
begin
  h := High(Self);
  Result.start := 0;
  while ((Result.start <= h) and (Self[Result.start] <> target) and (oAscending = (Self[Result.start] < target))) do
    Inc(Result.start);
  if ((Result.start > h) or (Self[Result.start] <> target)) then
    Exit(TRange.Construct(-1, -1));
  Result.stop := Result.start;
  while ((Result.stop < h) and (Self[Result.stop + 1] = target)) do
    Inc(Result.stop);
end;
{$ENDIF}
