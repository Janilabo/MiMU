{$IFDEF HELPERS}
function SortByRow(const aAscending: Boolean = True): Integer; overload;
function SortByColumn(const aAscending: Boolean = True): Integer; overload;
function SortedByIndex(const aAscending: Boolean = True): TPointArray; overload;
function QuickSortByX(const aAscending: Boolean = True): Integer;
function QuickSortByY(const aAscending: Boolean = True): Integer;
function QuickSortByXY(const aAscending: Boolean = True): Integer;
function QuickSortByYX(const aAscending: Boolean = True): Integer;
function SortByIndex(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
function SortByIndex(const aAscending: Boolean = True): Integer; overload;
function SortByScanline(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
function SortByScanline(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
