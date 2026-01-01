{$DEFINE TCircle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CCircleArray = class
public
  {$DEFINE METHODS}{$I TCircleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I TCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TCircleArray.pph}
{$ENDIF}

{$UNDEF TCircle}
