{$DEFINE Char}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DCharArray = class
public 
  {$DEFINE METHODS}{$I T2DCharArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I ../Base/Base.inc}
  {$I T2DCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DCharArray.pph}
{$ENDIF}

{$UNDEF Char}
