{$IFDEF METHODS}
function All: TPointArray; overload;
function All(var target: TPointArray): Integer; overload;
function Allness: TPointArray; overload;
function Atomize: TPointArray; overload;
function Breakdown: TPointArray; overload;
function Content: TPointArray; overload;
function Contents: TPointArray; overload;
function Decompose: TPointArray; overload;
function Decomposed: TPointArray; overload;
function Elemented: TPointArray; overload;
function Elements: TPointArray; overload;
function Enum: TPointArray; overload;
function Enumerate: TPointArray; overload;
function Enumerated: TPointArray; overload;
function Explode: TPointArray; overload;
function Exploded: TPointArray; overload;
function Extract: TPointArray; overload;
function Filled: TPointArray; overload;
function Flat: TPointArray; overload;
function Flatten: TPointArray; overload;
function Generate: TPointArray; overload;
function List: TPointArray; overload;
function Material: TPointArray; overload;
function Materialize: TPointArray; overload;
function Materialized: TPointArray; overload;
function Pixeled: TPointArray; overload;
function Pixels: TPointArray; overload;
function Pixels(const pIndex: Integer): TPoint; overload;
function Pointalize: TPointArray; overload;
function Pointify: TPointArray; overload;
function Points: TPointArray; overload;
function Points(const pIndex: Integer): TPoint; overload;
function Points(const pIDs: TIntegerArray): TPointArray; overload;
function Points(var xArray, yArray: TIntegerArray): Integer; overload;
function Pts: TPointArray; overload;
function Release: TPointArray; overload;
function Stack: TPointArray; overload;
function ToPoints: TPointArray; overload;
function TPA: TPointArray; overload;
function TPA(const pIndex: Integer): TPoint; overload;
function Unbox: TPointArray; overload;
function Unboxed: TPointArray; overload;
function Unpack: TPointArray; overload;
function Unzip(var bX1, bY1, bX2, bY2: Integer): Integer; overload;	
function Unzip: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <All>
  @action: Returns ALL points of TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.All: TPointArray; overload;
var
  h, v: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Area);
  p := PPoint(Result);
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
    begin
      p^ := Point(h, v);
      Inc(p);
    end;
end;

{==============================================================================]
  <All>
  @action: Populates the provided TPointArray with every coordinate in the box.
  @note: Returns the total count of points (Area). If the target array size 
         does not match the box area, it is automatically resized. Uses 
         pointer arithmetic for optimal performance.
[==============================================================================}
function TBox.All(var target: TPointArray): Integer; overload;
var
  h, v: Integer;
  p: PPoint;
begin
  Result := Self.Area;
  if (target.Length <> Result) then
    SetLength(target, Result);
  p := PPoint(target);
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
    begin
      p^ := Point(h, v);
      Inc(p);
    end;
end;

{==============================================================================]
  <Allnesss>
  @action: Populates a TPointArray with all coordinate points contained within the TBox.
  @note: Allocates memory based on width and height, then iterates from top-left (X1, Y1) to bottom-right (X2, Y2) using a sequential row-major calculation.
[==============================================================================}
function TBox.Allness: TPointArray; overload;
const
  CHUNK_SIZE = 1024;
var
  w, s, j, i, r, c: Integer;
function Below(const val: Integer; const aTarget, bTarget: Integer): Boolean;
begin
  Result := ((val < aTarget) and (val < bTarget));
end;
begin
  w := Self.Width;
  s := (w * Self.Height);
  SetLength(Result, s);
  for j := 0 to ((((s + CHUNK_SIZE) - 1) div CHUNK_SIZE) - 1) do
  begin
    i := ((j * CHUNK_SIZE) - 1);
    while Below(i.Increment, ((j + 1) * CHUNK_SIZE), s) do
      Result[i] := Point((Self.X1 + (i mod w)), (Self.Y1 + (i div w)));
  end;
end;

