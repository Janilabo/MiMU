{$IFDEF METHODS}
function Bounds: TBox; 
function Boundaries: TBox; 
function BoundingBox: TBox; 
function Envelope: TBox; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bounds>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Bounds: TBox;
begin
  Result := Box(Floor(Self.Center.X - Self.Radius), Floor(Self.Center.Y - Self.Radius), Ceil(Self.Center.X + Self.Radius), Ceil(Self.Center.Y + Self.Radius));
end;

{==============================================================================]
  <Boundaries>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Boundaries: TBox;
begin
  Result := Box(Trunc(Self.Center.X - Self.Radius), Trunc(Self.Center.Y - Self.Radius), (Trunc(Self.Center.X + Self.Radius) + 1), (Trunc(Self.Center.Y + Self.Radius) + 1));
end;

{==============================================================================]
  <BoundingBox>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.BoundingBox: TBox;
var
  r: Integer;
begin
  r := Round(Self.Radius);
  Result := Box((Self.Center.X - R), (Self.Center.Y - R), (Self.Center.X + R), (Self.Center.Y + R));
end;

{==============================================================================]
  <Envelope>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Envelope: TBox;
var
  r: Integer;
begin
  r := Round(2 * Self.Radius);
  with Result do
  begin
    X1 := Round(Self.Center.X - Self.Radius);
    Y1 := Round(Self.Center.Y - Self.Radius);
    X2 := (X1 + r);
    Y2 := (Y1 + r);
  end;
end;
{$ENDIF}