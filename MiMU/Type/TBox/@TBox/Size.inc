{$IFDEF METHODS}
function Acre: Integer; overload;
function Acreage: Integer; overload;
function Area: Integer; overload;
function Area(var bWidth, bHeight: Integer): Integer; overload;
function Capacity: Integer; overload;
function Cardinality: Int64; overload;
function Domain: Integer; overload;
function Extent: Int64; overload;
function Footprint: Double; overload;
function Measure: Int64; overload;
function Px: Int64; overload;
function Resolution: Int64; overload;
function Size(var bWidth, bHeight: Integer): Integer; overload;
function Size: Integer; overload;
function Volume: Int64; overload;
function WxH: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Acre>
  @action: Calculates the total discrete area (pixel/grid cell count) enclosed 
           by the box.
  @note: Uses a low-level memory overlay technique via the `absolute` keyword, 
         interpreting the structural bounds as an array of two `TPoint` elements 
         (`a[0]` as X1,Y1 and `a[1]` as X2,Y2). The formula adds `1` to both the 
         width and height calculations, making it an inclusive grid/pixel-area 
         measurement rather than a strict geometric vector area.
[==============================================================================}
function TBox.Acre: Integer; overload;
var
  a: array[0..1] of TPoint absolute Self;
begin
  Result := ((Abs(a[1].X - a[0].X) + 1) * (Abs(a[1].Y - a[0].Y) + 1));
end;

{==============================================================================]
  <Acreage>
  @action: Calculates the inclusive discrete area (total cell/pixel count) 
           enclosed by the box.
  @note: Achieves identical functionality to `Acre` and `Domain` but uses 
         the low-level standard `Move` procedure to copy the data structures. 
         It copies the raw memory layout of `Self` directly into a local 
         4-element integer array (`a[0]` = X1, `a[1]` = Y1, `a[2]` = X2, `a[3]` = Y2) 
         before performing the inclusive area arithmetic.
[==============================================================================}
function TBox.Acreage: Integer; overload;
var
  a: array[0..3] of Integer;
begin
  Move(Self, a, SizeOf(a));
  Result := ((Abs(a[2] - a[0]) + 1) * (Abs(a[3] - a[1]) + 1));
end; 

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
function TBox.Capacity: Integer; overload;
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
function TBox.Cardinality: Int64; overload;
begin
  Result := (Int64((Self.X2 - Self.X1) + 1) * ((Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Domain>
  @action: Calculates the inclusive discrete area (total cell/pixel count) 
           enclosed by the box.
  @note: Achieves identical functionality to `Acre` but implements it using 
         low-level pointer arithmetic instead of a variable overlay. By mapping 
         a `PInteger` to the object's raw memory address, it evaluates fields sequentially:
         `P^` is X1, `(P + 1)^` is Y1, `(P + 2)^` is X2, and `(P + 3)^` is Y2.
[==============================================================================}
function TBox.Domain: Integer; overload;
var
  P: PInteger;
begin
  P := @Self;
  Result := ((Abs((P + 2)^ - P^) + 1) * (Abs((P + 3)^ - (P + 1)^) + 1));
end;

{==============================================================================]
  <Extent>
  @action: Returns the total area of the box.
  @note: Computed as width * height, where width = (X2 - X1 + 1) and height
         = (Y2 - Y1 + 1). Result is Int64 to avoid overflow for large boxes.
         If the box has zero or negative width/height, area is 0.
[==============================================================================}
function TBox.Extent: Int64; overload;
begin
  Result := (Max(0, Int64((Self.X2 - Self.X1) + 1)) * Max(0, Int64((Self.Y2 - Self.Y1) + 1)));
end;


{==============================================================================]
  <Footprint>
  @action: Returns the total area of the box.
  @note: None.
[==============================================================================}
function TBox.Footprint: Double; overload;
begin
  Result := ((Abs(Self.X2 - Self.X1) + 1) * (Abs(Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Measure>
  @action: Returns the total area of the box.
  @note: ?
[==============================================================================}
function TBox.Measure: Int64; overload;
begin
  Result := (Max(0, Int64(Self.Width)) * Max(0, Int64(Self.Height)));
end;

{==============================================================================]
  <Px>
  @action: Calculates the total number of discrete pixel coordinates enclosed 
           by the bounding box, treating X2 and Y2 as inclusive boundaries.
  @note: Uses Int64 to prevent integer overflow on large boxes.
[==============================================================================}
function TBox.Px: Int64; overload;
begin
  with Self do
    Result := (((X2 - X1) + 1) * ((Y2 - Y1) + 1));
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
function TBox.Resolution: Int64; overload;
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

{==============================================================================]
  <Volume>
  @action: Returns number of integer lattice points in the box.
  @note: Guarantees non-negative result. Uses ABS to handle inverted boxes.
         Equivalent to (abs(X2-X1)+1) * (abs(Y2-Y1)+1) but with overflow protection.
[==============================================================================}
function TBox.Volume: Int64; overload;
begin
  Result := ((Abs(Int64(Self.X2) - Int64(Self.X1)) + 1) * (Abs(Int64(Self.Y2) - Int64(Self.Y1)) + 1));
end;

{==============================================================================]
  <WxH>
  @action: Calculates the total discrete pixel area by multiplying the box's 
           inclusive Width by its inclusive Height.
  @note: Since the Width and Height properties already incorporate the (+1) 
         offset for discrete pixel counting, this method yields the identical 
         numerical result as the Px method. It is simply a more explicit alias 
         that reads as "Width times Height". Uses Int64 to prevent overflow.
[==============================================================================}
function TBox.WxH: Int64; overload;
begin
  Result := (Int64(Self.Width) * Int64(Self.Height));
end;
{$ENDIF}
