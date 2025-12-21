{$DEFINE TSegment}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TSegment}