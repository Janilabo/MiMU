{$DEFINE TBox}{$I ..\Configuration\Defines.inc}

{$IFDEF TYPES}
TBoxEnumerator = record
private
  FX, FY, XStart, YStart, XStop, YStop: Integer;
  FFirst: Boolean;
public
  constructor Init(const AX1, AY1, AX2, AY2: Integer);
  function MoveNext: Boolean;
  function GetCurrent: TPoint;
  property Current: TPoint read GetCurrent;
end;
TBox = record
  X1, Y1, X2, Y2: Integer;
  function GetEnumerator: TBoxEnumerator;
  constructor Create(const minX, minY, maxX, maxY: Integer); overload;
  constructor Create(const top, bottom: TPoint); overload;
  constructor Create(const valueX, valueY: Integer); overload;
  constructor Create(const target: TPoint); overload;
  constructor Create(const value: Integer); overload;
  class function Construct(const XS, YS, XE, YE: Integer): TBox; overload; static;
  class function Null(const value: Integer = -2147483648): TBox; overload; static;
  function Build(const minX, minY, maxX, maxY: Integer): Integer; overload; 
  function Build(const top, bottom: TPoint): Integer; overload; 
  function Build(const valueX, valueY: Integer): Integer; overload; 
  function Build(const target: TPoint): Integer; overload; 
  function Build(const value: Integer = 0): Integer; overload; 
  function Init(const bX1, bY1, bX2, bY2: Integer): TBox; overload; 
  function Init(const b: TBox): TBox; overload; 
  function Init(const val: Integer = 0): TBox; overload; 
  function Init(const p: TPoint): TBox; overload; 
  function Init(const TL, BR: TPoint): TBox; overload; 
  function Form(const pt: TPoint; const size: Integer = 1): TBox; overload; 
  function Form(const pt: TPoint; const width, height: Integer): TBox; overload; 
  function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; 
  function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; 
  function Frame(var width, height: Integer): TBox; overload; 
  function Frame: TBox; overload;  
  function Singular: Boolean; 
  function IsPoint: Boolean; 
  function IsHorizontalLine: Boolean; 
  function IsVerticalLine: Boolean; 
  function IsLine: Boolean; 
  function Linear: Boolean; 
  function Is2D: Boolean; 
  function Collapsed: Boolean; 
  function Boxy: Boolean; 
  function Plural: Boolean; 
  function Rectangular: Boolean; 
  function Equilateral: Boolean; 
  function Square: Boolean; 
  function Size(var width, height: Integer): Integer; overload; inline;
  function Size: TPoint; overload; 
  function Area: Integer; inline;
  function Capacity: Integer; 
  function Footprint: Double; 
  function Perimeter: Integer; 
  function Perim: Integer; 
  function Circumference: Integer; 
  function Diagonal: Double; 
  function Width: Integer; overload; 
  function Width(const w: Integer): Integer; overload; 
  function Height: Integer; overload; 
  function Height(const h: Integer): Integer; overload; 
  function Ratio: Double; 
  function Horizontal: TRange; 
  function Vertical: TRange; 
  function Expand(const change: Integer = 1): TBox; overload; 
  function Expand(const target: TBox): TBox; overload; 
  function Shrink(const change: Integer = 1): TBox; overload; 
  function Shrink(const target: TBox): TBox; overload; 
  function Resize(const change: Integer): TBox; 
  function ResizeVertically(const change: Integer): TBox; 
  function ResizeHorizontally(const change: Integer): TBox; 
  function ResizeTop(const change: Integer): TBox; 
  function ResizeBottom(const change: Integer): TBox; 
  function ResizeLeft(const change: Integer): TBox; 
  function ResizeRight(const change: Integer): TBox; 
  function ResizeTopLeft(const change: Integer): TBox; 
  function ResizeTopRight(const change: Integer): TBox; 
  function ResizeBottomRight(const change: Integer): TBox; 
  function ResizeBottomLeft(const change: Integer): TBox; 
  function Equal(const b: TBox): Boolean; inline;
  function Contains(const pt: TPoint): Boolean; overload; 
  function Contains(const b: TBox): Boolean; overload; 
  function Center: TPoint; 
  function Envelope(const b: TBox): TBox; 
  function Overlap(const b: TBox): Boolean; inline;
  function Intersect(const b: TBox): TBox; overload; 
  function Intersect(const b: TBox; var iArea: TBox): Boolean; overload; 
  function Valid: Boolean; inline;
  function Invalid: Boolean; 
  function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; 
  function Similar(const b: TBox; const diff: Integer): Boolean; overload; 
  function Fix: Boolean; 
  function Constraint(const toArea: TBox): Boolean; 
  function Clip(const toArea: TBox): TBox; 
  function Restrict(const toArea: TBox): Boolean; 
  function Clamp(const toArea: TBox): TBox;
  function Unzip(var bX1, bY1, bX2, bY2: Integer): Integer; overload;	
  function Unzip: TPointArray; overload;
  function Unpack: TPointArray; overload;
  function Unbox: TPointArray; overload;
  function Points: TPointArray; overload; 
  function Points(const pIndex: Integer): TPoint; overload; 
  function Points(const pIDs: TIntegerArray): TPointArray; overload; 
  function Points(var xArray, yArray: TIntegerArray): Integer; overload; 
  function Pixels: TPointArray; overload; 
  function Pixels(const index: Integer): TPoint; overload; 
  function Pixeled: TPointArray; overload; 
  function Pts: TPointArray; overload;
  function Explode: TPointArray; overload; 
  function Flat: TPointArray; overload; 	
  function IDs: TIntegerArray; overload; 
  function IDs(const p: TPoint): Integer; overload; 
  function IDs(const p: TPointArray): TIntegerArray; overload; 
  function TPA: TPointArray; overload; 
  function TPA(const index: Integer): TPoint; overload; 
  function Contents: TPointArray;
  function Content: TPointArray;	
  function Extract: TPointArray; 
  function Enumerate: TPointArray; 
  function Enumerated: TPointArray; 
  function Elements: TPointArray;	
  function Border: TPointArray; overload; 
  function Border(const X, Y: Integer): Boolean; overload; 
  function Border(const pt: TPoint): Boolean; overload; 
  function Edge: TPointArray; overload; 
  function Edge(const X, Y: Integer): Boolean; overload; 
  function Edge(const pt: TPoint): Boolean; overload; 
  function Outline: TPointArray; overload; 
  function Outline(const X, Y: Integer): Boolean; overload; 
  function Outline(const pt: TPoint): Boolean; overload; 
  function Contour: TPointArray; 
  function Spiral: TPointArray; 
  function Traverse: TPointArray; 
  function CornerPoints: TPointArray; 
  function CornerPts: TPointArray; 
  function Corners: TPointArray; 
  function Rows: Integer; overload;
  function Rows(const index: Integer): TPointArray; overload;
  function Columns: Integer; overload;
  function Columns(const index: Integer): TPointArray; overload;
  function Row(const index: Integer): TPointArray; overload;
  function Row: T2DPointArray; overload;
  function Column(const index: Integer): TPointArray; overload;
  function Column: T2DPointArray; overload; 
  function Rowwise: TPointArray; 
  function Columnwise: TPointArray; 
  function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; 
  function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; 
  function Centered(const toArea: TBox): TBox; 
  function CenterVertically(const toArea: TBox): TBox; 
  function CenterHorizontally(const toArea: TBox): TBox; 
  function Inside(const target: TBox): Boolean; overload; 
  function ExtendX(const xCoord: Integer): Boolean; 
  function ExtendY(const yCoord: Integer): Boolean; 
  function Extend(const pt: TPoint): Boolean; 
  function UnionX(const xCoord: Integer): TBox; 
  function Uniony(const yCoord: Integer): TBox; 
  function Union(const pt: TPoint): TBox; overload; 
  function Union(const b: TBox): TBox; overload; 
  function Disjoint(const target: TBox): Boolean; overload; 
  function Lacks(const pt: TPoint): Boolean; overload; 
  function Mixed(const mixings: Integer = 1): TPointArray; 
  function Shake(const shakes: Integer = 1): TPointArray; 
  function Shuffle(const shuffles: Integer = 1): TPointArray; 
  function Any: TPoint; 
  function Some: TPointArray; overload; 
  function Some(const amount: Integer): TPointArray; overload; 
  function All: TPointArray; overload;
  function Places(const target: TBox; const o: TPoint): TPointArray; overload;
  function Places(const target: TBox): TPointArray; overload;
  function Reserve: TPointArray; overload; 
  function Reserve(var aBox: TPointArray): Integer; overload;
  function Uniform(const val: Integer): Boolean; overload;
  function Uniform: Boolean; overload;
  function Employs(const val: Integer): Boolean;
  function Omits(const val: Integer): Boolean; 
