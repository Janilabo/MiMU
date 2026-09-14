{$IFDEF HELPERS}
function Pixeled(const oAscending: Boolean = True): TPointArray; overload;
function Pixelize(const oAscending: Boolean = True): TPointArray; overload;
function Pixels(const oAscending: Boolean = True): TPointArray; overload;
function Pointify(const oAscending: Boolean = True): TPointArray; overload;
function Points(const oAscending: Boolean = True): TPointArray; overload;
function ToPoints(const oAscending: Boolean = True): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Pixeled>
  @action: Splices overlapping boxes into non-overlapping sub-boxes before
           generating points.
  @note: Outstandingly fast when handling large overlapping boxes (e.g., 500x500
         boxes) because it avoids generating and sorting millions of transient
         duplicate points.
[==============================================================================}
function TBoxArrayHelper.Pixeled(const oAscending: Boolean = True): TPointArray; overload;
var
  d: TBoxArray;
  i, j, r, c, t, l: Integer;
  procedure Z(const subject, cutter: TBox; var list: TBoxArray);
  var
    o, s: TBox;
  begin
    if not subject.Overlap(cutter) then
    begin
      SetLength(list, (list.Length + 1));
      list[High(list)] := subject;
      Exit;
    end;
    o := subject.Intersect(cutter);
    s := subject;
    if (s.Y1 < o.Y1) then
    begin
      SetLength(list, (list.Length + 1));
      list[High(list)] := Box(s.X1, s.Y1, s.X2, (o.Y1 - 1));
      s.Y1 := o.Y1;
    end;
    if (s.Y2 > o.Y2) then
    begin
      SetLength(list, (list.Length + 1));
      list[High(list)] := Box(s.X1, (o.Y2 + 1), s.X2, s.Y2);
      s.Y2 := o.Y2;
    end;
    if (s.X1 < o.X1) then
    begin
      SetLength(list, (list.Length + 1));
      list[High(list)] := Box(s.X1, s.Y1, (o.X1 - 1), s.Y2);
    end;
    if (s.X2 > o.X2) then
    begin
      SetLength(list, (list.Length + 1));
      list[High(list)] := Box((o.X2 + 1), s.Y1, s.X2, s.Y2);
    end;
  end;
  procedure A(const candidate: TBox);
  var
    p, n: TBoxArray;
    k, m: Integer;
  begin
    if (candidate.Area <= 0) then
      Exit;
    SetLength(p, 1);
    p[0] := candidate;
    for k := 0 to High(d) do
    begin
      SetLength(n, 0);
      for m := 0 to High(p) do
        Z(p[m], d[k], n);
      p := n;
      if (p.Length = 0) then
        Break;
    end;
    for k := 0 to High(p) do
    begin
      SetLength(d, (d.Length + 1));
      d[High(d)] := p[k];
    end;
  end;
begin
  SetLength(d, 0);
  for i := 0 to High(Self) do
    A(Self[i]);
  t := 0;
  for i := 0 to High(d) do
    Inc(t, d[i].Area);
  SetLength(Result, t);
  l := 0;
  for i := 0 to High(d) do
    for r := d[i].Y1 to d[i].Y2 do
      for c := d[i].X1 to d[i].X2 do
        Result[l.Increase] := Point(c, r);
  Result.QuickSort(oAscending);
end;

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
  <Pointify>
  @action: Returns a TPointArray of every unique pixel covered by any TBox in Self,
           calculated via a 1D boolean occupancy grid (s) sized to Self.Bounds.
		   Each box stamps its coordinates onto the grid while dynamically tracking the unique count,
		   allowing for an exact allocation before scanning the grid to build the sorted array.
  @note: Unlike a 2D grid, this flattens indexing ((y - b.Y1) * w + (x - b.X1)) to avoid multi-dimensional array overhead
         and eliminates the need for a preliminary count pass. Allocation remains proportional to Bounds.Width * Bounds.Height,
		 making it memory-intensive if boxes are widely separated.
		 oAscending determines raster scan direction (top-left-to-bottom-right vs. bottom-right-to-top-left),
		 and c.Increase handles post-increment index assignment.
[==============================================================================}
function TBoxArrayHelper.Pointify(const oAscending: Boolean = True): TPointArray; overload;
var
  b: TBox;
  w, h, i, x, y, p, c: Integer;
  s: TBooleanArray;
begin
  if (Self.Length = 0) then
    Exit([]);
  b := Self.Bounds;
  b.Dimensions(w, h);
  SetLength(s, (w * h));
  c := 0;
  for i := 0 to High(Self) do
    for y := Self[i].Y1 to Self[i].Y2 do
      for x := Self[i].X1 to Self[i].X2 do
      begin
        p := ((y - b.Y1) * w + (x - b.X1));
        if not s[p] then
        begin
          s[p] := True;
          Inc(c);
        end;
      end;
  SetLength(Result, c);
  c := 0;
  case oAscending of
    True:
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if s[(y * w) + x] then
          Result[c.Increase] := Point(x + b.X1, y + b.Y1);
    False:
    for y := (h - 1) downto 0 do
      for x := (w - 1) downto 0 do
        if s[(y * w) + x] then
          Result[c.Increase] := Point((x + b.X1), (y + b.Y1));
  end;
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

{==============================================================================]
  <ToPoints>
  @action: Converts an array of boxes into a single array containing all grid points bounded by those boxes, sorted with all duplicate points removed.
  @note: Points from overlapping boxes are deduplicated after sorting. The oAscending parameter determines the sort direction (True for ascending, False for descending).
[==============================================================================}
function TBoxArrayHelper.ToPoints(const oAscending: Boolean = True): TPointArray; overload;
var
  a, i, r, c, s: Integer;
begin
  s := 0;
  for i := 0 to High(Self) do
  begin
    a := Self[i].Area;
    SetLength(Result, s.Increment(a));
    for r := Self[i].Y2 downto Self[i].Y1 do
      for c := Self[i].X2 downto Self[i].X1 do
        Result[s - a.Decrease] := Point(c, r);
  end;
  Result.QuickSort(oAscending);
  s := 0;
  for i := 1 to High(Result) do
    if ((Result[s].X <> Result[i].X) or (Result[s].Y <> Result[i].Y)) then
      Result[s.Increment] := Result[i];
  SetLength(Result, (s + 1));
end;
{$ENDIF}
