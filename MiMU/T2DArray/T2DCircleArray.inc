{$DEFINE TCircle}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TCircle}