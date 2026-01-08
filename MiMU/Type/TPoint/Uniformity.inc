{$IFDEF METHODS}
function Employs(const val: Integer): Boolean; cdecl;
function Omits(const val: Integer): Boolean; cdecl;
function Uniform(const val: Integer): Boolean; overload; cdecl;
function Uniform: Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches either the X or Y coordinate of the point.
  @note: Useful for determining if a specific value is present in a 2D point.
[==============================================================================}
function TPoint.Employs(const val: Integer): Boolean; cdecl;
begin
  Result := ((Self.X = val) or (Self.Y = val));
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present in either the X or Y coordinate of the point.
  @note: Logical inverse of TPoint.Employs; returns True if the value is absent.
[==============================================================================}
function TPoint.Omits(const val: Integer): Boolean; cdecl;
begin
  Result := not ((Self.X = val) or (Self.Y = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether both coordinates of the point equal the specified value.
  @note: Returns True only if (X = val) and (Y = val).
[==============================================================================}
function TPoint.Uniform(const val: Integer): Boolean; overload; cdecl;
begin
  Result := ((Self.X = val) and (Self.Y = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether the point’s coordinates are equal to each other.
  @note: Returns True if (X = Y).
[==============================================================================}
function TPoint.Uniform: Boolean; overload; cdecl;
begin
  Result := (Self.X = Self.Y);
end;
{$ENDIF}