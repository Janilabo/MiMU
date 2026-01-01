{$DEFINE TCircle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DCircleArray = class
public 
  {$DEFINE METHODS}{$I T2DCircleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I ../Base/Base.inc}
  {$I T2DCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DCircleArray.pph}
{$ENDIF}

{$UNDEF TCircle}
