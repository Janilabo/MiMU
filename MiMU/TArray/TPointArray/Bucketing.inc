{$IFDEF HELPERS}
function BinBox(const bWidth, bHeight: Integer): T2DPointArray; overload;
function BinBox(const bSize: Integer = 1): T2DPointArray; overload;
function Boxified(const bWidth, bHeight: Integer): T2DPointArray; overload;
function Boxified(const bSize: Integer = 1): T2DPointArray; overload;
function Boxify(const bWidth, bHeight: Integer): T2DPointArray; overload;
function Boxify(const bSize: Integer = 1): T2DPointArray; overload;
function Bucketed(const bWidth, bHeight: Integer): T2DPointArray; overload;
function Bucketed(const bSize: Integer = 1): T2DPointArray; overload;
function Buckets(const bWidth, bHeight: Integer): T2DPointArray; overload;
function Buckets(const bSize: Integer = 1): T2DPointArray; overload;
function XBuckets(const bWidth: Integer = 1): T2DPointArray;
function YBuckets(const bHeight: Integer = 1): T2DPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinBox>
  @action: Groups all points in the array into a grid of rectangular boxes of
           size bWidth × bHeight. Uses a precomputed 2D X-index and binary
           search for fast assignment.
  @note: Boxes are arranged in row-major order: row + column * totalRows.
         Only points within the bounds of each box are included. Efficient
         for large and sparse point sets.
