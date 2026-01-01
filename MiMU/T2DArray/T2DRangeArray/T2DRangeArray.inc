{$DEFINE TRange}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DRangeArray = class
public 
  {$DEFINE METHODS}{$I T2DRangeArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I ../Base/Base.inc}
  {$I T2DRangeArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DRangeArray.pph}
{$ENDIF}

{$UNDEF TRange}
