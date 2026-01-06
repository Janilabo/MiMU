{$DEFINE Integer}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DIntegerArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DIntegerArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DIntegerArrayHelper = type helper for T2DIntegerArray
  {$I T2DIntegerArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DIntegerArray.pph}
{$ENDIF}

{$UNDEF Integer}
