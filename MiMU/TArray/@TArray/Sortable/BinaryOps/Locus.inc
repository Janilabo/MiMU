{$IFDEF HELPERS}
function BinaryBand(const target: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryExtended(const target: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryExtent(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryExtenta(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryExtentFor(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryExtentOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryLocate(const x: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryNest(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryPocket(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryRange(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryWindow(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryZone(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryZoneOf(const target: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryPincer(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryRelay(const target: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySector(const target: MType; const oAscending: Boolean = True): TRange; overload;

function BinaryBracket(const aMin, aMax: MType; const oAscending: Boolean = True): TRange; overload;

function Bisected(const item: MType; const oAscending: Boolean = True): TRange; overload;
function Bisection(const item: MType; const oAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBand>
  @action: Uses a three-phase hybrid strategy—combining binary search with galloping (exponential) expansion
           to isolate the contiguous index range (band) of elements matching target in a sorted array.
  @note: Phase 1 locates an initial matching element via standard binary search in O(log N) time.
         Phases 2 and 3 perform exponential stepping (doubling stride s) outward from index m to rapidly bound the duplicate cluster,
		 followed by a binary search within the bounded window to determine the precise lower and upper indices.
		 Optimized for small-to-medium clusters of identical values, returning a TRange of inclusive indices, or (-1, -1) if target is missing.
[==============================================================================}
function MArrayHelper.BinaryBand(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  l, r, m, c, s, a, z, x, h: Integer;
begin
  h := High(Self);
  l := 0;
  r := h;
  while (l <= r) do
  begin
    m := (l + ((r - l) div 2));
    if (Self[m] = target) then
      Break;
    if (oAscending = (Self[m] < target)) then
      l := (m + 1)
    else
      r := (m - 1);
  end;
  if (l > r) then
    Exit(TRange.Construct(-1, -1));
  a := m;
  s := 1;
  while (((a - s) >= 0) and (Self[a - s] = target)) do
  begin
    a := (a - s);
    s := (s * 2);
  end;
  x := (a - s);
  if (x < -1) then
    x := -1;
  while ((a - x) > 1) do
  begin
    c := (x + ((a - x) div 2));
    if (Self[c] = target) then
      a := c
    else
      x := c;
  end;
  Result.start := a;
  z := m;
  s := 1;
  while (((z + s) <= h) and (Self[z + s] = target)) do
  begin
    z := (z + s);
    s := (s * 2);
  end;
  x := (z + s);
  if (x > (h + 1)) then
    x := (h + 1);
  while ((x - z) > 1) do
  begin
    c := (z + ((x - z) div 2));
    if (Self[c] = target) then
      z := c
    else
      x := c;
  end;
  Result.stop := z;
end;

{==============================================================================]
  <BinaryExtended>
  @action: Finds the contiguous index range of elements matching target in a sorted generic array using a decoupled dual-pass binary search (STL equal_range style).
  @note: Phase 1 performs a lower-bound binary search to locate the first matching element, exiting in O(log N) time if absent.
         Phase 2 reuses the lower-bound index as its left boundary to run an upper-bound binary search.
		 Operates in O(log N) total time complexity across MType generics and returns TRange(start, stop), or (-1, -1) if target is missing.
[==============================================================================}
function MArrayHelper.BinaryExtended(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  l, r, m, h: Integer;
begin
  h := High(Self);
  l := 0;
  r := (h + 1);
  while (l < r) do
  begin
    m := (l + ((r - l) div 2));
    if ((oAscending and (Self[m] < target)) or ((not oAscending) and (Self[m] > target))) then
      l := (m + 1)
    else
      r := m;
  end;
  if ((l > h) or (Self[l] <> target)) then
    Exit(TRange.Construct(-1, -1));
  Result.start := l;
  r := (h + 1);
  while (l < r) do
  begin
    m := (l + ((r - l) div 2));
    if ((oAscending and (Self[m] <= target)) or ((not oAscending) and (Self[m] >= target))) then
      l := (m + 1)
    else
      r := m;
  end;
  Result.stop := (l - 1);
end;

{==============================================================================]
  <BinaryExtent>
  @action: Performs a dual binary search on a sorted array to locate the start and end indices of all contiguous elements equal to the specified item.
  @note: Requires the array to be pre-sorted according to the oAscending flag.
         Executes in O(log N) time and returns a TRange containing the inclusive index bounds (Start, Stop), or (-1, -1) if the item is not found.
[==============================================================================}
function MArrayHelper.BinaryExtent(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  L, R: TRange;
  M: Integer;
begin
  L := TRange.Construct(0, Self.Length);
  R := TRange.Construct(0, Self.Length);
  while ((L.start < L.stop) or (R.start < R.stop)) do
  begin
    if (L.start < L.stop) then
    begin
      m := (L.start + (L.stop - L.start) shr 1);
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        L.start := (m + 1)
      else
        L.stop := m;
    end;
    if (R.start < R.stop) then
    begin
      m := (R.start + (R.stop - R.start) shr 1);
      if ((oAscending and (Self[m] > item)) or ((not oAscending) and (Self[m] < item))) then
        R.stop := m
      else
        R.start := (m + 1);
    end;
  end;
  if (L.start < R.start) then
    Result.Create(L.start, (R.start - 1))
  else
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryExtenta>
  @action: Performs a dual binary search to find the continuous index range [start, stop] of all elements matching `item` in a sorted array.
  @note: Operates in O(log N) time. Once a match is found, splits into concurrent lower-bound and upper-bound searches to locate the exact extent in a single pass.
[==============================================================================}
function MArrayHelper.BinaryExtenta(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  L, R: TRange;
  M, C: Integer;
begin
  L := TRange.Construct(0, Self.Length);
  R := L;
  while ((L.start < L.stop) or (R.start < R.stop)) do
  case ((L.start = R.start) and (L.stop = R.stop)) of
    True:
    begin
      M := (L.start + ((L.stop - L.start) shr 1));
      C := Self[M].Bout(item, oAscending);
      if (C < 0) then
      begin
        L.start := (M + 1);
        R.start := L.start;
      end else if (C > 0) then
      begin
        L.stop := M;
        R.stop := L.stop;
      end else
      begin
        L.stop := M;
        R.start := (M + 1);
      end;
    end;
    False:
    begin
      if (L.start < L.stop) then
      begin
        M := (L.start + ((L.stop - L.start) shr 1));
        if (Self[M].Bout(item, oAscending) < 0) then
          L.start := (M + 1)
        else
          L.stop := M;
      end;
      if (R.start < R.stop) then
      begin
        M := (R.start + ((R.stop - R.start) shr 1));
        if (Self[M].Bout(item, oAscending) <= 0) then
          R.start := (M + 1)
        else
          R.stop := M;
      end;
    end;
  end;
  if (L.start < R.start) then
    Result.Create(L.start, (R.start - 1))
  else
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryExtentFor>
  @action: Performs a state-driven single-loop binary search to determine the lower and upper index bounds of all contiguous matching items in a sorted array.
  @note: Requires the array to be pre-sorted according to oAscending.
         Uses a boolean flag (S) inside a case statement to transition from a single search window to non-overlapping dual searches upon finding the first match.
         Operates in O(log N) time and returns a TRange of inclusive indices, or (-1, -1) if the item does not exist.
[==============================================================================}
function MArrayHelper.BinaryExtentFor(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  L, R: TRange;
  M, A, B: Integer;
  S: Boolean;
begin
  L := TRange.Construct(0, Self.Length);
  R := L;
  S := False;
  while ((L.start < L.stop) or (R.start < R.stop)) do
  case S of
    False:
    begin
      M := (L.start + ((L.stop - L.start) shr 1));
      if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      begin
        L.start := (M + 1);
        R.start := L.start;
      end else if ((oAscending and (Self[M] > item)) or ((not oAscending) and (Self[M] < item))) then
      begin
        L.stop := M;
        R.stop := L.stop;
      end else
      begin
        S := True;
        L.stop := M;
        R.start := (M + 1);
      end;
    end;
    True:
    begin
      if (L.start < L.stop) then
      begin
        A := (L.start + ((L.stop - L.start) shr 1));
        if ((oAscending and (Self[A] < item)) or ((not oAscending) and (Self[A] > item))) then
          L.start := (A + 1)
        else
          L.stop := A;
      end;
      if (R.start < R.stop) then
      begin
        B := (R.start + ((R.stop - R.start) shr 1));
        if ((oAscending and (Self[B] <= item)) or ((not oAscending) and (Self[B] >= item))) then
          R.start := (B + 1)
        else
          R.stop := B;
      end;
    end;
  end;
  if (L.start < R.start) then
    Result.Create(L.start, (R.start - 1))
  else
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryExtentOf>
  @action: Performs a single-loop binary search on a sorted array to identify the index range (extent) occupied by all contiguous elements equal to the specified item.
  @note: Requires the array to be pre-sorted according to oAscending. Starts as a single binary search window until a match is encountered,
         after which it splits into non-overlapping left and right bounds searches.
         Executes in O(log N) time and returns a TRange of inclusive indices, or (-1, -1) if the item is not found.
[==============================================================================}
function MArrayHelper.BinaryExtentOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  L, R: TRange;
  A, D: Integer;
  B, S: Boolean;
begin
  L := TRange.Construct(0, Self.Length);
  R := TRange.Construct(0, Self.Length);
  while ((L.start < L.stop) or (R.start < R.stop)) do
  begin
    if ((L.start = R.start) and (L.stop = R.stop)) then
    begin
      A := (L.start + ((L.stop - L.start) shr 1));
      S := ((oAscending and (Self[A] < item)) or ((not oAscending) and (Self[A] > item)));
      B := ((oAscending and (Self[A] > item)) or ((not oAscending) and (Self[A] < item)));
      if S then
      begin
        L.start := (A + 1);
        R.start := L.start;
      end else if B then
      begin
        L.stop := A;
        R.stop := L.stop;
      end else
      begin
        L.stop := A;
        R.start := (A + 1);
      end;
    end else
    begin
      if (L.start < L.stop) then
      begin
        A := (L.start + ((L.stop - L.start) shr 1));
        if ((oAscending and (Self[A] < item)) or ((not oAscending) and (Self[A] > item))) then
          L.start := (A + 1)
        else
          L.stop := A;
      end;
      if (R.start < R.stop) then
      begin
        D := (R.start + ((R.stop - R.start) shr 1));
        if ((oAscending and (Self[D] <= item)) or ((not oAscending) and (Self[D] >= item))) then
          R.start := (D + 1)
        else
          R.stop := D;
      end;
    end;
  end;
  if (L.start < R.start) then
    Result.Create(L.start, (R.start - 1))
  else
    Result.Create(-1, -1);
end;

{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryLocate(const x: MType; const aAscending: Boolean = True): TRange; overload;
begin
  Result.start := Self.BinaryLefty(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryRighty(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryNest>
  @action: Return the index range (start..stop) of all elements whose
           value equals item. Uses binary search to find the leftmost
           and rightmost matching indexes.
  @note: Returns (-1,-1) if item is not present. Works for arrays sorted
         ascending or descending as controlled by aAscending.
[==============================================================================}
function MArrayHelper.BinaryNest(const item: MType; const aAscending: Boolean = True): TRange; overload;
begin
  Result.Create(Self.BinaryLefty(item, aAscending), Self.BinaryRighty(item, aAscending));
end;

{==============================================================================]
  <BinaryRange>
  @action: Performs a binary search to find the contiguous index range of all
           points equal to the specified item.
  @note:   Assumes the array is sorted according to TPoint_Compare.
           Returns (-1,-1) if no matching point is found.
[==============================================================================}
function MArrayHelper.BinaryPocket(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  M: Integer;
  R: TRange;
begin
  Result.Create(-1);
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compete(item, oAscending) of
      0:
      begin
        Result.start := M;
        R.stop := (M - 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compete(item, oAscending) of
      0:
      begin
        Result.stop := M;
        R.start := (M + 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryRange>
  @action: Returns Binary Search left and right index as TRange based on item value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
        - Locates any occurrence via binary search, then expands linearly in
          both directions to find the full equal-value window.
[==============================================================================}
function MArrayHelper.BinaryRange(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M, H: Integer;
  R: TRange;
begin
  Result := TRange.Construct(-1, -1);
  H := High(Self);
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result.start := M;
      Result.stop := M;
      while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
        Dec(Result.start);
      while ((Result.stop < H) and (Self[Result.stop + 1] = item)) do
        Inc(Result.stop);
      Exit;
    end else if ((Self[M] < item) = aAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific item in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the item is not found.
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinaryRangeOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) of
      False:
      begin
        r.stop := (m - 1);
        if (Self[m] = item) then
          Result.start := m;
      end;
      True: r.start := (m + 1);
    end;
  end;
  if (Result.start = -1) then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of a specific item in a sorted array.
  @note:
    - This function performs a binary search to find the first and last occurrences
      of the given item in the array.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of the item.
    - If the item is not found, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinarySpanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of a specific item in a sorted array.
  @note:
    - Performs a binary search to locate any occurrence of the item.
    - Once found, expands linearly left and right to determine the full span.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if the item is not found.
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinarySpanOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] = item)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryWindow>
  @action: Performs a binary search on a sorted array and returns the closed index
           interval [start, stop] containing all occurrences of <item>.
           The function determines:
            - The first index at which Self[i] = item
            - The last  index at which Self[i] = item
           Both bounds are located using independent binary searches.
  @note:
    - Self must be sorted according to <aAscending>.
    - Returns (-1, -1) if <item> is not present.
    - The resulting range contains only indices whose value equals <item>.
    - Time complexity: O(log n), where n = Length(Self).
    - No linear expansion is performed.
[==============================================================================}
function MArrayHelper.BinaryWindow(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M, S: Integer;
  R: TRange;
begin
  Result := TRange.Construct(-1, -1);
  S := Self.Length;
  if (S = 0) then
    Exit;
  R.Create(0, (S - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] >= item) = aAscending) then
    begin
      if (Self[M] = item) then
        Result.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (Result.start = -1) then
    Exit;
  Result.stop := Result.start;
  R.Create(0, (S - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] <= item) = aAscending) then
    begin
      if (Self[M] = item) then
        Result.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryZone>
  @action: Returns Binary Search left and right index as TRange based on item value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
        - Runs two independent boundary searches (leftmost/rightmost equal-item
          index) without a preliminary existence probe.
[==============================================================================}
function MArrayHelper.BinaryZone(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M: Integer;
  R: TRange;
begin
  Result.start := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result.start := M;
        R.stop := (M - 1);
      end;
      False:
      if ((Self[M] < item) = aAscending) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (Result.start = -1) then
  begin
    Result.stop := -1;
    Exit;
  end;
  Result.stop := Result.start;
  R.Create(Result.start, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result.stop := M;
        R.start := (M + 1);
      end;
      False:
      if ((Self[M] < item) = aAscending) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryZoneOf>
  @action: Performs a three-phase binary search (pivot-and-split) on a sorted array to locate the inclusive index bounds of all contiguous elements matching target.
  @note: Phase 1 locates an initial matching element in O(log N) time;
         if found, Phases 2 and 3 perform independent, non-overlapping binary searches on [0..m] and [m..High] to isolate the exact lower and upper boundaries.
         Operates in O(log N) total time complexity and returns a TRange containing the index bounds, or (-1, -1) if target is missing.
[==============================================================================}
function MArrayHelper.BinaryZoneOf(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  l, r, m, c, h: Integer;
begin
  h := High(Self);
  l := 0;
  r := h;
  while (l <= r) do
  begin
    m := (l + ((r - l) div 2));
    if (Self[m] = target) then
      Break;
    if (oAscending = (Self[m] < target)) then
      l := (m + 1)
    else
      r := (m - 1);
  end;
  if (l > r) then
    Exit(TRange.Construct(-1, -1));
  l := 0;
  r := m;
  while (l < r) do
  begin
    c := (l + ((r - l) div 2));
    if (Self[c] = target) then
      r := c
    else
      l := (c + 1);
  end;
  Result.start := l;
  l := m;
  r := h;
  while (l < r) do
  begin
    c := (l + ((r - l + 1) div 2));
    if (Self[c] = target) then
      l := c
    else
      r := (c - 1);
  end;
  Result.stop := l;
end;

{==============================================================================]
  <BinaryPincer>
  @action: Finds the index range (first and last occurrence) of `item` in a sorted array by running two interleaved binary searches in a single loop pass.
  @note: Dual-tracks left (`L`) and right (`R`) bounds simultaneously to find both `Result.start` and `Result.stop` in $O(\log N)$ time.
         Returns `(start: -1, stop: -1)` if `item` is not present or if the array is empty. Supports both ascending and descending order via `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryPincer(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  L, R: TRange;
  h, A, B: Integer;
begin
  Result.start := -1;
  Result.stop := -1;
  h := High(Self);
  if (h = -1) then
    Exit;
  L.Create(0, h);
  R.Create(0, h);
  while ((L.start <= L.stop) or (R.start <= r.stop)) do
  begin
    if (L.start <= L.stop) then
    begin
      A := (L.start + ((L.stop - L.start) div 2));
      case oAscending of
        True:
        if (Self[A] < item) then
          L.start := (A + 1)
        else
        begin
          if (Self[A] = item) then
            Result.start := A;
          L.stop := (A - 1);
        end;
        False:
        if (Self[A] > item) then
          L.start := (A + 1)
        else
        begin
          if (Self[A] = item) then
            Result.start := A;
          L.stop := (A - 1);
        end;
      end;
    end;
    if (R.start <= R.stop) then
    begin
      B := (R.start + ((R.stop - R.start) div 2));
      case oAscending of
        True:
        if (Self[B] > item) then
          R.stop := (B - 1)
        else
        begin
          if (Self[B] = item) then
            Result.stop := B;
          R.start := (B + 1);
        end;
        False:
        if (Self[B] < item) then
          R.stop := (B - 1)
        else
        begin
          if (Self[B] = item) then
            Result.stop := B;
          R.start := (B + 1);
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryRelay>
  @action: Finds the index range (first and last occurrence) of `target` in a sorted array using two sequential binary searches.
  @note: Executes in deterministic O(log N) time. Returns `(start: -1, stop: -1)` if `target` is not found or if the array is empty.
         Supports both ascending and descending order via `oAscending`.
[==============================================================================}
function MArrayHelper.BinaryRelay(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  h, l, r, m: Integer;
  a: TRange;
begin
  h := High(Self);
  Result.start := -1;
  Result.stop := -1;
  if (h = -1) then
    Exit;
  l := 0;
  r := h;
  while (l <= r) do
  begin
    m := (l + ((r - l) div 2));
    if (Self[m] = target) then
    begin
      Result.start := m;
      r := (m - 1);
    end else if ((oAscending and (Self[m] < target)) or ((not oAscending) and (Self[m] > target))) then
      l := (m + 1)
    else
      r := (m - 1);
  end;
  if (Result.start = -1) then
    Exit;
  l := Result.start;
  r := h;
  while (l <= r) do
  begin
    m := (l + ((r - l) div 2));
    if (Self[m] = target) then
    begin
      Result.stop := m;
      l := (m + 1);
    end else if ((oAscending and (Self[m] < target)) or ((not oAscending) and (Self[m] > target))) then
      l := (m + 1)
    else
      r := (m - 1);
  end;
end;

{==============================================================================]
  <BinarySector>
  @action: Locates the contiguous index sector of elements matching target in a sorted array by combining unbounded forward galloping with binary refinement.
  @note: Bypasses initial midpoint binary search by galloping exponentially from index 0 to bound the lower boundary window before executing binary refinement.
         Once the lower bound is established, it gallops forward from that index to bound and refine the upper boundary.
		 Operates in O(log K) time where K is the target's position/cluster offset, returning a TRange of inclusive indices, or (-1, -1) if target is missing.
[==============================================================================}
function MArrayHelper.BinarySector(const target: MType; const oAscending: Boolean = True): TRange; overload;
var
  s, l, h, j: Integer;
begin
  s := High(Self);
  if (s < 0) then
    Exit(TRange.Construct(-1, -1));
  l := 0;
  j := 1;
  while ((l <= s) and ((oAscending and (Self[l] < target)) or ((not oAscending) and (Self[l] > target)))) do
  begin
    l := (l + j);
    j := (j * 2);
  end;
  h := l;
  if (h > s) then
    h := s;
  l := (l - (j div 2));
  if (l < 0) then
    l := 0;
  while (l < h) do
  begin
    j := (l + ((h - l) div 2));
    if ((oAscending and (Self[j] < target)) or ((not oAscending) and (Self[j] > target))) then
      l := (j + 1)
    else
      h := j;
  end;
  if ((l > s) or (Self[l] <> target)) then
    Exit(TRange.Construct(-1, -1));
  Result.start := l;
  h := l;
  j := 1;
  while ((h <= s) and (Self[h] = target)) do
  begin
    h := (h + j);
    j := (j * 2);
  end;
  l := (h - (j div 2));
  if (h > (s + 1)) then
    h := (s + 1);
  while (l < h) do
  begin
    j := (l + ((h - l) div 2));
    if (Self[j] = target) then
      l := (j + 1)
    else
      h := j;
  end;
  Result.stop := (l - 1);
end;

{==============================================================================]
  <BinaryBracket>
  @action: Uses binary search to locate the inclusive index bounds [`start`, `stop`] of all elements falling within the range [`aMin`, `aMax`] in a sorted array, returning them as a `TRange`.
  @note: Executes in O(log N) time using `BinaryBoundMin` and `BinaryBoundMax`. Handles both ascending and descending sorted arrays via `oAscending`,
         invalidating the range (`Result.start := -1; Result.stop := -1`) if either boundary is not found or out of bounds.
[==============================================================================}
function MArrayHelper.BinaryBracket(const aMin, aMax: MType; const oAscending: Boolean = True): TRange; overload;
begin
  case oAscending of
    True:
    begin
      Result.start := Self.BinaryBoundMin(aMin, oAscending);
      if (Result.start = -1) then
        Result.stop := -1
      else
        Result.stop := Self.BinaryBoundMax(aMax, oAscending);
      if (Result.stop = -1) then
        Result.start := -1;
    end;
    False:
    begin
      Result.start := Self.BinaryBoundMin(aMax, oAscending);
      if (Result.start = -1) then
        Result.stop := -1
      else
        Result.stop := Self.BinaryBoundMax(aMin, oAscending);
      if (Result.stop = -1) then
        Result.start := -1;
    end;
  end;
end;

{==============================================================================]
  <Bisected>
  @action: Returns the full insertion range of `item` in a sorted array as a
           TRange, computing both edges in one interleaved pass rather than
           two sequential searches. start is the leftmost valid insertion
           point (bisect_left semantics: Contest < 0 moves right); stop is
           the rightmost valid insertion point (bisect_right semantics:
           Contest <= 0 moves right). If `item` is absent, start = stop = the
           single insertion point that keeps the array sorted; if present,
           the range spans every existing occurrence.
  @note: - Requires the array to be sorted according to `oAscending`.
         - Never returns a -1 sentinel in either field — both bounds are
           always valid indices in [0, Length].
         - The two searches (a/b for the left edge, x/y for the right edge)
           run interleaved in a single while loop rather than sequentially;
           each converges independently and the loop continues until both
           have finished (a < b) or (x < y)). Total comparisons are the same
           as calling BisectLeft then BisectRight separately — this changes
           the order of operations, not the amount of work.
         - Result.Size (stop - start) gives the occurrence count directly.
[==============================================================================}
function MArrayHelper.Bisected(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  a, b, c, r, x, y, z: Integer;
begin
  a := 0;
  b := Self.Length;
  x := a;
  y := b;
  while ((a < b) or (x < y)) do
  begin
    if (a < b) then
    begin
      c := (a + (b - a) div 2);
      r := Self[c].Contest(item, oAscending);
      if (r < 0) then
        a := (c + 1)
      else
        b := c;
    end;
    if (x < y) then
    begin
      z := (x + (y - x) div 2);
      r := Self[z].Contest(item, oAscending);
      if (r <= 0) then
        x := (z + 1)
      else
        y := z;
    end;
  end;
  Result := TRange.Construct(a, x);
end;

{==============================================================================]
  <Bisection>
  @action: Returns the full insertion range of `item` in a sorted array as a
           TRange — start is BisectLeft (first valid insertion point), stop
           is BisectRight (last valid insertion point). If `item` is absent,
           start = stop = the single insertion point that keeps the array
           sorted. If present, the range spans every existing occurrence.
  @note: - Requires the array to be sorted according to `oAscending`.
         - Never returns a -1 sentinel in either field — both bounds are
           always valid indices in [0, Length], consistent with
           BisectLeft/BisectRight's insertion-point semantics.
         - r.Size (stop - start) gives the occurrence count directly, making
           this a single-call replacement for pairing BisectLeft + BisectRight
           at call sites that need both.
         - Distinct in kind from Bisect (alias for BisectRight, one index) —
           Bisection is the noun/aggregate form, returning the whole range
           rather than a single edge.
[==============================================================================}
function MArrayHelper.Bisection(const item: MType; const oAscending: Boolean = True): TRange; overload;
begin
  Result := TRange.Construct(Self.BisectLeft(item, oAscending), Self.BisectRight(item, oAscending));
end;
{$ENDIF}
