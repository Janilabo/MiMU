{$DEFINE TCircle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DCircleArray = class
public 
  {$DEFINE METHODS}{$I T2DCircleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I ../T2DArray.inc}
  {$I T2DCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DCircleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}
