{$DEFINE Char}{$I ../../Type/Defines.inc}{$DEFINE BASE}

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
