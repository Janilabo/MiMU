{$DEFINE TTriangle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DTriangleArrayHelper = type helper for T2DTriangleArray
  {$I ../T2DArray.inc}
  {$I T2DTriangleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DTriangleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TTriangle}
