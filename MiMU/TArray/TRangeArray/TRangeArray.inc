{$DEFINE TRange}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CRangeArray = class
public
  {$DEFINE METHODS}{$I TRangeArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TRangeArrayHelper = type helper for TRangeArray
  {$I TRangeArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TRangeArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := start}{$I ../F.inc}
{$DEFINE FField := stop}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$UNDEF TRange}
