{$DEFINE TRange}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I ../T2DArray.inc}
  {$I T2DRangeArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DRangeArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TRange}
