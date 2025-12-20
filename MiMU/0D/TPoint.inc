{$DEFINE MType := TPoint}
{$DEFINE MArray := TPointArray}
{$DEFINE M2DArray := T2DPointArray}
{$DEFINE MCompare := TPointCompare}
{$DEFINE MHelper := TPointHelper}
{$DEFINE Sortable}

{$IFDEF TYPES}
TPoint = record
  X, Y: Integer;
  constructor Create(const pX, pY: Integer); overload;
  constructor Create(const value: Integer); overload;
  class function Construct(const pX, pY: Integer): TPoint; overload; static;
  class function Null(const value: Integer = -2147483648): TPoint; overload; static;
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
  function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; overload;
  function AngleRadians(const target: TPoint): Double; overload;
  function HypotEuclidean(const target: TPoint): Double; overload;	
  function Euclidean(const target: TPoint): Double; overload;
  function Euclidean2(const target: TPoint): Double; overload;
  function SquaredEuclidean(const target: TPoint): Double; overload;
  function Manhattan(const target: TPoint): Double; overload;
  function Chebyshev(const target: TPoint): Double; overload;
  function Minkowski(const target: TPoint): Double; overload;
  function Minkowski(const target: TPoint; const P: Double): Double; overload;
  function MaxMinChebyshev(const target: TPoint): Double; overload;
  function Octile(const target: TPoint): Double; overload;
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
{$I Core.inc}
PPoint = ^TPoint;
_TPoint = class
public
  class function Create(const pX, pY: Integer): TPoint; overload; 
  class function Create(const value: Integer = 0): TPoint; overload; 
end;
TMetrics = (dmHypotEuclidean, dmEuclidean, dmEuclidean2, dmSquaredEuclidean, dmManhattan, dmChebyshev, dmMinkowski, dmMaxMinChebyshev, dmOctile);
TDistance = function(const A, B: TPoint): Double;
{$ENDIF}

