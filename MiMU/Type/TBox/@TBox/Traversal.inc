{$IFDEF METHODS}
function Columnwise: TPointArray;
function Rowwise: TPointArray;
function Spiral: TPointArray;
function Traverse: TPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Columnwise>
  @action: Returns all TBox TPoints as Column-wise.
  @note: None.
[==============================================================================}
function TBox.Columnwise: TPointArray;
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
  <Rowwise>
  @action: Returns all TBox TPoints as Row-wise.
  @note: None.
[==============================================================================}
function TBox.Rowwise: TPointArray;
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
function TBox.Spiral: TPointArray;
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
function TBox.Traverse: TPointArray;
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
