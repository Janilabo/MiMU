{$DEFINE TCircle}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
CCircleArray = class
public
  {$DEFINE METHODS}{$I TCircleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I ../TArray.inc}
  {$I TCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TCircleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}
