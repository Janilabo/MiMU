{$IFDEF METHODS}
function Contains(const pt: TPoint): Boolean; overload;
function Contains(const b: TBox): Boolean; overload;
function Disjoint(const target: TBox): Boolean; overload;
function Inside(const target: TBox): Boolean; overload;
function Lacks(const pt: TPoint): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Inside(const targets: TBoxArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contains>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TBox.Contains(const pt: TPoint): Boolean; overload;
begin
  Result := not ((pt.X < Self.X1) or (pt.Y < Self.Y1) or (pt.X > Self.X2) or (pt.Y > Self.Y2));
end;

{==============================================================================]
  <Contains>
  @action: Returns true if x is in/within bx boundaries.
  @note: None
[==============================================================================}
function TBox.Contains(const b: TBox): Boolean; overload;
begin
  Result := ((b.X1 >= Self.X1) and (b.X1 <= Self.X2) and (b.X2 >= Self.X1) and (b.X2 <= Self.X2) and (b.Y1 >= Self.Y1) and (b.Y1 <= Self.Y2) and (b.Y2 >= Self.Y1) and (b.Y2 <= Self.Y2));
end;

{==============================================================================]
  <Disjoint>
  @action: Returns true if target TBox is outside the target boundaries.
  @note: None.
[==============================================================================}
function TBox.Disjoint(const target: TBox): Boolean; overload;
begin
  Result := ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <Inside>
  @action: Returns true if bx is INSIDE target boundaries.
  @note: None.
[==============================================================================}
function TBox.Inside(const target: TBox): Boolean; overload;
begin
  Result := not ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <Inside>
  @action: Returns true if bx is in/within any area boundaries by target areas.
  @note: None.
[==============================================================================}
function TBoxHelper.Inside(const targets: TBoxArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(targets) do
    if not ((Self.X2 < targets[i].X1) or (Self.X1 > targets[i].X2) or (Self.Y2 < targets[i].Y1) or (Self.Y1 > targets[i].Y2)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Lacks>
  @action: Returns true if pt TPoint is OUTSIDE the TBox boundaries.
  @note: None.
[==============================================================================}
function TBox.Lacks(const pt: TPoint): Boolean; overload;
begin
  Result := ((pt.X > Self.X2) or (pt.Y > Self.Y2) or (pt.X < Self.X1) or (pt.Y < Self.Y1));
end;
{$ENDIF}