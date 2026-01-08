{$IFDEF METHODS}
function Boundaries: TBox; cdecl;
function BoundingBox: TBox; cdecl;
function Bounds: TBox; cdecl;
function Envelope: TBox; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boundaries>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Boundaries: TBox; cdecl;
begin
  Result := Box(Trunc(Self.Center.X - Self.Radius), Trunc(Self.Center.Y - Self.Radius), (Trunc(Self.Center.X + Self.Radius) + 1), (Trunc(Self.Center.Y + Self.Radius) + 1));
end;

{==============================================================================]
  <BoundingBox>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.BoundingBox: TBox; cdecl;
var
  r: Integer;
begin
  r := Round(Self.Radius);
  Result := Box((Self.Center.X - R), (Self.Center.Y - R), (Self.Center.X + R), (Self.Center.Y + R));
end;

{==============================================================================]
  <Bounds>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Bounds: TBox; cdecl;
begin
  Result := Box(Floor(Self.Center.X - Self.Radius), Floor(Self.Center.Y - Self.Radius), Ceil(Self.Center.X + Self.Radius), Ceil(Self.Center.Y + Self.Radius));
end;

{==============================================================================]
  <Envelope>
  @action: Returns TCircle boundaries as TBox.
  @note: None.
[==============================================================================}
function TCircle.Envelope: TBox; cdecl;
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