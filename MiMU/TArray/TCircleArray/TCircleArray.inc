{$DEFINE TCircle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CCircleArray = class
public
  {$DEFINE METHODS}{$I TCircleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I ../Base/Base.inc}
  {$I TCircleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TCircleArray.pph}
{$ENDIF}

{$UNDEF TCircle}
