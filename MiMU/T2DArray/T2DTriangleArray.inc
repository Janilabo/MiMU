{$DEFINE TTriangle}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
T2DTriangleArrayHelper = type helper for T2DTriangleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TTriangle}