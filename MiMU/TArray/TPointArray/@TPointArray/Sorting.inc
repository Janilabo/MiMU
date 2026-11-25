{$IFDEF HELPERS}
function QuickSortByX(const aAscending: Boolean = True): Integer; overload;
function QuickSortByXY(const aAscending: Boolean = True): Integer; overload;
function QuickSortByY(const aAscending: Boolean = True): Integer; overload;
function QuickSortByYX(const aAscending: Boolean = True): Integer; overload;
function QuickSortedByXY(const aAscending: Boolean = True): TPointArray; overload;
function QuickSortedByYX(const aAscending: Boolean = True): TPointArray; overload;
function QuickSortedByX(const aAscending: Boolean = True): TPointArray; overload;
function QuickSortedByY(const aAscending: Boolean = True): TPointArray; overload;
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
function XthenY(const oAscending: Boolean = True): TPointArray; overload;
function YthenX(const oAscending: Boolean = True): TPointArray; overload;

function Raster: Integer; overload;
function Rasterify: Integer; overload;
function Rasterize: Integer; overload;

function Rastered: TPointArray; overload;
function Rasterified: TPointArray; overload;
function Rasterized: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <QuickSortByX>
  @action: Sorts all points in ascending order based on their X coordinate.
  @note: Uses an in-place recursive QuickSort. Does not guarantee stability
         for equal X values. Complexity is O(n log n) on average.
[==============================================================================}
function TPointArrayHelper.QuickSortByX(const aAscending: Boolean = True): Integer; overload;
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
function TPointArrayHelper.QuickSortByXY(const aAscending: Boolean = True): Integer; overload;
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
function TPointArrayHelper.QuickSortByY(const aAscending: Boolean = True): Integer; overload;
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
function TPointArrayHelper.QuickSortByYX(const aAscending: Boolean = True): Integer; overload;
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
  <QuickSortedByXY>
  @action: Returns a copy of all points sorted by X coordinate first, and then by Y
           coordinate for points sharing the same X value.
  @note: Self-contained, non-mutating. Copies Self and runs a dual-key Hoare
         QuickSort on the copy, so Self is left untouched. Average complexity
         O(n log n). Not stable for equal (X,Y) pairs.
