{$DEFINE Int64}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DInt64Array = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DInt64Array.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I T2DInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DInt64Array.pph}
{$ENDIF}

{$UNDEF Int64}
