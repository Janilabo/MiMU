{$IFDEF METHODS}
function Common(const other: TRange): TIntegerArray; overload;
function Commons(const other: TRange): TIntegerArray; overload;
function CommonWith(const other: TRange): TIntegerArray; overload;
function Diverge(const other: TRange): TIntegerArray; overload;
function Excluded(const other: TRange): TIntegerArray; overload;
function Exclusive(const other: TRange): TIntegerArray; overload;
function Included(const other: TRange): TIntegerArray; overload;
function Shared(const other: TRange): TIntegerArray; overload;
function Shares(const other: TRange): TIntegerArray; overload;
function Sharing(const other: TRange): TIntegerArray; overload;
function Uncommon(const other: TRange): TIntegerArray; overload;
function Uncommons(const other: TRange): TIntegerArray; overload;
function UncommonWith(const other: TRange): TIntegerArray; overload;
function Unshared(const other: TRange): TIntegerArray; overload;
function Unshares(const other: TRange): TIntegerArray; overload;
function Unsharing(const other: TRange): TIntegerArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Subtract(const other: TRange): TRangeArray; overload;
function Without(const other: TRange): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Common>
  @action: Returns the elements shared by Self and other.
  @note:
    - Computes the intersection: Self ∩ other.
    - Bounds are normalized implicitly via Min/Max to support any direction.
    - If the ranges do not overlap, an empty array is returned.
    - Result is always contiguous and includes both endpoints.
    - Ordering follows Self (ascending or descending).
    - Result length is (h - l + 1), where l/h are the overlap bounds.
[==============================================================================}
function TRange.Common(const other: TRange): TIntegerArray; overload;
var
  a: Boolean;
  l, h, i: Integer;
begin
  a := Self.Ascending;
  l := Max(Min(Self.start, Self.stop), Min(other.start, other.stop));
  h := Min(Max(Self.start, Self.stop), Max(other.start, other.stop));
  if (l > h) then
    Exit([]);
  SetLength(Result, ((h - l) + 1));
  for i := 0 to High(Result) do
    Result[i] := IfThen(a, (l + i), (h - i));
end;

{==============================================================================]
  <Commons>
  @action: Returns the elements present in both Self and other.
  @note:
    - Computes the intersection: Self ∩ other.
    - Both ranges are normalized before evaluation.
    - Uses a boolean membership map over the combined bounds [min..max]
      to test inclusion of other within Self.
    - If there is no overlap, an empty array is returned.
    - Result is not constructed via direct bounds, but by membership testing,
      and is therefore equivalent to <Common> though less direct.
    - Ordering follows Self (ascending or descending).
    - Result is trimmed to the number of matched elements.
    - Capacity is preallocated to Min(Self.Size, other.Size).
[==============================================================================}
function TRange.Commons(const other: TRange): TIntegerArray; overload;
var
  l, h, i, r: Integer;
  m: TBooleanArray;
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  l := Min(s.start, o.start);
  h := Max(s.stop, o.stop);
  SetLength(m, ((h - l) + 1));
  for i := s.start to s.stop do
    m[i - l] := True;
  SetLength(Result, Min(s.Size, o.Size));
  r := 0;
  case Self.Ascending of
    True:
    for i := o.start to o.stop do
      if m[i - l] then Result[r.Increase] := i;
    False:
    for i := o.stop downto o.start do
      if m[i - l] then Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CommonWith>
  @action: Returns the integer elements common to both ranges. Computes the
           intersection of the current range and the specified range as a
           contiguous sequence of values.
  @note:
    - If the ranges do not overlap, an empty array is returned.
    - The result ordering follows the direction (ascending or descending)
      of the current range (Self), independent of the other range.
    - The intersection is computed using inclusive bounds [l, h].
    - Result length is calculated as (h - l + 1) for efficiency.
[==============================================================================}
function TRange.CommonWith(const other: TRange): TIntegerArray; overload;
var
  a: Boolean;
  l, h, i: Integer;
begin
  l := Max(Self.Minimum, other.Minimum);
  h := Min(Self.Maximum, other.Maximum);
  if (l > h) then
    Exit([]);
  a := Self.Ascending;
  SetLength(Result, ((h - l) + 1));
  for i := 0 to High(Result) do
    Result[i] := IfThen(a, (l + i), (h - i));
end;

{==============================================================================]
  <Diverge>
  @action: Returns the elements that are unique to either Self or other, excluding any shared elements.
  @note:
    - Computes the symmetric difference: (Self − other) ∪ (other − Self).
    - Equivalent to <Exclusive>; essentially a concatenation of both Uncommons arrays.
    - If the ranges do not overlap, the result is the combined contents of both ranges.
    - If the ranges are identical, the result is empty.
    - Result preserves the ordering of each input range.
    - Uses Concat() for combining both difference arrays.
