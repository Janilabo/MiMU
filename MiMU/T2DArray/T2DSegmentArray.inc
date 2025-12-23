{$DEFINE TSegment}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DSegmentArrayHelper = type helper for T2DSegmentArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TSegment}
