{$IFDEF HELPERS}
function BinaryXGrouped: T2DPointArray; overload;
function BinaryYGrouped: T2DPointArray; overload;
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
{$ENDIF}
