{$IFDEF METHODS}
function Circumference: Integer; overload;
function Diagonal: Double; overload;
function Perim: Integer; overload;
function Perimeter: Integer; overload;
function Perimetric: Integer; overload;
function Perimetry: Integer; overload;
function Population(const scale: Integer = 1): Integer; overload;
function Ratio: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer; overload;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double; overload;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <Perim>
  @action: Returns the total number of distinct pixels forming the outer border of the box.
  @note: Calculates outer boundary count using inner dimensions 2 * (Pred(w) + Pred(h)).
        Safely handles single-pixel points and 1D line segments (w or h <= 1).
[==============================================================================}
function TBox.Perim: Integer; overload;
var
  w, h: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  if ((w <= 1) or (h <= 1)) then
    Exit(w * h);
  Result := (2 * (Pred(w) + Pred(h)));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the total number of distinct pixels forming the outer border of the box.
  @note: Calculates 2 * (w + h) - 4 to compensate for shared corner pixels in a discrete grid.
        Safely handles single-pixel points and 1D line segments (w or h <= 1).
[==============================================================================}
function TBox.Perimeter: Integer; overload;
var
  w, h: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  if ((w <= 1) or (h <= 1)) then
    Exit(w * h);
  Result := ((2 * (w + h)) - 4);
end;

{==============================================================================]
  <Perimetric>
  @action: Returns the exact discrete pixel border length of the box.
  @note: Uses explicit edge summation with branchless bounds clamping to handle underflow.
         Safely handles single-pixel points and 1D line segments (w or h <= 1).
[==============================================================================}
function TBox.Perimetric: Integer; overload;
var
  w, h: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  if ((w <= 1) or (h <= 1)) then
    Exit(w * h);
  Result := ((2 * w) + (2 * Max(0, (h - 2))));
end;

{==============================================================================]
  <Perimetry>
  @action: Returns the total number of distinct pixels forming the outer shell of the box.
  @note: Uses area subtraction logic (Total Area - Interior Area).
         Safely handles small or thin boxes (Width or Height <= 2) where all pixels belong to the boundary.
[==============================================================================}
function TBox.Perimetry: Integer; overload;
var
  w, h: Integer;
begin
  w := Self.Width;
  h := Self.Height;
  if ((w <= 2) or (h <= 2)) then
    Exit(w * h);
  Result := ((w * h) - ((w - 2) * (h - 2)));
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
function TBox.Population(const scale: Integer = 1): Integer; overload;
begin
  Result := ((((Self.X2 - Self.X1) + 1) * scale) * (((Self.Y2 - Self.Y1) + 1) * scale));
end;

{==============================================================================]
  <Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double; overload;
begin
  Result := (Self.Width / Self.Height);
end;
{$ENDIF}
