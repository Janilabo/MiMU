{$DEFINE Char}{$I Configuration\Defines.inc}

{$IFDEF TYPES}
{$I Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TCharHelper = type helper for Char
  {$I ./Core.inc}
  {$I ./Char/Char.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./Char/Char.inc}
{$ENDIF}

{$UNDEF Char}