{==============================================================================]
  <Atomize>
  @action: Expands the rectangle defined by (X1,Y1)-(X2,Y2) into a dense array
           containing every integer grid coordinate within the box (inclusive
           bounds). Points are written in row-major order using precomputed
           row offsets for direct index addressing.
  @note:
    • The resulting array length is determined by Self.Size(w, o).
      The method is expected to return total element count and assign
      the box width to "w" (height or auxiliary value to "o", if used).
    • Enumeration order:
        (X1,Y1) → (X2,Y1),
        (X1,Y2) → (X2,Y2), etc.
    • Index calculation:
        rowOffset = (y - Y1) * width
        index     = rowOffset + (x - X1)
    • No bounds validation is performed (assumes X1 ≤ X2 and Y1 ≤ Y2).
    • Memory allocation is proportional to the box area.
    • Direct index computation avoids incremental counters and
      branch-based wrap logic.
[==============================================================================}
function TBox.Atomize: TPointArray; overload;
var
  h, v, w, o: Integer;
begin
  SetLength(Result, Self.Size(w, o));
  for v := Self.Y1 to Self.Y2 do
  begin
    o := ((v - Self.Y1) * w);
    for h := Self.X1 to Self.X2 do
      Result[o + (h - Self.X1)] := Point(h, v);
  end;
end;

{==============================================================================]
  <Breakdown>
  @action: Expands the rectangle defined by (X1,Y1)-(X2,Y2) into a dense array
           containing every integer grid coordinate within the box (inclusive
           bounds). Points are emitted in row-major order, iterating Y from Y1
           to Y2 and, for each row, X from X1 to X2.
  @note:
    • The resulting array length equals Self.Area.
    • Enumeration order:
        (X1,Y1) → (X2,Y1),
        (X1,Y2) → (X2,Y2), etc.
    • Uses increment helper methods (Increment / Increase) for loop
      progression and index advancement.
    • Bounds are assumed valid (X1 ≤ X2 and Y1 ≤ Y2).
    • No range or consistency validation is performed.
    • Memory allocation is proportional to the box area.
[==============================================================================}
function TBox.Breakdown: TPointArray; overload;
var
  h, v, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for v := Self.Y1 to Self.Y2 do
  begin
    h := (Self.X1 - 1);
    while (h.Increment <= Self.X2) do
      Result[r.Increase] := Point(h, v);
  end;
end;

{==============================================================================]
  <Content>
  @action: Returns TBox points as TPointArray.
  @note: Fast, Pointer-based alternative single loop version.
[==============================================================================}
function TBox.Content: TPointArray; overload;
var
  w, i: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Size(w, i));
  if Result.Empty then
    Exit;
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^.X := (Self.X1 + (i mod w));
    p^.Y := (Self.Y1 + (i div w));
    Inc(p);
  end;
end;

{==============================================================================]
  <Contents>
  @action: Returns TBox points as TPointArray.
  @note: Fast, Pointer-based alternative. Double loop version.
[==============================================================================}
function TBox.Contents: TPointArray; overload;
var
  p: PPoint;
  h, v: Integer;
begin
  SetLength(Result, Self.Area);
  p := @Result[0];
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
    begin
      p^.X := h;
      p^.Y := v;
      Inc(p);
    end;
end;

{==============================================================================]
  <Decompose>
  @action: Expands the rectangle defined by (X1,Y1)-(X2,Y2) into a dense array
           containing every integer grid coordinate within the box (inclusive
           bounds). Points are emitted in row-major order, starting at (X1,Y1),
           incrementing X toward X2, then wrapping to X1 and incrementing Y.
  @note:
    • The resulting array length equals TBox_Area(Self).
    • Enumeration order:
        (X1,Y1) → (X2,Y1),
        (X1,Y2) → (X2,Y2), etc.
    • Bounds are assumed valid (X1 ≤ X2 and Y1 ≤ Y2).
    • No range validation is performed.
    • Memory allocation is proportional to box area.
