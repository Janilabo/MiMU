{$DEFINE TPoint}{$I config\Defines.inc}

{$IFDEF INTERFACE}
type
  TPoint = record
    X, Y: Integer;
    constructor Create(const pX, pY: Integer); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const pX, pY: Integer): TPoint; overload; static;
    function Build(const pX, pY: Integer): TPoint;  inline;
	function Lower(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
    function Higher(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
	function Under(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
    function Over(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
    function Behind(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
    function Ahead(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
    function Comparison(const target: TPoint): Integer; overload;
    function Compare(const target: TPoint): Integer; overload;
    function Compared(const target: TPoint): Integer; overload;
    function Comp(const target: TPoint): Integer; overload;
    function Cmp(const target: TPoint): Integer; overload;
    function XComp(const target: TPoint): Integer; inline;
    function YComp(const target: TPoint): Integer; inline;
    function XCompare(const target: TPoint): Integer;
    function YCompare(const target: TPoint): Integer;
    function CompareX(const target: TPoint): Integer;
    function CompareY(const target: TPoint): Integer;
    function CompX(const target: TPoint): Integer;
    function CompY(const target: TPoint): Integer;
    function InCircle(const center: TPoint; const radius: Double): Boolean; inline;
    function InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
    function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; 
    function AngleRadians(const target: TPoint): Double;
    function DistHypotEuclidean(const target: TPoint): Double; 	
    function DistEuclidean(const target: TPoint): Double; 
    function DistEuclidean2(const target: TPoint): Double; 
    function DistSquaredEuclidean(const target: TPoint): Double; 
    function DistManhattan(const target: TPoint): Double; 
    function DistChebyshev(const target: TPoint): Double;
    function DistMinkowski(const target: TPoint): Double; overload;
    function DistMinkowski(const target: TPoint; const P: Double): Double; overload;
    function DistMaxMinChebyshev(const target: TPoint): Double;
    function DistOctile(const target: TPoint): Double;
    function Within(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
    function Near(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
    function Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
    function Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function DistX(const target: TPoint): Integer;
    function DistY(const target: TPoint): Integer;
    function DistanceX(const target: TPoint): Integer;
    function DistanceY(const target: TPoint): Integer;
    function DistMaxMinX(const Target: TPoint): Integer;
    function DistMaxMinY(const Target: TPoint): Integer;
    function Reflected: TPoint; inline;
    function Flipped: TPoint; inline;
    function DeltaX(const target: TPoint): Integer;
    function DeltaY(const target: TPoint): Integer;
    function Delta(const target: TPoint): TPoint;
    function HorizontalDist(const target: TPoint): Integer;
    function VerticalDist(const target: TPoint): Integer;
    function Uniform(const val: Integer): Boolean; overload;
    function Uniform: Boolean; overload;
    function Employs(const val: Integer): Boolean;
    function Omits(const val: Integer): Boolean; 	
  end;
  TPointArray = array of TPoint;
  T2DPointArray = array of TPointArray;
  PPoint = ^TPoint;
  _TPoint = class
  public
    class function Create(const pX, pY: Integer): TPoint; overload; 
    class function Create(const value: Integer = 0): TPoint; overload; 
  end;
  TDistanceFunction = function(const A, B: TPoint): Double;
  
operator+(const a, b: TPoint): TPoint;
operator-(const a, b: TPoint): TPoint;
operator=(const a, b: TPoint): Boolean;
operator<>(const a, b: TPoint): Boolean;
operator>(const a, b: TPoint): Boolean;
operator<(const a, b: TPoint): Boolean;
operator>=(const a, b: TPoint): Boolean;
operator<=(const a, b: TPoint): Boolean;

function Point(const pX, pY: Integer): TPoint; overload; inline;
function Point(const val: Integer = 0): TPoint; overload; inline;

{$ENDIF}

{$IFDEF HELPERS}
type
  HVar = type helper for TVar {$I config\0D.inc}
    function Inside(const bx: TBox): Boolean; inline;
    function Clamp(const area: TBox): TPoint;
    function Create: TPoint; overload;
    function Sign(const target: TPoint): Integer; overload; inline;
    function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray;
    function Row(const cells: Integer; const space: Integer = 0): TPointArray;
    function Column(const cells: Integer; const space: Integer = 0): TPointArray;
    function Surrounding(const adjacency8: Boolean = True): TPointArray; overload;
    function Adjacent(const adjacency8: Boolean = True): TPointArray; overload;
    procedure Adjacent(var adj: TPointArray; const adjacency8: Boolean = True); overload;
    function Adjacency(const adjacency8: Boolean = True): TPointArray; overload;	  
    function Neighbours(const adjacency8: Boolean = True): TPointArray; overload;
    procedure Neighbours(var adj: TPointArray); overload;
    function Neighbors(const adjacency8: Boolean = True): TPointArray; overload;
    procedure Neighbors(var adj: TPointArray); overload;
    function ToY(const yGoal: Integer): TPointArray; overload;
    function ToX(const xGoal: Integer): TPointArray; overload;
    function Linked(const p: TPoint; const link: TPointArray): Boolean; overload;
    function Boxed(const xRadius, yRadius: Integer): TBox; overload;
    function Boxed(const radius: Integer = 0): TBox; overload;
    function ToBox(const width, height: Integer): TBox; overload;
    function ToBox(const size: Integer = 0): TBox; overload;
    function Boxify(const width, height: Integer): TBox; overload;
    function Boxify(const size: Integer = 0): TBox; overload;
    function Within(const target: TPoint; const radius: Double; const distFunc: TDistanceFunction): Boolean; overload;
    function Within(const target: TPoint; const radius: Double = 1.0; const metric: TDistanceMetric = dmEuclidean): Boolean; overload;
    function Near(const target: TPoint; const radius: Double; const distFunc: TDistanceFunction): Boolean; overload;
    function Near(const target: TPoint; const radius: Double; const metric: TDistanceMetric): Boolean; overload;
    function Dist(const target: TPoint; const metric: TDistanceMetric = dmEuclidean): Double;
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\0D.inc}

operator+(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X + b.X);
  Result.X := (a.Y + b.Y);
end;

operator-(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X - b.X);
  Result.Y := (a.Y - b.Y);
end;

operator=(const a, b: TPoint): Boolean;
begin
  Result := ((a.X = b.X) and (a.Y = b.Y));
end;

operator<>(const a, b: TPoint): Boolean;
begin
  Result := not ((a.X = b.X) and (a.Y = b.Y));
end;

operator>(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y > b.Y) or ((a.Y = b.Y) and (a.X > b.X)));
end;

operator<(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y < b.Y) or ((a.Y = b.Y) and (a.X < b.X)));
end;

operator >=(const a, b: TPoint): Boolean;
begin
  Result := ((a > b) or (a = b));
end;

operator <=(const a, b: TPoint): Boolean;
begin
  Result := ((a < b) or (a = b));
end;

function Point(const pX, pY: Integer): TPoint; overload; inline;
begin
  Result.X := pX;
  Result.Y := pY;
end;

function Point(const val: Integer = 0): TPoint; overload; inline;
begin
  Result.X := val;
  Result.Y := val;
end;

{==============================================================================]
  <TPoint.Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const pX, pY: Integer); overload;
begin
  Self.X := pX;
  Self.Y := pY;
end;

{==============================================================================]
  <TPoint.Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <TPoint.Create>
  @action: Constructs new TPoint with pX and pY.
  @note: None.
[==============================================================================}
class function TPoint.Construct(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <TPoint.Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPoint.Build(const pX, pY: Integer): TPoint; inline;
begin
  Self.X := pX;
  Self.Y := pY;
  Result := Self;
end;

{==============================================================================]
  <TPoint.Sign>
  @action: Compares the current TPoint (Self) with a target TPoint and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TPointHelper.Sign(const target: TPoint): Integer; overload; inline; {$DEFINE Skeleton_Sign}{$I config\Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <TPoint.Lower>
  @action: Returns True if Self precedes target in scanline order.
  @note: Comparison is Y-major, then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Lower(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
    Exit((oAscending and (Self.Y < target.Y)) or ((not oAscending) and (Self.Y > target.Y)));
  Result := ((oAscending and (Self.X < target.X)) or ((not oAscending) and (Self.X > target.X)));
end;

{==============================================================================]
  <TPoint.Higher>
  @action: Returns True if Self follows target in scanline order.
  @note: Comparison is Y-major, then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Higher(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
    Exit((oAscending and (Self.Y > target.Y)) or ((not oAscending) and (Self.Y < target.Y)));
  Result := ((oAscending and (Self.X > target.X)) or ((not oAscending) and (Self.X < target.X)));
end;

{==============================================================================]
  <TPoint.Under>
  @action: Returns True if Self precedes target in scanline order.
  @note: Comparison is Y-major then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Under(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
    Result := IfThen(oAscending, (Self.Y < target.Y), (Self.Y > target.Y))
  else
    Result := IfThen(oAscending, (Self.X < target.X), (Self.X > target.X));
end;

{==============================================================================]
  <TPoint.Over>
  @action: Returns True if Self follows target in scanline order.
  @note: Comparison is Y-major then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Over(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
    Result := IfThen(oAscending, (Self.Y > target.Y), (Self.Y < target.Y))
  else
    Result := IfThen(oAscending, (Self.X > target.X), (Self.X < target.X));
end;

{==============================================================================]
  <TPoint.Behind>
  @action: Returns True if Self is "behind" the target in scanline order.
  @note: "Behind" means lower Y (or X if Y equal) for ascending order, opposite for descending.
[==============================================================================}
function TPoint.Behind(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
  case oAscending of
    True: Exit(Self.Y < target.Y);
    False: Exit(Self.Y > target.Y);
  end;
  if oAscending then
    Result := (Self.X < target.X)
  else
    Result := (Self.X > target.X);
end;

{==============================================================================]
  <TPoint.Ahead>
  @action: Returns True if Self is "ahead" of the target in scanline order.
  @note: "Ahead" means higher Y (or X if Y equal) for ascending order, opposite for descending.
[==============================================================================}
function TPoint.Ahead(const target: TPoint; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self.Y <> target.Y) then
  case oAscending of
    True: Exit(Self.Y > target.Y);
    False: Exit(Self.Y < target.Y);
  end;
  if oAscending then
    Result := (Self.X > target.X)
  else
    Result := (Self.X < target.X);
end;

{==============================================================================]
  <TPoint.Comparison>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Comparison(const target: TPoint): Integer; overload;
begin
  if ((Self.X = target.X) and (Self.Y = target.Y)) then
    Exit(0);
  if (Self.X < target.X) then
    Exit(-1);
  if (Self.X > target.X) then
    Exit(1);
  if (Self.Y < target.Y) then
    Exit(-1);
  if (Self.Y > target.Y) then
    Exit(1);
end;

{==============================================================================]
  <TPoint.Compared>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Compared(const target: TPoint): Integer; overload;
begin
  if (X <> target.X) then
    Exit(Ord(X > target.X) - Ord(X < target.X));
  if (Y <> target.Y) then
    Exit(Ord(Y > target.Y) - Ord(Y < target.Y));
  Result := 0;
end;

{==============================================================================]
  <TPoint.Comp>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Comp(const target: TPoint): Integer; overload;
begin
  Result := IfThen((X <> target.X), (Ord(X > target.X) - Ord(X < target.X)), (Ord(Y > target.Y) - Ord(Y < target.Y)));
end;

{==============================================================================]
  <TPoint.Cmp>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Cmp(const target: TPoint): Integer; overload;
begin
  Result := Sign(X - target.X);
  if (Result = 0) then
    Result := Sign(Y - target.Y);
end;

{==============================================================================]
  <TPoint.Compare>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Compare(const target: TPoint): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if (Self < target) then
    Exit(-1);
  Result := 1;
end;

{==============================================================================]
  <TPoint.XComp>
  @action: Compares two points by their X coordinates only.
  @note: Returns -1 if Self.X < target.X, 1 if Self.X > target.X, or 0 if equal.
[==============================================================================}
function TPoint.XComp(const target: TPoint): Integer; inline;
begin
  if (Self.X < target.X) then
    Result := -1
  else
    if (Self.X > target.X) then
	  Result := 1
    else
	  Result := 0;
end;

{==============================================================================]
  <TPoint.YComp>
  @action: Compares two points by their Y coordinates only.
  @note: Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, or 0 if equal.
[==============================================================================}
function TPoint.YComp(const target: TPoint): Integer; inline;
begin
  if (Self.Y < target.Y) then
    Result := -1
  else
    if (Self.Y > target.Y) then
	  Result := 1
    else
	  Result := 0;
end;

{==============================================================================]
  <TPoint.XCompare>
  @action: Compares two points primarily by X coordinate, then by Y as a tiebreaker.
  @note: Useful for X-major ordering or sorting points left-to-right, then top-to-bottom.
[==============================================================================}
function TPoint.XCompare(const target: TPoint): Integer;
begin
  if (Self.X < target.X) then
    Exit(-1)
  else
    if (Self.X > target.X) then
      Exit(1)
    else
      if (Self.Y < target.Y) then
        Exit(-1)
      else
        if (Self.Y > target.Y) then
          Exit(1);
  Result := 0;
end;

{==============================================================================]
  <TPoint.YCompare>
  @action: Compares two points primarily by Y coordinate, then by X as a tiebreaker.
  @note: Useful for Y-major ordering or sorting points top-to-bottom, then left-to-right.
[==============================================================================}
function TPoint.YCompare(const target: TPoint): Integer;
begin
  if (Self.Y < target.Y) then
    Exit(-1)
  else
    if (Self.Y > target.Y) then
      Exit(1)
    else
      if (Self.X < target.X) then
        Exit(-1)
      else
        if (Self.X > target.X) then
          Exit(1);
  Result := 0;
end;

{==============================================================================]
  <TPoint.CompareX>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareX(const target: TPoint): Integer;
begin
  Result := (Ord(Self.X > target.X) - Ord(Self.X < target.X));
end;

{==============================================================================]
  <TPoint.CompareY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareY(const target: TPoint): Integer;
begin
  Result := (Ord(Self.Y > target.Y) - Ord(Self.Y < target.Y));
end;

{==============================================================================]
  <TPoint.CompX>
  @action: Compares two points by their X coordinate only.
  @note: - Returns -1 if Self.X < target.X, 1 if Self.X > target.X, and 0 if equal.
         - The Y coordinate is ignored.
[==============================================================================}
function TPoint.CompX(const target: TPoint): Integer;
begin
  Result := Sign(Self.X - target.X);
end;

{==============================================================================]
  <TPoint.CompY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompY(const target: TPoint): Integer;
begin
  Result := Sign(Self.Y - target.Y);
end;

{==============================================================================]
  <TPoint.Inside>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TPointHelper.Inside(const bx: TBox): Boolean; inline;
begin
  Result := ((Self.X >= bx.X1) and (Self.Y >= bx.Y1) and (Self.X <= bx.X2) and (Self.Y <= bx.Y2));
end;

{==============================================================================]
  <TPoint.InCircle>
  @action: Returns true if pt is inside the given circle,
          that is defined by the center point and radius.
  @note: None.
[==============================================================================}
function TPoint.InCircle(const center: TPoint; const radius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / radius) + Sqr((Self.Y - center.Y) / radius) <= 1);
end;

{==============================================================================]
  <TPoint.InEllipse>
  @action: Returns true if pt is inside the given ellipse,
          defined by the center point and X-radius and Y-radius.
  @note: None.
[==============================================================================}
function TPoint.InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / XRadius) + Sqr((Self.Y - center.Y) / YRadius) <= 1);
end;

{==============================================================================]
 <TPoint.AngleDegrees>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPoint.AngleDegrees(const target: TPoint; const compass: Boolean = False): Double;
var
  a: Double;
begin
  if compass then
    a := ((ArcTan2((target.Y - Self.Y), (target.X - Self.X)) * (180.0 / Pi)) + 90.0)
  else
    a := (ArcTan2((target.Y - Self.Y), (target.X - Self.X)) * (180.0 / Pi));
  Result := a.FixDegrees;
end;

{==============================================================================]
 <TPoint.AngleRadians>
 @action: Calculates the angle in degrees from source to target.
 @note: None
[==============================================================================}
function TPoint.AngleRadians(const target: TPoint): Double;
var
  a: Double;
begin
  a := ArcTan2((target.Y - Self.Y), (target.X - Self.X));
  Result := a.FixRadians;
end;

{==============================================================================]
 <TPoint.DistHypotEuclidean>
 @action: Calculates the distance from source to target.
 @note: Euclidean.
[==============================================================================}
function TPoint.DistHypotEuclidean(const target: TPoint): Double;
begin
  Result := HypotEuclidean(Self, target);
end;

{==============================================================================]
 <TPoint.DistEuclidean>
 @action: Calculates the distance from source to target.
 @note: Euclidean.
[==============================================================================}
function TPoint.DistEuclidean(const target: TPoint): Double;
begin
  Result := Euclidean(Self, target);
end;

{==============================================================================]
 <TPoint.DistEuclidean2>
 @action: Calculates the distance from source to target.
 @note: Euclidean v2
[==============================================================================}
function TPoint.DistEuclidean2(const target: TPoint): Double;
begin
  Result := Euclidean2(Self, target);
end;

{==============================================================================]
 <TPoint.DistSquaredEuclidean>
 @action: Calculates the distance from source to target.
 @note: Squared Euclidean
[==============================================================================}
function TPoint.DistSquaredEuclidean(const target: TPoint): Double;
begin
  Result := SquaredEuclidean(Self, target);
end;

{==============================================================================]
 <TPoint.DistManhattan>
 @action: Calculates the distance from source to target.
 @note: Manhattan
[==============================================================================}
function TPoint.DistManhattan(const target: TPoint): Double;
begin
  Result := Manhattan(Self, target);
end;

{==============================================================================]
 <TPoint.DistChebyshev>
 @action: Calculates the distance from source to target.
 @note: Chebyshev
[==============================================================================}
function TPoint.DistChebyshev(const target: TPoint): Double;
begin
  Result := Chebyshev(Self, target);
end;

{==============================================================================]
 <TPoint.DistMinkowski>
 @action: Calculates the distance from source to target.
 @note: Minkowski
[==============================================================================}
function TPoint.DistMinkowski(const target: TPoint): Double; overload;
begin
  Result := Minkowski(Self, target);
end;

{==============================================================================]
 <TPoint.DistMinkowski>
 @action: Calculates the distance from source to target.
 @note: Minkowski
[==============================================================================}
function TPoint.DistMinkowski(const target: TPoint; const P: Double): Double; overload;
begin
  Result := Minkowski(Self, target, P);
end;

{==============================================================================]
 <TPoint.DistMaxMinChebyshev>
 @action: Calculates the distance from source to target.
 @note: Max-Min Chebyshev
[==============================================================================}
function TPoint.DistMaxMinChebyshev(const target: TPoint): Double;
begin
  Result := MaxMinChebyshev(Self, target);
end;

{==============================================================================]
 <TPoint.DistOctile>
 @action: Calculates the distance from source to target.
 @note: Octile
[==============================================================================}
function TPoint.DistOctile(const target: TPoint): Double;
begin
  Result := Octile(Self, target);
end;

{==============================================================================]
 <TPoint.Dist>
 @action: Calculates the distance from source to target.
 @note: Octile
[==============================================================================}
function TPointHelper.Dist(const target: TPoint; const metric: TDistanceMetric = dmEuclidean): Double;
begin
  Result := Distance(Self, target, metric);
end;

{==============================================================================]
 <TPoint.Reflected>
 @action: Reflects the point across the line y = x.
 @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Reflected: TPoint; inline;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;

{==============================================================================]
 <TPoint.Flipped>
 @action: Returns the point with its coordinates flipped (same as Reflected).
 @note: This is a shorthand, stylistically different version of Reflected.
[==============================================================================}
function TPoint.Flipped: TPoint; inline;
begin
  Result := Point(Self.Y, Self.X);
end;

{==============================================================================]
 <TPoint.Within>
 @action: Determines whether this point lies within a given distance (radius)
          of another point, using the specified distance function.
 @note: If no distance function is provided, Euclidean distance should be
        used as the default metric.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double; const distFunc: TDistanceFunction): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
 <TPoint.Within>
 @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
 @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double = 1.0; const metric: TDistanceMetric = dmEuclidean): Boolean; overload;
begin
  Result := Self.Within(target, radius, DistanceFunction(metric));
end;

{==============================================================================]
 <TPoint.Within>
 @action: Determines whether this point lies within a rectangular area centered
          on another point, defined by horizontal and vertical radii.
 @note: Useful for grid or axis-aligned range checks where separate X/Y
        tolerances are used instead of a circular radius.
[==============================================================================}
function TPoint.Within(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Abs(Self.X - target.X) <= xRadius) and (Abs(Self.Y - target.Y) <= yRadius));
end;

{==============================================================================]
 <TPoint.Near>
 @action: Determines whether the current point is within a given radius of the target point using a custom distance function.
 @note: `distFunc` is a user-provided function that calculates the distance between two points. Useful for non-standard distance metrics.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const distFunc: TDistanceFunction): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
 <TPoint.Near>
 @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
 @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const metric: TDistanceMetric): Boolean; overload;
begin
  Result := Self.Near(target, radius, DistanceFunction(metric));
end;

{==============================================================================]
 <TPoint.Near>
 @action: Determines whether the current point is within a circular radius of the target point using Euclidean distance.
 @note: Computes the squared Euclidean distance (`dx*dx + dy*dy`) and compares it to the squared radius for efficiency.
[==============================================================================}
function TPoint.Near(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
var
  h, v: Double;
begin
  h := (Self.X - target.X);
  v := (Self.Y - target.Y);
  Result := (((h * h) + (v * v)) <= (radius * radius));
end;

{==============================================================================]
 <TPoint.Near>
 @action: Determines whether the current point is within an axis-aligned rectangular area around the target point.
 @note: Checks whether the X and Y distances are within `xRadius` and `yRadius` respectively. Uses `DistanceX` and `DistanceY` for clarity.
[==============================================================================}
function TPoint.Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Self.DistanceX(target) <= xRadius) and (Self.DistanceY(target) <= yRadius));
end;

{==============================================================================]
 <TPoint.DistX>
 @action: Returns the absolute horizontal distance between this point and the target point.
 @note: Equivalent to Abs(Self.X - target.X). Useful for quick delta comparisons on the X-axis.
[==============================================================================}
function TPoint.DistX(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
 <TPoint.DistY>
 @action: Returns the absolute vertical distance between this point and the target point.
 @note: Equivalent to Abs(Self.Y - target.Y). Useful for quick delta comparisons on the Y-axis.
[==============================================================================}
function TPoint.DistY(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;

{==============================================================================]
 <TPoint.DistanceX>
 @action: Calculates the horizontal distance between this point and the target point.
 @note: Functionally identical to DistX; uses explicit conditional logic instead of Abs().
[==============================================================================}
function TPoint.DistanceX(const target: TPoint): Integer;
begin
  if (Self.X > target.X) then
    Result := (Self.X - target.X)
  else
    Result := (target.X - Self.X);
end;

{==============================================================================]
 <TPoint.DistanceY>
 @action: Calculates the vertical distance between this point and the target point.
 @note: Functionally identical to DistY; uses explicit conditional logic instead of Abs().
[==============================================================================}
function TPoint.DistanceY(const target: TPoint): Integer;
begin
  if (Self.Y > target.Y) then
    Result := (Self.Y - target.Y)
  else
    Result := (target.Y - Self.Y);
end;

{==============================================================================]
 <TPoint.DistMaxMinX>
 @action: Returns the absolute horizontal distance between this point and the target point using Max/Min arithmetic.
 @note: Equivalent to Abs(Self.X - Target.X); employs the branchless Max(a,b) - Min(a,b) idiom,
        which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinX(const target: TPoint): Integer;
begin
  Result := (Max(Self.X, target.X) - Min(Self.X, target.X));
end;

{==============================================================================]
 <TPoint.DistMaxMinY>
 @action: Returns the absolute vertical distance between this point and the target point using Max/Min arithmetic.
@note: Equivalent to Abs(Self.Y - Target.Y); employs the branchless Max(a,b) - Min(a,b) idiom,
       which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinY(const target: TPoint): Integer;
begin
  Result := (Max(Self.Y, target.Y) - Min(Self.Y, target.Y));
end;

{==============================================================================]
 <TPoint.DeltaX>
 @action: Returns the signed horizontal delta from this point to the target point (positive if target is to the right).
 @note: Equivalent to Target.X - Self.X; useful for directional movement or vector calculations without absolute value.
[==============================================================================}
function TPoint.DeltaX(const target: TPoint): Integer;
begin
  Result := (target.X - Self.X);
end;

{==============================================================================]
 <TPoint.DeltaY>
 @action: Returns the signed vertical delta from this point to the target point (positive if target is below).
 @note: Equivalent to Target.Y - Self.Y; useful for directional movement or vector calculations without absolute value. Assumes Y increases downward in coordinate system.
[==============================================================================}
function TPoint.DeltaY(const target: TPoint): Integer;
begin
  Result := (target.Y - Self.Y);
end;

{==============================================================================]
 <TPoint.Delta>
 @action: Returns the signed vector delta from this point to the target point as a TPoint (dx, dy).
 @note: Equivalent to Point(Target.X - Self.X, Target.Y - Self.Y); useful for relative positioning, vector calculations, or directional offsets without absolute values.
[==============================================================================}
function TPoint.Delta(const target: TPoint): TPoint;
begin
  Result := Point((target.X - Self.X), (target.Y - Self.Y));
end;

{==============================================================================]
 <TPoint.HorizontalDist>
 @action: Returns the absolute horizontal distance between this point and the target point.
 @note: Equivalent to Abs(Self.X - target.X); useful for quick delta comparisons on the X-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.HorizontalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
 <TPoint.VerticalDist>
 @action: Returns the absolute vertical distance between this point and the target point.
 @note: Equivalent to Abs(Self.Y - target.Y); useful for quick delta comparisons on the Y-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.VerticalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;

{==============================================================================]
  <TPointHelper.Create>
  @action: Returns TPoint 0,0.
  @note: None.
[==============================================================================}
function TPointHelper.Create: TPoint; overload;
begin
  Self.X := 0;
  Self.Y := 0;
  Result := Self;
end;

{==============================================================================]
  <TPointHelper.Clamp>
  @action: Clamps pt in area, if it is not inside area.
  @note: None.
[==============================================================================}
function TPointHelper.Clamp(const area: TBox): TPoint;
begin
  Result.X := specialize IfThenElse<Integer>((Self.X < area.X1), (Self.X > area.X2), area.X1, area.X2, Self.X);
  Result.Y := specialize IfThenElse<Integer>((Self.Y < area.Y1), (Self.Y > area.Y2), area.Y1, area.Y2, Self.Y);
end;

{==============================================================================]
 <TPointHelper.Grid>
 @action: Outputs/builds grid of points with parameters;
          pt = starting point, used for starting coordinates.
          rows, columns = count of rows and columns
          spaceHorizontal = space between columns
          spaceVertical = space between rows
 @note: None.
[==============================================================================}
function TPointHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray;
var
  r, c, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y + (r * (spaceVertical + 1)));
      for c := 0 to (columns - 1) do
      begin
        x := (Self.X + (c * (spaceHorizontal + 1)));
		Result[(r * columns) + c].Create(x, y);
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TPointHelper.Row>
 @action: Outputs column of points. Starting from pt,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TPointHelper.Row(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create((Self.X + (i * (space + 1))), Self.Y);
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TPointHelper.Column>
 @action: Outputs column of points. Starting from pt,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TPointHelper.Column(const cells: Integer; const space: Integer = 0): TPointArray;
var
  i: Integer;
begin
  if (cells > 0) then
  begin
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
	  Result[i].Create(Self.X, (Self.Y + (i * (space + 1))));
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TPointHelper.ToY>
 @action: Returns an array of points forming a vertical line from Self to yGoal.
 @note:   X remains constant; Y increments or decrements depending on yGoal.
[==============================================================================}
function TPointHelper.ToY(const yGoal: Integer): TPointArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, (Abs(yGoal - Self.Y) + 1));
  r := 0;
  case (Self.Y > yGoal) of
    True:
    for i := Self.Y downto yGoal do
      Result[r.Increase] := Point(Self.X, i);
    False:
    for i := Self.Y to yGoal do
      Result[r.Increase] := Point(Self.X, i);
  end;
end;

{==============================================================================]
 <TPointHelper.ToX>
 @action: Returns an array of points forming a horizontal line from Self to xGoal.
 @note:   Y remains constant; X increments or decrements depending on xGoal.
[==============================================================================}
function TPointHelper.ToX(const xGoal: Integer): TPointArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, (Abs(xGoal - Self.X) + 1));
  r := 0;
  case (Self.X > xGoal) of
    True:
    for i := Self.X downto xGoal do
      Result[r.Increase] := Point(i, Self.Y);
    False:
    for i := Self.X to xGoal do
      Result[r.Increase] := Point(i, Self.Y);
  end;
end;

{==============================================================================]
  <_TPoint.Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <_TPoint.Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const value: Integer = 0): TPoint; overload;
begin
  Result := _TPoint.Create(value, value);
end;

{==============================================================================]
  <TPoint.Surrounding>
  @action: Returns an array of points surrounding the current point (Self)
           within a 3×3 neighborhood.
           Includes diagonal neighbors when adjacency8 = True.
  @note: Each point in the result represents an absolute position relative
         to the current point. The center point (Self) is excluded.
         Useful for grid traversal, flood fill, pathfinding, or image
         processing algorithms where nearby cells must be evaluated.
[==============================================================================}
function TPointHelper.Surrounding(const adjacency8: Boolean = True): TPointArray; overload;
var
  r, c, i: Integer;
begin
  SetLength(Result, IfThen(adjacency8, 8, 4));
  i := 0;
  for r := -1 to 1 do
    for c := -1 to 1 do
      if not ((r = 0) and (c = 0)) then
        if (adjacency8 or (Abs(r) + Abs(c) = 1)) then
          Result[i.Increase] := Point((Self.X + c), (Self.Y + r));
end;

{==============================================================================]
  <TPoint.Neighbour>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note:  Uses explicit comparisons of absolute differences.
          Excludes `Self` from being a neighbor in 8-way mode.
[==============================================================================}
function TPoint.Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (((d.X <= 1) and (d.Y <= 1)) and (not ((d.X = 0) and (d.Y = 0))))
  else
    Result := (((d.X = 1) and (d.Y = 0)) or ((d.X = 0) and (d.Y = 1)));
end;

{==============================================================================]
  <TPoint.Neighbor>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note: Uses a more concise method with Chebyshev distance (Max(dx, dy)) for 8-way
         and Manhattan distance (dx + dy) for 4-way. Excludes `Self` automatically
         because distance 0 is not considered adjacency.
[==============================================================================}
function TPoint.Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (Max(d.X, d.Y) = 1)
  else
    Result := ((d.X + d.Y) = 1);
end;

{==============================================================================]
  <TPoint.Adjacent>
  @action: Checks whether the given point p is directly adjacent to `Self`.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Efficient exact comparison. Self is not considered adjacent.
[==============================================================================}
function TPoint.Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
  c: TPoint;
begin
  c := Point((p.X - Self.X), (p.Y - Self.Y)); 
  for i := 0 to IfThen(adjacency8, 7, 3) do
    if ((c.X = o[i].X) and (c.Y = o[i].Y)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TPoint.Adjacent>
  @action: Returns all points adjacent to Self as a TPointArray.
           Can return either 4-way (orthogonal) or 8-way (including diagonals).
  @note: Creates a new dynamic array on each call.
[==============================================================================}
function TPointHelper.Adjacent(const adjacency8: Boolean = True): TPointArray; overload;
begin
  if adjacency8 then
    Exit([Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1)), Point((Self.X + 1), (Self.Y + 1)), Point((Self.X + 1), (Self.Y - 1)), Point((Self.X - 1), (Self.Y + 1)), Point((Self.X - 1), (Self.Y - 1))]);
  Result := [Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1))];
