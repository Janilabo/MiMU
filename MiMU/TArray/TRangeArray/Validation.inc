{$IFDEF HELPERS}
function Cohesive: Boolean; overload;
function Contiguous: Boolean; overload;
function Continuous: Boolean; overload;
function Gapless: Boolean; overload;
function Integral: Boolean; overload;
function Monolithic: Boolean; overload;
function Seamless: Boolean; overload;
function Solid: Boolean; overload;
function Unbroken: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cohesive>
  @action: Checks if the sorted range sequence forms a single continuous span.
  @returns: True if there are no gaps between segments; False otherwise.
  @note: Uses a high-speed linear scan. A "gap" is defined as any space 
         greater than 1 unit between the current maximum reach and the 
         next segment's start.
[==============================================================================}
function TRangeArrayHelper.Cohesive: Boolean; overload;
var
  s: TRangeArray;
  i, m: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.Normalized.SortedByStart;
  m := s[0].stop;
  for i := 0 to (High(s) - 1) do
    if (s[i + 1].start > (m + 1)) then
      Exit(False)
    else if (s[i + 1].stop > m) then
      m := s[i + 1].stop;
  Result := True;
end;

{==============================================================================]
  <Contiguous>
  @action: Uses recursive merging to see if all ranges belong to one "island."
  @returns: True if the entire array collapses into a single segment.
  @note: This is the "Flood-Fill" of range logic.
[==============================================================================}
function TRangeArrayHelper.Contiguous: Boolean; overload;
var
  s: TRangeArray;
  i: Integer;
  c: Boolean;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.Normalized.SortedByStart;
  repeat
    c := False;
    i := 1;
    while (i <= High(s)) do
      if s[0].Linkable(s[i]) then
      begin
        s[0].start := Min(s[0].start, s[i].start);
        s[0].stop := Max(s[0].stop, s[i].stop);
        s.RemoveIndex(i);
        c := True;
      end else
        Inc(i);
  until not c;
  Result := (s.Length = 1);
end;

{==============================================================================]
  <Continuous>
  @action: Determines if the array of ranges forms a single continuous span.
  @returns: True if all ranges overlap or touch to form one segment.
  @note: This is a destructive check on a local copy. It merges all 
         connectable segments and checks if the final count is 1.
[==============================================================================}
function TRangeArrayHelper.Continuous: Boolean; overload;
var
  s: TRangeArray;
  i: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.Normalized;
  s.SortByStart;
  i := 0;
  while (i < High(s)) do
    if s[i].Linkable(s[i + 1]) then
    begin
      s[i].start := Min(s[i].start, s[i + 1].start);
      s[i].stop := Max(s[i].stop, s[i + 1].stop);
      s.Zap(i + 1); 
    end else
      Inc(i);
  Result := (s.Length = 1);
end;

{==============================================================================]
  <Gapless>
  @action: Checks if the combined ranges form a single, continuous interval 
           without any numerical voids.
  @note: This method flattens all start/stop boundaries into a sorted list. 
         It returns True if no two adjacent boundaries in the sorted set are 
         separated by more than 1 unit, effectively bridging overlaps.
[==============================================================================}
function TRangeArrayHelper.Gapless: Boolean; overload;
var
  i: Integer;
  s: TIntegerArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.TIA.Cleaned;
  for i := 1 to High(s) do
    if (s[i] > (s[i - 1] + 1)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Integral>
  @action: Verifies if the range collection forms a single, unbroken span.
  @note: True if all segments are connected (no gaps > 1); False otherwise.
[==============================================================================}
function TRangeArrayHelper.Integral: Boolean; overload;
var
  s: TRangeArray;
  i, l, h: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.Normalized.SortedByStart;
  l := s[0].start;
  h := s[0].stop;
  for i := 0 to High(s) do
    if (s[i].start > (h + 1)) then
      Exit(False)
    else if (s[i].stop > h) then
      h := s[i].stop;
  Result := ((h - l) >= (s[High(s)].stop - s[0].start));
end;

{==============================================================================]
  <Monolithic>
  @action: Validates continuity by splitting the array and bridging sub-sections.
  @returns: True if the segments form an unbroken chain.
  @note: Sorting by Start is the engine; it ensures r[0].start is the
         minimum possible entry point for the right-hand partition.
         Recursive Divide & Conquer.
[==============================================================================}
function TRangeArrayHelper.Monolithic: Boolean; overload;
  function C(const aSub: TRangeArray): Boolean;
  var
    l, r: TRangeArray;
    m: Integer;
    x, y: Integer;
  begin
    if (aSub.Length <= 1) then
      Exit(True);
    m := (aSub.Length div 2);
    l := aSub.Copy(0, m);
    r := aSub.Copy(m, (aSub.Length - m));
    if not C(l) then
      Exit(False);
    if not C(r) then
      Exit(False);
    x := l.MaxStop;
    y := r[0].start;
    Result := (x >= (y - 1));
  end;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  Result := C(Self.Normalized.SortedByStart);
end;

{==============================================================================]
  <Seamless>
  @action: Determines whether all ranges form a continuous coverage without gaps.
  @note: Returns True if the union of all ranges in the array completely covers
         the interval from the global minimum to the global maximum. Internally
         builds a coverage map and marks each integer position spanned by the
         ranges; if any position remains unmarked, the result is False. Overlaps
         are allowed, but any uncovered gap causes failure. Arrays of length 0
         return False, length 1 returns True.
[==============================================================================}
function TRangeArrayHelper.Seamless: Boolean; overload;
var
  l, h, i, j: Integer;
  m: TBooleanArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  l := Self.MinimumValue;
  h := Self.MaximumValue;
  SetLength(m, ((h - l) + 1));
  FillChar(m[0], m.Length, 0);
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      m[j - l] := True;
  for i := 0 to High(m) do
    if not m[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Solid>
  @action: Verifies that the collective ranges form a single, unbroken span 
           without any numerical gaps.
  @note: Uses a sweep-line algorithm to track the maximum reach of overlapping 
         intervals. This method correctly handles nested, overlapping, and 
         sequential ranges.
[==============================================================================}
function TRangeArrayHelper.Solid: Boolean; overload;
var
  i, r: Integer;
  s: TRangeArray;
begin
  if (Self.Length < 2) then
    Exit(Self.Length = 1);
  s := Self.Normalized;
  s.SortByStart;
  r := s[0].stop;
  for i := 1 to High(s) do
    if (s[i].start > (r + 1)) then
      Exit(False)
    else if (s[i].stop > r) then
      r := s[i].stop;
  Result := True;
end;

{==============================================================================]
  <Unbroken>
  @action: Determines whether a set of ranges forms a continuous interval without gaps.
  @note: Returns True if the union of all ranges is gap-free. The ranges are first
         normalized and sorted by their starting points. Iteratively tracks the
         furthest reachable endpoint (r) and verifies that each subsequent range
         begins at or before r + 1. If any range starts beyond this boundary, a
         gap exists and the result is False. Overlapping and adjacent ranges are
         both accepted.
[==============================================================================}
function TRangeArrayHelper.Unbroken: Boolean; overload;
var
  a, b: TIntegerArray;
  h, i, j, r: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(h = 0);
  Self.Normalized.SortedByStart.Unzip(a, b);
  b.QuickSort;
  r := b[0];
  i := 1;
  for j := 1 to h do
  begin
    while ((i <= h) and (b[i] < a[j])) do
    begin
      if (b[i] > r) then
        r := b[i];
      Inc(i);
    end;
    if (a[j] > (r + 1)) then
      Exit(False);
  end;
  Result := True;
end;
{$ENDIF}
