{$DEFINE TRange}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DRangeArray = class
public 
  {$DEFINE METHODS}{$I T2DRangeArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I ../T2DArray.inc}
  {$I T2DRangeArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DRangeArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TRange}
