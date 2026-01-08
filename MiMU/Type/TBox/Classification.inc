{$IFDEF METHODS}
function Boxy: Boolean; cdecl;
function Collapsed: Boolean; cdecl;
function Equilateral: Boolean; cdecl;
function Is2D: Boolean; cdecl;
function IsHorizontalLine: Boolean; cdecl;
function IsLine: Boolean; cdecl;
function IsPoint: Boolean; cdecl;
function IsVerticalLine: Boolean; cdecl;  
function Linear: Boolean; cdecl;
function Plural: Boolean; cdecl;
function Rectangular: Boolean; cdecl;
function Singular: Boolean; cdecl;
function Square: Boolean; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boxy>
  @action: Returns true if TBox is valid rectangle
  @note: None.
[==============================================================================}
function TBox.Boxy: Boolean; cdecl;
begin
  Result := ((Self.X1 <> Self.X2) and (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <Collapsed>
  @action: Returns true if TBox is either point or a horizontal/vertical line.
  @note: Returns False if TBox is rectangle with workable area.
[==============================================================================}
function TBox.Collapsed: Boolean; cdecl;
begin
  Result := ((Self.X1 = Self.X2) or (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <Equilateral>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Equilateral: Boolean; cdecl;
begin
  Result := ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1));
end;

{==============================================================================]
  <Is2D>
  @action: Returns true if TBox is valid rectangle with area.
  @note: None.
[==============================================================================}
function TBox.Is2D: Boolean; cdecl;
begin
  Result := ((Self.Width > 1) and (Self.Height > 1));
end;

{==============================================================================]
  <IsHorizontalLine>
  @action: Returns true if TBox is horizontal line. (Width <> 1) and (Height = 1)
  @note: None.
[==============================================================================}
function TBox.IsHorizontalLine: Boolean; cdecl;
begin
  Result := ((Y1 = Y2) and (X1 <> X2));
end;

{==============================================================================]
  <IsLine>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.IsLine: Boolean; cdecl;
begin
  Result := (Self.IsHorizontalLine or Self.IsVerticalLine);
end;

{==============================================================================]
  <IsPoint>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.IsPoint: Boolean; cdecl;
begin
  Result := not ((Self.X1 <> Self.X2) or (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <IsVerticalLine>
  @action: Returns true if TBox is vertical line. (Width = 1) and (Height <> 1)
  @note: None.
[==============================================================================}
function TBox.IsVerticalLine: Boolean; cdecl;
begin
  Result := ((X1 = X2) and (Y1 <> Y2));
end;

{==============================================================================]
  <Linear>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.Linear: Boolean; cdecl;
begin
  Result := (((Self.X1 = Self.X2) xor (Self.Y1 = Self.Y2)) and (not Self.IsPoint));
end;

{==============================================================================]
  <Plural>
  @action: Returns true if TBox contains more than single point.
  @note: None.
[==============================================================================}
function TBox.Plural: Boolean; cdecl;
begin
  Result := ((Self.X2 > Self.X1) or (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Rectangular>
  @action: Returns true if TBox width AND height are higher than 1.
  @note: (X2 > X1 and Y2 > Y1).
[==============================================================================}
function TBox.Rectangular: Boolean; cdecl;
begin
  Result := ((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Singular>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.Singular: Boolean; cdecl;
begin
  Result := ((Self.X1 = Self.X2) and (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <Square>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Square: Boolean; cdecl;
begin
  Result := (((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) and ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1)));
end;
{$ENDIF}
