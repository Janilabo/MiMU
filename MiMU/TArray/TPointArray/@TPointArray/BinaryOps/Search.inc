{$IFDEF HELPERS}
function BinaryFinder(const item: TPoint): Integer; overload;
function BinaryFind(const area: TBox): Integer; overload;
function BinarySearch(const area: TBox): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFinder>
  @action: Performs binary search on the sorted point array to locate the exact TPoint whose coordinates match the specified item.
           The search is lexicographical: first by Y, then by X.
  @note: The array must be pre-sorted by Y ascending and, for identical Y values, by X ascending.
         Returns the index of the matching element, or -1 if no match is found.
[==============================================================================}
function TPointArrayHelper.BinaryFinder(const item: TPoint): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M].Y < item.Y) of
      True:
      begin
        R.start := (M + 1);
        Continue;
      end;
      False:
      if (Self[M].Y > item.Y) then
      begin
        R.stop := (M - 1);
        Continue;
      end;
    end;
    case (Self[M].X < item.X) of
      True:
      begin
        R.start := (M + 1);
        Continue;
      end;
      False:
      if (Self[M].X > item.X) then
      begin
        R.stop := (M - 1);
        Continue;
      end;
    end;
    Exit(M);
  end;
end;

{==============================================================================]
  <BinaryFind>
  @action: Locates the first point within the array whose coordinates fall inside the given rectangular TBox by performing a binary search on the Y coordinate,
           then scanning forward through the candidate range.
  @note: The array must be sorted by Y ascending. The function first narrows the search to the lowest index where Y ≥ area.Y1,
         then linearly scans forward until Y > area.Y2 or a qualifying point is found.
		 Returns the index of the first point inside the box, or -1 if the area contains no points.
[==============================================================================}
function TPointArrayHelper.BinaryFind(const area: TBox): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y < area.Y1) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  while ((R.start <= High(Self)) and (Self[R.start].Y <= area.Y2)) do
  begin
    if ((Self[R.start].X >= area.X1) and (Self[R.start].X <= area.X2)) then
      Exit(R.start);
    Inc(R.start);
  end;
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search over the point array to locate any point contained within the specified bounding box (TBox).
           If a point lying inside the area is found, its index is returned; otherwise, the function returns –1.
  @note: The array must be pre-sorted by Y coordinate (and implicitly by X for tie-breaking) in the same ordering implemented by TPoint.Compare.
         The initial boundary check short-circuits the search if the box vertically lies outside the array’s extents.
		 The search returns the first matching point encountered during the binary-search traversal,
		 not a guaranteed minimal or maximal spatial index. Execution is O(log n).
[==============================================================================}
function TPointArrayHelper.BinarySearch(const area: TBox): Integer; overload;
var
  M: Integer;
  Y, R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  Y.Create(area.Y1, area.Y2);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y < Y.start) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  while ((R.start <= High(Self)) and (Self[R.start].Y <= Y.stop)) do
  begin
    if ((Self[R.start].X >= area.X1) and (Self[R.start].X <= area.X2)) then
      Exit(R.start);
    Inc(R.start);
  end;
end;
{$ENDIF}
