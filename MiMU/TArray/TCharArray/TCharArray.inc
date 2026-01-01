{$DEFINE Char}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CCharArray = class
public
  {$DEFINE METHODS}{$I TCharArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TCharArrayHelper = type helper for TCharArray
  {$I TCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TCharArray.pph}
{$ENDIF}

{$UNDEF Char}
