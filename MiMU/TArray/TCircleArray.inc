{$DEFINE TCircle}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TCircle}
