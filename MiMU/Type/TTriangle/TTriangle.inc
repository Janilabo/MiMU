{$DEFINE TTriangle}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
TTriangleCompare = specialize TCompare<TTriangle>;
TTriangleArray = array of TTriangle;
T2DTriangleArray = array of TTriangleArray;
{$I ../Type.inc}
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

{$UNDEF BASE}{$UNDEF TTriangle}
