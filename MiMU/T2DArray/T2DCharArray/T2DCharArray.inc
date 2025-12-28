{$DEFINE Char}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I ../T2DArray.inc}
  {$I T2DCharArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DCharArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}
