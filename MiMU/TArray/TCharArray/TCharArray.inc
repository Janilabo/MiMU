{$DEFINE Char}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TCharArrayHelper = type helper for TCharArray
  {$I ../TArray.inc}
  {$I TCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TCharArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}
