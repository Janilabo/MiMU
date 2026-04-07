{$IFDEF HELPERS}
function Complement: TRangeArray; overload;
function Cracks(const rAscending: Boolean = True): TRangeArray; overload;
function Gaps: TRangeArray; overload;
function Holes: TRangeArray; overload;
function Spaces: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Complement>
  @action: Returns the complement intervals between consecutive ranges in a TRangeArray.
           Each complement range spans from the end of one range to the start of the next
           when they are not exactly contiguous.
  @note:
    - Does not offset start/stop; uses raw `stop` and `start` values.
    - Only gaps between non-touching consecutive ranges are returned.
    - Result may be empty if all ranges are contiguous or overlapping.
    - Pre-allocates maximum length and then trims unused slots for efficiency.
[==============================================================================}
function TRangeArrayHelper.Complement: TRangeArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([]);
  r := 0;
  SetLength(Result, (l - 1));
  for i := 0 to (l - 2) do
    if (Self[i].stop <> Self[i + 1].start) then
      Result[r.Increase] := TRange.Construct(Self[i].stop, Self[i + 1].start);
  SetLength(Result, r);
end;

{==============================================================================]
  <Cracks>
  @action: Computes the “cracks” (adjusted gaps) between consecutive ranges in a TRangeArray.
           Gaps are adjusted by ±1 depending on the direction (ascending or descending).
  @note:
    - If ascending, cracks are [stop_i + 1, start_(i+1) - 1] when ranges are separated.
    - If descending, logic mirrors the ascending case with reversed iteration and offsets.
    - Ensures gaps do not overlap with the original ranges.
    - Returns empty array if fewer than 2 ranges exist.
    - Result is trimmed to remove unused slots.
    - Useful for detecting strictly internal missing intervals in ordered ranges.
[==============================================================================}
function TRangeArrayHelper.Cracks(const rAscending: Boolean = True): TRangeArray; overload;
var
  i, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([]);
  r := 0;
  SetLength(Result, (l - 1));
  case rAscending of
    True:
    for i := 0 to (l - 2) do
      if ((Self[i].stop + 1) < Self[i + 1].start) then
        Result[r.Increase] := TRange.Construct((Self[i].stop + 1), (Self[i + 1].start - 1))
      else if ((Self[i].stop - 1) > Self[i + 1].start) then
        Result[r.Increase] := TRange.Construct((Self[i].stop - 1), (Self[i + 1].start + 1));
    False:
    for i := (l - 1) downto 1 do
      if ((Self[i].start - 1) > Self[i - 1].stop) then
        Result[r.Increase] := TRange.Construct((Self[i].start - 1), (Self[i - 1].stop + 1))
      else if ((Self[i].start + 1) < Self[i + 1].stop) then
        Result[r.Increase] := TRange.Construct((Self[i].start + 1), (Self[i - 1].stop - 1));
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Gaps>
  @action: Computes all gaps between consecutive ranges in the array.
  @note: Normalizes and sorts ranges first.
         Each resulting range represents a non-overlapping interval between adjacent ranges. 
		 Returns empty array if less than two ranges.
[==============================================================================}
function TRangeArrayHelper.Gaps: TRangeArray; overload;
var
  i, g: Integer;
  n: TRangeArray;
  a, b: Integer;
  procedure SortNormRanges(var r: TRangeArray);
  var
    a, b: Integer;
  begin
    for a := 0 to (High(r) - 1) do
      for b := (a + 1) to High(r) do
        if (r[a].start > r[b].start) then
	  Swap(r[a], r[b])
  end;
begin
  g := 0;
  if (Self.Size > 1) then
  begin
    SetLength(n, Self.Size);
    n := Self.Normalized;
    SortNormRanges(n);
    SetLength(Result, (Self.Size - 1));
    for i := 0 to (High(n) - 1) do
    begin
      a := (n[i].stop + 1);
      b := (n[i + 1].start - 1);
      if (a <= b) then
        Result[g.Increase].Create(a, b);
    end;
  end;
  SetLength(Result, g);
end;

{==============================================================================]
  <Holes>
  @action: Computes the gaps (holes) between consecutive ranges in a TRangeArray.
           Returns a new array of ranges representing all uncovered intervals.
  @note:
    - Overlapping and adjacent ranges are merged first to ensure correctness.
    - If the array contains fewer than two ranges, the result is empty.
    - Each hole is defined as [previous.stop + 1, next.start - 1].
    - The function does not filter out empty ranges where start > stop; 
      caller should handle this if needed.
    - Useful for complement operations or detecting missing intervals in a set of ranges.
[==============================================================================}
function TRangeArrayHelper.Holes: TRangeArray; overload;
var
  s: TRangeArray;
  i, l: Integer;
begin
  s := Self.Unite;
  l := s.Length;
  SetLength(Result, 0);
  if (l < 2) then
    Exit;
  SetLength(Result, (l - 1));
  for i := 0 to (l - 2) do
  begin
    Result[i].start := (s[i].stop + 1);
    Result[i].stop := (s[i + 1].start - 1);
  end;
end;

{==============================================================================]
  <Spaces>
  @action: Computes all uncovered intervals (spaces) between ranges in a TRangeArray.
           Each space is guaranteed not to overlap any original range.
  @note:
    - Ranges are first normalized (start ≤ stop) to ensure correct calculations.
    - Returns intervals [stop_i + 1, start_(i+1) - 1] for ascending order,
      and [stop_(i+1) + 1, start_i - 1] for descending cases.
    - If fewer than 2 ranges exist, the result is empty.
    - The function handles both ascending and descending ranges dynamically.
    - Uses pre-allocated array with `r.Increase` to compactly store spaces.
    - Result contains only the true gaps—no overlapping or touching intervals.
[==============================================================================}
function TRangeArrayHelper.Spaces: TRangeArray; overload;
var
  n: TRangeArray;
  i, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([]);
  n := Self.Normalized;
  r := 0;
  SetLength(Result, (l - 1));
  for i := 0 to (l - 2) do
    if ((n[i].stop + 1) < n[i + 1].start) then
      Result[r.Increase] := TRange.Construct((n[i].stop + 1), (n[i + 1].start - 1))
    else if ((n[i].start - 1) > n[i + 1].stop) then
      Result[r.Increase] := TRange.Construct((n[i + 1].stop + 1), (n[i].start - 1));
  SetLength(Result, r);
end;
{$ENDIF}