[==============================================================================}
function TBox.Decompose: TPointArray; overload;
label
  sLoop, eLoop;
var
  a, i: Integer;
  v: TPoint;
begin
  a := Self.Area;
  SetLength(Result, a);
  i := 0;
  v := Point(Self.X1, Self.Y1);
  sLoop:
  if (i >= a) then
    goto eLoop;
  Result[i] := v;
  if (v.X = Self.X2) then
    v := Point(Self.X1, (v.Y + 1))
  else
    v.X := (v.X + 1);
  Inc(i);
  goto sLoop;
  eLoop:
end;

{==============================================================================]
  <Decomposed>
  @action: Flattens the TBox into a TPointArray using manual jump labels.
  @note: Implements coordinate traversal using 'goto' statements instead of 
         standard loop constructs. Iterates X within Y (row-major order) 
         until the boundary conditions are met.
[==============================================================================}
function TBox.Decomposed: TPointArray; overload;
label
  loop, done;
var
  h, v, i: Integer;
begin
  SetLength(Result, Self.Area);
  v := Self.Y1;
  h := Self.X1;
  i := 0;
  loop:
  if (v > Self.Y2) then
    goto done;
  if (h > Self.X2) then
  begin
    h := Self.X1;
    Inc(v);
    goto loop;
  end;
  Result[i.Increase] := Point(h.Increase, v);
  goto loop;
  done:
end;

{==============================================================================]
  <Elemented>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Elemented: TPointArray; overload;
var
  h, v: Integer;
  r: TPointArray;
begin
  Result := [];
  for v := Self.Y1 to Self.Y2 do
  begin
    r := [];
    for h := Self.X1 to Self.X2 do
      r := (r + [Point(h, v)]);
    Result := (Result + r);
  end;
end;

{==============================================================================]
  <Elements>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Elements: TPointArray; overload;
var
  h, v: Integer;
begin
  SetLength(Result, 0);
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
      Result := (Result + [Point(h, v)]);
end;

{==============================================================================]
  <Enum>
  @action: Returns all points of the box as TPointArray using the built-in enumerator.
  @note: Requires TBox.GetEnumerator to be implemented.
        Uses the for-in syntax which is readable and safe.
        Performance is slightly slower than pointer-based methods due to enumerator overhead.
[==============================================================================}
function TBox.Enum: TPointArray; overload;
var
  p: TPoint;
  i: Integer;
begin
  SetLength(Result, Self.Area);
  i := 0;
  for p in Self do
    Result[i.Increase] := p;
end;

{==============================================================================]
  <Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TBox.Enumerate: TPointArray; overload;
var
  i: Integer;
  e: TBoxEnumerator;
begin
  SetLength(Result, Self.Area);
  e := GetEnumerator;
  i := 0;
  while e.MoveNext do
    Result[i.Increase] := e.Current;
end;

{==============================================================================]
  <Enumerated>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TBox.Enumerated: TPointArray; overload;
var
  i: Integer;
  e: TBoxEnumerator;
begin
  SetLength(Result, Self.Area);
  e := GetEnumerator;
  for i := 0 to High(Result) do
    if e.MoveNext then
      Result[i] := e.Current;
end;

{==============================================================================]
  <Explode>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Explode: TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  Result[0] := Point(Self.X1, Self.Y1);
  for i := 1 to High(Result) do
    if ((Result[i - 1].X + 1) > Self.X2) then
      Result[i] := Point(Self.X1, (Result[i - 1].Y + 1))
    else
      Result[i] := Point((Result[i - 1].X + 1), Result[i - 1].Y);
end;

{==============================================================================]
  <Exploded>
  @action: Generates a TPointArray of the box using memory block copying.
  @note: Highly efficient for wide boxes; it generates a template row of X 
         coordinates and uses Move() to clone them across the Y-axis before 
         applying the vertical offsets.
