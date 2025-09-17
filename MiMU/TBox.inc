{==============================================================================]
  <TBox.Create>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const minX, minY, maxX, maxY: Integer); overload;
begin
  X1 := minX;
  Y1 := minY;
  X2 := maxX;
  Y2 := maxY;
end;

{==============================================================================]
  <TBox.Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY) 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const top, bottom: TPoint); overload;
begin
  Self.Create(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <TBox.Create>
  @action: We simply build using  
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const valueX, valueY: Integer); overload;
begin
  Self.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <TBox.Create>
  @action: Creates TBox using target TPoint 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const target: TPoint); overload;
begin
  Self.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <TBox.Create>
  @action: We simply build using value. 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const value: Integer); overload;
begin
  Self.Create(value, value, value, value); 
end;

{==============================================================================]
  <TBoxHelper.Create>
  @action: Creates TBox(0,0,0,0).
  @note: None
[==============================================================================}
function TBoxHelper.Create: TBox; overload; cdecl;
begin
  Self.X1 := 0;
  Self.Y1 := 0;
  Self.X2 := 0;
  Self.Y2 := 0;
  Result := Self;  
end;

{==============================================================================]
  <TBox.Construct>
  @action: Constructs TBox with XS, YS, XE, YE.
  @note: None.
[==============================================================================}
class function TBox.Construct(const XS, YS, XE, YE: Integer): TBox; overload; cdecl;
begin
  Result.X1 := XS;
  Result.Y1 := YS;
  Result.X2 := XE;
  Result.Y2 := YE;
end;

{==============================================================================]
  <TBox.Build>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: Min-Maxed. Creates only valid TBoxes. Returns area.
[==============================================================================}
function TBox.Build(const minX, minY, maxX, maxY: Integer): Integer; overload; cdecl;
begin
  Self.X1 := Min(minX, maxX);
  Self.Y1 := Min(minY, maxY);
  Self.X2 := Max(maxX, minX);
  Self.Y2 := Max(maxY, minY);
  Result := Self.Area;
end;

{==============================================================================]
  <TBox.Build>
  @action: Builds TBox using 2 points (a = start point, b = end point)..
  @note: Make sure start and end points are correct!
[==============================================================================}
function TBox.Build(const top, bottom: TPoint): Integer; overload; cdecl;
begin
  Result := Self.Build(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <TBox.Build>
  @action: We simply build using  
  @note: Constructor.
[==============================================================================}
function TBox.Build(const valueX, valueY: Integer): Integer; overload; cdecl;
begin
  Result := Self.Build(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <TBox.Build>
  @action: Creates TBox using target TPoint
  @note: Constructor.
[==============================================================================}
function TBox.Build(const target: TPoint): Integer; overload; cdecl;
begin
  Result := Self.Build(target.X, target.Y, target.X, target.Y)
end;

{==============================================================================]
  <TBox.Build>
  @action: We simply build using value.
  @note: Constructor.
[==============================================================================}
function TBox.Build(const value: Integer = 0): Integer; overload; cdecl;
begin
  Result := Self.Build(value, value, value, value);
end;

{==============================================================================]
  <TBox.Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
begin
  Self.X1 := (pt.X - wRadius);
  Self.Y1 := (pt.Y - hRadius);
  Self.X2 := (pt.X + wRadius);
  Self.Y2 := (pt.Y + hRadius);
  Result := Self;
end;

{==============================================================================]
  <TBox.Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
begin
  Result := Self.Make(pt, radius, radius);
end;

{==============================================================================]
  <TBox.Form>
  @action: Creates box to point, with size for width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (size - 1));
  Self.Y2 := (pt.Y + (size - 1));
  Result := Self;
end;

{==============================================================================]
  <TBox.Form>
  @action: Creates box to point, with width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (width - 1));
  Self.Y2 := (pt.Y + (height - 1));
  Result := Self;
end;

{==============================================================================]
  <TBox.Frame>
  @action: Returns the frame of TBox 
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame(var width, height: Integer): TBox; overload; cdecl;
begin
  width := Self.Width;
  height := Self.Height;
  Result := Box(0, 0, (width - 1), (height - 1));
end;

{==============================================================================]
  <TBox.Frame>
  @action: Returns the frame of TBox 
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame: TBox; overload; cdecl;
begin
  Result := Box(0, 0, (Self.Width - 1), (Self.Height - 1));
end;

{==============================================================================]
  <TBox.Singular>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.Singular: Boolean; cdecl;
