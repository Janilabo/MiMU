{$DEFINE TTriangle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DTriangleArray = class
public 
  {$DEFINE METHODS}{$I T2DTriangleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DTriangleArrayHelper = type helper for T2DTriangleArray
  {$I ../T2DArray.inc}
  {$I T2DTriangleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DTriangleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TTriangle}
