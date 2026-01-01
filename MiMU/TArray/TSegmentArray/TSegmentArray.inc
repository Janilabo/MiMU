{$DEFINE TSegment}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CSegmentArray = class
public
  {$DEFINE METHODS}{$I TSegmentArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I TSegmentArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TSegmentArray.pph}
{$ENDIF}

{$UNDEF TSegment}