begin
  Result := ((Self.X1 = Self.X2) and (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <TBox.IsPoint>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.IsPoint: Boolean; cdecl;
begin
  Result := not ((Self.X1 <> Self.X2) or (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <TBox.IsHorizontalLine>
  @action: Returns true if TBox is horizontal line. (Width <> 1) and (Height = 1)
  @note: None.
[==============================================================================}
function TBox.IsHorizontalLine: Boolean; cdecl;
begin
  Result := ((Y1 = Y2) and (X1 <> X2));
end;

{==============================================================================]
  <TBox.IsVerticalLine>
  @action: Returns true if TBox is vertical line. (Width = 1) and (Height <> 1)
  @note: None.
[==============================================================================}
function TBox.IsVerticalLine: Boolean; cdecl;
begin
  Result := ((X1 = X2) and (Y1 <> Y2));
end;

{==============================================================================]
  <TBox.IsLine>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.IsLine: Boolean; cdecl;
begin
  Result := (Self.IsHorizontalLine or Self.IsVerticalLine);
end;

{==============================================================================]
  <TBox.Linear>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.Linear: Boolean; cdecl;
begin
  Result := (((Self.X1 = Self.X2) xor (Self.Y1 = Self.Y2)) and (not Self.IsPoint));
end;

{==============================================================================]
  <TBox.Is2D>
  @action: Returns true if TBox is valid rectangle with area.
  @note: None.
[==============================================================================}
function TBox.Is2D: Boolean; cdecl;
begin
  Result := ((Self.Width > 1) and (Self.Height > 1));
end;

{==============================================================================]
  <TBox.Collapsed>
  @action: Returns true if TBox is either point or a horizontal/vertical line.
  @note: Returns False if TBox is rectangle with workable area.
[==============================================================================}
function TBox.Collapsed: Boolean; cdecl;
begin
  Result := ((Self.X1 = Self.X2) or (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <TBox.Boxy>
  @action: Returns true if TBox is valid rectangle
  @note: None.
[==============================================================================}
function TBox.Boxy: Boolean; cdecl;
begin
  Result := ((Self.X1 <> Self.X2) and (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <TBox.Plural>
  @action: Returns true if TBox contains more than single point.
  @note: None.
[==============================================================================}
function TBox.Plural: Boolean; cdecl;
begin
  Result := ((Self.X2 > Self.X1) or (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <TBox.Rectangular>
  @action: Returns true if TBox width AND height are higher than 1.
  @note: (X2 > X1 and Y2 > Y1).
[==============================================================================}
function TBox.Rectangular: Boolean; cdecl;
begin
  Result := ((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <TBox.Equilateral>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Equilateral: Boolean; cdecl;
begin
  Result := ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1));
end;

{==============================================================================]
  <TBox.Square>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Square: Boolean; cdecl;
begin
  Result := (((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) and ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1)));
end;

{==============================================================================]
  <TBox.Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBox.Size(var width, height: Integer): Integer; overload; cdecl; inline;
begin
  width := Self.Width;
  height := Self.Height;
  Result := (width * height);
end;

{==============================================================================]
  <TBox.Size>
  @action: Returns TBox dimensions (Width and Height) as TPoint.
  @note: X = Width, Y = Height.
[==============================================================================}
function TBox.Size: TPoint; overload; cdecl;
begin
  Result := Point(Self.Width, Self.Height);
end;

{==============================================================================]
  <TBox.Area>
  @action: Calculates the amount of pixels in TBox (bx).
           Returns -1 with invalid TBox.
  @note: None
[==============================================================================}
function TBox.Area: Integer; cdecl; inline;
begin
  Result := (Self.Width * Self.Height);
end;

{==============================================================================]
  <TBox.Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer; cdecl;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
end;

{==============================================================================]
  <TBox.Perim>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perim: Integer; cdecl;
begin
  Result := (2 * (Pred(Self.Width) + Pred(Self.Height)));
end;

{==============================================================================]
  <TBox.Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer; cdecl;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <TBox.Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double; cdecl;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <TBox.Width>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Width: Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <TBox.Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBox.Width(const w: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (w - 1));
end;

{==============================================================================]
  <TBox.Height>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Height: Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <TBox.Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBox.Height(const h: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (h - 1));
end;

{==============================================================================]
  <TBox.Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange; cdecl;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
end;

{==============================================================================]
  <TBox.Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double; cdecl;
begin
  Result := (Self.Width / Self.Height);
end;

{==============================================================================]
  <TBox.Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange; cdecl;
begin
  Result.start := Self.Y1;
  Result.stop := Self.Y2;
end;

{==============================================================================]
  <TBox.Expand>
  @action: Returns bx that has been expanded fully by change.
  @note: Works with positive values only.
[==============================================================================}
function TBox.Expand(const change: Integer = 1): TBox; cdecl;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox.Shrink>
  @action: Returns bx that has been shrinked fully by change.
  @note: Works with positive values only. UNSAFE method, no checks!
[==============================================================================}
function TBox.Shrink(const change: Integer = 1): TBox; cdecl;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 + change);
  Result.Y1 := (Self.Y1 + change);
  Result.X2 := (Self.X2 - change);
  Result.Y2 := (Self.Y2 - change);
end;

{==============================================================================]
  <TBox.Resize>
  @action: Returns bx that has been resized fully by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.Resize(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox.ResizeVertically>
  @action: Returns bx that has been resized vertically by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeVertically(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox_ResizeHorizontally>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeHorizontally(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeTop>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTop(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeBottom>
  @action: Returns bx that has been resized from bottom by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottom(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox.ResizeLeft>
  @action: Returns bx that has been resized from left-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeRight>
  @action: Returns bx that has been resized from right-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeTopLeft>
  @action: Returns bx that has been resized from top-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeTopRight>
  @action: Returns bx that has been resized from top-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ResizeBottomRight>
  @action: Returns bx that has been resized from bottom-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox.ResizeBottomLeft>
  @action: Returns bx that has been resized from bottom-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox.Equal>
  @action: Returns true if bx1 and bx2 are identical.
  @note: None
[==============================================================================}
function TBox.Equal(const b: TBox): Boolean; cdecl; inline;
begin
  Result := ((Self.X1 = b.X1) and (Self.Y1 = b.Y1) and (Self.X2 = b.X2) and (Self.Y2 = b.Y2));
end;  

{==============================================================================]
  <TBox.Contains>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TBox.Contains(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := not ((pt.X < Self.X1) or (pt.Y < Self.Y1) or (pt.X > Self.X2) or (pt.Y > Self.Y2));
end;

{==============================================================================]
  <TBox.Contains>
  @action: Returns true if x is in/within bx boundaries.
  @note: None
[==============================================================================}
function TBox.Contains(const b: TBox): Boolean; overload; cdecl;
begin
  Result := ((b.X1 >= Self.X1) and (b.X1 <= Self.X2) and (b.X2 >= Self.X1) and (b.X2 <= Self.X2) and (b.Y1 >= Self.Y1) and (b.Y1 <= Self.Y2) and (b.Y2 >= Self.Y1) and (b.Y2 <= Self.Y2));
end;

{==============================================================================]
  <TBox.Inside>
  @action: Returns true if bx is INSIDE target boundaries.
  @note: None.
[==============================================================================}
function TBox.Inside(const target: TBox): Boolean; overload; cdecl;
begin
  Result := not ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <TBoxHelper.Inside>
  @action: Returns true if bx is in/within any area boundaries by target areas.
  @note: None.
[==============================================================================}
function TBoxHelper.Inside(const targets: TBoxArray): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(targets) do
    if not ((Self.X2 < targets[i].X1) or (Self.X1 > targets[i].X2) or (Self.Y2 < targets[i].Y1) or (Self.Y1 > targets[i].Y2)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TBox.Disjoint>
  @action: Returns true if target TBox is outside the target boundaries.
  @note: None.
[==============================================================================}
function TBox.Disjoint(const target: TBox): Boolean; overload; cdecl;
begin
  Result := ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <TBox.Lacks>
  @action: Returns true if pt TPoint is OUTSIDE the TBox boundaries.
  @note: None.
[==============================================================================}
function TBox.Lacks(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := ((pt.X > Self.X2) or (pt.Y > Self.Y2) or (pt.X < Self.X1) or (pt.Y < Self.Y1));
end;

{==============================================================================]
  <TBoxHelper.Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBox.Center: TPoint; cdecl;
begin
  Result.X := Round(Self.X1 + ((Self.Width - 1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Height - 1) div 2));
end;

{==============================================================================]
  <TBoxHelper.Envelope>
  @action: Bounds 2 boxes (a and b) to 1 box.
  @note: Based on lowest / highest coordinate values.
[==============================================================================}
function TBox.Envelope(const b: TBox): TBox; cdecl;
begin
  Result.X1 := Min(Min(Self.X1, Self.X2), Min(b.X1, b.X2));
  Result.Y1 := Min(Min(Self.Y1, Self.Y2), Min(b.Y1, b.Y2));
  Result.X2 := Max(Max(Self.X1, Self.X2), Max(b.X1, b.X2));
  Result.Y2 := Max(Max(Self.Y1, Self.Y2), Max(b.Y1, b.Y2));
end;

{==============================================================================]
  <TBox.Overlap>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Overlap(const b: TBox): Boolean; cdecl; inline;
begin
  Result := not ((Self.X1 > b.X2) or (Self.X2 < b.X1) or (Self.Y1 > b.Y2) or (Self.Y2 < b.Y1));
end;

{==============================================================================]
  <TBox.Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox): TBox; overload; cdecl;
begin
  Result.X1 := Max(Self.X1, b.X1);
  Result.Y1 := Max(Self.Y1, b.Y1);
  Result.X2 := Min(Self.X2, b.X2);
  Result.Y2 := Min(Self.Y2, b.Y2);
end;

{==============================================================================]
  <TBox.Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox; var iArea: TBox): Boolean; overload; cdecl;
begin
  iArea := Self.Intersect(b);
  Result := not ((iArea.X1 > iArea.X2) or (iArea.Y1 > iArea.Y2));
end;

{==============================================================================]
  <TBox_Valid>
  Explanation: Returns true if TBox is valid (X1 <= X2 and Y1 <= Y2)
  Example: None.
[==============================================================================}
function TBox.Valid: Boolean; cdecl; inline;
begin
  Result := ((Self.X1 <= Self.X2) and (Self.Y1 <= Self.Y2));
end;

{==============================================================================]
  <TBox.Invalid>
  Explanation: Returns true if TBox is invalid (X1 > X2 or Y1 > Y2)
  Example: None.
[==============================================================================}
function TBox.Invalid: Boolean; cdecl;
begin
  Result := ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2));
end;

{==============================================================================]
  <TBox_Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within maxWDiff (max width differency) and maxHDiff (max height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(b.Width - Self.Width) <= maxWDiff) and (Abs(b.Height- Self.Height) <= maxHDiff));
end;

{==============================================================================]
  <TBox.Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within diff (max width and height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const diff: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(b.Width - Self.Width) <= diff) and (Abs(b.Height - Self.Height) <= diff));
end;

{==============================================================================]
  <TBox.Fix>
  Explanation: Fixes the bx. Swaps incorrectly set values (XS/YS > XE/YE).
               Returns true if bx was fixed.
  Example: (200*, 100, 100*, 200) => (100, 100, 200, 200)
[==============================================================================}
function TBox.Fix: Boolean; cdecl;
var
  x, y: Boolean;
begin
  x := (Self.X1 > Self.X2);
  y := (Self.Y1 > Self.Y2); 
  Result := (x or y);
  if not Result then
    Exit;
  if x then
    Swap(Self.X1, Self.X2);
  if y then
    Swap(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <TBox.Constraint>
  Explanation: Constraints bx to area.
  Example: None.
[==============================================================================}
function TBox.Constraint(const toArea: TBox): Boolean; cdecl;
var
  b: TBox;
begin
  b := Self;
  Self.X1 := Max(toArea.X1, Min(toArea.X2, Self.X1));
  Self.Y1 := Max(toArea.Y1, Min(toArea.Y2, Self.Y1));
  Self.X2 := Max(toArea.X1, Min(toArea.X2, Self.X2));
  Self.Y2 := Max(toArea.Y1, Min(toArea.Y2, Self.Y2));
  Result := (Self <> b);
end;

{==============================================================================]
  <TBox.Clip>
  Explanation: Returns bx that has been constrained to area.
  Example: None.
[==============================================================================}
function TBox.Clip(const toArea: TBox): TBox; cdecl;
begin
  Result.X1 := Max(toArea.X1, Min(toArea.X2, Self.X1));
  Result.Y1 := Max(toArea.Y1, Min(toArea.Y2, Self.Y1));
  Result.X2 := Max(toArea.X1, Min(toArea.X2, Self.X2));
  Result.Y2 := Max(toArea.Y1, Min(toArea.Y2, Self.Y2));
end;

{==============================================================================]
  <TBox_Restrict>
  Explanation: Restricts bx to area.
  Example: None.
[==============================================================================}
function TBox.Restrict(const toArea: TBox): Boolean; cdecl;
var
  b: TBox;
begin
  b := Self;
  if (Self.X1 < toArea.X1) then
    Self.X1 := toArea.X1
  else
    if (Self.X1 > toArea.X2) then
      Self.X1 := toArea.X2;
  if (Self.Y1 < toArea.Y1) then
    Self.Y1 := toArea.Y1
  else
    if (Self.Y1 > toArea.Y2) then
      Self.Y1 := toArea.Y2;
  if (Self.X2 > toArea.X2) then
    Self.X2 := toArea.X2
  else
    if (Self.X2 < toArea.X1) then
      Self.X2 := toArea.X1;
  if (Self.Y2 > toArea.Y2) then
    Self.Y2 := toArea.Y2
  else
    if (Self.Y2 < toArea.Y1) then
      Self.Y2 := toArea.Y1;
  Result := (Self <> b);
end;

{==============================================================================]
  <TBox_Clamp>
  Explanation: Returns bx that has been restricted to area.
  Example: None.
[==============================================================================}
function TBox.Clamp(const toArea: TBox): TBox; cdecl;
begin
  if (Self.X1 < toArea.X1) then
    Result.X1 := toArea.X1
  else
    if (Self.X1 > toArea.X2) then
      Result.X1 := toArea.X2
    else
      Result.X1 := Self.X1;
  if (Self.Y1 < toArea.Y1) then
    Result.Y1 := toArea.Y1
  else
    if (Self.Y1 > toArea.Y2) then
      Result.Y1 := toArea.Y2
    else
      Result.Y1 := Self.Y1;
  if (Self.X2 > toArea.X2) then
    Result.X2 := toArea.X2
  else
    if (Self.X2 < toArea.X1) then
      Result.X2 := toArea.X1
    else
      Result.X2 := Self.X2;
  if (Self.Y2 > toArea.Y2) then
    Result.Y2 := toArea.Y2
  else
    if (Self.Y2 < toArea.Y1) then
      Result.Y2 := toArea.Y1
    else
      Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox_Points>
  Explanation: Returns TBox points as TPointArray.
  Example: None.
[==============================================================================}
function TBox.Points: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result[r.Increase].Create(x, y);
end;

{==============================================================================]
  <TBox.Pixels>
  Explanation: Returns TBox points as TPointArray.
  Example: None.
[==============================================================================}
function TBox.Pixels: TPointArray; cdecl;
var
  w, h, s, x, y, i: Integer;
  p: TPointArray;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(p, w);
  for x := 0 to (w - 1) do
    p[x].X := (Self.X1 + x);
  s := (w * SizeOf(TPoint));
  i := 0;
  for y := Self.Y1 to Self.Y2 do
  begin
    for x := 0 to (w - 1) do
      p[x].Y := y;
    Move(p[0], Result[i.Increase(w)], s);
  end;
end;

{==============================================================================]
  <TBox.TPA>
  Explanation: Returns TBox points as TPointArray.
  Example: None.
[==============================================================================}
function TBox.TPA: TPointArray; cdecl;
var
  i, j: Integer;
begin
  SetLength(Result, Self.Size(j, i));
  for i := 0 to High(Result) do
    Result[i].Create((Self.X1 + (i mod j)), (Self.Y1 + (i div j)));
end;

{==============================================================================]
  <TBox.Contents>
  Explanation: Returns TBox points as TPointArray.
  Example: Fast, Pointer-based alternative
[==============================================================================}
function TBox.Contents: TPointArray; cdecl;
var
  p: PPoint;
  x, y: Integer;
begin
  SetLength(Result, Self.Area);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
    begin
      p^.X := x;
      p^.Y := y;
      Inc(p);
    end;
end;

{==============================================================================]
  <TBox.Extract>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method for Points(), TPA() and Contents().
[==============================================================================}
function TBox.Extract: TPointArray; cdecl;
var
  x, y, i: Integer;
begin
  SetLength(Result, Self.Area);
  i := 0;
  y := Self.Y1;
  repeat
    x := Self.X1;
    repeat
      Result[i.Increase] := Point(x, y);
    until (x.Increment > Self.X2);
  until (y.Increment > Self.Y2);
end;

{==============================================================================]
  <TBox.Enumerate>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method.
[==============================================================================}
function TBox.Enumerate: TPointArray; cdecl;
var
  x, y: Integer;
begin
  SetLength(Result, 0);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result := (Result + [Point(x, y)]);
end;

{==============================================================================]
  <TBox.Elements>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method.
[==============================================================================}
function TBox.Elements: TPointArray; cdecl;
var
  p: specialize TList<TPoint>;
  x, y: Integer;
begin
  p := specialize TList<TPoint>.Create;
  try
    for y := Self.Y1 to Self.Y2 do
      for x := Self.X1 to Self.X2 do
        p.Add(Point(x, y));
    Result := p.ToArray;
  finally
    p.Free;
  end;
end;

{==============================================================================]
  <TBox.Border>
  Explanation: Returns TBox border points as TPointArray.
  Example: Skips all the inside points.
[==============================================================================}
function TBox.Border: TPointArray; overload; cdecl;
var
  x, y, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for x := Self.X1 to Self.X2 do
    Result[i.Increase] := Point(x, Self.Y1);
  for y := (Self.Y1 + 1) to (Self.Y2 - 1) do
    Result[i.Increase] := Point(Self.X2, y);
  for x := Self.X2 downto Self.X1 do
    Result[i.Increase] := Point(x, Self.Y2);
  for y := (Self.Y2 - 1) downto (Self.Y1 + 1) do
    Result[i.Increase] := Point(Self.X1, y);
end;

function TBox.Border(const X, Y: Integer): Boolean; overload; cdecl;
begin
  with Self do
    Result := ((((X = X1) or (X = X2)) and ((Y >= Y1) and (Y <= Y2))) or (((Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2))));
end;

function TBox.Border(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := Self.Border(pt.X, pt.Y);
end;

{==============================================================================]
  <TBox.Edge>
  Explanation: Returns TBox edge points as TPointArray.
  Example: Skips all the inside points.
[==============================================================================}
function TBox.Edge: TPointArray; overload; cdecl;
var
  i, d, s: Integer;
  p: TPoint;
  c: TPointArray;
begin
  Self.Size(i, d);
  if ((i = 1) or (d = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (i + d)) - 4));
  p := Point(Self.X1, Self.Y1);
  i := 0;
  c := [Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)];
  for d := 0 to 3 do
  begin
    if ((d mod 2) = 0) then
      s := (Self.X2 - Self.X1)
    else
      s := (Self.Y2 - Self.Y1);
    while (s > 0) do
    begin
      Result[i.Increase] := p;
      if (s.Decrease >= 0) then
        p := Point(p.X + c[d].X, p.Y + c[d].Y);
    end;
  end;
end;

function TBox.Edge(const X, Y: Integer): Boolean; overload; cdecl;
begin
  with Self do
    Result := (((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2) and (Y >= Y1) and (Y <= Y2)));
end;

function TBox.Edge(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := Self.Edge(pt.X, pt.Y);
end;

{==============================================================================]
  <TBox.Outline>
  Explanation: Returns TBox outline points as TPointArray.
  Example: Skips all the inside points.
[==============================================================================}
function TBox.Outline: TPointArray; overload; cdecl;
var
  x, y, i, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w = 1) or (h = 1)) then
    Exit(Self.Points);
  SetLength(Result, ((2 * (w + h)) - 4));
  i := 0;
  for x := Self.X1 to Self.X2 do
  begin
    Result[i.Increase] := Point(x, Self.Y1);
    Result[i.Increase] := Point(x, Self.Y2);
  end;
  for y := (Self.Y1 + 1) to (Self.Y2 - 1) do
  begin
    Result[i.Increase] := Point(Self.X1, y);
    Result[i.Increase] := Point(Self.X2, y);
  end;
end;

function TBox.Outline(const X, Y: Integer): Boolean; overload; cdecl;
begin
  Result := ((not ((X < X1) or (X > X2) or (Y < Y1) or (Y > Y2))) and ((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)));
end;

function TBox.Outline(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := Self.Outline(pt.X, pt.Y);
end;

{==============================================================================]
  <TBox.Contour>
  Explanation: Returns TBox contour points as TPointArray.
  Example: Skips all the inside points.
[==============================================================================}
function TBox.Contour: TPointArray; cdecl;
var
  z: TIntegerArray;
  s: TSegment;
  i, l: Integer;
begin
  if not Self.Rectangular then
    Exit(Self.Points);
  SetLength(Result, Self.Circumference);
  z := [Self.X1, Self.Y1, Self.X2, Self.Y1, Self.X2, (Self.Y1 + 1), Self.X2, Self.Y2, (Self.X2 - 1), Self.Y2, Self.X1, Self.Y2, Self.X1, (Self.Y2 - 1), Self.X1, (Self.Y1 + 1)];
  l := 0;
  for i := 0 to 3 do
    l := Result.Blit(s.Create(z[(i * 4)], z[(i * 4) + 1], z[(i * 4) + 2], z[(i * 4) + 3]).Points, l);
end;

{==============================================================================]
  <TBox.Spiral>
  Explanation: Returns TBox TPoints as spiral shaped TPointArray.
  Example: Alternative for TBox.Traverse.
[==============================================================================}
function TBox.Spiral: TPointArray; cdecl;
var
  b: TBox;
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  b := Self;
  r := 0;
  repeat
    for x := b.X1 to b.X2 do
      Result[r.Increase] := Point(x, b.Y1);
    Inc(b.Y1);
    for y := b.Y1 to b.Y2 do
      Result[r.Increase] := Point(b.X2, y);
    Dec(b.X2);
    if (b.Y1 <= b.Y2) then
    begin
      for x := b.X2 downto b.X1 do
        Result[r.Increase] := Point(x, b.Y2);
      Dec(b.Y2);
    end;
    if (b.X1 <= b.X2) then
    begin
      for y := b.Y2 downto b.Y1 do
        Result[r.Increase] := Point(b.X1, y);
      Inc(b.X1);
    end;
  until ((b.X1 > b.X2) or (b.Y1 > b.Y2));
end;

{==============================================================================]
  <TBox.Traverse>
  Explanation: Returns TBox TPoints as spiral shaped TPointArray.
  Example: Alternative for TBox.Spiral.
[==============================================================================}
function TBox.Traverse: TPointArray; cdecl;
var
  m: T2DBooleanArray;
  c: TPoint;
  z, i: Integer;
  x, y: TIntegerArray;
begin
  x := [1, 0, -1, 0];
  y := [0, 1, 0, -1];
  SetLength(Result, Self.Area);
  m := T2D.Create(False, Self.Width, Self.Height);
  c := Point(Self.X1, Self.Y1);
  z := 0;
  for i := 0 to High(Result) do
  begin
    Result[i] := c;
    m[(c.X - Self.X1), (c.Y - Self.Y1)] := True;
    if (((c.X + x[z]) < Self.X1) or ((c.X + x[z]) > Self.X2) or
       ((c.Y + y[z]) < Self.Y1) or ((c.Y + y[z]) > Self.Y2) or
       m[((c.X + x[z]) - Self.X1), ((c.Y + y[z]) - Self.Y1)]) then
      z := ((z + 1) mod 4);
    c.X := (c.x + x[z]);
    c.Y := (c.y + y[z]);
  end;
end;

{==============================================================================]
 <TBoxHelper.Grid>
 @action: Outputs/builds grid of boxes with parameters;
          bx = starting box, used for starting coordinates and also for dimensions (width & height) of the boxes.
          rows, columns = count of rows and columns
          spaceHorizontal = space between columns
          spaceVertical = space between rows
 @note: None.
[==============================================================================}
function TBoxHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
var
  w, h, r, c, i, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    Self.Size(w, h);
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y1 + (r * (h + spaceVertical)));
      for c := 0 to (columns - 1) do
      begin
        i := ((r * columns) + c);
        x := (Self.X1 + (c * (w + spaceHorizontal)));
        Result[i].Build(x, y, (x + (w - 1)), (y + (h - 1)));
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBoxHelper.Row>
 @action: Outputs row of boxes. Starting from bx,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TBoxHelper.Row(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    Self.Size(w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.X1 + (i * (w + space)));
      Result[i].Build(z, Self.Y1, (z + (w - 1)), Self.Y2);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBoxHelper.Column>
 @action: Outputs column of boxes. Starting from bx,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TBoxHelper.Column(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    Self.Size(w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.Y1 + (i * (h + space)));
      Result[i].Build(Self.X1, z, Self.X2, (z + (h - 1)));
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBox.Rows>
 @action: Returns TBox as its rows of TPoints.
 @note: Row-major. Dimensions = [Height][Width].
[==============================================================================}
function TBox.Rows: T2DPointArray; cdecl;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Height, Self.Width);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result[y - Self.Y1][x - Self.X1] := Point(x, y);
end;

{==============================================================================]
 <TBox.Columns>
 @action: Returns TBox as its columns of TPoints.
 @note: Column-major. Dimensions = [Width][Height].
[==============================================================================}
function TBox.Columns: T2DPointArray; cdecl;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Width, Self.Height);
  for x := Self.X1 to Self.X2 do
    for y := Self.Y1 to Self.Y2 do
      Result[x - Self.X1][y - Self.Y1] := Point(x, y);
end;

{==============================================================================]
 <TBox.Rowwise>
 @action: Returns all TBox TPoints as Row-wise.
 @note: None.
[==============================================================================}
function TBox.Rowwise: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for y := Y1 to Y2 do
    for x := X1 to X2 do
      Result[r.Increase] := Point(x, y);
end;

{==============================================================================]
 <TBox.Columnwise>
 @action: Returns all TBox TPoints as Column-wise.
 @note: None.
[==============================================================================}
function TBox.Columnwise: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, Self.Area);
  r := 0;
  for x := X1 to X2 do
    for y := Y1 to Y2 do
      Result[r.Increase] := Point(x, y);
end;

{==============================================================================]
 <TBox.CornerPoints>
 @action: Returns all 4 corner points of bx.
 @note: None
[==============================================================================}
function TBox.CornerPoints: TPointArray; cdecl;
begin
  SetLength(Result, 4);
  Result[0].X := Self.X1;
  Result[0].Y := Self.Y1;
  Result[1].X := Self.X2;
  Result[1].Y := Self.Y1;
  Result[2].X := Self.X2;
  Result[2].Y := Self.Y2;
  Result[3].X := Self.X1;
  Result[3].Y := Self.Y2;
end;

{==============================================================================]
 <TBox.CornerPts>
 @action: Returns all 4 corner points of bx.
 @note: Gives also duplicates, if TBox is not rectangular.
[==============================================================================}
function TBox.CornerPts: TPointArray; cdecl;
begin
  Result := [Point(Self.X1, Self.Y1), Point(Self.X2, Self.Y1), Point(Self.X2, Self.Y2), Point(Self.X1, Self.Y2)];
end;

{==============================================================================]
 <TBox.Corners>
 @action: Returns corner points of bx.
 @note: Outputs only unique TPoints.
[==============================================================================}
function TBox.Corners: TPointArray; cdecl;
var
  p: TPoint;
begin
  SetLength(Result, 0);
  case ((Ord(Boolean(Self.X1 = Self.X2)) shl 1) or Ord(Boolean(Self.Y1 = Self.Y2))) of
    0: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1), p.Create(Self.X2, Self.Y2), p.Create(Self.X1, Self.Y2)];
    1: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1)];
    2: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X1, Self.Y2)];
    3: Result := [p.Create(Self.X1, Self.Y1)];
  end;
end;

{==============================================================================]
  <TBox.SimilarSize>
  @action: Returns true if the size from boxes a and b
           are within widthDifferency and heightDifferency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(b.Width - Self.Width) <= widthDifferency) and (Abs(b.Height - Self.Height) <= heightDifferency));
