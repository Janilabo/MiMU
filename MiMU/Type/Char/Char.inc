{$DEFINE Char}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I ../Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TCharHelper = type helper for Char
  {$I ../Core.inc}
  {$I Char.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I Char.pph}
{$ENDIF}

{$UNDEF Char}