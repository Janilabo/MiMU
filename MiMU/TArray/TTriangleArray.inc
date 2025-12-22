{$DEFINE TTriangle}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
TTriangleArrayHelper = type helper for TTriangleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TTriangle}
