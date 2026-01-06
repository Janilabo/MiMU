{$DEFINE TCircle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DCircleArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DCircleArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I T2DCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DCircleArray.pph}
{$ENDIF}

{$UNDEF TCircle}
