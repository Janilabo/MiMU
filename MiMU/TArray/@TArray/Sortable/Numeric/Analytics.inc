{$IFDEF HELPERS}
function Average: Double; overload;
function Mean: Double; overload;
function Median: Double; overload;
function Middle: Double; overload;
function Occupancy: Double; overload;
function Sum: MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Average>
  @action: Calculates the arithmetic mean of all elements in the array.
  @note: Accumulates via repeated division (Result := Result + Self[i]/l)
         rather than summing then dividing once. Mathematically equivalent
         to Mean, but accrues more floating-point rounding error per
         element for large arrays. Returns 0.0 for an empty array (silent,
         no sentinel) — behavior differs from Median/Middle, which return
         a sentinel on empty input.
[==============================================================================}
function MArrayHelper.Average: Double; overload;
var
  i, l: Integer;
begin
  Result := 0.0;
  l := Self.Length;
  for i := 0 to (l - 1) do
    Result := (Result + (Self[i] / l));
end;

{==============================================================================]
  <Mean>
  @action: Calculates the arithmetic mean of all elements in the array,
           via Self.Sum / Self.Size.
  @note: Same result as Average up to floating-point rounding — Mean
         sums once then divides, so it accumulates less rounding error.
         Prefer this over Average unless Average's incremental behavior
         is specifically needed. Undefined on empty arrays (Size = 0
         divides by zero); no guard.
[==============================================================================}
function MArrayHelper.Mean: Double; overload;
begin
  Result := (Self.Sum / Self.Size);
end;

{==============================================================================]
  <Median>
  @action: Returns the statistical median: the middle value of the array
           once sorted ascending. Odd length → the exact middle element.
           Even length → the average of the two middle elements.
  @note: Operates on a sorted COPY (Self.Copy) — Self is left untouched.
         Sorting is bubble sort, triggered only if any adjacent pair in
         the copy is found out of order; already-sorted input skips the
         sort pass entirely. Returns -2147483648 as an empty-array
         sentinel (magic number, not a documented constant — treat any
         Median result equal to Low(Integer) as ambiguous between "true
         result" and "empty input").
[==============================================================================}
function MArrayHelper.Median: Double; overload;
var
  a: MArray;
  i, j, n, s, d: Integer;
begin
  n := Self.Size;
  if (n = 0) then
    Exit(-2147483648);
  d := (n div 2);
  a := Self.Copy;
  for i := 0 to (n - 2) do
    if (a[i] > a[i + 1]) then
    begin
      for j := 0 to (n - 2) do
        for s := 0 to ((n - j) - 2) do
          if (a[s] > a[s + 1]) then
            Exchange(s, (s + 1));
      Break;
    end;
  if ((n mod 2) = 1) then
    Result := a[d]
  else
    Result := ((a[d - 1] + a[d]) / 2);
end;

{==============================================================================]
  <Middle>
  @action: Returns the value(s) at the center position(s) of the array
           IN ITS CURRENT ORDER — no sorting is performed. Odd length →
           the exact middle element. Even length → the average of the
           two middle elements.
  @note: Unlike Median, this does not sort — "middle" here means
         positional center, not statistical median. On an unsorted
         array the two will generally disagree. Returns -2147483648 as
         an empty-array sentinel, same caveat as Median.
[==============================================================================}
function MArrayHelper.Middle: Double; overload;
var
  l, d: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(-2147483648);
  d := (l div 2);
  if ((l mod 2) = 1) then
    Result := Self[d]
  else
    Result := ((Self[d - 1] + Self[d]) / 2.0);
end;

{==============================================================================]
  <Occupancy>
  @action: Returns the density of distinct values in the array relative
           to its index range: Self.QuickSorted.Distinct / index range
           size, where index range is Construct(0, High(Self)).
  @note: Despite the name and "density" framing, this is Distinct count
         divided by array Length (via a TRange spanning 0..High(Self)),
         NOT a measure of value spread over the values' own numeric
         range. Returns 1.0 for an array with no duplicates, tending
         toward 0.0 as duplicates increase. Returns 0.0 (not a sentinel)
         on an empty array. Self is not mutated (QuickSorted operates on
         a copy).
[==============================================================================}
function MArrayHelper.Occupancy: Double; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0.0);
  Result := (Self.QuickSorted.Distinct / r.Construct(0, High(Self)).Size);
end;

{==============================================================================]
  <Sum>
  @action: Returns the sum of all elements in the array.
  @note: Returns 0 on an empty array. No overflow checking —
         behavior on overflow follows standard type arithmetic rules.
[==============================================================================}
function MArrayHelper.Sum: MType; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;
{$ENDIF}
