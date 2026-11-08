{$DEFINE TTriangle}{$I ../Defines.inc}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
TTriangleCompare = specialize TCompare<TTriangle>;
TTriangleArray = array of TTriangle;
T2DTriangleArray = array of TTriangleArray;
T3DTriangleArray = array of T2DTriangleArray;
PTriangle = ^TTriangle;
{$ENDIF}

{$IFDEF HELPERS}
TTriangleHelper = type helper for TTriangle
  {$I ../Type.inc}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$ENDIF}

{$UNDEF TTriangle}
