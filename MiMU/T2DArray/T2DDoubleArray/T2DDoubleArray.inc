{$DEFINE Double}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DDoubleArray = class
public 
  {$DEFINE METHODS}{$I T2DDoubleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DDoubleArrayHelper = type helper for T2DDoubleArray
  {$I T2DDoubleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DDoubleArray.pph}
{$ENDIF}

{$UNDEF Double}
