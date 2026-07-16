{$IFDEF HELPERS}
function Column(const cells: Integer; const space: Integer = 0): TPointArray;
function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray;
function Row(const cells: Integer; const space: Integer = 0): TPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Column>
  @action: Outputs column of points. Starting from pt,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TPointHelper.Column(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create(Self.X, (Self.Y + (i * (space + 1))));
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Grid>
  @action: Outputs/builds grid of points with parameters;
           pt = starting point, used for starting coordinates.
           rows, columns = count of rows and columns
           spaceHorizontal = space between columns
           spaceVertical = space between rows
  @note: None.
[==============================================================================}
function TPointHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray;
var
  r, c, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y + (r * (spaceVertical + 1)));
      for c := 0 to (columns - 1) do
      begin
        x := (Self.X + (c * (spaceHorizontal + 1)));
		Result[(r * columns) + c].Create(x, y);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Row>
  @action: Outputs column of points. Starting from pt,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TPointHelper.Row(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create((Self.X + (i * (space + 1))), Self.Y);
  end else
    SetLength(Result, 0);
end;
{$ENDIF}