end;

{==============================================================================]
  <TPoint.Adjacent>
  @action: Fills the given point array with the 4 or 8 adjacent points around Self.
  @note: If adjacency8 is True, diagonal neighbors are also included.
[==============================================================================}
procedure TPointHelper.Adjacent(var adj: TPointArray; const adjacency8: Boolean = True); overload;
begin
  adj[0].Create(Self.x, (Self.y - 1));
  adj[3].Create(Self.x, (Self.y + 1));
  adj[1].Create((Self.x + 1), Self.y);
  adj[2].Create((Self.x - 1), Self.y);
  if adjacency8 then
  begin
    adj[4].Create((Self.x - 1), (Self.y - 1));
    adj[5].Create((Self.x + 1), (Self.y - 1));
    adj[6].Create((Self.x - 1), (Self.y + 1));
    adj[7].Create((Self.x + 1), (Self.y + 1));
  end;
end;

{==============================================================================]
  <TPoint.Adjacency>
  @action: Returns an array of points adjacent to the current point (Self).
           When adjacency8 is True, diagonal neighbors are included.
  @note: The resulting points are absolute coordinates on the same grid.
         Useful for operations like pathfinding, image processing, and
         grid traversal where nearby cells must be inspected.
[==============================================================================}
function TPointHelper.Adjacency(const adjacency8: Boolean = True): TPointArray; overload;
begin
  if adjacency8 then
    Result := [Point((Self.X - 1), (Self.Y - 1)), Point((Self.X - 1), Self.Y), Point((Self.X - 1), (Self.X + 1)), Point(Self.X, (Self.X + 1)), Point((Self.X + 1), (Self.Y + 1)), Point((Self.X + 1), Self.Y), Point((Self.X + 1), (Self.Y - 1)), Point(Self.X, (Self.Y - 1))]
  else
    Result := [Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1)), Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1))];
