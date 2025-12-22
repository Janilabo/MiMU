{$DEFINE TRange}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TRange}
