{$DEFINE Double}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TDoubleCompare = specialize TCompare<Double>;
TDoubleArray = array of Double;
T2DDoubleArray = array of TDoubleArray;
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