end;

{==============================================================================]
  <TPoint.Neighbours>
  @action: Returns all neighboring points of Self as a TPointArray.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Dynamic array is allocated for each call. Offset array ensures correct order.
[==============================================================================}
function TPointHelper.Neighbours(const adjacency8: Boolean = True): TPointArray; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
begin
  SetLength(Result, IfThen(adjacency8, 8, 4));
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X + o[i].X), (Self.Y + o[i].Y));
end;

{==============================================================================]
  <TPoint.Neighbours>
  @action:  Populates the provided array with adjacent points in 4 or 8 directions.
  @note:    Uses 8-way adjacency if the array length is greater than 4; 
            otherwise only the 4 cardinal directions are filled.
[==============================================================================}
procedure TPointHelper.Neighbours(var adj: TPointArray); overload;
begin
  adj[0] := Point(Self.x, (Self.y - 1));
  adj[3] := Point(Self.x, (Self.y + 1));
  adj[1] := Point((Self.x + 1), Self.y);
  adj[2] := Point((Self.x - 1), Self.y);
  if (Length(adj) > 4) then
  begin
    adj[4] := Point((Self.x - 1), (Self.y - 1));
    adj[5] := Point((Self.x + 1), (Self.y - 1));
    adj[6] := Point((Self.x - 1), (Self.y + 1));
    adj[7] := Point((Self.x + 1), (Self.y + 1));
  end;
