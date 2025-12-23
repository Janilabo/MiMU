{$DEFINE TCircle}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TCircle}
