{$DEFINE TRange}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TRangeArrayHelper = type helper for TRangeArray
  {$I ../TArray.inc}
  {$I TRangeArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TRangeArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := start}{$I ../F.inc}
{$DEFINE FField := stop}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TRange}
