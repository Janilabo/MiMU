{$IFDEF HELPERS}
function BinarySortified(const oAscending: Boolean = True): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinarySortified>
  @action: Returns a new TPointArray sorted by scanline position (Y, then X).
  @note: Non-mutating; Self is left untouched.
   - Binary insertion sort: the insertion slot in the sorted prefix is found
     by binary search (upper bound, so the sort is stable), then the tail
     is shifted up by one.
   - oAscending = False sorts bottom-to-top, right-to-left.
   - O(n log n) comparisons, O(n^2) moves worst case, O(1) extra memory.
   - Already-sorted input is O(n): each point is checked against the end
     of the prefix before any searching.
[==============================================================================}
function TPointArrayHelper.BinarySortified(const oAscending: Boolean = True): TPointArray; overload;
var
  n, i, j, l, h, m: Integer;
  p: TPoint;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  Result := Self.Copy;
  for i := 1 to (n - 1) do
  begin
    p := Result[i];
    if not ((oAscending and ((p.Y < Result[i - 1].Y) or ((p.Y = Result[i - 1].Y) and (p.X < Result[i - 1].X)))) or ((not oAscending) and ((p.Y > Result[i - 1].Y) or ((p.Y = Result[i - 1].Y) and (p.X > Result[i - 1].X))))) then
      Continue;
    l := 0;
    h := (i - 1);
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if ((oAscending and ((p.Y < Result[m].Y) or ((p.Y = Result[m].Y) and (p.X < Result[m].X)))) or ((not oAscending) and ((p.Y > Result[m].Y) or ((p.Y = Result[m].Y) and (p.X > Result[m].X))))) then
        h := m
      else
        l := (m + 1);
    end;
    for j := i downto (l + 1) do
      Result[j] := Result[j - 1];
    Result[l] := p;
  end;
end; 
{$ENDIF}
