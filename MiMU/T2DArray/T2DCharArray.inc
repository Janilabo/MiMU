{$DEFINE Char}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I T2DArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I T2DArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}
