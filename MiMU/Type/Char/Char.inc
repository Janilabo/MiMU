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

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I Char.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Char}