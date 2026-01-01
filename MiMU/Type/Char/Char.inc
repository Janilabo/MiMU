{$DEFINE Char}{$I ../Defines.inc}

{$IFDEF TYPES}
TCharCompare = specialize TCompare<Char>;
TCharArray = array of Char;
T2DCharArray = array of TCharArray;
{$ENDIF}

{$IFDEF HELPERS}
TCharHelper = type helper for Char
  {$I Char.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I Char.pph}
{$ENDIF}

{$UNDEF Char}