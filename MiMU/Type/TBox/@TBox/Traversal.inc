{$IFDEF METHODS}
function Columnmajor: TPointArray; overload;
function Columnwise: TPointArray; overload;
function Rowmajor: TPointArray; overload;
function Rowwise: TPointArray; overload;
function Spiral: TPointArray; overload;
function Traverse: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Columnmajor>
  @action: Returns all points in column-major order: (X1,Y1) → (X1,Y2),
           (X2,Y1) → (X2,Y2), etc.
  @note: Uses pointer arithmetic for speed; order differs from row-major.
[==============================================================================}
function TBox.Columnmajor: TPointArray; overload;
var
  c, r: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Px);
  p := @Result[0];
  for c := Self.X1 to Self.X2 do
    for r := Self.Y1 to Self.Y2 do
    begin
      p^.X := c;
      p^.Y := r;
      Inc(p);
    end;
end;

{==============================================================================]
  <Columnwise>
  @action: Returns all TBox TPoints as Column-wise.
  @note: None.
[==============================================================================}
function TBox.Columnwise: TPointArray; overload;
var
  h, v, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for h := X1 to X2 do
    for v := Y1 to Y2 do
      Result[r.Increase] := Point(h, v);
end;

{==============================================================================]
  <Rowmajor>
  @action: Returns all points in row-major order: (X1,Y1) → (X2,Y1),
           (X1,Y2) → (X2,Y2), etc.
  @note: Uses pointer arithmetic for speed; matches the typical enumeration
         order of your other methods like Contents/Materialized.
[==============================================================================}
function TBox.Rowmajor: TPointArray; overload;
var
  c, r: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Px);
  p := @Result[0];
  for r := Self.Y1 to Self.Y2 do
    for c := Self.X1 to Self.X2 do
    begin
      p^.X := c;
      p^.Y := r;
      Inc(p);
    end;
end;

{==============================================================================]
  <Rowwise>
  @action: Returns all TBox TPoints as Row-wise.
  @note: None.
[==============================================================================}
function TBox.Rowwise: TPointArray; overload;
var
  h, v, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for v := Y1 to Y2 do
    for h := X1 to X2 do
      Result[r.Increase] := Point(h, v);
end;

{==============================================================================]
  <Spiral>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Traverse.
[==============================================================================}
function TBox.Spiral: TPointArray; overload;
var
  b: TBox;
  h, v, r: Integer;
begin
  SetLength(Result, Self.Area);
  b := Self;
  r := 0;
  repeat
    for h := b.X1 to b.X2 do
      Result[r.Increase] := Point(h, b.Y1);
    Inc(b.Y1);
    for v := b.Y1 to b.Y2 do
      Result[r.Increase] := Point(b.X2, v);
    Dec(b.X2);
    if (b.Y1 <= b.Y2) then
    begin
      for h := b.X2 downto b.X1 do
        Result[r.Increase] := Point(h, b.Y2);
      Dec(b.Y2);
    end;
    if (b.X1 <= b.X2) then
    begin
      for v := b.Y2 downto b.Y1 do
        Result[r.Increase] := Point(b.X1, v);
      Inc(b.X1);
    end;
  until ((b.X1 > b.X2) or (b.Y1 > b.Y2));
end;

{==============================================================================]
  <Traverse>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Spiral.
[==============================================================================}
function TBox.Traverse: TPointArray; overload;
var
  m: T2DBooleanArray;
  c: TPoint;
  z, i: Integer;
  h, v: TIntegerArray;
begin
  h := [1, 0, -1, 0];
  v := [0, 1, 0, -1];
  SetLength(Result, Self.Area);
  m := T2D.Create(False, Self.Width, Self.Height);
  c := Point(Self.X1, Self.Y1);
  z := 0;
  for i := 0 to High(Result) do
  begin
    Result[i] := c;
    m[(c.X - Self.X1), (c.Y - Self.Y1)] := True;
    if (((c.X + h[z]) < Self.X1) or ((c.X + h[z]) > Self.X2) or ((c.Y + v[z]) < Self.Y1) or ((c.Y + v[z]) > Self.Y2) or m[((c.X + h[z]) - Self.X1), ((c.Y + v[z]) - Self.Y1)]) then
      z := ((z + 1) mod 4);
    c.X := (c.x + h[z]);
    c.Y := (c.y + v[z]);
  end;
end;
{$ENDIF}