end;

{==============================================================================]
  <TPoint.Neighbors>
  @action: Returns all neighboring points of Self as a TPointArray (alternative spelling).
           Supports 4-way or 8-way adjacency.
  @note: The first 4 points are orthogonal neighbors; the next 4 (if adjacency8) are diagonals.
[==============================================================================}
function TPointHelper.Neighbors(const adjacency8: Boolean = True): TPointArray; overload;
begin
  with Self do
    Result := [Point((X + 1), Y), Point(X, (Y + 1)), Point((X - 1), Y), Point(X, (Y - 1)),
               Point((X + 1), (Y + 1)), Point((X + 1), (Y - 1)), Point((X - 1), (Y + 1)), Point((X - 1), (Y - 1))];
  if not adjacency8 then
    SetLength(Result, 4);
end;

{==============================================================================]
  <TPoint.Neighbors>
  @action:  Populates the provided array with adjacent points in 4 or 8 directions.
  @note:    Uses 8-way adjacency if the array length is greater than 4; 
            otherwise only the 4 cardinal directions are filled.
[==============================================================================}
procedure TPointHelper.Neighbors(var adj: TPointArray); overload;
begin
  adj[0].Create(Self.x, (Self.y - 1));
  adj[3].Create(Self.x, (Self.y + 1));
  adj[1].Create((Self.x + 1), Self.y);
  adj[2].Create((Self.x - 1), Self.y);
  if (Length(adj) > 4) then
  begin
    adj[4].Create((Self.x - 1), (Self.y - 1));
    adj[5].Create((Self.x + 1), (Self.y - 1));
    adj[6].Create((Self.x - 1), (Self.y + 1));
    adj[7].Create((Self.x + 1), (Self.y + 1));
  end;
