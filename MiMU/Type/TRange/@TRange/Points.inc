{$IFDEF METHODS}
function Horizontal(const Y: Integer = 0): TPointArray; overload;
function Horizontaled(const Y: Integer = 0): TPointArray; overload;
function Horizontaline(const Y: Integer = 0): TPointArray; overload;
function Horizontally(const Y: Integer = 0): TPointArray; overload;

function Vertical(const X: Integer = 0): TPointArray; overload;
function Verticaled(const X: Integer = 0): TPointArray; overload;
function Verticaline(const X: Integer = 0): TPointArray; overload;
function Vertically(const X: Integer = 0): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================
  <Horizontal>
  @action: Generates a TPointArray forming a horizontal line across the range.
  @note: Uses mathematical index scaling (start + i * direction) without temporary state mutation, holding Y constant.
[==============================================================================}
function TRange.Horizontal(const Y: Integer = 0): TPointArray; overload;
var
  i, d: Integer;
begin
  d := Self.Direction;
  for i := 0 to (Result.SetSize(Self.Size) - 1) do
    Result[i] := Point((Self.start + (i * d)), Y);
end;

{==============================================================================]
  <Horizontaled>
  @action: Generates a TPointArray forming a horizontal line across the range.
  @note: Uses vector step-direction iteration via Direction and Increase methods, holding Y constant.
[==============================================================================}
function TRange.Horizontaled(const Y: Integer = 0): TPointArray; overload;
var
  i, d, x: Integer;
begin
  d := Self.Direction;
  x := Self.start;
  for i := 0 to (Result.SetSize(Self.Size) - 1) do
    Result[i] := Point(x.Increase(d), Y);
end;

{==============================================================================]
  <Horizontaline>
  @action: Generates a TPointArray forming a horizontal line across the range.
  @note: Uses explicit directional Pascal loops (to/downto) based on Descending, holding Y constant.
[==============================================================================}
function TRange.Horizontaline(const Y: Integer = 0): TPointArray; overload;
var
  x: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for x := Self.start to Self.stop do
      Result[x - Self.start] := Point(x, Y);
    True:
    for x := Self.start downto Self.stop do
      Result[Self.start - x] := Point(x, Y);
  end;
end;

{==============================================================================]
  <Horizontally>
  @action: Generates a TPointArray forming a horizontal line across the range.
  @note: Uses direct pointer arithmetic and vector step-direction iteration, holding Y constant.
[==============================================================================}
function TRange.Horizontally(const Y: Integer = 0): TPointArray; overload;
var
  i, d, x: Integer;
  P: PPoint;
begin
  SetLength(Result, Self.Size);
  d := Self.Direction;
  x := Self.start;
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^.X := x.Increase(d);
    P^.Y := Y;
    Inc(P);
  end;
end;

{==============================================================================
  <Vertical>
  @action: Generates a TPointArray forming a vertical line across the range.
  @note: Uses mathematical index scaling (start + i * direction) without temporary state mutation, holding X constant.
[==============================================================================}
function TRange.Vertical(const X: Integer = 0): TPointArray; overload;
var
  i, d: Integer;
begin
  d := Self.Direction;
  for i := 0 to (Result.SetSize(Self.Size) - 1) do
    Result[i] := Point(X, (Self.start + (i * d)));
end;

{==============================================================================]
  <Verticaled>
  @action: Generates a TPointArray forming a vertical line across the range.
  @note: Uses vector step-direction iteration via Direction and Increase methods, holding X constant.
[==============================================================================}
function TRange.Verticaled(const X: Integer = 0): TPointArray; overload;
var
  i, d, y: Integer;
begin
  d := Self.Direction;
  y := Self.start;
  for i := 0 to (Result.SetSize(Self.Size) - 1) do
    Result[i] := Point(X, y.Increase(d));
end;

{==============================================================================]
  <Verticaline>
  @action: Generates a TPointArray forming a vertical line across the range.
  @note: Uses explicit directional Pascal loops (to/downto) based on Descending, holding X constant.
[==============================================================================}
function TRange.Verticaline(const X: Integer = 0): TPointArray; overload;
var
  y: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for y := Self.start to Self.stop do
      Result[y - Self.start] := Point(X, y);
    True:
    for y := Self.start downto Self.stop do
      Result[Self.start - y] := Point(X, y);
  end;
end;

{==============================================================================]
  <Vertically>
  @action: Generates a TPointArray forming a vertical line across the range.
  @note: Uses direct pointer arithmetic and vector step-direction iteration, holding X constant.
[==============================================================================}
function TRange.Vertically(const X: Integer = 0): TPointArray; overload;
var
  i, d, y: Integer;
  P: PPoint;
begin
  SetLength(Result, Self.Size);
  d := Self.Direction;
  y := Self.start;
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^.X := X;
	P^.Y := y.Increase(d);
    Inc(P);
  end;
end;
{$ENDIF}