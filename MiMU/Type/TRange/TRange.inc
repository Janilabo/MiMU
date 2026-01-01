{$DEFINE TRange}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I Enumerator.inc}
TRange = record
  start, stop: Integer;
  function GetEnumerator: TRangeEnumerator;
  {$DEFINE METHODS}{$I TRange.pph}{$UNDEF METHODS}
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
  {$I ../Base/Base.inc}
  {$I TRange.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TRange.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Enumerator.inc}

{==============================================================================]
  <GetEnumerator>
  @action: Creates and returns an enumerator that iterates through all integer
           values contained in the range, following the iteration rules defined
           by TRangeEnumerator.
  @note: The iteration order and behavior (ascending, descending, inclusive, or
         normalized) are determined entirely by TRangeEnumerator.Init. This
         function performs no normalization and passes the range endpoints
         exactly as stored.
[==============================================================================}
function TRange.GetEnumerator: TRangeEnumerator;
begin
  Result.Init(start, stop);
end;
{$ENDIF}

{$UNDEF TRange}
