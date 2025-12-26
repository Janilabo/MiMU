{$IFDEF HELPERS}
function FrameLinks(const dist: Integer; const area: TBox): TPointArray; overload;
function FrameLinks(const dist: Integer = 1): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <FrameLinks>
  @action: For each point in the array that lies within the given area, generates
           a “frame” around the point (a box of size determined by dist) and a
           vertical line from the point to the top of the box. Returns a new
           TPointArray containing all these border and line points.
  @note:   Uses the Attach helper to efficiently append points. The size of the
           resulting array depends on the borders of all valid points. Points
           outside the area are ignored.
[==============================================================================}
function TPointArrayHelper.FrameLinks(const dist: Integer; const area: TBox): TPointArray; overload;
var
  b: TBox;
  i: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
    if area.Contains(Self[i]) then
    begin
      b.Create(Max(area.X1, (Self[i].X - dist)), Max(area.Y1, (Self[i].Y - dist)), Min(area.X2, (Self[i].X + dist)), Min(area.Y2, (Self[i].Y + dist)));
      Result.Attach(b.Border);
      Result.Attach(Self[i].ToY(b.Y1 + 1));
    end;
end;

function TPointArrayHelper.FrameLinks(const dist: Integer = 1): TPointArray; overload;
begin
  Result := Self.FrameLinks(dist, Self.Bounds);
end;
{$ENDIF}
