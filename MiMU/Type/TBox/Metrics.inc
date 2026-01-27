{$IFDEF METHODS}
function Area: Integer; overload;
function Area(var bWidth, bHeight: Integer): Integer; overload;
function Capacity: Integer;
function Cardinality: Int64;
function Circumference: Integer;
function Diagonal: Double;
function Footprint: Double;
function Perim: Integer;
function Perimeter: Integer;
function Population(const scale: Integer = 1): Integer;
function Ratio: Double;
function Resolution: Int64;
function Size(var bWidth, bHeight: Integer): Integer; overload;
function Size: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Area>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Area: Integer; overload;
begin
  Result := (Self.Width * Self.Height);
end;

function TBox.Area(var bWidth, bHeight: Integer): Integer; overload;
begin
  bWidth := Self.GetWidth;
  bHeight := Self.GetHeight;
  Result := (bWidth * bHeight);
end;

{==============================================================================]
  <Capacity>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Capacity: Integer;
begin
  with Self do
    Result := (((Max(X1, X2) - Min(X1, X2)) + 1) * ((Max(Y1, Y2) - Min(Y1, Y2)) + 1));
end;

{==============================================================================]
  <Cardinality>
  @action: Returns the number of discrete integer coordinate points contained
           within the box.
  @note: Bounds are inclusive: the result is computed as
         (X2 − X1 + 1) × (Y2 − Y1 + 1).
         No validation is performed; if either dimension is negative, the
         result will also be negative.
[==============================================================================}
function TBox.Cardinality: Int64;
begin
  Result := (Int64((Self.X2 - Self.X1) + 1) * ((Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <Footprint>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TBox.Footprint: Double;
begin
  Result := ((Abs(Self.X2 - Self.X1) + 1) * (Abs(Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Perim>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perim: Integer;
begin
  Result := (2 * (Pred(Self.Width) + Pred(Self.Height)));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
end;

{==============================================================================]
  <Population>
  @action: Returns the number of discrete elements contained in the box after
           uniform integer scaling.
  @note: The population is computed using inclusive bounds:
         ((X2 − X1 + 1) × scale) × ((Y2 − Y1 + 1) × scale).
         No validation or clamping is performed; negative extents or scale
         values will yield negative results.
[==============================================================================}
function TBox.Population(const scale: Integer = 1): Integer;
begin
  Result := ((((Self.X2 - Self.X1) + 1) * scale) * (((Self.Y2 - Self.Y1) + 1) * scale));
end;

{==============================================================================]
  <Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double;
begin
  Result := (Self.Width / Self.Height);
end;

{==============================================================================]
  <Resolution>
  @action: Returns the discrete area of the box expressed as a count of
           addressable integer points.
  @note: Width and height are treated as inclusive (X2−X1+1, Y2−Y1+1).
         If either dimension is non-positive, the result is zero.
         Useful for pixel- or cell-based domains rather than continuous
         geometry.
[==============================================================================}
function TBox.Resolution: Int64;
var
  W, H: Integer;
begin
  W := ((Self.X2 - Self.X1) + 1);
  H := ((Self.Y2 - Self.Y1) + 1);
  Result := (Int64(W * (Integer(W > 0))) * Int64(H * (Integer(H > 0))));
end;

{==============================================================================]
  <Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBox.Size(var bWidth, bHeight: Integer): Integer; overload;
begin
  bWidth := Self.Width;
  bHeight := Self.Height;
  Result := (bWidth * bHeight);
end;

{==============================================================================]
  <Size>
  @action: Returns area of Self.
  @note: None.
[==============================================================================}
function TBox.Size: Integer; overload;
var
  w, h: Integer;
begin
  Result := Self.Size(w, h);
end;
{$ENDIF}
