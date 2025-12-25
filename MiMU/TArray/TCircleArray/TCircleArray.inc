{$DEFINE TCircle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I ../TArray.inc}
  {$I TCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TCircleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}
