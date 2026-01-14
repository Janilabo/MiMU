{$IFDEF METHODS}
function Flipped: TPoint;
function Reflected: TPoint;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flipped>
  @action: Returns the point with its coordinates flipped (same as Reflected).
  @note: This is a shorthand, stylistically different version of Reflected.
[==============================================================================}
function TPoint.Flipped: TPoint;
begin
  Result := Point(Self.Y, Self.X);
end;

{==============================================================================]
  <Reflected>
  @action: Reflects the point across the line y = x.
  @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Reflected: TPoint;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;
{$ENDIF}