[==============================================================================}
function TBox.Exploded: TPointArray; overload;
var
  a, b, w, h, r, s: Integer;
  t: TPointArray;
begin
  w := Self.Width;
  h := Self.Height;
  s := SizeOf(TPoint);
  SetLength(Result, (w * h));
  SetLength(t, w);
  for a := 0 to (w - 1) do
    t[a] := Point((Self.X1 + a), 0);
  for b := 0 to (h - 1) do
  begin
    r := (b * w);
    Move(t[0], Result[r], (w * s));
    for a := 0 to (w - 1) do
      Result[r + a].Y := (Self.Y1 + b);
  end;
end;

{==============================================================================]
  <Extract>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method for Points(), TPA() and Contents().
[==============================================================================}
function TBox.Extract: TPointArray; overload;
var
  h, v, i: Integer;
begin
  SetLength(Result, Self.Area);
  i := 0;
  v := Self.Y1;
  repeat
    h := Self.X1;
    repeat
      Result[i.Increase] := Point(h, v);
    until (h.Increment > Self.X2);
  until (v.Increment > Self.Y2);
end;

{==============================================================================]
  <Filled>
  @action: ?
  @note: ?
[==============================================================================}
function TBox.Filled: TPointArray; overload;
var
  w, h, i: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  SetLength(Result, (w * h));
  FillChar(Result[0], (Result.Length * SizeOf(TPoint)), 0); 
  for i := 0 to High(Result) do
  begin
    Result[i].X := (Self.X1 + (i mod w));
    Result[i].Y := (Self.Y1 + (i div w));
  end;
end;

{==============================================================================]
  <Flat>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Flat: TPointArray; overload;
var
  i: Integer;
  p: TPoint;
begin
  SetLength(Result, Self.Area);
  p := Point(Self.X1, Self.Y1);
  for i := 0 to High(Result) do
  begin
    Result[i] := p;
    if (p.X < Self.X2) then
      Inc(p.X)
    else
      p := Point(Self.X1, (p.Y + 1));
  end;
end;

{==============================================================================]
  <Flatten>
  @action: Returns a linear array containing all discrete points within the
           box, flattened from its two-dimensional extent.
  @note: The box is first expressed in a local (zero-based) frame, then
         enumerated in row-major order (Y outer, X inner). The resulting
         points are translated back to the box’s original coordinate space.
         The array length equals the discrete area of the box.
[==============================================================================}
function TBox.Flatten: TPointArray; overload;
var
  B: TBox;
  h, v, i: Integer;
begin
  B := Self.Blanco;
  SetLength(Result, B.Area);
  i := 0;
  for v := 0 to B.Y2 do
    for h := 0 to B.X2 do
      Result[i.Increase] := Point((h + Self.X1), (v + Self.Y1));
end;

{==============================================================================]
  <Generate>
  @action: Populates a TPointArray with all coordinates within the TBox.
  @note: Uses a recursive depth-first approach to traverse the X and Y axes. 
         While functionally identical to a loop, it is subject to stack 
         limits for very large areas.
[==============================================================================}
function TBox.Generate: TPointArray; overload;
var
  i: Integer;
  procedure G(var arr: TPointArray; const x, y: Integer);
  begin
    if (y > Self.Y2) then
      Exit;
    if not (x > Self.X2) then
    begin
      arr[i.Increase] := Point(x, y);
      G(arr, (x + 1), y);
    end else
      G(arr, Self.X1, (y + 1));
  end;
begin
  SetLength(Result, Self.Area);
  i := 0;
  G(Result, Self.X1, Self.Y1);
end;

{==============================================================================]
  <List>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.List: TPointArray; overload;
var
  p: specialize TList<TPoint>;
  h, v: Integer;