end;

{==============================================================================]
  <TPoint.Linked>
  @action: Determines whether both the current point (Self) and the given point p
           are present in the provided TPointArray. Returns True if both points
           are contained in the array, False otherwise.
  @note:   Uses the Contains helper of TPointArray for membership checks. This
           method only checks array membership; it does not imply any geometric
           connection or adjacency between the points.
[==============================================================================}
function TPointHelper.Linked(const p: TPoint; const link: TPointArray): Boolean; overload;
begin
  Result := (link.Contains(Self) and link.Contains(p));
end;

{==============================================================================]
  <TPoint.Boxed>
  @action: Creates a square/rectangular box centered on the point,
           extending by xRadius horizontally and yRadius vertically.
  @note: Useful for defining an area of influence around a point.
[==============================================================================}
function TPointHelper.Boxed(const xRadius, yRadius: Integer): TBox; overload;
begin
  Result.X1 := (Self.X - xRadius);
  Result.Y1 := (Self.Y - yRadius);
  Result.X2 := (Self.X + xRadius);
  Result.Y2 := (Self.Y + yRadius);
end;

function TPointHelper.Boxed(const radius: Integer = 0): TBox; overload;
begin
  Result := Self.Boxed(radius, radius);
end;

{==============================================================================]
  <TPoint.ToBox>
  @action: Creates a box using the point as the top-left corner (origin),
           extending rightward by width and downward by height.
  @note: Negative width/height make the box extend left/up instead.
