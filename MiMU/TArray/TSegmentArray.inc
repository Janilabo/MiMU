{$DEFINE TSegment}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TSegment}
