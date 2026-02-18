{$IFDEF METHODS}
function IDs: TIntegerArray; overload;
function IDs(const p: TPoint): Integer; overload;
function IDs(const p: TPointArray): TIntegerArray; overload;
function Indexed: T2DIntegerArray; overload;
function Indexes: TIntegerArray; overload;
function IndexList: TIntegerArray; overload;
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
  r, w, h, x, y: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  SetLength(Result, h, w);
  r := 0;
  for y := 0 to (h - 1) do
    for x := 0 to (w - 1) do
      Result[y][x] := r.Increase;
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
  r, x, y: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
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
  x, y: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    for y := Self.Y1 to Self.Y2 do
      for x := Self.X1 to Self.X2 do
        l.Add(l.Count);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{$ENDIF}