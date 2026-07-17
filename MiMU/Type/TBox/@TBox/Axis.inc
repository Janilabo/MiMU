{$IFDEF METHODS}
function Bottom: Integer; overload;
function Left: Integer; overload;
function Right: Integer; overload;
function Top: Integer; overload;

function Horter: Integer; overload;
function Verter: Integer; overload;
function XC: Integer; overload;
function XF: Integer; overload;
function XMid: Double; overload;
function XR: Integer; overload;
function YC: Integer; overload;
function YF: Integer; overload;
function YMid: Double; overload;
function YR: Integer; overload;
function XT: Integer; overload;
function YT: Integer; overload;

function X(const oAscending: Boolean = True): TIntegerArray; overload;
function Xs(const AStep: Integer = 1): TIntegerArray; overload;
function Y(const oAscending: Boolean = True): TIntegerArray; overload;
function Ys(const AStep: Integer = 1): TIntegerArray; overload;

function Horizontal: TRange; overload;
function Vertical: TRange; overload;
function X1X2: TRange; overload;
function X2X1: TRange; overload;
function Y1Y2: TRange; overload;
function Y2Y1: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bottom>
  @action: Maximum Y-value
  @note: Always returns correct Bottom-value from TBox
[==============================================================================}
function TBox.Bottom: Integer; overload;
begin
  Result := Max(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Left>
  @action: Minimum X-value
  @note: Always returns correct Left-value from TBox
[==============================================================================}
function TBox.Left: Integer; overload;
begin
  Result := Min(Self.X1, Self.X2);
end;

{==============================================================================]
  <Right>
  @action: Maximum X-value
  @note: Always returns correct Right-value from TBox
[==============================================================================}
function TBox.Right: Integer; overload;
begin
  Result := Max(Self.X1, Self.X2);
end;

{==============================================================================]
  <Top>
  @action: Minimum Y-value
  @note: Always returns correct Top-value from TBox
[==============================================================================}
function TBox.Top: Integer; overload;
begin
  Result := Min(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Horter>
  @action: Returns the horizontal center (X-axis midpoint) of the box
  @param: None
  @return: Integer representing the center X coordinate
  @note: Uses integer division which truncates toward zero.
         For even widths, this biases toward the left side.
         Equivalent to: Self.X1 + (Self.Width div 2)
[==============================================================================}
function TBox.Horter: Integer; overload;
begin
  Result := ((Self.X1 + Self.X2) div 2);
end;

{==============================================================================]
  <Verter>
  @action: Returns the vertical center (Y-axis midpoint) of the box
  @param: None
  @return: Integer representing the center Y coordinate
  @note: Uses integer division which truncates toward zero.
         For even heights, this biases toward the top side.
         Equivalent to: Self.Y1 + (Self.Height div 2)
[==============================================================================}
function TBox.Verter: Integer; overload;
begin
  Result := ((Self.Y1 + Self.Y2) div 2);
end;

{==============================================================================]
  <XC>
  @action: Calculates the horizontal midpoint of the box, rounding up.
  @note: Uses `Ceil` to round the geometric center towards positive infinity.
[==============================================================================}
function TBox.XC: Integer; overload;
begin
  Result := Ceil(Self.XMid);
end;

{==============================================================================]
  <XF>
  @action: Calculates the horizontal midpoint of the box, rounding down.
  @note: Uses `Floor` to round the geometric center towards negative infinity.
[==============================================================================}
function TBox.XF: Integer; overload;
begin
  Result := Floor(Self.XMid);
end;

{==============================================================================]
  <XMid>
  @action: Calculates and returns the exact horizontal midpoint of the box.
  @note: Returns a `Double` precision float to preserve the fractional part 
         (e.g., .5) when the span is an odd number, avoiding rounding errors.
         Casting X1 to `Int64` safely prevents integer overflow during addition.
[==============================================================================}
function TBox.XMid: Double; overload;
begin
  Result := ((Int64(Self.X1) + Self.X2) / 2);
end;

{==============================================================================]
  <XR>
  @action: Calculates the horizontal midpoint of the box, rounding to the nearest integer.
  @note: Uses `Round` to find the nearest whole number. Be aware that in Delphi,
         `Round` utilizes Bankers' Rounding (rounds to the nearest even number 
         if the fractional part is exactly 0.5).
[==============================================================================}
function TBox.XR: Integer; overload;
begin
  Result := Round(Self.XMid);
end;

{==============================================================================]
  <YC>
  @action: Calculates the vertical midpoint of the box, rounding up.
  @note: Uses `Ceil` to round the geometric center towards positive infinity.
[==============================================================================}
function TBox.YC: Integer; overload;
begin
  Result := Ceil(Self.YMid);
end;

{==============================================================================]
  <YF>
  @action: Calculates the vertical midpoint of the box, rounding down.
  @note: Uses `Floor` to round the geometric center towards negative infinity.
[==============================================================================}
function TBox.YF: Integer; overload;
begin
  Result := Floor(Self.YMid);
end;

{==============================================================================]
  <YMid>
  @action: Calculates and returns the exact vertical midpoint of the box.
  @note: Returns a `Double` precision float to preserve the fractional part 
         (e.g., .5) when the span is an odd number, avoiding rounding errors.
         Casting Y1 to `Int64` safely prevents integer overflow during addition.
[==============================================================================}
function TBox.YMid: Double; overload;
begin
  Result := ((Int64(Self.Y1) + Self.Y2) / 2);
end;

{==============================================================================]
  <YR>
  @action: Calculates the vertical midpoint of the box, rounding to the nearest integer.
  @note: Uses `Round` to find the nearest whole number. Be aware that in Delphi,
         `Round` utilizes Bankers' Rounding (rounds to the nearest even number 
         if the fractional part is exactly 0.5).
