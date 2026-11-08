{$DEFINE Char}{$I ../Defines.inc}

{$IFDEF TYPES}
TCharInterval = specialize TInterval<Char>;
TCharCompare = specialize TCompare<Char>;
TCharArray = array of Char;
T2DCharArray = array of TCharArray;
T3DCharArray = array of T2DCharArray;
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