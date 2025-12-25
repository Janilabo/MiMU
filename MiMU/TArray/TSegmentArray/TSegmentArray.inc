{$DEFINE TSegment}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I ../TArray.inc}
  {$I TSegmentArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TSegmentArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TSegment}
