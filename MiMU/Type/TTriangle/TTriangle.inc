{$DEFINE TTriangle}{$I ../Defines.inc}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
TTriangleCompare = specialize TCompare<TTriangle>;
TTriangleArray = array of TTriangle;
T2DTriangleArray = array of TTriangleArray;
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
