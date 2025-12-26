{$IFDEF HELPERS}
function Invert: TPointArray;
function Inverted(const arrBounds: TBox): TPointArray; overload;
function Inverted: TPointArray; overload;
function Inverse(const arrBounds: TBox): TPointArray; overload;
function Inverse: TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Invert>
  @action: Returns inverted version of arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Invert: TPointArray; 
var
  i, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if (High(Self) > 0) then
  begin
    b := Self.Bounds(w, h);
	m := T2D.Create(False, w, h);
    x := 0;
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Inc(x);
    SetLength(Result, ((w * h) - x));
    if (Result.Size > 0) then
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if not m[x][y] then
          Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Inverted>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverted(const arrBounds: TBox): TPointArray; overload; 
var
  x, y, r: Integer;
begin
  SetLength(Result, arrBounds.Area);
  r := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not Self.Contains(Point(x, y)) then
        Result[r.Increase] := Point(x, y);
  SetLength(Result, r);
end;

function TPointArrayHelper.Inverted: TPointArray; overload; 
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <Inverse>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverse(const arrBounds: TBox): TPointArray; overload; 
var
  w, h, l, i, x, y: Integer;
  b: T2DBooleanArray;
begin
  if (Self.Size < 2) then
    Exit([]);
  SetLength(Result, arrBounds.Size(w, h));
  b := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    if arrBounds.Contains(Self[i]) then
      b[Self[i].Y - arrBounds.Y1][Self[i].X - arrBounds.X1] := True;
  l := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not b[y - arrBounds.Y1][x - arrBounds.X1] then
        Result[l.Increase] := Point(x, y);
  SetLength(Result, l);
end;

function TPointArrayHelper.Inverse: TPointArray; overload; 
begin
  Result := Self.Inverse(Self.Bounds);
end;
{$ENDIF}
