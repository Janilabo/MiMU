{$IFDEF METHODS}
function All: TPointArray; overload;
function Content: TPointArray;
function Contents: TPointArray;
function Elements: TPointArray;
function Enumerate: TPointArray;
function Enumerated: TPointArray;
function Explode: TPointArray; overload;
function Exploded: TPointArray;
function Extract: TPointArray;
function Flat: TPointArray; overload;
function List: TPointArray;
function Materialize: TPointArray;
function Pixeled: TPointArray; overload;
function Pixels: TPointArray; overload;
function Pixels(const index: Integer): TPoint; overload;
function Points: TPointArray; overload;
function Points(const pIndex: Integer): TPoint; overload;
function Points(const pIDs: TIntegerArray): TPointArray; overload;
function Points(var xArray, yArray: TIntegerArray): Integer; overload;
function Pts: TPointArray; overload;
function TPA: TPointArray; overload;
function TPA(const index: Integer): TPoint; overload;
function Unbox: TPointArray; overload;
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
  x, y: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Area);
  p := PPoint(Result);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
    begin
      p^ := Point(x, y);
      Inc(p);
    end;
end;

{==============================================================================]
  <Content>
  @action: Returns TBox points as TPointArray.
  @note: Fast, Pointer-based alternative single loop version.
[==============================================================================}
function TBox.Content: TPointArray;
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
function TBox.Contents: TPointArray;
var
  p: PPoint;
  x, y: Integer;
begin
  SetLength(Result, Self.Area);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
    begin
      p^.X := x;
      p^.Y := y;
      Inc(p);
    end;
end;

{==============================================================================]
  <Elements>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Elements: TPointArray;
var
  x, y: Integer;
begin
  SetLength(Result, 0);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result := (Result + [Point(x, y)]);
end;

{==============================================================================]
  <Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TBox.Enumerate: TPointArray;
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
function TBox.Enumerated: TPointArray;
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
  @action: Returns all points of the given box as TPointArray.
  @note: Uses the TBox enumerator (for-in).
[==============================================================================}
function TBox.Exploded: TPointArray;
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
  <Extract>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method for Points(), TPA() and Contents().
[==============================================================================}
function TBox.Extract: TPointArray;
var
  x, y, i: Integer;
begin
  SetLength(Result, Self.Area);
  i := 0;
  y := Self.Y1;
  repeat
    x := Self.X1;
    repeat
      Result[i.Increase] := Point(x, y);
    until (x.Increment > Self.X2);
  until (y.Increment > Self.Y2);
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
  <List>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.List: TPointArray;
var
  p: specialize TList<TPoint>;
  x, y: Integer;
begin
  p := specialize TList<TPoint>.Create;
  try
    for y := Self.Y1 to Self.Y2 do
      for x := Self.X1 to Self.X2 do
        p.Add(Point(x, y));
    Result := p.ToArray;
  finally
    p.Free;
  end;
end;

{==============================================================================]
  <Materialize>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Materialize: TPointArray;
var
  i, W, H: Integer;
begin
  W := ((Self.X2 - Self.X1) + 1);
  H := ((Self.Y2 - Self.Y1) + 1);
  SetLength(Result, W * H);
  for i := 0 to High(Result) do
  begin
    Result[i].X := (Self.X1 + (i mod W));
    Result[i].Y := (Self.Y1 + (i div W));
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
  w, h, s, x, y, i: Integer;
  p: TPointArray;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(p, w);
  for x := 0 to (w - 1) do
    p[x].X := (Self.X1 + x);
  s := (w * SizeOf(TPoint));
  i := 0;
  for y := Self.Y1 to Self.Y2 do
  begin
    for x := 0 to (w - 1) do
      p[x].Y := y;
    Move(p[0], Result[i.Increase(w)], s);
  end;
end;

function TBox.Pixels(const index: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + (index mod Self.Width)), (Self.Y1 + (index div Self.Width)));
end;

{==============================================================================]
  <Points>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Points: TPointArray; overload;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result[r.Increase].Create(x, y);
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
  x, y, w, h: Integer;
begin
  Self.Size(w, h);
  SetLength(Result, (w * h));
  for y := 0 to (h - 1) do
    for x := 0 to (w - 1) do
      Result[(y * w) + x] := Point((Self.X1 + x), (Self.Y1 + y));
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

function TBox.TPA(const index: Integer): TPoint; overload;
var
  x, y: Integer;
begin
  y := (index div Self.Width);
  x := (index - (y * Self.Width));
  Result := Point((Self.X1 + x), (Self.Y1 + y));
end;

{==============================================================================]
  <Unpack>
  @action: Unpacks TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unbox: TPointArray; overload;
var
  w, h: Integer;
  x, y: Integer;
  s: TPointArray;
  p, r: PPoint;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(s, w);
  r := @s[0];
  p := r;
  for x := 0 to (w - 1) do
  begin
    p^.X := (Self.X1 + x);
    p^.Y := Self.Y1;
    Inc(p);
  end;
  P := @Result[0];
  for y := 0 to (h - 1) do
  begin
    Move(s[0], p^, (w * SizeOf(TPoint)));
    r := p;
    for x := 0 to (w - 1) do
    begin
      r^.Y := (Self.Y1 + y);
      Inc(r);
    end;
    Inc(p, w);
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
  w, h, l, x, y: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for x := 0 to (w - 1) do
    r[x] := Point((Self.X1 + x), 0);
  SetLength(Result, l);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    Inc(s, w);
    while (p <> s) do
    begin
      p^.Y := y;
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
  w, h, l, x, y: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for x := 0 to (w - 1) do
    r[x] := Point((Self.X1 + x), 0);
  SetLength(Result, l);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    for x := 0 to (w - 1) do
    begin
      s^.Y := y;
      Inc(s);
    end;
    Inc(p, w);
  end;
end;
{$ENDIF}
