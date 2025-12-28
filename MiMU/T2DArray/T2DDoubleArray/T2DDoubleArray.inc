{$DEFINE Double}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DDoubleArrayHelper = type helper for T2DDoubleArray
  {$I ../T2DArray.inc}
  {$I T2DDoubleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DDoubleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Double}
