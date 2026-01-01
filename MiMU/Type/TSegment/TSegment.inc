{$DEFINE TSegment}{$I ../Defines.inc}

{$IFDEF TYPES}
TSegment = record
  A, B: TPoint;
  {$DEFINE METHODS}{$I TSegment.pph}{$UNDEF METHODS}
end;
TSegmentCompare = specialize TCompare<TSegment>;
TSegmentArray = array of TSegment;
T2DSegmentArray = array of TSegmentArray;
{$ENDIF}

{$IFDEF HELPERS}
TSegmentHelper = type helper for TSegment
  {$I ../Base/Base.inc}
  {$I TSegment.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TSegment.pph}
{$ENDIF}

{$UNDEF TSegment}
