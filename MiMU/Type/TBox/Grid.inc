{$IFDEF METHODS}
function Column(const index: Integer): TPointArray; overload; cdecl;
function Column: T2DPointArray; overload; cdecl;
function Columns: Integer; overload; cdecl;
function Columns(const index: Integer): TPointArray; overload; cdecl;
function Row(const index: Integer): TPointArray; overload; cdecl;
function Row: T2DPointArray; overload; cdecl;
function Rows: Integer; overload; cdecl;
function Rows(const index: Integer): TPointArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Column>
  @action: Returns all points in the specified column (top-to-bottom)
  @note: 'index' is zero-based relative to the left edge (X1)
[==============================================================================}
function TBox.Column(const index: Integer): TPointArray; overload; cdecl;
var
  i: Integer;
  p: PPoint;
begin
  if ((index < 0) or (index >= Self.Width)) then
    Exit([]);
  SetLength(Result, Self.Height);
  p := PPoint(Result);
  for i := 0 to (Self.Height - 1) do
  begin
    p^.X := (Self.X1 + index);
    p^.Y := (Self.Y1 + i);
    Inc(p);
  end;
end;

{==============================================================================]
  <Column>
  @action: Returns TBox as its columns of TPoints.
  @note: Column-major. Dimensions = [Width][Height].
[==============================================================================}
function TBox.Column: T2DPointArray; overload; cdecl;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Width, Self.Height);
  for x := Self.X1 to Self.X2 do
    for y := Self.Y1 to Self.Y2 do
      Result[x - Self.X1][y - Self.Y1] := Point(x, y);
end;

{==============================================================================]
  <Columns>
  @action: Returns the number of columns in the box (width)
  @note: Zero-based column indexing is from left (X1) to right (X2)
[==============================================================================}
function TBox.Columns: Integer; overload; cdecl;
begin
  Result := (Self.Width);
end;

{==============================================================================]
  <Columns>
  @action: Returns all points in the specified column of the box, top-to-bottom.
  @note: 'index' is zero-based relative to the left edge (X1). Returns [] if index is out of bounds.
[==============================================================================}
function TBox.Columns(const index: Integer): TPointArray; overload; cdecl;
var
  i: Integer;
begin
  if ((index < 0) or not (index < Self.Width)) then
    Exit([]);
  SetLength(Result, Self.Height);
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X1 + index), (Self.Y1 + i));
end;

{==============================================================================]
  <Row>
  @action: Returns all points in the specified row (left-to-right)
  @note: 'index' is zero-based relative to the top edge (Y1)
[==============================================================================}
function TBox.Row(const index: Integer): TPointArray; overload; cdecl;
var
  i: Integer;
  p: PPoint;
begin
  if ((index < 0) or (index >= Self.Height)) then
    Exit([]);
  SetLength(Result, Self.Width);
  p := PPoint(Result);
  for i := 0 to (Self.Width - 1) do
  begin
    p^.X := (Self.X1 + i);
    p^.Y := (Self.Y1 + index);
    Inc(p);
  end;
end;

{==============================================================================]
  <Row>
  @action: Returns TBox as its rows of TPoints.
  @note: Row-major. Dimensions = [Height][Width].
[==============================================================================}
function TBox.Row: T2DPointArray; overload; cdecl;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Height, Self.Width);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result[y - Self.Y1][x - Self.X1] := Point(x, y);
end;

{==============================================================================]
  <Rows>
  @action: Returns the number of rows in the box (height)
  @note: Zero-based row indexing is from top (Y1) to bottom (Y2)
[==============================================================================}
function TBox.Rows: Integer; overload; cdecl;
begin
  Result := (Self.Height);
end;

{==============================================================================]
  <Row>
  @action: Returns all points in the specified row of the box, left-to-right.
  @note: 'index' is zero-based relative to the top edge (Y1). Returns [] if index is out of bounds.
[==============================================================================}
function TBox.Rows(const index: Integer): TPointArray; overload; cdecl;
var
  i: Integer;
begin
  if ((index < 0) or not (index < Self.Height)) then
    Exit([]);
  SetLength(Result, Self.Width);
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X1 + i), (Self.Y1 + index));
end;
{$ENDIF}