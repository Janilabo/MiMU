{$DEFINE Double}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I ../Type.inc}
  {$I Double.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I Double.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Double}