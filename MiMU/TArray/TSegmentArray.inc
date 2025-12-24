{$DEFINE TSegment}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I TArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I TArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TSegment}
