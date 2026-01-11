{$DEFINE TRange}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I Enumerator.inc}
TRange = record
  start, stop: Integer;
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TRange.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
TRangeCompare = specialize TCompare<TRange>;
TRangeArray = array of TRange;
T2DRangeArray = array of TRangeArray;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IFDEF HELPERS}
TRangeHelper = type helper for TRange
  {$I TRange.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TRange.pph}
{$ENDIF}

{$UNDEF TRange}
