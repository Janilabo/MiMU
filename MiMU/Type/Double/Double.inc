{$DEFINE Double}{$I ../Defines.inc}

{$IFDEF TYPES}
TDoubleCompare = function(const A, B: Double): Integer;
TDoubleArray = array of Double;
T2DDoubleArray = array of TDoubleArray;
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