{$DEFINE TPoint}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I Enumerator.inc}
TPoint = record
  X, Y: Integer;
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TPoint.pph}{$UNDEF METHODS}{$DEFINE TYPES}
  function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; overload;
  function AngleRadians(const target: TPoint): Double; overload;
  class function Null(const value: Integer = -2147483648): TPoint; overload; static;
end;
TPointCompare = specialize TCompare<TPoint>;
TPointArray = array of TPoint;
T2DPointArray = array of TPointArray;
PPoint = ^TPoint;
TMetrics = (dmHypotEuclidean, dmEuclidean, dmEuclidean2, dmSquaredEuclidean, dmManhattan, dmChebyshev, dmMinkowski, dmMaxMinChebyshev, dmOctile);
TDistance = function(const A, B: TPoint): Double;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IFDEF HELPERS}
TPointHelper = type helper for TPoint
  {$I TPoint.pph}
  function Clamp(const area: TBox): TPoint;
  function Linked(const p: TPoint; const link: TPointArray): Boolean; overload;
  function ToX(const xGoal: Integer): TPointArray; overload;
  function ToY(const yGoal: Integer): TPointArray; overload;
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TPoint.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}

{$UNDEF TPoint}
