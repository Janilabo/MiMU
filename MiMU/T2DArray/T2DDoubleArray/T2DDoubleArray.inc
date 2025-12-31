{$DEFINE Double}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DDoubleArray = class
public 
  {$DEFINE METHODS}{$I T2DDoubleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DDoubleArrayHelper = type helper for T2DDoubleArray
  {$I ../T2DArray.inc}
  {$I T2DDoubleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DDoubleArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Double}
