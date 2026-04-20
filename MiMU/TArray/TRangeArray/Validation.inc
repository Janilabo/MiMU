{$IFDEF HELPERS}
function Cohesive: Boolean; overload;
function Continuous: Boolean; overload;
function Gapless: Boolean; overload;
function Integral: Boolean; overload;
function Solid: Boolean; overload;
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
{$ENDIF}
