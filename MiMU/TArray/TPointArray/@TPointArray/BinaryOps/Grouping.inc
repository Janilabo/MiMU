{$IFDEF HELPERS}
function BinaryXGrouped: T2DPointArray; overload;
function BinaryXGroups(const oAscending: Boolean = True): T2DPointArray; overload;
function BinaryYGrouped: T2DPointArray; overload;
function BinaryYGroups(const oAscending: Boolean = True): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryXGrouped>
  @action:
    Groups all points in the TPointArray by their X-coordinate using binary search.
    Returns a T2DPointArray where each element is a TPointArray containing all
    points that share the same X-value.
    The result is ordered by increasing X, and contains only X-columns that
    actually exist in the source array.
  @note:
    - The array must be sorted in **column-scan order**: X ascending, then
      Y ascending for points with equal X. This is the OPPOSITE sort order
      required by BinaryYGrouped — the two are not interchangeable on the
      same sorted array.
    - Internally uses BinaryXPoints to extract each X-column efficiently.
    - Result length equals the number of unique X-values present.
    - Empty columns (X values with no points) are skipped.
[==============================================================================}
function TPointArrayHelper.BinaryXGrouped: T2DPointArray; overload;
var
  r, h, i, l: Integer;
begin
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    l := Result.SetSize(Min((h + 1), ((Self[h].X - Self[0].X) + 1)));
    for i := Self[0].X to Self[h].X do
      if (Result[r].Supply(Self.BinaryXPoints(i)) > -1) then
        Inc(r);
    if (r < l) then
      SetLength(Result, r);
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <BinaryXGroups>
  @action: Groups points into a 2D point array by their X coordinates using binary search.
  @note: Returns a T2DPointArray where each sub-array contains points sharing the same X value,
         ordered according to the oAscending parameter.
[==============================================================================}
function TPointArrayHelper.BinaryXGroups(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i: Integer;
  x: TIntegerArray;
begin
  if (Self.Length = 0) then
    Exit([]);
  x := Self.XArr(oAscending).Compressed;
  SetLength(Result, x.Length);
  for i := 0 to High(Self) do
    Result[x.BinarySearch(Self[i].X, oAscending)].BinaryAppend(Self[i], oAscending);
end;

{==============================================================================]
  <BinaryGrouped>
  @action:
    Groups all points in the TPointArray by their Y-coordinate using binary search.
    Returns a T2DPointArray where each element is a TPointArray containing all
    points that share the same Y-value.
    The result is ordered by increasing Y, and contains only Y-rows that actually
    exist in the source array.
  @note:
    - The array must be sorted in **scanline order**:
      Y ascending, then X ascending for points with equal Y.
    - Internally uses BinaryYPoints to extract each Y-row efficiently.
    - Result length equals the number of unique Y-values present.
    - Empty rows (Y values with no points) are skipped.
[==============================================================================}
function TPointArrayHelper.BinaryYGrouped: T2DPointArray; overload;
var
  r, h, i, l: Integer;
begin
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    l := Result.SetSize(Min((h + 1), ((Self[h].Y - Self[0].Y) + 1)));
    for i := Self[0].Y to Self[h].Y do
      if (Result[r].Supply(Self.BinaryYPoints(i)) > -1) then
        Inc(r);
    if (r < l) then
      SetLength(Result, r);
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <BinaryYGroups>
  @action: Groups points into a 2D point array by their Y coordinates using binary search.
  @note: Returns a T2DPointArray where each sub-array contains points sharing the same Y value,
         ordered according to the oAscending parameter.
[==============================================================================}
function TPointArrayHelper.BinaryYGroups(const oAscending: Boolean = True): T2DPointArray; overload;
var
  i: Integer;
  y: TIntegerArray;
begin
  if (Self.Length = 0) then
    Exit([]);
  y := Self.YArr(oAscending).Compressed;
  SetLength(Result, y.Length);
  for i := 0 to High(Self) do
    Result[y.BinarySearch(Self[i].Y, oAscending)].BinaryAppend(Self[i], oAscending);
end;
{$ENDIF}