end;
{$I Core.inc}
_TBox = class
public
  class function Create(const minX, minY, maxX, maxY: Integer): TBox; overload; 
  class function Create(const top, bottom: TPoint): TBox; overload; 
  class function Create(const valueX, valueY: Integer): TBox; overload; 
  class function Create(const target: TPoint): TBox; overload; 
  class function Create(const value: Integer = 0): TBox; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
TBoxHelper = type helper for TBox
  {$I Core.inc}
  function Create: TBox; overload;
  function Inside(const targets: TBoxArray): Boolean; overload;
  function AsGrid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray;
  function AsRow(const cells: Integer; const space: Integer = 0): TBoxArray;
  function AsColumn(const cells: Integer; const space: Integer = 0): TBoxArray;
  function Placements(const target: TBox; const o: TPoint): TBoxArray; overload;
  function Placements(const target: TBox): TBoxArray; overload;
  function Tiled(const target: TBox): TBoxArray; overload;
  function Gridded(const target: TBox): TBoxArray; overload;
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator +(const a, b: TBox): TBox;
operator -(const a, b: TBox): TBox;
operator =(const a, b: TBox): Boolean;
operator <>(const a, b: TBox): Boolean;

operator in(const P: TPoint; const B: TBox): Boolean;
{$ENDIF}

{$IFDEF METHODS}
function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload; inline;
function Box(const val: Integer = 0): TBox; overload; inline;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <+>
  @action: Computes the union of two boxes. The resulting box fully contains
           both input boxes.
  @note:   Supports any coordinate ordering; assumes X1 <= X2 and Y1 <= Y2 after normalization.
[==============================================================================}
operator +(const a, b: TBox): TBox;
begin
  Result.X1 := Min(a.X1, b.X1);
  Result.Y1 := Min(a.Y1, b.Y1);
  Result.X2 := Max(a.X2, b.X2);
  Result.Y2 := Max(a.Y2, b.Y2);
end;

{==============================================================================]
  <->
  @action: Computes the intersection of two boxes. Returns a box representing the 
           overlapping area of `a` and `b`. If the boxes do not overlap, returns 
           a null box marker.
  @note:   A null box can be represented by `TBox.Null` (e.g., all coordinates = Low(Integer)).
           This function does not require the boxes to be normalized beforehand, but
           you may normalize them for consistent behavior.
[==============================================================================}
operator -(const a, b: TBox): TBox;
begin
  if ((a.X2 < b.X1) or (b.X2 < a.X1) or (a.Y2 < b.Y1) or (b.Y2 < a.Y1)) then
    Exit(TBox.Null);
  Result.X1 := Max(a.X1, b.X1);
  Result.Y1 := Max(a.Y1, b.Y1);
  Result.X2 := Min(a.X2, b.X2);
  Result.Y2 := Min(a.Y2, b.Y2);
end;

operator =(const a, b: TBox): Boolean;
begin
  Result := ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator <>(const a, b: TBox): Boolean;
begin
  Result := not ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator in(const P: TPoint; const B: TBox): Boolean;
begin
  Result := B.Contains(P);
end;

constructor TBoxEnumerator.Init(const AX1, AY1, AX2, AY2: Integer);
begin
  XStart := AX1;
  XStop := AX2;
  YStart := AY1;
  YStop := AY2;
  FX := (XStart - 1);
  FY := YStart;
  FFirst := True;
end;

function TBoxEnumerator.MoveNext: Boolean;
begin
  if FFirst then
  begin
    FFirst := False;
    FX := XStart;
    Result := True;
    Exit;
  end;
  Inc(FX);
  if (FX > XStop) then
  begin
    FX := XStart;
    Inc(FY);
  end;
  Result := (FY <= YStop);
end;

function TBoxEnumerator.GetCurrent: TPoint;
begin
  Result := Point(FX, FY);
end;

function TBox.GetEnumerator: TBoxEnumerator;
begin
  Result.Init(X1, Y1, X2, Y2);
end;

function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload; inline;
begin
  Result.X1 := bX1;
  Result.Y1 := bY1;
  Result.X2 := bX2;
  Result.Y2 := bY2;
end;

function Box(const val: Integer = 0): TBox; overload; inline;
begin
  Result.X1 := val;
  Result.Y1 := val;
  Result.X2 := val;
  Result.Y2 := val;
end;

{==============================================================================]
  <Create>
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
  <Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY) 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const top, bottom: TPoint); overload;
begin
  Self.Create(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using  
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const valueX, valueY: Integer); overload;
begin
  Self.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using target TPoint 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const target: TPoint); overload;
begin
  Self.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using value. 
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const value: Integer); overload;
begin
  Self.Create(value, value, value, value); 
end;

{==============================================================================]
  <Create>
  @action: Creates TBox(0,0,0,0).
  @note: None
[==============================================================================}
function TBoxHelper.Create: TBox; overload;
begin
  Self.X1 := 0;
  Self.Y1 := 0;
  Self.X2 := 0;
  Self.Y2 := 0;
  Result := Self;  
end;

{==============================================================================]
  <Construct>
  @action: Constructs TBox with XS, YS, XE, YE.
  @note: None.
[==============================================================================}
class function TBox.Construct(const XS, YS, XE, YE: Integer): TBox; overload;
begin
  Result.X1 := XS;
  Result.Y1 := YS;
  Result.X2 := XE;
  Result.Y2 := YE;