{$IFDEF METHODS}
function Point(const pX, pY: Integer): TPoint; overload; inline;
function Point(const val: Integer = 0): TPoint; overload; inline;
function HypotEuclidean(const A, B: TPoint): Double; overload;
function Euclidean(const A, B: TPoint): Double; overload;
function Euclidean2(const A, B: TPoint): Double; overload;
function SquaredEuclidean(const A, B: TPoint): Double; overload;
function Manhattan(const A, B: TPoint): Double; overload;
function Chebyshev(const A, B: TPoint): Double; overload;
function Minkowski(const A, B: TPoint): Double; overload;
function Minkowski(const A, B: TPoint; const P: Double): Double; overload;
function MaxMinChebyshev(const A, B: TPoint): Double; overload;
function Octile(const A, B: TPoint): Double; overload;
function Distance(const distFunc: TDistance): TDistance; overload;
function Distance(const method: Integer = 0): TDistance; overload;
function Distance(const metric: TMetrics): TDistance; overload;
function Distance(const A, B: TPoint; const distFunc: TDistance): Double; overload;
function Distance(const A, B: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
function Min(const A, B: TPoint): TPoint; overload;
function Max(const A, B: TPoint): TPoint; overload;
function Compare(const A, B: TPoint): Integer; overload;
function Comparison(const A, B: TPoint): Integer; overload;
{$ENDIF}

{$IFDEF OPERATORS}
operator +(const a, b: TPoint): TPoint;
operator -(const a, b: TPoint): TPoint;
operator =(const a, b: TPoint): Boolean;
operator <>(const a, b: TPoint): Boolean;
operator >(const a, b: TPoint): Boolean;
operator <(const a, b: TPoint): Boolean;
operator >=(const a, b: TPoint): Boolean;
operator <=(const a, b: TPoint): Boolean;
{$ENDIF}

{$IFDEF HELPERS}
TPointHelper = type helper for TPoint
  {$I Core.inc}
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
  function Within(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
  function Within(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
  function Near(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
  function Near(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
  function Dist(const target: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator +(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X + b.X);
  Result.X := (a.Y + b.Y);
end;

operator -(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X - b.X);
  Result.Y := (a.Y - b.Y);
end;

operator =(const a, b: TPoint): Boolean;
begin
  Result := ((a.X = b.X) and (a.Y = b.Y));
end;

operator <>(const a, b: TPoint): Boolean;
begin
  Result := not ((a.X = b.X) and (a.Y = b.Y));
end;

operator >(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y > b.Y) or ((a.Y = b.Y) and (a.X > b.X)));
end;

operator <(const a, b: TPoint): Boolean;
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
  <Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const pX, pY: Integer); overload;
begin
  Self.X := pX;
  Self.Y := pY;
end;

{==============================================================================]
  <Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <Create>
  @action: Constructs new TPoint with pX and pY.
  @note: None.
[==============================================================================}
class function TPoint.Construct(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <Build>
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
  <Null>
  @action: Returns a "null" or invalid point, with both X and Y set to the specified sentinel value.
  @param: value - Optional integer to use as the sentinel for an empty point. Defaults 
                  to Low(Integer) (-2147483648 for 32-bit integers).
  @note:   This function is typically used to mark uninitialized or invalid points, 
           such as the result of an intersection that yields no valid coordinates.
[==============================================================================}
class function TPoint.Null(const value: Integer = -2147483648): TPoint; overload; static;
begin
  Result := Point(value, value);
end;

{==============================================================================]
  <Sign>
  @action: Compares the current TPoint (Self) with a target TPoint and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TPointHelper.Sign(const target: TPoint): Integer; overload; inline; {$DEFINE Skeleton_Sign}{$I Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Lower>
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
  <Higher>
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
  <Under>
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
  <Over>
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
  <Behind>
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
  <Ahead>
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
  <Comparison>
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
  <Compared>
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
  <Comp>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Comp(const target: TPoint): Integer; overload;
begin
  Result := IfThen((X <> target.X), (Ord(X > target.X) - Ord(X < target.X)), (Ord(Y > target.Y) - Ord(Y < target.Y)));
end;

{==============================================================================]
  <Cmp>
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
  <Compare>
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
  <XComp>
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
  <YComp>
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
  <XCompare>
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
  <YCompare>
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
  <CompareX>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareX(const target: TPoint): Integer;
begin
  Result := (Ord(Self.X > target.X) - Ord(Self.X < target.X));
end;

{==============================================================================]
  <CompareY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareY(const target: TPoint): Integer;
begin
  Result := (Ord(Self.Y > target.Y) - Ord(Self.Y < target.Y));
end;

{==============================================================================]
  <CompX>
  @action: Compares two points by their X coordinate only.
  @note: - Returns -1 if Self.X < target.X, 1 if Self.X > target.X, and 0 if equal.
         - The Y coordinate is ignored.
[==============================================================================}
function TPoint.CompX(const target: TPoint): Integer;
begin
  Result := Sign(Self.X - target.X);
end;

{==============================================================================]
  <CompY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompY(const target: TPoint): Integer;
begin
  Result := Sign(Self.Y - target.Y);
end;

{==============================================================================]
  <Inside>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TPointHelper.Inside(const bx: TBox): Boolean; inline;
begin
  Result := ((Self.X >= bx.X1) and (Self.Y >= bx.Y1) and (Self.X <= bx.X2) and (Self.Y <= bx.Y2));
end;

{==============================================================================]
  <InCircle>
  @action: Returns true if pt is inside the given circle,
          that is defined by the center point and radius.
  @note: None.
[==============================================================================}
function TPoint.InCircle(const center: TPoint; const radius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / radius) + Sqr((Self.Y - center.Y) / radius) <= 1);
end;

{==============================================================================]
  <InEllipse>
  @action: Returns true if pt is inside the given ellipse,
          defined by the center point and X-radius and Y-radius.
  @note: None.
[==============================================================================}
function TPoint.InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
begin
  Result := (Sqr((Self.X - center.X) / XRadius) + Sqr((Self.Y - center.Y) / YRadius) <= 1);
end;

{==============================================================================]
  <AngleDegrees>
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
  <AngleRadians>
  @action: Calculates the angle in degrees from source to target.
  @note: None
[==============================================================================}
function TPoint.AngleRadians(const target: TPoint): Double; overload;
var
  a: Double;
begin
  a := ArcTan2((target.Y - Self.Y), (target.X - Self.X));
  Result := a.FixRadians;
end;

{==============================================================================]
  <DistHypotEuclidean>
  @action: Calculates the distance from source to target.
  @note: Euclidean.
[==============================================================================}
function TPoint.HypotEuclidean(const target: TPoint): Double; overload;
begin
  Result := Hypot((Self.X - target.X), (Self.Y - target.Y));
end;

{==============================================================================]
  <DistEuclidean>
  @action: Calculates the distance from source to target.
  @note: Euclidean.
[==============================================================================}
function TPoint.Euclidean(const target: TPoint): Double; overload;
begin
  Result := (Sqrt(Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y)));
end;

{==============================================================================]
  <DistEuclidean2>
  @action: Calculates the distance from source to target.
  @note: Euclidean v2
[==============================================================================}
function TPoint.Euclidean2(const target: TPoint): Double; overload;
begin
  Result := Sqrt(Power((Self.X - target.X), 2) + Power((Self.Y - target.Y), 2));
end;

{==============================================================================]
  <DistSquaredEuclidean>
  @action: Calculates the distance from source to target.
  @note: Squared Euclidean
[==============================================================================}
function TPoint.SquaredEuclidean(const target: TPoint): Double; overload;
begin
  Result := (Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y));
end;

{==============================================================================]
  <DistManhattan>
  @action: Calculates the distance from source to target.
  @note: Manhattan
[==============================================================================}
function TPoint.Manhattan(const target: TPoint): Double; overload;
begin
  Result := (Abs(Self.X - target.X) + Abs(Self.Y - target.Y));
end;

{==============================================================================]
  <DistChebyshev>
  @action: Calculates the distance from source to target.
  @note: Chebyshev
[==============================================================================}
function TPoint.Chebyshev(const target: TPoint): Double; overload;
begin
  Result := Max(Abs(Self.X - target.X), Abs(Self.Y - target.Y));
end;

{==============================================================================]
  <DistMinkowski>
  @action: Calculates the distance from source to target.
  @note: Minkowski
[==============================================================================}
function TPoint.Minkowski(const target: TPoint): Double; overload;
begin
  Result := Power(Power(Abs(Self.X - target.X), 2.0) + Power(Abs(Self.Y - target.Y), 2.0), (1 / 2.0)); 
end;

{==============================================================================]
  <DistMinkowski>
  @action: Calculates the distance from source to target.
  @note: Minkowski
[==============================================================================}
function TPoint.Minkowski(const target: TPoint; const P: Double): Double; overload;
begin
  Result := Power(Power(Abs(Self.X - target.X), P) + Power(Abs(Self.Y - target.Y), P), (1 / P));
end;

{==============================================================================]
  <DistMaxMinChebyshev>
  @action: Calculates the distance from source to target.
  @note: Max-Min Chebyshev
[==============================================================================}
function TPoint.MaxMinChebyshev(const target: TPoint): Double; overload;
begin
  Result := Max(Max(Self.X, target.X) - Min(Self.X, target.X), Max(Self.Y, target.Y) - Min(Self.Y, target.Y));
end;

{==============================================================================]
  <DistOctile>
  @action: Calculates the distance from source to target.
  @note: Octile
[==============================================================================}
function TPoint.Octile(const target: TPoint): Double; overload;
var
  h, v: Integer;
begin
  h := Abs(Self.X - target.X);
  v := Abs(Self.Y - target.Y);
  Result := (Max(h, v) + (Sqrt(2) - 1) * Min(h, v));
end;

{==============================================================================]
  <Dist>
  @action: Calculates the distance from source to target.
  @note: Octile
[==============================================================================}
function TPointHelper.Dist(const target: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
begin
  Result := Distance(Self, target, metric);
end;

{==============================================================================]
  <Reflected>
  @action: Reflects the point across the line y = x.
  @note: Swaps the X and Y coordinates. (x, y) → (y, x)
[==============================================================================}
function TPoint.Reflected: TPoint; inline;
begin
  Result.X := Self.Y;
  Result.Y := Self.X;
end;

{==============================================================================]
  <Flipped>
  @action: Returns the point with its coordinates flipped (same as Reflected).
  @note: This is a shorthand, stylistically different version of Reflected.
[==============================================================================}
function TPoint.Flipped: TPoint; inline;
begin
  Result := Point(Self.Y, Self.X);
end;

{==============================================================================]
  <Within>
  @action: Determines whether this point lies within a given distance (radius)
           of another point, using the specified distance function.
  @note: If no distance function is provided, Euclidean distance should be
         used as the default metric.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
  <Within>
  @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
  @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Within(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): Boolean; overload;
begin
  Result := Self.Within(target, radius, Distance(metric));
end;

{==============================================================================]
  <Within>
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
  <Near>
  @action: Determines whether the current point is within a given radius of the target point using a custom distance function.
  @note: `distFunc` is a user-provided function that calculates the distance between two points. Useful for non-standard distance metrics.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const distFunc: TDistance): Boolean; overload;
begin
  Result := (distFunc(Self, target) <= radius);
end;

{==============================================================================]
  <Near>
  @action: Determines whether the current point is within a given radius of the target point using a specified distance metric.
  @note: `metric` specifies a predefined distance metric (e.g., Euclidean, Manhattan, Chebyshev). Internally uses `DistanceFunction(metric)`.
[==============================================================================}
function TPointHelper.Near(const target: TPoint; const radius: Double; const metric: TMetrics): Boolean; overload;
begin
  Result := Self.Near(target, radius, Distance(metric));
end;

{==============================================================================]
  <Near>
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
  <Near>
  @action: Determines whether the current point is within an axis-aligned rectangular area around the target point.
  @note: Checks whether the X and Y distances are within `xRadius` and `yRadius` respectively. Uses `DistanceX` and `DistanceY` for clarity.
[==============================================================================}
function TPoint.Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
begin
  Result := ((Self.DistanceX(target) <= xRadius) and (Self.DistanceY(target) <= yRadius));
end;

{==============================================================================]
  <DistX>
  @action: Returns the absolute horizontal distance between this point and the target point.
  @note: Equivalent to Abs(Self.X - target.X). Useful for quick delta comparisons on the X-axis.
[==============================================================================}
function TPoint.DistX(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
  <DistY>
  @action: Returns the absolute vertical distance between this point and the target point.
  @note: Equivalent to Abs(Self.Y - target.Y). Useful for quick delta comparisons on the Y-axis.
[==============================================================================}
function TPoint.DistY(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;

{==============================================================================]
  <DistanceX>
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
  <DistanceY>
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
  <DistMaxMinX>
  @action: Returns the absolute horizontal distance between this point and the target point using Max/Min arithmetic.
  @note: Equivalent to Abs(Self.X - Target.X); employs the branchless Max(a,b) - Min(a,b) idiom,
         which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinX(const target: TPoint): Integer;
begin
  Result := (Max(Self.X, target.X) - Min(Self.X, target.X));
end;

{==============================================================================]
  <DistMaxMinY>
  @action: Returns the absolute vertical distance between this point and the target point using Max/Min arithmetic.
  @note: Equivalent to Abs(Self.Y - Target.Y); employs the branchless Max(a,b) - Min(a,b) idiom,
         which often compiles to conditional moves for efficiency.
[==============================================================================}
function TPoint.DistMaxMinY(const target: TPoint): Integer;
begin
  Result := (Max(Self.Y, target.Y) - Min(Self.Y, target.Y));
end;

{==============================================================================]
  <DeltaX>
  @action: Returns the signed horizontal delta from this point to the target point (positive if target is to the right).
  @note: Equivalent to Target.X - Self.X; useful for directional movement or vector calculations without absolute value.
[==============================================================================}
function TPoint.DeltaX(const target: TPoint): Integer;
begin
  Result := (target.X - Self.X);
end;

{==============================================================================]
  <DeltaY>
  @action: Returns the signed vertical delta from this point to the target point (positive if target is below).
  @note: Equivalent to Target.Y - Self.Y; useful for directional movement or vector calculations without absolute value. Assumes Y increases downward in coordinate system.
[==============================================================================}
function TPoint.DeltaY(const target: TPoint): Integer;
begin
  Result := (target.Y - Self.Y);
end;

{==============================================================================]
  <Delta>
  @action: Returns the signed vector delta from this point to the target point as a TPoint (dx, dy).
  @note: Equivalent to Point(Target.X - Self.X, Target.Y - Self.Y); useful for relative positioning, vector calculations, or directional offsets without absolute values.
[==============================================================================}
function TPoint.Delta(const target: TPoint): TPoint;
begin
  Result := Point((target.X - Self.X), (target.Y - Self.Y));
end;

{==============================================================================]
  <HorizontalDist>
  @action: Returns the absolute horizontal distance between this point and the target point.
  @note: Equivalent to Abs(Self.X - target.X); useful for quick delta comparisons on the X-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.HorizontalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.X - target.X);
end;

{==============================================================================]
  <VerticalDist>
  @action: Returns the absolute vertical distance between this point and the target point.
  @note: Equivalent to Abs(Self.Y - target.Y); useful for quick delta comparisons on the Y-axis in UI, games, or grid systems.
[==============================================================================}
function TPoint.VerticalDist(const target: TPoint): Integer;
begin
  Result := Abs(Self.Y - target.Y);
end;

{==============================================================================]
  <Create>
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
  <Clamp>
  @action: Clamps pt in area, if it is not inside area.
  @note: None.
[==============================================================================}
function TPointHelper.Clamp(const area: TBox): TPoint;
begin
  Result.X := specialize IfThenElse<Integer>((Self.X < area.X1), (Self.X > area.X2), area.X1, area.X2, Self.X);
  Result.Y := specialize IfThenElse<Integer>((Self.Y < area.Y1), (Self.Y > area.Y2), area.Y1, area.Y2, Self.Y);
end;

{==============================================================================]
  <Grid>
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
  <Row>
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
  <Column>
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
  <ToY>
  @action: Returns an array of points forming a vertical line from Self to yGoal.
  @note: X remains constant; Y increments or decrements depending on yGoal.
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
  <ToX>
  @action: Returns an array of points forming a horizontal line from Self to xGoal.
  @note: Y remains constant; X increments or decrements depending on xGoal.
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
  <Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TPoint.Create(const value: Integer = 0): TPoint; overload;
begin
  Result := _TPoint.Create(value, value);
end;

{==============================================================================]
  <Surrounding>
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
  <Neighbour>
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
  <Neighbor>
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
  <Adjacent>
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
  <Adjacent>
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
  <Adjacent>
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
  <Adjacency>
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
  <Neighbours>
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
  <Neighbours>
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
  <Neighbors>
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
  <Neighbors>
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
  <Linked>
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
  <Boxed>
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
  <ToBox>
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
  <Boxify>
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
  <Uniform>
  @action: Checks whether both coordinates of the point equal the specified value.
  @note: Returns True only if (X = val) and (Y = val).
[==============================================================================}
function TPoint.Uniform(const val: Integer): Boolean; overload;
begin
  Result := ((Self.X = val) and (Self.Y = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether the point’s coordinates are equal to each other.
  @note: Returns True if (X = Y).
[==============================================================================}
function TPoint.Uniform: Boolean; overload;
begin
  Result := (Self.X = Self.Y);
end;

{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches either the X or Y coordinate of the point.
  @note: Useful for determining if a specific value is present in a 2D point.
[==============================================================================}
function TPoint.Employs(const val: Integer): Boolean;
begin
  Result := ((Self.X = val) or (Self.Y = val));
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present in either the X or Y coordinate of the point.
  @note: Logical inverse of TPoint.Employs; returns True if the value is absent.
[==============================================================================}
function TPoint.Omits(const val: Integer): Boolean;
begin
  Result := not ((Self.X = val) or (Self.Y = val));
end;

function HypotEuclidean(const A, B: TPoint): Double; overload;
begin
  Result := Hypot(A.X - B.X, A.Y - B.Y);
end;

function Euclidean(const A, B: TPoint): Double; overload;
begin
  Result := (Sqrt(Sqr(A.X - B.X) + Sqr(A.Y - B.Y)));
end;

function Euclidean2(const A, B: TPoint): Double; overload;
begin
  Result := Sqrt(Power((A.X - B.X), 2) + Power((A.Y - B.Y), 2));
end;

function SquaredEuclidean(const A, B: TPoint): Double; overload;
begin
  Result := (Sqr(A.X - B.X) + Sqr(A.Y - B.Y));
end;

function Manhattan(const A, B: TPoint): Double; overload;
begin
  Result := (Abs(A.X - B.X) + Abs(A.Y - B.Y));
end;

function Chebyshev(const A, B: TPoint): Double; overload;
begin
  Result := Max(Abs(A.X - B.X), Abs(A.Y - B.Y));
end;

function Minkowski(const A, B: TPoint): Double; overload;
begin
  Result := Power(Power(Abs(A.X - B.X), 2.0) + Power(Abs(A.Y - B.Y), 2.0), (1 / 2.0));
end;

function Minkowski(const A, B: TPoint; const P: Double): Double; overload;
begin
  Result := Power(Power(Abs(A.X - B.X), P) + Power(Abs(A.Y - B.Y), P), (1 / P));
end;

function MaxMinChebyshev(const A, B: TPoint): Double; overload;
begin
  Result := Max(Max(A.X, B.X) - Min(A.X, B.X), Max(A.Y, B.Y) - Min(A.Y, B.Y));
end;

function Octile(const A, B: TPoint): Double; overload;
var
  h, v: Integer;
begin
  h := Abs(A.X - B.X);
  v := Abs(A.Y - B.Y);
  Result := (Max(h, v) + (Sqrt(2) - 1) * Min(h, v));
end;

function Distance(const distFunc: TDistance): TDistance; overload;
begin
  Result := distFunc;
  if not Assigned(Result) then
    Result := @Euclidean;
end;

function Distance(const method: Integer = 0): TDistance; overload;
begin
  if not InRange(method, 0, 8) then
    Exit(@Euclidean);
  case method of
    0: Result := @HypotEuclidean;
    1: Result := @Euclidean;
    2: Result := @Euclidean2;
    3: Result := @SquaredEuclidean;
    4: Result := @Manhattan;
    5: Result := @Chebyshev;
    6: Result := @Minkowski;
    7: Result := @MaxMinChebyshev;
    8: Result := @Octile;
  end;
end;

function Distance(const metric: TMetrics): TDistance; overload;
begin
  case metric of
    dmHypotEuclidean: Result := @HypotEuclidean;
    dmEuclidean: Result := @Euclidean;
    dmEuclidean2: Result := @Euclidean2;
    dmSquaredEuclidean: Result := @SquaredEuclidean;
    dmManhattan: Result := @Manhattan;
    dmChebyshev: Result := @Chebyshev;
    dmMinkowski: Result := @Minkowski;
    dmMaxMinChebyshev: Result := @MaxMinChebyshev;
    dmOctile: Result := @Octile;
  else
    Result := @Euclidean;
  end;
end;

function Distance(const A, B: TPoint; const distFunc: TDistance): Double; overload;
begin
  Result := distFunc(A, B);
end;

function Distance(const A, B: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
begin
  Result := Distance(A, B, Distance(metric));
end;

function Min(const A, B: TPoint): TPoint; overload;
begin
  if ((A.Y < B.Y) or ((A.Y = B.Y) and (A.X < B.X))) then
    Result := A
  else
    Result := B;
end;

function Max(const A, B: TPoint): TPoint; overload;
begin
  if ((A.Y > B.Y) or ((A.Y = B.Y) and (A.X > B.X))) then
    Result := A
  else
    Result := B;
end;

function Compare(const A, B: TPoint): Integer; overload;
begin
  if (A.Y < B.Y) then
    Exit(-1);
  if (A.Y > B.Y) then
    Exit(1);
  if (A.X < B.X) then
    Exit(-1);
  if (A.X > B.X) then
    Exit(1);
  Result := 0;
end;

function Comparison(const A, B: TPoint): Integer; overload; {$DEFINE Skeleton_Comparison}{$I Skeletons.inc}{$UNDEF Skeleton_Comparison}
{$ENDIF}
