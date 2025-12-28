{$DEFINE TCircle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I ../T2DArray.inc}
  {$I T2DCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DCircleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}
