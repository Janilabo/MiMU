{$IFDEF TYPES}
function DistX(const target: TPoint): Integer;
function DistY(const target: TPoint): Integer;
function DistanceX(const target: TPoint): Integer;
function DistanceY(const target: TPoint): Integer;
function DistMaxMinX(const Target: TPoint): Integer;
function DistMaxMinY(const Target: TPoint): Integer;
function DeltaX(const target: TPoint): Integer;
function DeltaY(const target: TPoint): Integer;
function Delta(const target: TPoint): TPoint;
function HorizontalDist(const target: TPoint): Integer;
function VerticalDist(const target: TPoint): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DistX>
  @action: Returns the absolute horizontal distance between this point and the target point.
  @note: Equivalent to Abs(Self.X - target.X). Useful for quick delta comparisons on the X-axis.
[==============================================================================}
function TPoint.DistX(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
  <DistY>
  @action: Returns the absolute vertical distance between this point and the target point.
  @note: Equivalent to Abs(Self.Y - target.Y). Useful for quick delta comparisons on the Y-axis.
[==============================================================================}
function TPoint.DistY(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;

{==============================================================================]
  <DistanceX>
  @action: Calculates the horizontal distance between this point and the target point.
  @note: Functionally identical to DistX; uses explicit conditional logic instead of Abs().
[==============================================================================}
function TPoint.DistanceX(const target: TPoint): Integer;
begin
  if (Self.X > target.X) then
    Result := (Self.X - target.X)
  else
    Result := (target.X - Self.X);
end;

{==============================================================================]
  <DistanceY>
  @action: Calculates the vertical distance between this point and the target point.
  @note: Functionally identical to DistY; uses explicit conditional logic instead of Abs().
[==============================================================================}
function TPoint.DistanceY(const target: TPoint): Integer;
begin
  if (Self.Y > target.Y) then
    Result := (Self.Y - target.Y)
  else
    Result := (target.Y - Self.Y);
end;

{==============================================================================]
  <DistMaxMinX>
  @action: Returns the absolute horizontal distance between this point and the target point using Max/Min arithmetic.
  @note: Equivalent to Abs(Self.X - Target.X); employs the branchless Max(a,b) - Min(a,b) idiom,
         which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinX(const target: TPoint): Integer;
begin
  Result := (Max(Self.X, target.X) - Min(Self.X, target.X));
end;

{==============================================================================]
  <DistMaxMinY>
  @action: Returns the absolute vertical distance between this point and the target point using Max/Min arithmetic.
  @note: Equivalent to Abs(Self.Y - Target.Y); employs the branchless Max(a,b) - Min(a,b) idiom,
         which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinY(const target: TPoint): Integer;
begin
  Result := (Max(Self.Y, target.Y) - Min(Self.Y, target.Y));
end;

{==============================================================================]
  <DeltaX>
  @action: Returns the signed horizontal delta from this point to the target point (positive if target is to the right).
  @note: Equivalent to Target.X - Self.X; useful for directional movement or vector calculations without absolute value.
[==============================================================================}
function TPoint.DeltaX(const target: TPoint): Integer;
begin
  Result := (target.X - Self.X);
end;

{==============================================================================]
  <DeltaY>
  @action: Returns the signed vertical delta from this point to the target point (positive if target is below).
  @note: Equivalent to Target.Y - Self.Y; useful for directional movement or vector calculations without absolute value. Assumes Y increases downward in coordinate system.
[==============================================================================}
function TPoint.DeltaY(const target: TPoint): Integer;
begin
  Result := (target.Y - Self.Y);
end;

{==============================================================================]
  <Delta>
  @action: Returns the signed vector delta from this point to the target point as a TPoint (dx, dy).
  @note: Equivalent to Point(Target.X - Self.X, Target.Y - Self.Y); useful for relative positioning, vector calculations, or directional offsets without absolute values.
[==============================================================================}
function TPoint.Delta(const target: TPoint): TPoint;
begin
  Result := Point((target.X - Self.X), (target.Y - Self.Y));
end;

{==============================================================================]
  <HorizontalDist>
  @action: Returns the absolute horizontal distance between this point and the target point.
  @note: Equivalent to Abs(Self.X - target.X); useful for quick delta comparisons on the X-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.HorizontalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
  <VerticalDist>
  @action: Returns the absolute vertical distance between this point and the target point.
  @note: Equivalent to Abs(Self.Y - target.Y); useful for quick delta comparisons on the Y-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.VerticalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;
{$ENDIF}