[==============================================================================}
function TBox.YR: Integer; overload;
begin
  Result := Round(Self.YMid);
end;

{==============================================================================]
  <XT>
  @action: Calculates the horizontal midpoint of the box, rounding towards zero.
  @note: Uses `Trunc` to strip the fractional component, rounding towards zero.
[==============================================================================}
function TBox.XT: Integer; overload;
begin
  Result := Trunc(Self.XMid);
end;

{==============================================================================]
  <YT>
  @action: Calculates the vertical midpoint of the box, rounding towards zero.
  @note: Uses `Trunc` to strip the fractional component, rounding towards zero.
[==============================================================================}
function TBox.YT: Integer; overload;
begin
  Result := Trunc(Self.YMid);
end;

{==============================================================================]
  <X>
  @action: Generates an array containing every integer X-coordinate across the 
           box's width, ordered sequentially.
  @note: If `oAscending` is True, the array starts at X1 and steps upward (+1). 
         If False, it starts at X2 and steps downward (-1). This is useful for 
         iterating through columns or scanning the box horizontally.
[==============================================================================}
function TBox.X(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, r, s: Integer;
begin
  SetLength(Result, Self.Width);
  Result[0] := IfThen(oAscending, Self.X1, Self.X2);
  r := IfThen(oAscending, 1, -1);
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + r);
end;

{==============================================================================]
  <Xs>
  @action: Generates an array of horizontal X-coordinates sampled across the 
           box's width using a custom step interval.
  @note: Automatically safely terminates with an empty array `[]` if `AStep` 
         is less than 1 to prevent infinite loops. Uses an advanced helper 
         method `s.Increase(AStep)` to increment and record the values across 
         the pre-allocated array.
[==============================================================================}
function TBox.Xs(const AStep: Integer = 1): TIntegerArray; overload;
var
  i, s: Integer;
begin
  if (AStep < 1) then
    Exit([]);
  SetLength(Result, (Abs((Self.X2 - Self.X1) div AStep) + 1));
  s := Self.X1;
  for i := 0 to High(Result) do
    Result[i] := s.Increase(AStep);
end;

{==============================================================================]
  <Y>
  @action: Generates an array containing every integer Y-coordinate across the 
           box's height, ordered sequentially.
  @note: If `oAscending` is True, the array starts at Y1 and steps upward (+1). 
         If False, it starts at Y2 and steps downward (-1). This is useful for 
         iterating through rows or scanning the box vertically.
[==============================================================================}
function TBox.Y(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s: Integer;
begin
  SetLength(Result, Self.Height);
  Result[0] := IfThen(oAscending, Self.Y1, Self.Y2);
  s := IfThen(oAscending, 1, -1);
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + s);
end;

{==============================================================================]
  <Ys>
  @action: Generates an array of vertical Y-coordinates sampled across the 
           box's height using a custom step interval.
  @note: Automatically safely terminates with an empty array `[]` if `AStep` 
         is less than 1 to prevent infinite loops. Uses an advanced helper 
         method `s.Increase(AStep)` to increment and record the values across 
         the pre-allocated array.
[==============================================================================}
function TBox.Ys(const AStep: Integer = 1): TIntegerArray; overload;
var
  i, s: Integer;
begin
  if (AStep < 1) then
    Exit([]);
  SetLength(Result, (Abs((Self.Y2 - Self.Y1) div AStep) + 1));
  s := Self.Y1;
  for i := 0 to High(Result) do
    Result[i] := s.Increase(AStep);
end;

{==============================================================================]
  <Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange; overload;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
end;

{==============================================================================]
  <Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange; overload;
begin
  Result.start := Self.Y1;
  Result.stop := Self.Y2;
end;

{==============================================================================]
  <X1X2>
  @action: Extracts the horizontal span of the box along the X-axis, projecting it 
           into a TRange instance tracking from left (X1) to right (X2).
  @note: Represents the natural reading or layout direction of the box's horizontal width.
[==============================================================================}
function TBox.X1X2: TRange; overload;
begin
  Result := TRange.Construct(Self.X1, Self.X2);
end;

{==============================================================================]
  <X2X1>
  @action: Extracts the horizontal span of the box along the X-axis, projecting it 
           into a TRange instance tracking in reverse from right (X2) to left (X1).
  @note: Yields an inverted/backwards horizontal range. Sibling and reciprocal orientation 
         of the X1X2 method.
[==============================================================================}
function TBox.X2X1: TRange; overload;
begin
  Result := TRange.Construct(Self.X2, Self.X1);
end;

{==============================================================================]
  <Y1Y2>
  @action: Extracts the vertical span of the box along the Y-axis, projecting it 
           into a TRange instance tracking from top (Y1) to bottom (Y2).
  @note: Represents the natural reading or layout direction of the box's vertical height.
[==============================================================================}
function TBox.Y1Y2: TRange; overload;
begin
  Result := TRange.Construct(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Y2Y1>
  @action: Extracts the vertical span of the box along the Y-axis, projecting it 
           into a TRange instance tracking in reverse from bottom (Y2) to top (Y1).
  @note: Yields an inverted/backwards vertical range. Sibling and reciprocal orientation 
         of the Y1Y2 method.
[==============================================================================}
function TBox.Y2Y1: TRange; overload;
begin
  Result := TRange.Construct(Self.Y2, Self.Y1);
end;
{$ENDIF}