{$DEFINE Char}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF Char}
