{$DEFINE Int64}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF Int64}