end;

{==============================================================================]
  <Build>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: Min-Maxed. Creates only valid TBoxes. Returns area.
[==============================================================================}
function TBox.Build(const minX, minY, maxX, maxY: Integer): Integer; overload;
begin
  Self.X1 := Min(minX, maxX);
  Self.Y1 := Min(minY, maxY);
  Self.X2 := Max(maxX, minX);
  Self.Y2 := Max(maxY, minY);
  Result := Self.Area;
end;

{==============================================================================]
  <Build>
  @action: Builds TBox using 2 points (a = start point, b = end point)..
  @note: Make sure start and end points are correct!
[==============================================================================}
function TBox.Build(const top, bottom: TPoint): Integer; overload;
begin
  Result := Self.Build(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <Build>
  @action: We simply build using  
  @note: Constructor.
[==============================================================================}
function TBox.Build(const valueX, valueY: Integer): Integer; overload;
begin
  Result := Self.Build(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Build>
  @action: Creates TBox using target TPoint
  @note: Constructor.
[==============================================================================}
function TBox.Build(const target: TPoint): Integer; overload;
begin
  Result := Self.Build(target.X, target.Y, target.X, target.Y)
end;

{==============================================================================]
  <Build>
  @action: We simply build using value.
  @note: Constructor.
[==============================================================================}
function TBox.Build(const value: Integer = 0): Integer; overload;
begin
  Result := Self.Build(value, value, value, value);
end;

{==============================================================================]
  <Null>
  @action: Returns a "null" or empty box, represented by all coordinates set to 
           the specified sentinel value.
  @param: value - Optional integer to use as the sentinel for an empty box. 
                  Defaults to Low(Integer) (-2147483648 for 32-bit integers).
  @note:   This function is typically used to mark non-overlapping boxes resulting 
           from intersection operations. It provides a consistent marker for 
           "empty" boxes.
[==============================================================================}
class function TBox.Null(const value: Integer = -2147483648): TBox; overload;
begin
  Result := Box(value, value, value, value);
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with the specified X1, Y1, X2, Y2 values.
           Also returns the initialized record so it can be assigned in-line.
  @note: Useful for initializing a TBox instance and simultaneously returning it
         for assignment. Example: a := b.Init(2,2,8,8);
[==============================================================================}
function TBox.Init(const bX1, bY1, bX2, bY2: Integer): TBox; overload;
begin
  Self.X1 := bX1;
  Self.Y1 := bY1;
  Self.X2 := bX2;
  Self.Y2 := bY2;
  Result.X1 := bX1;
  Result.Y1 := bY1;
  Result.X2 := bX2;
  Result.Y2 := bY2;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy of another TBox.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(c);
[==============================================================================}
function TBox.Init(const b: TBox): TBox; overload;
begin
  Self := b;
  Result := b;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox with all X1, Y1, X2, Y2 set to the same value.
           Also returns the initialized record.
  @note: The parameter has a default of 0, allowing zero-initialization.
         Example: a := b.Init; or a := b.Init(5);
[==============================================================================}
function TBox.Init(const val: Integer = 0): TBox; overload;
begin
  Self.X1 := val;
  Self.Y1 := val;
  Self.X2 := val;
  Self.Y2 := val;
  Result.X1 := val;
  Result.Y1 := val;
  Result.X1 := val;
  Result.Y2 := val;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy with TPoint.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(p);
[==============================================================================}
function TBox.Init(const p: TPoint): TBox; overload;
begin
  Self.X1 := p.X;
  Self.Y1 := p.Y;
  Self.X2 := p.X;
  Self.Y2 := p.Y;
  Result.X1 := p.X;
  Result.Y1 := p.Y;
  Result.X1 := p.X;
  Result.Y2 := p.Y;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy with Top-Left and Bottom-Right TPoints.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(c, d);
[==============================================================================}
function TBox.Init(const TL, BR: TPoint): TBox; overload;
begin
  Self.X1 := TL.X;
  Self.Y1 := TL.Y;
  Self.X2 := BR.X;
  Self.Y2 := BR.Y;
  Result.X1 := TL.X;
  Result.Y1 := TL.Y;
  Result.X1 := BR.X;
  Result.Y2 := BR.Y;
end;

{==============================================================================]
  <Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload;
begin
  Self.X1 := (pt.X - wRadius);
  Self.Y1 := (pt.Y - hRadius);
  Self.X2 := (pt.X + wRadius);
  Self.Y2 := (pt.Y + hRadius);
  Result := Self;
end;

{==============================================================================]
  <Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const radius: Integer = 0): TBox; overload;
begin
  Result := Self.Make(pt, radius, radius);
end;

{==============================================================================]
  <Form>
  @action: Creates box to point, with size for width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const size: Integer = 1): TBox; overload;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (size - 1));
  Self.Y2 := (pt.Y + (size - 1));
  Result := Self;
end;

{==============================================================================]
  <Form>
  @action: Creates box to point, with width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const width, height: Integer): TBox; overload;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (width - 1));
  Self.Y2 := (pt.Y + (height - 1));
  Result := Self;
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox 
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame(var width, height: Integer): TBox; overload;
begin
  width := Self.Width;
  height := Self.Height;
  Result := Box(0, 0, (width - 1), (height - 1));
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox 
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame: TBox; overload;
begin
  Result := Box(0, 0, (Self.Width - 1), (Self.Height - 1));
end;

{==============================================================================]
  <Singular>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.Singular: Boolean;