end;

{==============================================================================]
  <TBox.SimilarSize>
  Explanation: Returns true if the size from boxes a and b
               are within differency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(b.Width - Self.Width) <= differency) and (Abs(b.Width - Self.Width) <= differency));
end;

{==============================================================================]
  <TBox.Centered>
  Explanation: Returns bx (by the dimensions) centered to area.
  @note: None.
[==============================================================================}
function TBox.Centered(const toArea: TBox): TBox; cdecl;
var
  w, h: Integer;
begin
  Self.Size(w, h);
  Result.X1 := (toArea.X1 + ((toArea.Width - w) div 2));
  Result.Y1 := (toArea.Y1 + ((toArea.Height - h) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <TBox.CenterVertically>
  Explanation: Returns bx centered vertically to area.
  @note: None.
[==============================================================================}
function TBox.CenterVertically(const toArea: TBox): TBox; cdecl;
var
  h: Integer;
begin
  h := Self.Height;
  Result.X1 := Self.X1;
  Result.Y1 := (toArea.Y1 + ((toArea.Height - h) div 2));
  Result.X2 := Self.X2;
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <TBox.CenterHorizontally>
  Explanation: Returns bx centered horizontally to area.
  @note: None.
[==============================================================================}
function TBox.CenterHorizontally(const toArea: TBox): TBox; cdecl;
var
  w: Integer;
begin
  w := Self.Width;
  Result.X1 := (toArea.X1 + ((toArea.Width - w) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y1 := Self.Y1;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox.ExtendX>
  Explanation: Returns true if TBox is changed with xCoord (X1 or X2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendX(const xCoord: Integer): Boolean; cdecl;
begin
  if (xCoord < Self.X1) then
    Self.X1 := xCoord
  else
    if (xCoord > Self.X2) then
      Self.X2 := xCoord
    else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TBox.ExtendY>
  Explanation: Returns true if TBox is changed with yCoord (Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendY(const yCoord: Integer): Boolean; cdecl;
begin
  if (yCoord < Self.Y1) then
    Self.Y1 := yCoord
  else
    if (yCoord > Self.Y2) then
      Self.Y2 := yCoord
    else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TBox.Extend>
  Explanation: Returns true if TBox is changed with pt (X1, X2, Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.Extend(const pt: TPoint): Boolean; cdecl;
var
  w, h: Boolean;
begin
  w := Self.ExtendX(pt.X);
  h := Self.ExtendY(pt.Y);
  Result := (w or h);
end;

{==============================================================================]
  <TBox.UnionX>
  Explanation: Returns the TBox Self with X-value extended (if xCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionX(const xCoord: Integer): TBox; cdecl;
begin
  if (xCoord < Self.X1) then
    Result := Box(xCoord, Self.Y1, Self.X2, Self.Y2)
  else
    if (xCoord > Self.X2) then
      Result := Box(Self.X1, Self.Y1, xCoord, Self.Y2)
    else
      Result := Self;
end;

{==============================================================================]
  <TBox.UnionY>
  Explanation: Returns the TBox Self with Y-value extended (if yCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionY(const yCoord: Integer): TBox; cdecl;
begin
  if (yCoord < Self.Y1) then
    Result := Box(Self.X1, yCoord, Self.X2, Self.Y2)
  else
    if (yCoord > Self.Y2) then
      Result := Box(Self.X1, Self.Y1, Self.X2, yCoord)
    else
      Result := Self;
end;

{==============================================================================]
  <TBox.Union>
  Explanation: Returns the Self unioned with pt.
  @note: None.
[==============================================================================}
function TBox.Union(const pt: TPoint): TBox; overload; cdecl;
begin
  Result := Self.UnionX(pt.X).UnionY(pt.Y);
end;

{==============================================================================]
  <TBox.Union>
  @action: Returns union of a and b TBoxes
  @note: None
[==============================================================================}
function TBox.Union(const b: TBox): TBox; overload; cdecl;
begin
  Result.X1 := Min(Self.X1, b.X1);
  Result.Y1 := Min(Self.Y1, b.Y1);
  Result.X2 := Max(Self.X2, b.X2);
  Result.Y2 := Max(Self.Y2, b.Y2);
end;

{==============================================================================]
  <TBox.Shake>
  @action: Returns TBox randomly shaked as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shake(const shakes: Integer = 1): TPointArray; cdecl;
var
  i, s: Integer;
begin
  Result := Self.Points;
  for s := 1 to shakes do
    for i := 0 to Random(Result.Size) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <TBox.Shuffle>
  @action: Returns TBox randomly shuffled as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shuffle(const shuffles: Integer = 1): TPointArray; cdecl;
var
  i, s: Integer;
begin
  Result := Self.Points;
  for s := 1 to shuffles do
    for i := 0 to High(Result) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <TBox.Any>
  @action: Returns random TBox point.
  @note: None.
[==============================================================================}
function TBox.Any: TPoint; cdecl;
begin
  Result := Point((Self.X1 + Random(Self.Width)), (Self.X1 + Random(Self.Height)));
end;

{==============================================================================]
  <TBox.Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some: TPointArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Area + 1), 1));
end;

{==============================================================================]
  <TBox.Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some(const amount: Integer): TPointArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Area)));
end;

{==============================================================================]
  <_TBox.Create>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: function version
[==============================================================================}
class function _TBox.Create(const minX, minY, maxX, maxY: Integer): TBox; overload; cdecl;
begin
  Result.X1 := minX;
  Result.Y1 := minY;
  Result.X2 := maxX;
  Result.Y2 := maxY;
end;

{==============================================================================]
  <_TBox.Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY) 
  @note: Constructor.
[==============================================================================}
class function _TBox.Create(const top, bottom: TPoint): TBox; overload; cdecl;
begin
  Result := _TBox.Create(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <_TBox.Create>
  @action: We simply build using  
  @note: Function.
[==============================================================================}
class function _TBox.Create(const valueX, valueY: Integer): TBox; overload; cdecl;
begin
  Result := _TBox.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <_TBox.Create>
  @action: Creates TBox using target TPoint 
  @note: Function.
[==============================================================================}
class function _TBox.Create(const target: TPoint): TBox; overload; cdecl;
begin
  Result := _TBox.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <_TBox.Create>
  @action: We simply build using value. 
  @note: Constructor.
 
[==============================================================================}
class function _TBox.Create(const value: Integer = 0): TBox; overload; cdecl;
begin
  Result := _TBox.Create(value, value, value, value);
end;
