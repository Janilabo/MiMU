{$IFDEF METHODS}
function InCircle(const center: TPoint; const radius: Double): Boolean; inline;
function InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
{$ENDIF}

{$IFDEF HELPERS}
function Inside(const bx: TBox): Boolean; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <InCircle>
  @action: Returns true if pt is inside the given circle,
          that is defined by the center point and radius.
  @note: None.
[==============================================================================}
function TPoint.InCircle(const center: TPoint; const radius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / radius) + Sqr((Self.Y - center.Y) / radius) <= 1);
end;

{==============================================================================]
  <InEllipse>
  @action: Returns true if pt is inside the given ellipse,
          defined by the center point and X-radius and Y-radius.
  @note: None.
[==============================================================================}
function TPoint.InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / XRadius) + Sqr((Self.Y - center.Y) / YRadius) <= 1);
end;

{==============================================================================]
  <Inside>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TPointHelper.Inside(const bx: TBox): Boolean; inline;
begin
  Result := ((Self.X >= bx.X1) and (Self.Y >= bx.Y1) and (Self.X <= bx.X2) and (Self.Y <= bx.Y2));
end;
{$ENDIF}