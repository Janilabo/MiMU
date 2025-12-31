{$DEFINE Char}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DCharArray = class
public 
  {$DEFINE METHODS}{$I T2DCharArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I ../T2DArray.inc}
  {$I T2DCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DCharArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}
