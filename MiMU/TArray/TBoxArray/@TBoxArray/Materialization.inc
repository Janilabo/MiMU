{$IFDEF HELPERS}
function Pixelize(const oAscending: Boolean = True): TPointArray; overload;
function Pixels(const oAscending: Boolean = True): TPointArray; overload;
function Points(const oAscending: Boolean = True): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Pixelize>
  @action: Returns a TPointArray of every unique pixel covered by any TBox in
           Self, via a boolean occupancy grid sized to Self.Bounds — each
           covered box is stamped onto the grid, then the grid is scanned
           twice: once to count set cells (for exact single allocation), once
           to collect their coordinates in raster order.
  @note: Grid size is (Bounds.Width * Bounds.Height) regardless of how much of
         that area is actually covered — memory-unsafe for widely-separated,
         sparse boxes (e.g. one box near origin and another far away), even
         though real screen-region use is typically fine. oAscending selects
         top-left-to-bottom-right vs. bottom-right-to-top-left raster order;
         c.Increase (postfix capture) relies on Points/Pixels having already
         established that convention for fill-index bookkeeping.
[==============================================================================}
function TBoxArrayHelper.Pixelize(const oAscending: Boolean = True): TPointArray; overload;
var
  w, h, i, x, y, c: Integer;
  b: TBox;
  s: T2DBooleanArray;
begin
  SetLength(Result, 0);
  if (Self.Length = 0) then
    Exit;
  b := Self.Bounds;
  b.Dimensions(w, h);
  SetLength(s, h, w);
  for i := 0 to High(Self) do
    for y := Self[i].Y1 to Self[i].Y2 do
      for x := Self[i].X1 to Self[i].X2 do
        s[y - b.Y1][x - b.X1] := True;
  c := 0;
  for y := 0 to (h - 1) do
    for x := 0 to (w - 1) do
      if s[y][x] then
        Inc(c);
  SetLength(Result, c);
  c := 0;
  case oAscending of
    True:
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if s[y][x] then
          Result[c.Increase] := Point((x + b.X1), (y + b.Y1));
    False:
    for y := (h - 1) downto 0 do
      for x := (w - 1) downto 0 do
        if s[y][x] then
          Result[c.Increase] := Point((x + b.X1), (y + b.Y1));
  end;
end;

{==============================================================================]
  <Pixels>
  @action: Returns a TPointArray of every unique pixel covered by any TBox in
           Self, built by inserting each covered point into its sorted
           position via BinarySupply as it's discovered.
  @note: O(total covered pixels) BinarySupply calls, each an O(log n) locate
         but up to O(n) shift on insert — cost trends toward O(n²) for large
         or heavily-overlapping coverage. Result grows to exactly the final
         unique count with no transient over-allocation. oAscending sets the
         maintained sort direction (TPoint's Y-primary ordering).
[==============================================================================}
function TBoxArrayHelper.Pixels(const oAscending: Boolean = True): TPointArray; overload;
var
  i, r, c: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    for r := Self[i].Y1 to Self[i].Y2 do
      for c := Self[i].X1 to Self[i].X2 do
        Result.BinarySupply(Point(c, r), oAscending);
end;

{==============================================================================]
  <Points>
  @action: Returns a TPointArray of every unique pixel covered by any TBox in
           Self, built by materializing all covered points up front
           (duplicates included), sorting once, then compacting adjacent
           duplicates in place.
  @note: Transient allocation is Sum(Self[i].Area) — the *non-unique* pixel
         count — before compaction, which can be far larger than the final
         result under heavy overlap. Sort + single-pass compaction is
         O(n log n), faster than Pixels at scale despite the larger peak
         memory. `s` does double duty: countdown fill-index during
         materialization, then reset to 0 and reused as the dedup
         write-pointer.
[==============================================================================}
function TBoxArrayHelper.Points(const oAscending: Boolean = True): TPointArray; overload;
var
  i, r, c, s: Integer;
begin
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Area);
  SetLength(Result, s);
  for i := High(Self) downto 0 do
    for r := Self[i].Y2 downto Self[i].Y1 do
      for c := Self[i].X2 downto Self[i].X1 do
        Result[s.Decrement] := Point(c, r);
  Result.QuickSort(oAscending);
  for i := 1 to High(Result) do
    if ((Result[s].X <> Result[i].X) or (Result[s].Y <> Result[i].Y)) then
      Result[s.Increment] := Result[i];
  SetLength(Result, (s + 1));
end;
{$ENDIF}