begin
  Result := ((Self.X1 = Self.X2) and (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <IsPoint>
  @action: Returns true if TBox is just a single point.
  @note: None.
[==============================================================================}
function TBox.IsPoint: Boolean;
begin
  Result := not ((Self.X1 <> Self.X2) or (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <IsHorizontalLine>
  @action: Returns true if TBox is horizontal line. (Width <> 1) and (Height = 1)
  @note: None.
[==============================================================================}
function TBox.IsHorizontalLine: Boolean;
begin
  Result := ((Y1 = Y2) and (X1 <> X2));
end;

{==============================================================================]
  <IsVerticalLine>
  @action: Returns true if TBox is vertical line. (Width = 1) and (Height <> 1)
  @note: None.
[==============================================================================}
function TBox.IsVerticalLine: Boolean;
begin
  Result := ((X1 = X2) and (Y1 <> Y2));
end;

{==============================================================================]
  <IsLine>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.IsLine: Boolean;
begin
  Result := (Self.IsHorizontalLine or Self.IsVerticalLine);
end;

{==============================================================================]
  <Linear>
  @action: Returns true if TBox is horizontal or vertical line.
  @note: None.
[==============================================================================}
function TBox.Linear: Boolean;
begin
  Result := (((Self.X1 = Self.X2) xor (Self.Y1 = Self.Y2)) and (not Self.IsPoint));
end;

{==============================================================================]
  <Is2D>
  @action: Returns true if TBox is valid rectangle with area.
  @note: None.
[==============================================================================}
function TBox.Is2D: Boolean;
begin
  Result := ((Self.Width > 1) and (Self.Height > 1));
end;

{==============================================================================]
  <Collapsed>
  @action: Returns true if TBox is either point or a horizontal/vertical line.
  @note: Returns False if TBox is rectangle with workable area.
[==============================================================================}
function TBox.Collapsed: Boolean;
begin
  Result := ((Self.X1 = Self.X2) or (Self.Y1 = Self.Y2));
end;

{==============================================================================]
  <Boxy>
  @action: Returns true if TBox is valid rectangle
  @note: None.
[==============================================================================}
function TBox.Boxy: Boolean;
begin
  Result := ((Self.X1 <> Self.X2) and (Self.Y1 <> Self.Y2));
end;

{==============================================================================]
  <Plural>
  @action: Returns true if TBox contains more than single point.
  @note: None.
[==============================================================================}
function TBox.Plural: Boolean;
begin
  Result := ((Self.X2 > Self.X1) or (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Rectangular>
  @action: Returns true if TBox width AND height are higher than 1.
  @note: (X2 > X1 and Y2 > Y1).
[==============================================================================}
function TBox.Rectangular: Boolean;
begin
  Result := ((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Equilateral>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Equilateral: Boolean;
begin
  Result := ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1));
end;

{==============================================================================]
  <Square>
  @action: Returns true if width equals height.
  @note: (X2 - X1) = (Y2 - Y1), so WIDTH equals HEIGHT.
[==============================================================================}
function TBox.Square: Boolean;
begin
  Result := (((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) and ((Self.X2 - Self.X1) = (Self.Y2 - Self.Y1)));
end;

{==============================================================================]
  <Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBox.Size(var width, height: Integer): Integer; overload; inline;
begin
  width := Self.Width;
  height := Self.Height;
  Result := (width * height);
end;

{==============================================================================]
  <Size>
  @action: Returns TBox dimensions (Width and Height) as TPoint.
  @note: X = Width, Y = Height.
[==============================================================================}
function TBox.Size: TPoint; overload;
begin
  Result := Point(Self.Width, Self.Height);
end;

{==============================================================================]
  <Area>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Area: Integer; inline;
begin
  Result := (Self.Width * Self.Height);
end;

{==============================================================================]
  <Capacity>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Capacity: Integer; inline;
begin
  with Self do
    Result := (((Max(X1, X2) - Min(X1, X2)) + 1) * ((Max(Y1, Y2) - Min(Y1, Y2)) + 1));
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
  <Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
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
  <Width>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Width: Integer; overload;
begin
  Result := ((Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBox.Width(const w: Integer): Integer; overload;
begin
  Result := ((Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (w - 1));
end;

{==============================================================================]
  <Height>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Height: Integer; overload;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBox.Height(const h: Integer): Integer; overload;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (h - 1));
end;

{==============================================================================]
  <Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
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
  <Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange;
begin
  Result.start := Self.Y1;
  Result.stop := Self.Y2;
end;

{==============================================================================]
  <Expand>
  @action: Returns bx that has been expanded fully by change.
  @note: Works with positive values only.
[==============================================================================}
function TBox.Expand(const change: Integer = 1): TBox; overload;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

function TBox.Expand(const target: TBox): TBox; overload;
begin
  Result.X1 := Min(Self.X1, target.X1);
  Result.Y1 := Min(Self.Y1, target.Y1);
  Result.X2 := Max(Self.X2, target.X2);
  Result.Y2 := Max(Self.Y2, target.Y2);
end;

{==============================================================================]
  <Shrink>
  @action: Returns bx that has been shrinked fully by change.
  @note: Works with positive values only. UNSAFE method, no checks!
[==============================================================================}
function TBox.Shrink(const change: Integer = 1): TBox; overload;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 + change);
  Result.Y1 := (Self.Y1 + change);
  Result.X2 := (Self.X2 - change);
  Result.Y2 := (Self.Y2 - change);
end;

function TBox.Shrink(const target: TBox): TBox; overload;
begin
  Result.X1 := Max(Self.X1, target.X1);
  Result.Y1 := Max(Self.Y1, target.Y1);
  Result.X2 := Min(Self.X2, target.X2);
  Result.Y2 := Min(Self.Y2, target.Y2);
end;

{==============================================================================]
  <Resize>
  @action: Returns bx that has been resized fully by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.Resize(const change: Integer): TBox;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeVertically>
  @action: Returns bx that has been resized vertically by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeVertically(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeHorizontally>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeHorizontally(const change: Integer): TBox;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTop>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTop(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeBottom>
  @action: Returns bx that has been resized from bottom by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottom(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeLeft>
  @action: Returns bx that has been resized from left-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeLeft(const change: Integer): TBox;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeRight>
  @action: Returns bx that has been resized from right-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeRight(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTopLeft>
  @action: Returns bx that has been resized from top-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopLeft(const change: Integer): TBox;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTopRight>
  @action: Returns bx that has been resized from top-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopRight(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeBottomRight>
  @action: Returns bx that has been resized from bottom-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomRight(const change: Integer): TBox;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeBottomLeft>
  @action: Returns bx that has been resized from bottom-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomLeft(const change: Integer): TBox;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <Equal>
  @action: Returns true if bx1 and bx2 are identical.
  @note: None
[==============================================================================}
function TBox.Equal(const b: TBox): Boolean; inline;
begin
  Result := ((Self.X1 = b.X1) and (Self.Y1 = b.Y1) and (Self.X2 = b.X2) and (Self.Y2 = b.Y2));
end;  

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
  <Disjoint>
  @action: Returns true if target TBox is outside the target boundaries.
  @note: None.
[==============================================================================}
function TBox.Disjoint(const target: TBox): Boolean; overload;
begin
  Result := ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
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

{==============================================================================]
  <Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBox.Center: TPoint;
begin
  Result.X := Round(Self.X1 + ((Self.Width - 1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Height - 1) div 2));
end;

{==============================================================================]
  <Envelope>
  @action: Bounds 2 boxes (a and b) to 1 box.
  @note: Based on lowest / highest coordinate values.
[==============================================================================}
function TBox.Envelope(const b: TBox): TBox;
begin
  Result.X1 := Min(Min(Self.X1, Self.X2), Min(b.X1, b.X2));
  Result.Y1 := Min(Min(Self.Y1, Self.Y2), Min(b.Y1, b.Y2));
  Result.X2 := Max(Max(Self.X1, Self.X2), Max(b.X1, b.X2));
  Result.Y2 := Max(Max(Self.Y1, Self.Y2), Max(b.Y1, b.Y2));
end;

{==============================================================================]
  <Overlap>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Overlap(const b: TBox): Boolean; inline;
begin
  Result := not ((Self.X1 > b.X2) or (Self.X2 < b.X1) or (Self.Y1 > b.Y2) or (Self.Y2 < b.Y1));
end;

{==============================================================================]
  <Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox): TBox; overload;
begin
  Result.X1 := Max(Self.X1, b.X1);
  Result.Y1 := Max(Self.Y1, b.Y1);
  Result.X2 := Min(Self.X2, b.X2);
  Result.Y2 := Min(Self.Y2, b.Y2);
end;

{==============================================================================]
  <Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox; var iArea: TBox): Boolean; overload;
begin
  iArea := Self.Intersect(b);
  Result := not ((iArea.X1 > iArea.X2) or (iArea.Y1 > iArea.Y2));
end;

{==============================================================================]
  <Valid>
  Explanation: Returns true if TBox is valid (X1 <= X2 and Y1 <= Y2)
  Example: None.
[==============================================================================}
function TBox.Valid: Boolean; inline;
begin
  Result := ((Self.X1 <= Self.X2) and (Self.Y1 <= Self.Y2));
end;

{==============================================================================]
  <Invalid>
  Explanation: Returns true if TBox is invalid (X1 > X2 or Y1 > Y2)
  Example: None.
[==============================================================================}
function TBox.Invalid: Boolean;
begin
  Result := ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2));
end;

{==============================================================================]
  <Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within maxWDiff (max width differency) and maxHDiff (max height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= maxWDiff) and (Abs(b.Height- Self.Height) <= maxHDiff));
end;

{==============================================================================]
  <Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within diff (max width and height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const diff: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= diff) and (Abs(b.Height - Self.Height) <= diff));
end;

{==============================================================================]
  <Fix>
  Explanation: Fixes the bx. Swaps incorrectly set values (XS/YS > XE/YE).
               Returns true if bx was fixed.
  Example: (200*, 100, 100*, 200) => (100, 100, 200, 200)
[==============================================================================}
function TBox.Fix: Boolean;
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
  <Constraint>
  Explanation: Constraints bx to area.
  Example: None.
[==============================================================================}
function TBox.Constraint(const toArea: TBox): Boolean;
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
  <Clip>
  Explanation: Returns bx that has been constrained to area.
  Example: None.
[==============================================================================}
function TBox.Clip(const toArea: TBox): TBox;
begin
  Result.X1 := Max(toArea.X1, Min(toArea.X2, Self.X1));
  Result.Y1 := Max(toArea.Y1, Min(toArea.Y2, Self.Y1));
  Result.X2 := Max(toArea.X1, Min(toArea.X2, Self.X2));
  Result.Y2 := Max(toArea.Y1, Min(toArea.Y2, Self.Y2));
end;

{==============================================================================]
  <Restrict>
  Explanation: Restricts bx to area.
  Example: None.
[==============================================================================}
function TBox.Restrict(const toArea: TBox): Boolean;
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
  <Clamp>
  Explanation: Returns bx that has been restricted to area.
  Example: None.
[==============================================================================}
function TBox.Clamp(const toArea: TBox): TBox;
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
  <Reserve>
  Explanation: Reselve function for TBox.
  Example: None.
[==============================================================================}
function TBox.Reserve: TPointArray; overload;
begin
  SetLength(Result, Self.Area);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an TPoint array sized to fit the full box.
  @note: The array is preallocated with the correct length but is not filled 
         with values from X1,Y1..X2,Y2. Elements are default-initialized to 0,0.
[==============================================================================}
function TBox.Reserve(var aBox: TPointArray): Integer; overload;
begin
  Result := Self.Area;
  SetLength(aBox, Result);
end;

{==============================================================================]
  <Unzip>
  @action: Unzips TBox X1, Y1, X2, Y2 and returns the area.
  @note: None.
[==============================================================================}
function TBox.Unzip(var bX1, bY1, bX2, bY2: Integer): Integer; overload;
begin
  bX1 := Self.X1;
  bY1 := Self.Y1;
  bX2 := Self.X2;
  bY2 := Self.Y2;
  Result := Self.Area;
end;

{==============================================================================]
  <Unzip>
  @action: Unzips TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unzip: TPointArray; overload;
var
  r: TPointArray;
  w, h, l, x, y: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for x := 0 to (w - 1) do
    r[x] := Point((Self.X1 + x), 0);
  SetLength(Result, l);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    for x := 0 to (w - 1) do
    begin
      s^.Y := y;
      Inc(s);
    end;
    Inc(p, w);
  end;
end;

{==============================================================================]
  <Unpack>
  @action: Unpacks TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unpack: TPointArray; overload;
var
  r: TPointArray;
  w, h, l, x, y: Integer;
  p, s: PPoint;
begin
  l := Self.Size(w, h);
  if (l < 1) then
    Exit([]);
  SetLength(r, w);
  for x := 0 to (w - 1) do
    r[x] := Point((Self.X1 + x), 0);
  SetLength(Result, l);
  p := @Result[0];
  for y := Self.Y1 to Self.Y2 do
  begin
    Move(r[0], p^, (w * SizeOf(TPoint)));
    s := p;
    Inc(s, w);
    while (p <> s) do
    begin
      p^.Y := y;
      Inc(p);
    end;
  end;
end;

{==============================================================================]
  <Unpack>
  @action: Unpacks TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Unbox: TPointArray; overload;
var
  w, h, count: Integer;
  x, y: Integer;
  s: TPointArray;
  p, r: PPoint;
begin
  SetLength(Result, Self.Size(w, h));
  SetLength(s, w);
  r := @s[0];
  p := r;
  for x := 0 to (w - 1) do
  begin
    p^.X := (Self.X1 + x);
    p^.Y := Self.Y1;
    Inc(p);
  end;
  P := @Result[0];
  for y := 0 to (h - 1) do
  begin
    Move(s[0], p^, (w * SizeOf(TPoint)));
    r := p;
    for x := 0 to (w - 1) do
    begin
      r^.Y := (Self.Y1 + y);
      Inc(r);
    end;
    Inc(p, w);
  end;
end;

{==============================================================================]
  <Points>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Points: TPointArray; overload;
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
  <Points>
  @action: Returns TBox point with index (pIndex).
  @note: None.
[==============================================================================}
function TBox.Points(const pIndex: Integer): TPoint; overload;
begin
  if not InRange(pIndex, 0, (Self.Area - 1)) then
    Exit(Result.Create(-2147483648));
  Result := Point((Self.X1 + (pIndex mod Self.Width)), (Self.Y1 + (pIndex div Self.Width)));
end;

{==============================================================================]
  <Points>
  @action: Returns TBox points with indexes (pIDs).
  @note: None.
[==============================================================================}
function TBox.Points(const pIDs: TIntegerArray): TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(pIDs));
  for i := 0 to High(pIDs) do
    Result[i] := Self.Points(pIDs[i]);
end;

{==============================================================================]
  <Points>
  @action: Stores TBox points to xArray and yArray.
  @note: Returns area (length of TPointArray in box)
[==============================================================================}
function TBox.Points(var xArray, yArray: TIntegerArray): Integer; overload;
var
  i, w: Integer;
begin
  w := Self.Width;
  Result := (w * Self.Height);
  SetLength(xArray, Result);
  SetLength(yArray, Result);
  for i := 0 to (Result - 1) do
  begin
    xArray[i] := (Self.X1 + (i mod w));
    yArray[i] := (Self.Y1 + (i div w));
  end;
end;

{==============================================================================]
  <Pixels>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Pixels: TPointArray; overload;
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

function TBox.Pixels(const index: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + (index mod Self.Width)), (Self.Y1 + (index div Self.Width)));
end;

{==============================================================================]
  <Pixeled>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Pixeled: TPointArray; overload;
var
  w, h, l, i: Integer;
  r: TRange;
begin
  l := Self.Area;
  SetLength(Result, l);
  w := Self.Width;
  h := (l div 2);
  r.Create(0, (l - 1));
  for i := 0 to (h - 1) do
  begin
    Result[r.start.Increase] := Point((Self.X1 + (i mod w)), (Self.Y1 + (i div w)));
    Result[r.stop.Decrease] := Point((Self.X1 + (((l - 1) - i) mod w)), (Self.Y1 + (((l - 1) - i) div w)));
  end;
  if l.Odd then
    Result[h] := Point((Self.X1 + (h mod w)), (Self.Y1 + (h div w)));
end;

{==============================================================================]
  <TPA>
  @action: Returns TBox points as TPointArray.
  @note: None.
[==============================================================================}
function TBox.TPA: TPointArray; overload;
var
  i, j: Integer;
begin
  SetLength(Result, Self.Size(j, i));
  for i := 0 to High(Result) do
    Result[i].Create((Self.X1 + (i mod j)), (Self.Y1 + (i div j)));
end;

function TBox.TPA(const index: Integer): TPoint; overload;
var
  x, y: Integer;
begin
  y := (index div Self.Width);
  x := (index - (y * Self.Width));
  Result := Point((Self.X1 + x), (Self.Y1 + y));
end;

{==============================================================================]
  <Contents>
  @action: Returns TBox points as TPointArray.
  @note: Fast, Pointer-based alternative. Double loop version.
[==============================================================================}
function TBox.Contents: TPointArray;
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
  <Content>
  @action: Returns TBox points as TPointArray.
  @note: Fast, Pointer-based alternative single loop version.
[==============================================================================}
function TBox.Content: TPointArray;
var
  w, i: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Size(w, i));
  if Result.Empty then
    Exit;
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^.X := (Self.X1 + (i mod w));
    p^.Y := (Self.Y1 + (i div w));
    Inc(p);
  end;
end;

{==============================================================================]
  <Extract>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method for Points(), TPA() and Contents().
[==============================================================================}
function TBox.Extract: TPointArray;
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
  <Enumerate>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Enumerate: TPointArray;
var
  x, y: Integer;
begin
  SetLength(Result, 0);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result := (Result + [Point(x, y)]);
end;

{==============================================================================]
  <Enumerated>
  @action: Returns all points of the given box as TPointArray.
  @note: Uses the TBox enumerator (for-in).
[==============================================================================}
function TBox.Enumerated: TPointArray;
var
  p: TPoint;
  i: Integer;
begin
  SetLength(Result, Self.Area);
  i := 0;
  for p in Self do
    Result[i.Increase] := p;
end;

{==============================================================================]
  <Elements>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Elements: TPointArray;
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
  <Pts>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Pts: TPointArray; overload;
var
  x, y, w, h: Integer;
begin
  Self.Size(w, h);
  SetLength(Result, (w * h));
  for y := 0 to (h - 1) do
    for x := 0 to (w - 1) do
      Result[(y * w) + x] := Point((Self.X1 + x), (Self.Y1 + y));
end;

{==============================================================================]
  <Explode>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Explode: TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  Result[0] := Point(Self.X1, Self.Y1);
  for i := 1 to High(Result) do
    if ((Result[i - 1].X + 1) > Self.X2) then
      Result[i] := Point(Self.X1, (Result[i - 1].Y + 1))
    else
      Result[i] := Point((Result[i - 1].X + 1), Result[i - 1].Y);
end;

{==============================================================================]
  <Flat>
  @action: Returns TBox points as TPointArray.
  @note: Alternative method.
[==============================================================================}
function TBox.Flat: TPointArray; overload;
var
  i: Integer;
  p: TPoint;
begin
  SetLength(Result, Self.Area);
  p := Point(Self.X1, Self.Y1);
  for i := 0 to High(Result) do
  begin
    Result[i] := p;
    if (p.X < Self.X2) then
      Inc(p.X)
    else
      p := Point(Self.X1, (p.Y + 1));
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox indexes as TIntegerArray
  @note: None.
[==============================================================================}
function TBox.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to (Self.Area - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox index with TPoint p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPoint): Integer; overload;
begin
  if not Self.Contains(p) then
    Exit(-1);
  Result := (((p.Y - Self.Y1) * Self.Width) + (p.X - Self.X1));
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox indexes with TPointArray p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPointArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(p));
  for i := 0 to High(p) do
    Result[i] := Self.IDs(p[i]);
end;

{==============================================================================]
  <Border>
  @action: Returns TBox border points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Border: TPointArray; overload;
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

function TBox.Border(const X, Y: Integer): Boolean; overload;
begin
  with Self do
    Result := ((((X = X1) or (X = X2)) and ((Y >= Y1) and (Y <= Y2))) or (((Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2))));
end;

function TBox.Border(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Border(pt.X, pt.Y);
end;

{==============================================================================]
  <Edge>
  @action: Returns TBox edge points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Edge: TPointArray; overload;
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
    s := IfThen(d.Even, (Self.X2 - Self.X1), (Self.Y2 - Self.Y1));
    while (s > 0) do
    begin
      Result[i.Increase] := p;
      if (s.Decrease >= 0) then
        p := Point((p.X + c[d].X), (p.Y + c[d].Y));
    end;
  end;
end;

function TBox.Edge(const X, Y: Integer): Boolean; overload;
begin
  with Self do
    Result := (((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)) and ((X >= X1) and (X <= X2) and (Y >= Y1) and (Y <= Y2)));
end;

function TBox.Edge(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Edge(pt.X, pt.Y);
end;

{==============================================================================]
  <Outline>
  @action: Returns TBox outline points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Outline: TPointArray; overload;
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

function TBox.Outline(const X, Y: Integer): Boolean; overload;
begin
  Result := ((not ((X < X1) or (X > X2) or (Y < Y1) or (Y > Y2))) and ((X = X1) or (X = X2) or (Y = Y1) or (Y = Y2)));
end;

function TBox.Outline(const pt: TPoint): Boolean; overload;
begin
  Result := Self.Outline(pt.X, pt.Y);
end;

{==============================================================================]
  <Contour>
  @action: Returns TBox contour points as TPointArray.
  @note: Skips all the inside points.
[==============================================================================}
function TBox.Contour: TPointArray;
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
  <Spiral>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Traverse.
[==============================================================================}
function TBox.Spiral: TPointArray;
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
  <Traverse>
  @action: Returns TBox TPoints as spiral shaped TPointArray.
  @note: Alternative for TBox.Spiral.
[==============================================================================}
function TBox.Traverse: TPointArray;
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
  <AsGrid>
  @action: Outputs/builds grid of boxes with parameters;
           bx = starting box, used for starting coordinates and also for dimensions (width & height) of the boxes.
           rows, columns = count of rows and columns
           spaceHorizontal = space between columns
           spaceVertical = space between rows
  @note: None.
[==============================================================================}
function TBoxHelper.AsGrid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray;
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
  <AsRow>
  @action: Outputs row of boxes. Starting from bx,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TBoxHelper.AsRow(const cells: Integer; const space: Integer = 0): TBoxArray;
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
  <AsColumn>
  @action: Outputs column of boxes. Starting from bx,
           where space is the amount of space between each cell.
  @note: None
[==============================================================================}
function TBoxHelper.AsColumn(const cells: Integer; const space: Integer = 0): TBoxArray;
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
  <Rows>
  @action: Returns the number of rows in the box (height)
  @note: Zero-based row indexing is from top (Y1) to bottom (Y2)
[==============================================================================}
function TBox.Rows: Integer; overload;
begin
  Result := (Self.Height);
end;

{==============================================================================]
  <Row>
  @action: Returns all points in the specified row of the box, left-to-right.
  @note: 'index' is zero-based relative to the top edge (Y1). Returns [] if index is out of bounds.
[==============================================================================}
function TBox.Rows(const index: Integer): TPointArray; overload;
var
  i: Integer;
begin
  if ((index < 0) or not (index < Self.Height)) then
    Exit([]);
  SetLength(Result, Self.Width);
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X1 + i), (Self.Y1 + index));
end;

{==============================================================================]
  <Columns>
  @action: Returns the number of columns in the box (width)
  @note: Zero-based column indexing is from left (X1) to right (X2)
[==============================================================================}
function TBox.Columns: Integer; overload;
begin
  Result := (Self.Width);
end;

{==============================================================================]
  <Columns>
  @action: Returns all points in the specified column of the box, top-to-bottom.
  @note: 'index' is zero-based relative to the left edge (X1). Returns [] if index is out of bounds.
[==============================================================================}
function TBox.Columns(const index: Integer): TPointArray; overload;
var
  i: Integer;
begin
  if ((index < 0) or not (index < Self.Width)) then
    Exit([]);
  SetLength(Result, Self.Height);
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X1 + index), (Self.Y1 + i));
end;

{==============================================================================]
  <Row>
  @action: Returns all points in the specified row (left-to-right)
  @note: 'index' is zero-based relative to the top edge (Y1)
[==============================================================================}
function TBox.Row(const index: Integer): TPointArray; overload;
var
  i: Integer;
  p: PPoint;
begin
  if ((index < 0) or (index >= Self.Height)) then
    Exit([]);
  SetLength(Result, Self.Width);
  p := PPoint(Result);
  for i := 0 to (Self.Width - 1) do
  begin
    p^.X := (Self.X1 + i);
    p^.Y := (Self.Y1 + index);
    Inc(p);
  end;
end;

{==============================================================================]
  <Row>
  @action: Returns TBox as its rows of TPoints.
  @note: Row-major. Dimensions = [Height][Width].
[==============================================================================}
function TBox.Row: T2DPointArray; overload;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Height, Self.Width);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
      Result[y - Self.Y1][x - Self.X1] := Point(x, y);