[==============================================================================}
function TPointArrayHelper.BinBox(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, j, r, c, p, k, l: Integer;
  a, b: TBox;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds;
  r := Ceil(b.Height / bHeight);
  c := Ceil(b.Width / bWidth);
  SetLength(Result, 0);
  SetLength(Result, (r * c));
  h := Self.XTo2D(v, z);
  for j := 0 to (c - 1) do
    for i := 0 to (r - 1) do
    begin
      p := (i + (j * r));
      a.X1 := (b.X1 + (j * bWidth));
      a.X2 := (a.X1 + (bWidth - 1));
      a.Y1 := (b.Y1 + (i * bHeight));
      a.Y2 := (a.Y1 + (bHeight - 1));
      y := v.BinaryRange(TRange.Construct(a.Y1, a.Y2));
      if not y.Employs(-1) then
      for k := y.start to y.stop do
      begin
        x := h[k].BinaryRange(TRange.Construct(a.X1, a.X2));
        if not x.Employs(-1) then
        for l := x.start to x.stop do
          Result[p].Supply(Self[z[k][l]]);
      end;
    end;
end;

{==============================================================================]
  <BinBox>
  @action: Convenience overload for square boxes. Groups points into boxes of
           size bSize × bSize by calling BinBox(bSize, bSize).
  @note: Calls the rectangular BinBox internally. Useful for uniform grids.
[==============================================================================}
function TPointArrayHelper.BinBox(const bSize: Integer = 1): T2DPointArray; overload;
begin
  Result := Self.BinBox(bSize, bSize);
end;

{==============================================================================]
  <Boxified>
  @action: Groups the points of the current array into a grid of equally sized
           square boxes of side length bSize, returning a 2D array where each
           subarray contains the points belonging to its corresponding box.
  @note: Uses direct indexing (no grid scanning) to compute each point’s
         target box based on its position relative to the bounding box.
         Boxes are arranged in row-major order.
         Empty boxes are automatically trimmed by Result.Squeeze.
         This method is faster and more memory-efficient than Boxify
         for uniformly sized square grids.
[==============================================================================}
function TPointArrayHelper.Boxified(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, r, c, w, h: Integer;
  b: TBox;
begin
  if (Self.Empty or (bSize < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  r := Ceil(h / bSize);
  c := Ceil(w / bSize);
  SetLength(Result, (r * c));
  for i := 0 to High(Self) do
    Result[(((Self[i].Y - b.Y1) div bSize) + (((Self[i].X - b.X1) div bSize) * r))].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Boxified>
  @action: Groups the points of the current array into a grid of rectangular
           boxes with dimensions bWidth × bHeight, returning a 2D array
           where each element contains the points that fall within that box.
  @note:   Computes each point’s box position directly using integer division
           based on its relative coordinates. Boxes are arranged in row-major
           order (rows first, then columns).
           The Result.Squeeze call removes any empty boxes from the final output.
           This method is the most efficient rectangular variant of Boxify.
[==============================================================================}
function TPointArrayHelper.Boxified(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, r, c, w, h: Integer;
  b: TBox;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  r := Ceil(h / bHeight);
  c := Ceil(w / bWidth);
  SetLength(Result, (r * c));
  for i := 0 to High(Self) do
    Result[(((Self[i].Y - b.Y1) div bHeight) + (((Self[i].X - b.X1) div bWidth) * r))].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Boxify>
  @action: Splits the current point array into a grid of rectangular cells
           (boxes) of the specified width and height, returning a 2D array
           of points grouped by their corresponding box.
  @note: Each box represents a bounded sub-region of the point array’s
         overall bounding box. Boxes are generated in row-major order,
         and may be smaller along the right or bottom edges if the total
         width/height is not divisible by the box size. Empty boxes
         return as empty point arrays.
[==============================================================================}
function TPointArrayHelper.Boxify(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, j, r, c, w, h, x, y, z, p: Integer;
  a, b: TBox;
  m: T2DBooleanArray;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  SetLength(Result, 0);
  r := Ceil(h / bHeight);
  c := Ceil(w / bWidth);
  SetLength(Result, (r * c));
  for i := 0 to (r - 1) do
    for j := 0 to (c - 1) do
    begin
      a := TBox.Construct((b.X1 + (j * bWidth)), (b.Y1 + (i * bHeight)), ((b.X1 + (j * bWidth)) + bWidth), ((b.Y1 + (i * bHeight)) + bHeight)).Clamp(b);
      z := 0;
      p := (i + (j * r));
      SetLength(Result[p], a.Area);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
          if m[(y - b.Y1)][(x - b.X1)] then
            Result[p][z.Increase] := Point(x, y);
      SetLength(Result[p], z);
    end;
end;

{==============================================================================]
  <Boxify>
  @action: Splits the current point array into spatial groups using a uniform
           box size (bSize). Each group contains points that fall within a
           Chebyshev distance of bSize from the box's origin point.
  @note: Creates a grid of square boxes based on the specified size,
         using the Chebyshev metric to determine point inclusion.
         Effectively partitions the bounding area into square regions
         and assigns points to their nearest box region.
         Useful for coarse spatial grouping or uniform grid segmentation
         of point data.
[==============================================================================}
function TPointArrayHelper.Boxify(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, j, r, d, c, w, h, x, y, z, p: Integer;
  a, b: TBox;
  m: T2DBooleanArray;
  g: TPoint;
begin
  if (Self.Empty or (bSize < 1)) then
    Exit([]);
  d := Ceil(bSize);
  b := Self.Bounds(w, h);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  SetLength(Result, 0);
  r := Ceil(h / bSize);
  c := Ceil(w / bSize);
  SetLength(Result, (r * c));
  for i := 0 to (r - 1) do
    for j := 0 to (c - 1) do
    begin
      a := TBox.Construct((b.X1 + (j * d)), (b.Y1 + (i * d)), (b.X1 + (j * d)) + d, (b.Y1 + (i * d)) + d).Clamp(b);
      g := Point(a.X1, a.Y1);
      z := 0;
      p := (i + (j * r));
      SetLength(Result[p], a.Area);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
          if (m[(y - b.Y1)][(x - b.X1)] and (g.Within(Point(x, y), bSize, dmChebyshev))) then
            Result[p][z.Increase] := Point(x, y);
      SetLength(Result[p], z);
    end;
end;

{==============================================================================]
  <Bucketed>
  @action: Splits the point array into a 2D grid of buckets, each containing points
           that fall within a specific rectangular region of the bounding box.
  @note: Each bucket’s dimensions are defined by (bWidth, bHeight). Empty buckets
         are removed using Squeeze. Returns an empty array if input or bounds are invalid.
[==============================================================================}
function TPointArrayHelper.Bucketed(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, w, h, x, y: Integer;
  b: TBox;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  if ((w < 1) or (h < 1)) then
    Exit([]);
  y := (((h + bHeight) - 1) div bHeight);
  x := (((w + bWidth) - 1) div bWidth);
  SetLength(Result, 0);
  SetLength(Result, (y * x));
  for i := 0 to High(Self) do
    Result[Integer((Self[i].Y - b.Y1) div bHeight).Clamp(0, (y - 1)) + (Integer((Self[i].X - b.X1) div bWidth).Clamp(0, (x - 1)) * y)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Bucketed>
  @action: Creates a 2D grid of buckets using a uniform bucket size for both width and height.
  @note: Equivalent to calling Bucketed(bSize, bSize). Returns an empty array if input or size is invalid.
[==============================================================================}
function TPointArrayHelper.Bucketed(const bSize: Integer = 1): T2DPointArray; overload;
begin
  Result := Self.Bucketed(bSize, bSize);
end;

{==============================================================================]
  <Buckets>
  @action: Divides the TPointArray into a rectangular grid of boxes of size bWidth x bHeight.
           Returns a T2DPointArray where each bucket contains all points falling
           into that box. The buckets are stored as a flattened 1D array:
           bucketIndex = col + row * numCols.
           Empty buckets are removed at the end.
  @note: - Computes the bounds of the points automatically (Self.Bounds).
         - Supports multiple points per bucket.
         - Uses arr.Supply to append points to each bucket.
         - Returns only non-empty buckets for convenience.
[==============================================================================}
function TPointArrayHelper.Buckets(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, h, v: Integer;
  b: TBox;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds;
  h := (((b.X2 - b.X1) div bWidth) + 1);
  v := (((b.Y2 - b.Y1) div bHeight) + 1);
  SetLength(Result, (h * v));
  for i := 0 to High(Self) do
    Result[((Self[i].X - b.X1) div bWidth) + (((Self[i].Y - b.Y1) div bHeight) * h)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Buckets>
  @action: Divides the TPointArray into a square grid of boxes of size bSize x bSize.
           Internally calls the same algorithm as the rectangular version.
  @note: - bSize defines both width and height of the grid cells.
         - Empty buckets are removed at the end.
[==============================================================================}
function TPointArrayHelper.Buckets(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, h, v: Integer;
  b: TBox;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds;
  h := (((b.X2 - b.X1) div bSize) + 1);
  v := (((b.Y2 - b.Y1) div bSize) + 1);
  SetLength(Result, (h * v));
  for i := 0 to High(Self) do
    Result[((Self[i].X - b.X1) div bSize) + (((Self[i].Y - b.Y1) div bSize) * h)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <XBuckets>
  @action: Groups the points in the array into buckets (columns) based on their X-coordinate.
           Each bucket contains all points whose X-value falls within the range
           [BucketIndex * bWidth .. (BucketIndex+1) * bWidth - 1].
  @note: Returns a 2D array (T2DPointArray) where each element is a bucket (array of points).
         The default bucket width is 1. Use a larger value to group points into wider columns.
[==============================================================================}
function TPointArrayHelper.XBuckets(const bWidth: Integer = 1): T2DPointArray;
var
  i, m: Integer;
begin
  m := 0;
  for i := 0 to High(Self) do
    m := Max(m, (Self[i].X div bWidth));
  SetLength(Result, (m + 1));
  for i := 0 to High(Self) do
    Result[Self[i].X div bWidth].Supply(Self[i]);
end;

{==============================================================================]
  <YBuckets>
  @action: Groups the points in the array into buckets (rows) based on their Y-coordinate.
           Each bucket contains all points whose Y-value falls within the range
           [BucketIndex * bHeight .. (BucketIndex+1) * bHeight - 1].
  @note: Returns a 2D array (T2DPointArray) where each element is a bucket (array of points).
         The default bucket height is 1. Use a larger value to group points into taller rows.
[==============================================================================}
function TPointArrayHelper.YBuckets(const bHeight: Integer = 1): T2DPointArray;
var
  i, m: Integer;
begin
  m := 0;
  for i := 0 to High(Self) do
    m := Max(m, (Self[i].Y div bHeight));
  SetLength(Result, (m + 1));
  for i := 0 to High(Self) do
    Result[Self[i].Y div bHeight].Supply(Self[i]);
end;
{$ENDIF}