[==============================================================================}
function TRange.Diverge(const other: TRange): TIntegerArray; overload;
begin
  Result := Concat(Self.Uncommons(other), other.Uncommons(Self));
end;

{==============================================================================]
  <Excluded>
  @action: Returns values present in Self but not in Other.
  @note: Result is ordered according to Self's direction.
[==============================================================================}
function TRange.Excluded(const other: TRange): TIntegerArray; overload;
var
  i, v, d: Integer;
begin
  SetLength(Result, 0);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  for i := 0 to (Self.Size - 1) do
  begin
    if not other.Contains(v) then
      Result := (Result + [v]);
    Inc(v, d);
  end;
end;

{==============================================================================]
  <Exclusive>
  @action: Returns the elements that belong to either Self or other, but not both.
  @note:
    - Computes the symmetric difference: (Self − other) ∪ (other − Self).
    - Internally combines:
      Self.Uncommons(other) and other.Uncommons(Self).
    - If the ranges do not overlap, the result is the concatenation of both ranges.
    - If the ranges are identical, the result is empty.
    - Result may consist of up to two disjoint segments from each input range.
    - Ordering of each segment follows its source range.
    - Result is formed by concatenating both difference arrays without reordering.
    - Capacity is preallocated to the sum of both partial results.
[==============================================================================}
function TRange.Exclusive(const other: TRange): TIntegerArray; overload;
var
  a, b: TIntegerArray;
  x, y: Integer;
begin
  a := Self.Uncommons(other);
  b := other.Uncommons(Self);
  x := a.Length;
  y := b.Length;
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(a[0], Result[0], (x * SizeOf(Integer)));
  if (y > 0) then
    Move(b[0], Result[x], (y * SizeOf(Integer)));
end;

{==============================================================================]
  <Included>
  @action: Returns values present in both Self and Other, ordered according
           to Self's direction.
  @note: Equivalent to a set intersection viewed from Self's perspective.
         Returns an empty array if the ranges share no common values.
         Result length is at most Min(Self.Size, Other.Size).
[==============================================================================}
function TRange.Included(const other: TRange): TIntegerArray; overload;
var
  i, v, d: Integer;
begin
  SetLength(Result, 0);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  for i := 0 to (Self.Size - 1) do
  begin
    if other.Contains(v) then
      Result := (Result + [v]);
    Inc(v, d);
  end;
end;

{==============================================================================]
  <Shared>
  @action: Returns an array of every integer that exists in both ranges.
  @note: The order of the resulting array matches the direction of 'Self'.
         If there is no overlap, returns an empty array.
[==============================================================================}
function TRange.Shared(const other: TRange): TIntegerArray; overload;
var
  r: TRange;
  i, s: Integer;
begin
  if not Self.Meet(other, r) then
    Exit([]);
  s := r.Size;
  if (s = 1) then
    Exit([r.start]);
  SetLength(Result, s);
  case Self.Ascending of
    True:
    for i := 0 to (s - 1) do
      Result[i] := r.start.Increase;
    False:
    for i := 0 to (s - 1) do
      Result[i] := r.stop.Decrease;
  end;
end;

{==============================================================================]
  <Shares>
  @action: Returns integers present in both ranges using a two-pointer walk.
  @note: Both ranges are treated as sorted sequences (ascending).
         Direction of Self is re-applied to the result afterward.
[==============================================================================}
function TRange.Shares(const other: TRange): TIntegerArray; overload;
var
  a, b, x, y, r: Integer;
begin
  SetLength(Result, Min(Self.Size, other.Size));
  r := 0;
  a := Min(Self.start, Self.stop);
  x := Max(Self.start, Self.stop);
  b := Min(other.start, other.stop);
  y := Max(other.start, other.stop);
  while ((a <= x) and (b <= y)) do
  case (a = b) of
    True:
    begin
      Result[r.Increase] := a.Increase;
      Inc(b);
    end;
    False:
    if (a < b) then
      Inc(a)
    else
      Inc(b);
  end;
  SetLength(Result, r);
  if not Self.Ascending then
    Result.Reverse;
end;

{==============================================================================]
  <Sharing>
  @action: Returns an array of values from this range that exist in the other.
  @note: Maintains the direction of 'Self'.