end;

{==============================================================================]
  <Column>
  @action: Returns all points in the specified column (top-to-bottom)
  @note: 'index' is zero-based relative to the left edge (X1)
[==============================================================================}
function TBox.Column(const index: Integer): TPointArray; overload;
var
  i: Integer;
  p: PPoint;
begin
  if ((index < 0) or (index >= Self.Width)) then
    Exit([]);
  SetLength(Result, Self.Height);
  p := PPoint(Result);
  for i := 0 to (Self.Height - 1) do
  begin
    p^.X := (Self.X1 + index);
    p^.Y := (Self.Y1 + i);
    Inc(p);
  end;
end;

{==============================================================================]
  <Column>
  @action: Returns TBox as its columns of TPoints.
  @note: Column-major. Dimensions = [Width][Height].
[==============================================================================}
function TBox.Column: T2DPointArray; overload;
var
  x, y: Integer;
begin
  Result := T2D.Create(Point(0, 0), Self.Width, Self.Height);
  for x := Self.X1 to Self.X2 do
    for y := Self.Y1 to Self.Y2 do
      Result[x - Self.X1][y - Self.Y1] := Point(x, y);
end;

{==============================================================================]
  <Rowwise>
  @action: Returns all TBox TPoints as Row-wise.
  @note: None.
