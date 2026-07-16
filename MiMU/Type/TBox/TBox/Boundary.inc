{$IFDEF METHODS}
function BottomEdge: TRange;
function BottomLeft: TPoint;
function BottomRight: TPoint;
function LeftEdge: TRange;
function RightEdge: TRange;
function TopEdge: TRange;
function TopLeft: TPoint;
function TopRight: TPoint;
function X1Y1: TPoint; overload;
function X1Y2: TPoint; overload;
function X2Y1: TPoint; overload;
function X2Y2: TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BottomEdge>
  @action: Returns the horizontal range of the bottom edge.
  @note: Range from X1 to X2 along Y2
[==============================================================================}
function TBox.BottomEdge: TRange;
begin
  Result.Create(Self.X1, Self.X2);
end;

{==============================================================================]
  <BottomLeft>
  @action: Returns the bottom-left corner of the box.
  @note: Point(X1, Y2)
[==============================================================================}
function TBox.BottomLeft: TPoint;
begin
  Result := Point(Self.X1, Self.Y2);
end;

{==============================================================================]
  <BottomRight>
  @action: Returns the bottom-right corner of the box.
  @note: Point(X2, Y2)
[==============================================================================}
function TBox.BottomRight: TPoint;
begin
  Result := Point(Self.X2, Self.Y2);
end;

{==============================================================================]
  <LeftEdge>
  @action: Returns the vertical range of the left edge.
  @note: Range from Y1 to Y2 along X1
[==============================================================================}
function TBox.LeftEdge: TRange;
begin
  Result.Create(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <RightEdge>
  @action: Returns the vertical range of the right edge.
  @note: Range from Y1 to Y2 along X2
[==============================================================================}
function TBox.RightEdge: TRange;
begin
  Result.Create(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <TopEdge>
  @action: Returns the horizontal range of the top edge.
  @note: Range from X1 to X2 along Y1
[==============================================================================}
function TBox.TopEdge: TRange;
begin
  Result.Create(Self.X1, Self.X2);
end;

{==============================================================================]
  <TopLeft>
  @action: Returns the top-left corner of the box.
  @note: Point(X1, Y1)
[==============================================================================}
function TBox.TopLeft: TPoint;
begin
  Result := Point(Self.X1, Self.Y1);
end;

{==============================================================================]
  <TopRight>
  @action: Returns the top-right corner of the box.
  @note: Point(X2, Y1)
[==============================================================================}
function TBox.TopRight: TPoint;
begin
  Result := Point(Self.X2, Self.Y1);
end;

{==============================================================================]
  <X1Y1>
  @action: Returns the top-left corner coordinate of the box as a TPoint.
  @note: Combines the primary X1 and Y1 properties. In standard computer 
         graphics systems, this represents the anchor or starting corner.
[==============================================================================}
function TBox.X1Y1: TPoint; overload;
begin
  Result.X := Self.X1;
  Result.Y := Self.Y1;
end;

{==============================================================================]
  <X1Y2>
  @action: Returns the bottom-left corner coordinate of the box as a TPoint.
  @note: Combines the primary left boundary (X1) with the secondary vertical 
         boundary (Y2).
[==============================================================================}
function TBox.X1Y2: TPoint; overload;
begin
  Result.X := Self.X1;
  Result.Y := Self.Y2;
end;

{==============================================================================]
  <X2Y1>
  @action: Returns the top-right corner coordinate of the box as a TPoint.
  @note: Combines the secondary horizontal boundary (X2) with the primary 
         vertical boundary (Y1).
[==============================================================================}
function TBox.X2Y1: TPoint; overload;
begin
  Result.X := Self.X2;
  Result.Y := Self.Y1;
end;

{==============================================================================]
  <X2Y2>
  @action: Returns the bottom-right corner coordinate of the box as a TPoint.
  @note: Combines the secondary X2 and Y2 properties. In standard computer 
         graphics systems, this represents the ending or opposite corner.
[==============================================================================}
function TBox.X2Y2: TPoint; overload;
begin
  Result.X := Self.X2;
  Result.Y := Self.Y2;
end;
{$ENDIF}