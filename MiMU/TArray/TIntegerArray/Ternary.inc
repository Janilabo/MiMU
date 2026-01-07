{$IFDEF HELPERS}
function TernaryMountain: Integer; overload;
function TernaryPeak: Integer; overload;
function TernarySearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function TernaryValley: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <TernaryMountain>
  @action: Identifies an index at or near the global maximum by using a
           ternary-search-inspired unimodal search.
  @note: Assumes the array can be treated as unimodal (first rising,
         eventually falling). The method contracts the search range by
         comparing values at symmetric trisection points. No explicit
         local-maximum validation is performed; the algorithm simply
         converges to the region containing the highest value encountered.
         Returns the index of the final converged position.
[==============================================================================}
function TIntegerArrayHelper.TernaryMountain: Integer; overload;
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  S.Create(0, High(Self));
  while (S.start < S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if (Self[L] < Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  Result := S.start;
end;

{==============================================================================]
  <TernaryPeak>
  @action: Performs a ternary-search-style scan to locate a single local maximum.
  @note: The algorithm attempts to find any valid local maximum with
         sublinear search behavior by iteratively narrowing the search
         interval. Edge maxima are detected up front. If no valid local
         maximum exists in the interior segment, the function returns -1.
         The method guarantees O(log n) probe behavior in the expected case
         but completes with a linear fallback scan when necessary.
[==============================================================================}
function TIntegerArrayHelper.TernaryPeak: Integer; overload;
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  if (Self[0] > Self[1]) then
    Exit(0);
  if (Self[H] > Self[H - 1]) then
    Exit(H);
  S.Create(1, (H - 1));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if ((Self[L] > Self[L - 1]) and (Self[L] > Self[L + 1])) then
      Exit(L);
    if ((Self[R] > Self[R - 1]) and (Self[R] > Self[R + 1])) then
      Exit(R);
    if (Self[L] < Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  for Result := S.start to S.stop do
    if ((Self[Result] > Self[Result - 1]) and (Self[Result] > Self[Result + 1])) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <TernarySearch>
  @action: Performs a ternary search over the array to locate the specified value.
           The routine splits the current search interval into three segments,
           compares the target value against the two internal partition points,
           and repeatedly narrows the interval until the value is found or the range is exhausted.

  @note: Requires the array to be pre-sorted in either ascending or descending order depending on oAscending.
         Returns the index of the matching element when found; otherwise returns -1.
         This implementation executes in logarithmic time relative to array length,
         but is generally not faster than binary search in practical scenarios due to the additional comparisons.
[==============================================================================}
function TIntegerArrayHelper.TernarySearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  L, R: Integer;
  S: TRange;
begin
  Result := -1;
  S.Create(0, High(Self));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if (Self[L] = value) then
      Exit(L);
    if (Self[R] = value) then
      Exit(R);
    if ((oAscending and (value < Self[L])) or ((not oAscending) and (value > Self[L]))) then
      S.stop := (L - 1)
    else if ((oAscending and (value > Self[R])) or ((not oAscending) and (value < Self[R]))) then
      S.start := (R + 1)
    else
      S.Create((L + 1), (R - 1));
  end;
end;

{==============================================================================]
  <TernaryValley>
  @action: Performs a ternary-search-style scan to locate a single local minimum.
  @note: The algorithm mirrors the logic used in TernaryPeak but inverts
         all comparisons to detect a valley rather than a peak. Edge
         minima are tested first. If no valid local minimum exists in the
         narrowed search interval, the function returns -1. Expected
         complexity is O(log n) with a linear fallback validation.
[==============================================================================}
function TIntegerArrayHelper.TernaryValley: Integer; overload;
var
  H, L, R: Integer;
  S: TRange;
begin
  H := High(Self);
  if (H < 1) then
    Exit(H);
  if (Self[0] < Self[1]) then
    Exit(0);
  if (Self[H] < Self[H - 1]) then
    Exit(H);
  S.Create(1, (H - 1));
  while (S.start <= S.stop) do
  begin
    L := (S.start + ((S.stop - S.start) div 3));
    R := (S.stop - ((S.stop - S.start) div 3));
    if ((Self[L] < Self[L - 1]) and (Self[L] < Self[L + 1])) then
      Exit(L);
    if ((Self[R] < Self[R - 1]) and (Self[R] < Self[R + 1])) then
      Exit(R);
    if (Self[L] > Self[R]) then
      S.start := (L + 1)
    else
      S.stop := (R - 1);
  end;
  for Result := S.start to S.stop do
    if ((Self[Result] < Self[Result - 1]) and (Self[Result] < Self[Result + 1])) then
      Exit;
  Result := -1;
end;
{$ENDIF}