[==============================================================================}
function TRange.Sharing(const other: TRange): TIntegerArray; overload;
var
  i, r, v, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := 0;
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to (s - 1) do
  begin
    v := (Self.start + (i * d));
    if other.Contains(v) then
      Result[r.Increase] := v;
  end;
  if (r < s) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Subtract>
  @action: Returns an array of TRange segments representing the parts of 'Self' 
           that do not overlap with 'other'.
  @note: Uses an "Inversion" strategy by intersecting 'Self' with the 
         theoretical infinite space before and after the 'other' range.
         The resulting segments are returned in an order and direction 
         matching 'Self' (Ascending vs Descending).
[==============================================================================}
function TRangeHelper.Subtract(const other: TRange): TRangeArray; overload;
var
  R: TRange;
begin
  case Self.Ascending of
    True:
    begin
      if Self.Meet(TRange.Construct(Low(Integer), (other.Minimum - 1)), R) then
        Result.Supply(R);
      if Self.Meet(TRange.Construct((other.Maximum + 1), High(Integer)), R) then
        Result.Supply(R);
	end;
	False:
    begin
      if Self.Meet(TRange.Construct((other.Maximum + 1), High(Integer)), R) then
        Result.Supply(R.Reversed);
	  if Self.Meet(TRange.Construct(Low(Integer), (other.Minimum - 1)), R) then
        Result.Supply(R.Reversed);
	end;
  end;
end;

{==============================================================================]
  <Uncommon>
  @action: Returns the elements of Self not shared with other.
  @note:
    - Computes the difference: Self − (Self ∩ other).
    - Both ranges are normalized prior to evaluation.
    - If there is no overlap, the full contents of Self are returned.
    - If other fully covers Self, the result is empty.
    - Result may consist of up to two contiguous segments:
        (1) values before the overlap
        (2) values after the overlap
    - Ordering follows Self (ascending or descending).
    - Result is trimmed to the number of elements actually written.
[==============================================================================}
function TRange.Uncommon(const other: TRange): TIntegerArray; overload;
var
  i, r: Integer;
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  SetLength(Result, Self.Size);
  r := 0;
  case Self.Ascending of
    True:
    begin
      for i := s.start to Min(s.stop, (o.start - 1)) do
        Result[r.Increase] := i;
      for i := Max(s.start, (o.stop + 1)) to s.stop do
        Result[r.Increase] := i;
    end;
    False:
    begin
      for i := s.stop downto Max(s.start, (o.stop + 1)) do
        Result[r.Increase] := i;
      for i := Min(s.stop, (o.start - 1)) downto s.start do
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Uncommons>
  @action: Returns the elements of Self that are not present in other.
  @note:
    - Computes the difference: Self − other.
    - Both ranges are normalized prior to evaluation.
    - Uses a boolean membership map over the combined bounds [min..max]
      to mark elements of other and exclude them from Self.
    - If there is no overlap, the full contents of Self are returned.
    - If other fully covers Self, the result is empty.
    - Result is constructed via membership testing rather than direct bounds.
    - Ordering follows Self (ascending or descending).
    - Result is trimmed to the number of elements actually written.
    - Capacity is preallocated to Self.Size.
[==============================================================================}
function TRange.Uncommons(const other: TRange): TIntegerArray; overload;
var
  l, h, i, r: Integer;
  m: TBooleanArray;
  s, o: TRange;
begin
  s := Self.Normalize;
  o := other.Normalize;
  l := Min(s.start, o.start);
  h := Max(s.stop, o.stop);
  SetLength(m, ((h - l) + 1));
  for i := o.start to o.stop do
    m[i - l] := True;
  SetLength(Result, s.Size);
  r := 0;
  case Self.Ascending of
    True:
    for i := s.start to s.stop do
      if not m[i - l] then
        Result[r.Increase] := i;
    False:
    for i := s.stop downto s.start do
      if not m[i - l] then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <UncommonWith>
  @action: Returns all integer elements of the current range that are not present
           in the intersection with another range. Effectively computes the
           relative complement of the overlapping segment.
  @note:
    - If the two ranges do not overlap, the full set of digits from Self is returned.
    - The order of the result preserves the original direction (ascending or descending).
    - The function assumes Normalize ensures start <= stop for internal calculations,
      while iteration respects the original range direction.
    - Result size is precomputed for efficiency based on overlap length.
[==============================================================================}
function TRange.UncommonWith(const other: TRange): TIntegerArray; overload;
var
  a: Boolean;
  l, h, i, r: Integer;
  s: TRange;
begin
  s := Self.Normalize;
  l := Max(s.start, other.Minimum);
  h := Min(s.stop, other.Maximum);
  if (l > h) then
    Exit(Self.Digits);
  a := Self.Ascending;
  SetLength(Result, (Self.Size - ((h - l) + 1)));
  r := 0;
  case a of
    True:
    begin
      for i := s.start to (l - 1) do
        Result[r.Increase] := i;
      for i := (h + 1) to s.stop do
        Result[r.Increase] := i;
    end;
    False:
    begin
      for i := s.stop downto (h + 1) do
        Result[r.Increase] := i;
      for i := (l - 1) downto s.start do
        Result[r.Increase] := i;
    end;
  end;
