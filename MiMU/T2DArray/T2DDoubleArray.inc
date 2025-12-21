{$DEFINE Double}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
T2DDoubleArrayHelper = type helper for T2DDoubleArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF Double}