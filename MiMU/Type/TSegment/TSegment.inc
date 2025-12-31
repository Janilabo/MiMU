{$DEFINE TSegment}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TSegment = record
  A, B: TPoint;
  {$DEFINE METHODS}{$I TSegment.pph}{$UNDEF METHODS}
end;
TSegmentCompare = specialize TCompare<TSegment>;
TSegmentArray = array of TSegment;
T2DSegmentArray = array of TSegmentArray;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TSegmentHelper = type helper for TSegment
  {$I ../Type.inc}
  {$I TSegment.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I TSegment.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TSegment}
