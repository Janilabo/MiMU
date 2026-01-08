{$IFDEF METHODS}
function Columnwise: TPointArray; cdecl;
function Rowwise: TPointArray; cdecl;
function Spiral: TPointArray; cdecl;
function Traverse: TPointArray; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Columnwise>
  @action: Returns all TBox TPoints as Column-wise.
  @note: None.
[==============================================================================}
function TBox.Columnwise: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for x := X1 to X2 do
    for y := Y1 to Y2 do
      Result[r.Increase] := Point(x, y);
end;

{==============================================================================]
  <Rowwise>
  @action: Returns all TBox TPoints as Row-wise.
  @note: None.
[==============================================================================}
function TBox.Rowwise: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for y := Y1 to Y2 do
    for x := X1 to X2 do
      Result[r.Increase] := Point(x, y);
end;

{==============================================================================]
  <Spiral>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Traverse.
[==============================================================================}
function TBox.Spiral: TPointArray; cdecl;
var
  b: TBox;
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  b := Self;
  r := 0;
  repeat
    for x := b.X1 to b.X2 do
      Result[r.Increase] := Point(x, b.Y1);
    Inc(b.Y1);
    for y := b.Y1 to b.Y2 do
      Result[r.Increase] := Point(b.X2, y);
    Dec(b.X2);
    if (b.Y1 <= b.Y2) then
    begin
      for x := b.X2 downto b.X1 do
        Result[r.Increase] := Point(x, b.Y2);
      Dec(b.Y2);
    end;
    if (b.X1 <= b.X2) then
    begin
      for y := b.Y2 downto b.Y1 do
        Result[r.Increase] := Point(b.X1, y);
      Inc(b.X1);
    end;
  until ((b.X1 > b.X2) or (b.Y1 > b.Y2));
end;

{==============================================================================]
  <Traverse>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Spiral.
[==============================================================================}
function TBox.Traverse: TPointArray; cdecl;
var
  m: T2DBooleanArray;
  c: TPoint;
  z, i: Integer;
  x, y: TIntegerArray;
begin
  x := [1, 0, -1, 0];
  y := [0, 1, 0, -1];
  SetLength(Result, Self.Area);
  m := T2D.Create(False, Self.Width, Self.Height);
  c := Point(Self.X1, Self.Y1);
  z := 0;
  for i := 0 to High(Result) do
  begin
    Result[i] := c;
    m[(c.X - Self.X1), (c.Y - Self.Y1)] := True;
    if (((c.X + x[z]) < Self.X1) or ((c.X + x[z]) > Self.X2) or
       ((c.Y + y[z]) < Self.Y1) or ((c.Y + y[z]) > Self.Y2) or
       m[((c.X + x[z]) - Self.X1), ((c.Y + y[z]) - Self.Y1)]) then
      z := ((z + 1) mod 4);
    c.X := (c.x + x[z]);
    c.Y := (c.y + y[z]);
  end;
end;
{$ENDIF}