[==============================================================================}
function TPointHelper.ToBox(const width, height: Integer): TBox; overload;
begin
  Result.X1 := IfThen((width < 0), (Self.X - width), Self.X);
  Result.Y1 := IfThen((height < 0), (Self.Y - height), Self.Y);
  Result.X2 := IfThen((width < 0), Self.X, (Self.X + width));
  Result.Y2 := IfThen((height < 0), Self.Y, (Self.Y + height));
end;

function TPointHelper.ToBox(const size: Integer = 0): TBox; overload;
begin
  Result := Self.ToBox(size, size);
end;

{==============================================================================]
  <TPoint.Boxify>
  @action: Returns a box centered on the point with the specified width and height.
  @note: The box expands equally in all directions from the point’s center.
[==============================================================================}
function TPointHelper.Boxify(const width, height: Integer): TBox; overload;
var
  w, h: Integer;
begin
  w := (width div 2);
  h := (height div 2);
  Result.X1 := (Self.X - w);
  Result.Y1 := (Self.Y - h);
  Result.X2 := (Self.X + (width - w));
  Result.Y2 := (Self.Y + (height - h));
end;

function TPointHelper.Boxify(const size: Integer = 0): TBox; overload;
begin
  Result := Self.Boxify(size, size);
end;

{==============================================================================]
  <TPoint.Uniform>
  @action: Checks whether both coordinates of the point equal the specified value.
  @note: Returns True only if (X = val) and (Y = val).
[==============================================================================}
function TPoint.Uniform(const val: Integer): Boolean; overload;
begin
  Result := ((Self.X = val) and (Self.Y = val));
end;

{==============================================================================]
  <TPoint.Uniform>
  @action: Checks whether the point’s coordinates are equal to each other.
  @note: Returns True if (X = Y).
[==============================================================================}
function TPoint.Uniform: Boolean; overload;
begin
  Result := (Self.X = Self.Y);
end;

{==============================================================================]
  <TPoint.Employs>
  @action: Checks if the given integer value matches either the X or Y coordinate of the point.
  @note: Useful for determining if a specific value is present in a 2D point.
[==============================================================================}
function TPoint.Employs(const val: Integer): Boolean;
begin
  Result := ((Self.X = val) or (Self.Y = val));
end;

{==============================================================================]
  <TPoint.Omits>
  @action: Checks if the given integer value is NOT present in either the X or Y coordinate of the point.
  @note: Logical inverse of TPoint.Employs; returns True if the value is absent.
[==============================================================================}
function TPoint.Omits(const val: Integer): Boolean;
begin
  Result := not ((Self.X = val) or (Self.Y = val));
end;

{$ENDIF}

{$UNDEF TPoint}