{$DEFINE TSegment}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DSegmentArrayHelper = type helper for T2DSegmentArray
  {$I ../T2DArray.inc}
  {$I T2DSegmentArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DSegmentArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TSegment}
