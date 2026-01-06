{$DEFINE TTriangle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DTriangleArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DTriangleArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DTriangleArrayHelper = type helper for T2DTriangleArray
  {$I T2DTriangleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DTriangleArray.pph}
{$ENDIF}

{$UNDEF TTriangle}
