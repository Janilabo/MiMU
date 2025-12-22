{$IFDEF TYPES}
function Uniform(const val: Integer): Boolean; overload;
function Uniform: Boolean; overload;
function Employs(const val: Integer): Boolean;
function Omits(const val: Integer): Boolean; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Uniform>
  @action: Checks whether all four coordinates of the box equal the specified value.
  @note: Returns True only if (X1 = Y1 = X2 = Y2 = val).
[==============================================================================}
function TBox.Uniform(const val: Integer): Boolean; overload;
begin
  Result := ((Self.X1 = val) and (Self.Y1 = val) and (Self.X2 = val) and (Self.Y2 = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether all coordinates of the box are equal to each other.
  @note: Returns True if (X1 = Y1 = X2 = Y2). Indicates a fully uniform box.
[==============================================================================}
function TBox.Uniform: Boolean; overload;
begin
  Result := ((Self.X1 = Self.X2) and (Self.Y1 = Self.Y2) and (Self.X2 = Self.Y2));
end;

{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches any of the four coordinates of the box (X1, Y1, X2, Y2).
  @note: Useful for detecting if a value is part of the box’s defining corners.
[==============================================================================}
function TBox.Employs(const val: Integer): Boolean;
begin
  Result := ((Self.X1 = val) or (Self.Y1 = val) or (Self.X2 = val) or (Self.Y2 = val));
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present in any of the four coordinates of the box (X1, Y1, X2, Y2).
  @note: Logical inverse of TBox.Employs; returns True if the value is absent from all box corners.
[==============================================================================}
function TBox.Omits(const val: Integer): Boolean;
begin
  Result := not ((Self.X1 = val) or (Self.Y1 = val) or (Self.X2 = val) or (Self.Y2 = val));
end;
{$ENDIF}