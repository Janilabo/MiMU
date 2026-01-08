{$IFDEF METHODS}
function Places(const target: TBox; const o: TPoint): TPointArray; overload; cdecl;
function Places(const target: TBox): TPointArray; overload; cdecl;
{$ENDIF}

{$IFDEF HELPERS}
function Placements(const target: TBox; const o: TPoint): TBoxArray; overload; cdecl;
function Placements(const target: TBox): TBoxArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Placements>
  @action: Generate all possible translations of Self fully contained within target.
  @note: Returns an array of boxes representing every valid placement;
         order is row-major (y first, then x). Returns empty array if no fit.
[==============================================================================}
function TBoxHelper.Placements(const target: TBox; const o: TPoint): TBoxArray; overload; cdecl;
var
  y, x, r: Integer;
  f, t: TBox;
begin
  t := Box(target.X1, target.Y1, ((target.X2 - Self.Width) + 1), ((target.Y2 - Self.Height) + 1));
  SetLength(Result, t.Area);
  if Result.Empty then
    Exit;
  r := 0;
  f := Self.Frame;
  for y := t.Y1 to t.Y2 do
    for x := t.X1 to t.X2 do
      Result[r.Increase] := Box(((f.X1 + x) + o.X), ((f.Y1 + y) + o.Y), ((f.X2 + x) + o.X), ((f.Y2 + y) + o.Y));
end;

function TBoxHelper.Placements(const target: TBox): TBoxArray; overload; cdecl;
begin
  Result := Self.Placements(target, Point(0, 0));
end;

{==============================================================================]
  <Places>
  @action: Generate all possible translations of Self fully contained within target.
  @note: Returns an array of points representing every valid place;
         order is row-major (y first, then x). Returns empty array if no fit.
[==============================================================================}
function TBox.Places(const target: TBox; const o: TPoint): TPointArray; overload; cdecl;
var
  w, h, x, y, l: Integer;
  r, c: TRange;
begin
  target.Size(w, h);
  Self.Size(x, y);
  if ((x > w) or (y > h)) then
    Exit([]);
  r.Create(0, (h - y));
  c.Create(0, (w - x));
  l := 0;
  SetLength(Result, ((r.stop + 1) * (c.stop + 1)));
  for y := r.start to r.stop do
    for x := c.start to c.stop do
      Result[l.Increase] := Point(((x + target.X1) + o.X), ((y + target.Y1) + o.Y));
end;

function TBox.Places(const target: TBox): TPointArray; overload; cdecl;
begin
  Result := Self.Places(target, Point(0, 0));
end;
{$ENDIF}