end;

{==============================================================================]
  <Unshared>
  @action: Returns the elements of Self excluding those within the overlap with other.
  @note:
    - Implements the set difference: Self − (Self ∩ other).
    - If Self and other do not intersect, a full extraction of Self is returned.
    - If other fully overlaps Self, the result is empty.
    - The result consists of up to two contiguous segments:
        (1) values before the intersection
        (2) values after the intersection
    - Ordering is preserved according to TRange_Ascending(Self).
    - Result length is exactly Self.Size - (Self ∩ other).Size.
[==============================================================================}
function TRange.Unshared(const other: TRange): TIntegerArray; overload;
var
  r: TRange;
  i, l: Integer;
begin
  if not Self.Meet(other, r) then
    Exit(Self.Extract);
  SetLength(Result, (Self.Size - r.Size));
  l := 0;
  case Self.Ascending of
    True:
    begin
      for i := Self.start to (r.start - 1) do
        Result[l.Increase] := i;
      for i := (r.stop + 1) to Self.stop do
        Result[l.Increase] := i;
    end;
    False:
    begin
      for i := Self.start downto (r.stop + 1) do
        Result[l.Increase] := i;
      for i := (r.start - 1) downto Self.stop do
        Result[l.Increase] := i;
    end;
  end;
end;

{==============================================================================]
  <Unshares>
  @action: Returns integers in Self that are NOT in other (Self − Self∩other).
  @note: Same two-pointer strategy; emits from Self whenever other doesn't match.
[==============================================================================}
function TRange.Unshares(const other: TRange): TIntegerArray; overload;
var
  a, b, x, y, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  a := Min(Self.start, Self.stop);
  x := Max(Self.start, Self.stop);
  b := Min(other.start, other.stop);
  y := Max(other.start, other.stop);
  while (a <= x) do
  case ((b > y) or (a < b)) of
    False:
    if (a = b) then
    begin
      Inc(a);
      Inc(b);
    end else
      Inc(b);
	True: Result[r.Increase] := a.Increase;
  end;
  SetLength(Result, r);
  if not Self.Ascending then
    Result.Reverse;
end;

{==============================================================================]
  <Unsharing>
  @action: Returns an array of values from this range that are NOT in the other.
  @note: Useful for finding the "Difference" between two sets of numbers.
[==============================================================================}
function TRange.Unsharing(const other: TRange): TIntegerArray; overload;
var
  i, r, v, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := 0;
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to (s - 1) do
  begin
    v := (Self.start + (i * d));
    if not other.Contains(v) then
      Result[r.Increase] := v;
  end;
  if (r < s) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Without>
  @action: Returns an array of TRange objects representing the portions of 
           this range that do not overlap with the other range.
  @note: This is a geometric "Set Difference" (Self - other). 
          - Returns [Self] if there is no overlap.
          - Returns [] (empty) if other completely covers Self.
          - Returns 1 or 2 TRange segments if there is a partial overlap, 
            preserving the original direction (Ascending/Descending) and 
            order of the segments relative to the original start.
[==============================================================================}
function TRangeHelper.Without(const other: TRange): TRangeArray; overload;
var
  S, O: TRange;
  R: Integer;
  A: Boolean;
begin
  S := Self.Normalize;
  O := other.Normalize;
  if ((O.stop < S.start) or (O.start > S.stop)) then
    Exit([Self]);
  if ((O.start <= S.start) and (O.stop >= S.stop)) then
    Exit([]);
  A := Self.Ascending;
  SetLength(Result, 2);
  R := 0;
  case A of
    True:
    begin
      if (S.start < O.start) then
        Result[R.Increase].Create(IfThen(A, S.start, (O.start - 1)), IfThen(A, (O.start - 1), S.start));
      if (S.stop > O.stop) then
        Result[R.Increase].Create(IfThen(A, (O.stop + 1), S.stop), IfThen(A, S.stop, (O.stop + 1)));
    end;
    False:
    begin
      if (S.stop > O.stop) then
        Result[R.Increase].Create(IfThen(A, (O.stop + 1), S.stop), IfThen(A, S.stop, (O.stop + 1)));
      if (S.start < O.start) then
        Result[R.Increase].Create(IfThen(A, S.start, (O.start - 1)), IfThen(A, (O.start - 1), S.start));
    end;
  end;
  SetLength(Result, R);
end;
{$ENDIF}
