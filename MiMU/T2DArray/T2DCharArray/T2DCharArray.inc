{$DEFINE Char}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DCharArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DCharArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I T2DCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DCharArray.pph}
{$ENDIF}

{$UNDEF Char}
