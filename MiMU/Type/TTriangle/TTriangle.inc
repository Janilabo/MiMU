{$DEFINE TTriangle}{$I ../Defines.inc}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
TTriangleCompare = function(const A, B: TTriangle): Integer;
TTriangleArray = array of TTriangle;
T2DTriangleArray = array of TTriangleArray;
{$ENDIF}

{$IFDEF HELPERS}
TTriangleHelper = type helper for TTriangle
  {$I ../Base/Base.inc}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$ENDIF}

{$UNDEF TTriangle}
