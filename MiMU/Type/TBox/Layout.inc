{$IFDEF HELPERS}
function AsColumn(const cells: Integer; const space: Integer = 0): TBoxArray;
function AsGrid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray;
function AsRow(const cells: Integer; const space: Integer = 0): TBoxArray;
function Gridded(const target: TBox): TBoxArray; overload;
function Tiled(const target: TBox): TBoxArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsColumn>
  @action: Outputs column of boxes. Starting from bx,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TBoxHelper.AsColumn(const cells: Integer; const space: Integer = 0): TBoxArray;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    Self.Size(w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.Y1 + (i * (h + space)));
      Result[i].Build(Self.X1, z, Self.X2, (z + (h - 1)));
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <AsGrid>
  @action: Outputs/builds grid of boxes with parameters;
           bx = starting box, used for starting coordinates and also for dimensions (width & height) of the boxes.
           rows, columns = count of rows and columns
           spaceHorizontal = space between columns
           spaceVertical = space between rows
  @note: None.
[==============================================================================}
function TBoxHelper.AsGrid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray;
var
  w, h, r, c, i, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    Self.Size(w, h);
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y1 + (r * (h + spaceVertical)));
      for c := 0 to (columns - 1) do
      begin
        i := ((r * columns) + c);
        x := (Self.X1 + (c * (w + spaceHorizontal)));
        Result[i].Build(x, y, (x + (w - 1)), (y + (h - 1)));
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <AsRow>
  @action: Outputs row of boxes. Starting from bx,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TBoxHelper.AsRow(const cells: Integer; const space: Integer = 0): TBoxArray;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    Self.Size(w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.X1 + (i * (w + space)));
      Result[i].Build(z, Self.Y1, (z + (w - 1)), Self.Y2);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Gridded>
  @action: Generate non-overlapping, grid-aligned positions of Self inside target.
  @note: Steps by Self Width and Height. Returns empty array if Self does not fit.
[==============================================================================}
function TBoxHelper.Gridded(const target: TBox): TBoxArray; overload;
var
  l, y, x, r, c, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w > target.Width) or (h > target.Height)) then
    Exit([]);
  c := (target.Width div w);
  r := (target.Height div h);
  SetLength(Result, (r * c));
  l := 0;
  for y := 0 to (r - 1) do
    for x := 0 to (c - 1) do
      Result[l.Increase].Form(Point((target.X1 + (w * x)), (target.Y1 + (h * y))), w, h);
end;

{==============================================================================]
  <Tiled>
  @action: Generate non-overlapping, grid-aligned positions of Self inside target.
  @note: Steps by Self Width and Height. Returns empty array if Self does not fit.
[==============================================================================}
function TBoxHelper.Tiled(const target: TBox): TBoxArray; overload;
var
  y, x, r, w, h: Integer;
  m: TPoint;
  f: TBox;
begin
  Self.Size(w, h);
  if ((w > target.Width) or (h > target.Height)) then
    Exit([]);
  f := Self.Frame;
  m := Point(((target.X2 - w) + 1), ((target.Y2 - h) + 1));
  SetLength(Result, ((target.Width div w) * (target.Height div h)));
  r := 0;
  y := target.Y1;
  repeat
    x := (target.X1 - w);
    while (x.Increment(w) <= m.X) do
      Result[r.Increase] := Box((f.X1 + x), (f.Y1 + y), (f.X2 + x), (f.Y2 + y));
  until (y.Increment(h) > m.Y);
end;
{$ENDIF}