[==============================================================================}
function TBox.Rowwise: TPointArray;
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
  <Columnwise>
  @action: Returns all TBox TPoints as Column-wise.
  @note: None.
[==============================================================================}
function TBox.Columnwise: TPointArray;
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
  <CornerPoints>
  @action: Returns all 4 corner points of bx.
  @note: None
[==============================================================================}
function TBox.CornerPoints: TPointArray;
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
  <CornerPts>
  @action: Returns all 4 corner points of bx.
  @note: Gives also duplicates, if TBox is not rectangular.
[==============================================================================}
function TBox.CornerPts: TPointArray;
begin
  Result := [Point(Self.X1, Self.Y1), Point(Self.X2, Self.Y1), Point(Self.X2, Self.Y2), Point(Self.X1, Self.Y2)];
end;

{==============================================================================]
  <Corners>
  @action: Returns corner points of bx.
  @note: Outputs only unique TPoints.
[==============================================================================}
function TBox.Corners: TPointArray;
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
  <SimilarSize>
  @action: Returns true if the size from boxes a and b
           are within widthDifferency and heightDifferency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= widthDifferency) and (Abs(b.Height - Self.Height) <= heightDifferency));
end;

{==============================================================================]
  <SimilarSize>
  Explanation: Returns true if the size from boxes a and b
               are within differency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const differency: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= differency) and (Abs(b.Width - Self.Width) <= differency));
