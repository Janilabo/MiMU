{$DEFINE Int64}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I ../T2DArray.inc}
  {$I T2DInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DInt64Array.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Int64}
