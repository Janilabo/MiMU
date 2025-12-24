{$DEFINE TCircle}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I TArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I TArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}
