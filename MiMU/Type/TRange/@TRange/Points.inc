{$IFDEF METHODS}
function Horizontal(const Y: Integer = 0): TPointArray; overload;
function Horizontaled(const Y: Integer = 0): TPointArray; overload;
function Horizontalen(const Y: Integer = 0): TPointArray; overload;
function Horizontaline(const Y: Integer = 0): TPointArray; overload;
function Horizontalize(const Y: Integer = 0): TPointArray; overload;
function Horizontally(const Y: Integer = 0): TPointArray; overload;
function Horizontalment(const Y: Integer = 0): TPointArray; overload;

function Vertical(const X: Integer = 0): TPointArray; overload;
function Verticaled(const X: Integer = 0): TPointArray; overload;
function Verticalen(const X: Integer = 0): TPointArray; overload;
function Verticaline(const X: Integer = 0): TPointArray; overload;
function Verticalize(const X: Integer = 0): TPointArray; overload;
function Vertically(const X: Integer = 0): TPointArray; overload;
function Verticalment(const X: Integer = 0): TPointArray; overload;
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
  <Horizontalen>
  @action: Generates an array of TPoint structures representing a horizontal line segment across the defined TRange.
  @note: Sets all points in the returned TPointArray to a fixed Y-coordinate (defaulting to 0)
         while stepping the X-coordinate sequentially from Self.start using Self.Direction.
[==============================================================================}
function TRange.Horizontalen(const Y: Integer = 0): TPointArray; overload;
var
  i, d: Integer;
begin
  for i := 0 to Result.Alloc(Self.Size) do
    Result[i].Y := Y;
  d := Self.Direction;
  for i := 0 to High(Result) do
    Result[i].X := (Self.start + (i * d));
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

{==============================================================================
  <Horizontalize>
  @action: Converts the 1D range into an array of 2D points aligned horizontally along a fixed Y-coordinate.
  @note: Uses a two-pointer inward approach (filling head and tail simultaneously) to map range values to Point(X, Y).
[==============================================================================}
function TRange.Horizontalize(const Y: Integer = 0): TPointArray; overload;
var
  d: Integer;
  s, r: TRange;
begin
  r.start := -1;
  r.stop := Result.SetSize(Self.Size);
  d := Self.Direction;
  s := Self;
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Point(s.start.Increase(d), Y);
    Result[r.stop] := Point(s.stop.Decrease(d), Y);
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

{==============================================================================]
  <Horizontalment>
  @action: Projects the range's values into an array of 2D points along a horizontal line at a given Y-coordinate.
  @note: Converts the range to an integer array via ToArray and allocates the point array sequentially, unlike the two-pointer approach in Horizontalize.
[==============================================================================}
function TRange.Horizontalment(const Y: Integer = 0): TPointArray; overload;
var
  x: TIntegerArray;
  i: Integer;
begin
  x := Self.ToArray;
  for i := 0 to Result.Alloc(x.Length) do
    Result[i] := Point(x[i], Y);
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
  <Verticalen>
  @action: Generates an array of TPoint structures representing a vertical line segment across the defined TRange.
  @note: Sets all points in the returned TPointArray to a fixed X-coordinate (defaulting to 0)
         while stepping the Y-coordinate sequentially from Self.start using Self.Direction.
[==============================================================================}
function TRange.Verticalen(const X: Integer = 0): TPointArray; overload;
var
  i, d: Integer;
begin
  for i := 0 to Result.Alloc(Self.Size) do
    Result[i].X := X;
  d := Self.Direction;
  for i := 0 to High(Result) do
    Result[i].Y := (Self.start + (i * d));
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

{==============================================================================
  <Verticalize>
  @action: Converts the 1D range into an array of 2D points aligned vertically along a fixed X-coordinate.
  @note: Uses a two-pointer inward approach (filling head and tail simultaneously) to map range values to Point(X, Y).
[==============================================================================}
function TRange.Verticalize(const X: Integer = 0): TPointArray; overload;
var
  d: Integer;
  s, r: TRange;
begin
  r.stop := Result.SetSize(Self.Size);
  r.start := -1;
  d := Self.Direction;
  s := Self;
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Point(X, s.start.Increase(d));
    Result[r.stop] := Point(X, s.stop.Decrease(d));
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

{==============================================================================]
  <Verticalment>
  @action: Projects the range's values into an array of 2D points along a vertical line at a given X-coordinate.
  @note: Converts the range to an integer array via ToArray and allocates the point array sequentially, unlike the two-pointer approach in Verticalize.
[==============================================================================}
function TRange.Verticalment(const X: Integer = 0): TPointArray; overload;
var
  y: TIntegerArray;
  i: Integer;
begin
  y := Self.ToArray;
  for i := 0 to Result.Alloc(y.Length) do
    Result[i] := Point(x, y[i]);
end;
{$ENDIF}