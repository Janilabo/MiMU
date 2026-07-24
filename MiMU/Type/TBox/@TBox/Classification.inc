{$IFDEF METHODS}
function Asymmetric: Boolean; overload;
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
function Squere: Boolean; overload;
function Squore: Boolean; overload;
function Symmetric: Boolean; overload;

function Dimensioned(const N: Integer): Boolean; overload;
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
  <Asymmetric>
  @action: Returns true if the box has unequal width and height spans.
  @note: Pure dimensional symmetry check (Self.Width <> Self.Height).
         Evaluates to True whenever the horizontal and vertical extents differ.
[==============================================================================}
function TBox.Asymmetric: Boolean; overload;
begin
  Result := (Self.Width <> Self.Height);
end;

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
  @action: Returns true if the box has valid positive dimensions and equal width and height.
  @note: Ensures the box is not inverted or zero-area (X2 > X1 and Y2 > Y1)
         and verifies that horizontal and vertical spans are equal ((X2 - X1) = (Y2 - Y1)).
[==============================================================================}
function TBox.Square: Boolean; overload;
begin
  Result := (((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) and ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1)));
end;

{==============================================================================]
  <Squere>
  @action: Returns true if the box is a valid positive-area square with an even width/height.
  @note: Evaluates whether `Self.Square` is true and `Self.Width` is an even integer.
[==============================================================================}
function TBox.Squere: Boolean; overload;
begin
  Result := (Self.Square and Self.Width.Even);
end;

{==============================================================================]
  <Squore>
  @action: Returns true if the box is a valid positive-area square with an odd width/height.
  @note: Evaluates whether `Self.Square` is true and `Self.Width` is an odd integer.
[==============================================================================}
function TBox.Squore: Boolean; overload;
begin
  Result := (Self.Square and Self.Width.Odd);
end;

{==============================================================================]
  <Symmetric>
  @action: Returns true if the box has identical width and height spans.
  @note: Pure dimension check (Self.Width = Self.Height) without bounds or positive-area validation.
         Evaluates to True for zero-area (0x0) or degenerate coordinates as long as X and Y extents are equal.
[==============================================================================}
function TBox.Symmetric: Boolean; overload;
begin
  Result := (Self.Width = Self.Height);
end;

{==============================================================================]
  <Dimensioned>
  @action: Checks if the box matches a specific geometric dimension target (-1 to 2).
  @note: Uses InRange to safeguard the input tier before querying the state-machine
         dimension property, ensuring zero overhead on out-of-bounds inputs.
[==============================================================================}
function TBox.Dimensioned(const N: Integer): Boolean; overload;
begin
  Result := ((N > -2) and (N < 3) and (Self.Dimensioned = N));
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
