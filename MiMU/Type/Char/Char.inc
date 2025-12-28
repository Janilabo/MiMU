{$DEFINE Char}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TCharHelper = type helper for Char
  {$I ../Type.inc}
  {$I Char.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I Char.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}