{$DEFINE Double}{$I ../Defines.inc}

{$IFDEF TYPES}
TDoubleCompare = specialize TCompare<Double>;
TDoubleArray = array of Double;
T2DDoubleArray = array of TDoubleArray;
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I ../Base/Base.inc}
  {$I Double.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I Double.pph}
{$ENDIF}

{$UNDEF Double}