end;

{==============================================================================]
  <Centered>
  Explanation: Returns bx (by the dimensions) centered to area.
  @note: None.
[==============================================================================}
function TBox.Centered(const toArea: TBox): TBox;
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
  <CenterVertically>
  Explanation: Returns bx centered vertically to area.
  @note: None.
[==============================================================================}
function TBox.CenterVertically(const toArea: TBox): TBox;
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
  <CenterHorizontally>
  Explanation: Returns bx centered horizontally to area.
  @note: None.
[==============================================================================}
function TBox.CenterHorizontally(const toArea: TBox): TBox;
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
  <ExtendX>
  Explanation: Returns true if TBox is changed with xCoord (X1 or X2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendX(const xCoord: Integer): Boolean;
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
  <ExtendY>
  Explanation: Returns true if TBox is changed with yCoord (Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendY(const yCoord: Integer): Boolean;
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
  <Extend>
  Explanation: Returns true if TBox is changed with pt (X1, X2, Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.Extend(const pt: TPoint): Boolean;
var
  w, h: Boolean;
begin
  w := Self.ExtendX(pt.X);
  h := Self.ExtendY(pt.Y);
  Result := (w or h);
end;

{==============================================================================]
  <UnionX>
  Explanation: Returns the TBox Self with X-value extended (if xCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionX(const xCoord: Integer): TBox;
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
  <UnionY>
  Explanation: Returns the TBox Self with Y-value extended (if yCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionY(const yCoord: Integer): TBox;
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
  <Union>
  Explanation: Returns the Self unioned with pt.
  @note: None.
[==============================================================================}
function TBox.Union(const pt: TPoint): TBox; overload;
begin
  Result := Self.UnionX(pt.X).UnionY(pt.Y);
end;

{==============================================================================]
  <Union>
  @action: Returns union of a and b TBoxes
  @note: None
[==============================================================================}
function TBox.Union(const b: TBox): TBox; overload;
begin
  Result.X1 := Min(Self.X1, b.X1);
  Result.Y1 := Min(Self.Y1, b.Y1);
  Result.X2 := Max(Self.X2, b.X2);
  Result.Y2 := Max(Self.Y2, b.Y2);
end;

{==============================================================================]
  <Mixed>
  @action: Returns TBox randomly mixed as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Mixed(const mixings: Integer = 1): TPointArray;
var
  i, m: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for m := 1 to mixings do
    for i := 0 to High(Result) do
      Swap(Result[Random(Result.Size)], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shake>
  @action: Returns TBox randomly shaked as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shake(const shakes: Integer = 1): TPointArray;
var
  i, s: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for s := 1 to shakes do
    for i := 0 to Random(Result.Size) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shuffle>
  @action: Returns TBox randomly shuffled as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shuffle(const shuffles: Integer = 1): TPointArray;
var
  i, s: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for s := 1 to shuffles do
    for i := 0 to High(Result) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Any>
  @action: Returns random TBox point.
  @note: None.
[==============================================================================}
function TBox.Any: TPoint;
begin
  Result := Point((Self.X1 + Random(Self.Width)), (Self.X1 + Random(Self.Height)));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some: TPointArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Area + 1), 1));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some(const amount: Integer): TPointArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Area)));
