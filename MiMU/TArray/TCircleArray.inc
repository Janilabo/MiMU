{$DEFINE TCircle}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TCircle}