begin
  p := specialize TList<TPoint>.Create;
  try
    for v := Self.Y1 to Self.Y2 do
      for h := Self.X1 to Self.X2 do
        p.Add(Point(h, v));
    Result := p.ToArray;
  finally
    p.Free;
  end;
end;

{==============================================================================]
  <Material>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Material: TPointArray; overload;
begin
  case Self.Area of
    1: Exit([Self.X1Y1]);
    2:
	if (Self.Width = 2) then
      Exit([Self.X1Y1, Self.X2Y1])
    else
      Exit([Self.X1Y1, Self.X1Y2]);
  else
    Result := Self.Materialize;
  end;
end;

{==============================================================================]
  <Materialize>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Materialize: TPointArray; overload;
var
  i, W: Integer;
begin
  W := Self.Width;
  SetLength(Result, (W * Self.Height));
  for i := 0 to High(Result) do
  begin
    Result[i].X := (Self.X1 + (i mod W));
    Result[i].Y := (Self.Y1 + (i div W));
  end;
end;

{==============================================================================]
  <Materialized>
  @action: Generates a TPointArray containing every coordinate within the box.
  @note: Highly optimized; pre-allocates the entire array at once and uses 
         pointer increments to populate data, avoiding repeated reallocations.
[==============================================================================}
function TBox.Materialized: TPointArray; overload;
var
  r, c, w, h: Integer;
  p: PPoint;
begin
  w := Self.Width;
  h := Self.Height;
  SetLength(Result, (w * h));
  p := @Result[0];
  for r := 0 to (h - 1) do
    for c := 0 to (w - 1) do
    begin
      p^.X := (Self.X1 + c);
      p^.Y := (Self.Y1 + r);
      Inc(p);
    end;
end;

{==============================================================================]
  <Pixeled>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Pixeled: TPointArray; overload;
var
  w, h, l, i: Integer;
  r: TRange;
begin
  l := Self.Area;
  SetLength(Result, l);
  w := Self.Width;
  h := (l div 2);
  r.Create(0, (l - 1));
  for i := 0 to (h - 1) do
  begin
    Result[r.start.Increase] := Point((Self.X1 + (i mod w)), (Self.Y1 + (i div w)));
    Result[r.stop.Decrease] := Point((Self.X1 + (((l - 1) - i) mod w)), (Self.Y1 + (((l - 1) - i) div w)));
  end;
  if l.Odd then
    Result[h] := Point((Self.X1 + (h mod w)), (Self.Y1 + (h div w)));
end;

{==============================================================================]
  <Pixels>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Pixels: TPointArray; overload;
var
  w, h, s, r, c, i: Integer;
  p: TPointArray;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(p, w);
  for c := 0 to (w - 1) do
    p[c].X := (Self.X1 + c);
  s := (w * SizeOf(TPoint));
  i := 0;
  for r := Self.Y1 to Self.Y2 do
  begin
    for c := 0 to (w - 1) do
      p[c].Y := r;
    Move(p[0], Result[i.Increase(w)], s);
  end;
end;

function TBox.Pixels(const pIndex: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + (pIndex mod Self.Width)), (Self.Y1 + (pIndex div Self.Width)));
end;

{==============================================================================]
  <Pointalize>
  @action: Populates a TPointArray with all coordinate points contained within the TBox.
  @note: Allocates memory based on width and height, then iterates from top-left (X1, Y1) to bottom-right (X2, Y2) using a sequential row-major calculation.
[==============================================================================}
function TBox.Pointalize: TPointArray; overload;
var
  w, h, r, c: Integer;
  b: TPoint;
begin
  w := Self.Width;
  h := Self.Height;
  SetLength(Result, (w * h));
  b := Self.X1Y1;
  r := -1;
  while (r.Increment < h) do
    for c := 0 to (w - 1) do
      Result[(r * w) + c] := Point((b.X + c), (b.Y + r));
end;