end;

{==============================================================================]
  <All>
  @action: Returns ALL points of TBox as TPointArray.
  @note: None.
[==============================================================================}
function TBox.All: TPointArray; overload;
var
  x, y: Integer;
  p: PPoint;
begin
  SetLength(Result, Self.Area);
  p := PPoint(Result);
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
    begin
      p^ := Point(x, y);
      Inc(p);
    end;
end;

{==============================================================================]
  <Placements>
  @action: Generate all possible translations of Self fully contained within target.
  @note: Returns an array of boxes representing every valid placement;
         order is row-major (y first, then x). Returns empty array if no fit.
[==============================================================================}
function TBoxHelper.Placements(const target: TBox; const o: TPoint): TBoxArray; overload;
var
  y, x, r: Integer;
  f, t: TBox;
begin
  t := Box(target.X1, target.Y1, ((target.X2 - Self.Width) + 1), ((target.Y2 - Self.Height) + 1));
  SetLength(Result, t.Area);
  if Result.Empty then
    Exit;
  r := 0;
  f := Self.Frame;
  for y := t.Y1 to t.Y2 do
    for x := t.X1 to t.X2 do
      Result[r.Increase] := Box(((f.X1 + x) + o.X), ((f.Y1 + y) + o.Y), ((f.X2 + x) + o.X), ((f.Y2 + y) + o.Y));
end;

function TBoxHelper.Placements(const target: TBox): TBoxArray; overload;
begin
  Result := Self.Placements(target, Point(0, 0));
end;

{==============================================================================]
  <Places>
  @action: Generate all possible translations of Self fully contained within target.
  @note: Returns an array of points representing every valid place;
         order is row-major (y first, then x). Returns empty array if no fit.
[==============================================================================}
function TBox.Places(const target: TBox; const o: TPoint): TPointArray; overload;
var
  w, h, x, y, l: Integer;
  r, c: TRange;
begin
  target.Size(w, h);
  Self.Size(x, y);
  if ((x > w) or (y > h)) then
    Exit([]);
  r.Create(0, (h - y));
  c.Create(0, (w - x));
  l := 0;
  SetLength(Result, ((r.stop + 1) * (c.stop + 1)));
  for y := r.start to r.stop do
    for x := c.start to c.stop do
      Result[l.Increase] := Point(((x + target.X1) + o.X), ((y + target.Y1) + o.Y));
end;

function TBox.Places(const target: TBox): TPointArray; overload;
begin
  Result := Self.Places(target, Point(0, 0));
end;

{==============================================================================]
  <Tiled>
  @action: Generate non-overlapping, grid-aligned positions of Self inside target.
  @note: Steps by Self Width and Height. Returns empty array if Self does not fit.
[==============================================================================}
function TBoxHelper.Tiled(const target: TBox): TBoxArray; overload;
var
  y, x, r, w, h: Integer;
  m: TPoint;
  f: TBox;
begin
  Self.Size(w, h);
  if ((w > target.Width) or (h > target.Height)) then
    Exit([]);
  f := Self.Frame;
  m := Point(((target.X2 - w) + 1), ((target.Y2 - h) + 1));
  SetLength(Result, ((target.Width div w) * (target.Height div h)));
  r := 0;
  y := target.Y1;
  repeat
    x := (target.X1 - w);
    while (x.Increment(w) <= m.X) do
      Result[r.Increase] := Box((f.X1 + x), (f.Y1 + y), (f.X2 + x), (f.Y2 + y));
  until (y.Increment(h) > m.Y);
end;

{==============================================================================]
  <Gridded>
  @action: Generate non-overlapping, grid-aligned positions of Self inside target.
  @note: Steps by Self Width and Height. Returns empty array if Self does not fit.
[==============================================================================}
function TBoxHelper.Gridded(const target: TBox): TBoxArray; overload;
var
  l, y, x, r, c, w, h: Integer;
begin
  Self.Size(w, h);
  if ((w > target.Width) or (h > target.Height)) then
    Exit([]);
  c := (target.Width div w);
  r := (target.Height div h);
  SetLength(Result, (r * c));
  l := 0;
  for y := 0 to (r - 1) do
    for x := 0 to (c - 1) do
      Result[l.Increase].Form(Point((target.X1 + (w * x)), (target.Y1 + (h * y))), w, h);
end;

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


{==============================================================================]
  <Create>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: function version
[==============================================================================}
class function _TBox.Create(const minX, minY, maxX, maxY: Integer): TBox; overload;
begin
  Result.X1 := minX;
  Result.Y1 := minY;
  Result.X2 := maxX;
  Result.Y2 := maxY;
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY) 
  @note: Constructor.
[==============================================================================}
class function _TBox.Create(const top, bottom: TPoint): TBox; overload;
begin
  Result := _TBox.Create(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using  
  @note: Function.
[==============================================================================}
class function _TBox.Create(const valueX, valueY: Integer): TBox; overload;
begin
  Result := _TBox.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using target TPoint 
  @note: Function.
[==============================================================================}
class function _TBox.Create(const target: TPoint): TBox; overload;
begin
  Result := _TBox.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using value. 
  @note: Constructor.
 
[==============================================================================}
class function _TBox.Create(const value: Integer = 0): TBox; overload;
begin
  Result := _TBox.Create(value, value, value, value);
end;
{$ENDIF}

{$UNDEF TBox}