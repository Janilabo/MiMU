{$DEFINE TCircle}{$I ../Defines.inc}

{$IFDEF TYPES}
TCircle = record
  Center: TPoint;
  Radius: Double; 
  {$DEFINE METHODS}{$I TCircle.pph}{$UNDEF METHODS}
end;
TCircleCompare = specialize TCompare<TCircle>;
TCircleArray = array of TCircle;
T2DCircleArray = array of TCircleArray;
{$ENDIF}

{$IFDEF HELPERS}
TCircleHelper = type helper for TCircle
  {$I TCircle.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TCircle.pph}
{$ENDIF}

{$UNDEF TCircle}