{$IFDEF TYPES}
function Contains(const pt: TPoint): Boolean; 
function Item(const pt: TPoint): Boolean; 
function Pixel(const pt: TPoint): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contains>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Contains(const pt: TPoint): Boolean;
begin
  Result := ((Sqr(pt.X - Self.Center.X) + Sqr(pt.Y - Self.Center.Y)) <= Sqr(Self.Radius));
end;

{==============================================================================]
  <Item>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Item(const pt: TPoint): Boolean;
begin
  Result := (Hypot((pt.X - Self.Center.X), (pt.Y - Self.Center.Y)) <= Self.Radius);
end;

{==============================================================================]
  <Pixel>
  @action: Returns true if TCircle contains pt.
  @note: None.
[==============================================================================}
function TCircle.Pixel(const pt: TPoint): Boolean;
begin
  Result := ((((pt.X - Self.Center.X) * (pt.X - Self.Center.X)) + ((pt.Y - Self.Center.Y) * (pt.Y - Self.Center.Y))) <= (Self.Radius * Self.Radius));
end;
{$ENDIF}