{$DEFINE TSegment}{$I ../Defines.inc}

{$IFDEF TYPES}
TSegment = record
  A, B: TPoint;
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TSegment.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
TSegmentCompare = function(const A, B: TSegment): Integer;
TSegmentArray = array of TSegment;
T2DSegmentArray = array of TSegmentArray;
{$ENDIF}

{$IFDEF HELPERS}
TSegmentHelper = type helper for TSegment
  {$I TSegment.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TSegment.pph}
{$ENDIF}

{$UNDEF TSegment}