[==============================================================================}
function TPointArrayHelper.QuickSortedByXY(const aAscending: Boolean = True): TPointArray; overload;
  procedure QSXY(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p, t: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].X < p.X) or ((arr[i].X = p.X) and (arr[i].Y < p.Y)))) or ((not A) and ((arr[i].X > p.X) or ((arr[i].X = p.X) and (arr[i].Y > p.Y))))) do
        Inc(i);
      while ((A and ((arr[j].X > p.X) or ((arr[j].X = p.X) and (arr[j].Y > p.Y)))) or ((not A) and ((arr[j].X < p.X) or ((arr[j].X = p.X) and (arr[j].Y < p.Y))))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSXY(arr, L, j, A);
    if (i < R) then
      QSXY(arr, i, R, A);
  end;
var
  s: Integer;
begin
  Result := Self.Copy;
  s := Result.Length;
  if (s > 1) then
    QSXY(Result, 0, (s - 1), aAscending);
end;

{==============================================================================]
  <QuickSortedByYX>
  @action: Returns a copy of all points sorted by Y coordinate first, and then by X
           coordinate for points sharing the same Y value.
  @note: Self-contained, non-mutating. Copies Self and runs a dual-key Hoare
         QuickSort on the copy, so Self is left untouched. Average complexity
         O(n log n). Not stable for equal (X,Y) pairs.
[==============================================================================}
function TPointArrayHelper.QuickSortedByYX(const aAscending: Boolean = True): TPointArray; overload;
  procedure QSYX(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p, t: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].Y < p.Y) or ((arr[i].Y = p.Y) and (arr[i].X < p.X)))) or ((not A) and ((arr[i].Y > p.Y) or ((arr[i].Y = p.Y) and (arr[i].X > p.X))))) do
        Inc(i);
      while ((A and ((arr[j].Y > p.Y) or ((arr[j].Y = p.Y) and (arr[j].X > p.X)))) or ((not A) and ((arr[j].Y < p.Y) or ((arr[j].Y = p.Y) and (arr[j].X < p.X))))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSYX(arr, L, j, A);
    if (i < R) then
      QSYX(arr, i, R, A);
  end;
var
  s: Integer;
begin
  Result := Self.Copy;
  s := Result.Length;
  if (s > 1) then
    QSYX(Result, 0, (s - 1), aAscending);
end;

{==============================================================================]
  <QuickSortedByX>
  @action: Sorts the point array based on the X coordinates of its points.
  @note: Uses a quicksort algorithm. The sorting direction is determined by the aAscending parameter
         (True for ascending, False for descending). Returns a new sorted TPointArray.
[==============================================================================}
function TPointArrayHelper.QuickSortedByX(const aAscending: Boolean = True): TPointArray; overload;
begin
  Result := Self.QuickSorted(Self.Xs, aAscending); 
end;

{==============================================================================]
  <QuickSortedByY>
  @action: Sorts the point array based on the Y coordinates of its points.
  @note: Uses a quicksort algorithm. The sorting direction is determined by the aAscending parameter
         (True for ascending, False for descending). Returns a new sorted TPointArray.
[==============================================================================}
function TPointArrayHelper.QuickSortedByY(const aAscending: Boolean = True): TPointArray; overload;
begin
  Result := Self.QuickSorted(Self.Ys, aAscending);
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

{==============================================================================]
  <XthenY>
  @action: Returns a copy of the TPointArray sorted by X, then by Y.
  @note: Returns a copy of the array as-is if its length is less than 2.
[==============================================================================}
function TPointArrayHelper.XthenY(const oAscending: Boolean = True): TPointArray; overload;
var
  i, j, l, h, t: Integer;
  r, p: TPoint;
  s: array[0..63] of Integer;
begin
  Result := Self.Copy;
  if (Result.Length < 2) then
    Exit;
  t := 0;
  l := 0;
  h := High(Result);
  repeat
    while ((h - l) > 16) do
    begin
      r := Result[l + ((h - l) div 2)];
      i := l;
      j := h;
      repeat
        while ((Result[i].X < r.X) or ((Result[i].X = r.X) and (Result[i].Y < r.Y))) do
          Inc(i);
        while ((Result[j].X > r.X) or ((Result[j].X = r.X) and (Result[j].Y > r.Y))) do
          Dec(j);
        if (i <= j) then
          Swap(Result[i.Increase], Result[j.Decrease]);
      until (i > j);
      if ((j - l) < (h - i)) then
      begin
        s[t] := i;
        s[t + 1] := h;
        Inc(t, 2);
        h := j;
      end else
      begin
        s[t] := l;
        s[t + 1] := j;
        Inc(t, 2);
        l := i;
      end;
    end;
    for i := (l + 1) to h do
    begin
      p := Result[i];
      j := i - 1;
      while ((j >= l) and ((Result[j].X > p.X) or ((Result[j].X = p.X) and (Result[j].Y > p.Y)))) do
      begin
        Result[j + 1] := Result[j];
        Dec(j);
      end;
      Result[j + 1] := p;
    end;
    if (t = 0) then
      Break;
    Dec(t, 2);
    l := s[t];
    h := s[t + 1];
  until False;
  if not oAscending then
    Result.Reverse;
end;

{==============================================================================]
  <YthenX>
  @action: Returns a copy of the TPointArray sorted by Y, then by X.
  @note: Returns a copy of the array as-is if its length is less than 2.
[==============================================================================}
function TPointArrayHelper.YthenX(const oAscending: Boolean = True): TPointArray; overload;
var
  i, j, l, h, t: Integer;
  r, p: TPoint;
  s: array[0..63] of Integer;
begin
  Result := Self.Copy;
  if (Result.Length < 2) then
    Exit;
  t := 0;
  l := 0;
  h := High(Result);
  repeat
    while ((h - l) > 16) do
    begin
      r := Result[l + ((h - l) div 2)];
      i := l;
      j := h;
      repeat
        while ((Result[i].Y < r.Y) or ((Result[i].Y = r.Y) and (Result[i].X < r.X))) do
          Inc(i);
        while ((Result[j].Y > r.Y) or ((Result[j].Y = r.Y) and (Result[j].X > r.X))) do
          Dec(j);
        if (i <= j) then
          Swap(Result[i.Increase], Result[j.Decrease]);
      until (i > j);
      if ((j - l) < (h - i)) then
      begin
        s[t] := i;
        s[t + 1] := h;
        Inc(t, 2);
        h := j;
      end else
      begin
        s[t] := l;
        s[t + 1] := j;
        Inc(t, 2);
        l := i;
      end;
    end;
    for i := (l + 1) to h do
    begin
      p := Result[i];
      j := (i - 1);
      while ((j >= l) and ((Result[j].Y > p.Y) or ((Result[j].Y = p.Y) and (Result[j].X > p.X)))) do
      begin
        Result[j + 1] := Result[j];
        Dec(j);
      end;
      Result[j + 1] := p;
    end;
    if (t = 0) then
      Break;
    Dec(t, 2);
    l := s[t];
    h := s[t + 1];
  until False;
  if not oAscending then
    Result.Reverse;
end;

{==============================================================================]
  <Raster>
  @action: Sorts the point array in-place in row-major (scanline) order (ascending Y, then ascending X) and returns the element count.
  @note: Uses a fast-path check for already-ordered arrays, insertion sort for small arrays (n <= 24),
         two-pass counting sort for compact bounding boxes ((width + height) <= 4 * n),
		 and 11-bit base-2048 LSD radix sort over linear Int64 scanline indices for wider spans.
[==============================================================================}
function TPointArrayHelper.Raster: Integer; overload;
var
  n, i, k, d, s, h, v: Integer;
  o: Boolean;
  c: TIntegerArray;
  t: TPointArray;
  x, y, z: TInt64Array;
  m, q: Int64;
  b: TBox;
  procedure Insertion;
  var
    i: Integer;
    p: TPoint;
  begin
    for i := 1 to (n - 1) do
    begin
      p := Self[i];
      k := (i - 1);
      while ((k >= 0) and ((Self[k].y > p.y) or ((Self[k].y = p.y) and (Self[k].x > p.x)))) do
      begin
        Self[k + 1] := Self[k];
        Dec(k);
      end;
      Self[k + 1] := p;
    end;
  end;
  procedure Counting;
  var
    i: Integer;
  begin
    SetLength(t, n);
    SetLength(c, (h + 1));
    for i := 0 to (n - 1) do
      Inc(c[(Self[i].x - b.X1) + 1]);
    for i := 1 to h do
      c[i] := (c[i] + c[i - 1]);
    for i := 0 to (n - 1) do
      t[c[Self[i].x - b.X1].Increase] := Self[i];
    SetLength(c, 0);
    SetLength(c, (v + 1));
    for i := 0 to (n - 1) do
      Inc(c[(t[i].y - b.Y1) + 1]);
    for i := 1 to v do
      c[i] := (c[i] + c[i - 1]);
    for i := 0 to (n - 1) do
      Self[c[t[i].y - b.Y1].Increase] := t[i];
  end;
  procedure Radix;
  var
    i: Integer;
  begin
    SetLength(x, n);
    SetLength(y, n);
    SetLength(c, 2048);
    m := ((Int64(v - 1) * h) + (h - 1));
    for i := 0 to (n - 1) do
      x[i] := ((Int64(Self[i].y - b.Y1) * h) + (Self[i].x - b.X1));
    s := 0;
    while ((m shr s) > 0) do
    begin
      for i := 0 to 2047 do
        c[i] := 0;
      for i := 0 to (n - 1) do
        Inc(c[Integer((x[i] shr s) and 2047)]);
      d := 0;
      for i := 0 to 2047 do
      begin
        k := c[i];
        c[i] := d;
        d := (d + k);
      end;
      for i := 0 to (n - 1) do
        y[c[Integer((x[i] shr s) and 2047)].Increase] := x[i];
      z := x;
      x := y;
      y := z;
      s := (s + 11);
    end;
    for i := 0 to (n - 1) do
    begin
      q := (x[i] div h);
      Self[i].y := (Integer(q) + b.Y1);
      Self[i].x := (Integer(x[i] - (q * h)) + b.X1);
    end;
  end;
begin
  n := Self.Length;
  Result := n;
  if (n < 2) then
    Exit;
  b := TBox.Construct(Self[0].X, Self[0].Y, Self[0].X, Self[0].Y);
  o := True;
  for i := 1 to (n - 1) do
  begin
    if (Self[i].x < b.X1) then
      b.X1 := Self[i].x
    else if (Self[i].x > b.X2) then
      b.X2 := Self[i].x;
    if (Self[i].y < b.Y1) then
      b.Y1 := Self[i].y
    else if (Self[i].y > b.Y2) then
      b.Y2 := Self[i].y;
    if (o and ((Self[i].y < Self[i - 1].y) or ((Self[i].y = Self[i - 1].y) and (Self[i].x < Self[i - 1].x)))) then
      o := False;
  end;
  if o then
    Exit;
  if (n <= 24) then
  begin
    Insertion;
    Exit;
  end;
  h := (b.X2 - b.X1 + 1);
  v := (b.Y2 - b.Y1 + 1);
  if ((h + v) <= (n * 4)) then
    Counting
  else
    Radix;
end;

{==============================================================================]
  <Rasterify>
  @action: Sorts the point array in-place according to TPoint.Before ordering and returns the element count.
  @note: Quicksort-style partitioning with median-of-three pivot selection, recursing into the smaller
         partition and iterating on the larger one (stack depth O(log n)). Subranges of 17 elements or
         fewer are finished with insertion sort. Not stable; worst case is O(n^2) on adversarial input.
[==============================================================================}
function TPointArrayHelper.Rasterify: Integer; overload;
  procedure S(lo, hi: Integer);
  var
    i, j, m, k: Integer;
    p: TPoint;
  begin
    while ((hi - lo) > 16) do
    begin
      m := (lo + ((hi - lo) shr 1));
      if Self[m].Before(Self[lo]) then
        Swap(Self[m], Self[lo]);
      if Self[hi].Before(Self[lo]) then
        Swap(Self[hi], Self[lo]);
      if Self[hi].Before(Self[m]) then
        Swap(Self[hi], Self[m]);
      p := Self[m];
      i := lo;
      j := hi;
      repeat
        while Self[i].Before(p) do
          Inc(i);
        while p.Before(Self[j]) do
          Dec(j);
        if (i <= j) then
          Swap(Self[i.Increase], Self[j.Decrease]);
      until (i > j);
      if ((j - lo) < (hi - i)) then
      begin
        S(lo, j);
        lo := i;
      end else
      begin
        S(i, hi);
        hi := j;
      end;
    end;
    for i := (lo + 1) to hi do
    begin
      p := Self[i];
      k := (i - 1);
      while ((k >= lo) and p.Before(Self[k])) do
      begin
        Self[k + 1] := Self[k];
        Dec(k);
      end;
      Self[k + 1] := p;
    end;
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    S(0, (Result - 1));
end;

{==============================================================================]
  <Rasterize>
  @action: Orders the point array in-place into row-major scanline order (ascending Y, then ascending X within each row) and returns the element count.
  @note: Uses a counting sort pass to bucket points by Y into row ranges (c[r]..c[r+1]),
         followed by an in-place insertion sort on X within each individual row before copying back to Self.
[==============================================================================}
function TPointArrayHelper.Rasterize: Integer; overload;
var
  i, k, r, a, b, n: Integer;
  s: TRange;
  c, w: TIntegerArray;
  t: TPointArray;
  p: TPoint;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  s.start := Self[0].y;
  s.stop := s.start;
  for i := 1 to (Result - 1) do
    if (Self[i].y < s.start) then
      s.start := Self[i].y
    else if (Self[i].y > s.stop) then
      s.stop := Self[i].y;
  n := ((s.stop - s.start) + 1);
  SetLength(c, (n + 1));
  for i := 0 to (Result - 1) do
    Inc(c[(Self[i].y - s.start) + 1]);
  for i := 1 to n do
    c[i] := (c[i] + c[i - 1]);
  SetLength(w, n);
  for r := 0 to (n - 1) do
    w[r] := c[r];
  for i := 0 to t.Alloc(Result) do
    t[w[Self[i].y - s.start].Increase] := Self[i];
  for r := 0 to (n - 1) do
  begin
    a := c[r];
    b := c[r + 1];
    for i := (a + 1) to (b - 1) do
    begin
      p := t[i];
      k := (i - 1);
      while ((k >= a) and (t[k].x > p.x)) do
      begin
        t[k + 1] := t[k];
        Dec(k);
      end;
      t[k + 1] := p;
    end;
  end;
  for i := 0 to (Result - 1) do
    Self[i] := t[i];
end;

{==============================================================================]
  <Rastered>
  @action: Returns a new point array ordered in row-major scanline order (ascending Y, then ascending X within each row) without modifying Self.
  @note: Buckets points by Y into row slices via prefix sums (falling back to Result.Rasterify when Y-span exceeds 4x the point count),
         then sorts each row's X coordinates in-place using Shell sort with Ciura gaps (starting at gap 1 for rows of 24 or fewer points).
[==============================================================================}
function TPointArrayHelper.Rastered: TPointArray; overload;
var
  l, i, j, k, r, a, b, s, h: Integer;
  c, w, g: TIntegerArray;
  p: TPoint;
  v: TRange;
begin
  l := Self.Length;
  if (Result.SetSize(l) = 0) then
    Exit;
  v.start := Self[0].Y;
  v.stop := v.start;
  for i := 1 to (l - 1) do
    if (Self[i].Y < v.start) then
      v.start := Self[i].Y
    else if (Self[i].Y > v.stop) then
      v.stop := Self[i].Y;
  h := ((v.stop - v.start) + 1);
  if (h > (l * 4)) then
  begin
    for i := 0 to (l - 1) do
	  Result[i] := Self[i];
    Result.Rasterify;
    Exit;
  end;
  SetLength(c, (h + 1));
  for i := 0 to (l - 1) do
    Inc(c[(Self[i].y - v.start) + 1]);
  for r := 1 to h do
    c[r] := (c[r] + c[r - 1]);
  for r := 0 to w.Alloc(h) do
    w[r] := c[r];
  for i := 0 to Result.Alloc(l) do
    Result[w[Self[i].y - v.start].Increase] := Self[i];
  g := [701, 301, 132, 57, 23, 10, 4, 1];
  for r := 0 to (h - 1) do
  begin
    a := c[r];
    b := c[r + 1];
    if ((b - a) < 2) then
      Continue;
    if ((b - a) <= 24) then
      s := 7
    else
      s := 0;
    for j := s to 7 do
      if (g[j] < (b - a)) then
      for i := (a + g[j]) to (b - 1) do
      begin
        p := Result[i];
        k := i;
        while (((k - g[j]) >= a) and (Result[k - g[j]].X > p.X)) do
        begin
          Result[k] := Result[k - g[j]];
          k := (k - g[j]);
        end;
        Result[k] := p;
      end;
  end;
end;

{==============================================================================]
  <Rasterified>
  @action: Returns a new point array ordered in row-major scanline order (ascending Y, then ascending X) without modifying Self.
  @note: Uses a dense 2D bounding-box occupancy grid (w * h) to emit points in scanline order when the area is within 8x the point count,
         falling back to copying Self and sorting via Rasterify for sparse or wide bounding boxes.
[==============================================================================}
function TPointArrayHelper.Rasterified: TPointArray; overload;
var
  l, i, j, k, w, h, x, y, c: Integer;
  b: TBox;
  g: TIntegerArray;
begin
  l := Self.Length;
  if (Result.SetSize(l) = 0) then
    Exit;
  b := Self.Bounds(w, h);
  if ((Int64(w) * h) > (Int64(l) * 8)) then
  begin
    for i := 0 to (l - 1) do
      Result[i] := Self[i];
    Result.Rasterify;
    Exit;
  end;
  SetLength(g, (w * h));
  for i := 0 to (l - 1) do
    Inc(g[((Self[i].Y - b.Y1) * w) + (Self[i].X - b.X1)]);
  SetLength(Result, l);
  k := 0;
  for y := 0 to (h - 1) do
    for x := 0 to (w - 1) do
      for j := 1 to g[(y * w) + x] do
        Result[k.Increase] := Point((X + b.X1), (Y + b.Y1));
end;

{==============================================================================]
  <Rasterized>
  @action: Returns a new point array ordered in row-major scanline order (ascending Y, then ascending X) without modifying Self.
  @note: Buckets point indices into Y-rows via prefix sums, sorts each row's index slice by X using insertion sort, and gathers points into Result in a single pass.
[==============================================================================}
function TPointArrayHelper.Rasterized: TPointArray; overload;
var
  l, i, r, k, v, c: Integer;
  s: TRange;
  o, d: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  s.start := Self[0].Y;
  s.stop := Self[0].Y;
  for i := 1 to (l - 1) do
    if (Self[i].Y < s.start) then
      s.start := Self[i].Y
    else if (Self[i].Y > s.stop) then
      s.stop := Self[i].Y;
  v := ((s.stop - s.start) + 1);
  if (v > (l * 4)) then
  begin
    Result := Self.Cloned;
    Result.Rasterify;
    Exit;
  end;
  SetLength(o, (v + 1));
  for i := 0 to (l - 1) do
    Inc(o[(Self[i].y - s.start) + 1]);
  for r := 1 to v do
    o[r] := (o[r] + o[r - 1]);
  for i := 0 to d.Alloc(l) do
    d[o[Self[i].y - s.start].Increase] := i;
  for r := v downto 1 do
    o[r] := o[r - 1];
  o[0] := 0;
  for r := 0 to (v - 1) do
    for i := (o[r] + 1) to (o[r + 1] - 1) do
    begin
      c := d[i];
      k := (i - 1);
      while ((k >= o[r]) and (Self[d[k]].X > Self[c].X)) do
      begin
        d[k + 1] := d[k];
        Dec(k);
      end;
      d[k + 1] := c;
    end;
  for i := 0 to Result.Alloc(l) do
    Result[i] := Self[d[i]];
end;
{$ENDIF}
