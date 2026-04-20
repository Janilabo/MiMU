{$IFDEF HELPERS}
function Gapless: Boolean; overload;
function Solid: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
