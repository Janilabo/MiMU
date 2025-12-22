{$IFDEF TYPES}
function Reflected: TPoint; inline;
function Flipped: TPoint; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reflected>
  @action: Reflects the point across the line y = x.
  @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Reflected: TPoint; inline;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;

{==============================================================================]
  <Flipped>
  @action: Returns the point with its coordinates flipped (same as Reflected).
  @note: This is a shorthand, stylistically different version of Reflected.
[==============================================================================}
function TPoint.Flipped: TPoint; inline;
begin
  Result := Point(Self.Y, Self.X);
end;
{$ENDIF}