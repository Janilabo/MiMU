{$IFDEF METHODS}
function IDs: TIntegerArray; overload;
function IDs(const p: TPoint): Integer; overload;
function IDs(const p: TPointArray): TIntegerArray; overload;
function Index(const p: TPoint): Integer; overload;
function Indexed: T2DIntegerArray; overload;
function Indexes: TIntegerArray; overload;
function IndexList: TIntegerArray; overload;
function IndexOf(const p: TPoint): Integer; overload;
function ToIndex(const p: TPoint): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IDs>
  @action: Returns TBox indexes as TIntegerArray
  @note: None.
[==============================================================================}
function TBox.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox index with TPoint p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPoint): Integer; overload;
begin
  if not Self.Contains(p) then
    Exit(-1);
  Result := (((p.Y - Self.Y1) * Self.Width) + (p.X - Self.X1));
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox indexes with TPointArray p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPointArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(p));
  for i := 0 to High(p) do
    Result[i] := Self.IDs(p[i]);
end;

{==============================================================================]
  <Index>
  @action: Returns index of point in the flattened box array.
  @note: Returns -1 if point not in box.
[==============================================================================}
function TBox.Index(const p: TPoint): Integer; overload;
begin
  if Self.Contains(p) then
    Result := (((p.Y - Self.Y1) * Self.Width) + (p.X - Self.X1))
  else
    Result := -1;
end;

{==============================================================================]
  <Indexed>
  @action: A 2D array (T2DIntegerArray) representing the box, with each element
           containing its sequential linear index.
  @details:
    - Generates a two-dimensional integer array sized [Height x Width] of the box.
    - Fills the array in row-major order (rows first, then columns).
    - Each element is a sequential index, starting from 0.
    - Uses the helper r.Increase to increment the counter automatically.
    - Useful for mapping points in the box to linear indexes or for 2D lookup tables.
  @note:
    - The size of Result is automatically determined by the box's Width and Height.
    - Row index corresponds to Y coordinate (0..Height-1).
    - Column index corresponds to X coordinate (0..Width-1).
[==============================================================================}
function TBox.Indexed: T2DIntegerArray; overload;
var
  r, w, h, i, j: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  SetLength(Result, h, w);
  r := 0;
  for i := 0 to (h - 1) do
    for j := 0 to (w - 1) do
      Result[i][j] := r.Increase;
end;

{==============================================================================]
  <Indexes>
  @action: An array of indexes corresponding to all points in the box.
  @details:
    - Iterates over the 2D rectangular bounds of the box (from X1,Y1 to X2,Y2).
    - Each index in the result array corresponds to the linear position in the box,
      using a row-major order (rows first, then columns).
    - Uses the custom helper r.Increase to increment the index counter.
    - The length of the result array is equal to the box's Area (number of points).
[==============================================================================}
function TBox.Indexes: TIntegerArray; overload;
var
  r, h, v: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
      Result[r] := r.Increment;
end;

{==============================================================================]
  <IndexList>
  @action: An array of integer indexes corresponding to all points in the box.
    - Iterates over the 2D bounds of the box (from X1,Y1 to X2,Y2) in row-major order.
    - Uses a dynamic list (`TList<Integer>`) to accumulate indexes.
    - Each index is sequential, starting from 0, representing the position of the point in the box.
    - Converts the list to a fixed-length array (`TIntegerArray`) before returning.
    - Does not require knowing the Area in advance, unlike the `Indexes` method.
  @note: Slightly less efficient than pre-allocating an array (like `Indexes`), because of dynamic list growth.
[==============================================================================}
function TBox.IndexList: TIntegerArray; overload;
var
  l: specialize TList<Integer>;
  h, v: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    for v := Self.Y1 to Self.Y2 do
      for h := Self.X1 to Self.X2 do
        l.Add(l.Count);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <IndexOf>
  @action: Returns the linear index of a point within the box's row-major order.
  @param p: The point to locate within the box.
  @return: Zero-based index if point is inside the box; -1 otherwise.
  @note: Uses linear search (O(n)) - suitable for small boxes or when index is
        rarely needed. For frequent lookups, consider the direct calculation
        approach which is O(1).
[==============================================================================}
function TBox.IndexOf(const p: TPoint): Integer; overload;
var
  h, v: Integer;
begin
  if not Self.Contains(p) then
    Exit(-1);
  Result := 0;
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
      if ((h = p.X) and (v = p.Y)) then
        Exit
      else
        Inc(Result);
end;

{==============================================================================]
  <ToIndex>
  @action: Reduces a 2D spatial TPoint back into its row-major flat 1D index
           relative to the box's origin.
  @note:
    - The inverse of 'At(pID)'/'Access(pID)'. No bounds validation — the
      point-in, index-out mirror image of the fast 'At' variant.
[==============================================================================}
function TBox.ToIndex(const p: TPoint): Integer; overload;
begin
  Result := (((p.Y - Self.Y1) * Self.Width) + (p.X - Self.X1));
end;
{$ENDIF}
