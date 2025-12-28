{$DEFINE Int64}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I ../T2DArray.inc}
  {$I T2DInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DInt64Array.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Int64}
