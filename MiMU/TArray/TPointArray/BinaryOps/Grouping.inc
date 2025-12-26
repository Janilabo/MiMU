{$IFDEF HELPERS}
function BinaryGrouped: T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
function TPointArrayHelper.BinaryGrouped: T2DPointArray; overload;
var
  r, h, i, l: Integer;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    l := Min((h + 1), ((Self[h].Y - Self[0].Y) + 1));
    SetLength(Result, l);
    for i := Self[0].Y to Self[h].Y do
      if (Result[r].Supply(Self.BinaryYPoints(i)) > -1) then
        Inc(r);
    if (r < l) then
      SetLength(Result, r);
  end;
end;
{$ENDIF}
