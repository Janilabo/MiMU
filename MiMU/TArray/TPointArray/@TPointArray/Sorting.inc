{$IFDEF HELPERS}
function QuickSortByX(const aAscending: Boolean = True): Integer;
function QuickSortByXY(const aAscending: Boolean = True): Integer;
function QuickSortByY(const aAscending: Boolean = True): Integer;
function QuickSortByYX(const aAscending: Boolean = True): Integer;
function SortByColumn(const aAscending: Boolean = True): Integer; overload;
function SortByIndex(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
function SortByIndex(const aAscending: Boolean = True): Integer; overload;
function SortByRow(const aAscending: Boolean = True): Integer; overload;
function SortByScanline(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
function SortByScanline(const aAscending: Boolean = True): Integer; overload;
function SortBySpiral(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
function SortSpiraling(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
function SortSpiralix(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
function SortSpirally(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
function SortSpiralwise(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
function SortedByCoords(const oAscending: Boolean = True): TPointArray; overload;
function SortedByIndex(const aAscending: Boolean = True): TPointArray; overload;
function SortedByLocale(const oAscending: Boolean = True): TPointArray; overload;
function SortedByLocation(const oAscending: Boolean = True): TPointArray; overload;
function SortedByPosition(const oAscending: Boolean = True): TPointArray; overload;
function SortedBySpiral(const origin: TPoint; const oAscending: Boolean = True): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <QuickSortByX>
  @action: Sorts all points in ascending order based on their X coordinate.
  @note: Uses an in-place recursive QuickSort. Does not guarantee stability
         for equal X values. Complexity is O(n log n) on average.
[==============================================================================}
function TPointArrayHelper.QuickSortByX(const aAscending: Boolean = True): Integer;
  procedure QSX(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].X < p.X)) or ((not A) and (arr[i].X > p.X))) do
        Inc(i);
      while ((A and (arr[j].X > p.X)) or ((not A) and (arr[j].X < p.X))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSX(arr, L, j, A);
    if (i < R) then
      QSX(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSX(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByXY>
  @action: Sorts all points by X coordinate first, and then by Y coordinate
           for points sharing the same X value.
  @note: Implements a dual-key QuickSort for consistent ordering by (X,Y).
         Average complexity O(n log n). Not stable for equal (X,Y) pairs.
[==============================================================================}
function TPointArrayHelper.QuickSortByXY(const aAscending: Boolean = True): Integer;
  procedure QSXY(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].X < p.X) or ((arr[i].X = p.X) and (arr[i].Y < p.Y)))) or ((not A) and ((arr[i].X > p.X) or ((arr[i].X = p.X) and (arr[i].Y > p.Y))))) do
        Inc(i);
      while ((A and ((arr[j].X > p.X) or ((arr[j].X = p.X) and (arr[j].Y > p.Y))) or ((not A) and ((arr[j].X < p.X) or ((arr[j].X = p.X) and (arr[j].Y < p.Y)))))) do
        Dec(J);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSXY(arr, L, j, A);
    if (i < R) then
      QSXY(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSXY(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByY>
  @action: Sorts all points in ascending order based on their Y coordinate.
  @note: In-place recursive QuickSort implementation. Equal Y values are not
         guaranteed to preserve original order (unstable sort).
[==============================================================================}
function TPointArrayHelper.QuickSortByY(const aAscending: Boolean = True): Integer;
  procedure QSY(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].Y < p.Y)) or ((not A) and (arr[i].Y > p.Y))) do
        Inc(i);
      while ((A and (arr[j].Y > p.Y)) or ((not A) and (arr[j].Y < p.Y))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSY(arr, L, j, A);
    if (i < R) then
      QSY(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSY(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByYX>
  @action: Sorts all points by Y coordinate first, and then by X coordinate
           for points sharing the same Y value.
  @note: Commonly used for spatial clustering and grid-based sorting.
         In-place QuickSort with O(n log n) average complexity.
[==============================================================================}
function TPointArrayHelper.QuickSortByYX(const aAscending: Boolean = True): Integer;
  procedure QSYX(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].Y < p.Y) or ((arr[i].Y = p.Y) and (arr[i].X < p.X)))) or ((not A) and ((arr[i].Y > p.Y) or ((arr[i].Y = p.Y) and (arr[i].X > p.X))))) do
        Inc(i);
      while ((A and ((arr[j].Y > p.Y) or ((arr[j].Y = p.Y) and (arr[j].X > p.X)))) or ((not A) and ((arr[j].Y < p.Y) or ((arr[j].Y = p.Y) and (arr[j].X < p.X))))) do
        Dec(J);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSYX(arr, L, j, A);
    if (i < R) then
      QSYX(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSYX(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <SortByColumn>
  @action: Sorts array Column-by-Column.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByColumn(const aAscending: Boolean = True): Integer; overload;
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Self.Size;
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
	case aAscending of
	  True:
      for x := 0 to (b.X2 - b.X1) do
        for y := 0 to (b.Y2 - b.Y1) do
          if (c[x][y] > 0) then
          begin
            for i := 0 to (c[x][y] - 1) do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
	  False:
      for x := (b.X2 - b.X1) downto 0 do
        for y := (b.Y2 - b.Y1) downto 0 do
          if (c[x][y] > 0) then
          begin
            for i := (c[x][y] - 1) downto 0 do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
    end;		
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <SortByIndex>
  @action: Sorts the point array by a calculated linear index within the given bounding box.
  @note: Each point is mapped from (X,Y) to a single 1D index value and sorted
         using TArray_QuickSortWeighted. Returns the number of points in the array.
[==============================================================================}
function TPointArrayHelper.SortByIndex(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  w: TIntegerArray;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  SetLength(w, Result);
  for i := 0 to (Result - 1) do
    w[i] := (((Self[i].Y - aBounds.Y1) * ((aBounds.X2 - aBounds.X1) + 1)) + (Self[i].X - aBounds.X1));
  Self.QuickSortWeighted(w, aAscending);
end;

{==============================================================================]
  <SortByIndex>
  @action: Sorts the point array by index using a default large bounding box.
  @note: Calls SortByIndex(Box(-23169, -23169, 23169, 23169), aAscending).
         Useful when explicit bounds are not needed.
[==============================================================================}
function TPointArrayHelper.SortByIndex(const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.SortByIndex(TBox.Construct(-23169, -23169, 23169, 23169), aAscending);
end;

{==============================================================================]
  <SortByRow>
  @action: Sorts array Row-by-Row.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByRow(const aAscending: Boolean = True): Integer; overload;
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Self.Size;
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
	case aAscending of
	  True:
      for y := 0 to (b.Y2 - b.Y1) do
        for x := 0 to (b.X2 - b.X1) do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := 0 to (c[x][y] - 1) do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	  False:
      for y := (b.Y2 - b.Y1) downto 0 do
        for x := (b.X2 - b.X1) downto 0 do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := (c[x][y] - 1) downto 0 do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	end;
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <SortByScanline>
  @action: Reorders all points in the array into strict row-to-column (scanline)
           sequence within the specified bounding box. The sort scans from the
           top-left corner to the bottom-right (ascending = True), or the reverse
           direction if ascending = False. The operation is performed by iterating
           through every coordinate in raster order and moving matching points into
           the output array.
 @note: - This is a *deterministic, stable* traversal-based ordering, not a
          comparison sort.
        - Complexity is O(W × H × N) in the worst case, so it is best used when
          the bounding box is small or the coordinate grid is discrete and bounded.
        - Points that fall outside the bounding box are discarded.
        - The method modifies the array in place and returns the number of points
          remaining after sorting.
[==============================================================================}
function TPointArrayHelper.SortByScanline(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
var
  s: TPointArray;
  x, y, i, l, h: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  l := 0;
  h := (Result - 1);
  case aAscending of
    True:
    for y := aBounds.Y1 to aBounds.Y2 do
      for x := aBounds.X1 to aBounds.X2 do
      begin
        i := 0;
	    while (i <= h) do
          if ((s[i].X = x) and (s[i].Y = y)) then
          begin
            Self[l.Increase] := s[i];
            Swap(s[i], s[h.Decrease]);
            if (h = -1) then
              Exit;
          end else
	        Inc(i);
      end;
    False:
    for y := aBounds.Y2 downto aBounds.Y1 do
      for x := aBounds.X2 downto aBounds.X1 do
      begin
        i := 0;
	    while (i <= h) do
          if ((s[i].X = x) and (s[i].Y = y)) then
          begin
            Self[l.Increase] := s[i];
            Swap(s[i], s[h.Decrease]);
            if (h = -1) then
              Exit;
          end else
	        Inc(i);
       end;
  end;
  SetLength(Self, l);
end;

{==============================================================================]
  <SortByScanline>
  @action: Convenience overload that calls SortByScanline using the array’s own
           bounding box (Self.Bounds) as the region to scan.
  @note: Equivalent to SortByScanline(Self.Bounds, aAscending).
         Produces identical ordering but automatically derives the limits from the
         data set.
[==============================================================================}
function TPointArrayHelper.SortByScanline(const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.SortByScanline(Self.Bounds, aAscending);
end;

{==============================================================================]
  <SortBySpiral>
  @action: Sorts the points in the array based on their spatial spiral distance 
           relative to a given origin point.
  @note: Uses TIndexed<TPoint> to temporarily pair each point with its calculated 
         Unspiral index before sorting in-place using QuickSort. Returns the 
         total number of elements in the array.
[==============================================================================}
function TPointArrayHelper.SortBySpiral(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
var
  s, i: Integer;
  k: array of specialize TIndexed<TPoint>;
  procedure O(var n, m: Integer);
  begin
    k[s] := k[n];
    k[n] := k[m];
    k[m] := k[s];
    Inc(n);
    Dec(m);
  end;
  procedure Q(L, R: Integer);
  var
    a, b: Integer;
    P: UInt32;
  begin
    a := L;
    b := R;
    P := k[(L + R) div 2].index;
    case oAscending of
      True:
      repeat
        while (k[a].index < P) do
          Inc(a);
        while (k[b].index > P) do
          Dec(b);
        if (a <= b) then
          O(a, b);
      until (a > b);
      False:
      repeat
        while (k[a].index > P) do
          Inc(a);
        while (k[b].index < P) do
          Dec(b);
        if (a <= b) then
          O(a, b);
      until (a > b);
    end;
    if (L < b) then
      Q(L, b);
    if (a < R) then
      Q(a, R);
  end;
begin
  s := Self.Length;
  Result := s;
  if (s <= 1) then
    Exit;
  SetLength(k, (s + s));
  for i := 0 to (s - 1) do
  begin
    k[i].item := Self[i];
    k[i].index := origin.Unspiral(Self[i]);
  end;
  Q(0, (s - 1));
  for i := 0 to (s - 1) do
    Self[i] := k[i].item;
end;

{==============================================================================]
  <SortSpiraling>
  @action: Sorts the points in the array based on their spatial spiral distance 
           relative to an origin point using indirect index-map sorting.
  @note: Pre-calculates spiral keys into a UInt32 array and sorts an integer 
         index map to minimize memory swap overhead before performing a final 
         reordering pass. Returns the total number of elements in the array.
[==============================================================================}
function TPointArrayHelper.SortSpiraling(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  m: TIntegerArray;
  k: array of UInt32;
  t: TPointArray;
  procedure Q(L, R: Integer);
  var
    a, b, s: Integer;
    p: UInt32;
  begin
    a := L;
    b := R;
    p := k[m[(L + R) div 2]];
    case oAscending of
      True:
      repeat
        while (k[m[a]] < p) do
          Inc(a);
        while (k[m[b]] > p) do
          Dec(b);
        if (a <= b) then
        begin
          s := m[a];
          m[a] := m[b];
          m[b] := s;
          Inc(a);
          Dec(b);
        end;
      until (a > b);
      False:
      repeat
        while (k[m[a]] > p) do
          Inc(a);
        while (k[m[b]] < p) do
          Dec(b);
        if (a <= b) then
        begin
          s := m[a];
          m[a] := m[b];
          m[b] := s;
          Inc(a);
          Dec(b);
        end;
      until (a > b);
    end;
    if (L < b) then
      Q(L, b);
    if (a < R) then
      Q(a, R);
  end;
begin
  Result := Self.Length;
  if (Result <= 1) then
    Exit;
  SetLength(m, Result);
  SetLength(k, Result);
  for i := 0 to (Result - 1) do
  begin
    m[i] := i;
    k[i] := origin.Unspiral(Self[i]);
  end;
  Q(0, (Result - 1));
  for i := 0 to t.Alloc(Result) do
    t[i] := Self[m[i]];
  for i := 0 to (Result - 1) do
    Self[i] := t[i];
end;

{==============================================================================]
  <SortSpiralix>
  @action: Sorts points in the array based on their spatial spiral distance
           relative to an origin point using a 32-bit LSD Radix Sort.
  @note: Achieves O(N) linear time complexity by evaluating spiral keys in
         four 8-bit passes. Requires two temporary work arrays (O(N) space).
[==============================================================================}
function TPointArrayHelper.SortSpiralix(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
type
  TPointIndex = specialize TIndexed<TPoint>;
var
  i, p, m, j: Integer;
  b: Byte;
  s, d, z: array of TPointIndex;
  c: array[0..255] of Integer;
begin
  Result := Self.Length;
  if (Result <= 1) then
    Exit;
  SetLength(s, Result);
  SetLength(d, Result);
  for i := 0 to (Result - 1) do
  begin
    s[i].item := Self[i];
    s[i].index := origin.Unspiral(Self[i]);
  end;
  for p := 0 to 3 do
  begin
    m := (p * 8);
    FillChar(c, SizeOf(c), 0);
    for i := 0 to (Result - 1) do
    begin
      b := Byte((s[i].index shr m) and $FF);
      Inc(c[b]);
    end;
    j := 0;
    for i := 0 to 255 do
    begin
      m := c[i];
      c[i] := j;
      Inc(j, m);
    end;
    m := (p * 8);
    for i := 0 to (Result - 1) do
    begin
      b := Byte((s[i].index shr m) and $FF);
      d[c[b]] := s[i];
      Inc(c[b]);
    end;
    z := s;
    s := d;
    d := z;
  end;
  case oAscending of
    True:
    for i := 0 to (Result - 1) do
      Self[i] := s[i].item;
    False:
    for i := 0 to (Result - 1) do
      Self[i] := s[(Result - 1) - i].item;
  end;
end;

{==============================================================================]
  <SortSpirally>
  @action: Sorts points in the array based on their spatial spiral distance
           relative to an origin point.
  @note: Computes spiral indices and delegates sorting to QuickSortByIndex.
[==============================================================================}
function TPointArrayHelper.SortSpirally(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  k: TIntegerArray;
begin
  Result := Self.Length;
  if (Result <= 1) then
    Exit;
  for i := 0 to k.Alloc(Result) do
    k[i] := origin.Unspiral(Self[i]);
  Self.QuickSortByIndex(k, oAscending);
end;

{==============================================================================]
  <SortSpiralwise>
  @action: Sorts the points in the array in-place based on their spiral order 
           relative to an origin point.
  @note: Uses an in-place QuickSort algorithm that calculates spiral index 
         keys on the fly without allocating auxiliary temporary memory arrays.
[==============================================================================}
function TPointArrayHelper.SortSpiralwise(const origin: TPoint; const oAscending: Boolean = True): Integer; overload;
  procedure Q(L, R: Integer);
  var
    a, b: Integer;
    p: UInt32;
  begin
    a := L;
    b := R;
    p := origin.Unspiral(Self[(L + R) div 2]);
    case oAscending of
      True:
      repeat
        while (origin.Unspiral(Self[a]) < p) do
          Inc(a);
        while (origin.Unspiral(Self[b]) > p) do
          Dec(b);
        if (a <= b) then
          Self.Switch(a.Increase, b.Decrease);
      until (a > b);
      False:
      repeat
        while (origin.Unspiral(Self[a]) > p) do
          Inc(a);
        while (origin.Unspiral(Self[b]) < p) do
          Dec(b);
        if (a <= b) then
          Self.Switch(a.Increase, b.Decrease);
      until (a > b);
    end;
    if (L < b) then
      Q(L, b);
    if (a < R) then
      Q(a, R);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    Q(0, (Result - 1));
end;

{==============================================================================]
  <SortSpiralwise>
  @action: Sorts a TPointArray lexicographically by coordinates (primarily by Y-coordinate, then by X-coordinate) using an iterative merge sort algorithm.
  @note: Operates in O(N log N) time complexity with O(N) auxiliary space. As a stable merge sort,
         it performs consistently regardless of coordinate sparsity or bounding box size.
[==============================================================================}
function TPointArrayHelper.SortedByCoords(const oAscending: Boolean = True): TPointArray; overload;
var
  n, w, i, a, b, m, e, p: Integer;
  r, s: TPointArray;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  Result := Self.Copy;
  SetLength(r, n);
  w := 1;
  while (w < n) do
  begin
    i := 0;
    while (i < n) do
    begin
      m := Min((i + w), n);
      e := Min((i + (2 * w)), n);
      a := i;
      b := m;
      p := i;
      while ((a < m) and (b < e)) do
        if ((oAscending and ((Result[b].Y < Result[a].Y) or ((Result[b].Y = Result[a].Y) and (Result[b].X < Result[a].X)))) or ((not oAscending) and ((Result[b].Y > Result[a].Y) or ((Result[b].Y = Result[a].Y) and (Result[b].X > Result[a].X))))) then
          r[p.Increase] := Result[b.Increase]
        else
          r[p.Increase] := Result[a.Increase];
      while (a < m) do
        r[p.Increase] := Result[a.Increase];
      while (b < e) do
        r[p.Increase] := Result[b.Increase];
      Inc(i, (2 * w));
    end;
    s := Result;
    Result := r;
    r := s;
    w := (w * 2);
  end;
end;

{==============================================================================]
  <SortedByIndex>
  @action: Returns array sorted by indexes in array bounding box.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SortedByIndex(const aAscending: Boolean = True): TPointArray; overload;
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    Result := Self.QuickSorted(Self.Bounds.IDs(Self), aAscending);
end;

{==============================================================================]
  <SortedByLocale>
  @action: Sorts a TPointArray primarily by Y-coordinate using a counting sort approach,
           and then sorts points within each horizontal row by their X-coordinate using insertion sort.
@note: Hybrid sorting algorithm combining counting sort (for rows) and insertion sort (for columns within each row).
       Efficient when the vertical span (Y range) is relatively compact, with a final reversal applied if descending order is requested.
[==============================================================================}
function TPointArrayHelper.SortedByLocale(const oAscending: Boolean = True): TPointArray; overload;
var
  s, i, j, r, h, l: Integer;
  c: TIntegerArray;
  p: TPoint;
  y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  y.Create(Self[0].Y);
  for i := 1 to (s - 1) do
    if (Self[i].Y < y.start) then
      y.start := Self[i].Y
    else if (Self[i].Y > y.stop) then
      y.stop := Self[i].Y;
  SetLength(c, (y.stop - y.start + 2));
  for i := 0 to (s - 1) do
    Inc(c[Self[i].Y - y.start + 1]);
  for i := 1 to High(c) do
    Inc(c[i], c[i - 1]);
  for i := 0 to Result.Alloc(s) do
    Result[c[Self[i].Y - y.start].Increase] := Self[i];
  l := 0;
  for r := 0 to (y.stop - y.start) do
  begin
    h := c[r];
    for i := (l + 1) to (h - 1) do
    begin
      p := Result[i];
      j := (i - 1);
      while ((j >= l) and (Result[j].X > p.X)) do
      begin
        Result[j + 1] := Result[j];
        Dec(j);
      end;
      Result[j + 1] := p;
    end;
    l := h;
  end;
  if (not oAscending) then
    Result.Reverse;
end;

{==============================================================================]
  <SortedByLocation>
  @action: Sorts a TPointArray spatially by coordinate location (top-to-bottom, left-to-right) using a counting sort algorithm based on its bounding box.
  @note: Operates in O(N + W * H) time complexity. Highly efficient for dense clusters of points,
         but can consume excessive memory if the bounding box dimensions (W and H) are extremely large due to the frequency array allocation.
[==============================================================================}
function TPointArrayHelper.SortedByLocation(const oAscending: Boolean = True): TPointArray; overload;
var
  s, i, j, k, w, h, r, c: Integer;
  x, y: TRange;
  p: TIntegerArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  x.Create(Self[0].X);
  y.Create(Self[0].Y);
  for i := 1 to (s - 1) do
  begin
    if (Self[i].X < x.start) then
      x.start := Self[i].X
    else if (Self[i].X > x.stop) then
      x.stop := Self[i].X;
    if (Self[i].Y < y.start) then
      y.start := Self[i].Y
    else if (Self[i].Y > y.stop) then
      y.stop := Self[i].Y;
  end;
  w := ((x.stop - x.start) + 1);
  h := ((y.stop - y.start) + 1);
  SetLength(p, (w * h));
  for i := 0 to Result.Alloc(s) do
    Inc(p[(Self[i].Y - y.start) * w + (Self[i].X - x.start)]);
  k := 0;
  case oAscending of
    True:
    for i := 0 to (h - 1) do
      for j := 0 to (w - 1) do
        for s := 1 to p[i * w + j] do
          Result[k.Increase] := Point((j + x.start), (i + y.start));
    False:
    for i := 0 to (h - 1) do
    begin
      r := (h - 1 - i);
      for j := 0 to (w - 1) do
      begin
        c := (w - 1 - j);
        for s := 1 to p[r * w + c] do
          Result[k.Increase] := Point((c + x.start), (r + y.start));
      end;
    end;
  end;
end;

{==============================================================================]
  <SortedByPosition>
  @action: Returns a new TPointArray sorted by scanline position (Y, then X).
  @note: Non-mutating; Self is left untouched.
   - oAscending = True: top-to-bottom, left-to-right within each row.
   - oAscending = False: bottom-to-top, right-to-left within each row
     (the exact reverse of the ascending order).
   - Two stable counting-sort passes (X, then Y): O(n + rangeX + rangeY).
   - Memory is O(n + rangeX + rangeY), so very sparse points with huge
     coordinate spans are better served by a comparison sort.
[==============================================================================}
function TPointArrayHelper.SortedByPosition(const oAscending: Boolean = True): TPointArray; overload;
var
  s, i: Integer;
  c, r: TIntegerArray;
  t: TPointArray;
  p: TPoint;
  x, y: TRange;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  x.Create(Self[0].X);
  y.Create(Self[0].Y);
  for i := 1 to (s - 1) do
  begin
    if (Self[i].X < x.start) then
      x.start := Self[i].X
    else if (Self[i].X > x.stop) then
      x.stop := Self[i].X;
    if (Self[i].Y < y.start) then
      y.start := Self[i].Y
    else if (Self[i].Y > y.stop) then
      y.stop := Self[i].Y;
  end;
  SetLength(c, (x.stop - x.start + 2));
  SetLength(r, (y.stop - y.start + 2));
  for i := 0 to (s - 1) do
  begin
    Inc(c[(Self[i].X - x.start) + 1]);
    Inc(r[(Self[i].Y - y.start) + 1]);
  end;
  for i := 1 to High(c) do
    Inc(c[i], c[i - 1]);
  for i := 1 to High(r) do
    Inc(r[i], r[i - 1]);
  for i := 0 to t.Alloc(s) do
    t[c[Self[i].X - x.start].Increase] := Self[i];
  for i := 0 to Result.Alloc(s) do
    Result[r[t[i].Y - y.start].Increase] := t[i];
  if (not oAscending) then
    Result.Reverse;
end;

function TPointArrayHelper.SortedBySpiral(const origin: TPoint; const oAscending: Boolean = True): TPointArray; overload;
begin
  Result := Self.Cloned;
  Result.SortBySpiral(origin, oAscending);
end;
{$ENDIF}