{==============================================================================]
  <Pointify>
  @action: Converts the TBox into a 1D TPointArray by first constructing a 2D grid representation of the coordinates.
  @note: Allocates a dynamic 2D array (T2DPointArray) matching the box dimensions,
         populates it from top-left to bottom-right, and then flattens it row-by-row into the final result array via concatenation.
[==============================================================================}
function TBox.Pointify: TPointArray; overload;
var
  p: T2DPointArray;
  r, c, w: Integer;
begin
  w := Self.Width;
  SetLength(p, Self.Height, w);
  for r := 0 to (Self.Height - 1) do
    for c := 0 to (w - 1) do
      p[r][c] := Point((Self.X1 + c), (Self.Y1 + r));
  Result := [];
  for r := 0 to High(p) do
    Result := (Result + p[r]);
end;

{==============================================================================]
  <Points>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Points: TPointArray; overload;
var
  h, v, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
      Result[r.Increase].Create(h, v);
end;

{==============================================================================]
  <Points>
  @action: Returns TBox point with index (pIndex).
  @note: None.
[==============================================================================}
function TBox.Points(const pIndex: Integer): TPoint; overload;
begin
  if not InRange(pIndex, 0, (Self.Area - 1)) then
    Exit(Result.Create(-2147483648));
  Result := Point((Self.X1 + (pIndex mod Self.Width)), (Self.Y1 + (pIndex div Self.Width)));
end;

{==============================================================================]
  <Points>
  @action: Returns TBox points with indexes (pIDs).
  @note: None.
[==============================================================================}
function TBox.Points(const pIDs: TIntegerArray): TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(pIDs));
  for i := 0 to High(pIDs) do
    Result[i] := Self.Points(pIDs[i]);
end;

{==============================================================================]
  <Points>
  @action: Stores TBox points to xArray and yArray.
  @note: Returns area (length of TPointArray in box)
[==============================================================================}
function TBox.Points(var xArray, yArray: TIntegerArray): Integer; overload;
var
  i, w: Integer;
begin
  w := Self.Width;
  Result := (w * Self.Height);
  SetLength(xArray, Result);
  SetLength(yArray, Result);
  for i := 0 to (Result - 1) do
  begin
    xArray[i] := (Self.X1 + (i mod w));
    yArray[i] := (Self.Y1 + (i div w));
  end;
end;

{==============================================================================]
  <Pts>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Pts: TPointArray; overload;
var
  r, c, w, h: Integer;
begin
  Self.Size(w, h);
  SetLength(Result, (w * h));
  for r := 0 to (h - 1) do
    for c := 0 to (w - 1) do
      Result[(r * w) + c] := Point((Self.X1 + c), (Self.Y1 + r));
end;

{==============================================================================]
  <Release>
  @action: Flattens the TBox area into a linear TPointArray (TPA).
  @note: Iterates through the box row-by-row (Y-major order), appending 
         each horizontal line of points to the final result array.
[==============================================================================}
function TBox.Release: TPointArray; overload;
var
  h, v: Integer;
  r: TPointArray;
begin
  SetLength(Result, 0);
  SetLength(r, Self.Width);
  for v := Self.Y1 to Self.Y2 do
  begin
    for h := Self.X1 to Self.X2 do
      r[h - Self.X1] := Point(h, v);
    Result := (Result + r);
  end;
end;

{==============================================================================]
  <Stack>
  @action: Populates a TPointArray with all coordinate points within the TBox using an intermediate stack structure.
  @note: Leverages a specialized generic TStack to temporarily hold the generated points in top-left to bottom-right order
         before converting the collection into the final result array.
[==============================================================================}
function TBox.Stack: TPointArray; overload;
var
  s: specialize TStack<TPoint>;
  r, c: Integer;
