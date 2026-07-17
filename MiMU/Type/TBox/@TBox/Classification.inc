{$IFDEF METHODS}
function Boxy: Boolean; overload;
function Collapsed: Boolean; overload;
function Equilateral: Boolean; overload;
function IsHorizontalLine: Boolean; overload;
function IsLine: Boolean; overload;
function IsPoint: Boolean; overload;
function IsVerticalLine: Boolean; overload;
function Linear: Boolean; overload;
function Plural: Boolean; overload;
function Rectangular: Boolean; overload;
function Singular: Boolean; overload;
function Square: Boolean; overload;

function In0D: Boolean; overload;
function In1D: Boolean; overload;
function In2D: Boolean; overload;
function Is0D: Boolean; overload;
function Is1D: Boolean; overload;
function Is2D: Boolean; overload;
function IsND(const N: Integer): Boolean; overload;
function IsND: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boxy>
  @action: Returns true if TBox is valid rectangle
  @note: None.
[==============================================================================}
function TBox.Boxy: Boolean; overload;
begin
  Result := ((Self.X1 <> Self.X2) and (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <Collapsed>
  @action: Returns true if TBox is either point or a horizontal/vertical line.
  @note: Returns False if TBox is rectangle with workable area.
[==============================================================================}
function TBox.Collapsed: Boolean; overload;
begin
  Result := ((Self.X1 = Self.X2) or (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <Equilateral>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Equilateral: Boolean; overload;
begin
  Result := ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1));
end;

{==============================================================================]
  <IsHorizontalLine>
  @action: Returns true if TBox is horizontal line. (Width <> 1) and (Height = 1)
  @note: None.
[==============================================================================}
function TBox.IsHorizontalLine: Boolean; overload;
begin
  Result := ((Y1 = Y2) and (X1 <> X2));
end;

{==============================================================================]
  <IsLine>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.IsLine: Boolean; overload;
begin
  Result := (Self.IsHorizontalLine or Self.IsVerticalLine);
end;

{==============================================================================]
  <IsPoint>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.IsPoint: Boolean; overload;
begin
  Result := not ((Self.X1 <> Self.X2) or (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <IsVerticalLine>
  @action: Returns true if TBox is vertical line. (Width = 1) and (Height <> 1)
  @note: None.
[==============================================================================}
function TBox.IsVerticalLine: Boolean; overload;
begin
  Result := ((X1 = X2) and (Y1 <> Y2));
end;

{==============================================================================]
  <Linear>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.Linear: Boolean; overload;
begin
  Result := (((Self.X1 = Self.X2) xor (Self.Y1 = Self.Y2)) and (not Self.IsPoint));
end;

{==============================================================================]
  <Plural>
  @action: Returns true if TBox contains more than single point.
  @note: None.
[==============================================================================}
function TBox.Plural: Boolean; overload;
begin
  Result := ((Self.X2 > Self.X1) or (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Rectangular>
  @action: Returns true if TBox width AND height are higher than 1.
  @note: (X2 > X1 and Y2 > Y1).
[==============================================================================}
function TBox.Rectangular: Boolean; overload;
begin
  Result := ((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Singular>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.Singular: Boolean; overload;
begin
  Result := ((Self.X1 = Self.X2) and (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <Square>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Square: Boolean; overload;
begin
  Result := (((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) and ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1)));
end;

{==============================================================================]
  <In0D>
  @action: Determines if the box represents a zero-dimensional point (exactly 1x1 size).
  @note: Uses direct boolean AND evaluation to ensure both dimensions are exactly 1.
[==============================================================================}
function TBox.In0D: Boolean; overload;
begin
  Result := ((Self.Width = 1) and (Self.Height = 1));
end;

{==============================================================================]
  <In1D>
  @action: Determines if the box represents a one-dimensional line (horizontal or vertical strip).
  @note: Evaluates if exactly one dimension is equal to 1 while the opposing dimension is greater than 1.
[==============================================================================}
function TBox.In1D: Boolean; overload;
begin
  Result := (((Self.Width = 1) and (Self.Height > 1)) or  ((Self.Height = 1) and (Self.Width > 1)));
end;

{==============================================================================]
  <In2D>
  @action: Determines if the box has a two-dimensional layout.
  @note: Uses an inverted evaluation; assumes any layout where neither dimension is 1 qualifies as 2D.
[==============================================================================}
function TBox.In2D: Boolean; overload;
begin
  Result := not ((Self.Width = 1) or (Self.Height = 1));
end;

{==============================================================================]
  <Is0D>
  @action: Determines if the box represents a zero-dimensional point (exactly 1 pixel in total size).
  @note: Returns true only when Width * Height equals 1.
[==============================================================================}
function TBox.Is0D: Boolean; overload;
begin
  Result := (Self.Size = 1);
end;

{==============================================================================]
  <Is1D>
  @action: Determines if the box represents a one-dimensional line (either a single row or a single column, but not both).
  @note: Evaluates if exactly one dimension equals 1 while the other is greater than 1.
[==============================================================================}
function TBox.Is1D: Boolean; overload;
begin
  if (Self.Width = 1) then
    Result := (Self.Height > 1)
  else
    Result := (Self.Height = 1);
end;

{==============================================================================]
  <Is2D>
  @action: Determines if the box represents a two-dimensional area.
  @note: Returns true only when both the Width and Height are strictly greater than 1.
[==============================================================================}
function TBox.Is2D: Boolean; overload;
begin
  Result := ((Self.Width > 1) and (Self.Height > 1));
end;

{==============================================================================]
  <IsND>
  @action: Checks if the box matches a specific geometric dimension N (-1 to 2).
  @note: Uses InRange to validate that the requested dimension N is a valid geometric tier before comparison.
[==============================================================================}
function TBox.IsND(const N: Integer): Boolean; overload;
begin
  Result := (InRange(N, -1, 2) and (Self.Dimensionality = N));
end;

{==============================================================================]
  <IsND>
  @action: Determines whether the box possesses a valid geometric dimension (0D, 1D, or 2D).
  @note: Returns True if the coordinates are properly formed, and False if the box is inverted, malformed, or invalid (-1).
[==============================================================================}
function TBox.IsND: Boolean; overload;
begin
  Result := (Self.Dimensionality > -1);
end;
{$ENDIF}
