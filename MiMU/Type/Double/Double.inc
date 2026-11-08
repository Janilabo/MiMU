{$DEFINE Double}{$I ../Defines.inc}

{$IFDEF TYPES}
TDoubleInterval = specialize TInterval<Double>;
TDoubleCompare = specialize TCompare<Double>;
TDoubleArray = array of Double;
T2DDoubleArray = array of TDoubleArray;
T3DDoubleArray = array of T2DDoubleArray;
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I Double.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I Double.pph}
{$ENDIF}

{$UNDEF Double}