begin
  s := specialize TStack<TPoint>.Create;
  try
    s.Capacity := Self.Area;
    for r := Self.Y1 to Self.Y2 do
      for c := Self.X1 to Self.X2 do
        s.Push(Point(c, r));
    Result := s.ToArray;
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <ToPoints>
  @action: Converts the TBox bounds into an array of all TPoint coordinates it contains.
  @note: Populates the array in reverse order (bottom-right to top-left) using a pre-allocated result array.
[==============================================================================}
function TBox.ToPoints: TPointArray; overload;
var
  r, c, i: Integer;
begin
  i := Result.SetSize(Self.Area);
  for r := Self.Y2 downto Self.Y1 do
    for c := Self.X2 downto Self.X1 do
	  Result[i.Decrement] := Point(c, r);
end;

{==============================================================================]
  <TPA>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.TPA: TPointArray; overload;
var
  i, j: Integer;
begin
  SetLength(Result, Self.Size(j, i));
  for i := 0 to High(Result) do
    Result[i].Create((Self.X1 + (i mod j)), (Self.Y1 + (i div j)));
end;

function TBox.TPA(const pIndex: Integer): TPoint; overload;
var
  h, v: Integer;
begin
  v := (pIndex div Self.Width);
  h := (pIndex - (v * Self.Width));
  Result := Point((Self.X1 + h), (Self.Y1 + v));
end;

{==============================================================================]
  <Unpack>
  @action: Unpacks TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unbox: TPointArray; overload;
var
  w, h, i, j: Integer;
  s: TPointArray;
  p, r: PPoint;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(s, w);
  r := @s[0];
  p := r;
  for i := 0 to (w - 1) do
  begin
    p^.X := (Self.X1 + i);
    p^.Y := Self.Y1;
    Inc(p);
  end;
  P := @Result[0];
  for j := 0 to (h - 1) do
  begin
    Move(s[0], p^, (w * SizeOf(TPoint)));
    r := p;
    for i := 0 to (w - 1) do
    begin
      r^.Y := (Self.Y1 + j);
      Inc(r);
    end;
    Inc(p, w);
  end;
end;

{==============================================================================]
  <Unboxed>
  @action: Converts the TBox region into an array of TPoint structures containing every coordinate point inside the box.
  @note: None.
[==============================================================================}
function TBox.Unboxed: TPointArray; overload;
var
  h, v, r: Integer;
begin
  r := Result.SetSize(Self.Area);
  v := (Self.Y2 + 1);
  while (v.Decrement >= Self.Y1) do
  begin
    h := (Self.X2 + 1);
    while (h.Decrement >= Self.X1) do
      Result[r.Decrement] := Point(h, v);
  end;
end;

{==============================================================================]
  <Unpack>
  @action: Unpacks TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unpack: TPointArray; overload;
var
  r: TPointArray;
  w, h, l, i, j: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for i := 0 to (w - 1) do
    r[i] := Point((Self.X1 + i), 0);
  SetLength(Result, l);
  p := @Result[0];
  for j := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    Inc(s, w);
    while (p <> s) do
    begin
      p^.Y := j;
      Inc(p);
    end;
  end;
end;

{==============================================================================]
  <Unzip>
  @action: Unzips TBox X1, Y1, X2, Y2 and returns the area.
  @note: None.
[==============================================================================}
function TBox.Unzip(var bX1, bY1, bX2, bY2: Integer): Integer; overload;
begin
  bX1 := Self.X1;
  bY1 := Self.Y1;
  bX2 := Self.X2;
  bY2 := Self.Y2;
  Result := Self.Area;
end;

{==============================================================================]
  <Unzip>
  @action: Unzips TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unzip: TPointArray; overload;
var
  r: TPointArray;
  w, h, l, i, j: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for i := 0 to (w - 1) do
    r[i] := Point((Self.X1 + i), 0);
  SetLength(Result, l);
  p := @Result[0];
  for j := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    for i := 0 to (w - 1) do
    begin
      s^.Y := j;
      Inc(s);
    end;
    Inc(p, w);
  end;
end;
{$ENDIF}
